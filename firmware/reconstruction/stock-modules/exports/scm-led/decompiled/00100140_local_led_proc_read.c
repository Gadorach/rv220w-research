/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00100140
 * Function: local_led_proc_read
 * Subsystem: led-gpio
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Front-panel LED/GPIO control
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Stock /proc LED read handler recovered from a function pointer and .pdr entry.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Front-panel LED/GPIO control
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Stock /proc LED read handler recovered from a function pointer and .pdr entry.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

ulonglong local_led_proc_read(undefined8 param_1,ulonglong param_2,undefined8 param_3,
                             ulonglong *param_4)

{
  int iVar2;
  int iVar3;
  ulonglong uVar1;
  ulonglong uVar4;
  ulonglong *puVar5;
  int iVar6;
  int unaff_gp_lo;
  undefined1 auStack_240 [512];
  
  auStack_240[0] = DAT_001014c0;
  (*(code *)&memset)(auStack_240 + 1,0,0x1ff);
  if (*param_4 != 0) {
    return 0;
  }
  if (uRam00101a18 != 0) {
    iVar6 = 0;
    puVar5 = (ulonglong *)0x101a38;
    uVar4 = uRam00101a18;
    iVar3 = 0;
    do {
      iVar2 = (*(code *)&sprintf)(auStack_240 + iVar6,&UNK_00101888,iVar3,
                                  (uVar4 & 0x8001070000000880) == 0);
      uVar4 = *puVar5;
      iVar6 = iVar2 + iVar6;
      puVar5 = puVar5 + 4;
      iVar3 = iVar3 + 1;
    } while (uVar4 != 0);
  }
  iVar3 = (*(code *)&strlen)(auStack_240);
  uVar1 = (ulonglong)(iVar3 + 1);
  uVar4 = param_2;
  if (uVar1 != 0) {
    uVar4 = (param_2 + uVar1) - 1;
  }
  if ((*(ulonglong *)(unaff_gp_lo + 0x28) & (uVar4 | uVar1 | param_2)) == 0) {
    (*(code *)&__copy_user)(param_2,auStack_240,uVar1);
  }
  (*(code *)&printk)(&UNK_00101898);
  *param_4 = uVar1;
  return uVar1;
}

