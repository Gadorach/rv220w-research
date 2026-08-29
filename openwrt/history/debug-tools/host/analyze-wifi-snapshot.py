#!/usr/bin/env python3
"""Analyze an RV220W read-only BCM4322/b43 discovery snapshot.

This consumes only collected evidence.  It never changes the router, SPROM,
OpenWrt source tree or firmware image.  v4 deliberately distinguishes the
physical PCI identity observed during enumeration from historical fallback-SPROM runtime device-ID overrides, distinguishes an existing-but-unreadable b43 debugfs file from a missing file, recognizes the v1.14.14 native physical-SPROM double-read path, and records the v1.14.15 stock base+4 MAC identity gate and v1.14.16 failed SSB rebind experiment and the v1.14.17/v1.14.18 failed U-Boot bootarg MAC preload path and the v1.14.20-v1.14.29 MTD-derived first-probe MAC source. Initialized explicit diagnostic runs may be recognized from the bound b43 SSB core + wiphy even after the temporary interface has been torn down.
"""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

MAC_RE = re.compile(r"^(?:[0-9a-f]{2}:){5}[0-9a-f]{2}$", re.I)


def values(text: str, key: str) -> list[str]:
    pat = re.compile(rf"^{re.escape(key)}=(.*)$", re.M)
    return [m.group(1).strip() for m in pat.finditer(text)]


def first(text: str, key: str) -> str | None:
    v = values(text, key)
    return v[0] if v else None


def valid_unicast(mac: str | None) -> bool:
    if not mac or not MAC_RE.fullmatch(mac):
        return False
    b = bytes.fromhex(mac.replace(":", ""))
    return b not in (b"\0" * 6, b"\xff" * 6) and not (b[0] & 1)


def norm(mac: str | None) -> str | None:
    return mac.lower() if mac else None


def pci_runtime_identity(text: str) -> tuple[str | None, str | None, str | None]:
    section = re.search(r"=== PCI FUNCTIONS ===\n(.*?)(?=\n=== |\Z)", text, re.S)
    if not section:
        return None, None, None
    body = section.group(1)
    block = re.search(r"^\[(0000:00:03\.0)\]\n(.*?)(?=^\[|\Z)", body, re.M | re.S)
    if not block:
        return None, None, None
    b = block.group(2)
    vendor = re.search(r"^vendor=(0x[0-9a-f]+)$", b, re.M | re.I)
    device = re.search(r"^device=(0x[0-9a-f]+)$", b, re.M | re.I)
    return block.group(1), vendor.group(1).lower() if vendor else None, device.group(1).lower() if device else None


def pci_boot_identity(text: str) -> tuple[str | None, str | None]:
    explicit_vendor = first(text, "pci_boot_vendor")
    explicit_device = first(text, "pci_boot_device")
    if explicit_vendor and explicit_device:
        return explicit_vendor.lower(), explicit_device.lower()
    # Kernel enumeration occurs before fallback-SPROM can overwrite pci_dev.device.
    m = re.search(r"pci\s+0000:00:03\.0:\s+\[([0-9a-f]{4}):([0-9a-f]{4})\]", text, re.I)
    if m:
        return "0x" + m.group(1).lower(), "0x" + m.group(2).lower()
    return None, None


def b43_probe(text: str) -> dict[str, object | None]:
    core = re.search(r"b43-phy(\d+):\s+Broadcom\s+([0-9a-f]+)\s+WLAN found \(core revision (\d+)\)", text, re.I)
    phy = re.search(r"b43-phy\d+:\s+Found PHY:\s+Analog\s+(\d+),\s+Type\s+(\d+)\s+\(([^)]+)\),\s+Revision\s+(\d+)", text, re.I)
    radio = re.search(r"b43-phy\d+:\s+Found Radio:\s+Manuf\s+(0x[0-9a-f]+),\s+ID\s+(0x[0-9a-f]+),\s+Revision\s+(\d+),\s+Version\s+(\d+)", text, re.I)
    return {
        "phy_index": int(core.group(1)) if core else None,
        "chip": core.group(2).lower() if core else None,
        "core_rev": int(core.group(3)) if core else None,
        "analog_rev": int(phy.group(1)) if phy else None,
        "phy_type": int(phy.group(2)) if phy else None,
        "phy_name": phy.group(3) if phy else None,
        "phy_rev": int(phy.group(4)) if phy else None,
        "radio_manuf": radio.group(1).lower() if radio else None,
        "radio_id": radio.group(2).lower() if radio else None,
        "radio_rev": int(radio.group(3)) if radio else None,
        "radio_version": int(radio.group(4)) if radio else None,
    }


def capabilities_state(text: str, b43_phy_present: bool) -> tuple[str, str | None]:
    explicit = first(text, "capabilities_read_status")
    path = first(text, "capabilities_path")
    if explicit:
        return explicit, path
    m = re.search(r"^\[(/sys/kernel/debug/b43/[^\]]+/capabilities)\]\s*$", text, re.M)
    if m:
        path = m.group(1)
        # Old collectors suppressed the -ENODEV from b43's common debugfs read
        # wrapper.  An empty file marker while the PHY is present and the radio
        # is intentionally disabled is therefore a deferred pre-init read.
        after = text[m.end():]
        next_header = re.search(r"\n=== |\n\[/sys/kernel/debug/b43/", after)
        payload = after[: next_header.start()] if next_header else after
        if re.search(r"^(permanent_mac|core_rev|phy_type|phy_rev|active_transfer)=", payload, re.M):
            return "read", path
        return ("deferred-preinit" if b43_phy_present else "empty"), path
    return "missing", None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("snapshot", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    args = ap.parse_args()
    text = args.snapshot.read_text(errors="replace")

    base = first(text, "platform_base_mac")
    expected = first(text, "stock_expected_wlan_mac")
    perm = first(text, "permanent_mac")
    et1 = first(text, "sprom_et1mac")
    il0 = first(text, "sprom_il0mac")
    transfer = first(text, "active_transfer")
    module_mac = first(text, "macaddr")
    module_mac_mtd = first(text, "macaddr_mtd")
    module_mac_mtd_offset = first(text, "macaddr_mtd_offset")
    module_mac_increment = first(text, "macaddr_increment")
    module_pio = first(text, "pio")
    stock_mac_marker = first(text, "stock_mac_apply_marker")
    mtd_mac_log = bool(expected and re.search(
        rf"Using MTD-derived permanent MAC address\s+{re.escape(expected)}\b", text, re.I))
    calibration_integrity = first(text, "calibration_integrity_qualified") == "1"
    receiver_init_qualified = first(text, "receiver_init_qualified") == "1"
    profile = first(text, "profile")
    toolkit_version = first(text, "toolkit")
    wifi_profile = profile == "wifi-discovery"

    pci_addr, runtime_vendor, runtime_device = pci_runtime_identity(text)
    boot_vendor, boot_device = pci_boot_identity(text)
    sprom_source = first(text, "source")
    generic_sprom = sprom_source == "openwrt-generic-bcm4322"
    physical_double_sprom = sprom_source == "physical-sprom-double-read"
    devid_override = bool(
        generic_sprom
        and boot_vendor == "0x14e4"
        and boot_device == "0x432b"
        and runtime_vendor == "0x14e4"
        and runtime_device == "0x432c"
    )
    pci_physical = bool(
        (boot_vendor == "0x14e4" and boot_device == "0x432b")
        or (runtime_vendor == "0x14e4" and runtime_device == "0x432b")
    )

    fallback_blob_present = "fallback_sprom_firmware=/lib/firmware/brcm/bcm4322-sprom.bin" in text
    fallback_registered = bool(re.search(r"registered SPROM for \[0:3\]", text, re.I))
    fallback_requested = bool(re.search(r"requested by \[0:3\]", text, re.I))
    rf_qualified = first(text, "rf_qualified") == "1"

    probe = b43_probe(text)
    cap_core_rev = first(text, "core_rev")
    cap_phy_type = first(text, "phy_type")
    cap_phy_rev = first(text, "phy_rev")
    wiphy_present = bool(re.search(r"\bWiphy phy\d+\b|\bphy#\d+\b|^wiphy=", text, re.M | re.I))
    b43_ssb_bound = bool(re.search(r"^\[ssb\d+:\d+\]\n(?:(?!^\[).)*?^coreid=0x0812$\n(?:(?!^\[).)*?^driver=b43$", text, re.M | re.S))
    carried_receiver = first(text, "receiver_init_evidence") or ""
    explicit_nphy_diag = bool(first(text, "nphy_rxdiag_scope"))
    b43_phy_present = probe["core_rev"] is not None or cap_core_rev is not None or (b43_ssb_bound and wiphy_present)
    nphy_present = (
        (probe["phy_type"] == 4 and str(probe["phy_name"] or "").upper() == "N")
        or cap_phy_type == "4"
        or (b43_phy_present and explicit_nphy_diag)
        or (b43_phy_present and "nphy-rev4" in carried_receiver)
    )
    ssb_devices = len(re.findall(r"^\[ssb\d+:\d+\]$", text, re.M))
    # A successfully created b43 PHY is itself downstream proof that the SSB
    # WLAN core registered, so retain compatibility with older snapshots that
    # did not enumerate /sys/bus/ssb/devices explicitly.
    ssb_registered = ssb_devices > 0 or "Sonics Silicon Backplane found" in text or b43_phy_present

    caps_status, caps_path = capabilities_state(text, b43_phy_present)
    caps_read = caps_status == "read"
    caps_deferred = caps_status == "deferred-preinit"

    firmware_inventory = "/lib/firmware/b43/" in text
    firmware_failure = bool(re.search(r"b43[^\n]*firmware[^\n]*(?:fail|error|not found)|firmware[^\n]*b43[^\n]*(?:fail|error|not found)", text, re.I))
    firmware_loaded = bool(re.search(r"b43-phy\d+:[^\n]*(?:firmware version|loading firmware|firmware loaded|ucode)", text, re.I))
    if firmware_failure:
        firmware_state = "failure"
    elif firmware_loaded:
        firmware_state = "loaded"
    elif firmware_inventory and b43_phy_present:
        firmware_state = "inventory-present-not-loaded"
    elif firmware_inventory:
        firmware_state = "inventory-present"
    else:
        firmware_state = "missing"

    nvmem_bdf = first(text, "ssb_nvmem_bdf")
    nvmem_capture_state = first(text, "ssb_nvmem_capture")
    otp_info_line = first(text, "otp_info")
    otp_info: dict[str, str] = {}
    if otp_info_line:
        for token in otp_info_line.split():
            if "=" in token:
                key, value = token.split("=", 1)
                otp_info[key] = value
    nvmem_present = bool(nvmem_bdf and otp_info_line)
    otp_supported = nvmem_present and bool(otp_info.get("otp_words") and otp_info.get("hwbase"))

    sprom_sysfs_format = first(text, "sprom_sysfs_format")
    sprom_sysfs = first(text, "sprom_sysfs")
    physical_sprom_present = bool(sprom_sysfs and sprom_sysfs != "not-found")

    # Preserve initialized identity evidence even after an explicit diagnostic tears
    # down its temporary interface and the common capabilities file becomes deferred.
    ssb_wlan_rev_m = re.search(r"^\[ssb\d+:\d+\]\n(?:(?!^\[).)*?^coreid=0x0812$\n^revision=(\d+)$", text, re.M | re.S)
    carried_m = re.search(r"nphy-rev(\d+)-radio2056-rev(\d+)", carried_receiver)
    core_rev = cap_core_rev or (str(probe["core_rev"]) if probe["core_rev"] is not None else None) or (ssb_wlan_rev_m.group(1) if ssb_wlan_rev_m else None)
    phy_type = cap_phy_type or (str(probe["phy_type"]) if probe["phy_type"] is not None else None) or ("4" if nphy_present else None)
    phy_rev = cap_phy_rev or (str(probe["phy_rev"]) if probe["phy_rev"] is not None else None) or (carried_m.group(1) if carried_m else None)
    radio_id = probe["radio_id"] or ("0x2056" if carried_m else None)
    radio_rev = probe["radio_rev"] if probe["radio_rev"] is not None else (int(carried_m.group(2)) if carried_m else None)

    analysis = {
        "schema": "rv220w-bcm4322-discovery-analysis-v5",
        "snapshot": str(args.snapshot),
        "source_profile": profile,
        "gates": {
            "wifi_discovery_profile": wifi_profile,
            "pci_physical_14e4_432b_present": pci_physical,
            "pci_14e4_432b_present": pci_physical,
            "fallback_sprom_blob_present": fallback_blob_present,
            "fallback_sprom_registered": fallback_registered,
            "fallback_sprom_requested": fallback_requested,
            "ssb_registered": ssb_registered,
            "b43_phy_present": b43_phy_present,
            "nphy_present": nphy_present,
            "b43_capabilities_read": caps_read,
            "b43_capabilities_present": caps_read or caps_deferred,
            "b43_capabilities_deferred_preinit": caps_deferred,
            "b43_firmware_inventory_present": firmware_inventory,
            "b43_firmware_loaded": firmware_loaded,
            "wiphy_present": wiphy_present,
            "physical_sprom_shadow_present": physical_sprom_present,
            "ssb_nvmem_diagnostics_present": nvmem_present,
            "otp_diagnostics_supported": otp_supported,
            "rf_calibration_qualified": rf_qualified,
            "firmware_failure_seen": firmware_failure,
        },
        "pci": {
            "address": pci_addr,
            "boot_vendor": boot_vendor,
            "boot_device": boot_device,
            "runtime_vendor": runtime_vendor,
            "runtime_device": runtime_device,
            "fallback_devid_override_observed": devid_override,
        },
        "identity": {
            "platform_base_mac": base,
            "stock_expected_wlan_mac": expected,
            "b43_permanent_mac": perm,
            "sprom_et1mac": et1,
            "sprom_il0mac": il0,
            "expected_mac_valid_unicast": valid_unicast(expected),
            "module_mac_matches_stock_policy": norm(module_mac) == norm(expected) if module_mac and expected else None,
            "mtd_mac_source": module_mac_mtd,
            "mtd_mac_offset": module_mac_mtd_offset,
            "mtd_mac_increment": module_mac_increment,
            "mtd_pio": module_pio,
            "mtd_first_probe_log_matches_stock_policy": mtd_mac_log,
            "stock_mac_apply_marker": stock_mac_marker,
            "permanent_matches_stock_policy": norm(perm) == norm(expected) if perm and expected else None,
            "sprom_et1_matches_stock_policy": norm(et1) == norm(expected) if et1 and expected else None,
            "sprom_il0_matches_stock_policy": norm(il0) == norm(expected) if il0 and expected else None,
        },
        "radio": {
            "core_rev": core_rev,
            "phy_type": phy_type,
            "phy_rev": phy_rev,
            "active_transfer": transfer,
            "probe": probe,
        },
        "capabilities": {"path": caps_path, "status": caps_status},
        "firmware": {"state": firmware_state, "inventory_present": firmware_inventory, "loaded": firmware_loaded},
        "sprom": {"sysfs_path": sprom_sysfs, "sysfs_format": sprom_sysfs_format or ("ascii-hex" if physical_sprom_present else None)},
        "ssb_nvmem": {
            "bdf": nvmem_bdf,
            "capture_state": nvmem_capture_state,
            "present": nvmem_present,
            "otp_supported": otp_supported,
            "otp_info": otp_info,
        },
        "policy": {
            "automatic_mac_override": False,
            "calibration_integrity_qualified": calibration_integrity,
            "receiver_init_qualified": receiver_init_qualified,
            "automatic_rf_test": False,
            "sprom_source": sprom_source,
            "generic_fallback_sprom": generic_sprom,
            "physical_double_read_sprom": physical_double_sprom,
            "rf_calibration_qualified": rf_qualified,
            "next_rf_gate": "apply/verify the board-derived WLAN MAC, then use the explicit acknowledged receiver-init gate; passive scan remains blocked",
        },
    }

    problems: list[str] = []
    if not wifi_profile:
        problems.append(f"snapshot source profile is {profile or 'unknown'}, not wifi-discovery")
    if not pci_physical:
        problems.append("physical BCM4322 PCI identity 14e4:432b was not observed during enumeration")
    if generic_sprom:
        if not fallback_blob_present:
            problems.append("OpenWrt BCM4322 fallback SPROM firmware was not observed")
        if not fallback_registered or not fallback_requested:
            problems.append("SSB fallback SPROM provider for PCI [0:3] did not complete registration/request")
    elif physical_double_sprom:
        if fallback_registered or fallback_requested:
            problems.append("fallback SPROM provider was unexpectedly used during native physical-SPROM qualification")
        if runtime_vendor != "0x14e4" or runtime_device != "0x432b":
            problems.append("runtime PCI identity did not remain physical 14e4:432b without fallback-SPROM override")
        if toolkit_version in {"1.14.15", "1.14.16", "1.14.17", "1.14.18", "1.14.20", "1.14.21", "1.14.23", "1.14.24", "1.14.25", "1.14.26", "1.14.27", "1.14.29", "1.14.30"} and not calibration_integrity:
            problems.append(f"v{toolkit_version} native-SPROM calibration integrity marker is not qualified")
        if stock_mac_marker:
            if toolkit_version in {"1.14.20", "1.14.21", "1.14.23", "1.14.24", "1.14.25", "1.14.26", "1.14.27", "1.14.29", "1.14.30"}:
                try:
                    mtd_offset_value = int(module_mac_mtd_offset or "", 0)
                except ValueError:
                    mtd_offset_value = None
                if not (module_mac_mtd == "boot-chain" and mtd_offset_value == 0x6ff00 and
                        module_mac_increment == "4" and module_pio in {"0", "1"} and mtd_mac_log):
                    problems.append("stock MAC apply marker exists but b43 MTD identity source/log does not match platform base+4 policy")
            elif not module_mac or norm(module_mac) != norm(expected):
                problems.append("stock MAC apply marker exists but b43 module macaddr does not match platform base+4")
    else:
        problems.append(f"unknown SPROM source policy: {sprom_source or 'missing'}")
    if not ssb_registered:
        problems.append("SSB core registration was not observed")
    if not b43_phy_present:
        problems.append("b43 did not identify the BCM4322 WLAN core")
    if not nphy_present:
        problems.append("b43 N-PHY identification was not observed")
    if caps_status in ("missing", "empty"):
        problems.append("b43 capabilities debugfs file was not observed in a usable/deferred state")
    if toolkit_version in {"1.14.8", "1.14.9", "1.14.11", "1.14.12", "1.14.13", "1.14.14", "1.14.15", "1.14.16", "1.14.17", "1.14.18", "1.14.20", "1.14.21", "1.14.23", "1.14.24", "1.14.25", "1.14.26", "1.14.27", "1.14.29", "1.14.30"} and not nvmem_present:
        problems.append("v1.14.8+ read-only SSB PCI NVM diagnostics were not captured")
    if firmware_failure:
        problems.append("kernel log contains a b43 firmware failure indication")
    if not wiphy_present:
        problems.append("no b43 wiphy evidence was observed")
    analysis["problems"] = problems

    pci_note = f"boot {boot_vendor or '?'}:{(boot_device or '?').removeprefix('0x')}; runtime {runtime_vendor or '?'}:{(runtime_device or '?').removeprefix('0x')}"
    if devid_override:
        pci_note += "; expected generic-fallback devid override"
    cap_label = "PASS" if caps_read else ("DEFERRED" if caps_deferred else "FAIL")
    lines = [
        "RV220W BCM4322/b43 discovery analysis",
        f"source profile: {profile or 'unknown'} ({'PASS' if wifi_profile else 'FAIL'})",
        f"physical PCI 14e4:432b: {'PASS' if pci_physical else 'FAIL'} ({pci_note})",
        (f"SPROM source: native physical double-read ({'PASS' if physical_double_sprom and not fallback_registered and not fallback_requested else 'FAIL'})"
         if physical_double_sprom else
         f"fallback SPROM blob/provider: {'PASS' if fallback_blob_present and fallback_registered and fallback_requested else 'FAIL'}"),
        f"SSB core registration: {'PASS' if ssb_registered else 'FAIL'} ({ssb_devices} sysfs cores)",
        f"b43 BCM4322 probe: {'PASS' if b43_phy_present else 'FAIL'}",
        f"N-PHY: {'PASS' if nphy_present else 'FAIL'} (core_rev={core_rev or 'unknown'} phy_type={phy_type or 'unknown'} phy_rev={phy_rev or 'unknown'} radio={radio_id or 'unknown'} rev={radio_rev if radio_rev is not None else 'unknown'})",
        f"wiphy: {'PASS' if wiphy_present else 'FAIL'}",
        f"b43 capabilities: {cap_label} ({caps_status})",
        f"b43 firmware: {firmware_state}; failure indication: {'YES' if firmware_failure else 'NO'}",
        f"physical SPROM shadow: {'PRESENT' if physical_sprom_present else 'NOT FOUND'}{f' ({sprom_sysfs_format or "ascii-hex"})' if physical_sprom_present else ''}",
        f"SSB PCI OTP diagnostics: {'PASS' if otp_supported else ('PRESENT' if nvmem_present else 'NOT CAPTURED')}" + (f" (BDF={nvmem_bdf} words={otp_info.get('otp_words', 'unknown')} hwbase={otp_info.get('hwbase', 'unknown')} status_fresh={otp_info.get('status_fresh', 'unknown')})" if nvmem_present else ""),
        f"RF calibration qualified: {'YES' if rf_qualified else 'NO — RF BLOCKED'}",
        f"platform base MAC: {base or 'unknown'}",
        f"stock expected WLAN MAC (+4): {expected or 'unknown'}",
        f"b43 module MAC override: {module_mac or 'empty'}" + (f" ({'PASS' if norm(module_mac) == norm(expected) else 'MISMATCH'})" if stock_mac_marker and expected and toolkit_version not in {"1.14.20", "1.14.21", "1.14.23", "1.14.24", "1.14.25", "1.14.26", "1.14.27", "1.14.29", "1.14.30"} else ""),
        f"b43 MTD MAC source: {module_mac_mtd or 'none'} offset={module_mac_mtd_offset or 'unknown'} increment={module_mac_increment or 'unknown'} pio={module_pio or 'unknown'}" + (f" ({'PASS' if mtd_mac_log else 'FAIL'})" if toolkit_version in {"1.14.20", "1.14.21", "1.14.23", "1.14.24", "1.14.25", "1.14.26", "1.14.27", "1.14.29", "1.14.30"} and stock_mac_marker else ""),
        f"b43 permanent MAC: {perm or 'unknown'}",
    ]
    if problems:
        lines.append("Next action: resolve remaining discovery evidence failures; do not perform any RF test.")
    elif toolkit_version in {"1.14.23", "1.14.24", "1.14.25", "1.14.26", "1.14.27", "1.14.29", "1.14.30"} and explicit_nphy_diag:
        lines.append("Next action: receiver initialization is hardware-qualified and DMA/PIO monitor RX remain zero; use only the explicit read-only N-PHY/IQ diagnostic gate. Association/AP remain blocked.")
    elif toolkit_version in {"1.14.20", "1.14.21"} and stock_mac_marker:
        lines.append("Next action: native calibration + MTD-derived stock identity + receiver initialization are hardware-qualified; use only the explicit CA channels 1-11 passive-scan/monitor receive gates. 5 GHz/DFS, active scan, association and AP remain blocked.")
    elif toolkit_version in {"1.14.15", "1.14.16", "1.14.17", "1.14.18"} and stock_mac_marker:
        lines.append("Next action: native calibration + stock base+4 identity are qualified; use the explicit acknowledged receiver-init gate. Passive scan/association/AP remain blocked.")
    elif physical_double_sprom and not rf_qualified:
        lines.append("Next action: native physical-SPROM discovery is qualified; apply/verify the stock base+4 WLAN identity before explicit receiver initialization.")
    elif generic_sprom and not rf_qualified:
        lines.append("Next action: PCI/SSB/b43/N-PHY discovery is qualified; capture/audit physical SPROM evidence before firmware/RF activation.")
    else:
        lines.append("Next action: review calibration and MAC identity before any explicitly gated RF operation.")
    rendered = "\n".join(lines) + "\n"

    if args.json_path:
        args.json_path.write_text(json.dumps(analysis, indent=2, sort_keys=True) + "\n")
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end="")
    return 0 if not problems else 1


if __name__ == "__main__":
    raise SystemExit(main())
