/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc21c0c
 * Function: FUN_ffffffffbfc21c0c
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

undefined8 FUN_ffffffffbfc21c0c(int *param_1,long param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar6[1] = unaff_s1;
  lVar5 = (long)*param_1;
  puVar6[2] = unaff_s2;
  iVar4 = *(int *)(lVar5 + 0x14);
  puVar6[6] = &_gp;
  puVar6[5] = unaff_s5;
  puVar6[4] = unaff_s4;
  puVar6[3] = unaff_s3;
  puVar6[7] = in_ra;
  *puVar6 = unaff_s0;
  if (param_3 == iVar4 + 1) {
    param_3 = 0;
  }
  else if (iVar4 < param_3) {
    return 0;
  }
  iVar1 = *(int *)(lVar5 + 0xc);
  if (iVar1 <= iVar4) {
    iVar3 = -param_4;
    if (iVar3 == 0) {
      iVar3 = (iVar1 * (*(int *)(lVar5 + 4) + 100)) / 100;
      if (iVar3 <= *(int *)(lVar5 + 8)) {
        iVar3 = *(int *)(lVar5 + 8);
      }
    }
    else if (iVar3 < 0) {
      iVar3 = (iVar1 * (*(int *)(lVar5 + 4) + 100)) / 100;
      if (iVar3 <= *(int *)(lVar5 + 8)) {
        iVar3 = *(int *)(lVar5 + 8);
      }
      iVar3 = iVar3 + param_4;
    }
    lVar5 = (*(code *)(long)DAT_ffffffffbfc43cbc)
                      (param_1,(iVar1 + iVar3) * *(int *)(lVar5 + 0x10) + 0x1c);
    if (lVar5 == 0) {
      return 0;
    }
    *(int *)((long)*param_1 + 0xc) = *(int *)((long)*param_1 + 0xc) + iVar3;
  }
  if (param_3 == -1) {
    param_3 = 1;
    if (iVar4 == 0) {
LAB_ffffffffbfc21d54:
      iVar1 = *param_1;
      if (param_2 == 0) {
        param_2 = 0;
        iVar3 = *(int *)((long)iVar1 + 0x10);
        iVar2 = DAT_ffffffffbfc43a54;
      }
      else {
        iVar3 = *(int *)((long)iVar1 + 0x10);
        iVar2 = DAT_ffffffffbfc43e84;
      }
      iVar4 = iVar3 * iVar4;
      goto LAB_ffffffffbfc21dfc;
    }
    iVar1 = *param_1;
  }
  else {
    if (param_3 == 0) goto LAB_ffffffffbfc21d54;
    iVar1 = *param_1;
  }
  iVar3 = *(int *)((long)iVar1 + 0x10);
  (*(code *)(long)DAT_ffffffffbfc43f84)
            (iVar3 * (param_3 + param_4 + -1) + iVar1 + 0x18,iVar3 * (param_3 + -1) + iVar1 + 0x18,
             ((iVar4 - param_3) + 1) * iVar3);
  iVar1 = *param_1;
  if (param_2 == 0) {
    param_2 = 0;
    iVar3 = *(int *)((long)iVar1 + 0x10);
    iVar2 = DAT_ffffffffbfc43a54;
  }
  else {
    iVar3 = *(int *)((long)iVar1 + 0x10);
    iVar2 = DAT_ffffffffbfc43f84;
  }
  iVar4 = iVar3 * (param_3 + -1);
LAB_ffffffffbfc21dfc:
  (*(code *)(long)iVar2)(iVar4 + iVar1 + 0x18,param_2,iVar3 * param_4);
  *(int *)((long)*param_1 + 0x14) = *(int *)((long)*param_1 + 0x14) + param_4;
  return 1;
}

