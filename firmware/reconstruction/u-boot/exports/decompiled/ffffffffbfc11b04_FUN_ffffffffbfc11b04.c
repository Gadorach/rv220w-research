/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc11b04
 * Function: FUN_ffffffffbfc11b04
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

uint FUN_ffffffffbfc11b04(long param_1,int param_2,ulong param_3)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x10);
  *puVar9 = &_gp;
  puVar9[1] = in_ra;
  if (param_1 == 0) {
    iVar5 = DAT_ffffffffbfc436f4 + -0x5448;
LAB_ffffffffbfc11bbc:
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x53f8,iVar5);
    uVar7 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x110);
    iVar8 = 0;
    do {
      iVar4 = iVar8 * 0x24;
      bVar2 = iVar5 <= iVar8;
      iVar8 = iVar8 + 1;
      if (bVar2) {
        iVar5 = DAT_ffffffffbfc436f4 + -0x53d8;
        goto LAB_ffffffffbfc11bbc;
      }
      iVar4 = (int)param_1 + iVar4 + 0x10;
      lVar6 = (long)(iVar4 + 4);
      uVar3 = getCopReg(2,0);
      *(undefined4 *)((param_3 ^ (long)*(int *)(lVar6 + 0xc)) + 0xd) = uVar3;
      uVar1 = *(uint *)((long)iVar4 + 4);
      uVar7 = (param_2 - *(int *)(lVar6 + 4)) + uVar1;
    } while ((uVar7 < uVar1) || (uVar1 + *(int *)(lVar6 + 8) <= uVar7));
  }
  return uVar7;
}

