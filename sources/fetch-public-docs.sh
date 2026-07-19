#!/bin/sh
set -eu

OUT="$(dirname "$0")/downloads"
mkdir -p "$OUT"

fetch() {
    name=$1
    url=$2
    echo "Fetching $name"
    if command -v curl >/dev/null 2>&1; then
        curl -fL --retry 3 -o "$OUT/$name" "$url"
    elif command -v wget >/dev/null 2>&1; then
        wget -O "$OUT/$name" "$url"
    else
        echo "curl or wget is required" >&2
        exit 1
    fi
}

fetch rv220w-open-source-used-1.0.3.x.pdf \
  'https://device.report/m/f6723f558228d9192b556080c69f59b23f7f2aa6f3e62239ceddb34092fcd5e7.pdf'
fetch cn50xx-product-brief.pdf \
  'https://lafibre.info/images/doc/200710_Cavium_Networks_Octeon_Plus_CN5000F.pdf'
fetch cn50xx-hrm-v0.99e.pdf \
  'https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/hactive/CN50XX-HRM-V0.99E.pdf'
fetch bcm53115-product-brief.pdf \
  'https://docs.broadcom.com/docs/12381552'
fetch sn74lvc373a.pdf \
  'https://www.ti.com/lit/ds/scas295t/scas295t.pdf'
fetch ame8809.pdf \
  'https://www.ame.com.tw/datasheet/12-AME8806%208809%208842_112408_H.02.pdf'

( cd "$OUT" && sha256sum ./* > SHA256SUMS )
echo "Downloads and hashes stored in $OUT"
