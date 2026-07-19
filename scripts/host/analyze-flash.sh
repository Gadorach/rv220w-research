#!/bin/sh
set -eu

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 full-flash.bin" >&2
    exit 2
fi

IMAGE=$1
[ -f "$IMAGE" ] || { echo "Not a file: $IMAGE" >&2; exit 1; }

python3 "$(dirname "$0")/firmware_inventory.py" "$IMAGE" --json "$IMAGE.inventory.json"
sha256sum "$IMAGE" > "$IMAGE.sha256"
file "$IMAGE" | tee "$IMAGE.file.txt"

if command -v binwalk >/dev/null 2>&1; then
    binwalk "$IMAGE" | tee "$IMAGE.binwalk.txt"
else
    echo "binwalk not installed; skipped" >&2
fi
