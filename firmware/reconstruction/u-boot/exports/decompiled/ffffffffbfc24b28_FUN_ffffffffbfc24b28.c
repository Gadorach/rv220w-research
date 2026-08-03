/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc24b28
 * Function: FUN_ffffffffbfc24b28
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

void FUN_ffffffffbfc24b28(int *param_1,long param_2,int *param_3)

{
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar1;
  undefined8 *puVar2;
  undefined8 in_ra;
  
  iVar1 = param_1[0xe];
  puVar2 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar2[3] = &_gp;
  puVar2[1] = unaff_s1;
  *puVar2 = unaff_s0;
  puVar2[4] = in_ra;
  puVar2[2] = unaff_s2;
  if (iVar1 != 0) {
    *param_3 = param_1[0xf];
  }
  if (*param_1 - 4U < 2) {
    (*(code *)(long)*(int *)(param_2 + 0x24))
              (*(undefined4 *)(param_2 + 0x28),param_1[3],param_1[6] << 2);
  }
  if (*param_1 == 6) {
    (*(code *)(long)(DAT_ffffffffbfc43700 + 0x4b10))(param_1[3],param_2);
    iVar1 = DAT_ffffffffbfc43700 + 0x4488;
    (*(code *)(long)iVar1)(param_1[2],param_2);
    (*(code *)(long)iVar1)(param_1[1],param_2);
  }
  param_1[0xc] = param_1[10];
  *param_1 = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xd] = param_1[10];
  if ((code *)(long)param_1[0xe] != (code *)0x0) {
    iVar1 = (*(code *)(long)param_1[0xe])(0,0,0);
    param_1[0xf] = iVar1;
  }
  if ((code *)(long)*(int *)(param_2 + 0x30) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc24c30. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(long)*(int *)(param_2 + 0x30))(0,0);
    return;
  }
  return;
}

