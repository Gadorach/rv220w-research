#!/usr/bin/env python3
from __future__ import annotations

import json
import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
FLASHER = ROOT / "flash-tools" / "rv220w-combined-boot-policy-patch-flasher-v1.0.0"
VALIDATION = ROOT / "evidence" / "hardware-validation-v1.4.0-r1.json"


def main() -> int:
    subprocess.run([sys.executable, str(FLASHER / "tests" / "test_offline.py")], check=True)

    data = json.loads(VALIDATION.read_text())
    assert data["validated_sector"]["crc32"] == "b77a94de"
    assert data["validated_sector"]["http_recovery_branch"]["bytes"] == "10000003"
    assert data["validated_sector"]["bootcmd_overwrite_tailcall"]["bytes"] == "03e00008"
    assert data["runtime_results"]["normal_openwrt_boot"] is True
    assert data["runtime_results"]["physical_recovery_download_mode_preserved"] is True
    assert data["combined_distribution_flasher"]["idempotent_no_write_path_hardware_validated"] is True
    assert data["combined_distribution_flasher"]["single_step_destructive_write_from_stock_directly_exercised"] is False

    transcript = (ROOT / "evidence" / "hardware-validation" / "2026-08-02-combined-flasher-idempotence.log").read_text()
    assert "Recognized live sector identity: combined" in transcript
    assert "Flash already matches target combined; no write performed" in transcript
    assert "destructive_started=False" in transcript

    recovery = (ROOT / "evidence" / "hardware-validation" / "2026-08-02-recovery-button-validation.log").read_text()
    assert "PUSH_BUTTON--> 0" in recovery
    assert "you select download mode" in recovery

    normal = (ROOT / "evidence" / "hardware-validation" / "2026-08-02-normal-openwrt-boot.log").read_text(errors="replace")
    assert "PUSH_BUTTON--> 1" in normal
    assert "ELF file is 64 bit" in normal
    assert "Linux version 6.12.94" in normal
    assert "OpenWrt RV220W full-RJ45 + LuCI RAM firmware" in normal

    print("combined patch flasher and hardware-validation metadata tests passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
