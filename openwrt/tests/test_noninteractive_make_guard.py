#!/usr/bin/env python3
"""Exercise the detached make invocation used by automated OpenWrt builds."""
from __future__ import annotations

import os
import pathlib
import shutil
import subprocess
import tempfile

setsid = shutil.which("setsid")
if setsid is None:
    raise SystemExit("setsid is required for noninteractive build guard test")

with tempfile.TemporaryDirectory(prefix="rv220w-make-guard-") as td:
    root = pathlib.Path(td)
    make = root / "make"
    result = root / "result.txt"
    make.write_text(
        "#!/bin/sh\n"
        "set -eu\n"
        "{\n"
        "  printf 'args=%s\\n' \"$*\"\n"
        "  printf 'stdin_tty=%s\\n' \"$([ -t 0 ] && echo yes || echo no)\"\n"
        "  printf 'term=%s\\n' \"${TERM-}\"\n"
        "  printf 'kconfig=%s\\n' \"${KCONFIG_NONINTERACTIVE-}\"\n"
        "  if (exec 3</dev/tty) 2>/dev/null; then echo tty_open=yes; else echo tty_open=no; fi\n"
        f"}} > {result!s}\n",
        encoding="utf-8",
    )
    make.chmod(0o755)
    env = os.environ.copy()
    env.update(
        {
            "PATH": f"{root}:{env.get('PATH', '')}",
            "CI": "1",
            "DEBIAN_FRONTEND": "noninteractive",
            "GIT_TERMINAL_PROMPT": "0",
            "KCONFIG_NONINTERACTIVE": "1",
            "TERM": "dumb",
        }
    )
    with open(os.devnull, "rb") as devnull:
        subprocess.run(
            [setsid, "--fork", "--wait", "make", "world", "V=s"],
            env=env,
            stdin=devnull,
            check=True,
        )
    values = dict(
        line.split("=", 1)
        for line in result.read_text(encoding="utf-8").splitlines()
    )
    expected = {
        "args": "world V=s",
        "stdin_tty": "no",
        "term": "dumb",
        "kconfig": "1",
        "tty_open": "no",
    }
    if values != expected:
        raise SystemExit(f"unexpected detached make environment: {values!r}")

print("detached noninteractive make guard regression check passed")
