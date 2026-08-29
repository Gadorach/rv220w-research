# RV220W stock `wl.ko` capability inventory

> Generated from the user-preserved stock module. The proprietary binary is not included.

## Identity

- Size: `5222416` bytes
- SHA-256: `59097fc90ef2af55ce22000c7cd4ee0567bebae8ea6243963539008c6307ad0d`
- ELF: `ELF64`, `2's complement, big endian`, `MIPS R3000`
- License: `Proprietary`
- Vermagic: `2.6.21.7-Cavium-Octeon mod_unload OCTEON 64BIT`
- Dependencies: `scm-led`

## Module parameters

- `name:string`
- `nompc:int`
- `macaddr:charp`
- `instance_base:int`
- `piomode:int`
- `oneonly:int`

## Symbol-family evidence

Counts are unique symbol names matching conservative regular-expression families. They prove that code/data for a family is present, not that the RV220W product enabled every member.

| Family | Unique symbols | Examples |
|---|---:|---|
| nphy | 64 | `NPHY_IPA_REV4_txdigi_filtcoeffs`, `nphy_ipa_rxcal_gaintbl_2GHz`, `nphy_ipa_rxcal_gaintbl_2GHz_rev7`, `nphy_ipa_rxcal_gaintbl_5GHz`, `nphy_ipa_rxcal_gaintbl_5GHz_rev7`, `wlc_nphy_deaf_mode`, `wlc_phy_aci_init_nphy`, `wlc_phy_aci_noise_upd_nphy`, `wlc_phy_aci_scan_nphy`, `wlc_phy_aci_sw_reset_nphy`, `wlc_phy_acimode_reset_nphy`, `wlc_phy_acimode_set_nphy` |
| ht phy | 61 | `HTPHY_txdigi_filtcoeffs`, `ht_est_pwr_lut_core1_rev0`, `ht_est_pwr_lut_core2_rev0`, `ht_est_pwr_lut_core3_rev0`, `ht_gainctrl_lut_rev0`, `ht_iq_lut_core1_rev0`, `ht_iq_lut_core2_rev0`, `ht_iq_lut_core3_rev0`, `ht_loft_lut_core1_rev0`, `ht_loft_lut_core2_rev0`, `ht_loft_lut_core3_rev0`, `ht_mcs_tbl_rev0` |
| ampdu | 22 | `scb_ampdu_cleanup`, `scb_ampdu_cleanup_all`, `wlc_ampdu_agg_state_update_rx`, `wlc_ampdu_agg_state_update_tx`, `wlc_ampdu_attach`, `wlc_ampdu_cap`, `wlc_ampdu_change_epoch`, `wlc_ampdu_detach`, `wlc_ampdu_dotxstatus`, `wlc_ampdu_dotxstatus_regmpdu`, `wlc_ampdu_macaddr_upd`, `wlc_ampdu_null_delim_cnt` |
| mimo spatial | 64 | `cck_ofdm_40bw_mimo_rates`, `cck_ofdm_mimo_rates`, `d11ucode16_mimo`, `d11ucode16_mimosz`, `d11ucode17_mimo`, `d11ucode17_mimosz`, `d11ucode22_mimo`, `d11ucode22_mimosz`, `d11ucode24_mimo`, `d11ucode24_mimosz`, `d11ucode25_mimo`, `d11ucode25_mimosz` |
| antenna selection | 19 | `mimo_2x3_div_antselid_tbl`, `mimo_2x3_div_antselpat_tbl`, `mimo_2x3_div_antselpat_tbl_nrev7p`, `mimo_2x4_div_antselid_tbl`, `mimo_2x4_div_antselpat_tbl`, `wlc_antsel_antcfg_get`, `wlc_antsel_antsel2id`, `wlc_antsel_antseltype_get`, `wlc_antsel_attach`, `wlc_antsel_buildtxh`, `wlc_antsel_detach`, `wlc_antsel_init` |
| calibration | 62 | `aes_ccmp_cal_params`, `dot11lcn_papd_compdelta_tbl_rev0`, `ht_papd_cal_scalars_tbl_core0_rev0`, `ht_papd_cal_scalars_tbl_core1_rev0`, `ht_papd_cal_scalars_tbl_core2_rev0`, `ht_papd_comp_epsilon_tbl_core0_rev0`, `ht_papd_comp_epsilon_tbl_core1_rev0`, `ht_papd_comp_epsilon_tbl_core2_rev0`, `ht_papd_comp_rfpwr_tbl_core0_rev0`, `ht_papd_comp_rfpwr_tbl_core1_rev0`, `ht_papd_comp_rfpwr_tbl_core2_rev0`, `papd_cal_scalars_tbl_core0_rev3` |
| tx power tssi | 62 | `txpwr_ctrl_tbl_rev0`, `txpwr_ctrl_tbl_rev1`, `wlc_bmac_set_txpwr_percent`, `wlc_channel_set_txpower_limit`, `wlc_lcnphy_get_tssi`, `wlc_lcnphy_idle_tssi_est_iovar`, `wlc_lcnphy_iovar_txpwrctrl`, `wlc_lcnphy_tssi2dbm`, `wlc_lcnphy_txpower_recalc_target`, `wlc_phy_cal_txgainctrl_inttssi_nphy`, `wlc_phy_cal_txpower_recalc_sw_abgphy`, `wlc_phy_cal_txpower_stats_clr_gphy` |
| noise interference | 77 | `ELNA_CCK_ACI_GAINTBL_TWEAKS_sz`, `ELNA_OLYMPIC_CCK_ACI_GAINTBL_TWEAKS_sz`, `ELNA_OLYMPIC_OFDM_ACI_GAINTBL_TWEAKS_sz`, `NOISE_ARRAY_sz`, `aux_gain_idx_aci_tbl_rev2`, `aux_gain_idx_aci_tbl_rev3`, `aux_gain_idx_ext_lna_g_aci_tbl_rev3`, `dot11lcn_noise_scale_tbl_rev0`, `dot11lpphytbl_rx_gain_aci_info_rev2`, `dot11lpphytbl_rx_gain_aci_info_rev3`, `dot11lpphytbl_rx_gain_aci_info_sz_rev2`, `dot11lpphytbl_rx_gain_aci_info_sz_rev3` |
| radar dfs | 15 | `radar_class`, `wl_iw_getdfsstat`, `wlc_dfs_setchanspec`, `wlc_dfs_timer_add`, `wlc_phy_radar_detect_enable`, `wlc_phy_radar_detect_init`, `wlc_phy_radar_detect_init_htphy`, `wlc_phy_radar_detect_mode_set`, `wlc_phy_radar_detect_run`, `wlc_phy_radar_detect_run_htphy`, `wlc_phy_update_radar_detect_param_htphy`, `wlc_phy_update_radar_detect_param_nphy` |
| mbss bsscfg | 42 | `wl_dot11_scbclear_bsscfg`, `wlc_ap_mbss16_tbtt`, `wlc_ap_mbss16_write_prbrsp`, `wlc_ap_mbss4_tbtt`, `wlc_bsscfg_ID_assign`, `wlc_bsscfg_SSID_set`, `wlc_bsscfg_alloc`, `wlc_bsscfg_ap_init`, `wlc_bsscfg_clear_smfs`, `wlc_bsscfg_disable`, `wlc_bsscfg_disablemulti`, `wlc_bsscfg_down` |
| wds | 5 | `wl_iw_wdsaddmac`, `wl_iw_wdsdelmac`, `wlc_scb_wds_free`, `wlc_wds_create`, `wlc_wds_wpa_role_set` |
| qos wme | 31 | `scb_ampdu_cleanup`, `scb_ampdu_cleanup_all`, `wl_iw_setwmemap`, `wlc_ampdu_agg_state_update_rx`, `wlc_ampdu_agg_state_update_tx`, `wlc_ampdu_attach`, `wlc_ampdu_cap`, `wlc_ampdu_change_epoch`, `wlc_ampdu_detach`, `wlc_ampdu_dotxstatus`, `wlc_ampdu_dotxstatus_regmpdu`, `wlc_ampdu_macaddr_upd` |
| security crypto | 31 | `aes_cbc_decrypt`, `aes_cbc_decrypt_pad`, `aes_cbc_encrypt`, `aes_cbc_encrypt_pad`, `aes_ccm_decrypt`, `aes_ccm_encrypt`, `aes_ccm_mac`, `aes_ccmp_cal_params`, `aes_ccmp_decrypt`, `aes_ccmp_encrypt`, `aes_ctr_crypt`, `aes_decrypt` |
| power save | 75 | `si_is_otp_powered`, `si_otp_power`, `si_pmu_alp_clock`, `si_pmu_chip_init`, `si_pmu_chipcontrol`, `si_pmu_cpu_clock`, `si_pmu_fast_pwrup_delay`, `si_pmu_force_ilp`, `si_pmu_gband_spurwar`, `si_pmu_ilp_clock`, `si_pmu_init`, `si_pmu_is_otp_powered` |
| regulatory country | 28 | `cntry_rev_locales`, `radar_class`, `wl_iw_getdfsstat`, `wlc_channel_country_abbrev`, `wlc_channel_locale_flags`, `wlc_channel_locale_flags_in_band`, `wlc_country_lookup`, `wlc_dfs_setchanspec`, `wlc_dfs_timer_add`, `wlc_get_channels_in_country`, `wlc_get_country_list`, `wlc_get_locale_2g` |

## Interpretation boundary

This inventory is suitable for a feature crosswalk and regression plan. It is not source reconstruction and does not justify copying vendor algorithms into b43. Features implemented by hostapd/mac80211/userspace must remain separated from hardware-driver gaps.
