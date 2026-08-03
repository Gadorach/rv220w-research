/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1fcb0
 * Function: FUN_ffffffffbfc1fcb0
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

undefined8 FUN_ffffffffbfc1fcb0(int param_1)

{
  int iVar2;
  int iVar3;
  long lVar1;
  uint uVar4;
  long lVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  long lVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar7[3] = &_gp;
  puVar7[2] = unaff_s2;
  *puVar7 = unaff_s0;
  iVar2 = DAT_ffffffffbfc436f4;
  puVar7[1] = unaff_s1;
  puVar7[4] = in_ra;
  lVar6 = (long)(iVar2 + 0x32a8);
  uVar4 = *(uint *)((long)*(int *)(lVar6 + 8) + 4) & 0xfffffffc;
  iVar2 = ((uVar4 - param_1) + 0xfef >> 0xc) - 1;
  if (0xfff < iVar2 * 0x1000) {
    iVar3 = (*(code *)(long)DAT_ffffffffbfc43a80)(0);
    if (iVar3 == uVar4 + *(int *)(lVar6 + 8)) {
      lVar1 = (*(code *)(long)DAT_ffffffffbfc43a80)(iVar2 * -0x1000);
      lVar5 = (long)DAT_ffffffffbfc436f4;
      if (lVar1 != -1) {
        *(uint *)((long)*(int *)(lVar6 + 8) + 4) = uVar4 + iVar2 * -0x1000 | 1;
        *(int *)(lVar5 + 0x4f68) = *(int *)(lVar5 + 0x4f68) + iVar2 * -0x1000;
        return 1;
      }
      iVar3 = (*(code *)(long)DAT_ffffffffbfc43a80)(0);
      iVar2 = *(int *)(lVar6 + 8);
      uVar4 = iVar3 - iVar2;
      if (0xf < (int)uVar4) {
        *(int *)((long)DAT_ffffffffbfc436f4 + 0x4f68) =
             iVar3 - *(int *)((long)DAT_ffffffffbfc436f4 + 0x2918);
        *(uint *)((long)iVar2 + 4) = uVar4 | 1;
        return 0;
      }
    }
  }
  return 0;
}

