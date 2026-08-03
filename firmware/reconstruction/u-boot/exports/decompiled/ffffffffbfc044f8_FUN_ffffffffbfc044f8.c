/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc044f8
 * Function: FUN_ffffffffbfc044f8
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

void FUN_ffffffffbfc044f8(ulong param_1,byte param_2,ulong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  long lVar4;
  byte *pbVar5;
  ulong uVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(long)((int)&stack0x00000000 + -0x20);
  if (((param_1 & 0xffffffff00000000) == 0) && ((param_1 & 0xffffffff80000000) != 0)) {
    param_1 = param_1 & 0xffffffff | 0xffffffff00000000;
  }
  pbVar5 = (byte *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000);
  while (((ulong)pbVar5 & 7) != 0) {
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffffffffffff) goto LAB_ffffffffbfc04570;
    *pbVar5 = param_2;
    pbVar5 = pbVar5 + 1;
  }
  if (7 < param_3) {
LAB_ffffffffbfc04570:
    uVar6 = param_3 & 0xfffffffffffffff8;
    *puVar7 = (int)uVar6;
    puVar7[1] = (int)(uVar6 >> 0x20);
    puVar7[2] = (int)pbVar5;
    puVar7[3] = (int)((ulong)pbVar5 >> 0x20);
    puVar7[4] = (uint)CONCAT11(param_2,param_2) | (uint)param_2 << 0x18 | (uint)param_2 << 0x10;
    puVar7[5] = puVar7[4];
    uVar1 = puVar7[4];
    uVar2 = puVar7[5];
    lVar4 = CONCAT44(puVar7[1],*puVar7);
    puVar3 = (undefined8 *)CONCAT44(puVar7[3],puVar7[2]);
    do {
      lVar4 = lVar4 + -8;
      *puVar3 = CONCAT44(uVar2,uVar1);
      puVar3 = puVar3 + 1;
    } while (lVar4 != 0);
    param_3 = param_3 & 7;
    pbVar5 = pbVar5 + uVar6;
  }
  while (param_3 = param_3 - 1, param_3 != 0xffffffffffffffff) {
    *pbVar5 = param_2;
    pbVar5 = pbVar5 + 1;
  }
  return;
}

