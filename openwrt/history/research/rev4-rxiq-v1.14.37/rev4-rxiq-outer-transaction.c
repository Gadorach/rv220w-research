/*
 * RV220W v1.14.37 compile-only rev4 RX-IQ outer transaction.
 *
 * This is the enclosing stock-order transaction around the v1.14.36 rev4
 * primitives.  It is deliberately NOT wired into the public debugfs `run`
 * command: v1.14.37 remains fail-closed.  The purpose of this revision is to
 * compile the whole N-PHY4/BCM2056r3 orchestration and mechanically preserve
 * one rollback path for normal completion plus every injected failure stage.
 *
 * Target scope is intentionally narrow for the first hardware candidate:
 *   - N-PHY revision 4
 *   - BCM2056 radio revision 3
 *   - 2.4 GHz channels 1..11
 *   - two-core RX state (RFSEQ RXEN == 0x3 and phyrxchain == 0x3)
 *   - external PA / non-IPA path
 *
 * Requiring the normal two-core state avoids b43_nphy_set_rx_core_state(),
 * whose current implementation performs its own MAC suspend/resume.  A future
 * RF-active debugfs caller already owns MAC suspension and must not nest it.
 */

enum rv220w_rxiq_rev4_fault_point {
	RV220W_RXIQ_FAULT_NONE = 0,
	RV220W_RXIQ_FAULT_AFTER_CARRIER,
	RV220W_RXIQ_FAULT_AFTER_TPC_OFF,
	RV220W_RXIQ_FAULT_AFTER_GAIN_TABLE,
	RV220W_RXIQ_FAULT_AFTER_CORE0_PHY,
	RV220W_RXIQ_FAULT_AFTER_CORE0_RADIO,
	RV220W_RXIQ_FAULT_AFTER_CORE0_GAIN,
	RV220W_RXIQ_FAULT_AFTER_CORE0_IQ,
	RV220W_RXIQ_FAULT_AFTER_CORE1_PHY,
	RV220W_RXIQ_FAULT_AFTER_CORE1_RADIO,
	RV220W_RXIQ_FAULT_AFTER_CORE1_GAIN,
	RV220W_RXIQ_FAULT_AFTER_CORE1_IQ,
	RV220W_RXIQ_FAULT_AFTER_RCCAL,
	RV220W_RXIQ_FAULT_AFTER_RCCAL_COMMIT,
};

#define RV220W_RXIQ_CLEAN_PLAYBACK       BIT(0)
#define RV220W_RXIQ_CLEAN_RADIO          BIT(1)
#define RV220W_RXIQ_CLEAN_PHY            BIT(2)
#define RV220W_RXIQ_CLEAN_RCCAL_COMMIT   BIT(3)
#define RV220W_RXIQ_CLEAN_TXPWR          BIT(4)
#define RV220W_RXIQ_CLEAN_BBCFG          BIT(5)
#define RV220W_RXIQ_CLEAN_RXGAIN         BIT(6)
#define RV220W_RXIQ_CLEAN_IQCOEFF        BIT(7)
#define RV220W_RXIQ_CLEAN_HANG_AVOID     BIT(8)
#define RV220W_RXIQ_CLEAN_CARRIER        BIT(9)
#define RV220W_RXIQ_CLEAN_DEAF_COUNT     BIT(10)

struct rv220w_rxiq_rev4_rccal_commit_saved {
	bool valid;
	u16 rx_lpc[2];
	u16 rx_hpc[2];
	u16 tx_lpc[2];
};

struct rv220w_rxiq_rev4_transaction_result {
	int primary_rc;
	int cleanup_rc;
	u32 cleanup_fail_mask;
	u8 cal_type;
	u8 rxcore_state;
	u8 rccal_candidate;
	u8 rccal_committed[2];
	struct rv220w_rxiq_gain_result gain[2];
	struct b43_phy_n_iq_comp iq_before;
	struct b43_phy_n_iq_comp iq_observed;
};

static int __maybe_unused
rv220w_rxiq_rev4_maybe_fault(enum rv220w_rxiq_rev4_fault_point selected,
			     enum rv220w_rxiq_rev4_fault_point here)
{
	return selected == here ? -ECANCELED : 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_rccal_commit_capture(
	struct b43_wldev *dev,
	struct rv220w_rxiq_rev4_rccal_commit_saved *s)
{
	int core;

	if (!s || s->valid)
		return -EINVAL;
	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4 ||
	    dev->phy.radio_ver != 0x2056 || dev->phy.radio_rev != 3)
		return -EOPNOTSUPP;

	for (core = 0; core < 2; core++) {
		u16 rx = core ? B2056_RX1 : B2056_RX0;
		u16 tx = core ? B2056_TX1 : B2056_TX0;

		s->rx_lpc[core] = b43_radio_read(dev,
			rx | B2056_RX_RXLPF_RCCAL_LPC);
		s->rx_hpc[core] = b43_radio_read(dev,
			rx | B2056_RX_RXLPF_RCCAL_HPC);
		s->tx_lpc[core] = b43_radio_read(dev,
			tx | B2056_TX_TXLPF_RCCAL);
	}
	s->valid = true;
	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_rccal_commit_apply(
	struct b43_wldev *dev, u8 candidate,
	struct rv220w_rxiq_rev4_transaction_result *result)
{
	int core;

	if (candidate > 0x7f)
		return -ERANGE;
	if (b43_nphy_ipa(dev))
		return -EOPNOTSUPP;

	/* Stock rev3+ mirrors the core-1 sweep result to both cores. */
	for (core = 0; core < 2; core++) {
		u16 rx = core ? B2056_RX1 : B2056_RX0;
		u16 tx = core ? B2056_TX1 : B2056_TX0;
		int rxlpf_rccal_hpc;
		int txlpf_rccal_lpc;

		rxlpf_rccal_hpc = (((int)candidate - 12) >> 1) + 10;
		txlpf_rccal_lpc = ((int)candidate - 12) + 10;
		rxlpf_rccal_hpc = clamp_t(int, rxlpf_rccal_hpc, 0, 31);
		txlpf_rccal_lpc = clamp_t(int, txlpf_rccal_lpc, 0, 31);

		b43_radio_write(dev, rx | B2056_RX_RXLPF_RCCAL_LPC,
				candidate | 0x80);
		b43_radio_write(dev, rx | B2056_RX_RXLPF_RCCAL_HPC,
				rxlpf_rccal_hpc | 0x80);
		b43_radio_write(dev, tx | B2056_TX_TXLPF_RCCAL,
				txlpf_rccal_lpc | 0x80);
		if (result)
			result->rccal_committed[core] = candidate;
	}

	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_rccal_commit_restore(
	struct b43_wldev *dev,
	const struct rv220w_rxiq_rev4_rccal_commit_saved *s)
{
	int core;

	if (!s || !s->valid)
		return -EINVAL;
	for (core = 0; core < 2; core++) {
		u16 rx = core ? B2056_RX1 : B2056_RX0;
		u16 tx = core ? B2056_TX1 : B2056_TX0;

		b43_radio_write(dev, rx | B2056_RX_RXLPF_RCCAL_LPC,
				s->rx_lpc[core]);
		b43_radio_write(dev, rx | B2056_RX_RXLPF_RCCAL_HPC,
				s->rx_hpc[core]);
		b43_radio_write(dev, tx | B2056_TX_TXLPF_RCCAL,
				s->tx_lpc[core]);
	}
	return 0;
}

static int __maybe_unused
rv220w_rxiq_rev4_rccal_commit_verify(
	struct b43_wldev *dev,
	const struct rv220w_rxiq_rev4_rccal_commit_saved *s)
{
	int core;

	if (!s || !s->valid)
		return -EINVAL;
	for (core = 0; core < 2; core++) {
		u16 rx = core ? B2056_RX1 : B2056_RX0;
		u16 tx = core ? B2056_TX1 : B2056_TX0;

		if (b43_radio_read(dev, rx | B2056_RX_RXLPF_RCCAL_LPC) !=
							 s->rx_lpc[core] ||
		    b43_radio_read(dev, rx | B2056_RX_RXLPF_RCCAL_HPC) !=
							 s->rx_hpc[core] ||
		    b43_radio_read(dev, tx | B2056_TX_TXLPF_RCCAL) !=
							 s->tx_lpc[core])
			return -EUCLEAN;
	}
	return 0;
}

static bool __maybe_unused
rv220w_rxiq_rev4_iq_equal(const struct b43_phy_n_iq_comp *a,
			  const struct b43_phy_n_iq_comp *b)
{
	return a->a0 == b->a0 && a->b0 == b->b0 &&
	       a->a1 == b->a1 && a->b1 == b->b1;
}

static int __maybe_unused
rv220w_rxiq_rev4_run_transaction(
	struct b43_wldev *dev, u8 cal_type,
	enum rv220w_rxiq_rev4_fault_point fault,
	struct rv220w_rxiq_rev4_transaction_result *result)
{
	struct b43_phy_n *nphy = dev->phy.n;
	struct rv220w_rxiq_txpwr_saved txs = { };
	struct rv220w_rxiq_rev4_rccal_commit_saved rccal_saved = { };
	struct rv220w_rxiq_phy_saved phy_saved = { };
	struct rv220w_rxiq_radio_saved radio_saved = { };
	struct nphy_txgains target;
	struct nphy_iqcal_params cal_params[2];
	struct b43_phy_n_iq_comp iq_verify;
	u16 cal_gain[2];
	u16 bbcfg_saved;
	u16 rfctl_over_saved[2];
	u32 deaf_before;
	bool hang_avoid_saved;
	bool carrier_held = false;
	bool phy_active = false;
	bool radio_active = false;
	u8 active_core = 0;
	int ret = 0;
	int cleanup_rc = 0;
	int core;

	if (!result || !nphy || cal_type > 2)
		return -EINVAL;
	memset(result, 0, sizeof(*result));
	result->cal_type = cal_type;

	if (dev->phy.type != B43_PHYTYPE_N || dev->phy.rev != 4 ||
	    dev->phy.radio_ver != 0x2056 || dev->phy.radio_rev != 3 ||
	    b43_current_band(dev->wl) != NL80211_BAND_2GHZ ||
	    dev->phy.channel < 1 || dev->phy.channel > 11 ||
	    b43_nphy_ipa(dev))
		return -EOPNOTSUPP;

	result->rxcore_state = b43_nphy_get_rx_core_state(dev);
	if (result->rxcore_state != 0x3 || nphy->phyrxchain != 0x3)
		return -EOPNOTSUPP;

	/* Target gain must be sampled before TPC is disabled. */
	target = b43_nphy_get_tx_gains(dev);
	b43_nphy_rx_iq_coeffs(dev, false, &result->iq_before);
	bbcfg_saved = b43_phy_read(dev, B43_NPHY_BBCFG);
	rfctl_over_saved[0] = b43_phy_read(dev, B43_NPHY_REV3_RFCTL_OVER0);
	rfctl_over_saved[1] = b43_phy_read(dev, B43_NPHY_REV3_RFCTL_OVER1);
	deaf_before = nphy->deaf_count;
	hang_avoid_saved = nphy->hang_avoid;

	ret = rv220w_rxiq_rev4_txpwr_capture(dev, &txs);
	if (ret)
		goto out;
	ret = rv220w_rxiq_rev4_rccal_commit_capture(dev, &rccal_saved);
	if (ret)
		goto out;

	/* Stock clears BBConfig.RSTRX, enters carrier search, then disables
	 * hang-avoid so nested tone/stop/TPC helpers do not alter deaf_count. */
	b43_phy_mask(dev, B43_NPHY_BBCFG, ~B43_NPHY_BBCFG_RSTRX);
	b43_nphy_stay_in_carrier_search(dev, true);
	carrier_held = true;
	nphy->hang_avoid = false;

	ret = rv220w_rxiq_rev4_maybe_fault(fault,
					   RV220W_RXIQ_FAULT_AFTER_CARRIER);
	if (ret)
		goto cleanup;

	ret = rv220w_rxiq_rev4_txpwr_begin_calibration(dev, &txs);
	if (ret)
		goto cleanup;
	ret = rv220w_rxiq_rev4_maybe_fault(fault,
					   RV220W_RXIQ_FAULT_AFTER_TPC_OFF);
	if (ret)
		goto cleanup;

	for (core = 0; core < 2; core++) {
		b43_nphy_iq_cal_gain_params(dev, core, target, &cal_params[core]);
		cal_gain[core] = cal_params[core].cal_gain;
	}
	b43_ntab_write_bulk(dev, B43_NTAB16(7, 0x110), 2, cal_gain);
	ret = rv220w_rxiq_rev4_maybe_fault(fault,
					   RV220W_RXIQ_FAULT_AFTER_GAIN_TABLE);
	if (ret)
		goto cleanup;

	for (core = 0; core < 2; core++) {
		enum rv220w_rxiq_rev4_fault_point fp;

		active_core = core;
		memset(&phy_saved, 0, sizeof(phy_saved));
		memset(&radio_saved, 0, sizeof(radio_saved));

		ret = rv220w_rxiq_rev4_phy_setup(dev, core, &phy_saved);
		if (ret)
			goto cleanup;
		phy_active = true;
		fp = core ? RV220W_RXIQ_FAULT_AFTER_CORE1_PHY :
			    RV220W_RXIQ_FAULT_AFTER_CORE0_PHY;
		ret = rv220w_rxiq_rev4_maybe_fault(fault, fp);
		if (ret)
			goto cleanup;

		ret = rv220w_rxiq_rev4_radio_setup(dev, core, &radio_saved);
		if (ret)
			goto cleanup;
		radio_active = true;
		fp = core ? RV220W_RXIQ_FAULT_AFTER_CORE1_RADIO :
			    RV220W_RXIQ_FAULT_AFTER_CORE0_RADIO;
		ret = rv220w_rxiq_rev4_maybe_fault(fault, fp);
		if (ret)
			goto cleanup;

		if (cal_type == 0 || cal_type == 2) {
			ret = rv220w_rxiq_rev4_gainctrl(dev, &txs, core, 0,
						     &result->gain[core]);
			if (ret)
				goto cleanup;
			fp = core ? RV220W_RXIQ_FAULT_AFTER_CORE1_GAIN :
				    RV220W_RXIQ_FAULT_AFTER_CORE0_GAIN;
			ret = rv220w_rxiq_rev4_maybe_fault(fault, fp);
			if (ret)
				goto cleanup;

			ret = b43_nphy_tx_tone(dev,
				b43_is_40mhz(dev) ? RV220W_RXIQ_TONEFREQ_40 :
						     RV220W_RXIQ_TONEFREQ_20,
				RV220W_RXIQ_TONEAMP, false, cal_type != 0, false);
			if (ret)
				goto cleanup;
			b43_nphy_calc_rx_iq_comp(dev, BIT(core));
			b43_nphy_stop_playback(dev);
			b43_nphy_rx_iq_coeffs(dev, false, &result->iq_observed);
			fp = core ? RV220W_RXIQ_FAULT_AFTER_CORE1_IQ :
				    RV220W_RXIQ_FAULT_AFTER_CORE0_IQ;
			ret = rv220w_rxiq_rev4_maybe_fault(fault, fp);
			if (ret)
				goto cleanup;
		}

		/* Stock rev<7 performs RCCAL only while processing RX core 1.  The
		 * RV220W runner requires rxcore_state==3, so no temporary core-enable
		 * transition is required or permitted here. */
		if ((cal_type == 1 || cal_type == 2) && core == 1) {
			ret = rv220w_rxiq_rev4_gainctrl(dev, &txs, core, 1,
						     &result->gain[core]);
			if (ret)
				goto cleanup;
			ret = rv220w_rxiq_rev4_rc_sweep(dev, core, 1,
						     &result->rccal_candidate);
			if (ret)
				goto cleanup;
			ret = rv220w_rxiq_rev4_maybe_fault(fault,
						   RV220W_RXIQ_FAULT_AFTER_RCCAL);
			if (ret)
				goto cleanup;
		}

		b43_nphy_stop_playback(dev);
		if (radio_active) {
			ret = rv220w_rxiq_rev4_radio_restore(dev, &radio_saved);
			if (!ret)
				ret = rv220w_rxiq_rev4_radio_verify_restored(dev,
								       &radio_saved);
			radio_active = false;
			if (ret)
				goto cleanup;
		}
		if (phy_active) {
			ret = rv220w_rxiq_rev4_phy_restore(dev, core, &phy_saved);
			if (!ret)
				ret = rv220w_rxiq_rev4_phy_verify_restored(dev, core,
								     &phy_saved);
			phy_active = false;
			if (ret)
				goto cleanup;
		}
		b43_nphy_force_rf_sequence(dev, B43_RFSEQ_RESET2RX);
	}

	if (cal_type == 1 || cal_type == 2) {
		ret = rv220w_rxiq_rev4_rccal_commit_apply(dev,
			result->rccal_candidate, result);
		if (ret)
			goto cleanup;
		ret = rv220w_rxiq_rev4_maybe_fault(fault,
					   RV220W_RXIQ_FAULT_AFTER_RCCAL_COMMIT);
		if (ret)
			goto cleanup;
	}

cleanup:
	result->primary_rc = ret;
	b43_nphy_stop_playback(dev);

	if (radio_active) {
		if (rv220w_rxiq_rev4_radio_restore(dev, &radio_saved) ||
		    rv220w_rxiq_rev4_radio_verify_restored(dev, &radio_saved))
			result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_RADIO;
		radio_active = false;
	}
	if (phy_active) {
		if (rv220w_rxiq_rev4_phy_restore(dev, active_core, &phy_saved) ||
		    rv220w_rxiq_rev4_phy_verify_restored(dev, active_core,
							 &phy_saved))
			result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_PHY;
		phy_active = false;
	}

	/* The compile-only transaction never persists RCCAL.  Even a successful
	 * stock-equivalent commit is rolled back so the future test command is
	 * observational until a separate persistence policy is qualified. */
	if (rccal_saved.valid) {
		if (rv220w_rxiq_rev4_rccal_commit_restore(dev, &rccal_saved) ||
		    rv220w_rxiq_rev4_rccal_commit_verify(dev, &rccal_saved))
			result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_RCCAL_COMMIT;
	}

	if (txs.valid) {
		if (rv220w_rxiq_rev4_txpwr_restore(dev, &txs) ||
		    rv220w_rxiq_rev4_txpwr_verify(dev, &txs))
			result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_TXPWR;
	}

	/* Gainctrl leaves the selected RX-gain override installed for its caller.
	 * Per-core PHY restoration should already have restored both rev3 override
	 * registers.  Re-apply the exact transaction-wide originals here instead
	 * of blindly clearing BIT(12), which could destroy a legitimate pre-run
	 * override. */
	b43_phy_write(dev, B43_NPHY_REV3_RFCTL_OVER0, rfctl_over_saved[0]);
	b43_phy_write(dev, B43_NPHY_REV3_RFCTL_OVER1, rfctl_over_saved[1]);
	b43_nphy_force_rf_sequence(dev, B43_RFSEQ_RESET2RX);
	if (b43_phy_read(dev, B43_NPHY_REV3_RFCTL_OVER0) !=
						rfctl_over_saved[0] ||
	    b43_phy_read(dev, B43_NPHY_REV3_RFCTL_OVER1) !=
						rfctl_over_saved[1])
		result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_RXGAIN;

	/* Reset CCA as stock does, then enforce exact BBConfig rollback after the
	 * reset helper's temporary RSTCCA toggle. */
	b43_nphy_reset_cca(dev);
	b43_phy_write(dev, B43_NPHY_BBCFG, bbcfg_saved);
	if (b43_phy_read(dev, B43_NPHY_BBCFG) != bbcfg_saved)
		result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_BBCFG;

	/* The transaction is rollback-only in v1.14.37: retain the calculated
	 * tuple in result->iq_observed, but restore the hardware coefficients. */
	b43_nphy_rx_iq_coeffs(dev, true, &result->iq_before);
	b43_nphy_rx_iq_coeffs(dev, false, &iq_verify);
	if (!rv220w_rxiq_rev4_iq_equal(&iq_verify, &result->iq_before))
		result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_IQCOEFF;

	nphy->hang_avoid = hang_avoid_saved;
	if (nphy->hang_avoid != hang_avoid_saved)
		result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_HANG_AVOID;

	if (carrier_held) {
		b43_nphy_stay_in_carrier_search(dev, false);
		carrier_held = false;
	}
	if (nphy->deaf_count != deaf_before)
		result->cleanup_fail_mask |= RV220W_RXIQ_CLEAN_DEAF_COUNT;

	if (result->cleanup_fail_mask) {
		cleanup_rc = -EUCLEAN;
		result->cleanup_rc = cleanup_rc;
		if (!ret)
			ret = cleanup_rc;
	}

out:
	if (!result->primary_rc)
		result->primary_rc = ret;
	return ret;
}
