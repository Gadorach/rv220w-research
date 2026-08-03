/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104a40
 * Function: cvm_ipfwd_setup_flow_info
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

void cvm_ipfwd_setup_flow_info(undefined4 *param_1,int param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0x12;
  puVar2 = (undefined4 *)*(undefined8 *)(param_2 + 0x140);
  if (*(short *)(puVar2 + 3) == -0x7f00) {
    *(undefined2 *)((int)param_1 + 0xe) = 1;
    *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)puVar2 + 0xe);
  }
  else {
    *(undefined2 *)((int)param_1 + 0xe) = 0;
    iVar3 = 0xe;
  }
  *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)((int)puVar2 + 6);
  param_1[2] = puVar2[2];
  *param_1 = *puVar2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(puVar2 + 1);
  puVar2 = (undefined4 *)(iVar3 + (int)*(undefined8 *)(param_2 + 0x140));
  param_1[4] = puVar2[3];
  param_1[5] = puVar2[4];
  *(undefined1 *)(param_1 + 6) = *(undefined1 *)((int)puVar2 + 9);
  uVar1 = puVar2[(int)(char)((uint)*puVar2 >> 0x18) & 0xf];
  *(undefined8 *)(param_1 + 8) = param_3;
  param_1[7] = uVar1;
  *(undefined8 *)(param_1 + 10) = _jiffies;
  return;
}

