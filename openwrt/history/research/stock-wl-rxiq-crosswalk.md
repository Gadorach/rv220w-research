# Stock Broadcom wl.ko N-PHY RX-IQ crosswalk

Evidence source: preserved RV220W stock `wl.ko` 5.60.120.9, unstripped. This file records symbols and control-flow relationships only; it does not reproduce proprietary source.

| Stock symbol/data | Address | Size | b43 relationship |
|---|---:|---:|---|
| `nphy_ipa_rxcal_gaintbl_5GHz` | `0x0000b220` | `0x48` | RX calibration gain selection |
| `nphy_ipa_rxcal_gaintbl_2GHz` | `0x0000b268` | `0x48` | RX calibration gain selection |
| `nphy_ipa_rxcal_gaintbl_5GHz_rev7` | `0x0000b2b0` | `0x48` | rev7+ branch, not RV220W rev4 |
| `nphy_ipa_rxcal_gaintbl_2GHz_rev7` | `0x0000b2f8` | `0x48` | rev7+ branch, not RV220W rev4 |
| `wlc_phy_rx_iq_coeffs_nphy` | `0x000f3760` | `0x108` | live RX-IQ coefficient read/write |
| `wlc_phy_rx_iq_est_nphy` | `0x000f3d60` | `0x2a4` | hardware IQ estimator |
| `wlc_phy_force_rfseq_nphy` | `0x000f6a58` | `0x1c8` | RF sequence helper |
| `wlc_phy_stay_in_carriersearch_nphy` | `0x000f80c0` | `0x1a4` | classifier/clip state helper |
| `wlc_phy_tx_tone_nphy` | `0x0010db88` | `0x4e0` | calibration stimulus helper |
| `wlc_phy_cal_rxiq_nphy` | `0x0011e578` | `0x0d98` | full stock RX-IQ calibration |

Disassembly of `wlc_phy_cal_rxiq_nphy` reads the PHY revision and has a separate rev7+ path; the RV220W N-PHY rev4 follows the large rev3–6 body. The routine calls helpers corresponding to carrier-search hold, N-PHY table access, PHY register modify/read/write, RF-sequence forcing, sample-playback stop, TX tone, IQ estimation, bit-width calculation and radio register masks.

Linux b43's rev2 RX-IQ calibration is therefore not the preferred donor for rev4 behavior. If an active implementation becomes justified, reconstruct the stock rev3–6 control sequence and map it to existing b43 helpers/register definitions, retaining an explicit opt-in test gate and complete state restoration.

## v1.14.28 rev4 reconstruction result

Subsequent instruction-level comparison changed the earlier donor conclusion: the shipping 5.60.120.9 **rev3–6 / RV220W rev4** body follows the older inline sequence that is structurally close to b43's existing `b43_nphy_rev2_cal_rx_iq()` path. The separate local target near `.text+0x11d370` is the rev7+ branch and is not taken by this PHY.

Strong local-helper mappings for the rev3–6 body are:

- `.text+0xf0b50` → IQ-calibration gain parameter derivation;
- `.text+0xf5560` → RF-control gain override (`field 0x400`);
- `.text+0x10d758` → sample playback/run helper;
- `.text+0xfa7e8` → RX-IQ compensation calculation;
- `.text+0x11d370` → separate rev7+ RX-IQ path.

The stock gain search uses `{3,3,1}` for LNA, `{7,2,0}` for HPF1 and `{2,0,0}` for HPF2. The v1.14.26 software state also showed `nphy_rxcalparams=0`, while Broadcom's shipping initialization value used by this routine is `0x010100B5`. v1.14.28 uses that value **locally** in the diagnostic and does not change normal b43 policy.

Two defects in the existing b43 rev2 transcription are corrected only in the diagnostic reconstruction:

- measured power is stored by gain pass (`power[pass]`), not RX core (`power[i]`);
- fourth-pass gain adjustment uses bit width (`fls(power[index])`), not population count (`hweight32(power[index])`).

The experiment remains channel-1-only, PIO-only, dual-acknowledged and rollback-mandatory. The normal rev3+ b43 calibration stub remains untouched.

## v1.14.34 stock cleanup / final-calculation correction

Follow-up disassembly against the v1.14.33 hardware forensics resolves two details that matter to the active rev3–6 reconstruction:

- raw radio registers `0xD6` and `0xE2` are temporary low-two-bit selectors. The stock routine masks those low two bits during setup and clears them at cleanup with `0xFFFC`; it does not restore an entire saved readback value. v1.14.33's `0x0072 -> 0x00e4` full-value mismatch was therefore not evidence of failed stock cleanup because both observed values have bits `[1:0] == 0`.
- the local stock `CalcRxIqComp` helper follows the same broad sequence as b43's existing compensation helper: save old coefficients, temporarily write zero, take a 16384-sample IQ estimate, compute A/B compensation, restore old coefficients on estimator/math error, otherwise write the new tuple. Because b43's ordinary helper returns `void`, v1.14.34 uses a diagnostic-only clone to expose final estimator/error state without altering normal calibration.

The stock 2.4 GHz rev3–6 path selects RFCTL values `0x110/0x114`; `0x140/0x148` belongs to the 5 GHz branch. The RFSEQCA operations remain RXDIS and TXEN field updates as already reconstructed.
