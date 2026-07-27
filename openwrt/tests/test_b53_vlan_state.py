#!/usr/bin/env python3
from __future__ import annotations

import os
import pathlib
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
HELPER = ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-vlan-state"

FAKE_MDIO = r'''#!/bin/sh
set -eu
state=${FAKE_MDIO_STATE:?}
[ "$2" = phy ] && [ "$3" = 30 ] && [ "$4" = raw ] || {
    echo "bad mdio args: $*" >&2
    exit 2
}
reg=$5
if [ "$#" -eq 6 ]; then
    value=$6
    case "$reg" in
        16) printf '%s\n' "$value" > "$state/page" ;;
        24|25|26|27) printf '%s\n' "$value" > "$state/data$reg" ;;
        17)
            value_num=$((value))
            addr=$(((value_num >> 8) & 255))
            op=$((value_num & 3))
            page_num=$(cat "$state/page")
            page=$(((page_num >> 8) & 255))
            key="$state/switch_${page}_${addr}"
            if [ "$op" -eq 2 ]; then
                if [ -r "$key" ]; then
                    set -- $(cat "$key")
                else
                    set -- 0x0000 0x0000 0x0000 0x0000
                fi
                printf '%s\n' "$1" > "$state/data24"
                printf '%s\n' "$2" > "$state/data25"
                printf '%s\n' "$3" > "$state/data26"
                printf '%s\n' "$4" > "$state/data27"
            elif [ "$op" -eq 1 ]; then
                printf '%s %s %s %s\n' \
                    "$(cat "$state/data24")" "$(cat "$state/data25")" \
                    "$(cat "$state/data26")" "$(cat "$state/data27")" > "$key"
                if [ "$page" -eq 5 ] && [ "$addr" -eq 128 ]; then
                    access=$(($(cat "$state/data24")))
                    index=$(($(awk '{print $1}' "$state/switch_5_129")))
                    if [ $((access & 1)) -eq 1 ]; then
                        if [ -r "$state/vlan_$index" ]; then
                            cp "$state/vlan_$index" "$state/switch_5_131"
                        else
                            printf '0x0000 0x0000 0x0000 0x0000\n' > "$state/switch_5_131"
                        fi
                        printf '0x0001 0x0000 0x0000 0x0000\n' > "$key"
                    else
                        cp "$state/switch_5_131" "$state/vlan_$index"
                        printf '0x0000 0x0000 0x0000 0x0000\n' > "$key"
                    fi
                fi
            fi
            printf '0x%04x\n' $((addr << 8)) > "$state/addr"
            ;;
        *) echo "refused reg $reg" >&2; exit 3 ;;
    esac
else
    case "$reg" in
        16) cat "$state/page" ;;
        17) cat "$state/addr" ;;
        24|25|26|27) cat "$state/data$reg" ;;
        *) echo 0x0000 ;;
    esac
fi
'''

FAKE_IP = r'''#!/bin/sh
state=${FAKE_MDIO_STATE:?}
if [ "$1" = -d ] && [ "$2" = link ] && [ "$3" = show ] && [ "$4" = dev ] && [ "$5" = wan ]; then
    conduit=$(cat "$state/conduit")
    echo "5: wan@$conduit: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500"
    exit 0
fi
exit 2
'''


def run(helper: pathlib.Path, env: dict[str, str], *args: str, check: bool = True) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        ["/bin/sh", str(helper), *args],
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=check,
        timeout=15,
    )


def words(value: int) -> str:
    return f"0x{value & 0xffff:04x} 0x{(value >> 16) & 0xffff:04x} 0x0000 0x0000\n"


def read_words(path: pathlib.Path) -> int:
    ws = [int(v, 0) for v in path.read_text().split()]
    return ws[0] | (ws[1] << 16)


def main() -> int:
    subprocess.run(["/bin/sh", "-n", str(HELPER)], check=True)
    with tempfile.TemporaryDirectory(prefix="rv220w-vlan-test-") as td:
        tmp = pathlib.Path(td)
        bindir = tmp / "bin"
        bindir.mkdir()
        (bindir / "mdio").write_text(FAKE_MDIO)
        (bindir / "mdio").chmod(0o755)
        (bindir / "ip").write_text(FAKE_IP)
        (bindir / "ip").chmod(0o755)

        state = tmp / "state"
        state.mkdir()
        (state / "page").write_text("0x2401\n")
        (state / "addr").write_text("0xc000\n")
        (state / "conduit").write_text("eth1\n")
        for reg in (24, 25, 26, 27):
            (state / f"data{reg}").write_text("0x0000\n")
        # Port 0 VID 0, port 5 VID 1, port 8 VID 0.
        (state / "switch_52_16").write_text(words(0))
        (state / "switch_52_26").write_text(words(1))
        (state / "switch_52_32").write_text(words(0))
        (state / "switch_5_128").write_text(words(0))
        (state / "switch_5_129").write_text(words(0))
        (state / "switch_5_131").write_text(words(0))
        vlan0_original = 0x011E | (0x001E << 9)
        vlan1_original = 0x0000
        (state / "vlan_0").write_text(words(vlan0_original))
        (state / "vlan_1").write_text(words(vlan1_original))

        env = dict(os.environ)
        env["PATH"] = f"{bindir}:{env.get('PATH', '')}"
        env["FAKE_MDIO_STATE"] = str(state)
        env["RV220W_VLAN_STATE_DIR"] = str(tmp)

        result = run(HELPER, env, "show", "fake")
        assert "before_pvid5_vid=1" in result.stdout, result.stdout
        assert "before_vlan0_member_ports={1,2,3,4,8}" in result.stdout, result.stdout

        result = run(HELPER, env, "set-p5-pvid0", "fake", "RAM_ONLY_CONFIRM")
        assert "after_pvid5_vid=0" in result.stdout, result.stdout
        assert read_words(state / "switch_52_26") & 0xFFF == 0
        assert read_words(state / "vlan_0") == vlan0_original

        result = run(HELPER, env, "set-domain-vlan0", "fake", "RAM_ONLY_CONFIRM")
        assert "after_pvid0_vid=0" in result.stdout
        assert "after_pvid5_vid=0" in result.stdout
        entry0 = read_words(state / "vlan_0")
        assert entry0 & 0x1FF == 0x13F, hex(entry0)
        assert (entry0 >> 9) & 0x1FF == 0x01F, hex(entry0)

        result = run(HELPER, env, "set-domain-vlan1", "fake", "RAM_ONLY_CONFIRM")
        assert "after_pvid0_vid=1" in result.stdout
        assert "after_pvid5_vid=1" in result.stdout
        entry1 = read_words(state / "vlan_1")
        assert entry1 & 0x1FF == 0x021, hex(entry1)
        assert (entry1 >> 9) & 0x1FF == 0x001, hex(entry1)

        result = run(HELPER, env, "restore", "fake", "RAM_ONLY_CONFIRM")
        assert "result=ok" in result.stdout, result.stdout
        assert read_words(state / "switch_52_16") == 0
        assert read_words(state / "switch_52_26") == 1
        assert read_words(state / "switch_52_32") == 0
        assert read_words(state / "vlan_0") == vlan0_original
        assert read_words(state / "vlan_1") == vlan1_original
        assert int((state / "page").read_text(), 0) == 0x2401
        assert int((state / "addr").read_text(), 0) == 0xC000

        (state / "conduit").write_text("eth0\n")
        result = run(HELPER, env, "set-p5-pvid0", "fake", "RAM_ONLY_CONFIRM", check=False)
        assert result.returncode != 0
        assert "require live wan@eth1" in result.stderr

        result = run(HELPER, env, "set-p5-pvid0", "fake", check=False)
        assert result.returncode == 2
        assert "RAM_ONLY_CONFIRM" in result.stderr

    print("B53 VLAN/PVID helper simulation passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
