/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 0010a770
 * Function: cvm_oct_xmit_pow
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Transmit datapath routine, including queue/QoS or POW handling according to the selected entry point.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Transmit datapath routine, including queue/QoS or POW handling according to the
   selected entry point.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_xmit_pow(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  ulonglong in_t1;
  ulonglong uVar11;
  undefined2 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  
  uVar5 = uRam00000000;
  if (uRam00000000 != 0) {
    uVar6 = uRam00000000 & 0x7fffffffffffffff;
    uVar11 = uVar6 | 0x8000000000000000;
    if (uVar11 != 0) {
      if (uRam00000000 != 0) {
        uVar14 = uRam00000000 & 0x7fffffffffffffff | 0x8000000000000000;
        uVar13 = uVar14 + 0xc6;
        if (uVar14 != 0) {
          (*(code *)&memcpy)(uVar13,*(undefined8 *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0x88)
                            );
          puVar12 = (undefined2 *)uVar6;
          *puVar12 = *(undefined2 *)(param_1 + 0x96);
          puVar12[4] = *(undefined2 *)(param_1 + 0x8a);
          uVar5 = (ulonglong)*(byte *)(param_2 + 0x563);
          uVar9 = special2(uVar5,uVar5,10,0x33);
          *(ulonglong *)(puVar12 + 4) = *(ulonglong *)(puVar12 + 4) & 0xffff03ffffffffff | uVar5;
          uVar6 = (ulonglong)*(byte *)(param_2 + 0x563);
          uVar5 = special2(uVar6,uVar6,7,0x33);
          *(ulonglong *)(puVar12 + 4) = uVar5 | uVar6;
          uVar7 = special2((longlong)pow_send_group,(longlong)pow_send_group,3,0x33);
          *(ulonglong *)(puVar12 + 4) = uVar5 & 0xffffff80ffffffff | uVar6 | uVar7;
          iVar4 = pow_send_group;
          *(undefined8 *)(puVar12 + 8) = 0;
          *(int *)(puVar12 + 6) = iVar4;
          *(undefined1 *)(puVar12 + 8) = 1;
          *(undefined8 *)(puVar12 + 0xc) = 0;
          if (uVar13 == 0) {
            (*(code *)&cvmx_warn)(&UNK_0010f750,uVar9);
            uVar13 = 0;
            uVar5 = 0;
          }
          else if ((longlong)uVar13 >> 0x3e == 3) {
            uVar5 = uVar13 & 0x3fffffff;
          }
          else {
            uVar5 = uVar13 & 0xffffffffff;
          }
          lVar8 = (longlong)(int)((longlong)(uVar13 - uVar14) >> 7);
          uVar6 = special2(lVar8,lVar8,0x1b,0x33);
          *(ulonglong *)(puVar12 + 0xc) =
               *(ulonglong *)(puVar12 + 0xc) & 0x8000000000000000 | uVar5 | 0x8000000000000 | uVar6;
          if (*(short *)(param_1 + 0x9e) == 0x800) {
            *(undefined1 *)((int)puVar12 + 0x11) = 0xe;
            uVar5 = (ulonglong)*(byte *)((int)*(undefined8 *)(param_1 + 0x38) + 9);
            if (uVar5 != 6) {
              special2(uVar5,1,0x11,0x2e);
            }
            uVar6 = *(ulonglong *)(puVar12 + 8);
            *(ulonglong *)(puVar12 + 8) = uVar6 & 0xfffffffffffbffff | 0x40000;
            sVar1 = *(short *)((int)*(undefined8 *)(param_1 + 0x38) + 6);
            uVar5 = 0;
            if (sVar1 != 0) {
              uVar5 = (ulonglong)(sVar1 != 0x4000);
            }
            uVar5 = uVar5 << 0xd;
            *(ulonglong *)(puVar12 + 8) = uVar6 & 0xfffffffffffbdfff | 0x40000 | uVar5;
            uVar13 = special2(*(ulonglong *)(param_1 + 0x98) & 0xe00000,0x200000,0,0x2a);
            uVar13 = (uVar13 & 1) << 0xb;
            *(ulonglong *)(puVar12 + 8) = uVar6 & 0xfffffffffffbd7ff | 0x40000 | uVar5 | uVar13;
            uVar14 = special2(*(ulonglong *)(param_1 + 0x98) & 0xe00000,0x400000,0,0x2a);
            *(ulonglong *)(puVar12 + 8) =
                 uVar6 & 0xfffffffffffbd3ff | 0x40000 | uVar5 | uVar13 | (uVar14 & 1) << 10;
            (*(code *)&memcpy)(uVar11 + 0x20,*(longlong *)(param_1 + 0x140) + 10,0x60);
            uVar5 = *(ulonglong *)(puVar12 + 4);
          }
          else {
            uVar7 = *(ulonglong *)(puVar12 + 8);
            uVar13 = (ulonglong)(*(short *)(param_1 + 0x9e) == -0x7fcb) << 0xd;
            *(ulonglong *)(puVar12 + 8) = uVar7 & 0xffffffffffffdfff | uVar13;
            uVar5 = (ulonglong)(*(short *)(param_1 + 0x9e) == 0x806) << 0xc;
            *(ulonglong *)(puVar12 + 8) = uVar7 & 0xffffffffffffcfff | uVar13 | uVar5;
            uVar6 = special2(*(ulonglong *)(param_1 + 0x98) & 0xe00000,0x200000,0,0x2a);
            uVar6 = (uVar6 & 1) << 0xb;
            *(ulonglong *)(puVar12 + 8) = uVar7 & 0xffffffffffffc7ff | uVar13 | uVar5 | uVar6;
            uVar14 = special2(*(ulonglong *)(param_1 + 0x98) & 0xe00000,0x400000,0,0x2a);
            *(ulonglong *)(puVar12 + 8) =
                 uVar7 & 0xffffffffffffc3ff | uVar13 | uVar5 | uVar6 | (uVar14 & 1) << 10 | 0x200;
            (*(code *)&memcpy)(uVar11 + 0x20,*(undefined8 *)(param_1 + 0x140),0x60);
            uVar5 = *(ulonglong *)(puVar12 + 4);
          }
          uVar2 = *(uint *)(puVar12 + 6);
          special2(0xffffffffffffffff,in_t1,0xe,0x33);
          *(ulonglong *)(puVar12 + 4) = uVar5 & 0xfffffc7fffffffff | (uVar5 >> 0x27 & 7) << 0x27;
          *(uint *)(puVar12 + 6) = uVar2;
          *(ulonglong *)(puVar12 + 4) =
               *(ulonglong *)(puVar12 + 4) & 0xffffff80ffffffff | (uVar5 >> 0x20 & 7) << 0x20 |
               (uVar5 >> 0x23 & 0xf) << 0x23;
          if ((longlong)uVar11 >> 0x3e == 3) {
            uVar3 = 0x3fffffff;
          }
          else {
            uVar3 = 0xffffffff;
          }
          SYNC(4);
          SYNC(4);
          *(ulonglong *)((uint)puVar12 & uVar3) =
               in_t1 & 0xfffffc0000000000 | (uVar5 >> 0x20 & 7) << 0x20 | (ulonglong)uVar2 |
               (uVar5 >> 0x27 & 7) << 0x27 | (uVar5 >> 0x23 & 0xf) << 0x23;
          *(longlong *)(param_2 + 0x6f8) = *(longlong *)(param_2 + 0x6f8) + 1;
          *(ulonglong *)(param_2 + 0x708) =
               *(longlong *)(param_2 + 0x708) + (ulonglong)*(uint *)(param_1 + 0x88);
          (*(code *)&kfree_skb)(param_1);
          return 0;
        }
      }
      lVar8 = (*(code *)&__printk_ratelimit)(0xfa,10);
      if (lVar8 != 0) {
        (*(code *)&printk)(&UNK_0010f7d0,param_2);
      }
      if (uVar11 == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010f750);
        puVar10 = (undefined8 *)0x0;
      }
      else {
        puVar10 = (undefined8 *)((uint)(undefined8 *)uVar5 & 0x3fffffff);
        if ((longlong)uVar11 >> 0x3e != 3) {
          puVar10 = (undefined8 *)uVar5;
        }
      }
      SYNC(4);
      SYNC(4);
      *puVar10 = 1;
      *(longlong *)(param_2 + 0x728) = *(longlong *)(param_2 + 0x728) + 1;
      (*(code *)&kfree_skb)(param_1);
      return 0;
    }
  }
  lVar8 = (*(code *)&__printk_ratelimit)(0xfa,10);
  if (lVar8 == 0) {
    lVar8 = *(longlong *)(param_2 + 0x728);
  }
  else {
    (*(code *)&printk)(&UNK_0010f7a0,param_2);
    lVar8 = *(longlong *)(param_2 + 0x728);
  }
  *(longlong *)(param_2 + 0x728) = lVar8 + 1;
  (*(code *)&kfree_skb)(param_1);
  return 0;
}

