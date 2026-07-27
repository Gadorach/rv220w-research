#!/usr/bin/env python3
"""Validate the generic B53 multi-conduit DSA affinity patch."""
from __future__ import annotations

import re
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PATCH = ROOT / "openwrt/dsa-dual/997-b53-multi-conduit-affinity.patch"


def fail(message: str) -> None:
    raise SystemExit(message)


if not PATCH.is_file():
    fail("missing B53 multi-conduit patch")
text = PATCH.read_text(encoding="utf-8")

paths = []
for line in text.splitlines():
    if line.startswith("--- a/") or line.startswith("+++ b/"):
        paths.append(line[6:])
if set(paths) != {"drivers/net/dsa/b53/b53_common.c"}:
    fail(f"patch touches unexpected paths: {sorted(set(paths))}")

for token in (
    "static int b53_multi_cpu_vlan_setup",
    "u16 cpu_ports = dsa_cpu_ports(ds);",
    "pvlan &= ~cpu_ports;",
    "pvlan |= BIT(cpu_port);",
    "dev->ports[i].vlan_ctl_mask = pvlan;",
    "dsa_switch_for_each_user_port(user_dp, ds)",
    "static int b53_port_change_conduit",
    "netif_is_lag_master(conduit)",
    "b53_possible_cpu_port(ds, cpu_dp->index)",
    "return b53_multi_cpu_vlan_setup(ds, port, cpu_dp->index);",
    ".port_change_conduit\t= b53_port_change_conduit,",
    "if (hweight16(dsa_cpu_ports(ds)) > 1)",
):
    if token not in text:
        fail(f"B53 patch lacks required token: {token}")

# Ensure the actual added implementation is switch-generic. Mail metadata and
# prose may name the research target while the C additions must not.
added_code = "\n".join(
    line[1:]
    for line in text.splitlines()
    if line.startswith("+") and not line.startswith("+++")
)
for forbidden in (
    "RV220W",
    "Cisco",
    "BCM53115",
    "eth0",
    "eth1",
    "wan",
    "lan1",
):
    if forbidden.lower() in added_code.lower():
        fail(f"B53 implementation contains board-specific token: {forbidden}")

# The existing single-CPU path must remain after the early multi-CPU branch.
branch = text.index("if (hweight16(dsa_cpu_ports(ds)) > 1)")
legacy = text.index("/* BCM5325 CPU port is at 8 */")
if branch >= legacy:
    fail("multi-CPU branch does not preserve the existing single-CPU path")

# Build a synthetic source file from the patch's old-side hunks, preserving
# hunk start positions. This catches malformed unified-diff counts and proves
# that standard OpenWrt/plaintext patch application can consume the file.
hunk_re = re.compile(r"^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@", re.M)
lines = text.splitlines()
hunks: list[tuple[int, list[str]]] = []
i = 0
while i < len(lines):
    match = hunk_re.match(lines[i])
    if not match:
        i += 1
        continue
    start = int(match.group(1))
    old: list[str] = []
    i += 1
    while i < len(lines) and not lines[i].startswith("@@ ") and lines[i] != "-- ":
        line = lines[i]
        if line.startswith(" "):
            old.append(line[1:])
        elif line.startswith("-") and not line.startswith("---"):
            old.append(line[1:])
        elif line.startswith("+"):
            pass
        else:
            break
        i += 1
    hunks.append((start, old))

if len(hunks) != 3:
    fail(f"expected three B53 patch hunks, found {len(hunks)}")

max_line = max(start + len(old) + 20 for start, old in hunks)
fixture = [f"/* filler {n + 1} */" for n in range(max_line)]
for start, old in hunks:
    fixture[start - 1 : start - 1 + len(old)] = old

with tempfile.TemporaryDirectory(prefix="rv220w-b53-patch-") as tmp:
    tree = Path(tmp)
    source = tree / "drivers/net/dsa/b53/b53_common.c"
    source.parent.mkdir(parents=True)
    source.write_text("\n".join(fixture) + "\n", encoding="utf-8")
    result = subprocess.run(
        ["patch", "--batch", "--forward", "-p1", "-i", str(PATCH)],
        cwd=tree,
        text=True,
        capture_output=True,
    )
    if result.returncode != 0:
        fail("B53 patch failed synthetic plaintext application:\n" + result.stdout + result.stderr)
    patched = source.read_text(encoding="utf-8")
    for token in (
        "static int b53_multi_cpu_vlan_setup",
        "dev->ports[i].vlan_ctl_mask = pvlan;",
        ".port_change_conduit\t= b53_port_change_conduit,",
    ):
        if token not in patched:
            fail(f"applied B53 source lacks token: {token}")

# Model the C helper's topology update. This verifies the subtle callback
# ordering used by DSA: the changed port's new CPU assignment is supplied
# before dp->cpu_dp itself is updated. Non-CPU bridge membership must survive.
cpu_ports = (1 << 5) | (1 << 8)
users = [0, 1, 2, 3, 4]
assignments = {port: 5 for port in users}
# Preserve a pre-existing LAN bridge domain while all users initially point
# at CPU port 5. WAN remains isolated from the LAN members.
masks = {
    0: (1 << 0) | (1 << 5),
    1: sum(1 << p for p in (1, 2, 3, 4, 5)),
    2: sum(1 << p for p in (1, 2, 3, 4, 5)),
    3: sum(1 << p for p in (1, 2, 3, 4, 5)),
    4: sum(1 << p for p in (1, 2, 3, 4, 5)),
    5: sum(1 << p for p in (0, 1, 2, 3, 4, 5)),
    8: 1 << 8,
}

def rebuild(changed_port: int, new_cpu_port: int) -> None:
    for port in users:
        cpu = new_cpu_port if port == changed_port else assignments[port]
        masks[port] = (masks[port] & ~cpu_ports) | (1 << cpu)

    for cpu in (5, 8):
        value = 1 << cpu
        for port in users:
            assigned = new_cpu_port if port == changed_port else assignments[port]
            if assigned == cpu:
                value |= 1 << port
        masks[cpu] = value

for port in (1, 2, 3, 4):
    rebuild(port, 8)
    assignments[port] = 8

expected = {
    0: sum(1 << p for p in (0, 5)),
    1: sum(1 << p for p in (1, 2, 3, 4, 8)),
    2: sum(1 << p for p in (1, 2, 3, 4, 8)),
    3: sum(1 << p for p in (1, 2, 3, 4, 8)),
    4: sum(1 << p for p in (1, 2, 3, 4, 8)),
    5: sum(1 << p for p in (0, 5)),
    8: sum(1 << p for p in (1, 2, 3, 4, 8)),
}
if masks != expected:
    fail(f"multi-conduit PVLAN model mismatch: got {masks!r}, expected {expected!r}")

print("v1.8.0 generic B53 multi-conduit patch checks passed")
