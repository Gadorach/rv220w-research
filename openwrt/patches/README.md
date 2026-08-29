# Minimal active RV220W patch set

The release build has four active logical patch groups. Historical intermediate patches, experiments and diagnostic-only changes are retained under `history/` and are not installed into the release worktree.

## `openwrt/0001-rv220w-platform.patch`

OpenWrt integration only:

- board detection and standard `lan1`-`lan4` / `wan` defaults;
- persistent full-NOR device definitions;
- DTB-appended Octeon kernel image generation;
- persistent-layout initramfs writer target and sysupgrade target.

The release form does not force verbose kernel logging and does not expose the old discovery/flash-stage image profiles.

## `kernel/generic/900-rv220w-ssb-sprom.patch`

One generic SSB change in `drivers/ssb/pci.c`: performs the hardware-qualified paired 16-bit SPROM read sequence and retains the second value. This is required for the BCM4322 physical SPROM on the RV220W PCI path.

## `kernel/octeon/900-rv220w-octeon-platform.patch`

Board-specific Octeon platform and DSA support consolidated from the qualified kernel series:

- prevents Ubiquiti-specific DT pruning on unrelated Octeon boards;
- builds the RV220W DTS;
- maps BCM4322 slot-3 INTA to physical Octeon PCI INT0/IRQ109;
- keeps the PCI IRQ mapping callback available for the device lifetime;
- attaches OF nodes to Octeon Ethernet devices for DSA;
- accepts DSA-tagged short receive frames on the Octeon conduit;
- contains the qualified BCM53115/B53 conduit behavior;
- contains the RV220W BootBus/NOR platform support needed by the final DTS and sysupgrade layout.

## `mac80211/brcm/900-rv220w-b43.patch`

The remaining BCM4322/b43 device support:

- derives the permanent WLAN MAC from the board MTD source when configured by the release overlay;
- retains the hardware-qualified rev4 N-PHY RX-IQ/RCCAL implementation and normal startup integration required for reliable operation on this card;
- retains old diagnostic source under `#if B43_DEBUG` only where it is intertwined with the qualified calibration implementation.

Both release profiles explicitly disable `B43_DEBUG`, so the historical debugfs/telemetry surface is not part of the runtime production configuration. Standalone diagnostic packages and collection tools are moved to `history/debug-tools/`.

The superseded debug-only RX-IQ verification patch and research scaffolding are under `history/debug-tools/` and `history/research/` respectively.

## Release status

These four groups are the complete active RV220W patch surface for `1.16.0-rc7`. The final RC7 build/install workflow completed hardware qualification; no promotion/debug-only patch group is required by the release image.
