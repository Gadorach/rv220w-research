#!/usr/bin/env bash
set -euo pipefail
root=${RV220W_RELEASE_ROOT:?}
workspace=${RV220W_WORKSPACE:?}
mode=${1:-all}
jobs=${RV220W_JOBS:-$(nproc)}
tree="$workspace/sources/openwrt"
art="$workspace/artifacts"
logs="$workspace/logs"
mkdir -p "$art" "$logs"
[[ -d "$tree/.git" ]] || { echo 'OpenWrt sources missing; run make sources' >&2; exit 1; }
python3 "$root/scripts/release/apply-openwrt.py" "$tree" --verify

run_make() { setsid make </dev/null "$@"; }
sync_files() {
  local profile=$1
  cd "$tree"
  rm -rf files
  mkdir -p files
  rsync -a "$root/files/" files/
  if [[ $profile == initramfs ]]; then
    rm -f files/etc/modules.conf \
      files/etc/uci-defaults/97-rv220w-wifi-production-defaults \
      files/etc/uci-defaults/98-rv220w-wlan-led-defaults
    rsync -a "$root/installer-files/" files/
    cat > files/etc/banner <<'EOF'
Cisco RV220W OpenWrt installer / recovery RAM boot
LAN: 192.168.1.1
Production LuCI/Wi-Fi intentionally not loaded in initramfs.
Use the host-side make initramfs-liveboot workflow for permanent installation.
EOF
  fi
  cat > files/etc/rv220w-build <<EOF
RV220W OpenWrt release $(cat "$root/VERSION")
Profile: $profile
OpenWrt: $(git describe --always --tags)
Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)
EOF
}
validate_config() {
  local profile=$1
  grep -qxF 'CONFIG_TARGET_PREINIT_IP="192.168.1.1"' .config
  if grep -qxF 'CONFIG_PACKAGE_B43_DEBUG=y' .config; then echo 'release build unexpectedly enables B43_DEBUG' >&2; exit 1; fi
  if grep -qxF 'CONFIG_PACKAGE_tcpdump-mini=y' .config; then echo 'release build unexpectedly includes tcpdump-mini' >&2; exit 1; fi
  grep -qxF 'CONFIG_PACKAGE_mtd=y' .config
  grep -qxF 'CONFIG_PACKAGE_kmod-dsa-b53=y' .config
  grep -qxF 'CONFIG_PACKAGE_kmod-dsa-b53-mdio=y' .config

  if [[ $profile == sysupgrade ]]; then
    grep -qxF 'CONFIG_PACKAGE_kmod-b43=y' .config
    grep -qxF 'CONFIG_PACKAGE_kmod-ssb=y' .config
    grep -qxF 'CONFIG_PACKAGE_B43_PHY_N=y' .config
    grep -qxF 'CONFIG_PACKAGE_B43_PIO=y' .config
    grep -qxF 'CONFIG_PACKAGE_wpad=y' .config
    grep -qxF 'CONFIG_PACKAGE_luci-light=y' .config
    grep -qxF 'CONFIG_PACKAGE_luci-app-package-manager=y' .config
    grep -qxF 'CONFIG_PACKAGE_kmod-leds-gpio=y' .config
    grep -qxF 'CONFIG_PACKAGE_kmod-ledtrig-network=y' .config
  else
    # The RAM installer is intentionally LAN-only. Reject accidental growth
    # back into the production LuCI/Wi-Fi profile because every MiB matters on
    # this 128 MiB target while the sysupgrade tar is also resident in tmpfs.
    for sym in CONFIG_PACKAGE_kmod-b43 CONFIG_PACKAGE_wpad CONFIG_PACKAGE_luci-light CONFIG_PACKAGE_luci-app-package-manager CONFIG_PACKAGE_uhttpd; do
      if grep -qx "${sym}=y" .config; then echo "installer initramfs unexpectedly enables ${sym}" >&2; exit 1; fi
    done
  fi
}
configure() {
  local seed=$1 profile=$2
  sync_files "$profile"
  cd "$tree"
  cp "$root/config/$seed" .config
  run_make defconfig
  cp .config "$art/${seed%.config}.expanded.config"
  validate_config "$profile"
}
download_and_build() {
  local label=$1
  cd "$tree"
  run_make -j"$jobs" download
  if find dl -type f -size -1024c -print | grep -q .; then
    echo 'Suspiciously small OpenWrt downloads detected' >&2; exit 1
  fi
  local log="$logs/$label-build.log"
  if ! { printf '[rv220w-release] label=%s utc=%s jobs=%s\n' "$label" "$(date -u +%Y-%m-%dT%H:%M:%SZ)" "$jobs"; run_make -j"$jobs" world; } 2>&1 | tee "$log"; then
    echo 'Parallel build failed; retrying serially with V=s' >&2
    run_make -j1 world V=s 2>&1 | tee "$logs/$label-build-serial.log"
  fi
}
verify_elf() {
  local image=$1
  file "$image"
  readelf -h "$image" > "$image.readelf.txt"
  grep -q 'Class:.*ELF64' "$image.readelf.txt"
  grep -q 'Data:.*big endian' "$image.readelf.txt"
  grep -q 'Machine:.*MIPS' "$image.readelf.txt"
}
find_initramfs() { find "$tree/bin/targets/octeon/generic" -maxdepth 1 -type f -name '*-cisco_rv220w_persistent_writer-initramfs-kernel.bin' -printf '%T@ %p\n' | sort -nr | sed -n '1p' | cut -d' ' -f2-; }
find_kernel() { find "$tree/bin/targets/octeon/generic" -maxdepth 1 -type f -name '*-cisco_rv220w_persistent-kernel.bin' ! -name '*initramfs*' -printf '%T@ %p\n' | sort -nr | sed -n '1p' | cut -d' ' -f2-; }
find_sysupgrade() { find "$tree/bin/targets/octeon/generic" -maxdepth 1 -type f -name '*-cisco_rv220w_persistent-*sysupgrade.tar' -printf '%T@ %p\n' | sort -nr | sed -n '1p' | cut -d' ' -f2-; }
find_rootfs() {
  local p
  p=$(find "$tree/bin/targets/octeon/generic" -maxdepth 1 -type f \( -name 'root.squashfs' -o -name '*rootfs.squashfs' \) -printf '%T@ %p\n' | sort -nr | sed -n '1p' | cut -d' ' -f2-)
  if [[ -z $p ]]; then p=$(find "$tree/build_dir" -type f -path '*/linux-octeon_generic/root.squashfs' -printf '%T@ %p\n' | sort -nr | sed -n '1p' | cut -d' ' -f2-); fi
  printf '%s\n' "$p"
}
sha_artifacts() { (cd "$art" && find . -maxdepth 1 -type f ! -name SHA256SUMS -printf '%P\0' | sort -z | xargs -0 sha256sum > SHA256SUMS); }

build_initramfs() {
  configure openwrt-rv220w-release-initramfs.config initramfs
  grep -qxF 'CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_persistent_writer=y' "$tree/.config"
  grep -qxF 'CONFIG_TARGET_ROOTFS_INITRAMFS=y' "$tree/.config"
  download_and_build rv220w-release-initramfs
  local img; img=$(find_initramfs); [[ -f $img ]] || { echo 'release initramfs not found' >&2; exit 1; }
  cp "$img" "$art/rv220w-openwrt-release-initramfs.elf"
  verify_elf "$art/rv220w-openwrt-release-initramfs.elf"
  sha256sum "$art/rv220w-openwrt-release-initramfs.elf" > "$art/rv220w-openwrt-release-initramfs.elf.sha256"
}
build_sysupgrade() {
  configure openwrt-rv220w-release-sysupgrade.config sysupgrade
  grep -qxF 'CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_persistent=y' "$tree/.config"
  grep -qxF 'CONFIG_TARGET_ROOTFS_SQUASHFS=y' "$tree/.config"
  download_and_build rv220w-release-sysupgrade
  local k r s gz raw fwtool
  k=$(find_kernel); r=$(find_rootfs); s=$(find_sysupgrade)
  [[ -f $k && -f $r && -f $s ]] || { echo 'one or more persistent release artifacts were not found' >&2; exit 1; }
  gz="$art/rv220w-openwrt-release-kernel.elf.gz"; raw="$art/rv220w-openwrt-release-kernel.elf"
  cp "$k" "$gz"; gzip -t "$gz"; gzip -cd "$gz" > "$raw"; verify_elf "$raw"
  cp "$r" "$art/rv220w-openwrt-release-rootfs.squashfs"
  cp "$s" "$art/rv220w-openwrt-release-sysupgrade.tar"
  python3 "$root/scripts/host/build_rv220w_persistent_images.py" build "$gz" "$art/rv220w-openwrt-release-rootfs.squashfs" "$art" --manifest "$art/rv220w-openwrt-release-images.json" --prefix rv220w-openwrt-release
  fwtool=$(find "$tree/staging_dir/host/bin" -maxdepth 1 -type f -name fwtool -print -quit)
  [[ -x $fwtool ]] || { echo 'fwtool not found' >&2; exit 1; }
  python3 "$root/scripts/host/verify_rv220w_sysupgrade.py" "$art/rv220w-openwrt-release-sysupgrade.tar" "$gz" "$art/rv220w-openwrt-release-rootfs.squashfs" --fwtool "$fwtool" --report "$art/rv220w-openwrt-release-sysupgrade.json"
  sha256sum "$art/rv220w-openwrt-release-kernel.elf" "$gz" "$art/rv220w-openwrt-release-rootfs.squashfs" "$art/rv220w-openwrt-release-sysupgrade.tar"
}
case "$mode" in
  initramfs) build_initramfs ;;
  sysupgrade) build_sysupgrade ;;
  all) build_initramfs; build_sysupgrade ;;
  *) echo "usage: $0 {initramfs|sysupgrade|all}" >&2; exit 2 ;;
esac
sha_artifacts
echo "[rv220w-release] artifacts ready: $art"
