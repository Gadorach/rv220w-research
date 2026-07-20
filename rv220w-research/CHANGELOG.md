# Changelog

## 1.0.0 — organized research baseline

- Rebuilt the chat-derived package into a coherent directory hierarchy.
- Replaced 29 overlapping numbered documents with canonical topic documents and a small history section.
- Removed duplicate copies of the UART dumper and JFFS2 extractor.
- Moved all executable tools into `tools/` and adjusted the OpenWrt fish workflows to use them.
- Unpacked nested firmware archives into canonical images, partitions, derived components, reports, and filesystems.
- Reconstructed the verified canonical 32 MiB image from the partition set.
- Retained unredacted factory-reset JFFS2 contents, including the obsolete HTTPS private key.
- Removed stale apply notes, nested release ZIPs, duplicate release artifacts, and broken documentation links.
- Added import provenance, legacy-document mapping, package manifests, and split distribution volumes.
