/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc220c0
 * Function: FUN_ffffffffbfc220c0
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

undefined8 FUN_ffffffffbfc220c0(undefined1 param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 unaff_s0;
  code *pcVar5;
  ushort *puVar6;
  undefined8 in_ra;
  
  puVar6 = (ushort *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(puVar6 + 0xc) = &_gp;
  *(undefined8 *)(puVar6 + 8) = unaff_s0;
  pcVar5 = (code *)(long)DAT_ffffffffbfc43df0;
  *(undefined8 *)(puVar6 + 0x10) = in_ra;
  lVar3 = (*pcVar5)(param_1,10,puVar6);
  uVar1 = *puVar6;
  if (lVar3 == 0) {
    if ((ulong)uVar1 == 0xffff) {
      pcVar5 = (code *)(long)DAT_ffffffffbfc43df0;
    }
    else {
      pcVar5 = (code *)(long)DAT_ffffffffbfc43df0;
      if ((uVar1 & 0xc00) != 0) {
        uVar2 = getCopReg(2,0xb);
        *(undefined4 *)((ulong)uVar1 + 0x13) = uVar2;
        return 0x16;
      }
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0xfd0);
    pcVar5 = (code *)(long)DAT_ffffffffbfc43df0;
  }
  lVar3 = (*pcVar5)(param_1,5,puVar6);
  if (lVar3 == 0) {
    if ((*puVar6 & 0x140) == 0) {
      uVar4 = 0x16;
    }
    else {
      uVar4 = 0x2c;
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0xff0);
    uVar4 = 0x16;
  }
  return uVar4;
}

