# mii.ko — per-function annotations

> All C is Ghidra reconstruction, not original Cisco source. Confidence is deliberately conservative.

## `mii_phy_read` @ `0x00100050`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Recovered exported wrapper around TF1_cvm_oct_mdio_read; brackets the transaction with bottom-half exclusion.
- **Decompiler:** success; reconstructed C SHA-256 `ac4ea99f3dab7778fcfa86b476e3785285f7115b31aceafd4ea8b1d33f95e210`
- **Artifacts:** `decompiled/00100050_mii_phy_read.c`, `assembly/00100050_mii_phy_read.asm`
- **Recognized calls:** `TF1_cvm_oct_mdio_read` ×1, `local_bh_disable` ×1, `local_bh_enable` ×1

## `mii_phy_write` @ `0x00100108`

- **Subsystem:** mdio-pseudophy
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Recovered exported wrapper around cvm_oct_mdio_write; brackets the transaction with bottom-half exclusion.
- **Decompiler:** success; reconstructed C SHA-256 `bbb84cbe22b12409cf76c9209ff2203c2c8102419e95ef1e4cd8a349d54fa384`
- **Artifacts:** `decompiled/00100108_mii_phy_write.c`, `assembly/00100108_mii_phy_write.asm`
- **Recognized calls:** `cvm_oct_mdio_write` ×1, `local_bh_disable` ×1, `local_bh_enable` ×1

## `cleanup_module` @ `0x001001b0`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Module teardown path; reverses registrations and frees runtime resources.
- **Decompiler:** success; reconstructed C SHA-256 `46393b640ab99a083c3e90b269bf0896dc79cf337cfe564f8c61272cfe4a7138`
- **Artifacts:** `decompiled/001001b0_cleanup_module.c`, `assembly/001001b0_cleanup_module.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `init_module` @ `0x001001e8`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
- **Decompiler:** success; reconstructed C SHA-256 `5a11a8d85c3c68ddad5420492ca65307d058739f724c5dea7dc18f20e35c309c`
- **Artifacts:** `decompiled/001001e8_init_module.c`, `assembly/001001e8_init_module.asm`
- **Recognized calls:** `printk` ×1
