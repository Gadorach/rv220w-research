/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc19e00
 * Function: FUN_ffffffffbfc19e00
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

void FUN_ffffffffbfc19e00(undefined8 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 unaff_s0;
  int iVar3;
  int iVar4;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar5;
  code *pcVar6;
  byte *pbVar7;
  undefined8 in_ra;
  
  iVar4 = (int)&stack0x00000000;
  pbVar7 = (byte *)(long)(iVar4 + -0x40);
  *(undefined1 **)(pbVar7 + 0x28) = &_gp;
  *(undefined8 *)(pbVar7 + 0x30) = in_ra;
  pcVar6 = (code *)(long)DAT_ffffffffbfc437d4;
  *(undefined8 *)(pbVar7 + 0x18) = unaff_s1;
  *(undefined8 *)(pbVar7 + 0x10) = unaff_s0;
  iVar3 = iVar4 + -0x3e;
  *(undefined8 *)(pbVar7 + 0x20) = unaff_s2;
  (*pcVar6)(param_1,0xe,iVar4 + -0x3f);
  (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0,iVar3);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1c70,*(undefined2 *)(pbVar7 + 2));
  (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,2,iVar3);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1c48,*(undefined2 *)(pbVar7 + 2));
  (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,4,iVar3);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1c20,*(undefined2 *)(pbVar7 + 2));
  (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,6,iVar3);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1bf8,*(undefined2 *)(pbVar7 + 2));
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,8,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1bd0,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0xb,pbVar7);
  bVar1 = *pbVar7;
  if (bVar1 == 8) {
    iVar3 = DAT_ffffffffbfc436f4 + -0x1ad8;
    goto LAB_ffffffffbfc1a0a4;
  }
  if (bVar1 < 9) {
    if (bVar1 == 3) {
      iVar3 = DAT_ffffffffbfc436f4 + -0x1b48;
      goto LAB_ffffffffbfc1a0a4;
    }
    if (bVar1 < 4) {
      if (bVar1 == 1) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1b78;
      }
      else if (bVar1 < 2) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1b90;
      }
      else {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1b60;
      }
      goto LAB_ffffffffbfc1a0a4;
    }
    if (bVar1 == 5) {
      iVar3 = DAT_ffffffffbfc436f4 + -0x1b18;
      goto LAB_ffffffffbfc1a0a4;
    }
    if (bVar1 < 5) {
      iVar3 = DAT_ffffffffbfc436f4 + -0x1b30;
      goto LAB_ffffffffbfc1a0a4;
    }
    if (bVar1 == 6) {
      iVar3 = DAT_ffffffffbfc436f4 + -0x1b00;
      goto LAB_ffffffffbfc1a0a4;
    }
    if (bVar1 == 7) {
      iVar3 = DAT_ffffffffbfc436f4 + -0x1af0;
      goto LAB_ffffffffbfc1a0a4;
    }
  }
  else {
    if (bVar1 == 0xe) {
      iVar3 = DAT_ffffffffbfc436f4 + -0x1a78;
      goto LAB_ffffffffbfc1a0a4;
    }
    if (bVar1 < 0xf) {
      if (bVar1 == 10) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1ab0;
        goto LAB_ffffffffbfc1a0a4;
      }
      if (bVar1 < 10) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1ac0;
        goto LAB_ffffffffbfc1a0a4;
      }
      if (bVar1 == 0xb) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1aa0;
        goto LAB_ffffffffbfc1a0a4;
      }
      if (bVar1 == 0xc) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1a90;
        goto LAB_ffffffffbfc1a0a4;
      }
    }
    else {
      if (bVar1 == 0x10) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1a48;
        goto LAB_ffffffffbfc1a0a4;
      }
      if (bVar1 < 0x10) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1a60;
        goto LAB_ffffffffbfc1a0a4;
      }
      if (bVar1 == 0x11) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1a30;
        goto LAB_ffffffffbfc1a0a4;
      }
      if (bVar1 == 0xff) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x1ba8;
        goto LAB_ffffffffbfc1a0a4;
      }
    }
  }
  iVar3 = DAT_ffffffffbfc436f4 + -0x2d00;
LAB_ffffffffbfc1a0a4:
  iVar5 = iVar4 + -0x3c;
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1a28,bVar1,iVar3);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,10,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x19f8,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,9,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x19d0,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0xc,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x19a8,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0xd,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1980,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0xe,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1958,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0xf,pbVar7);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1930,*pbVar7);
  (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x10,iVar5);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1908,*(undefined4 *)(pbVar7 + 4));
  bVar1 = pbVar7[1] & 3;
  if (bVar1 == 1) {
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x14,iVar5);
    iVar4 = iVar4 + -0x3e;
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x18e0,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x18,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x16d8,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x19,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x16b0,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x1a,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1688,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x1b,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1660,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x1c,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1638,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x1d,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1610,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x1e,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x15e8,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x20,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x15c0,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x22,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1598,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x24,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1570,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x26,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1548,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x28,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1520,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x2c,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x14f8,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x30,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x14d0,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x32,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x14a8,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x38,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x17a0,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3c,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1778,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3d,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1750,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x3e,iVar4);
    pcVar6 = (code *)(long)DAT_ffffffffbfc4400c;
    uVar2 = (uint)*(ushort *)(pbVar7 + 2);
    iVar3 = DAT_ffffffffbfc436f4 + -0x1480;
  }
  else if (bVar1 == 2) {
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x14,pbVar7);
    iVar4 = iVar4 + -0x3e;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1458,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x16,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x15e8,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x18,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x16d8,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x19,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1430,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x1a,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1688,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x1b,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1408,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x1c,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x13e0,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x20,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x13b8,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x24,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1390,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x28,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1368,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x2c,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1340,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x2e,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1318,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x30,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x12f0,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x32,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x12c8,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x34,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x12a0,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x36,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1278,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x38,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1250,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x3a,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1228,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3c,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1778,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3d,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1750,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x3e,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1480,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x40,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1200,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x42,iVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x11d8,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x44,iVar5);
    pcVar6 = (code *)(long)DAT_ffffffffbfc4400c;
    uVar2 = *(uint *)(pbVar7 + 4);
    iVar3 = DAT_ffffffffbfc436f4 + -0x11b0;
  }
  else {
    if ((pbVar7[1] & 3) != 0) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1188);
      return;
    }
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x14,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x18e0,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x18,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x18b8,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x1c,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1890,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x20,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1868,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x24,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1840,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x28,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x1818,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x2c,iVar4 + -0x3e);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x17f0,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,0x2e,iVar4 + -0x3e);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x17c8,*(undefined2 *)(pbVar7 + 2));
    (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,0x30,iVar5);
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x17a0,*(undefined4 *)(pbVar7 + 4));
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3c,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1778,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3d,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1750,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3e,pbVar7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1728,*pbVar7);
    (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0x3f,pbVar7);
    pcVar6 = (code *)(long)DAT_ffffffffbfc4400c;
    uVar2 = (uint)*pbVar7;
    iVar3 = DAT_ffffffffbfc436f4 + -0x1700;
  }
  (*pcVar6)(iVar3,uVar2);
  return;
}

