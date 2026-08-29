# Import normalization report

## Source

- Archive: `rv220w-research(1).7z`
- SHA-256: `87f2cb196aaab0a4f9264b6d56ad421ec307c5848a9b14c339cbe3466c8467c3`
- Extracted root: `rv220w-research/`
- Original Git commit: `b95c6f6` (`First commit, pulls in all initial data from the system`)

## Structural changes

- Replaced the flat numbered-document series with topic-oriented canonical documentation under `docs/`.
- Preserved the imported document snapshots under `archive/import/legacy-documents/`.
- Merged the separate OpenWrt promotion toolkit into `openwrt/`.
- Moved canonical executable tools to `tools/`.
- Moved hardware maps, measurements, and templates to `hardware/`.
- Moved images, partitions, filesystems, and reports to `firmware/`.
- Consolidated photographic evidence under `evidence/photos/`.

## Duplicates removed

- Removed the second byte-identical copies of:
  - `dump_uboot_flash_uart.py`
  - `extract_jffs2_be.py`
- Replaced overlapping JP1 candidate/confirmed documents with one `hardware/pinouts/jp1-jp2-interfaces.md`.
- Removed nested release archives after unpacking their canonical contents.
- Removed the nested `rv220w-research.zip` copy.
- Removed stale `APPLY.md` and `APPLY-README.md` patch-install notes.
- Omitted the redacted public board overview because the unredacted source and direct stitches are retained.

## Firmware normalization

- Unpacked physical partitions, derived boot/kernel components, analysis reports, rootfs, and JFFS2 data.
- Reconstructed `firmware/images/rv220w-flash-32MiB-canonical.bin` by concatenating the verified non-overlapping partition set.
- Verified the reconstructed full-image SHA-256 as:
  `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`.
- Retained the JFFS2 contents without redaction, including the obsolete HTTPS certificate and private key.

## Distribution policy

Large binary evidence is excluded from the core Git bundle and distributed in overlay archives. Extract all overlays into the same workspace root.

The original 2.0.0 overlay inventories are preserved as `rv220w-research-2.0.0-core-overlay.sha256` and `rv220w-research-2.0.0-full-overlay.sha256`. The repository-root `MANIFEST.core.sha256` now covers only the Git-visible tree, so it can be verified from a clean clone without unavailable preservation overlays.
