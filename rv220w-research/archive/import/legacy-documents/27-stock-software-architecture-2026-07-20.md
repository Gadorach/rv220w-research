# Stock software architecture findings — 2026-07-20

## Boot chain

1. A pre-U-Boot boot region occupies the first `0x30000` bytes.
2. U-Boot 1.1.1 occupies `0x30000–0x7ffff`.
3. U-Boot copies `0x580000` bytes from `0xbdc80000` to RAM at `0x02a00000`.
4. `bootoctlinux 0x02a00200` loads the ELF64 big-endian kernel.
5. Linux mounts SquashFS as the immutable platform filesystem and JFFS2 as `/data` configuration storage.

## Kernel and board support

The stock kernel is Linux `2.6.21.7-Cavium-Octeon`, built with Cavium GCC 4.1.2 and a Cavium SDK-derived platform tree. It recognizes custom board type `CVMX_BOARD_TYPE_CUST_RV200W`. The stock boot information reports one active core, 128 MiB RAM, and Octeon interface 0 with three RGMII ports.

Kernel and module symbols show that the vendor stack includes:

- Octeon BootBus parallel NOR support
- Octeon RGMII and MDIO support
- custom board-type and MAC-address handling
- custom Broadcom switch-tag handling in the Octeon Ethernet driver
- platform GPIO LED and push-button modules

## Ethernet and switch path

The key open-source-relevant module chain is:

```text
cavium-ethernet.ko
  exports cvm_oct_mdio_write, TF1_cvm_oct_mdio_read
  exports brcm_miiphy_read/write
  implements optional Broadcom tag add/delete handling

mii.ko
  wraps the Cavium MDIO exports as mii_phy_read/write

bcm5398.ko
  uses mii_phy_read/write
  implements switch register, port and VLAN operations
  contains BCM53115 identification strings
```

`/etc/switchdriverInit` explicitly calls the RV220W device a BCM53115 platform but loads the generic `bcm5398.ko` module using `bcmswitch="bcm5395"`. The module is unstripped and exposes useful symbols including:

- `miiSwitchRegisterRead/Write`
- `bcm5398PortConfigSet/Get`
- `bcm5398PortStateSet`
- `bcm5398VlanEnable/Disable`
- `bcm5398VlanEntrySet/Get`
- `bcm5398PortMirrorSet`

The stock script has a shell typo, `wanportNo= -1`, which explains the boot-time `-1: not found` message.

`/bin/imp_status.sh` documents the old vendor design for enabling a Broadcom CPU/IMP port, including frame-managed mode, in-band management, CPU-port broadcast/multicast/unicast handling, CRC behavior and Broadcom header tagging. Its comments name BCM5325, so the exact values must be checked against BCM53115 behavior rather than copied blindly.

## Ethernet interfaces

The stock Octeon driver creates three interfaces. The boot log says interface 0 has three RGMII ports. The switch is likely connected to one RGMII port as a CPU/IMP interface, while the remaining Octeon ports may service separate WAN/LAN paths or unused board connections. This must be resolved by link tests, MDIO scans and traffic captures under the stock firmware.

## WLAN

The Mini PCI device enumerates as PCI `14e4:432b`, corresponding to the BCM4322 family. The stock `wl.ko` is a proprietary, unstripped 64-bit big-endian Octeon module and depends on `scm-led.ko`. Userspace derives the WLAN MAC from the Octeon base MAC plus four before inserting the module.

For an open implementation, WLAN should be deferred. A modern b43 stack may provide partial support for PCI ID `14e4:432b`, requires separately supplied firmware, and has significant 802.11n limitations. Replacing the removable Mini PCI card with a well-supported ath9k card is likely the cleaner end state.

## Buttons and LEDs

- `push_button.ko` exports/configures GPIO input sensing and depends on `scm-led.ko`.
- `scm-led.ko` exposes LED on/off/blink and GPIO configuration functions.
- Factory-reset behavior is partly userspace-driven through `fReset` and `factoryReset.sh`.

Exact GPIO numbers still require static disassembly and/or dynamic tracing.

## Valuable next static-analysis targets

1. `cavium-ethernet.ko`: RGMII mapping, Broadcom tag handling, MDIO and IMP controls.
2. `bcm5398.ko`: pseudo-PHY MDIO transaction protocol and BCM53115 register usage.
3. `mii.ko`: wrapper argument mapping.
4. `push_button.ko` and `scm-led.ko`: GPIO numbers, polarity and front-panel mapping.
5. Kernel ELF: custom RV200W board helpers, BootBus timing and MAC-address source.
6. U-Boot: TFTP and RAM-boot behavior, board descriptors and recovery paths.
