/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc50190
 * Function: FUN_ffffffffbfc50190
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

undefined8 FUN_ffffffffbfc50190(void)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  byte *pbVar4;
  undefined8 unaff_s0;
  int iVar5;
  undefined8 unaff_s1;
  code *pcVar6;
  uint *puVar7;
  undefined8 in_ra;
  int iVar8;
  
  iVar8 = (int)&stack0x00000000;
  puVar7 = (uint *)(long)(iVar8 + -0x50);
  *(undefined1 **)(puVar7 + 0x10) = &_gp;
  *(undefined8 *)(puVar7 + 0x12) = in_ra;
  *(undefined8 *)(puVar7 + 0xe) = unaff_s1;
  iVar5 = iRamffffffffbfc55c28;
  pcVar6 = (code *)(long)iRamffffffffbfc55dd4;
  *(undefined8 *)(puVar7 + 0xc) = unaff_s0;
  *puVar7 = 0;
  puVar7[1] = 0;
  (*pcVar6)(iVar5 + 0x4848,&DAT_ffffffffbdc00000);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar8 + -0x48,0xffffffffbdc80074,0x20);
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4870,iVar8 + -0x48);
  (*(code *)(long)iRamffffffffbfc55d98)(puVar7,0xffffffffbdc80014,4);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar8 + -0x4c,0xffffffffbdc80010,4);
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4890,puVar7[1],puVar7[1]);
  (*(code *)(long)iRamffffffffbfc55d98)(&DAT_00500000,0xffffffffbdc80000,puVar7[1]);
  pbVar4 = &DAT_00500000;
  iVar5 = 0;
  while( true ) {
    uVar2 = *puVar7;
    if ((byte *)(long)(int)(puVar7[1] + 0x500000) <= pbVar4) break;
    bVar1 = *pbVar4;
    pbVar4 = (byte *)(long)((int)pbVar4 + 1);
    iVar5 = iVar5 + (uint)bVar1;
  }
  iVar5 = iVar5 - ((uVar2 & 0xff) + ((int)(int3)(uVar2 >> 8) & 0xffU) +
                  (uVar2 >> 0x18) + ((int)(short)(uVar2 >> 0x10) & 0xffU));
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x48b8,iVar5);
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x48d8);
  if ((iVar5 == *puVar7) && (iVar5 != 0)) {
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x48f8);
    uVar3 = 0;
  }
  else {
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4900);
    uVar3 = 0xffffffffffffffff;
  }
  return uVar3;
}

