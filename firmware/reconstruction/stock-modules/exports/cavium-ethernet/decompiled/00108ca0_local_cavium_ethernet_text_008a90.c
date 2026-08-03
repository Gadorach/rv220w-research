/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00108ca0
 * Function: local_cavium_ethernet_text_008a90
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Function boundary recovered from the compiler-emitted MIPS .pdr table; the
   original local function name was stripped. Semantics are constrained by code, data-pointer
   relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 local_cavium_ethernet_text_008a90(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 in_zero;
  ulonglong uVar4;
  undefined8 unaff_s2;
  
  iVar2 = (int)uRam00000000;
  uVar1 = getCopReg(2,0x13);
  *(undefined4 *)(iVar2 + 0x39) = uVar1;
  setCopReg(2,unaff_s2,*(undefined4 *)(iVar2 + 0x30));
  if (iRam001113c8 == 0) {
    uVar4 = uRam90000300 & uRam90000308;
    iVar2 = (int)uVar4;
    uVar1 = getCopReg(2,0x1f);
    *(undefined4 *)(iVar2 + 0x119) = uVar1;
    uVar1 = getCopReg(2,0xb);
    *(undefined4 *)(iVar2 + 0x14d) = uVar1;
    uVar1 = getCopReg(2,10);
    *(undefined4 *)(iVar2 + 0x139) = uVar1;
    uVar1 = getCopReg(2,9);
    *(undefined4 *)(iVar2 + 0x125) = uVar1;
    uVar1 = getCopReg(2,8);
    *(undefined4 *)(iVar2 + 0xcd) = uVar1;
    uVar1 = getCopReg(2,7);
    *(undefined4 *)(iVar2 + 0xb9) = uVar1;
    uVar1 = getCopReg(2,6);
    *(undefined4 *)(iVar2 + 0xa5) = uVar1;
    uVar1 = getCopReg(2,5);
    *(undefined4 *)(iVar2 + 0x91) = uVar1;
    uVar1 = getCopReg(2,4);
    *(undefined4 *)(iVar2 + 0xf7) = uVar1;
    uVar1 = getCopReg(2,1);
    *(undefined4 *)(iVar2 + 0xd5) = uVar1;
    uVar1 = getCopReg(2,0);
    *(undefined4 *)(iVar2 + 0xe3) = uVar1;
    if (iRam001113c8 == 0) {
      uVar3 = uRam90000698._4_4_ & (uint)uRam900006a0;
      uVar1 = getCopReg(2,8);
      uRam90000698 = uVar4;
      *(undefined4 *)(uVar3 + 0x1f7) = uVar1;
      uVar1 = getCopReg(2,7);
      *(undefined4 *)(uVar3 + 0x239) = uVar1;
      uVar1 = getCopReg(2,6);
      *(undefined4 *)(uVar3 + 0x247) = uVar1;
      uVar1 = getCopReg(2,5);
      *(undefined4 *)(uVar3 + 0x255) = uVar1;
      uVar1 = getCopReg(2,4);
      *(undefined4 *)(uVar3 + 0x263) = uVar1;
      uVar1 = getCopReg(2,3);
      *(undefined4 *)(uVar3 + 0x20f) = uVar1;
      uVar1 = getCopReg(2,2);
      *(undefined4 *)(uVar3 + 0x21d) = uVar1;
      uVar1 = getCopReg(2,1);
      *(undefined4 *)(uVar3 + 0x1fb) = uVar1;
      setCopReg(2,in_zero,*(undefined4 *)(uVar3 - 0x8a));
      (*(code *)&printk)(&UNK_0010f6c8);
      uVar4 = uRam90000698;
    }
  }
  else {
    uRam90000698 = uRam90000300;
    uVar4 = uRam90000698;
  }
  uRam90000698 = uVar4;
  uRam90000308 = 0;
  uRam900006a0 = 0;
  iRam001113c8 = 1;
  return 1;
}

