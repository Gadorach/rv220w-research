/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc183dc
 * Function: do_bcmmii
 * Subsystem: bcm53115-switch
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register diagnostics.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register diagnostics.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register diagnostics.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Recovered from U-Boot command table: command='bcmmii', maxargs=5, repeatable=1, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register
   diagnostics.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register
   diagnostics.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register
   diagnostics.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='bcmmii', maxargs=5, repeatable=1, usage=''. */

undefined8 do_bcmmii(long param_1,long param_2,long param_3,long param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong unaff_s0;
  ulong unaff_s1;
  ulong unaff_s2;
  ulong unaff_s3;
  ulong unaff_s4;
  ulong unaff_s5;
  code *pcVar6;
  ulong *puVar7;
  ulong in_ra;
  
  puVar7 = (ulong *)(long)((int)&stack0x00000000 + -0x50);
  puVar7[8] = (ulong)&_gp;
  puVar7[7] = unaff_s5;
  puVar7[3] = unaff_s1;
  puVar7[2] = unaff_s0;
  puVar7[9] = in_ra;
  puVar7[6] = unaff_s4;
  puVar7[5] = unaff_s3;
  uVar2 = getCopReg(2,0);
  *(undefined4 *)(param_2 + 0x1e) = uVar2;
  puVar7[4] = unaff_s2;
  cVar1 = *(char *)(long)*(int *)(param_4 + 4);
  if (2 < param_3) {
    unaff_s2 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 8),0,0x10);
  }
  if (3 < param_3) {
    unaff_s3 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 0xc),0,0x10);
  }
  if (4 < param_3) {
    uVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 0x10),0,0x10);
    *puVar7 = uVar4 & 0xffffffff;
  }
  if (cVar1 == 'r') {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2bd0,unaff_s2,unaff_s3);
    uVar4 = (*(code *)(long)DAT_ffffffffbfc43768)(unaff_s2,unaff_s3);
    iVar3 = DAT_ffffffffbfc436f4;
    pcVar6 = (code *)(long)DAT_ffffffffbfc4400c;
    *puVar7 = uVar4;
    (*pcVar6)(iVar3 + -0x2bb8,uVar4 & 0xffff);
    uVar5 = 0;
  }
  else if (cVar1 == 'w') {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2bb0,unaff_s2,unaff_s3,*puVar7);
    (*(code *)(long)DAT_ffffffffbfc4405c)(unaff_s2,unaff_s3,puVar7);
    uVar5 = 0;
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    uVar5 = 1;
  }
  return uVar5;
}

