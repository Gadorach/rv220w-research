# Candidate source staging

This directory is **not RF-active and not a release**. The qualified v1.14.35 baseline remains untouched and its debugfs `run` gate remains fail-closed.

The review fragments are intentionally separated so each mutation domain can be audited and unit-tested before integration:

- `rev4-rxcal-setup-target-helper.c` — rev4 PHY setup/restore plus BCM2056 rev3 radio loopback setup/restore/verification. The PHY portion corresponds to the dormant rev3-6 b43 source already present under `#if 0`; the radio portion is the missing target-specific layer.
- `rev4-txpwr-index-target-helper.c` — exact transaction snapshot, TPC-off calibration context, signed `s8` force/release semantics, lazy per-core force-base state, final restore and verifier.
- `rev4-gainctrl-target-helper.c` — target-scoped pre-rev7 2.4-GHz gain-search state machine, including the `-128` release sentinel and IQ-coefficient rollback.
- `rev4-rccal-sweep-target-helper.c` — mapped `wlc_phy_rc_sweep_nphy()` with a safer diagnostic contract: measured RCCAL is returned while all sweep-local state, including RX LPC, is restored.
- `rev4-rxiq-porting-scaffold.c` — integration order and target guard; it is not an applied patch.

None of these files changes normal b43 calibration behavior or enables the RV220W debugfs RF path. The next milestone is compile-only integration into a v1.14.36-derived staging tree while retaining `-EOPNOTSUPP` at the active gate.
