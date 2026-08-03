/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1bf6c
 * Function: FUN_ffffffffbfc1bf6c
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

int FUN_ffffffffbfc1bf6c(long *param_1,ulong param_2,ulong param_3,int param_4,undefined8 param_5)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  uint uVar9;
  int iVar10;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int iVar11;
  undefined8 unaff_s2;
  ulong uVar12;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  ulong uVar13;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  ulong uVar14;
  code *pcVar15;
  int *piVar16;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  piVar16 = (int *)(long)((int)&stack0x00000000 + -0x80);
  *(undefined1 **)(piVar16 + 0x18) = &_gp;
  *(undefined8 *)(piVar16 + 0x1a) = unaff_s8;
  pcVar15 = (code *)(long)DAT_ffffffffbfc43b28;
  *(undefined8 *)(piVar16 + 0x14) = unaff_s6;
  *(undefined8 *)(piVar16 + 0x10) = unaff_s4;
  *(undefined8 *)(piVar16 + 8) = unaff_s0;
  *(undefined8 *)(piVar16 + 0x1c) = in_ra;
  *(undefined8 *)(piVar16 + 0x16) = unaff_s7;
  *(undefined8 *)(piVar16 + 0x12) = unaff_s5;
  *(undefined8 *)(piVar16 + 0xe) = unaff_s3;
  *(undefined8 *)(piVar16 + 0xc) = unaff_s2;
  *(undefined8 *)(piVar16 + 10) = unaff_s1;
  *(undefined8 *)(piVar16 + 4) = param_5;
  lVar1 = (*pcVar15)(param_2,param_3,1,piVar16);
  if (lVar1 != 0) {
    iVar11 = -1;
    uVar12 = param_2 & -1L << (long)(*piVar16 + 1);
    while (0 < param_4) {
      if (param_3 <= uVar12) goto LAB_ffffffffbfc1c2ac;
      uVar13 = uVar12 + lVar1;
      uVar14 = uVar13 - 1;
      if (param_3 <= uVar13 - 1) {
        uVar14 = param_3;
      }
      lVar1 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0xdb0);
      uVar2 = (*(code *)(long)DAT_ffffffffbfc43b28)(uVar12,uVar14,1,(int)&stack0x00000000 + -0x7c);
      if (uVar2 == 0) {
        return -1;
      }
      iVar10 = 0;
      uVar12 = uVar12 & -1L << (long)(piVar16[1] + 1);
      uVar7 = (uVar12 + uVar2) - 1;
      iVar11 = *(int *)(param_1 + 3);
      plVar8 = param_1;
      while( true ) {
        iVar10 = iVar10 + 1;
        if (iVar11 != 0) {
          uVar3 = plVar8[2];
          uVar6 = (uVar3 + (1L << (long)(iVar11 + 1))) - 1;
          if ((((uVar3 <= uVar12) && (uVar12 <= uVar6)) || ((uVar3 <= uVar7 && (uVar7 <= uVar6))))
             || ((uVar12 <= uVar3 && (uVar6 <= uVar7)))) {
            iVar11 = DAT_ffffffffbfc436f4 + -0xd98;
            goto LAB_ffffffffbfc1c1f0;
          }
        }
        plVar8 = (long *)(long)((int)plVar8 + 0x28);
        if (iVar10 == 0x20) break;
        iVar11 = *(int *)(plVar8 + 3);
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0xd20,uVar2);
      if ((lVar1 == 0) ||
         (lVar4 = (*(code *)(long)DAT_ffffffffbfc43a08)
                            (0x70010,0x410000000,0x41fffffff,1 << (piVar16[1] & 0x1fU),0), lVar4 < 0
         )) {
        lVar4 = (*(code *)(long)DAT_ffffffffbfc43a08)(0x70010,0,0,1 << (piVar16[1] & 0x1fU),0);
      }
      lVar5 = lVar4;
      if (uVar12 + (uVar2 >> 1) <= uVar14) {
        uVar9 = piVar16[1];
        if (lVar1 != 0) {
          lVar5 = (*(code *)(long)DAT_ffffffffbfc43a08)
                            (0x70010,0x410000000,0x41fffffff,1 << (uVar9 & 0x1f),0);
          if (-1 < lVar5) goto LAB_ffffffffbfc1c1c8;
          uVar9 = piVar16[1];
        }
        lVar5 = (*(code *)(long)DAT_ffffffffbfc43a08)(0x70010,0,0,1 << (uVar9 & 0x1f),0);
      }
LAB_ffffffffbfc1c1c8:
      if ((lVar4 < 0) || (lVar5 < 0)) {
        iVar11 = DAT_ffffffffbfc436f4 + -0xd48;
LAB_ffffffffbfc1c1f0:
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar11);
        return -1;
      }
      iVar11 = 0;
      plVar8 = param_1;
      while (*(int *)(plVar8 + 3) != 0) {
        plVar8 = (long *)(long)((int)plVar8 + 0x28);
        if (iVar11 == 0x20) {
          return -1;
        }
        iVar11 = iVar11 + 1;
      }
      iVar10 = piVar16[1];
      if (iVar11 == 0x20) {
        return -1;
      }
      *plVar8 = lVar4;
      *(int *)(plVar8 + 3) = iVar10;
      lVar1 = *(long *)(piVar16 + 4);
      plVar8[1] = lVar5;
      plVar8[2] = uVar12;
      plVar8[4] = lVar1;
      if (iVar11 < 0) {
        return -1;
      }
      lVar1 = (*(code *)(long)DAT_ffffffffbfc43b28)(uVar13,param_3,1,piVar16);
      if (lVar1 == 0) {
        return -1;
      }
      param_4 = param_4 + -1;
      uVar12 = uVar13;
      if (uVar13 != (uVar13 & -1L << (long)(*piVar16 + 1))) {
        return -1;
      }
    }
    if (-1 < param_4) {
LAB_ffffffffbfc1c2ac:
      if (param_3 <= uVar12) {
        return iVar11;
      }
    }
  }
  return -1;
}

