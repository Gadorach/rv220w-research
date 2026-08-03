/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2a22c
 * Function: FUN_ffffffffbfc2a22c
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

undefined8 FUN_ffffffffbfc2a22c(uint param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  ushort uVar2;
  undefined8 unaff_s0;
  int iVar3;
  undefined8 unaff_s1;
  code *pcVar4;
  ushort *puVar5;
  undefined8 in_ra;
  
  puVar5 = (ushort *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(puVar5 + 0x10) = &_gp;
  *(undefined8 *)(puVar5 + 0x14) = in_ra;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43b2c;
  *(undefined8 *)(puVar5 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar5 + 8) = unaff_s0;
  (*pcVar4)(0x1e,0x10,(param_1 & 0xff) << 8 | 1);
  iVar3 = 1;
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x11,(param_2 & 0xff) << 8 | 2);
  (*(code *)(long)DAT_ffffffffbfc43df0)(0x1e,0x11,puVar5);
  (*(code *)(long)DAT_ffffffffbfc43b18)(10);
  uVar2 = *puVar5;
  while ((uVar2 & 3) != 0) {
    (*(code *)(long)DAT_ffffffffbfc43df0)(0x1e,0x11,puVar5);
    (*(code *)(long)DAT_ffffffffbfc43b18)(10);
    bVar1 = iVar3 == 5;
    iVar3 = iVar3 + 1;
    if (bVar1) break;
    uVar2 = *puVar5;
  }
  (*(code *)(long)DAT_ffffffffbfc43df0)(0x1e,0x18,puVar5);
  pcVar4 = (code *)(long)DAT_ffffffffbfc43df0;
  *param_3 = (uint)*puVar5;
  (*pcVar4)(0x1e,0x19,puVar5);
  *param_3 = *param_3 | (uint)*puVar5 << 0x10;
  return 0;
}

