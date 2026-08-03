/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc14f38
 * Function: FUN_ffffffffbfc14f38
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

undefined8 FUN_ffffffffbfc14f38(char *param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar10;
  char cVar13;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar11;
  uint uVar12;
  undefined8 uVar9;
  int iVar14;
  char *pcVar15;
  char *pcVar16;
  undefined8 unaff_s0;
  int iVar17;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int *piVar18;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar19;
  undefined8 *puVar20;
  undefined8 in_ra;
  
  puVar20 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar20[6] = &_gp;
  puVar20[5] = unaff_s5;
  pcVar19 = (code *)(long)DAT_ffffffffbfc437c8;
  puVar20[4] = unaff_s4;
  puVar20[3] = unaff_s3;
  puVar20[2] = unaff_s2;
  puVar20[1] = unaff_s1;
  *puVar20 = unaff_s0;
  puVar20[7] = in_ra;
  iVar17 = DAT_ffffffffbfc43c70;
  iVar10 = (*pcVar19)();
  do {
    piVar18 = (int *)(long)iVar17;
    pcVar15 = (char *)(long)*piVar18;
    pcVar16 = param_1;
    iVar14 = iVar10;
    while( true ) {
      cVar1 = *pcVar16;
      cVar2 = *pcVar15;
      cVar13 = cVar2;
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      pcVar16 = (char *)(long)((int)pcVar16 + 1);
      cVar13 = cVar1;
      if ((cVar2 != cVar1) ||
         (pcVar15 = (char *)(long)((int)pcVar15 + 1), cVar13 = cVar2, cVar1 == '\0')) break;
    }
    if ((cVar13 == cVar2) &&
       (iVar14 = (*(code *)(long)DAT_ffffffffbfc437c8)((char *)(long)*piVar18), iVar10 == iVar14)) {
      uVar6 = piVar18[1];
      if (param_4 != 0) {
        iVar17 = DAT_ffffffffbfc436fc + 0x4ebc;
        (*(code *)(long)iVar17)(param_2,param_4);
        uVar9 = (*(code *)(long)iVar17)(param_3,param_4);
        if (5 < uVar6) {
          return 0;
        }
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc1510c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar9 = (*(code *)(long)(*(int *)(long)(int)(uVar6 * 4 + DAT_ffffffffbfc436f0 + 0x6468) +
                                -0x403bc920))(uVar9);
        return uVar9;
      }
      iVar17 = DAT_ffffffffbfc436fc + 0x4e80;
      pbVar7 = (byte *)(*(code *)(long)iVar17)(param_2);
      pbVar8 = (byte *)(*(code *)(long)iVar17)(param_3);
      uVar11 = (*(code *)(long)DAT_ffffffffbfc437c8)(pbVar7);
      uVar12 = (*(code *)(long)DAT_ffffffffbfc437c8)(pbVar8);
      if (uVar11 < uVar12) {
        uVar12 = uVar11;
      }
      break;
    }
    iVar17 = iVar17 + 8;
    if (piVar18 == (int *)(long)(DAT_ffffffffbfc43c70 + 0x60)) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4480,param_1);
      return 0;
    }
  } while( true );
LAB_ffffffffbfc15030:
  bVar3 = *pbVar7;
  bVar4 = *pbVar8;
  bVar5 = bVar4;
  if (uVar12 == 0) {
LAB_ffffffffbfc15054:
    if (5 < uVar6) {
      return 0;
    }
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc1507c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar9 = (*(code *)(long)(*(int *)(long)(int)(uVar6 * 4 + DAT_ffffffffbfc436f0 + 0x6450) +
                            -0x403bc920))((uint)bVar5 - (uint)bVar4);
    return uVar9;
  }
  uVar12 = uVar12 - 1;
  pbVar7 = (byte *)(long)((int)pbVar7 + 1);
  bVar5 = bVar3;
  if ((bVar4 != bVar3) || (pbVar8 = (byte *)(long)((int)pbVar8 + 1), bVar5 = bVar4, bVar3 == 0))
  goto LAB_ffffffffbfc15054;
  goto LAB_ffffffffbfc15030;
}

