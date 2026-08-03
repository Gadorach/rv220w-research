/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001002e0
 * Function: sysctlHwOffloadBrcmHandler
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

undefined8 sysctlHwOffloadBrcmHandler(void)

{
  int iVar1;
  int iVar2;
  int *in_t1_lo;
  
  iVar2 = 0xe;
  if (in_t1_lo != (int *)0x0) {
    iVar1 = *in_t1_lo;
    if (iVar1 == 1) {
      iVar2 = 0x12;
    }
    if (offload_vlan_enabled == 1) {
      iVar2 = iVar2 + 4;
    }
    if (offload_brcmtag_enabled != iVar1) {
      offloadPortConfig(iVar2);
      iVar1 = *in_t1_lo;
    }
    (*(code *)&printk)(&UNK_0010dae0,iVar1,offload_brcmtag_enabled);
  }
  return 0;
}

