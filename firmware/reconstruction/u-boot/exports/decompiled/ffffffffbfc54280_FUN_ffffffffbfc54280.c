/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc54280
 * Function: FUN_ffffffffbfc54280
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

void FUN_ffffffffbfc54280(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined8 unaff_s0;
  long lVar5;
  undefined8 unaff_s1;
  long lVar6;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar7;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar9[6] = &_gp;
  *puVar9 = unaff_s0;
  puVar9[7] = in_ra;
  iVar4 = (int)param_1;
  lVar5 = (long)(iVar4 + 0x22);
  puVar9[5] = unaff_s5;
  puVar9[4] = unaff_s4;
  puVar9[3] = unaff_s3;
  iVar7 = (int)param_2 + -0x22;
  puVar9[2] = unaff_s2;
  puVar9[1] = unaff_s1;
  *(undefined1 *)(param_1 + 0x22) = 0;
  *(undefined1 *)(lVar5 + 1) = 0x43;
  uVar1 = uRamffffffffbfc55ca4;
  pcVar8 = (code *)(long)iRamffffffffbfc55d98;
  lVar6 = (long)(iVar4 + 0xe);
  *(undefined1 *)(lVar5 + 3) = 0x44;
  *(char *)(lVar5 + 5) = (char)iVar7;
  *(char *)(lVar5 + 4) = (char)((uint)iVar7 >> 8);
  *(undefined1 *)(lVar5 + 2) = 0;
  *(undefined1 *)(lVar5 + 6) = 0;
  *(undefined1 *)(lVar5 + 7) = 0;
  (*pcVar8)(iVar4 + 0x1a,uVar1,4);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar4 + 0x1e,param_3,4);
  *(undefined1 *)(lVar6 + 9) = 0x11;
  uVar3 = *(undefined2 *)(lVar5 + 4);
  pcVar8 = (code *)(long)iRamffffffffbfc55cb0;
  *(char *)(lVar6 + 3) = (char)uVar3;
  *(char *)(lVar6 + 2) = (char)((ushort)uVar3 >> 8);
  uVar2 = (*pcVar8)(lVar6);
  uVar3 = (*(code *)(long)iRamffffffffbfc55d5c)(lVar5,iVar7,uVar2);
  *(char *)(lVar5 + 7) = (char)uVar3;
  *(char *)(lVar5 + 6) = (char)((ushort)uVar3 >> 8);
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc543a0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)iRamffffffffbfc55cdc)(param_1,param_2,0x11,param_3);
  return;
}

