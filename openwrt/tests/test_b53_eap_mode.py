#!/usr/bin/env python3
from __future__ import annotations

import os
import pathlib
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
HELPER = ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-eap-mode"

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


def run(
    helper: pathlib.Path,
    env: dict[str, str],
    *args: str,
    check: bool = True,
) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        ["/bin/sh", str(helper), *args],
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=check,
        timeout=10,
    )


def main() -> int:
    subprocess.run(["/bin/sh", "-n", str(HELPER)], check=True)
    with tempfile.TemporaryDirectory(prefix="rv220w-eap-test-") as td:
        tmp = pathlib.Path(td)
        bindir = tmp / "bin"
        bindir.mkdir()
        mdio = bindir / "mdio"
        mdio.write_text(FAKE_MDIO)
        mdio.chmod(0o755)

        state_dir = tmp / "state"
        state_dir.mkdir()
        (state_dir / "page").write_text("0x2401\n")
        (state_dir / "addr").write_text("0xc000\n")
        for reg in (24, 25, 26, 27):
            (state_dir / f"data{reg}").write_text("0x0000\n")
        original_words = [0x1234, 0x5678, 0x9ABC, 0xA018]
        (state_dir / "switch_66_32").write_text(
            " ".join(f"0x{word:04x}" for word in original_words) + "\n"
        )

        env = dict(os.environ)
        env["PATH"] = f"{bindir}:{env.get('PATH', '')}"
        env["FAKE_MDIO_STATE"] = str(state_dir)
        env["RV220W_EAP_STATE_DIR"] = str(tmp)

        def switch_words() -> list[int]:
            return [
                int(word, 0)
                for word in (state_dir / "switch_66_32").read_text().split()
            ]

        result = run(HELPER, env, "show", "0", "fake")
        assert "before_mode=simplified" in result.stdout, result.stdout

        result = run(HELPER, env, "set-basic", "0", "fake")
        assert "after_mode=basic" in result.stdout, result.stdout
        assert switch_words() == [0x1234, 0x5678, 0x9ABC, 0xA000]
        assert int((state_dir / "page").read_text(), 0) == 0x2401
        assert int((state_dir / "addr").read_text(), 0) == 0xC000

        result = run(HELPER, env, "set-simplified", "0", "fake")
        assert "after_mode=simplified" in result.stdout, result.stdout
        assert switch_words() == [0x1234, 0x5678, 0x9ABC, 0xA018]

        result = run(HELPER, env, "restore", "0", "fake")
        assert "result=ok" in result.stdout, result.stdout
        assert switch_words() == original_words

        result = run(HELPER, env, "set-basic", "5", "fake", check=False)
        assert result.returncode == 90, (result.returncode, result.stderr)
        assert "write actions are restricted" in result.stderr

    print("B53 EAP helper simulation passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
