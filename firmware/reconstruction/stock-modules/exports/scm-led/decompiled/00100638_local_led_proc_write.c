/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00100638
 * Function: local_led_proc_write
 * Subsystem: led-gpio
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Front-panel LED/GPIO control
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Stock /proc LED command parser/write handler; decompilation exposes accepted LED identifiers and actions.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Switch with 1 destination removed at 0x00100760 */
/* WARNING: Exceeded maximum restarts with more pending */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Front-panel LED/GPIO control
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Stock /proc LED command parser/write handler; decompilation exposes accepted LED
   identifiers and actions.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

ulonglong local_led_proc_write(undefined8 param_1,ulonglong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int unaff_gp_lo;
  byte abStack_30 [16];
  
  uVar2 = param_2;
  if (param_3 != 0) {
    uVar2 = (param_2 + param_3) - 1;
  }
  if ((*(ulonglong *)(unaff_gp_lo + 0x28) & (uVar2 | param_2 | param_3)) == 0) {
    (*(code *)&__copy_user)(abStack_30,param_2,param_3);
  }
  uVar2 = Status;
  if (param_3 != 0) {
    abStack_30[(int)param_3] = 0;
    Status = Status & 0xfffffffffffffffe;
    iRam00101e28 = iRam00101e28 + -1;
    setCopReg(0,Status,(longlong)Status._4_4_ | uVar2 & 1);
    if (iRam00101e28 < 0) {
      (*(code *)&__down_interruptible)(&iRam00101e28);
    }
    uVar2 = Status;
    Status = Status & 0xfffffffffffffffe;
    if (((longlong)(int)(abStack_30[0] - 0x42) & 0xffU) < 0x36) {
      special2((longlong)(int)(abStack_30[0] - 0x42),uVar2 & 1,3,0x32);
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
      if (abStack_30[1] == '1') {
        led_blink(1,0,1,0);
        led_on(1);
      }
      else if (abStack_30[1] == '2') {
        led_blink(1,0xffffffffffffffff,0,0);
      }
      else if (abStack_30[1] == '3') {
        led_blink(1,0xffffffffffffffff,1,0);
      }
      else if (abStack_30[1] == '0') {
        led_blink(1,0,1,0);
        led_off(1);
      }
    }
    uVar1 = Status;
    setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar2 & 1);
    Status = Status & 0xfffffffffffffffe;
    iRam00101e28 = iRam00101e28 + 1;
    setCopReg(0,Status,(longlong)Status._4_4_ | uVar1 & 1);
    if (iRam00101e28 < 1) {
      (*(code *)&__up)(&iRam00101e28);
    }
  }
  return param_3;
}

