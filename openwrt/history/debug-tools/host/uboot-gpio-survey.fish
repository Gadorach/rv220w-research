#!/usr/bin/env fish
set -l script_dir (dirname (status --current-filename))
source "$script_dir/lib/common.fish"
argparse 'p/port=' 'u/uart-baud=' 's/start=' 'e/end=' 'o/output-dir=' 'i/include-inputs' 'x/include-sensitive' -- $argv; or exit 2
if test (count $argv) -ne 0
    rv_die 'Usage: ./rv220w.fish uboot-gpio-survey [--port DEV] [--start 0] [--end 10] [--output-dir DIR] [--include-inputs] [--include-sensitive]'
end
set -l port
if set -q _flag_port
    set port $_flag_port
else
    set port (rv_find_serial); or rv_die 'Could not uniquely identify the UART adapter; pass --port.'
end
set -l baud 115200; set -q _flag_uart_baud; and set baud $_flag_uart_baud
set -l start 0; set -q _flag_start; and set start $_flag_start
set -l end 10; set -q _flag_end; and set end $_flag_end
set -l outdir "$PWD"; set -q _flag_output_dir; and set outdir $_flag_output_dir
set -l cmd python3 "$RV220W_TOOLKIT_ROOT/scripts/host/rv220w_uboot_gpio_survey.py" "$port" --baud "$baud" --start "$start" --end "$end" --output-dir "$outdir"
set -q _flag_include_inputs; and set -a cmd --include-inputs
set -q _flag_include_sensitive; and set -a cmd --include-sensitive
exec $cmd
