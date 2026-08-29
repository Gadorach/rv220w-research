.PHONY: verify test test-root test-openwrt test-bootchain prebuilt-check hashes hashes-generate tree

verify: test prebuilt-check hashes
	PYTHONDONTWRITEBYTECODE=1 python3 tools/firmware/extract_rv220w_flash.py --help >/dev/null
	PYTHONDONTWRITEBYTECODE=1 python3 tools/uart/dump_uboot_flash_uart.py --help >/dev/null

test: test-root test-openwrt test-bootchain

test-root:
	PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover -s tests -p 'test_*.py'

test-openwrt:
	$(MAKE) -C openwrt verify

test-bootchain:
	PYTHONDONTWRITEBYTECODE=1 python3 firmware/reconstruction/bootloader-poc/tests/run_all.py

prebuilt-check:
	$(MAKE) -C openwrt prebuilt-check

hashes:
	sha256sum -c MANIFEST.core.sha256

hashes-generate:
	PYTHONDONTWRITEBYTECODE=1 python3 tools/evidence/hash_tree.py . --git --output MANIFEST.core.sha256

tree:
	find . -path './.git' -prune -o -print | sort
