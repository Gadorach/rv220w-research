/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00106470
 * Function: is_port_authorised
 * Subsystem: module-support
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Module-local support
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Module-local support
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Semantics inferred conservatively from the retained source symbol, direct
   callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

ulonglong is_port_authorised(int param_1)

{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  
  iVar2 = (int)*(undefined8 *)(param_1 + 0x140);
  sVar1 = *(short *)(iVar2 + 0x10);
  uVar3 = (ulonglong)*(byte *)(iVar2 + 0xf) & 0x1f;
  if (sVar1 == -0x7f00) {
    sVar1 = *(short *)(iVar2 + 0x14);
  }
  if (sVar1 == -0x7772) {
    uVar3 = special2((longlong)_8021x_enabled_port,uVar3,0,0x2b);
    return uVar3 & 0xffffffff;
  }
  if ((longlong)_8021x_enabled_port != uVar3) {
    return 0;
  }
  return (ulonglong)(drop_non_eap_traffic != 0);
}

