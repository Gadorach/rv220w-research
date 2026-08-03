/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00102928
 * Function: local_cavium_ethernet_text_002718
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

undefined8 local_cavium_ethernet_text_002718(int param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint *puVar3;
  uint uVar4;
  longlong extraout_a0;
  longlong lVar5;
  int iVar7;
  longlong extraout_a1;
  byte *pbVar8;
  longlong lVar6;
  undefined8 uVar9;
  longlong lVar10;
  ulonglong *puVar11;
  uint uVar13;
  ulonglong uVar12;
  
  lVar5 = (longlong)*(int *)(param_1 + 0x560);
  puVar3 = (uint *)(param_1 + 0x560);
  if (lVar5 < 0x20) {
    lVar10 = lVar5 >> 4;
LAB_00102958:
    uVar4 = *puVar3;
LAB_0010295c:
    uVar13 = uVar4 & 3;
    if (0x1f < (int)uVar4) goto LAB_0010296c;
  }
  else {
    if (0x23 < lVar5) {
      lVar10 = 3;
      if (lVar5 < 0x28) goto LAB_00102958;
      lVar10 = 4;
      if (lVar5 != 0x28) {
        (*(code *)&panic)(&UNK_0010e2f8);
        puVar3 = (uint *)((int)extraout_a0 + 0x560);
        lVar5 = (longlong)*(int *)((int)extraout_a0 + 0x560);
        if (lVar5 < 0x20) {
          lVar10 = lVar5 >> 4;
        }
        else {
          if (lVar5 < 0x24) {
            uVar4 = *puVar3;
            lVar10 = 2;
            goto joined_r0x00102c74;
          }
          lVar10 = 3;
          if ((0x27 < lVar5) && (lVar10 = 4, lVar5 != 0x28)) {
            (*(code *)&panic)(&UNK_0010e2f8);
            return 0xffff;
          }
        }
        uVar4 = *puVar3;
joined_r0x00102c74:
        if ((int)uVar4 < 0x20) {
          uVar4 = uVar4 & 0xf;
          (*(code *)&memcpy)(extraout_a0 + 0x150,extraout_a1 + 2,6);
        }
        else {
          uVar4 = uVar4 & 3;
          (*(code *)&memcpy)(extraout_a0 + 0x150,extraout_a1 + 2,6);
        }
        if (lVar10 < 2) {
          lVar6 = extraout_a1 + 2;
          lVar5 = (*(code *)&cvmx_helper_interface_get_mode)(lVar10);
          special2(lVar5,lVar5,0,0x3a);
          if (lVar5 != 3) {
            uVar2 = 0;
            do {
              pbVar8 = (byte *)lVar6;
              lVar6 = lVar6 + 1;
              uVar2 = uVar2 << 8 | (ulonglong)*pbVar8;
            } while (extraout_a1 + 8 != lVar6);
            special2(lVar10,lVar6,0x10,0x32);
            iVar1 = ((int)lVar6 + (uVar4 & 3)) * 0x800;
            puVar11 = (ulonglong *)(iVar1 + 0x8000010);
            uVar12 = *puVar11;
            *puVar11 = uVar12 & 0xfffffffffffffffe;
            *(ulonglong *)(iVar1 + 0x8000230) = uVar2;
            iVar7 = (int)extraout_a1;
            *(ulonglong *)(iVar1 + 0x8000180) = (ulonglong)*(byte *)(iVar7 + 2);
            *(ulonglong *)(iVar1 + 0x8000188) = (ulonglong)*(byte *)(iVar7 + 3);
            *(ulonglong *)(iVar1 + 0x8000190) = (ulonglong)*(byte *)(iVar7 + 4);
            *(ulonglong *)(iVar1 + 0x8000198) = (ulonglong)*(byte *)(iVar7 + 5);
            *(ulonglong *)(iVar1 + 0x80001a0) = (ulonglong)*(byte *)(iVar7 + 6);
            *(ulonglong *)(iVar1 + 0x80001a8) = (ulonglong)*(byte *)(iVar7 + 7);
            local_cavium_ethernet_text_002028(extraout_a0);
            *puVar11 = uVar12;
            return 0;
          }
        }
        return 0;
      }
      uVar4 = *puVar3;
      goto LAB_0010295c;
    }
    uVar4 = *puVar3;
    lVar10 = 2;
    if (0x1f < (int)uVar4) {
      uVar13 = uVar4 & 3;
      goto LAB_0010296c;
    }
  }
  uVar13 = uVar4 & 0xf;
LAB_0010296c:
  if (param_2 - 0x2aU < 0xff31) {
    *(int *)(param_1 + 0xa4) = param_2;
    if (lVar10 < 2) {
      lVar5 = (*(code *)&cvmx_helper_interface_get_mode)(lVar10);
      special2(lVar5,lVar5,0,0x3a);
      uVar9 = 0;
      if (lVar5 != 3) {
        uVar2 = (ulonglong)PRId;
        if (((uint)((uVar2 << 0x28) >> 0x2e) << 6 < 0xd0300) || ((uVar2 & 0xffffff) >> 8 == 0xd03))
        {
          special2(lVar10,uVar2,0x10,0x32);
          iVar7 = (PRId + (uVar13 & 3)) * 0x800;
          *(longlong *)(iVar7 + 0x8000030) = (longlong)(param_2 + 0x16);
        }
        else {
          uVar4 = (uint)lVar10 & 1;
          *(ulonglong *)(uVar4 * 8 + -0x5ffffe80) =
               ((longlong)(param_2 + 0x16) & 0xffffU) << 0x10 | 0x40;
          iVar7 = ((uVar13 & 3) + uVar4 * 0x10000) * 0x800;
        }
        *(ulonglong *)(iVar7 + 0x8000038) =
             ((ulonglong)(longlong)(param_2 + 0x1d) >> 3 & 0x1fffffff) << 3;
        return 0;
      }
    }
    else {
      uVar9 = 0;
    }
  }
  else {
    (*(code *)&printk)(&UNK_0010e328,0x2e,0xff5e);
    uVar9 = 0xffffffffffffffea;
  }
  return uVar9;
}

