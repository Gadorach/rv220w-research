/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc14250
 * Function: FUN_ffffffffbfc14250
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

undefined8 FUN_ffffffffbfc14250(uint param_1,uint param_2,int *param_3,int *param_4,int *param_5)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x10);
  *puVar11 = &_gp;
  *param_5 = 0;
  *param_3 = -1;
  puVar11[1] = in_ra;
  *param_4 = -1;
  if (param_1 <= param_2) {
    piVar4 = (int *)(long)DAT_ffffffffbfc43fc4;
    lVar6 = 0;
    if (piVar4[2] != 0xffff) {
      iVar8 = DAT_ffffffffbfc43fc4 + 0xc;
      sVar1 = *(short *)(piVar4 + 1);
      uVar2 = *(ushort *)(piVar4 + 1);
      uVar9 = (piVar4[3] + *piVar4) - 1;
      while (lVar6 < (long)(ulong)uVar2) {
        uVar5 = uVar9;
        if (lVar6 != (short)(sVar1 + -1)) {
          uVar5 = ((uint *)(long)iVar8)[1] - 1;
        }
        iVar7 = (int)lVar6;
        if ((param_1 <= uVar5) && (uVar3 = *(uint *)(long)iVar8, uVar3 <= param_2)) {
          if (param_1 == uVar3) {
            *param_3 = iVar7;
          }
          if (param_2 == uVar5) {
            *param_4 = iVar7;
          }
        }
        iVar8 = iVar8 + 4;
        lVar6 = (long)(iVar7 + 1);
      }
      if (*param_3 < 0) {
        if (*param_4 < 0) {
          return 0;
        }
        pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar8 = DAT_ffffffffbfc436f4 + -0x4a10;
      }
      else {
        if (*param_4 < 0) {
          if (param_2 <= uVar9) {
            pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
            iVar8 = DAT_ffffffffbfc436f4 + -0x4a70;
            goto LAB_ffffffffbfc14368;
          }
          *param_4 = (int)(short)(sVar1 + -1);
        }
        if (*param_3 <= *param_4) {
          *param_5 = (*param_4 - *param_3) + *param_5 + 1;
          return 0;
        }
        pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar8 = DAT_ffffffffbfc436f4 + -0x4a40;
      }
LAB_ffffffffbfc14368:
      (*pcVar10)(iVar8);
      return 1;
    }
  }
  return 0;
}

