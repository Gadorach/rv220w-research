/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00108a20
 * Function: local_cavium_ethernet_text_008810
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

void local_cavium_ethernet_text_008810(int param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = (int *)(param_1 + 0x560);
  piVar5 = (int *)0x1113c8;
  iVar3 = 0;
  do {
    if (((*piVar6 == iVar3 << 4) && (*piVar5 != 0)) &&
       (lVar2 = (*(code *)&cvmx_spi_restart_interface)(iVar3,3,10), lVar2 == 0)) {
      *piVar5 = 0;
      local_cavium_ethernet_text_008600(iVar3);
      iVar1 = *piVar6;
    }
    else {
      iVar1 = *piVar6;
    }
    iVar4 = iVar3 + 1;
    piVar5 = piVar5 + 1;
    if (iRam001113d0 == iVar1) {
      (*(code *)&cvmx_spi4000_check_speed)(iVar3);
      iRam001113d0 = iRam001113d0 + -1;
      if (iRam001113d0 < 0) {
        iRam001113d0 = 10;
      }
    }
    iVar3 = iVar4;
  } while (iVar4 != 2);
  return;
}

