/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc50e2c
 * Function: FUN_ffffffffbfc50e2c
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

undefined8 FUN_ffffffffbfc50e2c(long param_1)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  undefined2 uVar5;
  undefined8 uVar4;
  short *psVar6;
  int iVar7;
  undefined8 unaff_s0;
  undefined4 *puVar8;
  undefined8 unaff_s1;
  uint uVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  ushort *puVar10;
  code *pcVar11;
  undefined2 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined2 *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(puVar12 + 0x18) = &_gp;
  *(undefined8 *)(puVar12 + 0x14) = unaff_s3;
  *(undefined8 *)(puVar12 + 0x10) = unaff_s2;
  puVar10 = (ushort *)(long)iRamffffffffbfc55da0;
  *(undefined8 *)(puVar12 + 0x1c) = in_ra;
  iVar7 = *(int *)(puVar10 + 0xc);
  *(undefined8 *)(puVar12 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar12 + 8) = unaff_s0;
  iVar2 = iRamffffffffbfc55c28;
  if (iVar7 != 1) {
    return 0;
  }
  uVar9 = (uint)(*(ushort *)(param_1 + 0x10) >> 8) | (*(ushort *)(param_1 + 0x10) & 0xff) << 8;
  if (*puVar10 == uVar9) {
    if (*(int *)(puVar10 + 6) == 0) {
      pcVar11 = (code *)(long)iRamffffffffbfc55dd4;
      puVar10[6] = 0;
      puVar10[7] = 4;
      puVar10[8] = 0;
      puVar10[9] = 0;
      (*pcVar11)(iVar2 + 0x4a80);
    }
    iVar7 = ((uint)(*(ushort *)(param_1 + 0x14) >> 8) | (*(ushort *)(param_1 + 0x14) & 0xff) << 8) *
            0x10 + ((uint)(*(ushort *)(param_1 + 0x12) >> 8) |
                   (*(ushort *)(param_1 + 0x12) & 0xff) << 8);
    if (iVar7 == 0) {
      *(int *)(puVar10 + 8) = *(int *)(puVar10 + 8) + 1;
    }
    uVar9 = iVar7 + *(int *)(puVar10 + 8) * 0x100000 + -0x100000;
    if (((uVar9 < *(uint *)(long)iRamffffffffbfc55d40) ||
        (((uint *)(long)iRamffffffffbfc55d40)[1] <= uVar9)) || (uVar9 - 0x60000 < 0x10000)) {
      psVar6 = (short *)(long)iRamffffffffbfc55da0;
      *puVar12 = 0;
      *psVar6 = *psVar6 + 1;
      pcVar11 = (code *)(long)iRamffffffffbfc55d9c;
      goto LAB_ffffffffbfc51050;
    }
    puVar8 = (undefined4 *)(long)(int)(uVar9 + 0xbdc00000);
    lVar3 = (*(code *)(long)iRamffffffffbfc55cd4)
                      (puVar8,(int)param_1 + 0x18,
                       *(ushort *)(param_1 + 0x16) >> 8 | *(ushort *)(param_1 + 0x16) << 8);
    if (lVar3 == 0) {
      uVar1 = *puVar10;
      *puVar12 = 0;
      *puVar10 = uVar1 + 1;
      pcVar11 = (code *)(long)iRamffffffffbfc55d9c;
      goto LAB_ffffffffbfc51050;
    }
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4a98,uVar9,puVar8);
    (*(code *)(long)iRamffffffffbfc55dd4)
              (iRamffffffffbfc55c28 + 0x4ac0,*(undefined4 *)(param_1 + 0x18),*puVar8);
    puVar10[0xc] = 0;
    puVar10[0xd] = 2;
    uVar5 = 0x900;
LAB_ffffffffbfc51048:
    *puVar12 = uVar5;
  }
  else {
    uVar5 = 0x600;
    if (*puVar10 - 1 != uVar9) goto LAB_ffffffffbfc51048;
    *puVar12 = 0;
  }
  pcVar11 = (code *)(long)iRamffffffffbfc55d9c;
LAB_ffffffffbfc51050:
  uVar4 = (*pcVar11)(param_1,puVar12,2);
  (*(code *)(long)iRamffffffffbfc55dcc)(uVar4,0x40);
  return 0;
}

