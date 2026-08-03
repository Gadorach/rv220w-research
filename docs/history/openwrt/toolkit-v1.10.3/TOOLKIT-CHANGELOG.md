# Changelog

## 1.10.3

- Record the successful verified 22 MiB NOR write and the failed direct-flash
  `bootoct` experiment.
- Correct the boot method: copy the exact Linux ELF from memory-mapped NOR to
  the proven `0x05500000` RAM staging address, then run `bootoctlinux`.
- Add `./rv220w.fish nor-stage boot-plan`, derived from `source_size` in the
  slot manifest and compatible with existing v1.10.0/v1.10.2 artifacts.
- Update generated manifests with RAM-copy metadata and explicit rejection of
  direct Octeon Executive execution.
- No image rebuild, NOR rewrite, U-Boot environment change, or kernel/platform
  change is required.

## 1.10.2 — 2026-07-28

- Records successful build and TFTP/RAM boot of the dedicated v1.10.1 NOR-writer image with the expected single writable 22 MiB `openwrt-slot`.
- Fixes the actual host-side write/restore transfer: OpenSSH 9+ `scp` defaulted to SFTP, but the intentionally minimal Dropbear image has no `/usr/libexec/sftp-server`.
- Replaces `scp` with byte-exact `cat | ssh` streaming into a private `/tmp` partial file followed by an atomic rename.
- Checks both sides of the Fish pipeline and removes partial/remote images on transfer or writer failure.
- Isolates expected per-boot Dropbear host keys from the user's persistent `known_hosts`, while disabling PTY allocation for binary streams.
- Preserves the mandatory pre-write backup, local manifest/SHA-256 validation, target-side exact-size/hash/ELF validation, slot-only MTD write, complete read-back SHA-256, separate restore token, and no-reboot/no-saveenv policy.
- Confirms the two captured 22 MiB pre-write backups are byte-identical with SHA-256 `47b546d826e9016d3fa0a8e08356e1ba614cba7290d11eba79a6bd80e0671c6d`.
- No NOR erase or write occurred in the failed v1.10.1 attempt. This hotfix is host-side only; the already running v1.10.1 writer image can be reused.

## 1.10.1 — 2026-07-28

- Records the successful v1.10.0 LuCI build and TFTP/RAM boot. The generated
  ELF is 18,179,536 bytes and the padded NOR-slot artifact is exactly 22 MiB.
- Fixes `verify_nor_writer_config()`: the dedicated writer is intentionally
  LuCI-free, so it now validates the proven RJ45 base rather than requiring
  `luci-light` and uHTTPd.
- Requires the writer-specific `mtd` package and
  `cisco_rv220w_flash_stage` target after `defconfig`.
- Explicitly rejects accidental selection of the normal RV220W target or
  LuCI/uHTTPd packages in the writer image.
- Removes the misleading `+ LuCI` text from the NOR-writer banner.
- Changes no kernel patch, DTS, OpenWrt platform integration, partition map,
  writer command, confirmation token, boot command, or flash-write policy.

## 1.10.0 — 2026-07-28

- Freeze v1.9.3 as the validated five-RJ45 RAM baseline.
- Add `rj45-luci` with `luci-light`/uHTTPd bound to `192.168.240.2:80` on LAN only.
- Add OpenWrt platform integration v1.4.0 with a normal all-read-only RV220W target and a separate RAM-boot `cisco_rv220w_flash_stage` target.
- The writer target exposes only a 22 MiB `openwrt-slot`; boot chain, stock-data, legacy gap, vendor tail and U-Boot environment remain read-only.
- Add an exact-size 22 MiB `0xff`-padded NOR-slot artifact builder and JSON/SHA-256 manifest.
- Add a dedicated non-LuCI target `rv220w-nor-stage` and host `nor-stage` workflow with exact board/profile/MTD geometry checks, mandatory backup, separate write/restore confirmation tokens, local SHA-256 validation and full post-write read-back verification.
- Originally proposed direct `bootoct` first boot; hardware testing later proved this invalid for the Linux ELF and v1.10.3 supersedes it with NOR-to-RAM copy plus `bootoctlinux`.
- Correct NAND terminology: the RV220W uses 32 MiB x16 parallel CFI NOR.
- Make `collect-conduit` skip absent production MDIO diagnostics cleanly unless `--require-b53`.
- Preflight B53 MDIO support before UART upload and retrieve target failure reports when available.
- Add `collect-rj45` production-safe acceptance collection without raw MDIO.
- Delete stale serial-fallback build logs before each build and stamp current logs with build metadata.
- Document the secondary-IMP counter-accounting limitation: DSA `wan` and end-to-end traffic are authoritative when Octeon `eth1` RX/B53 port-5 Tx remain zero.
- Preserve run12 v1.9.3 DSA evidence and record passed WAN isolation.

## 1.9.3 - 2026-07-28

- Fix patch 999 for the Linux 6.12 `early_init_dt_verify(void *, phys_addr_t)` API.
- Pass `initial_boot_params` and `__pa(initial_boot_params)` after Octeon FDT fixups.
- Add an API-arity regression test that applies the patch and compiles a minimal Linux-shaped fixture.
- Preserve the v1.9.2 stable patch context, production DTS, BootBus NOR ownership, full-RJ45 topology, firewall policy and RAM-only operation unchanged.
- Archive the operator-provided v1.9.2 compile-failure logs.

## 1.9.2 - 2026-07-28

- Correct patch 999 so its `setup.c` hunk applies after OpenWrt's earlier `400-ubnt_dts_pruning.patch`.
- Restrict the FDT-CRC hunk context to the stable `octeon_fill_mac_addresses()` / `unflatten_and_copy_device_tree()` tail.
- Restrict the BootBus match-table hunk context to the stable `of_flash_match[]` declaration, eliminating the observed fuzz dependency.
- Add a realistic post-OpenWrt-patch fixture test and reject reintroduction of the conflicting prune-block context.
- Preserve the v1.9.1 production DTS, BootBus NOR ownership, fixed MAC links, firewall policy, five-port DSA topology and RAM-only policy unchanged.

## 1.9.1 - 2026-07-27

- Added a dedicated production full-RJ45 DTS with fixed Octeon MAC links.
- Added patch 999 to refresh the post-fixup FDT CRC and give the Octeon
  BootBus flash driver an explicit compatible.
- Retained the NOR trigger node while eliminating the intentionally failing
  generic physmap probe.
- Removed MDIO-netlink and raw switch-register tooling from the production
  image; diagnostic profiles remain unchanged.
- Corrected firewall status reporting, removed default IPsec WAN-to-LAN
  exceptions, bound Dropbear to LAN, and expanded standard status output.
- Recorded the user's informal confirmation that all five RJ45 ports and LAN
  DHCP worked on the v1.9.0 hardware boot.

## 1.9.0 — 2026-07-27

- Preserved the complete run9 DSA and B53 evidence proving that the failed `wan@eth1` state used PVID 0 on port 0 while CPU port 5 was absent from the selected VLAN table entry.
- Recorded that changing only port 5's PVID did not restore traffic, while explicit VID-0 and VID-1 port-0/5 domains both restored ordinary and full-MTU ICMP; restoring the original table restored the failure.
- Added generic kernel patch `998-b53-enable-dt-cpu-ports.patch`, which merges firmware-described DSA CPU ports into B53's active-port mask before default PVID/VLAN configuration.
- Added the `rj45-full` / `rv220w-rj45-initramfs` build mode and artifact `rv220w-openwrt-rv220w-rj45-initramfs.elf`.
- Added a complete wired OpenWrt policy: LAN1-LAN4 bridge, LAN DHCP/IPv6 service, WAN DHCP/DHCPv6, firewall4 zone isolation, LAN-to-WAN forwarding/NAT, and PPPoE packages.
- Retained the proven 192.168.240.0/24 RAM/TFTP lab subnet, dual `rgmii-rxid` timing, Octeon DSA RX correction, conduit affinity, and RAM-only/no-flash policy.
- Added `rv220w-rj45-status`, full-RJ45 documentation, run9 evidence, patch-application tests, network/firewall profile tests, and updater rollback for patch 998.

# v1.8.4 — 2026-07-26

- Records run8 proof that changing WAN port 0 from SIMPLIFIED to BASIC EAP mode does not restore ARP or ICMP through CPU port 5/`eth1`.
- Adds direct readback of generic BCM53115 VLAN-table entries 0 and 1 plus decoded member and untag masks.
- Adds a reversible RAM-only `b53-vlan` controller for the port-5 PVID-only test, an explicit VLAN-0 WAN domain, an explicit vendor-style VLAN-1 WAN domain, and exact restoration.
- Requires live `wan@eth1`, saves original PVID/VLAN state in `/tmp`, verifies readback and restores pseudo-PHY selectors.
- Makes no kernel, DTS, PVLAN, EAP, RGMII, bridge, firewall or flash change.

# v1.8.3 — 2026-07-26

- Records run7 proof that failed `wan@eth1` already has the correct `0x0021` port-0/port-5 PVLAN domain, both Broadcom-tag ports enabled, and `0xc2` dual-IMP management selection.
- Records that working `wan@eth0` changes only the expected port-0 and port-8 PVLAN masks, clearing the v1.8.0 conduit-affinity callback as the remaining blocker.
- Extends passive B53 reports with raw 64-bit EAP configuration and decoded BASIC/SIMPLIFIED mode for every port.
- Adds a reversible RAM-only `b53-eap` UART action that changes only EAP mode bits 52:51, preserves all other bits, refuses CPU-port writes, saves the original value in `/tmp`, verifies readback and restores selectors.
- Makes no DTS, timing, PVLAN, Broadcom-header, network-policy or flash change; this stage tests the Linux 6.12 standalone-port simplified EAP behavior before adding a kernel workaround.

# v1.8.2 — 2026-07-26

- Records the hardware result that WAN works through CPU port 8/`eth0` but remains one-way through CPU port 5/`eth1`, even after a real conduit transition and `ifdown`/`ifup` reopen.
- Extends the selector-only B53 scanner with focused port-0/5/8 control and PVLAN readback plus a live conduit consistency check.
- Adds `collect-conduit` to capture paired DSA and raw B53 reports.
- Adds `compare-b53` to diff focused switch state and decode PVLAN masks as switch-port bit sets.
- Includes the read-only B53 helper in future dual-conduit images, while retaining UART fallback upload for the currently booted v1.8.0 image.
- Makes no DTS, RGMII timing, kernel forwarding, network-policy or flash-write change; this stage gathers the evidence needed for the next B53 patch.

# v1.8.1 — 2026-07-26

- Fixes the DSA build sequence that invoked `target/linux/clean` before the seed config had been expanded. OpenWrt's top-level `.config` rule can launch `menuconfig` in that state, producing an orphaned `mconf` process and racing `tmp/info/.files-targetinfo-*` generation.
- Configures and verifies the selected seed before any clean/download/world target.
- Adds an exclusive per-workspace build lock.
- Clears inherited `MAKEFLAGS`/`MFLAGS` for each detached make invocation.
- Rejects interactive Kconfig targets from the noninteractive helper.
- Requires `CONFIG_HAVE_DOT_CONFIG=y` before clean/download/world/kernel compilation.
- Leaves the v1.8.0 dual-conduit DTS, B53 patch, Octeon patches, network policy, and RAM-only safety model unchanged.

# v1.8.0 — 2026-07-26

- Promoted the v1.7.6 LAN result to hardware-proven status: LAN1-LAN4 all negotiate 1000/full and pass DSA traffic; LAN1 passes minimum through full-1500-byte IPv4 frames.
- Added a separate RAM-only dual-conduit DSA profile with BCM53115 port 5/Octeon `eth1` for WAN and proven port 8/`eth0` for LAN.
- Added early standard-DSA rtnetlink affinity assignment so `wan -> eth1` and `lan1-lan4 -> eth0` before netifd raises the interfaces.
- Added a generic B53 `port_change_conduit` implementation which rebuilds port-based VLAN membership from DSA's user-to-CPU-port topology; it contains no RV220W or BCM53115-specific implementation policy and leaves single-CPU behavior unchanged.
- Added isolated WAN address `192.168.241.2/24` with no routing, NAT, DHCP, DNS or firewall policy.
- Added dual-profile build/TFTP aliases, UART evidence collection, conservative stale-DTS recovery for both generated templates, tests and complete stage documentation.
- Preserved OpenWrt core unchanged; the two proven Octeon patches and the generic B53 multi-conduit patch are installed through the normal Octeon target patch set.

## 1.7.6

- Confirmed full BCM53115 DSA registration, `lan1`-`lan4` creation, `br-lan` membership, and LAN1 forwarding with the `rgmii-rxid` candidate.
- Added a generic Octeon-driver receive compatibility patch for PIP error code 10 on active DSA conduit netdevs.
- Retained the existing minimum-frame exception and left non-DSA Octeon receive-error handling unchanged.
- Kept B53 and OpenWrt core unmodified; both DSA compatibility fixes remain standard Octeon target-kernel patches.
- Extended build preflight, updater rollback, and regression tests to verify both persistent kernel patches byte-for-byte.

## 1.7.5

- Prevent automated OpenWrt builds from acquiring the caller's controlling terminal.
- Run every noninteractive `make` operation in a detached `setsid` session with stdin closed.
- Make DSA builds verbose from the first attempt so any unexpected Kconfig invocation is recorded.
- Require an explicit authorization marker for the user-requested `build menuconfig` path.
- Add `setsid`/`util-linux` to build-box provisioning and readiness checks.
- Keep the Octeon-only master-netdev OF-node patch, B53 sources, and OpenWrt core unchanged.

## 1.7.4

- Repair a stale generated LAN-only DSA DTS left by the failed v1.7.2 cleanup path.
- Replace brittle literal model-token verification with structural DTS validation.
- Refuse to overwrite unrecognized local DTS modifications.
- Make toolkit, Octeon patch, and source-DTS installation one rollback-safe transaction.
- Keep the kernel fix confined to the legacy Octeon Ethernet driver; B53 and OpenWrt core remain unchanged.

## 1.7.3

- Replaced the failed combined Octeon/B53 patch with an Octeon-only upstream-oriented netdev OF-node fix.
- Removed the nonessential B53 diagnostic modification.
- Installed the kernel patch persistently in the OpenWrt target patch set instead of injecting it during each build.
- Made DSA DTS cleanup subshell-scoped so build failures cannot trigger an unset-backup error.

# v1.7.2

- Associate legacy Octeon netdevs with their per-port OF nodes during DSA candidate builds.
- Add numeric B53/DSA registration-error logging.
- Remove stale anonymous `br-lan -> eth0` and excluded `wan6` configuration.
- Record netdev and parent OF-node sysfs links in DSA snapshots.
- Preserve and restore the exact pre-build target kernel-patch state.

# v1.7.1 — 2026-07-26

- Confirmed that the v1.7.0 image identified the BCM53115 correctly as revision 8 but deferred during DSA registration.
- Proved that `tag_brcm.ko` was present in the initramfs while `/etc/modules.d/` autoloaded only `b53_common` and `b53_mdio`.
- Added an explicit early `/etc/modules.d/30-tag-brcm` entry so Broadcom tag protocol ID 1 is registered before the B53 MDIO driver probes.
- Expanded DSA snapshots to record tag-module availability and relevant module-autoload files.
- Kept the LAN-only DTS, timing variants, platform v1.3.2 baseline, RAM-only policy, and flash-write prohibition unchanged.

## 1.7.0 - 2026-07-26

- Record the proven dual-conduit BCM53115 topology: WAN port0 ↔ port5 ↔ eth1 and LAN ports1-4 ↔ port8 ↔ eth0.
- Add a separate RAM-only LAN-only B53/DSA ownership-validation build; the hardware-proven v1.3.2 baseline and passive discovery profile remain available.
- Exclude WAN, port5, eth1, eth2, and unused ports6-7 from the first DSA test to avoid unresolved multi-conduit routing.
- Add rxid, txid, and plain-rgmii xMII variants while making rxid the only initially requested test.
- Temporarily substitute the DSA DTS during a build and restore the exact source DTS afterward.
- Add UART-only `collect-dsa` evidence retrieval so failure of the candidate network path cannot hide diagnostics.
- Explicitly disclose that B53/DSA may reset and rewrite volatile switch state; no flash writes are added.

## 1.6.2 - 2026-07-26

- Replace long sentinel-wrapped upload commands with short per-chunk acknowledgement lines.
- Reduce payload chunks to 24 bytes and pace UART writes in 32-byte bursts.
- Keep every upload command at or below 240 bytes to avoid the target ash continuation prompt.
- Make the host regression test portable when CachyOS does not install BusyBox.
- Preserve the selector-only B53 policy, current discovery image, and router flash unchanged.

## 1.6.1 - 2026-07-26

- Replace B53 and MDIO UART uploads with decoder-free BusyBox ash `printf %b` octal chunks.
- Remove the incorrect dependency on the optional target `base64` applet.
- Verify every upload by acknowledged chunks, exact byte count, target shell syntax, and SHA-256 when available.
- Leave the passive B53 register policy, running discovery image, platform integration, and router flash unchanged.

## 1.6.0 - 2026-07-26

- Record the completed external map: PHY0=WAN/eth1 and PHY1-4=LAN1-4/eth0; treat eth2 as an unpopulated optional board interface by strong board-level inference.
- Add `collect-b53`, a UART-only passive BCM53115 topology collector.
- Restrict all indirect-access writes to pseudo-PHY selector registers 0x10 and 0x11; switch data registers remain read only.
- Capture device identity, global status/control, ports 0-8, port-based VLAN membership, default tags, and xMII override/control state.
- Restore the initial pseudo-PHY selector state after collection and retain the v1.3.2 platform and existing discovery image unchanged.

## 1.5.2 - 2026-07-26

- Fix UART framing so sentinel text echoed as part of the submitted ash command cannot be mistaken for target output.
- Require begin, return-code, and end markers to appear as complete normalized UART lines.
- Force the real begin marker onto a fresh line and parse the last complete marker sequence.
- Leave the target MDIO scanner, direct Clause 22 read policy, OpenWrt image, and platform integration unchanged.

## 1.5.1 - 2026-07-26

- Make `collect-mdio` use UART by default so no-cable and WAN measurements do not require a working IP path.
- Add checksum-verified UART upload of the read-only target scanner and sentinel-framed UART report capture.
- Retain SSH only as an explicit `--ssh` compatibility transport.
- Add a separate 115200-baud Linux-console default and fix unavailable carrier reporting on unused `eth2`.
- Record that the successful Stage 4 scans map LAN1-LAN4 to Clause 22 PHY addresses 1-4; NONE and WAN remain the only required UART measurements.

# v1.5.0 — 2026-07-26

- Recorded the hardware-proven physical map: LAN1-LAN4 feed Octeon `eth0`, WAN feeds `eth1`, and `eth2` showed no link or traffic.
- Added `collect-mdio`, a host-side SSH collector for a strictly read-only direct Clause 22 identity/status scan.
- Added the target `rv220w-mdio-scan` helper; it reads BMCR, BMSR twice, and PHY ID registers at addresses 0-31 without supplying any MDIO write value.
- Added a configurable `RV220W_MDIO_BUS`, defaulting to the observed Octeon bus `8001180000001800`.
- Kept the OpenWrt platform integration at hardware-proven v1.3.2 and did not enable DSA, a B53 DT child, indirect page access, switch-register writes, or flash writes.

# Changelog

## 1.4.1 - 2026-07-26

- Fixed discovery collection against Dropbear/OpenWrt targets by replacing modern `scp`/SFTP transfers with plain SSH streaming.
- Isolated expected RAM-boot host keys from the user's persistent `known_hosts`.
- Deduplicated `/dev/serial/by-id/...` and `/dev/ttyUSB*` aliases that resolve to the same FTDI adapter.
- Added `./rv220w.fish version` and clearer platform output to distinguish toolkit v1.4.x from the intentionally unchanged OpenWrt platform integration v1.3.2.
- Added `./rv220w.fish build discovery` as an alias and improved discovery-artifact diagnostics.

# v1.4.0 — 2026-07-26

- Recorded the clean v1.3.2 hardware validation as the new reference baseline.
- Added a separate `rv220w-discovery-initramfs` build mode; the proven `rv220w-initramfs` profile is unchanged.
- Added `ip-full`, `ip-bridge`, `ethtool-full`, `tcpdump-mini`, dormant B53/DSA modules, and MDIO netlink/tools to the discovery profile.
- Added an installed read-only target snapshot tool and a host-side `collect-snapshot` action.
- Added `tftp-boot --profile discovery` without changing no-argument reference-image selection.
- Added package-retention checks so unavailable discovery dependencies fail before a long build.
- Added hardware-validation, discovery-profile, and physical-jack campaign documentation.
- Kept the known redundant generic physmap failure and deprecated legacy link warning unchanged until topology evidence is available.

# v1.3.2 — 2026-07-25

- Restored the exact v1.3.0 enabled `nor@0,0` BootBus child while retaining the v1.3.1 explicit 400 MHz UART clock.
- Preserved all seven command-line NOR partitions as read-only and kept the RV220W profile initramfs-only.
- Added a direct v1.3.1-to-v1.3.2 platform upgrade patch and generalized the installer upgrade chain from v1.2.0 onward.
- Added hard-stop protection when an installer/upgrader is launched from a physical working directory that would be renamed.
- Regenerated the reference DTB with the NOR trigger child retained.
- Added a DTB-repacked RAM-boot candidate derived from pristine v1.3.0/v1.3.1 ELFs after proving their DTBs differ only in the NOR child and UART clock.
- Added constrained ELF64 big-endian DTB-section expansion and byte-for-byte non-DTB section validation.
- Hardware RAM-boot validation remains pending; v1.3.1 is still the last proven ELF.

# v1.3.1 — 2026-07-24

- Hard-coded the verified CN5010 UART clock at 400 MHz; appended DTBs do not receive the legacy Octeon pruning-time clock fixup.
- Kept the BootBus parent enabled while deleting the inherited generic `nor@0,0`, eliminating the erroneous `0x1f400000` physmap probe while preserving the verified legacy `phys_mapped_flash` registration.
- Added a deterministic TFTP host address (`192.168.240.1/24`) even when the selected NIC already has unrelated IPv4 addresses; unrelated addresses are never flushed.
- Rejected identical server/device IP addresses before dnsmasq or U-Boot commands start.
- Added explicit missing-image path diagnostics.
- Added fatal handling for stale U-Boot `Abort` and reserved-load-area warnings, requiring a clean power cycle instead of continuing.
- Added an in-place v1.3.0-to-v1.3.1 platform and toolkit upgrade path.

# v1.3.0 — 2026-07-24

- Added the required `uart0` alias so Octeon early DT fixup supplies the live I/O clock to the DesignWare UART.
- Enabled only the CS0 CFI child of BootBus and removed unrelated generic-board timing, LED-display, and CompactFlash children.
- Kept all command-line NOR partitions read-only and retained RAM-only safety policy.
- Set the initramfs LAN address to `192.168.240.2/24` for deterministic direct-link SSH after TFTP boot.
- Added board-artifact auto-discovery and proven direct-link defaults to the TFTP wrapper.
- Prevented the serial helper from sending Ctrl-C to a running OpenWrt shell while waiting for a real power cycle.
- Added an in-place v1.2.0-to-v1.3.0 source-tree upgrade path.

# v1.2.0 — 2026-07-24

- Replaced the fragile patch-of-patch RV220W integration with a clean OpenWrt platform patch.
- Added automatic platform installation during `prepare-sources`.
- Added the board-specific `rv220w-initramfs` build mode and artifact discovery.
- Added conservative `cn5010_cisco_rv220w.dts` with USB and DT BootBus disabled.
- Added separate UBNT-pruning guard and DTB Makefile kernel patches.
- Included the validated TFTP MTU and RAM-only `netretry=no` fixes.
- Added platform verification and clean-environment installation helpers.

# Changelog

## 1.0.4 — 2026-07-20

- Fixed Ubuntu 24.04 provisioning when the MIPS64 cross-compiler dependency was unavailable because the Universe component was not enabled.
- Added an explicit Ubuntu Universe enablement step using `add-apt-repository -y universe`.
- Split mandatory OpenWrt build prerequisites from the optional system MIPS64 compiler used only by the standalone upstream-Linux reference workflow.
- Prevented an optional cross-compiler packaging failure from blocking `prepare-sources` and OpenWrt builds.
- Added phased provisioning output and separate `doctor` status for the OpenWrt toolset and reference cross compiler.
- Added a clear `build-linux` guard when the optional compiler is unavailable.

## 1.0.3 — 2026-07-20

- Fixed `setup-box --recreate` appearing to hang because v1.0.2 invoked the interactive `distrobox stop` command without `--yes` while redirecting its prompt.
- Replaced the recreate removal path with non-interactive `podman rm --force --time 3 --ignore`, bounded by a 30-second GNU `timeout`.
- Added `setup-box --remove-only` for deterministic cleanup without immediately creating or provisioning a replacement.
- Changed container-existence checks to use Podman directly so `doctor` does not start a container merely to test whether the name exists.
- Added runtime image/status diagnostics to `doctor` to make Distrobox/Toolbx name collisions visible.
- Kept image-pull and provisioning output visible and explicitly distinguished those potentially long operations from bounded container removal.

## 1.0.2 — 2026-07-20

- Added positive validation that the named build container is Ubuntu 24.04 and provides `apt-get`; a reachable but incompatible Distrobox is no longer accepted as ready.
- Added `setup-box --recreate` recovery for a name collision with an existing non-Ubuntu container.
- Switched scripted Distrobox execution to the explicit `distrobox enter --name ... --no-tty -- ...` form and retained a TTY only for menuconfig workflows.
- Added post-provision checks for the compiler suite, the MIPS64 cross compiler, and Perl `FindBin`.
- Made the Ubuntu provisioning helper validate `/etc/os-release`, handle root/sudo consistently, and clean apt state with the correct privileges.
- Prevented `prepare-sources` from running in an incompatible or unprovisioned container.
- Changed new source checkouts to shallow, single-ref clones so the Linux stable tree does not download multi-gigabyte full history when a server ignores partial-clone filtering.
- Added `prepare-sources --reclone-linux` as an explicit disk-recovery option for an already-created full-history Linux checkout.
- Added diagnostics for the exact failure sequence observed on CachyOS.

## 1.0.1 — 2026-07-20

- Fixed Fish 4.x option parsing in `string join` calls by adding the `--` separator.
- Removed Bash heredocs from Fish entry points; container-side Bash programs now ship as static, syntax-checkable helpers under `scripts/inner/`.
- Changed CachyOS host setup to install only genuinely missing packages, avoiding unintended upgrades and stale-mirror 404 failures when dependencies are already present.
- Added an explicit `setup-host --sync-upgrade` recovery path for users who intentionally want a normal CachyOS/Arch full sync and upgrade.
- Added Fish and Bash syntax validation to `doctor` and `verify`.
- Added the MIPS64 big-endian cross compiler to the Ubuntu Distrobox and wired the standalone Linux build to `mips64-linux-gnuabi64-`.
- Added troubleshooting documentation for the v1.0.0 setup failures.

## 1.0.0 — 2026-07-20

- Added CachyOS fish dispatcher and minimal host setup.
- Added Ubuntu 24.04 Distrobox provisioning for complete OpenWrt builds.
- Added pinned source preparation for OpenWrt, upstream Linux, and Gadorach/meraki-builder.
- Integrated the validated read-only U-Boot UART NOR dumper.
- Added verified partition splitting, SquashFS extraction, and big-endian JFFS2 extraction.
- Added minimal generic Octeon initramfs and SquashFS build modes.
- Added RAM-only SquashFS + tmpfs-overlay live-root assembly.
- Added standalone Octeon Linux reference build, marked not-for-boot until board support is proven.
- Added automated dnsmasq TFTP service, host IPv4 discovery, U-Boot interruption, interface attempts, exact transfer-size validation, boot automation, and serial/TFTP logging.
- Added staged OpenWrt promotion and recovery gates.
