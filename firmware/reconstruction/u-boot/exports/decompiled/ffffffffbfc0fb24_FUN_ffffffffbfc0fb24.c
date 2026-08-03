/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0fb24
 * Function: FUN_ffffffffbfc0fb24
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

undefined8 FUN_ffffffffbfc0fb24(long param_1,ulong *param_2,ulong param_3)

{
  byte bVar1;
  ushort uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 uVar9;
  undefined8 unaff_s5;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[6] = &_gp;
  puVar11[3] = unaff_s3;
  lVar4 = (long)DAT_ffffffffbfc436f4;
  puVar11[2] = unaff_s2;
  iVar5 = *(int *)(lVar4 + 0x4a80);
  puVar11[1] = unaff_s1;
  puVar11[7] = in_ra;
  puVar11[5] = unaff_s5;
  puVar11[4] = unaff_s4;
  *puVar11 = unaff_s0;
  if (iVar5 == 0) {
LAB_ffffffffbfc0fbf4:
    uVar9 = 0;
  }
  else if (param_2 < (ulong *)0xffffffffbeb00000) {
    if (param_2 < (ulong *)0xffffffffbe800000) {
      if (param_2 < (ulong *)0xffffffffbe500000) {
        if (param_2 < (ulong *)0xffffffffbe400000) {
          if (param_2 < (ulong *)0xffffffffbe300000) {
            if (param_2 < (ulong *)0xffffffffbe000000) {
              uVar9 = 0x17;
              if (param_2 < (ulong *)0xffffffffbdd00000) goto LAB_ffffffffbfc0fbf4;
            }
            else {
              uVar9 = 0x47;
            }
          }
          else {
            uVar9 = 0x77;
          }
        }
        else {
          uVar9 = 0x8e;
        }
      }
      else {
        uVar9 = 0xa5;
      }
    }
    else {
      uVar9 = 0xd5;
    }
  }
  else {
    uVar9 = 0x105;
  }
  bVar1 = *(byte *)(param_1 + 0xa0c);
  if (bVar1 == 2) {
    pcVar10 = (code *)(long)DAT_ffffffffbfc43930;
    if ((param_3 >> 0x30 & (ulong)*(ushort *)param_2) != param_3 >> 0x30) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x56f0,*(ushort *)param_2);
      return 2;
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 != 1) {
      return 2;
    }
    uVar3 = param_3 >> 0x38;
    pcVar10 = (code *)(long)DAT_ffffffffbfc43930;
    if ((*(byte *)param_2 & uVar3) != uVar3) {
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x5770,param_2,(ulong)*(byte *)param_2,uVar3);
      pcVar10 = (code *)(long)DAT_ffffffffbfc43930;
      if ((*(byte *)param_2 & uVar3) != uVar3) {
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x5730,param_2,(ulong)*(byte *)param_2,uVar3);
        return 2;
      }
    }
  }
  else {
    if (bVar1 == 4) {
      lVar4 = special2((long)(int)*(uint *)param_2 & (long)param_3 >> 0x20,(long)param_3 >> 0x20,0,
                       0x2a);
    }
    else {
      if (bVar1 != 8) {
        return 2;
      }
      lVar4 = special2(*(uint *)param_2 & param_3,param_3,0,0x2a);
    }
    pcVar10 = (code *)(long)DAT_ffffffffbfc43930;
    if (lVar4 == 0) {
      return 2;
    }
  }
  lVar4 = (*pcVar10)();
  uVar2 = *(ushort *)(param_1 + 0xa1c);
  if (uVar2 == 2) {
    iVar5 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a80);
LAB_ffffffffbfc0fd9c:
    if (iVar5 == 0) {
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0xc50))(param_1,0);
      if (*(char *)(param_1 + 0xa0d) != '\x01') {
        uVar6 = 0;
        goto LAB_ffffffffbfc0fe24;
      }
      uVar6 = 0;
LAB_ffffffffbfc0fe10:
      uVar7 = 0xaaa;
    }
    else {
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0xc50))(param_1,uVar9);
      uVar6 = uVar9;
      if (*(char *)(param_1 + 0xa0d) == '\x01') goto LAB_ffffffffbfc0fe10;
LAB_ffffffffbfc0fe24:
      uVar7 = 0x555;
    }
    pcVar10 = (code *)(long)(DAT_ffffffffbfc436fc + -0xd40);
    uVar8 = 0xa0;
  }
  else {
    if (uVar2 < 3) {
      if (uVar2 != 1) goto LAB_ffffffffbfc0fe34;
    }
    else if (uVar2 != 3) {
      if (uVar2 != 4) goto LAB_ffffffffbfc0fe34;
      iVar5 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a80);
      goto LAB_ffffffffbfc0fd9c;
    }
    pcVar10 = (code *)(long)(DAT_ffffffffbfc436fc + -0xd40);
    (*pcVar10)(param_1,0,0,0x50);
    uVar6 = 0;
    uVar7 = 0;
    uVar8 = 0x40;
  }
  (*pcVar10)(param_1,uVar6,uVar7,uVar8);
LAB_ffffffffbfc0fe34:
  bVar1 = *(byte *)(param_1 + 0xa0c);
  if (bVar1 == 2) {
    *(ushort *)param_2 = (ushort)(param_3 >> 0x30);
  }
  else if (bVar1 < 3) {
    if ((bVar1 == 1) &&
       (*(byte *)param_2 = (byte)(param_3 >> 0x38), *(short *)(param_1 + 0xa1c) != 1)) {
      do {
      } while ((ulong)*(byte *)param_2 != param_3 >> 0x38);
    }
  }
  else if (bVar1 == 4) {
    *(uint *)param_2 = (uint)(param_3 >> 0x20);
  }
  else if (bVar1 == 8) {
    *param_2 = param_3;
  }
  if (lVar4 != 0) {
    (*(code *)(long)DAT_ffffffffbfc43790)();
  }
  if (*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a80) == 0) {
    uVar9 = 0;
  }
  uVar9 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x8b8))
                    (param_1,uVar9,*(undefined4 *)(param_1 + 0xa14),DAT_ffffffffbfc436f4 + -0x56c0);
  return uVar9;
}

