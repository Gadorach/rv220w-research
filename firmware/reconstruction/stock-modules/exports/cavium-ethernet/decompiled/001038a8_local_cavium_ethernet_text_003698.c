/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001038a8
 * Function: local_cavium_ethernet_text_003698
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

undefined8 local_cavium_ethernet_text_003698(undefined8 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  uint *puVar12;
  
  puVar11 = cvm_oct_device;
  iVar9 = 0;
  do {
    lVar2 = *(longlong *)puVar11;
    iVar10 = iVar9 + 1;
    puVar11 = (undefined1 *)((int)puVar11 + 8);
    if (lVar2 != 0) {
      (*(code *)&seq_printf)(param_1,&UNK_0010e480,iVar9,lVar2);
      iVar9 = (int)lVar2;
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e498,*(undefined8 *)(iVar9 + 0x6f0),*(undefined8 *)(iVar9 + 0x6f8)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e4d8,*(undefined8 *)(iVar9 + 0x700),*(undefined8 *)(iVar9 + 0x708)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e518,*(undefined8 *)(iVar9 + 0x710),*(undefined8 *)(iVar9 + 0x718)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e558,*(undefined8 *)(iVar9 + 0x720),*(undefined8 *)(iVar9 + 0x728)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e598,*(undefined8 *)(iVar9 + 0x740),*(undefined8 *)(iVar9 + 0x770)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e5d8,*(undefined8 *)(iVar9 + 0x748),*(undefined8 *)(iVar9 + 0x778)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e618,*(undefined8 *)(iVar9 + 0x750),*(undefined8 *)(iVar9 + 0x780)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e658,*(undefined8 *)(iVar9 + 0x758),*(undefined8 *)(iVar9 + 0x788)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e698,*(undefined8 *)(iVar9 + 0x760),*(undefined8 *)(iVar9 + 0x790)
                );
      (*(code *)&seq_printf)
                (param_1,&UNK_0010e6d8,*(undefined8 *)(iVar9 + 0x768),*(undefined8 *)(iVar9 + 0x730)
                );
    }
    uVar1 = cvm_oct_device._0_8_;
    iVar9 = iVar10;
  } while (iVar10 != 0x29);
  iVar9 = (int)cvm_oct_device._0_8_;
  if (cvm_oct_device._0_8_ != 0) {
    uVar8 = 0;
    if (*(int *)(iVar9 + 0x56c) == 2) {
      puVar12 = (uint *)&UNK_0010d914;
      do {
        (*(code *)*(undefined8 *)(iVar9 + 2000))(uVar1,0x1b,0x1d,uVar8 | 0xdc00);
        (*(code *)&seq_printf)(param_1,&UNK_0010e718,uVar8);
        uVar3 = local_cavium_ethernet_text_003520(uVar1,0x1b,0);
        lVar2 = local_cavium_ethernet_text_003520(uVar1,0x1b,1);
        uVar4 = local_cavium_ethernet_text_003520(uVar1,0x1b,0xe);
        lVar5 = local_cavium_ethernet_text_003520(uVar1,0x1b,0xf);
        local_cavium_ethernet_text_003520(uVar1,0x1b,8);
        (*(code *)&seq_printf)(param_1,&UNK_0010e730,uVar3 | lVar2 << 0x20,uVar4 | lVar5 << 0x20);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,2);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x10);
        local_cavium_ethernet_text_003520(uVar1,0x1b,9);
        (*(code *)&seq_printf)(param_1,&UNK_0010e778,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,4);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x13);
        local_cavium_ethernet_text_003520(uVar1,0x1b,10);
        (*(code *)&seq_printf)(param_1,&UNK_0010e7c0,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,6);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x12);
        local_cavium_ethernet_text_003520(uVar1,0x1b,0xb);
        (*(code *)&seq_printf)(param_1,&UNK_0010e808,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,7);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x15);
        local_cavium_ethernet_text_003520(uVar1,0x1b,0xc);
        (*(code *)&seq_printf)(param_1,&UNK_0010e850,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x16);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x11);
        local_cavium_ethernet_text_003520(uVar1,0x1b,0xd);
        (*(code *)&seq_printf)(param_1,&UNK_0010e898,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x18);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x1e);
        (*(code *)&seq_printf)(param_1,&UNK_0010e8e0,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x19);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,5);
        (*(code *)&seq_printf)(param_1,&UNK_0010e910,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x1a);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x14);
        (*(code *)&seq_printf)(param_1,&UNK_0010e940,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x1b);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x17);
        (*(code *)&seq_printf)(param_1,&UNK_0010e970,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x1c);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,3);
        (*(code *)&seq_printf)(param_1,&UNK_0010e9a0,uVar6,uVar7);
        uVar6 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x1d);
        uVar7 = local_cavium_ethernet_text_003520(uVar1,0x1b,0x1f);
        (*(code *)&seq_printf)(param_1,&UNK_0010e9d0,uVar6,uVar7);
        uVar8 = *puVar12;
        puVar12 = puVar12 + 1;
      } while (uVar8 != 0xffffffff);
      return 0;
    }
  }
  return 0;
}

