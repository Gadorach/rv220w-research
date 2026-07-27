#!/usr/bin/env python3
"""Validate the generic B53 firmware-described CPU-port activation patch."""
from __future__ import annotations

import re
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PATCH = ROOT / "openwrt/dsa-dual/998-b53-enable-dt-cpu-ports.patch"


def fail(message: str) -> None:
    raise SystemExit(message)


if not PATCH.is_file():
    fail("missing B53 DT CPU-port patch")
text = PATCH.read_text(encoding="utf-8")

paths = {
    line[6:]
    for line in text.splitlines()
    if line.startswith("--- a/") or line.startswith("+++ b/")
}
if paths != {"drivers/net/dsa/b53/b53_common.c"}:
    fail(f"patch touches unexpected paths: {sorted(paths)}")

for token in (
    "static int b53_setup(struct dsa_switch *ds)",
    "dev->enabled_ports |= (u16)dsa_cpu_ports(ds);",
    "before the default PVID/VLAN setup iterates enabled_ports",
    "A firmware-described CPU port absent from the static chip",
    "mask is therefore skipped",
):
    if token not in text:
        fail(f"patch lacks required token: {token}")

added_code = "\n".join(
    line[1:]
    for line in text.splitlines()
    if line.startswith("+") and not line.startswith("+++")
)
for forbidden in (
    "RV220W",
    "Cisco",
    "BCM53115",
    "port 5",
    "eth1",
    "wan",
    "VLAN 1",
):
    if forbidden.lower() in added_code.lower():
        fail(f"implementation contains board-specific policy: {forbidden}")

# Construct the exact old side of the single hunk and apply the patch using
# standard patch(1). This verifies unified-diff counts and context shape.
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

if len(hunks) != 1:
    fail(f"expected one patch hunk, found {len(hunks)}")

start, old = hunks[0]
fixture = [f"/* filler {n + 1} */" for n in range(start + len(old) + 20)]
fixture[start - 1 : start - 1 + len(old)] = old

with tempfile.TemporaryDirectory(prefix="rv220w-b53-cpu-ports-") as tmp:
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
        fail("patch failed synthetic application:\n" + result.stdout + result.stderr)
    if "dev->enabled_ports |= (u16)dsa_cpu_ports(ds);" not in source.read_text(encoding="utf-8"):
        fail("applied source lacks CPU-port mask merge")

# BCM53115's legacy mask covers 0-4 and 8 (0x11f). Firmware adds valid CPU
# ports 5 and 8. The generic merge must retain the legacy mask and add bit 5.
legacy_enabled = 0x11F
firmware_cpu_ports = (1 << 5) | (1 << 8)
merged = legacy_enabled | firmware_cpu_ports
if merged != 0x13F:
    fail(f"enabled-port model mismatch: 0x{merged:03x}")

# Model the existing B53 default-VLAN loop after the merge. Every enabled port,
# including the secondary CPU conduit, must receive the default PVID and be a
# member of the internal default VID domain.
default_vid_members = merged
if not (default_vid_members & (1 << 5)):
    fail("secondary CPU port is still absent from the default VLAN model")
if (default_vid_members & 0x11F) != 0x11F:
    fail("legacy enabled ports were lost by the CPU-port merge")

print("v1.9.0 generic B53 firmware CPU-port activation patch checks passed")
