#!/usr/bin/env fish
set -l here (path resolve (dirname (status filename)))
set -l tool "$here/tools/rv220w_flash_combined_boot_policy.py"

if not test -x "$tool"
    echo "error: flasher tool is missing or not executable: $tool" >&2
    exit 1
end

# Serial-only operation: no TFTP server and no host-interface changes.
exec python3 "$tool" $argv
