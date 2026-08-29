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

static int
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
static int
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

static int
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

static int
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
static int
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

static int
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

static int
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
