/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13760
 * Function: FUN_ffffffffbfc13760
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

undefined8 FUN_ffffffffbfc13760(int param_1,int param_2,long param_3,int *param_4)

{
  byte bVar1;
  long lVar2;
  int iVar4;
  char *pcVar3;
  ulong uVar5;
  int iVar6;
  undefined8 unaff_s0;
  int iVar8;
  undefined8 uVar7;
  undefined8 unaff_s1;
  int iVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar10;
  int *piVar11;
  undefined8 in_ra;
  
  piVar11 = (int *)(long)((int)&stack0x00000000 + -0x80);
  *(undefined1 **)(piVar11 + 0x1a) = &_gp;
  *(undefined8 *)(piVar11 + 0x18) = unaff_s4;
  *(undefined8 *)(piVar11 + 0x16) = unaff_s3;
  *(undefined8 *)(piVar11 + 0x14) = unaff_s2;
  *(undefined8 *)(piVar11 + 0x10) = unaff_s0;
  *(undefined8 *)(piVar11 + 0x1c) = in_ra;
  *(undefined8 *)(piVar11 + 0x12) = unaff_s1;
  iVar6 = DAT_ffffffffbfc436fc;
  bVar1 = *(byte *)(param_3 + 3);
  uVar5 = (ulong)bVar1;
  if ((*(char *)(param_3 + 2) != '\b') || ((bVar1 & 0xe0) != 0)) {
    iVar6 = DAT_ffffffffbfc436f4 + -0x5008;
LAB_ffffffffbfc13844:
    (*(code *)(long)DAT_ffffffffbfc43e38)(iVar6);
    return 0xffffffffffffffff;
  }
  setCopReg(2,uVar5 & 0xe0,*(undefined4 *)(uVar5 + 6));
  iVar4 = (uint)*(byte *)(param_3 + 0xb) * 0x100;
  iVar9 = iVar4 + *(byte *)(param_3 + 10) + 0xc;
  setCopReg(2,(long)iVar4,*(undefined4 *)(uVar5 + 6));
  iVar8 = (int)param_3;
  iVar4 = iVar8 + iVar9;
  do {
    pcVar3 = (char *)(long)iVar4;
    iVar9 = iVar9 + 1;
    iVar4 = iVar4 + 1;
  } while (*pcVar3 != '\0');
  setCopReg(2,uVar5,*(undefined4 *)(uVar5 + 5));
  iVar4 = iVar8 + iVar9;
  do {
    pcVar3 = (char *)(long)iVar4;
    iVar9 = iVar9 + 1;
    iVar4 = iVar4 + 1;
  } while (*pcVar3 != '\0');
  iVar9 = iVar9 + (bVar1 & 2);
  if (*param_4 <= iVar9) {
    iVar6 = DAT_ffffffffbfc436f4 + -0x4fe8;
    goto LAB_ffffffffbfc13844;
  }
  pcVar10 = (code *)(long)DAT_ffffffffbfc43eb4;
  piVar11[0xc] = 0;
  piVar11[8] = iVar6 + 0x39c4;
  piVar11[9] = DAT_ffffffffbfc436fc + 0x39ac;
  lVar2 = (*pcVar10)(piVar11,0xfffffffffffffff1);
  if (lVar2 != 0) {
    iVar6 = DAT_ffffffffbfc436f4 + -0x4fc0;
    goto LAB_ffffffffbfc1397c;
  }
  iVar6 = *param_4;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43ec4;
  *piVar11 = iVar8 + iVar9;
  piVar11[1] = iVar6 - iVar9;
  piVar11[4] = param_2;
  piVar11[3] = param_1;
  uVar5 = (*pcVar10)(piVar11,4);
  if (uVar5 < 2) {
    if (piVar11[1] == 0) {
      if (uVar5 == 1) {
LAB_ffffffffbfc13944:
        iVar6 = piVar11[3];
        goto LAB_ffffffffbfc13948;
      }
      iVar6 = DAT_ffffffffbfc436f4 + -0x4f50;
    }
    else {
      iVar6 = piVar11[3];
      if (piVar11[4] != 0) {
LAB_ffffffffbfc13948:
        uVar7 = 0;
        *param_4 = iVar6 - param_1;
        pcVar10 = (code *)(long)DAT_ffffffffbfc43784;
        goto LAB_ffffffffbfc13958;
      }
      if (uVar5 == 1) goto LAB_ffffffffbfc13944;
      iVar6 = DAT_ffffffffbfc436f4 + -0x4f78;
    }
    uVar7 = 0xffffffffffffffff;
    (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6);
    pcVar10 = (code *)(long)DAT_ffffffffbfc43784;
  }
  else {
    uVar7 = 0xffffffffffffffff;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4f98);
    pcVar10 = (code *)(long)DAT_ffffffffbfc43784;
  }
LAB_ffffffffbfc13958:
  lVar2 = (*pcVar10)(piVar11);
  if (lVar2 == 0) {
    return uVar7;
  }
  iVar6 = DAT_ffffffffbfc436f4 + -0x4f30;
LAB_ffffffffbfc1397c:
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6,lVar2);
  return 0xffffffffffffffff;
}

