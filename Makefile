.PHONY: verify test test-root test-openwrt hashes tree

verify: test hashes
	PYTHONDONTWRITEBYTECODE=1 python3 tools/firmware/extract_rv220w_flash.py --help >/dev/null
	PYTHONDONTWRITEBYTECODE=1 python3 tools/uart/dump_uboot_flash_uart.py --help >/dev/null

test: test-root test-openwrt

test-root:
	PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover -s tests -p 'test_*.py'

test-openwrt:
	PYTHONDONTWRITEBYTECODE=1 python3 openwrt/tests/test_static_toolkit.py

hashes:
	sha256sum -c MANIFEST.core.sha256

tree:
	find . -path './.git' -prune -o -print | sort
