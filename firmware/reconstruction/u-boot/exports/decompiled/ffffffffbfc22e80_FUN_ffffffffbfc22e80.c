/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc22e80
 * Function: FUN_ffffffffbfc22e80
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

uint FUN_ffffffffbfc22e80(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  
  param_1 = ~param_1;
  iVar10 = DAT_ffffffffbfc436f0 + 0x6530;
  for (; 7 < param_3; param_3 = param_3 - 8) {
    pbVar1 = param_2 + 1;
    pbVar2 = param_2 + 2;
    pbVar3 = param_2 + 3;
    pbVar4 = param_2 + 4;
    pbVar5 = param_2 + 5;
    pbVar6 = param_2 + 6;
    pbVar7 = param_2 + 7;
    uVar9 = param_1 >> 8 ^ *(uint *)(long)(int)(((param_1 ^ *param_2) & 0xff) * 4 + iVar10);
    param_2 = (byte *)(long)((int)param_2 + 8);
    uVar9 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar1) & 0xff) * 4 + iVar10);
    uVar9 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar2) & 0xff) * 4 + iVar10);
    uVar9 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar3) & 0xff) * 4 + iVar10);
    uVar9 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar4) & 0xff) * 4 + iVar10);
    uVar9 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar5) & 0xff) * 4 + iVar10);
    uVar9 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar6) & 0xff) * 4 + iVar10);
    param_1 = uVar9 >> 8 ^ *(uint *)(long)(int)(((uVar9 ^ *pbVar7) & 0xff) * 4 + iVar10);
  }
  if (param_3 != 0) {
    do {
      bVar8 = *param_2;
      param_3 = param_3 - 1;
      param_2 = (byte *)(long)((int)param_2 + 1);
      param_1 = param_1 >> 8 ^
                *(uint *)(long)(int)(((param_1 ^ bVar8) & 0xff) * 4 + DAT_ffffffffbfc436f0 + 0x6530)
      ;
    } while (param_3 != 0);
  }
  return ~param_1;
}

