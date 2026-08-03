/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc34d34
 * Function: FUN_ffffffffbfc34d34
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

ulong FUN_ffffffffbfc34d34(ulong param_1)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  undefined8 in_t3;
  undefined8 unaff_s0;
  code *pcVar11;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar12;
  undefined8 *puVar13;
  undefined8 in_ra;
  
  puVar13 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar13[4] = &_gp;
  puVar13[2] = unaff_s2;
  piVar3 = (int *)(long)DAT_ffffffffbfc43cb0;
  puVar13[5] = in_ra;
  iVar10 = *piVar3;
  puVar13[3] = unaff_s3;
  puVar13[1] = unaff_s1;
  *puVar13 = unaff_s0;
  if ((code *)(long)iVar10 != (code *)0x0) {
    uVar4 = (*(code *)(long)iVar10)();
    return uVar4;
  }
  uVar4 = 0;
  lVar5 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  uVar1 = *(ushort *)(lVar5 + 0x40);
  if (uVar1 == 0xe) {
LAB_ffffffffbfc34e2c:
    if (param_1 == 1) {
      return 0xc03e8;
    }
LAB_ffffffffbfc34f00:
    bVar2 = false;
  }
  else {
    if (uVar1 < 0xf) {
      if (uVar1 == 9) goto LAB_ffffffffbfc34e2c;
      if (uVar1 < 10) {
        if (uVar1 == 1) {
          return 0xc03e8;
        }
      }
      else if (uVar1 - 0xb < 2) goto LAB_ffffffffbfc34e2c;
      goto LAB_ffffffffbfc34f00;
    }
    if (uVar1 == 0x2715) {
      return 0xc0064;
    }
    if (0x2715 < uVar1) {
      if (uVar1 == 0x2716) {
        if (param_1 < 2) {
          return 0xc03e8;
        }
      }
      else if (uVar1 == 0x2717) {
        if (param_1 < 2) {
          return 0xc03e8;
        }
        if (param_1 == 2) {
          uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4730))(0,7,0x11);
          uVar6 = uVar4 & 0xffff;
          if ((long)uVar4 < 0) {
            uVar9 = 0;
            uVar4 = 0;
          }
          else {
            uVar9 = (uint)uVar6 >> 0xe;
            uVar4 = (uVar6 >> 10 & 1) << 0x13 | (uVar6 >> 0xd & 1) << 0x12;
            if (uVar9 == 2) {
              uVar6 = 1000;
              goto LAB_ffffffffbfc34ed4;
            }
          }
          uVar6 = 100;
          if (uVar9 != 1) {
            if (uVar9 != 0) {
              return uVar4;
            }
            uVar6 = 10;
          }
LAB_ffffffffbfc34ed4:
          return uVar4 | uVar6;
        }
      }
      goto LAB_ffffffffbfc34f00;
    }
    if (uVar1 == 0x14) {
      if (param_1 != 2) {
        return 0xc03e8;
      }
      return 0;
    }
    if (uVar1 != 0x2713) goto LAB_ffffffffbfc34f00;
    bVar2 = true;
    if (param_1 == 1) {
      return 0xc03e8;
    }
  }
  uVar6 = (*(code *)(long)DAT_ffffffffbfc438b4)(param_1);
  if (uVar6 == 0xffffffffffffffff) {
    pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x4510);
    lVar5 = (*pcVar11)(0x70d0300);
    pcVar12 = (code *)(long)DAT_ffffffffbfc43fb0;
    if (lVar5 == 0) {
      lVar5 = (*pcVar11)(0x30d0300);
      pcVar12 = (code *)(long)DAT_ffffffffbfc43fb0;
      if (lVar5 == 0) {
        lVar5 = (*pcVar11)(0x30d0600);
        pcVar12 = (code *)(long)DAT_ffffffffbfc43fb0;
        if (lVar5 == 0) {
          uVar4 = 0;
          goto LAB_ffffffffbfc350c8;
        }
      }
    }
    lVar5 = (*pcVar12)(param_1);
    special2(lVar5,lVar5,0x1b,0x32);
    lVar7 = (*(code *)(long)DAT_ffffffffbfc43dd0)(param_1);
    special2(lVar7,lVar7,0xb,0x32);
    uVar4 = *(ulong *)(lVar5 + lVar7 + -0x7ffee7fff7ffffa0);
    uVar6 = uVar4 >> 1;
    uVar4 = (uVar4 & 1) << 0x13 | (uVar4 >> 3 & 1) << 0x12;
  }
  else {
    iVar10 = (int)uVar6 >> 8;
    if (bVar2) {
      uVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4730))(iVar10,uVar6 & 0xff,0x19);
      uVar6 = uVar6 >> 8 & 7;
      if (uVar6 < 8) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc34f5c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (*(code *)(long)(*(int *)(long)((int)uVar6 * 4 + DAT_ffffffffbfc436f0 + 0x6d00) +
                                -0x403bc920))();
        return uVar4;
      }
      goto LAB_ffffffffbfc350c8;
    }
    uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4730))(iVar10,uVar6 & 0xff,0x11);
    setCopReg(2,in_t3,*(undefined4 *)(uVar4 + 0x44));
    uVar6 = uVar4 >> 0xe;
    uVar4 = (uVar4 >> 0xd & 1) << 0x12 | 0x80000;
  }
  uVar6 = uVar6 & 3;
  uVar8 = 100;
  if (uVar6 != 1) {
    if (uVar6 < 2) {
      if (uVar6 != 0) goto LAB_ffffffffbfc350c8;
      uVar8 = 10;
    }
    else {
      uVar8 = 1000;
      if (uVar6 != 2) {
        if (uVar6 == 3) {
          uVar4 = 0;
        }
        goto LAB_ffffffffbfc350c8;
      }
    }
  }
  uVar4 = uVar4 | uVar8;
LAB_ffffffffbfc350c8:
  if ((uVar4 & 0x80000) == 0) {
    uVar4 = 0;
  }
  return uVar4;
}

