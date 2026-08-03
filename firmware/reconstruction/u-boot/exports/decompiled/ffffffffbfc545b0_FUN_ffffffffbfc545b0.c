/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc545b0
 * Function: FUN_ffffffffbfc545b0
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

undefined8 FUN_ffffffffbfc545b0(void)

{
  uint uVar1;
  long lVar2;
  byte *pbVar3;
  undefined8 unaff_s0;
  int iVar4;
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
  iVar4 = iVar8 + -0x48;
  puVar7[1] = 0;
  (*pcVar6)(iVar5 + 0x5b48);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar4,0x500074,0x20);
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4870,iVar4);
  (*(code *)(long)iRamffffffffbfc55d98)(puVar7,0x500014,4);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar8 + -0x4c,0x500010,4);
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5b68,puVar7[1]);
  uVar1 = puVar7[1];
  *(uint *)(long)iRamffffffffbfc55cd8 = uVar1;
  if (uVar1 < 0x2000001) {
    lVar2 = (*(code *)(long)iRamffffffffbfc55cd4)(iVar4,iRamffffffffbfc55c28 + 0x5b88,6);
    if (lVar2 == 0) {
      iVar5 = 0;
      for (pbVar3 = &DAT_00500000; uVar1 = *puVar7,
          pbVar3 < (byte *)(long)(int)(puVar7[1] + 0x500000);
          pbVar3 = (byte *)(long)((int)pbVar3 + 1)) {
        iVar5 = iVar5 + (uint)*pbVar3;
      }
      iVar5 = iVar5 - ((uVar1 & 0xff) + ((int)(int3)(uVar1 >> 8) & 0xffU) +
                      (uVar1 >> 0x18) + ((int)(short)(uVar1 >> 0x10) & 0xffU));
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x48b8,iVar5);
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x48d8);
      if ((iVar5 == *puVar7) && (iVar5 != 0)) {
        (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x48f8);
        return 0;
      }
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4900);
    }
  }
  return 0xffffffffffffffff;
}

