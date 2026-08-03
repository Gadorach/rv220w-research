/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0ce74
 * Function: FUN_ffffffffbfc0ce74
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

uint FUN_ffffffffbfc0ce74(ulong param_1)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  int iVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  undefined8 uVar4;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  undefined8 unaff_s0;
  long lVar12;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar13;
  int *in_k0;
  long lVar14;
  undefined8 in_ra;
  
  lVar14 = (long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(lVar14 + 0x30) = &_gp;
  *(undefined8 *)(lVar14 + 0x20) = unaff_s2;
  iVar1 = DAT_ffffffffbfc43e44;
  iVar5 = DAT_ffffffffbfc437c4;
  iVar10 = *in_k0;
  puVar11 = (uint *)(long)DAT_ffffffffbfc43e44;
  *(undefined8 *)(lVar14 + 0x28) = unaff_s3;
  uVar9 = iVar5 + 0x1fU & 0xffffffe0;
  lVar2 = (long)DAT_ffffffffbfc436f4;
  *(undefined8 *)(lVar14 + 0x18) = unaff_s1;
  *(undefined4 *)(lVar2 + 0x4a10) = 0;
  lVar2 = (long)DAT_ffffffffbfc436f4;
  *(undefined8 *)(lVar14 + 0x38) = in_ra;
  *(undefined4 *)(lVar2 + 0x4a14) = 0;
  puVar3 = (undefined4 *)(long)DAT_ffffffffbfc44010;
  *(undefined8 *)(lVar14 + 0x10) = unaff_s0;
  *puVar3 = 0;
  *(undefined4 *)(long)DAT_ffffffffbfc43dcc = 0;
  *(undefined4 *)(long)DAT_ffffffffbfc43e5c = 0;
  *(uint *)(long)DAT_ffffffffbfc43904 = uVar9;
  do {
    uVar9 = uVar9 + 0x600;
    *puVar11 = uVar9;
    puVar11 = (uint *)(long)((int)puVar11 + 4);
  } while (puVar11 != (uint *)(long)(iVar1 + 0x10));
  pcVar13 = (code *)(long)DAT_ffffffffbfc43eec;
  *(uint *)(long)DAT_ffffffffbfc43e40 = DAT_ffffffffbfc439c0 + 0x1fU & 0xffffffe0;
  *(undefined4 *)(long)DAT_ffffffffbfc43e74 = 0;
  (*pcVar13)();
  (*(code *)(long)DAT_ffffffffbfc43a7c)();
  lVar2 = (*(code *)(long)DAT_ffffffffbfc43874)(iVar10);
  if (lVar2 < 0) {
    return 0xffffffff;
  }
  do {
    iVar5 = (*(code *)(long)DAT_ffffffffbfc43cac)();
    (*(code *)(long)DAT_ffffffffbfc43e84)(DAT_ffffffffbfc43fa8,iVar5 + 0x10,6);
    *(undefined4 *)(long)DAT_ffffffffbfc43d80 = 1;
    iVar5 = DAT_ffffffffbfc436f4;
    if (param_1 == 3) {
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0x3e90))(DAT_ffffffffbfc43f80,iVar10 + 4);
      uVar6 = (*(code *)(long)DAT_ffffffffbfc44060)(DAT_ffffffffbfc436f4 + -24000);
      iVar5 = DAT_ffffffffbfc436f4;
      pcVar13 = (code *)(long)DAT_ffffffffbfc44060;
      *(undefined4 *)(long)DAT_ffffffffbfc43a90 = uVar6;
      uVar6 = (*pcVar13)(iVar5 + -0x5db0);
      iVar5 = DAT_ffffffffbfc436f4;
      pcVar13 = (code *)(long)DAT_ffffffffbfc43aac;
      *(undefined4 *)(long)DAT_ffffffffbfc43c58 = uVar6;
      uVar7 = (*pcVar13)(iVar5 + -0x5da8);
      iVar5 = DAT_ffffffffbfc436f4;
      pcVar13 = (code *)(long)DAT_ffffffffbfc43aac;
      *(undefined2 *)(long)DAT_ffffffffbfc43830 = uVar7;
      uVar7 = (*pcVar13)(iVar5 + -0x5da0);
      iVar5 = DAT_ffffffffbfc436f4;
      pcVar13 = (code *)(long)DAT_ffffffffbfc44060;
      *(undefined2 *)(long)DAT_ffffffffbfc43dc4 = uVar7;
      uVar6 = (*pcVar13)(iVar5 + -0x5d98);
      *(undefined4 *)(long)DAT_ffffffffbfc43f00 = uVar6;
LAB_ffffffffbfc0d0e0:
      if (*(int *)(long)DAT_ffffffffbfc43f00 == 0) {
        pcVar13 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar10 = DAT_ffffffffbfc436f4 + -0x5d88;
        goto LAB_ffffffffbfc0d3e0;
      }
      if (*(int *)(long)DAT_ffffffffbfc43f80 == 0) {
        pcVar13 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar10 = DAT_ffffffffbfc436f4 + -0x5d68;
        goto LAB_ffffffffbfc0d3e0;
      }
LAB_ffffffffbfc0d0fc:
      lVar2 = (*(code *)(long)DAT_ffffffffbfc43ab4)
                        (DAT_ffffffffbfc43fa8,DAT_ffffffffbfc436f0 + 0x6370,6);
      if (lVar2 != 0) goto LAB_ffffffffbfc0d188;
      lVar2 = (*(code *)(long)DAT_ffffffffbfc43900)();
      if (lVar2 == -1) {
        pcVar13 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar10 = DAT_ffffffffbfc436f4 + -0x5d48;
LAB_ffffffffbfc0d3e0:
        (*pcVar13)(iVar10);
        return 0xffffffff;
      }
      if (lVar2 == 0) {
        (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5d28);
      }
      else {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5d08);
      }
      (*(code *)(long)DAT_ffffffffbfc438f4)();
      pcVar13 = (code *)(long)DAT_ffffffffbfc43980;
    }
    else {
      if (param_1 < 4) {
        if (param_1 < 2) {
          pcVar13 = (code *)(long)DAT_ffffffffbfc44060;
          *(undefined4 *)(long)DAT_ffffffffbfc43f80 = 0;
          uVar6 = (*pcVar13)(iVar5 + -0x5d98);
          iVar5 = DAT_ffffffffbfc436f4;
          pcVar13 = (code *)(long)DAT_ffffffffbfc43aac;
          *(undefined4 *)(long)DAT_ffffffffbfc43f00 = uVar6;
          uVar7 = (*pcVar13)(iVar5 + -0x5da8);
          iVar5 = DAT_ffffffffbfc436f4;
          pcVar13 = (code *)(long)DAT_ffffffffbfc43aac;
          *(undefined2 *)(long)DAT_ffffffffbfc43830 = uVar7;
          uVar7 = (*pcVar13)(iVar5 + -0x5da0);
          *(undefined2 *)(long)DAT_ffffffffbfc43dc4 = uVar7;
LAB_ffffffffbfc0d08c:
          uVar7 = (*(code *)(long)DAT_ffffffffbfc43aac)(DAT_ffffffffbfc436f4 + -0x5da8);
          iVar5 = DAT_ffffffffbfc436f4;
          pcVar13 = (code *)(long)DAT_ffffffffbfc43aac;
          *(undefined2 *)(long)DAT_ffffffffbfc43830 = uVar7;
          uVar7 = (*pcVar13)(iVar5 + -0x5da0);
          *(undefined2 *)(long)DAT_ffffffffbfc43dc4 = uVar7;
        }
      }
      else if (param_1 == 8) goto LAB_ffffffffbfc0d08c;
      if (param_1 < 9) {
        uVar8 = 1L << param_1;
        if ((uVar8 & 0x113) == 0) {
          setCopReg(2,uVar8,*(undefined4 *)(uVar8 + 0x2b));
          goto LAB_ffffffffbfc0d0e0;
        }
        goto LAB_ffffffffbfc0d0fc;
      }
LAB_ffffffffbfc0d188:
      *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a14) = 1;
      iVar1 = DAT_ffffffffbfc43c88;
      iVar5 = DAT_ffffffffbfc43e98;
      if ((param_1 == 1) ||
         (iVar1 = DAT_ffffffffbfc43d74, iVar5 = DAT_ffffffffbfc437b0, param_1 == 0)) {
        *(undefined4 *)(long)iVar1 = 0;
        (*(code *)(long)iVar5)();
      }
      else if (param_1 == 3) {
        (*(code *)(long)DAT_ffffffffbfc43758)();
        uVar4 = (*(code *)(long)DAT_ffffffffbfc43b98)();
        *(undefined8 *)(long)DAT_ffffffffbfc43f10 = uVar4;
      }
      *(undefined4 *)(long)DAT_ffffffffbfc43894 = 0;
      pcVar13 = (code *)(long)DAT_ffffffffbfc43980;
    }
    do {
      lVar12 = (long)DAT_ffffffffbfc436f4;
      (*pcVar13)();
      lVar2 = (*(code *)(long)DAT_ffffffffbfc43b08)();
      if (lVar2 != 0) {
        (*(code *)(long)DAT_ffffffffbfc43eec)();
        pcVar13 = (code *)(long)DAT_ffffffffbfc43e38;
        iVar10 = DAT_ffffffffbfc436f4 + -0x5ce8;
        goto LAB_ffffffffbfc0d3e0;
      }
      (*(code *)(long)DAT_ffffffffbfc43f04)();
      if ((*(int *)(lVar12 + 0x4a1c) != 0) &&
         (lVar2 = (*(code *)(long)DAT_ffffffffbfc43d0c)(0),
         *(ulong *)((long)DAT_ffffffffbfc436f4 + 0x4a28) <
         (ulong)(lVar2 - *(long *)((long)DAT_ffffffffbfc436f4 + 0x4a20)))) {
        iVar5 = *(int *)(lVar12 + 0x4a1c);
        *(undefined4 *)(lVar12 + 0x4a1c) = 0;
        (*(code *)(long)iVar5)();
      }
      iVar5 = *(int *)(long)DAT_ffffffffbfc43d80;
      if (iVar5 == 3) {
        puVar11 = (uint *)(long)DAT_ffffffffbfc43894;
        iVar10 = DAT_ffffffffbfc43eec;
        if (*puVar11 != 0) {
          lVar2 = (*(code *)(long)DAT_ffffffffbfc43b98)();
          uVar9 = *puVar11;
          uVar8 = (ulong)(in_k0[9] * 0x7d);
          lVar12 = special2(uVar8,uVar8,3,0x32);
          if (uVar8 == 0) {
            trap(7);
          }
          lVar2 = (long)(int)((ulong)(lVar2 - *(long *)(long)DAT_ffffffffbfc43f10) / uVar8);
          if (lVar2 == 0) {
            trap(7);
          }
          iVar10 = (int)((long)((long)(int)((ulong)uVar9 * 1000 >> 0x20) << 0x20 |
                               (ulong)uVar9 * 1000 & 0xffffffff) / lVar2);
          if (iVar10 < 0) {
            iVar10 = iVar10 + 0x3ff;
          }
          (*(code *)(long)*(int *)(lVar12 + 0x92c))
                    (*(int *)(lVar12 + 0x14) + -0x5ce0,uVar9,uVar9,iVar10 >> 10);
          (*(code *)(long)*(int *)(lVar12 + 0x2c4))
                    (lVar14,*(int *)(lVar12 + 0x14) + -0x5ca8,*puVar11);
          (*(code *)(long)*(int *)(lVar12 + 0x434))(*(int *)(lVar12 + 0x10) + 0x7b80,lVar14);
          (*(code *)(long)*(int *)(lVar12 + 0x2c4))
                    (lVar14,*(int *)(lVar12 + 0x14) + -0x5ca0,
                     *(undefined4 *)(long)*(int *)(lVar12 + 0x534));
          (*(code *)(long)*(int *)(lVar12 + 0x434))(*(int *)(lVar12 + 0x10) + 0x7b70,lVar14);
          iVar10 = *(int *)(lVar12 + 0x80c);
        }
        (*(code *)(long)iVar10)();
        return *puVar11;
      }
      if (iVar5 == 4) {
        return 0xffffffff;
      }
      pcVar13 = (code *)(long)DAT_ffffffffbfc43980;
    } while (iVar5 != 2);
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a10) = 1;
  } while( true );
}

