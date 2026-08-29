#!/usr/bin/env python3
"""Analyze RV220W normal BCM4322/b43 managed-start evidence.

Schema v2 makes automatic RX-IQ/RCCAL invocation diagnostic rather than a
normal-operation gate. v1.14.80 qualifies the forced-PIO baseline; v1.14.81
qualifies the otherwise-identical native-DMA experiment.
"""
from __future__ import annotations
import argparse, json, re
from pathlib import Path


def first(text: str, key: str):
    m = re.search(rf"^{re.escape(key)}=(.*)$", text, re.M)
    return m.group(1).strip() if m else None


def integer(v, default=None):
    try:
        return int(v)
    except (TypeError, ValueError):
        return default


def ciu_enabled(snapshot):
    if not snapshot or snapshot == "missing":
        return None
    m = re.search(r"pci_int_enabled=0x([0-9a-f]+)", snapshot, re.I)
    return int(m.group(1), 16) if m else None


def section(text: str, start: str, end: str):
    m = re.search(rf"^{re.escape(start)}\n(.*?)^{re.escape(end)}$", text, re.M | re.S)
    return m.group(1) if m else ""


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("input", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    a = ap.parse_args()
    text = a.input.read_text(errors="replace")

    probe = first(text, "normal_start_probe_revision")
    mode = first(text, "normal_start_mode")
    if probe == "v1.14.80":
        expected_transport = "pio"
        expected_pio = "1"
        transport_label = "PIO"
    elif probe == "v1.14.81":
        expected_transport = "dma"
        expected_pio = "0"
        transport_label = "native DMA"
    else:
        expected_transport = None
        expected_pio = None
        transport_label = "unknown transport"

    transport_rc = integer(first(text, "normal_start_transport_rc"))
    stdout_bytes = integer(first(text, "normal_start_stdout_bytes"))
    stderr_bytes = integer(first(text, "normal_start_stderr_bytes"))
    country = first(text, "normal_start_country")
    no_debugfs = first(text, "normal_start_no_debugfs_calibration")
    no_monitor = first(text, "normal_start_no_monitor_handoff")
    no_gate = first(text, "normal_start_no_channel8_gate")
    reg_rc = integer(first(text, "normal_start_reg_set_rc"))
    reg_ok = first(text, "normal_start_regulatory_verified")
    expected = (first(text, "stock_expected_wlan_mac") or "").lower()
    iface = (first(text, "normal_start_interface_mac") or "").lower()
    pio = first(text, "b43_module_pio")
    ifadd = integer(first(text, "normal_start_interface_add_rc"))
    ifup = integer(first(text, "normal_start_interface_up_rc"))
    ready = first(text, "normal_start_interface_ready")
    cal_start = integer(first(text, "normal_start_cal_start_delta"), 0)
    cal_pass = integer(first(text, "normal_start_cal_pass_delta"), 0)
    cal_fail = integer(first(text, "normal_start_cal_fail_delta"), 0)
    operating = first(text, "normal_start_b43_operating")
    transfer = first(text, "normal_start_b43_transfer")
    status = integer(first(text, "normal_start_b43_status"))
    scan_started = first(text, "normal_start_scan_started")
    scan_rc = integer(first(text, "normal_start_scan_rc"))
    tx_before = integer(first(text, "normal_start_txstatus_before"), 0)
    tx_after = integer(first(text, "normal_start_txstatus_after"), 0)
    tx_delta = integer(first(text, "normal_start_txstatus_delta"), 0)
    irq = integer(first(text, "normal_start_host_irq"))
    irq_before = integer(first(text, "normal_start_host_irq_count_before"), 0)
    irq_after = integer(first(text, "normal_start_host_irq_count_after"), 0)
    irq_delta = integer(first(text, "normal_start_host_irq_count_delta"), 0)
    ciu_before = ciu_enabled(first(text, "normal_start_octeon_ciu_before"))
    ciu_after = ciu_enabled(first(text, "normal_start_octeon_ciu_after"))
    stations = integer(first(text, "normal_start_station_count"), -1)
    complete = first(text, "normal_start_capture_complete")

    scan_mode = first(text, "requested_scan_mode")
    probes = first(text, "requested_probe_requests")
    assoc = first(text, "requested_association")
    auth = first(text, "requested_authentication")
    ap_req = first(text, "requested_ap")
    inj = first(text, "requested_frame_injection")
    persist = first(text, "requested_persistent_write")
    nvm = first(text, "requested_nvm_write")
    nor = first(text, "requested_nor_write")

    scan = section(text, "=== normal-start scan results ===", "=== normal-start post-scan b43 txstatus ===")
    bss = re.findall(r"^BSS\s+([0-9a-f:]+)", scan, re.M | re.I)
    freqs = [int(float(v)) for v in re.findall(r"^\s*freq:\s*(\d+(?:\.\d+)?)\s*$", scan, re.M)]
    signals = [float(v) for v in re.findall(r"^\s*signal:\s*(-?\d+(?:\.\d+)?)\s+dBm", scan, re.M)]
    ssids = re.findall(r"^\s*SSID:\s*(.*)$", scan, re.M)
    link = section(text, "=== normal-start post-scan link ===", "=== normal-start post-scan station dump ===")
    not_connected = "Not connected." in link
    dmesg = section(text, "=== normal-start dmesg tail ===", "normal_start_capture_complete=1")

    # Calibration invocation is telemetry in the full-send/native-transport A/B
    # experiment. Remove its explicitly tagged failure line before looking for
    # unrelated b43 transport/firmware failures.
    dmesg_transport = "\n".join(
        line for line in dmesg.splitlines()
        if "normal RX-IQ/RCCAL calibration failed" not in line
    )
    kernel_error = bool(re.search(
        r"b43[^\n]*(?:error|failed|failure|firmware[^\n]*(?:not found|too old|unsupported))",
        dmesg_transport, re.I,
    ))
    cal_kernel_failure = "normal RX-IQ/RCCAL calibration failed" in dmesg
    calibration_observed = cal_start >= 1
    calibration_passed = cal_pass >= 1 and cal_fail == 0 and not cal_kernel_failure
    allowed = {2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462}

    gates = {
        "evidence_nonempty": bool(text.strip()),
        "transport_succeeded": transport_rc in (None, 0),
        "probe_supported": probe in {"v1.14.80", "v1.14.81"},
        "country_ca": country == "CA" and reg_rc == 0 and reg_ok == "1",
        "normal_path_no_interposed_gates": no_debugfs == "1" and no_monitor == "1" and no_gate == "1",
        "identity": bool(expected) and expected == iface,
        "requested_native_transport": expected_pio is not None and pio == expected_pio,
        "active_transport_matches": expected_transport is not None and transfer == expected_transport,
        "interface_started": ifadd == 0 and ifup == 0 and ready == "1" and operating == "1" and status == 2,
        "scan_requested_normal": scan_mode == "active-normal-cfg80211" and probes == "1",
        "scan_succeeded": scan_started == "1" and scan_rc == 0,
        "tx_status_advanced": tx_delta > 0 and tx_after > tx_before,
        "bss_received": len(bss) > 0,
        "bss_frequencies_2g_ca": bool(freqs) and all(f in allowed for f in freqs),
        "pci_irq_active": irq == 109 and irq_delta > 0 and irq_after > irq_before and ciu_before == 1 and ciu_after == 1,
        "remained_unassociated": not_connected and stations == 0,
        "no_assoc_auth_ap_injection_persistence": assoc == "0" and auth == "0" and ap_req == "0" and inj == "0" and persist == "0" and nvm == "0" and nor == "0",
        "no_transport_kernel_error": not kernel_error,
        "capture_complete": complete == "1",
    }
    problems = [k for k, v in gates.items() if not v]

    if not gates["interface_started"]:
        finding = "normal-start-managed-interface-failed"
    elif not gates["requested_native_transport"]:
        finding = "normal-start-module-transport-selection-mismatch"
    elif not gates["active_transport_matches"]:
        finding = "normal-start-native-dma-not-selected" if probe == "v1.14.81" else "normal-start-pio-not-active"
    elif not gates["scan_succeeded"]:
        finding = "normal-start-cfg80211-scan-failed"
    elif not gates["tx_status_advanced"]:
        finding = "normal-start-no-b43-tx-status"
    elif not gates["bss_received"]:
        finding = "normal-start-tx-without-bss-results"
    elif not gates["pci_irq_active"]:
        finding = "normal-start-irq-anomaly"
    elif problems:
        finding = "normal-start-qualification-incomplete"
    elif probe == "v1.14.81":
        finding = "b43-normal-managed-dma-2g-scan-qualified"
    else:
        finding = "b43-normal-managed-pio-2g-scan-qualified"

    passed = not problems
    data = {
        "schema": "rv220w-b43-normal-start-analysis-v2",
        "input": str(a.input),
        "finding": finding,
        "passed": passed,
        "gates": gates,
        "problems": problems,
        "transport": {"host_rc": transport_rc, "stdout_bytes": stdout_bytes, "stderr_bytes": stderr_bytes,
                      "module_pio": pio, "expected": expected_transport, "active": transfer},
        "calibration": {"start_delta": cal_start, "pass_delta": cal_pass, "fail_delta": cal_fail,
                        "observed": calibration_observed, "passed_if_observed": calibration_passed,
                        "kernel_failure": cal_kernel_failure},
        "interface": {"expected_mac": expected or None, "interface_mac": iface or None,
                      "operating": operating, "transfer": transfer, "status": status},
        "scan": {"rc": scan_rc, "bss_count": len(bss), "frequencies": sorted(set(freqs)),
                 "bssids": bss, "ssids": ssids, "signals_dbm": signals},
        "tx": {"before": tx_before, "after": tx_after, "delta": tx_delta},
        "irq": {"irq": irq, "before": irq_before, "after": irq_after, "delta": irq_delta,
                "ciu_before": ciu_before, "ciu_after": ciu_after},
    }
    cal_desc = "not-invoked"
    if calibration_observed:
        cal_desc = "pass" if calibration_passed else "failed"
    lines = [
        f"RV220W BCM4322/b43 normal managed-start {transport_label} qualification",
        f"transport: host_rc={transport_rc if transport_rc is not None else '?'} module_pio={pio or '?'} active={transfer or '?'} expected={expected_transport or '?'} "
        f"stdout={stdout_bytes if stdout_bytes is not None else '?'}B stderr={stderr_bytes if stderr_bytes is not None else '?'}B probe={probe or '?'} "
        f"({'PASS' if gates['transport_succeeded'] and gates['requested_native_transport'] and gates['active_transport_matches'] else 'FAIL'})",
        f"normal path: no-debugfs-cal={no_debugfs} no-monitor={no_monitor} no-gate={no_gate} ({'PASS' if gates['normal_path_no_interposed_gates'] else 'FAIL'})",
        f"automatic PHY calibration telemetry: start/pass/fail delta={cal_start}/{cal_pass}/{cal_fail} state={cal_desc} (INFO; not a qualification gate)",
        f"managed interface: add/up={ifadd}/{ifup} operating={operating} status={status} transfer={transfer} MAC={iface or 'missing'} "
        f"({'PASS' if gates['interface_started'] and gates['identity'] else 'FAIL'})",
        f"normal cfg80211 scan: rc={scan_rc} BSS={len(bss)} freqs={sorted(set(freqs))} "
        f"({'PASS' if gates['scan_succeeded'] and gates['bss_received'] and gates['bss_frequencies_2g_ca'] else 'FAIL'})",
        f"b43 TX status: {tx_before}->{tx_after} delta={tx_delta} ({'PASS' if gates['tx_status_advanced'] else 'FAIL'})",
        f"PCI/host IRQ: irq={irq} count={irq_before}->{irq_after} delta={irq_delta} ciu={ciu_before}->{ciu_after} ({'PASS' if gates['pci_irq_active'] else 'FAIL'})",
        f"post-scan isolation: not_connected={int(not_connected)} stations={stations} ({'PASS' if gates['remained_unassociated'] else 'FAIL'})",
        f"finding: {finding}",
        f"overall: {'PASS' if passed else 'FAIL'}",
    ]
    if signals:
        lines.append(f"signal range observed: {min(signals):.1f}..{max(signals):.1f} dBm")
    if ssids:
        lines.append("SSIDs observed: " + ", ".join(sorted(set(s for s in ssids if s))))
    if problems:
        lines.append("failed gates: " + ", ".join(problems))
    out = "\n".join(lines) + "\n"
    print(out, end="")
    if a.text_path:
        a.text_path.write_text(out)
    if a.json_path:
        a.json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
