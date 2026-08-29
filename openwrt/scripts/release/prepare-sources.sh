#!/usr/bin/env bash
set -euo pipefail
root=${RV220W_RELEASE_ROOT:?}
workspace=${RV220W_WORKSPACE:?}
lock_file="$root/source-lock.json"
[[ -f $lock_file ]] || { echo "qualified source lock is missing: $lock_file" >&2; exit 1; }
readarray -t source_identity < <(python3 - "$lock_file" <<'PY'
import json,sys
lock=json.load(open(sys.argv[1],encoding='utf-8'))
print(lock['openwrt']['url'])
print(lock['openwrt']['requested_ref'])
print(lock['openwrt']['commit'])
PY
)
url=${RV220W_OPENWRT_URL:-${source_identity[0]}}
ref=${RV220W_OPENWRT_REF:-${source_identity[1]}}
commit=${source_identity[2]}
mkdir -p "$workspace/sources" "$workspace/artifacts" "$workspace/logs" "$workspace/backups"
tree="$workspace/sources/openwrt"
if [[ ! -d "$tree/.git" ]]; then
  git clone --depth 1 --single-branch --branch "$ref" "$url" "$tree"
else
  current=$(git -C "$tree" describe --tags --exact-match HEAD 2>/dev/null || true)
  [[ $current == "$ref" ]] || { echo "OpenWrt checkout is $current, expected $ref" >&2; exit 1; }
fi
[[ $(git -C "$tree" rev-parse HEAD) == "$commit" ]] || { echo "OpenWrt checkout does not match source-lock.json" >&2; exit 1; }
python3 "$root/scripts/release/apply-openwrt.py" "$tree"
cd "$tree"
./scripts/feeds update -a
python3 - "$lock_file" "$tree" <<'PY'
import json,pathlib,subprocess,sys
lock=json.load(open(sys.argv[1],encoding='utf-8'))
tree=pathlib.Path(sys.argv[2])
feeds=tree/'feeds'
actual={path.name for path in feeds.iterdir() if (path/'.git').exists()}
expected=set(lock['feeds'])
if actual != expected:
    raise SystemExit(f'feed set differs from lock: actual={sorted(actual)} expected={sorted(expected)}')
for name,identity in sorted(lock['feeds'].items()):
    repo=feeds/name
    subprocess.run(['git','-C',str(repo),'fetch','--depth','1','origin',identity['commit']],check=True)
    subprocess.run(['git','-C',str(repo),'checkout','--detach',identity['commit']],check=True)
    if subprocess.check_output(['git','-C',str(repo),'rev-parse','HEAD'],text=True).strip()!=identity['commit']:
        raise SystemExit(f'{name} did not reach locked commit')
PY
./scripts/feeds install -a
python3 "$root/scripts/release/apply-openwrt.py" "$tree" --verify
python3 - "$lock_file" <<'PY'
import json,os,pathlib,subprocess
w=pathlib.Path(os.environ['RV220W_WORKSPACE']); t=w/'sources/openwrt'
def git(repo,*args):
    return subprocess.check_output(['git','-C',str(repo),*args],text=True,stderr=subprocess.DEVNULL).strip()
lock={
    'release_version': pathlib.Path(os.environ['RV220W_RELEASE_ROOT'],'VERSION').read_text().strip(),
    'openwrt':{
        'url':os.environ.get('RV220W_OPENWRT_URL','https://github.com/openwrt/openwrt.git'),
        'requested_ref':os.environ.get('RV220W_OPENWRT_REF','v25.12.5'),
        'commit':git(t,'rev-parse','HEAD'),
        'describe':git(t,'describe','--always','--tags'),
    },
    'feeds':{},
}
feeds=t/'feeds'
if feeds.is_dir():
    for repo in sorted(x for x in feeds.iterdir() if (x/'.git').exists()):
        try:
            origin=git(repo,'remote','get-url','origin')
        except Exception:
            origin=''
        lock['feeds'][repo.name]={'url':origin,'commit':git(repo,'rev-parse','HEAD')}
qualified=json.load(open(__import__('sys').argv[1],encoding='utf-8'))
if lock != qualified:
    raise SystemExit('prepared source identity differs from qualified source-lock.json')
(w/'source-lock.json').write_text(json.dumps(lock,indent=2,sort_keys=True)+'\n')
print(json.dumps(lock,indent=2,sort_keys=True))
PY
