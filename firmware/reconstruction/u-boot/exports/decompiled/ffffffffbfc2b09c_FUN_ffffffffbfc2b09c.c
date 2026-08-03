/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2b09c
 * Function: FUN_ffffffffbfc2b09c
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

ushort FUN_ffffffffbfc2b09c
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  ushort uVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[4] = &_gp;
  puVar6[3] = unaff_s3;
  iVar1 = DAT_ffffffffbfc436f0;
  uVar4 = 0;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  *puVar6 = unaff_s0;
  puVar6[5] = in_ra;
  lVar2 = (*(code *)(long)(iVar1 + -0x5500))(1);
  *(int *)(long)DAT_ffffffffbfc43724 = (int)lVar2;
  if (lVar2 == 0) {
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x544c))(param_1);
  }
  else {
    uVar4 = 0;
    if (*(int *)(long)DAT_ffffffffbfc43ff8 == 0) {
      setCopReg(2,param_5,*(undefined4 *)(*(ulong *)(lVar2 + 0x10) + 6));
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + 0x1a60,*(ulong *)(lVar2 + 0x10) >> 8 & 1);
    }
    else {
      uVar3 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x581c))
                        (*(ulong *)(lVar2 + 0x18) & 0xffffffffff);
      uVar4 = *(ushort *)(lVar2 + 8);
      pcVar5 = (code *)(long)DAT_ffffffffbfc43e84;
      *(uint *)(long)DAT_ffffffffbfc437b8 = (uint)uVar4;
      (*pcVar5)(param_2,uVar3,uVar4);
    }
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x569c))(lVar2);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x5704))(lVar2,1,0);
  }
  return uVar4;
}

