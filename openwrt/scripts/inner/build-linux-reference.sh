#!/usr/bin/env bash
set -euo pipefail
jobs=${RV220W_JOBS:-1}
workspace=${RV220W_WORKSPACE:?}
cross=${RV220W_LINUX_CROSS_COMPILE:-mips64-linux-gnuabi64-}
src="$workspace/sources/linux-reference"
out="$workspace/build/linux-reference"
artifacts="$workspace/artifacts/linux-reference"
logs="$workspace/logs"
mkdir -p "$out" "$artifacts" "$logs"
command -v "${cross}gcc" >/dev/null 2>&1 || { echo "Missing cross compiler: ${cross}gcc" >&2; exit 1; }

if [[ ${RV220W_CLEAN:-0} == 1 ]]; then
    rm -rf "$out"
    mkdir -p "$out"
fi

cd "$src"
if [[ ! -f "$out/.config" ]]; then
    make O="$out" ARCH=mips CROSS_COMPILE="$cross" cavium_octeon_defconfig
fi

# Keep this a conservative reference kernel.  OpenWrt's managed kernel remains
# the authoritative image source until the RV220W DTS/board support is promoted.
./scripts/config --file "$out/.config" \
    -e CPU_CAVIUM_OCTEON \
    -e 64BIT \
    -e PCI \
    -e SERIAL_8250 \
    -e SERIAL_8250_CONSOLE \
    -e DEVTMPFS \
    -e DEVTMPFS_MOUNT \
    -e BLK_DEV_INITRD \
    -e RD_GZIP \
    -e MTD \
    -e MTD_CFI \
    -e MTD_CFI_AMDSTD \
    -e MTD_PHYSMAP \
    -e OF \
    -e OF_EARLY_FLATTREE
make O="$out" ARCH=mips CROSS_COMPILE="$cross" olddefconfig
cp "$out/.config" "$artifacts/linux-cn5010-reference.config"

if [[ ${RV220W_MENUCONFIG:-0} == 1 ]]; then
    exec make O="$out" ARCH=mips CROSS_COMPILE="$cross" menuconfig
fi

if ! make O="$out" ARCH=mips CROSS_COMPILE="$cross" -j"$jobs" vmlinux dtbs 2>&1 | tee "$logs/linux-reference-build.log"; then
    echo 'Parallel reference-kernel build failed; retrying serially with V=1.' >&2
    make O="$out" ARCH=mips CROSS_COMPILE="$cross" -j1 V=1 vmlinux dtbs 2>&1 | tee "$logs/linux-reference-build-serial.log"
fi

cp "$out/vmlinux" "$artifacts/vmlinux-cn5010-reference"
file "$artifacts/vmlinux-cn5010-reference"
readelf -h "$artifacts/vmlinux-cn5010-reference" > "$artifacts/vmlinux-cn5010-reference.readelf.txt"
sha256sum "$artifacts/vmlinux-cn5010-reference" > "$artifacts/vmlinux-cn5010-reference.sha256"
find "$out/arch/mips/boot/dts" -type f -name '*.dtb' -print0 2>/dev/null \
    | xargs -0 -r cp -t "$artifacts" --
printf '%s\n' \
  "Cross compiler: $cross" \
  'Reference kernel only: do not boot until an RV220W-specific DTS and boot contract are verified.' \
  > "$artifacts/NOT-FOR-BOOT-YET.txt"
