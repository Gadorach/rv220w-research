/*
 * RV220W v1.14.36 compile-only rev4 RX-IQ staging.
 *
 * These helpers are intentionally unreachable from the debugfs `run` gate.
 * v1.14.35 fail-closed dispatch remains in force.  This block exists solely
 * to compile the reconstructed N-PHY rev4 / BCM2056 rev3 primitives against
 * the exact OpenWrt/backports b43 tree before any RF-active transaction is
 * permitted.
 */

/*
 * Review-only target-scoped PHY/radio loopback setup for the genuine
 * RV220W N-PHY rev4 / BCM2056 rev3 RX-IQ path.
 *
 * NOT WIRED INTO B43. NOT RF-ACTIVE. The qualified v1.14.35 debugfs run gate
 * remains fail-closed. These helpers are intended for insertion into phy_n.c,
 * where the b43 N-PHY static helpers they call are visible.
 *
 * Provenance:
 *   - PHY setup/cleanup: Broadcom rev3+ wlc_phy_rxcal_physetup_nphy() and
 *     wlc_phy_rxcal_phycleanup_nphy(); the same rev3-6 body already exists in
 *     mainline b43 under #if 0, but is unused.
 *   - Radio setup/cleanup: Broadcom wlc_phy_rxcal_radio_setup_nphy() /
 *     cleanup, cross-checked against RV220W stock wl.ko.
 *   - Stock wl.ko mod_radio_reg(old, mask, value) is
 *       (old & ~mask) | (value & mask).
 *     The radio-rev3 2.4-GHz call uses mask 0x00f0,value 0x0f00; therefore its
 *     actual effect is simply to CLEAR LNAG_TUNE bits 4..7.  Do not "fix" the
 *     apparently mis-shifted Broadcom source expression.
 */

struct rv220w_rxiq_phy_saved {
	u16 rfseqca;          /* 0x0a2 */
	u16 afectl_core;      /* 0x0a6 / 0x0a7 */
	u16 afectl_over_core; /* 0x08f / 0x0a5 */
	u16 rfctl_intc1;      /* 0x091 */
	u16 rfctl_intc2;      /* 0x092 */
	u16 rfctl_rssio1;     /* 0x07a */
	u16 rfctl_rssio2;     /* 0x07d */
	u16 txf_40co_b1s1;    /* 0x0e7 */
	u16 rfctl_over;       /* 0x0ec */
	u16 papd_en0;         /* 0x297 */
	u16 papd_en1;         /* 0x29b */
	bool valid;
};

struct rv220w_rxiq_radio_saved {
	u16 tx_reg;
	u16 rx_reg;
	u16 lna_reg;
	u16 tx_rxiqcal_txmux;
	u16 rx_rxiqcal_rxmux;
	u16 lna_tune;
	bool valid;
};

static int __maybe_unused
rv220w_rxiq_rev4_phy_setup(struct b43_wldev *dev, u8 rx_core,
			   struct rv220w_rxiq_phy_saved *s)
{
	u8 tx_core;
	u16 rx_antval, tx_antval;
	u16 afectl_core, afectl_over_core;

	if (!s || s->valid || rx_core > 1)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4)
		return -EOPNOTSUPP;

	tx_core = 1 - rx_core;
	afectl_core = rx_core ? B43_NPHY_AFECTL_C2 : B43_NPHY_AFECTL_C1;
	afectl_over_core = rx_core ? B43_NPHY_AFECTL_OVER :
					    B43_NPHY_AFECTL_OVER1;

	/* Capture every PHY register touched directly or by the rev3-6 RF
	 * override helpers.  This is the exact Broadcom save set for rev4. */
	s->rfseqca = b43_phy_read(dev, B43_NPHY_RFSEQCA);
	s->afectl_core = b43_phy_read(dev, afectl_core);
	s->afectl_over_core = b43_phy_read(dev, afectl_over_core);
	s->rfctl_intc1 = b43_phy_read(dev, B43_NPHY_RFCTL_INTC1);
	s->rfctl_intc2 = b43_phy_read(dev, B43_NPHY_RFCTL_INTC2);
	s->rfctl_rssio1 = b43_phy_read(dev, B43_NPHY_RFCTL_RSSIO1);
	s->rfctl_rssio2 = b43_phy_read(dev, B43_NPHY_RFCTL_RSSIO2);
	s->txf_40co_b1s1 = b43_phy_read(dev, B43_NPHY_TXF_40CO_B1S1);
	s->rfctl_over = b43_phy_read(dev, B43_NPHY_RFCTL_OVER);
	s->papd_en0 = b43_phy_read(dev, B43_NPHY_PAPD_EN0);
	s->papd_en1 = b43_phy_read(dev, B43_NPHY_PAPD_EN1);
	s->valid = true;

	/* Broadcom rev3+ setup disables PAPD while the loopback path is active. */
	b43_phy_mask(dev, B43_NPHY_PAPD_EN0, ~0x0001);
	b43_phy_mask(dev, B43_NPHY_PAPD_EN1, ~0x0001);

	/* Rev<7 loopback routes the opposite core as TX and the selected core
	 * as RX.  These four fields are the 0xa2 mutations visible in stock. */
	b43_phy_maskset(dev, B43_NPHY_RFSEQCA,
			~B43_NPHY_RFSEQCA_RXDIS & 0xffff,
			tx_core << B43_NPHY_RFSEQCA_RXDIS_SHIFT);
	b43_phy_maskset(dev, B43_NPHY_RFSEQCA,
			~B43_NPHY_RFSEQCA_TXEN & 0xffff,
			tx_core << B43_NPHY_RFSEQCA_TXEN_SHIFT);
	b43_phy_maskset(dev, B43_NPHY_RFSEQCA,
			~B43_NPHY_RFSEQCA_RXEN & 0xffff,
			rx_core << B43_NPHY_RFSEQCA_RXEN_SHIFT);
	b43_phy_maskset(dev, B43_NPHY_RFSEQCA,
			~B43_NPHY_RFSEQCA_TXDIS & 0xffff,
			rx_core << B43_NPHY_RFSEQCA_TXDIS_SHIFT);

	/* Broadcom performs bit2 and bits1:0 separately; the net rev4 state is
	 * AFECTL[2:0]=0 and the matching override bits [2:0]=1. */
	b43_phy_mask(dev, afectl_core, ~0x0007);
	b43_phy_set(dev, afectl_over_core, 0x0007);

	b43_nphy_rf_ctl_intc_override(dev, N_INTC_OVERRIDE_PA, 0, 3);
	b43_nphy_rf_ctl_override(dev, BIT(3), 0, 3, false);
	b43_nphy_force_rf_sequence(dev, B43_RFSEQ_RX2TX);

	if (rx_core == 0) {
		rx_antval = 0x1;
		tx_antval = 0x8;
	} else {
		rx_antval = 0x4;
		tx_antval = 0x2;
	}
	b43_nphy_rf_ctl_intc_override(dev, N_INTC_OVERRIDE_TRSW,
				      rx_antval, rx_core + 1);
	b43_nphy_rf_ctl_intc_override(dev, N_INTC_OVERRIDE_TRSW,
				      tx_antval, tx_core + 1);

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_phy_restore(struct b43_wldev *dev, u8 rx_core,
			     const struct rv220w_rxiq_phy_saved *s)
{
	u16 afectl_core, afectl_over_core;

	if (!s || !s->valid || rx_core > 1)
		return -EINVAL;

	afectl_core = rx_core ? B43_NPHY_AFECTL_C2 : B43_NPHY_AFECTL_C1;
	afectl_over_core = rx_core ? B43_NPHY_AFECTL_OVER :
					    B43_NPHY_AFECTL_OVER1;

	/* Exact register restoration intentionally supersedes attempting to
	 * unwind the nested override helpers piecemeal. */
	b43_phy_write(dev, B43_NPHY_RFSEQCA, s->rfseqca);
	b43_phy_write(dev, afectl_core, s->afectl_core);
	b43_phy_write(dev, afectl_over_core, s->afectl_over_core);
	b43_phy_write(dev, B43_NPHY_RFCTL_INTC1, s->rfctl_intc1);
	b43_phy_write(dev, B43_NPHY_RFCTL_INTC2, s->rfctl_intc2);
	b43_phy_write(dev, B43_NPHY_RFCTL_RSSIO1, s->rfctl_rssio1);
	b43_phy_write(dev, B43_NPHY_RFCTL_RSSIO2, s->rfctl_rssio2);
	b43_phy_write(dev, B43_NPHY_TXF_40CO_B1S1, s->txf_40co_b1s1);
	b43_phy_write(dev, B43_NPHY_RFCTL_OVER, s->rfctl_over);
	b43_phy_write(dev, B43_NPHY_PAPD_EN0, s->papd_en0);
	b43_phy_write(dev, B43_NPHY_PAPD_EN1, s->papd_en1);

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_phy_verify_restored(struct b43_wldev *dev, u8 rx_core,
				     const struct rv220w_rxiq_phy_saved *s)
{
	u16 afectl_core, afectl_over_core;

	if (!s || !s->valid || rx_core > 1)
		return -EINVAL;

	afectl_core = rx_core ? B43_NPHY_AFECTL_C2 : B43_NPHY_AFECTL_C1;
	afectl_over_core = rx_core ? B43_NPHY_AFECTL_OVER :
					    B43_NPHY_AFECTL_OVER1;

	if (b43_phy_read(dev, B43_NPHY_RFSEQCA) != s->rfseqca ||
	    b43_phy_read(dev, afectl_core) != s->afectl_core ||
	    b43_phy_read(dev, afectl_over_core) != s->afectl_over_core ||
	    b43_phy_read(dev, B43_NPHY_RFCTL_INTC1) != s->rfctl_intc1 ||
	    b43_phy_read(dev, B43_NPHY_RFCTL_INTC2) != s->rfctl_intc2 ||
	    b43_phy_read(dev, B43_NPHY_RFCTL_RSSIO1) != s->rfctl_rssio1 ||
	    b43_phy_read(dev, B43_NPHY_RFCTL_RSSIO2) != s->rfctl_rssio2 ||
	    b43_phy_read(dev, B43_NPHY_TXF_40CO_B1S1) != s->txf_40co_b1s1 ||
	    b43_phy_read(dev, B43_NPHY_RFCTL_OVER) != s->rfctl_over ||
	    b43_phy_read(dev, B43_NPHY_PAPD_EN0) != s->papd_en0 ||
	    b43_phy_read(dev, B43_NPHY_PAPD_EN1) != s->papd_en1)
		return -EUCLEAN;

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_radio_setup(struct b43_wldev *dev, u8 rx_core,
			     struct rv220w_rxiq_radio_saved *s)
{
	if (!s || s->valid || rx_core > 1)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4 ||
	    dev->phy.radio_ver != 0x2056 || dev->phy.radio_rev != 3 ||
	    b43_current_band(dev->wl) != NL80211_BAND_2GHZ)
		return -EOPNOTSUPP;

	/* Rev<7 uses the opposite TX core.  The RV220W is 2.4 GHz and radio
	 * rev3, so only the three-register pre-rev5 G-band branch is needed. */
	if (rx_core == 0) {
		s->tx_reg = B2056_TX1 | B2056_TX_RXIQCAL_TXMUX;
		s->rx_reg = B2056_RX0 | B2056_RX_RXIQCAL_RXMUX;
		s->lna_reg = B2056_RX0 | B2056_RX_LNAG_TUNE;
	} else {
		s->tx_reg = B2056_TX0 | B2056_TX_RXIQCAL_TXMUX;
		s->rx_reg = B2056_RX1 | B2056_RX_RXIQCAL_RXMUX;
		s->lna_reg = B2056_RX1 | B2056_RX_LNAG_TUNE;
	}

	s->tx_rxiqcal_txmux = b43_radio_read(dev, s->tx_reg);
	s->rx_rxiqcal_rxmux = b43_radio_read(dev, s->rx_reg);
	s->lna_tune = b43_radio_read(dev, s->lna_reg);
	s->valid = true;

	/* Exact stock rev3 effect of mod_radio_reg(reg, 0x00f0, 0x0f00):
	 * (old & ~0x00f0) | (0x0f00 & 0x00f0) == old & ~0x00f0. */
	b43_radio_mask(dev, s->lna_reg, ~0x00f0 & 0xffff);
	b43_radio_write(dev, s->tx_reg, 0x0006);
	b43_radio_write(dev, s->rx_reg, 0x0006);

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_radio_restore(struct b43_wldev *dev,
			       const struct rv220w_rxiq_radio_saved *s)
{
	if (!s || !s->valid)
		return -EINVAL;

	b43_radio_write(dev, s->tx_reg, s->tx_rxiqcal_txmux);
	b43_radio_write(dev, s->rx_reg, s->rx_rxiqcal_rxmux);
	b43_radio_write(dev, s->lna_reg, s->lna_tune);
	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_radio_verify_restored(struct b43_wldev *dev,
				       const struct rv220w_rxiq_radio_saved *s)
{
	if (!s || !s->valid)
		return -EINVAL;

	if (b43_radio_read(dev, s->tx_reg) != s->tx_rxiqcal_txmux ||
	    b43_radio_read(dev, s->rx_reg) != s->rx_rxiqcal_rxmux ||
	    b43_radio_read(dev, s->lna_reg) != s->lna_tune)
		return -EUCLEAN;

	return 0;
}

/*
 * Per-core unwind order after a calibration attempt:
 *   stop playback
 *   radio_restore()
 *   phy_restore()
 *   b43_nphy_force_rf_sequence(dev, B43_RFSEQ_RESET2RX)
 *   verify radio + PHY snapshots
 *
 * The final RESET2RX is part of the genuine outer routine.  The transaction
 * level snapshot must separately cover state outside these local save sets.
 */

/*
 * Review-only target-scoped port of the TX-power-index operation used by the
 * genuine N-PHY rev4 RX calibration gain-control routine.
 *
 * NOT WIRED INTO B43. NOT RF-ACTIVE. Compile/API adaptation against the exact
 * OpenWrt backports tree is still required.
 *
 * Scope: N-PHY rev4, restore_cals=false, two cores.
 *
 * Important source-level detail:
 *   Broadcom's txpwrindex argument is s8.  The first entry of the pre-rev7
 *   2.4-GHz RX-cal table is written as literal 128 into an s8 member, so on the
 *   stock toolchain it is -128.  All negative values mean "release the forced
 *   index and restore the lazily captured per-core base state".  Only the exact
 *   value -1 is intercepted by RX gain-control itself for its gmval fallback;
 *   -128 reaches wlc_phy_txpwr_index_nphy() and therefore MUST be supported.
 *
 * This diagnostic staging deliberately has TWO rollback layers:
 *   1. a transaction-wide exact snapshot, captured before calibration disables
 *      TPC, for unconditional final rollback/verification;
 *   2. a lazy per-core force-base snapshot, captured immediately before the
 *      first numeric forced index, for Broadcom-compatible negative-sentinel
 *      semantics during the gain search.
 */

#define RV220W_RXIQ_TXPWR_ADJ_LEN 84
#define RV220W_RXIQ_TXPWR_INDEX_MAX 127

struct rv220w_rxiq_txpwr_force_base {
	bool active;
	u16 afectl_over1;
	u16 afectl_over;
	u16 dac_gain;
	u16 rfseq_gain;
	u8 bbmult;
};

struct rv220w_rxiq_txpwr_saved {
	bool valid;
	bool calibration_tpc_off;
	bool txpwrctrl;
	u8 tx_pwr_idx[2];

	u16 txpctl_cmd;
	u16 txpctl_init;
	u16 afectl_over1;
	u16 afectl_over;
	u16 dac_gain[2];
	u16 rfseq_gain[2];
	u16 bbmult_word;
	u16 adj_pwr[2][RV220W_RXIQ_TXPWR_ADJ_LEN];

	struct rv220w_rxiq_txpwr_force_base force_base[2];
};

static int __maybe_unused
rv220w_rxiq_rev4_txpwr_capture(struct b43_wldev *dev,
			       struct rv220w_rxiq_txpwr_saved *s)
{
	struct b43_phy_n *nphy = dev->phy.n;

	if (!s || s->valid)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4)
		return -EOPNOTSUPP;

	s->txpwrctrl = nphy->txpwrctrl;
	s->tx_pwr_idx[0] = nphy->tx_pwr_idx[0];
	s->tx_pwr_idx[1] = nphy->tx_pwr_idx[1];

	s->txpctl_cmd = b43_phy_read(dev, B43_NPHY_TXPCTL_CMD);
	s->txpctl_init = b43_phy_read(dev, B43_NPHY_TXPCTL_INIT);
	s->afectl_over1 = b43_phy_read(dev, B43_NPHY_AFECTL_OVER1);
	s->afectl_over = b43_phy_read(dev, B43_NPHY_AFECTL_OVER);
	s->dac_gain[0] = b43_phy_read(dev, B43_NPHY_AFECTL_DACGAIN1);
	s->dac_gain[1] = b43_phy_read(dev, B43_NPHY_AFECTL_DACGAIN2);
	b43_ntab_read_bulk(dev, B43_NTAB16(7, 0x110), 2, s->rfseq_gain);
	s->bbmult_word = b43_ntab_read(dev, B43_NTAB16(15, 87));
	b43_ntab_read_bulk(dev, B43_NTAB16(26, 64),
			   RV220W_RXIQ_TXPWR_ADJ_LEN, s->adj_pwr[0]);
	b43_ntab_read_bulk(dev, B43_NTAB16(27, 64),
			   RV220W_RXIQ_TXPWR_ADJ_LEN, s->adj_pwr[1]);

	s->force_base[0].active = false;
	s->force_base[1].active = false;
	s->calibration_tpc_off = false;
	s->valid = true;
	return 0;
}

/*
 * The genuine calibration caller enters RX-IQ with hardware TPC disabled.
 * A standalone diagnostic must recreate that precondition only AFTER the exact
 * transaction-wide snapshot has been captured.
 */
static int __maybe_unused
rv220w_rxiq_rev4_txpwr_begin_calibration(struct b43_wldev *dev,
					 struct rv220w_rxiq_txpwr_saved *s)
{
	if (!s || !s->valid || s->calibration_tpc_off)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4)
		return -EOPNOTSUPP;

	b43_nphy_tx_power_ctrl(dev, false);
	if (dev->phy.n->txpwrctrl)
		return -EUCLEAN;

	s->calibration_tpc_off = true;
	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_txpwr_capture_force_base(struct b43_wldev *dev,
					  struct rv220w_rxiq_txpwr_saved *s,
					  u8 core)
{
	struct rv220w_rxiq_txpwr_force_base *b;
	u16 m1m2;

	if (!s || !s->valid || !s->calibration_tpc_off || core > 1)
		return -EINVAL;

	b = &s->force_base[core];
	if (b->active)
		return 0;

	/* Capture the state as seen by the force-index helper, i.e. AFTER the
	 * outer calibration transaction has disabled TPC and installed its
	 * calibration RFSEQ gains.  This is intentionally not the global snapshot. */
	b->afectl_over1 = b43_phy_read(dev, B43_NPHY_AFECTL_OVER1);
	b->afectl_over = b43_phy_read(dev, B43_NPHY_AFECTL_OVER);
	b->dac_gain = b43_phy_read(dev, core ? B43_NPHY_AFECTL_DACGAIN2 :
					       B43_NPHY_AFECTL_DACGAIN1);
	b->rfseq_gain = b43_ntab_read(dev, B43_NTAB16(7, 0x110 + core));
	m1m2 = b43_ntab_read(dev, B43_NTAB16(15, 87));
	b->bbmult = core ? (u8)(m1m2 & 0xff) : (u8)(m1m2 >> 8);
	b->active = true;

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_txpwr_release_index(struct b43_wldev *dev,
				     struct rv220w_rxiq_txpwr_saved *s,
				     u8 core)
{
	struct rv220w_rxiq_txpwr_force_base *b;
	u16 m1m2;

	if (!s || !s->valid || !s->calibration_tpc_off || core > 1)
		return -EINVAL;

	b = &s->force_base[core];
	if (!b->active)
		return 0; /* Same no-op semantics as stock when no index is forced. */

	b43_phy_write(dev, core ? B43_NPHY_AFECTL_DACGAIN2 :
				    B43_NPHY_AFECTL_DACGAIN1, b->dac_gain);
	b43_ntab_write(dev, B43_NTAB16(7, 0x110 + core), b->rfseq_gain);

	m1m2 = b43_ntab_read(dev, B43_NTAB16(15, 87));
	if (core == 0)
		m1m2 = (m1m2 & 0x00ff) | ((u16)b->bbmult << 8);
	else
		m1m2 = (m1m2 & 0xff00) | b->bbmult;
	b43_ntab_write(dev, B43_NTAB16(15, 87), m1m2);

	/* Stock re-applies the caller's TPC state after releasing a forced index.
	 * In this diagnostic transaction that state must remain OFF. */
	b43_nphy_tx_power_ctrl(dev, false);
	b43_phy_write(dev, B43_NPHY_AFECTL_OVER1, b->afectl_over1);
	b43_phy_write(dev, B43_NPHY_AFECTL_OVER, b->afectl_over);

	b->active = false;
	return 0;
}

/*
 * Apply one signed Broadcom TX-power-index value.
 *
 *   index >= 0 : lazily capture the per-core force base and install that index
 *   index <  0 : release the force and restore that per-core base
 *
 * The exact -1 gmval special case belongs to gainctrl and must not call this
 * helper.  The 2.4-GHz table's -128 sentinel DOES call this helper.
 */
static int __maybe_unused
rv220w_rxiq_rev4_txpwr_apply_signed(struct b43_wldev *dev,
				    struct rv220w_rxiq_txpwr_saved *s,
				    u8 core, s8 index)
{
	u32 txgain;
	u16 radio_gain, dac_gain, m1m2;
	u8 bbmult;
	int ret;

	if (!s || !s->valid || !s->calibration_tpc_off || core > 1)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4)
		return -EOPNOTSUPP;
	if (dev->phy.n->txpwrctrl)
		return -EUCLEAN;

	if (index < 0)
		return rv220w_rxiq_rev4_txpwr_release_index(dev, s, core);
	if ((u8)index > RV220W_RXIQ_TXPWR_INDEX_MAX)
		return -ERANGE;

	ret = rv220w_rxiq_rev4_txpwr_capture_force_base(dev, s, core);
	if (ret)
		return ret;

	/* Broadcom saves the current TPC mode, disables it, applies the index, and
	 * restores that mode.  Our caller's mode is deliberately OFF throughout
	 * calibration, so both calls below are false. */
	b43_nphy_tx_power_ctrl(dev, false);

	/* Genuine stock path reads the live per-core gain-control table. */
	txgain = b43_ntab_read(dev, B43_NTAB32(26 + core, 192 + (u8)index));
	radio_gain = (u16)((txgain >> 16) & 0x1ffff);
	dac_gain = (u16)((txgain >> 8) & 0x3f);
	bbmult = (u8)(txgain & 0xff);

	if (core == 0) {
		b43_phy_set(dev, B43_NPHY_AFECTL_OVER1, 0x0100);
		b43_phy_write(dev, B43_NPHY_AFECTL_DACGAIN1, dac_gain);
	} else {
		b43_phy_set(dev, B43_NPHY_AFECTL_OVER, 0x0100);
		b43_phy_write(dev, B43_NPHY_AFECTL_DACGAIN2, dac_gain);
	}

	b43_ntab_write(dev, B43_NTAB16(7, 0x110 + core), radio_gain);
	m1m2 = b43_ntab_read(dev, B43_NTAB16(15, 87));
	if (core == 0)
		m1m2 = (m1m2 & 0x00ff) | ((u16)bbmult << 8);
	else
		m1m2 = (m1m2 & 0xff00) | bbmult;
	b43_ntab_write(dev, B43_NTAB16(15, 87), m1m2);

	b43_nphy_tx_power_ctrl(dev, false);
	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_txpwr_restore(struct b43_wldev *dev,
			       struct rv220w_rxiq_txpwr_saved *s)
{
	struct b43_phy_n *nphy = dev->phy.n;

	if (!s || !s->valid)
		return -EINVAL;

	/* First ask b43 to reconstruct the saved logical mode, then overwrite all
	 * touched hardware with the exact pre-transaction snapshot. */
	b43_nphy_tx_power_ctrl(dev, s->txpwrctrl);

	b43_ntab_write_bulk(dev, B43_NTAB16(26, 64),
			    RV220W_RXIQ_TXPWR_ADJ_LEN, s->adj_pwr[0]);
	b43_ntab_write_bulk(dev, B43_NTAB16(27, 64),
			    RV220W_RXIQ_TXPWR_ADJ_LEN, s->adj_pwr[1]);

	b43_phy_write(dev, B43_NPHY_AFECTL_OVER1, s->afectl_over1);
	b43_phy_write(dev, B43_NPHY_AFECTL_OVER, s->afectl_over);
	b43_phy_write(dev, B43_NPHY_AFECTL_DACGAIN1, s->dac_gain[0]);
	b43_phy_write(dev, B43_NPHY_AFECTL_DACGAIN2, s->dac_gain[1]);
	b43_ntab_write_bulk(dev, B43_NTAB16(7, 0x110), 2, s->rfseq_gain);
	b43_ntab_write(dev, B43_NTAB16(15, 87), s->bbmult_word);

	b43_phy_write(dev, B43_NPHY_TXPCTL_INIT, s->txpctl_init);
	b43_phy_write(dev, B43_NPHY_TXPCTL_CMD, s->txpctl_cmd);
	nphy->tx_pwr_idx[0] = s->tx_pwr_idx[0];
	nphy->tx_pwr_idx[1] = s->tx_pwr_idx[1];
	nphy->txpwrctrl = s->txpwrctrl;

	s->force_base[0].active = false;
	s->force_base[1].active = false;
	s->calibration_tpc_off = false;
	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_txpwr_verify(struct b43_wldev *dev,
			      const struct rv220w_rxiq_txpwr_saved *s)
{
	struct b43_phy_n *nphy = dev->phy.n;
	u16 tmp[RV220W_RXIQ_TXPWR_ADJ_LEN];
	u16 rfseq[2];

	if (!s || !s->valid)
		return -EINVAL;

	if (nphy->txpwrctrl != s->txpwrctrl ||
	    nphy->tx_pwr_idx[0] != s->tx_pwr_idx[0] ||
	    nphy->tx_pwr_idx[1] != s->tx_pwr_idx[1])
		return -EUCLEAN;
	if (b43_phy_read(dev, B43_NPHY_TXPCTL_CMD) != s->txpctl_cmd ||
	    b43_phy_read(dev, B43_NPHY_TXPCTL_INIT) != s->txpctl_init ||
	    b43_phy_read(dev, B43_NPHY_AFECTL_OVER1) != s->afectl_over1 ||
	    b43_phy_read(dev, B43_NPHY_AFECTL_OVER) != s->afectl_over ||
	    b43_phy_read(dev, B43_NPHY_AFECTL_DACGAIN1) != s->dac_gain[0] ||
	    b43_phy_read(dev, B43_NPHY_AFECTL_DACGAIN2) != s->dac_gain[1])
		return -EUCLEAN;

	b43_ntab_read_bulk(dev, B43_NTAB16(7, 0x110), 2, rfseq);
	if (memcmp(rfseq, s->rfseq_gain, sizeof(rfseq)))
		return -EUCLEAN;
	if ((u16)b43_ntab_read(dev, B43_NTAB16(15, 87)) != s->bbmult_word)
		return -EUCLEAN;

	b43_ntab_read_bulk(dev, B43_NTAB16(26, 64),
			   RV220W_RXIQ_TXPWR_ADJ_LEN, tmp);
	if (memcmp(tmp, s->adj_pwr[0], sizeof(tmp)))
		return -EUCLEAN;
	b43_ntab_read_bulk(dev, B43_NTAB16(27, 64),
			   RV220W_RXIQ_TXPWR_ADJ_LEN, tmp);
	if (memcmp(tmp, s->adj_pwr[1], sizeof(tmp)))
		return -EUCLEAN;

	return 0;
}

/*
 * Any mismatch above is a failed diagnostic transaction and must leave the
 * public run gate blocked.
 */

/*
 * Review-only target-scoped port of Broadcom's
 * wlc_phy_rxcal_gainctrl_nphy_rev5() for the RV220W's genuine N-PHY rev4,
 * BCM2056 rev3, 2.4-GHz RX-IQ path.
 *
 * NOT WIRED INTO B43. NOT RF-ACTIVE. Intended to live in phy_n.c beside the
 * static b43 N-PHY primitives and rev4-txpwr-index-target-helper.c.
 *
 * Source behavior retained:
 *   - opposite TX core for PHY rev<7
 *   - 1024-sample estimator / threshold 10000 / desired log2 power 13
 *   - starting gain-table row 3 and INIT/UP/DOWN search
 *   - RX-IQ compensation is zeroed during gain search and always restored
 *   - final fine adjustment is applied to HPVGA, clamped 0..10
 *   - gain override BIT(12) remains installed for the outer RX-IQ routine
 *
 * Diagnostic-strengthening differences from Broadcom:
 *   - tone failure is propagated instead of silently ignored;
 *   - a zero estimator result is treated as -EIO;
 *   - exact txpwrindex == -1 is rejected in this 2.4-GHz target helper rather
 *     than fabricating the unrelated 5-GHz gmval fallback.
 */

#define RV220W_RXIQ_NUM_SAMPS        1024
#define RV220W_RXIQ_THRESH_PWR       10000U
#define RV220W_RXIQ_DESIRED_LOG2_PWR 13
#define RV220W_RXIQ_TONEAMP          181
#define RV220W_RXIQ_TONEFREQ_40      4000
#define RV220W_RXIQ_TONEFREQ_20      2000
#define RV220W_RXIQ_GAIN_ROWS        6

struct rv220w_rxiq_gain_row {
	u16 hpvga;
	u16 lpf_biq1;
	u16 lpf_biq0;
	u16 lna2;
	u16 lna1;
	s8 txpwrindex;
};

/*
 * Broadcom source writes literal 128 into an s8 member in row 0.  Spell the
 * conversion explicitly so reviewers cannot mistake it for numeric index 128.
 */
static const struct rv220w_rxiq_gain_row rv220w_rxiq_rev4_gain_2g[] = {
	{ 0, 0, 0, 0, 0, (s8)0x80 }, /* -128: release forced TX index */
	{ 0, 0, 0, 0, 0, 70 },
	{ 0, 0, 0, 0, 0, 20 },
	{ 0, 0, 0, 3, 0, 20 },
	{ 0, 0, 3, 3, 0, 20 },
	{ 0, 2, 3, 3, 0, 20 },
};

enum rv220w_rxiq_gain_dir {
	RV220W_RXIQ_GAIN_INIT = 0,
	RV220W_RXIQ_GAIN_UP,
	RV220W_RXIQ_GAIN_DOWN,
};

struct rv220w_rxiq_gain_result {
	u8 rx_core;
	u8 tx_core;
	s8 optimum_row;
	s8 last_txpwrindex;
	u32 optimum_power;
	u16 lna1;
	u16 lna2;
	u16 mix_tia;
	u16 lpf_biq0;
	u16 lpf_biq1;
	u16 hpvga;
};

static u16
rv220w_rxiq_rev4_pack_rxgain(u16 hpvga, u16 lpf_biq1, u16 lpf_biq0,
			     u16 mix_tia, u16 lna2, u16 lna1)
{
	return (hpvga << 12) | (lpf_biq1 << 10) | (lpf_biq0 << 8) |
	       (mix_tia << 4) | (lna2 << 2) | lna1;
}

static u32
rv220w_rxiq_rev4_est_power(const struct nphy_iq_est *est, u8 core)
{
	u32 i_pwr, q_pwr;

	if (core == 0) {
		i_pwr = DIV_ROUND_CLOSEST(est->i0_pwr, RV220W_RXIQ_NUM_SAMPS);
		q_pwr = DIV_ROUND_CLOSEST(est->q0_pwr, RV220W_RXIQ_NUM_SAMPS);
	} else {
		i_pwr = DIV_ROUND_CLOSEST(est->i1_pwr, RV220W_RXIQ_NUM_SAMPS);
		q_pwr = DIV_ROUND_CLOSEST(est->q1_pwr, RV220W_RXIQ_NUM_SAMPS);
	}

	return i_pwr + q_pwr;
}

static int __maybe_unused
rv220w_rxiq_rev4_gainctrl(struct b43_wldev *dev,
			  struct rv220w_rxiq_txpwr_saved *txs,
			  u8 rx_core, u8 cal_type,
			  struct rv220w_rxiq_gain_result *result)
{
	struct b43_phy_n_iq_comp save_comp;
	struct b43_phy_n_iq_comp zero_comp = { };
	struct nphy_iq_est est;
	const struct rv220w_rxiq_gain_row *row;
	enum rv220w_rxiq_gain_dir dir = RV220W_RXIQ_GAIN_INIT;
	s8 curr_row = 3, prev_row = 0, optimum_row = 0;
	u8 tx_core;
	u16 mix_tia = 3;
	u16 hpvga = 0, lpf_biq1 = 0, lpf_biq0 = 0, lna2 = 0, lna1 = 0;
	s8 txpwrindex = 0;
	u32 curr_pwr, prev_pwr = 0, optimum_pwr = 0;
	int actual_log2_pwr, delta_pwr;
	bool done = false;
	int ret = 0;

	if (!txs || !txs->valid || !txs->calibration_tpc_off || rx_core > 1)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4 ||
	    dev->phy.radio_ver != 0x2056 || dev->phy.radio_rev != 3 ||
	    b43_current_band(dev->wl) != NL80211_BAND_2GHZ)
		return -EOPNOTSUPP;
	if (cal_type > 1)
		return -EINVAL;

	tx_core = 1 - rx_core;
	b43_nphy_rx_iq_coeffs(dev, false, &save_comp);
	b43_nphy_rx_iq_coeffs(dev, true, &zero_comp);

	do {
		if (curr_row < 0 || curr_row >= RV220W_RXIQ_GAIN_ROWS) {
			ret = -ERANGE;
			goto out_restore_coeffs;
		}

		row = &rv220w_rxiq_rev4_gain_2g[curr_row];
		hpvga = row->hpvga;
		lpf_biq1 = row->lpf_biq1;
		lpf_biq0 = row->lpf_biq0;
		lna2 = row->lna2;
		lna1 = row->lna1;
		txpwrindex = row->txpwrindex;

		b43_nphy_rf_ctl_override(dev, BIT(12),
			rv220w_rxiq_rev4_pack_rxgain(hpvga, lpf_biq1, lpf_biq0,
						     mix_tia, lna2, lna1),
			3, false);

		/* Exact -1 belongs to Broadcom's gmval fallback.  It occurs in the
		 * 5-GHz table, not this target's 2-GHz table.  Row 0 is -128 and must
		 * pass through to the signed TX-power helper as a release sentinel. */
		if (txpwrindex == -1) {
			ret = -EOPNOTSUPP;
			goto out_stop;
		}
		ret = rv220w_rxiq_rev4_txpwr_apply_signed(dev, txs, tx_core,
							 txpwrindex);
		if (ret)
			goto out_stop;

		ret = b43_nphy_tx_tone(dev,
			b43_is_40mhz(dev) ? RV220W_RXIQ_TONEFREQ_40 :
					     RV220W_RXIQ_TONEFREQ_20,
			RV220W_RXIQ_TONEAMP, false, cal_type != 0, false);
		if (ret)
			goto out_stop;

		memset(&est, 0, sizeof(est));
		b43_nphy_rx_iq_est(dev, &est, RV220W_RXIQ_NUM_SAMPS, 32, false);
		curr_pwr = rv220w_rxiq_rev4_est_power(&est, rx_core);
		if (!curr_pwr) {
			ret = -EIO;
			goto out_stop;
		}

		switch (dir) {
		case RV220W_RXIQ_GAIN_INIT:
			if (curr_pwr > RV220W_RXIQ_THRESH_PWR) {
				dir = RV220W_RXIQ_GAIN_DOWN;
				prev_row = curr_row;
				curr_row--;
			} else {
				dir = RV220W_RXIQ_GAIN_UP;
				prev_row = curr_row;
				curr_row++;
			}
			break;
		case RV220W_RXIQ_GAIN_UP:
			if (curr_pwr > RV220W_RXIQ_THRESH_PWR) {
				done = true;
				optimum_pwr = prev_pwr;
				optimum_row = prev_row;
			} else {
				prev_row = curr_row;
				curr_row++;
			}
			break;
		case RV220W_RXIQ_GAIN_DOWN:
			if (curr_pwr > RV220W_RXIQ_THRESH_PWR) {
				prev_row = curr_row;
				curr_row--;
			} else {
				done = true;
				optimum_pwr = curr_pwr;
				optimum_row = curr_row;
			}
			break;
		}

		if (curr_row < 0 || curr_row >= RV220W_RXIQ_GAIN_ROWS) {
			done = true;
			optimum_pwr = curr_pwr;
			optimum_row = prev_row;
		} else {
			prev_pwr = curr_pwr;
		}

		b43_nphy_stop_playback(dev);
	} while (!done);

	if (optimum_row < 0 || optimum_row >= RV220W_RXIQ_GAIN_ROWS ||
	    !optimum_pwr) {
		ret = -ERANGE;
		goto out_restore_coeffs;
	}

	row = &rv220w_rxiq_rev4_gain_2g[optimum_row];
	hpvga = row->hpvga;
	lpf_biq1 = row->lpf_biq1;
	lpf_biq0 = row->lpf_biq0;
	lna2 = row->lna2;
	lna1 = row->lna1;

	/* Broadcom wlc_phy_nbits() is the integer bit length for this positive
	 * power value.  Linux fls() has the same result for u32. */
	actual_log2_pwr = fls(optimum_pwr);
	delta_pwr = RV220W_RXIQ_DESIRED_LOG2_PWR - actual_log2_pwr;
	hpvga = clamp_t(int, (int)hpvga + delta_pwr, 0, 10);

	b43_nphy_rf_ctl_override(dev, BIT(12),
		rv220w_rxiq_rev4_pack_rxgain(hpvga, lpf_biq1, lpf_biq0,
					     mix_tia, lna2, lna1),
		3, false);

	if (result) {
		result->rx_core = rx_core;
		result->tx_core = tx_core;
		result->optimum_row = optimum_row;
		result->last_txpwrindex = txpwrindex;
		result->optimum_power = optimum_pwr;
		result->lna1 = lna1;
		result->lna2 = lna2;
		result->mix_tia = mix_tia;
		result->lpf_biq0 = lpf_biq0;
		result->lpf_biq1 = lpf_biq1;
		result->hpvga = hpvga;
	}

	goto out_restore_coeffs;

out_stop:
	b43_nphy_stop_playback(dev);
out_restore_coeffs:
	b43_nphy_rx_iq_coeffs(dev, true, &save_comp);
	return ret;
}

/*
 * Review-only target-scoped port of stock .text+0x110640, now mapped to
 * Broadcom wlc_phy_rc_sweep_nphy().
 *
 * NOT WIRED INTO B43. NOT RF-ACTIVE.
 *
 * Target: N-PHY rev4 / BCM2056.  The source routine is pre-rev7 only.
 *
 * Safety divergence from stock:
 *   Stock intentionally leaves the selected RX RXLPF_RCCAL_LPC register at the
 *   measured best value and returns best-0x80.  This diagnostic helper captures
 *   and restores that register too, returning the candidate via *result.  Any
 *   later outer routine must commit RCCAL explicitly under its own transaction
 *   snapshot.  That separates measurement from commit and makes the sweep
 *   itself fully rollback-verifiable.
 */

#define RV220W_RCCAL_NUM_SAMPS 1024
#define RV220W_RCCAL_TONEAMP   181

struct rv220w_rxiq_rccal_sweep_saved {
	bool valid;
	u16 tx_rccal_reg;
	u16 rx_hpc_reg;
	u16 rx_lpc_reg;
	u16 tx_rccal;
	u16 rx_hpc;
	u16 rx_lpc;
	u16 dc_bypass_reg;
	u16 filt[10];       /* PHY 0x267..0x270 */
	u16 rf_over[2];     /* 0xe7, 0xec */
	u16 rf_aux[2];      /* 0xf8, 0xfa */
	u16 rssi_other_reg; /* 0x7a or 0x7d */
	u16 rssi_other;
};

static int __maybe_unused
rv220w_rxiq_rev4_rccal_restore(struct b43_wldev *dev,
			       const struct rv220w_rxiq_rccal_sweep_saved *s)
{
	int i;

	if (!s || !s->valid)
		return -EINVAL;

	b43_nphy_stop_playback(dev);
	b43_radio_write(dev, s->tx_rccal_reg, s->tx_rccal);
	b43_radio_write(dev, s->rx_hpc_reg, s->rx_hpc);
	b43_radio_write(dev, s->rx_lpc_reg, s->rx_lpc);
	b43_phy_write(dev, 0x048, s->dc_bypass_reg);
	for (i = 0; i < 10; i++)
		b43_phy_write(dev, 0x267 + i, s->filt[i]);
	b43_phy_write(dev, 0x0e7, s->rf_over[0]);
	b43_phy_write(dev, 0x0ec, s->rf_over[1]);
	b43_phy_write(dev, 0x0f8, s->rf_aux[0]);
	b43_phy_write(dev, 0x0fa, s->rf_aux[1]);
	b43_phy_write(dev, s->rssi_other_reg, s->rssi_other);

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_rccal_verify(struct b43_wldev *dev,
			      const struct rv220w_rxiq_rccal_sweep_saved *s)
{
	int i;

	if (!s || !s->valid)
		return -EINVAL;
	if (b43_radio_read(dev, s->tx_rccal_reg) != s->tx_rccal ||
	    b43_radio_read(dev, s->rx_hpc_reg) != s->rx_hpc ||
	    b43_radio_read(dev, s->rx_lpc_reg) != s->rx_lpc ||
	    b43_phy_read(dev, 0x048) != s->dc_bypass_reg ||
	    b43_phy_read(dev, 0x0e7) != s->rf_over[0] ||
	    b43_phy_read(dev, 0x0ec) != s->rf_over[1] ||
	    b43_phy_read(dev, 0x0f8) != s->rf_aux[0] ||
	    b43_phy_read(dev, 0x0fa) != s->rf_aux[1] ||
	    b43_phy_read(dev, s->rssi_other_reg) != s->rssi_other)
		return -EUCLEAN;
	for (i = 0; i < 10; i++)
		if (b43_phy_read(dev, 0x267 + i) != s->filt[i])
			return -EUCLEAN;

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_rc_sweep(struct b43_wldev *dev, u8 core_idx,
			  u8 loopback_type, u8 *result)
{
	struct rv220w_rxiq_rccal_sweep_saved s = { };
	struct nphy_iq_est est;
	const u32 target_bw = b43_is_40mhz(dev) ? 21000 : 9500;
	const u32 ref_tone = b43_is_40mhz(dev) ? 6000 : 3000;
	const u32 target_pwr_ratio = b43_is_40mhz(dev) ? 18468 : 28606;
	const u16 rx_lpf_bw = b43_is_40mhz(dev) ? 4 : 2;
	const u16 tx_lpf_bw = 4, lpf_hpc = 7, hpvga_hpc = 7;
	u16 rx_off, tx_off;
	u16 rccal_val, last_rccal_val = 0, best_rccal_val = 0;
	u32 ref_iq_vals = 0, target_iq_vals, pwr_ratio, last_pwr_ratio = 0;
	s8 step = 16;
	int ret = 0, i;

	if (!result || core_idx > 1 || loopback_type > 1)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4 ||
	    dev->phy.radio_ver != 0x2056)
		return -EOPNOTSUPP;

	rx_off = core_idx ? B2056_RX1 : B2056_RX0;
	if (core_idx == 0)
		tx_off = loopback_type ? B2056_TX1 : B2056_TX0;
	else
		tx_off = loopback_type ? B2056_TX0 : B2056_TX1;

	s.tx_rccal_reg = tx_off | B2056_TX_TXLPF_RCCAL;
	s.rx_hpc_reg = rx_off | B2056_RX_RXLPF_RCCAL_HPC;
	s.rx_lpc_reg = rx_off | B2056_RX_RXLPF_RCCAL_LPC;
	s.tx_rccal = b43_radio_read(dev, s.tx_rccal_reg);
	s.rx_hpc = b43_radio_read(dev, s.rx_hpc_reg);
	s.rx_lpc = b43_radio_read(dev, s.rx_lpc_reg);
	s.dc_bypass_reg = b43_phy_read(dev, 0x048);
	for (i = 0; i < 10; i++)
		s.filt[i] = b43_phy_read(dev, 0x267 + i);
	s.rf_over[0] = b43_phy_read(dev, 0x0e7);
	s.rf_over[1] = b43_phy_read(dev, 0x0ec);
	s.rf_aux[0] = b43_phy_read(dev, 0x0f8);
	s.rf_aux[1] = b43_phy_read(dev, 0x0fa);
	s.rssi_other_reg = core_idx ? 0x07d : 0x07a;
	s.rssi_other = b43_phy_read(dev, s.rssi_other_reg);
	s.valid = true;

	b43_radio_write(dev, s.tx_rccal_reg, 128);
	b43_radio_write(dev, s.rx_hpc_reg, 159);
	b43_phy_set(dev, 0x048, BIT(8));

	b43_phy_write(dev, 0x267, 0x02d4);
	b43_phy_write(dev, 0x268, 0x0000);
	b43_phy_write(dev, 0x269, 0x0000);
	b43_phy_write(dev, 0x26a, 0x0000);
	b43_phy_write(dev, 0x26b, 0x0000);
	b43_phy_write(dev, 0x26c, 0x02d4);
	b43_phy_write(dev, 0x26d, 0x0000);
	b43_phy_write(dev, 0x26e, 0x0000);
	b43_phy_write(dev, 0x26f, 0x0000);
	b43_phy_write(dev, 0x270, 0x0000);

	b43_phy_set(dev, core_idx ? 0x0ec : 0x0e7, BIT(8));
	b43_phy_set(dev, core_idx ? 0x0e7 : 0x0ec, BIT(15));
	b43_phy_set(dev, core_idx ? 0x0ec : 0x0e7, BIT(9) | BIT(10));
	b43_phy_maskset(dev, core_idx ? 0x0f8 : 0x0fa,
			~(0x7 << 10) & 0xffff, tx_lpf_bw << 10);
	b43_phy_maskset(dev, core_idx ? 0x0fa : 0x0f8,
			~0x0007 & 0xffff, hpvga_hpc);
	b43_phy_maskset(dev, core_idx ? 0x0fa : 0x0f8,
			~(0x7 << 4) & 0xffff, lpf_hpc << 4);
	b43_phy_maskset(dev, s.rssi_other_reg,
			~(0x7 << 8) & 0xffff, rx_lpf_bw << 8);

	rccal_val = 128 + step;
	while (step >= 0) {
		u64 sum;

		b43_radio_write(dev, s.rx_lpc_reg, rccal_val);

		if (step == 16) {
			ret = b43_nphy_tx_tone(dev, ref_tone, RV220W_RCCAL_TONEAMP,
					    false, true, false);
			if (ret)
				goto out_restore;
			udelay(2);
			memset(&est, 0, sizeof(est));
			b43_nphy_rx_iq_est(dev, &est, RV220W_RCCAL_NUM_SAMPS,
					   32, false);
			sum = core_idx ? (u64)est.i1_pwr + est.q1_pwr :
					 (u64)est.i0_pwr + est.q0_pwr;
			if (!sum) {
				ret = -EIO;
				goto out_restore;
			}
			ref_iq_vals = max_t(u32, (u32)(sum >> 11), 1);

			ret = b43_nphy_tx_tone(dev, target_bw,
					    RV220W_RCCAL_TONEAMP,
					    false, true, false);
			if (ret)
				goto out_restore;
			udelay(2);
		}

		memset(&est, 0, sizeof(est));
		b43_nphy_rx_iq_est(dev, &est, RV220W_RCCAL_NUM_SAMPS, 32, false);
		sum = core_idx ? (u64)est.i1_pwr + est.q1_pwr :
				 (u64)est.i0_pwr + est.q0_pwr;
		if (!sum) {
			ret = -EIO;
			goto out_restore;
		}
		target_iq_vals = (u32)(sum >> 11);
		pwr_ratio = (u32)(((u64)target_iq_vals << 16) / ref_iq_vals);

		if (step == 0) {
			step--;
		} else if (step == 1) {
			last_rccal_val = rccal_val;
			rccal_val += (pwr_ratio > target_pwr_ratio) ? 1 : -1;
			last_pwr_ratio = pwr_ratio;
			step--;
		} else {
			step >>= 1;
			rccal_val += (pwr_ratio > target_pwr_ratio) ? step : -step;
		}

		if (step == -1) {
			best_rccal_val =
				(abs((int)last_pwr_ratio - (int)target_pwr_ratio) <
				 abs((int)pwr_ratio - (int)target_pwr_ratio)) ?
				last_rccal_val : rccal_val;

			if (b43_is_40mhz(dev)) {
				if (best_rccal_val > 140 || best_rccal_val < 135)
					best_rccal_val = 138;
			} else if (best_rccal_val > 142 || best_rccal_val < 137) {
				best_rccal_val = 140;
			}
			b43_radio_write(dev, s.rx_lpc_reg, best_rccal_val);
		}
	}

	*result = (u8)(best_rccal_val - 0x80);

out_restore:
	/* Unlike stock, also restore RX_LPC: the returned value is observation,
	 * not an implicit commit. */
	if (rv220w_rxiq_rev4_rccal_restore(dev, &s) && !ret)
		ret = -EUCLEAN;
	if (rv220w_rxiq_rev4_rccal_verify(dev, &s) && !ret)
		ret = -EUCLEAN;
	return ret;
}
