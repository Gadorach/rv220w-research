# Current status

**Research package:** 2.0.0  
**OpenWrt toolkit:** 1.10.3 integrated documentation revision  
**Boot-chain reconstruction:** 1.4.0-r1  
**Snapshot:** 2026-08-02  
**Board:** Cisco RV220W-A V01 / PCB `YK910A-1.6`

## Hardware-proven persistent OpenWrt state

The RV220W now boots the LuCI-enabled OpenWrt initramfs ELF from the onboard
parallel NOR. The stock U-Boot chain remains in use with two narrow instruction
patches in its first 128 KiB erase sector.

Required boot sequence:

```text
NOR 0xbdc80000 -> cp.b exact ELF source_size -> RAM 0x05500000
RAM 0x05500000 -> bootoctlinux -> OpenWrt 25.12.5 / Linux 6.12.94
```

The validated environment policy is:

```text
bootdelay=3
bootcmd=run openwrt_boot
openwrt_boot=cp.b 0xbdc80000 0x05500000 0x11565d0; bootoctlinux 0x05500000 console=ttyS0,115200
```

`0x11565d0` is specific to the validated 18,179,536-byte LuCI ELF. It must be
regenerated from the slot manifest whenever the image changes.

## Mandatory installation order

1. Preserve a complete NOR backup and external recovery capability.
2. Apply and verify the combined boot-policy patch.
3. Build and RAM-boot the dedicated `nor-writer` image.
4. Back up and write only the 22 MiB `openwrt-slot`.
5. Manually test the manifest-derived copy-to-RAM boot commands.
6. Save the final `openwrt_boot` and `bootcmd` environment only after the manual boot succeeds.

Do **not** flash the OpenWrt slot first on an unpatched boot chain. The stock late
initialization overwrites `bootcmd`, and the proprietary image check diverts an
OpenWrt image into Sercomm HTTP recovery.

## Verified behavior

- LuCI is available on LAN at `http://192.168.240.2/`.
- LAN1-LAN4 operate through BCM53115 CPU port 8 and Octeon `eth0`.
- WAN operates through BCM53115 CPU port 5 and Octeon `eth1`.
- DHCP, firewall4, LAN-to-WAN routing/NAT, and WAN isolation are validated.
- A complete 22 MiB slot write and read-back SHA-256 verification succeeded.
- Saved `bootcmd` survives `saveenv` and reset after the boot-policy patch.
- Released-button invalid-format HTTP recovery is bypassed.
- Holding the active-low recovery button still enters Sercomm download mode.

## Boot-chain patch identity

```text
flash range: 0xbdc00000-0xbdc1ffff
combined CRC32: b77a94de
0x13138: 04 41 00 03 -> 10 00 00 03
0x13168: 03 20 00 08 -> 03 e0 00 08
```

The exact target bytes, sector erase/program/compare procedure, runtime policy,
and recovery-button behavior were exercised on hardware. The distribution
wrapper's idempotent already-combined path was also tested. One single wrapper
execution directly from a completely stock sector to combined was not separately
performed; the two component transitions and final combined state were.

## Remaining limitations

- The stored image is initramfs. Firmware persists, but runtime configuration is recreated on every boot.
- No persistent SquashFS plus writable overlay or supported `sysupgrade` path exists.
- Wi-Fi remains unsupported; the BCM4322 only has PCI enumeration proof.
- Status LEDs, reset-button Linux integration, watchdog behavior, and remaining GPIOs are not fully promoted.
- Every replacement ELF requires a newly generated `openwrt_boot` copy length.
