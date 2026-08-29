# Current validation status — v1.14.1

Hardware-qualified:

- fixed-length compressed-kernel cold boot through saved U-Boot environment;
- exact five-partition runtime map including the automatic JFFS2 child;
- clean `sysupgrade -n` through UART;
- clean LuCI sysupgrade image recognition and write path;
- rootfs-first/kernel-last erase, write and readback verification;
- preservation of `boot-chain` and `uboot-env`;
- fresh JFFS2 overlay creation and persistence across ordinary reboot.

Observed remaining defect in v1.7.4: command-line and LuCI keep-settings
upgrades saved `/tmp/sysupgrade.tgz` but did not append it, because the exact
SquashFS write image did not contain the erase-aligned JFFS2 insertion marker
required by `mtd -j`. Firmware flashing completed correctly, but the hostname
and explicit test UCI file reverted after reboot.

Platform v1.7.5 creates and validates an erase-aligned marker-bearing temporary
root image, validates the backup before any erase, requires a JFFS2 node to
replace the marker, and writes the kernel only after that check. Static, shell,
archive, simulated MTD, missing-backup and failed-marker regressions pass.
Hardware keep-settings testing through both CLI and LuCI remains pending.

# RV220W validation status

## v1.12.0 full-NOR transition status

Hardware validation of the earlier rootfs-first gate passed:

- persistent ELF execution and appended DTB: pass;
- expected missing-rootfs panic before write: pass;
- RAM persistent writer boot: pass;
- rootfs write and complete readback hash: pass;
- SquashFS `/rom`: pass;
- JFFS2 `/overlay`: pass;
- configuration marker across reboot: pass.

The active overlay was the automatic SquashFS split inside `rootfs`, proving the
explicit tail `rootfs_data` was redundant. v1.12.0 changes the map to a 25.375
MiB rootfs ending at the final environment and preserves only boot-chain and
uboot-env. That new full-region write and reboot test remains pending.

Expected post-write map with the current SquashFS:

```text
mtd0 boot-chain       0x00080000
mtd1 openwrt-kernel   0x00600000
mtd2 rootfs           0x01960000
mtd3 rootfs_data      0x01560000 (automatic child)
mtd4 uboot-env        0x00020000
```

## Historical validation record

## v1.11.8 rootfs-staging correction

The v1.11.7 hardware-hosted build completed the OpenWrt target, exported the compressed persistent kernel and created a valid SquashFS. Toolkit staging then failed because a fallback `mksquashfs` command ran inside command substitution and wrote progress text to stdout; that text was captured with the intended pathname. v1.11.8 first selects the exact OpenWrt-generated build-directory `root.squashfs`. Its fallback path redirects all tool output to a log/stderr and returns only the output pathname. Hardware validation remains pending.

## v1.11.7 persistent build-tool correction

The v1.11.6 hardware-hosted build proved that the explicit-output DTB helper completed successfully, including output creation, `.appended_dtb` extraction, byte comparison and final move. OpenWrt then deleted the raw kernel because `KERNEL_SIZE := 6m` runs `Build/check-size` after the kernel pipeline and the sparse Octeon ELF exceeded 6 MiB. The following export copy produced the misleading `cannot stat` error.

v1.11.7 appends OpenWrt's deterministic `gzip -9n` step after verified DTB injection. The 6 MiB check now applies to the actual compressed flash payload. The build stages both `.elf.gz` for the kernel partition and the decompressed `.elf` for TFTP validation. Hardware validation of the compressed build and U-Boot `gunzip` path remains pending.

## v1.11.0 persistent SquashFS design status

Validated offline and synthetically:

- platform v1.5.0 defines the approved 6 MiB kernel, 16 MiB SquashFS,
  preserved 1 MiB stock-data, 8.375 MiB JFFS2 rootfs_data and final 128 KiB
  U-Boot environment layout;
- the reclaimed 128 KiB legacy gap and 8.25 MiB vendor tail are all `0xff` in
  the preserved extraction;
- persistent and persistent-writer build profiles, config seeds and command
  lines are present;
- the component builder rejects invalid gzip-compressed ELF/SquashFS inputs, enforces partition
  sizes, pads with `0xff`, records exact hashes and emits an exact U-Boot plan;
- target and host writers enforce model/profile/MTD geometry, exact confirmation
  tokens, mandatory backups and complete read-back SHA-256 verification;
- synthetic gzip-ELF/SquashFS component generation and all toolkit regressions pass.

Not yet validated:

- an actual persistent-profile build from the pinned OpenWrt tree;
- target boot of the non-initramfs kernel;
- SquashFS root and JFFS2 overlay creation/mounting;
- settings/package persistence, factory reset or overlay lifecycle;
- any persistent component write using the new writer;
- sysupgrade creation or execution.

## Hardware-validated boot-chain and current initramfs state — 2026-08-02

- combined sector-0 policy CRC32 is `b77a94de`;
- saved custom `bootcmd` survives `saveenv` and reset;
- invalid proprietary firmware magic no longer launches Sercomm HTTP recovery;
- holding the active-low recovery button still launches download recovery;
- automatic NOR-to-RAM OpenWrt boot works with `bootdelay=3`, no `preboot`, and
  `bootcmd=run openwrt_boot`;
- the installed LuCI image remains initramfs and therefore has no persistent
  writable root.

## v1.10.3 NOR flash boot correction

The v1.10.2 transport completed the first full `openwrt-slot` write. The
target-side read-back matched SHA-256
`51340539fff729869bab36181662e36648768663c9774e5f98646d4283bc86a5`.

Direct `bootoct 0xbdc80000 forceboot` then failed with a read-only TLB-mapping
error because `bootoct` is the Octeon Executive application loader, not the
validated Linux ELF loader. The programmed image remains valid.

The corrected first boot copies the exact ELF byte count from NOR to the proven
RAM staging address and then invokes `bootoctlinux`. For the current LuCI image:

```text
cp.b 0xbdc80000 0x05500000 0x11565d0
bootoctlinux 0x05500000 console=ttyS0,115200
```

No rebuild or rewrite is required. See
`RV220W-V1.10.3-NOR-FLASH-BOOT-CORRECTION.md`.

## v1.10.2 NOR transport hotfix

The dedicated v1.10.1 NOR-writer image built and RAM-booted successfully. Its command line exposed one writable 22 MiB `openwrt-slot`; status and two complete backups succeeded. Both backups are byte-identical and match SHA-256 `47b546d826e9016d3fa0a8e08356e1ba614cba7290d11eba79a6bd80e0671c6d`.

The write attempt stopped during host-to-target transfer because modern OpenSSH `scp` attempted SFTP against Dropbear without `sftp-server`. The target writer was never invoked, so no erase or NOR write occurred. v1.10.2 replaces `scp` with byte-exact SSH streaming and isolates ephemeral RAM-boot host keys. See `RV220W-V1.10.2-NOR-TRANSPORT-HOTFIX.md`.

## v1.10.1 NOR-writer guard hotfix

The v1.10.0 `rj45-luci` profile built and TFTP/RAM-booted successfully. U-Boot
transferred the complete 18,179,536-byte ELF, Linux reached DSA setup with both
CPU ports in `rgmii-rxid`, the 32 MiB BootBus NOR map remained clean/read-only,
and the operator reported LuCI working normally.

The `nor-writer` build did not reach compilation because the post-defconfig
verifier incorrectly required LuCI packages from the intentionally LuCI-free
writer seed. v1.10.1 changes only that validation path and the writer banner.
The platform v1.4.0 integration, patches 995-999, production DTS, partition
layout, and guarded writer remain byte-for-byte unchanged.

See `RV220W-V1.10.1-NOR-WRITER-GUARD-HOTFIX.md`.

## v1.10.0 entry gate

The v1.9.3 RAM image is the validated all-RJ45 baseline. Archived run12 evidence and operator tests establish all five 1 Gb/s jacks, LAN DHCP, WAN DHCP, LAN-to-WAN routing/NAT, WAN-to-LAN forwarding rejection, clean FDT export, readable NOR partitions, firewall4, and kernel taint value 0.

v1.10.0 does not change patches 995-999 or the production DTS. New validation is limited to:

- `rj45-luci`: LuCI/uHTTPd reachable only at `192.168.240.2:80`;
- `nor-writer`: only a 22 MiB `openwrt-slot` writable while all non-slot regions remain read-only;
- exact-size slot artifact and manifest;
- mandatory backup, write, and full read-back SHA-256 verification;
- manual NOR-to-RAM copy followed by `bootoctlinux`;
- no `saveenv`, automatic reboot, bootloader write, or environment write.

The storage device is parallel NOR, not NAND. See `RV220W-V1.10.0-LUCI-NOR-STAGING.md`.

## v1.9.3 FDT verification API hotfix

See `RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md`. Patch 999 now calls the Linux 6.12 two-argument `early_init_dt_verify()` API with the flat-tree virtual address and `__pa()` physical address. The v1.9.2 stable patch context and all production DTS, NOR, firewall and RJ45 behavior remain unchanged.


## v1.9.2 patch-999 context hotfix

See `RV220W-V1.9.2-PATCH999-CONTEXT-HOTFIX.md`. This release changes only the textual context used to apply patch 999 after OpenWrt patch 400; the v1.9.1 production DTS, NOR/FDT cleanup semantics, firewall policy and full-RJ45 topology are unchanged.


## Current hardware-validated state — 2026-07-27

- v1.3.2 remains the clean RAM-only platform baseline: 115200 UART, Linux 6.12.94, 32 MiB x16 NOR and seven read-only partitions.
- Passive MDIO/B53 discovery proves switch ports 0/5 are the WAN/`eth1` path and ports 1-4/8 are the LAN/`eth0` path.
- LAN1-LAN4 each negotiate 1000/full and pass minimum through full-1500-byte traffic over CPU port 8 with no sustained Octeon receive errors.
- WAN port 0 negotiates 1000/full and passes ordinary/full-MTU traffic through CPU port 8 when reassigned there, proving the external PHY and DSA user path.
- Run7 proves the intended port-0/5 and port-1-4/8 PVLAN domains, Broadcom tag enablement, dual-IMP management mode, and `rgmii-rxid` links are correct.
- Run8 proves BASIC versus SIMPLIFIED EAP mode is not causal.
- Run9 proves ordinary VLAN-table classification is causal: port-5 PVID-only change fails, explicit VID-0 and VID-1 port-0/5 domains pass, and restoring the original VLAN table restores failure.
- The generic production fix is patch 998, which merges firmware-described DSA CPU ports into B53's active-port mask before default PVID/VLAN initialization.
- NOR remains untouched throughout every DSA, EAP and VLAN test.

## v1.9.0 hardware result and v1.9.1 cleanup boundary

The v1.9.0 `rv220w-rj45-initramfs` image booted successfully with the intended
`wan@eth1` and `lan1-lan4@eth0` topology, a live LAN bridge, DHCP service,
firewall4 rules, and NAT policy.  The operator then performed a quick hardware
check and reported that all five RJ45 jacks and LAN DHCP worked.  Because that
quick check did not include an archived packet/counter bundle, it is retained as
informal hardware confirmation rather than the final acceptance record.

v1.9.1 is a production-cleanup candidate.  It preserves patches 995-998 and adds
patch 999 plus a dedicated production DTS.  The cleanup is intended to remove
the deprecated Octeon link fallback, the redundant generic physmap failure, the
raw-FDT CRC rejection, and the validation-module taint while retaining the
BootBus-aware 32 MiB x16 NOR mapping.  It also removes raw MDIO packages from the
production image, fixes firewall status reporting, removes default WAN-to-LAN
IPsec exceptions, and binds Dropbear to LAN.

No flash installation or write path is introduced.

## Historical diagnostic boundaries

### v1.8.4 VLAN/PVID validation

The live controller measured and reversibly changed only port-0/5 default VLAN tags and VLAN-table entries 0/1. Run9 established the root cause and the original state was restored after testing.

### v1.8.3 EAP validation

Run8 changed only EAP mode bits 52:51 from SIMPLIFIED to BASIC and back. Neither mode restored `eth1` ingress, ruling out the direct EAP-mode hypothesis.

### v1.8.2 conduit diagnostics

The external WAN port and DSA path were proven through CPU port 8/`eth0`; paired DSA/B53 snapshots showed that software affinity alone did not validate ordinary VLAN-table membership on CPU port 5.

### v1.8.0 dual-conduit foundation

The dual-conduit DTS, generic B53 `port_change_conduit` patch, Octeon DSA receive correction, early userspace affinity assignment, and disjoint PVLAN model were established. The validation image intentionally had no routing, NAT, DHCP or firewall policy.

Validated in the artifact-generation environment:

- all Python helpers compile with `python3 -m py_compile`;
- the UART dumper's dry-run produces the expected 32 MiB / 460800-baud read-only plan;
- the flash extractor accepts the independently verified RV220W dump, reproduces CRC32 `ce96f3e0` and SHA-256 `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`, splits the flash map, and extracts the expected big-endian JFFS2 files;
- the TFTP helper dry-run recognizes the recovered stock kernel as ELF64 big-endian MIPS, selects an interface/server/device address plan, and calculates the RAM boot address;
- every static Bash container helper passes `bash -n`;
- the existing UART dumper v0.8.1 already completed two byte-identical hardware acquisitions with target/host CRC validation.

Not yet hardware-validated with an archived acceptance bundle:

- the v1.9.1 clean production DTS and patch 999;
- disappearance of the deprecated-link, generic-physmap, raw-FDT CRC, and
  `mdio_netlink` taint messages while `/proc/mtd` still exposes all seven
  read-only partitions;
- sustained full-MTU traffic, DHCP/DHCPv6, NAT counters, and strict WAN-to-LAN
  isolation on v1.9.1;
- tagged `wan.<VID>` service;
- the RAM-only SquashFS launcher;
- BCM4322/b43 WLAN driver, firmware and RF operation.

Version 1.0.1 also makes `doctor` parse every Fish entry point with `fish -n` and every Bash container helper with `bash -n`.

Run `./rv220w.fish doctor` on CachyOS before provisioning and keep the first build and boot logs intact.

Run the packaged static regression suite with:

```bash
python3 tests/test_static_toolkit.py
```

## v1.0.2 setup regression coverage

- Scripted Distrobox calls use explicit `--name` and headless execution unless a
  menuconfig UI requires a TTY.
- A reachable non-Ubuntu container is rejected before provisioning, feeds, or
  builds.
- Ubuntu provisioning verifies `apt-get`, Perl `FindBin`, and the MIPS64 cross
  compiler.
- New OpenWrt, Linux, and reference-builder clones use shallow single-ref
  history.
- Static tests reject the older `--filter=blob:none --no-single-branch` clone
  path and direct positional Distrobox calls outside the shared helper.

## v1.0.3 recreate regression coverage

- Static tests reject any return of the interactive `distrobox stop` path in
  `setup-box`.
- Container removal uses `podman rm --force --time 3 --ignore` under a
  30-second GNU `timeout` and verifies that the named object disappeared.
- `setup-box --remove-only` separates bounded cleanup from image pulling and
  apt provisioning.
- `doctor` reports the Podman object name, state, and image before checking the
  guest distribution.
- First-use image pulls and apt installation keep their normal output visible;
  only stale-container removal has a hard time bound.

## v1.0.4 package-source regression coverage

The static regression suite now verifies that:

- the Ubuntu provisioner enables `universe` through `add-apt-repository`;
- the optional MIPS64 system compiler is isolated from main OpenWrt readiness;
- `rv_box_is_provisioned` does not require the optional reference compiler;
- `rv_box_has_reference_cross` remains available for the standalone Linux guard;
- all container helpers continue to pass `bash -n`.

A hardware-host validation should exercise the existing Ubuntu box without
recreation:

```fish
./rv220w.fish setup-box
./rv220w.fish doctor
./rv220w.fish prepare-sources
```

The acceptance gate is that OpenWrt prerequisites report ready even when the
optional system cross compiler cannot be installed. `build-linux` must remain
blocked with a specific diagnostic in that case.

## v1.3.2 repaired-baseline validation

Completed in the preparation environment:

- verified the original handoff `SHA256SUMS` before extracting baselines;
- verified pristine v1.3.0 and v1.3.1 ELF hashes against the handoff;
- proved the actual appended DTBs differ only in the enabled BootBus `nor@0,0` child and the UART `clock-frequency` value;
- generated a v1.3.2 DTB semantically equal to v1.3.0 plus the v1.3.1 400 MHz UART clock;
- expanded the v1.3.1 terminal `.appended_dtb` section by 116 bytes and updated only required ELF metadata;
- verified every non-DTB file-backed section remains byte-identical to v1.3.1;
- verified the candidate remains ELF64 big-endian MIPS64r2, retains one `PT_LOAD`, and ends its TFTP source buffer at `0x063fb2a8`, below `0x07f00000`;
- passed platform patch clean-install and all supported upgrade-chain tests;
- passed installer physical-working-directory guards, Python compilation, Bash syntax, and static safety tests.

Candidate SHA-256: `8284b808e3698b97ed17969439df8285c6ff82d1945af5932b3c1072b644551b`.

Still required on the RV220W:

- normal 115200 `ttyS0` console;
- one x16 Macronix device through `phys_mapped_flash`, manufacturer `0xc2`, chip `0x227e`;
- seven read-only command-line MTD partitions;
- retained `eth0` traffic at 1000/full;
- confirmation that no USB, B53/DSA, reset, LED-GPIO, or flash-write behavior was activated.

A pinned v25.12.5 source build is also still required because external DNS prevented cloning the exact OpenWrt tree in the preparation container.


## v1.9.1 production cleanup

See `RV220W-V1.9.1-PRODUCTION-CLEANUP.md`. The full-RJ45 production profile uses fixed internal MAC links, explicit Octeon BootBus flash ownership, refreshed post-fixup FDT verification, no out-of-tree MDIO module, strict default WAN isolation, and standard read-only status collection.


## BCM4322 v1.14.1 staging

Static analysis and toolkit tests cover the stock `wl.ko` audit, b43 patch structure, installer placement and read-only collector integration. The mac80211 package has not yet been compiled in the user workspace and the patch has not been booted on hardware. Radio operation, association, throughput, 5 GHz/DFS and HT remain unqualified.
