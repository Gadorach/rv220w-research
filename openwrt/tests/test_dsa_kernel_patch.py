#!/usr/bin/env python3
"""Check both persistent Octeon/DSA target patches against their source contexts."""

from __future__ import annotations

import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MASTER_PATCH = ROOT / "openwrt/dsa-lan/995-rv220w-octeon-dsa-master-node.patch"
RX_PATCH = ROOT / "openwrt/dsa-lan/996-octeon-dsa-conduit-length-error.patch"


def fail(message: str) -> None:
    raise SystemExit(message)


def write_master_fixture(root: Path) -> None:
    source = root / "drivers/staging/octeon/ethernet.c"
    source.parent.mkdir(parents=True, exist_ok=True)
    lines = ["/* post-OpenWrt target-patch fixture */"] * 820
    lines += [
        "\t\t\tSET_NETDEV_DEV(dev, &pdev->dev);",
        "\t\t\tpriv = netdev_priv(dev);",
        "\t\t\tpriv->netdev = dev;",
        "\t\t\tpriv->of_node = cvm_oct_node_for_port(pip, interface,",
        "\t\t\t\t\t\t\t port_index);",
        "",
        "\t\t\tINIT_DELAYED_WORK(&priv->port_periodic_work,",
        "\t\t\t\t\t  cvm_oct_periodic_worker);",
        "\t\t\tpriv->imode = imode;",
    ]
    source.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_rx_fixture(root: Path) -> None:
    source = root / "drivers/staging/octeon/ethernet-rx.c"
    source.parent.mkdir(parents=True, exist_ok=True)
    source.write_text(
        """// SPDX-License-Identifier: GPL-2.0
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cache.h>
#include <linux/cpumask.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/ip.h>
#include <linux/string.h>
#include <linux/prefetch.h>
#include <linux/ratelimit.h>
#include <linux/smp.h>
#include <linux/interrupt.h>
#include <net/dst.h>
#ifdef CONFIG_XFRM
#include <linux/xfrm.h>
#include <net/xfrm.h>
#endif /* CONFIG_XFRM */

static inline int cvm_oct_check_rcv_error(struct cvmx_wqe *work)
{
\tint port;

\tif (octeon_has_feature(OCTEON_FEATURE_PKND))
\t\tport = work->word0.pip.cn68xx.pknd;
\telse
\t\tport = work->word1.cn38xx.ipprt;

\tif ((work->word2.snoip.err_code == 10) && (work->word1.len <= 64))
\t\t/*
\t\t * Ignore length errors on min size packets. Some
\t\t * equipment incorrectly pads packets to 64+4FCS
\t\t * instead of 60+4FCS. Note these packets still get
\t\t * counted as frame errors.
\t\t */
\t\treturn 0;

\tif (work->word2.snoip.err_code == 5 ||
\t    work->word2.snoip.err_code == 7) {
\t\treturn 0;
\t}
\treturn 0;
}
""",
        encoding="utf-8",
    )


for patch in (MASTER_PATCH, RX_PATCH):
    if not patch.is_file():
        fail(f"missing patch: {patch}")
    text = patch.read_text(encoding="utf-8")
    for forbidden in ("drivers/net/dsa/b53", "package/kernel", "target/linux/generic"):
        if forbidden in text:
            fail(f"driver compatibility patch modifies forbidden layer {forbidden}: {patch.name}")

with tempfile.TemporaryDirectory(prefix="rv220w-octeon-patches-git-") as tmp:
    fixture = Path(tmp)
    write_master_fixture(fixture)
    write_rx_fixture(fixture)
    for patch in (MASTER_PATCH, RX_PATCH):
        subprocess.run(["git", "apply", "--check", str(patch)], cwd=fixture, check=True)
        subprocess.run(["git", "apply", str(patch)], cwd=fixture, check=True)

    master = (fixture / "drivers/staging/octeon/ethernet.c").read_text(encoding="utf-8")
    if master.count("dev->dev.of_node = priv->of_node;") != 1:
        fail("master-node patch did not add exactly one OF-node association")

    rx = (fixture / "drivers/staging/octeon/ethernet-rx.c").read_text(encoding="utf-8")
    for token in (
        "#include <net/dsa.h>",
        "work->word1.len <= 64",
        "port < TOTAL_NUMBER_OF_PORTS",
        "cvm_oct_device[port]",
        "netdev_uses_dsa(cvm_oct_device[port])",
    ):
        if token not in rx:
            fail(f"RX compatibility patch lacks token after application: {token}")
    if rx.count("netdev_uses_dsa(") != 1:
        fail("RX compatibility patch added an unexpected number of DSA-conduit checks")


with tempfile.TemporaryDirectory(prefix="rv220w-octeon-patches-plain-") as tmp:
    fixture = Path(tmp)
    write_master_fixture(fixture)
    write_rx_fixture(fixture)
    for kernel_patch in (MASTER_PATCH, RX_PATCH):
        subprocess.run(
            ["patch", "--batch", "--forward", "--dry-run", "-p1", "-i", str(kernel_patch)],
            cwd=fixture,
            check=True,
            stdout=subprocess.DEVNULL,
        )
        subprocess.run(
            ["patch", "--batch", "--forward", "-p1", "-i", str(kernel_patch)],
            cwd=fixture,
            check=True,
            stdout=subprocess.DEVNULL,
        )

print("v1.7.6 Octeon-only DSA patch applicability checks passed")
