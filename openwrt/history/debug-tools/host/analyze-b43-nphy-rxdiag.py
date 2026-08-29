#!/usr/bin/env python3
"""Analyze RV220W b43 N-PHY fixed-channel receive/IQ/calibration-state evidence."""
from __future__ import annotations
import argparse, json, re
from pathlib import Path

FREQS={
 '2g':[2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462],
 '5g':[5180,5200,5220,5240],
}
IQ_KEYS=(
 'status','phy_rev','radio_ver','radio_rev','channel','radio_on','transfer',
 'bbcfg','bandctl','phy_channel_reg','classctl','rfseqca','rfseqmode','rfseqst',
 'rfctl_cmd','rfctl_over','rfctl_intc1','rfctl_intc2','rfctl_rssio1','rfctl_rssio2',
 'afectl_c1','afectl_c2','afectl_over1','afectl_over','c1_initgain','c2_initgain','c1_clip1','c2_clip1',
 'radio2056_syn_com_ctrl','radio2056_syn_com_pu','radio2056_rx0_com_pu','radio2056_rx1_com_pu',
 'radio2056_rx0_lnaa_master','radio2056_rx1_lnaa_master','radio2056_rx0_lnag_master','radio2056_rx1_lnag_master',
 'radio2056_rx0_mixg_master','radio2056_rx1_mixg_master','radio2056_rx0_tia_master','radio2056_rx1_tia_master',
 'radio2056_rx0_lpf_master','radio2056_rx1_lpf_master',
 'iq_estimator_complete','iq_samples','iq_i0_pwr','iq_q0_pwr','iq_iq0_prod',
 'iq_i1_pwr','iq_q1_pwr','iq_iq1_prod','iq_core0_avg','iq_core1_avg',
 'rx_iq_cal_rev3plus_implemented',
 # v1.14.25 inline fields retained for historical evidence compatibility.
 'rx_iq_live_a0_signed','rx_iq_live_b0_signed','rx_iq_live_a1_signed','rx_iq_live_b1_signed',
 'rx_iq_cache_2g_a0_signed','rx_iq_cache_2g_b0_signed','rx_iq_cache_2g_a1_signed','rx_iq_cache_2g_b1_signed',
 'rx_iq_cache_5g_a0_signed','rx_iq_cache_5g_b0_signed','rx_iq_cache_5g_a1_signed','rx_iq_cache_5g_b1_signed',
 'iqcal_2g_center_freq','rssical_2g_center_freq','iqcal_5g_center_freq','rssical_5g_center_freq',
 'nphy_measure_hold','nphy_mute','nphy_perical','nphy_phyrxchain','nphy_hw_phyrxchain','nphy_hw_phytxchain',
)
SW_CAL_KEYS=(
 'rx_iq_cal_rev3plus_implemented',
 'rx_iq_cache_2g_a0_signed','rx_iq_cache_2g_b0_signed','rx_iq_cache_2g_a1_signed','rx_iq_cache_2g_b1_signed',
 'rx_iq_cache_5g_a0_signed','rx_iq_cache_5g_b0_signed','rx_iq_cache_5g_a1_signed','rx_iq_cache_5g_b1_signed',
 'iqcal_2g_center_freq','rssical_2g_center_freq','iqcal_5g_center_freq','rssical_5g_center_freq',
 'nphy_measure_hold','nphy_mute','nphy_perical','nphy_phyrxchain','nphy_hw_phyrxchain','nphy_hw_phytxchain',
)
INLINE_CAL_KEYS=SW_CAL_KEYS + ('rx_iq_live_a0_signed','rx_iq_live_b0_signed','rx_iq_live_a1_signed','rx_iq_live_b1_signed')

def kv(text,key):
 m=re.search(rf'^{re.escape(key)}=(.*)$',text,re.M); return m.group(1).strip() if m else None

def intval(v):
 if v is None: return None
 try: return int(v,0)
 except ValueError: return None

def parse_samples(block):
 parts=re.split(r'^--- nphy rxdiag sample (\d+) ---[ \t]*$', block, flags=re.M)
 out=[]
 for i in range(1,len(parts),2):
  d={'sample':int(parts[i])}; body=parts[i+1]
  for k in IQ_KEYS:
   v=kv(body,k)
   if v is not None: d[k]=v
  out.append(d)
 return out

def unique_tuples(samples,keys):
 vals=[]
 for s in samples:
  row=tuple(intval(s.get(k)) for k in keys)
  if all(v is not None for v in row) and row not in vals: vals.append(row)
 return vals

def main():
 ap=argparse.ArgumentParser()
 ap.add_argument('input',type=Path); ap.add_argument('--json',dest='jsonp',type=Path); ap.add_argument('--text',dest='textp',type=Path)
 a=ap.parse_args(); text=a.input.read_text(errors='replace')
 # v1.14.26 emitted its software-only calstate as one physical line with
 # literal \n separators. Normalize that payload for backward-compatible analysis.
 text=re.sub(r'(?m)^calstate_source=software-only(?:\\n[^\r\n]*)+',
             lambda m: m.group(0).replace('\\n', '\n'), text)
 band=kv(text,'nphy_rxdiag_band'); country=kv(text,'nphy_rxdiag_country')
 expected=FREQS.get(band,[])
 requested=[int(x) for x in (kv(text,'requested_frequencies') or '').split() if x.isdigit()]
 sections=re.split(r'^=== nphy rxdiag frequency (\d+) ===[ \t]*$', text, flags=re.M)
 freqs=[]
 for i in range(1,len(sections),2):
  freq=int(sections[i]); body=sections[i+1]
  freqs.append({'frequency':freq,'set_rc':intval(kv(body,'nphy_setfreq_rc')),
                'reported':intval(kv(body,'nphy_reported_freq')),'samples':parse_samples(body)})
 allsamples=[s for f in freqs for s in f['samples']]
 def flag(key,val='1'): return kv(text,key)==val
 source_ok=(kv(text,'b43_macaddr_mtd')=='boot-chain' and intval(kv(text,'b43_macaddr_mtd_offset'))==458496 and intval(kv(text,'b43_macaddr_increment'))==4 and intval(kv(text,'b43_module_pio'))==1)
 freq_ok=bool(expected) and requested==expected and [f['frequency'] for f in freqs]==expected and all(f['set_rc']==0 and f['reported']==f['frequency'] for f in freqs)
 sample_count_ok=bool(freqs) and all(len(f['samples'])==3 for f in freqs)
 estimator_ok=bool(allsamples) and all(intval(s.get('iq_estimator_complete'))==1 and intval(s.get('iq_samples'))==4096 for s in allsamples)
 started_ok=bool(allsamples) and all(intval(s.get('status'))==2 and intval(s.get('radio_on'))==1 and s.get('transfer')=='pio' for s in allsamples)
 rx_states=[((intval(s.get('rfseqca')) or 0)&0x00f0)>>4 for s in allsamples]
 classifier=[(intval(s.get('classctl')) or 0)&0x3 for s in allsamples]
 rxcores_ok=bool(rx_states) and all(v==3 for v in rx_states)
 classifier_ok=bool(classifier) and all(v==3 for v in classifier)
 no_tx=all(flag(k,'0') for k in ('requested_scan','requested_probe_requests','requested_ssid_count','requested_association','requested_ap','requested_user_tx','requested_frame_injection','requested_rf_override','requested_calibration_sequence'))
 capture=flag('nphy_rxdiag_capture_complete')
 mac=kv(text,'nphy_rxdiag_interface_mac'); expmac=kv(text,'stock_expected_wlan_mac'); mac_ok=bool(mac and expmac and mac.lower()==expmac.lower())

 # v1.14.26 uses a separate software-only node. Older synthetic/v1.14.25
 # evidence with inline fields remains parseable for regression/history.
 split_source=kv(text,'calstate_source')
 split_rc=intval(kv(text,'nphy_calstate_rc'))
 split_vals={k:intval(kv(text,k)) for k in SW_CAL_KEYS}
 split_ok=(split_source=='software-only' and split_rc==0 and all(v is not None for v in split_vals.values()))
 inline_ok=bool(allsamples) and all(all(k in s and intval(s.get(k)) is not None for k in INLINE_CAL_KEYS) for s in allsamples)
 calibration_state_present=split_ok or inline_ok
 cal_mode='split-software-only' if split_ok else ('legacy-inline' if inline_ok else 'missing')

 vals=[]
 for s in allsamples:
  p=[intval(s.get(k)) for k in ('iq_i0_pwr','iq_q0_pwr','iq_i1_pwr','iq_q1_pwr')]
  if all(v is not None for v in p): vals.extend(p)
 energy=any(v!=0 for v in vals)
 av0=[intval(s.get('iq_core0_avg')) for s in allsamples if intval(s.get('iq_core0_avg')) is not None]
 av1=[intval(s.get('iq_core1_avg')) for s in allsamples if intval(s.get('iq_core1_avg')) is not None]

 if split_ok:
  cache2=[tuple(split_vals[k] for k in ('rx_iq_cache_2g_a0_signed','rx_iq_cache_2g_b0_signed','rx_iq_cache_2g_a1_signed','rx_iq_cache_2g_b1_signed'))]
  cache5=[tuple(split_vals[k] for k in ('rx_iq_cache_5g_a0_signed','rx_iq_cache_5g_b0_signed','rx_iq_cache_5g_a1_signed','rx_iq_cache_5g_b1_signed'))]
  iq2=[split_vals['iqcal_2g_center_freq']]; rs2=[split_vals['rssical_2g_center_freq']]
  iq5=[split_vals['iqcal_5g_center_freq']]; rs5=[split_vals['rssical_5g_center_freq']]
  rev3_impl=[split_vals['rx_iq_cal_rev3plus_implemented']]
  live=[]
 else:
  live=unique_tuples(allsamples,('rx_iq_live_a0_signed','rx_iq_live_b0_signed','rx_iq_live_a1_signed','rx_iq_live_b1_signed'))
  cache2=unique_tuples(allsamples,('rx_iq_cache_2g_a0_signed','rx_iq_cache_2g_b0_signed','rx_iq_cache_2g_a1_signed','rx_iq_cache_2g_b1_signed'))
  cache5=unique_tuples(allsamples,('rx_iq_cache_5g_a0_signed','rx_iq_cache_5g_b0_signed','rx_iq_cache_5g_a1_signed','rx_iq_cache_5g_b1_signed'))
  iq2=sorted({intval(s.get('iqcal_2g_center_freq')) for s in allsamples if intval(s.get('iqcal_2g_center_freq')) is not None})
  rs2=sorted({intval(s.get('rssical_2g_center_freq')) for s in allsamples if intval(s.get('rssical_2g_center_freq')) is not None})
  iq5=sorted({intval(s.get('iqcal_5g_center_freq')) for s in allsamples if intval(s.get('iqcal_5g_center_freq')) is not None})
  rs5=sorted({intval(s.get('rssical_5g_center_freq')) for s in allsamples if intval(s.get('rssical_5g_center_freq')) is not None})
  rev3_impl=sorted({intval(s.get('rx_iq_cal_rev3plus_implemented')) for s in allsamples if intval(s.get('rx_iq_cal_rev3plus_implemented')) is not None})

 current_iq=iq2 if band=='2g' else iq5
 current_rssi=rs2 if band=='2g' else rs5
 current_cache=cache2 if band=='2g' else cache5
 live_all_zero=bool(live) and all(all(v==0 for v in row) for row in live)
 current_cache_all_zero=bool(current_cache) and all(all(v==0 for v in row) for row in current_cache)
 gates={'band':band in FREQS,'country_ca':country=='CA','mtd_pio_source':source_ok,'interface_mac':mac_ok,'frequency_scope_and_readback':freq_ok,'three_samples_per_frequency':sample_count_ok,'b43_started_radio_on_pio':started_ok,'iq_estimator_completed':estimator_ok,'rx_cores_enabled':rxcores_ok,'cck_ofdm_classifier_enabled':classifier_ok,'calibration_state_present':calibration_state_present,'no_tx_or_calibration_requested':no_tx,'capture_complete':capture}
 problems=[k for k,v in gates.items() if not v]
 finding='invalid-capture'
 if not problems:
  if energy and rev3_impl==[0] and current_iq and all(v==0 for v in current_iq):
   finding='rx-iq-calibration-unsaved-rssi-calibrated' if current_rssi and any(v>0 for v in current_rssi) else 'rx-iq-calibration-unsaved'
  elif current_iq and any(v>0 for v in current_iq):
   finding='rx-iq-calibration-cache-present'
  else:
   finding='iq-activity-observed' if energy else 'iq-accumulators-all-zero'
 data={'schema':'rv220w-b43-nphy-rxdiag-v3','input':str(a.input),'band':band,'country':country,'gates':gates,'problems':problems,'finding':finding,'calibration_state_mode':cal_mode,'iq_activity_observed':energy,'iq_power_all_zero':bool(vals) and not energy,'iq_power_values':vals,'core0_avg_min':min(av0) if av0 else None,'core0_avg_max':max(av0) if av0 else None,'core1_avg_min':min(av1) if av1 else None,'core1_avg_max':max(av1) if av1 else None,'rx_core_states':rx_states,'classifier_low2':classifier,'rx_iq_cal_rev3plus_implemented':rev3_impl,'live_rx_iq_coefficients':live,'cache_2g_rx_iq_coefficients':cache2,'cache_5g_rx_iq_coefficients':cache5,'live_coefficients_all_zero':live_all_zero,'current_band_cache_coefficients_all_zero':current_cache_all_zero,'iqcal_2g_center_freq':iq2,'rssical_2g_center_freq':rs2,'iqcal_5g_center_freq':iq5,'rssical_5g_center_freq':rs5,'frequencies':freqs}
 lines=['RV220W b43 N-PHY receive-state / IQ / calibration-state analysis',f'band: {band or "unknown"} ({"PASS" if gates["band"] else "FAIL"})',f'country: {country or "unknown"} ({"PASS" if gates["country_ca"] else "FAIL"})',f'MTD identity + forced PIO: {"PASS" if source_ok else "FAIL"}',f'frequency set/readback: {"PASS" if freq_ok else "FAIL"}',f'3 IQ samples per frequency: {"PASS" if sample_count_ok else "FAIL"}',f'b43 STARTED/radio_on/PIO: {"PASS" if started_ok else "FAIL"}',f'IQ estimator completion: {"PASS" if estimator_ok else "FAIL"}',f'RFSEQ RX core mask == 3: {"PASS" if rxcores_ok else "FAIL"} values={rx_states}',f'CCK+OFDM classifier enabled: {"PASS" if classifier_ok else "FAIL"} low2={classifier}',f'calibration state captured: {"PASS" if calibration_state_present else "FAIL"} mode={cal_mode}',f'no TX/scan/override/calibration request: {"PASS" if no_tx else "FAIL"}',f'IQ accumulator activity observed: {energy}',f'core0 IQ average range: {min(av0) if av0 else "n/a"}..{max(av0) if av0 else "n/a"}',f'core1 IQ average range: {min(av1) if av1 else "n/a"}..{max(av1) if av1 else "n/a"}',f'rev3+ RX-IQ calibration implemented flag(s): {rev3_impl}',f'2G cached RX-IQ coefficient tuples (a0,b0,a1,b1): {cache2}',f'5G cached RX-IQ coefficient tuples: {cache5}',f'2G iqcal/rssical center frequencies: {iq2} / {rs2}',f'5G iqcal/rssical center frequencies: {iq5} / {rs5}',f'current-band cached coefficients all zero: {current_cache_all_zero}',f'diagnostic capture: {"PASS" if not problems else "FAIL"}',f'finding: {finding}']
 if live:
  lines.insert(-3,f'legacy inline live RX-IQ coefficient tuples: {live}')
 if problems: lines.append('failed gates: '+', '.join(problems))
 elif finding=='rx-iq-calibration-unsaved-rssi-calibrated': lines.append('Interpretation: ADC/IQ activity is present and RSSI calibration state is populated, but rev3+ RX-IQ calibration is unimplemented and the current-band IQ calibration chanspec/cache remain unsaved. This strongly supports the missing rev3+ RX-IQ calibration path as the next controlled experiment.')
 elif finding=='rx-iq-calibration-cache-present': lines.append('Interpretation: RX-IQ calibration/cache state is already populated; do not assume the rev3+ stub explains zero frame decode. Continue read-only baseband comparison.')
 elif energy: lines.append('Interpretation: N-PHY ADC/IQ activity is present; frame decode still requires separate evidence.')
 else: lines.append('Interpretation: no IQ accumulator activity was observed.')
 if a.jsonp: a.jsonp.write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')
 if a.textp: a.textp.write_text('\n'.join(lines)+'\n')
 print('\n'.join(lines))
 return 0 if not problems else 3

if __name__=='__main__': raise SystemExit(main())
