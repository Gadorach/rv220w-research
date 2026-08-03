/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc51094
 * Function: FUN_ffffffffbfc51094
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

undefined8 FUN_ffffffffbfc51094(long param_1)

{
  long lVar1;
  undefined2 uVar3;
  undefined8 uVar2;
  ushort uVar4;
  int iVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ushort *puVar6;
  undefined2 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined2 *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(puVar7 + 0x10) = &_gp;
  *(undefined8 *)(puVar7 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar7 + 8) = unaff_s0;
  puVar6 = (ushort *)(long)iRamffffffffbfc55da0;
  *(undefined8 *)(puVar7 + 0x14) = in_ra;
  iVar5 = iRamffffffffbfc55d9c;
  if (*(int *)(puVar6 + 0xc) == 0) {
    *puVar7 = 0x500;
  }
  else {
    if (*(int *)(puVar6 + 0xc) != 1) {
      return 0;
    }
    uVar4 = *(ushort *)(param_1 + 0x10) >> 8 | *(ushort *)(param_1 + 0x10) << 8;
    if (*puVar6 == uVar4) {
      iVar5 = ((uint)(*(ushort *)(param_1 + 0x14) >> 8) | (*(ushort *)(param_1 + 0x14) & 0xff) << 8)
              * 0x10 + ((uint)(*(ushort *)(param_1 + 0x12) >> 8) |
                       (*(ushort *)(param_1 + 0x12) & 0xff) << 8);
      if (iVar5 == 0) {
        *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 1;
      }
      lVar1 = (*(code *)(long)iRamffffffffbfc55ca8)
                        (iVar5 + *(int *)(puVar6 + 8) * 0x100000 + -0x100000,(int)param_1 + 0x18,
                         *(ushort *)(param_1 + 0x16) >> 8 | *(ushort *)(param_1 + 0x16) << 8,
                         *(undefined4 *)(puVar6 + 6));
      if (lVar1 == 0) {
        puVar6[6] = 0;
        puVar6[7] = 0;
        uVar4 = *puVar6;
        *puVar7 = 0;
        *puVar6 = uVar4 + 1;
        iVar5 = iRamffffffffbfc55d9c;
        goto LAB_ffffffffbfc51218;
      }
      puVar6[0xc] = 0;
      puVar6[0xd] = 2;
      uVar3 = 0x700;
    }
    else {
      uVar3 = 0x600;
      if (uVar4 <= *puVar6) {
        *puVar7 = 0;
        iVar5 = iRamffffffffbfc55d9c;
        goto LAB_ffffffffbfc51218;
      }
    }
    *puVar7 = uVar3;
    iVar5 = iRamffffffffbfc55d9c;
  }
LAB_ffffffffbfc51218:
  uVar2 = (*(code *)(long)iVar5)(param_1,puVar7,2);
  (*(code *)(long)iRamffffffffbfc55dcc)(uVar2,0x40);
  return 0;
}

