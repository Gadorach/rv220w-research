/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc353c8
 * Function: FUN_ffffffffbfc353c8
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

undefined8 FUN_ffffffffbfc353c8(ulong param_1,ulong param_2,ulong param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar5;
  undefined8 uVar4;
  long lVar6;
  uint uVar7;
  long *plVar8;
  ulong unaff_s0;
  code *pcVar9;
  ulong unaff_s1;
  ulong unaff_s2;
  int iVar10;
  ulong unaff_s3;
  ulong uVar11;
  long lVar12;
  ulong unaff_s4;
  undefined8 uVar13;
  ulong unaff_s5;
  long lVar14;
  ulong unaff_s6;
  ulong unaff_s7;
  ulong *puVar15;
  ulong unaff_s8;
  ulong in_ra;
  
  puVar15 = (ulong *)(long)((int)&stack0x00000000 + -0x80);
  puVar15[0xc] = (ulong)&_gp;
  puVar15[0xd] = unaff_s8;
  puVar15[10] = unaff_s6;
  puVar15[0xe] = in_ra;
  puVar15[0xb] = unaff_s7;
  puVar15[9] = unaff_s5;
  puVar15[8] = unaff_s4;
  puVar15[7] = unaff_s3;
  puVar15[6] = unaff_s2;
  puVar15[5] = unaff_s1;
  puVar15[4] = unaff_s0;
  puVar15[1] = param_2;
  *(undefined4 *)(puVar15 + 2) = param_4;
  if ((param_1 < 0x28) || (param_2 = param_1, param_1 == 0x3f)) {
    uVar11 = puVar15[1] + param_3;
    pcVar9 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x5110);
    lVar1 = (*pcVar9)(0x30d0100,param_2);
    uVar2 = 0x20;
    if (lVar1 == 0) {
      lVar1 = (*pcVar9)(0x10d0200);
      uVar2 = 0x20;
      if (lVar1 == 0) {
        lVar1 = (*pcVar9)(0x10d0210);
        uVar2 = 0x20;
        if (lVar1 == 0) {
          lVar1 = (*pcVar9)(0x30d0600);
          uVar2 = 0x20;
          if (lVar1 == 0) {
            lVar1 = (*pcVar9)(0x30d0300);
            uVar2 = 0x100;
            if (lVar1 == 0) {
              lVar1 = (*pcVar9)(0x30d0400);
              uVar2 = 0x80;
              if (lVar1 != 0) {
                uVar2 = 0x100;
              }
            }
          }
        }
      }
    }
    if (uVar11 <= uVar2) {
      iVar5 = *(int *)(puVar15 + 2);
      if (param_1 == 0x3f) {
        lVar14 = -1;
        lVar1 = -1;
      }
      else {
        lVar14 = -1;
        lVar1 = -1;
        lVar6 = 0;
        for (uVar11 = 0; plVar8 = (long *)(long)iVar5, uVar11 != param_3; uVar11 = uVar11 + 1) {
          lVar12 = lVar1;
          if ((lVar14 == -1) && ((*plVar8 != 9 || (lVar14 = lVar6, lVar6 == -1))))
          goto LAB_ffffffffbfc35594;
          if (lVar1 == -1) {
            if ((*plVar8 == 9) || (uVar11 == 0)) {
              lVar12 = lVar6;
              if (uVar11 == param_3 - 1) goto LAB_ffffffffbfc35594;
            }
            else {
              lVar12 = (long)((int)lVar6 + -1);
LAB_ffffffffbfc35594:
              lVar1 = lVar12;
              if (lVar12 != -1) goto LAB_ffffffffbfc355a0;
            }
          }
          else {
LAB_ffffffffbfc355a0:
            lVar1 = lVar12;
            if ((lVar12 < lVar6) && (*plVar8 == 9)) {
              (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2708,lVar6,lVar12);
              return 3;
            }
          }
          lVar6 = (long)((int)lVar6 + 1);
          iVar5 = iVar5 + 8;
        }
        if (0 < lVar14) {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2780,lVar14);
          return 3;
        }
      }
      uVar13 = 0;
      uVar11 = 0;
      iVar5 = (int)puVar15[1];
      while( true ) {
        if (uVar11 == param_3) {
          return uVar13;
        }
        iVar10 = (int)uVar11;
        uVar2 = special2(uVar11,param_3 - 1,0,0x2a);
        uVar7 = (uint)*(undefined8 *)(long)(*(int *)(puVar15 + 2) + iVar10 * 8);
        lVar6 = special2((long)iVar10,lVar1,0,0x2a);
        uVar2 = (uVar2 & 1) << 0x10 | (uVar11 & 7) << 0xd | ((long)(int)param_1 & 0x3fU) << 7 |
                (long)iVar5 & 0x7fU | (long)(int)(~(uint)lVar14 >> 0x1f) << 0x3e |
                ((ulong)(lVar1 < iVar10) ^ 1) << 0x3d | lVar6 << 0x3f;
        *puVar15 = puVar15[1] + uVar11;
        if (uVar7 < 10) break;
        uVar13 = 3;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x27d8);
        uVar4 = *puVar15;
        if (param_1 == 0x3f) {
          uVar2 = uVar2 | 0x1fe0000000000000;
        }
        else {
          lVar6 = (*(code *)(long)DAT_ffffffffbfc43b6c)((uint)uVar4 & 0xffff,0,2,0x3f8);
          if (lVar6 != 0) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2810);
            return 4;
          }
          uVar3 = (*(code *)(long)DAT_ffffffffbfc43d6c)((uint)uVar4 & 0xffff);
          if (uVar3 == 0) {
            (*(code *)(long)DAT_ffffffffbfc43be4)(DAT_ffffffffbfc436f0 + 0x7eb8);
          }
          uVar2 = uVar2 | 0x1fe0000000000000 | (uVar3 & 0x1fffffff) << 0x11;
        }
        uVar3 = *puVar15;
        SYNC(4);
        SYNC(4);
        lVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5110))(0x70d0300);
        if (lVar6 == 0) {
          (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5288))
                    (0x8001180050000100,
                     ((long)(int)(uVar11 >> 3) & 1U) << 1 | (long)(int)(uVar3 >> 7) & 1U);
        }
        uVar11 = uVar11 + 1;
        (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5288))(0x8001180050001000,uVar2);
        iVar5 = (int)((long)iVar5 & 0x7fU) + 1;
      }
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc3568c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar13 = (*(code *)(long)(*(int *)(long)(int)(uVar7 * 4 + DAT_ffffffffbfc436f0 + 0x6d20) +
                               -0x403bc920))();
      return uVar13;
    }
    uVar13 = 2;
    iVar5 = DAT_ffffffffbfc436f4 + 0x26d0;
  }
  else {
    uVar13 = 1;
    iVar5 = DAT_ffffffffbfc436f4 + 0x26a0;
    uVar11 = param_1;
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar5,uVar11);
  return uVar13;
}

