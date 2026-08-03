/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: push_button
 * Entry: 001000e0
 * Function: local_push_button_proc_write_or_ack
 * Subsystem: reset-button
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: push_button
 * Subsystem: Reset-button/GPIO control
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Stock /proc push-button control/acknowledgement handler; semaphore-protected state update rather than the read-to-userspace path.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: push_button
   Subsystem: Reset-button/GPIO control
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Stock /proc push-button control/acknowledgement handler; semaphore-protected
   state update rather than the read-to-userspace path.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8
local_push_button_proc_write_or_ack(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  uVar1 = Status;
  Status = Status & 0xfffffffffffffffe;
  iRam00101088 = iRam00101088 + 1;
  setCopReg(0,Status,(longlong)Status._4_4_ | uVar1 & 1);
  if (iRam00101088 < 1) {
    (*(code *)&__up)(0x101088);
  }
  return param_3;
}

