/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00100378
 * Function: led_blink
 * Subsystem: led-gpio
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Front-panel LED/GPIO control
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Exported board LED blink API used by other stock modules, including reset-button feedback.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Front-panel LED/GPIO control
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Exported board LED blink API used by other stock modules, including reset-button
   feedback.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void led_blink(longlong param_1,int param_2,longlong param_3,undefined4 param_4)

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
      if (lVar2 == param_1) {
        *(int *)(plVar3 + 2) = (int)param_3;
        *(int *)(plVar3 + 1) = param_2 << 1;
        *(undefined4 *)(plVar3 + 3) = param_4;
        *(undefined4 *)((int)plVar3 + 0x14) = param_4;
      }
      plVar3 = plVar3 + 4;
      lVar2 = *plVar3;
    } while (lVar2 != 0);
  }
  if (param_3 == 1) {
    if (iRam00101e04 == 0) {
      iRam00101e04 = 1;
      lRam00101e80 = _jiffies + 5;
      uRam00101e90 = 1;
      if (lRam00101e70 != 0) {
        trap(0x200);
      }
      (*(code *)&__mod_timer)(0x101e70);
    }
  }
  else if ((param_3 == 0) && (iRam00101e08 == 0)) {
    iRam00101e08 = 1;
    lRam00101e50 = _jiffies + 0x25;
    uRam00101e60 = 0;
    if (lRam00101e40 != 0) {
      trap(0x200);
    }
    (*(code *)&__mod_timer)(0x101e40);
    setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar1 & 1);
    return;
  }
  setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar1 & 1);
  return;
}

