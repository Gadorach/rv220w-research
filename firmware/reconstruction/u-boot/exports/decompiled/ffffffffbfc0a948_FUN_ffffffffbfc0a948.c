/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0a948
 * Function: FUN_ffffffffbfc0a948
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

undefined8 FUN_ffffffffbfc0a948(ulong param_1,long param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong uVar9;
  undefined4 *puVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x10);
  *puVar11 = &_gp;
  puVar11[1] = in_ra;
  lVar5 = (long)DAT_ffffffffbfc436f4;
  piVar3 = (int *)(long)*(int *)(lVar5 + 0x4830);
  if (3 < (uint)piVar3[4]) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6318,piVar3[4],piVar3[5],piVar3)
    ;
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = *(int *)(lVar5 + 0x4830);
  if ((param_3 & 2) == 0) {
    do {
    } while (*piVar3 != 0);
    *piVar3 = 1;
    iVar1 = *(int *)(lVar5 + 0x4830);
  }
  puVar10 = (undefined4 *)(long)iVar1;
  uVar6 = *(ulong *)(puVar10 + 2);
  if (uVar6 != 0) {
    if (uVar6 <= param_1) {
      uVar9 = 0;
      do {
        uVar7 = uVar6;
        puVar8 = (ulong *)(uVar7 & 0x7fffffffffffffff | 0x8000000000000000);
        if (param_1 <= uVar7) {
          plVar4 = (long *)(uVar9 + 8 & 0x7fffffffffffffff | 0x8000000000000000);
          lVar5 = *plVar4;
          if (uVar9 + lVar5 == param_1) {
            *plVar4 = *plVar4 + param_2;
            uVar6 = uVar9 + lVar5 + param_2;
            if (uVar6 != uVar7) goto LAB_ffffffffbfc0abd8;
            *plVar4 = *(long *)(uVar7 + 8 & 0x7fffffffffffffff | 0x8000000000000000) + *plVar4;
            *(undefined8 *)(uVar9 & 0x7fffffffffffffff | 0x8000000000000000) =
                 *(undefined8 *)(uVar6 & 0x7fffffffffffffff | 0x8000000000000000);
            uVar2 = 1;
            goto LAB_ffffffffbfc0abdc;
          }
          if (param_1 + param_2 == uVar7) {
            *(long *)(param_1 + 8 & 0x7fffffffffffffff | 0x8000000000000000) =
                 *(long *)(uVar7 + 8 & 0x7fffffffffffffff | 0x8000000000000000) + param_2;
            *(undefined8 *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000) =
                 *(undefined8 *)(param_1 + param_2 & 0x7fffffffffffffff | 0x8000000000000000);
          }
          else {
            *(long *)(param_1 + 8 & 0x7fffffffffffffff | 0x8000000000000000) = param_2;
            *(ulong *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000) = uVar7;
          }
          *(ulong *)(uVar9 & 0x7fffffffffffffff | 0x8000000000000000) = param_1;
          goto LAB_ffffffffbfc0abd8;
        }
        uVar6 = *puVar8;
        uVar9 = uVar7;
      } while (uVar6 != 0);
      plVar4 = (long *)(uVar7 + 8 & 0x7fffffffffffffff | 0x8000000000000000);
      if (uVar7 + *plVar4 == param_1) {
        *plVar4 = *plVar4 + param_2;
        uVar2 = 1;
      }
      else {
        *puVar8 = param_1;
        *(long *)(param_1 + 8 & 0x7fffffffffffffff | 0x8000000000000000) = param_2;
        *(undefined8 *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000) = 0;
        uVar2 = 1;
      }
      goto LAB_ffffffffbfc0abdc;
    }
    if (uVar6 < param_1 + param_2) {
      uVar2 = 0;
      goto LAB_ffffffffbfc0abdc;
    }
  }
  if (param_1 + param_2 == uVar6) {
    *(undefined8 *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000) =
         *(undefined8 *)(uVar6 & 0x7fffffffffffffff | 0x8000000000000000);
    *(long *)(param_1 + 8 & 0x7fffffffffffffff | 0x8000000000000000) =
         *(long *)(param_1 + param_2 + 8 & 0x7fffffffffffffff | 0x8000000000000000) + param_2;
    *(ulong *)(puVar10 + 2) = param_1;
  }
  else {
    *(ulong *)(param_1 & 0x7fffffffffffffff | 0x8000000000000000) = uVar6;
    *(long *)(param_1 + 8 & 0x7fffffffffffffff | 0x8000000000000000) = param_2;
    *(ulong *)(puVar10 + 2) = param_1;
  }
LAB_ffffffffbfc0abd8:
  uVar2 = 1;
LAB_ffffffffbfc0abdc:
  if ((param_3 & 2) == 0) {
    SYNC(4);
    SYNC(4);
    *puVar10 = 0;
    SYNC(4);
    SYNC(4);
  }
  return uVar2;
}

