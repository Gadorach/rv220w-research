SHELL := /usr/bin/env bash
ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
VERSION := $(shell cat $(ROOT)/VERSION)
WORKSPACE ?= $(ROOT)/build
PREBUILT := $(abspath $(ROOT)/../prebuilt)
export RV220W_WORKSPACE := $(WORKSPACE)
export RV220W_BOX ?= rv220w-openwrt-release
export RV220W_OPENWRT_REF ?= v25.12.5
export RV220W_OPENWRT_URL ?= https://github.com/openwrt/openwrt.git
LIVEBOOT_ARGS ?=

# Both firmware profiles share one OpenWrt worktree. Never configure/build them
# concurrently, even if a caller invokes make -j.
.NOTPARALLEL:

.PHONY: all host-setup box-setup setup recreate-box sources platform initramfs sysupgrade \
        verify prebuilt-check artifacts-check u-boot-verify u-boot-patches initramfs-liveboot package clean distclean help next-steps

all: verify sources initramfs sysupgrade artifacts-check next-steps

host-setup:
	@echo '[rv220w] Checking/installing CachyOS/Arch host prerequisites...'
	@fish $(ROOT)/scripts/setup-host-cachyos.fish

box-setup: host-setup
	@echo '[rv220w] Creating/provisioning the Ubuntu 24.04 OpenWrt build box...'
	@fish $(ROOT)/scripts/setup-distrobox.fish

setup: box-setup

recreate-box: host-setup
	@fish $(ROOT)/scripts/setup-distrobox.fish --recreate

sources: setup
	@mkdir -p $(WORKSPACE)/sources $(WORKSPACE)/artifacts $(WORKSPACE)/logs $(WORKSPACE)/backups
	@fish $(ROOT)/scripts/release/prepare-sources.fish

platform: sources
	@distrobox enter --name "$(RV220W_BOX)" --no-tty -- \
		python3 "$(ROOT)/scripts/release/apply-openwrt.py" "$(WORKSPACE)/sources/openwrt" --verify

initramfs: sources
	@fish $(ROOT)/scripts/release/build.fish initramfs

sysupgrade: sources
	@fish $(ROOT)/scripts/release/build.fish sysupgrade

verify: prebuilt-check
	@python3 $(ROOT)/scripts/release/verify-release.py

prebuilt-check:
	@cd "$(PREBUILT)" && sha256sum -c SHA256SUMS
	@readelf -h "$(PREBUILT)/rv220w-openwrt-release-initramfs.elf" | grep -Eq 'Class:[[:space:]]+ELF64'
	@readelf -h "$(PREBUILT)/rv220w-openwrt-release-initramfs.elf" | grep -Eq 'Data:[[:space:]]+.*big endian'
	@readelf -h "$(PREBUILT)/rv220w-openwrt-release-initramfs.elf" | grep -Eq 'Machine:[[:space:]]+MIPS'
	@python3 $(ROOT)/scripts/host/verify_rv220w_sysupgrade.py "$(PREBUILT)/rv220w-openwrt-release-sysupgrade.tar"
	@echo '[rv220w] Bundled prebuilt images passed integrity and format checks.'

artifacts-check:
	@test -f "$(WORKSPACE)/artifacts/rv220w-openwrt-release-initramfs.elf" || { echo 'missing initramfs artifact' >&2; exit 1; }
	@test -f "$(WORKSPACE)/artifacts/rv220w-openwrt-release-sysupgrade.tar" || { echo 'missing sysupgrade artifact' >&2; exit 1; }
	@test -f "$(WORKSPACE)/artifacts/SHA256SUMS" || { echo 'missing artifact SHA256SUMS' >&2; exit 1; }
	@cd "$(WORKSPACE)/artifacts" && sha256sum -c SHA256SUMS
	@echo '[rv220w] Built artifacts passed checksum verification.'

u-boot-verify: host-setup
	@python3 $(ROOT)/scripts/release/uboot_patch.py --verify-only --backup-scope bootloader

u-boot-patches: host-setup
	@python3 $(ROOT)/scripts/release/uboot_patch.py

initramfs-liveboot: host-setup
	@python3 $(ROOT)/scripts/release/liveboot.py $(LIVEBOOT_ARGS)

next-steps:
	@printf '%s\n' \
	  '' \
	  'Build complete.' \
	  'Artifacts: $(WORKSPACE)/artifacts' \
	  '' \
	  'For a stock/unmodified RV220W:' \
	  '  Optional first: make u-boot-verify' \
	  '     - fast read-only 512 KiB boot-chain + 128 KiB U-Boot-environment backup' \
	  '     - verifies only bootloader compatibility; Cisco firmware partitions are ignored' \
	  '  1. make u-boot-patches' \
	  '     - hooks U-Boot over UART and checks for stock/already-qualified patch state' \
	  '     - offers full 32 MiB or warning-gated 640 KiB bootloader-only backup' \
	  '     - can leave an already-patched unit unchanged or force a qualified rewrite for testing' \
	  '     - installs/repairs bootdelay/openwrt_boot/bootcmd and saves the environment' \
	  '  2. make initramfs-liveboot' \
	  '     - TFTP-boots the LAN-only persistent-layout installer initramfs over a direct LAN connection' \
	  '     - monitors the RAM boot and offers an optional verified direct NOR install from the validated sysupgrade image' \
	  '' \
	  'After permanent installation:' \
	  '  LuCI: http://192.168.1.1/' \
	  '  Wi-Fi: SSID OpenWrt on 2.4 GHz (open on a fresh install)' \
	  '  WLAN LED: netdev TX+RX on phy0-ap0' \
	  '  Set a root password and secure Wi-Fi immediately.'


package: verify
	@python3 $(ROOT)/scripts/release/package-source.py

clean:
	@rm -rf $(WORKSPACE)/artifacts $(WORKSPACE)/logs
	@mkdir -p $(WORKSPACE)/artifacts $(WORKSPACE)/logs

# Leaves this source package untouched but removes all downloaded/generated state.
distclean:
	@rm -rf $(WORKSPACE)

help:
	@printf '%s\n' \
	 'RV220W OpenWrt release build' \
	 '' \
	 '  make all                 Setup environment, download OpenWrt, build initramfs + sysupgrade' \
	 '  make verify              Validate the release source/patch/config policy' \
	 '  make setup               Install host deps and provision Ubuntu 24.04 Distrobox' \
	 '  make recreate-box        Recreate and reprovision the dedicated build Distrobox' \
	 '  make sources             Fetch OpenWrt v25.12.5 and apply the minimal RV220W release delta' \
	 '  make initramfs           Build the LAN-only persistent-layout installer image' \
	 '  make sysupgrade          Build the persistent NOR sysupgrade image' \
	 '  make artifacts-check     Verify checksums of completed build artifacts' \
	 '  make prebuilt-check      Verify bundled hardware-qualified release images' \
	 '  make u-boot-verify       Fast read-only bootloader-region backup + compatibility check' \
	 '  make u-boot-patches      Guided guarded U-Boot onboarding; full or bootloader-only backup' \
	 '  make initramfs-liveboot  Guided UART/TFTP RAM boot; optional verified direct NOR install' \
	 '  make package             Create a versioned source-release ZIP + SHA-256' \
	 '  make clean               Remove generated artifacts/logs only' \
	 '  make distclean           Remove the complete local build workspace'
