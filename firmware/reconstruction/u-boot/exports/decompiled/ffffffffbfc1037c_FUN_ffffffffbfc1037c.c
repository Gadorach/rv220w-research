/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1037c
 * Function: FUN_ffffffffbfc1037c
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

undefined8 FUN_ffffffffbfc1037c(long param_1,uint param_2,uint param_3)

{
  char cVar1;
  ushort uVar2;
  long lVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 uVar8;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[6] = &_gp;
  iVar5 = *(int *)(param_1 + 8);
  puVar10[4] = unaff_s4;
  puVar10[2] = unaff_s2;
  *puVar10 = unaff_s0;
  puVar10[7] = in_ra;
  puVar10[5] = unaff_s5;
  puVar10[3] = unaff_s3;
  puVar10[1] = unaff_s1;
  if (iVar5 == 0x1000000) {
    if (-1 < (int)param_2) {
      if ((int)param_2 <= (int)param_3) {
        pcVar4 = (char *)(long)(int)(param_2 + (int)param_1 + 0x80c);
        uVar6 = param_2;
        iVar5 = 0;
        while (uVar6 <= param_3) {
          cVar1 = *pcVar4;
          uVar6 = uVar6 + 1;
          pcVar4 = (char *)(long)((int)pcVar4 + 1);
          if (cVar1 != '\0') {
            iVar5 = iVar5 + 1;
          }
        }
        if (iVar5 == 0) {
          (*(code *)(long)DAT_ffffffffbfc439f0)(10);
        }
        else {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5530);
        }
        uVar8 = 0;
        iVar5 = param_2 + (int)param_1 + 0x80c;
        for (; param_2 <= param_3; param_2 = param_2 + 1) {
          if (*(char *)(long)iVar5 == '\0') {
            uVar2 = *(ushort *)(param_1 + 0xa1c);
            if (uVar2 == 2) {
LAB_ffffffffbfc10504:
              (*(code *)(long)(DAT_ffffffffbfc436fc + -0xc50))(param_1,param_2);
              if (*(char *)(param_1 + 0xa0d) == '\x01') {
                uVar7 = 0xaaa;
              }
              else {
                uVar7 = 0x555;
              }
              (*(code *)(long)(DAT_ffffffffbfc436fc + -0xd40))(param_1,param_2,uVar7,0x80);
              (*(code *)(long)(DAT_ffffffffbfc436fc + -0xc50))(param_1,param_2);
              uVar7 = 0x30;
              pcVar9 = (code *)(long)(DAT_ffffffffbfc436fc + -0xd40);
LAB_ffffffffbfc1057c:
              (*pcVar9)(param_1,param_2,0,uVar7);
            }
            else if (uVar2 < 3) {
              if (uVar2 == 1) goto LAB_ffffffffbfc104b8;
            }
            else {
              if (uVar2 == 3) {
LAB_ffffffffbfc104b8:
                pcVar9 = (code *)(long)(DAT_ffffffffbfc436fc + -0xd40);
                (*pcVar9)(param_1,param_2,0,0x50);
                (*pcVar9)(param_1,param_2,0,0x20);
                uVar7 = 0xd0;
                goto LAB_ffffffffbfc1057c;
              }
              if (uVar2 == 4) goto LAB_ffffffffbfc10504;
            }
            lVar3 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x8b8))
                              (param_1,param_2,*(undefined4 *)(param_1 + 0xa10),
                               DAT_ffffffffbfc436f4 + -0x54f8);
            if (lVar3 == 0) {
              (*(code *)(long)DAT_ffffffffbfc439f0)(0x2e);
            }
            else {
              uVar8 = 1;
            }
          }
          iVar5 = iVar5 + 1;
        }
        pcVar9 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar5 = DAT_ffffffffbfc436f0 + 0x6ed8;
        goto LAB_ffffffffbfc105d8;
      }
    }
    uVar8 = 1;
    pcVar9 = (code *)(long)DAT_ffffffffbfc43e38;
    iVar5 = DAT_ffffffffbfc436f4 + -0x5548;
  }
  else {
    uVar8 = 1;
    pcVar9 = (code *)(long)DAT_ffffffffbfc43e38;
    iVar5 = DAT_ffffffffbfc436f4 + -0x5578;
  }
LAB_ffffffffbfc105d8:
  (*pcVar9)(iVar5);
  return uVar8;
}

