#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse \
    'p/port=' \
    'u/uart-baud=' \
    't/timeout=' \
    'o/output-dir=' \
    'b/bus=' \
    'f/force-upload' \
    'r/require-b53' -- $argv; or exit 2
set -l label conduit
if test (count $argv) -ge 1
    set label $argv[1]
end
set label (string replace -ra '[^A-Za-z0-9._-]' '_' -- "$label")
set -l common
set -q _flag_port; and set -a common --port $_flag_port
set -q _flag_uart_baud; and set -a common --uart-baud $_flag_uart_baud
set -q _flag_timeout; and set -a common --timeout $_flag_timeout
set -l dsa_cmd "$RV220W_TOOLKIT_ROOT/scripts/collect-dsa.fish" "$label-dsa" $common
if set -q _flag_output_dir
    set -a dsa_cmd --output-dir (realpath -m "$_flag_output_dir/dsa")
end
rv_info "Collecting DSA state for conduit label '$label'"
command $dsa_cmd
or rv_die 'DSA half of conduit-state collection failed.'
set -l b53_cmd "$RV220W_TOOLKIT_ROOT/scripts/collect-b53.fish" "$label-b53" $common
set -q _flag_bus; and set -a b53_cmd --bus $_flag_bus
set -q _flag_force_upload; and set -a b53_cmd --force-upload
if set -q _flag_output_dir
    set -a b53_cmd --output-dir (realpath -m "$_flag_output_dir/b53")
end
rv_info "Collecting raw BCM53115 state for conduit label '$label'"
command $b53_cmd
set -l b53_status $status
switch $b53_status
    case 0
        rv_info 'Paired DSA and raw B53 collection completed.'
    case 3
        if set -q _flag_require_b53
            rv_die 'Raw B53 collection is unavailable and --require-b53 was requested.'
        end
        rv_warn 'Raw B53 collection skipped: the running production image excludes mdio-tools/mdio-netlink diagnostics.'
        printf '%s\n' 'b53_collection=skipped' 'reason=production image excludes mdio diagnostics'
    case '*'
        rv_die 'B53 half of conduit-state collection failed for a reason other than unavailable production diagnostics.'
end
