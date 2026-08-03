/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc25068
 * Function: FUN_ffffffffbfc25068
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

uint FUN_ffffffffbfc25068(uint param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  if (param_2 != (byte *)0x0) {
    uVar18 = param_1 >> 0x10;
    param_1 = param_1 & 0xffff;
    for (; param_3 != 0; param_3 = param_3 - uVar21) {
      uVar19 = 0x15b0;
      uVar21 = 0x15b0;
      if (param_3 < 0x15b1) {
        uVar19 = param_3;
        uVar21 = param_3;
      }
      for (; iVar17 = (int)param_2, 0xf < (int)uVar19; uVar19 = uVar19 - 0x10) {
        iVar2 = param_1 + *param_2;
        iVar3 = iVar2 + (uint)param_2[1];
        iVar7 = iVar3 + (uint)param_2[2];
        iVar14 = iVar7 + (uint)param_2[3];
        iVar10 = iVar14 + (uint)param_2[4];
        iVar4 = iVar10 + (uint)param_2[5];
        iVar12 = iVar4 + (uint)param_2[6];
        iVar8 = iVar12 + (uint)param_2[7];
        iVar15 = iVar8 + (uint)param_2[8];
        iVar5 = iVar15 + (uint)param_2[9];
        iVar13 = iVar5 + (uint)param_2[10];
        iVar11 = iVar13 + (uint)param_2[0xb];
        iVar16 = iVar11 + (uint)param_2[0xc];
        iVar6 = iVar16 + (uint)param_2[0xd];
        iVar9 = iVar6 + (uint)param_2[0xe];
        param_1 = iVar9 + (uint)param_2[0xf];
        param_2 = (byte *)(long)(iVar17 + 0x10);
        uVar18 = uVar18 + iVar2 + iVar3 + iVar7 + iVar14 + iVar10 + iVar4 + iVar12 + iVar8 + iVar15
                 + iVar5 + iVar13 + iVar11 + iVar16 + iVar6 + iVar9 + param_1;
      }
      uVar20 = uVar19;
      if (uVar19 != 0) {
        do {
          bVar1 = *param_2;
          uVar20 = uVar20 - 1;
          param_2 = (byte *)(long)((int)param_2 + 1);
          param_1 = param_1 + bVar1;
          uVar18 = uVar18 + param_1;
        } while (uVar20 != 0);
        param_2 = (byte *)(long)(int)(iVar17 + uVar19);
      }
      param_1 = param_1 % 0xfff1;
      uVar18 = uVar18 % 0xfff1;
    }
    return uVar18 << 0x10 | param_1;
  }
  return 1;
}

