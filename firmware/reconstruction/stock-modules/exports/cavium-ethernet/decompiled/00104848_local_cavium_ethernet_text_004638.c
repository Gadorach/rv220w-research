/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104848
 * Function: local_cavium_ethernet_text_004638
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

undefined8 local_cavium_ethernet_text_004638(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong extraout_a0;
  ulonglong uVar5;
  ulonglong *puVar6;
  
  uVar5 = (ulonglong)*(int *)(param_1 + 0x560);
  if ((longlong)uVar5 < 0x20) {
    iVar3 = (int)((uVar5 >> 4 & 1) << 0x10);
LAB_00104868:
    uVar4 = *(uint *)(param_1 + 0x560);
    uVar2 = uVar4 & 3;
    iVar1 = iVar3;
    if (0x1f < (int)uVar4) goto LAB_0010487c;
  }
  else {
    if (0x23 < (longlong)uVar5) {
      iVar3 = 0x10000;
      if ((longlong)uVar5 < 0x28) goto LAB_00104868;
      if (uVar5 != 0x28) {
        (*(code *)&panic)(&UNK_0010ea00);
        if (extraout_a0 != 0) {
          *(undefined8 *)
           (((int)*(undefined8 *)((int)extraout_a0 + 0x150) + 0x13fU & 0xfffffff8) + 8) = 0;
        }
        return 1;
      }
    }
    uVar4 = *(uint *)(param_1 + 0x560);
    iVar3 = 0;
    iVar1 = 0;
    if (0x1f < (int)uVar4) {
      uVar2 = uVar4 & 3;
      goto LAB_0010487c;
    }
  }
  iVar3 = iVar1;
  uVar2 = uVar4 & 0xf;
LAB_0010487c:
  puVar6 = (ulonglong *)(((uVar2 & 3) + iVar3) * 0x800 + 0x8000010);
  *puVar6 = *puVar6 | 1;
  return 0;
}

