/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc24c50
 * Function: FUN_ffffffffbfc24c50
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

undefined8 FUN_ffffffffbfc24c50(long param_1)

{
  undefined8 uVar1;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar2;
  long lVar3;
  undefined8 in_ra;
  
  lVar3 = (long)((int)&stack0x00000000 + -0x30);
  uVar1 = 0xfffffffffffffffe;
  *(undefined1 **)(lVar3 + 0x20) = &_gp;
  *(undefined8 *)(lVar3 + 0x10) = unaff_s0;
  *(undefined8 *)(lVar3 + 0x28) = in_ra;
  *(undefined8 *)(lVar3 + 0x18) = unaff_s1;
  if (((param_1 != 0) && ((long)*(int *)(param_1 + 0x1c) != 0)) && (*(int *)(param_1 + 0x24) != 0))
  {
    lVar2 = (long)*(int *)((long)*(int *)(param_1 + 0x1c) + 0x14);
    if (lVar2 != 0) {
      (*(code *)(long)(DAT_ffffffffbfc43700 + 0x4b28))(lVar2,param_1,lVar3);
      (*(code *)(long)*(int *)(param_1 + 0x24))
                (*(undefined4 *)(param_1 + 0x28),*(int *)(lVar2 + 0x28),
                 *(int *)(lVar2 + 0x2c) - *(int *)(lVar2 + 0x28));
      (*(code *)(long)*(int *)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),lVar2,0x40);
    }
    (*(code *)(long)*(int *)(param_1 + 0x24))
              (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c),0x18);
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return uVar1;
}

