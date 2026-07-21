#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'u/update' 'n/dry-run' -- $argv; or exit 2
rv_box_exists; or rv_die 'Build Distrobox is not ready; run setup-box first'
mkdir -p "$RV220W_WORKSPACE" "$RV220W_TOOLKIT_ROOT/work"
set -l inner "$RV220W_TOOLKIT_ROOT/work/prepare-sources-inner.sh"
cat > "$inner" <<'BASH'
#!/usr/bin/env bash
set -euo pipefail
workspace=${RV220W_WORKSPACE:?}
mkdir -p "$workspace/sources" "$workspace/artifacts" "$workspace/logs"
clone_or_update() {
    local url=$1 ref=$2 dest=$3
    if [[ -d "$dest/.git" ]]; then
        if [[ ${RV220W_UPDATE:-0} == 1 ]]; then
            if [[ -n $(git -C "$dest" status --porcelain) ]]; then
                echo "Refusing to update dirty managed checkout: $dest" >&2
                return 1
            fi
            git -C "$dest" fetch --tags --prune origin
            git -C "$dest" checkout "$ref"
            if git -C "$dest" show-ref --verify --quiet "refs/remotes/origin/$ref"; then
                git -C "$dest" merge --ff-only "origin/$ref"
            fi
        fi
    else
        git clone --filter=blob:none --no-single-branch "$url" "$dest"
        git -C "$dest" checkout "$ref"
    fi
}
clone_or_update "$RV220W_OPENWRT_URL" "$RV220W_OPENWRT_REF" "$workspace/sources/openwrt"
clone_or_update "$RV220W_LINUX_URL" "$RV220W_LINUX_REF" "$workspace/sources/linux-reference"
clone_or_update "$RV220W_MERAKI_BUILDER_URL" "$RV220W_MERAKI_BUILDER_REF" "$workspace/sources/meraki-builder-reference"
cd "$workspace/sources/openwrt"
./scripts/feeds update -a
./scripts/feeds install -a
python3 - <<'PY'
import json, os, pathlib, subprocess
workspace=pathlib.Path(os.environ['RV220W_WORKSPACE'])
repos={
 'openwrt':workspace/'sources/openwrt',
 'linux_reference':workspace/'sources/linux-reference',
 'meraki_builder_reference':workspace/'sources/meraki-builder-reference',
}
def git(path,*args):
 return subprocess.check_output(['git','-C',str(path),*args],text=True).strip()
requested_refs={'openwrt':os.environ['RV220W_OPENWRT_REF'],'linux_reference':os.environ['RV220W_LINUX_REF'],'meraki_builder_reference':os.environ['RV220W_MERAKI_BUILDER_REF']}
urls={'openwrt':os.environ['RV220W_OPENWRT_URL'],'linux_reference':os.environ['RV220W_LINUX_URL'],'meraki_builder_reference':os.environ['RV220W_MERAKI_BUILDER_URL']}
result={name:{'path':str(path),'url':urls[name],'requested_ref':requested_refs[name],'commit':git(path,'rev-parse','HEAD'),'describe':git(path,'describe','--always','--dirty','--tags')} for name,path in repos.items()}
(workspace/'source-lock.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
PY
BASH
chmod +x "$inner"
set -lx RV220W_UPDATE 0
set -q _flag_update; and set -lx RV220W_UPDATE 1
rv_info "Preparing sources under $RV220W_WORKSPACE"
if set -q _flag_dry_run
    echo "distrobox enter $RV220W_BOX -- env RV220W_WORKSPACE=... bash $inner"
    exit 0
end
distrobox enter "$RV220W_BOX" -- env \
    RV220W_WORKSPACE="$RV220W_WORKSPACE" \
    RV220W_UPDATE="$RV220W_UPDATE" \
    RV220W_OPENWRT_URL="$RV220W_OPENWRT_URL" \
    RV220W_OPENWRT_REF="$RV220W_OPENWRT_REF" \
    RV220W_LINUX_URL="$RV220W_LINUX_URL" \
    RV220W_LINUX_REF="$RV220W_LINUX_REF" \
    RV220W_MERAKI_BUILDER_URL="$RV220W_MERAKI_BUILDER_URL" \
    RV220W_MERAKI_BUILDER_REF="$RV220W_MERAKI_BUILDER_REF" \
    bash "$inner"; or rv_die 'Source preparation failed'
rv_info 'Sources and feeds are ready.'
