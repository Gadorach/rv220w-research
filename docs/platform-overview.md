# Platform overview

## Goal

Preserve and understand the Cisco RV220W well enough to recover the original firmware, boot modern Linux safely from RAM, and develop maintainable OpenWrt support without risking the stock boot chain.

## Confirmed platform

- Cisco RV220W-A V01, PCB `YK910A-1.6`.
- Cavium OCTEON Plus CN5010-SCP pass 1.1, one active core at 400 MHz.
- 128 MiB DDR2.
- 32 MiB x16 CFI NOR at U-Boot address `0xbdc00000`.
- Broadcom BCM53115 five-port Gigabit switch.
- Broadcom BCM4322 Mini PCI WLAN module, PCI ID `14e4:432b`.
- U-Boot 1.1.1 development build, revision `193M`.
- Stock Linux 2.6.21.7-Cavium-Octeon, big-endian MIPS64.
- JP1 primary UART at 115200 8N1.

## Current modern OpenWrt result

A modern OpenWrt initramfs image now boots completely through the stock U-Boot TFTP path and runs entirely from RAM. The current `rj45-full` profile initializes all five RJ45 ports using upstream-style B53/DSA support plus focused Octeon and B53 patches.

The wired topology is hardware-proven as:

```text
LAN1-LAN4 -> switch ports 1-4 -> CPU port 8 -> eth0 -> br-lan
WAN        -> switch port 0   -> CPU port 5 -> eth1 -> wan
```

No persistent flash installation has been attempted. LuCI is not included, and the BCM4322 radio is not yet operational.

## Evidence vocabulary

- **Observed:** directly photographed, measured, or captured.
- **Hardware-proven:** reproduced on the physical RV220W through live boot or traffic testing.
- **Inferred:** the best current explanation, but not yet directly validated.
- **Unknown:** insufficient evidence.

## Preservation rule

The stock boot chain and full verified flash image remain the recovery baseline. Until a separate persistent-installation project is qualified, all OpenWrt work must continue through RAM-only TFTP boot with no `saveenv`, erase, copy-to-NOR, or Linux MTD write operation.
