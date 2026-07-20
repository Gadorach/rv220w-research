.PHONY: verify test hashes tree

verify: test hashes
	python3 tools/firmware/extract_rv220w_flash.py --help >/dev/null
	python3 tools/uart/dump_uboot_flash_uart.py --help >/dev/null

test:
	python3 -m unittest discover -s tests -p 'test_*.py'

hashes:
	sha256sum -c MANIFEST.core.sha256

tree:
	find . -path './.git' -prune -o -print | sort
