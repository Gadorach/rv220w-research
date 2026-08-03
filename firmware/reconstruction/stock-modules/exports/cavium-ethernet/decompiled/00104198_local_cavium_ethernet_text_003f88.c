/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104198
 * Function: local_cavium_ethernet_text_003f88
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

undefined8 local_cavium_ethernet_text_003f88(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar5;
  ulonglong uVar3;
  longlong lVar4;
  int iVar6;
  uint uVar7;
  undefined8 extraout_a0;
  ulonglong uVar8;
  ulonglong *puVar9;
  int iVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined8 in_t3;
  uint *puVar13;
  undefined8 uVar14;
  
  uVar8 = (ulonglong)*(int *)(param_1 + 0x560);
  if ((longlong)uVar8 < 0x20) {
    iVar6 = (int)((uVar8 >> 4 & 1) << 0x10);
LAB_001041b8:
    uVar7 = *(uint *)(param_1 + 0x560);
    uVar5 = uVar7 & 3;
    iVar10 = iVar6;
    if (0x1f < (int)uVar7) goto LAB_001041cc;
  }
  else {
    if (0x23 < (longlong)uVar8) {
      iVar6 = 0x10000;
      if ((longlong)uVar8 < 0x28) goto LAB_001041b8;
      if (uVar8 != 0x28) {
        uVar14 = 0x104294;
        (*(code *)&panic)(&UNK_0010ea00);
        uVar8 = Status;
        iVar6 = (int)extraout_a0;
        puVar13 = (uint *)(iVar6 + 0x560);
        Status = Status & 0xfffffffffffffffe;
        uVar3 = (*(code *)&cvmx_helper_link_get)(*(undefined4 *)(iVar6 + 0x560));
        if (uVar3 == *(ulonglong *)(iVar6 + 0x7e0)) {
          uVar12 = 10;
          if ((uVar3 & 0x3ffff) != 10) goto LAB_00104628;
          uVar3 = (ulonglong)*(int *)(iVar6 + 0x560);
          if ((longlong)uVar3 < 0x20) {
            iVar6 = (int)((uVar3 >> 4 & 1) << 0x10);
          }
          else {
            if (0x23 < (longlong)uVar3) {
              if ((longlong)uVar3 < 0x28) {
                iVar6 = 0x10000;
                goto LAB_00104514;
              }
              if (uVar3 != 0x28) goto LAB_00104808;
            }
LAB_00104840:
            iVar6 = 0;
          }
LAB_00104514:
          uVar7 = *puVar13;
          uVar5 = uVar7 & 3;
          if ((int)uVar7 < 0x20) {
            uVar5 = uVar7 & 0xf;
          }
          iVar6 = (iVar6 + (uVar5 & 3)) * 0x800;
          puVar11 = (undefined8 *)(iVar6 + 0x8000000);
          uVar12 = *puVar11;
          setCopReg(2,in_t3,*(undefined4 *)((int)uVar12 + 0x35));
          puVar9 = (ulonglong *)(iVar6 + 0x8000018);
          *puVar9 = *puVar9 & 0xfffffffffffffffe;
          uVar3 = uRam00000170 & 0xffffffff00000000 |
                  (ulonglong)
                  ((uint)uRam00000170 & ((uint)(1L << (longlong)(int)*puVar13) ^ 0xffffffff));
          uRam00000170 = uVar3;
          *puVar11 = uVar12;
          lVar4 = (*(code *)&__printk_ratelimit)(0xfa,10,0x80014f0000000170,uVar3,uVar14);
          uVar12 = 0;
          if (lVar4 != 0) {
            uVar12 = (*(code *)&printk)(&UNK_0010ea30,extraout_a0);
          }
LAB_00104628:
          setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar8 & 1);
          return uVar12;
        }
        uVar3 = (ulonglong)*(int *)(iVar6 + 0x560);
        if ((longlong)uVar3 < 0x20) {
          iVar10 = (int)((uVar3 >> 4 & 1) << 0x10);
LAB_00104308:
          uVar7 = *puVar13;
          uVar5 = uVar7 & 3;
          iVar2 = iVar10;
          if (0x1f < (int)uVar7) goto LAB_0010431c;
        }
        else {
          if (0x23 < (longlong)uVar3) {
            if ((longlong)uVar3 < 0x28) {
              iVar10 = 0x10000;
              goto LAB_00104308;
            }
            if (uVar3 != 0x28) {
LAB_00104808:
              (*(code *)&panic)(&UNK_0010ea00);
              goto LAB_00104840;
            }
          }
          uVar7 = *puVar13;
          iVar10 = 0;
          iVar2 = 0;
          if (0x1f < (int)uVar7) {
            uVar5 = uVar7 & 3;
            goto LAB_0010431c;
          }
        }
        iVar10 = iVar2;
        uVar5 = uVar7 & 0xf;
LAB_0010431c:
        iVar10 = ((uVar5 & 3) + iVar10) * 0x800;
        puVar9 = (ulonglong *)(iVar10 + 0x8000018);
        puVar11 = (undefined8 *)(iVar10 + 0x8000000);
        *puVar9 = *puVar9 | 1;
        uRam00000170 = uRam00000170 & 0xffffffff00000000 |
                       (ulonglong)((uint)uRam00000170 | (uint)(1L << (longlong)(int)*puVar13));
        *puVar11 = *puVar11;
        uVar14 = (*(code *)&cvmx_helper_link_autoconf)(*puVar13);
        *(undefined8 *)(iVar6 + 0x7e0) = uVar14;
        setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar8 & 1);
        setCopReg(2,extraout_a0,*(undefined4 *)((int)uVar14 + 0x9d));
        uVar1 = getCopReg(2,4);
        *(undefined4 *)((int)*(undefined8 *)(iVar6 + 0x40) + 0xc6) = uVar1;
        if (*(int *)(iVar6 + 0x564) == -1) {
          lVar4 = (*(code *)&__printk_ratelimit)(0xfa,10);
        }
        else {
          lVar4 = (*(code *)&__printk_ratelimit)(0xfa,10);
        }
        if (lVar4 == 0) {
          return 0x40000;
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    uVar7 = *(uint *)(param_1 + 0x560);
    iVar6 = 0;
    iVar10 = 0;
    if (0x1f < (int)uVar7) {
      uVar5 = uVar7 & 3;
      goto LAB_001041cc;
    }
  }
  iVar6 = iVar10;
  uVar5 = uVar7 & 0xf;
LAB_001041cc:
  puVar9 = (ulonglong *)(((uVar5 & 3) + iVar6) * 0x800 + 0x8000010);
  *puVar9 = *puVar9 & 0xfffffffffffffffe;
  return 0;
}

