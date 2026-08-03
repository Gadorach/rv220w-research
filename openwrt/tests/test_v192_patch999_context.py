#!/usr/bin/env python3
"""Validate patch 999 against OpenWrt-modified Octeon source context."""
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PATCH = ROOT / "openwrt/production/999-octeon-production-dt-flash-cleanups.patch"

def fail(msg):
    raise SystemExit(msg)

patch_text = PATCH.read_text()
added_text = "\n".join(line[1:] for line in patch_text.splitlines() if line.startswith("+") and not line.startswith("+++"))
if 'pr_info("Using internal Device Tree.' in patch_text:
    fail("patch999 again includes the OpenWrt-modified prune block")
if added_text.count("early_init_dt_verify(initial_boot_params,\n\t\t\t\t  __pa(initial_boot_params))") != 1:
    fail("patch999 must add exactly one post-fixup verification call")

setup = r'''/* representative Linux 6.12 / OpenWrt Octeon setup tail */
void __init device_tree_init(void)
{
	const void *fdt;
	bool do_prune;
	bool fill_mac;

	/* OpenWrt patch 400 adds board-specific DT selection above this point. */
	if (octeon_is_ubnt()) {
		fdt = &__dtb_ubnt_begin;
		do_prune = false;
		fill_mac = true;
	} else {
		fdt = &__dtb_octeon_3xxx_begin;
		do_prune = true;
		fill_mac = true;
	}

	initial_boot_params = (void *)fdt;

	/* Deliberately different from the v1.9.1 hunk context. */
	if (do_prune)
		octeon_prune_device_tree();

	if (fill_mac)
		octeon_fill_mac_addresses();
	unflatten_and_copy_device_tree();
	init_octeon_system_type();
}
'''
flash = r'''static int octeon_flash_probe(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id of_flash_match[] = {
	{
		.compatible = "cfi-flash",
	},
	{},
};
'''

with tempfile.TemporaryDirectory(prefix="rv220w-v192-patch-") as td:
    tree = Path(td)
    setup_file = tree / "arch/mips/cavium-octeon/setup.c"
    flash_file = tree / "arch/mips/cavium-octeon/flash_setup.c"
    setup_file.parent.mkdir(parents=True)
    setup_file.write_text(setup)
    flash_file.write_text(flash)
    result = subprocess.run(
        ["patch", "--batch", "--forward", "-p1", "-i", str(PATCH)],
        cwd=tree,
        text=True,
        capture_output=True,
    )
    if result.returncode:
        fail("corrected patch999 did not apply to OpenWrt-modified fixture:\n" + result.stdout + result.stderr)
    if "fuzz" in (result.stdout + result.stderr).lower():
        fail("corrected patch999 required fuzz on the regression fixture")
    setup_after = setup_file.read_text()
    flash_after = flash_file.read_text()
    if setup_after.index("octeon_fill_mac_addresses();") > setup_after.index("early_init_dt_verify(initial_boot_params,"):
        fail("FDT verification was inserted before MAC fixups")
    if setup_after.index("early_init_dt_verify(initial_boot_params,") > setup_after.index("unflatten_and_copy_device_tree();"):
        fail("FDT verification was inserted after unflattening")
    if flash_after.count("cavium,octeon-3860-bootbus-flash") != 1:
        fail("BootBus compatible missing or duplicated")

print("v1.9.2 patch999 post-OpenWrt-context checks passed")
