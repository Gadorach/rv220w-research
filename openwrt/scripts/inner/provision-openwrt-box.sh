#!/usr/bin/env bash
set -euo pipefail

if [[ ! -r /etc/os-release ]]; then
    echo 'missing /etc/os-release inside build container' >&2
    exit 1
fi
# shellcheck disable=SC1091
. /etc/os-release
if [[ ${ID:-} != ubuntu || ${VERSION_ID:-} != 24.04* ]]; then
    echo "expected Ubuntu 24.04, found: ${PRETTY_NAME:-unknown}" >&2
    exit 1
fi
if ! command -v apt-get >/dev/null 2>&1; then
    echo 'apt-get is unavailable; this is not the expected Ubuntu build container' >&2
    exit 1
fi

as_root() {
    if [[ $(id -u) -eq 0 ]]; then
        "$@"
    elif command -v sudo >/dev/null 2>&1; then
        sudo "$@"
    else
        echo "root privileges are required for: $*" >&2
        return 1
    fi
}

apt_candidate() {
    local package=$1
    local candidate
    candidate=$(apt-cache policy "$package" 2>/dev/null | awk '/Candidate:/ {print $2; exit}')
    [[ -n $candidate && $candidate != '(none)' ]]
}

enable_universe() {
    # Ubuntu's MIPS cross toolchains are in Universe.  The minimal Ubuntu OCI
    # image can be created with only Main enabled, which leaves the meta-package
    # visible in stale/partial metadata while its versioned dependency has no
    # installable candidate.  Use Ubuntu's supported repository helper rather
    # than rewriting deb822 source files by hand.
    if apt_candidate gcc-12-mips64-linux-gnuabi64 \
        || apt_candidate gcc-13-mips64-linux-gnuabi64; then
        echo '[rv220w:box] Ubuntu Universe already provides the MIPS64 cross toolchain.'
        return 0
    fi

    echo '[rv220w:box] Enabling the Ubuntu Universe component for optional MIPS64 cross tools.'
    as_root apt-get install -y --no-install-recommends software-properties-common
    as_root add-apt-repository -y universe
    as_root apt-get update
}

install_reference_cross() {
    # OpenWrt builds its own target toolchain.  This compiler is only for the
    # separate upstream-Linux reference workflow, so a repository packaging
    # problem must not block the main OpenWrt environment.
    local binutils=binutils-mips64-linux-gnuabi64
    local package

    if command -v mips64-linux-gnuabi64-gcc >/dev/null 2>&1; then
        echo '[rv220w:box] MIPS64 reference cross compiler is already installed.'
        return 0
    fi

    enable_universe || true

    for package in gcc-mips64-linux-gnuabi64 gcc-13-mips64-linux-gnuabi64 gcc-12-mips64-linux-gnuabi64; do
        if ! apt_candidate "$package"; then
            continue
        fi
        echo "[rv220w:box] Installing optional reference compiler package: $package"
        if as_root apt-get install -y --no-install-recommends "$package" "$binutils"; then
            break
        fi
        echo "[rv220w:box] Package $package was not installable; trying the next supported candidate." >&2
    done

    if command -v mips64-linux-gnuabi64-gcc >/dev/null 2>&1; then
        mips64-linux-gnuabi64-gcc --version | head -1
        return 0
    fi

    # Versioned compiler packages may omit the unversioned gcc front-end.  The
    # kernel build expects CROSS_COMPILE=mips64-linux-gnuabi64-, so install one
    # deterministic compatibility symlink when a versioned binary is present.
    local versioned
    versioned=$(command -v mips64-linux-gnuabi64-gcc-14 \
        || command -v mips64-linux-gnuabi64-gcc-13 \
        || command -v mips64-linux-gnuabi64-gcc-12 \
        || true)
    if [[ -n $versioned ]]; then
        echo "[rv220w:box] Creating unversioned compiler link for $versioned"
        as_root ln -sfn "$versioned" /usr/local/bin/mips64-linux-gnuabi64-gcc
    fi

    if command -v mips64-linux-gnuabi64-gcc >/dev/null 2>&1; then
        mips64-linux-gnuabi64-gcc --version | head -1
        return 0
    fi

    cat >&2 <<'MSG'
[rv220w:box:warning] The optional system MIPS64 cross compiler could not be installed.
[rv220w:box:warning] OpenWrt builds are fully provisioned and are not affected;
[rv220w:box:warning] only `./rv220w.fish build-linux` remains unavailable until
[rv220w:box:warning] a mips64-linux-gnuabi64-gcc front-end is installed.
MSG
    return 1
}

export DEBIAN_FRONTEND=noninteractive

echo '[rv220w:box] Phase 1/4: refreshing Ubuntu package metadata.'
as_root apt-get update

echo '[rv220w:box] Phase 2/4: installing OpenWrt and kernel build prerequisites.'
as_root apt-get install -y --no-install-recommends \
  build-essential clang flex bison g++ g++-multilib gawk gcc-multilib gettext git \
  libncurses-dev libssl-dev libelf-dev zlib1g-dev libzstd-dev liblzma-dev \
  python3 python3-dev python3-pip python3-setuptools python3-venv python3-pyelftools \
  rsync swig unzip zip xz-utils zstd file wget curl ca-certificates ccache util-linux \
  xsltproc subversion mercurial ecj fastjar time perl bc jq patch patchutils quilt \
  device-tree-compiler u-boot-tools squashfs-tools mtd-utils binutils genisoimage \
  autoconf automake libtool pkg-config gperf help2man texinfo \
  software-properties-common

echo '[rv220w:box] Phase 3/4: installing the optional standalone-Linux cross compiler.'
reference_cross=available
if ! install_reference_cross; then
    reference_cross=unavailable
fi

echo '[rv220w:box] Phase 4/4: validating and cleaning the build environment.'
perl -MFindBin -e 1
python3 --version
gcc --version | head -1
printf 'container=%s version=%s reference_cross=%s\n' "${ID}" "${VERSION_ID}" "$reference_cross"

as_root apt-get clean
as_root rm -rf /var/lib/apt/lists/*
