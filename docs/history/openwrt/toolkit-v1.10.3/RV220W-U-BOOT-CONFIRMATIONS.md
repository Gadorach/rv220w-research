# U-Boot confirmations used by the RV220W platform update

The complete 512 KiB boot chain was imported as raw big-endian MIPS64 at its linked boot alias, `0xffffffffbfc00000`. The U-Boot application region starts at `0xffffffffbfc30000`; the physical x16 NOR read/write alias used by board code is `0xffffffffbdc00000`.

## High-confidence board facts

| Finding | Reconstructed behavior | DT/build treatment |
|---|---|---|
| Board identity | The image retains `CVMX_BOARD_TYPE_CUST_RV200W`. | Root model/compatible set to Cisco RV220W. |
| Reset/recovery button | Late board init configures GPIO 1 as input, reads GPIO 1, prints `PUSH_BUTTON`, and enters recovery when the value is zero. | GPIO 1 active-low key is represented but disabled for the first Linux-controlled test. |
| Base MAC | Six bytes are copied from physical `0xbdc6ff00`, flash offset `0x6ff00`, and rejected when all-zero or all-`ff`. | Location documented; first profile continues relying on bootloader/kernel MAC fixup behavior rather than introducing an untested NVMEM binding. |
| BCM53115 management | Pseudo-PHY MDIO address is `0x1e`; page selector is reg `0x10`, operation/address is reg `0x11`, and data is regs `0x18`–`0x1b`. | Disabled `brcm,bcm53115` node at MDIO `0x1e`. |
| Switch enable path | Board function writes page 0, registers 1–4; the logged `enable 53115` path writes `0x20`, and the disable path writes zero. | Linux switch management remains disabled to preserve the known-working U-Boot state. The bit is not assigned a speculative semantic name. |
| MDIO controller | Clause-22 operations use the Octeon SMI controller CSR block at `0x1180000001800`. | Enables `smi0`. |
| NOR access | Board code uses AMD/Macronix command sequences through the `0xbdc00000` alias and probes the known device IDs. | DT BootBus programming remains disabled; validated legacy `phys_mapped_flash` remains in use with read-only partitions. |
| Diagnostic surface | U-Boot exposes direct `gpio`, `mii`, and `bcmmii` commands. | Preserved as a recovery/research path; the OpenWrt update performs none of these writes. |

## Cross-confirmation with stock modules

The stock `mii.ko` and `bcm5398.ko` independently implement the same BCM pseudo-PHY address and page/command/data register protocol. `cavium-ethernet.ko` implements Broadcom CPU-tag handling. These matches substantially increase confidence in the MDIO/switch-management portion of the reconstructed platform description.

The exact BCM53115 internal WAN/LAN/IMP port map is not promoted. The switch module contains variant-dependent values and the working front-panel LED map proves that U-Boot configured the switch correctly, but it does not yet establish the Linux DSA port numbering unambiguously.
