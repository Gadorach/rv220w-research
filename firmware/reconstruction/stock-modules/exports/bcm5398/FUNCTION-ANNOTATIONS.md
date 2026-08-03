# bcm5398.ko — per-function annotations

> All C is Ghidra reconstruction, not original Cisco source. Confidence is deliberately conservative.

## `bcm5398VlanDisable` @ `0x001000a0`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Disables switch VLAN processing through the Broadcom register interface.
- **Decompiler:** success; reconstructed C SHA-256 `03291bdec9e05691d8306035a29ee481798878c7efa9b503b03826cda2f42ace`
- **Artifacts:** `decompiled/001000a0_bcm5398VlanDisable.c`, `assembly/001000a0_bcm5398VlanDisable.asm`
- **Recognized calls:** `miiSwitchRegisterWrite` ×1

## `bcm5398VlanEnable` @ `0x00100138`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Enables IEEE 802.1Q VLAN processing in the Broadcom switch through the module's MII register-access layer.
- **Decompiler:** success; reconstructed C SHA-256 `f26975abab4270c05fb70543741d7a6d1c1b3f45fe5aeb0f6ed9fdea5d12361f`
- **Artifacts:** `decompiled/00100138_bcm5398VlanEnable.c`, `assembly/00100138_bcm5398VlanEnable.asm`
- **Recognized calls:** `miiSwitchRegisterWrite` ×1

## `bcm5398PortDefaultTagSet` @ `0x001001d0`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Programs the per-port default VLAN tag/PVID state used for untagged ingress traffic.
- **Decompiler:** success; reconstructed C SHA-256 `3c9339326751e9fb307afe8016654a05c1717a898f680c66cfa69e727d01ead6`
- **Artifacts:** `decompiled/001001d0_bcm5398PortDefaultTagSet.c`, `assembly/001001d0_bcm5398PortDefaultTagSet.asm`
- **Recognized calls:** `miiSwitchRegisterWrite` ×1

## `bcm5398PortEntrySet` @ `0x00100240`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Writes a BCM switch port-table entry; exact bit fields should be correlated with BCM53115/B53 register definitions before reuse.
- **Decompiler:** success; reconstructed C SHA-256 `75673d39b72cde9c20cd83c565a72495ad8d26b07666d54eeb397253b7d414c8`
- **Artifacts:** `decompiled/00100240_bcm5398PortEntrySet.c`, `assembly/00100240_bcm5398PortEntrySet.asm`
- **Recognized calls:** `miiSwitchRegisterWrite` ×1

## `configWanPort` @ `0x00100288`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Board-policy routine that applies special configuration to the designated WAN port. This is a primary target for recovering WAN-vs-LAN switch-port numbering.
- **Decompiler:** success; reconstructed C SHA-256 `202e23291f028069b5c6c3ce79a674ea00f708797cac85b16aed98f158d8329d`
- **Artifacts:** `decompiled/00100288_configWanPort.c`, `assembly/00100288_configWanPort.asm`
- **Recognized calls:** `miiSwitchRegisterRead16` ×1, `miiSwitchRegisterWrite` ×1, `strcmp` ×2

## `bcm5398VlanNon8021QSet` @ `0x00100510`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `c45b0355c9d5a4513ef8cdc3907def5e210f92383ed713d1d26809a6a990a638`
- **Artifacts:** `decompiled/00100510_bcm5398VlanNon8021QSet.c`, `assembly/00100510_bcm5398VlanNon8021QSet.asm`
- **Recognized calls:** `miiSwitchRegisterRead16` ×1, `miiSwitchRegisterWrite` ×1

## `bcm5398PortLinkStatusQuery` @ `0x001005d0`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Reads switch port link state through the Broadcom register-access path.
- **Decompiler:** success; reconstructed C SHA-256 `7d0cb6d6f52e231ea54165d2b32ae4a3cf8ce1c6c5ec6479dc33832636b3c8e0`
- **Artifacts:** `decompiled/001005d0_bcm5398PortLinkStatusQuery.c`, `assembly/001005d0_bcm5398PortLinkStatusQuery.asm`
- **Recognized calls:** `miiSwitchRegisterRead16` ×1

## `bcm5398PortDefaultTagGet` @ `0x00100628`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `7a62452f3337536737456ce343de68858308ab475d100747938682edc061104c`
- **Artifacts:** `decompiled/00100628_bcm5398PortDefaultTagGet.c`, `assembly/00100628_bcm5398PortDefaultTagGet.asm`
- **Recognized calls:** `miiSwitchRegisterRead16` ×1

## `bcm5398PortEntryGet` @ `0x001006b8`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `60e1f90696e8efa70267958ecd57be15b454347e66dd235787124ae33ba7eed5`
- **Artifacts:** `decompiled/001006b8_bcm5398PortEntryGet.c`, `assembly/001006b8_bcm5398PortEntryGet.asm`
- **Recognized calls:** `miiSwitchRegisterRead16` ×1

## `bcm5398PortConfigGet` @ `0x00100710`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Reads per-port switch configuration for the vendor control plane.
- **Decompiler:** success; reconstructed C SHA-256 `9d163a29bc9da00b3aaa0679afc2289a57ca8d46e503c2692dfb8b895855ea38`
- **Artifacts:** `decompiled/00100710_bcm5398PortConfigGet.c`, `assembly/00100710_bcm5398PortConfigGet.asm`
- **Recognized calls:** `mii_phy_read` ×1

## `bcm5398PortStateSet` @ `0x001007e8`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Sets a switch port's forwarding/state control; likely covers disabled/blocking/listening/learning/forwarding encodings.
- **Decompiler:** success; reconstructed C SHA-256 `8d262c4a9440b82c0391db56da098ec8a45c202a1ce1a12a0d44cfbc54eb07b0`
- **Artifacts:** `decompiled/001007e8_bcm5398PortStateSet.c`, `assembly/001007e8_bcm5398PortStateSet.asm`
- **Recognized calls:** `mii_phy_read` ×1, `mii_phy_write` ×1

## `bcm5398PortConfigSet` @ `0x00100898`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Programs per-port switch configuration, including policy fields supplied by the vendor control plane.
- **Decompiler:** success; reconstructed C SHA-256 `e6547e29fbcde379e37b724d640a2cf48bc1ff17502dbd141cd44b0bf9ec80fa`
- **Artifacts:** `decompiled/00100898_bcm5398PortConfigSet.c`, `assembly/00100898_bcm5398PortConfigSet.asm`
- **Recognized calls:** `mii_phy_read` ×1, `mii_phy_write` ×2

## `bcm5398VlanEntrySet` @ `0x00100a18`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Programs a VLAN table entry, including membership and tagging policy.
- **Decompiler:** success; reconstructed C SHA-256 `6f0f687469dbd1733cedb3257113e6942a32ef0a71326838cbb6fd027b9fab60`
- **Artifacts:** `decompiled/00100a18_bcm5398VlanEntrySet.c`, `assembly/00100a18_bcm5398VlanEntrySet.asm`
- **Recognized calls:** `configWanPort` ×1, `miiSwitchRegisterRead8` ×1, `miiSwitchRegisterWrite` ×1, `strcmp` ×2

## `bcm5398VlanEntryGet` @ `0x00100ca8`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Reads a VLAN table entry from the switch.
- **Decompiler:** success; reconstructed C SHA-256 `5eeffc91b9f2deffa749e24246945a62f8a669d0e0aa4354bba111137a889ad2`
- **Artifacts:** `decompiled/00100ca8_bcm5398VlanEntryGet.c`, `assembly/00100ca8_bcm5398VlanEntryGet.asm`
- **Recognized calls:** `miiSwitchRegisterRead32` ×1, `miiSwitchRegisterRead8` ×1, `miiSwitchRegisterWrite` ×1, `strcmp` ×2

## `wanportCheck` @ `0x00100ed8`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Tests whether a requested logical/physical port matches the module's configured WAN-port parameter.
- **Decompiler:** success; reconstructed C SHA-256 `ada966e007861c5773aca8a11248869a69293c6c26bc59e86eddda9f527a40ce`
- **Artifacts:** `decompiled/00100ed8_wanportCheck.c`, `assembly/00100ed8_wanportCheck.asm`
- **Recognized calls:** `bcm5398VlanEntryGet` ×1

## `bcm5398PortMirrorSet` @ `0x00100f60`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Programs port-mirroring source/destination controls.
- **Decompiler:** success; reconstructed C SHA-256 `856cae3a8947311b3a8fedbc0dc34b8e2424da1e488f143256bfa8c30957ecd4`
- **Artifacts:** `decompiled/00100f60_bcm5398PortMirrorSet.c`, `assembly/00100f60_bcm5398PortMirrorSet.asm`
- **Recognized calls:** `miiSwitchRegisterRead16` ×1, `miiSwitchRegisterWrite` ×1, `strcmp` ×8, `wanportCheck` ×1

## `bcm5398Ioctl` @ `0x001014b0`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Character-device ioctl dispatcher exposing switch operations to vendor userspace; command decoding is preserved in the decompiled export.
- **Decompiler:** success; reconstructed C SHA-256 `b72939d2e5d2054c7d078a3c92e9e421b3761901f95cdfeaf508d777aebb0f0e`
- **Artifacts:** `decompiled/001014b0_bcm5398Ioctl.c`, `assembly/001014b0_bcm5398Ioctl.asm`
- **Recognized calls:** `__copy_user` ×22, `bcm5398PortConfigGet` ×1, `bcm5398PortConfigSet` ×1, `bcm5398PortDefaultTagGet` ×1, `bcm5398PortDefaultTagSet` ×1, `bcm5398PortEntryGet` ×1, `bcm5398PortEntrySet` ×1, `bcm5398PortLinkStatusQuery` ×1, `bcm5398PortMirrorSet` ×1, `bcm5398PortStateSet` ×1, `bcm5398VlanDisable` ×1, `bcm5398VlanEnable` ×1, `bcm5398VlanEntryGet` ×1, `bcm5398VlanEntrySet` ×1, `bcm5398VlanNon8021QSet` ×1, `printk` ×1

## `bcm5398CompatIoctl` @ `0x00102610`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Character-device ioctl dispatcher exposing switch operations to vendor userspace; command decoding is preserved in the decompiled export.
- **Decompiler:** success; reconstructed C SHA-256 `e9c9a6963eb52d0d6fa115a20ccc1db8e71f907baa7e1a553cf40dd480e2f716`
- **Artifacts:** `decompiled/00102610_bcm5398CompatIoctl.c`, `assembly/00102610_bcm5398CompatIoctl.asm`
- **Recognized calls:** `bcm5398Ioctl` ×1

## `miiSwitchRegisterWrite` @ `0x00102660`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Writes an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction protocol.
- **Decompiler:** success; reconstructed C SHA-256 `40ff688ba955d9e48dfe74c8944974cae53c2705def97fb33898dbb2e3192400`
- **Artifacts:** `decompiled/00102660_miiSwitchRegisterWrite.c`, `assembly/00102660_miiSwitchRegisterWrite.asm`
- **Recognized calls:** `mii_phy_read` ×2, `mii_phy_write` ×7, `printk` ×1

## `miiSwitchRegisterRead` @ `0x00102898`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Reads an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction protocol.
- **Decompiler:** success; reconstructed C SHA-256 `61c3751c77e9da090af887ffe6c63ac6b6358b4dc30f5b8ed395fe6bc945f507`
- **Artifacts:** `decompiled/00102898_miiSwitchRegisterRead.c`, `assembly/00102898_miiSwitchRegisterRead.asm`
- **Recognized calls:** `mii_phy_read` ×6, `mii_phy_write` ×3, `printk` ×1

## `miiSwitchRegisterRead8` @ `0x00102ad8`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Width-specific wrapper around the generic BCM switch-register read routine.
- **Decompiler:** success; reconstructed C SHA-256 `68a064d52992c20a3f162a6513581e1193b5e7fbb519c1545be1b388e9f8166b`
- **Artifacts:** `decompiled/00102ad8_miiSwitchRegisterRead8.c`, `assembly/00102ad8_miiSwitchRegisterRead8.asm`
- **Recognized calls:** `miiSwitchRegisterRead` ×1

## `miiSwitchRegisterRead16` @ `0x00102b28`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Width-specific wrapper around the generic BCM switch-register read routine.
- **Decompiler:** success; reconstructed C SHA-256 `8d6f056d6f1677e47ac738eaf04aadf1cb3f6123c94f5596eee08f8f03887817`
- **Artifacts:** `decompiled/00102b28_miiSwitchRegisterRead16.c`, `assembly/00102b28_miiSwitchRegisterRead16.asm`
- **Recognized calls:** `miiSwitchRegisterRead` ×1

## `miiSwitchRegisterRead32` @ `0x00102b78`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Width-specific wrapper around the generic BCM switch-register read routine.
- **Decompiler:** success; reconstructed C SHA-256 `35711160bb40a1bd88f28516c13a4b8501b5cfefa4f34c3aca7b1e4bd8ae7392`
- **Artifacts:** `decompiled/00102b78_miiSwitchRegisterRead32.c`, `assembly/00102b78_miiSwitchRegisterRead32.asm`
- **Recognized calls:** `miiSwitchRegisterRead` ×1

## `cleanup_module` @ `0x00102bd0`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Module teardown path; reverses registrations and frees runtime resources.
- **Decompiler:** success; reconstructed C SHA-256 `57b5fcbacfb082d09106539f767c330c3e8762c965f4b49559e70b43eba823e6`
- **Artifacts:** `decompiled/00102bd0_cleanup_module.c`, `assembly/00102bd0_cleanup_module.asm`
- **Recognized calls:** `cdev_del` ×1

## `init_module` @ `0x00102c58`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Registers the switch-control character device, module parameters and initial BCM switch policy.
- **Decompiler:** success; reconstructed C SHA-256 `9e0183f893aa89344e1cbe7929bbc743d0de18589e4859b33ad0ae05efcd65a5`
- **Artifacts:** `decompiled/00102c58_init_module.c`, `assembly/00102c58_init_module.asm`
- **Recognized calls:** `alloc_chrdev_region` ×1, `cdev_add` ×1, `cdev_init` ×1, `printk` ×4, `strcmp` ×2
