/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33974
 * Function: FUN_ffffffffbfc33974
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

long FUN_ffffffffbfc33974(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  long lVar3;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 *puVar4;
  undefined8 in_ra;
  
  puVar4 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar4[5] = &_gp;
  puVar4[4] = unaff_s4;
  iVar1 = DAT_ffffffffbfc436f0;
  puVar4[2] = unaff_s2;
  puVar4[3] = unaff_s3;
  puVar4[1] = unaff_s1;
  *puVar4 = unaff_s0;
  puVar4[6] = in_ra;
  lVar2 = (*(code *)(long)(iVar1 + 0x3620))(0x30d0001);
  if ((lVar2 == 0) && (lVar2 = (*(code *)(long)(iVar1 + 0x3620))(0x30d0300), lVar2 == 0)) {
    lVar2 = -1;
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + 0x2430,param_1,
               *(undefined4 *)(long)((int)param_2 * 4 + DAT_ffffffffbfc436f4 + 0x2f60));
    if ((code *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x2f40) == (code *)0x0) {
      lVar2 = -1;
    }
    else {
      lVar3 = (*(code *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x2f40))(param_1,param_2);
      lVar2 = 0;
      if (lVar3 != 0) {
        return lVar3;
      }
    }
    lVar3 = (long)(DAT_ffffffffbfc436f4 + 0x2f40);
    if (((((code *)(long)*(int *)(lVar3 + 8) == (code *)0x0) ||
         (lVar2 = (*(code *)(long)*(int *)(lVar3 + 8))(param_1,param_2,param_3), lVar2 == 0)) &&
        (((code *)(long)*(int *)(lVar3 + 0xc) == (code *)0x0 ||
         (lVar2 = (*(code *)(long)*(int *)(lVar3 + 0xc))(param_1,param_2,param_3), lVar2 == 0)))) &&
       ((((code *)(long)*(int *)(lVar3 + 0x10) == (code *)0x0 ||
         (lVar2 = (*(code *)(long)*(int *)(lVar3 + 0x10))(param_1,param_2,param_3), lVar2 == 0)) &&
        ((code *)(long)*(int *)(lVar3 + 0x14) != (code *)0x0)))) {
      lVar2 = (*(code *)(long)*(int *)(lVar3 + 0x14))(param_1,param_2);
      return lVar2;
    }
  }
  return lVar2;
}

