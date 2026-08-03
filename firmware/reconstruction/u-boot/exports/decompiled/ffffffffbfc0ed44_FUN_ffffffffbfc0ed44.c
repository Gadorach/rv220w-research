/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0ed44
 * Function: FUN_ffffffffbfc0ed44
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

void FUN_ffffffffbfc0ed44(int param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  undefined1 uVar3;
  undefined8 unaff_s0;
  undefined1 *puVar4;
  undefined8 unaff_s1;
  int *piVar5;
  undefined8 in_ra;
  int iVar6;
  
  iVar6 = (int)&stack0x00000000;
  piVar5 = (int *)(long)(iVar6 + -0x30);
  *(undefined1 **)(piVar5 + 8) = &_gp;
  *(undefined8 *)(piVar5 + 6) = unaff_s1;
  lVar2 = (long)DAT_ffffffffbfc436f4;
  *(undefined8 *)(piVar5 + 10) = in_ra;
  iVar1 = *(int *)(lVar2 + 0x4a74);
  *(undefined8 *)(piVar5 + 4) = unaff_s0;
  if (iVar1 != 0) {
    puVar4 = (undefined1 *)(long)(iVar6 + -0x2c);
    do {
      if (param_2 == (char *)0x0) {
        *puVar4 = 0;
      }
      else {
        uVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_2,piVar5,0x10);
        iVar1 = *piVar5;
        *puVar4 = uVar3;
        param_2 = (char *)(long)iVar1;
        if (*(char *)(long)iVar1 != '\0') {
          param_2 = (char *)(long)(iVar1 + 1);
        }
      }
      puVar4 = (undefined1 *)(long)((int)puVar4 + 1);
    } while (puVar4 != (undefined1 *)(long)(iVar6 + -0x26));
    lVar2 = (long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a74);
    do {
      if (param_1 < 1) {
        (*(code *)(long)DAT_ffffffffbfc43e84)((int)lVar2 + 0x10,iVar6 + -0x2c,6);
        return;
      }
      lVar2 = (long)*(int *)(lVar2 + 0x30);
      param_1 = param_1 + -1;
    } while (lVar2 != *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a74));
  }
  return;
}

