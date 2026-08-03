/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: mii
 * Entry: 00100108
 * Function: mii_phy_write
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: mii
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Recovered exported wrapper around cvm_oct_mdio_write; brackets the transaction with bottom-half exclusion.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: mii
   Subsystem: MDIO/pseudo-PHY access
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Recovered exported wrapper around cvm_oct_mdio_write; brackets the transaction
   with bottom-half exclusion.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 mii_phy_write(undefined1 param_1,undefined1 param_2,undefined2 param_3)

{
  (*(code *)&local_bh_disable)();
  (*(code *)&cvm_oct_mdio_write)(0,param_1,param_2,param_3);
  (*(code *)&local_bh_enable)();
  return 0;
}

