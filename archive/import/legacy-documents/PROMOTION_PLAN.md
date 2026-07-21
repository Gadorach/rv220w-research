# RV220W OpenWrt promotion plan

## Promotion rule

Each stage must produce reproducible evidence and a rollback path before the next stage begins.  Flash remains read-only through the entire validation sequence.  A successful serial shell is not permission to flash.

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

## P5 — native Octeon Ethernet without switch assumptions

Identify which of `octeth0`, `octeth1`, and `octeth2` corresponds to each GMX/RGMII interface and whether any port is directly accessible without BCM53115 configuration.

Collect:

- PHY/MDIO scans,
- link state while moving one known cable among jacks,
- packet counters,
- RGMII clock and delay behavior,
- stock module register traces where needed.

Gate: one reliable wired management path in RAM-only OpenWrt.

## P6 — BCM53115 switch promotion

The stock stack uses an Octeon Ethernet driver, an MII wrapper, and a module named `bcm5398.ko` that contains BCM53115-specific operations.  Reconstruct the minimal sequence for:

- pseudo-PHY/MDIO access,
- switch reset and managed mode,
- IMP/CPU port selection,
- RGMII delays,
- port enable/state,
- VLAN membership,
- Broadcom tag or an initial VLAN-based untagged CPU path.

Prefer the upstream Linux B53/DSA implementation.  Add the narrowest board-specific fix needed rather than porting Cisco's TeamF1 control plane.

Gate: two physical ports exchange traffic through DSA and OpenWrt obtains/configures an address normally.

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

## P9 — persistent image design

Only after P0–P8:

- define a recovery-preserving partition layout,
- keep the stock boot chain and final environment sector untouched,
- decide whether to use the existing application area or a dual-image scheme,
- implement image metadata and model compatibility checks,
- create read-back verification before reboot.

The first persistent write should target an otherwise unused erase sector, not overwrite the stock kernel/rootfs.

## P10 — installation and recovery qualification

Before offering a flash installer:

- prove TFTP recovery from U-Boot,
- prove full restoration of the original dump,
- test interrupted writes,
- confirm power-loss behavior,
- test on a second RV220W if available,
- create a serial-guided restore script.

## P11 — WLAN

The removable Mini PCI BCM4322 card is PCI ID `14e4:432b`.  Initial OpenWrt promotion should omit WLAN.  Later choices:

- investigate `b43` with separately supplied firmware and limited 802.11n support,
- or replace the removable card with a well-supported ath9k Mini PCI device.

WLAN is not allowed to block wired OpenWrt promotion.
