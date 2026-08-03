/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00100bb8
 * Function: local_cavium_ethernet_text_0009a8
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

undefined8 local_cavium_ethernet_text_0009a8(undefined8 param_1)

{
  bool bVar1;
  byte *pbVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint auStack_50 [5];
  int iStack_3c;
  
  (*(code *)&seq_printf)(param_1,&UNK_0010dd98,uRam1dc6ff00,uRam1dc6ff01);
  bVar1 = false;
  iVar4 = 5;
  do {
    while( true ) {
      if (iVar4 == 5) {
        if (bRam1dc6ff05 == 0xff) {
          iStack_3c = 0;
          bVar1 = true;
        }
        else {
          iStack_3c = bRam1dc6ff05 + 1;
        }
        iVar4 = 4;
        iVar5 = 3;
        pbVar2 = (byte *)0x1dc6ff04;
      }
      else {
        pbVar2 = (byte *)(iVar4 + 0x1dc6ff00);
        iVar5 = iVar4 + -1;
      }
      if (!bVar1) break;
      if (*pbVar2 == 0xff) {
        auStack_50[iVar4] = 0;
        iVar4 = iVar5;
        if (iVar5 < 0) {
          uVar6 = 0;
          goto LAB_00100cb0;
        }
      }
      else {
        bVar1 = false;
        auStack_50[iVar4] = *pbVar2 + 1;
        iVar4 = iVar5;
        if (iVar5 < 0) {
          uVar6 = 0;
LAB_00100cb0:
          do {
            uVar7 = uVar6;
            uVar6 = uVar7 + 1;
            (*(code *)&seq_printf)(param_1,&UNK_0010ddc0,auStack_50[uVar7]);
            while (puVar3 = auStack_50 + uVar6, ~uVar7 + uVar7 + 1 != uVar6) {
              uVar6 = uVar6 + 1;
              (*(code *)&seq_printf)(param_1,&UNK_0010ddb8,*puVar3);
              if (5 < (int)uVar6) {
                return 0;
              }
            }
          } while( true );
        }
      }
    }
    auStack_50[iVar4] = (uint)*pbVar2;
    iVar4 = iVar5;
  } while (-1 < iVar5);
  uVar6 = 0;
  goto LAB_00100cb0;
}

