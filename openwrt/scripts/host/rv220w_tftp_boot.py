#!/usr/bin/env python3
"""Serve and RAM-boot an RV220W Octeon ELF through U-Boot TFTP.

The script modifies only U-Boot's in-memory environment.  It never invokes
saveenv, erase, protect, cp, mw, or any flash-programming command.
"""
from __future__ import annotations

import argparse
import datetime as dt
import grp
import ipaddress
import json
import os
import pathlib
import pwd
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import threading
import time
from dataclasses import dataclass
from typing import BinaryIO

PROMPT = b"rv200w# "
ELF_MAGIC = b"\x7fELF"
CONSERVATIVE_RAM_END = 0x07F00000


class BootError(RuntimeError):
    pass


class UnsafeBootState(BootError):
    """U-Boot reported a stale/unsafe transfer state requiring a power cycle."""


UNSAFE_UBOOT_MARKERS = (
    b"WARNING: Data loaded outside of the reserved load area",
    b"memory corruption may occur",
)

def check_unsafe_uboot(data: bytes) -> None:
    if any(marker in data for marker in UNSAFE_UBOOT_MARKERS):
        raise UnsafeBootState(
            "U-Boot reported an unsafe stale transfer state. Power-cycle the router "
            "before retrying; the helper will not continue from this prompt."
        )
    # U-Boot prints a standalone Abort when a previous transfer was interrupted.
    if re.search(rb"(?:^|[\r\n])Abort(?:[\r\n]|$)", data):
        raise UnsafeBootState(
            "U-Boot reported Abort from a previous transfer. Power-cycle the router "
            "before retrying."
        )


def auto_int(value: str) -> int:
    return int(value, 0)


def utc_stamp() -> str:
    return dt.datetime.now(dt.timezone.utc).strftime("%Y%m%dT%H%M%SZ")


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("serial_port")
    p.add_argument("image", type=pathlib.Path)
    p.add_argument("--interface")
    p.add_argument("--server-ip")
    p.add_argument("--device-ip")
    p.add_argument("--configure-interface", action="store_true", help="temporarily add a test IPv4 address when the interface has none")
    p.add_argument("--test-subnet", default="192.168.240.0/24")
    p.add_argument("--load-address", type=auto_int, default=0x05500000)
    p.add_argument("--ethact", action="append", default=[], help="U-Boot interface to try; repeatable. Default: octeth0, octeth1, octeth2")
    p.add_argument("--bootargs", default="console=ttyS0,115200")
    p.add_argument("--serial-baud", type=int, default=115200)
    p.add_argument("--tftp-timeout", type=float, default=240.0)
    p.add_argument("--boot-timeout", type=float, default=300.0)
    p.add_argument("--interrupt-timeout", type=float, default=90.0)
    p.add_argument("--no-boot", action="store_true", help="transfer only; leave image in RAM at the U-Boot prompt")
    p.add_argument("--already-at-prompt", action="store_true")
    p.add_argument("--server-only", action="store_true")
    p.add_argument("--keep-interface-address", action="store_true")
    p.add_argument("--log-dir", type=pathlib.Path, default=pathlib.Path("."))
    p.add_argument("--dry-run", action="store_true")
    return p.parse_args()


def run_json(command: list[str]) -> object:
    return json.loads(subprocess.check_output(command, text=True))


def candidate_interfaces() -> list[dict[str, object]]:
    records = run_json(["ip", "-j", "-4", "address", "show", "up"])
    result = []
    assert isinstance(records, list)
    for record in records:
        name = str(record.get("ifname", ""))
        if name == "lo" or re.match(r"^(docker|podman|veth|virbr|br-|tun|tap)", name):
            continue
        addresses = [a for a in record.get("addr_info", []) if a.get("family") == "inet"]
        result.append({"name": name, "addresses": addresses, "record": record})
    return result


def choose_network(args: argparse.Namespace) -> tuple[str, ipaddress.IPv4Interface, ipaddress.IPv4Address, bool]:
    records = candidate_interfaces()
    selected = None
    if args.interface:
        selected = next((r for r in records if r["name"] == args.interface), None)
        if selected is None:
            # Interface might be down or have no IPv4.
            all_links = run_json(["ip", "-j", "link", "show"])
            if not any(str(link.get("ifname")) == args.interface for link in all_links):
                raise BootError(f"interface does not exist: {args.interface}")
            selected = {"name": args.interface, "addresses": []}
    elif args.server_ip:
        # With an explicit server address and no explicit interface, first look
        # for an interface already carrying it. Route lookup is not meaningful
        # for an address that --configure-interface is about to add locally.
        selected = next(
            (
                r
                for r in records
                if any(a.get("local") == args.server_ip for a in r.get("addresses", []))
            ),
            None,
        )
        if selected is None:
            if args.configure_interface and len(records) == 1:
                selected = records[0]
            else:
                raise BootError("could not choose an interface for --server-ip; pass --interface")
    else:
        with_ipv4 = [r for r in records if r["addresses"]]
        if len(with_ipv4) == 1:
            selected = with_ipv4[0]
        elif len(records) == 1 and args.configure_interface:
            selected = records[0]
        else:
            lines = [f"{r['name']}: " + ", ".join(str(a.get('local')) for a in r['addresses']) for r in records]
            raise BootError("could not choose a unique physical IPv4 interface; pass --interface\n  " + "\n  ".join(lines))

    name = str(selected["name"])
    addresses = list(selected.get("addresses", []))
    test_network = ipaddress.IPv4Network(args.test_subnet, strict=False)
    added = False

    if args.configure_interface:
        server_ip = ipaddress.IPv4Address(args.server_ip) if args.server_ip else next(test_network.hosts())
        if server_ip not in test_network:
            raise BootError(f"server IP {server_ip} is outside configured test subnet {test_network}")
        server_if = ipaddress.IPv4Interface(f"{server_ip}/{test_network.prefixlen}")
        matching = [a for a in addresses if a.get("local") == str(server_ip)]
        subprocess.run(["sudo", "ip", "link", "set", name, "up"], check=True)
        if not matching:
            # Do not flush or replace unrelated host addresses. Add only the
            # deterministic direct-link address and remove only this address on exit.
            subprocess.run(["sudo", "ip", "address", "add", str(server_if), "dev", name], check=True)
            added = True
        elif int(matching[0]["prefixlen"]) != test_network.prefixlen:
            raise BootError(
                f"server IP {server_ip} already exists on {name} with /{matching[0]['prefixlen']}, "
                f"expected /{test_network.prefixlen}"
            )
    elif args.server_ip:
        server_ip = ipaddress.IPv4Address(args.server_ip)
        matching = [a for a in addresses if a.get("local") == str(server_ip)]
        if not matching:
            raise BootError(f"server IP {server_ip} is not configured on {name}; use --configure-interface")
        server_if = ipaddress.IPv4Interface(f"{server_ip}/{matching[0]['prefixlen']}")
    elif addresses:
        in_test = [a for a in addresses if ipaddress.IPv4Address(a["local"]) in test_network]
        preferred_pool = in_test or [a for a in addresses if not ipaddress.IPv4Address(a["local"]).is_link_local] or addresses
        preferred = preferred_pool[0]
        server_if = ipaddress.IPv4Interface(f"{preferred['local']}/{preferred['prefixlen']}")
    else:
        raise BootError(f"interface {name} has no IPv4 address; use --configure-interface or configure one manually")

    network = server_if.network
    if args.device_ip:
        device_ip = ipaddress.IPv4Address(args.device_ip)
        if device_ip not in network:
            raise BootError(f"device IP {device_ip} is outside {network}")
    else:
        hosts = network.hosts()
        device_ip = next(hosts)
        while device_ip == server_if.ip:
            device_ip = next(hosts)

    if device_ip == server_if.ip:
        raise BootError(f"server IP and device IP must differ; both resolve to {device_ip}")
    return name, server_if, device_ip, added

def inspect_image(path: pathlib.Path, load_address: int) -> tuple[int, int]:
    blob = path.read_bytes()
    if blob.startswith(ELF_MAGIC):
        offset = 0
    elif len(blob) > 0x204 and blob[0x200:0x204] == ELF_MAGIC:
        offset = 0x200
    else:
        raise BootError("image is not an ELF at offset 0 or 0x200; bootoctlinux would be unsafe")
    ident = blob[offset : offset + 20]
    if ident[4] != 2 or ident[5] != 2:
        raise BootError("expected ELF64 big-endian image")
    machine = int.from_bytes(ident[18:20], "big")
    if machine != 8:
        raise BootError(f"expected MIPS ELF machine 8, found {machine}")
    end = load_address + len(blob)
    if end > CONSERVATIVE_RAM_END:
        raise BootError(
            f"image source buffer 0x{load_address:08x}..0x{end:08x} exceeds conservative RAM limit 0x{CONSERVATIVE_RAM_END:08x}"
        )
    return offset, len(blob)


class LogPump(threading.Thread):
    def __init__(self, process: subprocess.Popen[str], log: BinaryIO):
        super().__init__(daemon=True)
        self.process = process
        self.log = log

    def run(self) -> None:
        assert self.process.stdout is not None
        for line in self.process.stdout:
            encoded = line.encode("utf-8", "replace")
            self.log.write(encoded)
            self.log.flush()
            sys.stderr.write("[tftp] " + line)
            sys.stderr.flush()


@dataclass
class TftpServer:
    process: subprocess.Popen[str]
    pump: LogPump
    root: pathlib.Path
    temporary: tempfile.TemporaryDirectory[str]
    log_handle: BinaryIO

    def stop(self) -> None:
        if self.process.poll() is None:
            self.process.send_signal(signal.SIGTERM)
            try:
                self.process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.process.kill()
        self.log_handle.close()
        self.temporary.cleanup()


def start_tftp(image: pathlib.Path, server_ip: ipaddress.IPv4Address, interface: str, log_path: pathlib.Path) -> tuple[TftpServer, str]:
    if shutil.which("dnsmasq") is None:
        raise BootError("dnsmasq is required on the host")
    temporary = tempfile.TemporaryDirectory(prefix="rv220w-tftp-")
    root = pathlib.Path(temporary.name)
    os.chmod(root, 0o755)
    safe_name = re.sub(r"[^A-Za-z0-9_.-]", "_", image.name)
    served = root / safe_name
    shutil.copy2(image, served)
    os.chmod(served, 0o644)
    user = pwd.getpwuid(os.getuid()).pw_name
    group = grp.getgrgid(os.getgid()).gr_name
    prefix = [] if os.geteuid() == 0 else ["sudo"]
    if prefix:
        subprocess.run(["sudo", "-v"], check=True)
    command = prefix + [
        "dnsmasq",
        "--no-daemon",
        "--port=0",
        "--log-facility=-",
        "--bind-interfaces",
        f"--interface={interface}",
        f"--listen-address={server_ip}",
        "--enable-tftp",
        f"--tftp-root={root}",
        "--tftp-mtu=544",
        "--tftp-max=16",
        f"--user={user}",
        f"--group={group}",
    ]
    log_handle = log_path.open("ab")
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, bufsize=1)
    pump = LogPump(process, log_handle)
    pump.start()
    time.sleep(1.0)
    if process.poll() is not None:
        log_handle.close()
        temporary.cleanup()
        raise BootError(f"dnsmasq exited with status {process.returncode}; inspect {log_path}")
    return TftpServer(process, pump, root, temporary, log_handle), safe_name


class Console:
    def __init__(self, serial_obj: object, raw_log: BinaryIO):
        self.ser = serial_obj
        self.log = raw_log

    def write(self, data: bytes) -> None:
        self.ser.write(data)
        self.ser.flush()

    def read_some(self) -> bytes:
        waiting = int(getattr(self.ser, "in_waiting", 0))
        data = self.ser.read(max(1, min(waiting or 1, 65536)))
        if data:
            self.log.write(data)
            self.log.flush()
            sys.stdout.buffer.write(data)
            sys.stdout.buffer.flush()
        return data

    def wait_prompt(self, timeout: float, echo: bool = True) -> bytes:
        deadline = time.monotonic() + timeout
        buf = bytearray()
        while time.monotonic() < deadline:
            data = self.read_some()
            if data:
                buf.extend(data)
                check_unsafe_uboot(bytes(buf[-4096:]))
                if bytes(buf).endswith(PROMPT):
                    return bytes(buf)
            else:
                time.sleep(0.002)
        raise BootError(f"timeout waiting for {PROMPT!r}")

    def interrupt_boot(self, timeout: float) -> None:
        self.ser.reset_input_buffer()
        self.write(b"\r")
        try:
            self.wait_prompt(1.0)
            return
        except UnsafeBootState:
            raise
        except BootError:
            pass
        print("\n[rv220w] Power-cycle the router now. Ctrl-C will be sent automatically.", file=sys.stderr)
        deadline = time.monotonic() + timeout
        buf = bytearray()
        last_interrupt = 0.0
        seen_uboot = False
        seen_magic = False
        linux_notice = False
        while time.monotonic() < deadline:
            data = self.read_some()
            if data:
                buf.extend(data)
                tail = bytes(buf[-4096:])
                check_unsafe_uboot(tail)
                seen_uboot = seen_uboot or b"U-Boot" in tail
                seen_magic = seen_magic or b"checking fw magic" in tail or b"Image name" in tail
                if not linux_notice and (b"root@rv220w-validation" in tail or b"OpenWrt" in tail):
                    print(
                        "\n[rv220w] Running Linux detected. Waiting for a real power cycle; "
                        "no Ctrl-C will be sent until a U-Boot banner appears.",
                        file=sys.stderr,
                    )
                    linux_notice = True
                if tail.endswith(PROMPT):
                    return
            now = time.monotonic()
            if (seen_magic or seen_uboot) and now - last_interrupt > 0.08:
                self.write(b"\x03")
                last_interrupt = now
            time.sleep(0.002)
        raise BootError("failed to interrupt U-Boot within the timeout")

    def command(self, command: str, timeout: float = 10.0) -> bytes:
        verb = command.strip().split(maxsplit=1)[0].lower()
        allowed = {"base", "setenv", "tftpboot"}
        if verb not in allowed:
            raise BootError(f"refusing non-whitelisted prompt command: {command}")
        self.ser.reset_input_buffer()
        self.write(command.encode("ascii") + b"\r")
        return self.wait_prompt(timeout)

    def boot(self, command: str, timeout: float) -> None:
        if not command.startswith("bootoctlinux "):
            raise BootError("refusing unexpected boot command")
        self.ser.reset_input_buffer()
        self.write(command.encode("ascii") + b"\r")
        deadline = time.monotonic() + timeout
        buf = bytearray()
        while time.monotonic() < deadline:
            data = self.read_some()
            if data:
                buf.extend(data)
                check_unsafe_uboot(bytes(buf[-4096:]))
            else:
                time.sleep(0.002)
        print("\n[rv220w] boot capture timeout reached; log closed without sending input", file=sys.stderr)


def tftp_transfer(console: Console, filename: str, image_size: int, load_address: int, server_if: ipaddress.IPv4Interface, device_ip: ipaddress.IPv4Address, interfaces: list[str], timeout: float) -> str:
    netmask = server_if.network.netmask
    console.command("base 0")
    console.command("setenv autoload no")
    console.command("setenv netretry no")
    console.command(f"setenv ipaddr {device_ip}")
    console.command(f"setenv serverip {server_if.ip}")
    console.command(f"setenv netmask {netmask}")
    errors: list[str] = []
    for ethact in interfaces:
        print(f"\n[rv220w] trying U-Boot network interface {ethact}", file=sys.stderr)
        console.command(f"setenv ethact {ethact}")
        try:
            response = console.command(f"tftpboot 0x{load_address:08x} {filename}", timeout=timeout)
        except UnsafeBootState:
            raise
        except BootError as exc:
            errors.append(f"{ethact}: {exc}")
            console.write(b"\x03\r")
            try:
                console.wait_prompt(5.0)
            except UnsafeBootState:
                raise
            except BootError:
                pass
            continue
        match = re.search(rb"Bytes transferred\s*=\s*([0-9]+)", response)
        if match:
            transferred = int(match.group(1))
            if transferred != image_size:
                raise BootError(f"{ethact} transferred {transferred} bytes, expected {image_size}")
            return ethact
        errors.append(f"{ethact}: no successful byte count")
    raise BootError("TFTP failed on all requested ethact values:\n  " + "\n  ".join(errors))


def main() -> int:
    args = parse_args()
    args.image = args.image.resolve()
    if not args.image.is_file():
        print(f"error: image not found: {args.image}", file=sys.stderr)
        return 2
    try:
        image_offset, image_size = inspect_image(args.image, args.load_address)
        interface, server_if, device_ip, added_address = choose_network(args)
    except (BootError, subprocess.CalledProcessError, ValueError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2

    args.log_dir.mkdir(parents=True, exist_ok=True)
    stamp = utc_stamp()
    serial_log_path = args.log_dir / f"rv220w-tftp-boot-{stamp}.serial.log"
    tftp_log_path = args.log_dir / f"rv220w-tftp-boot-{stamp}.tftp.log"
    interfaces = args.ethact or ["octeth0", "octeth1", "octeth2"]
    plan = {
        "serial_port": args.serial_port,
        "serial_baud": args.serial_baud,
        "image": str(args.image),
        "image_size": image_size,
        "elf_offset": image_offset,
        "load_address": f"0x{args.load_address:08x}",
        "boot_address": f"0x{args.load_address + image_offset:08x}",
        "interface": interface,
        "server_ip": str(server_if.ip),
        "device_ip": str(device_ip),
        "netmask": str(server_if.network.netmask),
        "ethact_attempts": interfaces,
        "no_boot": args.no_boot,
        "flash_writes": False,
    }
    print(json.dumps(plan, indent=2), file=sys.stderr)
    if args.dry_run:
        return 0

    server = None
    serial_handle = None
    serial_log = None
    try:
        server, served_name = start_tftp(args.image, server_if.ip, interface, tftp_log_path)
        print(f"[rv220w] TFTP server ready: {server_if.ip}:{served_name}", file=sys.stderr)
        if args.server_only:
            print("[rv220w] server-only mode; press Ctrl-C to stop", file=sys.stderr)
            while True:
                time.sleep(1)
        try:
            import serial  # type: ignore
        except ImportError as exc:
            raise BootError("pyserial is required: python -m pip install pyserial") from exc
        serial_log = serial_log_path.open("ab")
        serial_handle = serial.Serial(
            args.serial_port,
            args.serial_baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.05,
            write_timeout=2.0,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
        )
        console = Console(serial_handle, serial_log)
        if args.already_at_prompt:
            console.write(b"\r")
            console.wait_prompt(5.0)
        else:
            console.interrupt_boot(args.interrupt_timeout)
        chosen = tftp_transfer(console, served_name, image_size, args.load_address, server_if, device_ip, interfaces, args.tftp_timeout)
        print(f"\n[rv220w] transfer verified through {chosen}", file=sys.stderr)
        print(f"[rv220w] image is in RAM at 0x{args.load_address:08x}", file=sys.stderr)
        if args.no_boot:
            print("[rv220w] --no-boot selected; remaining at U-Boot prompt", file=sys.stderr)
            return 0
        boot_address = args.load_address + image_offset
        command = f"bootoctlinux 0x{boot_address:08x}"
        if args.bootargs.strip():
            command += " " + args.bootargs.strip()
        print(f"[rv220w] executing: {command}", file=sys.stderr)
        console.boot(command, args.boot_timeout)
        return 0
    except KeyboardInterrupt:
        print("\n[rv220w] interrupted", file=sys.stderr)
        return 130
    except (BootError, subprocess.CalledProcessError, OSError) as exc:
        print(f"\nerror: {exc}", file=sys.stderr)
        return 1
    finally:
        if serial_handle is not None:
            serial_handle.close()
        if serial_log is not None:
            serial_log.close()
        if server is not None:
            server.stop()
        if added_address and not args.keep_interface_address:
            subprocess.run(["sudo", "ip", "address", "del", str(server_if), "dev", interface], check=False)
        print(f"[rv220w] serial log: {serial_log_path}", file=sys.stderr)
        print(f"[rv220w] TFTP log:   {tftp_log_path}", file=sys.stderr)


if __name__ == "__main__":
    raise SystemExit(main())
