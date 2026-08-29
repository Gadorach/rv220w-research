# RV220W rev4 RX-IQ outer transaction — v1.14.37

This directory preserves the v1.14.37 source-level staging copy of the enclosing N-PHY4 / BCM2056r3 RX-IQ transaction. The active copy is inserted into `phy_n.c` by `openwrt/wifi/998-b43-rv220w-platform-capabilities.patch`.

The runner is intentionally unreachable in v1.14.37. Host, target and kernel command gates remain fail-closed. Its purpose is to compile the entire stock-order orchestration and its single cleanup path against the project backports tree before any RF-active release is produced.

The target is deliberately restricted to the observed RV220W state: N-PHY rev4, BCM2056 rev3, 2.4 GHz channels 1–11, both RX cores enabled, `phyrxchain == 3`, and non-IPA. The stock one-core-to-two-core transition is not ported because the current b43 core-state setter performs MAC suspend/resume internally; a future diagnostic caller already owns MAC serialization.

The transaction captures and verifies pre-run IQ coefficients, BBConfig, carrier-search nesting, `hang_avoid`, TPC state and both 84-entry adjusted-power tables, calibration RFSEQ gains, per-core PHY/radio loopback state, and all RCCAL commit registers. It includes compile-time fault-injection points after each major mutation. Even a successful RCCAL commit is rolled back in v1.14.37.

The older reconstructed rev<3/rev2-family algorithm remains independently preserved under `research/legacy-revlt3-rxiq/`.
