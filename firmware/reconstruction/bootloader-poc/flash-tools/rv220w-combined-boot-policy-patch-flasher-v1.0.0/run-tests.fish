#!/usr/bin/env fish
set -l here (path resolve (dirname (status filename)))
exec python3 "$here/tests/test_offline.py"
