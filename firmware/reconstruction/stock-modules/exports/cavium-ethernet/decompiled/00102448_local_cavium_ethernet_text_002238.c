/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00102448
 * Function: local_cavium_ethernet_text_002238
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

longlong local_cavium_ethernet_text_002238(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  uint auStack_c0 [2];
  ulonglong uStack_b8;
  undefined1 auStack_a8 [4];
  uint uStack_a4;
  uint uStack_94;
  uint uStack_70;
  uint uStack_5c;
  ulonglong uStack_58;
  ushort uStack_50;
  
  iVar2 = (int)param_1;
  if (0x27 < *(int *)(iVar2 + 0x560)) {
    return param_1 + 0x6f0;
  }
  lVar3 = (*(code *)&octeon_is_simulation)();
  if (lVar3 != 0) {
    (*(code *)&memset)(auStack_a8,0,0x60);
    (*(code *)&memset)(auStack_c0,0,0x18);
    goto LAB_00102754;
  }
  uVar4 = *(uint *)(iVar2 + 0x560) & 0x3f;
  iVar1 = uVar4 * 0x50;
  uRama0000018 = 1;
  iVar5 = uVar4 * 0x20;
  uStack_a4 = (uint)((ulonglong)*(undefined8 *)(iVar1 + -0x5ffff800) >> 0x20);
  uStack_70 = (uint)((ulonglong)*(undefined8 *)(iVar1 + -0x5ffff7c8) >> 0x20);
  uStack_94 = (uint)*(undefined8 *)(iVar1 + -0x5ffff7e8);
  uVar4 = *(uint *)(iVar2 + 0x560);
  uStack_50 = (ushort)*(undefined8 *)(iVar5 + -0x5fffe5f0);
  uStack_5c = (uint)*(undefined8 *)(iVar5 + -0x5fffe600);
  uStack_58 = *(ulonglong *)(iVar5 + -0x5fffe5f8) & 0xffffffffffff;
  uVar6 = (ulonglong)(int)uVar4;
  auStack_c0[0] = (uint)uRam50001080;
  uRam50001080 = uRam50001080 & 0xffffffff00000000 | (ulonglong)uVar4;
  uStack_b8 = uRam50001088 & 0xffffffffffff;
  uRam50001088 = uRam50001088 & 0xffff000000000000 | (longlong)(int)uVar4 & 0xffffffffffffU;
  if ((uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6 < 0xd0300) {
    if (0xf < (longlong)uVar6) {
      uRam50000008 = uVar6 & 0xff;
      if ((uVar4 - 0x10 < 0x10) || (uRam50000008 = uVar6 & 0xff, uVar4 - 0x20 < 4))
      goto LAB_00102754;
      if (3 < uVar4 - 0x24) {
        uRam50000008 = 0xff;
        goto LAB_00102754;
      }
    }
    uRam50000008 = uVar6 & 0xff;
    goto LAB_00102754;
  }
  if ((0xf < (longlong)uVar6) && (0xf < uVar4 - 0x10)) {
    uRam50000008 = uVar6 & 0xff;
    if (uVar4 - 0x20 < 4) goto LAB_00102754;
    if (3 < uVar4 - 0x24) {
      uRam50000008 = 0xff;
      goto LAB_00102754;
    }
  }
  uRam50000008 = uVar6 & 0xff;
LAB_00102754:
  *(ulonglong *)(iVar2 + 0x6f0) = *(longlong *)(iVar2 + 0x6f0) + (ulonglong)uStack_5c;
  *(ulonglong *)(iVar2 + 0x6f8) = *(longlong *)(iVar2 + 0x6f8) + (ulonglong)auStack_c0[0];
  *(ulonglong *)(iVar2 + 0x700) = *(longlong *)(iVar2 + 0x700) + uStack_58;
  *(ulonglong *)(iVar2 + 0x708) = *(longlong *)(iVar2 + 0x708) + uStack_b8;
  *(ulonglong *)(iVar2 + 0x730) = *(longlong *)(iVar2 + 0x730) + (ulonglong)uStack_94;
  *(ulonglong *)(iVar2 + 0x750) = *(longlong *)(iVar2 + 0x750) + (ulonglong)uStack_50;
  *(ulonglong *)(iVar2 + 0x758) = *(longlong *)(iVar2 + 0x758) + (ulonglong)uStack_70;
  if ((uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6 < 0xd0300) {
    *(ulonglong *)(iVar2 + 0x720) = *(longlong *)(iVar2 + 0x720) + (ulonglong)uStack_a4;
    return param_1 + 0x6f0;
  }
  special2(param_1 + 0x720,(ulonglong)uStack_a4,0,0x19);
  return param_1 + 0x6f0;
}

