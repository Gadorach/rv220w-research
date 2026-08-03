/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00100dc0
 * Function: local_led_timer_callback
 * Subsystem: led-gpio
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Front-panel LED/GPIO control
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Timer callback that advances software-driven LED blink state.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Front-panel LED/GPIO control
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Timer callback that advances software-driven LED blink state.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void local_led_timer_callback(longlong param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  
  if (uRam00101a18 != 0) {
    puVar5 = (ulonglong *)0x101a18;
    bVar2 = false;
    uVar4 = uRam00101a18;
LAB_00100e60:
    do {
      if ((*(int *)(puVar5 + 1) != 0) && (param_1 == *(int *)(puVar5 + 2))) {
        if (*(int *)((int)puVar5 + 0x14) == 0) {
          led_on(uVar4 & 0xffff);
          iVar3 = *(int *)((int)puVar5 + 0x14);
        }
        else {
          led_off(uVar4 & 0xffff);
          iVar3 = *(int *)((int)puVar5 + 0x14);
        }
        iVar1 = *(int *)(puVar5 + 1);
        *(uint *)((int)puVar5 + 0x14) = (uint)(iVar3 == 0);
        *(int *)(puVar5 + 1) = iVar1 + -1;
        if (iVar1 + -1 != 0) {
          puVar5 = puVar5 + 4;
          uVar4 = *puVar5;
          bVar2 = true;
          if (uVar4 == 0) break;
          goto LAB_00100e60;
        }
        if (*(int *)(puVar5 + 3) == 0) {
          led_off((short)*puVar5);
        }
        else if (*(int *)(puVar5 + 3) == 1) {
          led_on((short)*puVar5);
        }
      }
      puVar5 = puVar5 + 4;
      uVar4 = *puVar5;
    } while (uVar4 != 0);
    if (bVar2) {
      if (param_1 == 1) {
        lRam00101e80 = _jiffies + 5;
        if (lRam00101e70 != 0) {
          trap(0x200);
        }
        uRam00101e90 = 1;
      }
      else {
        lRam00101e50 = _jiffies + 0x25;
        lRam00101e60 = param_1;
        if (lRam00101e40 != 0) {
          trap(0x200);
        }
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  uRam00101e18 = 1;
  if (param_1 != 1) {
    uRam00101e08 = 0;
    return;
  }
  uRam00101e04 = 0;
  return;
}

