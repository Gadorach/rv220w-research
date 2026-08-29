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

static int
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

static int
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

static int
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

static int
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

static int
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

static int
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
