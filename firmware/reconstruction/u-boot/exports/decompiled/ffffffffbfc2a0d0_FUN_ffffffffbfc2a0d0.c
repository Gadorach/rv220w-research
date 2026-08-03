/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2a0d0
 * Function: FUN_ffffffffbfc2a0d0
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

undefined8 FUN_ffffffffbfc2a0d0(uint param_1,uint param_2,ushort *param_3,long param_4)

{
  bool bVar1;
  undefined8 unaff_s0;
  ushort uVar2;
  undefined8 unaff_s1;
  int iVar3;
  undefined8 unaff_s2;
  ushort *puVar4;
  undefined8 in_ra;
  
  puVar4 = (ushort *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(puVar4 + 0x14) = &_gp;
  *(undefined8 *)(puVar4 + 0x10) = unaff_s2;
  *(undefined8 *)(puVar4 + 0x18) = in_ra;
  *(undefined8 *)(puVar4 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar4 + 8) = unaff_s0;
  if (param_4 == 1) {
    uVar2 = (ushort)*(byte *)param_3;
  }
  else {
    if (param_4 != 2) {
      return 1;
    }
    uVar2 = *param_3;
  }
  iVar3 = 1;
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x10,(param_1 & 0xff) << 8 | 1);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x18,uVar2);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x19,0);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x1a,0);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x1b,0);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x11,(param_2 & 0xff) << 8 | 1);
  (*(code *)(long)DAT_ffffffffbfc43df0)(0x1e,0x11,puVar4);
  (*(code *)(long)DAT_ffffffffbfc43b18)(10);
  uVar2 = *puVar4;
  while( true ) {
    if ((uVar2 & 3) == 0) {
      return 0;
    }
    (*(code *)(long)DAT_ffffffffbfc43df0)(0x1e,0x11,puVar4);
    (*(code *)(long)DAT_ffffffffbfc43b18)(10);
    bVar1 = iVar3 == 5;
    iVar3 = iVar3 + 1;
    if (bVar1) break;
    uVar2 = *puVar4;
  }
  return 0;
}

