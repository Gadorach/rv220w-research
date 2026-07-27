#!/usr/bin/env python3
"""Compare focused BCM53115 conduit state from two RV220W B53 snapshots."""
from __future__ import annotations

import argparse
import pathlib
import re
import sys
from dataclasses import dataclass

FOCUSED_GLOBAL = (
    "live_wan_conduit",
    "expected_wan_cpu_port",
    "conduit_register_check",
    "port0_has_expected_cpu",
    "expected_cpu_has_port0",
    "unexpected_cpu_has_port0",
    "switch_mode",
    "global_management_config",
    "frame_management_mode",
    "broadcom_header_control",
    "broadcom_header_rx_disable",
    "broadcom_header_tx_disable",
)
FOCUSED_PORTS = (0, 5, 8)
FOCUSED_PORT_KEYS = (
    "port_control",
    "port_vlan_mask",
    "default_vlan_tag",
    "gmii_override",
    "rgmii_control",
    "eap_config_raw",
    "eap_mode_code",
    "eap_mode",
)


@dataclass
class Snapshot:
    path: pathlib.Path
    globals: dict[str, str]
    ports: dict[int, dict[str, str]]


def parse_snapshot(path: pathlib.Path) -> Snapshot:
    text = path.read_text(encoding="utf-8", errors="replace")
    if not text.startswith("RV220W passive B53 topology snapshot"):
        raise ValueError(f"{path}: not an RV220W B53 snapshot")
    globals_: dict[str, str] = {}
    ports: dict[int, dict[str, str]] = {}
    current_port: int | None = None
    for raw in text.splitlines():
        line = raw.strip()
        match = re.fullmatch(r"\[port (\d+)\]", line)
        if match:
            current_port = int(match.group(1))
            ports.setdefault(current_port, {})
            continue
        if line.startswith("=== "):
            current_port = None
            continue
        if "=" not in line:
            continue
        key, value = line.split("=", 1)
        key, value = key.strip(), value.strip()
        if current_port is None:
            globals_[key] = value
        else:
            ports[current_port][key] = value
    return Snapshot(path=path, globals=globals_, ports=ports)


def mask_bits(value: str) -> str:
    try:
        number = int(value, 0)
    except (TypeError, ValueError):
        return "unavailable"
    bits = [str(bit) for bit in range(16) if number & (1 << bit)]
    return "{" + ",".join(bits) + "}"


def row(label: str, before: str, after: str) -> str:
    marker = "=" if before == after else "!"
    return f"{marker} {label:<38} {before:<18} -> {after}"


def compare(a: Snapshot, b: Snapshot) -> str:
    lines = [
        "RV220W BCM53115 conduit-state comparison",
        f"A={a.path}",
        f"B={b.path}",
        "",
        "=== FOCUSED_GLOBALS ===",
    ]
    for key in FOCUSED_GLOBAL:
        lines.append(row(key, a.globals.get(key, "<missing>"), b.globals.get(key, "<missing>")))
    lines.append("")
    lines.append("=== PORT_0_5_8_REGISTERS ===")
    for port in FOCUSED_PORTS:
        lines.append(f"[port {port}]")
        for key in FOCUSED_PORT_KEYS:
            av = a.ports.get(port, {}).get(key, "<missing>")
            bv = b.ports.get(port, {}).get(key, "<missing>")
            lines.append(row(key, av, bv))
            if key == "port_vlan_mask":
                lines.append(row("port_vlan_mask_bits", mask_bits(av), mask_bits(bv)))
    lines.append("")
    lines.append("Legend: '=' unchanged, '!' changed. VLAN-mask bit numbers are switch ports.")
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("snapshot_a", type=pathlib.Path)
    parser.add_argument("snapshot_b", type=pathlib.Path)
    parser.add_argument("--output", type=pathlib.Path)
    args = parser.parse_args()
    try:
        output = compare(parse_snapshot(args.snapshot_a), parse_snapshot(args.snapshot_b))
    except (OSError, ValueError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(output, encoding="utf-8")
        print(args.output)
    else:
        sys.stdout.write(output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
