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

static int
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
