.PHONY: manifest check package

VERSION := 0.1.0
NAME := rv220w-research-v$(VERSION)-2026-07-19

manifest:
	python3 scripts/host/hash_tree.py . --output SHA256SUMS

check:
	python3 -m py_compile scripts/host/*.py scripts/helpers/*.py
	sh -n scripts/host/analyze-flash.sh scripts/target/collect-linux-inventory.sh scripts/target/dump-mtd.sh sources/fetch-public-docs.sh

package: manifest
	mkdir -p dist
	git bundle create dist/$(NAME).git.bundle --all
	cd .. && zip -qr $(NAME)/dist/$(NAME).zip $(NAME) -x '$(NAME)/dist/*' '$(NAME)/.git/*'
