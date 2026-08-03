/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: push_button
 * Entry: 00100408
 * Function: local_push_button_timer_callback
 * Subsystem: reset-button
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: push_button
 * Subsystem: Reset-button/GPIO control
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Polling/debounce timer callback for the reset button; decompilation contains press-duration and LED-feedback behavior.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: push_button
   Subsystem: Reset-button/GPIO control
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Polling/debounce timer callback for the reset button; decompilation contains
   press-duration and LED-feedback behavior.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void local_push_button_timer_callback(ulonglong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar2 = uRam00000880;
  if (100 < param_1) {
    (*(code *)&led_blink)(2,1,1,1);
  }
  if (rebootbutton != 0) {
    (*(code *)&strcpy)(0x1010d0,&UNK_00100ad0);
    uVar3 = Status;
    Status = Status & 0xfffffffffffffffe;
    iRam00101088 = iRam00101088 + 1;
    setCopReg(0,Status,(longlong)Status._4_4_ | uVar3 & 1);
    if (iRam00101088 < 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    return;
  }
  uVar1 = getCopReg(2,1);
  *(undefined4 *)((int)uVar2 + 0x3c) = uVar1;
  lRam001010c0 = param_1 + 1;
  uRam001010b8 = ZEXT48(local_push_button_timer_callback);
  lRam001010b0 = _jiffies + 0x19;
  if (lRam001010a0 != 0) {
    trap(0x200);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

