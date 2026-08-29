/*
 * RV220W genuine N-PHY rev4 / BCM2056 rev3 RX-IQ staging scaffold.
 *
 * NOT WIRED INTO B43. NOT RF-ACTIVE. The qualified v1.14.35 run gate stays
 * -EOPNOTSUPP until these helpers are implemented, cross-built and covered by
 * rollback tests.
 *
 * Source mapping:
 *   stock .text+0x11d370 -> Broadcom rev3+ outer RX-IQ helper
 *   stock .text+0x110f98 -> RX-cal gain control
 *   stock .text+0x110640 -> pre-rev7 RCCAL sweep
 */

/*
 * Full review definition lives in rev4-txpwr-index-target-helper.c.  The
 * transaction snapshot is deliberately broader than Broadcom's private save
 * structure because b43_nphy_tx_power_ctrl() mutates shared TPC tables/state.
 */
struct rv220w_rxiq_txpwr_saved;

struct rv220w_rxiq_phy_saved {
	u16 r_a2;
	u16 r_a6_a7;
	u16 r_8f_a5;
	u16 r_91;
	u16 r_92;
	u16 r_7a;
	u16 r_7d;
	u16 r_e7;
	u16 r_ec;
	u16 r_297;
	u16 r_29b;
	bool valid;
};

struct rv220w_rxiq_radio_saved {
	u16 tx_rxiqcal_txmux;
	u16 rx_rxiqcal_rxmux;
	u16 lna_tune;
	bool valid;
};

struct rv220w_rxiq_rccal_saved {
	u16 rx0_lpc;
	u16 rx_hpc[2];
	u16 tx_lpc[2];
	u16 tx_idac4[2];
	bool idac_valid;
	bool valid;
};

/* Implementation order; every mutating helper requires a paired restore. */
static int rv220w_rxiq_rev4_phy_setup(/* dev, core, saved */);
static int rv220w_rxiq_rev4_phy_restore(/* dev, core, saved, verify */);
static int rv220w_rxiq_rev4_radio_setup(/* dev, core, saved */);
static int rv220w_rxiq_rev4_radio_restore(/* dev, core, saved, verify */);
static int rv220w_rxiq_rev4_txpwr_capture(/* dev, saved */);
static int rv220w_rxiq_rev4_txpwr_begin_calibration(/* dev, saved */);
static int rv220w_rxiq_rev4_txpwr_apply_signed(/* dev, saved, core, s8 index */);
static int rv220w_rxiq_rev4_txpwr_restore(/* dev, saved */);
static int rv220w_rxiq_rev4_txpwr_verify(/* dev, saved */);
static int rv220w_rxiq_rev4_gainctrl(/* dev, txpwr_session, rx_core, cal_type, telemetry */);
static int rv220w_rxiq_rev4_rc_sweep(/* dev, core, loopback_type, result */);
static int rv220w_rxiq_rev4_run_iq_only(/* dev, before, observed, status */);
static int rv220w_rxiq_rev4_run_full(/* later: includes rollback-protected RCCAL */);

/*
 * Initial target guard (first implementation only):
 *   PHY type N
 *   PHY rev 4
 *   radio 0x2056 rev 3
 *   2.4 GHz, channels 1..11
 *   IPA false
 *
 * Do not reuse b43_nphy_set_rx_core_state() from an already-suspended debugfs
 * transaction: current b43 performs its own MAC suspend/enable in that helper.
 */
