# cavium-ethernet.ko — per-function annotations

> All C is Ghidra reconstruction, not original Cisco source. Confidence is deliberately conservative.

## `offloadPortConfig` @ `0x00100210`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `0a018c52401a8685127efb0624a3e64ce677f3e4685d3eba8429bae7c163f252`
- **Artifacts:** `decompiled/00100210_offloadPortConfig.c`, `assembly/00100210_offloadPortConfig.asm`
- **Recognized calls:** `printk` ×2

## `sysctlHwOffloadBrcmHandler` @ `0x001002e0`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `12e99ab1bd2a19e4943cfa759a047a98be4bcf57f78aed6ba2e5d41d8cc43e69`
- **Artifacts:** `decompiled/001002e0_sysctlHwOffloadBrcmHandler.c`, `assembly/001002e0_sysctlHwOffloadBrcmHandler.asm`
- **Recognized calls:** `offloadPortConfig` ×1, `printk` ×1

## `sysctlHwOffloadVlanHandler` @ `0x001003d0`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `6e9c833248d8a8d3f46d526c23ad29ab9d25f9c002bb155e497a2f07fae1e2a2`
- **Artifacts:** `decompiled/001003d0_sysctlHwOffloadVlanHandler.c`, `assembly/001003d0_sysctlHwOffloadVlanHandler.asm`
- **Recognized calls:** `offloadPortConfig` ×1, `printk` ×1

## `hwOffloadSysctlUnregister` @ `0x001004c0`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `1e19b883733938ffaf470dd56c3e5d7faee3fcb443eb415bdd22764a3319a300`
- **Artifacts:** `decompiled/001004c0_hwOffloadSysctlUnregister.c`, `assembly/001004c0_hwOffloadSysctlUnregister.asm`
- **Recognized calls:** `printk` ×1, `unregister_sysctl_table` ×2

## `local_cavium_ethernet_text_000370` @ `0x00100580`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `961b1bcdc0e2119010abf6a83bdd7aede9159c067ce61d4962c57be5d64063ba`
- **Artifacts:** `decompiled/00100580_local_cavium_ethernet_text_000370.c`, `assembly/00100580_local_cavium_ethernet_text_000370.asm`
- **Recognized calls:** `single_open` ×1

## `local_cavium_ethernet_text_0003b0` @ `0x001005c0`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `9aad943c3a87ea618d8ff1c54c41f6c932fa079c4b3b3a03fc27afed1cd52a3b`
- **Artifacts:** `decompiled/001005c0_local_cavium_ethernet_text_0003b0.c`, `assembly/001005c0_local_cavium_ethernet_text_0003b0.asm`
- **Recognized calls:** `single_open` ×1

## `local_cavium_ethernet_text_0003f0` @ `0x00100600`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `a2821508d56716b8a69e9dd548fb6a6b5e7ecb0362e4251f11b2299c01a0950c`
- **Artifacts:** `decompiled/00100600_local_cavium_ethernet_text_0003f0.c`, `assembly/00100600_local_cavium_ethernet_text_0003f0.asm`
- **Recognized calls:** `single_open` ×1

## `local_cavium_ethernet_text_000430` @ `0x00100640`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `c61c42366ee0817244e3bdf0c1a107a9b7141db67322273d064c86f272390661`
- **Artifacts:** `decompiled/00100640_local_cavium_ethernet_text_000430.c`, `assembly/00100640_local_cavium_ethernet_text_000430.asm`
- **Recognized calls:** `single_open` ×1

## `local_cavium_ethernet_text_000470` @ `0x00100680`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `834a1ef1cf479134452fb8d9812a256f5f1f0aaca866294936044cb0439aa404`
- **Artifacts:** `decompiled/00100680_local_cavium_ethernet_text_000470.c`, `assembly/00100680_local_cavium_ethernet_text_000470.asm`
- **Recognized calls:** `single_open` ×1

## `local_cavium_ethernet_text_0004b0` @ `0x001006c0`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `7864516f059178173c5b796f50bee07485053a9127014646ffcecc30c551e9d8`
- **Artifacts:** `decompiled/001006c0_local_cavium_ethernet_text_0004b0.c`, `assembly/001006c0_local_cavium_ethernet_text_0004b0.asm`
- **Recognized calls:** `seq_printf` ×1

## `hwOffloadSysctlRegister` @ `0x00100768`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `ea42ffcb568006be96e87f7b7b99c83617e773d332898559b7dab0507b8dcf0c`
- **Artifacts:** `decompiled/00100768_hwOffloadSysctlRegister.c`, `assembly/00100768_hwOffloadSysctlRegister.asm`
- **Recognized calls:** `printk` ×8, `register_sysctl_table` ×4

## `allocateCacheMemory` @ `0x00100a10`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `79004b3b06f263972ec8c56f5664a6af903ba40593ff118cf3ab1cf20576cf22`
- **Artifacts:** `decompiled/00100a10_allocateCacheMemory.c`, `assembly/00100a10_allocateCacheMemory.asm`
- **Recognized calls:** `cvmx_bootmem_alloc` ×1, `flushFlowInfo` ×1, `panic` ×1, `printk` ×2

## `sysctlHwOffloadHandler` @ `0x00100b78`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `a6ea9ab1e5237ee5e2d3185c628048803af95175eb83ddd7c3a332765618f56b`
- **Artifacts:** `decompiled/00100b78_sysctlHwOffloadHandler.c`, `assembly/00100b78_sysctlHwOffloadHandler.asm`
- **Recognized calls:** `flushFlowInfo` ×1

## `local_cavium_ethernet_text_0009a8` @ `0x00100bb8`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `42262add86716b85dd276374d4564342f2bd91a17e51d988f0d86d0cabacec9b`
- **Artifacts:** `decompiled/00100bb8_local_cavium_ethernet_text_0009a8.c`, `assembly/00100bb8_local_cavium_ethernet_text_0009a8.asm`
- **Recognized calls:** `seq_printf` ×3

## `local_cavium_ethernet_text_000bd8` @ `0x00100de8`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `f565ca9c20843fdc2641c67eb171693dafd6201407c7d0bf542d1a872e9b6161`
- **Artifacts:** `decompiled/00100de8_local_cavium_ethernet_text_000bd8.c`, `assembly/00100de8_local_cavium_ethernet_text_000bd8.asm`
- **Recognized calls:** `seq_printf` ×1

## `local_cavium_ethernet_text_000cb8` @ `0x00100ec8`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `ca7bb49d29105be8e98494911b033c6f774ac1b08a52e91a1829fb7798922c91`
- **Artifacts:** `decompiled/00100ec8_local_cavium_ethernet_text_000cb8.c`, `assembly/00100ec8_local_cavium_ethernet_text_000cb8.asm`
- **Recognized calls:** `seq_printf` ×1

## `local_cavium_ethernet_text_000d38` @ `0x00100f48`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `36742efdd3d2aa861d27d9161b399a0ef767c0df4b3fd306140f2c4b33ba76b6`
- **Artifacts:** `decompiled/00100f48_local_cavium_ethernet_text_000d38.c`, `assembly/00100f48_local_cavium_ethernet_text_000d38.asm`
- **Recognized calls:** `seq_printf` ×1

## `cvm_oct_register_callback` @ `0x00100fb8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `15c3094d9d1134545b8d8e4c7741294537f3a82bd340147e60ddd844c3750e54`
- **Artifacts:** `decompiled/00100fb8_cvm_oct_register_callback.c`, `assembly/00100fb8_cvm_oct_register_callback.asm`
- **Recognized calls:** `strcmp` ×1

## `TF1_cvm_oct_mdio_read` @ `0x001010c0`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor Octeon MDIO read implementation exported to the MII wrapper module.
- **Decompiler:** success; reconstructed C SHA-256 `f8ccc29308a4707e7d492c20a9fecf637a91972317f90e5301edf4f58b2f2ec5`
- **Artifacts:** `decompiled/001010c0_TF1_cvm_oct_mdio_read.c`, `assembly/001010c0_TF1_cvm_oct_mdio_read.asm`
- **Recognized calls:** `yield` ×1

## `cvm_oct_mdio_write` @ `0x00101188`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor Octeon MDIO write implementation exported to the MII wrapper module.
- **Decompiler:** success; reconstructed C SHA-256 `a422e55ca3280fdda1b84a0b46774edb165a58ffd503f29a87a846c02fdfab7b`
- **Artifacts:** `decompiled/00101188_cvm_oct_mdio_write.c`, `assembly/00101188_cvm_oct_mdio_write.asm`
- **Recognized calls:** `yield` ×1

## `local_cavium_ethernet_text_001038` @ `0x00101248`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `2feec5f9ed4c38f32e6ed9255cff024167b57a1e9868a10dc3e4d22d15978231`
- **Artifacts:** `decompiled/00101248_local_cavium_ethernet_text_001038.c`, `assembly/00101248_local_cavium_ethernet_text_001038.asm`
- **Recognized calls:** `kfree_skb` ×2, `mod_timer` ×1

## `cvm_oct_free_work` @ `0x001015a8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `df34798c23bc10621d130c255298b4e4819f8f295f7a14c4c853d7be1eb5d078`
- **Artifacts:** `decompiled/001015a8_cvm_oct_free_work.c`, `assembly/001015a8_cvm_oct_free_work.asm`
- **Recognized calls:** `cvmx_warn` ×2

## `cvm_oct_common_uninit` @ `0x00101770`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `b40cb0425d562edfa1644b4f1004bdcd57e66b0a32207b0ad4e76b0426451174`
- **Artifacts:** `decompiled/00101770_cvm_oct_common_uninit.c`, `assembly/00101770_cvm_oct_common_uninit.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_001568` @ `0x00101778`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `bc59468560964e3dce4a46053b13835b73bd26e13c10b0f805af8e6b0e169a72`
- **Artifacts:** `decompiled/00101778_local_cavium_ethernet_text_001568.c`, `assembly/00101778_local_cavium_ethernet_text_001568.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_001638` @ `0x00101848`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `70719aa8a343bb7282aa95af8ac85312cef8beecb8ead2d5cc86f506386aa929`
- **Artifacts:** `decompiled/00101848_local_cavium_ethernet_text_001638.c`, `assembly/00101848_local_cavium_ethernet_text_001638.asm`
- **Recognized calls:** `printk` ×1

## `brcm_miiphy_read` @ `0x00101938`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Broadcom-oriented MDIO callback used by the Octeon Ethernet/switch integration.
- **Decompiler:** success; reconstructed C SHA-256 `6d137f309d4d3f0705d578682c2ed18db64b48ea870ff6ba84ac5821c3955a36`
- **Artifacts:** `decompiled/00101938_brcm_miiphy_read.c`, `assembly/00101938_brcm_miiphy_read.asm`
- **Recognized calls:** `local_cavium_ethernet_text_001568` ×1, `local_cavium_ethernet_text_001638` ×1

## `brcm_miiphy_write` @ `0x00101ac0`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Broadcom-oriented MDIO callback used by the Octeon Ethernet/switch integration.
- **Decompiler:** success; reconstructed C SHA-256 `5f5bfd40563fc0ae5d057d5ba096370dad5a831d214c90a49fdd30ff918aae4a`
- **Artifacts:** `decompiled/00101ac0_brcm_miiphy_write.c`, `assembly/00101ac0_brcm_miiphy_write.asm`
- **Recognized calls:** `local_cavium_ethernet_text_001568` ×1, `local_cavium_ethernet_text_001638` ×1

## `cvm_oct_common_init` @ `0x00101cc8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Initializes common Octeon Ethernet resources, packet I/O, device state and MDIO integration shared by ports.
- **Decompiler:** success; reconstructed C SHA-256 `9aec0b01bb7f92b329986a87ff5042fb632a7a226a76431ba1f64d64d5d0ad8a`
- **Artifacts:** `decompiled/00101cc8_cvm_oct_common_init.c`, `assembly/00101cc8_cvm_oct_common_init.asm`
- **Recognized calls:** `brcm_miiphy_read` ×1, `brcm_miiphy_write` ×1, `cvm_oct_mdio_setup_device` ×1, `memset` ×2, `strstr` ×1

## `local_cavium_ethernet_text_002028` @ `0x00102238`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `c1c307e7c9ca24188e8ded7dc3f82d79ad98439ee04eb38bd9b091054fc1e9a2`
- **Artifacts:** `decompiled/00102238_local_cavium_ethernet_text_002028.c`, `assembly/00102238_local_cavium_ethernet_text_002028.asm`
- **Recognized calls:** `cvmx_helper_interface_get_mode` ×1, `memset` ×2, `octeon_is_simulation` ×1, `panic` ×1

## `local_cavium_ethernet_text_002238` @ `0x00102448`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `509585afcb5584db23d3cb5dcf8051389f787c4b1310c6bf14c4280c39b5a294`
- **Artifacts:** `decompiled/00102448_local_cavium_ethernet_text_002238.c`, `assembly/00102448_local_cavium_ethernet_text_002238.asm`
- **Recognized calls:** `memset` ×2, `octeon_is_simulation` ×1

## `local_cavium_ethernet_text_002718` @ `0x00102928`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `2b85a74dea0a21009da46612a812c8a3dfd18bff12dd7fafa08c2e816b3db1d6`
- **Artifacts:** `decompiled/00102928_local_cavium_ethernet_text_002718.c`, `assembly/00102928_local_cavium_ethernet_text_002718.asm`
- **Recognized calls:** `cvmx_helper_interface_get_mode` ×2, `local_cavium_ethernet_text_002028` ×1, `memcpy` ×2, `panic` ×2, `printk` ×1

## `local_cavium_ethernet_text_0029a8` @ `0x00102bb8`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `bac03c2b2d56bae9552c6d405224a716e89b6386a3d0faa374cf9b4274267127`
- **Artifacts:** `decompiled/00102bb8_local_cavium_ethernet_text_0029a8.c`, `assembly/00102bb8_local_cavium_ethernet_text_0029a8.asm`
- **Recognized calls:** `cvmx_helper_interface_get_mode` ×1, `local_cavium_ethernet_text_002028` ×1, `memcpy` ×2, `panic` ×1

## `local_cavium_ethernet_text_002c60` @ `0x00102e70`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `ebdb8cfcf7f8aef4bb55a567a3a87a9715dd877d943c9580d66836978ec2bd2f`
- **Artifacts:** `decompiled/00102e70_local_cavium_ethernet_text_002c60.c`, `assembly/00102e70_local_cavium_ethernet_text_002c60.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_002c68` @ `0x00102e78`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `0b050fc6d119ce34b83f83a30c06dd4a765475a70e9fcd3f106c45f7fed5b24b`
- **Artifacts:** `decompiled/00102e78_local_cavium_ethernet_text_002c68.c`, `assembly/00102e78_local_cavium_ethernet_text_002c68.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_002c70` @ `0x00102e80`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `6ceddf48a728398cf2b752e05a0a5c5eb5157c522d6b0e43529d462c3560eeaf`
- **Artifacts:** `decompiled/00102e80_local_cavium_ethernet_text_002c70.c`, `assembly/00102e80_local_cavium_ethernet_text_002c70.asm`
- **Recognized calls:** `strcpy` ×2

## `cvm_oct_mdio_setup_device` @ `0x00102f20`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `34947f7e2c32ab4961636f5edd3c7367d3e55a61342a50cb2a5e00ba8537af3f`
- **Artifacts:** `decompiled/00102f20_cvm_oct_mdio_setup_device.c`, `assembly/00102f20_cvm_oct_mdio_setup_device.asm`
- **Recognized calls:** `cvmx_helper_board_get_mii_address` ×1

## `local_cavium_ethernet_text_002e20` @ `0x00103030`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `89473cd985a9deff6d391c102d48ad30efc1e8ca10892a2ea3d8a25030c7684a`
- **Artifacts:** `decompiled/00103030_local_cavium_ethernet_text_002e20.c`, `assembly/00103030_local_cavium_ethernet_text_002e20.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_002e40` @ `0x00103050`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `b41c8e1212ae9822749b6d69cfc1b83cf536649811af2dbfa7b1e8a5ee00db94`
- **Artifacts:** `decompiled/00103050_local_cavium_ethernet_text_002e40.c`, `assembly/00103050_local_cavium_ethernet_text_002e40.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_002e60` @ `0x00103070`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `34dda1242a48ab7cf7ea3505dedafdfc7067a15c381f6096eecf55a55f80d3a7`
- **Artifacts:** `decompiled/00103070_local_cavium_ethernet_text_002e60.c`, `assembly/00103070_local_cavium_ethernet_text_002e60.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_002e80` @ `0x00103090`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `531df64450c90c45ad0917fb1ebed8aeb81560e271ae30e4321431e8008a3795`
- **Artifacts:** `decompiled/00103090_local_cavium_ethernet_text_002e80.c`, `assembly/00103090_local_cavium_ethernet_text_002e80.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_ioctl` @ `0x001030b0`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `2124e46160ac9aba693b0b5f2930d92ddab5dabc7ec965665bf62bf4c33b401b`
- **Artifacts:** `decompiled/001030b0_cvm_oct_ioctl.c`, `assembly/001030b0_cvm_oct_ioctl.asm`
- **Recognized calls:** `generic_mii_ioctl` ×1

## `local_cavium_ethernet_text_002ee0` @ `0x001030f0`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `a209058955380521ffb00c39806c87f1f3935af81cd1848a1f768ea926e7c23b`
- **Artifacts:** `decompiled/001030f0_local_cavium_ethernet_text_002ee0.c`, `assembly/001030f0_local_cavium_ethernet_text_002ee0.asm`
- **Recognized calls:** `yield` ×1

## `local_cavium_ethernet_text_002fa0` @ `0x001031b0`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `e432c52ff6f56ea4c953b212db1258db4499f51ce9affc652565892d2ebe901d`
- **Artifacts:** `decompiled/001031b0_local_cavium_ethernet_text_002fa0.c`, `assembly/001031b0_local_cavium_ethernet_text_002fa0.asm`
- **Recognized calls:** `yield` ×1

## `cvm_oct_mem_empty_fpa` @ `0x00103280`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `07f0936b64a760b4080af74d045cc53d1c6630a30cb01d6afbfd324276145af5`
- **Artifacts:** `decompiled/00103280_cvm_oct_mem_empty_fpa.c`, `assembly/00103280_cvm_oct_mem_empty_fpa.asm`
- **Recognized calls:** `kfree_skb` ×1

## `local_cavium_ethernet_text_0031b0` @ `0x001033c0`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `751e071329ce056fea525087e43d7005dd3ef410da694dcbef3228ab1fc12a10`
- **Artifacts:** `decompiled/001033c0_local_cavium_ethernet_text_0031b0.c`, `assembly/001033c0_local_cavium_ethernet_text_0031b0.asm`
- **Recognized calls:** `__alloc_skb` ×1, `cvmx_warn` ×1, `memcpy` ×1

## `cvm_oct_mem_fill_fpa_tf1` @ `0x001035a8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `0056e032da3623779ce0a563f6f6f93e70271cf3841b8bb4f35c556f028283f5`
- **Artifacts:** `decompiled/001035a8_cvm_oct_mem_fill_fpa_tf1.c`, `assembly/001035a8_cvm_oct_mem_fill_fpa_tf1.asm`
- **Recognized calls:** `__alloc_skb` ×1, `cvmx_warn` ×1, `memcpy` ×1

## `cvm_oct_mem_fill_fpa` @ `0x001035c8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `3ef525cc76a9e044acb9303b6ccf044f94902b793de3a9c7ce94095c3b915b71`
- **Artifacts:** `decompiled/001035c8_cvm_oct_mem_fill_fpa.c`, `assembly/001035c8_cvm_oct_mem_fill_fpa.asm`
- **Recognized calls:** `__alloc_skb` ×1, `cvmx_warn` ×1, `memcpy` ×1

## `cvm_oct_fill_hw_memory` @ `0x001035e8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `607dfb660801133e881cdcbdd8830f62bd8d48874cc4ae2c7c92a576dae28af0`
- **Artifacts:** `decompiled/001035e8_cvm_oct_fill_hw_memory.c`, `assembly/001035e8_cvm_oct_fill_hw_memory.asm`
- **Recognized calls:** `__kmalloc` ×1, `panic` ×1

## `local_cavium_ethernet_text_003520` @ `0x00103730`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `fc41d2d42a54fd5fee6d81f52f0ed0ec1ca37d042a2030d377f531f320538fda`
- **Artifacts:** `decompiled/00103730_local_cavium_ethernet_text_003520.c`, `assembly/00103730_local_cavium_ethernet_text_003520.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_proc_shutdown` @ `0x001037b8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `c11e8a636212e03d9d9da234725c81ee8e1fb877353b712c710173f215eb578f`
- **Artifacts:** `decompiled/001037b8_cvm_oct_proc_shutdown.c`, `assembly/001037b8_cvm_oct_proc_shutdown.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_proc_initialize` @ `0x001037f0`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `90341e86ba8219a62f534e3ed4d476d4ee338a63cfa193478b597012f4ade186`
- **Artifacts:** `decompiled/001037f0_cvm_oct_proc_initialize.c`, `assembly/001037f0_cvm_oct_proc_initialize.asm`
- **Recognized calls:** `create_proc_entry` ×1

## `local_cavium_ethernet_text_003658` @ `0x00103868`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `364f1366f8d170a5b335a3a8be74bb85be558baa91d4ded31f80489258308d50`
- **Artifacts:** `decompiled/00103868_local_cavium_ethernet_text_003658.c`, `assembly/00103868_local_cavium_ethernet_text_003658.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_003698` @ `0x001038a8`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `bee94d3f175f97c78923dd9a377c281a7146e923414c275c7c12151fa414968a`
- **Artifacts:** `decompiled/001038a8_local_cavium_ethernet_text_003698.c`, `assembly/001038a8_local_cavium_ethernet_text_003698.asm`
- **Recognized calls:** `local_cavium_ethernet_text_003520` ×1, `seq_printf` ×24

## `cvm_oct_rgmii_uninit` @ `0x00104070`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `7a91c7df8ff8e1a7ded998d2d1e2f992fe3165a3b543be8aed63dc147710f8d1`
- **Artifacts:** `decompiled/00104070_cvm_oct_rgmii_uninit.c`, `assembly/00104070_cvm_oct_rgmii_uninit.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_rgmii_init` @ `0x00104090`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Initializes an Octeon RGMII interface; critical for correlating the three GMX/RGMII ports reported on RV220W.
- **Decompiler:** success; reconstructed C SHA-256 `69fe83cc1578700f24041a9090b29b0821fc4b83445495329ed2c0485d1cc9fe`
- **Artifacts:** `decompiled/00104090_cvm_oct_rgmii_init.c`, `assembly/00104090_cvm_oct_rgmii_init.asm`
- **Recognized calls:** `cvm_oct_common_init` ×1, `local_cavium_ethernet_text_003f88` ×1, `octeon_is_simulation` ×1

## `local_cavium_ethernet_text_003f88` @ `0x00104198`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `634b21451d1f1bef869dbb573b7853474933ae50f915b4f0a785e8b42e1558a1`
- **Artifacts:** `decompiled/00104198_local_cavium_ethernet_text_003f88.c`, `assembly/00104198_local_cavium_ethernet_text_003f88.asm`
- **Recognized calls:** `__printk_ratelimit` ×3, `cvmx_helper_link_autoconf` ×1, `cvmx_helper_link_get` ×1, `panic` ×2, `printk` ×1

## `local_cavium_ethernet_text_004088` @ `0x00104298`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `918e9030b9609683f49bee2c78a21ee0a61f7ff3630f7e68fe29b9e17e14012f`
- **Artifacts:** `decompiled/00104298_local_cavium_ethernet_text_004088.c`, `assembly/00104298_local_cavium_ethernet_text_004088.asm`
- **Recognized calls:** `__printk_ratelimit` ×3, `cvmx_helper_link_autoconf` ×1, `cvmx_helper_link_get` ×1, `panic` ×1, `printk` ×1

## `local_cavium_ethernet_text_004638` @ `0x00104848`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `fffc5c55cb2b9be0e126d185c9e935ab1287679b9d91964284f93782a899391b`
- **Artifacts:** `decompiled/00104848_local_cavium_ethernet_text_004638.c`, `assembly/00104848_local_cavium_ethernet_text_004638.asm`
- **Recognized calls:** `panic` ×1

## `mangleCookieValue` @ `0x00104950`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `21e591b4c3c6e1dcead33a4a64813a91e695f343d1fa60ec6c142b1458d02021`
- **Artifacts:** `decompiled/00104950_mangleCookieValue.c`, `assembly/00104950_mangleCookieValue.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_check_timestamp_just_created` @ `0x00104970`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `0cac8113f6eaf1caa71a33f9b49b07dc8537f30e4ed9f5b807b7a8f8809ed9c5`
- **Artifacts:** `decompiled/00104970_cvm_ipfwd_check_timestamp_just_created.c`, `assembly/00104970_cvm_ipfwd_check_timestamp_just_created.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_check_timestamp` @ `0x00104988`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `8a5f587b5fa14f85f68ebea597b7b822dfa4d5a43fb88656dde5bfcf79f93ad6`
- **Artifacts:** `decompiled/00104988_cvm_ipfwd_check_timestamp.c`, `assembly/00104988_cvm_ipfwd_check_timestamp.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_get_free_entry` @ `0x001049d0`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `093f51b999244c675b13cdb0316468ca6ed2aead2ecd134e120967bac045a8e2`
- **Artifacts:** `decompiled/001049d0_cvm_ipfwd_get_free_entry.c`, `assembly/001049d0_cvm_ipfwd_get_free_entry.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_setup_flow_info` @ `0x00104a40`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `8f38f0d27d2118c2be8309a4d36bacf4901b9b268ab33dccf41b00c8b8bf5baf`
- **Artifacts:** `decompiled/00104a40_cvm_ipfwd_setup_flow_info.c`, `assembly/00104a40_cvm_ipfwd_setup_flow_info.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_0048e8` @ `0x00104af8`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `f301a2b758c2747947ad32075d28828d977ce496708e1b2d7156382ce5be1c36`
- **Artifacts:** `decompiled/00104af8_local_cavium_ethernet_text_0048e8.c`, `assembly/00104af8_local_cavium_ethernet_text_0048e8.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_004948` @ `0x00104b58`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `e886f407e26d240292bf7543387d50697408049c43416e658f3189e3ba83a436`
- **Artifacts:** `decompiled/00104b58_local_cavium_ethernet_text_004948.c`, `assembly/00104b58_local_cavium_ethernet_text_004948.asm`
- **Recognized calls:** `local_cavium_ethernet_text_0048e8` ×1

## `local_cavium_ethernet_text_0049f8` @ `0x00104c08`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `571fe7ca0ae83b1fa15aff6b0cf1ab9c68bbbd80d78575b0a77427b832db9ca2`
- **Artifacts:** `decompiled/00104c08_local_cavium_ethernet_text_0049f8.c`, `assembly/00104c08_local_cavium_ethernet_text_0049f8.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_004a20` @ `0x00104c30`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `d31fb594c11e5ea97342aa88d6ca0b79e582ce2997c9f372b3db9c0bae5880bb`
- **Artifacts:** `decompiled/00104c30_local_cavium_ethernet_text_004a20.c`, `assembly/00104c30_local_cavium_ethernet_text_004a20.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_find_entry` @ `0x00104c38`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `1ab730e8050326593b4d0f690705e5eb3841b28f737c9d1f0809c5ee65123877`
- **Artifacts:** `decompiled/00104c38_cvm_ipfwd_find_entry.c`, `assembly/00104c38_cvm_ipfwd_find_entry.asm`
- **Recognized calls:** `cvmx_warn` ×1

## `cvm_ipfwd_ct_match_find` @ `0x00104db8`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `7acb8df62fca4c4a11b1e1d8f5eb7ea43fefee253b52b38c06800137e5c54078`
- **Artifacts:** `decompiled/00104db8_cvm_ipfwd_ct_match_find.c`, `assembly/00104db8_cvm_ipfwd_ct_match_find.asm`
- **Recognized calls:** `cvmx_warn` ×1

## `cvm_ipfwd_ptr_flush` @ `0x00104f28`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `280a029d67a1a03361ee17b5832eb1ca2ad2c6c8735eb53fe9b0e8286c8b4a1d`
- **Artifacts:** `decompiled/00104f28_cvm_ipfwd_ptr_flush.c`, `assembly/00104f28_cvm_ipfwd_ptr_flush.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_ptr_free` @ `0x00104fb8`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `dfc791b0b070c3e97842159b7843113ea9ed54eb70e6f2270caba7ee2e1ac2d9`
- **Artifacts:** `decompiled/00104fb8_cvm_ipfwd_ptr_free.c`, `assembly/00104fb8_cvm_ipfwd_ptr_free.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_setup_entry` @ `0x00105040`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `e034608c5e5af2ea95934b0d96c251284e1c406d92d73bcffa552d467c0f1346`
- **Artifacts:** `decompiled/00105040_cvm_ipfwd_setup_entry.c`, `assembly/00105040_cvm_ipfwd_setup_entry.asm`
- **Recognized calls:** `cvm_ipfwd_ptr_free` ×1, `cvmx_warn` ×1

## `cvm_ipfwd_ptr_alloc` @ `0x00105158`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `01b6ea9007ccc2d9d0ab556676e86aaa2aac7cd665218573c061d2ade64ea801`
- **Artifacts:** `decompiled/00105158_cvm_ipfwd_ptr_alloc.c`, `assembly/00105158_cvm_ipfwd_ptr_alloc.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_cavium_ethernet_text_004f78` @ `0x00105188`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `314025a4e7ad4f13596d5643db930febea953172febabb1bffee3ee0cc0dae35`
- **Artifacts:** `decompiled/00105188_local_cavium_ethernet_text_004f78.c`, `assembly/00105188_local_cavium_ethernet_text_004f78.asm`
- **Recognized calls:** `kfree` ×1, `kmem_cache_alloc` ×1, `memset` ×1, `seq_open` ×1

## `ip_fastfwd_proc_tbl_init` @ `0x001052b8`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `c8fbeb26fa2f64066d0d943b10fae39bce8df870e886c000745185bc52ec7c4f`
- **Artifacts:** `decompiled/001052b8_ip_fastfwd_proc_tbl_init.c`, `assembly/001052b8_ip_fastfwd_proc_tbl_init.asm`
- **Recognized calls:** `create_proc_entry` ×1

## `cvm_mac_sprintf` @ `0x00105390`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `f97468f021ece346e481249e397184e212f1e81d96caa6e45255e26663979943`
- **Artifacts:** `decompiled/00105390_cvm_mac_sprintf.c`, `assembly/00105390_cvm_mac_sprintf.asm`
- **Recognized calls:** `memcpy` ×1, `memset` ×1, `snprintf` ×1

## `local_cavium_ethernet_text_005270` @ `0x00105480`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `92cd47a68a20ff9568ccc8ef2c58c2115342be65a418901055a1892f9e3f987a`
- **Artifacts:** `decompiled/00105480_local_cavium_ethernet_text_005270.c`, `assembly/00105480_local_cavium_ethernet_text_005270.asm`
- **Recognized calls:** `cvm_ipfwd_check_timestamp` ×1, `cvm_mac_sprintf` ×1, `cvmx_warn` ×1, `memset` ×2, `seq_printf` ×1, `strcpy` ×4

## `cvm_ipfwd_ct_refresh` @ `0x001058b8`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `8ca2277086cec3b7885b90324896be4748ec6e4adef34e1c24caeda57a67e214`
- **Artifacts:** `decompiled/001058b8_cvm_ipfwd_ct_refresh.c`, `assembly/001058b8_cvm_ipfwd_ct_refresh.asm`
- **Recognized calls:** `__mod_timer` ×1, `cvm_ipfwd_ct_match_find` ×1, `del_timer` ×1, `tcp_ct_conn_timeout` ×1, `udp_ct_conn_timeout` ×1

## `isMarkable` @ `0x00105af0`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `c863c520e72b8ca4cd9e6bc298bdf30d4b27e7315134b8c5e3e351f6f25c77ce`
- **Artifacts:** `decompiled/00105af0_isMarkable.c`, `assembly/00105af0_isMarkable.asm`
- **Recognized calls:** `findInBlockList` ×2

## `cvm_ipfwd_mark_packet` @ `0x00105b60`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `4557fa6744f8ad87e5dc184e129bd2d6a6329abf705611debf4a6ddd4edaaeba`
- **Artifacts:** `decompiled/00105b60_cvm_ipfwd_mark_packet.c`, `assembly/00105b60_cvm_ipfwd_mark_packet.asm`
- **Recognized calls:** `isMarkable` ×1

## `cvm_ipfwd_calculate_ip_header_checksum` @ `0x00105cf8`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `ed70fedc0293979a508f65460742d2de643cf52e6efa87ddc8b3e70f4fd46bed`
- **Artifacts:** `decompiled/00105cf8_cvm_ipfwd_calculate_ip_header_checksum.c`, `assembly/00105cf8_cvm_ipfwd_calculate_ip_header_checksum.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_random_select` @ `0x00105db0`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `3ef917421850741084d37d87cee2515d524432baf12c2314c1cdbda8b9f943d5`
- **Artifacts:** `decompiled/00105db0_cvm_ipfwd_random_select.c`, `assembly/00105db0_cvm_ipfwd_random_select.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_ipfwd_check_bucket_timestamp` @ `0x00105dc0`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `0d250e7a36479a39bd90b16593f9c11cea0f43f54be1a116c3eac114724d151a`
- **Artifacts:** `decompiled/00105dc0_cvm_ipfwd_check_bucket_timestamp.c`, `assembly/00105dc0_cvm_ipfwd_check_bucket_timestamp.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `flushFlowInfo` @ `0x00105df8`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `0e61f43317085af1eadda67e38bb4ef2ad38772846bad71f4fb35cdd41fd435c`
- **Artifacts:** `decompiled/00105df8_flushFlowInfo.c`, `assembly/00105df8_flushFlowInfo.asm`
- **Recognized calls:** `cvm_ipfwd_ptr_flush` ×1, `cvm_ipfwd_ptr_free` ×1, `cvmx_warn` ×1, `printk` ×1

## `cvm_ipfwd_cache_flow` @ `0x00105f80`

- **Subsystem:** octeon-offload
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
- **Decompiler:** success; reconstructed C SHA-256 `bada3b62fe1e208e9455b990e5abf019b1cb1e6ccc50ff9a16cc7bfee5209bcd`
- **Artifacts:** `decompiled/00105f80_cvm_ipfwd_cache_flow.c`, `assembly/00105f80_cvm_ipfwd_cache_flow.asm`
- **Recognized calls:** `__printk_ratelimit` ×1, `cvm_ipfwd_check_timestamp` ×1, `cvm_ipfwd_check_timestamp_just_created` ×1, `cvm_ipfwd_find_entry` ×1, `cvm_ipfwd_get_free_entry` ×1, `cvm_ipfwd_ptr_alloc` ×1, `cvm_ipfwd_ptr_free` ×1, `cvm_ipfwd_setup_entry` ×1, `cvm_ipfwd_setup_flow_info` ×1, `cvmx_warn` ×3, `printk` ×1

## `is_port_authorised` @ `0x00106470`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `84ff7d1d6b4a20e017f4b3d6b394eb5f3c5fed16a3128c4e27cd46b4c4d2b985`
- **Artifacts:** `decompiled/00106470_is_port_authorised.c`, `assembly/00106470_is_port_authorised.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_rx_shutdown` @ `0x00106520`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `67bf9cfc5a0fb60aba6be7d8abc8a7ca81ad6c7a290a24c4dcb1586ad5ddb276`
- **Artifacts:** `decompiled/00106520_cvm_oct_rx_shutdown.c`, `assembly/00106520_cvm_oct_rx_shutdown.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_rx_initialize` @ `0x00106558`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `797c06ba92f369508e4d4610d74ccb69dd63df0627be1a81af6422eae8fd7e92`
- **Artifacts:** `decompiled/00106558_cvm_oct_rx_initialize.c`, `assembly/00106558_cvm_oct_rx_initialize.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `brcmTagDelete` @ `0x001065a8`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Removes/parses the vendor Broadcom switch tag from received traffic.
- **Decompiler:** success; reconstructed C SHA-256 `2285f890a19b4d2d9d2a199230d3490203827407f350ba277152709a66323f49`
- **Artifacts:** `decompiled/001065a8_brcmTagDelete.c`, `assembly/001065a8_brcmTagDelete.asm`
- **Recognized calls:** `memmove` ×1

## `cvm_oct_do_interrupt` @ `0x00106618`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Receive interrupt/tasklet datapath that drains Octeon work entries and submits packets to Linux.
- **Decompiler:** success; reconstructed C SHA-256 `1cbc6562afb5e6d2b892be1f78ecc86501f77d238bd2d7f7deb194a7f5330898`
- **Artifacts:** `decompiled/00106618_cvm_oct_do_interrupt.c`, `assembly/00106618_cvm_oct_do_interrupt.asm`
- **Recognized calls:** `__tasklet_schedule` ×1

## `cvm_oct_tasklet_rx` @ `0x00106708`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Receive interrupt/tasklet datapath that drains Octeon work entries and submits packets to Linux.
- **Decompiler:** success; reconstructed C SHA-256 `2e364210253d1fbf04f7b6d51bc54db78bb5471b4821d0fbd07c8396988105bb`
- **Artifacts:** `decompiled/00106708_cvm_oct_tasklet_rx.c`, `assembly/00106708_cvm_oct_tasklet_rx.asm`
- **Recognized calls:** `__alloc_skb` ×1, `__printk_ratelimit` ×2, `brcmTagDelete` ×1, `cvm_ipfwd_calculate_ip_header_checksum` ×1, `cvm_ipfwd_check_bucket_timestamp` ×1, `cvm_ipfwd_check_timestamp` ×1, `cvm_ipfwd_find_entry` ×1, `cvm_ipfwd_mark_packet` ×1, `cvm_ipfwd_random_select` ×1, `cvm_oct_free_work` ×1, `cvm_oct_mem_fill_fpa_tf1` ×1, `cvm_oct_transmit_qos` ×1, `cvmx_warn` ×12, `eth_type_trans` ×2, `is_port_authorised` ×1, `memcpy` ×2, `memmove` ×5, `netif_receive_skb` ×1, `printk` ×3, `raise_softirq_irqoff` ×3, `skb_over_panic` ×2, `skb_under_panic` ×1, `strncmp` ×1

## `cvm_oct_sgmii_uninit` @ `0x00108240`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `5de0ab489df368d881cb397ddbf295f33e67cf5d847de93ba284039460e3352d`
- **Artifacts:** `decompiled/00108240_cvm_oct_sgmii_uninit.c`, `assembly/00108240_cvm_oct_sgmii_uninit.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_sgmii_init` @ `0x00108260`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Interface-mode-specific Octeon Ethernet initialization retained from the vendor SDK; applicability to RV220W must be established from callers and bootinfo.
- **Decompiler:** success; reconstructed C SHA-256 `ee1a6fe8f02f91dc0c06f78ab2fc8c99e9e3de08aff291ffb7299e2f8f6a49df`
- **Artifacts:** `decompiled/00108260_cvm_oct_sgmii_init.c`, `assembly/00108260_cvm_oct_sgmii_init.asm`
- **Recognized calls:** `cvm_oct_common_init` ×1, `local_cavium_ethernet_text_008400` ×1, `octeon_is_simulation` ×1

## `local_cavium_ethernet_text_008118` @ `0x00108328`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `fd4b025bec654b75cbdfea1cf7999bbcb31c01e3dfa922ef390065ebc5641480`
- **Artifacts:** `decompiled/00108328_local_cavium_ethernet_text_008118.c`, `assembly/00108328_local_cavium_ethernet_text_008118.asm`
- **Recognized calls:** `__printk_ratelimit` ×2, `cvmx_helper_link_autoconf` ×1, `cvmx_helper_link_get` ×1

## `local_cavium_ethernet_text_008400` @ `0x00108610`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `88eb15a873cc97d578207a395a64c94c08ead3819c3ec203eb41cbed84221924`
- **Artifacts:** `decompiled/00108610_local_cavium_ethernet_text_008400.c`, `assembly/00108610_local_cavium_ethernet_text_008400.asm`
- **Recognized calls:** `panic` ×2

## `local_cavium_ethernet_text_008500` @ `0x00108710`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `ee0267df4bd8df0325e287a4c966256376f172638ec9c284951010ef0fb9d7b7`
- **Artifacts:** `decompiled/00108710_local_cavium_ethernet_text_008500.c`, `assembly/00108710_local_cavium_ethernet_text_008500.asm`
- **Recognized calls:** `panic` ×1

## `local_cavium_ethernet_text_008600` @ `0x00108810`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `184621e7ea50dae60347477536560c6be58761ad489e040b157aea67952129a9`
- **Artifacts:** `decompiled/00108810_local_cavium_ethernet_text_008600.c`, `assembly/00108810_local_cavium_ethernet_text_008600.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_spi_init` @ `0x00108878`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Interface-mode-specific Octeon Ethernet initialization retained from the vendor SDK; applicability to RV220W must be established from callers and bootinfo.
- **Decompiler:** success; reconstructed C SHA-256 `b196313f20b552d2aed00e5cf961a919bdc346354464bfd1383c10fbd9bd7d7e`
- **Artifacts:** `decompiled/00108878_cvm_oct_spi_init.c`, `assembly/00108878_cvm_oct_spi_init.asm`
- **Recognized calls:** `cvm_oct_common_init` ×1, `local_cavium_ethernet_text_008600` ×1, `request_irq` ×1

## `local_cavium_ethernet_text_008810` @ `0x00108a20`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `e5ea93393360107dc70d084055fa0abdde4065372c9603c0cc6ff7a7dd71a252`
- **Artifacts:** `decompiled/00108a20_local_cavium_ethernet_text_008810.c`, `assembly/00108a20_local_cavium_ethernet_text_008810.asm`
- **Recognized calls:** `cvmx_spi4000_check_speed` ×1, `cvmx_spi_restart_interface` ×1, `local_cavium_ethernet_text_008600` ×1

## `cvm_oct_spi_uninit` @ `0x00108b90`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `2fbf41ccc46fbcfd49be474f1112a696ee0138069350b83ab2c61dd8c4f037a2`
- **Artifacts:** `decompiled/00108b90_cvm_oct_spi_uninit.c`, `assembly/00108b90_cvm_oct_spi_uninit.asm`
- **Recognized calls:** `cvm_oct_common_uninit` ×1

## `local_cavium_ethernet_text_008a90` @ `0x00108ca0`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `00bdb1c117e2b3f2e2739a5395cddcee5b80177af96d06a2bdab76ae9f29b130`
- **Artifacts:** `decompiled/00108ca0_local_cavium_ethernet_text_008a90.c`, `assembly/00108ca0_local_cavium_ethernet_text_008a90.asm`
- **Recognized calls:** `printk` ×1

## `brcmTagAdd` @ `0x00109b50`

- **Subsystem:** bcm53115-switch
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Adds the vendor Broadcom switch tag to CPU-bound transmit traffic; essential evidence for eventual B53/DSA CPU-port configuration.
- **Decompiler:** success; reconstructed C SHA-256 `f82120e391f6ee50b674b25316604ca92a54042d9e2032791511a23ccdd77b1c`
- **Artifacts:** `decompiled/00109b50_brcmTagAdd.c`, `assembly/00109b50_brcmTagAdd.asm`
- **Recognized calls:** `memcmp` ×1, `memmove` ×3, `memset` ×3, `skb_over_panic` ×2, `skb_under_panic` ×2

## `cvm_oct_tx_shutdown` @ `0x00109ff8`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `ae7334d5fa1286dd4cf936b5edc4c847bdc4c42fd839edc93772208a0c48fc42`
- **Artifacts:** `decompiled/00109ff8_cvm_oct_tx_shutdown.c`, `assembly/00109ff8_cvm_oct_tx_shutdown.asm`
- **Recognized calls:** `dev_kfree_skb_any` ×2

## `cvm_oct_transmit_qos` @ `0x0010a0e0`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Transmit datapath routine, including queue/QoS or POW handling according to the selected entry point.
- **Decompiler:** success; reconstructed C SHA-256 `f0ef1b28f778ea89ad79f231bc16581a0c2d0bdb103cfe9c50fcac172aa6508b`
- **Artifacts:** `decompiled/0010a0e0_cvm_oct_transmit_qos.c`, `assembly/0010a0e0_cvm_oct_transmit_qos.asm`
- **Recognized calls:** `__printk_ratelimit` ×1, `cvm_oct_free_work` ×1, `cvmx_warn` ×3, `printk` ×1, `strncmp` ×4

## `cvm_oct_xmit_pow` @ `0x0010a770`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Transmit datapath routine, including queue/QoS or POW handling according to the selected entry point.
- **Decompiler:** success; reconstructed C SHA-256 `02b7b3701884482683b986b61e121daaa253505a800c78f635b6517a8f011b1a`
- **Artifacts:** `decompiled/0010a770_cvm_oct_xmit_pow.c`, `assembly/0010a770_cvm_oct_xmit_pow.asm`
- **Recognized calls:** `__printk_ratelimit` ×2, `cvmx_warn` ×2, `kfree_skb` ×3, `memcpy` ×3, `printk` ×2

## `cvm_oct_xmit` @ `0x0010ad60`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Transmit datapath routine, including queue/QoS or POW handling according to the selected entry point.
- **Decompiler:** success; reconstructed C SHA-256 `c74eece6817adc49ed87f9df84dafac7b259d17b98efec1abca3d9977353a5be`
- **Artifacts:** `decompiled/0010ad60_cvm_oct_xmit.c`, `assembly/0010ad60_cvm_oct_xmit.asm`
- **Recognized calls:** `__printk_ratelimit` ×1, `brcmTagAdd` ×1, `cvm_ipfwd_cache_flow` ×1, `cvmx_warn` ×4, `dev_kfree_skb_any` ×1, `kfree_skb` ×2, `printk` ×2, `strncmp` ×2

## `cvm_oct_xaui_uninit` @ `0x0010b7e0`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `105b9bc99e1b5e1bbbc552d11535c5b01613a266fc8026f35617bd3ad88fcbde`
- **Artifacts:** `decompiled/0010b7e0_cvm_oct_xaui_uninit.c`, `assembly/0010b7e0_cvm_oct_xaui_uninit.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `cvm_oct_xaui_init` @ `0x0010b800`

- **Subsystem:** octeon-ethernet
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Interface-mode-specific Octeon Ethernet initialization retained from the vendor SDK; applicability to RV220W must be established from callers and bootinfo.
- **Decompiler:** success; reconstructed C SHA-256 `b7b8cec5909059fa5bea82c7848895a8dad9caca532aa3af09530623f28d0489`
- **Artifacts:** `decompiled/0010b800_cvm_oct_xaui_init.c`, `assembly/0010b800_cvm_oct_xaui_init.asm`
- **Recognized calls:** `cvm_oct_common_init` ×1, `local_cavium_ethernet_text_00b670` ×1

## `local_cavium_ethernet_text_00b670` @ `0x0010b880`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `ba5601cc619322bd15dc876dccded4372479ccba5588581fb299ffe7a8da2d40`
- **Artifacts:** `decompiled/0010b880_local_cavium_ethernet_text_00b670.c`, `assembly/0010b880_local_cavium_ethernet_text_00b670.asm`
- **Recognized calls:** `alloc_etherdev` ×2, `allocateCacheMemory` ×1, `create_proc_entry` ×5, `cvm_oct_mem_fill_fpa` ×1, `cvm_oct_proc_initialize` ×1, `cvm_oct_rx_initialize` ×1, `cvmx_helper_get_ipd_port` ×5, `cvmx_helper_get_number_of_interfaces` ×2, `cvmx_helper_initialize_packet_io_global` ×1, `cvmx_helper_interface_get_mode` ×1, `cvmx_helper_ipd_and_packet_input_enable` ×1, `cvmx_helper_ports_on_interface` ×2, `cvmx_helper_setup_red` ×1, `hwOffloadSysctlRegister` ×1, `init_timer` ×1, `ip_fastfwd_proc_tbl_init` ×1, `kfree` ×3, `memset` ×3, `mod_timer` ×1, `octeon_is_simulation` ×1, `panic` ×2, `printk` ×19, `register_netdev` ×2, `register_sysctl_table` ×3, `request_irq` ×1, `strcpy` ×1

## `local_cavium_ethernet_text_00b770` @ `0x0010b980`

- **Subsystem:** octeon-ethernet
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
- **Decompiler:** success; reconstructed C SHA-256 `6190b16a712dda90cb68630f8f1862e46f5751519237e88453e89d85626154bb`
- **Artifacts:** `decompiled/0010b980_local_cavium_ethernet_text_00b770.c`, `assembly/0010b980_local_cavium_ethernet_text_00b770.asm`
- **Recognized calls:** `alloc_etherdev` ×2, `allocateCacheMemory` ×1, `create_proc_entry` ×5, `cvm_oct_mem_fill_fpa` ×1, `cvm_oct_proc_initialize` ×1, `cvm_oct_rx_initialize` ×1, `cvmx_helper_get_ipd_port` ×5, `cvmx_helper_get_number_of_interfaces` ×2, `cvmx_helper_initialize_packet_io_global` ×1, `cvmx_helper_interface_get_mode` ×1, `cvmx_helper_ipd_and_packet_input_enable` ×1, `cvmx_helper_ports_on_interface` ×2, `cvmx_helper_setup_red` ×1, `hwOffloadSysctlRegister` ×1, `init_timer` ×1, `ip_fastfwd_proc_tbl_init` ×1, `kfree` ×3, `memset` ×3, `mod_timer` ×1, `octeon_is_simulation` ×1, `panic` ×1, `printk` ×19, `register_netdev` ×2, `register_sysctl_table` ×3, `request_irq` ×1, `strcpy` ×1

## `init_module` @ `0x0010ba80`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Vendor Octeon Ethernet module entry point: discovers interfaces/ports, allocates resources, registers network devices and offload controls.
- **Decompiler:** success; reconstructed C SHA-256 `43976346e1fd727f4d7c2590664335cf293817ef7fb700a9e9a1990ad9a210a4`
- **Artifacts:** `decompiled/0010ba80_init_module.c`, `assembly/0010ba80_init_module.asm`
- **Recognized calls:** `alloc_etherdev` ×2, `allocateCacheMemory` ×1, `create_proc_entry` ×5, `cvm_oct_mem_fill_fpa` ×1, `cvm_oct_proc_initialize` ×1, `cvm_oct_rx_initialize` ×1, `cvmx_helper_get_ipd_port` ×5, `cvmx_helper_get_number_of_interfaces` ×2, `cvmx_helper_initialize_packet_io_global` ×1, `cvmx_helper_interface_get_mode` ×1, `cvmx_helper_ipd_and_packet_input_enable` ×1, `cvmx_helper_ports_on_interface` ×2, `cvmx_helper_setup_red` ×1, `hwOffloadSysctlRegister` ×1, `init_timer` ×1, `ip_fastfwd_proc_tbl_init` ×1, `kfree` ×3, `memset` ×3, `mod_timer` ×1, `octeon_is_simulation` ×1, `printk` ×19, `register_netdev` ×2, `register_sysctl_table` ×3, `request_irq` ×1, `strcpy` ×1

## `cleanup_module` @ `0x0010cc08`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Module teardown path; reverses registrations and frees runtime resources.
- **Decompiler:** success; reconstructed C SHA-256 `1be0c56acec291f2461b074ce5460844b120e6b7f59e3699bdc9da8475a2894a`
- **Artifacts:** `decompiled/0010cc08_cleanup_module.c`, `assembly/0010cc08_cleanup_module.asm`
- **Recognized calls:** `__printk_ratelimit` ×1, `cvm_ipfwd_ptr_flush` ×1, `cvm_oct_mem_empty_fpa` ×1, `cvm_oct_proc_shutdown` ×1, `cvm_oct_rx_shutdown` ×1, `cvm_oct_tx_shutdown` ×1, `cvmx_pko_disable` ×1, `cvmx_pko_shutdown` ×1, `cvmx_warn` ×5, `del_timer` ×1, `free_irq` ×1, `hwOffloadSysctlUnregister` ×1, `kfree` ×1, `printk` ×4, `remove_proc_entry` ×4, `unregister_netdev` ×1, `unregister_sysctl_table` ×3
