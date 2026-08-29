#!/usr/bin/env python3
from __future__ import annotations

import gzip
import importlib.util
import io
import json
import os
import pathlib
import re
import struct
import subprocess
import sys
import tarfile
import tempfile

sys.dont_write_bytecode = True

ROOT = pathlib.Path(__file__).resolve().parents[2]
VERSION = (ROOT / "VERSION").read_text().strip()


def req(cond: bool, msg: str) -> None:
    if not cond:
        raise SystemExit("FAIL: " + msg)


def check_installer_openwrt_shell_compat(installer: pathlib.Path) -> None:
    """Prove the OpenWrt library preamble survives BusyBox ash nounset."""
    text = installer.read_text()
    req(not re.search(r"(?m)^\s*set\s+-u(?:\s|$)", text), "direct installer still enables nounset across OpenWrt shell libraries")
    init = 'IPKG_INSTROOT="${IPKG_INSTROOT:-}"'
    source = ". /lib/functions.sh"
    req(init in text and source in text and text.index(init) < text.index(source),
        "direct installer does not initialize IPKG_INSTROOT before sourcing /lib/functions.sh")
    req("export IPKG_INSTROOT" in text, "direct installer does not export IPKG_INSTROOT")

    busybox = subprocess.run(["sh", "-c", "command -v busybox || true"], text=True, capture_output=True, check=True).stdout.strip()
    if not busybox:
        return
    with tempfile.TemporaryDirectory() as td:
        root = pathlib.Path(td)
        fake = root / "functions.sh"
        # Model the failure seen on hardware: OpenWrt library code directly
        # dereferences IPKG_INSTROOT while the caller has nounset enabled.
        fake.write_text('seen="$IPKG_INSTROOT"\n[ -z "$seen" ]\n')
        probe = root / "probe.sh"
        probe.write_text(
            '#!/bin/sh\n'
            'set -u\n'
            'IPKG_INSTROOT="${IPKG_INSTROOT:-}"\n'
            'export IPKG_INSTROOT\n'
            f'. "{fake}"\n'
            'echo RV220W_OPENWRT_SHELL_COMPAT_PASS\n'
        )
        proc = subprocess.run([busybox, "ash", str(probe)], text=True, capture_output=True)
        req(proc.returncode == 0 and "RV220W_OPENWRT_SHELL_COMPAT_PASS" in proc.stdout,
            "BusyBox nounset compatibility probe failed: " + (proc.stderr.strip() or proc.stdout.strip()))


def check_release_tree_migration() -> None:
    """Prove prior-release re-ownership preserves caches and refuses user edits."""
    apply_path = ROOT / "scripts/release/apply-openwrt.py"
    spec = importlib.util.spec_from_file_location("rv220w_apply_openwrt", apply_path)
    req(spec is not None and spec.loader is not None, "cannot load source migration helper")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)

    with tempfile.TemporaryDirectory() as td:
        tree = pathlib.Path(td) / "openwrt"
        tree.mkdir()
        subprocess.run(["git", "init", "-q"], cwd=tree, check=True)
        subprocess.run(["git", "config", "user.email", "rv220w-test@example.invalid"], cwd=tree, check=True)
        subprocess.run(["git", "config", "user.name", "RV220W release test"], cwd=tree, check=True)

        tracked = sorted(mod.RELEASE_TRACKED_PATHS)
        for rel in tracked:
            path = tree / rel
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("upstream\n")
        subprocess.run(["git", "add", "."], cwd=tree, check=True)
        subprocess.run(["git", "commit", "-qm", "base"], cwd=tree, check=True)
        subprocess.run(["git", "tag", mod.OPENWRT_REF], cwd=tree, check=True)

        # Simulate a prior release: tracked integration changes plus known
        # untracked RV220W injection files.  Add unrelated caches that must live.
        for rel in tracked:
            (tree / rel).write_text("prior release\n")
        marker = tree / ".rv220w-release"
        marker.write_text("1.16.0-rc4\n")
        dts = tree / mod.RELEASE_OWNED_UNTRACKED[0]
        dts.parent.mkdir(parents=True, exist_ok=True)
        dts.write_text("prior dts\n")
        old_patch = tree / "target/linux/octeon/patches-6.12/900-rv220w-old.patch"
        old_patch.parent.mkdir(parents=True, exist_ok=True)
        old_patch.write_text("prior patch\n")
        cache = tree / "dl/keep-me.tar.zst"
        cache.parent.mkdir(parents=True, exist_ok=True)
        cache.write_text("cache\n")
        build_cache = tree / "build_dir/keep-me/object.o"
        build_cache.parent.mkdir(parents=True, exist_ok=True)
        build_cache.write_text("cache\n")

        mod.reset_previous_release_tree(tree, marker, "1.16.0-rc4")
        req(not marker.exists(), "prior release marker survived automatic migration reset")
        req(not dts.exists() and not old_patch.exists(), "prior release-owned untracked injections survived migration")
        req(cache.read_text() == "cache\n" and build_cache.read_text() == "cache\n",
            "automatic migration destroyed OpenWrt download/build cache")
        req(not subprocess.check_output(["git", "diff", "--name-only"], cwd=tree, text=True).strip(),
            "automatic migration did not restore tracked OpenWrt base")

        # A tracked edit outside our integration surface must stop migration.
        user_file = tree / "README"
        user_file.write_text("base\n")
        subprocess.run(["git", "add", "README"], cwd=tree, check=True)
        subprocess.run(["git", "commit", "-qm", "add user file"], cwd=tree, check=True)
        # Move the v25.12.5 tag to this synthetic HEAD so the helper's hard reset
        # target remains available without introducing an unrelated ref mismatch.
        subprocess.run(["git", "tag", "-f", mod.OPENWRT_REF], cwd=tree, check=True, stdout=subprocess.DEVNULL)
        user_file.write_text("local edit\n")
        marker.write_text("1.16.0-rc4\n")
        try:
            mod.reset_previous_release_tree(tree, marker, "1.16.0-rc4")
        except SystemExit as exc:
            req("outside the release-owned integration surface" in str(exc),
                "unexpected diagnostic for tracked-user-edit migration refusal")
        else:
            raise SystemExit("FAIL: source migration reset a tracked user edit outside the release-owned surface")
        req(user_file.read_text() == "local edit\n", "migration refusal destroyed tracked user edit")


def check_patch(path: pathlib.Path) -> None:
    """Catch malformed hand-edited unified-diff hunk counts without applying it."""
    lines = path.read_text(errors="replace").splitlines()
    hunks = 0
    i = 0
    while i < len(lines):
        if not lines[i].startswith("@@ "):
            i += 1
            continue
        m = re.match(r"@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@", lines[i])
        req(bool(m), f"bad hunk header: {path}:{i + 1}")
        old_want = int(m.group(2) or 1)
        new_want = int(m.group(4) or 1)
        old = new = 0
        i += 1
        while i < len(lines):
            line = lines[i]
            if line.startswith("@@ ") or line.startswith("--- a/") or line.startswith("diff --git "):
                break
            if line == "-- ":
                break
            if line.startswith(" "):
                old += 1
                new += 1
            elif line.startswith("-") and not line.startswith("---"):
                old += 1
            elif line.startswith("+") and not line.startswith("+++"):
                new += 1
            i += 1
        req(
            (old, new) == (old_want, new_want),
            f"hunk line counts disagree in {path.name}: {(old, new)} != {(old_want, new_want)}",
        )
        hunks += 1
    req(hunks > 0, f"no patch hunks: {path}")



def check_wifi_defaults_behavior(script: pathlib.Path) -> None:
    """Exercise the fresh-template vs administrator-config branch with a stub UCI CLI."""
    uci_stub = r'''#!/bin/sh
[ "$1" = -q ] && shift
cmd=$1
shift || true
case "$cmd" in
  show)
    [ "$1" = wireless ] || exit 1
    cat <<EOF
wireless.radio0=wifi-device
wireless.default_radio0=wifi-iface
EOF
    ;;
  get)
    case "$1" in
      wireless.radio0.disabled) [ "$RV220W_UCI_SCENARIO" = pristine ] && echo 1 || echo 0 ;;
      wireless.default_radio0.mode) echo ap ;;
      wireless.default_radio0.network) echo lan ;;
      wireless.default_radio0.ssid) [ "$RV220W_UCI_SCENARIO" = pristine ] && echo OpenWrt || echo AdministratorAP ;;
      wireless.default_radio0.encryption) [ "$RV220W_UCI_SCENARIO" = pristine ] && echo none || echo psk2 ;;
      wireless.default_radio0.disabled) exit 1 ;;
      *) exit 1 ;;
    esac
    ;;
  set|delete|add|add_list|commit)
    printf '%s %s\n' "$cmd" "$*" >> "$RV220W_UCI_LOG"
    [ "$cmd" = add ] && echo cfgtest
    ;;
  *) exit 1 ;;
esac
'''
    with tempfile.TemporaryDirectory(prefix="rv220w-release-wifi-test-") as td:
        td = pathlib.Path(td)
        bindir = td / "bin"
        bindir.mkdir()
        for name, body in {
            "uci": uci_stub,
            "wifi": "#!/bin/sh\nexit 0\n",
            "logger": "#!/bin/sh\nexit 0\n",
        }.items():
            path = bindir / name
            path.write_text(body)
            path.chmod(0o755)
        wireless = td / "wireless"
        wireless.write_text("fixture\n")

        def run_case(scenario: str) -> str:
            log = td / f"{scenario}.log"
            log.write_text("")
            env = os.environ.copy()
            env.update({
                "PATH": str(bindir) + os.pathsep + env.get("PATH", ""),
                "RV220W_WIRELESS_CONFIG": str(wireless),
                "RV220W_UCI_SCENARIO": scenario,
                "RV220W_UCI_LOG": str(log),
            })
            subprocess.run(["sh", str(script)], env=env, check=True)
            return log.read_text()

        pristine = run_case("pristine")
        req("set wireless.radio0.disabled=0" in pristine, "pristine OpenWrt radio is not enabled")
        req("set wireless.default_radio0.ssid=OpenWrt" in pristine, "pristine OpenWrt AP is not normalized")
        req("delete wireless.default_radio0.disabled" in pristine, "pristine interface disable flag is not cleared")
        req("commit wireless" in pristine, "fresh wireless defaults are not committed")

        customized = run_case("customized")
        req(customized == "", "administrator wireless configuration would be modified by first-boot defaults")



def check_uboot_bootchain_behavior(script: pathlib.Path) -> None:
    """Exercise stock/patched/unknown boot-chain classification without hardware."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("rv220w_uboot_patch_test", script)
    req(spec is not None and spec.loader is not None, "could not load U-Boot onboarding module")
    mod = importlib.util.module_from_spec(spec)
    old_dont_write = sys.dont_write_bytecode
    sys.dont_write_bytecode = True
    try:
        spec.loader.exec_module(mod)
    finally:
        sys.dont_write_bytecode = old_dont_write
    with tempfile.TemporaryDirectory(prefix="rv220w-uboot-policy-test-") as td_raw:
        td = pathlib.Path(td_raw)
        # Build a synthetic sector/boot-chain and set the module's expected CRC
        # to that fixture. This tests classification mechanics without shipping
        # copyrighted/vendor bootloader bytes.
        patched = bytearray(mod.BOOT_CHAIN_SIZE)
        for off, _stock, target, _name in mod.PATCHES:
            patched[off:off+4] = target
        fixture_crc = mod.crc32(patched[:mod.SECTOR_SIZE])
        mod.EXPECTED_PATCHED_CRC = fixture_crc
        patched_path = td / "patched.bin"
        patched_path.write_bytes(patched)
        info = mod.validate_boot_chain(patched_path, td / "patched-sector.bin")
        req(info["code_state"] == "qualified-patched", "already-patched boot-chain is not recognized")

        stock = bytearray(patched)
        for off, stock_bytes, _target, _name in mod.PATCHES:
            stock[off:off+4] = stock_bytes
        stock_path = td / "stock.bin"
        stock_path.write_bytes(stock)
        info = mod.validate_boot_chain(stock_path, td / "stock-sector.bin")
        req(info["code_state"] == "stock-compatible", "stock boot-chain is not recognized")

        bad = bytearray(stock)
        off = mod.PATCHES[0][0]
        bad[off:off+4] = b"\xde\xad\xbe\xef"
        bad_path = td / "bad.bin"
        bad_path.write_bytes(bad)
        try:
            mod.validate_boot_chain(bad_path, td / "bad-sector.bin")
        except RuntimeError:
            pass
        else:
            raise SystemExit("FAIL: unknown U-Boot instruction bytes did not fail closed")


def check_low_memory_sysupgrade_behavior(platform_script: pathlib.Path) -> None:
    """Exercise the no-backup streaming validator/write path with fake MTD files."""
    with tempfile.TemporaryDirectory(prefix="rv220w-lowmem-sysupgrade-test-") as td_raw:
        td = pathlib.Path(td_raw)
        board = "sysupgrade-cisco,rv220w"
        kernel_raw = b"\x7fELF" + (b"K" * 508)
        kernel = gzip.compress(kernel_raw, mtime=0)
        root = bytearray(1024)
        root[0:4] = b"hsqs"
        struct.pack_into("<Q", root, 40, 96)
        tar_path = td / "fixture.tar"
        with tarfile.open(tar_path, "w", format=tarfile.GNU_FORMAT) as tf:
            di = tarfile.TarInfo(board + "/")
            di.type = tarfile.DIRTYPE
            di.mode = 0o755
            tf.addfile(di)
            for name, payload in (
                ("CONTROL", b"BOARD=cisco,rv220w\n"),
                ("kernel", kernel),
                ("root", bytes(root)),
            ):
                ti = tarfile.TarInfo(f"{board}/{name}")
                ti.size = len(payload)
                ti.mode = 0o644
                tf.addfile(ti, io.BytesIO(payload))

        bindir = td / "bin"
        bindir.mkdir()
        hexdump = bindir / "hexdump"
        hexdump.symlink_to("/usr/bin/busybox")
        mtd = bindir / "mtd"
        mtd.write_text(r'''#!/bin/sh
set -eu
len=
while [ "$#" -gt 0 ]; do
  case "$1" in
    -q) shift ;;
    -l) len=$2; shift 2 ;;
    unlock|erase|write|dump) cmd=$1; shift; break ;;
    *) echo "fake mtd: unsupported option $1" >&2; exit 2 ;;
  esac
done
case "$cmd" in
  unlock) exit 0 ;;
  erase) : > "$FAKE_MTD_DIR/$1" ;;
  write)
    image=$1; part=$2
    if [ "$image" = - ]; then cat > "$FAKE_MTD_DIR/$part"; else cp "$image" "$FAKE_MTD_DIR/$part"; fi
    ;;
  dump)
    part=$1
    [ -n "$len" ] || len=$(wc -c < "$FAKE_MTD_DIR/$part")
    dd if="$FAKE_MTD_DIR/$part" bs=1 count="$len" 2>/dev/null
    ;;
esac
''')
        mtd.chmod(0o755)
        mtd_dir = td / "mtd"
        mtd_dir.mkdir()
        env = os.environ.copy()
        env.update({
            "PATH": str(bindir) + os.pathsep + env.get("PATH", ""),
            "FAKE_MTD_DIR": str(mtd_dir),
            "UPGRADE_BACKUP": "",
        })
        script = f'''
set -e
. "{platform_script}"
rv220w_check_layout() {{ return 0; }}
rv220w_validate_upgrade_stream "{tar_path}" "{board}"
rv220w_do_upgrade "{tar_path}"
'''
        cp = subprocess.run(["bash", "-c", script], env=env, text=True, capture_output=True)
        req(cp.returncode == 0, f"low-memory sysupgrade fixture failed: stdout={cp.stdout!r} stderr={cp.stderr!r}")
        req("RV220W low-memory image validation" in cp.stdout, "streaming target validator was not exercised")
        req("stream/readback SHA-256 verified" in cp.stdout, "streaming MTD readback verification was not exercised")
        req((mtd_dir / "rootfs").read_bytes() == bytes(root), "streamed rootfs bytes differ from tar member")
        req((mtd_dir / "openwrt-kernel").read_bytes() == kernel, "streamed kernel bytes differ from tar member")

def main() -> None:
    req((ROOT / "VERSION").read_text().strip() == VERSION, "VERSION mismatch")
    req(not (ROOT / "rv220w.fish").exists(), "legacy promotion-toolkit CLI leaked into release root")
    req(not (ROOT / "toolkit.json").exists(), "promotion toolkit metadata leaked into release root")

    config_names = sorted(p.name for p in (ROOT / "config").glob("*"))
    req(
        config_names
        == ["openwrt-rv220w-release-initramfs.config", "openwrt-rv220w-release-sysupgrade.config"],
        f"unexpected active build configs: {config_names}",
    )
    persistent = (ROOT / "config/openwrt-rv220w-release-sysupgrade.config").read_text()
    initramfs = (ROOT / "config/openwrt-rv220w-release-initramfs.config").read_text()
    for config in (persistent, initramfs):
        req('CONFIG_TARGET_PREINIT_IP="192.168.1.1"' in config, "release preinit IP is not 192.168.1.1")
        req("CONFIG_PACKAGE_B43_DEBUG=y" not in config, "B43_DEBUG enabled")
        req("CONFIG_PACKAGE_tcpdump-mini=y" not in config, "tcpdump-mini included")
        req("CONFIG_PACKAGE_mtd=y" in config, "mtd utility missing")
        req("CONFIG_PACKAGE_kmod-dsa-b53=y" in config, "B53 DSA support missing")
    for token, msg in (
        ("CONFIG_PACKAGE_wpad=y", "full wpad missing from persistent image"),
        ("CONFIG_PACKAGE_luci-light=y", "LuCI missing from persistent image"),
        ("CONFIG_PACKAGE_luci-app-package-manager=y", "LuCI package manager missing from persistent image"),
        ("CONFIG_PACKAGE_kmod-b43=y", "b43 missing from persistent image"),
        ("CONFIG_PACKAGE_kmod-leds-gpio=y", "GPIO LED support missing from persistent image"),
        ("CONFIG_PACKAGE_kmod-ledtrig-network=y", "netdev LED trigger support missing from persistent image"),
    ):
        req(token in persistent, msg)
    for token in (
        "CONFIG_PACKAGE_kmod-b43=y",
        "CONFIG_PACKAGE_wpad=y",
        "CONFIG_PACKAGE_luci-light=y",
        "CONFIG_PACKAGE_luci-app-package-manager=y",
        "CONFIG_PACKAGE_uhttpd=y",
    ):
        req(token not in initramfs, "installer initramfs unexpectedly carries production service: " + token)
    req(
        "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_persistent_writer=y" in initramfs,
        "liveboot does not use the persistent-layout initramfs target",
    )
    req("CONFIG_TARGET_ROOTFS_INITRAMFS=y" in initramfs, "initramfs rootfs selection missing")
    req(
        "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_persistent=y" in persistent,
        "sysupgrade persistent target missing",
    )

    dts = (ROOT / "platform/cn5010_cisco_rv220w.dts").read_text()
    for token in (
        'rv220w:green:power',
        'rv220w:red:diag',
        'rv220w:green:wlan',
        'rv220w:green:dmz',
        'label = "wan"',
        'label = "lan1"',
        'label = "lan4"',
    ):
        req(token in dts, "DTS missing " + token)
    req("phy0tpt" not in dts, "DTS wrongly binds mainboard WLAN LED to b43/mac80211 trigger")

    platform_patch = (ROOT / "patches/openwrt/0001-rv220w-platform.patch").read_text()
    req("loglevel=8" not in platform_patch and "ignore_loglevel" not in platform_patch, "forced kernel debug logging remains")
    req(
        'ucidef_set_interfaces_lan_wan "lan1 lan2 lan3 lan4" "wan"' in platform_patch,
        "standard DSA board defaults missing",
    )
    req("Device/cisco_rv220w_flash_stage" not in platform_patch, "retired flash-stage image leaked into release patch")
    req("Device/cisco_rv220w\n" not in platform_patch, "retired stock-layout image leaked into release patch")

    wifi = (ROOT / "files/etc/uci-defaults/97-rv220w-wifi-production-defaults").read_text()
    led = (ROOT / "files/etc/uci-defaults/98-rv220w-wlan-led-defaults").read_text()
    for token in ("ssid=OpenWrt", "mode=ap", "band=2g", "disabled=0", "encryption=none"):
        req(token in wifi, "fresh AP default missing " + token)
    for token in ("rv220w:green:wlan", "trigger=netdev", "dev=phy0-ap0", "mode=tx", "mode=rx"):
        req(token in led, "WLAN LED default missing " + token)
    req("rv220w_pristine_openwrt_default" in wifi, "fresh OpenWrt wireless-template detector missing")
    req("preserving existing administrator wireless configuration" in wifi, "wireless sysupgrade-preservation guard missing")
    req('"$(rv220w_section_count wifi-device)" = 1' in wifi, "fresh Wi-Fi detector does not require one radio")
    req('"$(rv220w_section_count wifi-iface)" = 1' in wifi, "fresh Wi-Fi detector does not require one AP interface")
    req('[ "$disabled" = 1 ]' in wifi, "fresh Wi-Fi detector does not require disabled stock radio")
    req('[ "$ssid" = OpenWrt ]' in wifi, "fresh Wi-Fi detector does not require stock OpenWrt SSID")
    req('uci -q delete "wireless.$iface.disabled"' in wifi, "fresh Wi-Fi activation does not clear interface disable flag")
    req("existing rv220w:green:wlan policy preserved" in led, "LED sysupgrade-preservation guard missing")
    check_wifi_defaults_behavior(ROOT / "files/etc/uci-defaults/97-rv220w-wifi-production-defaults")

    runtime_files = sorted(str(p.relative_to(ROOT / "files")) for p in (ROOT / "files").rglob("*") if p.is_file())
    req(len(runtime_files) == 8, f"unexpected target-overlay size/content: {runtime_files}")
    req(not any("debug" in p.lower() or "diagnos" in p.lower() for p in runtime_files), "debug/diagnostic target helper leaked into release image")
    installer_files = sorted(str(p.relative_to(ROOT / "installer-files")) for p in (ROOT / "installer-files").rglob("*") if p.is_file())
    req(installer_files == ["usr/sbin/rv220w-install-from-ram"], f"unexpected initramfs-only overlay content: {installer_files}")
    installer = ROOT / "installer-files/usr/sbin/rv220w-install-from-ram"
    installer_text = installer.read_text()
    for token in (
        "Profile: initramfs",
        "persistent MTD root/overlay is mounted",
        "RV220W_DIRECT_INSTALL_BEGIN",
        "RV220W_DIRECT_INSTALL_PID1",
        "expected procd",
        "RV220W_DIRECT_INSTALL_VALIDATION_PASS",
        "RV220W_DIRECT_INSTALL_ROOTFS_BEGIN",
        "RV220W_DIRECT_INSTALL_ROOTFS_PASS",
        "RV220W_DIRECT_INSTALL_KERNEL_BEGIN",
        "RV220W_DIRECT_INSTALL_KERNEL_PASS",
        "RV220W_DIRECT_INSTALL_PASS",
        'rv220w_stream_write_member "$IMAGE" "$board_dir/root" rootfs',
        'rv220w_stream_write_member "$IMAGE" "$board_dir/kernel" openwrt-kernel',
        "UPGRADE_BACKUP=",
        "include /lib/upgrade",
        "reboot -f",
    ):
        req(token in installer_text, "direct initramfs installer invariant missing: " + token)
    subprocess.run(["sh", "-n", str(installer)], check=True)
    check_installer_openwrt_shell_compat(installer)
    ordering = [
        installer_text.index("RV220W_DIRECT_INSTALL_VALIDATION_PASS"),
        installer_text.index("RV220W_DIRECT_INSTALL_ROOTFS_BEGIN"),
        installer_text.index("RV220W_DIRECT_INSTALL_ROOTFS_PASS"),
        installer_text.index("RV220W_DIRECT_INSTALL_KERNEL_BEGIN"),
        installer_text.index("RV220W_DIRECT_INSTALL_KERNEL_PASS"),
        installer_text.index("RV220W_DIRECT_INSTALL_PASS"),
    ]
    req(ordering == sorted(ordering) and len(set(ordering)) == len(ordering),
        "direct installer phase ordering is not validate -> rootfs -> kernel -> PASS")

    active = sorted((ROOT / "patches").rglob("*.patch"))
    req(len(active) == 4, f"expected four logical active release patches, found {len(active)}")
    expected_patch_paths = {
        "patches/openwrt/0001-rv220w-platform.patch",
        "patches/kernel/generic/900-rv220w-ssb-sprom.patch",
        "patches/kernel/octeon/900-rv220w-octeon-platform.patch",
        "patches/mac80211/brcm/900-rv220w-b43.patch",
    }
    req({str(p.relative_to(ROOT)) for p in active} == expected_patch_paths, "active release patch groups differ from expected minimal set")
    for patch in active:
        check_patch(patch)

    script_names = {str(p.relative_to(ROOT)) for p in (ROOT / "scripts").rglob("*") if p.is_file()}
    allowed_scripts = {
        "scripts/lib/common.fish",
        "scripts/setup-host-cachyos.fish",
        "scripts/setup-distrobox.fish",
        "scripts/inner/provision-openwrt-box.sh",
        "scripts/host/wait_uboot_prompt.py",
        "scripts/host/dump_uboot_flash_uart.py",
        "scripts/host/rv220w_tftp_boot.py",
        "scripts/host/build_rv220w_persistent_images.py",
        "scripts/host/verify_rv220w_sysupgrade.py",
        "scripts/release/apply-openwrt.py",
        "scripts/release/build.fish",
        "scripts/release/build.sh",
        "scripts/release/prepare-sources.fish",
        "scripts/release/prepare-sources.sh",
        "scripts/release/verify-release.py",
        "scripts/release/uboot_patch.py",
        "scripts/release/liveboot.py",
        "scripts/release/package-source.py",
    }
    req(script_names == allowed_scripts, f"unexpected active host/debug scripts: {sorted(script_names ^ allowed_scripts)}")

    # Compile source in-memory so verification does not create __pycache__ in the release tree.
    for py in (ROOT / "scripts").rglob("*.py"):
        compile(py.read_text(), str(py), "exec")
    for sh in list((ROOT / "scripts/release").glob("*.sh")) + [ROOT / "scripts/inner/provision-openwrt-box.sh"]:
        subprocess.run(["bash", "-n", str(sh)], check=True)

    makefile = (ROOT / "Makefile").read_text()
    for target in ("all:", "u-boot-verify:", "u-boot-patches:", "initramfs-liveboot:", "prebuilt-check:", "artifacts-check:", "package:"):
        req(target in makefile, f"Makefile target missing: {target}")
    req(".NOTPARALLEL:" in makefile, "shared OpenWrt tree is not protected from parallel profile builds")

    provision = (ROOT / "scripts/inner/provision-openwrt-box.sh").read_text()
    req(not re.search(r"^[^#\n]*\|\s*head\b", provision, re.M),
        "pipefail-unsafe head pipeline remains in Distrobox provisioning")
    build_sh = (ROOT / "scripts/release/build.sh").read_text()
    req(not re.search(r"^[^#\n]*\|\s*head\b", build_sh, re.M),
        "pipefail-unsafe head pipeline remains in release build artifact selection")
    req('rsync -a "$root/installer-files/" files/' in build_sh,
        "initramfs-only installer overlay is not copied into the installer profile")
    req("rv220w-openwrt-release" in makefile, "release Makefile still reuses the historical promotion Distrobox")
    common = (ROOT / "scripts/lib/common.fish").read_text()
    req("RV220W_BOX rv220w-openwrt-release" in common, "release helper default Distrobox is not isolated")
    setup_box = (ROOT / "scripts/setup-distrobox.fish").read_text()
    req("distrobox-provision.log" in setup_box and "$pipestatus" in setup_box,
        "Distrobox setup does not preserve exact provisioning diagnostics")
    package_source = (ROOT / "scripts/release/package-source.py").read_text()
    req("SOURCE-SHA256SUMS" in package_source and "build" in package_source and "dist" in package_source,
        "source packaging does not include an internal manifest/exclusion policy")
    req('rel.as_posix() == "SOURCE-SHA256SUMS"' in package_source,
        "source packaging can duplicate/stale-chain an extracted SOURCE-SHA256SUMS")
    req('"artifacts", "backups", "build", "dist", ".git"' in package_source,
        "source packaging can include generated artifacts or device backups")

    uboot = (ROOT / "scripts/release/uboot_patch.py").read_text()
    for token in (
        "FLASH_SIZE = 0x02000000",
        "BOOT_CHAIN_SIZE = 0x00080000",
        "UBOOT_ENV_SIZE = 0x00020000",
        "EXPECTED_PATCHED_CRC = 0xB77A94DE",
        "0x13138",
        "0x13168",
        "BOOTLOADER BACKUP ONLY",
        "qualified-patched",
        "FORCE rewrite the already-qualified sector 0",
        "--verify-only",
        "proc_uart_holders",
        "exclusive=True",
        "PATCH RV220W U-BOOT",
        "saveenv",
    ):
        req(token in uboot, "U-Boot onboarding safety invariant missing: " + token)
    req("len(blob) != BOOT_CHAIN_SIZE" in uboot, "U-Boot compatibility is not scoped to boot-chain size")
    req("The rest of NOR is intentionally ignored" in uboot, "bootloader-only compatibility policy is not fail-closed/documented")
    req("full_nor_sha256" in uboot and "uboot_env_sha256" in uboot, "backup manifests do not hash both full/bootloader scopes")
    dry = subprocess.run(
        [sys.executable, str(ROOT / "scripts/release/uboot_patch.py"), "--serial", "/dev/ttyFAKE", "--backup-scope", "bootloader", "--verify-only", "--dry-run"],
        text=True, capture_output=True, check=True,
    )
    req('"verify_only": true' in dry.stdout and '"compatibility_scope"' in dry.stdout,
        "U-Boot read-only dry-run does not expose bootloader-only verification policy")
    wait_uboot = (ROOT / "scripts/host/wait_uboot_prompt.py").read_text()
    dump_uboot = (ROOT / "scripts/host/dump_uboot_flash_uart.py").read_text()
    req("exclusive=True" in wait_uboot and "exclusive=True" in dump_uboot,
        "low-level UART helpers do not request exclusive serial ownership")
    check_uboot_bootchain_behavior(ROOT / "scripts/release/uboot_patch.py")

    platform_sh = (ROOT / "platform/platform.sh").read_text()
    for token in (
        "rv220w_validate_upgrade_stream",
        "rv220w_stream_write_member",
        "mtd write -",
        "stream/readback SHA-256 verified",
        "RAMFS_COPY_BIN=\"$RAMFS_COPY_BIN /usr/bin/sha256sum\"",
    ):
        req(token in platform_sh, "low-memory sysupgrade invariant missing: " + token)
    req('rv220w_extract_upgrade "$tar_file" "$board_dir" /tmp/rv220w-sysupgrade-check' not in platform_sh,
        "platform_check_image still materializes sysupgrade components in /tmp")
    check_low_memory_sysupgrade_behavior(ROOT / "platform/platform.sh")

    liveboot = (ROOT / "scripts/release/liveboot.py").read_text()
    for token in ("192.168.240.1", "192.168.1.1", "sysupgrade -T", "INSTALL RV220W", "/usr/sbin/rv220w-install-from-ram", "run_direct_installer", "RV220W_DIRECT_INSTALL_PASS"):
        req(token in liveboot, "liveboot onboarding invariant missing: " + token)
    req("sysupgrade -n" not in liveboot, "liveboot still enters the unnecessary OpenWrt stage2 path for first install")
    req("oom-killer" in liveboot and "Out of memory: Killed process" in liveboot,
        "liveboot does not distinguish OOM from image corruption")
    req("exclusive=True" in liveboot, "liveboot post-boot UART shell does not request exclusive ownership")
    req("Persistent install UART log" in liveboot, "liveboot does not print the persistent-install UART evidence path before writing")
    for token in ("PREBUILT", "Use bundled hardware-qualified RC7 images", "--prebuilt", "--built", "Using artifacts built from source instead"):
        req(token in liveboot, "prebuilt/source artifact selection invariant missing: " + token)
    tftp_boot = (ROOT / "scripts/host/rv220w_tftp_boot.py").read_text()
    req("exclusive=True" in tftp_boot, "liveboot TFTP UART helper does not request exclusive ownership")

    req((ROOT / "history/debug-tools/host").is_dir(), "retired host debug tools were not separated under history/")
    req((ROOT / "history/debug-tools/target").is_dir(), "retired target debug tools were not separated under history/")
    req((ROOT / "history/research").is_dir(), "historical research subtree missing")
    req(any((ROOT / "history/debug-tools/host").rglob("collect-wifi.fish")), "historical Wi-Fi collector reference missing")
    req(any((ROOT / "history/debug-tools/target").rglob("ssb_nvmem_diag.c")), "historical target diagnostic reference missing")
    history_docs = ROOT.parent / "docs/history/openwrt/toolkit-v1.15.10"
    req(history_docs.is_dir() and any(history_docs.glob("RV220W-V1.15*.md")),
        "normalized v1.15 promotion documentation is missing")
    req(not (ROOT / "history/rv220w-openwrt-promotion-toolkit-v1.15.10.zip").exists(),
        "redundant nested promotion toolkit ZIP is present")

    readme = (ROOT / "README.md").read_text()
    req(readme.startswith("# Cisco RV220W OpenWrt release"), "top-level README is still promotion-toolkit documentation")
    req("make all" in readme and "make u-boot-verify" in readme and "make u-boot-patches" in readme and "make initramfs-liveboot" in readme,
        "README does not document all public Makefile onboarding entry points")
    req("192.168.1.1/24" in readme and "OpenWrt" in readme, "README does not document release defaults")
    req("release-ready / hardware-qualified RC" in readme, "README is not frozen as a release-ready RC")
    for doc in ("INSTALL.md", "RECOVERY.md", "HARDWARE-QUALIFICATION.md", "RELEASE-NOTES.md"):
        req((ROOT / "docs" / doc).is_file(), f"release documentation missing: docs/{doc}")
    qual = (ROOT / "docs/HARDWARE-QUALIFICATION.md").read_text()
    req("Rootfs direct write + readback | PASS" in qual and "Kernel-last direct write + readback | PASS" in qual,
        "hardware qualification document does not record the final direct-installer PASS")
    req("remaining end-to-end qualification" not in readme.lower(),
        "README still contains stale pre-release qualification language")

    prepare = (ROOT / "scripts/release/prepare-sources.sh").read_text()
    for token in ("source-lock.json", "checkout", "--detach", "prepared source identity differs from qualified"):
        req(token in prepare, "source preparation does not replay the qualified lock: " + token)
    lock = json.loads((ROOT / "source-lock.json").read_text())
    req(lock.get("release_version") == VERSION, "source lock release version differs from VERSION")
    req(lock.get("openwrt", {}).get("commit") == "f0a60eee2fe051741c643ea6118718aae1ef17fb",
        "source lock OpenWrt commit differs from qualified v25.12.5 commit")
    req(set(lock.get("feeds", {})) == {"luci", "packages", "routing", "telephony", "video"},
        "source lock feed set is incomplete")
    for name, identity in lock["feeds"].items():
        req(re.fullmatch(r"[0-9a-f]{40}", identity.get("commit", "")) is not None,
            f"source lock commit is invalid for feed {name}")

    image_builder = (ROOT / "scripts/host/build_rv220w_persistent_images.py").read_text()
    req("hardware-qualified in the 1.16.0-rc7 direct-install workflow" in image_builder,
        "persistent image metadata does not record completed hardware qualification")

    apply = (ROOT / "scripts/release/apply-openwrt.py").read_text()
    req("patch_dry_run" in apply and "reverse=True" in apply, "applied platform patch is not exact-verified")
    req("unmarked OpenWrt tree already contains RV220W integration" in apply,
        "source application does not fail closed on unknown pre-patched trees")
    req("reset_previous_release_tree" in apply and "RELEASE_TRACKED_PATHS" in apply,
        "source application cannot migrate a known prior RV220W release tree")
    req('git", "reset", "--hard", OPENWRT_REF' in apply and "git clean" not in apply,
        "source migration does not use the cache-preserving bounded reset policy")
    req("release-owned integration surface" in apply,
        "source migration does not refuse unrelated tracked edits")
    check_release_tree_migration()

    print(f"release_version={VERSION}")
    print("active_patch_groups=4")
    print("runtime_debug_b43=disabled")
    print("runtime_debug_tools=absent")
    print("initramfs_profile=lan-only-installer")
    print("sysupgrade_validation=low-memory-streaming")
    print("first_install_path=direct-initramfs-no-stage2")
    print("default_lan=192.168.1.1/24")
    print("default_wifi=OpenWrt 2.4GHz AP")
    print("default_wlan_led=netdev phy0-ap0 tx+rx")
    print("uboot_backup=full-32MiB-or-warning-gated-640KiB")
    print("uboot_compatibility=boot-chain-only")
    print("uart_busy_handling=fail-cleanly-before-router-interaction")
    print("direct_installer_openwrt_shell_compat=PASS")
    print("release_qualification=hardware-qualified-release-ready")
    print("historical_research=normalized-v1.15.10-history")
    print("release_static_verify=PASS")


if __name__ == "__main__":
    main()
