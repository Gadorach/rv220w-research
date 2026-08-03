/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105480
 * Function: local_cavium_ethernet_text_005270
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

undefined8 local_cavium_ethernet_text_005270(undefined8 param_1,undefined2 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  int iVar5;
  longlong lVar6;
  undefined1 auStack_100 [32];
  undefined1 auStack_e0 [64];
  undefined1 auStack_a0 [80];
  
  lVar6 = 0;
  puVar4 = param_2;
  do {
    if (*(longlong *)(puVar4 + 4) != 0) {
      iVar5 = *(int *)(puVar4 + 0xe) * 0x80;
      if (*(int *)(puVar4 + 0xe) == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010eae0);
        iVar5 = 0;
        lVar3 = cvm_ipfwd_check_timestamp(*(ulonglong *)(puVar4 + 0xc) >> 0x20 & 0xfffffff);
        if (lVar3 == 1) goto LAB_001057f8;
LAB_00105524:
        if (lVar3 == 2) {
          (*(code *)&strcpy)(auStack_100,&UNK_0010eb78);
        }
        else if (lVar3 == 0) {
          (*(code *)&strcpy)(auStack_100,&UNK_0010eb70);
        }
        else {
          (*(code *)&strcpy)(auStack_100,&UNK_0010eb88);
        }
      }
      else {
        lVar3 = cvm_ipfwd_check_timestamp(*(ulonglong *)(puVar4 + 0xc) >> 0x20 & 0xfffffff);
        if (lVar3 != 1) goto LAB_00105524;
LAB_001057f8:
        (*(code *)&strcpy)(auStack_100,&UNK_0010eb80);
      }
      uVar1 = *(ushort *)(iVar5 + 0xc);
      uVar2 = puVar4[0x10];
      (*(code *)&memset)(auStack_a0,0,0x40);
      (*(code *)&memset)(auStack_e0,0,0x40);
      cvm_mac_sprintf(iVar5,auStack_a0,0x40);
      cvm_mac_sprintf(iVar5 + 6,auStack_e0,0x40);
      (*(code *)&seq_printf)
                (param_1,&UNK_0010eb90,*(ulonglong *)(puVar4 + 4) >> 0x3e,
                 *(ulonglong *)(puVar4 + 8) >> 0x3e,*(undefined1 *)(puVar4 + 10),
                 *(undefined1 *)((int)puVar4 + 0x15),*(undefined1 *)(puVar4 + 0xb),
                 *(undefined1 *)((int)puVar4 + 0x17),uVar2 & 0xfff,*(undefined1 *)(iVar5 + 0x18),
                 *(uint *)(iVar5 + 0x1c) >> 0x10,*(undefined1 *)(iVar5 + 0x10),
                 *(undefined1 *)(iVar5 + 0x11),*(undefined1 *)(iVar5 + 0x12),
                 *(undefined1 *)(iVar5 + 0x13),*(uint *)(iVar5 + 0x1c) & 0xffff,
                 *(undefined1 *)(iVar5 + 0x14),*(undefined1 *)(iVar5 + 0x15),
                 *(undefined1 *)(iVar5 + 0x16),*(undefined1 *)(iVar5 + 0x17),uVar1 & 0xfff,
                 *(ulonglong *)(puVar4 + 0xc) >> 0x20 & 0xfffffff,auStack_100,
                 *(undefined8 *)(iVar5 + 0x20),auStack_e0,auStack_a0,iVar5,puVar4 + 4,param_2,
                 *param_2,*(undefined8 *)(iVar5 + 0x28));
    }
    lVar6 = lVar6 + 1;
    puVar4 = puVar4 + 0x10;
    if (lVar6 == 5) {
      return 0;
    }
  } while( true );
}

