#!/usr/bin/env bash
set -euo pipefail

ROOT=$(cd "$(dirname "$0")/.." && pwd)
GHIDRA_HOME=${GHIDRA_HOME:?Set GHIDRA_HOME to a Ghidra 12.1.2 installation}
HEADLESS="$GHIDRA_HOME/support/analyzeHeadless"
test -x "$HEADLESS"

build_one() {
    local module=$1 project=$2
    local project_dir="$ROOT/projects/$module"
    local export_dir="$ROOT/exports/$module"
    rm -rf "$project_dir" "$export_dir"
    mkdir -p "$project_dir" "$export_dir" "$ROOT/logs" "$ROOT/ghidra"

    local scripts=(
      -postScript RV220WRecoverPdrFunctions.java "$ROOT/tools/$module-pdr-map.tsv"
    )
    if [[ $module == mii ]]; then
      scripts+=( -postScript RV220WRecoverExports.java "$ROOT/tools/mii-export-map.tsv" )
    fi
    scripts+=(
      -postScript RV220WSemanticAnnotate.java "$module"
      -postScript RV220WWholeProgramPass.java "$export_dir" "$module"
    )

    "$HEADLESS" "$project_dir" "$project" \
      -import "$ROOT/originals/$module.ko" \
      -processor 'MIPS:BE:64:64-32addr' -cspec default -noanalysis \
      -scriptPath "$ROOT/tools" "${scripts[@]}" -overwrite \
      -log "$ROOT/logs/$module-import.log"

    "$HEADLESS" "$project_dir" "$project" \
      -process "$module.ko" -noanalysis -scriptPath "$ROOT/tools" \
      -postScript PackCurrentProgram.java "$ROOT/ghidra/$module.ko.gzf" \
      -log "$ROOT/logs/$module-pack.log"
}

build_one mii rv220w-mii
build_one bcm5398 rv220w-bcm5398
build_one scm-led rv220w-scm-led
build_one push_button rv220w-push_button
build_one cavium-ethernet rv220w-cavium-ethernet
python3 "$ROOT/tools/postprocess_reports.py"
