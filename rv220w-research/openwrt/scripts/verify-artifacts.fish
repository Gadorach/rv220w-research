#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
rv_require python3 sha256sum
set -l failures 0
for script in "$RV220W_REPO_ROOT"/tools/uart/*.py "$RV220W_REPO_ROOT"/tools/firmware/*.py "$RV220W_TOOLKIT_ROOT"/scripts/host/*.py
    python3 -m py_compile "$script"
    or begin
        rv_warn "Python compile failed: $script"
        set failures (math $failures + 1)
    end
end
if test -d "$RV220W_WORKSPACE/artifacts"
    for image in "$RV220W_WORKSPACE"/artifacts/*.elf
        if test -f "$image"
            if command -q readelf
                readelf -h "$image" | grep -q 'Machine:.*MIPS'
                or begin
                    rv_warn "Not a MIPS ELF: $image"
                    set failures (math $failures + 1)
                end
            end
            sha256sum "$image"
        end
    end
end
if test $failures -gt 0
    rv_die "$failures verification failure(s)"
end
rv_info 'Available artifacts passed static checks.'
