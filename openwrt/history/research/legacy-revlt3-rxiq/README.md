# Legacy N-PHY RX-IQ reconstruction reference

This directory deliberately preserves the v1.14.34 reconstructed RX-IQ diagnostic as a reusable engineering reference.

## Correct scope

The implementation reconstructed the stock **`phy_rev < 3` / rev2-family inline algorithm**. It is not the genuine Broadcom rev3+ helper used by the RV220W's N-PHY rev4. The naming trap is that current b43 calls its unimplemented rev3+ entry point `b43_nphy_rev3_cal_rx_iq()`.

## Why retain it

Current mainline b43 still has an unimplemented rev3+ RX-IQ routine, and its existing rev2 implementation retains defects that were corrected during the RV220W reconstruction (notably per-pass power indexing and the fourth-pass bit-width calculation). The reconstruction is therefore useful for other N-PHY/rev2 targets and as a behavioral comparison source.

## Qualification status

This is **reference code, not a universally qualified driver implementation**. The RV220W hardware runs of this body were later proven to be the wrong stock dispatch branch for rev4. Preserve the code; do not use those rev4 runs as evidence that the rev2-family algorithm works on another target.

SHA-256 of preserved fixture: `0ad734841cedf9328174d2ef8c8f644286d612fb82f0896e0a8d59bb781fb1e9`
