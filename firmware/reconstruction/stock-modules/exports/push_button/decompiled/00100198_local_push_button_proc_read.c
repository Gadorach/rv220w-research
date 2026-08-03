/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: push_button
 * Entry: 00100198
 * Function: local_push_button_proc_read
 * Subsystem: reset-button
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: push_button
 * Subsystem: Reset-button/GPIO control
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Stock /proc push-button read handler; copies the current button state to userspace and advances the file position.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: push_button
   Subsystem: Reset-button/GPIO control
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Stock /proc push-button read handler; copies the current button state to
   userspace and advances the file position.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

ulonglong local_push_button_proc_read
                    (undefined8 param_1,ulonglong param_2,undefined8 param_3,ulonglong *param_4)

{
  int iVar2;
  ulonglong uVar1;
  ulonglong extraout_v1;
  ulonglong uVar3;
  int unaff_gp_lo;
  
  if (*param_4 == 0) {
    uRam001010b8 = ZEXT48(local_push_button_timer_callback);
    lRam001010b0 = _jiffies + 0x53;
    uRam001010c0 = 0;
    if (lRam001010a0 != 0) {
      trap(0x200);
    }
    (*(code *)&__mod_timer)(0x1010a0);
    uVar1 = Status;
    Status = Status & 0xfffffffffffffffe;
    iRam00101088 = iRam00101088 + -1;
    setCopReg(0,Status,(longlong)Status._4_4_ | uVar1 & 1);
    if (iRam00101088 < 0) {
      (*(code *)&__down_interruptible)(0x101088);
    }
    iVar2 = (*(code *)&strlen)(0x1010d0);
    uVar1 = (ulonglong)(iVar2 + 1);
    uVar3 = param_2;
    if (uVar1 != 0) {
      uVar3 = (param_2 + uVar1) - 1;
    }
    if ((*(ulonglong *)(unaff_gp_lo + 0x28) & (uVar3 | param_2 | uVar1)) == 0) {
      (*(code *)&__copy_user)(param_2,0x1010d0,uVar1);
      uVar1 = extraout_v1;
    }
    *param_4 = uVar1;
    return uVar1;
  }
  return 0;
}

