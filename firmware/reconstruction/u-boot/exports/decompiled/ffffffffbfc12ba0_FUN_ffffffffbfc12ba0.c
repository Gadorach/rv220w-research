/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc12ba0
 * Function: FUN_ffffffffbfc12ba0
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

char * FUN_ffffffffbfc12ba0(char *param_1,char *param_2,uint *param_3,int *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  iVar2 = *param_4;
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar5[5] = &_gp;
  puVar5[4] = unaff_s4;
  puVar5[3] = unaff_s3;
  puVar5[2] = unaff_s2;
  puVar5[1] = unaff_s1;
  *puVar5 = unaff_s0;
  puVar5[6] = in_ra;
  if (iVar2 != 0) {
    param_2 = (char *)(long)((int)param_2 + -1);
    if (*param_2 == '\t') {
      uVar1 = *param_3;
      while( true ) {
        pcVar3 = (code *)(long)DAT_ffffffffbfc43e38;
        if ((int)uVar1 <= param_5) break;
        (*pcVar3)(DAT_ffffffffbfc436f4 + 0x28c8);
        *param_3 = *param_3 - 1;
        uVar1 = *param_3;
      }
      for (; pcVar4 = (code *)(long)DAT_ffffffffbfc439f0, param_1 < param_2;
          param_1 = (char *)(long)((int)param_1 + 1)) {
        if (*param_1 == '\t') {
          (*pcVar3)((*param_3 & 7) + DAT_ffffffffbfc436f4 + 0x28d0);
          *param_3 = (*param_3 & 0xfffffff8) + 8;
        }
        else {
          *param_3 = *param_3 + 1;
          (*pcVar4)(*param_1);
        }
        pcVar3 = (code *)(long)DAT_ffffffffbfc43e38;
      }
      iVar2 = *param_4;
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0x28c8);
      *param_3 = *param_3 - 1;
      iVar2 = *param_4;
    }
    *param_4 = iVar2 + -1;
  }
  return param_2;
}

