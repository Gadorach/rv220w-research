#!/usr/bin/env python3
from __future__ import annotations

import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]


def fail(message: str) -> None:
    raise SystemExit(message)


if (ROOT / "VERSION").read_text().strip() != "1.10.3":
    fail("toolkit version is not 1.10.3")

script = (ROOT / "scripts/nor-stage.fish").read_text()
for token in (
    "rv_require ssh python3 sha256sum",
    "UserKnownHostsFile=/dev/null",
    "GlobalKnownHostsFile=/dev/null",
    "StrictHostKeyChecking=no",
    "function upload_blob",
    "command cat \"$local_path\" | command ssh",
    "set -l transfer_status $pipestatus",
    "cat > '$remote_partial' && mv '$remote_partial' '$remote_path'",
    "Slot-image SSH stream failed; NOR was not written.",
    "Restore-image SSH stream failed; NOR was not written.",
    "NOR-writer status check failed. Confirm the RAM writer is running and reachable over SSH.",
):
    if token not in script:
        fail(f"NOR transport hotfix lacks token: {token}")

for forbidden in (
    "rv_require ssh scp",
    "command scp",
    "StrictHostKeyChecking=accept-new",
):
    if forbidden in script:
        fail(f"NOR transport still contains incompatible token: {forbidden}")

write_upload = script.index('Streaming the verified 22 MiB slot image')
write_invoke = script.index("Invoking the target-side openwrt-slot-only writer")
if write_upload >= write_invoke:
    fail("target writer is invoked before the SSH upload stream")

backup = script.index("# Every first-stage write creates a complete stock-kernel/rootfs-region")
if backup >= write_upload:
    fail("mandatory pre-write backup no longer precedes image transfer")

print("v1.10.3 NOR SSH-stream and ephemeral-host-key checks passed")
