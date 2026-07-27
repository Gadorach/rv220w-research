#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
set -l toolkit_version (string trim < "$RV220W_TOOLKIT_ROOT/VERSION")
printf 'RV220W toolkit version:             %s\n' "$toolkit_version"
printf 'OpenWrt platform integration:       1.3.2 (hardware-proven baseline)\n'
printf 'Read-only discovery profile:        %s\n' "$toolkit_version"
printf 'LAN-only DSA validation profile:    %s (hardware proven)\n' "$toolkit_version"
printf 'Dual-conduit diagnostic profile:    %s (run9 hardware proven with live VLAN repair)\n' "$toolkit_version"
printf 'Full-RJ45 routed candidate:         %s (source ready; first hardware boot pending)\n' "$toolkit_version"
printf 'OpenWrt source ref:                 %s\n' "$RV220W_OPENWRT_REF"
printf 'Platform and toolkit versions are intentionally independent.\n'
