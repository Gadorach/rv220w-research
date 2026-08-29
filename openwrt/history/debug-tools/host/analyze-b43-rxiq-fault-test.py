#!/usr/bin/env python3
import argparse, json, re
from pathlib import Path

def kv(text,key):
    m=re.findall(rf'^{re.escape(key)}=(.*)$',text,re.M)
    return m[-1].strip() if m else None

def iv(text,key,default=None):
    v=kv(text,key)
    if v is None or v=='missing': return default
    try: return int(v,0)
    except ValueError: return default

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('input'); ap.add_argument('--json',dest='json_out'); ap.add_argument('--text',dest='text_out')
    a=ap.parse_args(); text=Path(a.input).read_text(errors='replace')
    stage=kv(text,'rxiq_fault_stage')
    expected={'carrier':'1','tpc-off':'2','gain-table':'3','core0-phy':'4','core0-radio':'5','core0-gain':'6','core0-iq':'7','core1-phy':'8','core1-radio':'9','core1-gain':'10','core1-iq':'11','rccal-commit':'13','full-transaction':'14','retained-state':'15'}.get(stage)
    policy=kv(text,'rxiq_fault_policy')
    policies=(
      'v1.14.59-channel8-retained-live-calibration-state-ram-only',
      'v1.14.58-channel8-full-transaction-natural-complete-rollback-only',
      'v1.14.56-channel8-stock-zero-optimum-rccal-sweep-commit-rollback-only',
      'v1.14.55-channel8-rccal-sweep-commit-rollback-only',
      'v1.14.54-channel8-core1-gain-iq-combined-rollback-only',
      'v1.14.53-channel8-core1-gain-rollback-only',
      'v1.14.52-channel8-core1-radio-setup-rollback-only',
      'v1.14.51-channel8-core1-phy-setup-rollback-only',
      'v1.14.50-channel8-core0-iq-explicit-calc-rollback-only',
      'v1.14.49-channel8-core0-gain-zero-normalized-continue-rollback-only',
      'v1.14.48-channel8-core0-gain-rfseqca-bitmap-correction-rollback-only',
      'v1.14.47-channel8-core0-gain-phase-step-cordic-correction-rollback-only',
      'v1.14.46-channel8-core0-gain-corrected-sample-pack-rollback-only',
      'v1.14.45-channel8-core0-gain-signal-path-telemetry-rollback-only',
      'v1.14.44-channel8-core0-gain-telemetry-rollback-only',
      'v1.14.43-channel8-core0-gain-rollback-only',
      'v1.14.42-channel8-pre-tone-rollback-only')
    retainpol='v1.14.59-channel8-retained-live-calibration-state-ram-only'
    integrationpol='v1.14.58-channel8-full-transaction-natural-complete-rollback-only'
    newpol='v1.14.56-channel8-stock-zero-optimum-rccal-sweep-commit-rollback-only'
    prevpol='v1.14.55-channel8-rccal-sweep-commit-rollback-only'
    combinedpol='v1.14.54-channel8-core1-gain-iq-combined-rollback-only'
    current_iq_policy=policy in (retainpol,integrationpol,newpol,prevpol,combinedpol,'v1.14.52-channel8-core1-radio-setup-rollback-only','v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.50-channel8-core0-iq-explicit-calc-rollback-only')
    current_zero_continue_policy=policy in (retainpol,integrationpol,newpol,prevpol,combinedpol,'v1.14.52-channel8-core1-radio-setup-rollback-only','v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.50-channel8-core0-iq-explicit-calc-rollback-only','v1.14.49-channel8-core0-gain-zero-normalized-continue-rollback-only')
    current_rfseqca_policy=policy in (retainpol,integrationpol,newpol,prevpol,combinedpol,'v1.14.52-channel8-core1-radio-setup-rollback-only','v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.50-channel8-core0-iq-explicit-calc-rollback-only','v1.14.49-channel8-core0-gain-zero-normalized-continue-rollback-only','v1.14.48-channel8-core0-gain-rfseqca-bitmap-correction-rollback-only')
    current_phase_policy=policy in (retainpol,integrationpol,newpol,prevpol,combinedpol,'v1.14.52-channel8-core1-radio-setup-rollback-only','v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.50-channel8-core0-iq-explicit-calc-rollback-only','v1.14.49-channel8-core0-gain-zero-normalized-continue-rollback-only','v1.14.48-channel8-core0-gain-rfseqca-bitmap-correction-rollback-only','v1.14.47-channel8-core0-gain-phase-step-cordic-correction-rollback-only')
    current_pack_policy=policy in (retainpol,integrationpol,newpol,prevpol,combinedpol,'v1.14.52-channel8-core1-radio-setup-rollback-only','v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.50-channel8-core0-iq-explicit-calc-rollback-only','v1.14.49-channel8-core0-gain-zero-normalized-continue-rollback-only','v1.14.48-channel8-core0-gain-rfseqca-bitmap-correction-rollback-only','v1.14.47-channel8-core0-gain-phase-step-cordic-correction-rollback-only','v1.14.46-channel8-core0-gain-corrected-sample-pack-rollback-only')
    current_signal_policy=policy in (retainpol,integrationpol,newpol,prevpol,combinedpol,'v1.14.52-channel8-core1-radio-setup-rollback-only','v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.50-channel8-core0-iq-explicit-calc-rollback-only','v1.14.49-channel8-core0-gain-zero-normalized-continue-rollback-only','v1.14.48-channel8-core0-gain-rfseqca-bitmap-correction-rollback-only','v1.14.47-channel8-core0-gain-phase-step-cordic-correction-rollback-only','v1.14.46-channel8-core0-gain-corrected-sample-pack-rollback-only','v1.14.45-channel8-core0-gain-signal-path-telemetry-rollback-only')

    deep=('core0-gain','core0-iq','core1-phy','core1-radio','core1-gain','core1-iq','rccal-commit','full-transaction','retained-state')
    core1_phy_stages=('core1-phy','core1-radio','core1-gain','core1-iq','rccal-commit','full-transaction','retained-state')
    core1_radio_stages=('core1-radio','core1-gain','core1-iq','rccal-commit','full-transaction','retained-state')
    iq_stages=('core0-iq','core1-phy','core1-radio','core1-gain','core1-iq','rccal-commit','full-transaction','retained-state')
    core1_gain_stages=('core1-gain','core1-iq','rccal-commit','full-transaction','retained-state')
    core1_iq_stages=('core1-iq','rccal-commit','full-transaction','retained-state')
    rccal_stages=('rccal-commit','full-transaction','retained-state')
    iq_calc=kv(text,'requested_iq_calculation')
    if stage in deep:
        want_iq='0' if stage=='core0-gain' else '1'
        want_core1_phy='1' if stage in core1_phy_stages else '0'
        want_core1_radio='1' if stage in core1_radio_stages else '0'
        want_core1_gain='1' if stage in core1_gain_stages else '0'
        want_core1_iq='1' if stage in core1_iq_stages else '0'
        want_rccal='1' if stage in rccal_stages else '0'
        strict_core1=policy in ('v1.14.51-channel8-core1-phy-setup-rollback-only','v1.14.52-channel8-core1-radio-setup-rollback-only',combinedpol,prevpol,newpol,integrationpol,retainpol)
        absent=None if not strict_core1 else '__never__'
        absent_new=None if policy not in (combinedpol,prevpol,newpol,integrationpol,retainpol) else '__never__'
        absent_rccal=None if policy not in (prevpol,newpol,integrationpol,retainpol) else '__never__'
        rf_scope=(kv(text,'requested_internal_cal_tone')=='1' and kv(text,'requested_gain_search')=='1' and iq_calc==want_iq and
                  kv(text,'requested_core1_phy_setup') in (want_core1_phy,absent) and
                  kv(text,'requested_core1_radio_setup') in (want_core1_radio,absent) and
                  kv(text,'requested_core1_gain_search') in (want_core1_gain,absent_new) and
                  kv(text,'requested_core1_internal_cal_tone') in (want_core1_gain,absent_new) and
                  kv(text,'requested_core1_iq_calculation') in (want_core1_iq,absent_new) and
                  kv(text,'requested_rccal')==want_rccal and
                  kv(text,'requested_rccal_commit') in (want_rccal,absent_rccal))
        debug_scope=(kv(text,'gain_search_reachable')=='1' and kv(text,'calibration_tone_reachable')=='1' and kv(text,'iq_calculation_reachable')==want_iq and
                     kv(text,'core1_phy_reachable') in (want_core1_phy,absent) and
                     kv(text,'core1_radio_reachable') in (want_core1_radio,absent) and
                     kv(text,'core1_gain_reachable') in (want_core1_gain,absent_new) and
                     kv(text,'core1_tone_reachable') in (want_core1_gain,absent_new) and
                     kv(text,'core1_iq_reachable') in (want_core1_iq,absent_new) and
                     kv(text,'rccal_reachable')==want_rccal and
                     kv(text,'rccal_commit_reachable') in (want_rccal,absent_rccal))
        if stage in ('full-transaction','retained-state'):
            rf_scope=(rf_scope and kv(text,'requested_rev4_fault_transaction')=='0' and
                      kv(text,'requested_integration_transaction')=='1' and
                      kv(text,'requested_calibration_sequence')=='1' and
                      kv(text,'requested_normal_calibration')=='0')
            debug_scope=(debug_scope and kv(text,'integration_complete')=='1')
    else:
        rf_scope=(kv(text,'requested_internal_cal_tone')=='0' and kv(text,'requested_gain_search')=='0' and iq_calc in (None,'0') and kv(text,'requested_rccal')=='0')
        debug_scope=(kv(text,'gain_search_reachable') in (None,'0') and kv(text,'calibration_tone_reachable') in (None,'0') and kv(text,'iq_calculation_reachable') in (None,'0') and kv(text,'core1_phy_reachable') in (None,'0') and kv(text,'core1_radio_reachable') in (None,'0') and kv(text,'core1_gain_reachable') in (None,'0') and kv(text,'core1_tone_reachable') in (None,'0') and kv(text,'core1_iq_reachable') in (None,'0') and kv(text,'rccal_reachable') in (None,'0'))

    signal_keys=(
      'rxiq_fault_gain_classctl_before_tone','rxiq_fault_gain_classctl_after_tone','rxiq_fault_gain_classctl_after_est',
      'rxiq_fault_gain_samp_cmd_after_tone','rxiq_fault_gain_samp_stat_after_tone','rxiq_fault_gain_samp_stat_after_est',
      'rxiq_fault_gain_samp_depcnt_after_tone','rxiq_fault_gain_samp_loopcnt_after_tone','rxiq_fault_gain_samp_waitcnt_after_tone',
      'rxiq_fault_gain_rfseqst_after_tone','rxiq_fault_gain_rfseqmode_after_tone',
      'rxiq_fault_gain_txgain_word','rxiq_fault_gain_tx_radio_gain_expected','rxiq_fault_gain_tx_dac_gain_expected',
      'rxiq_fault_gain_tx_bbmult_expected','rxiq_fault_gain_tx_afectl_over_live','rxiq_fault_gain_tx_dac_gain_live',
      'rxiq_fault_gain_tx_rfseq_gain_live','rxiq_fault_gain_tx_bbmult_word_live','rxiq_fault_gain_phy_rfseqca',
      'rxiq_fault_gain_phy_rfctl_over','rxiq_fault_gain_phy_rfctl_intc1','rxiq_fault_gain_phy_rfctl_intc2',
      'rxiq_fault_gain_phy_afectl_c1','rxiq_fault_gain_phy_afectl_c2','rxiq_fault_gain_phy_afectl_over1','rxiq_fault_gain_phy_afectl_over',
      'rxiq_fault_gain_radio_txmux','rxiq_fault_gain_radio_rxmux','rxiq_fault_gain_radio_lna_tune')
    signal_present=all(kv(text,k) not in (None,'missing') for k in signal_keys) if stage in deep else True
    wave_keys=('rxiq_fault_gain_tone_sample_count','rxiq_fault_gain_tone_sample_nonzero','rxiq_fault_gain_tone_i_nonzero','rxiq_fault_gain_tone_q_nonzero','rxiq_fault_gain_tone_sample_or','rxiq_fault_gain_tone_sample_xor','rxiq_fault_gain_tone_sample0')
    wave_present=all(kv(text,k) not in (None,'missing') for k in wave_keys) if stage in deep else True
    wave_count=iv(text,'rxiq_fault_gain_tone_sample_count',0); wave_nonzero=iv(text,'rxiq_fault_gain_tone_sample_nonzero',0)
    wave_i_nonzero=iv(text,'rxiq_fault_gain_tone_i_nonzero',0); wave_q_nonzero=iv(text,'rxiq_fault_gain_tone_q_nonzero',0); wave_or=iv(text,'rxiq_fault_gain_tone_sample_or',0)
    waveform_good=(wave_present and wave_count in (160,320) and wave_nonzero>0 and wave_i_nonzero>0 and wave_q_nonzero>0 and wave_or!=0)

    rfseqca_live=iv(text,'rxiq_fault_gain_phy_rfseqca'); rfseqca_expected=0x2112 if stage in deep else None
    rfseqca_match=(rfseqca_live==rfseqca_expected) if rfseqca_expected is not None and rfseqca_live is not None else None
    rfseqca_declared=kv(text,'rxiq_fault_gain_phy_rfseqca_expected'); rfseqca_gate_declared=kv(text,'rxiq_fault_gain_phy_rfseqca_gate')
    trace_count=iv(text,'rxiq_fault_gain_trace_count',iv(text,'gain_trace_count',0)); zero_continue_declared=kv(text,'rxiq_fault_gain_zero_normalized_continue_gate')
    zero_continue_gate=(not current_zero_continue_policy or stage not in deep or (trace_count>1 and zero_continue_declared=='1'))

    iqcalc_keys=('rxiq_fault_iqcalc_tone_rc','rxiq_fault_iqcalc_tone_sample_count','rxiq_fault_iqcalc_tone_sample_nonzero','rxiq_fault_iqcalc_tone_i_nonzero','rxiq_fault_iqcalc_tone_q_nonzero','rxiq_fault_iqcalc_iqest_cmd','rxiq_fault_iqcalc_iqest_start_stuck','rxiq_fault_iqcalc_i_pwr','rxiq_fault_iqcalc_q_pwr','rxiq_fault_iqcalc_iq_prod','rxiq_fault_iqcalc_error','rxiq_fault_iqcalc_applied_mask','rxiq_fault_iqcalc_candidate_a0','rxiq_fault_iqcalc_candidate_b0')
    iqcalc_present=all(kv(text,k) not in (None,'missing') for k in iqcalc_keys) if stage in iq_stages else True
    iqcalc_tone_rc=iv(text,'rxiq_fault_iqcalc_tone_rc'); iqcalc_start=iv(text,'rxiq_fault_iqcalc_iqest_start_stuck')
    iqcalc_i=iv(text,'rxiq_fault_iqcalc_i_pwr',0); iqcalc_q=iv(text,'rxiq_fault_iqcalc_q_pwr',0); iqcalc_error=iv(text,'rxiq_fault_iqcalc_error'); iqcalc_mask=iv(text,'rxiq_fault_iqcalc_applied_mask')
    iqcalc_wave_count=iv(text,'rxiq_fault_iqcalc_tone_sample_count',0); iqcalc_wave_i=iv(text,'rxiq_fault_iqcalc_tone_i_nonzero',0); iqcalc_wave_q=iv(text,'rxiq_fault_iqcalc_tone_q_nonzero',0)
    iqcalc_gate=(stage not in iq_stages or (iqcalc_present and kv(text,'rxiq_fault_iqcalc_gate')=='1' and iqcalc_tone_rc==0 and iqcalc_start==0 and iqcalc_error==0 and iqcalc_mask==1 and iqcalc_i+iqcalc_q>=2 and iqcalc_wave_count in (160,320) and iqcalc_wave_i>0 and iqcalc_wave_q>0))

    core1_phy_live=iv(text,'rxiq_fault_core1_phy_rfseqca'); core1_phy_expected=0x1221 if stage in core1_phy_stages else None
    core1_phy_match=(core1_phy_live==core1_phy_expected) if core1_phy_live is not None and core1_phy_expected is not None else None
    core1_phy_gate=(stage not in core1_phy_stages or (core1_phy_match is True and kv(text,'rxiq_fault_core1_phy_rfseqca_expected')=='0x1221' and kv(text,'rxiq_fault_core1_phy_rfseqca_gate')=='1'))
    core1_radio_txmux=iv(text,'rxiq_fault_core1_radio_txmux'); core1_radio_rxmux=iv(text,'rxiq_fault_core1_radio_rxmux'); core1_radio_lna=iv(text,'rxiq_fault_core1_radio_lna_tune')
    core1_radio_match=None
    if stage in core1_radio_stages and None not in (core1_radio_txmux,core1_radio_rxmux,core1_radio_lna):
        core1_radio_match=(core1_radio_txmux==0x0006 and core1_radio_rxmux==0x0006 and (core1_radio_lna & 0x00f0)==0)
    core1_radio_gate=(stage not in core1_radio_stages or (core1_radio_match is True and kv(text,'rxiq_fault_core1_radio_txmux_expected')=='0x0006' and kv(text,'rxiq_fault_core1_radio_rxmux_expected')=='0x0006' and kv(text,'rxiq_fault_core1_radio_lna_clear_mask')=='0x00f0' and kv(text,'rxiq_fault_core1_radio_gate')=='1'))

    # Separate point-10 core1 gain telemetry; do not infer it from core0 fields.
    c1_trace=iv(text,'rxiq_fault_core1_gain_trace_count',0); c1_opt_row=iv(text,'rxiq_fault_core1_gain_optimum_row',-1); c1_opt_power=iv(text,'rxiq_fault_core1_gain_optimum_power',0); c1_last_dir=iv(text,'rxiq_fault_core1_gain_last_dir',-1)
    c1_txrc=iv(text,'rxiq_fault_core1_gain_last_txpwr_rc'); c1_tonerc=iv(text,'rxiq_fault_core1_gain_last_tone_rc'); c1_start=iv(text,'rxiq_fault_core1_gain_iqest_start_stuck'); c1_fail=iv(text,'rxiq_fault_core1_gain_fail_reason')
    c1_i=iv(text,'rxiq_fault_core1_gain_i1_pwr',0); c1_q=iv(text,'rxiq_fault_core1_gain_q1_pwr',0); c1_power=iv(text,'rxiq_fault_core1_gain_core_power',0); c1_samp=iv(text,'rxiq_fault_core1_gain_samp_stat_after_tone')
    c1_wave_count=iv(text,'rxiq_fault_core1_gain_tone_sample_count',0); c1_wave_nonzero=iv(text,'rxiq_fault_core1_gain_tone_sample_nonzero',0); c1_wave_i=iv(text,'rxiq_fault_core1_gain_tone_i_nonzero',0); c1_wave_q=iv(text,'rxiq_fault_core1_gain_tone_q_nonzero',0)
    c1_exp_radio=iv(text,'rxiq_fault_core1_gain_tx_radio_gain_expected'); c1_live_radio=iv(text,'rxiq_fault_core1_gain_tx_rfseq_gain_live'); c1_exp_dac=iv(text,'rxiq_fault_core1_gain_tx_dac_gain_expected'); c1_live_dac=iv(text,'rxiq_fault_core1_gain_tx_dac_gain_live'); c1_exp_bb=iv(text,'rxiq_fault_core1_gain_tx_bbmult_expected'); c1_live_bb=iv(text,'rxiq_fault_core1_gain_tx_bbmult_word_live')
    c1_rfseqca=iv(text,'rxiq_fault_core1_gain_phy_rfseqca'); c1_txmux=iv(text,'rxiq_fault_core1_gain_radio_txmux'); c1_rxmux=iv(text,'rxiq_fault_core1_gain_radio_rxmux'); c1_lna=iv(text,'rxiq_fault_core1_gain_radio_lna_tune')
    c1_gain_match=(None not in (c1_exp_radio,c1_live_radio,c1_exp_dac,c1_live_dac,c1_exp_bb,c1_live_bb) and c1_exp_radio==c1_live_radio and c1_exp_dac==c1_live_dac and c1_exp_bb==((c1_live_bb >> 8) & 0xff))
    c1_route_match=(None not in (c1_rfseqca,c1_txmux,c1_rxmux,c1_lna) and c1_rfseqca==0x1221 and c1_txmux==0x0006 and c1_rxmux==0x0006 and (c1_lna & 0x00f0)==0)
    c1_zero_optimum_cross=(c1_opt_power==0 and c1_trace>=2 and c1_last_dir==1 and c1_power>10000)
    c1_optimum_valid=(c1_opt_power>0 or (policy in (newpol,integrationpol) and c1_zero_optimum_cross))
    core1_gain_gate=(stage not in core1_gain_stages or (kv(text,'rxiq_fault_core1_gain_gate')=='1' and iv(text,'rxiq_fault_core1_gain_rx_core')==1 and iv(text,'rxiq_fault_core1_gain_tx_core')==0 and c1_trace>=1 and 0<=c1_opt_row<=5 and c1_optimum_valid and c1_txrc==0 and c1_tonerc==0 and c1_start==0 and c1_fail==0 and c1_i+c1_q>0 and c1_power>0 and c1_samp is not None and bool(c1_samp & 1) and c1_wave_count==160 and c1_wave_nonzero>0 and c1_wave_i>0 and c1_wave_q>0 and c1_gain_match and c1_route_match))

    c1iq_tone_rc=iv(text,'rxiq_fault_core1_iqcalc_tone_rc'); c1iq_start=iv(text,'rxiq_fault_core1_iqcalc_iqest_start_stuck')
    c1iq_i=iv(text,'rxiq_fault_core1_iqcalc_i_pwr',0); c1iq_q=iv(text,'rxiq_fault_core1_iqcalc_q_pwr',0); c1iq_error=iv(text,'rxiq_fault_core1_iqcalc_error'); c1iq_mask=iv(text,'rxiq_fault_core1_iqcalc_applied_mask')
    c1iq_wave_count=iv(text,'rxiq_fault_core1_iqcalc_tone_sample_count',0); c1iq_wave_nonzero=iv(text,'rxiq_fault_core1_iqcalc_tone_sample_nonzero',0); c1iq_wave_i=iv(text,'rxiq_fault_core1_iqcalc_tone_i_nonzero',0); c1iq_wave_q=iv(text,'rxiq_fault_core1_iqcalc_tone_q_nonzero',0)
    c1iq_present=all(kv(text,k) not in (None,'missing') for k in ('rxiq_fault_core1_iqcalc_tone_rc','rxiq_fault_core1_iqcalc_tone_sample_count','rxiq_fault_core1_iqcalc_tone_sample_nonzero','rxiq_fault_core1_iqcalc_tone_i_nonzero','rxiq_fault_core1_iqcalc_tone_q_nonzero','rxiq_fault_core1_iqcalc_iqest_cmd','rxiq_fault_core1_iqcalc_iqest_start_stuck','rxiq_fault_core1_iqcalc_i_pwr','rxiq_fault_core1_iqcalc_q_pwr','rxiq_fault_core1_iqcalc_iq_prod','rxiq_fault_core1_iqcalc_error','rxiq_fault_core1_iqcalc_applied_mask','rxiq_fault_core1_iqcalc_candidate_a1','rxiq_fault_core1_iqcalc_candidate_b1')) if stage in core1_iq_stages else True
    core1_iq_gate=(stage not in core1_iq_stages or (c1iq_present and kv(text,'rxiq_fault_core1_iqcalc_gate')=='1' and c1iq_tone_rc==0 and c1iq_start==0 and c1iq_error==0 and c1iq_mask==2 and c1iq_i+c1iq_q>=2 and c1iq_wave_count==160 and c1iq_wave_nonzero>0 and c1iq_wave_i>0 and c1iq_wave_q>0))

    # v1.14.55/v1.14.56 point-13 RCCAL: independently validate kernel and target gates.
    rccal_candidate=iv(text,'rxiq_fault_rccal_candidate',-1); rccal_best=iv(text,'rxiq_fault_rccal_best_raw',-1)
    rccal_iter=iv(text,'rxiq_fault_rccal_sweep_iterations',0); rccal_spur=iv(text,'rxiq_fault_rccal_dac_spur')
    rccal_gain_trace=iv(text,'rxiq_fault_rccal_gain_trace_count',0); rccal_gain_power=iv(text,'rxiq_fault_rccal_gain_optimum_power',0)
    rccal_gain_tone_rc=iv(text,'rxiq_fault_rccal_gain_tone_rc'); rccal_gain_count=iv(text,'rxiq_fault_rccal_gain_tone_sample_count',0)
    rccal_gain_i=iv(text,'rxiq_fault_rccal_gain_tone_i_nonzero',0); rccal_gain_q=iv(text,'rxiq_fault_rccal_gain_tone_q_nonzero',0)
    rccal_gain_stat=iv(text,'rxiq_fault_rccal_gain_samp_stat'); rccal_gain_fail=iv(text,'rxiq_fault_rccal_gain_fail_reason')
    rccal_ref_rc=iv(text,'rxiq_fault_rccal_ref_tone_rc'); rccal_target_rc=iv(text,'rxiq_fault_rccal_target_tone_rc')
    rccal_ref_count=iv(text,'rxiq_fault_rccal_ref_sample_count',0); rccal_target_count=iv(text,'rxiq_fault_rccal_target_sample_count',0)
    rccal_ref_i=iv(text,'rxiq_fault_rccal_ref_i_nonzero',0); rccal_ref_q=iv(text,'rxiq_fault_rccal_ref_q_nonzero',0)
    rccal_target_i=iv(text,'rxiq_fault_rccal_target_i_nonzero',0); rccal_target_q=iv(text,'rxiq_fault_rccal_target_q_nonzero',0)
    rccal_ref_vals=iv(text,'rxiq_fault_rccal_ref_iq_vals',0); rccal_target_vals=iv(text,'rxiq_fault_rccal_target_iq_vals',0); rccal_last_ratio=iv(text,'rxiq_fault_rccal_last_pwr_ratio'); rccal_target_ratio=iv(text,'rxiq_fault_rccal_target_pwr_ratio')
    rccal_start=iv(text,'rxiq_fault_rccal_iqest_start_stuck')
    rccal_sweep_decl=kv(text,'rxiq_fault_rccal_sweep_gate'); rccal_commit_decl=kv(text,'rxiq_fault_rccal_commit_gate')
    rccal_sweep_gate=(stage not in rccal_stages or (rccal_sweep_decl=='1' and rccal_gain_trace>0 and
        rccal_gain_tone_rc==0 and rccal_gain_count==160 and rccal_gain_i>0 and rccal_gain_q>0 and
        rccal_gain_stat is not None and bool(rccal_gain_stat & 1) and rccal_gain_fail==0 and rccal_spur==0 and
        rccal_ref_rc==0 and rccal_target_rc==0 and rccal_ref_count==160 and rccal_target_count==160 and
        rccal_ref_i>0 and rccal_ref_q>0 and rccal_target_i>0 and rccal_target_q>0 and rccal_ref_vals>0 and
        rccal_target_ratio==28606 and rccal_last_ratio is not None and rccal_last_ratio==((rccal_target_vals << 16)//rccal_ref_vals) and rccal_iter>=6 and 137<=rccal_best<=142 and rccal_candidate==rccal_best-128 and
        9<=rccal_candidate<=14 and rccal_start==0))
    def clamp(v,lo,hi): return max(lo,min(hi,v))
    exp_rx_lpc=(rccal_candidate|0x80) if rccal_candidate>=0 else None
    exp_rx_hpc=(clamp(((rccal_candidate-12)>>1)+10,0,31)|0x80) if rccal_candidate>=0 else None
    exp_tx_lpc=(clamp((rccal_candidate-12)+10,0,31)|0x80) if rccal_candidate>=0 else None
    rccal_commit_values=(iv(text,'rxiq_fault_rccal_expected_rx_lpc'),iv(text,'rxiq_fault_rccal_expected_rx_hpc'),iv(text,'rxiq_fault_rccal_expected_tx_lpc'),
        iv(text,'rxiq_fault_rccal_live_rx_lpc0'),iv(text,'rxiq_fault_rccal_live_rx_lpc1'),iv(text,'rxiq_fault_rccal_live_rx_hpc0'),iv(text,'rxiq_fault_rccal_live_rx_hpc1'),
        iv(text,'rxiq_fault_rccal_live_tx_lpc0'),iv(text,'rxiq_fault_rccal_live_tx_lpc1'))
    rccal_commit_gate=(stage not in rccal_stages or (rccal_commit_decl=='1' and None not in rccal_commit_values and
        rccal_commit_values[0]==exp_rx_lpc and rccal_commit_values[1]==exp_rx_hpc and rccal_commit_values[2]==exp_tx_lpc and
        rccal_commit_values[3]==exp_rx_lpc and rccal_commit_values[4]==exp_rx_lpc and
        rccal_commit_values[5]==exp_rx_hpc and rccal_commit_values[6]==exp_rx_hpc and
        rccal_commit_values[7]==exp_tx_lpc and rccal_commit_values[8]==exp_tx_lpc))

    integration=stage in ('full-transaction','retained-state')
    retained=(stage=='retained-state')
    expected_primary=iv(text,'rxiq_fault_expected_primary_rc')
    primary_rc=iv(text,'rxiq_fault_primary_rc')
    integration_complete=iv(text,'rxiq_fault_integration_complete',0)
    integration_live=(iv(text,'rxiq_fault_integration_live_a0'),iv(text,'rxiq_fault_integration_live_b0'),
                      iv(text,'rxiq_fault_integration_live_a1'),iv(text,'rxiq_fault_integration_live_b1'))
    integration_candidates=(iv(text,'rxiq_fault_iqcalc_candidate_a0'),iv(text,'rxiq_fault_iqcalc_candidate_b0'),
                            iv(text,'rxiq_fault_core1_iqcalc_candidate_a1'),iv(text,'rxiq_fault_core1_iqcalc_candidate_b1'))
    integration_live_decl=kv(text,'rxiq_fault_integration_live_iq_gate')
    integration_target_decl=kv(text,'rxiq_fault_integration_gate')
    integration_live_gate=(not integration or (integration_complete==1 and integration_live_decl=='1' and
        integration_target_decl=='1' and None not in integration_live and None not in integration_candidates and
        integration_live==integration_candidates))
    natural_completion_gate=(not integration or (expected_primary==0 and primary_rc==0 and integration_complete==1))
    before_tuple=kv(text,'rxiq_fault_before_tuple')
    after_tuple=kv(text,'rxiq_fault_after_tuple')
    retained_decl=kv(text,'rxiq_fault_retained_state_verified')
    retained_target_decl=kv(text,'rxiq_fault_retained_state_gate')
    retained_iq_gate=(not retained or (retained_decl=='1' and retained_target_decl=='1' and
        kv(text,'rxiq_fault_rollback_verified')=='0' and after_tuple and None not in integration_candidates and
        after_tuple==','.join(str(x) for x in integration_candidates)))
    state_semantics_gate=(retained_iq_gate if retained else
        (kv(text,'rxiq_fault_rollback_verified')=='1' and bool(before_tuple) and before_tuple==after_tuple))

    gates={
      'policy':policy in policies,
      'country':kv(text,'rxiq_fault_country')=='CA','channel':kv(text,'rxiq_fault_channel')=='8',
      'frequency_request':kv(text,'rxiq_fault_frequency')=='2447','setfreq':kv(text,'rxiq_fault_setfreq_rc')=='0',
      'frequency':kv(text,'rxiq_fault_frequency')=='2447' and kv(text,'rxiq_fault_setfreq_rc')=='0' and kv(text,'rxiq_fault_reported_frequency')=='2447',
      'stage':expected is not None and kv(text,'rxiq_fault_expected_id')==expected and kv(text,'rxiq_fault_actual_id')==expected,
      'write':kv(text,'rxiq_fault_write_rc')=='0',
      'expected_cancel':integration or (bool(kv(text,'rxiq_fault_expected_cancel_rc')) and kv(text,'rxiq_fault_primary_rc')==kv(text,'rxiq_fault_expected_cancel_rc')),
      'natural_completion':natural_completion_gate,'integration_complete':(not integration or integration_complete==1),'integration_live_iq':integration_live_gate,
      'cleanup_rc':kv(text,'rxiq_fault_cleanup_rc')=='0','cleanup_mask':kv(text,'rxiq_fault_cleanup_fail_mask')=='0x00000000',
      'mac_suspend':kv(text,'rxiq_fault_mac_suspend_verified')=='1','mac_resume':kv(text,'rxiq_fault_mac_resume_verified')=='1','rollback':state_semantics_gate,
      'iq_match':state_semantics_gate,'retained_state':retained_iq_gate,
      'rf_scope':rf_scope,'debugfs_scope':debug_scope,
      'signal_path_telemetry':(not current_signal_policy) or signal_present,
      'corrected_sample_pack':(not current_pack_policy) or waveform_good,
      'rfseqca_bitmap':(not current_rfseqca_policy) or (rfseqca_match is True and rfseqca_declared=='0x2112' and rfseqca_gate_declared=='1'),
      'zero_normalized_continue':zero_continue_gate,'iqcalc':iqcalc_gate,'core1_phy_setup':core1_phy_gate,'core1_radio_setup':core1_radio_gate,'core1_gain':core1_gain_gate,'core1_iq':core1_iq_gate,'rccal_sweep':rccal_sweep_gate,'rccal_commit':rccal_commit_gate,
      'no_80211_tx':kv(text,'requested_scan')=='0' and kv(text,'requested_association')=='0' and kv(text,'requested_ap')=='0' and kv(text,'requested_user_tx')=='0' and kv(text,'requested_frame_injection')=='0',
      'no_persistence':kv(text,'requested_persistent_write')=='0','unassociated':kv(text,'rxiq_fault_associated')=='0' and kv(text,'rxiq_fault_station_count')=='0',
      'safe_phy_readback':'PHY/RADIO register access with enabled MAC.' not in text,'capture':kv(text,'rxiq_fault_capture_complete')=='1'}
    passed=all(gates.values()); transaction_fields=any(kv(text,k) is not None for k in ('rxiq_fault_write_rc','rxiq_fault_primary_rc','rxiq_fault_cleanup_rc'))
    fail_reason=iv(text,'rxiq_fault_gain_fail_reason',iv(text,'gain_fail_reason')); start_stuck=iv(text,'rxiq_fault_gain_iqest_start_stuck',iv(text,'gain_iqest_start_stuck')); primary=iv(text,'rxiq_fault_primary_rc')
    raw=[iv(text,k,0) for k in ('rxiq_fault_gain_i0_pwr','rxiq_fault_gain_q0_pwr','rxiq_fault_gain_i1_pwr','rxiq_fault_gain_q1_pwr')]; core_power=iv(text,'rxiq_fault_gain_core_power',0)
    reason_names={0:'none',1:'row-range',2:'gmval-unsupported',3:'txpower',4:'tone',5:'iqest-timeout',6:'zero-power',7:'optimum-range'}
    samp_stat=iv(text,'rxiq_fault_gain_samp_stat_after_tone'); sample_running=(samp_stat is not None and bool(samp_stat & 0x1))
    exp_radio=iv(text,'rxiq_fault_gain_tx_radio_gain_expected'); exp_dac=iv(text,'rxiq_fault_gain_tx_dac_gain_expected'); exp_bb=iv(text,'rxiq_fault_gain_tx_bbmult_expected'); live_over=iv(text,'rxiq_fault_gain_tx_afectl_over_live'); live_dac=iv(text,'rxiq_fault_gain_tx_dac_gain_live'); live_rfseq=iv(text,'rxiq_fault_gain_tx_rfseq_gain_live'); live_bbword=iv(text,'rxiq_fault_gain_tx_bbmult_word_live')
    tx_gain_match=None
    if None not in (exp_radio,exp_dac,exp_bb,live_over,live_dac,live_rfseq,live_bbword): tx_gain_match=bool(live_over & 0x0100) and live_dac==exp_dac and live_rfseq==exp_radio and (live_bbword & 0xff)==exp_bb
    txmux=iv(text,'rxiq_fault_gain_radio_txmux'); rxmux=iv(text,'rxiq_fault_gain_radio_rxmux'); lna=iv(text,'rxiq_fault_gain_radio_lna_tune'); route_match=None
    if None not in (txmux,rxmux,lna): route_match=(txmux==0x0006 and rxmux==0x0006 and (lna & 0x00f0)==0)
    zero_failure=(stage=='core0-gain' and primary==-5 and fail_reason==6 and start_stuck==0 and core_power==0); raw_zero=all(x==0 for x in raw)

    if not gates['setfreq']: finding='precondition-channel-tune-failed'
    elif not transaction_fields: finding='transaction-not-captured'
    elif passed and stage=='retained-state': finding='retained-live-calibration-state-qualified'
    elif passed and stage=='full-transaction': finding='full-transaction-natural-complete-rollback-qualified'
    elif passed and stage=='rccal-commit': finding='rccal-sweep-commit-rollback-qualified'
    elif passed and stage=='core1-iq': finding='core1-iq-rollback-qualified'
    elif passed and stage=='core1-gain': finding='core1-gain-rollback-qualified'
    elif passed and stage=='core1-radio': finding='core1-radio-rollback-qualified'
    elif passed and stage=='core1-phy': finding='core1-phy-rollback-qualified'
    elif passed and stage=='core0-iq': finding='core0-iq-rollback-qualified'
    elif passed and stage=='core0-gain': finding='core0-gain-rollback-qualified'
    elif passed: finding='pre-tone-rollback-qualified'
    elif stage in ('full-transaction','retained-state') and not natural_completion_gate: finding=f'{stage}-natural-completion-failed'
    elif stage=='retained-state' and not retained_iq_gate: finding='retained-live-iq-mismatch'
    elif stage=='full-transaction' and not integration_live_gate: finding='full-transaction-live-iq-mismatch'
    elif stage=='rccal-commit' and policy==prevpol and c1_fail==7 and c1_trace>=2 and c1_opt_power==0 and c1_last_dir==1 and c1_power>10000: finding='core1-gain-stock-zero-optimum-rejected'
    elif stage=='rccal-commit' and any(x not in (None,0) for x in (rccal_gain_tone_rc,rccal_ref_rc,rccal_target_rc)): finding='rccal-dac-tone-failure'
    elif stage=='rccal-commit' and rccal_gain_fail not in (None,0): finding=f'rccal-gain-error-{rccal_gain_fail}'
    elif stage=='rccal-commit' and rccal_start==1: finding='rccal-estimator-timeout'
    elif stage=='rccal-commit' and not rccal_sweep_gate: finding='rccal-sweep-invalid'
    elif stage=='rccal-commit' and not rccal_commit_gate: finding='rccal-commit-mismatch'
    elif stage=='rccal-commit': finding='rccal-transaction-error'
    elif stage in core1_gain_stages and c1_fail==7 and c1_trace>1 and c1_power==0: finding='core1-gain-no-usable-normalized-power-after-full-search'
    elif stage in core1_gain_stages and c1_route_match is False: finding='core1-gain-route-mismatch'
    elif stage in core1_gain_stages and (c1_wave_count!=160 or c1_wave_nonzero<=0 or c1_wave_i<=0 or c1_wave_q<=0): finding='core1-gain-waveform-error'
    elif stage=='core1-iq' and c1iq_tone_rc not in (None,0): finding='core1-iq-dedicated-tone-error'
    elif stage=='core1-iq' and c1iq_start==1: finding='core1-iq-estimator-timeout'
    elif stage=='core1-iq' and c1iq_error not in (None,0): finding=f'core1-iq-calc-error-{c1iq_error}'
    elif stage=='core1-iq' and c1iq_mask!=2: finding='core1-iq-coefficient-not-applied'
    elif stage=='core1-iq': finding='core1-iq-transaction-error'
    elif stage=='core1-gain': finding='core1-gain-control-error'
    elif stage=='core0-gain' and primary==-5 and fail_reason==5 and start_stuck==1: finding='core0-gain-estimator-timeout'
    elif stage=='core0-gain' and current_rfseqca_policy and rfseqca_match is False: finding='core0-gain-rfseqca-bitmap-mismatch'
    elif zero_failure and current_phase_policy and wave_present and wave_count in (160,320) and wave_nonzero>0 and wave_i_nonzero>0 and wave_q_nonzero==0: finding='core0-gain-waveform-not-rotating'
    elif zero_failure and current_pack_policy and not waveform_good: finding='core0-gain-corrected-waveform-not-loaded'
    elif zero_failure and current_signal_policy and samp_stat is not None and not sample_running: finding='core0-gain-sample-playback-not-running'
    elif zero_failure and current_signal_policy and tx_gain_match is False: finding='core0-gain-tx-gain-programming-mismatch'
    elif zero_failure and current_signal_policy and route_match is False: finding='core0-gain-loopback-route-mismatch'
    elif zero_failure and current_rfseqca_policy and waveform_good and sample_running and tx_gain_match is True and route_match is True and rfseqca_match is True and raw_zero: finding='core0-gain-zero-after-rfseqca-correction'
    elif zero_failure and current_pack_policy and waveform_good and sample_running and tx_gain_match is True and route_match is True and raw_zero: finding='core0-gain-zero-after-corrected-waveform'
    elif zero_failure and policy=='v1.14.45-channel8-core0-gain-signal-path-telemetry-rollback-only' and sample_running and tx_gain_match is True and route_match is True and raw_zero: finding='core0-gain-estimator-zero-with-playback-active'
    elif zero_failure and raw_zero: finding='core0-gain-zero-power'
    elif zero_failure: finding='core0-gain-rounded-zero-power'
    elif stage=='core0-gain' and current_zero_continue_policy and fail_reason==7 and trace_count>1 and core_power==0: finding='core0-gain-no-usable-normalized-power-after-full-search'
    elif stage=='core1-radio' and core1_radio_match is False: finding='core1-radio-setup-mismatch'
    elif stage=='core1-radio': finding='core1-radio-transaction-error'
    elif stage=='core1-phy' and core1_phy_match is False: finding='core1-phy-rfseqca-bitmap-mismatch'
    elif stage=='core1-phy': finding='core1-phy-transaction-error'
    elif stage=='core0-iq' and iqcalc_tone_rc not in (None,0): finding='core0-iq-dedicated-tone-error'
    elif stage=='core0-iq' and iqcalc_start==1: finding='core0-iq-estimator-timeout'
    elif stage=='core0-iq' and iqcalc_error not in (None,0): finding=f'core0-iq-calc-error-{iqcalc_error}'
    elif stage=='core0-iq' and iqcalc_mask!=1: finding='core0-iq-coefficient-not-applied'
    elif stage=='core0-iq': finding='core0-iq-transaction-error'
    elif stage=='core0-gain': finding='core0-gain-control-error'
    else: finding='transaction-or-rollback-failed'

    obj={'schema':'rv220w-b43-rxiq-fault-v17','stage':stage,'finding':finding,'transaction_fields_present':transaction_fields,'gain_fail_reason':reason_names.get(fail_reason,'unknown'),'sample_playback_running':sample_running if samp_stat is not None else None,'tx_gain_programming_match':tx_gain_match,'loopback_route_match':route_match,'rfseqca_expected':f'0x{rfseqca_expected:04x}' if rfseqca_expected is not None else None,'rfseqca_live':f'0x{rfseqca_live:04x}' if rfseqca_live is not None else None,'rfseqca_bitmap_match':rfseqca_match,'corrected_waveform_loaded':waveform_good if current_pack_policy else None,'core1_phy_rfseqca_live':f'0x{core1_phy_live:04x}' if core1_phy_live is not None else None,'core1_phy_rfseqca_expected':'0x1221' if stage in core1_phy_stages else None,'core1_phy_rfseqca_match':core1_phy_match,'core1_radio_setup_match':core1_radio_match,'core1_gain_programming_match':c1_gain_match,'core1_gain_route_match':c1_route_match,'core1_gain_zero_optimum_threshold_cross':c1_zero_optimum_cross,'core1_iq_candidate_a1':iv(text,'rxiq_fault_core1_iqcalc_candidate_a1'),'core1_iq_candidate_b1':iv(text,'rxiq_fault_core1_iqcalc_candidate_b1'),'rccal_candidate':rccal_candidate if stage in rccal_stages else None,'rccal_best_raw':rccal_best if stage in rccal_stages else None,'rccal_sweep_iterations':rccal_iter if stage in rccal_stages else None,'rccal_expected_commit':{'rx_lpc':exp_rx_lpc,'rx_hpc':exp_rx_hpc,'tx_lpc':exp_tx_lpc} if stage in rccal_stages else None,'integration_complete':integration_complete if integration else None,'integration_live_iq':list(integration_live) if integration else None,'integration_expected_iq':list(integration_candidates) if integration else None,'retained_state_verified':retained_decl if retained else None,'gates':gates,'passed':passed}
    scope_text=('complete hardware-qualified transaction reaches natural success and retains only live IQ/RCCAL calibration in RAM after transient cleanup; normal automatic/persistent calibration blocked' if stage=='retained-state' else ('complete hardware-qualified two-core gain/IQ + RCCAL transaction reaches natural success, captures final live coefficients/commit, then exact rollback; normal active/persistent calibration blocked' if stage=='full-transaction' else ('hardware-qualified two-core gain/IQ path, then vendor DAC-test RCCAL gain + 3/9.5 MHz RC sweep + derived non-IPA mirrored commit; normal calibration blocked' if stage=='rccal-commit' else ('qualified path through core1 radio, then combined core1 gain search/internal corrected tone + dedicated corrected core1 IQ tone/16384-sample A1/B1 calculation; RCCAL blocked' if stage=='core1-iq' else ('qualified core0 gain/IQ + core1 PHY/radio, then core1 gain search/internal corrected tone only; core1 dedicated IQ and RCCAL blocked' if stage=='core1-gain' else ('qualified core0 gain + dedicated IQ calculation + core1 PHY, then core1 BCM2056 radio setup only; core1 gain/tone/IQ and RCCAL blocked' if stage=='core1-radio' else ('qualified core0 gain + dedicated IQ calculation, then core1 PHY setup only; core1 radio/gain/tone/IQ and RCCAL blocked' if stage=='core1-phy' else ('core0 gain search + dedicated corrected IQ tone + 16384-sample explicit coefficient calculation expected; core1 and RCCAL blocked' if stage=='core0-iq' else ('internal calibration tone + core0 gain search expected; dedicated IQ calculation and RCCAL blocked' if stage=='core0-gain' else 'pre-tone; gain search, internal calibration tone, IQ calculation and RCCAL blocked')))))))))
    lines=['RV220W b43 rev4 staged RX-IQ rollback fault analysis',
      f"stage: {stage or '?'} ({'PASS' if expected is not None and kv(text,'rxiq_fault_expected_id')==expected else 'FAIL'})",
      f"channel tune: {kv(text,'rxiq_fault_country') or '?'} / ch{kv(text,'rxiq_fault_channel') or '?'} / requested={kv(text,'rxiq_fault_frequency') or '?'} MHz / rc={kv(text,'rxiq_fault_setfreq_rc') or '?'} / reported={kv(text,'rxiq_fault_reported_frequency') or '?'} MHz ({'PASS' if gates['country'] and gates['channel'] and gates['frequency'] else 'FAIL'})",
      f'finding: {finding}',(f"natural completion: expected={kv(text,'rxiq_fault_expected_primary_rc') or '?'} primary_rc={kv(text,'rxiq_fault_primary_rc') or '?'} ({'PASS' if gates['natural_completion'] else 'FAIL'})" if integration else f"injected cancellation: expected={kv(text,'rxiq_fault_expected_cancel_rc') or '?'} primary_rc={kv(text,'rxiq_fault_primary_rc') or '?'} ({'PASS' if gates['expected_cancel'] else 'FAIL'})"),
      f"cleanup: rc={kv(text,'rxiq_fault_cleanup_rc') or '?'} mask={kv(text,'rxiq_fault_cleanup_fail_mask') or '?'} rollback={kv(text,'rxiq_fault_rollback_verified') or '?'} retained={kv(text,'rxiq_fault_retained_state_verified') or '?'} ({'PASS' if gates['cleanup_rc'] and gates['cleanup_mask'] and gates['rollback'] else 'FAIL'})",
      f"MAC suspend/resume: {kv(text,'rxiq_fault_mac_suspend_verified') or '?'} / {kv(text,'rxiq_fault_mac_resume_verified') or '?'} ({'PASS' if gates['mac_suspend'] and gates['mac_resume'] else 'FAIL'})",
      f"IQ before/after: {kv(text,'rxiq_fault_before_tuple') or '?'} / {kv(text,'rxiq_fault_after_tuple') or '?'} ({'PASS' if gates['iq_match'] else 'FAIL'})",
      f"gain telemetry: iter={kv(text,'rxiq_fault_gain_trace_count') or kv(text,'gain_trace_count') or '?'} row={kv(text,'rxiq_fault_gain_last_row') or kv(text,'gain_last_row') or '?'} dir={kv(text,'rxiq_fault_gain_last_dir') or kv(text,'gain_last_dir') or '?'} txidx={kv(text,'rxiq_fault_gain_last_txpwrindex') or kv(text,'gain_last_txpwrindex') or '?'} txrc={kv(text,'rxiq_fault_gain_last_txpwr_rc') or kv(text,'gain_last_txpwr_rc') or '?'} tonerc={kv(text,'rxiq_fault_gain_last_tone_rc') or kv(text,'gain_last_tone_rc') or '?'} iqcmd={kv(text,'rxiq_fault_gain_last_iqest_cmd') or kv(text,'gain_last_iqest_cmd') or '?'} start_stuck={start_stuck if start_stuck is not None else '?'} fail={reason_names.get(fail_reason,'?')}",
      f"raw estimator: i0={raw[0]} q0={raw[1]} i1={raw[2]} q1={raw[3]} selected_power={core_power}",
      f"tone samples: count={wave_count} nonzero={wave_nonzero} i_nonzero={wave_i_nonzero} q_nonzero={wave_q_nonzero} sample0={kv(text,'rxiq_fault_gain_tone_sample0') or '?'} or={kv(text,'rxiq_fault_gain_tone_sample_or') or '?'} xor={kv(text,'rxiq_fault_gain_tone_sample_xor') or '?'} corrected={waveform_good if current_pack_policy else 'historical'}",
      f"sample path: class={kv(text,'rxiq_fault_gain_classctl_before_tone') or '?'}->{kv(text,'rxiq_fault_gain_classctl_after_tone') or '?'}->{kv(text,'rxiq_fault_gain_classctl_after_est') or '?'} samp_cmd={kv(text,'rxiq_fault_gain_samp_cmd_after_tone') or '?'} samp_stat={kv(text,'rxiq_fault_gain_samp_stat_after_tone') or '?'}->{kv(text,'rxiq_fault_gain_samp_stat_after_est') or '?'} running={sample_running if samp_stat is not None else '?'}",
      f"TX gain path: table={kv(text,'rxiq_fault_gain_txgain_word') or '?'} expected_radio={kv(text,'rxiq_fault_gain_tx_radio_gain_expected') or '?'} live_radio={kv(text,'rxiq_fault_gain_tx_rfseq_gain_live') or '?'} expected_dac={kv(text,'rxiq_fault_gain_tx_dac_gain_expected') or '?'} live_dac={kv(text,'rxiq_fault_gain_tx_dac_gain_live') or '?'} expected_bb={kv(text,'rxiq_fault_gain_tx_bbmult_expected') or '?'} live_bbword={kv(text,'rxiq_fault_gain_tx_bbmult_word_live') or '?'} match={tx_gain_match if tx_gain_match is not None else '?'}",
      f"RFSEQCA bitmap: live={kv(text,'rxiq_fault_gain_phy_rfseqca') or '?'} expected={rfseqca_declared or (f'0x{rfseqca_expected:04x}' if rfseqca_expected is not None else '?')} match={rfseqca_match if rfseqca_match is not None else '?'}",
      f"zero-normalized continuation: trace_count={trace_count} gate={zero_continue_declared or '?'} ({'PASS' if gates['zero_normalized_continue'] else 'FAIL'})",
      f"loopback path: txmux={kv(text,'rxiq_fault_gain_radio_txmux') or '?'} rxmux={kv(text,'rxiq_fault_gain_radio_rxmux') or '?'} lna_tune={kv(text,'rxiq_fault_gain_radio_lna_tune') or '?'} match={route_match if route_match is not None else '?'}",
      f"IQ calc: tone_rc={kv(text,'rxiq_fault_iqcalc_tone_rc') or '?'} tone_count={kv(text,'rxiq_fault_iqcalc_tone_sample_count') or '?'} i/q_nonzero={kv(text,'rxiq_fault_iqcalc_tone_i_nonzero') or '?'}/{kv(text,'rxiq_fault_iqcalc_tone_q_nonzero') or '?'} iqest_cmd={kv(text,'rxiq_fault_iqcalc_iqest_cmd') or '?'} start_stuck={iqcalc_start if iqcalc_start is not None else '?'} raw_i/q/iq={iqcalc_i}/{iqcalc_q}/{kv(text,'rxiq_fault_iqcalc_iq_prod') or '?'} error={iqcalc_error if iqcalc_error is not None else '?'} mask={kv(text,'rxiq_fault_iqcalc_applied_mask') or '?'} candidate={kv(text,'rxiq_fault_iqcalc_candidate_a0') or '?'},{kv(text,'rxiq_fault_iqcalc_candidate_b0') or '?'} gate={kv(text,'rxiq_fault_iqcalc_gate') or '?'} ({'PASS' if gates['iqcalc'] else 'FAIL'})" if stage in iq_stages else 'IQ calc: not requested',
      f"core1 PHY setup: RFSEQCA live={kv(text,'rxiq_fault_core1_phy_rfseqca') or '?'} expected={kv(text,'rxiq_fault_core1_phy_rfseqca_expected') or '?'} gate={kv(text,'rxiq_fault_core1_phy_rfseqca_gate') or '?'} ({'PASS' if gates['core1_phy_setup'] else 'FAIL'})" if stage in core1_phy_stages else 'core1 PHY setup: not requested',
      f"core1 radio setup: txmux={kv(text,'rxiq_fault_core1_radio_txmux') or '?'} rxmux={kv(text,'rxiq_fault_core1_radio_rxmux') or '?'} lna_tune={kv(text,'rxiq_fault_core1_radio_lna_tune') or '?'} gate={kv(text,'rxiq_fault_core1_radio_gate') or '?'} ({'PASS' if gates['core1_radio_setup'] else 'FAIL'})" if stage in core1_radio_stages else 'core1 radio setup: not requested',
      f"core1 gain: iter={c1_trace} optimum_row={c1_opt_row} optimum_power={c1_opt_power} last_dir={c1_last_dir} zero_opt_cross={c1_zero_optimum_cross} i1/q1={c1_i}/{c1_q} selected={c1_power} txrc={c1_txrc if c1_txrc is not None else '?'} tonerc={c1_tonerc if c1_tonerc is not None else '?'} start_stuck={c1_start if c1_start is not None else '?'} fail={reason_names.get(c1_fail,'?')} RFSEQCA={kv(text,'rxiq_fault_core1_gain_phy_rfseqca') or '?'} txmux/rxmux={kv(text,'rxiq_fault_core1_gain_radio_txmux') or '?'}/{kv(text,'rxiq_fault_core1_gain_radio_rxmux') or '?'} gate={kv(text,'rxiq_fault_core1_gain_gate') or '?'} ({'PASS' if gates['core1_gain'] else 'FAIL'})" if stage in core1_gain_stages else 'core1 gain: not requested',
      f"core1 IQ calc: tone_rc={c1iq_tone_rc if c1iq_tone_rc is not None else '?'} tone_count={c1iq_wave_count} i/q_nonzero={c1iq_wave_i}/{c1iq_wave_q} iqest_cmd={kv(text,'rxiq_fault_core1_iqcalc_iqest_cmd') or '?'} start_stuck={c1iq_start if c1iq_start is not None else '?'} raw_i/q/iq={c1iq_i}/{c1iq_q}/{kv(text,'rxiq_fault_core1_iqcalc_iq_prod') or '?'} error={c1iq_error if c1iq_error is not None else '?'} mask={kv(text,'rxiq_fault_core1_iqcalc_applied_mask') or '?'} candidate={kv(text,'rxiq_fault_core1_iqcalc_candidate_a1') or '?'},{kv(text,'rxiq_fault_core1_iqcalc_candidate_b1') or '?'} gate={kv(text,'rxiq_fault_core1_iqcalc_gate') or '?'} ({'PASS' if gates['core1_iq'] else 'FAIL'})" if stage in core1_iq_stages else 'core1 IQ calc: not requested',
      f"RCCAL: dac_spur={rccal_spur if rccal_spur is not None else '?'} gain_iter={rccal_gain_trace} gain_power={rccal_gain_power} ref/target_tone_rc={rccal_ref_rc if rccal_ref_rc is not None else '?'}/{rccal_target_rc if rccal_target_rc is not None else '?'} ref/target_samples={rccal_ref_count}/{rccal_target_count} ref_norm={rccal_ref_vals} ratio={kv(text,'rxiq_fault_rccal_last_pwr_ratio') or '?'} target_ratio={rccal_target_ratio if rccal_target_ratio is not None else '?'} iterations={rccal_iter} best_raw={rccal_best} candidate={rccal_candidate} fallback={kv(text,'rxiq_fault_rccal_fallback') or '?'} sweep_gate={rccal_sweep_decl or '?'} commit_expected={exp_rx_lpc if exp_rx_lpc is not None else '?'}/{exp_rx_hpc if exp_rx_hpc is not None else '?'}/{exp_tx_lpc if exp_tx_lpc is not None else '?'} commit_gate={rccal_commit_decl or '?'} ({'PASS' if gates['rccal_sweep'] and gates['rccal_commit'] else 'FAIL'})" if stage in rccal_stages else 'RCCAL: not requested',
      f"integration live IQ: complete={integration_complete} live={integration_live} expected_candidates={integration_candidates} kernel_gate={integration_live_decl or '?'} target_gate={integration_target_decl or '?'} ({'PASS' if gates['integration_complete'] and gates['integration_live_iq'] else 'FAIL'})" if integration else 'integration live IQ: not requested',
      f"RF scope: {scope_text} ({'PASS' if gates['rf_scope'] and gates['debugfs_scope'] else 'FAIL'})",
      f"802.11 TX/scan/assoc/AP/injection blocked: {'PASS' if gates['no_80211_tx'] else 'FAIL'}; persistent writes: {'PASS' if gates['no_persistence'] else 'FAIL'}; enabled-MAC PHY readback absent: {'PASS' if gates['safe_phy_readback'] else 'FAIL'}",
      f"overall: {'PASS' if passed else 'FAIL'}"]
    if a.json_out: Path(a.json_out).write_text(json.dumps(obj,indent=2,sort_keys=True)+'\n')
    if a.text_out: Path(a.text_out).write_text('\n'.join(lines)+'\n')
    print('\n'.join(lines)); return 0 if passed else 2
if __name__=='__main__': raise SystemExit(main())
