#!/usr/bin/env bash
set -Eeuo pipefail

on_error() {
    local status=$?
    local line=${BASH_LINENO[0]:-unknown}
    local command=${BASH_COMMAND:-unknown}
    printf '[rv220w:box:error] command failed (status=%s line=%s): %s\n' "$status" "$line" "$command" >&2
    exit "$status"
}
trap on_error ERR

[[ -r /etc/os-release ]] || { echo 'missing /etc/os-release inside build container' >&2; exit 1; }
# shellcheck disable=SC1091
. /etc/os-release
[[ ${ID:-} == ubuntu && ${VERSION_ID:-} == 24.04* ]] || {
    echo "expected Ubuntu 24.04, found: ${PRETTY_NAME:-unknown}" >&2
    exit 1
}
command -v apt-get >/dev/null 2>&1 || { echo 'apt-get unavailable' >&2; exit 1; }

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

export DEBIAN_FRONTEND=noninteractive
printf '[rv220w:box] Container: %s\n' "${PRETTY_NAME:-Ubuntu 24.04}"
echo '[rv220w:box] Refreshing Ubuntu package metadata.'
as_root apt-get update

echo '[rv220w:box] Installing OpenWrt build prerequisites.'
as_root apt-get install -y --no-install-recommends \
  build-essential clang flex bison g++ g++-multilib gawk gcc-multilib gettext git \
  libncurses-dev libssl-dev libelf-dev zlib1g-dev libzstd-dev liblzma-dev \
  python3 python3-dev python3-pip python3-setuptools python3-venv python3-pyelftools \
  rsync swig unzip zip xz-utils zstd file wget curl ca-certificates ccache util-linux \
  xsltproc subversion time perl bc jq patch patchutils quilt \
  device-tree-compiler u-boot-tools squashfs-tools mtd-utils binutils \
  autoconf automake libtool pkg-config gperf help2man texinfo

echo '[rv220w:box] Validating build environment.'
perl -MFindBin -e 1
python3 --version
# Do not use `... | head -1` under pipefail: the producer may receive SIGPIPE
# after head exits and turn a successful validation into a silent status 141.
printf 'gcc %s\n' "$(gcc -dumpfullversion -dumpversion)"
git --version
make_version=$(make --version)
printf '%s\n' "${make_version%%$'\n'*}"
for command_name in bash git gcc g++ make perl python3 rsync file setsid patch dtc unsquashfs; do
    command -v "$command_name" >/dev/null 2>&1 || {
        echo "required build command missing after provisioning: $command_name" >&2
        exit 1
    }
done

# Package-cache cleanup is an optimization, not a build requirement.  Do not
# reject an otherwise valid Distrobox solely because a container runtime keeps
# an apt cache/list path busy or mounted.
if ! as_root apt-get clean; then
    echo '[rv220w:box:warning] apt-get clean failed; continuing with the validated build environment.' >&2
fi
if ! as_root rm -rf /var/lib/apt/lists/*; then
    echo '[rv220w:box:warning] apt metadata cleanup failed; continuing with the validated build environment.' >&2
fi

echo '[rv220w:box] OpenWrt build environment is ready.'
