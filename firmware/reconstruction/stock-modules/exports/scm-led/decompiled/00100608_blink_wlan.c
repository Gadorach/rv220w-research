/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00100608
 * Function: blink_wlan
 * Subsystem: led-gpio
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Front-panel LED/GPIO control
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: WLAN-specific blink helper; likely services the front-panel WIRELESS indicator rather than switch PHY LEDs.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Removing unreachable block (ram,0x001003ec) */
/* WARNING: Removing unreachable block (ram,0x00100424) */
/* WARNING: Removing unreachable block (ram,0x00100444) */
/* WARNING: Removing unreachable block (ram,0x001004c4) */
/* WARNING: Removing unreachable block (ram,0x001004c8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Front-panel LED/GPIO control
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: WLAN-specific blink helper; likely services the front-panel WIRELESS indicator
   rather than switch PHY LEDs.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void blink_wlan(void)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong *plVar3;
  
  uVar1 = Status;
  Status = Status & 0xfffffffffffffffe;
  if (lRam00101a18 != 0) {
    plVar3 = (longlong *)0x101a18;
    lVar2 = lRam00101a18;
    do {
      if (lVar2 == 4) {
        *(undefined4 *)(plVar3 + 2) = 1;
        *(undefined4 *)(plVar3 + 1) = 2;
        *(undefined4 *)(plVar3 + 3) = 1;
        *(undefined4 *)((int)plVar3 + 0x14) = 1;
      }
      plVar3 = plVar3 + 4;
      lVar2 = *plVar3;
    } while (lVar2 != 0);
  }
  if (iRam00101e04 == 0) {
    iRam00101e04 = 1;
    lRam00101e80 = _jiffies + 5;
    uRam00101e90 = 1;
    if (lRam00101e70 != 0) {
      trap(0x200);
    }
    (*(code *)&__mod_timer)(0x101e70);
  }
  setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar1 & 1);
  return;
}

