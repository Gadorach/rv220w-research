# D-Link Cavium multiversion findings — v1.4

## Scope

Eleven DSR/DWC GPL packages were enumerated and selectively expanded. The scan
covered archive paths, nested archives, Octeon SDK/executive sources, board
helpers, BSP patches, kernel entry code and packaged toolchains. Donor source is
not redistributed; the report records names, hashes, member counts and derived
facts.

## New findings

1. **No complete U-Boot source was released.** No cohesive `u-boot` tree,
   `bootoctlinux` implementation or `cmd_bootoct` source was found. SDK files
   refer to an external `../../bootloader/u-boot` tree, confirming that it was
   omitted rather than hidden elsewhere in these packages.
2. **The exact D-Link private board IDs are now known:** DSR1000N `20006`,
   DSR500N `20013`, DSR500 `20015`, DSR1000 `20016`, DWC1000 `20017`.
   No numeric `CUST_RV200W` ID was found; assigning one would be speculation.
3. **The hardware topology is consistent across donors:** Octeon IPD ports 0
   and 1 terminate at the BCM53115 without external PHY addresses; port 2 uses
   a Broadcom B5081 at MDIO address 8; interface 0 exposes three RGMII ports;
   ports 0 and 1 are represented as fixed 1000/full links.
4. **The shared TeamF1 lineage explicitly names RV200W/RV220W.** Early DSR and
   DWC kernel trees contain `CONFIG_OCTEON_RV200W` next to a comment explaining
   an RV220W-specific SSLVPN redirect exception. This is direct source-lineage
   evidence, not a board-ID inference.
5. **Generic CN50XX RGMII clock writes were intentionally removed.** D-Link's
   SDK patch removes the generic ASXX TX/RX clock value `16`. A replacement
   loader must preserve or audit late-stage initialized skew and must not
   blindly apply the SDK default. This agrees with the hardware-proven
   `rgmii-rxid` treatment in modern OpenWrt.
6. **The exact application boot ABI is now reconstructed.** The packaged SDK
   1.7.3/264 toolchain defines descriptor version 6, the 400-byte boot
   descriptor, the 152-byte `cvmx_bootinfo` v1.2 layout and the Linux entry
   register contract.
7. **A vendor-loader ELF restriction is explicit.** The D-Link Cavium kernel
   patch says this U-Boot lineage cannot handle a non-empty NOTES program
   header. Builds disable linker build IDs. v1.4 therefore validates and
   rejects non-empty `PT_NOTE` before calling the vendor loader.

## Unchanged conclusions

The forced `bootcmd` restoration still resolves to the late board-init tail
call at combined boot-chain offset `0x13168`. No donor source contradicts the
one-instruction `jr t9` to `jr ra` suppression candidate. It remains an offline,
hash-gated artifact and has not been written to hardware.

The RAM stage2 monitor remains the preferred development boundary. It does not
write NOR, environment, GPIO, MDIO or CSRs.
