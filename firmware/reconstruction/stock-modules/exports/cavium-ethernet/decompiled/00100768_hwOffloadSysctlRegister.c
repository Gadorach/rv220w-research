/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00100768
 * Function: hwOffloadSysctlRegister
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

void hwOffloadSysctlRegister(void)

{
  if (iRam001111f4 != 0) {
    return;
  }
  lRam00111228 = (*(code *)&register_sysctl_table)(0x110800);
  if (lRam00111228 == 0) {
    (*(code *)&printk)(&UNK_0010db70);
  }
  else {
    (*(code *)&printk)(&UNK_0010dba8,0);
    lRam00111230 = (*(code *)&register_sysctl_table)(0x1108a0);
    if (lRam00111230 == 0) {
      (*(code *)&printk)(&UNK_0010dbe0);
    }
    else {
      (*(code *)&printk)(&UNK_0010dc10);
    }
    lRam00111238 = (*(code *)&register_sysctl_table)(0x110940);
    if (lRam00111238 == 0) {
      (*(code *)&printk)(&UNK_0010dc40);
    }
    else {
      (*(code *)&printk)(&UNK_0010dc70);
    }
    lRam00111240 = (*(code *)&register_sysctl_table)(0x1109e0);
    if (lRam00111240 == 0) {
      (*(code *)&printk)(&UNK_0010dca0);
    }
    else {
      (*(code *)&printk)(&UNK_0010dcd0);
    }
  }
  iRam001111f4 = 1;
  return;
}

