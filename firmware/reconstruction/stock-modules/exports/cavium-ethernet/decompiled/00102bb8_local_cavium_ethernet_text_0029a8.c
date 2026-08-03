/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00102bb8
 * Function: local_cavium_ethernet_text_0029a8
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

undefined8 local_cavium_ethernet_text_0029a8(int param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  byte *pbVar5;
  longlong lVar4;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong *puVar8;
  uint uVar10;
  ulonglong uVar9;
  
  lVar3 = (longlong)*(int *)(param_1 + 0x560);
  if (lVar3 < 0x20) {
    lVar7 = lVar3 >> 4;
  }
  else {
    if (lVar3 < 0x24) {
      uVar10 = *(uint *)(param_1 + 0x560);
      lVar7 = 2;
      goto joined_r0x00102c74;
    }
    lVar7 = 3;
    if ((0x27 < lVar3) && (lVar7 = 4, lVar3 != 0x28)) {
      (*(code *)&panic)(&UNK_0010e2f8);
      return 0xffff;
    }
  }
  uVar10 = *(uint *)(param_1 + 0x560);
joined_r0x00102c74:
  if ((int)uVar10 < 0x20) {
    uVar10 = uVar10 & 0xf;
    (*(code *)&memcpy)(param_1 + 0x150,param_2 + 2,6);
  }
  else {
    uVar10 = uVar10 & 3;
    (*(code *)&memcpy)(param_1 + 0x150,param_2 + 2,6);
  }
  if (lVar7 < 2) {
    lVar4 = param_2 + 2;
    lVar3 = (*(code *)&cvmx_helper_interface_get_mode)(lVar7);
    special2(lVar3,lVar3,0,0x3a);
    if (lVar3 != 3) {
      uVar6 = 0;
      do {
        pbVar5 = (byte *)lVar4;
        lVar4 = lVar4 + 1;
        uVar6 = uVar6 << 8 | (ulonglong)*pbVar5;
      } while (param_2 + 8 != lVar4);
      special2(lVar7,lVar4,0x10,0x32);
      iVar2 = ((int)lVar4 + (uVar10 & 3)) * 0x800;
      puVar8 = (ulonglong *)(iVar2 + 0x8000010);
      uVar9 = *puVar8;
      *puVar8 = uVar9 & 0xfffffffffffffffe;
      *(ulonglong *)(iVar2 + 0x8000230) = uVar6;
      iVar1 = (int)param_2;
      *(ulonglong *)(iVar2 + 0x8000180) = (ulonglong)*(byte *)(iVar1 + 2);
      *(ulonglong *)(iVar2 + 0x8000188) = (ulonglong)*(byte *)(iVar1 + 3);
      *(ulonglong *)(iVar2 + 0x8000190) = (ulonglong)*(byte *)(iVar1 + 4);
      *(ulonglong *)(iVar2 + 0x8000198) = (ulonglong)*(byte *)(iVar1 + 5);
      *(ulonglong *)(iVar2 + 0x80001a0) = (ulonglong)*(byte *)(iVar1 + 6);
      *(ulonglong *)(iVar2 + 0x80001a8) = (ulonglong)*(byte *)(iVar1 + 7);
      local_cavium_ethernet_text_002028(param_1);
      *puVar8 = uVar9;
      return 0;
    }
  }
  return 0;
}

