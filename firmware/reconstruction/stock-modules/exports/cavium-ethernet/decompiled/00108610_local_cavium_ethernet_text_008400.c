/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00108610
 * Function: local_cavium_ethernet_text_008400
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

undefined1  [16] local_cavium_ethernet_text_008400(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int extraout_a0_lo;
  undefined8 extraout_a0;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  
  uVar5 = (ulonglong)*(int *)(param_1 + 0x560);
  if ((longlong)uVar5 < 0x20) {
    iVar3 = (int)((uVar5 >> 4 & 1) << 0x10);
LAB_00108630:
    uVar4 = *(uint *)(param_1 + 0x560);
    uVar2 = uVar4 & 3;
    iVar1 = iVar3;
    if (0x1f < (int)uVar4) goto LAB_00108644;
  }
  else {
    if (0x23 < (longlong)uVar5) {
      iVar3 = 0x10000;
      if ((longlong)uVar5 < 0x28) goto LAB_00108630;
      if (uVar5 != 0x28) {
        (*(code *)&panic)(&UNK_0010ef30);
        uVar5 = (ulonglong)*(int *)(extraout_a0_lo + 0x560);
        if ((longlong)uVar5 < 0x20) {
          iVar3 = (int)((uVar5 >> 4 & 1) << 0x10);
LAB_00108730:
          uVar4 = *(uint *)(extraout_a0_lo + 0x560);
          uVar2 = uVar4 & 3;
          iVar1 = iVar3;
          if (0x1f < (int)uVar4) goto LAB_00108744;
        }
        else {
          if (0x23 < (longlong)uVar5) {
            iVar3 = 0x10000;
            if ((longlong)uVar5 < 0x28) goto LAB_00108730;
            if (uVar5 != 0x28) {
              (*(code *)&panic)(&UNK_0010ef30);
              special2(extraout_a0,extraout_a0,0x1b,0x32);
              puVar7 = (ulonglong *)((int)extraout_a0 + -0x6ffffcf8);
              puVar6 = (ulonglong *)((int)extraout_a0 + -0x6ffff960);
              *puVar7 = *puVar7 & 0xfffffffffffff00c | 0xff3;
              auVar10._0_8_ = *puVar6 & 0xffffffffffffff00 | 0xff;
              *puVar6 = auVar10._0_8_;
              auVar10._8_8_ = uRam000000f8;
              return auVar10;
            }
          }
          uVar4 = *(uint *)(extraout_a0_lo + 0x560);
          iVar3 = 0;
          iVar1 = 0;
          if (0x1f < (int)uVar4) {
            uVar2 = uVar4 & 3;
            goto LAB_00108744;
          }
        }
        iVar3 = iVar1;
        uVar2 = uVar4 & 0xf;
LAB_00108744:
        puVar6 = (ulonglong *)(((uVar2 & 3) + iVar3) * 0x800 + 0x8000010);
        auVar9._8_8_ = *puVar6 | 1;
        *puVar6 = auVar9._8_8_;
        auVar9._0_8_ = 0;
        return auVar9;
      }
    }
    uVar4 = *(uint *)(param_1 + 0x560);
    iVar3 = 0;
    iVar1 = 0;
    if (0x1f < (int)uVar4) {
      uVar2 = uVar4 & 3;
      goto LAB_00108644;
    }
  }
  iVar3 = iVar1;
  uVar2 = uVar4 & 0xf;
LAB_00108644:
  puVar6 = (ulonglong *)(((uVar2 & 3) + iVar3) * 0x800 + 0x8000010);
  auVar8._8_8_ = *puVar6 & 0xfffffffffffffffe;
  *puVar6 = auVar8._8_8_;
  auVar8._0_8_ = 0;
  return auVar8;
}

