/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc10214
 * Function: FUN_ffffffffbfc10214
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

void FUN_ffffffffbfc10214(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int iVar4;
  undefined8 unaff_s2;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[3] = &_gp;
  uVar1 = param_1[2];
  *puVar6 = unaff_s0;
  puVar6[4] = in_ra;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  if (uVar1 == 0x1000000) {
    iVar2 = (int)param_1 + 0xc;
    iVar4 = 0;
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5678,(uint)*(byte *)(param_1 + 0x283) << 3,
               (uint)*(byte *)((long)param_1 + 0xa0d) << 3);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5640,*param_1 >> 0x14,*(undefined2 *)(param_1 + 1));
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5620,param_1[0x284],param_1[0x285],param_1[0x286],
               *(undefined2 *)((long)param_1 + 0xa0e));
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x55c0);
    while( true ) {
      puVar5 = (undefined4 *)(long)iVar2;
      if ((int)(uint)*(ushort *)(param_1 + 1) <= iVar4) break;
      if (iVar4 == (iVar4 / 5) * 5) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x55a0);
      }
      iVar3 = DAT_ffffffffbfc436f4 + -0x5598;
      if (*(char *)((long)((int)param_1 + iVar4) + 0x80c) == '\0') {
        iVar3 = DAT_ffffffffbfc436f4 + -0x5590;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 4;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5588,*puVar5,iVar3);
    }
    iVar2 = 10;
    iVar4 = DAT_ffffffffbfc439f0;
  }
  else {
    iVar2 = DAT_ffffffffbfc436f4 + -0x5698;
    iVar4 = DAT_ffffffffbfc43e38;
  }
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc10374. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)iVar4)(iVar2);
  return;
}

