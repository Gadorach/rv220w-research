/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104f28
 * Function: cvm_ipfwd_ptr_flush
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

void cvm_ipfwd_ptr_flush(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  
  lVar4 = 0;
  uRam0011128e = 0;
  iVar3 = 0x111288;
  do {
    lVar2 = *(longlong *)(iVar3 + 8);
    if (lVar2 != 0) {
      uVar1 = 0x3fffffff;
      if (lVar2 >> 0x3e != 3) {
        uVar1 = 0xffffffff;
      }
      SYNC(4);
      SYNC(4);
      *(undefined8 *)((uint)lVar2 & uVar1) = 0;
    }
    *(undefined8 *)(iVar3 + 8) = 0;
    lVar4 = lVar4 + 1;
    iVar3 = iVar3 + 8;
  } while (lVar4 != 0x10);
  return;
}

