/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc120c4
 * Function: FUN_ffffffffbfc120c4
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

uint FUN_ffffffffbfc120c4(long param_1,undefined8 param_2)

{
  short sVar1;
  uint uVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  long lVar3;
  undefined8 unaff_s4;
  long lVar4;
  undefined8 unaff_s5;
  uint uVar5;
  undefined8 unaff_s6;
  uint uVar6;
  code *pcVar7;
  byte *pbVar8;
  undefined8 in_ra;
  int iVar9;
  
  iVar9 = (int)&stack0x00000000;
  pbVar8 = (byte *)(long)(iVar9 + -0x60);
  *(undefined1 **)(pbVar8 + 0x48) = &_gp;
  *(undefined8 *)(pbVar8 + 0x40) = unaff_s6;
  pcVar7 = (code *)(long)DAT_ffffffffbfc437dc;
  *(undefined8 *)(pbVar8 + 0x38) = unaff_s5;
  uVar5 = (int)param_2 >> 0x10;
  *(undefined8 *)(pbVar8 + 0x20) = unaff_s2;
  *(undefined8 *)(pbVar8 + 0x18) = unaff_s1;
  *(undefined8 *)(pbVar8 + 0x50) = in_ra;
  uVar6 = uVar5 & 0xff;
  *(undefined8 *)(pbVar8 + 0x30) = unaff_s4;
  *(undefined8 *)(pbVar8 + 0x28) = unaff_s3;
  *(undefined8 *)(pbVar8 + 0x10) = unaff_s0;
  (*pcVar7)(param_1,param_2,10,iVar9 + -0x5e);
  sVar1 = *(short *)(pbVar8 + 2);
  if (sVar1 == 0x604) {
    pcVar7 = (code *)(long)DAT_ffffffffbfc43884;
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
    (*pcVar7)(param_1,param_2,2,*(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_1 + 0x138));
    uVar2 = *(uint *)(param_1 + 0x140);
    lVar3 = (long)*(int *)(param_1 + 0x134);
    lVar4 = (long)*(int *)(param_1 + 0x138);
    (*(code *)(long)DAT_ffffffffbfc43fa0)(param_1,param_2,4,iVar9 + -0x5c);
    (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0x18,uVar5 & 0xff);
    (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0x19,uVar2 & 0xff);
    (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0x1a,0xff);
    if (lVar3 != 0) {
      (*(code *)(long)DAT_ffffffffbfc4387c)(lVar3,0x100000);
      (*(code *)(long)DAT_ffffffffbfc43dd8)(param_1,param_2,0x20,*(ushort *)(lVar3 + 0x20) & 0xfff0)
      ;
      *(uint *)(pbVar8 + 4) = *(uint *)(pbVar8 + 4) | 2;
    }
    if (lVar4 != 0) {
      (*(code *)(long)DAT_ffffffffbfc4387c)(lVar4,0x1000);
      (*(code *)(long)DAT_ffffffffbfc437a4)
                (param_1,param_2,0x1c,(*(uint *)(lVar4 + 0x20) & 0xf000) >> 8);
      (*(code *)(long)DAT_ffffffffbfc43dd8)(param_1,param_2,0x30,*(undefined2 *)(lVar4 + 0x20));
      *(uint *)(pbVar8 + 4) = *(uint *)(pbVar8 + 4) | 1;
    }
    (*(code *)(long)DAT_ffffffffbfc43dd8)(param_1,param_2,0x24,0x1000);
    (*(code *)(long)DAT_ffffffffbfc43dd8)(param_1,param_2,0x26,0x1000);
    (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,4,*(uint *)(pbVar8 + 4) | 4);
    uVar5 = (*(code *)(long)DAT_ffffffffbfc43fbc)(param_1,*(undefined4 *)(param_1 + 0x140));
    if ((int)uVar5 <= (int)uVar6) {
      uVar5 = uVar6;
    }
    lVar3 = (long)*(int *)(param_1 + 0x134);
    lVar4 = (long)*(int *)(param_1 + 0x138);
    (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0x1a,uVar5 & 0xff);
    if (lVar3 != 0) {
      (*(code *)(long)DAT_ffffffffbfc4387c)(lVar3,0x100000);
      (*(code *)(long)DAT_ffffffffbfc43dd8)
                (param_1,param_2,0x22,*(int *)(lVar3 + 0x20) - 1U >> 0x10);
    }
    if (lVar4 != 0) {
      (*(code *)(long)DAT_ffffffffbfc4387c)(lVar4,0x1000);
      (*(code *)(long)DAT_ffffffffbfc437a4)
                (param_1,param_2,0x1d,(*(int *)(lVar4 + 0x20) - 1U & 0xf000) >> 8);
      (*(code *)(long)DAT_ffffffffbfc43dd8)
                (param_1,param_2,0x32,*(int *)(lVar4 + 0x20) - 1U >> 0x10);
    }
    uVar6 = *(uint *)(param_1 + 0x140);
  }
  else if (sVar1 == 0x607) {
    (*(code *)(long)DAT_ffffffffbfc43884)
              (param_1,param_2,0,*(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_1 + 0x138));
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
  }
  else if ((sVar1 != 0x101) ||
          ((*(code *)(long)DAT_ffffffffbfc43744)(param_1,param_2,9,pbVar8), (*pbVar8 & 5) != 0)) {
    (*(code *)(long)DAT_ffffffffbfc43884)
              (param_1,param_2,6,*(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_1 + 0x138));
  }
  return uVar6;
}

