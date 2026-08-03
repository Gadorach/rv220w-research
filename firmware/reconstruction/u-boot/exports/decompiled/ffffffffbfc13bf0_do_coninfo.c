/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13bf0
 * Function: do_coninfo
 * Subsystem: u-boot-command
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
 * 
 * Recovered from U-Boot command table: command='coninfo', maxargs=3, repeatable=1, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: u-boot-command
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='coninfo', maxargs=3, repeatable=1, usage=''. */

undefined8 do_coninfo(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 unaff_s0;
  undefined4 *puVar8;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int *piVar9;
  undefined8 unaff_s3;
  int iVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar11[4] = &_gp;
  puVar11[3] = unaff_s3;
  iVar3 = DAT_ffffffffbfc4400c;
  iVar4 = DAT_ffffffffbfc436f4;
  iVar10 = 1;
  puVar11[5] = in_ra;
  iVar4 = iVar4 + -0x4d38;
  puVar11[2] = unaff_s2;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  while( true ) {
    puVar8 = (undefined4 *)(long)DAT_ffffffffbfc43a24;
    (*(code *)(long)iVar3)(iVar4);
    iVar3 = (*(code *)(long)DAT_ffffffffbfc43a38)(*puVar8);
    if (iVar3 < iVar10) break;
    piVar9 = (int *)(long)DAT_ffffffffbfc439f8;
    puVar2 = (uint *)(*(code *)(long)DAT_ffffffffbfc4394c)(*puVar8,iVar10);
    iVar3 = DAT_ffffffffbfc43974;
    uVar6 = 0x49;
    uVar1 = *puVar2;
    uVar5 = 0x53;
    if (-1 < (int)uVar1) {
      uVar5 = 0x2e;
    }
    if ((uVar1 & 1) == 0) {
      uVar6 = 0x2e;
    }
    uVar7 = 0x4f;
    if ((uVar1 & 2) == 0) {
      uVar7 = 0x2e;
    }
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x4d18,(int)puVar2 + 8,uVar1,uVar5,uVar6,uVar7);
    do {
      iVar4 = *piVar9;
      piVar9 = (int *)(long)((int)piVar9 + 4);
      if ((uint *)(long)iVar4 == puVar2) {
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x4d00,*(undefined4 *)(long)iVar3);
      }
      iVar3 = iVar3 + 4;
    } while (piVar9 != (int *)(long)(DAT_ffffffffbfc439f8 + 0xc));
    iVar4 = 10;
    iVar10 = iVar10 + 1;
    iVar3 = DAT_ffffffffbfc439f0;
  }
  return 0;
}

