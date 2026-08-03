/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc18ec4
 * Function: FUN_ffffffffbfc18ec4
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

int FUN_ffffffffbfc18ec4(undefined8 param_1,undefined1 *param_2,int param_3)

{
  bool bVar1;
  int iVar3;
  long lVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int iVar4;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar5[5] = &_gp;
  puVar5[4] = unaff_s4;
  puVar5[3] = unaff_s3;
  puVar5[2] = unaff_s2;
  *puVar5 = unaff_s0;
  puVar5[6] = in_ra;
  puVar5[1] = unaff_s1;
  iVar3 = 0;
  while( true ) {
    lVar2 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar3);
    iVar4 = iVar3;
    if (lVar2 == 0) {
      return -1;
    }
    while (lVar2 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar4), lVar2 != 0) {
      bVar1 = 0x1ffff < iVar4;
      iVar4 = iVar4 + 1;
      if (bVar1) {
        return -1;
      }
    }
    iVar3 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x71f0))(param_1,iVar3);
    if (-1 < iVar3) break;
    iVar3 = iVar4 + 1;
  }
  iVar4 = 0;
  do {
    iVar4 = iVar4 + 1;
    if (iVar4 == param_3 + 1) break;
    lVar2 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar3);
    *param_2 = (char)lVar2;
    param_2 = (undefined1 *)(long)((int)param_2 + 1);
    iVar3 = iVar3 + 1;
  } while (lVar2 != 0);
  if (param_3 == iVar4) {
    *param_2 = 0;
  }
  return iVar4;
}

