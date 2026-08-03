.PHONY: verify test test-root test-openwrt test-bootchain hashes tree

verify: test hashes
	PYTHONDONTWRITEBYTECODE=1 python3 tools/firmware/extract_rv220w_flash.py --help >/dev/null
	PYTHONDONTWRITEBYTECODE=1 python3 tools/uart/dump_uboot_flash_uart.py --help >/dev/null

test: test-root test-openwrt test-bootchain

test-root:
	PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover -s tests -p 'test_*.py'

test-openwrt:
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_static_toolkit.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v1101_nor_writer_config_guard.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v1102_nor_transport.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v1103_nor_flash_boot.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v110_collector_cleanup.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v110_luci_nor_stage.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v191_production_cleanup.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v192_patch999_context.py
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_v193_fdt_verify_api.py

test-bootchain:
	PYTHONDONTWRITEBYTECODE=1 python3 firmware/reconstruction/bootloader-poc/tests/run_all.py

hashes:
	sha256sum -c MANIFEST.core.sha256

tree:
	find . -path './.git' -prune -o -print | sort
