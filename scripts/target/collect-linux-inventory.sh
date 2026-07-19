#!/bin/sh
# Read-only stock-firmware inventory collector.
set -u

OUT=${1:-/tmp/rv220w-inventory}
mkdir -p "$OUT"

capture() {
    name=$1
    shift
    echo "== $*" > "$OUT/$name.txt"
    "$@" >> "$OUT/$name.txt" 2>&1 || true
}

for f in cpuinfo cmdline mtd partitions interrupts iomem ioports devices modules mounts meminfo version; do
    if [ -r "/proc/$f" ]; then
        cat "/proc/$f" > "$OUT/proc-$f.txt"
    fi
done

capture dmesg dmesg
capture uname uname -a
capture mount mount
capture df df -h
capture ip-address ip address show
capture ip-link ip -details link show
capture ip-route ip route show table all
capture ifconfig ifconfig -a
capture lsmod lsmod
capture lspci lspci -nn -vv
capture lsusb lsusb
capture env env

if command -v fw_printenv >/dev/null 2>&1; then
    capture fw-printenv fw_printenv
fi
if command -v nvram >/dev/null 2>&1; then
    capture nvram-show nvram show
fi

find /sys/class/leds -maxdepth 3 -type f -print 2>/dev/null > "$OUT/sys-led-files.txt" || true
find /sys/class/gpio -maxdepth 3 -type f -print 2>/dev/null > "$OUT/sys-gpio-files.txt" || true
find /sys/bus/pci/devices -maxdepth 2 -type f -print 2>/dev/null > "$OUT/sys-pci-files.txt" || true

( cd "$OUT" && sha256sum ./* > SHA256SUMS 2>/dev/null ) || true
echo "Inventory written to $OUT"
