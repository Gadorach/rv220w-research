/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00106708
 * Function: cvm_oct_tasklet_rx
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Receive interrupt/tasklet datapath that drains Octeon work entries and submits packets to Linux.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Removing unreachable block (ram,0x00107e7c) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Receive interrupt/tasklet datapath that drains Octeon work entries and submits
   packets to Linux.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void cvm_oct_tasklet_rx(void)

{
  ushort uVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  ulonglong *puVar10;
  undefined8 in_zero;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  int iVar19;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined2 uVar21;
  longlong lVar16;
  int iVar20;
  ulonglong uVar17;
  ulonglong uVar18;
  undefined8 uVar22;
  int iVar24;
  ulonglong uVar23;
  uint uVar25;
  undefined8 uVar26;
  undefined4 *puVar27;
  ulonglong uVar28;
  longlong *plVar29;
  undefined8 in_HW_CPUNUM;
  undefined8 in_HW_RESIM30;
  undefined8 in_HW_RESIM31;
  undefined1 auVar30 [16];
  undefined1 auStack_b0 [16];
  uint uStack_a0;
  int iStack_9c;
  longlong lStack_88;
  longlong lStack_78;
  
  uVar22 = getHWRegister(in_HW_CPUNUM);
  prefetch(0x1110a8,0);
  SYNC(2);
  uVar22 = special2(uVar22,uVar22,3,0x32);
  uVar26 = *(undefined8 *)((int)in_zero + -0x8000);
  puVar10 = (ulonglong *)uVar22;
  uVar11 = *puVar10;
  *puVar10 = uVar11 & 0xffffffffffff0000 | (longlong)(1 << (pow_receive_group & 0x1f));
  lVar12 = getHWRegister(in_HW_RESIM30);
  if (lVar12 == 0) {
    (*(code *)&cvmx_warn)(&UNK_0010ecf8,&UNK_0010da20);
  }
  lVar12 = getHWRegister(in_HW_RESIM31);
  do {
    do {
      lVar13 = getHWRegister(in_HW_RESIM30);
      if (lVar13 != 0) {
        lVar12 = getHWRegister(in_HW_RESIM30);
        if (lVar12 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010ecf8,&UNK_0010da40);
        }
        *(undefined8 *)((int)in_zero + -0x5e00) = 0x1600000000000;
        iVar24 = iRam000007fc;
        if (iRam000007fc < 1) {
code_r0x00106894:
          bVar9 = false;
        }
        else {
          iVar19 = cvm_oct_mem_fill_fpa_tf1(0,0x800,iRam000007fc);
          iRam000007fc = -iVar19;
          if (iVar24 <= iVar19) goto code_r0x00106894;
          bVar9 = true;
        }
        iVar24 = 0;
        bVar3 = false;
        lStack_78 = 0;
        lStack_88 = 0;
        SYNC(2);
        uVar14 = *(ulonglong *)((int)in_zero + -0x8000);
        goto joined_r0x001068b0;
      }
      uVar14 = getHWRegister(in_HW_RESIM31);
    } while (uVar14 <= lVar12 + 0x80000000U);
    (*(code *)&printk)(&UNK_0010ed20);
    lVar12 = -0x80000001;
  } while( true );
joined_r0x001068b0:
  if ((longlong)uVar14 < 0) {
    *puVar10 = uVar11;
    *(undefined8 *)((int)in_zero + -0x8000) = uVar26;
    if (0 < iRam000007fc) {
      iRam000007fc = cvm_oct_mem_fill_fpa_tf1(0,0x800,iRam000007fc);
      iRam000007fc = -iRam000007fc;
    }
    return;
  }
  if ((uVar14 & 0xffffffffff) == 0) {
    (*(code *)&cvmx_warn)(&UNK_0010ed60);
    uVar14 = uVar14 & 0xffffffffff | 0x8000000000000000;
    if (0x3b < iVar24) goto code_r0x00107124;
code_r0x001068d8:
    lVar12 = getHWRegister(in_HW_RESIM30);
    if (lVar12 == 0) {
      (*(code *)&cvmx_warn)(&UNK_0010ecf8,&UNK_0010da40);
    }
    *(undefined8 *)((int)in_zero + -0x5e00) = 0x1600000000000;
  }
  else {
    uVar14 = uVar14 & 0xffffffffff | 0x8000000000000000;
    if (iVar24 < 0x3c) goto code_r0x001068d8;
code_r0x00107124:
    *(undefined8 *)((int)in_zero + -0x8000) = 0x8000000000000000;
    lVar12 = getHWRegister(in_HW_RESIM30);
    if (lVar12 == 0) {
      (*(code *)&cvmx_warn)(&UNK_0010ecf8,&UNK_0010da68);
    }
    uVar15 = getHWRegister(in_HW_CPUNUM);
    uVar15 = *(ulonglong *)((uint)((uVar15 & 0xf) << 6) | 0x10) >> 0x20;
    if ((uVar15 & 3) == 3) {
      (*(code *)&cvmx_warn)(&UNK_0010ed90,&UNK_0010da68);
    }
    else if ((uVar15 & 3) == 2) {
      (*(code *)&cvmx_warn)(&UNK_0010edb0,&UNK_0010da68);
    }
    uRam00000000 = 0;
    uRam00000001 = 0x200;
    uRam00000005 = 0;
    uRam00000007 = 0;
  }
  uVar7 = (uint)uVar14;
  if (ipfwd_driver_offload != 0) {
    lStack_88 = ((ulonglong)*(uint *)(uVar7 + 0xc) & 0x7ff) * 0xa8 + cvm_gbl_ipfwd_cache;
    prefetch(lStack_88,0);
  }
  prefetch(*(undefined8 *)
            (cvm_oct_device + ((uint)((ulonglong)*(undefined8 *)(uVar7 + 8) >> 0x2a) & 0x3f) * 8),0)
  ;
  uVar15 = (*(ulonglong *)(uVar7 + 0x18) >> 7 & 0x1ffffffff) -
           (*(ulonglong *)(uVar7 + 0x18) >> 0x3b & 0xf) & 0xffffffffff;
  uVar28 = uVar15 * 0x80;
  if (uVar15 == 0) {
    (*(code *)&cvmx_warn)(&UNK_0010ed60);
  }
  prefetch((uVar28 | 0x8000000000000000) - 8,0);
  if (bVar9) {
code_r0x00106fe8:
    cvm_oct_free_work(uVar14);
  }
  else {
    uVar6 = getCopReg(2,8);
    *(undefined4 *)((int)*(undefined8 *)(uVar7 + 0x10) + 0x38e) = uVar6;
    if (*(char *)(uVar7 + 0x10) == '\x01') {
      lVar12 = *(longlong *)((int)uVar28 + -8);
      uVar15 = *(ulonglong *)(uVar7 + 0x18);
      iVar19 = (int)lVar12;
      uVar28 = *(ulonglong *)(iVar19 + 0x138);
      if (uVar28 == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010ee10);
        uVar23 = 0;
      }
      else {
        uVar23 = uVar28 & 0x3fffffff;
        if ((longlong)uVar28 >> 0x3e != 3) {
          uVar23 = uVar28 & 0xffffffffff;
        }
      }
      lVar13 = (uVar28 + (uVar15 & 0xffffffffff)) - uVar23;
      *(longlong *)(iVar19 + 0x140) = lVar13;
      prefetch(lVar13,0);
      uVar1 = *(ushort *)(uVar7 + 8);
      *(uint *)(iVar19 + 0x88) = (uint)uVar1;
      *(ulonglong *)(iVar19 + 0x148) = *(longlong *)(iVar19 + 0x140) + (ulonglong)uVar1;
      lVar13 = (*(code *)&strncmp)(*(undefined8 *)
                                    (cvm_oct_device +
                                    ((uint)((ulonglong)*(undefined8 *)(uVar7 + 8) >> 0x2a) & 0x3f) *
                                    8),&UNK_0010ee40,4);
      bVar3 = lVar13 == 0;
      iVar20 = (int)*(undefined8 *)(iVar19 + 0x140);
      if ((bVar3) && (imp_port_enable != 0)) {
        bVar4 = *(short *)(iVar20 + 0x10) == -0x7f00;
        if (bVar4) goto code_r0x00106ae0;
code_r0x00107028:
        if ((bVar3) && (imp_port_enable != 0)) goto code_r0x001071f0;
        *(undefined1 *)(uVar7 + 0x11) = 0xe;
        lVar13 = *(longlong *)(iVar19 + 0x140) + (ulonglong)*(byte *)(uVar7 + 0x11);
        cVar2 = (char)((uint)*(undefined4 *)lVar13 >> 0x18);
        if (*(char *)((int)(undefined4 *)lVar13 + 9) == '\x06') goto code_r0x00107078;
code_r0x00106b30:
        bVar5 = false;
      }
      else {
        bVar4 = *(short *)(iVar20 + 0xc) == -0x7f00;
        if (!bVar4) goto code_r0x00107028;
code_r0x00106ae0:
        if ((bVar3) && (imp_port_enable != 0)) {
          *(undefined1 *)(uVar7 + 0x11) = 0x16;
        }
        else {
code_r0x001071f0:
          *(undefined1 *)(uVar7 + 0x11) = 0x12;
        }
        lVar13 = *(longlong *)(iVar19 + 0x140) + (ulonglong)*(byte *)(uVar7 + 0x11);
        cVar2 = (char)((uint)*(undefined4 *)lVar13 >> 0x18);
        if (*(char *)((int)(undefined4 *)lVar13 + 9) != '\x06') goto code_r0x00106b30;
code_r0x00107078:
        bVar5 = (*(uint *)(((int)cVar2 & 0xfU) * 4 + (int)lVar13 + 0xc) & 0x70000) != 0;
      }
      bVar8 = true;
      if (((ipfwd_driver_offload == 0) || ((*(ulonglong *)(uVar7 + 0x10) & 0x52000) != 0x40000)) ||
         (bVar8 = true, bVar5)) goto code_r0x00106b70;
      if (bVar4) {
        if ((bVar3) && (imp_port_enable != 0)) {
          uVar21 = *(undefined2 *)(iVar20 + 0x12);
        }
        else {
          uVar21 = *(undefined2 *)(iVar20 + 0xe);
        }
        lVar13 = cvm_ipfwd_find_entry(lStack_88,lVar13,uVar21,auStack_b0);
      }
      else {
        lVar13 = cvm_ipfwd_find_entry(lStack_88,lVar13,0,auStack_b0);
      }
      if ((((lVar13 == -1) ||
           (lVar13 = cvm_ipfwd_check_timestamp(uStack_a0 & 0xfffffff), lVar13 == 0)) ||
          ((lVar13 != 1 &&
           ((lVar13 = cvm_ipfwd_random_select(), lVar13 != 0 &&
            (lVar13 = cvm_ipfwd_check_bucket_timestamp(lStack_88), lVar13 != 0)))))) ||
         ((longlong)iStack_9c == 0)) {
        cvm_ipfwd_mark_packet(lVar12,uVar14,lStack_88);
        uVar15 = *(ulonglong *)(uVar7 + 8);
        uVar25 = (uint)(uVar15 >> 0x20);
        bVar8 = true;
        goto joined_r0x00106b7c;
      }
      special2((longlong)iStack_9c,1,7,0x32);
      puVar27 = (undefined4 *)*(undefined8 *)(iVar19 + 0x140);
      *puVar27 = uRam00000001;
      *(undefined2 *)(puVar27 + 1) = uRam00000005;
      *(ushort *)((int)puVar27 + 6) = CONCAT11(uRam00000007,uRam00000008);
      puVar27[2] = uRam00000009;
      if (bVar4) {
        if (sRam0000000f == 0) {
          if ((bVar3) && (imp_port_enable != 0)) {
            (*(code *)&memmove)(*(longlong *)(iVar19 + 0x140) + 0x10,
                                *(longlong *)(iVar19 + 0x140) + 0x14,*(int *)(iVar19 + 0x88) + -0x14
                               );
            *(undefined1 *)(uVar7 + 0x11) = 0x12;
            *(short *)(uVar7 + 8) = *(short *)(uVar7 + 8) + -4;
          }
          else {
            (*(code *)&memmove)(*(longlong *)(iVar19 + 0x140) + 4,*(longlong *)(iVar19 + 0x140),0xc)
            ;
            if (3 < *(uint *)(iVar19 + 0x88)) {
              *(uint *)(iVar19 + 0x88) = *(uint *)(iVar19 + 0x88) - 4;
              if (*(uint *)(iVar19 + 0x88) < *(uint *)(iVar19 + 0x8c)) {
                trap(0x200);
              }
              *(longlong *)(iVar19 + 0x140) = *(longlong *)(iVar19 + 0x140) + 4;
            }
            *(undefined1 *)(uVar7 + 0x11) = 0xe;
            *(short *)(uVar7 + 8) = *(short *)(uVar7 + 8) + -4;
          }
        }
        else if ((bVar3) && (imp_port_enable != 0)) {
          *(undefined2 *)(iVar20 + 0x12) = uRam0000000d;
        }
        else {
          *(undefined2 *)(iVar20 + 0xe) = uRam0000000d;
        }
code_r0x00107c30:
        uVar15 = *(ulonglong *)(iVar19 + 0x140);
        if (uVar15 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010ee10);
          uVar28 = 0;
        }
        else {
          uVar28 = uVar15 & 0x3fffffff;
          if ((longlong)uVar15 >> 0x3e != 3) {
            uVar28 = uVar15 & 0xffffffffff;
          }
        }
        *(ulonglong *)(uVar7 + 0x18) = *(ulonglong *)(uVar7 + 0x18) & 0xffffff0000000000 | uVar28;
      }
      else if (sRam0000000f != 0) {
        if ((bVar3) && (imp_port_enable != 0)) {
          (*(code *)&memmove)(*(longlong *)(iVar19 + 0x140) + 0x14,
                              *(longlong *)(iVar19 + 0x140) + 0x10,*(int *)(iVar19 + 0x88) + -0x10);
          *(undefined1 *)(uVar7 + 0x11) = 0x16;
          *(short *)(uVar7 + 8) = *(short *)(uVar7 + 8) + 4;
          *(undefined2 *)(iVar20 + 0x10) = 0x8100;
          *(undefined2 *)(iVar20 + 0x12) = uRam0000000d;
        }
        else {
          lVar13 = *(longlong *)(iVar19 + 0x140);
          if ((int)lVar13 - (int)*(ulonglong *)(iVar19 + 0x138) < 4) {
            (*(code *)&memmove)(lVar13 + 0x10,lVar13 + 0xc,*(int *)(iVar19 + 0x88) + -0xc);
          }
          else {
            *(ulonglong *)(iVar19 + 0x140) = lVar13 - 4U;
            *(int *)(iVar19 + 0x88) = *(int *)(iVar19 + 0x88) + 4;
            if (lVar13 - 4U < *(ulonglong *)(iVar19 + 0x138)) {
              (*(code *)&skb_under_panic)(lVar12,4,&UNK_00108118);
              lVar12 = *(longlong *)(iVar19 + 0x140);
            }
            else {
              lVar12 = *(longlong *)(iVar19 + 0x140);
            }
            (*(code *)&memmove)(lVar12,lVar12 + 4,0xc);
            iVar20 = (int)*(undefined8 *)(iVar19 + 0x140);
          }
          *(undefined2 *)(iVar20 + 0xc) = 0x8100;
          *(undefined2 *)(iVar20 + 0xe) = uRam0000000d;
          *(undefined1 *)(uVar7 + 0x11) = 0x12;
          *(short *)(uVar7 + 8) = *(short *)(uVar7 + 8) + 4;
        }
        goto code_r0x00107c30;
      }
      if ((bVar3) && (imp_port_enable != 0)) {
        *(undefined1 *)((int)*(undefined8 *)(iVar19 + 0x140) + 0xc) = 0;
        *(undefined1 *)((int)*(undefined8 *)(iVar19 + 0x140) + 0xd) = 0;
        *(undefined1 *)((int)*(undefined8 *)(iVar19 + 0x140) + 0xe) = 0;
        *(undefined1 *)((int)*(undefined8 *)(iVar19 + 0x140) + 0xf) = 0;
        *(short *)(uVar7 + 8) = *(short *)(uVar7 + 8) + 4;
      }
      lVar12 = *(longlong *)(iVar19 + 0x140) + (ulonglong)*(byte *)(uVar7 + 0x11);
      puVar27 = (undefined4 *)lVar12;
      *(char *)(puVar27 + 2) = *(char *)(puVar27 + 2) + -1;
      puVar27[3] = uRam00000011;
      puVar27[4] = uRam00000015;
      *(undefined1 *)((int)puVar27 + 9) = uRam00000019;
      puVar27[(int)(char)((uint)*puVar27 >> 0x18) & 0xf] = uRam0000001d;
      uVar21 = cvm_ipfwd_calculate_ip_header_checksum(lVar12);
      *(undefined2 *)((int)puVar27 + 10) = uVar21;
      if ((bVar3) && (imp_port_enable != 0)) {
        *(short *)(uVar7 + 8) = *(short *)(uVar7 + 8) + -4;
      }
      cvm_oct_transmit_qos(uRam00000021,uVar14,1,0);
      uRam00000029 = _jiffies;
      goto code_r0x00106d6c;
    }
    lVar12 = (*(code *)&__alloc_skb)(*(ushort *)(uVar7 + 8) + 0x10,0x20,0,0xffffffffffffffff);
    if (lVar12 == 0) {
      lVar12 = (*(code *)&__printk_ratelimit)(0xfa,10);
      if (lVar12 != 0) {
        (*(code *)&printk)(&UNK_0010ee48,*(ulonglong *)(uVar7 + 8) >> 0x2a & 0x3f);
      }
      goto code_r0x00106fe8;
    }
    iVar19 = (int)lVar12;
    lVar13 = *(longlong *)(iVar19 + 0x148) + 0x10;
    *(longlong *)(iVar19 + 0x140) = *(longlong *)(iVar19 + 0x140) + 0x10;
    *(longlong *)(iVar19 + 0x148) = lVar13;
    if (*(byte *)(uVar7 + 0x10) == 0) {
      iVar20 = (int)*(undefined8 *)(uVar7 + 0x10);
      uVar6 = getCopReg(2,9);
      *(undefined4 *)(iVar20 + 4) = uVar6;
      setCopReg(2,uVar14 + 0x20,*(undefined4 *)(iVar20 + 2));
      uVar1 = *(ushort *)(uVar7 + 8);
      if (*(int *)(iVar19 + 0x8c) != 0) {
        trap(0x200);
      }
      uVar15 = *(longlong *)(iVar19 + 0x148) + (ulonglong)uVar1;
      *(ulonglong *)(iVar19 + 0x148) = uVar15;
      *(uint *)(iVar19 + 0x88) = (uint)uVar1 + *(int *)(iVar19 + 0x88);
      if (*(ulonglong *)(iVar19 + 0x150) < uVar15) {
        (*(code *)&skb_over_panic)(lVar12,(ulonglong)uVar1,&UNK_0010803c);
      }
      (*(code *)&memcpy)(lVar13,uVar14 + 0x22,*(undefined2 *)(uVar7 + 8));
      bVar8 = false;
    }
    else {
      uVar15 = *(ulonglong *)(uVar7 + 0x18);
      iVar20 = *(byte *)(uVar7 + 0x10) - 1;
      uVar28 = (ulonglong)*(ushort *)(uVar7 + 8);
      if (iVar20 != -1) {
        while( true ) {
          uVar23 = uVar15 & 0xffffffffff;
          uVar17 = uVar23 - 8 & 0xffffffffff;
          if (uVar17 == 0) {
            (*(code *)&cvmx_warn)(&UNK_0010ed60);
          }
          uVar18 = uVar15 >> 0x3b;
          uVar15 = *(ulonglong *)uVar17;
          uVar17 = (ulonglong)
                   (int)(0x800 - ((int)uVar23 + ((int)(uVar23 >> 7) - ((uint)uVar18 & 0xf)) * -0x80)
                        );
          uVar22 = *(undefined8 *)(iVar19 + 0x148);
          if ((longlong)uVar28 <= (longlong)uVar17) {
            uVar17 = uVar28;
          }
          if (*(int *)(iVar19 + 0x8c) != 0) {
            trap(0x200);
          }
          uVar18 = *(longlong *)(iVar19 + 0x148) + (uVar17 & 0xffffffff);
          *(ulonglong *)(iVar19 + 0x148) = uVar18;
          *(int *)(iVar19 + 0x88) = (int)uVar17 + *(int *)(iVar19 + 0x88);
          if (*(ulonglong *)(iVar19 + 0x150) < uVar18) {
            (*(code *)&skb_over_panic)(lVar12,uVar17,&UNK_00107e38);
          }
          if (uVar23 == 0) {
            (*(code *)&cvmx_warn)(&UNK_0010ed60);
          }
          (*(code *)&memcpy)(uVar22,uVar23 | 0x8000000000000000,uVar17);
          iVar20 = iVar20 + -1;
          if (iVar20 == -1) break;
          uVar28 = (ulonglong)((int)uVar28 - (int)uVar17);
        }
      }
      bVar8 = false;
    }
code_r0x00106b70:
    uVar15 = *(ulonglong *)(uVar7 + 8);
    uVar25 = (uint)(uVar15 >> 0x20);
joined_r0x00106b7c:
    plVar29 = (longlong *)lVar12;
    if (((uVar15 >> 0x2a & 0x3f) < 0x29) &&
       (*(longlong *)(cvm_oct_device + (uVar25 >> 10 & 0x3f) * 8) != 0)) {
      lVar13 = *(longlong *)(cvm_oct_device + (uVar25 >> 10 & 0x3f) * 8);
      iVar19 = (int)lVar13;
      setCopReg(2,in_zero,*(undefined4 *)(*(int *)(iVar19 + 0x98) + 0x2fa));
      if ((bVar3) && (imp_port_enable != 0)) {
        lStack_78 = is_port_authorised(lVar12);
        brcmTagDelete(lVar12);
        uVar21 = (*(code *)&eth_type_trans)(lVar12,lVar13);
        *(undefined2 *)((int)plVar29 + 0x9e) = uVar21;
        plVar29[4] = lVar13;
        if ((*(ulonglong *)(uVar7 + 0x10) & 0x5200) != 0) goto code_r0x001073cc;
code_r0x00106c44:
        plVar29[0x13] = plVar29[0x13] & 0xffffffffcfffffffU | 0x20000000;
      }
      else {
        uVar21 = (*(code *)&eth_type_trans)(lVar12,lVar13);
        *(undefined2 *)((int)plVar29 + 0x9e) = uVar21;
        plVar29[4] = lVar13;
        if ((*(ulonglong *)(uVar7 + 0x10) & 0x5200) == 0) goto code_r0x00106c44;
code_r0x001073cc:
        plVar29[0x13] = plVar29[0x13] & 0xffffffffcfffffff;
      }
      if ((*(ulonglong *)(uVar7 + 8) >> 0x2a & 0x3f) < 0x28) {
code_r0x00106cdc:
        lVar16 = *(longlong *)(iVar19 + 0x7d8);
      }
      else {
        if ((uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6 < 0xd0300) {
          *(longlong *)(iVar19 + 0x6f0) = *(longlong *)(iVar19 + 0x6f0) + 1;
        }
        else {
          in_zero = special2(lVar13 + 0x6f0,1,0,0x19);
        }
        if ((uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6 < 0xd0300) {
          *(ulonglong *)(iVar19 + 0x700) =
               *(longlong *)(iVar19 + 0x700) + (ulonglong)*(uint *)(plVar29 + 0x11);
          goto code_r0x00106cdc;
        }
        in_zero = special2(lVar13 + 0x700,(ulonglong)*(uint *)(plVar29 + 0x11),0,0x19);
        lVar16 = *(longlong *)(iVar19 + 0x7d8);
      }
      if (lVar16 == 0) {
        if (lStack_78 != 0) goto code_r0x00107204;
code_r0x001072a0:
        (*(code *)&netif_receive_skb)(lVar12);
        goto code_r0x00106d1c;
      }
      auVar30 = (*(code *)lVar16)(lVar13,uVar14,lVar12);
      uVar15 = Status;
      lVar16 = auVar30._8_8_;
      special2(auVar30._0_8_,lVar16,0,0x3a);
      if (lVar16 == 1) {
        Status = Status & 0xfffffffffffffffe;
        iVar20 = *(int *)((int)plVar29 + 0x134) + -1;
        *(int *)((int)plVar29 + 0x134) = iVar20;
        setCopReg(0,Status,(longlong)Status._4_4_ | uVar15 & 1);
        if (iVar20 == 0) {
          Status = uVar15 & 0xfffffffffffffffe;
          *plVar29 = _cvmx_helper_get_interface_num;
          _cvmx_helper_get_interface_num = lVar12;
          (*(code *)&raise_softirq_irqoff)(2);
          setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffe);
        }
        if ((uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6 < 0xd0300) {
          *(longlong *)(iVar19 + 0x720) = *(longlong *)(iVar19 + 0x720) + 1;
        }
        else {
          in_zero = special2(lVar13 + 0x720,1,0,0x19);
        }
        goto code_r0x00106d1c;
      }
      if (lVar16 == 0) goto code_r0x001072a0;
      if (lVar16 == 2) {
        if (!bVar8) {
          Status = Status & 0xfffffffffffffffe;
          iVar19 = *(int *)((int)plVar29 + 0x134) + -1;
          *(int *)((int)plVar29 + 0x134) = iVar19;
          setCopReg(0,Status,(longlong)Status._4_4_ | uVar15 & 1);
          if (iVar19 == 0) {
            Status = uVar15 & 0xfffffffffffffffe;
            *plVar29 = _cvmx_helper_get_interface_num;
            _cvmx_helper_get_interface_num = lVar12;
            (*(code *)&raise_softirq_irqoff)(2);
            setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffe);
          }
        }
      }
      else if (lVar16 != 2) goto code_r0x00106d1c;
    }
    else {
      lVar13 = (*(code *)&__printk_ratelimit)(0xfa,10);
      if (lVar13 != 0) {
        (*(code *)&printk)(&UNK_0010ee80,*(ulonglong *)(uVar7 + 8) >> 0x2a & 0x3f);
      }
code_r0x00107204:
      uVar15 = Status;
      Status = Status & 0xfffffffffffffffe;
      iVar19 = *(int *)((int)plVar29 + 0x134) + -1;
      *(int *)((int)plVar29 + 0x134) = iVar19;
      setCopReg(0,Status,(longlong)Status._4_4_ | uVar15 & 1);
      if (iVar19 == 0) {
        Status = uVar15 & 0xfffffffffffffffe;
        *plVar29 = _cvmx_helper_get_interface_num;
        _cvmx_helper_get_interface_num = lVar12;
        (*(code *)&raise_softirq_irqoff)(2);
        setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffe);
      }
code_r0x00106d1c:
      if (!bVar8) goto code_r0x00106fe8;
      iRam000007fc = 1;
      uVar25 = 0x3fffffff;
      if ((longlong)uVar14 >> 0x3e != 3) {
        uVar25 = 0xffffffff;
      }
      SYNC(4);
      SYNC(4);
      *(undefined8 *)(uVar7 & uVar25) = 1;
    }
  }
code_r0x00106d6c:
  iVar24 = iVar24 + 1;
  SYNC(2);
  uVar14 = *(ulonglong *)((int)in_zero + -0x8000);
  goto joined_r0x001068b0;
}

