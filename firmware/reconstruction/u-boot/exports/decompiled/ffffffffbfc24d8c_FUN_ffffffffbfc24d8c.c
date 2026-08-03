/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc24d8c
 * Function: FUN_ffffffffbfc24d8c
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

undefined8 FUN_ffffffffbfc24d8c(int *param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[3] = &_gp;
  puVar8[2] = unaff_s2;
  puVar8[4] = in_ra;
  puVar8[1] = unaff_s1;
  *puVar8 = unaff_s0;
  if (param_1 == (int *)0x0) {
    uVar4 = 0xfffffffffffffffe;
  }
  else {
    piVar2 = (int *)(long)param_1[7];
    uVar4 = 0xfffffffffffffffe;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 8) {
        *piVar2 = 8;
        piVar2[1] = 0;
      }
      iVar7 = param_1[1];
      if (iVar7 == 0) {
        uVar4 = 0xfffffffffffffffb;
      }
      else {
        iVar1 = *param_1;
        pcVar5 = (char *)(long)iVar1;
        uVar6 = *(uint *)((long)param_1[7] + 4);
        do {
          cVar3 = -1;
          if (uVar6 < 2) {
            cVar3 = '\0';
          }
          if (3 < uVar6) break;
          if (*pcVar5 == cVar3) {
            uVar6 = uVar6 + 1;
          }
          else if (*pcVar5 == '\0') {
            uVar6 = 4 - uVar6;
          }
          else {
            uVar6 = 0;
          }
          iVar7 = iVar7 + -1;
          pcVar5 = (char *)(long)((int)pcVar5 + 1);
        } while (iVar7 != 0);
        *param_1 = (int)pcVar5;
        param_1[2] = param_1[2] + ((int)pcVar5 - iVar1);
        param_1[1] = iVar7;
        *(uint *)((long)param_1[7] + 4) = uVar6;
        if (uVar6 == 4) {
          iVar7 = param_1[2];
          iVar1 = param_1[5];
          (*(code *)(long)DAT_ffffffffbfc43ab8)(param_1);
          uVar4 = 0;
          param_1[2] = iVar7;
          *(undefined4 *)(long)param_1[7] = 2;
          param_1[5] = iVar1;
        }
        else {
          uVar4 = 0xfffffffffffffffd;
        }
      }
    }
  }
  return uVar4;
}

