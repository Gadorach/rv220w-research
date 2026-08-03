#!/usr/bin/env python3
"""Ensure patch 999 matches the Linux 6.12 two-argument FDT API."""
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PATCH = ROOT / "openwrt/production/999-octeon-production-dt-flash-cleanups.patch"
EXPECTED = "early_init_dt_verify(initial_boot_params,\n\t\t\t\t  __pa(initial_boot_params))"

def fail(message: str) -> None:
    raise SystemExit(message)

text = PATCH.read_text(encoding="utf-8")
added_text = "\n".join(line[1:] for line in text.splitlines() if line.startswith("+") and not line.startswith("+++"))
if added_text.count(EXPECTED) != 1:
    fail("patch999 does not contain exactly one Linux 6.12 two-argument FDT verification call")
if "early_init_dt_verify(initial_boot_params))" in text:
    fail("patch999 still contains the v1.9.2 one-argument call")

setup_prefix = """void octeon_fill_mac_addresses(void);
void unflatten_and_copy_device_tree(void);
void init_octeon_system_type(void);
void panic(const char *);
typedef unsigned long phys_addr_t;
typedef _Bool bool;
extern bool early_init_dt_verify(void *dt_virt, phys_addr_t dt_phys);
#define __pa(x) ((phys_addr_t)(unsigned long)(x))
void *initial_boot_params;
"""
setup_function = """void device_tree_init(void)
{
        bool fill_mac = 1;
	if (fill_mac)
		octeon_fill_mac_addresses();
	unflatten_and_copy_device_tree();
	init_octeon_system_type();
}
"""
# Put the old hunk at its real Linux line number so GNU patch does not rely on
# a large synthetic offset. The line containing `if (fill_mac)` is old line 1228.
pre_if_lines = len((setup_prefix + setup_function.split("\tif (fill_mac)", 1)[0]).splitlines())
filler_count = 1228 - pre_if_lines - 1
setup = setup_prefix + ("/* fixture filler */\n" * filler_count) + setup_function

flash_body = """struct of_device_id { const char *compatible; };
static const struct of_device_id of_flash_match[] = {
	{
		.compatible = "cfi-flash",
	},
	{},
};
"""
flash_lines_before_table = len(flash_body.split("static const struct of_device_id of_flash_match[]", 1)[0].splitlines())
flash = ("/* flash fixture filler */\n" * (121 - flash_lines_before_table)) + flash_body

with tempfile.TemporaryDirectory(prefix="rv220w-v193-api-") as td:
    tree = Path(td)
    sf = tree / "arch/mips/cavium-octeon/setup.c"
    ff = tree / "arch/mips/cavium-octeon/flash_setup.c"
    sf.parent.mkdir(parents=True)
    sf.write_text(setup, encoding="utf-8")
    ff.write_text(flash, encoding="utf-8")
    result = subprocess.run(["patch", "--batch", "--forward", "-p1", "-i", str(PATCH)], cwd=tree, text=True, capture_output=True)
    if result.returncode:
        fail("patch999 did not apply to API fixture:\n" + result.stdout + result.stderr)
    patched = sf.read_text(encoding="utf-8")
    if shutil.which("gcc"):
        result = subprocess.run(["gcc", "-std=c11", "-Wall", "-Wextra", "-Werror", "-fsyntax-only", str(sf)], text=True, capture_output=True)
        if result.returncode:
            fail("patched FDT call failed API compilation:\n" + result.stdout + result.stderr)
    if "__pa(initial_boot_params)" not in patched:
        fail("patched setup.c lacks the physical FDT address")

print("v1.9.3 FDT verification API checks passed")
