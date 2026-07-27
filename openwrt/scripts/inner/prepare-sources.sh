#!/usr/bin/env bash
set -euo pipefail

workspace=${RV220W_WORKSPACE:?}
mkdir -p "$workspace/sources" "$workspace/artifacts" "$workspace/logs"

for command_name in git perl python3; do
    command -v "$command_name" >/dev/null 2>&1 || {
        echo "required container command missing: $command_name; run setup-box" >&2
        exit 1
    }
done
perl -MFindBin -e 1 >/dev/null 2>&1 || {
    echo 'Perl core module FindBin is missing; run setup-box in the Ubuntu container' >&2
    exit 1
}

clone_or_update() {
    local url=$1 ref=$2 dest=$3
    if [[ -d "$dest/.git" ]]; then
        if [[ ${RV220W_UPDATE:-0} == 1 ]]; then
            if [[ -n $(git -C "$dest" status --porcelain) ]]; then
                echo "Refusing to update dirty managed checkout: $dest" >&2
                return 1
            fi
            git -C "$dest" fetch --depth 1 --tags origin "$ref"
            git -C "$dest" checkout --detach FETCH_HEAD
        fi
        return
    fi

    # A branch/tag-specific shallow clone avoids the multi-gigabyte full Linux
    # history download seen when a server ignores partial-clone filtering.
    git clone --depth 1 --single-branch --branch "$ref" "$url" "$dest"
}

linux_dest="$workspace/sources/linux-reference"
if [[ ${RV220W_RECLONE_LINUX:-0} == 1 && -e "$linux_dest" ]]; then
    if [[ -d "$linux_dest/.git" && -n $(git -C "$linux_dest" status --porcelain) ]]; then
        echo "Refusing to replace dirty Linux checkout: $linux_dest" >&2
        exit 1
    fi
    backup="$workspace/sources/linux-reference.full-history.$(date -u +%Y%m%dT%H%M%SZ)"
    mv "$linux_dest" "$backup"
    echo "Moved previous Linux checkout to: $backup"
fi

clone_or_update "$RV220W_OPENWRT_URL" "$RV220W_OPENWRT_REF" "$workspace/sources/openwrt"
clone_or_update "$RV220W_LINUX_URL" "$RV220W_LINUX_REF" "$linux_dest"
clone_or_update "$RV220W_MERAKI_BUILDER_URL" "$RV220W_MERAKI_BUILDER_REF" "$workspace/sources/meraki-builder-reference"

toolkit=$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)
python3 "$toolkit/scripts/inner/install-rv220w-platform.py" "$workspace/sources/openwrt"

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
