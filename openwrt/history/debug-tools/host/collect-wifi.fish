#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'r/router-ip=' 'o/output-dir=' 'I/otp-init-shadow' 'M/apply-stock-mac' 'R/receiver-init' 'P/passive-scan' 'X/monitor-rx' 'D/nphy-rxdiag' 'Y/rxiq-fault-test' 'S/fault-stage=' 'Q/rxiq-calibration' 'Z/rxiq-active-scan' 'N/normal-start' 'G/managed-assoc' 'L/managed-l3' 'W/managed-internet' 'T/netifd-client' 's/ssid=' 'U/ack-association' 'V/ack-l3' 'E/ack-internet' 'H/ack-netifd' 'b/band=' 'c/country=' 'A/ack-rf' 'K/ack-calibration' 'J/ack-tx' 'C/channel=' -- $argv; or exit 2

set -l label wifi-discovery
if test (count $argv) -ge 1
    set label $argv[1]
end
set label (string replace -ra '[^A-Za-z0-9._-]' '_' -- "$label")

set -l router_ip $RV220W_TFTP_DEVICE_IP
set -q _flag_router_ip; and set router_ip $_flag_router_ip
set -l output_dir "$RV220W_WORKSPACE/logs/wifi"
set -q _flag_output_dir; and set output_dir (realpath -m $_flag_output_dir)

rv_require ssh
mkdir -p "$output_dir"; or rv_die "Could not create output directory: $output_dir"
set -l ssh_options \
    -o BatchMode=yes \
    -o ConnectTimeout=5 \
    -o StrictHostKeyChecking=no \
    -o UserKnownHostsFile=/dev/null \
    -o LogLevel=ERROR
set -l target "root@$router_ip"
set -l remote_script /usr/sbin/rv220w-wifi-snapshot
set -l fallback "$RV220W_TOOLKIT_ROOT/openwrt/files-wifi-discovery/usr/sbin/rv220w-wifi-snapshot"

set -l remote_profile (ssh $ssh_options "$target" "sed -n 's/^profile=//p' /etc/rv220w-build-profile 2>/dev/null")
set -l profile_rc $status
if test $profile_rc -ne 0
    rv_die 'Could not read the target build profile; refusing to collect ambiguous WLAN evidence'
end
contains -- wifi-discovery $remote_profile; or begin
    set -l shown_profile unknown
    if test (count $remote_profile) -gt 0
        set shown_profile (string join ',' -- $remote_profile)
    end
    rv_die "Target profile is '$shown_profile', not 'wifi-discovery'. The RAM WLAN image likely did not remain booted; review the serial log before collecting."
end

set -l probe_helper /usr/sbin/rv220w-wifi-probe
set -l hot_probe_helper /tmp/rv220w-wifi-probe.hot
set -l hot_probe_version_file /tmp/rv220w-wifi-probe.hot.version
set -l toolkit_version (string trim < "$RV220W_TOOLKIT_ROOT/VERSION")
set -l remote_hot_version (ssh $ssh_options "$target" "test -x $hot_probe_helper && cat $hot_probe_version_file 2>/dev/null" 2>/dev/null | string trim)
if test "$remote_hot_version" = "$toolkit_version"
    set probe_helper $hot_probe_helper
    rv_info "Using RAM hot-deployed Wi-Fi probe helper $probe_helper ($remote_hot_version); no initramfs rebuild required."
end
if set -q _flag_apply_stock_mac
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end
    rv_info 'Verifying boot-time stock RV220W WLAN identity (protected platform base MAC + 4); no runtime module mutation or interface/RF start is requested.'
    set -l mac_output (ssh $ssh_options "$target" "$probe_helper apply-stock-mac")
    set -l mac_rc $status
    if test $mac_rc -ne 0
        printf '%s\n' $mac_output >&2
        rv_die "Stock WLAN MAC application failed (target rc=$mac_rc)."
    end
    set -l mac_file "$output_dir/rv220w-wifi-stock-mac-apply-$label.txt"
    printf '%s\n' $mac_output > "$mac_file"
    sha256sum "$mac_file" > "$mac_file.sha256"
    rv_info "Saved stock-MAC application evidence: $mac_file"
end

if set -q _flag_receiver_init
    set -q _flag_country; or rv_die '--receiver-init requires --country CC'
    set -q _flag_ack_rf; or rv_die '--receiver-init requires --ack-rf because it intentionally powers/starts the receiver path'
    if set -q _flag_otp_init_shadow; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_netifd_client
        rv_die '--receiver-init is mutually exclusive with --nphy-rxdiag and --otp-init-shadow'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end
    rv_warn 'Explicit receiver-init requested: one unconfigured managed interface will be started to exercise b43 firmware/receiver initialization, then removed. No scan, SSID, association, AP or userspace Wi-Fi daemon is requested.'
    set -l receiver_file "$output_dir/rv220w-wifi-b43-receiver-init-$label.txt"
    ssh $ssh_options "$target" "$probe_helper receiver-init --country '$_flag_country' --ack-rf" > "$receiver_file.partial.$fish_pid"
    set -l receiver_rc $status
    if test $receiver_rc -ne 0
        test -f "$receiver_file.partial.$fish_pid"; and cat "$receiver_file.partial.$fish_pid" >&2
        command rm -f "$receiver_file.partial.$fish_pid"
        rv_die "Receiver-init target gate failed (rc=$receiver_rc)."
    end
    command mv -f "$receiver_file.partial.$fish_pid" "$receiver_file"; or rv_die 'Could not finalize receiver-init evidence'
    sha256sum "$receiver_file" > "$receiver_file.sha256"
    set -l receiver_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-receiver-init.py"
    test -x "$receiver_analyzer"; or rv_die "Missing receiver-init analyzer: $receiver_analyzer"
    set -l receiver_json "$receiver_file.analysis.json"
    set -l receiver_text "$receiver_file.analysis.txt"
    python3 "$receiver_analyzer" "$receiver_file" --json "$receiver_json" --text "$receiver_text"
    set -l receiver_analysis_rc $status
    if test $receiver_analysis_rc -ne 0
        rv_warn "Receiver-init evidence did not pass all gates; saved $receiver_text and $receiver_json"
    else
        rv_info "Receiver-init gates passed; saved $receiver_text and $receiver_json"
    end
end

if set -q _flag_passive_scan
    set -q _flag_country; or rv_die '--passive-scan requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.20 passive-scan qualification is restricted to --country CA'
    set -q _flag_ack_rf; or rv_die '--passive-scan requires --ack-rf because it intentionally starts the receiver and triggers a scan operation'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_netifd_client
        rv_die '--passive-scan is mutually exclusive with --nphy-rxdiag, --receiver-init and --otp-init-shadow'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end
    rv_warn 'Explicit constrained passive scan requested: 2.4 GHz channels 1-11 only, CA regulatory domain, no SSID attribute/probe request, association, AP or userspace Wi-Fi daemon.'
    set -l scan_file "$output_dir/rv220w-wifi-b43-passive-scan-$label.txt"
    ssh $ssh_options "$target" "$probe_helper passive-scan --country '$_flag_country' --ack-rf" > "$scan_file.partial.$fish_pid"
    set -l scan_rc $status
    if test -f "$scan_file.partial.$fish_pid"
        command mv -f "$scan_file.partial.$fish_pid" "$scan_file"; or rv_die 'Could not finalize passive-scan evidence'
        sha256sum "$scan_file" > "$scan_file.sha256"
    end
    set -l scan_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-passive-scan.py"
    test -x "$scan_analyzer"; or rv_die "Missing passive-scan analyzer: $scan_analyzer"
    set -l scan_json "$scan_file.analysis.json"
    set -l scan_text "$scan_file.analysis.txt"
    if test -f "$scan_file"
        python3 "$scan_analyzer" "$scan_file" --json "$scan_json" --text "$scan_text"
        set -l scan_analysis_rc $status
        if test $scan_analysis_rc -eq 0
            rv_info "2.4 GHz passive-scan gates passed; saved $scan_text and $scan_json"
        else
            rv_warn "Passive-scan evidence did not pass all gates; saved $scan_text and $scan_json"
        end
    end
    if test $scan_rc -ne 0
        test -f "$scan_file"; and cat "$scan_file" >&2
        rv_die "Passive-scan target gate failed (rc=$scan_rc). Evidence was preserved in $scan_file."
    end
end

if set -q _flag_monitor_rx
    set -q _flag_country; or rv_die '--monitor-rx requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.22 monitor-rx is restricted to --country CA'
    set -q _flag_band; or rv_die '--monitor-rx requires --band 2g or --band 5g'
    contains -- "$_flag_band" 2g 5g; or rv_die '--monitor-rx band must be 2g or 5g'
    set -q _flag_ack_rf; or rv_die '--monitor-rx requires --ack-rf because it intentionally starts the receiver and changes channels'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_netifd_client
        rv_die '--monitor-rx is mutually exclusive with --nphy-rxdiag, --passive-scan, --receiver-init and --otp-init-shadow'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end
    if test "$_flag_band" = 2g
        rv_warn 'Explicit receive-only monitor sweep requested: CA 2.4 GHz channels 1-11. No scan request, SSID/probe request, association, AP, frame injection, or userspace Wi-Fi daemon.'
    else
        rv_warn 'Explicit receive-only monitor sweep requested: CA 5 GHz non-DFS channels 36/40/44/48 only. No scan request, SSID/probe request, association, AP, frame injection, or userspace Wi-Fi daemon.'
    end
    set -l monitor_file "$output_dir/rv220w-wifi-b43-monitor-rx-$_flag_band-$label.txt"
    ssh $ssh_options "$target" "$probe_helper monitor-rx --band '$_flag_band' --country '$_flag_country' --ack-rf" > "$monitor_file.partial.$fish_pid"
    set -l monitor_rc $status
    if test -f "$monitor_file.partial.$fish_pid"
        command mv -f "$monitor_file.partial.$fish_pid" "$monitor_file"; or rv_die 'Could not finalize monitor-RX evidence'
        sha256sum "$monitor_file" > "$monitor_file.sha256"
    end
    set -l monitor_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-monitor-rx.py"
    test -x "$monitor_analyzer"; or rv_die "Missing monitor-RX analyzer: $monitor_analyzer"
    set -l monitor_json "$monitor_file.analysis.json"
    set -l monitor_text "$monitor_file.analysis.txt"
    if test -f "$monitor_file"
        python3 "$monitor_analyzer" "$monitor_file" --json "$monitor_json" --text "$monitor_text"
        set -l monitor_analysis_rc $status
        if test $monitor_analysis_rc -eq 0
            rv_info "$_flag_band monitor-RX gates passed; saved $monitor_text and $monitor_json"
        else
            rv_warn "Monitor-RX evidence did not pass all gates; saved $monitor_text and $monitor_json"
        end
    end
    if test $monitor_rc -ne 0
        test -f "$monitor_file"; and cat "$monitor_file" >&2
        rv_die "Monitor-RX target gate failed (rc=$monitor_rc). Evidence was preserved in $monitor_file."
    end
end

if set -q _flag_nphy_rxdiag
    set -q _flag_country; or rv_die '--nphy-rxdiag requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.29 nphy-rxdiag is restricted to --country CA'
    set -q _flag_band; or rv_die '--nphy-rxdiag requires --band 2g or --band 5g'
    contains -- "$_flag_band" 2g 5g; or rv_die '--nphy-rxdiag band must be 2g or 5g'
    set -q _flag_ack_rf; or rv_die '--nphy-rxdiag requires --ack-rf because it starts a receive-only monitor interface, changes channels, and invokes the N-PHY IQ estimator'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_netifd_client
        rv_die '--nphy-rxdiag is mutually exclusive with --monitor-rx, --passive-scan, --receiver-init and --otp-init-shadow'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end
    if test "$_flag_band" = 2g
        rv_warn 'Explicit N-PHY receive-state/IQ diagnostic requested: CA 2.4 GHz channels 1-11. It invokes only the hardware IQ estimator and read-only PHY/radio snapshots; no scan, association, AP, RF override, calibration sequence, frame injection or user TX.'
    else
        rv_warn 'Explicit N-PHY receive-state/IQ diagnostic requested: CA 5 GHz non-DFS channels 36/40/44/48. It invokes only the hardware IQ estimator and read-only PHY/radio snapshots; no scan, association, AP, RF override, calibration sequence, frame injection or user TX.'
    end
    set -l diag_file "$output_dir/rv220w-wifi-b43-nphy-rxdiag-$_flag_band-$label.txt"
    ssh $ssh_options "$target" "$probe_helper nphy-rxdiag --band '$_flag_band' --country '$_flag_country' --ack-rf" > "$diag_file.partial.$fish_pid"
    set -l diag_rc $status
    if test -f "$diag_file.partial.$fish_pid"
        command mv -f "$diag_file.partial.$fish_pid" "$diag_file"; or rv_die 'Could not finalize N-PHY RX diagnostic evidence'
        sha256sum "$diag_file" > "$diag_file.sha256"
    end
    set -l diag_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-nphy-rxdiag.py"
    test -x "$diag_analyzer"; or rv_die "Missing N-PHY RX diagnostic analyzer: $diag_analyzer"
    set -l diag_json "$diag_file.analysis.json"
    set -l diag_text "$diag_file.analysis.txt"
    if test -f "$diag_file"
        python3 "$diag_analyzer" "$diag_file" --json "$diag_json" --text "$diag_text"
        set -l diag_analysis_rc $status
        if test $diag_analysis_rc -eq 0
            rv_info "$_flag_band N-PHY RX diagnostic capture is internally valid; saved $diag_text and $diag_json"
        else
            rv_warn "N-PHY RX diagnostic evidence did not pass state/capture gates; saved $diag_text and $diag_json"
        end
    end
    if test $diag_rc -ne 0
        test -f "$diag_file"; and cat "$diag_file" >&2
        rv_die "N-PHY RX diagnostic target gate failed (rc=$diag_rc). Evidence was preserved in $diag_file."
    end
end



if set -q _flag_rxiq_fault_test
    set -q _flag_country; or rv_die '--rxiq-fault-test requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.59 rxiq-fault-test is restricted to --country CA'
    set -l fault_channel 8
    set -q _flag_channel; and set fault_channel $_flag_channel
    test "$fault_channel" = 8; or rv_die 'v1.14.59 rxiq-fault-test is restricted to --channel 8'
    set -q _flag_fault_stage; or rv_die '--rxiq-fault-test requires --fault-stage carrier|tpc-off|gain-table|core0-phy|core0-radio|core0-gain|core0-iq|core1-phy|core1-radio|core1-gain|core1-iq|rccal-commit|full-transaction|retained-state'
    contains -- "$_flag_fault_stage" carrier tpc-off gain-table core0-phy core0-radio core0-gain core0-iq core1-phy core1-radio core1-gain core1-iq rccal-commit full-transaction retained-state; or rv_die 'invalid --fault-stage for v1.14.59'
    set -q _flag_ack_rf; or rv_die '--rxiq-fault-test requires --ack-rf because it starts the receiver and temporarily mutates calibration PHY/radio state'
    set -q _flag_ack_calibration; or rv_die '--rxiq-fault-test requires --ack-calibration because rollback is being actively exercised'
    if set -q _flag_otp_init_shadow; or set -q _flag_apply_stock_mac; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_calibration; or set -q _flag_netifd_client
        rv_die '--rxiq-fault-test is mutually exclusive with all other WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.59 Wi-Fi probe helper.'
    end
    if test "$_flag_fault_stage" = retained-state
        rv_warn 'This v1.14.59 retained-state qualification runs the hardware-qualified full rev4 transaction to natural success, restores every temporary calibration surface, and deliberately leaves only A0/B0/A1/B1 plus the six RCCAL registers live in RAM. No association/AP/user-data TX or persistent/NVM write is allowed.'
    else if test "$_flag_fault_stage" = full-transaction
        rv_warn 'full-transaction is the hardware-qualified v1.14.58 rollback integration regression gate; use retained-state for the v1.14.59 RAM-only retained calibration qualification.'
    else if test "$_flag_fault_stage" = rccal-commit
        rv_warn 'rccal-commit remains available as the hardware-qualified v1.14.56 regression gate; use full-transaction for the v1.14.59 integration qualification run.'
    else if test "$_flag_fault_stage" = core1-iq
        rv_warn 'core1-iq remains available as a regression gate; v1.14.54 hardware-qualified the combined core1 gain + dedicated IQ path.'
    else if test "$_flag_fault_stage" = core1-gain
        rv_warn 'core1-gain remains available only as a regression gate; use rccal-commit for the v1.14.56 hardware qualification run.'
    else if test "$_flag_fault_stage" = core1-radio
        rv_warn 'This point-9 run repeats the hardware-qualified core0 gain/IQ and core1 PHY setup, then programs only the core1 BCM2056r3 calibration radio mux/LNA state and injects rollback before any core1 gain search, tone/IQ or RCCAL.'
    else if test "$_flag_fault_stage" = core1-phy
        rv_warn 'This point-8 run repeats the hardware-qualified core0 gain + dedicated IQ calculation, restores core0 PHY/radio state, then enters core1 PHY setup and injects rollback before any core1 radio setup, gain search, tone/IQ or RCCAL. Core1 RFSEQCA must read 0x1221.'
    else if test "$_flag_fault_stage" = core0-iq
        rv_warn 'This point-7 run repeats the hardware-qualified core0 gain-search/internal tone, then starts the dedicated corrected RX-IQ tone and explicit 16384-sample coefficient calculation before injected rollback. Core1, RCCAL, association/AP and persistent writes remain blocked.'
    else if test "$_flag_fault_stage" = core0-gain
        rv_warn "Explicit RX-IQ core0 gain-search rollback test requested: CA channel 8. This intentionally repeats the internal calibration tone and rev4 core0 gain search with IQ-estimator and sample-table rollback plus target-scoped corrected I/Q packing, corrected degree phase stepping/direct CORDIC angle use, and waveform telemetry, then injects cancellation before the dedicated IQ-calculation tone/calc step. No scan, association, AP, frame injection, user-data TX, RCCAL or persistent write is requested."
    else
        rv_warn "Explicit pre-tone RX-IQ rollback fault test requested: CA channel 8 / stage $_flag_fault_stage. This mutates and restores calibration PHY/radio state without entering gain search or internal-tone generation."
    end
    set -l fault_file "$output_dir/rv220w-wifi-b43-rxiq-fault-$_flag_fault_stage-$label.txt"
    ssh $ssh_options "$target" "$probe_helper rxiq-fault-test --country CA --channel 8 --stage '$_flag_fault_stage' --ack-rf --ack-calibration" > "$fault_file.partial.$fish_pid"
    set -l fault_rc $status
    if test -f "$fault_file.partial.$fish_pid"
        command mv -f "$fault_file.partial.$fish_pid" "$fault_file"; or rv_die 'Could not finalize RX-IQ fault evidence'
        sha256sum "$fault_file" > "$fault_file.sha256"
    end
    set -l fault_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-rxiq-fault-test.py"
    test -x "$fault_analyzer"; or rv_die "Missing RX-IQ fault analyzer: $fault_analyzer"
    set -l fault_json "$fault_file.analysis.json"
    set -l fault_text "$fault_file.analysis.txt"
    set -l fault_analysis_rc 1
    if test -f "$fault_file"
        python3 "$fault_analyzer" "$fault_file" --json "$fault_json" --text "$fault_text"
        set fault_analysis_rc $status
        if test $fault_analysis_rc -eq 0
            rv_info "RX-IQ staged rollback fault gate passed; saved $fault_text and $fault_json"
        else
            rv_warn "RX-IQ fault evidence failed one or more rollback gates; saved $fault_text and $fault_json"
        end
    end
    if test $fault_rc -ne 0
        test -f "$fault_file"; and cat "$fault_file" >&2
        rv_die "RX-IQ fault target gate failed (rc=$fault_rc). Evidence was preserved in $fault_file."
    end
    if test $fault_analysis_rc -ne 0
        rv_die "RX-IQ fault safety/rollback analysis failed (rc=$fault_analysis_rc). Evidence was preserved in $fault_file."
    end
end


if set -q _flag_normal_start
    set -q _flag_country; or rv_die '--normal-start requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.81 --normal-start is restricted to --country CA'
    set -q _flag_ack_rf; or rv_die '--normal-start requires --ack-rf because it starts normal b43/mac80211 RF operation'
    set -q _flag_ack_calibration; or rv_die '--normal-start requires --ack-calibration because normal PHY init runs the reconstructed RX-IQ/RCCAL calibration automatically'
    set -q _flag_ack_tx; or rv_die '--normal-start requires --ack-tx because the normal cfg80211 scan transmits probe requests'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_rxiq_active_scan; or set -q _flag_netifd_client
        rv_die '--normal-start is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.81 Wi-Fi probe helper.'
    end

    rv_warn 'v1.14.81 native-DMA normal-start requested: identical normal managed lifecycle to the hardware-qualified v1.14.80 PIO run, but the historical b43 pio=1 override is removed. b43 must select its native DMA path for DMA qualification. Automatic RX-IQ/RCCAL invocation is telemetry, not a pre-scan gate. One ordinary cfg80211 active scan covers CA 2.4 GHz channels 1-11. No monitor/debugfs calibration transaction, channel gate, association/authentication/AP/arbitrary injection or persistent write is requested.' 

    set -l normal_file "$output_dir/rv220w-wifi-b43-normal-start-dma-$label.txt"
    set -l normal_partial "$normal_file.partial.$fish_pid"
    set -l normal_stderr "$normal_file.stderr.partial.$fish_pid"
    ssh $ssh_options "$target" "$probe_helper normal-start --country CA --ack-rf --ack-calibration --ack-tx" > "$normal_partial" 2> "$normal_stderr"
    set -l normal_rc $status
    test -f "$normal_partial"; or touch "$normal_partial"
    set -l normal_stdout_bytes (wc -c < "$normal_partial" | string trim)
    set -l normal_stderr_bytes 0
    if test -f "$normal_stderr"
        set normal_stderr_bytes (wc -c < "$normal_stderr" | string trim)
    end
    begin
        echo '=== host normal-start transport ==='
        echo "normal_start_transport_rc=$normal_rc"
        echo "normal_start_stdout_bytes=$normal_stdout_bytes"
        echo "normal_start_stderr_bytes=$normal_stderr_bytes"
        if test -s "$normal_stderr"
            echo '=== target normal-start stderr ==='
            cat "$normal_stderr"
        end
    end >> "$normal_partial"
    command rm -f "$normal_stderr"
    command mv -f "$normal_partial" "$normal_file"; or rv_die 'Could not finalize normal-start evidence'
    sha256sum "$normal_file" > "$normal_file.sha256"
    set -l normal_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-normal-start.py"
    test -x "$normal_analyzer"; or rv_die "Missing normal-start analyzer: $normal_analyzer"
    set -l normal_json "$normal_file.analysis.json"
    set -l normal_text "$normal_file.analysis.txt"
    python3 "$normal_analyzer" "$normal_file" --json "$normal_json" --text "$normal_text"
    set -l normal_analysis_rc $status
    if test $normal_analysis_rc -eq 0
        rv_info "Normal managed-start native-DMA qualification passed; saved $normal_text and $normal_json"
    else
        rv_warn "Normal managed-start native-DMA evidence did not pass all gates; saved $normal_text and $normal_json"
    end
    if test $normal_rc -ne 0
        test -f "$normal_file"; and cat "$normal_file" >&2
        rv_die "Normal-start target path failed (rc=$normal_rc). Evidence was preserved in $normal_file."
    end
    if test $normal_analysis_rc -ne 0
        rv_die "Normal-start qualification analysis failed (rc=$normal_analysis_rc). Evidence was preserved in $normal_file."
    end
end


if set -q _flag_managed_assoc
    set -q _flag_country; or rv_die '--managed-assoc requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.85 --managed-assoc is restricted to --country CA'
    set -q _flag_ssid; or rv_die '--managed-assoc requires --ssid SSID'
    set -q _flag_ack_rf; or rv_die '--managed-assoc requires --ack-rf because it starts normal b43/mac80211 RF operation'
    set -q _flag_ack_calibration; or rv_die '--managed-assoc requires --ack-calibration because normal PHY init may run the reconstructed RX-IQ/RCCAL calibration'
    set -q _flag_ack_tx; or rv_die '--managed-assoc requires --ack-tx because authentication and association transmit management frames'
    set -q _flag_ack_association; or rv_die '--managed-assoc requires --ack-association because it performs WPA-PSK authentication/association'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_rxiq_active_scan; or set -q _flag_normal_start; or set -q _flag_managed_l3; or set -q _flag_managed_internet; or set -q _flag_netifd_client
        rv_die '--managed-assoc is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper && command -v wpa_supplicant >/dev/null 2>&1" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.85 Wi-Fi association helper or wpa_supplicant. Run ./rv220w.fish wifi-hot-deploy first when using an older compatible RAM image.'
    end

    set -l wifi_psk ''
    if set -q RV220W_WIFI_PSK
        set wifi_psk "$RV220W_WIFI_PSK"
    else
        read --silent --prompt-str "WPA-PSK for $_flag_ssid: " wifi_psk
        echo
    end
    set -l psk_len (string length -- "$wifi_psk")
    test $psk_len -ge 8 -a $psk_len -le 63; or begin
        set wifi_psk ''
        rv_die 'WPA-PSK passphrase must be 8..63 characters.'
    end

    rv_warn "v1.14.85 native-DMA managed association requested for SSID '$_flag_ssid'. The credential is sent only on SSH stdin, written only to a mode-600 /tmp supplicant config in the RAM image, never copied into evidence, and deleted during teardown. This test performs WPA-PSK authentication/association only: no DHCP, AP mode, arbitrary injection, UCI network write, NVM write or NOR write."

    set -l assoc_file "$output_dir/rv220w-wifi-b43-managed-assoc-dma-$label.txt"
    set -l assoc_partial "$assoc_file.partial.$fish_pid"
    set -l assoc_stderr "$assoc_file.stderr.partial.$fish_pid"
    printf '%s\n%s\n' "$_flag_ssid" "$wifi_psk" | ssh $ssh_options "$target" "$probe_helper managed-assoc --country CA --ack-rf --ack-calibration --ack-tx --ack-association --credentials-stdin" > "$assoc_partial" 2> "$assoc_stderr"
    set -l assoc_rc $status
    set wifi_psk ''
    test -f "$assoc_partial"; or touch "$assoc_partial"
    set -l assoc_stdout_bytes (wc -c < "$assoc_partial" | string trim)
    set -l assoc_stderr_bytes 0
    if test -f "$assoc_stderr"
        set assoc_stderr_bytes (wc -c < "$assoc_stderr" | string trim)
    end
    begin
        echo '=== host managed-assoc transport ==='
        echo "managed_assoc_transport_rc=$assoc_rc"
        echo "managed_assoc_stdout_bytes=$assoc_stdout_bytes"
        echo "managed_assoc_stderr_bytes=$assoc_stderr_bytes"
        if test -s "$assoc_stderr"
            echo '=== target managed-assoc stderr ==='
            cat "$assoc_stderr"
        end
    end >> "$assoc_partial"
    command rm -f "$assoc_stderr"
    command mv -f "$assoc_partial" "$assoc_file"; or rv_die 'Could not finalize managed-assoc evidence'
    sha256sum "$assoc_file" > "$assoc_file.sha256"
    set -l assoc_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-managed-assoc.py"
    test -x "$assoc_analyzer"; or rv_die "Missing managed-assoc analyzer: $assoc_analyzer"
    set -l assoc_json "$assoc_file.analysis.json"
    set -l assoc_text "$assoc_file.analysis.txt"
    python3 "$assoc_analyzer" "$assoc_file" --json "$assoc_json" --text "$assoc_text"
    set -l assoc_analysis_rc $status
    if test $assoc_analysis_rc -eq 0
        rv_info "Native-DMA WPA-PSK managed association qualified; saved $assoc_text and $assoc_json"
    else
        rv_warn "Managed-assoc evidence did not pass all gates; saved $assoc_text and $assoc_json"
    end
    if test $assoc_rc -ne 0
        test -f "$assoc_file"; and cat "$assoc_file" >&2
        rv_die "Managed-assoc target path failed (rc=$assoc_rc). Evidence was preserved in $assoc_file."
    end
    if test $assoc_analysis_rc -ne 0
        rv_die "Managed-assoc qualification analysis failed (rc=$assoc_analysis_rc). Evidence was preserved in $assoc_file."
    end
end

if set -q _flag_managed_l3
    set -q _flag_country; or rv_die '--managed-l3 requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.87 --managed-l3 is restricted to --country CA'
    set -q _flag_ssid; or rv_die '--managed-l3 requires --ssid SSID'
    set -q _flag_ack_rf; or rv_die '--managed-l3 requires --ack-rf because it starts normal b43/mac80211 RF operation'
    set -q _flag_ack_calibration; or rv_die '--managed-l3 requires --ack-calibration because normal PHY init may run the reconstructed RX-IQ/RCCAL calibration'
    set -q _flag_ack_tx; or rv_die '--managed-l3 requires --ack-tx because WPA and DHCP/ICMP transmit frames'
    set -q _flag_ack_association; or rv_die '--managed-l3 requires --ack-association because it performs WPA-PSK authentication/association'
    set -q _flag_ack_l3; or rv_die '--managed-l3 requires --ack-l3 because it performs DHCP and interface-bound ICMP to the DHCP gateway'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_rxiq_active_scan; or set -q _flag_normal_start; or set -q _flag_managed_assoc; or set -q _flag_managed_internet; or set -q _flag_netifd_client
        rv_die '--managed-l3 is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper && command -v wpa_supplicant >/dev/null 2>&1 && command -v udhcpc >/dev/null 2>&1" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.85 hot Wi-Fi L3 helper, wpa_supplicant, or udhcpc. Run ./rv220w.fish wifi-hot-deploy first; a rebuild should not be necessary on the v1.14.84 image.'
    end

    set -l wifi_psk ''
    if set -q RV220W_WIFI_PSK
        set wifi_psk "$RV220W_WIFI_PSK"
    else
        read --silent --prompt-str "WPA-PSK for $_flag_ssid: " wifi_psk
        echo
    end
    set -l psk_len (string length -- "$wifi_psk")
    test $psk_len -ge 8 -a $psk_len -le 63; or begin
        set wifi_psk ''
        rv_die 'WPA-PSK passphrase must be 8..63 characters.'
    end

    rv_warn "v1.14.87 native-DMA managed L3 qualification requested for SSID '$_flag_ssid'. This reuses the qualified WPA association, obtains one DHCP lease, assigns only the leased address/prefix, and sends three interface-bound ICMP echoes to the first DHCP router. It deliberately installs no default route, performs no DNS/Internet test, and writes no UCI/NVM/NOR state."

    set -l l3_file "$output_dir/rv220w-wifi-b43-managed-l3-dma-$label.txt"
    set -l l3_partial "$l3_file.partial.$fish_pid"
    set -l l3_stderr "$l3_file.stderr.partial.$fish_pid"
    printf '%s\n%s\n' "$_flag_ssid" "$wifi_psk" | ssh $ssh_options "$target" "$probe_helper managed-l3 --country CA --ack-rf --ack-calibration --ack-tx --ack-association --ack-l3 --credentials-stdin" > "$l3_partial" 2> "$l3_stderr"
    set -l l3_rc $status
    set wifi_psk ''
    test -f "$l3_partial"; or touch "$l3_partial"
    set -l l3_stdout_bytes (wc -c < "$l3_partial" | string trim)
    set -l l3_stderr_bytes 0
    if test -f "$l3_stderr"
        set l3_stderr_bytes (wc -c < "$l3_stderr" | string trim)
    end
    begin
        echo '=== host managed-l3 transport ==='
        echo "managed_l3_transport_rc=$l3_rc"
        echo "managed_l3_stdout_bytes=$l3_stdout_bytes"
        echo "managed_l3_stderr_bytes=$l3_stderr_bytes"
        if test -s "$l3_stderr"
            echo '=== target managed-l3 stderr ==='
            cat "$l3_stderr"
        end
    end >> "$l3_partial"
    command rm -f "$l3_stderr"
    command mv -f "$l3_partial" "$l3_file"; or rv_die 'Could not finalize managed-l3 evidence'
    sha256sum "$l3_file" > "$l3_file.sha256"
    set -l l3_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-managed-l3.py"
    test -x "$l3_analyzer"; or rv_die "Missing managed-l3 analyzer: $l3_analyzer"
    set -l l3_json "$l3_file.analysis.json"
    set -l l3_text "$l3_file.analysis.txt"
    python3 "$l3_analyzer" "$l3_file" --json "$l3_json" --text "$l3_text"
    set -l l3_analysis_rc $status
    if test $l3_analysis_rc -eq 0
        rv_info "Native-DMA WPA-PSK DHCP/gateway L3 qualification passed; saved $l3_text and $l3_json"
    else
        rv_warn "Managed-L3 evidence did not pass all gates; saved $l3_text and $l3_json"
    end
    if test $l3_rc -ne 0
        test -f "$l3_file"; and cat "$l3_file" >&2
        rv_die "Managed-L3 target path failed (rc=$l3_rc). Evidence was preserved in $l3_file."
    end
    if test $l3_analysis_rc -ne 0
        rv_die "Managed-L3 qualification analysis failed (rc=$l3_analysis_rc). Evidence was preserved in $l3_file."
    end
end


if set -q _flag_managed_internet
    set -q _flag_country; or rv_die '--managed-internet requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.87 --managed-internet is restricted to --country CA'
    set -q _flag_ssid; or rv_die '--managed-internet requires --ssid SSID'
    set -q _flag_ack_rf; or rv_die '--managed-internet requires --ack-rf because it starts normal b43/mac80211 RF operation'
    set -q _flag_ack_calibration; or rv_die '--managed-internet requires --ack-calibration because normal PHY init may run the reconstructed RX-IQ/RCCAL calibration'
    set -q _flag_ack_tx; or rv_die '--managed-internet requires --ack-tx because WPA, DHCP, DNS and ICMP transmit frames'
    set -q _flag_ack_association; or rv_die '--managed-internet requires --ack-association because it performs WPA-PSK authentication/association'
    set -q _flag_ack_l3; or rv_die '--managed-internet requires --ack-l3 because it obtains and uses a DHCP lease'
    set -q _flag_ack_internet; or rv_die '--managed-internet requires --ack-internet because it sends public ICMP and a DNS query'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_rxiq_active_scan; or set -q _flag_normal_start; or set -q _flag_managed_assoc; or set -q _flag_managed_l3; or set -q _flag_netifd_client
        rv_die '--managed-internet is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper && command -v wpa_supplicant >/dev/null 2>&1 && command -v nslookup >/dev/null 2>&1" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.87 hot-deployed Internet/DNS helper, wpa_supplicant, or nslookup. Run ./rv220w.fish wifi-hot-deploy first.'
    end

    set -l wifi_psk ''
    if set -q RV220W_WIFI_PSK
        set wifi_psk "$RV220W_WIFI_PSK"
    else
        read --silent --prompt-str "WPA-PSK for $_flag_ssid: " wifi_psk
        echo
    end
    set -l psk_len (string length -- "$wifi_psk")
    test $psk_len -ge 8 -a $psk_len -le 63; or begin
        set wifi_psk ''
        rv_die 'WPA-PSK passphrase must be 8..63 characters.'
    end

    rv_warn "v1.14.87 Internet/DNS qualification requested for SSID '$_flag_ssid'. This reuses the qualified native-DMA WPA/DHCP path, adds exactly one temporary /32 route for 1.1.1.1 through the WLAN gateway, sends three interface-bound ICMP probes, and queries openwrt.org through the DHCP-provided DNS server. It never installs/replaces a default route and removes the host route, DHCP state, credentials, supplicant and interface during teardown."

    set -l internet_file "$output_dir/rv220w-wifi-b43-managed-internet-dma-$label.txt"
    set -l internet_partial "$internet_file.partial.$fish_pid"
    set -l internet_stderr "$internet_file.stderr.partial.$fish_pid"
    printf '%s\n%s\n' "$_flag_ssid" "$wifi_psk" | ssh $ssh_options "$target" "$probe_helper managed-internet --country CA --ack-rf --ack-calibration --ack-tx --ack-association --ack-l3 --ack-internet --credentials-stdin" > "$internet_partial" 2> "$internet_stderr"
    set -l internet_rc $status
    set wifi_psk ''
    test -f "$internet_partial"; or touch "$internet_partial"
    set -l internet_stdout_bytes (wc -c < "$internet_partial" | string trim)
    set -l internet_stderr_bytes 0
    if test -f "$internet_stderr"
        set internet_stderr_bytes (wc -c < "$internet_stderr" | string trim)
    end
    begin
        echo '=== host managed-internet transport ==='
        echo "managed_l3_transport_rc=$internet_rc"
        echo "managed_l3_stdout_bytes=$internet_stdout_bytes"
        echo "managed_l3_stderr_bytes=$internet_stderr_bytes"
        if test -s "$internet_stderr"
            echo '=== target managed-internet stderr ==='
            cat "$internet_stderr"
        end
    end >> "$internet_partial"
    command rm -f "$internet_stderr"
    command mv -f "$internet_partial" "$internet_file"; or rv_die 'Could not finalize managed-internet evidence'
    sha256sum "$internet_file" > "$internet_file.sha256"
    set -l internet_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-managed-internet.py"
    test -x "$internet_analyzer"; or rv_die "Missing managed-internet analyzer: $internet_analyzer"
    set -l internet_json "$internet_file.analysis.json"
    set -l internet_text "$internet_file.analysis.txt"
    python3 "$internet_analyzer" "$internet_file" --json "$internet_json" --text "$internet_text"
    set -l internet_analysis_rc $status
    if test $internet_analysis_rc -eq 0
        rv_info "Native-DMA DHCP + public ICMP + DNS qualification passed; saved $internet_text and $internet_json"
    else
        rv_warn "Managed-Internet evidence did not pass all gates; saved $internet_text and $internet_json"
    end
    if test $internet_rc -ne 0
        test -f "$internet_file"; and cat "$internet_file" >&2
        rv_die "Managed-Internet target path failed (rc=$internet_rc). Evidence was preserved in $internet_file."
    end
    if test $internet_analysis_rc -ne 0
        rv_die "Managed-Internet qualification analysis failed (rc=$internet_analysis_rc). Evidence was preserved in $internet_file."
    end
end


if set -q _flag_netifd_client
    set -q _flag_country; or rv_die '--netifd-client requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.88 --netifd-client is restricted to --country CA'
    set -q _flag_ssid; or rv_die '--netifd-client requires --ssid SSID'
    set -q _flag_ack_rf; or rv_die '--netifd-client requires --ack-rf'
    set -q _flag_ack_calibration; or rv_die '--netifd-client requires --ack-calibration'
    set -q _flag_ack_tx; or rv_die '--netifd-client requires --ack-tx'
    set -q _flag_ack_association; or rv_die '--netifd-client requires --ack-association'
    set -q _flag_ack_l3; or rv_die '--netifd-client requires --ack-l3 because netifd obtains a DHCP lease'
    set -q _flag_ack_netifd; or rv_die '--netifd-client requires --ack-netifd because it temporarily commits RAM-only UCI wireless/network configuration'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_rxiq_active_scan; or set -q _flag_normal_start; or set -q _flag_managed_assoc; or set -q _flag_managed_l3; or set -q _flag_managed_internet
        rv_die '--netifd-client is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper && command -v uci >/dev/null 2>&1 && command -v ubus >/dev/null 2>&1 && command -v wifi >/dev/null 2>&1 && command -v ifstatus >/dev/null 2>&1 && command -v wpa_supplicant >/dev/null 2>&1" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.88 hot-deployed netifd helper or required OpenWrt client commands. Run ./rv220w.fish wifi-hot-deploy first.'
    end

    set -l wifi_psk ''
    if set -q RV220W_WIFI_PSK
        set wifi_psk "$RV220W_WIFI_PSK"
    else
        read --silent --prompt-str "WPA-PSK for $_flag_ssid: " wifi_psk
        echo
    end
    set -l psk_len (string length -- "$wifi_psk")
    test $psk_len -ge 8 -a $psk_len -le 63; or begin
        set wifi_psk ''
        rv_die 'WPA-PSK passphrase must be 8..63 characters.'
    end

    rv_warn "v1.14.88 OpenWrt netifd/UCI client integration requested for SSID '$_flag_ssid'. The target must be the RAM-only wifi-discovery image; it refuses MTD-backed root/overlay mounts. Temporary UCI wireless/network files are restored byte-for-byte after the test. netifd owns WPA and DHCP; defaultroute=0 and peerdns=0 preserve the wired management path."

    set -l nf_file "$output_dir/rv220w-wifi-b43-netifd-client-dma-$label.txt"
    set -l nf_partial "$nf_file.partial.$fish_pid"
    set -l nf_stderr "$nf_file.stderr.partial.$fish_pid"
    printf '%s\n%s\n' "$_flag_ssid" "$wifi_psk" | ssh $ssh_options "$target" "$probe_helper netifd-client --country CA --ack-rf --ack-calibration --ack-tx --ack-association --ack-l3 --ack-netifd --credentials-stdin" > "$nf_partial" 2> "$nf_stderr"
    set -l nf_rc $status
    set wifi_psk ''
    test -f "$nf_partial"; or touch "$nf_partial"
    set -l nf_stdout_bytes (wc -c < "$nf_partial" | string trim)
    set -l nf_stderr_bytes 0
    if test -f "$nf_stderr"
        set nf_stderr_bytes (wc -c < "$nf_stderr" | string trim)
    end
    begin
        echo '=== host netifd-client transport ==='
        echo "netifd_client_transport_rc=$nf_rc"
        echo "netifd_client_stdout_bytes=$nf_stdout_bytes"
        echo "netifd_client_stderr_bytes=$nf_stderr_bytes"
        if test -s "$nf_stderr"
            echo '=== target netifd-client stderr ==='
            cat "$nf_stderr"
        end
    end >> "$nf_partial"
    command rm -f "$nf_stderr"
    command mv -f "$nf_partial" "$nf_file"; or rv_die 'Could not finalize netifd-client evidence'
    sha256sum "$nf_file" > "$nf_file.sha256"
    set -l nf_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-netifd-client.py"
    test -x "$nf_analyzer"; or rv_die "Missing netifd-client analyzer: $nf_analyzer"
    set -l nf_json "$nf_file.analysis.json"
    set -l nf_text "$nf_file.analysis.txt"
    python3 "$nf_analyzer" "$nf_file" --json "$nf_json" --text "$nf_text"
    set -l nf_analysis_rc $status
    if test $nf_analysis_rc -eq 0
        rv_info "OpenWrt netifd/UCI native-DMA station integration qualified; saved $nf_text and $nf_json"
    else
        rv_warn "netifd-client evidence did not pass all gates; saved $nf_text and $nf_json"
    end
    if test $nf_rc -ne 0
        test -f "$nf_file"; and cat "$nf_file" >&2
        rv_die "netifd-client target path failed (rc=$nf_rc). Evidence was preserved in $nf_file."
    end
    if test $nf_analysis_rc -ne 0
        rv_die "netifd-client qualification analysis failed (rc=$nf_analysis_rc). Evidence was preserved in $nf_file."
    end
end

if set -q _flag_rxiq_active_scan
    set -q _flag_country; or rv_die '--rxiq-active-scan requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.70 --rxiq-active-scan is restricted to --country CA'
    set -l tx_channel 8
    set -q _flag_channel; and set tx_channel $_flag_channel
    test "$tx_channel" = 8; or rv_die 'v1.14.70 --rxiq-active-scan requires --channel 8'
    set -q _flag_ack_rf; or rv_die '--rxiq-active-scan requires --ack-rf because it starts the receiver and performs retained calibration'
    set -q _flag_ack_calibration; or rv_die '--rxiq-active-scan requires --ack-calibration because it first establishes verified retained RX-IQ/RCCAL state'
    set -q _flag_ack_tx; or rv_die '--rxiq-active-scan requires --ack-tx because cfg80211 will transmit wildcard probe requests on channel 8'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_fault_test; or set -q _flag_rxiq_calibration; or set -q _flag_netifd_client
        rv_die '--rxiq-active-scan is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end

    rv_warn 'v1.14.74 controlled TX qualification requested: first repeat the hardware-qualified retained calibration + passive RX gate on CA channel 8. Only after that host-side PASS, the active target establishes a fresh same-lifecycle retained calibration on a held virtual monitor, re-verifies it after adding one managed vif, then performs exactly one cfg80211 wildcard active scan on 2447 MHz. Probe-request TX is explicitly acknowledged; association, authentication, AP mode, arbitrary frame injection, user data and persistent writes remain blocked.'

    set -l cal_file "$output_dir/rv220w-wifi-b43-rxiq-calibration-pre-active-scan-$label.txt"
    ssh $ssh_options "$target" "$probe_helper rxiq-calibration --country CA --channel 8 --ack-rf --ack-calibration" > "$cal_file.partial.$fish_pid"
    set -l cal_rc $status
    if test -f "$cal_file.partial.$fish_pid"
        command mv -f "$cal_file.partial.$fish_pid" "$cal_file"; or rv_die 'Could not finalize pre-active-scan RX-IQ calibration evidence'
        sha256sum "$cal_file" > "$cal_file.sha256"
    end
    set -l cal_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-rxiq-calibration.py"
    test -x "$cal_analyzer"; or rv_die "Missing RX-IQ calibration analyzer: $cal_analyzer"
    set -l cal_json "$cal_file.analysis.json"
    set -l cal_text "$cal_file.analysis.txt"
    set -l cal_analysis_rc 3
    if test -f "$cal_file"
        python3 "$cal_analyzer" "$cal_file" --json "$cal_json" --text "$cal_text"
        set cal_analysis_rc $status
    end
    if test $cal_rc -ne 0; or test $cal_analysis_rc -ne 0
        test -f "$cal_file"; and cat "$cal_file" >&2
        rv_die "Pre-active-scan retained calibration/RX qualification failed (target=$cal_rc analysis=$cal_analysis_rc). Active TX scan was not attempted."
    end
    rv_info "Pre-active-scan retained calibration/RX qualification passed; saved $cal_text and $cal_json"

    set -l active_file "$output_dir/rv220w-wifi-b43-active-scan-ch8-$label.txt"
    set -l active_partial "$active_file.partial.$fish_pid"
    set -l active_stderr "$active_file.stderr.partial.$fish_pid"
    ssh $ssh_options "$target" "$probe_helper active-scan-ch8 --country CA --channel 8 --ack-rf --ack-tx" > "$active_partial" 2> "$active_stderr"
    set -l active_rc $status
    test -f "$active_partial"; or touch "$active_partial"
    set -l active_stdout_bytes (wc -c < "$active_partial" | string trim)
    set -l active_stderr_bytes 0
    if test -f "$active_stderr"
        set active_stderr_bytes (wc -c < "$active_stderr" | string trim)
    end
    begin
        echo '=== host active-scan transport ==='
        echo "active_scan_transport_rc=$active_rc"
        echo "active_scan_stdout_bytes=$active_stdout_bytes"
        echo "active_scan_stderr_bytes=$active_stderr_bytes"
        if test -s "$active_stderr"
            echo '=== target active-scan stderr ==='
            cat "$active_stderr"
        end
    end >> "$active_partial"
    command rm -f "$active_stderr"
    command mv -f "$active_partial" "$active_file"; or rv_die 'Could not finalize active-scan evidence'
    sha256sum "$active_file" > "$active_file.sha256"
    set -l active_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-active-scan.py"
    test -x "$active_analyzer"; or rv_die "Missing active-scan analyzer: $active_analyzer"
    set -l active_json "$active_file.analysis.json"
    set -l active_text "$active_file.analysis.txt"
    set -l active_analysis_rc 3
    if test -f "$active_file"
        python3 "$active_analyzer" "$active_file" --json "$active_json" --text "$active_text"
        set active_analysis_rc $status
        if test $active_analysis_rc -eq 0
            rv_info "Channel-8 active-scan TX/RX qualification passed; saved $active_text and $active_json"
        else
            rv_warn "Channel-8 active-scan evidence failed one or more TX/RX gates; saved $active_text and $active_json"
        end
    end
    if test $active_rc -ne 0
        test -f "$active_file"; and cat "$active_file" >&2
        rv_die "Active-scan target gate failed (rc=$active_rc). Evidence was preserved in $active_file."
    end
    if test $active_analysis_rc -ne 0
        rv_die "Active-scan TX/RX analysis failed (rc=$active_analysis_rc). Evidence was preserved in $active_file."
    end
end

if set -q _flag_rxiq_calibration
    # Historical regression compatibility marker: v1.14.66 RX-path localization requested.
    set -q _flag_country; or rv_die '--rxiq-calibration requires --country CA'
    test "$_flag_country" = CA; or rv_die 'v1.14.62 rxiq-calibration is restricted to --country CA'
    set -l cal_channel 8
    set -q _flag_channel; and set cal_channel $_flag_channel
    test "$cal_channel" = 8; or rv_die 'v1.14.62 operational --rxiq-calibration requires --channel 8'
    set -q _flag_ack_rf; or rv_die '--rxiq-calibration requires --ack-rf because it starts the receiver and an internal calibration tone'
    set -q _flag_ack_calibration; or rv_die '--rxiq-calibration requires --ack-calibration because it temporarily changes live RX-IQ compensation and calibration RF/PHY state'
    if set -q _flag_otp_init_shadow; or set -q _flag_receiver_init; or set -q _flag_passive_scan; or set -q _flag_monitor_rx; or set -q _flag_nphy_rxdiag; or set -q _flag_rxiq_active_scan; or set -q _flag_netifd_client
        rv_die '--rxiq-calibration is mutually exclusive with all other active WLAN collection gates'
    end
    if not ssh $ssh_options "$target" "test -x $probe_helper" >/dev/null 2>&1
        rv_die 'Target lacks the v1.14.70 Wi-Fi probe helper.'
    end
    set -l cal_freq (math "2407 + $cal_channel * 5")
    rv_warn "v1.14.70 retained-calibration/passive-RX qualification requested: the v1.14.69 PCI INT0 correction is hardware-qualified on IRQ109/CIU36; repeat the same read-only host IRQ/CIU, b43 IRQ/DMA0/PIO/mac80211 and retained-state verification path. No scan/probe request, association, AP, injection, user-data TX or persistence. No scan/probe request, association, AP, injection, user-data TX or persistence."
    set -l cal_file "$output_dir/rv220w-wifi-b43-rxiq-calibration-$label.txt"
    ssh $ssh_options "$target" "$probe_helper rxiq-calibration --country '$_flag_country' --channel '$cal_channel' --ack-rf --ack-calibration" > "$cal_file.partial.$fish_pid"
    set -l cal_rc $status
    if test -f "$cal_file.partial.$fish_pid"
        command mv -f "$cal_file.partial.$fish_pid" "$cal_file"; or rv_die 'Could not finalize RX-IQ calibration evidence'
        sha256sum "$cal_file" > "$cal_file.sha256"
    end
    set -l cal_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-b43-rxiq-calibration.py"
    test -x "$cal_analyzer"; or rv_die "Missing RX-IQ calibration analyzer: $cal_analyzer"
    set -l cal_json "$cal_file.analysis.json"
    set -l cal_text "$cal_file.analysis.txt"
    set -l cal_analysis_rc 3
    if test -f "$cal_file"
        python3 "$cal_analyzer" "$cal_file" --json "$cal_json" --text "$cal_text"
        set cal_analysis_rc $status
        if test $cal_analysis_rc -eq 0
            rv_info "RX-IQ calibration experiment capture is internally valid; saved $cal_text and $cal_json"
        else
            rv_warn "RX-IQ calibration evidence failed one or more safety/capture gates; saved $cal_text and $cal_json"
        end
    end
    if test $cal_rc -ne 0
        test -f "$cal_file"; and cat "$cal_file" >&2
        rv_die "RX-IQ calibration target gate failed (rc=$cal_rc). Evidence was preserved in $cal_file."
    end
    if test $cal_analysis_rc -ne 0
        rv_die "RX-IQ calibration safety/capture analysis failed (rc=$cal_analysis_rc). Evidence was preserved in $cal_file."
    end
end

# Explicit second-stage BCM4322 OTP shadow initialization.  Normal collection
# never enters this path.  The target helper and kernel module independently
# require chipstatus to select OTP before accepting Broadcom's INIT opcode.
if set -q _flag_otp_init_shadow
    set -l init_helper /usr/sbin/ssb-nvmem-init-shadow
    if not ssh $ssh_options "$target" "test -x $init_helper" >/dev/null 2>&1
        rv_die 'Target lacks the current OTP INIT helper. Rebuild/boot the current wifi-discovery image before using --otp-init-shadow.'
    end

    rv_warn 'Explicit OTP shadow INIT requested. This is not passive capture: it issues Broadcom OTP opcode INIT only after BCM4322 chipstatus selects OTP. No programming/SET/RESET/lock opcode is exposed.'
    set -l init_output (ssh $ssh_options "$target" "$init_helper")
    set -l init_rc $status
    if test $init_rc -ne 0
        if test (count $init_output) -gt 0
            printf '%s\n' $init_output >&2
        end
        rv_die "OTP shadow INIT helper refused or failed (target rc=$init_rc). No RF action was attempted."
    end

    set -l pre_info_path (printf '%s\n' $init_output | sed -n 's/^otp_init_pre_info_copy=//p' | tail -n 1)
    set -l pre_raw_path (printf '%s\n' $init_output | sed -n 's/^otp_init_pre_raw_copy=//p' | tail -n 1)
    set -l post_info_path (printf '%s\n' $init_output | sed -n 's/^otp_init_post_info_copy=//p' | tail -n 1)
    set -l post_raw_path (printf '%s\n' $init_output | sed -n 's/^otp_init_post_raw_copy=//p' | tail -n 1)
    set -l init_sprom_path (printf '%s\n' $init_output | sed -n 's/^sprom_physical_copy=//p' | tail -n 1)

    for required_path in "$pre_info_path" "$pre_raw_path" "$post_info_path" "$post_raw_path"
        string match -qr '^/tmp/ssb-nvmem-init-[A-Za-z0-9._-]+\.(pre|post)\.otp-(info\.txt|raw\.hex)$' -- "$required_path"; or rv_die "Unexpected OTP INIT evidence path: $required_path"
    end

    set -l local_pre_info "$output_dir/"(basename "$pre_info_path")
    set -l local_pre_raw "$output_dir/"(basename "$pre_raw_path")
    set -l local_post_info "$output_dir/"(basename "$post_info_path")
    set -l local_post_raw "$output_dir/"(basename "$post_raw_path")

    for pair in \
        "$pre_info_path|$local_pre_info" \
        "$pre_raw_path|$local_pre_raw" \
        "$post_info_path|$local_post_info" \
        "$post_raw_path|$local_post_raw"
        set -l parts (string split -m 1 '|' -- "$pair")
        set -l remote_path $parts[1]
        set -l local_path $parts[2]
        set -l part "$local_path.partial.$fish_pid"
        ssh $ssh_options "$target" "cat '$remote_path'" > "$part"; or begin
            command rm -f "$part"
            rv_die "Could not retrieve OTP INIT evidence: $remote_path"
        end
        command mv -f "$part" "$local_path"; or rv_die "Could not finalize OTP INIT evidence: $local_path"
        sha256sum "$local_path" > "$local_path.sha256"
    end

    set -l local_init_sprom ''
    if string match -qr '^/tmp/ssb-nvmem-init-[A-Za-z0-9._-]+\.sprom-physical\.sysfs\.hex$' -- "$init_sprom_path"
        set local_init_sprom "$output_dir/"(basename "$init_sprom_path")
        set -l part "$local_init_sprom.partial.$fish_pid"
        ssh $ssh_options "$target" "cat '$init_sprom_path'" > "$part"; or begin
            command rm -f "$part"
            set local_init_sprom ''
            rv_warn 'Could not retrieve physical SPROM alongside OTP INIT evidence.'
        end
        if test -n "$local_init_sprom"
            command mv -f "$part" "$local_init_sprom"; or rv_die 'Could not finalize physical SPROM copy'
            sha256sum "$local_init_sprom" > "$local_init_sprom.sha256"
        end
    end

    rv_info "Saved OTP pre-INIT evidence: $local_pre_info and $local_pre_raw"
    rv_info "Saved OTP post-INIT evidence: $local_post_info and $local_post_raw"
    if cmp -s "$local_pre_raw" "$local_post_raw"
        rv_warn 'OTP shadow is byte-for-byte unchanged after INIT.'
    else
        rv_info 'OTP shadow changed after INIT; auditing the post-INIT geometry candidate.'
    end

    set -l nvmem_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-ssb-nvmem.py"
    test -x "$nvmem_analyzer"; or rv_die "Missing SSB NVM analyzer: $nvmem_analyzer"
    for phase in pre post
        set -l phase_info ''
        set -l phase_raw ''
        if test "$phase" = pre
            set phase_info "$local_pre_info"
            set phase_raw "$local_pre_raw"
        else
            set phase_info "$local_post_info"
            set phase_raw "$local_post_raw"
        end
        set -l stem (string replace -r '\.otp-info\.txt$' '' -- "$phase_info")
        set -l phase_json "$stem.analysis.json"
        set -l phase_text "$stem.analysis.txt"
        set -l candidate "$stem.srom-candidate.bin"
        set -l analyzer_args --otp-info "$phase_info" --otp-raw "$phase_raw" --json "$phase_json" --text "$phase_text" --candidate-bin "$candidate"
        if test -n "$local_init_sprom"
            set -a analyzer_args --physical-sprom "$local_init_sprom"
        end
        python3 "$nvmem_analyzer" $analyzer_args; or rv_die "Could not audit $phase-INIT OTP evidence"
        test -f "$candidate"; and sha256sum "$candidate" > "$candidate.sha256"

        if test "$phase" = post
            set -l eligible (python3 -c 'import json,sys; data=json.load(open(sys.argv[1], encoding="utf-8")); print("1" if data.get("openwrt_fallback", {}).get("eligible") else "0")' "$phase_json")
            if test "$eligible" = 1
                set -l fallback_bin "$stem.openwrt-fallback.bin"
                python3 "$nvmem_analyzer" $analyzer_args --emit-openwrt-fallback "$fallback_bin" >/dev/null; or rv_die 'CRC-valid post-INIT OTP candidate failed fallback serialization'
                sha256sum "$fallback_bin" > "$fallback_bin.sha256"
                rv_info "CRC-valid post-INIT OTP candidate serialized for offline comparison: $fallback_bin"
                rv_warn 'Fallback serialization is evidence only. RF remains blocked pending calibration/regulatory review.'
            end
        end
    end

    rv_info 'Explicit OTP INIT before/after capture complete. No radio firmware, scan, association, AP, SPROM write, OTP programming opcode, or flash write was attempted.'
    exit 0
end

if not ssh $ssh_options "$target" "test -x $remote_script" >/dev/null 2>&1
    rv_warn 'Wi-Fi snapshot script is not installed; streaming the packaged read-only script to /tmp.'
    test -f "$fallback"; or rv_die "Missing packaged Wi-Fi script: $fallback"
    command cat "$fallback" | ssh $ssh_options "$target" \
        'umask 077; cat > /tmp/rv220w-wifi-snapshot && chmod 0755 /tmp/rv220w-wifi-snapshot'
    set -l transfer_status $pipestatus
    if test $transfer_status[1] -ne 0 -o $transfer_status[2] -ne 0
        rv_die 'Could not stream Wi-Fi snapshot script to the target'
    end
    set remote_script /tmp/rv220w-wifi-snapshot
end

set -l remote_output (ssh $ssh_options "$target" "$remote_script '$label'" | string trim | tail -n 1)
string match -qr '^/tmp/rv220w-wifi-[A-Za-z0-9._-]+\.txt$' -- "$remote_output"; or rv_die "Unexpected target output path: $remote_output"
set -l local_output "$output_dir/"(basename "$remote_output")
set -l partial "$local_output.partial.$fish_pid"
ssh $ssh_options "$target" "cat '$remote_output'" > "$partial"; or begin
    command rm -f "$partial"
    rv_die 'Could not retrieve Wi-Fi snapshot'
end
command mv -f "$partial" "$local_output"; or rv_die 'Could not finalize Wi-Fi snapshot'
rv_info "Saved $local_output"

set -l analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-wifi-snapshot.py"
if test -x "$analyzer"
    set -l analysis_json "$local_output.analysis.json"
    set -l analysis_text "$local_output.analysis.txt"
    python3 "$analyzer" "$local_output" --json "$analysis_json" --text "$analysis_text"
    set -l analysis_rc $status
    if test $analysis_rc -eq 0
        rv_info "Discovery gates passed; saved $analysis_text and $analysis_json"
    else
        rv_warn "Discovery analyzer found a gate that needs review; saved $analysis_text and $analysis_json"
    end
end

set -l sprom_path (sed -n 's/^sprom_copy=//p' "$local_output" | tail -n 1)
if string match -qr '^/tmp/rv220w-bcm4322-sprom-[A-Za-z0-9._-]+\.sysfs\.hex$' -- "$sprom_path"
    set -l local_sprom "$output_dir/"(basename "$sprom_path")
    set -l sprom_partial "$local_sprom.partial.$fish_pid"
    ssh $ssh_options "$target" "cat '$sprom_path'" > "$sprom_partial"; or begin
        command rm -f "$sprom_partial"
        rv_die 'Could not retrieve the read-only physical SPROM sysfs dump'
    end
    command mv -f "$sprom_partial" "$local_sprom"; or rv_die 'Could not finalize physical SPROM sysfs dump'
    sha256sum "$local_sprom" > "$local_sprom.sha256"
    rv_info "Saved $local_sprom"

    set -l sprom_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-ssb-sprom.py"
    if test -x "$sprom_analyzer"
        set -l stem (string replace -r '\.sysfs\.hex$' '' -- "$local_sprom")
        set -l decoded "$stem.decoded.bin"
        set -l sprom_json "$stem.analysis.json"
        set -l sprom_text "$stem.analysis.txt"
        python3 "$sprom_analyzer" "$local_sprom" --decoded-bin "$decoded" --json "$sprom_json" --text "$sprom_text"; or rv_die 'Could not decode/audit the physical SPROM shadow'
        sha256sum "$decoded" > "$decoded.sha256"
        rv_info "Decoded/audited physical SPROM shadow: $sprom_text"
    end
else
    rv_warn 'No readable ssb_sprom sysfs file was reported.'
end

# Generic SSB PCI NVM diagnostics.  The target helper only reads the existing
# SSB driver's read-only sysfs attributes; this host block retrieves and audits
# those files.  It never enables the radio or writes NVM.
set -l otp_info_path (sed -n 's/^otp_info_copy=//p' "$local_output" | tail -n 1)
set -l otp_raw_path (sed -n 's/^otp_raw_copy=//p' "$local_output" | tail -n 1)
set -l sprom_physical_path (sed -n 's/^sprom_physical_copy=//p' "$local_output" | tail -n 1)
set -l sprom_paired16_path (sed -n 's/^sprom_paired16_copy=//p' "$local_output" | tail -n 1)

if string match -qr '^/tmp/ssb-nvmem-[A-Za-z0-9._-]+\.otp-info\.txt$' -- "$otp_info_path"; and \
   string match -qr '^/tmp/ssb-nvmem-[A-Za-z0-9._-]+\.otp-raw\.hex$' -- "$otp_raw_path"
    set -l local_otp_info "$output_dir/"(basename "$otp_info_path")
    set -l local_otp_raw "$output_dir/"(basename "$otp_raw_path")
    set -l part "$local_otp_info.partial.$fish_pid"
    ssh $ssh_options "$target" "cat '$otp_info_path'" > "$part"; or begin
        command rm -f "$part"
        rv_die 'Could not retrieve SSB OTP metadata'
    end
    command mv -f "$part" "$local_otp_info"; or rv_die 'Could not finalize SSB OTP metadata'

    set part "$local_otp_raw.partial.$fish_pid"
    ssh $ssh_options "$target" "cat '$otp_raw_path'" > "$part"; or begin
        command rm -f "$part"
        rv_die 'Could not retrieve SSB OTP raw shadow'
    end
    command mv -f "$part" "$local_otp_raw"; or rv_die 'Could not finalize SSB OTP raw shadow'
    sha256sum "$local_otp_info" > "$local_otp_info.sha256"
    sha256sum "$local_otp_raw" > "$local_otp_raw.sha256"
    rv_info "Saved $local_otp_info and $local_otp_raw"

    set -l local_sprom_physical ''
    if string match -qr '^/tmp/ssb-nvmem-[A-Za-z0-9._-]+\.sprom-physical\.sysfs\.hex$' -- "$sprom_physical_path"
        set local_sprom_physical "$output_dir/"(basename "$sprom_physical_path")
        set part "$local_sprom_physical.partial.$fish_pid"
        ssh $ssh_options "$target" "cat '$sprom_physical_path'" > "$part"; or begin
            command rm -f "$part"
            set local_sprom_physical ''
            rv_warn 'Could not retrieve the generic physical-SPROM diagnostic copy; continuing with OTP evidence'
        end
        if test -n "$local_sprom_physical"
            command mv -f "$part" "$local_sprom_physical"; or rv_die 'Could not finalize generic physical-SPROM diagnostic copy'
            sha256sum "$local_sprom_physical" > "$local_sprom_physical.sha256"
            rv_info "Saved $local_sprom_physical"
        end
    end

    set -l local_sprom_paired16 ''
    if string match -qr '^/tmp/ssb-nvmem-[A-Za-z0-9._-]+\.sprom-paired16\.txt$' -- "$sprom_paired16_path"
        set local_sprom_paired16 "$output_dir/"(basename "$sprom_paired16_path")
        set part "$local_sprom_paired16.partial.$fish_pid"
        ssh $ssh_options "$target" "cat '$sprom_paired16_path'" > "$part"; or begin
            command rm -f "$part"
            set local_sprom_paired16 ''
            rv_warn 'Could not retrieve the paired 16-bit SPROM capture; continuing with other NVM evidence'
        end
        if test -n "$local_sprom_paired16"
            command mv -f "$part" "$local_sprom_paired16"; or rv_die 'Could not finalize paired 16-bit SPROM capture'
            sha256sum "$local_sprom_paired16" > "$local_sprom_paired16.sha256"
            rv_info "Saved $local_sprom_paired16"
        end
    end

    set -l nvmem_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-ssb-nvmem.py"
    if test -x "$nvmem_analyzer"
        set -l stem (string replace -r '\.otp-info\.txt$' '' -- "$local_otp_info")
        set -l nvmem_json "$stem.analysis.json"
        set -l nvmem_text "$stem.analysis.txt"
        set -l candidate "$stem.srom-candidate.bin"
        set -l analyzer_args --otp-info "$local_otp_info" --otp-raw "$local_otp_raw" --json "$nvmem_json" --text "$nvmem_text" --candidate-bin "$candidate"
        if test -n "$local_sprom_physical"
            set -a analyzer_args --physical-sprom "$local_sprom_physical"
        end
        python3 "$nvmem_analyzer" $analyzer_args; or rv_die 'Could not audit the SSB PCI OTP evidence'
        if test -f "$candidate"
            sha256sum "$candidate" > "$candidate.sha256"
        end
        rv_info "Audited SSB PCI OTP evidence: $nvmem_text"

        set -l eligible (python3 -c 'import json,sys; data=json.load(open(sys.argv[1], encoding="utf-8")); print("1" if data.get("openwrt_fallback", {}).get("eligible") else "0")' "$nvmem_json")
        if test "$eligible" = 1
            set -l fallback_bin "$stem.openwrt-fallback.bin"
            python3 "$nvmem_analyzer" $analyzer_args --emit-openwrt-fallback "$fallback_bin" >/dev/null; or rv_die 'CRC-valid OTP candidate unexpectedly failed fallback serialization'
            sha256sum "$fallback_bin" > "$fallback_bin.sha256"
            rv_info "CRC-valid OTP candidate serialized for offline OpenWrt fallback comparison: $fallback_bin"
            rv_warn 'Fallback serialization is evidence only; RF remains blocked until board/regulatory calibration is independently validated.'
        else
            rv_warn 'Geometry-defined OTP SROM candidate is not integrity-valid; no OpenWrt fallback blob was emitted.'
        end
    end

    set -l paired_analyzer "$RV220W_TOOLKIT_ROOT/scripts/analyze-ssb-sprom-paired.py"
    if test -n "$local_sprom_paired16"; and test -x "$paired_analyzer"
        set -l paired_stem (string replace -r '\.sprom-paired16\.txt$' '' -- "$local_sprom_paired16")
        set -l paired_json "$paired_stem.sprom-paired16.analysis.json"
        set -l paired_text "$paired_stem.sprom-paired16.analysis.txt"
        set -l paired_second "$paired_stem.sprom-paired16.second.bin"
        set -l paired_args "$local_sprom_paired16" --json "$paired_json" --text "$paired_text" --second-bin "$paired_second"
        if test -n "$local_sprom_physical"
            set -a paired_args --physical-sprom "$local_sprom_physical"
        end
        python3 "$paired_analyzer" $paired_args; or rv_die 'Could not audit the paired 16-bit SPROM evidence'
        sha256sum "$paired_second" > "$paired_second.sha256"
        rv_info "Audited paired 16-bit SPROM evidence: $paired_text"

        set -l paired_eligible (python3 -c 'import json,sys; data=json.load(open(sys.argv[1], encoding="utf-8")); print("1" if data.get("openwrt_fallback", {}).get("eligible") else "0")' "$paired_json")
        if test "$paired_eligible" = 1
            set -l paired_fallback "$paired_stem.sprom-paired16.openwrt-fallback.bin"
            python3 "$paired_analyzer" $paired_args --emit-openwrt-fallback "$paired_fallback" >/dev/null; or rv_die 'CRC-valid stock-retained second SPROM read unexpectedly failed fallback serialization'
            sha256sum "$paired_fallback" > "$paired_fallback.sha256"
            rv_info "CRC-valid stock-retained second SPROM stream serialized for offline fallback comparison: $paired_fallback"
            rv_warn 'Fallback serialization is evidence only; RF remains blocked until board/regulatory calibration is independently validated.'
        else
            rv_warn 'Stock-retained second SPROM read is not integrity-valid; no paired-read fallback blob was emitted.'
        end
    end
else
    rv_warn 'No supported read-only SSB PCI OTP diagnostics were reported by this target.'
end
