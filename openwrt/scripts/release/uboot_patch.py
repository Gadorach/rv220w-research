#!/usr/bin/env python3
"""Guided RV220W U-Boot verification/bootstrap.

Compatibility is deliberately decided only from the preserved bootloader code
region, never from Cisco kernel/rootfs/config contents.  Before any write the
operator may choose either a complete 32 MiB archival backup or a much faster
backup of the two bootloader-owned regions (512 KiB boot-chain + 128 KiB
U-Boot environment).
"""
from __future__ import annotations

import argparse
import binascii
import datetime as dt
import grp
import hashlib
import json
import os
import pathlib
import pwd
import re
import shutil
import subprocess
import sys
import tempfile
import time

ROOT = pathlib.Path(__file__).resolve().parents[2]
WORKSPACE = pathlib.Path(os.environ.get("RV220W_WORKSPACE", ROOT / "build")).expanduser().resolve()
PROMPT = b"rv200w# "
FLASH_BASE = 0xBDC00000
FLASH_SIZE = 0x02000000
BOOT_CHAIN_SIZE = 0x00080000
SECTOR_SIZE = 0x00020000
UBOOT_ENV_SIZE = 0x00020000
UBOOT_ENV_BASE = FLASH_BASE + FLASH_SIZE - UBOOT_ENV_SIZE
FLASH_END = FLASH_BASE + SECTOR_SIZE - 1
RAM = 0x05500000
EXPECTED_PATCHED_CRC = 0xB77A94DE
PATCHES = (
    (0x13138, bytes.fromhex("04410003"), bytes.fromhex("10000003"), "invalid-magic HTTP recovery bypass"),
    (0x13168, bytes.fromhex("03200008"), bytes.fromhex("03e00008"), "bootcmd overwrite bypass"),
)
OPENWRT_BOOT = (
    "cp.b 0xbdc80000 0x05500000 0x600000; "
    "gunzip 0x05500000 0x600000 0x06500000 0x1a00000; "
    "bootoctlinux 0x06500000 console=ttyS0,115200"
)


def stamp() -> str:
    return dt.datetime.now(dt.timezone.utc).strftime("%Y%m%dT%H%M%SZ")


def sha256_file(path: pathlib.Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for block in iter(lambda: fh.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


def choose(items: list[str], label: str, override: str | None = None) -> str:
    if override:
        return override
    if not items:
        raise RuntimeError(f"no {label} candidates found")
    print(f"\nAvailable {label}:")
    for i, item in enumerate(items, 1):
        print(f"  {i}) {item}")
    while True:
        s = input(f"Select {label} [1-{len(items)}]: ").strip()
        if s.isdigit() and 1 <= int(s) <= len(items):
            return items[int(s) - 1]


def serial_candidates() -> list[str]:
    out: list[tuple[str, str]] = []
    for pat in ("/dev/serial/by-id/*", "/dev/ttyUSB*", "/dev/ttyACM*"):
        for p in sorted(pathlib.Path("/").glob(pat.lstrip("/"))):
            display = str(p)
            try:
                resolved = str(p.resolve())
            except OSError:
                resolved = display
            if resolved not in [x[1] for x in out]:
                out.append((display, resolved))
    return [x[0] for x in out]


def net_candidates() -> list[str]:
    data = json.loads(subprocess.check_output(["ip", "-j", "link", "show"], text=True))
    result: list[str] = []
    for item in data:
        name = item.get("ifname", "")
        if name == "lo" or re.match(r"^(docker|podman|veth|virbr|br-|tun|tap|wg)", name):
            continue
        result.append(name)
    return result


def proc_uart_holders(port: str) -> list[tuple[int, str]]:
    """Best-effort same-host holder discovery without requiring lsof/fuser."""
    try:
        target = pathlib.Path(port).resolve()
    except OSError:
        target = pathlib.Path(port)
    holders: list[tuple[int, str]] = []
    me = os.getpid()
    for proc in pathlib.Path("/proc").iterdir():
        if not proc.name.isdigit():
            continue
        pid = int(proc.name)
        if pid == me:
            continue
        fd_dir = proc / "fd"
        try:
            fds = list(fd_dir.iterdir())
        except (PermissionError, FileNotFoundError):
            continue
        found = False
        for fd in fds:
            try:
                if fd.resolve() == target:
                    found = True
                    break
            except (OSError, PermissionError):
                continue
        if not found:
            continue
        try:
            raw = (proc / "cmdline").read_bytes().replace(b"\0", b" ").decode(errors="replace").strip()
        except (OSError, PermissionError):
            raw = ""
        holders.append((pid, raw or "<unknown command>"))
    return holders


def require_uart_free(port: str) -> None:
    holders = proc_uart_holders(port)
    if holders:
        lines = [f"UART is already open: {port}"]
        for pid, cmd in holders:
            lines.append(f"  PID {pid}: {cmd}")
        lines.append("Close the serial terminal/process and rerun the command. No router state was changed.")
        raise RuntimeError("\n".join(lines))
    try:
        import serial  # type: ignore
        ser = serial.Serial(
            port,
            115200,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.05,
            write_timeout=1.0,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
            exclusive=True,
        )
        ser.close()
    except Exception as exc:
        raise RuntimeError(
            f"cannot claim UART {port} exclusively: {exc}\n"
            "Close picocom/minicom/screen/another RV220W helper and retry. No router state was changed."
        ) from exc


def choose_backup_scope(requested: str | None, assume_yes: bool = False) -> str:
    if requested:
        scope = requested
    else:
        print("\nBackup scope before bootloader verification/onboarding:")
        print("  1) Complete 32 MiB NOR image (slowest; best archival recovery)")
        print("  2) Bootloader regions only: 512 KiB boot-chain + 128 KiB U-Boot environment (fast)")
        while True:
            s = input("Select backup scope [1-2, default 1]: ").strip() or "1"
            if s in ("1", "2"):
                scope = "full" if s == "1" else "bootloader"
                break
    if scope == "bootloader" and not assume_yes:
        print("\nWARNING: the fast backup preserves every NOR region this helper can modify,")
        print("but it does NOT preserve the Cisco kernel/rootfs/config partitions.")
        print("This is sufficient for U-Boot verification/recovery, not for reconstructing the entire original firmware image.")
        if input("Type BOOTLOADER BACKUP ONLY to continue: ").strip() != "BOOTLOADER BACKUP ONLY":
            raise RuntimeError("bootloader-only backup not acknowledged")
    return scope


def validate_boot_chain(boot_chain: pathlib.Path, candidate_sector: pathlib.Path) -> dict:
    blob = boot_chain.read_bytes()
    if len(blob) != BOOT_CHAIN_SIZE:
        raise RuntimeError(f"boot-chain backup size is {len(blob)}, expected {BOOT_CHAIN_SIZE}")
    sec = bytearray(blob[:SECTOR_SIZE])
    original_sector_crc = crc32(sec)
    states: list[dict[str, str]] = []
    for off, stock, target, name in PATCHES:
        got = bytes(sec[off : off + 4])
        if got == stock:
            state = "stock"
        elif got == target:
            state = "patched"
        else:
            raise RuntimeError(
                f"bootloader compatibility FAIL at 0x{off:x}: got {got.hex()}, "
                f"expected stock {stock.hex()} or qualified {target.hex()}"
            )
        states.append({"name": name, "state": state, "offset": hex(off), "bytes": got.hex()})
        sec[off : off + 4] = target
    patched_crc = crc32(sec)
    if patched_crc != EXPECTED_PATCHED_CRC:
        raise RuntimeError(
            f"bootloader compatibility FAIL: candidate patched sector CRC32 {patched_crc:08x}, "
            f"expected {EXPECTED_PATCHED_CRC:08x}. The rest of NOR is intentionally ignored."
        )
    state_set = {x["state"] for x in states}
    if state_set == {"patched"}:
        if original_sector_crc != EXPECTED_PATCHED_CRC:
            raise RuntimeError(
                f"bootloader patch bytes are present but sector CRC32 is {original_sector_crc:08x}, "
                f"not qualified {EXPECTED_PATCHED_CRC:08x}; refusing heuristic repair"
            )
        code_state = "qualified-patched"
    elif state_set == {"stock"}:
        code_state = "stock-compatible"
    else:
        code_state = "partially-patched-compatible"
    candidate_sector.write_bytes(sec)
    return {
        "code_state": code_state,
        "boot_chain_sha256": sha256_file(boot_chain),
        "boot_chain_crc32": f"{crc32(blob):08x}",
        "sector0_original_crc32": f"{original_sector_crc:08x}",
        "sector0_patched_crc32": f"{patched_crc:08x}",
        "patch_sites": states,
    }


def run_dump(port: str, output: pathlib.Path, base: int, size: int, label: str) -> None:
    dump = ROOT / "scripts/host/dump_uboot_flash_uart.py"
    print(f"\n[rv220w] Backing up {label} (0x{size:x} bytes).", file=sys.stderr)
    cmd = [
        sys.executable,
        str(dump),
        port,
        "--output",
        str(output),
        "--base",
        hex(base),
        "--size",
        hex(size),
        "--target-baud",
        "460800",
        "--restart",
    ]
    result = subprocess.run(cmd)
    if result.returncode != 0:
        raise RuntimeError(f"{label} backup failed with status {result.returncode}")


def backup_regions(port: str, backup_dir: pathlib.Path, scope: str) -> tuple[pathlib.Path, pathlib.Path, dict]:
    full = backup_dir / "rv220w-flash-32MiB.bin"
    boot_chain = backup_dir / "rv220w-boot-chain-512KiB.bin"
    env = backup_dir / "rv220w-uboot-env-128KiB.bin"
    meta: dict[str, object] = {"scope": scope}
    if scope == "full":
        print("\n[rv220w] Dumping the complete 32 MiB NOR. Compatibility will still be checked only against the bootloader region.", file=sys.stderr)
        run_dump(port, full, FLASH_BASE, FLASH_SIZE, "complete 32 MiB NOR")
        blob = full.read_bytes()
        if len(blob) != FLASH_SIZE:
            raise RuntimeError("full NOR backup has unexpected size")
        boot_chain.write_bytes(blob[:BOOT_CHAIN_SIZE])
        env.write_bytes(blob[-UBOOT_ENV_SIZE:])
        meta.update({"full_nor": str(full), "full_nor_sha256": sha256_file(full)})
    else:
        print("\n[rv220w] Fast backup selected: dumping only bootloader-owned NOR regions.", file=sys.stderr)
        run_dump(port, boot_chain, FLASH_BASE, BOOT_CHAIN_SIZE, "512 KiB boot-chain")
        run_dump(port, env, UBOOT_ENV_BASE, UBOOT_ENV_SIZE, "128 KiB U-Boot environment")
    meta.update(
        {
            "boot_chain": str(boot_chain),
            "boot_chain_sha256": sha256_file(boot_chain),
            "uboot_env": str(env),
            "uboot_env_sha256": sha256_file(env),
        }
    )
    return boot_chain, env, meta


class Console:
    def __init__(self, port: str, log_handle):
        import serial  # type: ignore
        self.s = serial.Serial(
            port,
            115200,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.05,
            write_timeout=2,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
            exclusive=True,
        )
        self.log = log_handle

    def close(self) -> None:
        self.s.close()

    def read(self) -> bytes:
        waiting = self.s.in_waiting
        data = self.s.read(max(1, min(waiting or 1, 65536)))
        if data:
            self.log.write(data)
            self.log.flush()
            sys.stdout.buffer.write(data)
            sys.stdout.buffer.flush()
        return data

    def wait(self, timeout: float = 10) -> bytes:
        end = time.monotonic() + timeout
        buf = bytearray()
        while time.monotonic() < end:
            data = self.read()
            if data:
                buf.extend(data)
                if bytes(buf).endswith(PROMPT):
                    return bytes(buf)
            else:
                time.sleep(0.002)
        raise RuntimeError("timeout waiting for rv200w# prompt")

    def cmd(self, command: str, timeout: float = 10) -> bytes:
        print(f"\n[rv220w] U-Boot> {command}", file=sys.stderr)
        self.s.reset_input_buffer()
        self.s.write(command.encode() + b"\r")
        self.s.flush()
        response = self.wait(timeout)
        low = response.lower()
        if b"unknown command" in low or (b"usage:" in low) or (
            b"error" in low and command.split()[0] in ("protect", "erase", "cp.b")
        ):
            raise RuntimeError(f"U-Boot rejected command: {command}")
        return response


def read_environment(port: str, rawlog: pathlib.Path) -> tuple[dict[str, str | None], bool]:
    with rawlog.open("ab") as log:
        console = Console(port, log)
        try:
            response = console.cmd("printenv openwrt_boot bootcmd bootdelay preboot")
        finally:
            console.close()
    text = response.decode(errors="replace")
    values: dict[str, str | None] = {}
    for key in ("openwrt_boot", "bootcmd", "bootdelay", "preboot"):
        match = re.search(rf"(?m)^{re.escape(key)}=(.*)\r?$", text)
        values[key] = match.group(1).strip() if match else None
    qualified = (
        values["openwrt_boot"] == OPENWRT_BOOT
        and values["bootcmd"] == "run openwrt_boot"
        and values["bootdelay"] == "3"
        and values["preboot"] in (None, "")
    )
    return values, qualified


def start_tftp(image: pathlib.Path, iface: str, log: pathlib.Path):
    subprocess.run(["sudo", "-v"], check=True)
    subprocess.run(["sudo", "ip", "link", "set", iface, "up"], check=True)
    addr = json.loads(subprocess.check_output(["ip", "-j", "-4", "addr", "show", "dev", iface], text=True))
    has = any(a.get("local") == "192.168.240.1" for x in addr for a in x.get("addr_info", []))
    added = False
    if not has:
        subprocess.run(["sudo", "ip", "addr", "add", "192.168.240.1/24", "dev", iface], check=True)
        added = True
    td = tempfile.TemporaryDirectory(prefix="rv220w-uboot-tftp-")
    root = pathlib.Path(td.name)
    os.chmod(root, 0o755)
    target = root / "rv220w-sector0.bin"
    shutil.copy2(image, target)
    os.chmod(target, 0o644)
    user = pwd.getpwuid(os.getuid()).pw_name
    group = grp.getgrgid(os.getgid()).gr_name
    fh = log.open("ab")
    proc = subprocess.Popen(
        [
            "sudo",
            "dnsmasq",
            "--no-daemon",
            "--port=0",
            "--log-facility=-",
            "--bind-interfaces",
            f"--interface={iface}",
            "--listen-address=192.168.240.1",
            "--enable-tftp",
            f"--tftp-root={root}",
            "--tftp-mtu=544",
            "--tftp-max=16",
            f"--user={user}",
            f"--group={group}",
        ],
        stdout=fh,
        stderr=subprocess.STDOUT,
    )
    time.sleep(1)
    if proc.poll() is not None:
        raise RuntimeError("dnsmasq TFTP server failed to start")
    return proc, fh, td, added


def select_existing_action(code_state: str, env_ok: bool) -> str:
    if code_state != "qualified-patched":
        return "patch"
    print("\n[rv220w] Qualified patched U-Boot detected.")
    print(f"[rv220w] Saved OpenWrt environment: {'PASS' if env_ok else 'NEEDS REPAIR'}")
    if env_ok:
        print("  1) Verify only / leave U-Boot unchanged (recommended)")
        print("  2) Re-save the qualified OpenWrt environment only")
        print("  3) FORCE rewrite the already-qualified sector 0 and environment (automation test)")
        default = "1"
        mapping = {"1": "none", "2": "env", "3": "force"}
    else:
        print("  1) Repair the OpenWrt environment only (recommended)")
        print("  2) FORCE rewrite the already-qualified sector 0 and repair the environment")
        print("  3) Cancel")
        default = "1"
        mapping = {"1": "env", "2": "force", "3": "none"}
    while True:
        answer = input(f"Select action [default {default}]: ").strip() or default
        if answer in mapping:
            return mapping[answer]


def write_environment(console: Console) -> None:
    console.cmd("setenv openwrt_boot '" + OPENWRT_BOOT + "'")
    console.cmd("setenv bootdelay 3")
    console.cmd("setenv preboot")
    console.cmd("setenv bootcmd 'run openwrt_boot'")
    console.cmd("saveenv", 30)
    response = console.cmd("printenv openwrt_boot bootcmd bootdelay preboot")
    text = response.decode(errors="replace")
    for required in ("bootcmd=run openwrt_boot", "bootdelay=3", "openwrt_boot=cp.b 0xbdc80000"):
        if required not in text:
            raise RuntimeError(f"saved environment verification missing: {required}")


def perform_write(port: str, iface: str | None, sector: pathlib.Path, action: str, rawlog: pathlib.Path, backup_dir: pathlib.Path) -> None:
    sector_write = action in ("patch", "force")
    if action == "env":
        print("\nWARNING: continuing will write the U-Boot environment with saveenv.")
        phrase = "REPAIR RV220W U-BOOT ENV"
    else:
        print("\nWARNING: continuing will ERASE AND REWRITE the first 128 KiB NOR sector and then save the U-Boot environment.")
        if action == "force":
            print("The sector is already qualified; this forced rewrite exists only to exercise/test the automated write path.")
        print("The validated patch changes only the known U-Boot policy instructions; the recovery-button path remains intact.")
        phrase = "PATCH RV220W U-BOOT"
    if input(f"Type {phrase} to continue: ").strip() != phrase:
        print("Cancelled; backups retained and no NOR write performed.")
        return

    proc = fh = td = None
    added = False
    console = None
    console_log = None
    try:
        if sector_write:
            if not iface:
                raise RuntimeError("directly-connected Ethernet interface is required for sector rewrite")
            proc, fh, td, added = start_tftp(sector, iface, backup_dir / "tftp.log")
        console_log = rawlog.open("ab")
        console = Console(port, console_log)
        if sector_write:
            console.cmd("base 0")
            console.cmd("setenv autoload no")
            console.cmd("setenv netretry no")
            console.cmd("setenv ipaddr 192.168.240.2")
            console.cmd("setenv serverip 192.168.240.1")
            console.cmd("setenv netmask 255.255.255.0")
            transferred = False
            for eth in ("octeth0", "octeth1", "octeth2"):
                console.cmd(f"setenv ethact {eth}")
                response = console.cmd("tftpboot 0x05500000 rv220w-sector0.bin", 120)
                if re.search(rb"Bytes transferred\s*=\s*131072\b", response):
                    transferred = True
                    break
            if not transferred:
                raise RuntimeError("failed to TFTP the exact 128 KiB sector image")
            response = console.cmd("crc32 0x05500000 0x20000")
            if not any(int(x, 16) == EXPECTED_PATCHED_CRC for x in re.findall(rb"([0-9A-Fa-f]{8})", response)):
                raise RuntimeError("RAM sector CRC did not match qualified b77a94de")
            console.cmd(f"protect off 0x{FLASH_BASE:08x} 0x{FLASH_END:08x}", 20)
            console.cmd(f"erase 0x{FLASH_BASE:08x} 0x{FLASH_END:08x}", 60)
            console.cmd(f"cp.b 0x{RAM:08x} 0x{FLASH_BASE:08x} 0x{SECTOR_SIZE:x}", 60)
            response = console.cmd(f"crc32 0x{FLASH_BASE:08x} 0x{SECTOR_SIZE:x}", 20)
            if not any(int(x, 16) == EXPECTED_PATCHED_CRC for x in re.findall(rb"([0-9A-Fa-f]{8})", response)):
                raise RuntimeError("FLASH VERIFY FAILED: sector-0 CRC is not b77a94de")
            console.cmd(f"protect on 0x{FLASH_BASE:08x} 0x{FLASH_END:08x}", 20)
        write_environment(console)
        print("\nRV220W U-Boot bootstrap complete.")
        print(f"Recovery backup retained at: {backup_dir}")
    finally:
        if console:
            try:
                console.close()
            except Exception:
                pass
        if console_log:
            try:
                console_log.close()
            except Exception:
                pass
        if proc:
            proc.terminate()
            try:
                proc.wait(3)
            except subprocess.TimeoutExpired:
                proc.kill()
        if fh:
            try:
                fh.close()
            except Exception:
                pass
        if td:
            try:
                td.cleanup()
            except Exception:
                pass
        if added and iface:
            subprocess.run(["sudo", "ip", "addr", "del", "192.168.240.1/24", "dev", iface], check=False)


def parse_args() -> argparse.Namespace:
    ap = argparse.ArgumentParser()
    ap.add_argument("--serial")
    ap.add_argument("--interface")
    ap.add_argument("--backup-scope", choices=("full", "bootloader"))
    ap.add_argument("--verify-only", action="store_true", help="Back up/inspect bootloader regions and environment; never write NOR")
    ap.add_argument("--ack-bootloader-only-backup", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--dry-run", action="store_true")
    return ap.parse_args()


def main() -> int:
    ns = parse_args()
    port = choose(serial_candidates(), "UART port", ns.serial)
    if ns.dry_run:
        scope = ns.backup_scope or "full"
        print(
            json.dumps(
                {
                    "serial": port,
                    "backup_scope": scope,
                    "compatibility_scope": "512KiB boot-chain / qualified 128KiB sector0 only",
                    "boot_chain": f"0x{FLASH_BASE:08x}+0x{BOOT_CHAIN_SIZE:x}",
                    "uboot_env": f"0x{UBOOT_ENV_BASE:08x}+0x{UBOOT_ENV_SIZE:x}",
                    "patched_crc32": f"{EXPECTED_PATCHED_CRC:08x}",
                    "openwrt_boot": OPENWRT_BOOT,
                    "verify_only": ns.verify_only,
                },
                indent=2,
            )
        )
        return 0

    require_uart_free(port)
    scope = choose_backup_scope(ns.backup_scope, ns.ack_bootloader_only_backup)
    backup_dir = WORKSPACE / "backups" / f"uboot-bootstrap-{stamp()}"
    rawlog = backup_dir / "uboot-session.log"
    sector = backup_dir / "rv220w-sector0-qualified.bin"
    backup_dir.mkdir(parents=True)

    print("\nJP1 UART must be 115200 8N1; leave the adapter VCC pin disconnected.")
    wait = ROOT / "scripts/host/wait_uboot_prompt.py"
    wait_result = subprocess.run([sys.executable, str(wait), port, "--log", str(rawlog)])
    if wait_result.returncode != 0:
        raise RuntimeError(
            f"failed to capture U-Boot prompt (status {wait_result.returncode}). "
            f"Diagnostic log: {rawlog}"
        )

    boot_chain, env_backup, backup_meta = backup_regions(port, backup_dir, scope)
    validation = validate_boot_chain(boot_chain, sector)
    env_values, env_ok = read_environment(port, rawlog)

    plan = {
        "backup": backup_meta,
        **validation,
        "qualified_target_crc32": f"{EXPECTED_PATCHED_CRC:08x}",
        "compatibility_policy": "bootloader-only; Cisco kernel/rootfs/config contents are not compared",
        "uboot_environment_backup": str(env_backup),
        "uboot_environment_values": env_values,
        "uboot_environment_qualified": env_ok,
        "expected_environment": {
            "bootdelay": "3",
            "preboot": "deleted",
            "bootcmd": "run openwrt_boot",
            "openwrt_boot": OPENWRT_BOOT,
        },
    }
    (backup_dir / "bootstrap-plan.json").write_text(json.dumps(plan, indent=2) + "\n")

    print("\nBootloader compatibility: PASS")
    print(f"Code state: {validation['code_state']}")
    print("Compatibility scope: first 512 KiB boot-chain; non-bootloader NOR contents ignored")
    print(f"Boot-chain backup: {boot_chain}")
    print(f"U-Boot environment backup: {env_backup}")
    if scope == "full":
        print(f"Complete NOR backup: {backup_meta['full_nor']}")
    print(f"Original sector-0 CRC32: {validation['sector0_original_crc32']}")
    print(f"Qualified patched CRC32: {validation['sector0_patched_crc32']}")
    for site in validation["patch_sites"]:
        print(f"  {site['offset']}: {site['state']} ({site['name']})")
    print(f"Saved OpenWrt U-Boot environment: {'PASS' if env_ok else 'NEEDS REPAIR'}")

    if ns.verify_only:
        print("\nverify_only=PASS")
        print("No NOR or U-Boot environment write was attempted.")
        return 0

    action = select_existing_action(str(validation["code_state"]), env_ok)
    if action == "none":
        print("\nU-Boot left unchanged. Backups and verification manifest retained.")
        return 0

    iface = None
    if action in ("patch", "force"):
        iface = choose(net_candidates(), "directly-connected Ethernet interface", ns.interface)
        print("\nConnect the computer directly to one of the four RV220W LAN ports.")
    perform_write(port, iface, sector, action, rawlog, backup_dir)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except KeyboardInterrupt:
        print("\n[rv220w] Cancelled by user. No additional router state was changed.", file=sys.stderr)
        raise SystemExit(130)
    except (RuntimeError, OSError, subprocess.SubprocessError) as exc:
        print(f"\n[rv220w:error] {exc}", file=sys.stderr)
        raise SystemExit(1)
