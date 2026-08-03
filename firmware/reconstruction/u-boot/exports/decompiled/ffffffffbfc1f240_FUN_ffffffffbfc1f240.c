/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1f240
 * Function: FUN_ffffffffbfc1f240
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

long FUN_ffffffffbfc1f240(ulong param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long in_k0;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar5[2] = &_gp;
  puVar5[1] = unaff_s1;
  *puVar5 = unaff_s0;
  puVar5[3] = in_ra;
  if (param_2 == 0) {
    lVar4 = -1;
  }
  else {
    lVar4 = -1;
    if (param_1 < 3) {
      lVar4 = 0;
      if (((code *)(long)*(int *)(param_2 + 0x10) == (code *)0x0) ||
         (lVar4 = (*(code *)(long)*(int *)(param_2 + 0x10))(), -1 < lVar4)) {
        *(int *)(long)((int)param_1 * 4 + DAT_ffffffffbfc439f8) = (int)param_2;
        if (param_1 == 0) {
          uVar1 = *(undefined4 *)(param_2 + 0x20);
          iVar2 = *(int *)(in_k0 + 0x80);
          *(undefined4 *)((long)*(int *)(in_k0 + 0x80) + 4) = *(undefined4 *)(param_2 + 0x24);
          *(undefined4 *)((long)iVar2 + 8) = uVar1;
        }
        else if (param_1 == 1) {
          iVar2 = *(int *)(in_k0 + 0x80);
          *(undefined4 *)((long)*(int *)(in_k0 + 0x80) + 0xc) = *(undefined4 *)(param_2 + 0x18);
          uVar1 = DAT_ffffffffbfc4400c;
          iVar3 = *(int *)(in_k0 + 0x80);
          *(undefined4 *)((long)iVar2 + 0x10) = *(undefined4 *)(param_2 + 0x1c);
          *(undefined4 *)((long)iVar3 + 0x14) = uVar1;
        }
      }
    }
  }
  return lVar4;
}

