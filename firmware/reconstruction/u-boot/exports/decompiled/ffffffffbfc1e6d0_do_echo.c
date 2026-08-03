/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1e6d0
 * Function: do_echo
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
 * Recovered from U-Boot command table: command='echo', maxargs=64, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='echo', maxargs=64, repeatable=1, usage=''. */

undefined8 do_echo(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  bool bVar1;
  char cVar2;
  undefined8 unaff_s0;
  char *pcVar3;
  int iVar4;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar5;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar7[5] = &_gp;
  puVar7[4] = unaff_s4;
  puVar7[3] = unaff_s3;
  puVar7[2] = unaff_s2;
  puVar7[1] = unaff_s1;
  iVar5 = 1;
  puVar7[6] = in_ra;
  *puVar7 = unaff_s0;
  bVar1 = true;
LAB_ffffffffbfc1e768:
  if (param_3 <= iVar5) {
    if (bVar1) {
      (*(code *)(long)DAT_ffffffffbfc439f0)(10);
    }
    return 0;
  }
  pcVar3 = (char *)(long)*(int *)(param_4 + 4);
  if (iVar5 < 2) goto LAB_ffffffffbfc1e750;
  pcVar6 = (code *)(long)DAT_ffffffffbfc439f0;
  cVar2 = ' ';
  do {
    (*pcVar6)(cVar2);
LAB_ffffffffbfc1e750:
    while( true ) {
      cVar2 = *pcVar3;
      iVar4 = (int)pcVar3;
      pcVar3 = (char *)(long)(iVar4 + 1);
      pcVar6 = (code *)(long)DAT_ffffffffbfc439f0;
      if (cVar2 == '\0') {
        iVar5 = iVar5 + 1;
        param_4 = (long)((int)param_4 + 4);
        goto LAB_ffffffffbfc1e768;
      }
      if ((cVar2 != '\\') || (*pcVar3 != 'c')) break;
      pcVar3 = (char *)(long)(iVar4 + 2);
      bVar1 = false;
    }
  } while( true );
}

