# Upstream references

## v1.9.3 FDT verification API hotfix

See `RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md`. Patch 999 now calls the Linux 6.12 two-argument `early_init_dt_verify()` API with the flat-tree virtual address and `__pa()` physical address. The v1.9.2 stable patch context and all production DTS, NOR, firewall and RJ45 behavior remain unchanged.


## v1.9.2 patch-999 context hotfix

See `RV220W-V1.9.2-PATCH999-CONTEXT-HOTFIX.md`. This release changes only the textual context used to apply patch 999 after OpenWrt patch 400; the v1.9.1 production DTS, NOR/FDT cleanup semantics, firewall policy and full-RJ45 topology are unchanged.


The toolkit defaults are grounded in these upstream projects:

- OpenWrt source: `https://github.com/openwrt/openwrt.git`
- OpenWrt build documentation: `https://openwrt.org/docs/guide-developer/toolchain/use-buildsystem`
- OpenWrt feeds documentation: `https://openwrt.org/docs/guide-developer/feeds`
- OpenWrt 25.12.5 Octeon artifacts: `https://downloads.openwrt.org/releases/25.12.5/targets/octeon/generic/`
- Linux stable source: `https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git`
- Gadorach meraki-builder reference: `https://github.com/Gadorach/meraki-builder.git`, branch `ms42p-dev`
- Distrobox: `https://github.com/89luca89/distrobox`

The Gadorach repository is cloned as a workflow reference only. No Meraki-specific board implementation is applied to the RV220W.

## DSA and B53 references used for the dual-conduit stage

- Linux DSA configuration documentation: multiple CPU ports, conduit selection and the `ip link ... type dsa master ...` userspace operation.
- Linux `net/dsa/dsa.c`: CPU-port/master netdev resolution and switch registration.
- Linux `drivers/net/dsa/b53/b53_common.c`: BCM53115 detection, CPU-port enablement, port setup and conduit-aware user-port configuration.
- Linux `drivers/net/dsa/b53/b53_mdio.c`: selector-based pseudo-PHY management access.
- Linux `net/dsa/tag_brcm.c`: Broadcom tag insertion/removal and tagged minimum-frame behavior.
- Linux `drivers/staging/octeon/ethernet.c` and `ethernet-rx.c`: legacy Octeon netdev creation and PIP receive-error handling.

The v1.8.0 stage uses standard DSA rtnetlink affinity rather than an RV220W-specific register workaround. Linux DSA requires a switch driver to implement `port_change_conduit` before userspace can move a user port between CPU conduits. The included generic B53 patch supplies that callback and rebuilds B53 port-based VLAN conduit membership from DSA's existing user-to-CPU-port assignments. It contains no RV220W/BCM53115 implementation policy, preserves the original single-CPU path, and does not modify OpenWrt core.


## B53 default-VLAN root cause used for v1.9.0

The v1.9.0 correction follows existing Linux B53 structure rather than adding
board-specific VLAN policy:

- `b53_configure_vlan()` applies the internal default PVID/VLAN state by
  iterating B53's active/enabled-port mask.
- BCM53115's static chip description covers external ports 0-4 and the usual
  IMP at port 8, but not the alternate CPU-capable port 5 used by the RV220W.
- DSA has already parsed firmware CPU-port descriptions when `b53_setup()`
  runs. Patch 998 merges `dsa_cpu_ports(ds)` into `dev->enabled_ports` before
  reset/configuration, allowing the existing generic loop to initialize every
  active CPU conduit.
- User-configured provider VLANs remain ordinary Linux/OpenWrt devices above
  the DSA `wan` interface; the hidden default VID is not exposed as fixed board
  policy.

Relevant upstream files:

- Linux `drivers/net/dsa/b53/b53_common.c`: `b53_setup()`,
  `b53_configure_vlan()`, device tables and active-port iteration.
- Linux `drivers/net/dsa/b53/b53_priv.h`: B53 device/port state and enabled-port
  iteration helpers.
- Linux `include/net/dsa.h`: DSA CPU-port masks and parsed topology.


## v1.9.1 production cleanup

See `RV220W-V1.9.1-PRODUCTION-CLEANUP.md`. The full-RJ45 production profile uses fixed internal MAC links, explicit Octeon BootBus flash ownership, refreshed post-fixup FDT verification, no out-of-tree MDIO module, strict default WAN isolation, and standard read-only status collection.
