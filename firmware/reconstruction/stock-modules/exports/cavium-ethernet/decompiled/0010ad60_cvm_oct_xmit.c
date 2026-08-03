/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 0010ad60
 * Function: cvm_oct_xmit
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined8 cvm_oct_xmit(int param_1,longlong param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  int iVar6;
  int in_zero_lo;
  longlong lVar7;
  undefined8 uVar8;
  int *piVar9;
  uint uVar10;
  ulonglong *puVar11;
  undefined8 uVar12;
  uint uVar14;
  longlong lVar13;
  longlong extraout_v1;
  undefined8 uVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  ulonglong extraout_a0;
  int iVar18;
  ulonglong uVar19;
  uint *puVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  byte *pbVar23;
  ulonglong uVar24;
  undefined8 unaff_s6;
  ulonglong *puVar25;
  undefined8 uVar26;
  ulonglong uStack_78;
  
  lVar7 = (*(code *)&strncmp)(*(undefined8 *)(param_1 + 0x20),&UNK_0010f710,4);
  if (lVar7 == 0) {
code_r0x0010addc:
    if ((imp_port_enable == 0) || (lVar7 = brcmTagAdd(param_1), lVar7 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = true;
      (*(code *)&printk)(&UNK_0010f7f8);
    }
  }
  else {
    lVar7 = (*(code *)&strncmp)(*(undefined8 *)(param_1 + 0x20),&UNK_0010f718,3);
    bVar1 = false;
    if (lVar7 == 0) goto code_r0x0010addc;
  }
  prefetch(param_2 + 0x560,0);
  prefetch(param_2 + 0x5e0,0);
  SYNC(2);
  uVar8 = *(undefined8 *)(in_zero_lo + -0x8000);
  uVar12 = *(undefined8 *)(in_zero_lo + -0x7ff8);
  *(undefined8 *)(in_zero_lo + -0x5e00) = 0x101f000000017fc;
  iVar6 = (int)param_2;
  *(ulonglong *)(in_zero_lo + -0x5e00) =
       (ulonglong)*(uint *)(iVar6 + 0x568) & 0x7ff | 0x1f00000005000;
  uStack_78 = *(ulonglong *)(param_1 + 0x140);
  if (uStack_78 == 0) {
    (*(code *)&cvmx_warn)(&UNK_0010f750);
    uStack_78 = 0;
  }
  else if ((longlong)uStack_78 >> 0x3e == 3) {
    uStack_78 = uStack_78 & 0x3fffffff;
  }
  else {
    uStack_78 = uStack_78 & 0xffffffffff;
  }
  lVar7 = *(longlong *)(param_1 + 0x150);
  uVar26 = *(undefined8 *)(param_1 + 0x138);
  uVar24 = (longlong)*(int *)(param_1 + 0x88) & 0xffffU | 0x2000800400410000 |
           ((longlong)*(int *)(iVar6 + 0x568) & 0x7ffU) << 0x24;
  uVar21 = lVar7 + 0x13fU & 0xfffffffffffffff8;
  if (*(short *)(param_1 + 0x9e) == -0x7f00) {
    if ((bVar1) && (imp_port_enable != 0)) {
      iVar18 = (int)*(undefined8 *)(param_1 + 0x140);
      if (*(short *)(iVar18 + 0x14) == 0x800) {
        if ((((*(uint *)(iVar18 + 0x16) & 0xff000000) == 0x45000000) &&
            ((*(short *)(iVar18 + 0x1c) == 0 || (*(short *)(iVar18 + 0x1c) == 0x4000)))) &&
           ((cVar3 = *(char *)(iVar18 + 0x1f), cVar3 == '\x06' || (cVar3 == '\x11')))) {
          uVar10 = (int)(char)(*(uint *)(iVar18 + 0x16) >> 0x18) & 0xf;
          if (cVar3 == '\x06') {
            *(undefined2 *)(uVar10 * 4 + iVar18 + 0x16 + 0x10) = 0;
          }
          else {
            *(undefined2 *)(uVar10 * 4 + iVar18 + 0x16 + 6) = 0;
          }
          if (ipfwd_driver_offload == 0) {
            uVar24 = uVar24 | 0x17000000;
          }
          else {
            cvm_ipfwd_cache_flow(param_1,param_2,uVar21);
            uVar24 = uVar24 | 0x17000000;
          }
        }
        goto code_r0x0010aeb8;
      }
    }
    else {
      iVar18 = (int)*(undefined8 *)(param_1 + 0x140);
    }
    if (*(short *)(iVar18 + 0x10) == 0x800) {
      if ((((*(uint *)(iVar18 + 0x12) & 0xff000000) == 0x45000000) &&
          ((*(short *)(iVar18 + 0x18) == 0 || (*(short *)(iVar18 + 0x18) == 0x4000)))) &&
         ((cVar3 = *(char *)(iVar18 + 0x1b), cVar3 == '\x06' || (cVar3 == '\x11')))) {
        uVar10 = (int)(char)(*(uint *)(iVar18 + 0x12) >> 0x18) & 0xf;
        if (cVar3 == '\x06') {
          *(undefined2 *)(uVar10 * 4 + iVar18 + 0x12 + 0x10) = 0;
        }
        else {
          *(undefined2 *)(uVar10 * 4 + iVar18 + 0x12 + 6) = 0;
        }
        if (ipfwd_driver_offload != 0) {
          cvm_ipfwd_cache_flow(param_1,param_2,uVar21);
        }
code_r0x0010b37c:
        uVar24 = uVar24 | 0x13000000;
      }
    }
  }
  else if ((*(short *)(param_1 + 0x9e) == 0x800) &&
          (puVar20 = (uint *)*(undefined8 *)(param_1 + 0x38), (*puVar20 & 0xff000000) == 0x45000000)
          ) {
    if (*(short *)((int)puVar20 + 6) == 0) {
      cVar3 = *(char *)((int)puVar20 + 9);
    }
    else {
      if (*(short *)((int)puVar20 + 6) != 0x4000) goto code_r0x0010aeb8;
      cVar3 = *(char *)((int)puVar20 + 9);
    }
    if ((cVar3 == '\x06') || (cVar3 == '\x11')) {
      if (ipfwd_driver_offload != 0) {
        cvm_ipfwd_cache_flow(param_1,param_2,uVar21);
      }
      if ((bVar1) && (imp_port_enable != 0)) goto code_r0x0010b37c;
      uVar24 = uVar24 | 0xf000000;
    }
  }
code_r0x0010aeb8:
  *(undefined8 *)((int)uVar21 + 0x10) = 0;
  *(undefined8 *)((int)uVar21 + 8) = 0;
  SYNC(2);
  uVar15 = *(undefined8 *)(in_zero_lo + -0x8000);
  if ((int)*(undefined8 *)(in_zero_lo + -0x7ff8) < -100) {
    setCopReg(2,unaff_s6,*(undefined4 *)((int)uVar24 + 0xc9));
  }
  if ((ulonglong)*(uint *)(iVar6 + 0x580) < *(ulonglong *)(iVar6 + 0x1b0)) {
    uVar10 = *(uint *)(iVar6 + 0x564);
    uVar21 = (longlong)(int)uVar10 & 0xffff;
    uVar14 = *(uint *)(param_2 + 0x560);
    uStack_78 = uStack_78 | ((longlong)((int)lVar7 - (int)uVar26) & 0xffffU) << 0x28;
    if ((uVar21 < 0x100) &&
       (lVar7 = ___cvmx_cmd_queue_state_ptr +
                (longlong)(int)(((uint)(uVar21 >> 4) & 0xf) + (uVar10 & 0xf) * 0x10) * 0x10 + 0x2800
       , lVar7 != 0)) {
      prefetch(lVar7,0);
      piVar9 = (int *)((((uint)(uVar21 >> 4) & 0xf) + (uVar10 & 0xf) * 0x10) * 8 +
                      (int)___cvmx_cmd_queue_state_ptr);
      iVar18 = *piVar9;
      uVar16 = (ulonglong)iVar18;
      uVar26 = special2(1,uVar16,0,0x28);
      *piVar9 = (int)uVar26;
      uVar21 = uRam00000000;
      pbVar23 = (byte *)lVar7;
      bVar2 = *pbVar23;
      while (bVar2 != uVar16) {
        lVar7 = (longlong)(int)((iVar18 - (uint)bVar2) + -1);
        special2(lVar7,lVar7,5,0x32);
        do {
          bVar1 = lVar7 != 0;
          lVar7 = (longlong)((int)lVar7 + -1);
        } while (bVar1);
        bVar2 = *pbVar23;
      }
      uVar19 = *(ulonglong *)(pbVar23 + 8);
      uVar5 = uVar19 >> 0x20 & 0x1fffffff;
      if ((ulonglong)(longlong)(int)(((uint)uVar19 & 0x1fff) + 2) < (uVar19 >> 0xd & 0x1fff)) {
        if (uVar5 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010f720);
          uVar19 = *(ulonglong *)(pbVar23 + 8);
          uVar16 = extraout_a0;
        }
        special2(uVar19,uVar16,3,0x32);
        puVar11 = (ulonglong *)((int)uVar5 * 0x80 + (int)uVar16);
        *(ulonglong *)(pbVar23 + 8) = uVar19 & 0xffffffffffffe000 | uVar19 + 2 & 0x1fff;
        puVar11[1] = uStack_78;
        *puVar11 = uVar24;
code_r0x0010b020:
        *pbVar23 = *pbVar23 + 1;
        SYNC(4);
        SYNC(4);
        SYNC(4);
        SYNC(4);
        bVar1 = false;
        *(undefined8 *)((uVar14 & 0x3f) << 0xc | (uint)(((longlong)(int)uVar10 & 0x1ffU) << 3)) = 2;
        goto code_r0x0010b05c;
      }
      if (uRam00000000 != 0) {
        uVar5 = uRam00000000 & 0x7fffffffffffffff;
        uVar22 = uVar5 | 0x8000000000000000;
        uVar16 = uVar19 >> 0x20 & 0x1fffffff;
        if (uVar22 != 0) {
          lVar13 = (longlong)
                   (int)((((uint)(uVar19 >> 0xd) & 0x1fff) - ((uint)uVar19 & 0x1fff)) + -1);
          lVar7 = lVar13;
          if (uVar16 == 0) {
            (*(code *)&cvmx_warn)(&UNK_0010f720);
            uVar19 = *(ulonglong *)(pbVar23 + 8);
            lVar7 = extraout_v1;
          }
          special2(uVar19,lVar7,3,0x32);
          puVar11 = (ulonglong *)((int)uVar16 * 0x80 + (int)lVar7);
          *puVar11 = uVar24;
          puVar25 = puVar11 + 1;
          if (lVar13 != 0) {
            puVar11[1] = uStack_78;
            puVar25 = puVar11 + 2;
          }
          if (uVar22 == 0) {
            (*(code *)&cvmx_warn)(&UNK_0010f750,uVar19);
            uVar16 = 0;
          }
          else {
            uVar16 = uVar21 & 0x3fffffff;
            if ((longlong)uVar22 >> 0x3e != 3) {
              uVar16 = uVar21 & 0xffffffffff;
            }
          }
          *puVar25 = uVar16;
          special2(uVar16,uVar16,7,0x3a);
          special2(uVar16,uVar16,0,0x33);
          uVar21 = (*(ulonglong *)(pbVar23 + 8) & 0xe0000000ffffffff | uVar16) & 0xffffffffffffe000;
          *(ulonglong *)(pbVar23 + 8) = uVar21;
          if (lVar13 == 0) {
            *(ulonglong *)(pbVar23 + 8) = uVar21 | 1;
            *(ulonglong *)uVar5 = uStack_78;
          }
          goto code_r0x0010b020;
        }
      }
      *pbVar23 = *pbVar23 + 1;
      SYNC(4);
      SYNC(4);
    }
    lVar7 = (*(code *)&__printk_ratelimit)(0xfa,10);
    if (lVar7 != 0) {
      (*(code *)&printk)(&UNK_0010f780,param_2);
      bVar1 = true;
      goto code_r0x0010b05c;
    }
  }
  bVar1 = true;
code_r0x0010b05c:
  *(undefined8 *)(in_zero_lo + -0x8000) = uVar8;
  *(undefined8 *)(in_zero_lo + -0x7ff8) = uVar12;
  if (bVar1) {
    (*(code *)&dev_kfree_skb_any)(param_1);
    *(undefined4 *)(*(uint *)(iVar6 + 0x568) & 0x7ff) = 0xffffffff;
    *(longlong *)(iVar6 + 0x728) = *(longlong *)(iVar6 + 0x728) + 1;
  }
  else {
    uVar4 = getCopReg(2,0x16);
    *(undefined4 *)((int)uVar24 + 0x77) = uVar4;
    uRam000007fc = 0xffffffff;
    *(undefined4 *)(*(uint *)(iVar6 + 0x568) & 0x7ff) = 0xffffffff;
  }
  uVar10 = *(uint *)(iVar6 + 0x580);
  uVar14 = (uint)uVar15;
  if (uVar14 < uVar10) {
    if (uVar14 < uVar10) {
      lVar7 = *(longlong *)(iVar6 + 0x570);
      if (param_2 + 0x570 == lVar7) {
        lVar7 = 0;
      }
      else {
        puVar17 = (undefined8 *)lVar7;
        uVar8 = *puVar17;
        *(int *)(iVar6 + 0x580) = *(int *)(iVar6 + 0x580) + -1;
        *(longlong *)((int)uVar8 + 8) = param_2 + 0x570;
        *(undefined8 *)(iVar6 + 0x570) = uVar8;
        puVar17[1] = 0;
        *puVar17 = 0;
      }
      (*(code *)&kfree_skb)(lVar7);
      uVar10 = *(uint *)(iVar6 + 0x580);
    }
    if (uVar14 < uVar10) {
      lVar7 = *(longlong *)(iVar6 + 0x570);
      if (param_2 + 0x570 == lVar7) {
        lVar7 = 0;
      }
      else {
        puVar17 = (undefined8 *)lVar7;
        uVar8 = *puVar17;
        *(int *)(iVar6 + 0x580) = *(int *)(iVar6 + 0x580) + -1;
        *(undefined8 *)(iVar6 + 0x570) = uVar8;
        *(longlong *)((int)uVar8 + 8) = param_2 + 0x570;
        *puVar17 = 0;
        puVar17[1] = 0;
      }
      (*(code *)&kfree_skb)(lVar7);
    }
  }
  return 0;
}

