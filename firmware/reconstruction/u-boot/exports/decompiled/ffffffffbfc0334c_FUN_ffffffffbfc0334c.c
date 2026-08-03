/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0334c
 * Function: FUN_ffffffffbfc0334c
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

ulong FUN_ffffffffbfc0334c(ulong param_1,ulong param_2,ulong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ulong uVar7;
  undefined4 *puVar8;
  
  puVar8 = (undefined4 *)(long)((int)&stack0x00000000 + -0x20);
  if (((param_1 & 0xffffffff00000000) == 0) && ((param_1 & 0xffffffff80000000) != 0)) {
    param_1 = param_1 & 0xffffffff | 0xffffffff00000000;
  }
  if (((param_2 & 0xffffffff00000000) == 0) && ((param_2 & 0xffffffff80000000) != 0)) {
    param_2 = param_2 & 0xffffffff | 0xffffffff00000000;
  }
  puVar5 = (undefined1 *)(param_2 & 0x7fffffffffffffff | 0x8000000000000000);
  puVar6 = (undefined1 *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000);
  param_1 = param_1 & 7;
  uVar7 = param_3;
  if ((param_2 & 7) == param_1) {
    while (param_1 != 0) {
      uVar7 = uVar7 - 1;
      *puVar6 = *puVar5;
      param_1 = (ulong)(puVar6 + 1) & 7;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    if (7 < uVar7) {
      uVar3 = uVar7 & 0xfffffffffffffff8;
      *puVar8 = (int)uVar3;
      puVar8[1] = (int)(uVar3 >> 0x20);
      puVar8[2] = (int)puVar5;
      puVar8[3] = (int)((ulong)puVar5 >> 0x20);
      puVar8[4] = (int)puVar6;
      puVar8[5] = (int)((ulong)puVar6 >> 0x20);
      lVar4 = CONCAT44(puVar8[1],*puVar8);
      puVar1 = (undefined8 *)CONCAT44(puVar8[3],puVar8[2]);
      puVar2 = (undefined8 *)CONCAT44(puVar8[5],puVar8[4]);
      do {
        lVar4 = lVar4 + -8;
        *puVar2 = *puVar1;
        puVar2 = puVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (lVar4 != 0);
      uVar7 = uVar7 & 7;
      puVar5 = puVar5 + uVar3;
      puVar6 = puVar6 + uVar3;
    }
    while( true ) {
      uVar7 = uVar7 - 1;
      if (uVar7 == 0xffffffffffffffff) break;
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  else {
    while( true ) {
      if (uVar7 - 1 == 0xffffffffffffffff) break;
      *puVar6 = *puVar5;
      uVar7 = uVar7 - 1;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  return param_3;
}

