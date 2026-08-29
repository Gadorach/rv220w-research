#!/usr/bin/env python3
from __future__ import annotations
import argparse,hashlib,json,os,pathlib,re,subprocess,sys,time
ROOT=pathlib.Path(__file__).resolve().parents[2]
WORK=pathlib.Path(os.environ.get('RV220W_WORKSPACE',ROOT/'build')).expanduser().resolve()
ART=WORK/'artifacts'; LOGS=WORK/'logs'; PREBUILT=ROOT.parent/'prebuilt'
INIT_NAME='rv220w-openwrt-release-initramfs.elf'
SYS_NAME='rv220w-openwrt-release-sysupgrade.tar'

def choose(items,label,override=None):
    if override:return override
    if not items: raise SystemExit(f'no {label} candidates found')
    print(f'\nAvailable {label}:')
    for i,x in enumerate(items,1):print(f'  {i}) {x}')
    while True:
        s=input(f'Select {label} [1-{len(items)}]: ').strip()
        if s.isdigit() and 1<=int(s)<=len(items):return items[int(s)-1]
def serials():
    vals=[]; seen=set()
    for pat in ('/dev/serial/by-id/*','/dev/ttyUSB*','/dev/ttyACM*'):
        for p in sorted(pathlib.Path('/').glob(pat.lstrip('/'))):
            try:r=str(p.resolve())
            except OSError:r=str(p)
            if r not in seen: seen.add(r); vals.append(str(p))
    return vals
def nets():
    data=json.loads(subprocess.check_output(['ip','-j','link','show'],text=True)); out=[]
    for x in data:
        n=x.get('ifname','')
        if n!='lo' and not re.match(r'^(docker|podman|veth|virbr|br-|tun|tap|wg)',n):out.append(n)
    return out

def ensure_artifact(path: pathlib.Path,target:str):
    if path.is_file():return
    print(f'[rv220w] {path.name} is missing; building it now.')
    subprocess.run(['make',target],cwd=ROOT,check=True)
    if not path.is_file():raise SystemExit(f'build completed but artifact is still missing: {path}')

def artifact_paths(force_prebuilt:bool,force_built:bool):
    built=(ART/INIT_NAME,ART/SYS_NAME)
    prebuilt=(PREBUILT/INIT_NAME,PREBUILT/SYS_NAME)
    prebuilt_ready=all(path.is_file() for path in prebuilt)
    if force_prebuilt:
        if not prebuilt_ready:raise SystemExit(f'complete prebuilt image pair not found in {PREBUILT}')
        subprocess.run(['make','prebuilt-check'],cwd=ROOT,check=True)
        return prebuilt
    if force_built:return built
    if prebuilt_ready:
        answer=input(f'Use bundled hardware-qualified RC7 images from {PREBUILT}? [Y/n]: ').strip().lower()
        if answer in ('','y','yes'):
            subprocess.run(['make','prebuilt-check'],cwd=ROOT,check=True)
            return prebuilt
        print('[rv220w] Using artifacts built from source instead.')
    return built

def latest_serial_log():
    logs=sorted(LOGS.glob('rv220w-tftp-boot-*.serial.log'),key=lambda p:p.stat().st_mtime,reverse=True)
    return logs[0] if logs else None

class Shell:
    def __init__(self,port,log):
        import serial
        self.s=serial.Serial(port,115200,timeout=.05,write_timeout=2,xonxoff=False,rtscts=False,dsrdtr=False,exclusive=True); self.log=log
    def close(self):self.s.close();self.log.close()
    def send(self,b):self.s.write(b);self.s.flush()
    def read(self):
        n=self.s.in_waiting;d=self.s.read(max(1,min(n or 1,65536)))
        if d:self.log.write(d);self.log.flush();sys.stdout.buffer.write(d);sys.stdout.buffer.flush()
        return d
    def wait_prompt(self,timeout=20):
        end=time.monotonic()+timeout;b=bytearray()
        while time.monotonic()<end:
            d=self.read()
            if d:
                b.extend(d)
                if re.search(rb'root@[^\r\n:]+:[^\r\n]*# $',bytes(b[-2048:])):return bytes(b)
            else:time.sleep(.01)
        raise RuntimeError('OpenWrt root shell prompt not observed')
    def cmd(self,c,timeout=30):
        self.s.reset_input_buffer();self.send(c.encode()+b'\r');return self.wait_prompt(timeout)
    def run_direct_installer(self,c,timeout=420):
        self.s.reset_input_buffer();self.send(c.encode()+b'\r');end=time.monotonic()+timeout;b=bytearray()
        pass_seen=False; reboot_seen=False; linux_seen=False
        required=(
            b'RV220W_DIRECT_INSTALL_VALIDATION_PASS',
            b'RV220W_DIRECT_INSTALL_ROOTFS_PASS',
            b'RV220W_DIRECT_INSTALL_KERNEL_PASS',
            b'RV220W_DIRECT_INSTALL_PASS',
        )
        while time.monotonic()<end:
            d=self.read()
            if d:
                b.extend(d)
                if len(b)>4*1024*1024: del b[:-2*1024*1024]
                tail=bytes(b)
                if b'RV220W_DIRECT_INSTALL_ERROR:' in tail:
                    return tail,False,False,False
                if all(m in tail for m in required):pass_seen=True
                if pass_seen and (b'U-Boot 1.1.1' in tail or b'CUST_RV200W board revision' in tail):reboot_seen=True
                if reboot_seen and b'Linux version ' in tail:linux_seen=True;return tail,True,True,True
                # If the direct installer unexpectedly returns to an initramfs
                # shell before its PASS marker, preserve the UART evidence and
                # fail rather than treating a reboot/watchdog reset as success.
                if not pass_seen and re.search(rb'root@[^\r\n:]+:[^\r\n]*# $',tail[-4096:]):
                    return tail,False,reboot_seen,linux_seen
            else:time.sleep(.01)
        return bytes(b),pass_seen,reboot_seen,linux_seen

def add_ip(iface,addr):
    data=json.loads(subprocess.check_output(['ip','-j','-4','addr','show','dev',iface],text=True));has=any(a.get('local')==addr.split('/')[0] for x in data for a in x.get('addr_info',[]))
    if has:return False
    subprocess.run(['sudo','ip','link','set',iface,'up'],check=True);subprocess.run(['sudo','ip','addr','add',addr,'dev',iface],check=True);return True

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--serial');ap.add_argument('--interface');ap.add_argument('--no-sysupgrade-prompt',action='store_true')
    source=ap.add_mutually_exclusive_group();source.add_argument('--prebuilt',action='store_true',help='use the bundled qualified images without prompting');source.add_argument('--built',action='store_true',help='use or build images under the build workspace without prompting');ns=ap.parse_args()
    init,sysupgrade=artifact_paths(ns.prebuilt,ns.built)
    ensure_artifact(init,'initramfs')
    port=choose(serials(),'UART port',ns.serial);iface=choose(nets(),'directly-connected Ethernet interface',ns.interface)
    print('\nConnect this Ethernet interface directly to one of the FOUR RV220W LAN ports.')
    print('The helper will use 192.168.240.1/24 only for U-Boot TFTP; OpenWrt itself comes up at 192.168.1.1.')
    LOGS.mkdir(parents=True,exist_ok=True)
    helper=ROOT/'scripts/host/rv220w_tftp_boot.py'
    cmd=[sys.executable,str(helper),port,str(init),'--interface',iface,'--configure-interface','--server-ip','192.168.240.1','--device-ip','192.168.240.2','--test-subnet','192.168.240.0/24','--boot-timeout','150','--log-dir',str(LOGS)]
    subprocess.run(cmd,check=True)
    log=latest_serial_log()
    if not log:raise SystemExit('liveboot completed without a serial log')
    capture=log.read_bytes()
    markers=(b'OpenWrt',b'Please press Enter to activate this console',b'root@')
    if not any(m in capture for m in markers):raise SystemExit(f'OpenWrt boot success was not observed; inspect {log}')
    print(f'\n[rv220w] Live OpenWrt boot observed. Serial log: {log}')
    print('[rv220w] LuCI/default LAN will be http://192.168.1.1/ once networking settles.')
    if ns.no_sysupgrade_prompt:return 0
    answer=input('\nStart the permanent release install from this RAM boot? [y/N]: ').strip().lower()
    if answer not in ('y','yes'):
        print('Leaving the router in RAM-only OpenWrt. Power cycling returns to the previous NOR contents.');return 0
    ensure_artifact(sysupgrade,'sysupgrade')
    subprocess.run(['sudo','-v'],check=True);added=add_ip(iface,'192.168.1.2/24')
    http_log=(LOGS/'rv220w-liveboot-http.log').open('ab')
    http=subprocess.Popen([sys.executable,'-m','http.server','8000','--bind','192.168.1.2','--directory',str(sysupgrade.parent)],stdout=http_log,stderr=subprocess.STDOUT)
    time.sleep(1)
    if http.poll() is not None:raise SystemExit('temporary HTTP server failed to start')
    shell=None
    try:
        install_log=LOGS/'rv220w-liveboot-sysupgrade.serial.log'
        print(f'[rv220w] Persistent install UART log: {install_log}')
        shell=Shell(port,install_log.open('ab'))
        shell.send(b'\r');shell.wait_prompt(20)
        hostsha=hashlib.sha256(sysupgrade.read_bytes()).hexdigest()
        remote='/tmp/rv220w-openwrt-release-sysupgrade.tar'
        print('\n[rv220w] Installer memory before sysupgrade download:')
        shell.cmd("grep -E '^(MemTotal|MemFree|MemAvailable|Buffers|Cached|Shmem):' /proc/meminfo",10)
        shell.cmd(f'wget -O {remote} http://192.168.1.2:8000/{sysupgrade.name}',120)
        out=shell.cmd(f'sha256sum {remote}',30).decode(errors='replace')
        if hostsha not in out:raise RuntimeError('target sysupgrade SHA256 does not match host artifact')
        print('\n[rv220w] Running low-memory target sysupgrade validation...')
        test=shell.cmd(f'sysupgrade -T {remote}',180).decode(errors='replace')
        oom_tokens=('oom-killer','Out of memory: Killed process','Killed process')
        if any(tok in test for tok in oom_tokens):
            raise RuntimeError('target ran out of RAM during sysupgrade validation; no flash was requested. Inspect the liveboot serial log for memory-pressure details')
        if 'Image check failed' in test or 'not compatible' in test.lower():
            raise RuntimeError('target sysupgrade -T rejected the image after completing without an OOM condition')
        print('\nSysupgrade preflight: PASS')
        print('The router is already running entirely from the release initramfs, so the permanent installer will write from RAM directly instead of entering OpenWrt stage2 a second time.')
        print('The validated sysupgrade image is streamed rootfs-first/kernel-last with SHA-256 readback verification; boot-chain and uboot-env remain untouched.')
        confirm=input('Type INSTALL RV220W to write kernel/rootfs now: ').strip()
        if confirm!='INSTALL RV220W':print('Cancelled; the RAM boot remains active and NOR was not changed by this step.');return 0
        installer='/usr/sbin/rv220w-install-from-ram'
        print('\n[rv220w] Starting direct RAM-installer write. UART capture will remain active through write, verification, and reboot.')
        cap,passed,reboot_seen,linux_seen=shell.run_direct_installer(f'{installer} {remote}',420)
        text=cap.decode(errors='replace')
        if 'RV220W_DIRECT_INSTALL_ERROR:' in text:
            raise RuntimeError('direct RAM installer reported an error; inspect rv220w-liveboot-sysupgrade.serial.log. The last completed PASS marker identifies whether any partition was written')
        if not passed:
            raise RuntimeError('direct RAM installer did not reach its verified PASS marker; inspect rv220w-liveboot-sysupgrade.serial.log before retrying')
        print('\n[rv220w] Direct RAM installer verified rootfs and kernel writes successfully.')
        if linux_seen:
            print('[rv220w] Normal NOR Linux reboot observed on UART.')
        elif reboot_seen:
            print('[rv220w:warning] U-Boot reboot was observed, but the persistent Linux banner was not seen before the capture timeout.')
        else:
            print('[rv220w:warning] Flash verification passed, but the subsequent reboot was not observed before the capture timeout.')
        print('[rv220w] Expected first-boot management address: http://192.168.1.1/')
    finally:
        if shell:
            try:shell.close()
            except Exception:pass
        http.terminate();
        try:http.wait(3)
        except subprocess.TimeoutExpired:http.kill()
        http_log.close()
        if added:subprocess.run(['sudo','ip','addr','del','192.168.1.2/24','dev',iface],check=False)
    return 0
if __name__=='__main__':
    try:
        raise SystemExit(main())
    except (RuntimeError, subprocess.CalledProcessError, OSError) as exc:
        print(f'\n[rv220w:error] {exc}',file=sys.stderr)
        raise SystemExit(1)
