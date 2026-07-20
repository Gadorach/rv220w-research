#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'j/jobs=' 'c/clean' 'm/menuconfig' -- $argv; or exit 2
set -l jobs (nproc)
set -q _flag_jobs; and set jobs $_flag_jobs
rv_box_exists; or rv_die 'Build Distrobox is not ready; run setup-box'
test -d "$RV220W_WORKSPACE/sources/linux-reference/.git"; or rv_die 'Linux source is missing; run prepare-sources'
mkdir -p "$RV220W_TOOLKIT_ROOT/work" "$RV220W_WORKSPACE/artifacts/linux-reference" "$RV220W_WORKSPACE/logs"
set -l inner "$RV220W_TOOLKIT_ROOT/work/build-linux-reference-inner.sh"
cat > "$inner" <<'BASH'
#!/usr/bin/env bash
set -euo pipefail
jobs=${RV220W_JOBS:-1}
workspace=${RV220W_WORKSPACE:?}
src="$workspace/sources/linux-reference"
out="$workspace/build/linux-reference"
artifacts="$workspace/artifacts/linux-reference"
logs="$workspace/logs"
mkdir -p "$out" "$artifacts" "$logs"

if [[ ${RV220W_CLEAN:-0} == 1 ]]; then
    rm -rf "$out"
    mkdir -p "$out"
fi

cd "$src"
if [[ ! -f "$out/.config" ]]; then
    make O="$out" ARCH=mips cavium_octeon_defconfig
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
make O="$out" ARCH=mips olddefconfig
cp "$out/.config" "$artifacts/linux-cn5010-reference.config"

if [[ ${RV220W_MENUCONFIG:-0} == 1 ]]; then
    exec make O="$out" ARCH=mips menuconfig
fi

if ! make O="$out" ARCH=mips -j"$jobs" vmlinux dtbs 2>&1 | tee "$logs/linux-reference-build.log"; then
    echo 'Parallel reference-kernel build failed; retrying serially with V=1.' >&2
    make O="$out" ARCH=mips -j1 V=1 vmlinux dtbs 2>&1 | tee "$logs/linux-reference-build-serial.log"
fi

cp "$out/vmlinux" "$artifacts/vmlinux-cn5010-reference"
file "$artifacts/vmlinux-cn5010-reference"
readelf -h "$artifacts/vmlinux-cn5010-reference" > "$artifacts/vmlinux-cn5010-reference.readelf.txt"
sha256sum "$artifacts/vmlinux-cn5010-reference" > "$artifacts/vmlinux-cn5010-reference.sha256"
find "$out/arch/mips/boot/dts" -type f -name '*.dtb' -print0 2>/dev/null \
    | xargs -0 -r cp -t "$artifacts" --
printf '%s\n' \
  'Reference kernel only: do not boot until an RV220W-specific DTS and boot contract are verified.' \
  > "$artifacts/NOT-FOR-BOOT-YET.txt"
BASH
chmod +x "$inner"
set -l clean 0
set -q _flag_clean; and set clean 1
set -l menu 0
set -q _flag_menuconfig; and set menu 1
rv_info "Building the standalone Linux Octeon reference tree in $RV220W_BOX with $jobs job(s)."
distrobox enter "$RV220W_BOX" -- env \
    RV220W_JOBS="$jobs" \
    RV220W_CLEAN="$clean" \
    RV220W_MENUCONFIG="$menu" \
    RV220W_WORKSPACE="$RV220W_WORKSPACE" \
    bash "$inner"; or rv_die 'Linux reference build failed'
rv_info "Reference kernel artifacts: $RV220W_WORKSPACE/artifacts/linux-reference"
