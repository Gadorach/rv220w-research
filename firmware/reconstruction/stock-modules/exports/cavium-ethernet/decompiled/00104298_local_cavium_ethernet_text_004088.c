/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104298
 * Function: local_cavium_ethernet_text_004088
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

/* WARNING: Control flow encountered bad instruction data */
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

void local_cavium_ethernet_text_004088(undefined8 param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 in_t3;
  uint *puVar13;
  
  uVar2 = Status;
  iVar10 = (int)param_1;
  puVar13 = (uint *)(iVar10 + 0x560);
  Status = Status & 0xfffffffffffffffe;
  uVar4 = (*(code *)&cvmx_helper_link_get)(*(undefined4 *)(iVar10 + 0x560));
  if (uVar4 == *(ulonglong *)(iVar10 + 0x7e0)) {
    if ((uVar4 & 0x3ffff) != 10) goto LAB_00104628;
    uVar4 = (ulonglong)*(int *)(iVar10 + 0x560);
    if ((longlong)uVar4 < 0x20) {
      iVar10 = (int)((uVar4 >> 4 & 1) << 0x10);
    }
    else {
      if (0x23 < (longlong)uVar4) {
        if ((longlong)uVar4 < 0x28) {
          iVar10 = 0x10000;
          goto LAB_00104514;
        }
        if (uVar4 != 0x28) goto LAB_00104808;
      }
LAB_00104840:
      iVar10 = 0;
    }
LAB_00104514:
    uVar11 = *puVar13;
    uVar7 = uVar11 & 3;
    if ((int)uVar11 < 0x20) {
      uVar7 = uVar11 & 0xf;
    }
    iVar10 = (iVar10 + (uVar7 & 3)) * 0x800;
    puVar12 = (undefined8 *)(iVar10 + 0x8000000);
    uVar5 = *puVar12;
    setCopReg(2,in_t3,*(undefined4 *)((int)uVar5 + 0x35));
    puVar8 = (ulonglong *)(iVar10 + 0x8000018);
    *puVar8 = *puVar8 & 0xfffffffffffffffe;
    uRam00000170 = uRam00000170 & 0xffffffff00000000 |
                   (ulonglong)
                   ((uint)uRam00000170 & ((uint)(1L << (longlong)(int)*puVar13) ^ 0xffffffff));
    *puVar12 = uVar5;
    lVar6 = (*(code *)&__printk_ratelimit)(0xfa,10);
    if (lVar6 != 0) {
      (*(code *)&printk)(&UNK_0010ea30,param_1);
    }
LAB_00104628:
    setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar2 & 1);
    return;
  }
  uVar4 = (ulonglong)*(int *)(iVar10 + 0x560);
  if ((longlong)uVar4 < 0x20) {
    iVar9 = (int)((uVar4 >> 4 & 1) << 0x10);
LAB_00104308:
    uVar11 = *puVar13;
    uVar7 = uVar11 & 3;
    iVar3 = iVar9;
    if (0x1f < (int)uVar11) goto LAB_0010431c;
  }
  else {
    if (0x23 < (longlong)uVar4) {
      if ((longlong)uVar4 < 0x28) {
        iVar9 = 0x10000;
        goto LAB_00104308;
      }
      if (uVar4 != 0x28) {
LAB_00104808:
        (*(code *)&panic)(&UNK_0010ea00);
        goto LAB_00104840;
      }
    }
    uVar11 = *puVar13;
    iVar9 = 0;
    iVar3 = 0;
    if (0x1f < (int)uVar11) {
      uVar7 = uVar11 & 3;
      goto LAB_0010431c;
    }
  }
  iVar9 = iVar3;
  uVar7 = uVar11 & 0xf;
LAB_0010431c:
  iVar9 = ((uVar7 & 3) + iVar9) * 0x800;
  puVar8 = (ulonglong *)(iVar9 + 0x8000018);
  puVar12 = (undefined8 *)(iVar9 + 0x8000000);
  *puVar8 = *puVar8 | 1;
  uRam00000170 = uRam00000170 & 0xffffffff00000000 |
                 (ulonglong)((uint)uRam00000170 | (uint)(1L << (longlong)(int)*puVar13));
  *puVar12 = *puVar12;
  uVar5 = (*(code *)&cvmx_helper_link_autoconf)(*puVar13);
  *(undefined8 *)(iVar10 + 0x7e0) = uVar5;
  setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar2 & 1);
  setCopReg(2,param_1,*(undefined4 *)((int)uVar5 + 0x9d));
  uVar1 = getCopReg(2,4);
  *(undefined4 *)((int)*(undefined8 *)(iVar10 + 0x40) + 0xc6) = uVar1;
  if (*(int *)(iVar10 + 0x564) == -1) {
    lVar6 = (*(code *)&__printk_ratelimit)(0xfa,10);
  }
  else {
    lVar6 = (*(code *)&__printk_ratelimit)(0xfa,10);
  }
  if (lVar6 == 0) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

