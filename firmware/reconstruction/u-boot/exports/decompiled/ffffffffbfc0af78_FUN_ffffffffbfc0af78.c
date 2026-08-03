/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0af78
 * Function: FUN_ffffffffbfc0af78
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

long FUN_ffffffffbfc0af78
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,char *param_5,
               ulong param_6)

{
  char cVar1;
  long *plVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  long lVar6;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  ulong uVar7;
  undefined8 unaff_s4;
  ulong uVar8;
  undefined8 unaff_s5;
  long lVar9;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  undefined8 *puVar10;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x60);
  puVar10[8] = &_gp;
  puVar10[5] = unaff_s5;
  puVar10[9] = unaff_s8;
  lVar9 = (long)DAT_ffffffffbfc436f4;
  puVar10[7] = unaff_s7;
  piVar4 = (int *)(long)*(int *)(lVar9 + 0x4830);
  puVar10[6] = unaff_s6;
  iVar5 = piVar4[4];
  puVar10[3] = unaff_s3;
  *puVar10 = unaff_s0;
  puVar10[10] = in_ra;
  puVar10[4] = unaff_s4;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  if (iVar5 == 3) {
    uVar8 = param_6 & 2;
    if (uVar8 == 0) {
      do {
      } while (*piVar4 != 0);
      *piVar4 = 1;
    }
    param_6 = param_6 | 2;
    plVar2 = (long *)(*(code *)(long)DAT_ffffffffbfc43814)(0,param_6);
    lVar6 = (*(code *)(long)DAT_ffffffffbfc43814)(param_5,param_6);
    if ((lVar6 == 0) && (plVar2 != (long *)0x0)) {
      uVar7 = param_1 + 0xfU & 0xfffffffffffffff0;
      lVar6 = (*(code *)(long)DAT_ffffffffbfc43a08)(uVar7,param_2,param_3,param_4,param_6);
      if (-1 < lVar6) {
        iVar5 = *(int *)(lVar9 + 0x4830);
        plVar2[1] = uVar7;
        iVar5 = *(int *)((long)iVar5 + 0x2c);
        *plVar2 = lVar6;
        if (iVar5 != 0) {
          iVar3 = (int)plVar2 + 0x10;
          do {
            cVar1 = *param_5;
            iVar5 = iVar5 + -1;
            *(char *)(long)iVar3 = cVar1;
            iVar3 = iVar3 + 1;
            if (cVar1 == '\0') break;
            param_5 = (char *)(long)((int)param_5 + 1);
          } while (iVar5 != 0);
        }
        *(undefined1 *)((long)(*(int *)((long)*(int *)(lVar9 + 0x4830) + 0x2c) + (int)plVar2) + 0xf)
             = 0;
      }
      if (uVar8 == 0) {
        SYNC(4);
        SYNC(4);
        *(undefined4 *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830) = 0;
        SYNC(4);
        SYNC(4);
      }
    }
    else {
      if (uVar8 == 0) {
        SYNC(4);
        SYNC(4);
        *(undefined4 *)(long)*(int *)(lVar9 + 0x4830) = 0;
        SYNC(4);
        SYNC(4);
      }
      lVar6 = -1;
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6318,iVar5,piVar4[5],piVar4);
    lVar6 = -1;
  }
  return lVar6;
}

