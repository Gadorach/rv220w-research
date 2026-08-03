/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104fb8
 * Function: cvm_ipfwd_ptr_free
 * Subsystem: octeon-offload
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon hardware-offload/fast-forward path
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon hardware-offload/fast-forward path
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Vendor hardware-offload/fast-forward support. This is not required for initial
   upstream OpenWrt bring-up and should remain disabled until independently validated.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void cvm_ipfwd_ptr_free(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 in_HW_CPUNUM;
  
  uVar4 = getHWRegister(in_HW_CPUNUM);
  special2(uVar4,uVar4,8,0x32);
  iVar3 = (int)uVar4;
  iVar2 = iVar3 + 0x111288 + (uint)*(ushort *)(iVar3 + 0x11128e) * 8;
  lVar5 = *(longlong *)(iVar2 + 8);
  if (lVar5 != 0) {
    uVar1 = 0x3fffffff;
    if (lVar5 >> 0x3e != 3) {
      uVar1 = 0xffffffff;
    }
    SYNC(4);
    SYNC(4);
    *(undefined8 *)((uint)lVar5 & uVar1) = 0;
  }
  *(undefined8 *)(iVar2 + 8) = param_1;
  *(ushort *)(iVar3 + 0x11128e) = *(short *)(iVar3 + 0x11128e) + 1U & 0xf;
  return;
}

