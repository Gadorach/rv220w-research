#!/usr/bin/env python3
"""Analyze RV220W BCM4322 channel-8 cfg80211 active-scan/TX qualification evidence."""
from __future__ import annotations
import argparse, json, re
from pathlib import Path

MAC_RE = re.compile(r"(?:[0-9a-f]{2}:){5}[0-9a-f]{2}", re.I)


def first(text: str, key: str):
    m = re.search(rf"^{re.escape(key)}=(.*)$", text, re.M)
    return m.group(1).strip() if m else None


def integer(value, default=None):
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def norm(value):
    return value.lower() if value else value


def ciu_enabled(snapshot: str | None):
    if not snapshot or snapshot == "missing":
        return None
    m = re.search(r"pci_int_enabled=0x([0-9a-f]+)", snapshot, re.I)
    return int(m.group(1), 16) if m else None


def section(text: str, start: str, end: str):
    m = re.search(rf"^{re.escape(start)}\n(.*?)^{re.escape(end)}$", text, re.M | re.S)
    return m.group(1) if m else ""


def tail_section(text: str, start: str):
    m = re.search(rf"^{re.escape(start)}\n(.*)\Z", text, re.M | re.S)
    return m.group(1) if m else ""


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("input", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    args = ap.parse_args()
    text = args.input.read_text(errors="replace")
    evidence_empty = not bool(text.strip())

    transport_rc = integer(first(text, "active_scan_transport_rc"))
    stdout_bytes = integer(first(text, "active_scan_stdout_bytes"))
    stderr_bytes = integer(first(text, "active_scan_stderr_bytes"))
    probe_revision = first(text, "active_scan_probe_revision")
    preflight_started = first(text, "active_scan_preflight_started")
    reg_set_rc = integer(first(text, "active_scan_reg_set_rc"))
    regulatory_verified = first(text, "active_scan_regulatory_verified")
    interface_add_rc = integer(first(text, "active_scan_interface_add_rc"))
    interface_up_rc = integer(first(text, "active_scan_interface_up_rc"))
    interface_ready = first(text, "active_scan_interface_ready")
    scan_started = first(text, "active_scan_scan_started")
    cal_monitor_add_rc = integer(first(text, "active_scan_cal_monitor_add_rc"))
    cal_monitor_up_rc = integer(first(text, "active_scan_cal_monitor_up_rc"))
    cal_setfreq_rc = integer(first(text, "active_scan_cal_setfreq_rc"))
    cal_reported_freq = integer(first(text, "active_scan_cal_reported_frequency"))
    live_cal_started = first(text, "active_scan_live_calibration_started")
    live_cal_write_rc = integer(first(text, "active_scan_live_calibration_write_rc"))
    live_primary_rc = integer(first(text, "active_scan_live_primary_rc"))
    live_cleanup_rc = integer(first(text, "active_scan_live_cleanup_rc"))
    live_cleanup_mask = first(text, "active_scan_live_cleanup_fail_mask")
    live_retained = first(text, "active_scan_live_retained_state_verified")
    live_candidate = first(text, "active_scan_live_candidate_tuple")
    live_verify_write_rc = integer(first(text, "active_scan_live_verify_write_rc"))
    live_verify_rc = integer(first(text, "active_scan_live_verify_rc"))
    live_verify_attempted = first(text, "active_scan_live_verify_attempted")
    live_verify_ok = first(text, "active_scan_live_verify_retained_verified")
    live_verify_generation = integer(first(text, "active_scan_live_verify_generation"))
    live_verify_tuple = first(text, "active_scan_live_verify_iq_tuple")
    live_cal_ready = first(text, "active_scan_live_calibration_ready")
    b43_operating_before = first(text, "active_scan_b43_operating_before_managed")
    b43_operating_after = first(text, "active_scan_b43_operating_after_managed")
    preverify_status = first(text, "active_scan_preverify_b43_status")
    preverify_phy_type = first(text, "active_scan_preverify_phy_type")
    preverify_phy_rev = first(text, "active_scan_preverify_phy_rev")
    preverify_radio_ver = first(text, "active_scan_preverify_radio_ver")
    preverify_radio_rev = first(text, "active_scan_preverify_radio_rev")
    preverify_b43_channel = integer(first(text, "active_scan_preverify_b43_channel"))
    preverify_transfer = first(text, "active_scan_preverify_transfer")
    preverify_fault_point = integer(first(text, "active_scan_preverify_fault_point"))
    preverify_retained_state = first(text, "active_scan_preverify_retained_state_verified")
    preverify_integration = first(text, "active_scan_preverify_integration_complete")
    post_managed_retune_rc = integer(first(text, "active_scan_post_managed_retune_rc"))
    post_managed_monitor_freq = integer(first(text, "active_scan_post_managed_monitor_frequency"))
    post_managed_b43_channel = integer(first(text, "active_scan_post_managed_b43_channel"))
    post_managed_channel_reacquired = first(text, "active_scan_post_managed_channel_reacquired")
    managed_preup_setfreq_rc = integer(first(text, "active_scan_managed_preup_setfreq_rc"))
    managed_preup_monitor_freq = integer(first(text, "active_scan_managed_preup_monitor_frequency"))
    managed_preup_iface_freq = integer(first(text, "active_scan_managed_preup_interface_frequency"))
    managed_preup_b43_channel = integer(first(text, "active_scan_managed_preup_b43_channel"))
    managed_preup_prepared = first(text, "active_scan_managed_preup_channel_prepared")
    post_up_monitor_freq = integer(first(text, "active_scan_post_up_monitor_frequency"))
    post_up_managed_freq = integer(first(text, "active_scan_post_up_managed_frequency"))
    post_up_b43_channel = integer(first(text, "active_scan_post_up_b43_channel"))
    post_up_channel_preserved = first(text, "active_scan_post_up_channel_preserved")
    post_up_verify_preconditions_ready = first(text, "active_scan_post_up_verify_preconditions_ready")
    managed_verify_write_rc = integer(first(text, "active_scan_managed_verify_write_rc"))
    managed_verify_rc = integer(first(text, "active_scan_managed_verify_rc"))
    managed_verify_attempted = first(text, "active_scan_managed_verify_attempted")
    managed_verify_ok = first(text, "active_scan_managed_verify_retained_verified")
    managed_verify_generation = integer(first(text, "active_scan_managed_verify_generation"))
    managed_verify_fresh = first(text, "active_scan_managed_verify_fresh")
    managed_verify_tuple = first(text, "active_scan_managed_verify_iq_tuple")
    managed_retained = first(text, "active_scan_managed_retained_verified")
    handoff_freq = integer(first(text, "active_scan_handoff_frequency"))
    same_lifecycle_handoff = first(text, "active_scan_same_lifecycle_retained_handoff")
    pre_scan_monitor_freq = integer(first(text, "active_scan_pre_scan_monitor_frequency"))
    pre_scan_managed_freq = integer(first(text, "active_scan_pre_scan_managed_frequency"))
    pre_scan_b43_channel = integer(first(text, "active_scan_pre_scan_b43_channel"))
    scan_gate_required_marker = first(text, "active_scan_channel8_retained_gate_required")
    scan_gate_attempt_generation_before = integer(first(text, "active_scan_channel8_gate_attempt_generation_before"))
    scan_gate_arm_write_rc = integer(first(text, "active_scan_channel8_gate_arm_write_rc"))
    scan_gate_armed = first(text, "active_scan_channel8_gate_armed")
    scan_gate_arm_verify_generation = integer(first(text, "active_scan_channel8_gate_arm_verify_generation"))
    scan_gate_attempt_generation_armed = integer(first(text, "active_scan_channel8_gate_attempt_generation_armed"))
    scan_gate_ready = first(text, "active_scan_channel8_gate_ready")
    scan_gate_armed_after = first(text, "active_scan_channel8_gate_armed_after")
    scan_gate_attempt_generation_after = integer(first(text, "active_scan_channel8_gate_attempt_generation_after"))
    scan_gate_attempted = first(text, "active_scan_channel8_gate_attempted")
    scan_gate_verified = first(text, "active_scan_channel8_gate_verified")
    scan_gate_channel = integer(first(text, "active_scan_channel8_gate_channel"))
    scan_gate_rc = integer(first(text, "active_scan_channel8_gate_rc"))
    scan_gate_iq = first(text, "active_scan_channel8_gate_iq_tuple")
    scan_gate_rccal = first(text, "active_scan_channel8_gate_rccal")
    scan_gate_fresh = first(text, "active_scan_channel8_gate_fresh")

    expected = first(text, "stock_expected_wlan_mac")
    iface = first(text, "active_scan_interface_mac")
    country = first(text, "active_scan_country")
    channel = integer(first(text, "active_scan_channel"))
    freq = integer(first(text, "active_scan_frequency"))
    pio = first(text, "b43_module_pio")
    retained = first(text, "active_scan_retained_state_verified")
    preverify = first(text, "active_scan_preverify_retained_verified")
    mode = first(text, "requested_scan_mode")
    probe = first(text, "requested_probe_requests")
    probe_scope = first(text, "requested_probe_scope")
    ssids = first(text, "requested_ssid_count")
    assoc = first(text, "requested_association")
    auth = first(text, "requested_authentication")
    ap_req = first(text, "requested_ap")
    user_tx = first(text, "requested_user_tx")
    user_tx_scope = first(text, "requested_user_tx_scope")
    injection = first(text, "requested_frame_injection")
    persist = first(text, "requested_persistent_write")
    nvm = first(text, "requested_nvm_write")
    nor = first(text, "requested_nor_write")
    scan_rc = integer(first(text, "active_scan_command_rc"))
    tx_before = integer(first(text, "active_scan_txstatus_before"), 0)
    tx_after = integer(first(text, "active_scan_txstatus_after"), 0)
    tx_delta = integer(first(text, "active_scan_txstatus_delta"), 0)
    irq = integer(first(text, "active_scan_host_irq"))
    irq_before = integer(first(text, "active_scan_host_irq_count_before"), 0)
    irq_after = integer(first(text, "active_scan_host_irq_count_after"), 0)
    irq_delta = integer(first(text, "active_scan_host_irq_count_delta"), 0)
    ciu_before_text = first(text, "active_scan_octeon_ciu_before")
    ciu_after_text = first(text, "active_scan_octeon_ciu_after")
    ciu_before = ciu_enabled(ciu_before_text)
    ciu_after = ciu_enabled(ciu_after_text)
    not_connected = first(text, "post_scan_link_not_connected")
    station_count = integer(first(text, "post_scan_station_count"), -1)
    complete = first(text, "active_scan_capture_complete")

    scan = section(text, "=== active scan results ===", "=== post-scan b43 txstatus ===")
    bsses = re.findall(r"^BSS\s+([0-9a-f:]+)", scan, re.M | re.I)
    freqs = [int(float(v)) for v in re.findall(r"^\s*freq:\s*(\d+(?:\.\d+)?)\s*$", scan, re.M)]
    signals = [float(v) for v in re.findall(r"^\s*signal:\s*(-?\d+(?:\.\d+)?)\s+dBm", scan, re.M)]
    seen_ssids = re.findall(r"^\s*SSID:\s*(.*)$", scan, re.M)
    scan_aborted = "scan aborted!" in scan.lower()

    tx_after_section = section(text, "=== post-scan b43 txstatus ===", "=== post-scan link ===")
    tx_rows = re.findall(r"^\d{3}\s*\|.*$", tx_after_section, re.M)
    acked = 0
    for row in tx_rows:
        fields = [f.strip() for f in row.split("|")]
        if fields and fields[-1] == "1":
            acked += 1

    stderr_text = tail_section(text, "=== target active-scan stderr ===").strip()
    stderr_lines = [line.strip() for line in stderr_text.splitlines() if line.strip()]
    target_error = stderr_lines[-1] if stderr_lines else None
    b43_error = bool(re.search(r"b43[^\n]*(?:error|failed|failure|firmware[^\n]*(?:not found|too old|unsupported))", text, re.I))

    # v1.14.72 evidence predates transport metadata. Treat an absent transport rc
    # as unknown, not a failure. v1.14.73+ captures it on every active-scan attempt.
    transport_ok = transport_rc in (None, 0)
    legacy_retained_ok = retained == "1" and preverify == "1"
    same_lifecycle_required = probe_revision in ("v1.14.74", "v1.14.75", "v1.14.76", "v1.14.77", "v1.14.78", "v1.14.79")
    generation_required = probe_revision in ("v1.14.75", "v1.14.76", "v1.14.77", "v1.14.78")
    live_generation_ok = (live_verify_generation is not None and live_verify_generation >= 1) if generation_required else True
    managed_generation_ok = (
        live_verify_generation is not None and managed_verify_generation is not None
        and managed_verify_generation > live_verify_generation and managed_verify_fresh == "1"
    ) if generation_required else True
    channel_reacquire_required = probe_revision == "v1.14.77"
    channel_reacquire_ok = (
        post_managed_retune_rc == 0 and post_managed_monitor_freq == 2447
        and post_managed_b43_channel == 8 and post_managed_channel_reacquired == "1"
    ) if channel_reacquire_required else True
    managed_preup_required = probe_revision == "v1.14.78"
    managed_preup_ok = (
        managed_preup_setfreq_rc == 0 and managed_preup_monitor_freq == 2447
        and managed_preup_b43_channel == 8 and managed_preup_prepared == "1"
    ) if managed_preup_required else True
    post_up_channel_ok = (
        post_up_monitor_freq == 2447 and post_up_b43_channel == 8
        and post_up_channel_preserved == "1" and post_up_verify_preconditions_ready == "1"
    ) if managed_preup_required else True
    managed_channel_ok = channel_reacquire_ok and managed_preup_ok and post_up_channel_ok
    scan_gate_required = probe_revision == "v1.14.79"
    scan_gate_arm_ok = (
        scan_gate_required_marker == "1" and scan_gate_arm_write_rc == 0
        and scan_gate_armed == "1" and scan_gate_ready == "1"
        and live_verify_generation is not None
        and scan_gate_arm_verify_generation == live_verify_generation
        and scan_gate_attempt_generation_before is not None
        and scan_gate_attempt_generation_armed == scan_gate_attempt_generation_before
    ) if scan_gate_required else True
    scan_gate_attempt_fresh = (
        scan_gate_attempt_generation_before is not None
        and scan_gate_attempt_generation_after is not None
        and scan_gate_attempt_generation_after > scan_gate_attempt_generation_before
        and scan_gate_fresh == "1"
    ) if scan_gate_required else True
    scan_gate_ok = (
        scan_gate_arm_ok and scan_gate_attempt_fresh
        and scan_gate_armed_after == "0" and scan_gate_attempted == "1"
        and scan_gate_verified == "1" and scan_gate_channel == 8
        and scan_gate_rc == 0 and bool(scan_gate_iq) and scan_gate_iq == live_candidate
    ) if scan_gate_required else True
    live_transaction_ok = (
        cal_monitor_add_rc == 0 and cal_monitor_up_rc == 0 and cal_setfreq_rc == 0 and cal_reported_freq == 2447
        and live_cal_started == "1" and live_cal_write_rc == 0 and live_primary_rc == 0 and live_cleanup_rc == 0
        and live_cleanup_mask == "0x00000000" and live_retained == "1" and bool(live_candidate)
        and live_verify_write_rc == 0 and live_verify_rc == 0 and live_verify_attempted == "1" and live_verify_ok == "1"
        and live_verify_tuple == live_candidate and live_cal_ready == "1" and live_generation_ok
    )
    managed_handoff_ok = (
        interface_add_rc == 0 and interface_up_rc == 0 and interface_ready == "1"
        and managed_channel_ok
        and managed_verify_rc == 0 and managed_verify_attempted == "1"
        and managed_verify_ok == "1" and managed_verify_tuple == live_candidate
        and managed_generation_ok
        and managed_retained == "1" and handoff_freq == 2447 and same_lifecycle_handoff == "1"
    )
    scan_gate_handoff_ok = (
        interface_add_rc == 0 and interface_up_rc == 0 and interface_ready == "1"
        and b43_operating_after == "1" and scan_gate_ok
    ) if scan_gate_required else True
    same_lifecycle_ok = live_transaction_ok and (scan_gate_handoff_ok if scan_gate_required else managed_handoff_ok)
    gates = {
        "evidence_nonempty": not evidence_empty,
        "host_transport_succeeded": transport_ok,
        "expected_mac_valid": bool(expected and MAC_RE.fullmatch(expected)),
        "interface_mac_matches": bool(expected and iface and norm(expected) == norm(iface)),
        "country_ca_channel8": country == "CA" and channel == 8 and freq == 2447,
        "forced_pio": pio == "1",
        "retained_calibration_verified": same_lifecycle_ok if same_lifecycle_required else legacy_retained_ok,
        "same_lifecycle_retained_handoff": same_lifecycle_ok if same_lifecycle_required else True,
        "channel8_retained_gate": scan_gate_ok if scan_gate_required else True,
        "active_wildcard_probe_requested": mode == "active" and probe == "1" and probe_scope == "wildcard-broadcast-cfg80211-only" and ssids == "0",
        "tx_scope_narrow": user_tx == "1" and user_tx_scope == "cfg80211-active-scan-probe-requests-only" and injection == "0",
        "no_association_auth_ap": assoc == "0" and auth == "0" and ap_req == "0",
        "no_persistent_writes": persist == "0" and nvm == "0" and nor == "0",
        "pci_int0_route_active": irq == 109 and ciu_before is not None and ciu_after is not None and bool(ciu_before & 0x1) and bool(ciu_after & 0x1),
        "scan_command_succeeded": scan_rc == 0 and not scan_aborted,
        "b43_tx_status_advanced": tx_delta is not None and tx_delta > 0 and tx_after > tx_before and len(tx_rows) >= tx_after,
        "received_channel8_bss": bool(bsses) and bool(freqs) and all(f == 2447 for f in freqs),
        "host_irq_active": irq_delta is not None and irq_delta > 0 and irq_after > irq_before,
        "remained_unassociated": not_connected == "1" and station_count == 0,
        "capture_complete": complete == "1",
        "no_b43_error": not b43_error,
    }
    problems = [k for k, v in gates.items() if not v]

    if evidence_empty:
        finding = "active-scan-evidence-empty"
    elif complete != "1":
        if same_lifecycle_required and live_cal_started == "1" and not live_transaction_ok:
            if live_cal_write_rc not in (None, 0) or live_primary_rc not in (None, 0) or live_cleanup_rc not in (None, 0) or (live_cleanup_mask not in (None, "0x00000000")) or live_retained not in (None, "1"):
                finding = "active-scan-live-calibration-failed"
            else:
                finding = "active-scan-live-calibration-verify-failed"
        elif channel_reacquire_required and live_transaction_ok and interface_ready == "1" and not channel_reacquire_ok:
            finding = "active-scan-post-managed-channel-reacquire-failed"
        elif managed_preup_required and live_transaction_ok and interface_add_rc == 0 and not managed_preup_ok:
            finding = "active-scan-managed-preup-channel-pinning-failed"
        elif managed_preup_required and live_transaction_ok and interface_ready == "1" and managed_preup_ok and not post_up_channel_ok:
            finding = "active-scan-managed-up-channel-preservation-failed"
        elif scan_gate_required and live_transaction_ok and interface_ready == "1" and not scan_gate_arm_ok:
            finding = "active-scan-channel8-gate-arm-failed"
        elif generation_required and live_transaction_ok and interface_ready == "1" and not managed_generation_ok:
            finding = "active-scan-managed-verify-not-fresh"
        elif same_lifecycle_required and live_transaction_ok and interface_ready == "1" and not managed_handoff_ok:
            finding = "active-scan-managed-vif-retained-state-lost"
        else:
            finding = "active-scan-target-preflight-failed" if transport_rc not in (None, 0) else "active-scan-capture-incomplete"
    elif scan_gate_required and not scan_gate_attempt_fresh:
        finding = "active-scan-channel8-gate-not-reached"
    elif scan_gate_required and not scan_gate_ok:
        finding = "active-scan-channel8-retained-gate-failed"
    elif scan_rc != 0:
        finding = "active-scan-command-failed"
    elif not gates["b43_tx_status_advanced"]:
        finding = "active-scan-no-b43-tx-status"
    elif not gates["received_channel8_bss"]:
        finding = "active-scan-tx-status-without-bss-results"
    elif not gates["host_irq_active"]:
        finding = "active-scan-tx-status-rx-results-host-irq-anomaly"
    elif not problems:
        finding = "b43-channel8-active-scan-tx-rx-qualified"
    else:
        finding = "active-scan-not-qualified"

    data = {
        "schema": "rv220w-b43-active-scan-analysis-v7",
        "input": str(args.input),
        "finding": finding,
        "gates": gates,
        "problems": problems,
        "transport": {
            "rc": transport_rc,
            "stdout_bytes": stdout_bytes,
            "stderr_bytes": stderr_bytes,
            "probe_revision": probe_revision,
            "preflight_started": preflight_started,
            "reg_set_rc": reg_set_rc,
            "regulatory_verified": regulatory_verified,
            "interface_add_rc": interface_add_rc,
            "interface_up_rc": interface_up_rc,
            "interface_ready": interface_ready,
            "scan_started": scan_started,
            "target_error": target_error,
        },
        "same_lifecycle": {
            "required": same_lifecycle_required,
            "cal_monitor_add_rc": cal_monitor_add_rc,
            "cal_monitor_up_rc": cal_monitor_up_rc,
            "cal_setfreq_rc": cal_setfreq_rc,
            "cal_reported_frequency": cal_reported_freq,
            "live_calibration_started": live_cal_started,
            "live_calibration_write_rc": live_cal_write_rc,
            "live_primary_rc": live_primary_rc,
            "live_cleanup_rc": live_cleanup_rc,
            "live_cleanup_mask": live_cleanup_mask,
            "live_retained": live_retained,
            "live_candidate": live_candidate,
            "live_verify_write_rc": live_verify_write_rc,
            "live_verify_rc": live_verify_rc,
            "live_verify_attempted": live_verify_attempted,
            "live_verify_ok": live_verify_ok,
            "live_verify_generation": live_verify_generation,
            "live_verify_tuple": live_verify_tuple,
            "live_calibration_ready": live_cal_ready,
            "b43_operating_before_managed": b43_operating_before,
            "b43_operating_after_managed": b43_operating_after,
            "preverify_b43_status": preverify_status,
            "preverify_phy_type": preverify_phy_type,
            "preverify_phy_rev": preverify_phy_rev,
            "preverify_radio_ver": preverify_radio_ver,
            "preverify_radio_rev": preverify_radio_rev,
            "preverify_b43_channel": preverify_b43_channel,
            "preverify_transfer": preverify_transfer,
            "preverify_fault_point": preverify_fault_point,
            "preverify_retained_state_verified": preverify_retained_state,
            "preverify_integration_complete": preverify_integration,
            "post_managed_retune_rc": post_managed_retune_rc,
            "post_managed_monitor_frequency": post_managed_monitor_freq,
            "post_managed_b43_channel": post_managed_b43_channel,
            "post_managed_channel_reacquired": post_managed_channel_reacquired,
            "managed_preup_setfreq_rc": managed_preup_setfreq_rc,
            "managed_preup_monitor_frequency": managed_preup_monitor_freq,
            "managed_preup_interface_frequency": managed_preup_iface_freq,
            "managed_preup_b43_channel": managed_preup_b43_channel,
            "managed_preup_channel_prepared": managed_preup_prepared,
            "post_up_monitor_frequency": post_up_monitor_freq,
            "post_up_managed_frequency": post_up_managed_freq,
            "post_up_b43_channel": post_up_b43_channel,
            "post_up_channel_preserved": post_up_channel_preserved,
            "post_up_verify_preconditions_ready": post_up_verify_preconditions_ready,
            "managed_verify_write_rc": managed_verify_write_rc,
            "managed_verify_rc": managed_verify_rc,
            "managed_verify_attempted": managed_verify_attempted,
            "managed_verify_ok": managed_verify_ok,
            "managed_verify_generation": managed_verify_generation,
            "managed_verify_fresh": managed_verify_fresh,
            "managed_verify_tuple": managed_verify_tuple,
            "managed_retained": managed_retained,
            "handoff_frequency": handoff_freq,
            "handoff_marker": same_lifecycle_handoff,
        },
        "channel8_gate": {
            "required": scan_gate_required,
            "pre_scan_monitor_frequency": pre_scan_monitor_freq,
            "pre_scan_managed_frequency": pre_scan_managed_freq,
            "pre_scan_b43_channel": pre_scan_b43_channel,
            "required_marker": scan_gate_required_marker,
            "attempt_generation_before": scan_gate_attempt_generation_before,
            "arm_write_rc": scan_gate_arm_write_rc,
            "armed": scan_gate_armed,
            "arm_verify_generation": scan_gate_arm_verify_generation,
            "attempt_generation_armed": scan_gate_attempt_generation_armed,
            "ready": scan_gate_ready,
            "armed_after": scan_gate_armed_after,
            "attempt_generation_after": scan_gate_attempt_generation_after,
            "attempted": scan_gate_attempted,
            "verified": scan_gate_verified,
            "channel": scan_gate_channel,
            "rc": scan_gate_rc,
            "iq_tuple": scan_gate_iq,
            "rccal": scan_gate_rccal,
            "fresh": scan_gate_fresh,
            "arm_ok": scan_gate_arm_ok,
            "attempt_fresh": scan_gate_attempt_fresh,
            "passed": scan_gate_ok,
        },
        "expected_mac": expected,
        "interface_mac": iface,
        "country": country,
        "channel": channel,
        "frequency": freq,
        "bss_count": len(bsses),
        "bssids": bsses,
        "bss_frequencies": freqs,
        "signals_dbm": signals,
        "ssids": seen_ssids,
        "txstatus_before": tx_before,
        "txstatus_after": tx_after,
        "txstatus_delta": tx_delta,
        "txstatus_rows": len(tx_rows),
        "txstatus_acked_rows": acked,
        "host_irq": irq,
        "host_irq_count_before": irq_before,
        "host_irq_count_after": irq_after,
        "host_irq_count_delta": irq_delta,
        "ciu_enabled_before": ciu_before,
        "ciu_enabled_after": ciu_after,
    }

    lines = [
        "RV220W BCM4322/b43 channel-8 active-scan TX qualification",
        f"transport/evidence: rc={transport_rc if transport_rc is not None else '?'} stdout={stdout_bytes if stdout_bytes is not None else '?'}B stderr={stderr_bytes if stderr_bytes is not None else '?'}B probe={probe_revision or '?'} ({'PASS' if gates['evidence_nonempty'] and gates['host_transport_succeeded'] else 'FAIL'})",
        f"preflight: started={preflight_started or '?'} reg_rc={reg_set_rc if reg_set_rc is not None else '?'} regulatory={regulatory_verified or '?'} ifadd_rc={interface_add_rc if interface_add_rc is not None else '?'} ifup_rc={interface_up_rc if interface_up_rc is not None else '?'} ready={interface_ready or '?'} scan_started={scan_started or '?'}",
        f"same-lifecycle calibration/handoff: calmon={cal_monitor_add_rc if cal_monitor_add_rc is not None else '?'}/{cal_monitor_up_rc if cal_monitor_up_rc is not None else '?'} tune={cal_setfreq_rc if cal_setfreq_rc is not None else '?'}@{cal_reported_freq or '?'} live={live_retained or '?'} verify={live_verify_ok or '?'} gen={live_verify_generation if live_verify_generation is not None else '?'} managed_verify={managed_verify_ok or '?'} gen={managed_verify_generation if managed_verify_generation is not None else '?'} fresh={managed_verify_fresh or '?'} write_rc={managed_verify_write_rc if managed_verify_write_rc is not None else '?'} handoff={same_lifecycle_handoff or '?'}@{handoff_freq or '?'} ({'PASS' if gates['same_lifecycle_retained_handoff'] else 'FAIL'})",
        f"managed channel handoff: legacy_pre_b43={preverify_b43_channel if preverify_b43_channel is not None else '?'} legacy_retune={post_managed_retune_rc if post_managed_retune_rc is not None else '?'} preup_set={managed_preup_setfreq_rc if managed_preup_setfreq_rc is not None else '?'} preup_mon={managed_preup_monitor_freq if managed_preup_monitor_freq is not None else '?'} preup_b43={managed_preup_b43_channel if managed_preup_b43_channel is not None else '?'} postup_mon={post_up_monitor_freq if post_up_monitor_freq is not None else '?'} postup_b43={post_up_b43_channel if post_up_b43_channel is not None else '?'} ({'PASS' if managed_channel_ok else 'FAIL'})",
        f"channel-8 pre-TX gate: prescan_b43={pre_scan_b43_channel if pre_scan_b43_channel is not None else '?'} arm={scan_gate_armed or '?'} arm_gen={scan_gate_arm_verify_generation if scan_gate_arm_verify_generation is not None else '?'} attempt_gen={scan_gate_attempt_generation_before if scan_gate_attempt_generation_before is not None else '?'}->{scan_gate_attempt_generation_after if scan_gate_attempt_generation_after is not None else '?'} fresh={scan_gate_fresh or '?'} attempted={scan_gate_attempted or '?'} verified={scan_gate_verified or '?'} channel={scan_gate_channel if scan_gate_channel is not None else '?'} rc={scan_gate_rc if scan_gate_rc is not None else '?'} iq={scan_gate_iq or '?'} ({'PASS' if scan_gate_ok else 'FAIL'})",
        f"identity/regulatory: MAC={iface or 'missing'} expected={expected or 'missing'} CA/ch{channel or '?'} {freq or '?'} MHz ({'PASS' if gates['interface_mac_matches'] and gates['country_ca_channel8'] else 'FAIL'})",
        f"retained calibration: retained={retained or '?'} preverify={preverify or '?'} pio={pio or '?'} ({'PASS' if gates['retained_calibration_verified'] and gates['forced_pio'] else 'FAIL'})",
        f"TX request: mode={mode or '?'} probe={probe or '?'} scope={user_tx_scope or '?'} arbitrary_injection={injection or '?'} ({'PASS' if gates['active_wildcard_probe_requested'] and gates['tx_scope_narrow'] else 'FAIL'})",
        f"b43 TX status: {tx_before}->{tx_after} delta={tx_delta} parsed_rows={len(tx_rows)} acked_rows={acked} ({'PASS' if gates['b43_tx_status_advanced'] else 'FAIL'})",
        f"PCI/host IRQ: irq={irq if irq is not None else '?'} count={irq_before}->{irq_after} delta={irq_delta} ciu_enabled={ciu_before!r}->{ciu_after!r} ({'PASS' if gates['pci_int0_route_active'] and gates['host_irq_active'] else 'FAIL'})",
        f"scan result: rc={scan_rc if scan_rc is not None else '?'} BSS={len(bsses)} freqs={sorted(set(freqs)) if freqs else []} ({'PASS' if gates['scan_command_succeeded'] and gates['received_channel8_bss'] else 'FAIL'})",
        f"post-scan isolation: not_connected={not_connected or '?'} station_count={station_count} association/auth/AP={assoc or '?'}/{auth or '?'}/{ap_req or '?'} ({'PASS' if gates['remained_unassociated'] and gates['no_association_auth_ap'] else 'FAIL'})",
        f"persistent writes/injection blocked: {'PASS' if gates['no_persistent_writes'] and injection == '0' else 'FAIL'}",
        f"kernel b43 error indication: {'NO' if gates['no_b43_error'] else 'YES'}",
    ]
    if target_error:
        lines.append(f"target error: {target_error}")
    lines += [f"finding: {finding}", f"overall: {'PASS' if not problems else 'FAIL'}"]
    if signals:
        lines.append(f"signal range observed: {min(signals):.1f}..{max(signals):.1f} dBm")
    if seen_ssids:
        unique = []
        for ssid in seen_ssids:
            if ssid not in unique:
                unique.append(ssid)
        lines.append("SSIDs observed: " + ", ".join(unique[:12]))
    if problems:
        lines.append("failed gates: " + ", ".join(problems))
    else:
        lines.append("Next action: cfg80211 probe-request TX plus channel-8 receive is qualified; a separately acknowledged managed-station authentication/association gate can be introduced next.")

    rendered = "\n".join(lines) + "\n"
    if args.json_path:
        args.json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end="")
    return 0 if not problems else 3


if __name__ == "__main__":
    raise SystemExit(main())
