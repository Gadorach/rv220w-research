/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc27ed4
 * Function: FUN_ffffffffbfc27ed4
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

undefined8 FUN_ffffffffbfc27ed4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar7;
  long in_k0;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  iVar1 = *(int *)(in_k0 + 0x24);
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  *puVar8 = unaff_s0;
  lVar6 = (long)(param_1 << 10);
  puVar8[5] = &_gp;
  uVar2 = *(undefined4 *)(in_k0 + 8);
  puVar8[6] = in_ra;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43ec0;
  puVar8[4] = unaff_s4;
  puVar8[3] = unaff_s3;
  puVar8[2] = unaff_s2;
  puVar8[1] = unaff_s1;
  uVar3 = (*pcVar7)(iVar1 * 1000000,uVar2);
  pcVar7 = (code *)(long)(DAT_ffffffffbfc43700 + 0x7b40);
  (*pcVar7)(lVar6 + -0x7ffee7fffffff7b0,7);
  (*pcVar7)(lVar6 + -0x7ffee7fffffff7e8,0x93);
  (*pcVar7)(lVar6 + -0x7ffee7fffffff780,uVar3 & 0xff);
  (*pcVar7)(lVar6 + -0x7ffee7fffffff778,uVar3 >> 8 & 0xff);
  (*pcVar7)(lVar6 + -0x7ffee7fffffff7e8,0x13);
  lVar4 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  do {
    uVar5 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  } while (uVar5 < (ulong)(lVar4 + (long)((int)uVar3 << 5) + 10000));
  (*(code *)(long)(DAT_ffffffffbfc43700 + 0x7b40))(lVar6 + -0x7ffee7fffffff7e0,2);
  return 0;
}

