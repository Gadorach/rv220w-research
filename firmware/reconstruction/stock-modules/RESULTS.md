# RV220W stock module reverse-engineering results

## Scope

Five stock Linux 2.6.21.7 Cavium/Octeon modules were extracted from the preserved RV220W SquashFS 3.0 big-endian root filesystem and imported into Ghidra 12.1.2 as MIPS64 big-endian relocatable ELFs.

| Module | Functions | Reconstructed C | Failures |
|---|---:|---:|---:|
| `mii.ko` | 4 | 4 | 0 |
| `bcm5398.ko` | 25 | 25 | 0 |
| `scm-led.ko` | 11 | 11 | 0 |
| `push_button.ko` | 7 | 7 | 0 |
| `cavium-ethernet.ko` | 112 | 112 | 0 |
| **Total** | **159** | **159** | **0** |


Every recovered function has an embedded Ghidra comment with subsystem, evidence class, confidence, interpretation, and safety limits. Each function also has standalone reconstructed C and assembly exports. Compiler-emitted `.pdr` records restored 55 otherwise-missing function boundaries; two were named through `mii.ko` export metadata and 53 remain conservatively named local helpers.

## Hardware-relevant findings

### BCM53115 access and WAN policy

- `mii_phy_read()` and `mii_phy_write()` wrap Octeon MDIO bus 0 with bottom-half exclusion.
- `miiSwitchRegisterRead()` and `miiSwitchRegisterWrite()` access Broadcom pseudo-PHY address `0x1e`, using MDIO register `0x10` for page selection, `0x11` for command/address, and `0x18`–`0x1b` as the data window.
- The transaction timeout is based on `jiffies + 0x19`.
- `bcm5398.ko` recognizes switch strings `bcm5398`, `bcm5395`, and `bcm53115`; its module parameters include `wanportNo`, `privlegedID`, and `bcmswitch`.
- The module chooses a default WAN-port number of 8 for one recognized variant and 5 for another. This is strong evidence about internal Broadcom port numbering, but the correct RV220W branch must be tied to the runtime `bcmswitch` value before encoding a DSA port map.
- `configWanPort()` applies special state through switch page 2 registers `0x10`, `0x12`, and `0x1c`.

### Octeon Ethernet and switch tagging

- `cavium-ethernet.ko` contains the vendor MDIO implementation, RGMII initialization, receive tasklet/interrupt path, transmit paths, and Broadcom tag add/delete routines.
- `brcmTagAdd()` and `brcmTagDelete()` confirm the stock CPU/switch path uses a vendor Broadcom tag format.
- Vendor hardware offload/fast-forward code is substantial but is not required for first-stage upstream OpenWrt support.

### LEDs and reset button

- `scm-led.ko` directly drives Octeon GPIO set/clear registers for software-controlled LEDs.
- `blink_wlan()` selects logical LED record 4, making it the leading WIRELESS-indicator path.
- The five RJ45 link/activity indicators are more likely driven by the BCM53115 hardware LED engine, consistent with their correct operation after U-Boot initializes the switch.
- `push_button.ko:set_input()` configures GPIO candidates 5, 6, 11, 12, and 13 through the vendor input helper. This is a candidate set, not a definitive single reset pin.
- The recovered timer callback invokes `led_blink(2,1,1,1)` after a press-duration counter exceeds 100 ticks.

## Limits

This package does not claim original source recovery. Types, structure layouts, indirect-call edges, local names, and some control flow remain uncertain because these are old relocatable MIPS modules with vendor SDK code and incomplete type information. Constants and register interpretations are annotated only where supported by retained names, strings, relocations, or visible operations.
