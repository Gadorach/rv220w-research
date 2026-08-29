#!/usr/bin/env python3
"""Analyze the explicit RV220W rev4/BCM2056 RX-IQ calibration experiment."""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


def kv(text: str, key: str) -> str | None:
    matches = re.findall(rf"^{re.escape(key)}=(.*)$", text, re.M)
    return matches[-1].strip() if matches else None


def intval(value: str | None) -> int | None:
    if value is None:
        return None
    try:
        return int(value, 0)
    except ValueError:
        return None


def expected_2g_frequency(channel: int | None) -> int | None:
    if channel is None or channel < 1 or channel > 11:
        return None
    return 2407 + channel * 5


def tuple_value(text: str, prefix: str) -> tuple[int, int, int, int] | None:
    vals = []
    for name in ("a0", "b0", "a1", "b1"):
        v = intval(kv(text, f"{prefix}_{name}"))
        if v is None:
            return None
        vals.append(v)
    return tuple(vals)  # type: ignore[return-value]


CLEANUP_BITS = {
    0: "core0_rfctl_tx",
    1: "core0_rfctl_rx",
    2: "core0_afectl_over",
    3: "core0_afectl_core",
    4: "core0_rfseqca",
    5: "core1_rfctl_tx",
    6: "core1_rfctl_rx",
    7: "core1_afectl_over",
    8: "core1_afectl_core",
    9: "core1_rfseqca",
    10: "final_rfseq_reset2rx_timeout",
    11: "gain_table_core0",
    12: "gain_table_core1",
    13: "radio_spare_cleanup_core0",
    14: "radio_spare_cleanup_core1",
    15: "deaf_count",
}


def decode_cleanup_mask(mask: int | None) -> list[str]:
    if mask is None:
        return []
    return [name for bit, name in CLEANUP_BITS.items() if mask & (1 << bit)]


CALC_ERRORS = {
    0: "ok",
    1: "insufficient_final_iq_power",
    2: "a_divisor_zero",
    3: "b_divisor_zero",
    4: "core_mask_mismatch",
}


def calc_error_name(value: int | None) -> str:
    if value is None:
        return "unavailable"
    return CALC_ERRORS.get(value, f"unknown_{value}")


def pass_forensics(text: str, core: int) -> list[dict[str, int | None]]:
    out = []
    for p in range(3):
        out.append({
            "i_pwr": intval(kv(text, f"core{core}_pass{p}_i_pwr")),
            "q_pwr": intval(kv(text, f"core{core}_pass{p}_q_pwr")),
            "iq_prod": intval(kv(text, f"core{core}_pass{p}_iq_prod")),
            "selection_power": intval(kv(text, f"core{core}_pass{p}_power")),
            "packed_gain": intval(kv(text, f"core{core}_pass{p}_packed_gain")),
        })
    return out


def csv4(value: str | None) -> tuple[int, int, int, int] | None:
    if not value:
        return None
    try:
        vals = tuple(int(x, 0) for x in value.split(","))
    except ValueError:
        return None
    return vals if len(vals) == 4 else None  # type: ignore[return-value]



def pci_irq_window(value: str | None) -> tuple[int, int, int] | None:
    if value is None or not re.fullmatch(r"[0-9a-fA-F]{24}", value):
        return None
    raw = bytes.fromhex(value)
    return tuple(int.from_bytes(raw[i:i+4], "little") for i in (0, 4, 8))  # type: ignore[return-value]


def pci_header64(value: str | None) -> dict[str, int | bool] | None:
    if value is None or not re.fullmatch(r"[0-9a-fA-F]{128}", value):
        return None
    raw = bytes.fromhex(value)
    command = int.from_bytes(raw[4:6], "little")
    return {
        "command": command,
        "status": int.from_bytes(raw[6:8], "little"),
        "interrupt_line": raw[0x3c],
        "interrupt_pin": raw[0x3d],
        "intx_disabled": bool(command & 0x0400),
    }


def ciu_irq_snapshot(value: str | None) -> dict[str, int] | None:
    if not value or value == "missing":
        return None
    vals: dict[str, int] = {}
    for key in ("core", "ciu_index", "sum0", "en0", "pci_int_pending", "pci_int_enabled"):
        m = re.search(rf"(?:^|\s){key}=([^\s]+)", value)
        if not m:
            return None
        try:
            vals[key] = int(m.group(1), 0)
        except ValueError:
            return None
    return vals


def host_ciu_bit(value: str | None) -> int | None:
    if not value:
        return None
    m = re.search(r"\bCIU\s+(\d+)\b", value)
    return int(m.group(1)) if m else None


def analyze_v11460(text: str, input_path: Path, json_path: Path | None, text_path: Path | None) -> int:
    policy = kv(text, "rxiq_calibration_policy")
    is_v69 = policy == "v1.14.69-channel8-operational-retained-calibration-pci-int0-routing"
    is_v66 = policy == "v1.14.66-channel8-operational-retained-calibration-ciu-intx-telemetry"
    is_ciu = is_v66 or is_v69
    is_v65 = policy == "v1.14.65-channel8-operational-retained-calibration-irq-delivery-telemetry"
    is_v62 = policy == "v1.14.62-channel8-operational-retained-calibration-rx-path-telemetry"
    is_v61 = policy == "v1.14.61-channel8-operational-retained-calibration-rx-capture-hotfix"
    is_v60 = policy == "v1.14.60-channel8-operational-retained-calibration-rx-only"
    expected = kv(text, "stock_expected_wlan_mac")
    iface_mac = kv(text, "rxiq_calibration_interface_mac")
    candidate = csv4(kv(text, "rxiq_calibration_candidate_tuple"))
    verified_iq = csv4(kv(text, "rxiq_post_rx_verify_iq_tuple"))
    delta = intval(kv(text, "rxiq_observation_rx_packets_delta")) or 0
    frames = intval(kv(text, "rxiq_observation_tcpdump_frames")) or 0
    expected_rx_lpc = intval(kv(text, "rccal_expected_rx_lpc"))
    expected_rx_hpc = intval(kv(text, "rccal_expected_rx_hpc"))
    expected_tx_lpc = intval(kv(text, "rccal_expected_tx_lpc"))
    verify_regs = [
        intval(kv(text, "verify_rccal_rx_lpc0")), intval(kv(text, "verify_rccal_rx_lpc1")),
        intval(kv(text, "verify_rccal_rx_hpc0")), intval(kv(text, "verify_rccal_rx_hpc1")),
        intval(kv(text, "verify_rccal_tx_lpc0")), intval(kv(text, "verify_rccal_tx_lpc1")),
    ]
    expected_regs = [expected_rx_lpc, expected_rx_lpc, expected_rx_hpc, expected_rx_hpc, expected_tx_lpc, expected_tx_lpc]
    kernel_bad = bool(re.search(r"b43.*(?:ERROR|error)|RF sequence.*(?:error|timeout)", text, re.I))
    irq_delta = intval(kv(text, "rxiq_rxpath_irq_total_delta"))
    done_delta = intval(kv(text, "rxiq_rxpath_dma0_rx_done_delta"))
    pio_delta = intval(kv(text, "rxiq_rxpath_pio_dispatch_delta"))
    frame_delta = intval(kv(text, "rxiq_rxpath_pio_frame_ready_delta"))
    data_delta = intval(kv(text, "rxiq_rxpath_pio_data_ready_delta"))
    header_delta = intval(kv(text, "rxiq_rxpath_pio_header_ok_delta"))
    timeout_delta = intval(kv(text, "rxiq_rxpath_pio_timeout_delta"))
    error_delta = intval(kv(text, "rxiq_rxpath_pio_error_delta"))
    lenerr_delta = intval(kv(text, "rxiq_rxpath_pio_len_error_delta"))
    fcserr_delta = intval(kv(text, "rxiq_rxpath_pio_fcs_error_delta"))
    b43_enter_delta = intval(kv(text, "rxiq_rxpath_b43_enter_delta"))
    b43_drop_delta = intval(kv(text, "rxiq_rxpath_b43_drop_delta"))
    delivered_delta = intval(kv(text, "rxiq_rxpath_b43_delivered_delta"))
    pio_timeouts = intval(kv(text, "rxiq_rxpath_pio_timeout_messages"))
    pio_errors = intval(kv(text, "rxiq_rxpath_pio_error_messages"))
    host_irq = intval(kv(text, "rxiq_host_irq_number"))
    host_irq_before = intval(kv(text, "rxiq_host_irq_count_before"))
    host_irq_after = intval(kv(text, "rxiq_host_irq_count_after"))
    host_irq_delta = intval(kv(text, "rxiq_host_irq_count_delta"))
    host_line_before = intval(kv(text, "rxiq_host_irq_line_present_before"))
    host_line_after = intval(kv(text, "rxiq_host_irq_line_present_after"))
    pci_window_before = pci_irq_window(kv(text, "rxiq_ssb_pci_irq_window_0x90_0x9b_before"))
    pci_window_after = pci_irq_window(kv(text, "rxiq_ssb_pci_irq_window_0x90_0x9b_after"))
    gen_mask_after = intval(kv(text, "rxiq_rxpath_gen_irq_mask_after"))
    gen_reason_after = intval(kv(text, "rxiq_rxpath_gen_irq_reason_after"))
    dma0_mask_after = intval(kv(text, "rxiq_rxpath_dma0_irq_mask_after"))
    dma0_reason_after = intval(kv(text, "rxiq_rxpath_dma0_reason_after"))
    pending_dma_irq = bool(gen_mask_after is not None and gen_reason_after is not None and (gen_mask_after & gen_reason_after & 0x00008000))
    pending_rx_done = bool(dma0_mask_after is not None and dma0_reason_after is not None and (dma0_mask_after & dma0_reason_after & 0x00010000))
    pci_header_before = pci_header64(kv(text, "rxiq_pci_config_header64_before"))
    pci_header_after = pci_header64(kv(text, "rxiq_pci_config_header64_after"))
    ciu_before = ciu_irq_snapshot(kv(text, "rxiq_octeon_ciu_irq_diag_before"))
    ciu_after = ciu_irq_snapshot(kv(text, "rxiq_octeon_ciu_irq_diag_after"))
    assigned_ciu_bit = host_ciu_bit(kv(text, "rxiq_host_irq_line_after"))
    assigned_pci_int = assigned_ciu_bit - 36 if assigned_ciu_bit is not None and 36 <= assigned_ciu_bit <= 39 else None
    ciu_pending = ciu_after["pci_int_pending"] if ciu_after else None
    ciu_enabled = ciu_after["pci_int_enabled"] if ciu_after else None
    assigned_pci_mask = (1 << assigned_pci_int) if assigned_pci_int is not None else 0
    gates = {
        "policy_scope": is_v60 or is_v61 or is_v62 or is_v65 or is_ciu,
        "country_ca": kv(text, "rxiq_calibration_country") == "CA",
        "channel8_2447": kv(text, "rxiq_calibration_channel") == "8" and kv(text, "rxiq_calibration_frequency") == "2447" and kv(text, "rxiq_calibration_reported_frequency") == "2447",
        "setfreq_succeeded": kv(text, "rxiq_calibration_setfreq_rc") == "0",
        "mtd_identity_pio": kv(text, "b43_macaddr_mtd") == "boot-chain" and kv(text, "b43_macaddr_mtd_offset") == "458496" and kv(text, "b43_macaddr_increment") == "4" and kv(text, "b43_module_pio") == "1",
        "interface_mac": bool(expected and iface_mac and expected.lower() == iface_mac.lower()),
        "calibration_requested": kv(text, "requested_calibration_sequence") == "1",
        "internal_tone_requested": kv(text, "requested_internal_cal_tone") == "1",
        "passive_rx_requested": kv(text, "requested_passive_receiver_observation") == "1",
        "no_scan": kv(text, "requested_scan") == "0",
        "no_probe_requests": kv(text, "requested_probe_requests") == "0",
        "no_ssid_requests": kv(text, "requested_ssid_count") == "0",
        "no_association_requested": kv(text, "requested_association") == "0",
        "no_ap_requested": kv(text, "requested_ap") == "0",
        "no_user_tx_requested": kv(text, "requested_user_tx") == "0",
        "no_frame_injection": kv(text, "requested_frame_injection") == "0",
        "no_persistent_write": kv(text, "requested_persistent_write") == "0" and kv(text, "requested_nvm_write") == "0" and kv(text, "requested_nor_write") == "0",
        "no_automatic_startup_calibration": kv(text, "automatic_startup_calibration") == "0",
        "run_succeeded": kv(text, "rxiq_calibration_run_rc") == "0" and kv(text, "rxiq_calibration_primary_rc") == "0",
        "temporary_state_cleanup_verified": kv(text, "rxiq_calibration_cleanup_rc") == "0" and kv(text, "rxiq_calibration_cleanup_fail_mask") == "0x00000000",
        "retained_state_active": kv(text, "rxiq_calibration_retained_state_verified") == "1" and kv(text, "rxiq_calibration_rollback_verified") == "0" and candidate is not None,
        "run_mac_suspend_verified": kv(text, "rxiq_calibration_run_mac_suspend_verified") == "1",
        "run_mac_resume_verified": kv(text, "rxiq_calibration_run_mac_resume_verified") == "1",
        "capture_backend_ready": (is_v60) or (
            kv(text, "rxiq_observation_capture_backend") == "tcpdump-background-sigint" and
            kv(text, "rxiq_observation_window_seconds") == "8" and
            kv(text, "rxiq_observation_capture_started") == "1" and
            kv(text, "rxiq_observation_tcpdump_rc") == "0"
        ),
        "rxpath_telemetry_present": (not (is_v62 or is_v65 or is_ciu)) or all(v is not None for v in (
            irq_delta, done_delta, pio_delta, frame_delta, data_delta, header_delta,
            timeout_delta, error_delta, lenerr_delta, fcserr_delta,
            b43_enter_delta, b43_drop_delta, delivered_delta, pio_timeouts, pio_errors
        )),
        "irq_delivery_telemetry_present": (not (is_v65 or is_ciu)) or (
            host_irq is not None and host_irq >= 0 and host_irq_before is not None and host_irq_after is not None and host_irq_delta is not None and
            host_line_before == 1 and host_line_after == 1 and pci_window_before is not None and pci_window_after is not None and
            gen_mask_after is not None and gen_reason_after is not None and dma0_mask_after is not None and dma0_reason_after is not None
        ),
        "ciu_intx_telemetry_present": (not is_ciu) or (
            pci_header_before is not None and pci_header_after is not None and ciu_before is not None and ciu_after is not None and
            assigned_ciu_bit is not None and assigned_pci_int is not None
        ),
        "rv220w_pci_int0_route_active": (not is_v69) or (
            assigned_ciu_bit == 36 and assigned_pci_int == 0 and pci_header_after is not None and
            pci_header_after["interrupt_pin"] == 1 and not pci_header_after["intx_disabled"] and
            ciu_enabled is not None and bool(ciu_enabled & 0x1)
        ),
        "receive_packet_growth": delta > 0,
        "receive_frames_captured": frames > 0,
        "remained_unassociated": kv(text, "rxiq_observation_associated") == "0",
        "zero_stations": kv(text, "rxiq_observation_station_count") == "0",
        "post_rx_verify_write": kv(text, "rxiq_post_rx_verify_write_rc") == "0",
        "post_rx_verify_attempted": kv(text, "rxiq_post_rx_verify_attempted") == "1",
        "post_rx_verify_succeeded": kv(text, "rxiq_post_rx_verify_rc") == "0" and kv(text, "rxiq_post_rx_verify_verified") == "1",
        "post_rx_verify_mac_suspend": kv(text, "rxiq_post_rx_verify_mac_suspend_verified") == "1",
        "post_rx_verify_mac_resume": kv(text, "rxiq_post_rx_verify_mac_resume_verified") == "1",
        "post_rx_iq_stable": candidate is not None and verified_iq == candidate,
        "post_rx_rccal_stable": None not in expected_regs and verify_regs == expected_regs,
        "capture_complete": kv(text, "rxiq_calibration_capture_complete") == "1",
        "no_kernel_error": not kernel_bad,
    }
    problems = [k for k, v in gates.items() if not v]
    if not problems:
        finding = "rxiq-operational-calibration-receiver-rx-qualified"
    elif is_v60 and (kv(text, "rxiq_observation_tcpdump_rc") == "127" or "timeout: not found" in text):
        finding = "rxiq-operational-calibration-capture-runner-unavailable"
    elif not gates["capture_backend_ready"]:
        finding = "rxiq-operational-calibration-capture-runner-failed"
    elif (is_v65 or is_ciu) and not gates["irq_delivery_telemetry_present"]:
        finding = "rxiq-operational-rx-irq-delivery-telemetry-missing"
    elif is_ciu and not gates["ciu_intx_telemetry_present"]:
        finding = "rxiq-operational-rx-ciu-intx-telemetry-missing"
    elif is_v69 and not gates["rv220w_pci_int0_route_active"]:
        finding = "rxiq-operational-rx-rv220w-pci-int0-route-not-active"
    elif (is_v62 or is_v65 or is_ciu) and not gates["rxpath_telemetry_present"]:
        finding = "rxiq-operational-rx-path-telemetry-missing"
    elif (is_v62 or is_v65 or is_ciu) and (not gates["post_rx_verify_write"] or not gates["post_rx_verify_attempted"] or not gates["post_rx_verify_succeeded"]):
        finding = "rxiq-operational-calibration-post-rx-retained-verify-failed"
    elif (is_v62 or is_v65 or is_ciu) and (not gates["post_rx_verify_mac_suspend"] or not gates["post_rx_verify_mac_resume"]):
        finding = "rxiq-operational-calibration-post-rx-mac-serialization-failed"
    elif (is_v62 or is_v65 or is_ciu) and not gates["post_rx_iq_stable"]:
        finding = "rxiq-operational-calibration-post-rx-iq-drift"
    elif (is_v62 or is_v65 or is_ciu) and not gates["post_rx_rccal_stable"]:
        finding = "rxiq-operational-calibration-post-rx-rccal-drift"
    elif (is_v62 or is_v65 or is_ciu) and (not gates["receive_packet_growth"] or not gates["receive_frames_captured"]):
        if is_ciu and (host_irq_delta or 0) == 0 and (irq_delta or 0) == 0 and pending_dma_irq and pending_rx_done:
            if pci_header_after and pci_header_after["intx_disabled"]:
                finding = "rxiq-operational-rx-pci-intx-disabled"
            elif ciu_pending is None:
                finding = "rxiq-operational-rx-ciu-intx-telemetry-missing"
            elif ciu_pending == 0:
                finding = "rxiq-operational-rx-no-octeon-pci-intx-assertion"
            elif assigned_pci_mask and not (ciu_pending & assigned_pci_mask):
                finding = "rxiq-operational-rx-pci-intx-routing-mismatch"
            elif assigned_pci_mask and ciu_enabled is not None and not (ciu_enabled & assigned_pci_mask):
                finding = "rxiq-operational-rx-assigned-ciu-line-masked"
            else:
                finding = "rxiq-operational-rx-assigned-ciu-pending-no-linux-irq"
        elif (is_v65 or is_ciu) and (host_irq_delta or 0) == 0 and (irq_delta or 0) == 0:
            if pending_dma_irq and pending_rx_done:
                finding = "rxiq-operational-rx-pending-rx-done-no-host-irq"
            else:
                finding = "rxiq-operational-rx-no-host-irq-delivery"
        elif (is_v65 or is_ciu) and (irq_delta or 0) == 0:
            finding = "rxiq-operational-rx-host-irq-without-b43-claim"
        elif (irq_delta or 0) == 0:
            finding = "rxiq-operational-rx-no-device-interrupts"
        elif (done_delta or 0) == 0:
            finding = "rxiq-operational-rx-no-dma0-rx-done"
        elif (pio_delta or 0) == 0:
            finding = "rxiq-operational-rx-done-not-dispatched-to-pio"
        elif (frame_delta or 0) == 0:
            finding = "rxiq-operational-rx-pio-no-frame-ready"
        elif (data_delta or 0) == 0:
            if (timeout_delta or 0) > 0 or (pio_timeouts or 0) > 0:
                finding = "rxiq-operational-rx-pio-data-timeout"
            else:
                finding = "rxiq-operational-rx-pio-no-data-ready"
        elif (lenerr_delta or 0) > 0:
            finding = "rxiq-operational-rx-pio-length-error"
        elif (fcserr_delta or 0) > 0:
            finding = "rxiq-operational-rx-pio-fcs-rejected"
        elif (header_delta or 0) == 0:
            finding = "rxiq-operational-rx-pio-header-not-accepted"
        elif (error_delta or 0) > 0 and (b43_enter_delta or 0) == 0:
            finding = "rxiq-operational-rx-pio-frame-error"
        elif (b43_enter_delta or 0) == 0:
            finding = "rxiq-operational-rx-pio-frame-not-handed-to-b43"
        elif (b43_drop_delta or 0) > 0 and (delivered_delta or 0) == 0:
            finding = "rxiq-operational-rx-b43-frame-decode-drop"
        elif (delivered_delta or 0) == 0:
            finding = "rxiq-operational-rx-b43-no-mac80211-delivery"
        else:
            finding = "rxiq-operational-rx-mac80211-monitor-delivery-gap"
    elif not gates["receive_packet_growth"] or not gates["receive_frames_captured"]:
        finding = "rxiq-operational-calibration-no-passive-rx"
    elif not gates["remained_unassociated"] or not gates["zero_stations"]:
        finding = "rxiq-operational-calibration-associated-unexpectedly"
    elif not gates["post_rx_iq_stable"]:
        finding = "rxiq-operational-calibration-post-rx-iq-drift"
    elif not gates["post_rx_rccal_stable"]:
        finding = "rxiq-operational-calibration-post-rx-rccal-drift"
    elif not gates["post_rx_verify_mac_suspend"] or not gates["post_rx_verify_mac_resume"]:
        finding = "rxiq-operational-calibration-post-rx-mac-serialization-failed"
    else:
        finding = "rxiq-operational-calibration-gate-failed"
    data = {
        "schema": "rv220w-b43-rxiq-calibration-v9" if is_v69 else ("rv220w-b43-rxiq-calibration-v8" if is_v66 else ("rv220w-b43-rxiq-calibration-v7" if is_v65 else ("rv220w-b43-rxiq-calibration-v6" if is_v62 else ("rv220w-b43-rxiq-calibration-v4" if is_v61 else "rv220w-b43-rxiq-calibration-v3")))),
        "input": str(input_path), "finding": finding, "passed": not problems,
        "candidate_iq": list(candidate) if candidate else None,
        "post_rx_iq": list(verified_iq) if verified_iq else None,
        "expected_rccal": expected_regs, "post_rx_rccal": verify_regs,
        "rx_packets_delta": delta, "tcpdump_frames": frames,
        "octeon_ciu": {
            "sum0": ciu_after["sum0"] if ciu_after else None,
            "en0": ciu_after["en0"] if ciu_after else None,
            "pci_int_pending": ciu_pending, "pci_int_enabled": ciu_enabled,
            "assigned_ciu_bit": assigned_ciu_bit, "assigned_pci_int": assigned_pci_int,
            "pci_header": pci_header_after,
        },
        "irq_delivery": {
            "host_irq": host_irq, "count_before": host_irq_before, "count_after": host_irq_after, "count_delta": host_irq_delta,
            "line_present_before": host_line_before, "line_present_after": host_line_after,
            "ssb_pci_irqs": pci_window_after[0] if pci_window_after else None,
            "ssb_pci_irqmask": pci_window_after[1] if pci_window_after else None,
            "ssb_backplane_irqs": pci_window_after[2] if pci_window_after else None,
            "pending_dma_irq": pending_dma_irq, "pending_rx_done": pending_rx_done,
            "gen_irq_mask": gen_mask_after, "gen_irq_reason": gen_reason_after,
            "dma0_irq_mask": dma0_mask_after, "dma0_reason": dma0_reason_after,
        },
        "rxpath": {
            "irq_delta": irq_delta, "dma0_rx_done_delta": done_delta,
            "pio_dispatch_delta": pio_delta, "pio_frame_ready_delta": frame_delta,
            "pio_data_ready_delta": data_delta, "pio_header_ok_delta": header_delta,
            "pio_timeout_delta": timeout_delta, "pio_error_delta": error_delta,
            "pio_len_error_delta": lenerr_delta, "pio_fcs_error_delta": fcserr_delta,
            "b43_enter_delta": b43_enter_delta, "b43_drop_delta": b43_drop_delta,
            "mac80211_delivered_delta": delivered_delta,
            "pio_timeout_messages": pio_timeouts, "pio_error_messages": pio_errors,
        },
        "gates": gates, "problems": problems,
    }
    lines = [
        "RV220W b43 rev4/BCM2056 operational retained-calibration receiver analysis",
        f"scope/policy: {'PASS' if gates['policy_scope'] else 'FAIL'}",
        f"country/channel: CA / ch 8 / 2447 MHz ({'PASS' if gates['country_ca'] and gates['channel8_2447'] else 'FAIL'})",
        f"retained calibration: rc={kv(text,'rxiq_calibration_run_rc') or '?'} primary={kv(text,'rxiq_calibration_primary_rc') or '?'} cleanup={kv(text,'rxiq_calibration_cleanup_rc') or '?'} mask={kv(text,'rxiq_calibration_cleanup_fail_mask') or '?'} retained={kv(text,'rxiq_calibration_retained_state_verified') or '?'} ({'PASS' if gates['run_succeeded'] and gates['temporary_state_cleanup_verified'] and gates['retained_state_active'] else 'FAIL'})",
        f"capture window: backend={kv(text,'rxiq_observation_capture_backend') or ('legacy-timeout-wrapper' if is_v60 else '?')} seconds={kv(text,'rxiq_observation_window_seconds') or '?'} started={kv(text,'rxiq_observation_capture_started') or '?'} tcpdump_rc={kv(text,'rxiq_observation_tcpdump_rc') or '?'} ({'PASS' if gates['capture_backend_ready'] else 'FAIL'})",
        f"passive RX: rx_delta={delta} tcpdump_frames={frames} ({'PASS' if gates['receive_packet_growth'] and gates['receive_frames_captured'] else 'FAIL'})",
        f"b43 RX path: irq={irq_delta if irq_delta is not None else '?'} rx_done={done_delta if done_delta is not None else '?'} pio_dispatch={pio_delta if pio_delta is not None else '?'} frame_ready={frame_delta if frame_delta is not None else '?'} data_ready={data_delta if data_delta is not None else '?'} header_ok={header_delta if header_delta is not None else '?'} b43_enter/drop={b43_enter_delta if b43_enter_delta is not None else '?'}/{b43_drop_delta if b43_drop_delta is not None else '?'} mac80211={delivered_delta if delivered_delta is not None else '?'} pio_timeout/error={timeout_delta if timeout_delta is not None else '?'}/{error_delta if error_delta is not None else '?'} len/fcs={lenerr_delta if lenerr_delta is not None else '?'}/{fcserr_delta if fcserr_delta is not None else '?'} ({'PASS' if gates['rxpath_telemetry_present'] else 'FAIL'})",
        f"host IRQ provenance: irq={host_irq if host_irq is not None else '?'} count={host_irq_before if host_irq_before is not None else '?'}->{host_irq_after if host_irq_after is not None else '?'} delta={host_irq_delta if host_irq_delta is not None else '?'} pending_dma/rx_done={int(pending_dma_irq)}/{int(pending_rx_done)} ssb_pci_90/94/98={pci_window_after if pci_window_after is not None else '?'} ({'PASS' if gates['irq_delivery_telemetry_present'] else 'FAIL'})",
        f"Octeon CIU INTx: assigned_ciu_bit={assigned_ciu_bit if assigned_ciu_bit is not None else '?'} assigned_pci_int={assigned_pci_int if assigned_pci_int is not None else '?'} pending={hex(ciu_pending) if ciu_pending is not None else '?'} enabled={hex(ciu_enabled) if ciu_enabled is not None else '?'} sum0={hex(ciu_after['sum0']) if ciu_after else '?'} en0={hex(ciu_after['en0']) if ciu_after else '?'} pci_pin={pci_header_after['interrupt_pin'] if pci_header_after else '?'} intx_disabled={int(bool(pci_header_after and pci_header_after['intx_disabled']))} ({'PASS' if gates['ciu_intx_telemetry_present'] else 'FAIL'})",
        f"association/stations: {kv(text,'rxiq_observation_associated') or '?'} / {kv(text,'rxiq_observation_station_count') or '?'} ({'PASS' if gates['remained_unassociated'] and gates['zero_stations'] else 'FAIL'})",
        f"post-RX verify: write_rc={kv(text,'rxiq_post_rx_verify_write_rc') or '?'} rc={kv(text,'rxiq_post_rx_verify_rc') or '?'} attempted={kv(text,'rxiq_post_rx_verify_attempted') or '?'} verified={kv(text,'rxiq_post_rx_verify_verified') or '?'} MAC={kv(text,'rxiq_post_rx_verify_mac_suspend_verified') or '?'}/{kv(text,'rxiq_post_rx_verify_mac_resume_verified') or '?'} ({'PASS' if gates['post_rx_verify_succeeded'] and gates['post_rx_verify_mac_suspend'] and gates['post_rx_verify_mac_resume'] else 'FAIL'})",
        f"retained IQ after RX: candidate={candidate} live={verified_iq} ({'PASS' if gates['post_rx_iq_stable'] else 'FAIL'})",
        f"retained RCCAL after RX: expected={expected_regs} live={verify_regs} ({'PASS' if gates['post_rx_rccal_stable'] else 'FAIL'})",
        f"safety: scan/probe/assoc/AP/user-TX/injection/persistence/startup-auto blocked ({'PASS' if all(gates[k] for k in ('no_scan','no_probe_requests','no_ssid_requests','no_association_requested','no_ap_requested','no_user_tx_requested','no_frame_injection','no_persistent_write','no_automatic_startup_calibration')) else 'FAIL'})",
        f"finding: {finding}", f"overall: {'PASS' if not problems else 'FAIL'}",
    ]
    if problems: lines.append("failed gates: " + ", ".join(problems))
    rendered = "\n".join(lines) + "\n"
    if json_path: json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")
    if text_path: text_path.write_text(rendered)
    print(rendered, end="")
    return 0 if not problems else 3


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("input", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    args = ap.parse_args()
    text = args.input.read_text(errors="replace")

    if kv(text, "rxiq_calibration_policy") in ("v1.14.60-channel8-operational-retained-calibration-rx-only", "v1.14.61-channel8-operational-retained-calibration-rx-capture-hotfix", "v1.14.62-channel8-operational-retained-calibration-rx-path-telemetry", "v1.14.65-channel8-operational-retained-calibration-irq-delivery-telemetry", "v1.14.66-channel8-operational-retained-calibration-ciu-intx-telemetry", "v1.14.69-channel8-operational-retained-calibration-pci-int0-routing"):
        return analyze_v11460(text, args.input, args.json_path, args.text_path)

    expected = kv(text, "stock_expected_wlan_mac")
    iface_mac = kv(text, "rxiq_calibration_interface_mac")
    saved = None
    restored = None
    saved_csv = kv(text, "rxiq_saved_tuple")
    restored_csv = kv(text, "rxiq_restored_tuple")
    try:
        if saved_csv:
            parts = tuple(int(x) for x in saved_csv.split(","))
            if len(parts) == 4:
                saved = parts
        if restored_csv:
            parts = tuple(int(x) for x in restored_csv.split(","))
            if len(parts) == 4:
                restored = parts
    except ValueError:
        saved = restored = None

    # Failed calibration runs do not reach the normal tuple summary, but the
    # debugfs state always contains the saved tuple and, after fail-closed
    # rollback, the live current tuple. Preserve those as forensic evidence.
    if saved is None:
        saved = tuple_value(text, "saved")
    if restored is None and kv(text, "rxiq_failed_run_restore_verified") == "1":
        restored = tuple_value(text, "current")

    # The debugfs state is printed more than once. The final occurrences of the
    # stored "after" values still represent the coefficients produced by the run.
    after = tuple_value(text, "after")
    current = tuple_value(text, "current")
    changed = bool(saved is not None and after is not None and saved != after)

    delta = intval(kv(text, "rxiq_observation_rx_packets_delta")) or 0
    frames = intval(kv(text, "rxiq_observation_tcpdump_frames")) or 0
    receive_activity = delta > 0 or frames > 0

    channel = intval(kv(text, "rxiq_calibration_channel"))
    frequency = intval(kv(text, "rxiq_calibration_frequency"))
    reported_frequency = intval(kv(text, "rxiq_calibration_reported_frequency"))
    expected_frequency = expected_2g_frequency(channel)
    cleanup_mask = intval(kv(text, "cleanup_fail_mask"))
    cleanup_failures = decode_cleanup_mask(cleanup_mask)
    primary_rc = intval(kv(text, "primary_rc"))
    failure_stage = intval(kv(text, "failure_stage"))
    pass_diag = [pass_forensics(text, 0), pass_forensics(text, 1)]
    final_i_pwr = [intval(kv(text, "core0_final_i_pwr")), intval(kv(text, "core1_final_i_pwr"))]
    final_q_pwr = [intval(kv(text, "core0_final_q_pwr")), intval(kv(text, "core1_final_q_pwr"))]
    final_iq_prod = [intval(kv(text, "core0_final_iq_prod")), intval(kv(text, "core1_final_iq_prod"))]
    calc_error = [intval(kv(text, "core0_calc_error")), intval(kv(text, "core1_calc_error"))]
    calc_error_names = [calc_error_name(v) for v in calc_error]
    calc_applied_mask = intval(kv(text, "calc_applied_mask"))
    radio_spare_low2 = [intval(kv(text, "radio_spare_low2_observed0")), intval(kv(text, "radio_spare_low2_observed1"))]
    calc_forensics_present = all(v is not None for v in final_i_pwr + final_q_pwr + final_iq_prod + calc_error) and calc_applied_mask is not None
    failed_restore_safe = (
        kv(text, "rxiq_failed_run_restore_verified") == "1"
        and kv(text, "rxiq_failed_run_restore_mac_suspend_verified") == "1"
        and kv(text, "rxiq_failed_run_restore_mac_resume_verified") == "1"
        and kv(text, "rxiq_failed_run_restore_coeff_match") == "1"
        and saved is not None
        and restored is not None
        and saved == restored
    )

    no_kernel_error = not bool(
        re.search(
            r"(?:RF sequence status timeout|intc override timeout|b43[^\n]*(?:ERROR:|error:|failed to|failure|RX error|firmware error))",
            text,
            re.I,
        )
    )

    gates = {
        "policy_scope": kv(text, "rxiq_calibration_policy")
        == "v1.14.31-rev4-bcm2056-2g-ch1-11-live-coefficients-only-auto-rollback",
        "country_ca": kv(text, "rxiq_calibration_country") == "CA",
        "channel_2g_allowed": expected_frequency is not None,
        "frequency_matches_channel": bool(expected_frequency is not None and frequency == expected_frequency),
        "setfreq_succeeded": kv(text, "rxiq_calibration_setfreq_rc") == "0",
        "reported_frequency_matches": bool(expected_frequency is not None and reported_frequency == expected_frequency),
        "mtd_identity_pio": (
            kv(text, "b43_macaddr_mtd") == "boot-chain"
            and kv(text, "b43_macaddr_mtd_offset") == "458496"
            and kv(text, "b43_macaddr_increment") == "4"
            and kv(text, "b43_module_pio") == "1"
        ),
        "interface_mac": bool(
            expected
            and iface_mac
            and expected.lower() == iface_mac.lower()
        ),
        "calibration_requested": kv(text, "requested_calibration_sequence") == "1",
        "internal_tone_requested": kv(text, "requested_internal_cal_tone") == "1",
        "no_scan": kv(text, "requested_scan") == "0",
        "no_probe_requests": kv(text, "requested_probe_requests") == "0",
        "no_ssid_requests": kv(text, "requested_ssid_count") == "0",
        "no_association_requested": kv(text, "requested_association") == "0",
        "no_ap_requested": kv(text, "requested_ap") == "0",
        "no_user_tx_requested": kv(text, "requested_user_tx") == "0",
        "no_frame_injection": kv(text, "requested_frame_injection") == "0",
        "no_persistent_write": kv(text, "requested_persistent_write") == "0",
        "run_succeeded": kv(text, "rxiq_calibration_run_rc") == "0",
        "cleanup_forensics_present": cleanup_mask is not None and primary_rc is not None and failure_stage is not None,
        "calc_forensics_present": calc_forensics_present,
        "failed_run_rollback_safe": failed_restore_safe,
        "run_mac_suspend_verified": kv(text, "rxiq_calibration_run_mac_suspend_verified") == "1",
        "run_mac_resume_verified": kv(text, "rxiq_calibration_run_mac_resume_verified") == "1",
        "temporary_state_cleanup_verified": kv(text, "rxiq_calibration_cleanup_complete") == "1",
        "calibrated_coefficients_active_for_observation": kv(text, "rxiq_calibration_active") == "1",
        "remained_unassociated": kv(text, "rxiq_observation_associated") == "0",
        "zero_stations": kv(text, "rxiq_observation_station_count") == "0",
        "restore_succeeded": kv(text, "rxiq_restore_rc") == "0",
        "restore_mac_suspend_verified": kv(text, "rxiq_restore_mac_suspend_verified") == "1",
        "restore_mac_resume_verified": kv(text, "rxiq_restore_mac_resume_verified") == "1",
        "restore_verified": kv(text, "rxiq_restore_verified") == "1",
        "restore_coeff_match": kv(text, "rxiq_restore_coeff_match") == "1",
        "saved_and_restored_tuple_equal": bool(saved is not None and restored is not None and saved == restored),
        "capture_complete": kv(text, "rxiq_calibration_capture_complete") == "1",
        "no_kernel_error": no_kernel_error,
    }
    forensic_only_gates = {"cleanup_forensics_present", "calc_forensics_present", "failed_run_rollback_safe"}
    problems = [k for k, v in gates.items() if not v and k not in forensic_only_gates]

    run_failed = not gates["run_succeeded"]
    forensic_valid = (
        run_failed
        and gates["policy_scope"]
        and gates["country_ca"]
        and gates["channel_2g_allowed"]
        and gates["frequency_matches_channel"]
        and gates["setfreq_succeeded"]
        and gates["reported_frequency_matches"]
        and gates["mtd_identity_pio"]
        and gates["interface_mac"]
        and gates["calibration_requested"]
        and gates["internal_tone_requested"]
        and gates["run_mac_suspend_verified"]
        and gates["run_mac_resume_verified"]
        and gates["cleanup_forensics_present"]
        and gates["failed_run_rollback_safe"]
        and gates["no_kernel_error"]
    )

    calc_failed = any(v not in (None, 0) for v in calc_error)
    if forensic_valid and calc_failed:
        finding = "rxiq-calculation-estimator-failed-rollback-safe"
    elif forensic_valid and cleanup_mask:
        finding = "rxiq-calibration-cleanup-mismatch-rollback-safe"
    elif forensic_valid:
        finding = "rxiq-calibration-operation-failed-rollback-safe"
    elif problems:
        finding = "invalid-capture"
    elif receive_activity:
        finding = "rxiq-calibration-restored-frame-rx"
    elif changed:
        finding = "rxiq-calibration-changed-coefficients-no-frame-rx"
    else:
        finding = "rxiq-calibration-no-coefficient-change"

    data = {
        "schema": "rv220w-b43-rxiq-calibration-v2",
        "input": str(args.input),
        "finding": finding,
        "gates": gates,
        "problems": problems,
        "expected_mac": expected,
        "interface_mac": iface_mac,
        "channel": channel,
        "frequency": frequency,
        "reported_frequency": reported_frequency,
        "saved_coefficients": saved,
        "calibrated_coefficients": after,
        "final_current_coefficients": current,
        "restored_coefficients": restored,
        "coefficients_changed": changed,
        "rx_packets_delta": delta,
        "tcpdump_frames": frames,
        "receive_activity_observed": receive_activity,
        "cleanup_fail_mask": cleanup_mask,
        "cleanup_failures": cleanup_failures,
        "primary_rc": primary_rc,
        "failure_stage": failure_stage,
        "pass_forensics": pass_diag,
        "final_i_pwr": final_i_pwr,
        "final_q_pwr": final_q_pwr,
        "final_iq_prod": final_iq_prod,
        "calc_error": calc_error,
        "calc_error_names": calc_error_names,
        "calc_applied_mask": calc_applied_mask,
        "radio_spare_low2_observed": radio_spare_low2,
        "calc_forensics_present": calc_forensics_present,
        "failed_run_rollback_safe": failed_restore_safe,
        "forensic_valid": forensic_valid,
    }

    lines = [
        "RV220W b43 rev4/BCM2056 RX-IQ calibration experiment analysis",
        f"scope/policy: {'PASS' if gates['policy_scope'] else 'FAIL'}",
        f"country/channel: {kv(text, 'rxiq_calibration_country') or '?'} / ch {channel if channel is not None else '?'} / {frequency if frequency is not None else '?'} MHz ({'PASS' if gates['country_ca'] and gates['channel_2g_allowed'] and gates['frequency_matches_channel'] else 'FAIL'})",
        f"channel tune/readback: rc={kv(text, 'rxiq_calibration_setfreq_rc') or '?'} reported={reported_frequency if reported_frequency is not None else '?'} MHz ({'PASS' if gates['setfreq_succeeded'] and gates['reported_frequency_matches'] else 'FAIL'})",
        f"MTD identity + forced PIO: {'PASS' if gates['mtd_identity_pio'] else 'FAIL'}",
        f"interface MAC: {iface_mac or '?'} expected={expected or '?'} ({'PASS' if gates['interface_mac'] else 'FAIL'})",
        f"calibration run: rc={kv(text, 'rxiq_calibration_run_rc') or '?'} mac_suspend={kv(text, 'rxiq_calibration_run_mac_suspend_verified') or '?'} mac_resume={kv(text, 'rxiq_calibration_run_mac_resume_verified') or '?'} cleanup={kv(text, 'rxiq_calibration_cleanup_complete') or '?'} active={kv(text, 'rxiq_calibration_active') or '?'} ({'PASS' if gates['run_succeeded'] and gates['run_mac_suspend_verified'] and gates['run_mac_resume_verified'] and gates['temporary_state_cleanup_verified'] and gates['calibrated_coefficients_active_for_observation'] else 'FAIL'})",
        f"calibration forensics: primary_rc={primary_rc if primary_rc is not None else '?'} stage={failure_stage if failure_stage is not None else '?'} cleanup_mask={('0x%08x' % cleanup_mask) if cleanup_mask is not None else '?'} failures={cleanup_failures}",
        f"radio spare low2 after cleanup: {radio_spare_low2}",
        f"core0 gain-pass evidence: {pass_diag[0]}",
        f"core1 gain-pass evidence: {pass_diag[1]}",
        f"final CalcRxIqComp estimator: core0=(I={final_i_pwr[0]},Q={final_q_pwr[0]},IQ={final_iq_prod[0]},error={calc_error_names[0]}) core1=(I={final_i_pwr[1]},Q={final_q_pwr[1]},IQ={final_iq_prod[1]},error={calc_error_names[1]}) applied_mask={('0x%x' % calc_applied_mask) if calc_applied_mask is not None else '?'}",
        f"failed-run rollback safe: {failed_restore_safe}",
        f"saved coefficients: {saved}",
        f"calibrated coefficients: {after}",
        f"coefficients changed: {changed}",
        f"post-cal receive: rx_delta={delta} tcpdump_frames={frames} activity={receive_activity}",
        f"post-cal association/stations: {kv(text, 'rxiq_observation_associated') or '?'} / {kv(text, 'rxiq_observation_station_count') or '?'} ({'PASS' if gates['remained_unassociated'] and gates['zero_stations'] else 'FAIL'})",
        f"restore: rc={kv(text, 'rxiq_restore_rc') or '?'} mac_suspend={kv(text, 'rxiq_restore_mac_suspend_verified') or '?'} mac_resume={kv(text, 'rxiq_restore_mac_resume_verified') or '?'} verified={kv(text, 'rxiq_restore_verified') or '?'} coeff_match={kv(text, 'rxiq_restore_coeff_match') or '?'} ({'PASS' if gates['restore_succeeded'] and gates['restore_mac_suspend_verified'] and gates['restore_mac_resume_verified'] and gates['restore_verified'] and gates['restore_coeff_match'] and gates['saved_and_restored_tuple_equal'] else 'FAIL'})",
        f"restored coefficients: {restored}",
        "explicit safety markers: calibration=%s tone=%s scan=%s probe=%s ssids=%s association=%s AP=%s user_tx=%s injection=%s persistent_write=%s"
        % (
            kv(text, "requested_calibration_sequence") or "?",
            kv(text, "requested_internal_cal_tone") or "?",
            kv(text, "requested_scan") or "?",
            kv(text, "requested_probe_requests") or "?",
            kv(text, "requested_ssid_count") or "?",
            kv(text, "requested_association") or "?",
            kv(text, "requested_ap") or "?",
            kv(text, "requested_user_tx") or "?",
            kv(text, "requested_frame_injection") or "?",
            kv(text, "requested_persistent_write") or "?",
        ),
        f"kernel b43/RF-sequence error indication: {'NO' if gates['no_kernel_error'] else 'YES'}",
        f"capture: {'PASS' if not problems else 'FAIL'}",
        f"finding: {finding}",
    ]
    if finding == "rxiq-calculation-estimator-failed-rollback-safe":
        lines.append("Interpretation: the reconstructed gain/tone path reached the final CalcRxIqComp estimator, but its explicit diagnostic checks failed. The per-pass and 16384-sample I/Q values identify whether the calibration stimulus reached the selected RX core; the original coefficient tuple was restored safely.")
    elif finding == "rxiq-calibration-cleanup-mismatch-rollback-safe":
        lines.append("Interpretation: the active reconstruction returned through the fail-closed cleanup path; MAC serialization and coefficient rollback were verified. Radio D6/E2 cleanup now follows stock low-two-bit semantics; any remaining cleanup bits identify true temporary-state restoration failures. The calculated coefficient tuple shown above was snapshotted before rollback.")
    elif finding == "rxiq-calibration-operation-failed-rollback-safe":
        lines.append("Interpretation: the active reconstruction encountered an operation-level failure before successful cleanup, but MAC serialization and coefficient rollback were verified. Use primary_rc/failure_stage to localize the failed calibration operation.")
    elif problems:
        lines.append("failed gates: " + ", ".join(problems))
    elif finding == "rxiq-calibration-restored-frame-rx":
        lines.append("Interpretation: decoded monitor RX appeared only while reconstructed RX-IQ coefficients were active. The missing rev3-6 RX-IQ calibration path is therefore a leading causal blocker; coefficients were nevertheless rolled back by design.")
    elif finding == "rxiq-calibration-changed-coefficients-no-frame-rx":
        lines.append("Interpretation: reconstruction produced different RX-IQ compensation but did not restore frame RX. Keep normal calibration disabled and continue post-ADC/baseband comparison; the original coefficients were restored.")
    elif finding == "rxiq-calibration-no-coefficient-change":
        lines.append("Interpretation: the reconstructed sequence completed and rolled back safely but produced no coefficient change. Recheck stock algorithm/gain stimulus before treating RX-IQ calibration as causal.")

    rendered = "\n".join(lines) + "\n"
    if args.json_path:
        args.json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end="")
    return 3 if run_failed or problems else 0


if __name__ == "__main__":
    raise SystemExit(main())
