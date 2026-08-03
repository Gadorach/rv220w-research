/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00106618
 * Function: cvm_oct_do_interrupt
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Receive interrupt/tasklet datapath that drains Octeon work entries and submits packets to Linux.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Receive interrupt/tasklet datapath that drains Octeon work entries and submits
   packets to Linux.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_do_interrupt(void)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Status;
  lRam00000200 = (longlong)(1 << (pow_receive_group & 0x1f));
  Status = Status & 0xfffffffffffffffe;
  setCopReg(0,Status,(longlong)Status._4_4_ | uVar3 & 1);
  iVar2 = (int)uRam00111398;
  uVar1 = getCopReg(2,0);
  uRam00111398 = uRam00111398 | 1;
  *(undefined4 *)(iVar2 + 10) = uVar1;
  (*(code *)&__tasklet_schedule)(0x111390);
  return 1;
}

