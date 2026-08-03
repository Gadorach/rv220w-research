/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc07c5c
 * Function: FUN_ffffffffbfc07c5c
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Removing unreachable block (ram,0xffffffffbfc08590) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

undefined4
FUN_ffffffffbfc07c5c
          (undefined4 param_1,int *param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  short sVar11;
  undefined8 in_zero;
  undefined8 extraout_at;
  long lVar12;
  int *piVar13;
  char *pcVar14;
  int iVar21;
  char cVar24;
  uint uVar22;
  undefined4 uVar23;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  undefined8 uVar19;
  ulong *puVar20;
  undefined8 uVar25;
  long lVar26;
  undefined8 extraout_v1;
  int iVar28;
  uint uVar29;
  char *pcVar27;
  uint uVar30;
  undefined8 unaff_s0;
  int *piVar31;
  undefined1 uVar37;
  uint *puVar32;
  ulong uVar33;
  ulong uVar34;
  ulong uVar35;
  undefined8 unaff_s1;
  int *piVar38;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  uint uVar40;
  undefined1 uVar41;
  undefined1 *puVar39;
  undefined8 unaff_s4;
  int *piVar42;
  uint uVar45;
  ulong uVar43;
  ulong *puVar44;
  undefined8 unaff_s5;
  int iVar46;
  undefined8 unaff_s6;
  ulong uVar47;
  undefined8 unaff_s7;
  int iVar48;
  code *pcVar49;
  long in_k0;
  long lVar50;
  undefined8 unaff_s8;
  uint uVar52;
  undefined8 in_ra;
  undefined1 auVar53 [12];
  int iVar36;
  int iVar51;
  
  iVar51 = (int)&stack0x00000000;
  lVar50 = (long)(iVar51 + -0x200);
  *(undefined1 **)(lVar50 + 0x1e0) = &_gp;
  *(undefined4 *)(lVar50 + 400) = param_5;
  *(undefined4 *)(lVar50 + 0x180) = param_1;
  iVar46 = DAT_ffffffffbfc436f4;
  iVar36 = DAT_ffffffffbfc436ec;
  iVar28 = param_2[1];
  *(undefined8 *)(lVar50 + 0x1c0) = unaff_s4;
  iVar21 = *param_2;
  piVar42 = (int *)(long)iVar21;
  *(int *)(lVar50 + 0x184) = (int)param_2;
  *(undefined4 *)(lVar50 + 0x18c) = param_4;
  *(undefined8 *)(lVar50 + 0x1d8) = unaff_s7;
  *(undefined8 *)(lVar50 + 0x1f0) = in_ra;
  *(undefined8 *)(lVar50 + 0x1e8) = unaff_s8;
  *(undefined8 *)(lVar50 + 0x1d0) = unaff_s6;
  *(undefined8 *)(lVar50 + 0x1c8) = unaff_s5;
  *(undefined8 *)(lVar50 + 0x1b8) = unaff_s3;
  *(undefined8 *)(lVar50 + 0x1b0) = unaff_s2;
  *(undefined8 *)(lVar50 + 0x1a8) = unaff_s1;
  *(undefined8 *)(lVar50 + 0x1a0) = unaff_s0;
  *(int *)(lVar50 + 0x150) = iVar28;
  *(undefined4 *)(lVar50 + 0x194) = param_6;
  *(undefined4 *)(lVar50 + 0x198) = param_7;
  *(int *)(lVar50 + 0x188) = (int)param_3;
  iVar48 = param_2[2];
  (*(code *)(long)(iVar36 + 0x6910))
            (iVar46 + -0x65a8,*(undefined4 *)(lVar50 + 0x204),param_3,*(undefined4 *)(lVar50 + 400))
  ;
  iVar28 = *piVar42;
  if (iVar28 == 0) {
    iVar28 = DAT_ffffffffbfc436f4 + -0x6560;
    goto LAB_ffffffffbfc07ed4;
  }
  *(undefined4 *)(lVar50 + 0x13c) = 0;
  iVar46 = 0;
  *(undefined4 *)(lVar50 + 0x11c) = 0;
  piVar38 = piVar42;
  iVar36 = iVar21;
  while( true ) {
    iVar36 = iVar36 + 8;
    piVar31 = (int *)(long)iVar36;
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43a50)(iVar28,*(undefined4 *)(lVar50 + 0x13c),0);
    if (lVar12 == 0) break;
    iVar28 = *(int *)(lVar50 + 0x13c);
    uVar29 = *(uint *)(lVar50 + 0x180) >> 8 & 0xffff;
    *(int *)(lVar50 + 0x13c) = iVar28 + 1;
    if ((((uVar29 == 0xd01) || (uVar29 == 0xd02)) || (uVar29 == 0xd04)) ||
       ((uVar29 == 0xd06 || (uVar29 == 0xd07)))) {
      *(undefined4 *)(lVar50 + 0x11c) = 1;
      piVar13 = (int *)(long)(iVar21 + 0x40);
    }
    else {
      piVar13 = (int *)(long)(iVar21 + 0x40);
      if (piVar38[1] != 0) {
        lVar12 = (*(code *)(long)DAT_ffffffffbfc43a50)(piVar38[1],iVar28 + 1,0);
        if (lVar12 == 0) {
          piVar13 = (int *)(long)(iVar21 + 0x40);
          if (*(int *)(lVar50 + 0x11c) == 0) goto LAB_ffffffffbfc07df0;
        }
        else {
          *(undefined4 *)(lVar50 + 0x11c) = 1;
          *(int *)(lVar50 + 0x13c) = *(int *)(lVar50 + 0x13c) + 1;
        }
        setCopReg(2,in_zero,*(undefined4 *)((long)*(int *)(lVar50 + 0x13c) + 9));
        iVar46 = iVar46 + 1;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6528);
        piVar13 = (int *)(long)(iVar21 + 0x40);
      }
    }
LAB_ffffffffbfc07df0:
    if ((piVar31 == piVar13) || (iVar28 = *piVar31, piVar38 = piVar31, iVar28 == 0)) break;
  }
  (*(code *)(long)DAT_ffffffffbfc43e68)
            (*(undefined4 *)(lVar50 + 0x180),*(undefined4 *)(lVar50 + 0x18c),
             *(undefined4 *)(lVar50 + 0x188),*(undefined4 *)(lVar50 + 400),
             *(undefined4 *)(lVar50 + 0x204),*(undefined4 *)(lVar50 + 0x20c));
  if (*(int *)(lVar50 + 0x180) == 0xd0000) {
    *(int *)(lVar50 + 0x150) = DAT_ffffffffbfc43ccc;
    iVar48 = *(int *)(lVar50 + 0x150);
  }
  else {
    if (iVar48 == 0) {
      iVar48 = DAT_ffffffffbfc43ccc;
    }
    iVar28 = *(int *)(lVar50 + 0x150);
    if (*(int *)(lVar50 + 0x150) == 0) {
      iVar28 = DAT_ffffffffbfc43ccc;
    }
    *(int *)(lVar50 + 0x150) = iVar28;
  }
  pcVar14 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x64f0);
  iVar28 = DAT_ffffffffbfc436f4;
  if (pcVar14 == (char *)0x0) {
LAB_ffffffffbfc07eb8:
    *(undefined4 *)(lVar50 + 300) = 0;
    iVar28 = *(int *)(lVar50 + 0x13c);
  }
  else {
    iVar21 = DAT_ffffffffbfc436f4 + -0x64e0;
    cVar2 = *pcVar14;
    do {
      cVar3 = *(char *)(long)iVar21;
      pcVar14 = (char *)(long)((int)pcVar14 + 1);
      iVar21 = iVar21 + 1;
      cVar24 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar14;
      cVar24 = cVar3;
    } while (bVar1);
    if (cVar24 != cVar3) goto LAB_ffffffffbfc07eb8;
    pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
    *(undefined4 *)(lVar50 + 300) = 1;
    (*pcVar49)(iVar28 + -0x64d8);
    iVar28 = *(int *)(lVar50 + 0x13c);
  }
  if (iVar28 == 0) {
    iVar28 = DAT_ffffffffbfc436f4 + -0x64a8;
LAB_ffffffffbfc07ed4:
    (*(code *)(long)DAT_ffffffffbfc4400c)(iVar28);
    return 0xffffffff;
  }
  uVar29 = *(uint *)(lVar50 + 0x180) & 0xffff10;
  if ((uVar29 == 0xd0110) || (uVar22 = *(uint *)(lVar50 + 0x180), uVar29 == 0xd0210)) {
    *(undefined4 *)(lVar50 + 0x11c) = 0;
    uVar22 = *(uint *)(lVar50 + 0x180);
  }
  uVar22 = uVar22 >> 8 & 0xffff;
  if ((uVar22 == 0xd01) && ((*(int *)(lVar50 + 0x194) == 0xe || (*(int *)(lVar50 + 0x194) == 0xb))))
  {
    *(undefined4 *)(lVar50 + 0x11c) = 0;
LAB_ffffffffbfc07fb4:
    cVar2 = (char)*piVar42;
  }
  else {
    if ((*(int *)(lVar50 + 0x11c) == 0) ||
       (pcVar14 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x6488),
       iVar28 = DAT_ffffffffbfc436f4, pcVar14 == (char *)0x0)) goto LAB_ffffffffbfc07fb4;
    iVar21 = DAT_ffffffffbfc436f4 + -0x64e0;
    cVar2 = *pcVar14;
    do {
      cVar3 = *(char *)(long)iVar21;
      pcVar14 = (char *)(long)((int)pcVar14 + 1);
      iVar21 = iVar21 + 1;
      cVar24 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar14;
      cVar24 = cVar3;
    } while (bVar1);
    if (cVar24 != cVar3) goto LAB_ffffffffbfc07fb4;
    pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
    *(undefined4 *)(lVar50 + 0x11c) = 0;
    (*pcVar49)(iVar28 + -0x6478);
    cVar2 = (char)*piVar42;
  }
  lVar12 = (long)DAT_ffffffffbfc43f40;
  if (cVar2 == '\0') {
    uVar40 = 0;
    *(undefined4 *)(lVar50 + 0x140) = 0;
    uVar30 = 0;
    *(undefined4 *)(lVar50 + 0x148) = 0;
    *(undefined4 *)(lVar50 + 0x144) = 1;
LAB_ffffffffbfc08010:
    iVar46 = iVar46 + 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6428,uVar40);
  }
  else {
    bVar4 = *(byte *)(lVar12 + 4);
    uVar40 = (uint)bVar4;
    bVar5 = *(byte *)(lVar12 + 5);
    *(uint *)(lVar50 + 0x140) = (uint)*(byte *)(lVar12 + 0xd);
    uVar30 = (uint)*(byte *)(lVar12 + 3);
    bVar6 = *(byte *)(lVar12 + 0x11);
    *(uint *)(lVar50 + 0x144) = (bVar5 & 7) + 1;
    *(uint *)(lVar50 + 0x148) = (uint)bVar6;
    if (6 < bVar4 - 7) goto LAB_ffffffffbfc08010;
  }
  iVar28 = *(int *)(lVar50 + 0x148);
  if (0xb < uVar30 - 7) {
    iVar46 = iVar46 + 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6400,uVar30);
    iVar28 = *(int *)(lVar50 + 0x148);
  }
  if (iVar28 == 8) {
    iVar28 = 3;
  }
  else {
    iVar28 = 2;
    if (*(int *)(lVar50 + 0x148) != 4) {
      iVar28 = 0;
    }
  }
  *(uint *)(lVar50 + 0xfc) = (long)*(int *)(lVar50 + 0x144) < 2 ^ 1;
  if (uVar22 == 0xd01) {
    iVar21 = *(int *)(lVar50 + 0xfc);
    if (((*(short *)(in_k0 + 0x44) == 9) &&
        (iVar21 = *(int *)(lVar50 + 0xfc), *(char *)(in_k0 + 0x46) == '\x01')) &&
       (*(char *)(in_k0 + 0x47) == '\0')) {
      in_zero = special2((long)*(int *)(lVar50 + 0x144),0xd0000,1,0x2f);
      if (*(int *)(lVar50 + 0x13c) < 2) {
        *(undefined4 *)(lVar50 + 0xfc) = 0xd0000;
      }
      else {
        *(undefined4 *)(lVar50 + 0xfc) = 1;
      }
      iVar21 = *(int *)(lVar50 + 0xfc);
    }
    iVar28 = uVar40 + iVar28 + 2;
    *(int *)(lVar50 + 0xe4) = iVar28;
    iVar28 = uVar30 + iVar28 + iVar21;
LAB_ffffffffbfc08144:
    *(int *)(lVar50 + 0xe0) = iVar28;
    sVar11 = *(short *)(in_k0 + 0x44);
    uVar25 = special2((long)*(int *)(lVar50 + 0x13c),
                      (ulong)(1L << (long)(*(int *)(lVar50 + 0xe0) + *(int *)(lVar50 + 0x11c))) >>
                      0x14,0,3);
    *(int *)(lVar50 + 0x100) = (int)uVar25;
    iVar28 = DAT_ffffffffbfc436f4;
    if (((sVar11 == 9) && (*(char *)(in_k0 + 0x46) == '\x01')) &&
       ((*(char *)(in_k0 + 0x47) == '\0' && (*(int *)(lVar50 + 0xfc) != 0)))) {
      pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
      *(uint *)(lVar50 + 0x100) = *(uint *)(lVar50 + 0x100) >> 1;
      (*pcVar49)(iVar28 + -0x63b0);
    }
  }
  else {
    if (uVar22 == 0xd02) {
      iVar28 = uVar40 + iVar28 + 1;
      *(int *)(lVar50 + 0xe4) = iVar28;
      iVar28 = iVar28 + uVar30 + *(int *)(lVar50 + 0xfc);
      goto LAB_ffffffffbfc08144;
    }
    if ((uVar22 != 0xd00) && (uVar22 != 0xd03)) {
      if (uVar22 == 0xd04) {
        iVar21 = uVar40 + iVar28 + 2;
      }
      else {
        iVar21 = uVar40 + 2;
        if (uVar22 != 0xd07) {
          if (uVar22 != 0xd06) {
            (*(code *)(long)DAT_ffffffffbfc4400c)
                      (DAT_ffffffffbfc436f4 + -0x63d8,*(undefined4 *)(lVar50 + 0x180));
            iVar28 = uVar40 + iVar28 + 1;
            *(int *)(lVar50 + 0xe4) = iVar28;
            iVar28 = iVar28 + uVar30 + *(int *)(lVar50 + 0xfc);
            goto LAB_ffffffffbfc081bc;
          }
          iVar21 = uVar40 + 1;
        }
        iVar21 = iVar21 + iVar28;
      }
      *(int *)(lVar50 + 0xe4) = iVar21;
      iVar28 = iVar21 + uVar30 + *(int *)(lVar50 + 0xfc);
      goto LAB_ffffffffbfc08144;
    }
    iVar28 = uVar40 + 3 + iVar28;
    *(int *)(lVar50 + 0xe4) = iVar28;
    iVar28 = iVar28 + uVar30 + *(int *)(lVar50 + 0xfc);
LAB_ffffffffbfc081bc:
    *(int *)(lVar50 + 0xe0) = iVar28;
    uVar25 = special2((long)*(int *)(lVar50 + 0x13c),
                      (ulong)(1L << (long)*(int *)(lVar50 + 0xe0)) >> 0x14,0,3);
    *(int *)(lVar50 + 0x100) = (int)uVar25;
  }
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))
            (DAT_ffffffffbfc436f4 + -0x6370,uVar30,uVar40,*(undefined4 *)(lVar50 + 0x148),
             *(undefined4 *)(lVar50 + 0x144),*(undefined4 *)(lVar50 + 0x140),
             *(undefined4 *)(lVar50 + 0x100));
  lVar12 = (long)DAT_ffffffffbfc43f40;
  if ((char)*piVar42 == '\0') {
    *(undefined4 *)(lVar50 + 0x17c) = 0;
    uVar37 = 0;
    *(undefined4 *)(lVar50 + 0xd8) = 0;
    uVar41 = 0;
    *(undefined4 *)(lVar50 + 0xd4) = 0;
    *(undefined4 *)(lVar50 + 0xd0) = 0;
    *(undefined4 *)(lVar50 + 0xcc) = 0;
    *(undefined4 *)(lVar50 + 200) = 0;
    *(undefined4 *)(lVar50 + 0xc4) = 0;
    *(undefined4 *)(lVar50 + 0xc0) = 0;
    *(undefined4 *)(lVar50 + 0xbc) = 0;
    *(undefined4 *)(lVar50 + 0xa0) = 0;
    *(undefined4 *)(lVar50 + 0x9c) = 0;
    *(undefined4 *)(lVar50 + 0x8c) = 0;
    uVar30 = 0;
    uVar40 = 0;
LAB_ffffffffbfc082ec:
    uVar45 = uVar40;
    uVar52 = uVar30;
    *(undefined4 *)(lVar50 + 0x154) = *(undefined4 *)((long)*(int *)(lVar50 + 0x184) + 0xc);
  }
  else {
    bVar4 = *(byte *)(lVar12 + 0xb);
    bVar5 = *(byte *)(lVar12 + 0x10);
    bVar6 = *(byte *)(lVar12 + 0xc);
    bVar7 = *(byte *)(lVar12 + 0x19);
    *(uint *)(lVar50 + 0x8c) = (uint)((*(byte *)(lVar12 + 0x14) & 0x11) != 0);
    *(uint *)(lVar50 + 0x9c) = bVar4 >> 1 & 1;
    bVar4 = *(byte *)(lVar12 + 0x1b);
    bVar8 = *(byte *)(lVar12 + 0x1c);
    *(uint *)(lVar50 + 0x17c) = (uint)bVar5;
    uVar37 = *(undefined1 *)(lVar12 + 9);
    bVar5 = *(byte *)(lVar12 + 0x1d);
    *(uint *)(lVar50 + 0xd8) = (uint)bVar6;
    bVar6 = *(byte *)(lVar12 + 0x12);
    uVar45 = (uint)bVar6;
    bVar9 = *(byte *)(lVar12 + 0x24);
    uVar41 = *(undefined1 *)(lVar12 + 0x17);
    *(uint *)(lVar50 + 0xd4) = (uint)bVar7;
    *(uint *)(lVar50 + 0xd0) = (uint)bVar4;
    bVar4 = *(byte *)(lVar12 + 0x25);
    bVar7 = *(byte *)(lVar12 + 0x28);
    *(uint *)(lVar50 + 0xcc) = (uint)bVar8;
    bVar8 = *(byte *)(lVar12 + 0x1e);
    uVar52 = (uint)bVar8;
    bVar10 = *(byte *)(lVar12 + 0x2a);
    *(uint *)(lVar50 + 200) = (uint)bVar5;
    *(uint *)(lVar50 + 0xc4) = (uint)bVar9;
    *(uint *)(lVar50 + 0xc0) = (uint)bVar4;
    *(uint *)(lVar50 + 0xbc) = (uint)bVar7;
    *(uint *)(lVar50 + 0xa0) = (uint)bVar10;
    uVar30 = (uint)bVar8;
    uVar40 = (uint)bVar6;
    if (*(int *)(lVar50 + 0x8c) == 0) goto LAB_ffffffffbfc082ec;
    *(undefined4 *)(lVar50 + 0x154) = *(undefined4 *)((long)*(int *)(lVar50 + 0x184) + 0x1c);
  }
  if (uVar29 == 0xd0110) {
    *(undefined4 *)(lVar50 + 0xdc) = 0;
  }
  else {
    *(uint *)(lVar50 + 0xdc) = (uint)(uVar29 != 0xd0210);
  }
  if (*(int *)(lVar50 + 0x194) == 0xe) {
    *(undefined4 *)(lVar50 + 0xdc) = 0;
  }
  else {
    uVar23 = *(undefined4 *)(lVar50 + 0x9c);
    if (*(int *)(lVar50 + 0xdc) == 0) {
      uVar23 = 0;
    }
    *(undefined4 *)(lVar50 + 0xdc) = uVar23;
  }
  if (uVar22 == 0xd01) {
    uVar25 = 0x40;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x20;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7c20;
  }
  else if (uVar22 == 0xd02) {
    uVar25 = 0x20;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x10;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7bf0;
  }
  else if (uVar22 == 0xd03) {
    uVar25 = 0x80;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x40;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7bc0;
  }
  else if (uVar22 == 0xd04) {
    uVar25 = 0x40;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x20;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7b90;
  }
  else if (uVar22 == 0xd07) {
    uVar25 = 0x40;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x20;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7b60;
  }
  else if (uVar22 == 0xd06) {
    uVar25 = 0x20;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x10;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7b30;
  }
  else {
    uVar25 = 0x80;
    if (*(int *)(lVar50 + 0x11c) == 0) {
      uVar25 = 0x40;
    }
    if (*(int *)(lVar50 + 0xdc) == 0) {
      iVar28 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    else {
      iVar28 = DAT_ffffffffbfc436f4 + -0x6320;
    }
    iVar21 = DAT_ffffffffbfc436f4 + -0x7b00;
  }
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(iVar21,uVar25,iVar28);
  pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6314);
  uVar23 = (*pcVar49)(uVar37);
  *(undefined4 *)(lVar50 + 0x20) = uVar23;
  uVar23 = (*pcVar49)(uVar41);
  *(undefined4 *)(lVar50 + 0x24) = uVar23;
  uVar23 = (*pcVar49)(*(undefined4 *)(lVar50 + 0xd4));
  *(undefined4 *)(lVar50 + 0x28) = uVar23;
  setCopReg(2,in_zero,*(undefined4 *)((long)((int)uVar45 >> 7) + 8));
  uVar29 = 1000000000 / (*(uint *)(lVar50 + 0x188) / 1000);
  if (*(uint *)(lVar50 + 0x188) / 1000 == 0) {
    trap(7);
  }
  *(uint *)(lVar50 + 0x14c) = uVar29;
  iVar28 = 5;
  puVar32 = (uint *)(long)(iVar51 + -0x1d8);
  do {
    *(int *)(lVar50 + 0x70) = iVar28;
    setCopReg(2,in_zero,
              *(undefined4 *)((long)((int)uVar45 >> (*(uint *)(lVar50 + 0x70) & 0x1f)) + 7));
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x7aa0,*(uint *)(lVar50 + 0x70),*puVar32);
    iVar21 = DAT_ffffffffbfc436f4;
    uVar30 = *(uint *)(lVar50 + 0xd8);
    if (*puVar32 <= uVar29) goto LAB_ffffffffbfc08658;
    puVar32 = (uint *)(long)((int)puVar32 + -4);
    iVar28 = *(int *)(lVar50 + 0x70) + 1;
  } while (puVar32 != (uint *)(long)(iVar51 + -0x1e4));
  pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
  *(undefined4 *)(lVar50 + 0x70) = 7;
  (*pcVar49)(iVar21 + -0x7a60);
  uVar30 = *(uint *)(lVar50 + 0xd8);
LAB_ffffffffbfc08658:
  if ((uVar30 & 0x7f) < 6) {
    *(undefined4 *)(lVar50 + 0x6c) =
         *(undefined4 *)(long)(int)((uVar30 & 0x7f) * 4 + DAT_ffffffffbfc436f0 + 0x61f0);
  }
  else {
    pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
    iVar28 = DAT_ffffffffbfc436f4 + -0x7a10;
    *(undefined4 *)(lVar50 + 0x6c) = 0xffffffff;
    (*pcVar49)(iVar28,*(undefined4 *)(lVar50 + 0xd8));
  }
  pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6360);
  uVar23 = (*pcVar49)(*(undefined4 *)(lVar50 + 0xd0));
  *(undefined4 *)(lVar50 + 0x68) = uVar23;
  uVar23 = (*pcVar49)(*(undefined4 *)(lVar50 + 0xcc));
  *(undefined4 *)(lVar50 + 100) = uVar23;
  uVar23 = (*pcVar49)(*(undefined4 *)(lVar50 + 200));
  *(undefined4 *)(lVar50 + 0x60) = uVar23;
  *(uint *)(lVar50 + 0x5c) = uVar52 * 1000;
  uVar23 = (*pcVar49)(*(undefined4 *)(lVar50 + 0xc4));
  *(undefined4 *)(lVar50 + 0x58) = uVar23;
  uVar23 = (*pcVar49)(*(undefined4 *)(lVar50 + 0xc0));
  *(undefined4 *)(lVar50 + 0x54) = uVar23;
  iVar28 = *(int *)(lVar50 + 0xa0) * 1000 +
           *(char *)(long)(int)(((uint)((ulong)(long)*(int *)(lVar50 + 0xbc) >> 1) & 7) +
                               DAT_ffffffffbfc436f0 + 0x6210) * 10;
  setCopReg(2,in_zero,*(undefined4 *)((long)*(int *)(lVar50 + 0xbc) + 5));
  *(int *)(lVar50 + 0x50) = iVar28;
  *(int *)(lVar50 + 0x50) = iVar28 + 0x3e800;
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x79e8,*(undefined4 *)(lVar50 + 0x14c));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x79b0,*(undefined4 *)(lVar50 + 0x70));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x7978,*(undefined4 *)(lVar50 + 0x6c));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x7940,*(undefined4 *)(lVar50 + 0x68));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x7908,*(undefined4 *)(lVar50 + 100));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x78d0,*(undefined4 *)(lVar50 + 0x60));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x7898,*(undefined4 *)(lVar50 + 0x5c));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x7860,*(undefined4 *)(lVar50 + 0x58));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x7828,*(undefined4 *)(lVar50 + 0x54));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x77f0,*(undefined4 *)(lVar50 + 0x50));
  iVar28 = *(int *)(lVar50 + 0x148);
  if ((iVar28 != 4) && (iVar28 != 8)) {
    iVar46 = iVar46 + 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x77b8,iVar28);
  }
  if (1 < *(int *)(lVar50 + 0x144) - 1U) {
    iVar46 = iVar46 + 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7780,*(int *)(lVar50 + 0x144));
  }
  iVar28 = *(int *)(lVar50 + 0x140);
  if ((iVar28 != 8) && (iVar28 != 0x10)) {
    iVar46 = iVar46 + 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7758,iVar28);
  }
  lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7728);
  if (lVar12 == 0) {
LAB_ffffffffbfc08918:
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x76a8,*(undefined4 *)(lVar50 + 0x154));
    if (*(int *)(lVar50 + 0x154) == 0) goto LAB_ffffffffbfc0893c;
  }
  else {
    iVar21 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
    iVar28 = DAT_ffffffffbfc436f4;
    if (*(int *)(lVar50 + 0x154) != 0) {
      pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
      if (*(int *)(lVar50 + 0x154) != iVar21) {
        *(int *)(lVar50 + 0x154) = iVar21;
        (*pcVar49)(iVar28 + -0x7718);
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x76e8,iVar21);
      }
      goto LAB_ffffffffbfc08918;
    }
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x76a8,0);
LAB_ffffffffbfc0893c:
    iVar46 = iVar46 + 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7670);
  }
  if (iVar46 != 0) {
    return 0xffffffff;
  }
  if ((uVar22 == 0xd04) || (uVar22 == 0xd07)) {
    *(undefined4 *)(lVar50 + 0x4c) = 0;
    uVar47 = 0;
    uVar15 = 0;
LAB_ffffffffbfc08aa0:
    iVar28 = *(int *)(lVar50 + 0x13c);
  }
  else {
    uVar25 = special2((long)*(int *)(lVar50 + 0x180),0xd0000,0,0x2a);
    uVar29 = *(uint *)(lVar50 + 0x14c);
    iVar28 = *(int *)(in_k0 + 4);
    uVar30 = (uVar29 * (int)uVar25 + *(int *)(lVar50 + 0x154) * 4) / uVar29;
    if (uVar29 == 0) {
      trap(7);
    }
    uVar29 = 0xe;
    if ((int)uVar30 < 0xf) {
      uVar29 = uVar30;
    }
    iVar21 = *(int *)(long)(int)(uVar29 * 4 + DAT_ffffffffbfc436f0 + 0x6218);
    uVar47 = (long)iVar21 & 0xff;
    *(uint *)(lVar50 + 0x4c) = (int)(short)((uint)iVar21 >> 0x10) & 1;
    setCopReg(2,(long)iVar28,*(undefined4 *)((long)iVar28 + 0x36));
    uVar15 = (ulong)(long)iVar21 >> 8 & 1;
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7640);
    if (lVar12 != 0) {
      uVar47 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7630,uVar47);
    }
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7600);
    if (lVar12 != 0) {
      uVar15 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x75f0,uVar15);
    }
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x75b8);
    if (lVar12 == 0) goto LAB_ffffffffbfc08aa0;
    uVar23 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
    *(undefined4 *)(lVar50 + 0x4c) = uVar23;
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x75a8,*(undefined4 *)(lVar50 + 0x4c));
    iVar28 = *(int *)(lVar50 + 0x13c);
  }
  iVar28 = iVar28 + -1;
  if (3 < iVar28) {
    iVar28 = 3;
  }
  if (*(int *)(lVar50 + 0xfc) == 0) {
    iVar48 = *(int *)(lVar50 + 0x150);
  }
  iVar48 = iVar48 + iVar28 * 0x18;
  *(int *)(lVar50 + 0x168) = iVar48;
  uVar33 = (ulong)*(int *)((long)iVar48 + 0xc);
  if ((uVar22 == 0xd01) || (uVar22 == 0xd02)) {
    iVar28 = *(int *)(lVar50 + 0x168);
    if (*(uint *)(lVar50 + 0x14c) < 0xea7) {
      if (*(int *)(lVar50 + 0x144) != 1) {
        uVar33 = 3;
      }
      iVar28 = *(int *)(lVar50 + 0x168);
    }
    piVar42 = (int *)(long)iVar28;
    uVar43 = (ulong)piVar42[5];
    iVar28 = *piVar42;
    *(int *)(lVar50 + 0x3c) = piVar42[1];
    if (uVar22 == 0xd01) goto LAB_ffffffffbfc08b58;
    lVar12 = (long)*(int *)(lVar50 + 0x168);
    if (uVar22 != 0xd02) goto LAB_ffffffffbfc08b30;
LAB_ffffffffbfc08b5c:
    *(undefined4 *)(lVar50 + 0x34) = *(undefined4 *)(lVar12 + 8);
  }
  else {
    piVar42 = (int *)(long)*(int *)(lVar50 + 0x168);
    uVar43 = (ulong)piVar42[5];
    iVar28 = *piVar42;
    *(int *)(lVar50 + 0x3c) = piVar42[1];
LAB_ffffffffbfc08b30:
    if ((uVar22 == 0xd04) || (uVar22 == 0xd06)) {
LAB_ffffffffbfc08b58:
      lVar12 = (long)*(int *)(lVar50 + 0x168);
      goto LAB_ffffffffbfc08b5c;
    }
    lVar12 = (long)*(int *)(lVar50 + 0x168);
    if (uVar22 == 0xd07) goto LAB_ffffffffbfc08b5c;
    *(undefined4 *)(lVar50 + 0x34) = 0;
  }
  setCopReg(2,(long)*(int *)((long)*(int *)(lVar50 + 0x168) + 0x10),
            *(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x6f));
  *(int *)(lVar50 + 0x38) = *(int *)((long)*(int *)(lVar50 + 0x168) + 0x10);
  if (*(int *)(lVar50 + 0x180) != 0xd0000) {
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7570);
    if (lVar12 != 0) {
      uVar43 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7568,uVar43);
    }
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7538);
    if (lVar12 != 0) {
      uVar33 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7528,uVar33);
    }
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x74f0);
    if (lVar12 != 0) {
      iVar28 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x74e0,iVar28);
    }
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x74a8);
    if (lVar12 != 0) {
      uVar25 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      iVar21 = DAT_ffffffffbfc436f4;
      pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
      *(int *)(lVar50 + 0x3c) = (int)uVar25;
      (*pcVar49)(iVar21 + -0x7498,uVar25);
    }
    if ((((uVar22 == 0xd01) || (uVar22 == 0xd02)) || (uVar22 == 0xd04)) ||
       ((uVar22 == 0xd06 || (uVar22 == 0xd07)))) {
      lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7460);
      if (lVar12 != 0) {
        uVar25 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
        iVar21 = DAT_ffffffffbfc436f4;
        pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
        *(int *)(lVar50 + 0x34) = (int)uVar25;
        (*pcVar49)(iVar21 + -0x7450,uVar25);
      }
    }
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7418);
    if (lVar12 != 0) {
      uVar25 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar12,0,0);
      iVar21 = DAT_ffffffffbfc436f4;
      pcVar49 = (code *)(long)DAT_ffffffffbfc4400c;
      *(int *)(lVar50 + 0x38) = (int)uVar25;
      (*pcVar49)(iVar21 + -0x7408,uVar25);
    }
  }
  if (iVar28 == 0) {
    *(undefined4 *)(lVar50 + 0x38) = 0;
  }
  else if (*(int *)(lVar50 + 0x38) == 0) {
    iVar28 = 0;
  }
  lVar12 = 1;
  if ((*(int *)(lVar50 + 0x194) == 2) && (*(int *)(lVar50 + 0x198) == 1)) {
    lVar12 = 0;
    uVar33 = 2;
  }
  uVar33 = uVar43 & 3 | (uVar33 & 3) << 2;
  if ((uVar22 == 0xd04) || (uVar22 == 0xd07)) {
    uVar47 = uVar33 | (uVar15 & (long)*(int *)(lVar50 + 0x4c) & 1) << 8 | lVar12 << 9;
LAB_ffffffffbfc08ddc:
    if (uVar22 == 0xd02) {
      uVar47 = uVar47 | ((long)*(int *)(lVar50 + 0x11c) & 1U) << 10 |
               ((long)*(int *)(lVar50 + 300) & 1U) << 0xe |
               ((long)*(int *)(lVar50 + 0x8c) & 1U) << 0xf;
      goto LAB_ffffffffbfc08e44;
    }
    if (uVar22 == 0xd04) {
      iVar21 = *(int *)(lVar50 + 0x11c);
LAB_ffffffffbfc08e34:
      uVar33 = (long)iVar21 ^ 1;
    }
    else {
      uVar33 = (ulong)*(int *)(lVar50 + 0x11c);
      if (uVar22 == 0xd07) {
        iVar21 = *(int *)(lVar50 + 0x11c);
        goto LAB_ffffffffbfc08e34;
      }
    }
    uVar47 = uVar47 | (uVar33 & 1) << 10 | ((long)*(int *)(lVar50 + 300) & 1U) << 0xe |
             ((long)*(int *)(lVar50 + 0x8c) & 1U) << 0xf | 0x7c0000;
  }
  else {
    lVar26 = 2;
    if ((long)*(int *)(lVar50 + 300) == 0) {
      lVar26 = 1;
    }
    uVar33 = uVar33 | (uVar47 & 3) << 4 | lVar26 << 6 |
             (uVar15 & (long)*(int *)(lVar50 + 0x4c) & 1) << 8;
    uVar47 = uVar33 | lVar12 << 9;
    if (uVar22 != 0xd01) goto LAB_ffffffffbfc08ddc;
    uVar47 = uVar33 | lVar12 << 9 | (((long)*(int *)(lVar50 + 0x11c) ^ 1U) & 1) << 10 |
             ((long)*(int *)(lVar50 + 300) & 1U) << 0xe |
             ((long)*(int *)(lVar50 + 0x8c) & 1U) << 0xf;
LAB_ffffffffbfc08e44:
    uVar47 = uVar47 | 0x7c0800;
  }
  lVar12 = ((long)*(int *)(lVar50 + 0x204) & 1U) * 0x60000000;
  iVar21 = DAT_ffffffffbfc436ec + 0x62c8;
  *(undefined1 **)(lVar50 + 0x160) = &DAT_8001180088000010 + lVar12;
  uVar29 = 1000000000 / (*(uint *)(lVar50 + 0x18c) / 1000);
  uVar33 = (ulong)(int)uVar29;
  if (*(uint *)(lVar50 + 0x18c) / 1000 == 0) {
    trap(7);
  }
  uVar43 = uVar47;
  (*(code *)(long)iVar21)(&DAT_8001180088000010 + lVar12,uVar47);
  (*(code *)(long)DAT_ffffffffbfc44014)(6000);
  if ((((uVar22 == 0xd03) || (uVar22 == 0xd04)) || (uVar22 == 0xd06)) || (uVar22 == 0xd07)) {
    uVar29 = (uint)(*(int *)(lVar50 + 0x14c) * 10) / uVar29;
    if (uVar33 == 0) {
      trap(7);
    }
    uVar34 = 3;
    uVar33 = uVar43;
    if (0xe < (int)uVar29) {
      if ((int)uVar29 < 0x14) {
        uVar34 = 2;
      }
      else {
        uVar34 = (ulong)((int)uVar29 < 0x1e);
      }
    }
  }
  else {
    uVar34 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62f8))
                       (*(undefined4 *)(lVar50 + 0x14c),uVar33);
    if ((long)uVar34 < 1) {
      uVar34 = 1;
    }
    if (3 < (long)uVar34) {
      uVar34 = 3;
    }
  }
  if (((uVar22 == 0xd00) || (uVar22 == 0xd03)) ||
     ((uVar22 == 0xd04 || (iVar21 = *(int *)(lVar50 + 0x180), uVar22 != 0xd07)))) {
    iVar21 = *(int *)(lVar50 + 0x180);
  }
  uVar43 = 1;
  if (iVar21 != 0xd0000) {
    uVar33 = (ulong)*(int *)(lVar50 + 0x8c);
    if (*(int *)(lVar50 + 300) == 0) {
      uVar43 = (ulong)(uVar33 == 0);
    }
    else {
      uVar43 = 1;
    }
    uVar43 = uVar43 << 10 | 1;
  }
  setCopReg(2,uVar33,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x16));
  if (*(int *)(lVar50 + 0x180) != 0xd0000) {
    lVar26 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x73d0);
    if (lVar26 != 0) {
      uVar33 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar26,0,0);
      uVar43 = uVar43 & 0xfffffffffffffbff | (uVar33 & 1) << 10;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x73c8,uVar33 & 1);
    }
  }
  uVar43 = uVar43 | (uVar34 & 0xf) << 0x11;
  if ((uVar22 != 0xd04) && (uVar22 != 0xd07)) {
    uVar43 = uVar43 | (uVar15 & 1) << 0x15;
  }
  iVar21 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62f8))
                     (*(undefined4 *)(lVar50 + 0x58),*(undefined4 *)(lVar50 + 0x14c));
  uVar15 = 5;
  if ((long)(iVar21 + -1) < 6) {
    uVar15 = (long)(iVar21 + -1);
  }
  uVar33 = 1;
  if (0 < (long)uVar15) {
    uVar33 = uVar15;
  }
  uVar43 = uVar43 | (uVar33 & 7) << 0x16;
  if (1 < *(int *)(lVar50 + 0x180) - 0xd0000U) {
    uVar43 = uVar43 | (ulong)(iVar28 != 0) << 9;
  }
  if (*(int *)(lVar50 + 0x180) == 0xd0000) {
    uVar15 = 0;
  }
  else {
    uVar15 = ((long)*(int *)(lVar50 + 0x17c) ^ 8U) >> 3 & 1 ^ 1;
  }
  setCopReg(2,uVar33,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x12));
  lVar26 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7398);
  uVar33 = 0;
  if (lVar26 != 0) {
    uVar15 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar26,0,0);
    uVar15 = uVar15 & 1;
    uVar33 = (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7388,uVar15);
  }
  uVar25 = special2((long)*(int *)(lVar50 + 0x148),uVar33,8,0x2e);
  uVar33 = uVar43 | uVar15 << 0x1e | (uVar33 & 1) << 0x1f;
  puVar39 = &DAT_8001180088000018 + lVar12;
  pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
  (*pcVar49)(puVar39,uVar33);
  uVar34 = uVar33 | 0x100;
  (*pcVar49)(puVar39,uVar34);
  (*(code *)(long)DAT_ffffffffbfc44014)(2000);
  (*(code *)(long)DAT_ffffffffbfc44014)(2000);
  if (uVar22 == 0xd01) {
    uVar47 = uVar47 & 0xfffffffffffff7ff;
    (*pcVar49)(*(undefined8 *)(lVar50 + 0x160),uVar47);
    (*(code *)(long)DAT_ffffffffbfc44014)(2000);
    (*pcVar49)(lVar12 + -0x7ffee7ff77ffffd0,*(undefined4 *)(lVar50 + 0x3c));
LAB_ffffffffbfc0925c:
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
    (*pcVar49)(lVar12 + -0x7ffee7ff77ffff80,*(undefined4 *)(lVar50 + 0x34));
    (*pcVar49)(lVar12 + -0x7ffee7ff77ffff88,*(undefined4 *)(lVar50 + 0x38));
LAB_ffffffffbfc092a4:
    uVar35 = uVar34;
    (*pcVar49)(puVar39,uVar34);
    if (((*(int *)(lVar50 + 0x180) == 0xd0003) || (uVar22 == 0xd03)) ||
       ((uVar22 == 0xd04 || ((uVar22 == 0xd07 || (uVar22 == 0xd06)))))) {
      iVar28 = *(int *)(lVar50 + 0x8c);
      goto LAB_ffffffffbfc092e4;
    }
  }
  else {
    if (uVar22 != 0xd02) {
      if (((uVar22 == 0xd04) || (uVar22 == 0xd06)) || (uVar22 == 0xd07)) {
        (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))
                  (lVar12 + -0x7ffee7ff77ffffd0,*(undefined4 *)(lVar50 + 0x3c));
        if ((uVar22 == 0xd04) || (uVar22 == 0xd07)) goto LAB_ffffffffbfc0925c;
      }
      else {
        (*pcVar49)(0x8001180088000030,*(undefined4 *)(lVar50 + 0x3c));
      }
      pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
      (*pcVar49)(lVar12 + -0x7ffee7ff77ffff88,*(undefined4 *)(lVar50 + 0x38));
      goto LAB_ffffffffbfc092a4;
    }
    uVar47 = uVar47 & 0xfffffffffffff7ff;
    (*pcVar49)(*(undefined8 *)(lVar50 + 0x160),uVar47);
    (*(code *)(long)DAT_ffffffffbfc44014)(2000);
    (*pcVar49)(lVar12 + -0x7ffee7ff77ffffd0,*(undefined4 *)(lVar50 + 0x3c));
    (*pcVar49)(lVar12 + -0x7ffee7ff77ffff80,*(undefined4 *)(lVar50 + 0x34));
    (*pcVar49)(lVar12 + -0x7ffee7ff77ffff88,*(undefined4 *)(lVar50 + 0x38));
    (*pcVar49)(puVar39,uVar34);
    iVar28 = *(int *)(lVar50 + 0x8c);
LAB_ffffffffbfc092e4:
    if ((long)iVar28 == 0) {
      lVar26 = (long)*(int *)(lVar50 + 0x184);
      iVar48 = *(int *)(lVar26 + 0x10);
      iVar21 = *(int *)(lVar26 + 0x14);
      iVar36 = *(int *)(lVar26 + 0x18);
    }
    else {
      lVar26 = (long)*(int *)(lVar50 + 0x184);
      iVar48 = *(int *)(lVar26 + 0x20);
      iVar21 = *(int *)(lVar26 + 0x24);
      iVar36 = *(int *)(lVar26 + 0x28);
    }
    uVar17 = ((long)iVar21 & 0x1fU) << 5;
    setCopReg(2,(long)iVar28,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x34));
    uVar18 = ((long)iVar36 & 0x1fU) << 10;
    uVar35 = (long)iVar48 & 0x1fU | uVar17 | uVar18;
    lVar26 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7350);
    if (lVar26 != 0) {
      uVar16 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar26,0,0);
      uVar35 = uVar17 | uVar18 | uVar16 & 0x1f;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7340,uVar16 & 0x1f);
    }
    lVar26 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x7308);
    if (lVar26 != 0) {
      uVar17 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar26,0,0);
      uVar35 = uVar35 & 0xfffffffffffffc1f | (uVar17 & 0x1f) << 5;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x72f8,uVar17 & 0x1f);
    }
    lVar26 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x72c0);
    if (lVar26 != 0) {
      uVar17 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar26,0,0);
      uVar35 = uVar35 & 0xffffffffffff83ff | (uVar17 & 0x1f) << 10;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x72b0,uVar17 & 0x1f);
    }
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))(lVar12 + -0x7ffee7ff77ffff78,uVar35);
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x7278,uVar35 & 0x1f);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x7240,uVar35 >> 5 & 0x1f);
    uVar35 = uVar35 >> 10;
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x7208,uVar35);
  }
  setCopReg(2,uVar35,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x80));
  if ((((uVar22 == 0xd03) || (uVar22 == 0xd04)) || (uVar22 == 0xd06)) || (uVar22 == 0xd07)) {
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x71d0,*(ulong *)(&DAT_8001180088000090 + lVar12) >> 9 & 1);
    uVar18 = _DAT_80011800880000a8;
    uVar35 = _DAT_80011800880000a8 >> 0xe & 0xfff;
    uVar17 = _DAT_80011800880000a8 >> 8 & 0x3f;
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x7198,*(undefined4 *)(lVar50 + 400));
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x7160,uVar35);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x7128,uVar17);
    setCopReg(2,uVar25,*(undefined4 *)(uVar18 + 7));
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x70f0,1);
    setCopReg(2,extraout_at,*(undefined4 *)(uVar18 + 7));
    uVar25 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x70b8,1);
    setCopReg(2,uVar25,*(undefined4 *)(uVar18 + 7));
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x7080,1);
    setCopReg(2,extraout_v1,*(undefined4 *)(uVar18 + 7));
    lVar26 = (long)(DAT_ffffffffbfc436f4 + -0x7048);
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(lVar26,1);
    setCopReg(2,lVar26,*(undefined4 *)(uVar18 + 7));
    uVar25 = 1;
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x7010,1);
    setCopReg(2,uVar25,*(undefined4 *)(uVar18 + 9));
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x6fd8,1);
    uVar17 = uVar17 + 1;
    uVar35 = special2((ulong)*(uint *)(lVar50 + 400),uVar35 + 1,0,3);
    iVar28 = DAT_ffffffffbfc436ec + 0x6910;
    if (uVar17 == 0) {
      trap(7);
    }
    (*(code *)(long)iVar28)(DAT_ffffffffbfc436f4 + -0x6fa0,(uVar35 / uVar17) / 1000000);
    uVar17 = special2(uVar17,0x10,0,3);
    if (uVar17 == 0) {
      trap(7);
    }
    (*(code *)(long)iVar28)(DAT_ffffffffbfc436f4 + -0x6f60,uVar35 / uVar17);
  }
  iVar28 = DAT_ffffffffbfc436ec + 0x62f8;
  uVar35 = (*(code *)(long)iVar28)(*(undefined4 *)(lVar50 + 0x60),*(undefined4 *)(lVar50 + 0x14c));
  uVar17 = (*(code *)(long)iVar28)(*(undefined4 *)(lVar50 + 0x5c),*(undefined4 *)(lVar50 + 0x14c));
  uVar23 = getCopReg(2,10);
  *(undefined4 *)(uVar34 + 3) = uVar23;
  if ((long)uVar35 < 2) {
    uVar35 = 2;
  }
  pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62f8);
  iVar28 = *(int *)(lVar50 + 0x70);
  uVar34 = (*pcVar49)(*(undefined4 *)(lVar50 + 0x54),*(undefined4 *)(lVar50 + 0x14c));
  auVar53 = (*pcVar49)(*(undefined4 *)(lVar50 + 0x68),*(undefined4 *)(lVar50 + 0x14c));
  uVar25 = special2((long)*(int *)(lVar50 + 0x148),auVar53._4_8_,8,0x2e);
  uVar18 = (*pcVar49)(*(undefined4 *)(lVar50 + 0x50),*(int *)(lVar50 + 0x14c) << 2);
  uVar16 = (*pcVar49)(*(undefined4 *)(lVar50 + 100),*(undefined4 *)(lVar50 + 0x14c));
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))
            (lVar12 + -0x7ffee7ff77fffff8,
             uVar17 & 0x1f | (uVar35 & 0xf) << 5 | (uVar34 & 0xf) << 9 |
             ((long)(auVar53._0_4_ + auVar53._8_4_) & 0xfU) << 0xd | (uVar18 & 0x1f) << 0x11 |
             0xc00000 | ((long)iVar28 & 7U) << 0x19 | (uVar16 & 7) << 0x1c);
  uVar34 = 0xf000f000;
  iVar21 = *(int *)(lVar50 + 0x180);
  if ((*(int *)(lVar50 + 0x194) == 2) && (*(int *)(lVar50 + 0x198) == 1)) {
    uVar30 = (uint)(**(ulong **)(lVar50 + 0x160) >> 0x18) & 0xf;
    uVar29 = (uint)(**(ulong **)(lVar50 + 0x160) >> 0x1c) & 0xf;
    uVar34 = ((long)(int)(0x1e - uVar30) & 0xfU) << 4 | 0xf000f000 |
             ((long)(int)(0x1e - uVar29) & 0xfU) << 0x14;
    if (250000000 < *(uint *)(lVar50 + 0x188)) {
      uVar34 = uVar34 | ((long)(int)(0x11 - uVar30) & 0xfU) << 8 |
               ((long)(int)(0x12 - uVar29) & 0xfU) << 0x18;
    }
    iVar21 = *(int *)(lVar50 + 0x180);
  }
  iVar48 = *(int *)(lVar50 + 0xe0);
  if (iVar21 == 0xd0400) {
    uVar17 = (long)(int)(0x33 - ((uint)(*(ulong *)(lVar12 + -0x7ffee7ff77ffff50) >> 0x16) & 0x1f)) &
             0x1f;
    uVar35 = (long)(int)(0x26 - ((uint)(*(ulong *)(lVar12 + -0x7ffee7ff77ffff50) >> 0x1b) & 0x1f)) &
             0xf;
    uVar34 = uVar34 & 0xffffffffffffffe0 | uVar17 | uVar35 << 0x10;
    iVar21 = DAT_ffffffffbfc436ec + 0x6910;
    (*(code *)(long)iVar21)(DAT_ffffffffbfc436f4 + -0x6f28,uVar17);
    (*(code *)(long)iVar21)(DAT_ffffffffbfc436f4 + -0x6ef0,uVar35);
    iVar48 = *(int *)(lVar50 + 0xe0);
  }
  iVar21 = *(int *)(lVar50 + 0x11c);
  iVar36 = DAT_ffffffffbfc436ec + 0x62c8;
  puVar44 = (ulong *)(&DAT_8001180088000000 + lVar12);
  (*(code *)(long)iVar36)(lVar12 + -0x7ffee7ff77ffffd8,uVar34);
  (*(code *)(long)iVar36)(puVar44,0);
  uVar34 = (ulong)*(int *)(lVar50 + 0x9c);
  if (*(int *)(lVar50 + 0xdc) == 0) {
    uVar34 = 0;
  }
  uVar34 = (uVar34 & 1) << 1;
  if ((uVar22 == 0xd02) || (uVar22 == 0xd01)) {
LAB_ffffffffbfc0994c:
    uVar34 = uVar34 | ((long)*(int *)((long)((*(int *)(lVar50 + 0xe4) + *(int *)(lVar50 + 0x11c)) *
                                             4 + DAT_ffffffffbfc436f0 + 0x6258) + -0x30) & 7U) << 2
             | ((long)*(int *)(lVar50 + 0xfc) & 1U) << 0x1d;
LAB_ffffffffbfc09978:
    if (*(int *)(lVar50 + 0x180) != 0xd0000) {
      uVar34 = uVar34 | ((long)*(int *)(lVar50 + 0x4c) & 1U) << 0x1e;
    }
    if ((uVar22 != 0xd02) && (uVar22 != 0xd01)) {
      iVar36 = 0x1b;
      if (uVar22 != 0xd00) goto LAB_ffffffffbfc099a8;
      goto LAB_ffffffffbfc0a274;
    }
LAB_ffffffffbfc099ec:
    iVar36 = *(int *)((long)((iVar48 + iVar21) * 4 + DAT_ffffffffbfc436f0 + 0x6278) + -100);
  }
  else {
    if ((uVar22 == 0xd00) || (uVar22 == 0xd03)) {
      iVar36 = 0xe;
LAB_ffffffffbfc0a250:
      uVar34 = uVar34 | ((long)((*(int *)(lVar50 + 0xe4) + *(int *)(lVar50 + 0x11c)) - iVar36) & 7U)
                        << 2 | ((long)*(int *)(lVar50 + 0xfc) & 1U) << 0x1d;
      goto LAB_ffffffffbfc09978;
    }
    if ((uVar22 != 0xd04) && (uVar22 != 0xd07)) {
      if (uVar22 == 0xd06) goto LAB_ffffffffbfc0994c;
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x63d8,*(undefined4 *)(lVar50 + 0x180));
      iVar36 = 0xc;
      goto LAB_ffffffffbfc0a250;
    }
    uVar34 = uVar34 | ((long)*(int *)((long)((*(int *)(lVar50 + 0xe4) + *(int *)(lVar50 + 0x11c)) *
                                             4 + DAT_ffffffffbfc436f0 + 0x6258) + -0x30) & 7U) << 2
             | ((long)*(int *)(lVar50 + 0xfc) & 1U) << 0x1d;
LAB_ffffffffbfc099a8:
    if (uVar22 == 0xd03) {
      iVar36 = 0x1b;
    }
    else {
      if (((uVar22 == 0xd04) || (uVar22 == 0xd07)) || (uVar22 == 0xd06)) goto LAB_ffffffffbfc099ec;
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x63d8,*(undefined4 *)(lVar50 + 0x180));
      iVar36 = 0;
    }
LAB_ffffffffbfc0a274:
    iVar36 = (iVar48 + iVar21) - iVar36;
  }
  iVar21 = DAT_ffffffffbfc436f4;
  if (*(int *)(lVar50 + 0x14c) << 9 == 0) {
    trap(7);
  }
  uVar35 = uVar34 | ((long)iVar36 & 0xfU) << 5 |
           ((long)(int)((uint)(*(int *)(lVar50 + 0x6c) * 1000) /
                       (uint)(*(int *)(lVar50 + 0x14c) << 9)) & 0x3fU) << 9;
  if (*(int *)(lVar50 + 0x180) == 0xd0000) {
    uVar35 = uVar35 | ((long)iVar28 & 0xfU) << 0xf;
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6eb8,(uVar34 & 0x20000000) >> 0x1d);
    uVar33 = uVar33 >> 0x1e;
    iVar21 = iVar21 + -0x6e80;
  }
  else {
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6eb8,(uVar34 & 0x20000000) >> 0x1d);
    (*pcVar49)(iVar21 + -0x6e80,uVar15);
    uVar33 = uVar33 >> 10;
    iVar21 = DAT_ffffffffbfc436f4 + -0x6e48;
  }
  (*pcVar49)(iVar21,uVar33 & 1);
  if ((uVar22 != 0xd04) && (uVar22 != 0xd07)) {
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6e10,uVar47 >> 4 & 3);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6dd8,(uVar43 & 0x200000) >> 0x15);
    if (*(int *)(lVar50 + 0x180) != 0xd0000) {
      (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6da0,uVar35 >> 0x1e);
    }
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6d68,uVar47 >> 6 & 3);
  }
  pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
  (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6d30,uVar47 >> 0xe & 1);
  uVar15 = (uVar43 & 0x200) >> 9;
  if (*(int *)(lVar50 + 0x180) != 0xd0000) {
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6cf8,(uVar43 & 0x200) >> 9);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6cc0,uVar47 >> 2 & 3);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6c88,uVar47 & 3);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6c50,*(undefined4 *)(lVar50 + 0x3c));
    if (((uVar22 == 0xd01) || (uVar22 == 0xd02)) ||
       ((uVar22 == 0xd04 || ((uVar22 == 0xd06 || (uVar22 == 0xd07)))))) {
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))
                (DAT_ffffffffbfc436f4 + -0x6c18,*(undefined4 *)(lVar50 + 0x34));
    }
    uVar15 = (ulong)*(int *)(lVar50 + 0x38);
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x6be0,uVar15);
  }
  if ((((uVar22 != 0xd03) && (uVar22 != 0xd04)) && (uVar22 != 0xd06)) && (uVar22 != 0xd07))
  goto LAB_ffffffffbfc09ec8;
  uVar47 = 0;
  if (*(int *)(long)*(int *)(lVar50 + 0x168) == 1) {
    uVar47 = 0x10003;
    lVar26 = 1;
LAB_ffffffffbfc09ca4:
    uVar47 = uVar47 | lVar26 << 8;
  }
  else if (*(int *)(long)*(int *)(lVar50 + 0x168) == 2) {
    uVar47 = 0x10007;
    lVar26 = 2;
    goto LAB_ffffffffbfc09ca4;
  }
  setCopReg(2,uVar15,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x1e));
  pcVar14 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x6ba8);
  if (pcVar14 != (char *)0x0) {
    iVar28 = DAT_ffffffffbfc436f4 + -0x6b98;
    cVar2 = *pcVar14;
    pcVar27 = pcVar14;
    do {
      cVar3 = *(char *)(long)iVar28;
      pcVar27 = (char *)(long)((int)pcVar27 + 1);
      iVar28 = iVar28 + 1;
      cVar24 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar27;
      cVar24 = cVar3;
    } while (bVar1);
    if (cVar24 == cVar3) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6b90);
      uVar47 = 0x10103;
    }
  }
  setCopReg(2,pcVar14,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x1e));
  pcVar14 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x6ba8);
  if (pcVar14 != (char *)0x0) {
    iVar28 = DAT_ffffffffbfc436f4 + -0x6b60;
    cVar2 = *pcVar14;
    do {
      cVar3 = *(char *)(long)iVar28;
      pcVar14 = (char *)(long)((int)pcVar14 + 1);
      iVar28 = iVar28 + 1;
      cVar24 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar14;
      cVar24 = cVar3;
    } while (bVar1);
    if (cVar24 == cVar3) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6b90);
      uVar47 = 0x10207;
    }
  }
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))(lVar12 + -0x7ffee7ff77ffff60,uVar47);
  pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
  (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6b58,uVar47 >> 0x10);
  (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6b20,uVar47 & 0x1f);
  (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6ae8,uVar47 >> 8 & 0xf);
  if (((uVar22 == 0xd04) || (uVar22 == 0xd06)) || (uVar22 == 0xd07)) {
    uVar15 = *(ulong *)(lVar12 + -0x7ffee7ff77ffff50);
    pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x6910);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6ab0,uVar15 >> 0x16 & 0x1f);
    uVar15 = uVar15 >> 0x1b & 0x1f;
  }
  else {
    uVar15 = **(ulong **)(lVar50 + 0x160);
    (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6ab0,uVar15 >> 0x18 & 0xf);
    uVar15 = uVar15 >> 0x1c & 0xf;
  }
  (*pcVar49)(DAT_ffffffffbfc436f4 + -0x6a78,uVar15);
LAB_ffffffffbfc09ec8:
  iVar28 = DAT_ffffffffbfc436ec + 0x62c8;
  (*(code *)(long)iVar28)(puVar44,uVar35 | 0x1fe00000);
  (*(code *)(long)iVar28)(puVar44,*puVar44 | 1);
  if ((uVar22 != 0xd04) && (uVar22 != 0xd07)) {
    return *(undefined4 *)(lVar50 + 0x100);
  }
  lVar26 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x6a40);
  if (lVar26 == 0) {
    *(undefined4 *)(lVar50 + 0x30) = 1;
  }
  else {
    lVar26 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar26,0,0);
    iVar28 = DAT_ffffffffbfc436f4;
    *(uint *)(lVar50 + 0x30) = (uint)(lVar26 != 0);
    (*(code *)(long)DAT_ffffffffbfc4400c)(iVar28 + -0x6a30,*(undefined4 *)(lVar50 + 0x30));
  }
  uVar33 = *(ulong *)(lVar12 + -0x7ffee7ff77fffec0);
  uVar47 = *(ulong *)(&DAT_8001180088000090 + lVar12);
  uVar22 = 1;
  uVar15 = 0;
  uVar29 = 1;
  if (*(int *)(lVar50 + 0x144) != 1) {
    uVar22 = 3;
  }
  while( true ) {
    if (*(int *)(lVar50 + 0x13c) <= (int)uVar29) break;
    uVar22 = uVar22 | (uVar22 & 3) << ((uVar29 & 0xf) << 1);
    uVar29 = uVar29 + 1;
  }
  uVar29 = 0;
  *(int *)(lVar50 + 0x158) = *(int *)(lVar50 + 0x154) << 2;
  do {
    setCopReg(2,uVar25,*(undefined4 *)((long)(int)(uVar22 >> (uVar29 & 0x1f)) + 0x62));
    if (*(int *)(lVar50 + 0x30) == 0) {
      if (*(int *)(lVar50 + 0x30) == 0) {
        if (*(uint *)(lVar50 + 0x14c) == 0) {
          trap(7);
        }
        uVar43 = (long)(int)(*(uint *)(lVar50 + 0x158) / *(uint *)(lVar50 + 0x14c)) & 0xf;
        uVar19 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6290))
                           (uVar29,*(undefined4 *)(lVar50 + 0x204));
        (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))
                  (uVar19,uVar15 & 0xfffffff000000000 | uVar43 | uVar43 << 4 | uVar43 << 8 |
                          uVar43 << 0xc | uVar43 << 0x10 | uVar43 << 0x14 | uVar43 << 0x18 |
                          uVar43 << 0x1c | uVar43 << 0x20);
      }
    }
    else {
      uVar33 = uVar33 & 0xfffff0ffffffffff |
               ((long)(*(int *)(lVar50 + 0x30) << (uVar29 & 0x1f)) & 0xfU) << 0x28;
      pcVar49 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
      (*pcVar49)((ulong *)(lVar12 + -0x7ffee7ff77fffec0),uVar33);
      uVar47 = uVar47 & 0xffffffffffffe3ff | 0x400;
      (*pcVar49)(&DAT_8001180088000090 + lVar12,uVar47);
      uVar15 = *puVar44;
      (*pcVar49)(puVar44,uVar15 & 0xfffffffffffffffe);
      (*pcVar49)(puVar44,uVar15 & 0xfffffffffffffffe | 1);
    }
    puVar20 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436ec + 0x6290))
                                 (uVar29,*(undefined4 *)(lVar50 + 0x204));
    uVar15 = *puVar20;
    iVar21 = DAT_ffffffffbfc436ec + 0x6910;
    (*(code *)(long)iVar21)(DAT_ffffffffbfc436f4 + -0x69f8,uVar15 >> 0x24 & 3);
    *(uint *)(lVar50 + 0x14) = (uint)uVar15 & 0xf;
    iVar28 = DAT_ffffffffbfc436f4 + -0x69c0;
    *(uint *)(lVar50 + 4) = (uint)(uVar15 >> 8) & 0xf;
    *(uint *)(lVar50 + 0xc) = (uint)(uVar15 >> 4) & 0xf;
    (*(code *)(long)iVar21)
              (iVar28,uVar29,uVar15 >> 0x20 & 0xf,uVar15 >> 0x1c & 0xf,uVar15 >> 0x18 & 0xf,
               uVar15 >> 0x14 & 0xf,uVar15 >> 0x10 & 0xf,uVar15 >> 0xc & 0xf);
    uVar29 = uVar29 + 1;
  } while (uVar29 != 4);
  return *(undefined4 *)(lVar50 + 0x100);
}

