# Cisco RV220W OpenWrt promotion toolkit

Fish-first tooling for building and validating modern OpenWrt on the Cisco
RV220W/Cavium CN5010. The project remains experimental.

## Current status

- OpenWrt 25.12.5 / Linux 6.12.94 boots through TFTP into RAM.
- BCM53115 DSA support is hardware validated on all five RJ45 jacks.
- LAN1-LAN4 provide DHCP and routed/NAT Internet access.
- WAN uses the independent CPU-port-5/Octeon-`eth1` conduit and obtains DHCP.
- firewall4 permits WAN traffic addressed to the router while rejecting
  unsolicited WAN-to-LAN forwarding.
- production DTS cleanup, raw-FDT export, and 32 MiB x16 parallel-NOR mapping
  are validated.
- Wi-Fi remains unsupported.
- v1.10.0 LuCI and the v1.10.1 NOR-writer image both built and RAM-booted.
- v1.10.2 fixed the host writer transport: OpenSSH no longer attempts SFTP
  against Dropbear, and RAM-boot host keys no longer pollute `known_hosts`.
- v1.10.3 corrects first boot from NOR: the Linux ELF must be copied from
  memory-mapped NOR into RAM before invoking `bootoctlinux`; direct `bootoct`
  execution from flash is invalid for this image.

The board has **parallel NOR, not NAND**.

## Profiles

```text
rj45-full   Validated routed five-port RAM baseline; all NOR read-only
rj45-luci   Same data plane plus LuCI at http://192.168.240.2/; all NOR read-only
nor-writer  TFTP/RAM-only writer; only the 22 MiB openwrt-slot is writable
```

The first NOR payload is a padded initramfs ELF. The firmware image persists,
but configuration remains volatile on every boot. No profile changes U-Boot,
`bootcmd`, or the U-Boot environment automatically.

## Setup

```fish
unzip rv220w-openwrt-promotion-toolkit-v1.10.3.zip
cd rv220w-openwrt-promotion-toolkit-v1.10.3
cp config/toolkit.env.fish.example config/toolkit.env.fish

./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
```

## Build and RAM boot

```fish
./rv220w.fish build rj45-luci
./rv220w.fish tftp-boot --profile rj45-luci --interface enp0s31f6 --configure-interface
```

The LuCI profile produces both the RAM-boot ELF and an exact 22 MiB NOR-slot
artifact with a JSON manifest and SHA-256.

## Guarded first NOR stage

```fish
./rv220w.fish build nor-writer
./rv220w.fish tftp-boot --profile nor-writer --interface enp0s31f6 --configure-interface
```

Set a temporary root password over UART, then:

```fish
./rv220w.fish nor-stage status
./rv220w.fish nor-stage backup
./rv220w.fish nor-stage write --confirm RV220W_WRITE_OPENWRT_SLOT
```

The write action validates the local manifest, requires a complete pre-write
backup, writes only `openwrt-slot`, and verifies the complete 22 MiB read-back.
The same writer can restore an exact saved slot backup using the separate
`RV220W_RESTORE_OPENWRT_SLOT` confirmation token. Neither operation reboots.
Generate the exact two-command U-Boot plan from the local slot manifest:

```fish
./rv220w.fish nor-stage boot-plan
```

For the validated v1.10.0 LuCI ELF currently staged in NOR, it prints:

```text
cp.b 0xbdc80000 0x05500000 0x11565d0
bootoctlinux 0x05500000 console=ttyS0,115200
```

The v1.10.3 correction is host/tooling/documentation-only. The already written
slot image and the v1.10.1 writer image remain valid; no rebuild or rewrite is
required.

## Documentation

- [v1.10.3 NOR flash boot correction](docs/RV220W-V1.10.3-NOR-FLASH-BOOT-CORRECTION.md)
- [v1.10.2 NOR transport hotfix](docs/RV220W-V1.10.2-NOR-TRANSPORT-HOTFIX.md)
- [v1.10.1 NOR-writer guard hotfix](docs/RV220W-V1.10.1-NOR-WRITER-GUARD-HOTFIX.md)
- [v1.10.0 LuCI and NOR staging](docs/RV220W-V1.10.0-LUCI-NOR-STAGING.md)
- [Guarded NOR workflow](docs/FLASH_WORKFLOW.md)
- [Current validation record](docs/VALIDATION.md)
- [Promotion plan](docs/PROMOTION_PLAN.md)
- [TFTP RAM boot](docs/TFTP_LIVE_BOOT.md)
- [Run9 VLAN/PVID proof](docs/RV220W-RUN9-VLAN-PVID-PROOF.md)
- [v1.9.3 production/FDT hotfix](docs/RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md)

Preserved evidence is under `evidence/`, including the v1.9.3 five-port
validation in `evidence/run12-v193-rj45-validation/`.
