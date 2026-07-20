#!/usr/bin/env bash
set -euo pipefail
if [[ $# -ne 2 ]]; then
  echo "usage: $0 ANALYSIS_DIR OUTPUT_DIR" >&2
  exit 2
fi
analysis=$1
out=$2
rootfs="$analysis/partitions/02-rootfs.squashfs3-be.bin"
data="$analysis/partitions/03-data.jffs2-be.bin"
mkdir -p "$out"
if ! command -v unsquashfs >/dev/null; then
  echo "unsquashfs is required for SquashFS extraction (package: squashfs-tools)" >&2
  exit 2
fi
unsquashfs -no-progress -d "$out/rootfs" "$rootfs"
python3 "$(dirname "$0")/extract_jffs2_be.py" "$data" "$out/data-jffs2" --report "$out/data-jffs2-report.json"
echo "WARNING: $out/data-jffs2 contains a private HTTPS key and logs." >&2
