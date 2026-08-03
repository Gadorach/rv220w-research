/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00109b50
 * Function: brcmTagAdd
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Adds the vendor Broadcom switch tag to CPU-bound transmit traffic; essential evidence for eventual B53/DSA CPU-port configuration.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Removing unreachable block (ram,0x00109df0) */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: BCM53115 switch/VLAN datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Adds the vendor Broadcom switch tag to CPU-bound transmit traffic; essential
   evidence for eventual B53/DSA CPU-port configuration.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 brcmTagAdd(int param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  
  uVar2 = (ulonglong)*(int *)(param_1 + 0x88);
  if (uVar2 < 0x3c) {
    uVar6 = 0x3c - *(int *)(param_1 + 0x88);
    lVar5 = (longlong)(int)uVar6;
    if (*(int *)(param_1 + 0x8c) == 0) {
      lVar1 = (longlong)
              ((int)*(undefined8 *)(param_1 + 0x150) - (int)*(undefined8 *)(param_1 + 0x148));
    }
    else {
      lVar1 = 0;
    }
    if (lVar5 <= lVar1) {
      if (*(int *)(param_1 + 0x8c) != 0) {
        trap(0x200);
      }
      uVar2 = *(longlong *)(param_1 + 0x148) + (ulonglong)uVar6;
      *(ulonglong *)(param_1 + 0x148) = uVar2;
      *(uint *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + uVar6;
      if (*(ulonglong *)(param_1 + 0x150) < uVar2) {
        (*(code *)&skb_over_panic)(param_1,lVar5,&UNK_00109ed0);
        iVar3 = *(int *)(param_1 + 0x88);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x88);
      }
      (*(code *)&memset)((ulonglong)(iVar3 - uVar6) + *(longlong *)(param_1 + 0x140),0,lVar5);
      goto code_r0x00109c08;
    }
    lVar1 = *(longlong *)(param_1 + 0x140);
    if ((int)lVar1 - (int)*(undefined8 *)(param_1 + 0x138) <= lVar5) {
      return 0xffffffffffffffff;
    }
    (*(code *)&memmove)(lVar1 - lVar5,lVar1,uVar2);
    uVar4 = *(longlong *)(param_1 + 0x140) - (ulonglong)uVar6;
    *(ulonglong *)(param_1 + 0x140) = uVar4;
    *(uint *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + uVar6;
    if (uVar4 < *(ulonglong *)(param_1 + 0x138)) {
      (*(code *)&skb_under_panic)(param_1,lVar5,&UNK_00109fb4);
      uVar4 = *(ulonglong *)(param_1 + 0x140);
    }
    (*(code *)&memset)(uVar2 + uVar4,0,lVar5);
    iVar3 = *(int *)(param_1 + 0x8c);
  }
  else {
code_r0x00109c08:
    iVar3 = *(int *)(param_1 + 0x8c);
  }
  if (iVar3 == 0) {
    if (4 < (int)*(ulonglong *)(param_1 + 0x150) - (int)*(longlong *)(param_1 + 0x148)) {
      uVar2 = *(longlong *)(param_1 + 0x148) + 4;
      *(ulonglong *)(param_1 + 0x148) = uVar2;
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 4;
      if (*(ulonglong *)(param_1 + 0x150) < uVar2) {
        (*(code *)&skb_over_panic)(param_1,4,&UNK_00109f58);
        iVar3 = *(int *)(param_1 + 0x88);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x88);
      }
      goto code_r0x00109ce8;
    }
  }
  lVar5 = *(longlong *)(param_1 + 0x140);
  if ((int)lVar5 - (int)*(undefined8 *)(param_1 + 0x138) < 5) {
    return 0xffffffffffffffff;
  }
  iVar3 = *(int *)(param_1 + 0x88);
  (*(code *)&memmove)(lVar5 + -4,lVar5,(longlong)iVar3);
  uVar2 = *(longlong *)(param_1 + 0x140) - 4;
  *(ulonglong *)(param_1 + 0x140) = uVar2;
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 4;
  if (uVar2 < *(ulonglong *)(param_1 + 0x138)) {
    (*(code *)&skb_under_panic)(param_1,4,&UNK_00109f14);
    uVar2 = *(ulonglong *)(param_1 + 0x140);
  }
  (*(code *)&memset)((longlong)iVar3 + uVar2,0,4);
  iVar3 = *(int *)(param_1 + 0x88);
code_r0x00109ce8:
  (*(code *)&memmove)(*(longlong *)(param_1 + 0x140) + 0x10,*(longlong *)(param_1 + 0x140) + 0xc,
                      iVar3 + -0xc);
  lVar5 = (*(code *)&memcmp)(*(undefined8 *)(param_1 + 0x140),0x110d30,6);
  if (lVar5 != 0) {
    *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xc) = 0;
    *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xd) = 0;
    *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xe) = 0;
    *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xf) = 0;
    return 0;
  }
  *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xc) = 0x20;
  *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xd) = 0;
  *(undefined1 *)((int)*(undefined8 *)(param_1 + 0x140) + 0xe) = 0;
  *(char *)((int)*(undefined8 *)(param_1 + 0x140) + 0xf) = (char)(1 << (_8021x_enabled_port & 0x1f))
  ;
  return 0;
}

