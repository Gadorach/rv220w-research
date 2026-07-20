#!/bin/sh
# Read-only MTD dumper. Run from writable storage with enough free space.
set -eu

OUT=${1:-/tmp/rv220w-mtd-dump}
mkdir -p "$OUT"

if [ ! -r /proc/mtd ]; then
    echo "/proc/mtd is not readable" >&2
    exit 1
fi

cp /proc/mtd "$OUT/proc-mtd.txt"

while IFS= read -r line; do
    case "$line" in
        mtd[0-9]*:*)
            dev=${line%%:*}
            name=$(printf '%s\n' "$line" | sed -n 's/.*"\(.*\)".*/\1/p' | tr '/ ' '__')
            [ -n "$name" ] || name=unnamed
            src="/dev/$dev"
            dst="$OUT/${dev}-${name}.bin"
            echo "Reading $src -> $dst"
            if command -v nanddump >/dev/null 2>&1; then
                # The platform is expected to use NOR, but nanddump is avoided unless
                # the MTD reports NAND and the operator explicitly adapts this script.
                :
            fi
            dd if="$src" of="$dst" bs=64k conv=sync,noerror
            sync
            ;;
    esac
done < /proc/mtd

( cd "$OUT" && sha256sum ./*.bin > SHA256SUMS )
echo "MTD dumps written to $OUT"
