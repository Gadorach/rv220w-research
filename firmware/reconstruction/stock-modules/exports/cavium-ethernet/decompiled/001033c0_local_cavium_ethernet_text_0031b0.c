/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001033c0
 * Function: local_cavium_ethernet_text_0031b0
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

int local_cavium_ethernet_text_0031b0(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  undefined8 unaff_s4;
  
  lVar3 = param_2;
  if (param_2 < 0) {
    lVar3 = (longlong)((int)param_2 + 0x7f);
  }
  iVar8 = 0;
  special2(lVar3,unaff_s4,7,0x3a);
  do {
    do {
      param_3 = param_3 + -1;
      if (param_3 == -1) {
        return iVar8;
      }
      lVar3 = (*(code *)&__alloc_skb)((int)param_2 + 0x90,0x20,0,0xffffffffffffffff);
    } while (lVar3 == 0);
    iVar1 = (int)lVar3;
    lVar7 = *(longlong *)(iVar1 + 0x140) + 0x10;
    *(longlong *)(iVar1 + 0x140) = lVar7;
    lVar6 = *(longlong *)(iVar1 + 0x148) + 0x10;
    *(longlong *)(iVar1 + 0x148) = lVar6;
    if (param_1 == 0) {
      lVar6 = *(longlong *)(iVar1 + 0x150);
      lVar7 = lVar6 + -0x68;
      *(longlong *)(iVar1 + 0x150) = lVar7;
      (*(code *)&memcpy)(lVar7,lVar6,0x138);
      uVar2 = (int)*(undefined8 *)(iVar1 + 0x150) + 0x13fU & 0xfffffff8;
      *(undefined8 *)(uVar2 + 8) = 0;
      *(undefined8 *)(uVar2 + 0x10) = 0;
      lVar7 = (longlong)(int)(0x80 - ((uint)*(longlong *)(iVar1 + 0x140) & 0x7f));
      lVar6 = *(longlong *)(iVar1 + 0x140) + lVar7;
      *(longlong *)(iVar1 + 0x148) = lVar7 + *(longlong *)(iVar1 + 0x148);
      *(longlong *)(iVar1 + 0x140) = lVar6;
      *(longlong *)((int)lVar6 + -8) = lVar3;
      lVar3 = *(longlong *)(iVar1 + 0x140);
      if (lVar3 == 0) goto LAB_0010353c;
LAB_00103434:
      puVar5 = (undefined8 *)((uint)(undefined8 *)lVar3 & 0x3fffffff);
      if (lVar3 >> 0x3e != 3) {
        puVar5 = (undefined8 *)lVar3;
      }
    }
    else {
      lVar4 = (longlong)(int)(0x80 - ((uint)lVar7 & 0x7f));
      lVar7 = lVar7 + lVar4;
      *(longlong *)(iVar1 + 0x148) = lVar4 + lVar6;
      *(longlong *)(iVar1 + 0x140) = lVar7;
      *(longlong *)((int)lVar7 + -8) = lVar3;
      lVar3 = *(longlong *)(iVar1 + 0x140);
      if (lVar3 != 0) goto LAB_00103434;
LAB_0010353c:
      (*(code *)&cvmx_warn)(&UNK_0010e408);
      puVar5 = (undefined8 *)0x0;
    }
    SYNC(4);
    SYNC(4);
    *puVar5 = unaff_s4;
    iVar8 = iVar8 + 1;
  } while( true );
}

