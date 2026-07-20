#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'j/jobs=' 'c/clean' 'v/verbose' -- $argv; or exit 2
if test (count $argv) -lt 1
    echo 'Usage: ./rv220w.fish build MODE [--jobs N] [--clean]' >&2
    echo 'MODE: initramfs | squashfs | squashfs-live | menuconfig | kernel | clean' >&2
    exit 2
end
set -l mode $argv[1]
set -l jobs (nproc)
set -q _flag_jobs; and set jobs $_flag_jobs
rv_box_exists; or rv_die 'Build Distrobox is not ready; run setup-box'
test -d "$RV220W_WORKSPACE/sources/openwrt/.git"; or rv_die 'OpenWrt source is missing; run prepare-sources'
mkdir -p "$RV220W_TOOLKIT_ROOT/work" "$RV220W_WORKSPACE/artifacts" "$RV220W_WORKSPACE/logs"
set -l inner "$RV220W_TOOLKIT_ROOT/work/build-openwrt-inner.sh"
cat > "$inner" <<'BASH'
#!/usr/bin/env bash
set -euo pipefail
mode=${RV220W_BUILD_MODE:?}
jobs=${RV220W_JOBS:-1}
toolkit=${RV220W_TOOLKIT_ROOT:?}
workspace=${RV220W_WORKSPACE:?}
openwrt="$workspace/sources/openwrt"
artifacts="$workspace/artifacts"
logs="$workspace/logs"
mkdir -p "$artifacts" "$logs"
cd "$openwrt"

if [[ ${RV220W_CLEAN:-0} == 1 && "$mode" != clean ]]; then
    make clean
fi

sync_base_files() {
    rm -rf files
    mkdir -p files
    rsync -a "$toolkit/files/base/" files/
    printf '%s\n' \
      'RV220W generic Octeon RAM-validation build' \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}

configure() {
    local seed=$1
    cp "$toolkit/config/$seed" .config
    make defconfig
    cp .config "$artifacts/${seed%.config}.expanded.config"
}

download_sources() {
    make -j"$jobs" download
    local bad
    bad=$(find dl -type f -size -1024c -print || true)
    if [[ -n "$bad" ]]; then
        printf 'Suspiciously small downloads:\n%s\n' "$bad" >&2
        return 1
    fi
}

build_world() {
    local label=$1
    download_sources
    local verbosity=()
    if [[ ${RV220W_VERBOSE:-0} == 1 ]]; then verbosity=(V=s); fi
    if ! make -j"$jobs" "${verbosity[@]}" 2>&1 | tee "$logs/$label-build.log"; then
        echo 'Parallel build failed; rerunning serially with V=s for diagnostics.' >&2
        make -j1 V=s 2>&1 | tee "$logs/$label-build-serial.log"
    fi
}

find_initramfs() {
    find bin/targets/octeon/generic -maxdepth 1 -type f -name '*generic-initramfs-kernel.bin' -printf '%T@ %p\n' \
      | sort -nr | head -1 | cut -d' ' -f2-
}

verify_elf() {
    local image=$1
    file "$image"
    readelf -h "$image" > "$image.readelf.txt"
    grep -q 'Class:.*ELF64' "$image.readelf.txt"
    grep -q 'Data:.*big endian' "$image.readelf.txt"
    grep -q 'Machine:.*MIPS' "$image.readelf.txt"
    python3 - "$image" <<'PY'
import pathlib,sys
p=pathlib.Path(sys.argv[1]); b=p.read_bytes()
if b[:4] != b'\x7fELF': raise SystemExit('not an ELF at offset zero')
load=0x05500000; limit=0x07f00000
end=load+len(b)
print(f'image size=0x{len(b):x}; load range=0x{load:08x}..0x{end:08x}; conservative limit=0x{limit:08x}')
if end > limit: raise SystemExit('image exceeds conservative U-Boot source-buffer window')
PY
}

stage_initramfs() {
    local label=$1
    local image
    image=$(find_initramfs)
    [[ -n "$image" && -f "$image" ]] || { echo 'initramfs kernel artifact not found' >&2; exit 1; }
    verify_elf "$image"
    cp "$image" "$artifacts/$label.elf"
    cp "$image.readelf.txt" "$artifacts/$label.readelf.txt"
    sha256sum "$artifacts/$label.elf" > "$artifacts/$label.elf.sha256"
    echo "$artifacts/$label.elf"
}

find_or_make_squashfs() {
    local found
    found=$(find bin/targets/octeon/generic -maxdepth 1 -type f \( -name 'root.squashfs' -o -name '*rootfs.squashfs' \) -printf '%T@ %p\n' \
      | sort -nr | head -1 | cut -d' ' -f2-)
    if [[ -n "$found" && -f "$found" ]]; then
        echo "$found"
        return
    fi
    local root tool output
    root=$(find build_dir -maxdepth 3 -type d -name 'root-octeon' | head -1)
    [[ -n "$root" ]] || { echo 'OpenWrt target root directory not found' >&2; exit 1; }
    tool=$(find staging_dir/host/bin -maxdepth 1 -type f \( -name mksquashfs4 -o -name mksquashfs \) | head -1)
    [[ -n "$tool" ]] || { echo 'OpenWrt host mksquashfs tool not found' >&2; exit 1; }
    output="$artifacts/rv220w-openwrt-rootfs.squashfs"
    "$tool" "$root" "$output" -noappend -all-root -b 262144 -comp xz
    echo "$output"
}

build_squashfs() {
    sync_base_files
    configure openwrt-squashfs.config
    build_world rv220w-squashfs
    local rootfs
    rootfs=$(find_or_make_squashfs)
    if [[ "$(readlink -f "$rootfs")" != "$(readlink -f "$artifacts/rv220w-openwrt-rootfs.squashfs")" ]]; then
        cp "$rootfs" "$artifacts/rv220w-openwrt-rootfs.squashfs"
    fi
    sha256sum "$artifacts/rv220w-openwrt-rootfs.squashfs" > "$artifacts/rv220w-openwrt-rootfs.squashfs.sha256"
    file "$artifacts/rv220w-openwrt-rootfs.squashfs"
}

case "$mode" in
  initramfs)
    sync_base_files
    configure openwrt-initramfs.config
    build_world rv220w-initramfs
    stage_initramfs rv220w-openwrt-generic-initramfs
    ;;
  squashfs)
    build_squashfs
    ;;
  squashfs-live)
    build_squashfs
    sync_base_files
    mkdir -p files/rv220w
    cp "$artifacts/rv220w-openwrt-rootfs.squashfs" files/rv220w/rootfs.squashfs
    cp "$toolkit/files/squashfs-live/init" files/init
    chmod +x files/init
    configure openwrt-squashfs-live.config
    build_world rv220w-squashfs-live
    stage_initramfs rv220w-openwrt-squashfs-live
    ;;
  kernel)
    sync_base_files
    configure openwrt-initramfs.config
    download_sources
    make -j"$jobs" target/linux/compile V=s 2>&1 | tee "$logs/rv220w-kernel-build.log"
    ;;
  menuconfig)
    sync_base_files
    [[ -f .config ]] || configure openwrt-initramfs.config
    exec make menuconfig
    ;;
  clean)
    make clean
    ;;
  *)
    echo "unknown build mode: $mode" >&2
    exit 2
    ;;
esac
BASH
chmod +x "$inner"
set -l clean 0
set -q _flag_clean; and set clean 1
set -l verbose 0
set -q _flag_verbose; and set verbose 1
rv_info "Building OpenWrt mode '$mode' in $RV220W_BOX with $jobs job(s)."
distrobox enter "$RV220W_BOX" -- env \
    RV220W_BUILD_MODE="$mode" \
    RV220W_JOBS="$jobs" \
    RV220W_CLEAN="$clean" \
    RV220W_VERBOSE="$verbose" \
    RV220W_TOOLKIT_ROOT="$RV220W_TOOLKIT_ROOT" \
    RV220W_WORKSPACE="$RV220W_WORKSPACE" \
    bash "$inner"; or rv_die "OpenWrt build mode '$mode' failed"
rv_info "Build complete. Artifacts: $RV220W_WORKSPACE/artifacts"
