# RV220W OpenWrt promotion plan

## Current active stage — v1.13.2 P9C standard sysupgrade

The final four-partition NOR layout and reboot persistence are hardware proven.
P9C adds OpenWrt-native sysupgrade packaging and runtime support. The immediate
gate is to build and inspect the metadata-bearing tar, bootstrap a v1.13.2
persistent runtime, prove the NOR gzip-kernel boot path, and run `sysupgrade -T`.
The first write-producing sysupgrade remains a separately logged destructive
qualification with UART/TFTP/writer recovery retained.


The hardware-validated baseline includes all five RJ45 ports, LuCI, a verified
22 MiB NOR write, automatic NOR boot through the patched vendor boot chain,
persistent U-Boot environment control and preserved physical-button Sercomm
recovery.

The rootfs-first P9A gate is also complete: the non-initramfs kernel executes,
SquashFS mounts from NOR, JFFS2 initializes, and configuration persists across
reboot. That test proved the prior explicit tail overlay was redundant because
OpenWrt automatically split a working overlay inside `rootfs`.

Toolkit v1.12.0 begins P9B. It reclaims the obsolete Cisco data partition and
blank tail into a single 25.375 MiB rootfs while preserving the 512 KiB boot
chain and final 128 KiB U-Boot environment.

## v1.9.3 FDT verification API hotfix

See `RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md`. Patch 999 now calls the Linux 6.12 two-argument `early_init_dt_verify()` API with the flat-tree virtual address and `__pa()` physical address. The v1.9.2 stable patch context and all production DTS, NOR, firewall and RJ45 behavior remain unchanged.


## v1.9.2 patch-999 context hotfix

See `RV220W-V1.9.2-PATCH999-CONTEXT-HOTFIX.md`. This release changes only the textual context used to apply patch 999 after OpenWrt patch 400; the v1.9.1 production DTS, NOR/FDT cleanup semantics, firewall policy and full-RJ45 topology are unchanged.


## Current promotion status

The v1.3.2 board profile remains the hardware-proven UART and read-only NOR/MTD baseline. LAN1-LAN4 are proven through BCM53115 CPU port 8 and Octeon `eth0`, including full 1500-byte IPv4 frames. Run9 proves WAN port 0 and CPU port 5 communicate when ordinary VLAN classification is consistent. Toolkit v1.9.0 converts that discovery into generic B53 patch 998 and prepares the first RAM-only full-RJ45 routed/firewalled candidate.

## Promotion rule

Each stage must produce reproducible evidence and a rollback path before the next stage begins. Earlier promotion stages remain read-only. The v1.10.0 NOR stage is the first explicit exception and is limited to the guarded 22 MiB `openwrt-slot`; a successful serial shell alone is never permission to write.

## P0 — preserved stock baseline — complete

Required evidence:

- two independent 32 MiB UART reads,
- matching target-before, target-after, and host CRC32,
- matching full-image SHA-256,
- physical partition extraction,
- preserved bootloader and final U-Boot environment sector,
- sensitive JFFS2 data stored privately.

Current result: complete.  The preserved SHA-256 is:

```text
03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
```

## P1 — reproducible CachyOS build environment

Deliverables:

- minimal CachyOS host packages,
- Ubuntu 24.04 Distrobox,
- shared-home source workspace,
- pinned OpenWrt release checkout,
- separate Linux stable reference checkout,
- Gadorach `meraki-builder` reference checkout,
- source commit lock file,
- build logs and expanded OpenWrt configs.

Gate:

- `./rv220w.fish setup-box` succeeds twice without manual package repair;
- `prepare-sources` is idempotent;
- generic Octeon toolchain and kernel compile cleanly.

## P1.5 — known-stock TFTP transport proof

Use the recovered stock kernel ELF to prove the complete U-Boot TFTP path before changing kernels. This distinguishes transport, jack selection, and `octeth` problems from OpenWrt platform problems.

Gate: the stock ELF is transferred with an exact byte-count match and reaches its normal serial boot while loading from RAM.

## P2 — generic Octeon initramfs serial boot

Goal: prove that current OpenWrt's Octeon kernel executes on CN5010 and reaches a shell without any RV220W-specific flash or switch configuration.

Image properties:

- ELF64, big-endian MIPS,
- embedded initramfs,
- serial-first configuration,
- no LuCI,
- no assumed Ethernet port map,
- no persistent overlay,
- no flash-writing helper.

TFTP load address starts at `0x05500000`.  The build and boot helpers reject images whose source buffer would cross the conservative end of usable RAM at `0x07f00000`.

Evidence to collect:

```sh
cat /proc/cpuinfo
cat /proc/cmdline
cat /proc/iomem
cat /proc/interrupts
cat /proc/mtd 2>/dev/null
cat /sys/firmware/devicetree/base/model 2>/dev/null
find /sys/firmware/devicetree/base -maxdepth 3 -type f -print
lspci -nn 2>/dev/null
ip -details link
```

Gate: repeatable cold TFTP boot to an interactive serial shell.

## P3 — runtime board identity and device-tree evidence

Use the generic boot plus stock firmware/kernel analysis to resolve:

- the board type passed by U-Boot/CVMX bootinfo,
- exact RAM range reserved by firmware,
- UART node,
- PCI host node and BCM4322 enumeration,
- BootBus CS window and timing,
- NOR data width and CFI geometry,
- Octeon GMX/RGMII interface numbers,
- MDIO controller and switch address,
- MAC-address source,
- button/LED GPIOs.

The supplied `cn5010_cisco_rv220w.dts.todo` contains only known top-level facts.  It must not be installed until these details are supported by runtime or static evidence.

Gate: an RV220W-specific DTS boots at least as reliably as the generic image and does not expose writable NOR by default.

## P4 — read-only BootBus NOR under modern Linux

Goal: enumerate and read the NOR without allowing writes.

Initial partition policy:

- preserve the complete 512 KiB boot chain,
- preserve the final 128 KiB actual environment/footer sector,
- mark every MTD partition read-only,
- do not reproduce the misleading stock `bootload-env` label at `0x01780000` as the real environment.

Gate:

- modern kernel full-flash SHA-256 equals the preserved UART dump;
- two reads through Linux MTD match;
- no erase/write ioctls are available in the validation image.

## P5 — native Octeon Ethernet and passive switch topology — complete

Hardware evidence resolves:

- `eth0` as the LAN switch conduit;
- `eth1` as the WAN switch conduit;
- `eth2` as unused on the populated product, with a strong board-level inference tying it to the unpopulated optional RJ45 footprint;
- switch port 0 as WAN, ports 1–4 as LAN1–LAN4, port 5 as the WAN CPU conduit and port 8 as the LAN CPU conduit.

The selector-only passive B53 scanner restored management selectors after every run and performed no switch-data writes.

## P6 — BCM53115 switch promotion — direct wired data paths complete

The upstream B53/DSA implementation owns the switch in RAM. The validated topology is:

```text
BCM53115 ports 1-4 -> CPU port 8 -> Octeon eth0 -> Linux DSA -> br-lan
BCM53115 port 0    -> CPU port 5 -> Octeon eth1 -> Linux DSA -> wan
```

All four LAN ports negotiate 1000/full and pass bidirectional minimum/full-MTU traffic. The external WAN PHY, DSA user port, both CPU links, and Broadcom tagging are proven. `rgmii-rxid` is the working timing on ports 5 and 8.

Run9 identified the final blocker: BCM53115's static `enabled_ports=0x11f` excludes alternate CPU port 5, so generic B53 default-PVID/VLAN setup skipped a CPU conduit that the device tree legitimately described. Port-based VLAN masks were correct, but ordinary VID-0 membership omitted port 5. A port-5 PVID-only change failed; explicit VID-0 and VID-1 `{0,5}` domains both passed and restoring the original table restored failure.

Toolkit v1.9.0 adds generic patch 998 to merge firmware-described DSA CPU ports into the B53 active-port mask before configuration. Hardware PVLAN isolation remains:

```text
WAN: {0,5}
LAN: {1,2,3,4,8}
```

Result: v1.9.0 booted with no userspace MDIO repair, and the operator informally confirmed all five RJ45 ports plus LAN DHCP. The complete packet/counter acceptance bundle was not retained.

## P6.5 — first complete wired OpenWrt router candidate

The `rj45-full` profile adds normal OpenWrt software policy above the proven switch topology:

- LAN1-LAN4 in `br-lan` at `192.168.240.2/24`;
- DHCPv4 and IPv6 service on LAN;
- DHCP/DHCPv6 clients on WAN;
- firewall4 LAN/WAN zones;
- LAN-to-WAN forwarding and masquerading;
- WAN-to-LAN forwarding rejected;
- PPP and PPPoE packages available;
- no LuCI, WLAN, or flash-write automation.

Gate: WAN receives an upstream lease, LAN clients receive leases, routed/NAT traffic passes, direct WAN-to-LAN Layer-2 traffic remains impossible, firewall policy blocks unsolicited forwarding, and tagged `wan.<VID>` operation does not disturb the hidden default B53 transport domain.

## P7 — reset button, LEDs, and board services

Map SW2/reset behavior and LED GPIO polarity using stock modules and runtime probing.  Add:

- `gpio-keys` reset button,
- status LEDs,
- watchdog only after its timeout and reset semantics are understood.

Gate: button and LEDs behave predictably with no unexpected factory erase.

## P8 — RAM-only SquashFS live validation

The toolkit's `squashfs-live` mode builds:

1. a minimal OpenWrt SquashFS root,
2. a small initramfs launcher,
3. an ELF embedding the SquashFS,
4. a tmpfs-backed writable overlay.

This validates the final filesystem type and userspace in RAM.  It is not a flash layout test.

Gate:

- SquashFS mounts successfully,
- `/` reports overlay with SquashFS lowerdir,
- reboot returns to untouched stock firmware,
- complete NOR hash remains unchanged.

## P9 — persistent image design — active P9B gate

### Approved full-NOR layout

```text
0x00000000 +0x00080000  boot-chain       read-only
0x00080000 +0x00600000  openwrt-kernel   guarded writes
0x00680000 +0x01960000  rootfs           SquashFS + automatic rootfs_data
0x01fe0000 +0x00020000  uboot-env        read-only
```

The complete original 32 MiB dump preserves the former Cisco JFFS2 data area.
OpenWrt has no dependency on it, so v1.12.0 reclaims it with the blank gap and
tail.

### P9A — rootfs-first component and mount validation — complete

Hardware evidence established:

1. the non-initramfs ELF loads and executes through `bootoctlinux`;
2. before rootfs was written, failure occurred only at the expected SquashFS
   root mount;
3. the RAM writer booted and exposed only approved writes;
4. rootfs write/readback verification passed;
5. SquashFS mounted as `/rom`;
6. OpenWrt initialized and mounted JFFS2 as `/overlay`;
7. hostname and marker persisted across reboot and another TFTP kernel boot.

That gate also exposed the duplicate explicit/automatic `rootfs_data` naming,
which v1.12.0 removes.

### P9B — full-NOR reclaimed-rootfs transition — active

1. Install platform v1.6.0 and rebuild persistent plus writer profiles.
2. RAM-boot the v1.12.0 writer.
3. Back up the 6 MiB kernel and full 25.375 MiB rootfs region.
4. Write the full padded rootfs with complete readback verification.
5. TFTP-boot the rebuilt persistent kernel.
6. Require exactly one automatic `rootfs_data` child and about 21.375 MiB with
   the current SquashFS.
7. Repeat the persistence test.
8. Validate the padded gzip kernel through the exact U-Boot copy/gunzip path.
9. Stop for review before writing kernel or changing environment.

### P9C — kernel and automatic boot

After P9B passes:

1. write and verify the 6 MiB kernel partition;
2. install a manifest-derived `openwrt_boot` command;
3. retain the physical recovery-button path and RAM writer;
4. test cold boot, interrupted boot, and recovery.

## P10 — sysupgrade and recovery qualification

Implement only after full-NOR cold-boot validation:

- target-specific image checking;
- atomic kernel/rootfs update sequencing;
- configuration retention;
- interrupted-write recovery;
- factory reset and overlay reinitialization;
- restoration from the full flash dump and component backups.

## P11 — WLAN

BCM4322 remains deferred until persistent storage and recovery are qualified.

## Current active stage — v1.12.0 P9B full-NOR rootfs transition
