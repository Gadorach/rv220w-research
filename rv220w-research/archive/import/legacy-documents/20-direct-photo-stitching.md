# Direct photo-stitching baseline — 2026-07-20

This revision replaces the earlier block-overlay overviews with direct composites of the original photographs.

## Evidence-preservation rule

The stitched images are built only from photographs in `RV220W-BOARD-PHOTOS.zip`:

- no generated or imagined components,
- no semantic inpainting,
- no replacement of markings,
- no reconstruction of obscured circuitry,
- no artificial component completion.

The operations applied are geometric feature matching, RANSAC homography estimation, perspective/skew correction, warping, overlap feathering, and final cropping. Exposure differences and visible seams are intentionally retained in this baseline rather than risking alteration of evidence.

## Current outputs

- `evidence/photos/stitched/logic-board-topside.jpg` — 7000 × 5600
- `evidence/photos/stitched/logic-board-bottomside.jpg` — 7000 × 5600
- `evidence/photos/stitched/wifi-module-topside.jpg` — 5000 × 3500
- `evidence/photos/stitched/wifi-module-bottomside.jpg` — 5000 × 3500

Lossless PNG versions are distributed separately because adding them to the repository would substantially increase clone and download size.

## Source-frame groups

- Logic-board topside: overview `IMG_20260719_194145.jpg` through `194149.jpg`; detail sweep `194500.jpg` through `194729.jpg`.
- Logic-board bottom: overview `194306.jpg` and `194308.jpg`; underside detail sweep `194339.jpg` through `194445.jpg`.
- Wi-Fi module topside: `194127.jpg`, `194130.jpg`, and `194130~2.jpg`.
- Wi-Fi module bottom: `194319.jpg`, `194320.jpg`, `194325.jpg`, and `194326.jpg`.

The Wi-Fi topside remains oriented according to the original overview photograph. This preserves the photographed relationship between the PCB and all package markings, including the BCM4322 and the two SiGe RF front-end devices.

## Known limitations

- Lighting and exposure vary between source photographs.
- Some overlap boundaries remain visible.
- Fine alignment can still be manually refined in a later pass.
- The stitches are evidence references, not cosmetically reconstructed product renders.

## Diagram policy

New annotated diagrams must use these stitched images directly as their board layer. Callouts must remain outside the board whenever possible. No diagram may replace, redraw, or reinterpret board content.

The two SiGe front-end devices on the Wi-Fi module must be represented according to their photographed markings, currently read as:

```text
SiGe
2547A
2069CHF
```

This reading should remain marked as a photographic transcription until independently verified from a sharper macro or a part-marking reference.
