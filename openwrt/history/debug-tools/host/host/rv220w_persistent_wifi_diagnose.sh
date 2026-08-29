#!/bin/sh
# v1.14.99 read-only wireless diagnostic snapshot. Never prints UCI keys.
set -u
printf '%s\n' '=== rv220w persistent wireless diagnostic v1.14.99 ==='
printf 'model='; cat /tmp/sysinfo/model 2>/dev/null || true
printf 'build_profile='; cat /etc/rv220w-build-profile 2>/dev/null | tr '\n' ' '; echo
printf 'hostapd='; command -v hostapd 2>/dev/null || echo missing
printf 'wpa_supplicant='; command -v wpa_supplicant 2>/dev/null || echo missing
printf 'wifi='; command -v wifi 2>/dev/null || echo missing
printf 'installed_auth_packages='; apk info 2>/dev/null | grep -E '^(wpad|hostapd|wpa-supplicant)(-|$)' | tr '\n' ' ' || true; echo
printf 'installed_auth_package_versions='; apk info -v 2>/dev/null | grep -E '^(wpad|hostapd|wpa-supplicant)(-|$)' | tr '\n' ' ' || true; echo
printf '%s\n' '--- wpad service/control plane ---'
printf 'wpad_init='; [ -x /etc/init.d/wpad ] && echo present || echo missing
printf 'wpad_enabled='; /etc/init.d/wpad enabled >/dev/null 2>&1 && echo yes || echo no
printf 'wpad_running='; /etc/init.d/wpad running >/dev/null 2>&1 && echo yes || echo no
printf 'hostapd_global_socket='; [ -S /var/run/hostapd/global ] && echo present || echo absent
printf 'wpa_global_socket='; [ -S /var/run/wpa_supplicant/global ] && echo present || echo absent
printf 'ubus_hostapd='; ubus list 2>/dev/null | grep -E '^hostapd($|\.)' | tr '\n' ' ' || true; echo
printf 'ubus_wpa='; ubus list 2>/dev/null | grep -E '^wpa_supplicant($|\.)' | tr '\n' ' ' || true; echo
printf 'wireless_uci_changes='; uci changes wireless 2>/dev/null | tr '\n' ' ' || true; echo
printf '%s\n' '--- UCI wireless (keys redacted) ---'
uci -q show wireless 2>/dev/null | sed -E "s/(\.key=).*/\1'<redacted>'/; s/(\.password=).*/\1'<redacted>'/" || true
printf '%s\n' '--- wifi status ---'
wifi status 2>&1 || true
printf '%s\n' '--- network.wireless status (key-like fields redacted) ---'
ubus call network.wireless status 2>/dev/null | sed -E 's/("(key|password)"[[:space:]]*:[[:space:]]*")[^"]*/\1<redacted>/g' || true
printf '%s\n' '--- iw dev ---'
iw dev 2>&1 || true
printf '%s\n' '--- phy0 supported interface modes / combinations ---'
iw phy phy0 info 2>/dev/null | sed -n '/Supported interface modes:/,/Band 1:/p' || true
iw phy phy0 info 2>/dev/null | sed -n '/valid interface combinations:/,/Device supports/p' || true
printf '%s\n' '--- phy0 supported channels ---'
iw phy phy0 info 2>/dev/null | grep -E 'Band |\* [0-9]+(\.[0-9]+)? MHz' || true
printf '%s\n' '--- regulatory domain ---'
iw reg get 2>&1 || true
printf '%s\n' '--- daemon pids ---'
printf 'hostapd_pids=%s\n' "$(pidof hostapd 2>/dev/null || echo none)"
printf 'wpa_supplicant_pids=%s\n' "$(pidof wpa_supplicant 2>/dev/null || echo none)"
printf '%s\n' '--- recent wireless log ---'
logread 2>/dev/null | grep -Ei 'hostapd|wpa_supplicant|netifd.*(radio|wireless|wlan)|b43|phy0|cfg80211|mac80211' | tail -n 450 || true
