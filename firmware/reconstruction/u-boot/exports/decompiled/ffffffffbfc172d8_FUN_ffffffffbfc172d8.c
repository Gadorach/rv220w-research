/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc172d8
 * Function: FUN_ffffffffbfc172d8
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

undefined8 FUN_ffffffffbfc172d8(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  undefined8 in_zero;
  long lVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined8 unaff_s0;
  uint *puVar7;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int *piVar8;
  undefined8 in_ra;
  
  piVar8 = (int *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(piVar8 + 0xc) = &_gp;
  *(undefined8 *)(piVar8 + 10) = unaff_s3;
  *(undefined8 *)(piVar8 + 8) = unaff_s2;
  *(undefined8 *)(piVar8 + 0xe) = in_ra;
  *(undefined8 *)(piVar8 + 6) = unaff_s1;
  *(undefined8 *)(piVar8 + 4) = unaff_s0;
  if (param_4 == 2) {
    puVar7 = (uint *)(long)*(int *)(long)DAT_ffffffffbfc43c24;
    setCopReg(2,in_zero,*(undefined4 *)(param_3 + 3));
    iVar1 = *(int *)(long)DAT_ffffffffbfc43c78;
    while( true ) {
      while( true ) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3ca0,puVar7);
        if (iVar1 == 4) {
          uVar4 = *puVar7;
          iVar6 = DAT_ffffffffbfc436f4 + -0x3c98;
        }
        else if (iVar1 == 2) {
          uVar4 = (uint)*(ushort *)puVar7;
          iVar6 = DAT_ffffffffbfc436f4 + -0x3c90;
        }
        else {
          uVar4 = (uint)*(byte *)puVar7;
          iVar6 = DAT_ffffffffbfc436f4 + -0x3c88;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6,uVar4);
        lVar2 = (*(code *)(long)DAT_ffffffffbfc43e4c)(DAT_ffffffffbfc436f4 + -0x3c80);
        iVar6 = (int)puVar7;
        if ((lVar2 != 0) && ((lVar2 != 1 || (*(char *)(long)DAT_ffffffffbfc44084 != '-')))) break;
        if (param_2 != 0) {
          iVar3 = -iVar1;
          if (lVar2 == 0) {
            iVar3 = iVar1;
          }
          puVar7 = (uint *)(long)(iVar6 + iVar3);
        }
      }
      uVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(DAT_ffffffffbfc44084,piVar8,0x10);
      if (*piVar8 == DAT_ffffffffbfc44084) break;
      if (iVar1 == 4) {
        *puVar7 = uVar4;
      }
      else if (iVar1 == 2) {
        *(ushort *)puVar7 = (ushort)uVar4;
      }
      else {
        *(byte *)puVar7 = (byte)uVar4;
      }
      if (param_2 != 0) {
        puVar7 = (uint *)(long)(iVar6 + iVar1);
      }
    }
    uVar5 = 0;
    *(int *)(long)DAT_ffffffffbfc43c24 = iVar6;
    *(int *)(long)DAT_ffffffffbfc43c78 = iVar1;
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    uVar5 = 1;
  }
  return uVar5;
}

