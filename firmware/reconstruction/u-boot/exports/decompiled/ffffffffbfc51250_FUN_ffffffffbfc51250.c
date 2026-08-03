/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc51250
 * Function: FUN_ffffffffbfc51250
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

undefined8 FUN_ffffffffbfc51250(long param_1)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  short *psVar4;
  undefined8 unaff_s2;
  undefined4 *puVar5;
  code *pcVar6;
  undefined2 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined2 *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(puVar7 + 0x14) = &_gp;
  *(undefined8 *)(puVar7 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar7 + 0x10) = unaff_s2;
  psVar4 = (short *)(long)iRamffffffffbfc55da0;
  *(undefined8 *)(puVar7 + 8) = unaff_s0;
  psVar4[0xc] = 0;
  psVar4[0xd] = 1;
  *(undefined8 *)(puVar7 + 0x18) = in_ra;
  psVar4[8] = 0;
  psVar4[9] = 0;
  pcVar6 = (code *)(long)iRamffffffffbfc55dd4;
  iVar3 = iRamffffffffbfc55c28 + 0x4b18;
  puVar5 = (undefined4 *)(long)iRamffffffffbfc55d40;
  *psVar4 = (*(ushort *)(param_1 + 0x10) >> 8 | *(ushort *)(param_1 + 0x10) << 8) + 1;
  if ((ushort)(*(ushort *)(param_1 + 0xe) >> 8 | *(ushort *)(param_1 + 0xe) << 8) == 1) {
    (*pcVar6)(iRamffffffffbfc55c28 + 0x4ae0);
    psVar4[6] = 0;
    iVar3 = iRamffffffffbfc55c28;
    psVar4[7] = 4;
    puVar5[1] = 0x2000000;
    pcVar6 = (code *)(long)iRamffffffffbfc55dd4;
    *puVar5 = 0x80000;
    (*pcVar6)(iVar3 + 0x4b00,0x80000,0x2000000);
  }
  else {
    (*pcVar6)(iVar3);
    iVar3 = iRamffffffffbfc55d7c;
    pcVar6 = (code *)(long)iRamffffffffbfc55cc0;
    psVar4[6] = 0;
    psVar4[7] = 3;
    puVar5[1] = 0x2000000;
    *puVar5 = 0;
    (*pcVar6)(iVar3,0,0x99);
    (*(code *)(long)iRamffffffffbfc55d98)(iRamffffffffbfc55d7c,0xffffffffbdc6ff00,0x99);
    puVar1 = (undefined1 *)(long)iRamffffffffbfc55d7c;
    (*(code *)(long)iRamffffffffbfc55dd4)
              (iRamffffffffbfc55c28 + 0x4b40,*puVar1,puVar1[1],puVar1[2],puVar1[3],puVar1[4],
               puVar1[5]);
  }
  pcVar6 = (code *)(long)iRamffffffffbfc55d9c;
  *puVar7 = 0;
  uVar2 = (*pcVar6)(param_1,puVar7,2);
  (*(code *)(long)iRamffffffffbfc55dcc)(uVar2,0x40);
  return 0;
}

