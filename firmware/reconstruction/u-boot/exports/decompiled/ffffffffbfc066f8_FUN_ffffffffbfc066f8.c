/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc066f8
 * Function: FUN_ffffffffbfc066f8
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

ulong FUN_ffffffffbfc066f8(undefined1 param_1,undefined2 param_2,byte *param_3,ulong param_4)

{
  ushort uVar1;
  long lVar2;
  byte bVar4;
  short sVar3;
  undefined8 unaff_s0;
  byte *pbVar5;
  uint uVar6;
  undefined8 unaff_s1;
  int iVar7;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar8[6] = &_gp;
  puVar8[5] = unaff_s5;
  puVar8[3] = unaff_s3;
  puVar8[2] = unaff_s2;
  puVar8[7] = in_ra;
  puVar8[4] = unaff_s4;
  puVar8[1] = unaff_s1;
  *puVar8 = unaff_s0;
  if (7 < param_4) {
    lVar2 = (*(code *)(long)DAT_ffffffffbfc43fe0)(param_1,param_2);
    if (lVar2 != 0) {
      return 0xffffffffffffffff;
    }
    sVar3 = 0;
    iVar7 = 0;
    pbVar5 = param_3;
    do {
      iVar7 = iVar7 + 1;
      bVar4 = (*(code *)(long)DAT_ffffffffbfc43840)(param_1);
      *pbVar5 = bVar4;
      sVar3 = sVar3 + (ushort)bVar4;
      pbVar5 = (byte *)(long)((int)pbVar5 + 1);
    } while (iVar7 != 8);
    if (*(short *)param_3 == -1) {
      return 0xffffffffffffffff;
    }
    if (0xf8 < (ushort)(*(ushort *)(param_3 + 2) - 8)) {
      return 0xffffffffffffffff;
    }
    if (param_4 < *(ushort *)(param_3 + 2)) {
      return 0xffffffffffffffff;
    }
    uVar6 = 0;
    while( true ) {
      if (*(ushort *)(param_3 + 2) - 8 <= uVar6) break;
      bVar4 = (*(code *)(long)DAT_ffffffffbfc43840)(param_1);
      iVar7 = (int)param_3 + uVar6;
      uVar6 = uVar6 + 1;
      *(byte *)((long)iVar7 + 8) = bVar4;
      sVar3 = sVar3 + (ushort)bVar4;
    }
    uVar1 = *(ushort *)(param_3 + 6);
    if ((ushort)(sVar3 - ((uVar1 & 0xff) + (uVar1 >> 8))) == uVar1) {
      return (ulong)*(ushort *)(param_3 + 2);
    }
  }
  return 0xffffffffffffffff;
}

