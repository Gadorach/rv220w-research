#!/usr/bin/env python3
"""Run the B53 target helper against a stateful fake MDIO bus."""
from __future__ import annotations

import os
import pathlib
import shutil
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
SCANNER = ROOT / "openwrt/files-discovery/usr/sbin/rv220w-b53-snapshot"

STUB = r'''#!/bin/sh
state=${MDIO_STUB_STATE:?}
if [ "$#" -eq 0 ]; then
  echo 8001180000001800
  echo fixed-0
  exit 0
fi
if [ "$#" -eq 1 ]; then
  echo 'DEV PHY-ID LINK'
  echo '0x00 0x0143bf88 down'
  echo '0x1e 0x00000000 down'
  exit 0
fi
[ "$2" = phy ] && [ "$3" = 30 ] && [ "$4" = raw ] || exit 2
reg=$(( $5 ))
if [ "$#" -eq 6 ]; then
  val=$(( $6 & 65535 ))
  printf '0x%02x=0x%04x\n' "$reg" "$val" >> "$state/writes.log"
  case "$reg" in
    16)
      echo "$val" > "$state/page_selector"
      echo $(((val >> 8) & 255)) > "$state/page"
      ;;
    17)
      echo $((val & ~3)) > "$state/addr_selector"
      echo $(((val >> 8) & 255)) > "$state/reg"
      ;;
    *) echo UNSAFE >&2; exit 99 ;;
  esac
  exit 0
fi
case "$reg" in
  16) val=$(cat "$state/page_selector") ;;
  17) val=$(cat "$state/addr_selector") ;;
  24|25|26|27)
    page=$(cat "$state/page")
    off=$(cat "$state/reg")
    key="$page:$off"
    case "$key" in
      2:48) value=$((0x00053115)) ;;
      2:64) value=$((0x00000007)) ;;
      1:112) value=$((0x000008000000)) ;;
      0:10) value=$((0x00)) ;;
      0:11) value=$((0x03)) ;;
      0:14) value=$((0x87)) ;;
      2:0) value=$((0x80)) ;;
      2:3) value=$((0x00)) ;;
      1:0) value=$((0x0120)) ;;
      1:4) value=$((0x000a0000)) ;;
      1:8) value=$((0x0120)) ;;
      *) value=$(((page << 24) | (off << 8) | 0x55)) ;;
    esac
    shift=$(((reg - 24) * 16))
    val=$(((value >> shift) & 65535))
    ;;
  *) val=65535 ;;
esac
printf '0x%04x\n' "$val"
'''

with tempfile.TemporaryDirectory(prefix="rv220w-b53-test-") as tmp:
    tmp_path = pathlib.Path(tmp)
    bin_dir = tmp_path / "bin"
    state = tmp_path / "state"
    bin_dir.mkdir()
    state.mkdir()
    for name in ("page_selector", "addr_selector", "page", "reg"):
        (state / name).write_text("0\n", encoding="ascii")
    stub = bin_dir / "mdio"
    stub.write_text(STUB, encoding="utf-8")
    stub.chmod(0o755)

    env = os.environ.copy()
    env["PATH"] = str(bin_dir) + os.pathsep + env.get("PATH", "")
    env["MDIO_STUB_STATE"] = str(state)
    shell = shutil.which("busybox")
    command = [shell, "sh", str(SCANNER), "static-test", "8001180000001800"] if shell else ["sh", str(SCANNER), "static-test", "8001180000001800"]
    result = subprocess.run(command, env=env, text=True, capture_output=True, timeout=60, check=True)
    report_path = pathlib.Path(result.stdout.strip().splitlines()[-1])
    report = report_path.read_text(encoding="utf-8")
    try:
        assert report.startswith("RV220W passive B53 topology snapshot")
        assert "device_id=0x00053115" in report
        assert "revision_id=0x07" in report
        assert "strap_value=0x000008000000" in report
        assert "port5 link=1" in report
        assert "port8 link=1" in report
        assert "=== DSA_CONDUIT_REGISTER_CHECK ===" in report
        assert "port0_port_vlan_mask=" in report
        assert "conduit_register_check=" in report
        write_registers = {
            line.split("=", 1)[0]
            for line in (state / "writes.log").read_text(encoding="ascii").splitlines()
        }
        assert write_registers == {"0x10", "0x11"}, write_registers
        assert (state / "page_selector").read_text().strip() == "0"
        assert (state / "addr_selector").read_text().strip() == "0"
    finally:
        report_path.unlink(missing_ok=True)

print("B53 selector-safety integration checks passed")
