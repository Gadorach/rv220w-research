#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'p/port=' 'o/output=' 'b/baud=' 'r/restart' 'x/extract' 'd/double' 'c/chunk=' 'P/from-power-cycle' 'T/interrupt-timeout=' -- $argv; or exit 2
rv_require python3 sha256sum cmp
set -l port
if set -q _flag_port
    set port $_flag_port
else
    set port (rv_find_serial); or rv_die 'Could not choose a serial adapter automatically; use --port'
end
set -l baud $RV220W_UART_BAUD
set -q _flag_baud; and set baud $_flag_baud
set -l stamp (rv_timestamp)
mkdir -p "$RV220W_TOOLKIT_ROOT/captures"
set -l output "$RV220W_TOOLKIT_ROOT/captures/rv220w-flash-32MiB-$stamp-read1.bin"
set -q _flag_output; and set output (realpath -m $_flag_output)
set -l dumper "$RV220W_UART_DUMPER"
if set -q _flag_from_power_cycle
    set -l interrupt_timeout 120
    set -q _flag_interrupt_timeout; and set interrupt_timeout $_flag_interrupt_timeout
    set -l interrupt_log "$output.uboot-interrupt.log"
    rv_info 'Waiting for a power cycle and automatically interrupting U-Boot with Ctrl-C.'
    python3 "$RV220W_TOOLKIT_ROOT/scripts/host/wait_uboot_prompt.py" "$port" \
        --timeout "$interrupt_timeout" --log "$interrupt_log"; or rv_die 'Could not capture the U-Boot prompt'
end
set -l command python3 "$dumper" "$port" --target-baud "$baud" --output "$output"
set -q _flag_restart; and set -a command --restart
set -q _flag_chunk; and set -a command --chunk $_flag_chunk
rv_info "JP1 wiring: 1=VCC/NC, 2=target TX->adapter RX, 3=target RX->adapter TX, 4=GND."
rv_info "Starting read-only U-Boot dump to $output"
$command; or rv_die 'UART dump failed or was interrupted; rerun the same command to resume'

if set -q _flag_double
    set -l output2 (string replace -r 'read1\.bin$' 'read2.bin' "$output")
    if test "$output2" = "$output"
        set output2 "$output.read2.bin"
    end
    rv_info "Starting independent second acquisition: $output2"
    python3 "$dumper" "$port" --target-baud "$baud" --output "$output2" --restart; or rv_die 'Second acquisition failed'
    sha256sum "$output" "$output2"
    cmp -s "$output" "$output2"; or rv_die 'The two complete dumps differ'
    rv_info 'The two complete images are byte-identical.'
end

if set -q _flag_extract
    "$RV220W_TOOLKIT_ROOT/scripts/extract-dump.fish" "$output"
end
