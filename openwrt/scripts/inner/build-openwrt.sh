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

command -v flock >/dev/null 2>&1 || {
    echo "flock is required for serialized OpenWrt builds (install util-linux in the build box)" >&2
    exit 127
}
build_lock="$workspace/.rv220w-openwrt-build.lock"
exec 9>"$build_lock"
if ! flock -n 9; then
    echo "another RV220W OpenWrt build is already active for this workspace" >&2
    echo "lock: $build_lock" >&2
    exit 1
fi

run_make_noninteractive() {
    command -v setsid >/dev/null 2>&1 || {
        echo "setsid is required for noninteractive OpenWrt builds (install util-linux in the build box)" >&2
        return 127
    }

    local arg
    for arg in "$@"; do
        case "$arg" in
          menuconfig|nconfig|xconfig|kernel_menuconfig|kernel_nconfig|kernel_xconfig)
            echo "refusing interactive OpenWrt target in automated build: $arg" >&2
            return 2
            ;;
        esac
    done

    # OpenWrt's top-level .config rule launches menuconfig whenever a make
    # target that depends on .config is invoked before defconfig has written
    # CONFIG_HAVE_DOT_CONFIG=y.  Callers must therefore configure first.
    # Clearing inherited jobserver flags also prevents concurrent tmp/info
    # scanners from reusing stale temporary targetinfo names.
    env \
        MAKEFLAGS= \
        MFLAGS= \
        CI=1 \
        DEBIAN_FRONTEND=noninteractive \
        GIT_TERMINAL_PROMPT=0 \
        KCONFIG_NONINTERACTIVE=1 \
        TERM=dumb \
        setsid --fork --wait make "$@" </dev/null
}

config_is_expanded() {
    [[ -s .config ]] && grep -qxF 'CONFIG_HAVE_DOT_CONFIG=y' .config
}

require_expanded_config() {
    config_is_expanded || {
        echo 'refusing noninteractive make before OpenWrt defconfig completed' >&2
        echo 'the build helper must configure the selected seed before clean/download/world targets' >&2
        return 2
    }
}

maybe_full_clean() {
    if [[ ${RV220W_CLEAN:-0} == 1 ]]; then
        require_expanded_config
        run_make_noninteractive clean
    fi
}

sync_base_files() {
    rm -rf files
    mkdir -p files
    rsync -a "$toolkit/openwrt/files-base/" files/
    printf '%s\n' \
      'RV220W OpenWrt RAM-validation build' \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}

sync_discovery_files() {
    sync_base_files
    rsync -a "$toolkit/openwrt/files-discovery/" files/
    printf '%s\n' \
      'RV220W OpenWrt read-only discovery profile v1.8.0' \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}


sync_dsa_lan_files() {
    sync_base_files
    rsync -a "$toolkit/openwrt/files-dsa-lan/" files/
    printf '%s\n' \
      "RV220W OpenWrt RAM-only LAN DSA validation profile v1.8.0 (${RV220W_DSA_VARIANT})" \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}


sync_dsa_dual_files() {
    sync_base_files
    rsync -a "$toolkit/openwrt/files-dsa-dual/" files/
    printf '%s\n' \
      "RV220W OpenWrt RAM-only dual-conduit DSA validation profile v1.8.0 (${RV220W_DSA_VARIANT})" \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}

write_build_profile() {
    local profile=$1
    local writes=$2
    printf '%s\n' \
      "profile=$profile" \
      "writes=$writes" \
      "toolkit=1.10.3" \
      "build_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build-profile
}

sync_rj45_common_files() {
    sync_base_files
    rsync -a "$toolkit/openwrt/files-dsa-dual/" files/
    rm -f \
        files/etc/uci-defaults/98-rv220w-dsa-dual-network \
        files/etc/uci-defaults/99-rv220w-validation \
        files/usr/sbin/rv220w-b53-eap-mode \
        files/usr/sbin/rv220w-b53-snapshot \
        files/usr/sbin/rv220w-b53-vlan-state \
        files/usr/sbin/rv220w-dsa-snapshot
    rsync -a "$toolkit/openwrt/files-rj45-full/" files/
}

sync_rj45_full_files() {
    sync_rj45_common_files
    write_build_profile rj45-full none
    printf '%s\n' \
      "RV220W OpenWrt RAM-only full-RJ45 validated baseline v1.10.3 (${RV220W_DSA_VARIANT})" \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}

sync_rj45_luci_files() {
    sync_rj45_common_files
    rsync -a "$toolkit/openwrt/files-rj45-luci/" files/
    write_build_profile rj45-luci none
    printf '%s\n' \
      "RV220W OpenWrt RAM-only full-RJ45 + LuCI profile v1.10.3 (${RV220W_DSA_VARIANT})" \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}

sync_nor_writer_files() {
    sync_rj45_common_files
    rsync -a "$toolkit/openwrt/files-nor-writer/" files/
    write_build_profile nor-writer openwrt-slot-only
    printf '%s\n' \
      "RV220W OpenWrt RAM-boot NOR writer v1.10.3 (${RV220W_DSA_VARIANT})" \
      "Writable MTD policy: openwrt-slot only" \
      "OpenWrt ref: $(git describe --always --dirty --tags)" \
      "Build UTC: $(date -u +%Y-%m-%dT%H:%M:%SZ)" > files/etc/rv220w-build
}

verify_dsa_config() {
    local required=(
      CONFIG_PACKAGE_ip-full=y
      CONFIG_PACKAGE_ip-bridge=y
      CONFIG_PACKAGE_ethtool-full=y
      CONFIG_PACKAGE_kmod-dsa-b53=y
      CONFIG_PACKAGE_kmod-dsa-b53-mdio=y
    )
    local item
    for item in "${required[@]}"; do
        grep -qxF "$item" .config || {
            echo "DSA profile package was not retained by defconfig: $item" >&2
            exit 1
        }
    done
}

verify_dsa_dual_config() {
    verify_dsa_config
    grep -qxF "CONFIG_PACKAGE_ip-full=y" .config || exit 1
}

verify_rj45_full_config() {
    verify_dsa_dual_config
    local required=(
      CONFIG_PACKAGE_firewall4=y
      CONFIG_PACKAGE_dnsmasq=y
      CONFIG_PACKAGE_odhcp6c=y
      CONFIG_PACKAGE_odhcpd-ipv6only=y
      CONFIG_PACKAGE_ppp=y
      CONFIG_PACKAGE_ppp-mod-pppoe=y
    )
    local item
    for item in "${required[@]}"; do
        grep -qxF "$item" .config || {
            echo "Full-RJ45 package was not retained by defconfig: $item" >&2
            exit 1
        }
    done

    local forbidden=(
      CONFIG_PACKAGE_kmod-mdio-netlink=y
      CONFIG_PACKAGE_mdio-tools=y
    )
    for item in "${forbidden[@]}"; do
        if grep -qxF "$item" .config; then
            echo "Production full-RJ45 config retained diagnostic package: $item" >&2
            exit 1
        fi
    done
}

verify_luci_config() {
    verify_rj45_full_config
    local required=(
      CONFIG_PACKAGE_luci-light=y
      CONFIG_PACKAGE_luci-base=y
      CONFIG_PACKAGE_luci-mod-admin-full=y
      CONFIG_PACKAGE_luci-app-firewall=y
      CONFIG_PACKAGE_uhttpd=y
      CONFIG_PACKAGE_uhttpd-mod-ubus=y
    )
    local item
    for item in "${required[@]}"; do
        grep -qxF "$item" .config || {
            echo "LuCI profile package was not retained by defconfig: $item" >&2
            exit 1
        }
    done
}

verify_nor_writer_config() {
    # The writer deliberately reuses the proven RJ45 network base but excludes
    # LuCI/uHTTPd to minimize the destructive-maintenance image. v1.10.0
    # accidentally called verify_luci_config here, making a correct defconfig
    # fail before compilation.
    verify_rj45_full_config

    local required=(
      CONFIG_PACKAGE_mtd=y
      CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_flash_stage=y
    )
    local item
    for item in "${required[@]}"; do
        grep -qxF "$item" .config || {
            echo "NOR-writer requirement was not retained by defconfig: $item" >&2
            exit 1
        }
    done

    local forbidden=(
      CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w=y
      CONFIG_PACKAGE_luci-light=y
      CONFIG_PACKAGE_luci-base=y
      CONFIG_PACKAGE_luci-mod-admin-full=y
      CONFIG_PACKAGE_luci-app-firewall=y
      CONFIG_PACKAGE_uhttpd=y
      CONFIG_PACKAGE_uhttpd-mod-ubus=y
    )
    for item in "${forbidden[@]}"; do
        if grep -qxF "$item" .config; then
            echo "NOR-writer config retained a forbidden normal/LuCI option: $item" >&2
            exit 1
        fi
    done
}

build_dsa_lan() (
    local variant=$1
    local phy_mode=$2
    local source_dts="target/linux/octeon/files/arch/mips/boot/dts/cavium-octeon/cn5010_cisco_rv220w.dts"
    local template="$toolkit/openwrt/dsa-lan/cn5010_cisco_rv220w-dsa-lan.dts.in"
    local kernel_patch_sources=(
        "$toolkit/openwrt/dsa-lan/995-rv220w-octeon-dsa-master-node.patch"
        "$toolkit/openwrt/dsa-lan/996-octeon-dsa-conduit-length-error.patch"
    )
    local kernel_patch_targets=(
        "target/linux/octeon/patches-6.12/995-rv220w-octeon-dsa-master-node.patch"
        "target/linux/octeon/patches-6.12/996-octeon-dsa-conduit-length-error.patch"
    )
    local backup= source_sha= restore_rc=0 patch_index

    cleanup_dsa_source() {
        restore_rc=0
        if [[ -n ${backup:-} && -f ${backup:-} && -n ${source_sha:-} ]]; then
            cp "$backup" "$source_dts" 2>/dev/null || restore_rc=1
            if [[ $restore_rc == 0 ]]; then
                printf '%s  %s\n' "$source_sha" "$source_dts" | sha256sum -c - >/dev/null 2>&1 || restore_rc=1
            fi
            rm -f "$backup"
        fi
        if config_is_expanded; then
            run_make_noninteractive target/linux/clean >/dev/null 2>&1 || true
        fi
        if [[ $restore_rc != 0 ]]; then
            echo "ERROR: failed to restore the exact pre-build RV220W DTS state" >&2
            return 1
        fi
    }

    [[ -f "$source_dts" ]] || { echo "RV220W source DTS missing: $source_dts" >&2; exit 1; }
    for patch_index in "${!kernel_patch_sources[@]}"; do
        [[ -f "${kernel_patch_sources[$patch_index]}" ]] || {
            echo "RV220W DSA kernel patch missing: ${kernel_patch_sources[$patch_index]}" >&2
            exit 1
        }
        [[ -f "${kernel_patch_targets[$patch_index]}" ]] || {
            echo "RV220W DSA kernel patch is not installed in the OpenWrt source tree:" >&2
            echo "  ${kernel_patch_targets[$patch_index]}" >&2
            echo "Re-run the v1.10.3 updater with --workspace pointing at this tree." >&2
            exit 1
        }
        cmp -s "${kernel_patch_sources[$patch_index]}" "${kernel_patch_targets[$patch_index]}" || {
            echo "Installed DSA kernel patch differs from toolkit v1.10.3:" >&2
            echo "  ${kernel_patch_targets[$patch_index]}" >&2
            echo "Re-run the v1.10.3 updater before building." >&2
            exit 1
        }
    done

    backup=$(mktemp)
    cp "$source_dts" "$backup"
    source_sha=$(sha256sum "$source_dts" | awk '{print $1}')
    trap cleanup_dsa_source EXIT INT TERM
    sed -e "s/@VARIANT@/$variant/g" -e "s/@PHY_MODE@/$phy_mode/g" "$template" > "$source_dts"
    grep -q 'status = "okay";' "$source_dts"
    grep -q 'ethernet = <&rv220w_eth0>;' "$source_dts"
    ensure_discovery_feed_packages
    RV220W_DSA_VARIANT=$variant
    export RV220W_DSA_VARIANT
    sync_dsa_lan_files
    configure openwrt-rv220w-dsa-lan-initramfs.config
    verify_dsa_config
    maybe_full_clean
    require_expanded_config
    run_make_noninteractive target/linux/clean
    build_world "rv220w-dsa-lan-$variant"
    stage_initramfs "rv220w-openwrt-rv220w-dsa-lan-$variant" cisco_rv220w
)

build_dsa_dual() (
    local variant=$1
    local wan_phy_mode=$2
    local profile=${3:-validation}
    local production=0
    case "$profile" in
      full-rj45|luci|nor-writer) production=1 ;;
    esac

    local source_dts="target/linux/octeon/files/arch/mips/boot/dts/cavium-octeon/cn5010_cisco_rv220w.dts"
    local template="$toolkit/openwrt/dsa-dual/cn5010_cisco_rv220w-dsa-dual.dts.in"
    if [[ $production == 1 ]]; then
        template="$toolkit/openwrt/production/cn5010_cisco_rv220w-production.dts.in"
    fi
    local kernel_patch_sources=(
        "$toolkit/openwrt/dsa-lan/995-rv220w-octeon-dsa-master-node.patch"
        "$toolkit/openwrt/dsa-lan/996-octeon-dsa-conduit-length-error.patch"
        "$toolkit/openwrt/dsa-dual/997-b53-multi-conduit-affinity.patch"
    )
    local kernel_patch_targets=(
        "target/linux/octeon/patches-6.12/995-rv220w-octeon-dsa-master-node.patch"
        "target/linux/octeon/patches-6.12/996-octeon-dsa-conduit-length-error.patch"
        "target/linux/octeon/patches-6.12/997-b53-multi-conduit-affinity.patch"
    )
    if [[ $production == 1 ]]; then
        kernel_patch_sources+=(
            "$toolkit/openwrt/dsa-dual/998-b53-enable-dt-cpu-ports.patch"
            "$toolkit/openwrt/production/999-octeon-production-dt-flash-cleanups.patch"
        )
        kernel_patch_targets+=(
            "target/linux/octeon/patches-6.12/998-b53-enable-dt-cpu-ports.patch"
            "target/linux/octeon/patches-6.12/999-octeon-production-dt-flash-cleanups.patch"
        )
    fi
    local backup= source_sha= restore_rc=0 patch_index

    cleanup_dsa_dual_source() {
        restore_rc=0
        if [[ -n ${backup:-} && -f ${backup:-} && -n ${source_sha:-} ]]; then
            cp "$backup" "$source_dts" 2>/dev/null || restore_rc=1
            if [[ $restore_rc == 0 ]]; then
                printf '%s  %s\n' "$source_sha" "$source_dts" | sha256sum -c - >/dev/null 2>&1 || restore_rc=1
            fi
            rm -f "$backup"
        fi
        if config_is_expanded; then
            run_make_noninteractive target/linux/clean >/dev/null 2>&1 || true
        fi
        if [[ $restore_rc != 0 ]]; then
            echo "ERROR: failed to restore the exact pre-build RV220W DTS state" >&2
            return 1
        fi
    }

    [[ -f "$source_dts" ]] || { echo "RV220W source DTS missing: $source_dts" >&2; exit 1; }
    [[ -f "$template" ]] || { echo "RV220W dual-conduit DTS template missing: $template" >&2; exit 1; }
    for patch_index in "${!kernel_patch_sources[@]}"; do
        [[ -f "${kernel_patch_sources[$patch_index]}" ]] || {
            echo "RV220W DSA kernel patch missing: ${kernel_patch_sources[$patch_index]}" >&2
            exit 1
        }
        [[ -f "${kernel_patch_targets[$patch_index]}" ]] || {
            echo "RV220W DSA kernel patch is not installed in the OpenWrt source tree:" >&2
            echo "  ${kernel_patch_targets[$patch_index]}" >&2
            echo "Re-run the v1.10.3 updater with --workspace pointing at this tree." >&2
            exit 1
        }
        cmp -s "${kernel_patch_sources[$patch_index]}" "${kernel_patch_targets[$patch_index]}" || {
            echo "Installed DSA kernel patch differs from toolkit v1.10.3:" >&2
            echo "  ${kernel_patch_targets[$patch_index]}" >&2
            echo "Re-run the v1.10.3 updater before building." >&2
            exit 1
        }
    done

    backup=$(mktemp)
    cp "$source_dts" "$backup"
    source_sha=$(sha256sum "$source_dts" | awk '{print $1}')
    trap cleanup_dsa_dual_source EXIT INT TERM
    sed -e "s/@VARIANT@/$variant/g" -e "s/@WAN_PHY_MODE@/$wan_phy_mode/g" "$template" > "$source_dts"
    grep -q 'label = "wan";' "$source_dts"
    grep -q 'ethernet = <&rv220w_eth1>;' "$source_dts"
    grep -q 'ethernet = <&rv220w_eth0>;' "$source_dts"
    RV220W_DSA_VARIANT=$variant
    export RV220W_DSA_VARIANT

    case "$profile" in
      full-rj45)
        sync_rj45_full_files
        configure openwrt-rv220w-rj45-initramfs.config
        verify_rj45_full_config
        ;;
      luci)
        sync_rj45_luci_files
        configure openwrt-rv220w-rj45-luci-initramfs.config
        verify_luci_config
        ;;
      nor-writer)
        sync_nor_writer_files
        configure openwrt-rv220w-nor-writer-initramfs.config
        verify_nor_writer_config
        ;;
      *)
        ensure_discovery_feed_packages
        sync_dsa_dual_files
        configure openwrt-rv220w-dsa-dual-initramfs.config
        verify_dsa_dual_config
        ;;
    esac

    maybe_full_clean
    require_expanded_config
    run_make_noninteractive target/linux/clean

    case "$profile" in
      full-rj45)
        build_world "rv220w-rj45-$variant"
        stage_initramfs "rv220w-openwrt-rv220w-rj45-initramfs" cisco_rv220w
        ;;
      luci)
        build_world "rv220w-rj45-luci-$variant"
        stage_initramfs "rv220w-openwrt-rv220w-rj45-luci-initramfs" cisco_rv220w
        python3 "$toolkit/scripts/host/build_rv220w_nor_slot.py" build \
          "$artifacts/rv220w-openwrt-rv220w-rj45-luci-initramfs.elf" \
          "$artifacts/rv220w-openwrt-rv220w-rj45-luci-nor-slot.bin" \
          --manifest "$artifacts/rv220w-openwrt-rv220w-rj45-luci-nor-slot.json"
        ;;
      nor-writer)
        build_world "rv220w-nor-writer-$variant"
        stage_initramfs "rv220w-openwrt-rv220w-nor-writer-initramfs" cisco_rv220w_flash_stage
        ;;
      *)
        build_world "rv220w-dsa-dual-$variant"
        stage_initramfs "rv220w-openwrt-rv220w-dsa-dual-$variant" cisco_rv220w
        ;;
    esac
)

ensure_discovery_feed_packages() {
    local missing=0
    [[ -e package/feeds/packages/mdio-tools ]] || missing=1
    [[ -e package/feeds/packages/mdio-netlink ]] || missing=1
    if [[ $missing == 0 ]]; then
        return
    fi
    if [[ -f feeds/packages/net/mdio-tools/Makefile        && -f feeds/packages/kernel/mdio-netlink/Makefile ]]; then
        ./scripts/feeds install -a
    else
        cat >&2 <<'MSG'
The packages feed does not contain the MDIO discovery packages. Run:
  ./rv220w.fish prepare-sources
Then retry the discovery build.
MSG
        exit 1
    fi
    [[ -e package/feeds/packages/mdio-tools ]] || {
        echo 'feeds install did not expose package/feeds/packages/mdio-tools' >&2
        exit 1
    }
    [[ -e package/feeds/packages/mdio-netlink ]] || {
        echo 'feeds install did not expose package/feeds/packages/mdio-netlink' >&2
        exit 1
    }
}

verify_discovery_config() {
    local required=(
      CONFIG_PACKAGE_ip-full=y
      CONFIG_PACKAGE_ip-bridge=y
      CONFIG_PACKAGE_ethtool-full=y
      CONFIG_PACKAGE_tcpdump-mini=y
      CONFIG_PACKAGE_kmod-dsa-b53=y
      CONFIG_PACKAGE_kmod-dsa-b53-mdio=y
      CONFIG_PACKAGE_kmod-mdio-netlink=y
      CONFIG_PACKAGE_mdio-tools=y
    )
    local item
    for item in "${required[@]}"; do
        grep -qxF "$item" .config || {
            echo "Discovery profile package was not retained by defconfig: $item" >&2
            exit 1
        }
    done
}

configure() {
    local seed=$1
    cp "$toolkit/config/$seed" .config
    run_make_noninteractive defconfig
    require_expanded_config
    cp .config "$artifacts/${seed%.config}.expanded.config"
}

download_sources() {
    require_expanded_config
    run_make_noninteractive -j"$jobs" download
    local bad
    bad=$(find dl -type f -size -1024c -print || true)
    if [[ -n "$bad" ]]; then
        printf 'Suspiciously small downloads:\n%s\n' "$bad" >&2
        return 1
    fi
}

build_world() {
    local label=$1
    require_expanded_config
    download_sources
    local verbosity=()
    if [[ ${RV220W_VERBOSE:-0} == 1 || $mode == rv220w-dsa-lan-* || $mode == rv220w-dsa-dual-* || $mode == rv220w-rj45-* || $mode == rv220w-nor-* ]]; then
        verbosity=(V=s)
    fi
    local main_log="$logs/$label-build.log"
    local serial_log="$logs/$label-build-serial.log"
    rm -f "$serial_log"
    echo "[rv220w:build] mode=$mode target=world noninteractive=setsid stdin=/dev/null"
    if ! {
        printf '[rv220w:build-meta] toolkit=1.10.3 label=%s mode=%s utc=%s jobs=%s pass=parallel\n' \
          "$label" "$mode" "$(date -u +%Y-%m-%dT%H:%M:%SZ)" "$jobs"
        run_make_noninteractive -j"$jobs" world "${verbosity[@]}"
    } 2>&1 | tee "$main_log"; then
        echo 'Parallel build failed; rerunning serially with V=s for diagnostics.' >&2
        {
            printf '[rv220w:build-meta] toolkit=1.10.3 label=%s mode=%s utc=%s jobs=1 pass=serial-fallback\n' \
              "$label" "$mode" "$(date -u +%Y-%m-%dT%H:%M:%SZ)"
            run_make_noninteractive -j1 world V=s
        } 2>&1 | tee "$serial_log"
    fi
}

find_initramfs() {
    local device=${1:-generic}
    local pattern='*initramfs-kernel.bin'
    if [[ $device != generic ]]; then
        pattern="*-${device}-initramfs-kernel.bin"
    fi
    find bin/targets/octeon/generic -maxdepth 1 -type f \
      -name "$pattern" -printf '%T@ %p\n' \
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
    local device=${2:-generic}
    local image
    image=$(find_initramfs "$device")
    if [[ -z "$image" || ! -f "$image" ]]; then
        echo "initramfs kernel artifact not found for device: $device" >&2
        find bin/targets/octeon/generic -maxdepth 1 -type f -printf '  %f\n' | sort >&2 || true
        exit 1
    fi
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
    maybe_full_clean
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
    maybe_full_clean
    build_world rv220w-initramfs
    stage_initramfs rv220w-openwrt-generic-initramfs
    ;;
  rv220w-initramfs)
    sync_base_files
    configure openwrt-rv220w-initramfs.config
    maybe_full_clean
    build_world rv220w-board-initramfs
    stage_initramfs rv220w-openwrt-rv220w-initramfs cisco_rv220w
    ;;
  rv220w-discovery-initramfs)
    ensure_discovery_feed_packages
    sync_discovery_files
    configure openwrt-rv220w-discovery-initramfs.config
    verify_discovery_config
    maybe_full_clean
    build_world rv220w-discovery-initramfs
    stage_initramfs rv220w-openwrt-rv220w-discovery-initramfs cisco_rv220w
    ;;
  rv220w-dsa-lan-rxid)
    # Observed port-8 RGMII control is 0x00.  On BCM53115, rgmii-rxid is
    # the least-invasive B53 mode because it does not request a TX DLL bit.
    build_dsa_lan rxid rgmii-rxid
    ;;
  rv220w-dsa-lan-txid)
    build_dsa_lan txid rgmii-txid
    ;;
  rv220w-dsa-lan-rgmii)
    build_dsa_lan rgmii rgmii
    ;;
  rv220w-dsa-dual-rxid)
    build_dsa_dual rxid rgmii-rxid
    ;;
  rv220w-rj45-initramfs)
    # First complete wired-router candidate: proven dual RGMII topology,
    # synchronized secondary CPU-port VID 0 state, LAN DHCP, WAN DHCP/DHCPv6,
    # firewall4 isolation and LAN-to-WAN NAT.
    build_dsa_dual rxid rgmii-rxid full-rj45
    ;;
  rv220w-rj45-luci-initramfs)
    # Validated all-RJ45 data plane plus LAN-only LuCI/uHTTPd. The generated
    # ELF is also padded into the first-stage 22 MiB NOR slot artifact.
    build_dsa_dual rxid rgmii-rxid luci
    ;;
  rv220w-nor-writer-initramfs)
    # RAM-boot-only writer profile: exactly one writable MTD partition named
    # openwrt-slot; every non-slot NOR region stays read-only.
    build_dsa_dual rxid rgmii-rxid nor-writer
    ;;
  rv220w-dsa-dual-wan-txid)
    build_dsa_dual wan-txid rgmii-txid
    ;;
  rv220w-dsa-dual-wan-rgmii)
    build_dsa_dual wan-rgmii rgmii
    ;;
  squashfs)
    build_squashfs
    ;;
  squashfs-live)
    build_squashfs
    sync_base_files
    mkdir -p files/rv220w
    cp "$artifacts/rv220w-openwrt-rootfs.squashfs" files/rv220w/rootfs.squashfs
    cp "$toolkit/openwrt/files-squashfs-live/init" files/init
    chmod +x files/init
    configure openwrt-squashfs-live.config
    maybe_full_clean
    build_world rv220w-squashfs-live
    stage_initramfs rv220w-openwrt-squashfs-live
    ;;
  kernel)
    sync_base_files
    configure openwrt-initramfs.config
    maybe_full_clean
    download_sources
    require_expanded_config
    run_make_noninteractive -j"$jobs" target/linux/compile V=s 2>&1 | tee "$logs/rv220w-kernel-build.log"
    ;;
  menuconfig)
    [[ ${RV220W_ALLOW_MENUCONFIG:-0} == 1 ]] || {
        echo 'menuconfig is permitted only through: ./rv220w.fish build menuconfig' >&2
        exit 2
    }
    sync_base_files
    [[ -f .config ]] || configure openwrt-initramfs.config
    exec make menuconfig
    ;;
  clean)
    sync_base_files
    configure openwrt-initramfs.config
    require_expanded_config
    run_make_noninteractive clean
    ;;
  *)
    echo "unknown build mode: $mode" >&2
    exit 2
    ;;
esac
