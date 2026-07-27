#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
rv_require python3 sha256sum fish bash
set -l failures 0

for script in "$RV220W_TOOLKIT_ROOT/rv220w.fish" "$RV220W_TOOLKIT_ROOT"/scripts/*.fish "$RV220W_TOOLKIT_ROOT"/scripts/lib/*.fish
    if test -f "$script"
        fish -n "$script"
        or begin
            rv_warn "Fish syntax check failed: $script"
            set failures (math $failures + 1)
        end
    end
end
for script in "$RV220W_TOOLKIT_ROOT"/scripts/inner/*.sh
    if test -f "$script"
        bash -n "$script"
        or begin
            rv_warn "Bash syntax check failed: $script"
            set failures (math $failures + 1)
        end
    end
end
for script in "$RV220W_TOOLKIT_ROOT"/scripts/host/*.py
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
