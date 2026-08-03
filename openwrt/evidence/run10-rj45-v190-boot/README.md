# v1.9.0 first full-RJ45 boot evidence

This directory preserves the first successful RAM boot of the v1.9.0
full-RJ45 image on 2026-07-27.

Files:

- `rv220w-tftp-boot-20260727T025422Z.tftp.log` — host TFTP transfer log.
- `rv220w-tftp-boot-20260727T025422Z.serial.log` — U-Boot and Linux startup log.
- `rv220w-v1.9.0-runtime-status.txt` — router status, UCI policy, interface
  state, WAN status and the loaded firewall4 nftables ruleset.

The archived capture proves a clean RAM transfer and boot, DSA registration,
`wan@eth1`, `lan1-lan4@eth0`, LAN1 at 1000/full, the intended bridge/network
policy, and a loaded firewall4 ruleset. WAN had no external carrier during the
status capture, so this archive does not itself prove WAN DHCP or NAT.

After the capture, the operator performed a quick manual check and reported
that all five RJ45 jacks and LAN DHCP worked. No complete counter/packet log
was retained for that quick check, so it remains an informal hardware report.

No flash write was performed.
