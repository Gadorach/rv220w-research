/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0ff6c
 * Function: FUN_ffffffffbfc0ff6c
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

long FUN_ffffffffbfc0ff6c(long param_1,undefined1 *param_2,ulong param_3,uint param_4)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  uint uVar5;
  long lVar4;
  undefined8 unaff_s0;
  int iVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined8 unaff_s6;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x60);
  puVar9[9] = &_gp;
  puVar9[8] = unaff_s6;
  puVar9[7] = unaff_s5;
  puVar9[6] = unaff_s4;
  puVar9[5] = unaff_s3;
  puVar9[3] = unaff_s1;
  puVar9[10] = in_ra;
  puVar9[4] = unaff_s2;
  puVar9[2] = unaff_s0;
  puVar7 = (undefined1 *)(param_3 & (long)(int)-(uint)*(byte *)(param_1 + 0xa0c));
  puVar8 = puVar7;
  if ((int)param_3 != (int)puVar7) {
    *(undefined4 *)puVar9 = 0;
    for (iVar6 = 0; iVar6 < (int)param_3 - (int)puVar7; iVar6 = iVar6 + 1) {
      uVar2 = *puVar8;
      puVar8 = (undefined1 *)(long)((int)puVar8 + 1);
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0xe0c))(param_1,puVar9,uVar2);
    }
    bVar1 = *(byte *)(param_1 + 0xa0c);
    for (; iVar6 < (int)(uint)bVar1; iVar6 = iVar6 + 1) {
      if (param_4 == 0) {
        uVar5 = (uint)*(byte *)(param_1 + 0xa0c);
        goto LAB_ffffffffbfc1006c;
      }
      param_4 = param_4 - 1;
      uVar2 = *param_2;
      puVar8 = (undefined1 *)(long)((int)puVar8 + 1);
      param_2 = (undefined1 *)(long)((int)param_2 + 1);
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0xe0c))(param_1,puVar9,uVar2);
      bVar1 = *(byte *)(param_1 + 0xa0c);
    }
    if (param_4 == 0) {
      uVar5 = (uint)*(byte *)(param_1 + 0xa0c);
LAB_ffffffffbfc1006c:
      while (bVar3 = iVar6 < (int)uVar5, iVar6 = iVar6 + 1, bVar3) {
        uVar2 = *puVar8;
        puVar8 = (undefined1 *)(long)((int)puVar8 + 1);
        (*(code *)(long)(DAT_ffffffffbfc436fc + -0xe0c))(param_1,puVar9,uVar2);
        uVar5 = (uint)*(byte *)(param_1 + 0xa0c);
      }
    }
    lVar4 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x4dc))(param_1,puVar7,*puVar9);
    if (lVar4 != 0) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x56b8,puVar7);
      return lVar4;
    }
  }
  while( true ) {
    if (param_4 < *(byte *)(param_1 + 0xa0c)) {
      if (param_4 == 0) {
        lVar4 = 0;
      }
      else {
        *(undefined4 *)puVar9 = 0;
        uVar5 = 0;
        puVar7 = puVar8;
        while( true ) {
          if ((int)(uint)*(byte *)(param_1 + 0xa0c) <= (int)uVar5) goto LAB_ffffffffbfc101b4;
          if (uVar5 == param_4) break;
          uVar5 = uVar5 + 1;
          uVar2 = *param_2;
          puVar7 = (undefined1 *)(long)((int)puVar7 + 1);
          param_2 = (undefined1 *)(long)((int)param_2 + 1);
          (*(code *)(long)(DAT_ffffffffbfc436fc + -0xe0c))(param_1,puVar9,uVar2);
        }
        bVar1 = *(byte *)(param_1 + 0xa0c);
        while (bVar3 = (int)uVar5 < (int)(uint)bVar1, uVar5 = uVar5 + 1, bVar3) {
          uVar2 = *puVar7;
          puVar7 = (undefined1 *)(long)((int)puVar7 + 1);
          (*(code *)(long)(DAT_ffffffffbfc436fc + -0xe0c))(param_1,puVar9,uVar2);
LAB_ffffffffbfc101b4:
          bVar1 = *(byte *)(param_1 + 0xa0c);
        }
        lVar4 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x4dc))(param_1,puVar8,*puVar9);
      }
      return lVar4;
    }
    *(undefined4 *)puVar9 = 0;
    if ((param_4 & 0xffff) == 0) {
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0x1650);
    }
    iVar6 = 0;
    while (bVar3 = iVar6 < (int)(uint)*(byte *)(param_1 + 0xa0c), iVar6 = iVar6 + 1, bVar3) {
      uVar2 = *param_2;
      param_2 = (undefined1 *)(long)((int)param_2 + 1);
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0xe0c))(param_1,puVar9,uVar2);
    }
    lVar4 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x4dc))(param_1,puVar8,*puVar9);
    if (lVar4 != 0) break;
    param_4 = param_4 - *(byte *)(param_1 + 0xa0c);
    puVar8 = (undefined1 *)(long)(int)((int)puVar8 + (uint)*(byte *)(param_1 + 0xa0c));
  }
  return lVar4;
}

