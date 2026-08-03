/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0a7c0
 * Function: FUN_ffffffffbfc0a7c0
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

ulong FUN_ffffffffbfc0a7c0(char *param_1,ulong param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  char cVar6;
  char *pcVar7;
  undefined4 *puVar8;
  ulong uVar9;
  int iVar10;
  undefined8 unaff_s0;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar11[1] = &_gp;
  *puVar11 = unaff_s0;
  puVar11[2] = in_ra;
  param_2 = param_2 & 2;
  if (param_2 == 0) {
    do {
    } while (*(int *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830) != 0);
    *(int *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830) = 1;
  }
  puVar8 = (undefined4 *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830);
  uVar4 = (long)(int)puVar8[0xd] | 0xffffffff80000000;
  if (puVar8[4] == 3) {
    uVar9 = uVar4;
    for (iVar10 = 0; iVar10 != puVar8[10]; iVar10 = iVar10 + 1) {
      if (param_1 == (char *)0x0) {
        if (*(long *)(uVar4 + 8) == 0) {
LAB_ffffffffbfc0a89c:
          if (param_2 != 0) {
            return uVar9;
          }
          SYNC(4);
          SYNC(4);
          *puVar8 = 0;
          SYNC(4);
          SYNC(4);
          return uVar9;
        }
      }
      else {
        iVar3 = (int)uVar4 + 0x10;
        if (*(long *)(uVar4 + 8) != 0) {
          iVar5 = puVar8[0xb];
          pcVar7 = param_1;
          do {
            iVar5 = iVar5 + -1;
            cVar1 = *pcVar7;
            cVar2 = *(char *)(long)iVar3;
            cVar6 = cVar2;
            if ((iVar5 == 0) ||
               (pcVar7 = (char *)(long)((int)pcVar7 + 1), cVar6 = cVar1, cVar2 != cVar1)) break;
            iVar3 = iVar3 + 1;
            cVar6 = cVar2;
          } while (cVar1 != '\0');
          if (cVar6 == cVar2) goto LAB_ffffffffbfc0a89c;
        }
      }
      uVar9 = (ulong)((int)uVar9 + 0x90);
      uVar4 = (ulong)((int)uVar4 + 0x90);
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6318,puVar8[4],puVar8[5],puVar8)
    ;
  }
  if (param_2 == 0) {
    SYNC(4);
    SYNC(4);
    *(undefined4 *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4830) = 0;
    SYNC(4);
    SYNC(4);
  }
  return 0;
}

