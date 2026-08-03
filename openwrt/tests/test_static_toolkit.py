#!/usr/bin/env python3
"""Static regression checks for shell separation, Distrobox safety, and source size."""
from __future__ import annotations

import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
HISTORY_DOCS = ROOT.parent / "docs" / "history" / "openwrt" / "toolkit-v1.10.3"


def fail(message: str) -> None:
    raise SystemExit(message)


fish_files = [
    ROOT / "rv220w.fish",
    *sorted((ROOT / "scripts").glob("*.fish")),
    *sorted((ROOT / "scripts/lib").glob("*.fish")),
]
for path in fish_files:
    text = path.read_text(encoding="utf-8")
    if "<<'" in text or '<<"' in text or "<<EOF" in text:
        fail(f"Bash heredoc found in Fish script: {path}")
    if "string join ' ' $" in text or 'string join " " $' in text:
        fail(f"string join missing -- separator in: {path}")
    if path.name != "common.fish" and 'distrobox enter "$RV220W_BOX"' in text:
        fail(f"legacy positional Distrobox invocation found in: {path}")

common = (ROOT / "scripts/lib/common.fish").read_text(encoding="utf-8")
for required in (
    'distrobox enter --name "$RV220W_BOX" --no-tty --',
    "function rv_box_is_compatible",
    "function rv_box_is_provisioned",
    "function rv_require_build_box",
):
    if required not in common:
        fail(f"missing Distrobox safety primitive: {required}")


setup_box = (ROOT / "scripts/setup-distrobox.fish").read_text(encoding="utf-8")
if "distrobox stop" in setup_box:
    fail("setup-box still contains the interactive distrobox stop path")
for required in (
    "rv_remove_box_runtime",
    "remove-only",
    "The image pull may take several minutes",
):
    if required not in setup_box:
        fail(f"setup-box lacks recreate safety behavior: {required}")

for required in (
    "function rv_box_runtime_summary",
    "function rv_remove_box_runtime",
    "timeout --foreground 30s podman rm --force --time 3 --ignore",
):
    if required not in common:
        fail(f"common helpers lack bounded container removal: {required}")

inner = ROOT / "scripts/inner"
required_helpers = {
    "provision-openwrt-box.sh",
    "prepare-sources.sh",
    "build-openwrt.sh",
    "build-linux-reference.sh",
}
present = {p.name for p in inner.glob("*.sh")}
missing = required_helpers - present
if missing:
    fail(f"missing static Bash helper(s): {sorted(missing)}")

for path in sorted(inner.glob("*.sh")):
    subprocess.run(["bash", "-n", str(path)], check=True)

provision = (inner / "provision-openwrt-box.sh").read_text(encoding="utf-8")
for required in ("/etc/os-release", "apt-get", "perl -MFindBin", "add-apt-repository -y universe", "install_reference_cross"):
    if required not in provision:
        fail(f"provisioning helper lacks validation: {required}")
if "OpenWrt builds are fully provisioned and are not affected" not in provision:
    fail("provisioning helper does not isolate the optional reference compiler")

if "command -v mips64-linux-gnuabi64-gcc" in common.split("function rv_box_is_provisioned", 1)[1].split("end", 1)[0]:
    fail("main build-box readiness still requires the optional MIPS64 compiler")
if "function rv_box_has_reference_cross" not in common:
    fail("missing optional reference-cross readiness helper")

prepare = (inner / "prepare-sources.sh").read_text(encoding="utf-8")
if "--depth 1 --single-branch --branch" not in prepare:
    fail("source helper is not using shallow single-ref clones")
if "--no-single-branch" in prepare or "--filter=blob:none" in prepare:
    fail("source helper still contains the multi-history partial-clone path")

for path in sorted((ROOT / "scripts/host").glob("*.py")):
    compile(path.read_text(encoding="utf-8"), str(path), "exec")


# RV220W v1.3.2 platform integration checks.
build_inner = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
for required in (
    "rv220w-initramfs)",
    "openwrt-rv220w-initramfs.config",
    "rv220w-openwrt-rv220w-initramfs",
    "cisco_rv220w",
):
    if required not in build_inner:
        fail(f"missing RV220W build-mode token: {required}")

prepare_inner = (ROOT / "scripts/inner/prepare-sources.sh").read_text(encoding="utf-8")
if "install-rv220w-platform.py" not in prepare_inner:
    fail("prepare-sources does not automatically install the RV220W platform")

platform_patch = ROOT / "openwrt/platform/openwrt-rv220w-platform-v1.4.0.patch"
if not platform_patch.is_file():
    fail("missing full OpenWrt RV220W platform patch")
patch_text = platform_patch.read_text(encoding="utf-8")
for required in (
    "Device/cisco_rv220w",
    "405-rv220w-guard-ubnt-pruning.patch",
    "410-cisco-rv220w-dtb-makefile.patch",
    "cn5010_cisco_rv220w.dts",
    "uart0 = &uart0;",
    "/delete-node/ compact-flash@5,0;",
):
    if required not in patch_text:
        fail(f"platform patch lacks required token: {required}")
if "400-ubnt_dts_pruning.patch b/target/linux/octeon/patches-6.12/400-ubnt_dts_pruning.patch" in patch_text:
    fail("platform patch still edits OpenWrt's nested 400-ubnt_dts_pruning.patch")

platform_installer = (ROOT / "scripts/inner/install-rv220w-platform.py").read_text(encoding="utf-8")
for required in ('VERSION = "1.4.0"', '("1.3.2", "1.4.0")', "openwrt-rv220w-platform-v1.3.2-to-v1.4.0.patch"):
    if required not in platform_installer:
        fail(f"v1.4.0 platform installer token missing: {required}")

tftp = (ROOT / "scripts/host/rv220w_tftp_boot.py").read_text(encoding="utf-8")
if "--tftp-no-blocksize" in tftp:
    fail("TFTP helper still contains the 512-byte no-blocksize failure mode")
for required in ("--tftp-mtu=544", 'setenv netretry no'):
    if required not in tftp:
        fail(f"TFTP helper missing validated fix: {required}")

for path in sorted(ROOT.rglob("*.py")):
    compile(path.read_text(encoding="utf-8"), str(path), "exec")


repacker = (ROOT / "scripts/host/repack_v132_candidate.py").read_text(encoding="utf-8")
for required in (
    "replace_growing_appended_dtb",
    "PT_LOAD file image does not end at .appended_dtb",
    "v1.3.0/v1.3.1 DTBs differ beyond the two approved changes",
    "restore exact v1.3.0 bootbus nor@0,0 enabled child",
    '"hardware_validation": "pending"',
):
    if required not in repacker:
        fail(f"v1.3.2 candidate repacker lacks safety token: {required}")
if "subprocess.run" in repacker:
    fail("candidate repacker still depends on an external command")

print("static toolkit regression checks passed")

# v1.3 regression checks from the first board-specific live boot.
dts = (ROOT / "openwrt/reference/cn5010_cisco_rv220w.dts").read_text(encoding="utf-8")
for required in ('uart0 = &uart0;', '&bootbus {', 'status = "okay";', '/delete-node/ compact-flash@5,0;'):
    if required not in dts:
        fail(f"v1.3 DTS regression token missing: {required}")
tftp_fish = (ROOT / "scripts/tftp-boot.fish").read_text(encoding="utf-8")
if 'rv220w-openwrt-rv220w-initramfs.elf' not in tftp_fish:
    fail("board-specific artifact is missing from TFTP auto-discovery")
if 'RV220W_TFTP_INTERFACE' not in tftp_fish or 'RV220W_TFTP_DEVICE_IP' not in tftp_fish:
    fail("TFTP wrapper does not consume configured direct-link defaults")
helper = (ROOT / "scripts/host/rv220w_tftp_boot.py").read_text(encoding="utf-8")
if 'no Ctrl-C will be sent until a U-Boot banner appears' not in helper:
    fail("serial helper lacks running-Linux power-cycle guard")
uci = (ROOT / "openwrt/files-base/etc/uci-defaults/99-rv220w-validation").read_text(encoding="utf-8")
if "192.168.240.2" not in uci:
    fail("RAM-validation LAN address is not deterministic")
seed = (ROOT / "config/openwrt-rv220w-initramfs.config").read_text(encoding="utf-8")
if 'CONFIG_TARGET_PREINIT_IP="192.168.240.2"' not in seed:
    fail("RV220W preinit address is not aligned with the direct-link test subnet")


# v1.3.2 repaired-baseline checks.
dts = (ROOT / "openwrt/reference/cn5010_cisco_rv220w.dts").read_text(encoding="utf-8")
for required in (
    "clock-frequency = <400000000>;",
    "nor@0,0 {",
    'nor@0,0 {\n\t\tstatus = "okay";',
    "/delete-node/ compact-flash@5,0;",
):
    if required not in dts:
        fail(f"v1.3.2 DTS regression token missing: {required}")
if "/delete-node/ nor@0,0;" in dts:
    fail("v1.3.2 DTS still deletes the legacy MTD trigger child")

platform_delta = ROOT / "openwrt/platform/openwrt-rv220w-platform-v1.3.1-to-v1.3.2.patch"
if not platform_delta.is_file() or "nor@0,0" not in platform_delta.read_text(encoding="utf-8"):
    fail("v1.3.1-to-v1.3.2 platform upgrade patch is missing or incomplete")

common = (ROOT / "scripts/lib/common.fish").read_text(encoding="utf-8")
wrapper = (ROOT / "scripts/tftp-boot.fish").read_text(encoding="utf-8")
helper = (ROOT / "scripts/host/rv220w_tftp_boot.py").read_text(encoding="utf-8")
if "RV220W_TFTP_SERVER_IP" not in common or "192.168.240.1" not in common:
    fail("deterministic TFTP server default is missing from common.fish")
if "RV220W_TFTP_SERVER_IP" not in wrapper:
    fail("TFTP wrapper does not consume the deterministic server address")
for required in (
    "server IP and device IP must differ",
    "UnsafeBootState",
    "Data loaded outside of the reserved load area",
    "Do not flush or replace unrelated host addresses",
):
    if required not in helper:
        fail(f"v1.3.1 TFTP safety regression token missing: {required}")
if "Image file not found:" not in wrapper:
    fail("positional image failures do not report the requested pathname")

# v1.4.0 read-only discovery profile checks.
if (ROOT / "VERSION").read_text(encoding="utf-8").strip() != "1.10.3":
    fail("toolkit VERSION is not 1.10.3")

discovery_seed = ROOT / "config/openwrt-rv220w-discovery-initramfs.config"
if not discovery_seed.is_file():
    fail("missing discovery initramfs seed")
discovery_text = discovery_seed.read_text(encoding="utf-8")
for required in (
    "CONFIG_PACKAGE_ip-full=y",
    "CONFIG_PACKAGE_ip-bridge=y",
    "CONFIG_PACKAGE_ethtool-full=y",
    "CONFIG_PACKAGE_tcpdump-mini=y",
    "CONFIG_PACKAGE_kmod-dsa-b53=y",
    "CONFIG_PACKAGE_kmod-dsa-b53-mdio=y",
    "CONFIG_PACKAGE_kmod-mdio-netlink=y",
    "CONFIG_PACKAGE_mdio-tools=y",
):
    if required not in discovery_text:
        fail(f"discovery seed lacks package: {required}")

build_inner = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
for required in (
    "rv220w-discovery-initramfs)",
    "openwrt-rv220w-discovery-initramfs.config",
    "verify_discovery_config",
    "rv220w-openwrt-rv220w-discovery-initramfs",
):
    if required not in build_inner:
        fail(f"discovery build path lacks token: {required}")

snapshot = ROOT / "openwrt/files-discovery/usr/sbin/rv220w-discovery-snapshot"
if not snapshot.is_file():
    fail("missing installed discovery snapshot script")
snapshot_text = snapshot.read_text(encoding="utf-8")
for forbidden in ("flash_erase", "mtd write", "saveenv", "mdio write"):
    if forbidden in snapshot_text:
        fail(f"discovery snapshot contains forbidden write token: {forbidden}")
for required in ("ip -s -d link show", "bridge -d fdb show", "ethtool -S", "cat /proc/mtd", "policy=read-only"):
    if required not in snapshot_text:
        fail(f"discovery snapshot lacks evidence token: {required}")
subprocess.run(["bash", "-n", str(snapshot)], check=True)

collector = (ROOT / "scripts/collect-snapshot.fish").read_text(encoding="utf-8")
for required in ("rv220w-discovery-snapshot", "logs/discovery", "Unexpected target output path"):
    if required not in collector:
        fail(f"host snapshot collector lacks token: {required}")

entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
if "case collect-snapshot" not in entry:
    fail("toolkit entry point lacks collect-snapshot action")

tftp_fish = (ROOT / "scripts/tftp-boot.fish").read_text(encoding="utf-8")
for required in ("P/profile=", "case discovery", "rv220w-openwrt-rv220w-discovery-initramfs.elf"):
    if required not in tftp_fish:
        fail(f"TFTP discovery profile support lacks token: {required}")

for required in ("UserKnownHostsFile=/dev/null", "StrictHostKeyChecking=no", "streaming the packaged read-only script", "cat '$remote_output'"):
    if required not in collector:
        fail(f"v1.4.1 collector transport fix missing token: {required}")
if "rv_require ssh scp" in collector or 'scp "' in collector:
    fail("collector still depends on scp/SFTP")
if "case version" not in entry or "scripts/version.fish" not in entry:
    fail("toolkit entry point lacks explicit version reporting")
version_helper = ROOT / "scripts/version.fish"
if not version_helper.is_file() or "Platform and toolkit versions are intentionally independent" not in version_helper.read_text(encoding="utf-8"):
    fail("version helper does not explain independent version streams")
build_outer = (ROOT / 'scripts/build-openwrt.fish').read_text(encoding='utf-8')
if 'test \"$mode\" = discovery' not in build_outer:
    fail("discovery build alias is missing")
if "resolved_seen" not in common or "Multiple physical serial adapters" not in common:
    fail("serial alias deduplication is missing")

print("v1.4.1 discovery hotfix checks passed")


# v1.5.0 direct read-only MDIO identity stage checks.
if (ROOT / "VERSION").read_text(encoding="utf-8").strip() != "1.10.3":
    fail("toolkit VERSION is not 1.10.3")

mdio_scan = ROOT / "openwrt/files-discovery/usr/sbin/rv220w-mdio-scan"
if not mdio_scan.is_file():
    fail("missing read-only MDIO scan script")
mdio_scan_text = mdio_scan.read_text(encoding="utf-8")
for required in (
    "policy=read-only direct Clause 22 reads",
    'mdio "$bus"',
    'mdio "$bus" phy "$addr" raw 0',
    'mdio "$bus" phy "$addr" raw 1',
    'mdio "$bus" phy "$addr" raw 2',
    'mdio "$bus" phy "$addr" raw 3',
    "reg01_bmsr_second",
):
    if required not in mdio_scan_text:
        fail(f"MDIO scan lacks token: {required}")
for forbidden in (
    "mdio write",
    "saveenv",
    "flash_erase",
    "mtd write",
    "modprobe dsa",
):
    if forbidden in mdio_scan_text:
        fail(f"MDIO scan contains forbidden token: {forbidden}")
for line in mdio_scan_text.splitlines():
    stripped = line.strip()
    if stripped.startswith('mdio "$bus" phy "$addr" raw '):
        command_part = stripped.split("2>&1", 1)[0].strip()
        if len(command_part.split()) != 6:
            fail(f"MDIO scan read line appears to supply a write value: {stripped}")
subprocess.run(["bash", "-n", str(mdio_scan)], check=True)

mdio_collector = ROOT / "scripts/collect-mdio.fish"
if not mdio_collector.is_file():
    fail("missing host MDIO collector")
collector_text = mdio_collector.read_text(encoding="utf-8")
for required in (
    "RV220W_MDIO_BUS",
    "rv220w-mdio-scan",
    "logs/discovery/mdio",
    "Unexpected target output path",
    "UserKnownHostsFile=/dev/null",
):
    if required not in collector_text:
        fail(f"host MDIO collector lacks token: {required}")

entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
if "case collect-mdio" not in entry:
    fail("toolkit entry point lacks collect-mdio action")

common = (ROOT / "scripts/lib/common.fish").read_text(encoding="utf-8")
if "RV220W_MDIO_BUS" not in common or "8001180000001800" not in common:
    fail("default Octeon MDIO bus is missing")

build_inner = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
if "read-only discovery profile v1.8.0" not in build_inner:
    fail("discovery image version was not advanced to v1.5.0")

print("v1.5.0 MDIO identity-stage checks passed")


# v1.5.2 robust UART framing checks.
uart_helper = ROOT / "scripts/host/rv220w_uart_collect_mdio.py"
if not uart_helper.is_file():
    fail("missing UART MDIO host helper")
uart_text = uart_helper.read_text(encoding="utf-8")
for required in (
    "stty -echo",
    "octal_escape",
    "printf '%b'",
    "wc -c",
    "/bin/sh -n",
    "sha256sum",
    "__RV220W_BEGIN_",
    "exclusive=True",
    "RV220W MDIO identity/status scan",
):
    if required not in uart_text:
        fail(f"UART MDIO helper lacks token: {required}")
subprocess.run([sys.executable, "-m", "py_compile", str(uart_helper)], check=True)
subprocess.run([sys.executable, str(ROOT / "tests/test_uart_framing.py")], check=True)

collector_text = (ROOT / "scripts/collect-mdio.fish").read_text(encoding="utf-8")
for required in (
    "UART is the default",
    "rv220w_uart_collect_mdio.py",
    "RV220W_CONSOLE_BAUD",
    "S/ssh",
    "--force-upload",
):
    if required not in collector_text:
        fail(f"UART-first MDIO collector lacks token: {required}")
if "if not set -q _flag_ssh" not in collector_text:
    fail("MDIO collector does not default to UART")

common = (ROOT / "scripts/lib/common.fish").read_text(encoding="utf-8")
if "RV220W_CONSOLE_BAUD" not in common or "115200" not in common:
    fail("Linux console UART default is missing")

if "read-only discovery profile v1.8.0" not in build_inner:
    fail("future discovery rebuilds do not identify v1.8.0")

for required in (
    "read_until_line",
    "marker in self._normalized_lines",
    "tokens embedded in",
    "re.fullmatch",
):
    if required not in uart_text:
        fail(f"v1.5.2 UART framing fix lacks token: {required}")
if "self.read_until(end.encode" in uart_text or "if marker in data" in uart_text:
    fail("UART helper still accepts sentinel substrings from echoed commands")

print("v1.5.2 robust UART framing checks passed")


# v1.6.0 selector-safe passive B53 topology stage checks.
if (ROOT / "VERSION").read_text(encoding="utf-8").strip() != "1.10.3":
    fail("toolkit VERSION is not 1.10.3")

b53_scan = ROOT / "openwrt/files-discovery/usr/sbin/rv220w-b53-snapshot"
if not b53_scan.is_file():
    fail("missing passive B53 topology snapshot script")
b53_text = b53_scan.read_text(encoding="utf-8")
for required in (
    "RV220W passive B53 topology snapshot",
    "selector-only pseudo-PHY writes",
    "selector_write",
    "16|17",
    "B53 topology",
    "device_id",
    "link_status_summary",
    "port_vlan_mask",
    "gmii_override",
    "rgmii_control",
    "restore_selectors",
):
    if required not in b53_text:
        fail(f"B53 snapshot lacks token: {required}")
for forbidden in (
    "flash_erase",
    "saveenv",
    "modprobe dsa",
    "VTA_CMD_WRITE",
    "ARLTBL_START_DONE",
    "GC_RESET_MIB",
    "SW_RST",
):
    if forbidden in b53_text:
        fail(f"B53 snapshot contains forbidden token: {forbidden}")

write_forms = []
for line in b53_text.splitlines():
    stripped = line.strip()
    if stripped.startswith('mdio "$bus" phy "$pseudo_phy" raw '):
        if '"$selector_reg" "$selector_value"' in stripped:
            write_forms.append('selector_write')
        elif 'raw "$1"' in stripped:
            pass
        else:
            fail(f"unexpected B53 MDIO command form: {stripped}")
if write_forms != ['selector_write']:
    fail(f"B53 snapshot has unapproved MDIO write form(s): {write_forms}")
subprocess.run(["bash", "-n", str(b53_scan)], check=True)

b53_collector = ROOT / "scripts/collect-b53.fish"
if not b53_collector.is_file():
    fail("missing UART B53 collector")
b53_collector_text = b53_collector.read_text(encoding="utf-8")
for required in (
    "rv220w_uart_collect_b53.py",
    "logs/discovery/b53",
    "RV220W_CONSOLE_BAUD",
    "--force-upload",
    "Collecting passive B53 topology snapshot over UART",
):
    if required not in b53_collector_text:
        fail(f"B53 collector lacks token: {required}")
if "ssh" in b53_collector_text.lower():
    fail("B53 collector must not depend on SSH")

b53_uart = ROOT / "scripts/host/rv220w_uart_collect_b53.py"
if not b53_uart.is_file():
    fail("missing B53 UART host helper")
b53_uart_text = b53_uart.read_text(encoding="utf-8")
for required in (
    "stty -echo",
    "read_until_line",
    "tokens embedded in",
    "rv220w-b53-snapshot",
    "RV220W passive B53 topology snapshot",
    "exclusive=True",
    "octal_escape",
    "printf '%b'",
    "wc -c",
    "/bin/sh -n",
):
    if required not in b53_uart_text:
        fail(f"B53 UART helper lacks token: {required}")
subprocess.run([sys.executable, "-m", "py_compile", str(b53_uart)], check=True)
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_uart_framing.py")], check=True)
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_selector_safety.py")], check=True)

entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
if "case collect-b53" not in entry or "scripts/collect-b53.fish" not in entry:
    fail("toolkit entry point lacks collect-b53 action")
if "read-only discovery profile v1.8.0" not in build_inner:
    fail("future discovery rebuilds do not identify v1.8.0")

stage_doc = HISTORY_DOCS / "RV220W-V1.6.0-PASSIVE-B53-STAGE.md"
if not stage_doc.is_file():
    fail("missing v1.6.0 passive B53 stage documentation")

print("v1.6.0 passive B53 topology-stage checks passed")


# v1.6.1 decoder-free UART upload checks.
for helper_text, helper_name in ((uart_text, "MDIO"), (b53_uart_text, "B53")):
    for forbidden in ("import base64", "base64 -d", "command -v base64"):
        if forbidden in helper_text:
            fail(f"{helper_name} UART helper still depends on target base64: {forbidden}")
    for required in ("octal_escape", "printf '%b'", "size=(\\d+)", "/bin/sh -n"):
        if required not in helper_text:
            fail(f"{helper_name} UART helper lacks decoder-free upload token: {required}")
hotfix_doc = HISTORY_DOCS / "RV220W-V1.6.1-UART-OCTAL-UPLOAD-HOTFIX.md"
if not hotfix_doc.is_file():
    fail("missing v1.6.1 UART octal-upload hotfix documentation")
print("v1.6.1 decoder-free UART upload checks passed")


# v1.6.2 bounded/paced UART upload checks.
for helper_text, helper_name in ((uart_text, "MDIO"), (b53_uart_text, "B53")):
    for required in (
        "UPLOAD_CHUNK_BYTES",
        "UPLOAD_MAX_COMMAND_BYTES",
        "write_paced",
        "run_upload_append",
        "read_until_status_line",
        "short acknowledgement wrapper",
    ):
        if required not in helper_text:
            fail(f"{helper_name} UART helper lacks v1.6.2 token: {required}")
    if "chunk_size = 128" in helper_text:
        fail(f"{helper_name} UART helper retains oversized v1.6.1 chunks")
subprocess.run([sys.executable, str(ROOT / "tests/test_uart_octal_upload.py")], check=True)
hotfix_doc = HISTORY_DOCS / "RV220W-V1.6.2-UART-SHORT-COMMAND-HOTFIX.md"
if not hotfix_doc.is_file():
    fail("missing v1.6.2 bounded UART-command hotfix documentation")
print("v1.6.2 bounded UART upload checks passed")


# v1.7.0 LAN-only DSA ownership-stage checks.
dsa_template = ROOT / "openwrt/dsa-lan/cn5010_cisco_rv220w-dsa-lan.dts.in"
if not dsa_template.is_file():
    fail("missing LAN DSA DTS template")
dsa_text = dsa_template.read_text(encoding="utf-8")
for token in ['compatible = "brcm,bcm53115"', 'port@1', 'port@2', 'port@3', 'port@4', 'port@8', 'ethernet = <&rv220w_eth0>', '@PHY_MODE@']:
    if token not in dsa_text:
        fail(f"LAN DSA DTS missing token: {token}")
for forbidden in ['port@0', 'port@5', 'ethernet = <&rv220w_eth1>', 'status = "okay";\n\t\tethernet@1']:
    if forbidden in dsa_text:
        fail(f"LAN DSA DTS unexpectedly contains excluded topology: {forbidden}")
if 'ethernet@1 { status = "disabled"; }' not in dsa_text or 'ethernet@2 { status = "disabled"; }' not in dsa_text:
    fail("LAN DSA DTS does not disable eth1/eth2")
build_text = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
for token in ['rv220w-dsa-lan-rxid', 'rv220w-dsa-lan-txid', 'rv220w-dsa-lan-rgmii', 'trap cleanup_dsa_source', 'cp "$backup" "$source_dts"', 'run_make_noninteractive target/linux/clean', 'source_sha=$(sha256sum', 'sha256sum -c -']:
    if token not in build_text:
        fail(f"DSA build helper missing safety token: {token}")
for path in [
    ROOT / "openwrt/files-dsa-lan/usr/sbin/rv220w-dsa-snapshot",
    ROOT / "scripts/collect-dsa.fish",
    ROOT / "scripts/host/rv220w_uart_collect_dsa.py",
    HISTORY_DOCS / "RV220W-STAGE5-B53-TOPOLOGY.md",
    HISTORY_DOCS / "RV220W-V1.7.0-LAN-DSA-VALIDATION.md",
]:
    if not path.is_file():
        fail(f"missing v1.7.0 file: {path.relative_to(ROOT)}")
entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
if 'case collect-dsa' not in entry:
    fail("toolkit entry point lacks collect-dsa")
subprocess.run([sys.executable, str(ROOT / 'tests/test_dsa_uart_framing.py')], check=True)
print("v1.7.0 LAN-only DSA ownership-stage checks passed")

# v1.7.1 Broadcom tag-driver autoload hotfix checks.
tag_autoload = ROOT / "openwrt/files-dsa-lan/etc/modules.d/30-tag-brcm"
if not tag_autoload.is_file():
    fail("missing explicit tag_brcm autoload file")
autoload_lines = [
    line.strip()
    for line in tag_autoload.read_text(encoding="utf-8").splitlines()
    if line.strip() and not line.lstrip().startswith("#")
]
if autoload_lines != ["tag_brcm"]:
    fail(f"unexpected tag-driver autoload contents: {autoload_lines}")
dsa_snapshot_text = (ROOT / "openwrt/files-dsa-lan/usr/sbin/rv220w-dsa-snapshot").read_text(encoding="utf-8")
for token in ("tag-driver availability", "tag_brcm.ko", "/etc/modules.d/*"):
    if token not in dsa_snapshot_text:
        fail(f"DSA snapshot lacks v1.7.1 diagnostic token: {token}")
hotfix_doc = HISTORY_DOCS / "RV220W-V1.7.1-BRCM-TAG-AUTOLOAD-HOTFIX.md"
if not hotfix_doc.is_file():
    fail("missing v1.7.1 Broadcom tag autoload documentation")
print("v1.7.1 Broadcom tag-driver autoload checks passed")


# v1.7.2/v1.7.3 Octeon DSA master-node and network-cleanup checks.
master_patch = ROOT / "openwrt/dsa-lan/995-rv220w-octeon-dsa-master-node.patch"
if not master_patch.is_file():
    fail("missing corrected Octeon DSA master-node patch")
master_patch_text = master_patch.read_text(encoding="utf-8")
for token in (
    "dev->dev.of_node = priv->of_node",
    "drivers/staging/octeon/ethernet.c",
    "add any B53-",
):
    if token not in master_patch_text:
        fail(f"v1.7.3 kernel patch lacks token: {token}")
for forbidden in ("drivers/net/dsa/b53", "dsa_register_switch failed"):
    if forbidden in master_patch_text:
        fail(f"v1.7.3 kernel patch improperly modifies B53: {forbidden}")
build_text = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
for token in (
    'build_dsa_lan() (',
    'kernel_patch_sources=(',
    '996-octeon-dsa-conduit-length-error.patch',
    'cmp -s "${kernel_patch_sources[$patch_index]}" "${kernel_patch_targets[$patch_index]}"',
    'Re-run the v1.10.3 updater',
    'local backup= source_sha= restore_rc=0',
):
    if token not in build_text:
        fail(f"v1.7.3 build helper lacks token: {token}")
for forbidden in ("patch_preexisting", 'cp "$kernel_patch_source" "$kernel_patch_target"'):
    if forbidden in build_text:
        fail(f"v1.7.3 still injects a temporary kernel patch: {forbidden}")

trap_pos = build_text.find('trap cleanup_dsa_source EXIT INT TERM')
cmp_pos = build_text.find('cmp -s "${kernel_patch_sources[$patch_index]}" "${kernel_patch_targets[$patch_index]}"')
backup_pos = build_text.find('backup=$(mktemp)')
if not (0 <= cmp_pos < backup_pos < trap_pos):
    fail("v1.7.3 arms DTS cleanup before patch preflight/backup")
network_defaults = (ROOT / "openwrt/files-dsa-lan/etc/uci-defaults/98-rv220w-dsa-lan-network").read_text(encoding="utf-8")
for token in ("delete network.wan6", "@device", "name='br-lan'", "lan1", "lan4"):
    if token not in network_defaults:
        fail(f"DSA network cleanup lacks token: {token}")
snapshot_text = (ROOT / "openwrt/files-dsa-lan/usr/sbin/rv220w-dsa-snapshot").read_text(encoding="utf-8")
for token in ("netdev_of_node=", "parent_of_node="):
    if token not in snapshot_text:
        fail(f"DSA snapshot lacks OF-node diagnostic: {token}")
subprocess.run([sys.executable, str(ROOT / "tests/test_dsa_kernel_patch.py")], check=True)
hotfix_doc = HISTORY_DOCS / "RV220W-V1.7.3-OCTEON-KERNEL-PATCH-CORRECTION.md"
if not hotfix_doc.is_file():
    fail("missing v1.7.3 kernel-patch correction documentation")
print("v1.7.3 Octeon kernel-patch correction checks passed")


# v1.7.4 updater/source-DTS recovery checks.
repair_helper = ROOT / "scripts/inner/repair-rv220w-source-dts.py"
if not repair_helper.is_file():
    fail("missing v1.7.4 source-DTS repair helper")
repair_text = repair_helper.read_text(encoding="utf-8")
for token in (
    "is_generated_lan_candidate",
    "is_generated_dual_candidate",
    "is_platform_compatible",
    "refusing to overwrite an unrecognized RV220W source DTS",
    "os.replace",
):
    if token not in repair_text:
        fail(f"v1.7.4 DTS repair helper lacks token: {token}")
platform_installer = (ROOT / "scripts/inner/install-rv220w-platform.py").read_text(encoding="utf-8")
if "required platform token 'model =" in platform_installer:
    fail("platform verification still uses the brittle literal model-token error")
for token in ("re.MULTILINE", "DTS model is not the canonical Cisco RV220W platform model"):
    if token not in platform_installer:
        fail(f"v1.7.4 platform verifier lacks structural model check: {token}")
subprocess.run([sys.executable, str(ROOT / "tests/test_source_dts_repair.py")], check=True)
hotfix_doc = HISTORY_DOCS / "RV220W-V1.7.4-UPDATER-DTS-RECOVERY-HOTFIX.md"
if not hotfix_doc.is_file():
    fail("missing v1.7.4 updater/DTS recovery documentation")
print("v1.7.4 updater and stale-DTS recovery checks passed")

# v1.7.5 noninteractive build guard checks.
build_text = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
for token in (
    "run_make_noninteractive()",
    "setsid --fork --wait make",
    "KCONFIG_NONINTERACTIVE=1",
    "TERM=dumb",
    "</dev/null",
    "world V=s",
    "RV220W_ALLOW_MENUCONFIG",
    "mode=$mode target=world noninteractive=setsid",
):
    if token not in build_text:
        fail(f"v1.7.5 noninteractive build guard lacks token: {token}")
for forbidden in (
    'make -j"$jobs" "${verbosity[@]}"',
    'make -j1 V=s 2>&1',
    'make defconfig',
):
    if forbidden in build_text:
        fail(f"unguarded automated make invocation remains: {forbidden}")
outer_text = (ROOT / "scripts/build-openwrt.fish").read_text(encoding="utf-8")
for token in (
    'RV220W_ALLOW_MENUCONFIG="$allow_menuconfig"',
    "Noninteractive guard: detached session",
):
    if token not in outer_text:
        fail(f"v1.7.5 outer build wrapper lacks token: {token}")
common_text = (ROOT / "scripts/lib/common.fish").read_text(encoding="utf-8")
if "file setsid" not in common_text:
    fail("build-box readiness does not require setsid")
provision_text = (ROOT / "scripts/inner/provision-openwrt-box.sh").read_text(encoding="utf-8")
if "ccache util-linux" not in provision_text:
    fail("build-box provisioning does not install util-linux")
if not (HISTORY_DOCS / "RV220W-V1.7.5-NONINTERACTIVE-BUILD-GUARD.md").is_file():
    fail("missing v1.7.5 noninteractive build documentation")
subprocess.run([sys.executable, str(ROOT / "tests/test_noninteractive_make_guard.py")], check=True)
print("v1.7.5 noninteractive build guard checks passed")

# v1.7.6 Octeon DSA tagged-RX compatibility checks.
rx_patch = ROOT / "openwrt/dsa-lan/996-octeon-dsa-conduit-length-error.patch"
if not rx_patch.is_file():
    fail("missing v1.7.6 Octeon DSA receive patch")
rx_patch_text = rx_patch.read_text(encoding="utf-8")
for token in (
    "drivers/staging/octeon/ethernet-rx.c",
    "#include <net/dsa.h>",
    "work->word1.len <= 64",
    "netdev_uses_dsa(cvm_oct_device[port])",
    "generic Octeon/DSA conduit compatibility",
):
    if token not in rx_patch_text:
        fail(f"v1.7.6 RX patch lacks token: {token}")
for forbidden in ("drivers/net/dsa/b53", "brcm,bcm53115", "Cisco RV220W", "target/linux/generic"):
    if forbidden in rx_patch_text:
        fail(f"v1.7.6 RX patch contains a forbidden lower-layer special case: {forbidden}")
for token in (
    "996-octeon-dsa-conduit-length-error.patch",
    "kernel_patch_sources=(",
    "kernel_patch_targets=(",
    "Installed DSA kernel patch differs from toolkit v1.10.3",
):
    if token not in build_text:
        fail(f"v1.7.6 build preflight lacks token: {token}")
if not (HISTORY_DOCS / "RV220W-V1.7.6-OCTEON-DSA-RX-LENGTH-HOTFIX.md").is_file():
    fail("missing v1.7.6 Octeon DSA RX documentation")
subprocess.run([sys.executable, str(ROOT / "tests/test_dsa_kernel_patch.py")], check=True)
print("v1.7.6 Octeon DSA tagged-RX compatibility checks passed")



# v1.8.0 dual-conduit DSA/WAN stage checks.
if (ROOT / "VERSION").read_text(encoding="utf-8").strip() != "1.10.3":
    fail("toolkit VERSION is not 1.10.3")
for path in (
    ROOT / "config/openwrt-rv220w-dsa-dual-initramfs.config",
    ROOT / "openwrt/dsa-dual/cn5010_cisco_rv220w-dsa-dual.dts.in",
    ROOT / "openwrt/dsa-dual/997-b53-multi-conduit-affinity.patch",
    ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-dsa-affinity",
    ROOT / "openwrt/files-dsa-dual/etc/init.d/rv220w-dsa-affinity",
    ROOT / "openwrt/files-dsa-dual/etc/hotplug.d/net/20-rv220w-dsa-affinity",
    ROOT / "openwrt/files-dsa-dual/etc/uci-defaults/98-rv220w-dsa-dual-network",
    HISTORY_DOCS / "RV220W-STAGE6-LAN-DSA-HARDWARE-VALIDATION.md",
    HISTORY_DOCS / "RV220W-V1.8.0-DUAL-CONDUIT-WAN-VALIDATION.md",
):
    if not path.is_file():
        fail(f"missing v1.8.0 file: {path.relative_to(ROOT)}")
for token in (
    "build_dsa_dual() (",
    "rv220w-dsa-dual-rxid",
    "rv220w-dsa-dual-wan-txid",
    "rv220w-dsa-dual-wan-rgmii",
    "sync_dsa_dual_files",
    "openwrt-rv220w-dsa-dual-initramfs.config",
    "997-b53-multi-conduit-affinity.patch",
):
    if token not in build_text:
        fail(f"v1.8.0 build helper lacks token: {token}")
outer_build = (ROOT / "scripts/build-openwrt.fish").read_text(encoding="utf-8")
if "dsa-dual" not in outer_build or "rv220w-dsa-dual-rxid" not in outer_build:
    fail("v1.8.0 outer build wrapper lacks dsa-dual alias")
tftp_text = (ROOT / "scripts/tftp-boot.fish").read_text(encoding="utf-8")
for token in ("dsa-dual", "rv220w-openwrt-rv220w-dsa-dual-rxid.elf", "192.168.241.2"):
    if token not in tftp_text:
        fail(f"v1.8.0 TFTP wrapper lacks token: {token}")
collect_text = (ROOT / "scripts/collect-dsa.fish").read_text(encoding="utf-8")
if "logs/dsa" not in collect_text or "files-dsa-dual" not in collect_text:
    fail("DSA collector was not generalized for the dual profile")
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_multi_conduit_patch.py")], check=True)
subprocess.run([sys.executable, str(ROOT / "tests/test_dsa_dual_profile.py")], check=True)
subprocess.run([sys.executable, str(ROOT / "tests/test_source_dts_repair.py")], check=True)
print("v1.8.0 dual-conduit DSA/WAN stage checks passed")


# v1.8.1 pre-defconfig menuconfig-race hotfix checks.
build_text = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")
for token in (
    'build_lock="$workspace/.rv220w-openwrt-build.lock"',
    'flock -n 9',
    'MAKEFLAGS=',
    'MFLAGS=',
    'refusing interactive OpenWrt target in automated build',
    'CONFIG_HAVE_DOT_CONFIG=y',
    'require_expanded_config',
    'maybe_full_clean',
    'if config_is_expanded; then',
):
    if token not in build_text:
        fail(f"v1.8.1 build hotfix lacks token: {token}")
if 'if [[ ${RV220W_CLEAN:-0} == 1 && "$mode" != clean ]]; then' in build_text:
    fail("global pre-defconfig clean remains")
common_text = (ROOT / "scripts/lib/common.fish").read_text(encoding="utf-8")
if "file setsid flock" not in common_text:
    fail("build-box readiness does not require both setsid and flock")
if not (HISTORY_DOCS / "RV220W-V1.8.1-PRE-DEFCONFIG-MENUCONFIG-RACE-HOTFIX.md").is_file():
    fail("missing v1.8.1 build-race hotfix documentation")
subprocess.run([sys.executable, str(ROOT / "tests/test_build_config_order.py")], check=True)
print("v1.8.1 pre-defconfig menuconfig-race hotfix checks passed")


# v1.8.2 BCM53115 conduit-register diagnostic checks.
for path in (
    ROOT / "scripts/collect-conduit.fish",
    ROOT / "scripts/compare-b53.fish",
    ROOT / "scripts/host/compare_rv220w_b53_snapshots.py",
    ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-snapshot",
    HISTORY_DOCS / "RV220W-V1.8.2-B53-CONDUIT-REGISTER-DIAGNOSTICS.md",
):
    if not path.is_file():
        fail(f"missing v1.8.2 diagnostic file: {path.relative_to(ROOT)}")
entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
for token in ("case collect-conduit", "scripts/collect-conduit.fish", "case compare-b53", "scripts/compare-b53.fish"):
    if token not in entry:
        fail(f"v1.8.2 entry point lacks token: {token}")
scanner = (ROOT / "openwrt/files-discovery/usr/sbin/rv220w-b53-snapshot").read_text(encoding="utf-8")
for token in ("DSA_CONDUIT_REGISTER_CHECK", "port0_port_vlan_mask", "expected_cpu_has_port0", "conduit_register_check"):
    if token not in scanner:
        fail(f"v1.8.2 B53 scanner lacks token: {token}")
if scanner != (ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-snapshot").read_text(encoding="utf-8"):
    fail("dual-image and UART fallback B53 scanners differ")
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_conduit_compare.py")], check=True)
print("v1.8.2 BCM53115 conduit-register diagnostic checks passed")


# v1.8.3 BCM53115 standalone EAP-mode validation checks.
for path in (
    ROOT / "scripts/b53-eap.fish",
    ROOT / "scripts/host/rv220w_uart_b53_eap.py",
    ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-eap-mode",
    HISTORY_DOCS / "RV220W-V1.8.3-EAP-MODE-VALIDATION.md",
):
    if not path.is_file():
        fail(f"missing v1.8.3 EAP validation file: {path.relative_to(ROOT)}")
entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
for token in ("case b53-eap", "scripts/b53-eap.fish"):
    if token not in entry:
        fail(f"v1.8.3 entry point lacks token: {token}")
eap_helper = (ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-eap-mode").read_text(encoding="utf-8")
for token in (
    "writes are restricted to one 64-bit EAP configuration entry",
    "d3 & ~0x18",
    "d3 | 0x18",
    "write actions are restricted to external user ports 0..4",
    "saved_original=",
    "restore_selectors",
):
    if token not in eap_helper:
        fail(f"v1.8.3 EAP helper lacks token: {token}")
for forbidden in ("saveenv", "flash_erase", "mtd write", "erase "):
    if forbidden in eap_helper.lower():
        fail(f"v1.8.3 EAP helper contains forbidden token: {forbidden}")
scanner = (ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-snapshot").read_text(encoding="utf-8")
for token in ("eap_config_raw", "eap_mode_code", "eap_mode", "frame_management_mode"):
    if token not in scanner:
        fail(f"v1.8.3 scanner lacks token: {token}")
if scanner != (ROOT / "openwrt/files-discovery/usr/sbin/rv220w-b53-snapshot").read_text(encoding="utf-8"):
    fail("v1.8.3 discovery and dual B53 scanners differ")
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_eap_mode.py")], check=True)
print("v1.8.3 BCM53115 standalone EAP-mode validation checks passed")

# v1.8.4 BCM53115 VLAN/PVID validation checks.
for path in (
    ROOT / "scripts/b53-vlan.fish",
    ROOT / "scripts/host/rv220w_uart_b53_vlan.py",
    ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-vlan-state",
    HISTORY_DOCS / "RV220W-V1.8.4-VLAN-PVID-VALIDATION.md",
):
    if not path.is_file():
        fail(f"missing v1.8.4 VLAN/PVID validation file: {path.relative_to(ROOT)}")
entry = (ROOT / "rv220w.fish").read_text(encoding="utf-8")
for token in ("case b53-vlan", "scripts/b53-vlan.fish"):
    if token not in entry:
        fail(f"v1.8.4 entry point lacks token: {token}")
vlan_helper = (ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-b53-vlan-state").read_text(encoding="utf-8")
for token in (
    "writes are restricted to default VLAN tags for ports 0/5 and VLAN-table",
    "set-p5-pvid0",
    "set-domain-vlan0",
    "set-domain-vlan1",
    "VLAN-table entries 0/1",
    "require live wan@eth1",
    "saved_original=",
    "restore_selectors",
):
    if token not in vlan_helper:
        fail(f"v1.8.4 VLAN helper lacks token: {token}")
for forbidden in ("saveenv", "flash_erase", "mtd write", "erase "):
    if forbidden in vlan_helper.lower():
        fail(f"v1.8.4 VLAN helper contains forbidden token: {forbidden}")
if vlan_helper != (ROOT / "openwrt/files-discovery/usr/sbin/rv220w-b53-vlan-state").read_text(encoding="utf-8"):
    fail("v1.8.4 discovery and dual VLAN helpers differ")
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_vlan_state.py")], check=True)
print("v1.8.4 BCM53115 VLAN/PVID validation checks passed")

# v1.9.0 first full-RJ45 candidate checks.
if (ROOT / "VERSION").read_text(encoding="utf-8").strip() != "1.10.3":
    fail("toolkit VERSION is not 1.10.3")
for path in (
    ROOT / "openwrt/dsa-dual/998-b53-enable-dt-cpu-ports.patch",
    ROOT / "config/openwrt-rv220w-rj45-initramfs.config",
    ROOT / "openwrt/files-rj45-full/etc/uci-defaults/98-rv220w-rj45-network",
    ROOT / "openwrt/files-rj45-full/etc/uci-defaults/99-rv220w-rj45-services",
    ROOT / "openwrt/files-rj45-full/usr/sbin/rv220w-rj45-status",
    HISTORY_DOCS / "RV220W-RUN9-VLAN-PVID-PROOF.md",
    HISTORY_DOCS / "RV220W-V1.9.0-FULL-RJ45-CANDIDATE.md",
    ROOT / "evidence/run9-vlan-pvid/README.md",
):
    if not path.is_file():
        fail(f"missing v1.9.0 file: {path.relative_to(ROOT)}")
for token in (
    "sync_rj45_full_files",
    "verify_rj45_full_config",
    "998-b53-enable-dt-cpu-ports.patch",
    "rv220w-rj45-initramfs)",
    "openwrt-rv220w-rj45-initramfs.config",
    "rv220w-openwrt-rv220w-rj45-initramfs",
    "Re-run the v1.10.3 updater",
):
    if token not in build_text:
        fail(f"v1.9.0 build helper lacks token: {token}")
for forbidden in ("Re-run the v1.8.4 updater", "differs from toolkit v1.8.4"):
    if forbidden in build_text:
        fail(f"stale v1.8.4 build instruction remains: {forbidden}")
subprocess.run([sys.executable, str(ROOT / "tests/test_b53_dt_cpu_ports_patch.py")], check=True)
subprocess.run([sys.executable, str(ROOT / "tests/test_rj45_full_profile.py")], check=True)
print("v1.9.0 first full-RJ45 candidate checks passed")


# v1.9.1 production cleanup assets.
for required_path in (
    ROOT / "openwrt/production/cn5010_cisco_rv220w-production.dts.in",
    ROOT / "openwrt/production/999-octeon-production-dt-flash-cleanups.patch",
    HISTORY_DOCS / "RV220W-V1.9.1-PRODUCTION-CLEANUP.md",
    ROOT / "tests/test_v191_production_cleanup.py",
):
    if not required_path.is_file():
        fail(f"missing v1.9.1 production asset: {required_path}")


# v1.9.2 patch-context hotfix assets.
for required_path in (
    HISTORY_DOCS / "RV220W-V1.9.2-PATCH999-CONTEXT-HOTFIX.md",
    ROOT / "tests/test_v192_patch999_context.py",
):
    if not required_path.is_file():
        fail(f"missing v1.9.2 hotfix asset: {required_path}")


# v1.9.3 FDT verification API hotfix assets.
for required_path in (
    HISTORY_DOCS / "RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md",
    ROOT / "tests/test_v193_fdt_verify_api.py",
    ROOT / "evidence/v192-build-failure/README.md",
):
    if not required_path.is_file():
        fail(f"missing v1.9.3 hotfix asset: {required_path}")
subprocess.run([sys.executable, str(ROOT / "tests/test_v193_fdt_verify_api.py")], check=True)
