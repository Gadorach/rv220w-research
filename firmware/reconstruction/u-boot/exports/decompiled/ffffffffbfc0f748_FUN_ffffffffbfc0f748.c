/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0f748
 * Function: FUN_ffffffffbfc0f748
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

long FUN_ffffffffbfc0f748(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  ulong unaff_s0;
  ulong *puVar12;
  ulong unaff_s1;
  ulong unaff_s2;
  int iVar13;
  ulong unaff_s3;
  ulong unaff_s4;
  code *pcVar14;
  ulong *puVar15;
  ulong in_ra;
  
  puVar15 = (ulong *)(long)((int)&stack0x00000000 + -0x50);
  puVar15[7] = (ulong)&_gp;
  puVar15[3] = unaff_s1;
  pcVar14 = (code *)(long)DAT_ffffffffbfc43d0c;
  puVar15[6] = unaff_s4;
  puVar15[5] = unaff_s3;
  puVar15[4] = unaff_s2;
  puVar15[8] = in_ra;
  puVar15[2] = unaff_s0;
  *(undefined4 *)(param_1 + 0xa10) = 5;
  uVar5 = (*pcVar14)(0);
  do {
    uVar2 = *(ushort *)(param_1 + 0xa1c);
    iVar13 = (int)param_2;
    iVar11 = (int)param_1;
    if (uVar2 != 2) {
      if (uVar2 < 3) {
        if (uVar2 == 1) {
LAB_ffffffffbfc0f824:
          lVar7 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0xaac))(param_1,param_2,0,0x80);
          uVar8 = (ulong)(lVar7 == 0);
          goto LAB_ffffffffbfc0f90c;
        }
      }
      else {
        if (uVar2 == 3) goto LAB_ffffffffbfc0f824;
        if (uVar2 == 4) goto LAB_ffffffffbfc0f848;
      }
LAB_ffffffffbfc0f914:
      lVar7 = 0;
      sVar3 = *(short *)(param_1 + 0xa1c);
      goto LAB_ffffffffbfc0f91c;
    }
LAB_ffffffffbfc0f848:
    puVar12 = (ulong *)(long)*(int *)((long)(iVar13 * 4 + iVar11) + 0xc);
    (*(code *)(long)(DAT_ffffffffbfc436fc + -0xd84))(param_1,0x40,puVar15);
    bVar1 = *(byte *)(param_1 + 0xa0c);
    if (bVar1 == 2) {
      uVar10 = (ulong)*(ushort *)puVar12;
      uVar8 = (ulong)*(ushort *)puVar15;
      uVar6 = (ulong)(*(ushort *)puVar15 & *(ushort *)puVar12);
    }
    else if (bVar1 < 3) {
      if (bVar1 != 1) goto LAB_ffffffffbfc0f914;
      uVar10 = (ulong)*(byte *)puVar12;
      uVar8 = (ulong)*(byte *)puVar15;
      uVar6 = (ulong)(*(byte *)puVar15 & *(byte *)puVar12);
    }
    else {
      if (bVar1 != 4) {
        if (bVar1 != 8) goto LAB_ffffffffbfc0f914;
        uVar8 = special2(*puVar12 & *puVar15,*puVar12 & *puVar15,0,0x2b);
        goto LAB_ffffffffbfc0f90c;
      }
      uVar8 = (ulong)(int)*(uint *)puVar12;
      uVar10 = (ulong)(int)*(uint *)puVar15;
      uVar6 = (ulong)(int)(*(uint *)puVar12 & *(uint *)puVar15);
    }
    uVar8 = special2(uVar8 & uVar10,uVar6,0,0x2b);
LAB_ffffffffbfc0f90c:
    if (uVar8 == 0) goto LAB_ffffffffbfc0f914;
    uVar6 = (*(code *)(long)DAT_ffffffffbfc43d0c)(uVar5);
    uVar8 = (ulong)*(uint *)(param_1 + 0xa10) * 500000000;
  } while (uVar6 <= ((long)(int)(uVar8 >> 0x20) << 0x20 | uVar8 & 0xffffffff));
  uVar4 = *(undefined4 *)((long)(iVar13 * 4 + iVar11) + 0xc);
  lVar7 = 1;
  uVar5 = (*(code *)(long)DAT_ffffffffbfc43c38)(param_1,param_2,0);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5828,param_4,uVar4,uVar5);
  (*(code *)(long)(DAT_ffffffffbfc436fc + -0xd40))
            (param_1,param_2,0,*(undefined1 *)(param_1 + 0xa1f));
  sVar3 = *(short *)(param_1 + 0xa1c);
LAB_ffffffffbfc0f91c:
  if ((sVar3 != 1) && (sVar3 != 3)) {
    return lVar7;
  }
  if ((lVar7 == 0) ||
     (lVar9 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0xb9c))(param_1,param_2,0,0x80), lVar9 != 0))
  goto LAB_ffffffffbfc0fae4;
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x57f8,param_4,
             *(undefined4 *)((long)(iVar13 * 4 + iVar11) + 0xc));
  pcVar14 = (code *)(long)(DAT_ffffffffbfc436fc + -0xaac);
  lVar7 = (*pcVar14)(param_1,param_2,0,0x30);
  if (lVar7 == 0) {
    lVar7 = (*pcVar14)(param_1,param_2,0,0x20);
    if (lVar7 != 0) {
      lVar7 = 2;
      pcVar14 = (code *)(long)DAT_ffffffffbfc43e38;
      iVar11 = DAT_ffffffffbfc436f4 + -0x57b8;
      goto LAB_ffffffffbfc0fa70;
    }
    lVar9 = (*pcVar14)(param_1,param_2,0,0x10);
    lVar7 = 8;
    if (lVar9 != 0) {
      pcVar14 = (code *)(long)DAT_ffffffffbfc43e38;
      iVar11 = DAT_ffffffffbfc436f4 + -0x57a0;
      goto LAB_ffffffffbfc0fa70;
    }
  }
  else {
    lVar7 = 8;
    pcVar14 = (code *)(long)DAT_ffffffffbfc43e38;
    iVar11 = DAT_ffffffffbfc436f4 + -0x57d8;
LAB_ffffffffbfc0fa70:
    (*pcVar14)(iVar11);
  }
  iVar11 = DAT_ffffffffbfc436fc + -0xaac;
  lVar9 = (*(code *)(long)iVar11)(param_1,param_2,0,2);
  if (lVar9 != 0) {
    lVar7 = 4;
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5790);
  }
  lVar9 = (*(code *)(long)iVar11)(param_1,param_2,0,8);
  if (lVar9 != 0) {
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5780);
  }
LAB_ffffffffbfc0fae4:
  (*(code *)(long)(DAT_ffffffffbfc436fc + -0xd40))(param_1,param_2,0,0xf0);
  return lVar7;
}

