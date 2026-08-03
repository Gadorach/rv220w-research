/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105cf8
 * Function: cvm_ipfwd_calculate_ip_header_checksum
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

ulonglong cvm_ipfwd_calculate_ip_header_checksum(ushort *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  int iVar6;
  
  uVar5 = (ulonglong)param_1[2] + (ulonglong)param_1[3] + (ulonglong)param_1[6] +
          (ulonglong)param_1[8] +
          (ulonglong)*param_1 + (ulonglong)param_1[1] + (ulonglong)param_1[4] +
          (ulonglong)param_1[7] + (ulonglong)param_1[9];
  if (*(byte *)param_1 != 0x45) {
    uVar3 = *(byte *)param_1 & 0xf;
    iVar4 = uVar3 - 5;
    iVar6 = uVar3 - 6;
    if (iVar4 != 0) {
      param_1 = param_1 + iVar4 * 2;
      do {
        uVar2 = *param_1;
        iVar6 = iVar6 + -1;
        puVar1 = param_1 + 1;
        param_1 = param_1 + 2;
        uVar5 = uVar2 + uVar5 + (ulonglong)*puVar1;
      } while (iVar6 != -1);
    }
  }
  uVar5 = (uVar5 & 0xffff) + (uVar5 >> 0x10);
  return ((uVar5 & 0xffff) + (uVar5 >> 0x10) ^ 0xffff) & 0xffff;
}

