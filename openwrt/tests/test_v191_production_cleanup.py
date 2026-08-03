#!/usr/bin/env python3
"""Validate v1.9.1 production DTS and runtime cleanup."""
from pathlib import Path
import re, subprocess, tempfile
ROOT=Path(__file__).resolve().parents[1]
DTS=ROOT/'openwrt/production/cn5010_cisco_rv220w-production.dts.in'
PATCH=ROOT/'openwrt/production/999-octeon-production-dt-flash-cleanups.patch'
CONFIG=ROOT/'config/openwrt-rv220w-rj45-initramfs.config'
STATUS=ROOT/'openwrt/files-rj45-full/usr/sbin/rv220w-rj45-status'
SERVICES=ROOT/'openwrt/files-rj45-full/etc/uci-defaults/99-rv220w-rj45-services'
BUILD=ROOT/'scripts/inner/build-openwrt.sh'
BOOT_EVIDENCE=ROOT/'evidence/run10-rj45-v190-boot'

def fail(msg): raise SystemExit(msg)
for p in (DTS,PATCH,CONFIG,STATUS,SERVICES,BUILD):
    if not p.is_file(): fail(f'missing {p.relative_to(ROOT)}')

for name in ('README.md','rv220w-v1.9.0-runtime-status.txt','rv220w-tftp-boot-20260727T025422Z.tftp.log','rv220w-tftp-boot-20260727T025422Z.serial.log'):
    if not (BOOT_EVIDENCE/name).is_file(): fail(f'missing v1.9.0 boot evidence: {name}')

d=DTS.read_text()
for token in (
    'rv220w_eth0: ethernet@0 {','rv220w_eth1: ethernet@1 {',
    'compatible = "cavium,octeon-3860-bootbus-flash";',
    'ethernet = <&rv220w_eth1>;','ethernet = <&rv220w_eth0>;',
    'phy-mode = "@WAN_PHY_MODE@";','phy-mode = "rgmii-rxid";',
    '/delete-node/ compact-flash@5,0;', 'nor@0,0 {',
):
    if token not in d: fail(f'production DTS lacks {token}')
if d.count('fixed-link {') < 4: fail('production DTS lacks both MAC and both switch fixed-links')
if re.search(r'^[\t ]*bank-width\s*=', d, re.M): fail('production DTS must not fake a generic physmap bank-width')
if 'compatible = "cfi-flash"' in d: fail('production NOR still allows generic physmap ownership')

p=PATCH.read_text()
for token in ('early_init_dt_verify(initial_boot_params,',
              '__pa(initial_boot_params))',
              'cavium,octeon-3860-bootbus-flash',
              'arch/mips/cavium-octeon/setup.c',
              'arch/mips/cavium-octeon/flash_setup.c'):
    if token not in p: fail(f'patch999 lacks {token}')

cfg=CONFIG.read_text()
for forbidden in ('CONFIG_PACKAGE_kmod-mdio-netlink=y','CONFIG_PACKAGE_mdio-tools=y'):
    if forbidden in cfg: fail(f'production config retains diagnostic package: {forbidden}')

s=STATUS.read_text()
for token in ('nft list table inet fw4','firewall=loaded','/proc/mtd','/sys/firmware/fdt','/proc/sys/kernel/tainted','ethtool -S'):
    if token not in s: fail(f'status helper lacks {token}')
for forbidden in ('rv220w-b53-snapshot','mdio '):
    if forbidden in s: fail(f'status helper retains raw diagnostic token: {forbidden}')

svc=SERVICES.read_text()
for token in ('Allow-IPSec-ESP|Allow-ISAKMP', '$dropbear.Interface=lan'):
    if token not in svc: fail(f'service cleanup lacks {token}')

b=BUILD.read_text()
for token in ('openwrt/production/cn5010_cisco_rv220w-production.dts.in',
              '999-octeon-production-dt-flash-cleanups.patch',
              'files/usr/sbin/rv220w-b53-snapshot'):
    if token not in b: fail(f'build path lacks cleanup token: {token}')

subprocess.run(['sh','-n',str(STATUS)],check=True)
subprocess.run(['sh','-n',str(SERVICES)],check=True)
subprocess.run(['bash','-n',str(BUILD)],check=True)

# Apply the two patch hunks to exact source-shaped fixtures.
def old_hunks(text):
    lines=text.splitlines(); out=[]; i=0
    hr=re.compile(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@')
    current_path=None
    while i < len(lines):
        if lines[i].startswith('--- a/'):
            current_path=lines[i][6:]; i+=1; continue
        m=hr.match(lines[i])
        if not m: i+=1; continue
        start=int(m.group(1)); old=[]; i+=1
        while i<len(lines) and not lines[i].startswith('@@ ') and not lines[i].startswith('--- a/') and lines[i] != '-- ':
            line=lines[i]
            if line.startswith(' '): old.append(line[1:])
            elif line.startswith('-') and not line.startswith('---'): old.append(line[1:])
            elif line.startswith('+'): pass
            else: break
            i+=1
        out.append((current_path,start,old))
    return out
hunks=old_hunks(p)
if len(hunks)!=2: fail(f'expected 2 patch hunks, got {len(hunks)}')
with tempfile.TemporaryDirectory(prefix='rv220w-v191-patch-') as td:
    tree=Path(td)
    for path,start,old in hunks:
        f=tree/path; f.parent.mkdir(parents=True,exist_ok=True)
        fixture=[f'/* filler {n+1} */' for n in range(start+len(old)+20)]
        fixture[start-1:start-1+len(old)]=old
        f.write_text('\n'.join(fixture)+'\n')
    r=subprocess.run(['patch','--batch','--forward','-p1','-i',str(PATCH)],cwd=tree,text=True,capture_output=True)
    if r.returncode: fail('patch999 synthetic application failed:\n'+r.stdout+r.stderr)
    setup_after=(tree/'arch/mips/cavium-octeon/setup.c').read_text()
    if 'early_init_dt_verify(initial_boot_params,' not in setup_after or '__pa(initial_boot_params))' not in setup_after: fail('CRC refresh missing after apply')
    if 'cavium,octeon-3860-bootbus-flash' not in (tree/'arch/mips/cavium-octeon/flash_setup.c').read_text(): fail('flash compatible missing after apply')
print('v1.9.1 production cleanup checks passed')
