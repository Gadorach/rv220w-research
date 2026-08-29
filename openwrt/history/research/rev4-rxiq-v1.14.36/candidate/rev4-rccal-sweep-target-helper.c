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

static int
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

static int
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

static int
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
