/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0acec
 * Function: FUN_ffffffffbfc0acec
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

ulong FUN_ffffffffbfc0acec(long param_1,long param_2,ulong param_3,ulong param_4,ulong param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong *puVar7;
  int *piVar8;
  ulong uVar9;
  ulong *puVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  undefined4 *puVar14;
  undefined8 unaff_s0;
  ulong uVar15;
  undefined8 *puVar16;
  undefined8 in_ra;
  
  puVar16 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar16[1] = &_gp;
  *puVar16 = unaff_s0;
  lVar3 = (long)DAT_ffffffffbfc436f4;
  puVar16[2] = in_ra;
  piVar8 = (int *)(long)*(int *)(lVar3 + 0x4830);
  if ((uint)piVar8[4] < 4) {
    if (param_1 != 0) {
      uVar11 = param_1 + 0xfU & 0xfffffffffffffff0;
      if (param_2 == 0) {
        if (param_3 == 0) {
          param_3 = 0xffffffffffffffff;
        }
      }
      else if (param_3 == 0) {
        param_3 = param_2 + uVar11;
      }
      if (param_4 < 0x10) {
        param_4 = 0x10;
      }
      uVar2 = -param_4;
      uVar13 = (param_2 + param_4) - 1 & uVar2;
      if (uVar11 <= param_3 - uVar13) {
        if ((param_5 & 2) == 0) {
          do {
          } while (*piVar8 != 0);
          *piVar8 = 1;
        }
        puVar14 = (undefined4 *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830);
        uVar12 = *(ulong *)(puVar14 + 2);
        uVar15 = 0;
        while (uVar6 = uVar12, uVar6 != 0) {
          puVar10 = (ulong *)(uVar6 + 8 & 0x7fffffffffffffff | 0x8000000000000000);
          uVar12 = *puVar10;
          puVar7 = (ulong *)(uVar6 & 0x7fffffffffffffff | 0x8000000000000000);
          if ((*puVar7 != 0) && (*puVar7 < uVar6)) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6240,uVar6,*puVar7);
            break;
          }
          uVar5 = uVar13;
          if (uVar13 <= uVar6) {
            uVar5 = uVar6;
          }
          uVar9 = uVar6 + uVar12;
          uVar5 = uVar5 + ~uVar2 & uVar2;
          if ((uVar5 < uVar9) && (uVar6 < param_3)) {
            uVar4 = param_3;
            if (uVar9 <= param_3) {
              uVar4 = uVar9;
            }
            if (uVar11 <= uVar4 - uVar5) {
              uVar1 = getCopReg(2,0);
              *(undefined4 *)(param_5 + 3) = uVar1;
              if (uVar5 == uVar6) {
                uVar6 = uVar6 + uVar11;
                if (uVar11 < uVar12) {
                  *(ulong *)(uVar6 & 0x7fffffffffffffff | 0x8000000000000000) = *puVar7;
                  *(ulong *)(uVar6 + 8 & 0x7fffffffffffffff | 0x8000000000000000) = uVar12 - uVar11;
                  *puVar7 = uVar6;
                }
                if (uVar15 == 0) {
                  *(ulong *)(puVar14 + 2) = *puVar7;
                }
                else {
                  *(ulong *)(uVar15 & 0x7fffffffffffffff | 0x8000000000000000) = *puVar7;
                }
                if ((param_5 & 2) != 0) {
                  return uVar5;
                }
                SYNC(4);
                SYNC(4);
                *puVar14 = 0;
                SYNC(4);
                SYNC(4);
                return uVar5;
              }
              *(ulong *)(uVar5 & 0x7fffffffffffffff | 0x8000000000000000) = *puVar7;
              *(ulong *)(uVar5 + 8 & 0x7fffffffffffffff | 0x8000000000000000) =
                   *puVar10 - (uVar5 - uVar6);
              *puVar10 = uVar5 - uVar6;
              *puVar7 = uVar5;
            }
          }
          uVar15 = uVar6;
          uVar12 = *puVar7;
        }
      }
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6318,piVar8[4],piVar8[5],piVar8)
    ;
  }
  uVar1 = getCopReg(2,1);
  *(undefined4 *)(param_5 + 9) = uVar1;
  SYNC(4);
  SYNC(4);
  *(undefined4 *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830) = 0;
  SYNC(4);
  SYNC(4);
  return 0xffffffffffffffff;
}

