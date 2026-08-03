/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc53a90
 * Function: FUN_ffffffffbfc53a90
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

void FUN_ffffffffbfc53a90(long param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  long lVar7;
  undefined8 unaff_s3;
  long lVar8;
  undefined8 unaff_s4;
  int iVar9;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[5] = &_gp;
  puVar11[3] = unaff_s3;
  iVar3 = iRamffffffffbfc55d78;
  lVar8 = (long)iRamffffffffbfc55d78;
  pcVar10 = (code *)(long)iRamffffffffbfc55cc0;
  puVar11[6] = in_ra;
  puVar11[4] = unaff_s4;
  puVar11[2] = unaff_s2;
  lVar7 = (long)(iVar3 + 0xe);
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  (*pcVar10)(lVar8,0,0x36);
  lVar6 = (long)(iVar3 + 0x22);
  *(undefined1 *)(lVar6 + 0xc) = 0x50;
  iVar9 = (int)param_1 + 4;
  pcVar10 = (code *)(long)iRamffffffffbfc55d98;
  *(undefined4 *)(lVar6 + 4) = *(undefined4 *)(param_1 + 0x24);
  uVar2 = uRamffffffffbfc55ca4;
  *(undefined4 *)(lVar6 + 8) = *(undefined4 *)(param_1 + 0x20);
  *(undefined1 *)(lVar6 + 0x10) = 0;
  *(undefined1 *)(lVar6 + 0x11) = 0;
  *(undefined1 *)(lVar8 + 0x22) = *(undefined1 *)(param_1 + 0x18);
  *(undefined1 *)(lVar6 + 1) = *(undefined1 *)(param_1 + 0x19);
  *(char *)(lVar6 + 2) = (char)((ushort)*(undefined2 *)(param_1 + 0x1a) >> 8);
  uVar1 = *(undefined1 *)(param_1 + 0x1b);
  *(undefined1 *)(lVar6 + 0xd) = 0x10;
  *(undefined1 *)(lVar6 + 0xe) = 5;
  *(undefined1 *)(lVar6 + 3) = uVar1;
  *(undefined1 *)(lVar6 + 0xf) = 0xc0;
  *(undefined1 *)(lVar6 + 0x12) = 0;
  *(undefined1 *)(lVar6 + 0x13) = 0;
  (*pcVar10)(iVar3 + 0x1a,uVar2,4);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar3 + 0x1e,iVar9,4);
  pcVar10 = (code *)(long)iRamffffffffbfc55cb0;
  *(undefined1 *)(lVar7 + 9) = 6;
  *(undefined1 *)(lVar7 + 3) = 0x14;
  *(undefined1 *)(lVar7 + 2) = 0;
  uVar4 = (*pcVar10)(lVar7);
  uVar5 = (*(code *)(long)iRamffffffffbfc55d5c)(lVar6,0x14,uVar4);
  *(char *)(lVar6 + 0x11) = (char)uVar5;
  *(char *)(lVar6 + 0x10) = (char)((ushort)uVar5 >> 8);
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc53be8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)iRamffffffffbfc55cdc)(lVar8,0x36,6,iVar9);
  return;
}

