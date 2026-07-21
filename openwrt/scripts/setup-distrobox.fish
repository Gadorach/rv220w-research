#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'r/recreate' 'n/dry-run' -- $argv; or exit 2
rv_require distrobox podman
if set -q _flag_recreate
    rv_warn "Removing Distrobox $RV220W_BOX"
    if not set -q _flag_dry_run
        distrobox stop "$RV220W_BOX" >/dev/null 2>&1
        distrobox rm --force "$RV220W_BOX" >/dev/null 2>&1
    end
end
if not rv_box_exists
    rv_info "Creating $RV220W_BOX from $RV220W_BOX_IMAGE"
    if set -q _flag_dry_run
        echo "distrobox create --yes --name $RV220W_BOX --image $RV220W_BOX_IMAGE"
        exit 0
    end
    distrobox create --yes --name "$RV220W_BOX" --image "$RV220W_BOX_IMAGE"; or rv_die 'Distrobox creation failed'
end
set -l provision "$RV220W_TOOLKIT_ROOT/work/provision-openwrt-box.sh"
mkdir -p (dirname "$provision")
cat > "$provision" <<'BASH'
#!/usr/bin/env bash
set -euo pipefail
export DEBIAN_FRONTEND=noninteractive
sudo apt-get update
sudo apt-get install -y --no-install-recommends \
  build-essential clang flex bison g++ g++-multilib gawk gcc-multilib gettext git \
  libncurses-dev libssl-dev libelf-dev zlib1g-dev libzstd-dev liblzma-dev \
  python3 python3-dev python3-pip python3-setuptools python3-venv python3-pyelftools \
  rsync swig unzip zip xz-utils zstd file wget curl ca-certificates ccache \
  xsltproc subversion mercurial ecj fastjar time perl bc jq patch patchutils quilt \
  device-tree-compiler u-boot-tools squashfs-tools mtd-utils binutils genisoimage \
  autoconf automake libtool pkg-config gperf help2man texinfo
sudo apt-get clean
rm -rf /var/lib/apt/lists/*
python3 --version
gcc --version | head -1
BASH
chmod +x "$provision"
rv_info 'Provisioning OpenWrt build dependencies in the shared-home Ubuntu container.'
if set -q _flag_dry_run
    echo "distrobox enter $RV220W_BOX -- bash $provision"
    exit 0
end
distrobox enter "$RV220W_BOX" -- bash "$provision"; or rv_die 'Distrobox provisioning failed'
rv_info 'Distrobox is ready.'
