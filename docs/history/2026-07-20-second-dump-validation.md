# RV220W second full-flash dump validation

**Validation date:** 2026-07-20  
**Flash size:** `0x02000000` bytes / 32 MiB  
**Result:** **The two independent dumps are byte-for-byte identical.**

## Full-image result

| Capture | Started | Resumed from | Baud | Target CRC before | Target CRC after | Host CRC | SHA-256 | Retries |
|---|---|---:|---:|---|---|---|---|---:|
| Read 1 | `2026-07-20T03:33:03+00:00` | `0x30000` | 460800 | `ce96f3e0` | `ce96f3e0` | `ce96f3e0` | `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5` | 0 |
| Read 2 | `2026-07-20T04:42:13+00:00` | `0x0` | 460800 | `ce96f3e0` | `ce96f3e0` | `ce96f3e0` | `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5` | 0 |

Host comparison:

```text
size read 1: 33554432 bytes
size read 2: 33554432 bytes
cmp:         identical
CRC32:       ce96f3e0
SHA-256:     03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
```

The second capture began at offset `0x0`, completed all 512 chunks, and had no retries. It therefore provides a clean independent validation of the resumed first capture.

## Partition-by-partition comparison

| Region | Offset | Size | CRC32 | SHA-256 | Match |
|---|---:|---:|---:|---|:---:|
| `00-bootloader-combined` | `0x00000000` | `0x00080000` | `483548c0` | `0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d` | Yes |
| `00a-boot-stub` | `0x00000000` | `0x00030000` | `208d4c20` | `72389f1958bd8ec570eeafefc30c80227a85234a626eacfa1bb80fac064f322f` | Yes |
| `00b-u-boot` | `0x00030000` | `0x00050000` | `b0a21f65` | `1b68453e055dee56a8724b17a927df36ff201a44c8e450c5d17a3b8e9117000d` | Yes |
| `01-kernel-partition` | `0x00080000` | `0x00600000` | `699dccf5` | `a4aadfe8aff6d44157672efd5c52c3f1d403195da90adedbea26d9b44499a8b4` | Yes |
| `02-rootfs-squashfs3-be` | `0x00680000` | `0x01000000` | `2083f99f` | `e1360881a07134108d00f2b5aec1baf1507698513be8c63f232d4b8377a2de88` | Yes |
| `03-data-jffs2-be` | `0x01680000` | `0x00100000` | `8c3e87c4` | `3cc145af5ac33036e5390ca4525fe074a4cb49f192fd979b7837adfe89f5194d` | Yes |
| `04-linux-named-bootload-env` | `0x01780000` | `0x00020000` | `154803cc` | `b5a41c3758763bbec72769fab4a2533bf2db0b6312d93d25a695f9e4b9e02260` | Yes |
| `05-unmapped-vendor-tail` | `0x017a0000` | `0x00840000` | `024ebe1f` | `47ebe237a3987f843fc19b0f801ce1edc1690768ef6b18e4b03a12ca6b298358` | Yes |
| `06-u-boot-env-actual` | `0x01fe0000` | `0x00020000` | `6fa62107` | `4fcd18a84d33a0fb0d7e25c11d631978ff27a274c14fea7764d25fdd1287a1e6` | Yes |

All previously extracted v0.9.0 physical partition files also match the corresponding slices of the second image exactly.

## Preservation conclusion

The flash-preservation gate can now be considered complete:

- two full 32 MiB images exist;
- the images are byte-identical;
- target CRC32 was stable before and after each acquisition;
- host CRC32 matches the target;
- the complete SHA-256 matches across both reads;
- every defined and unmapped partition region matches independently.

No flash content changed between the two acquisition sessions.

## Recommended handling

1. Preserve both original images under distinct filenames.
2. Store at least one copy offline or read-only.
3. Retain the JSON metadata and compressed UART logs beside each image.
4. Before any future flash write, verify the expected SHA-256:
   `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`
5. Continue using the extracted v0.9.0 partition set; re-extraction is not necessary because it matches both source images.
