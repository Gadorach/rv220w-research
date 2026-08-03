# Current validation

Hardware validated:

- LuCI RAM boot and LAN access;
- all five RJ45 ports, WAN DHCP, routing/NAT, and isolation;
- exact 22 MiB slot backup, write, and complete read-back SHA-256;
- corrected copy-to-RAM plus `bootoctlinux` launch;
- combined boot-policy bytes and CRC32 `b77a94de`;
- saved `bootcmd` persistence and automatic OpenWrt boot;
- retained physical-button Sercomm recovery.

Not complete:

- persistent writable root/overlay and sysupgrade;
- Wi-Fi;
- full LEDs/reset/watchdog promotion;
- one-command packaged combined-flasher transition directly from a completely stock sector.
