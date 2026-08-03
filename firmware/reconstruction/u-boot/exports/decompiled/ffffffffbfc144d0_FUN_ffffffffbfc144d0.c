/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc144d0
 * Function: FUN_ffffffffbfc144d0
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

undefined8 FUN_ffffffffbfc144d0(char *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 unaff_s0;
  char *pcVar6;
  undefined8 unaff_s1;
  char *pcVar7;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  code *pcVar8;
  int *piVar9;
  undefined8 in_ra;
  
  piVar9 = (int *)(long)((int)&stack0x00000000 + -0x60);
  *(undefined1 **)(piVar9 + 0x12) = &_gp;
  *(undefined8 *)(piVar9 + 0x10) = unaff_s6;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43798;
  *(undefined8 *)(piVar9 + 0xe) = unaff_s5;
  *(undefined8 *)(piVar9 + 0xc) = unaff_s4;
  *(undefined8 *)(piVar9 + 6) = unaff_s1;
  *(undefined8 *)(piVar9 + 4) = unaff_s0;
  *(undefined8 *)(piVar9 + 0x14) = in_ra;
  *(undefined8 *)(piVar9 + 10) = unaff_s3;
  *(undefined8 *)(piVar9 + 8) = unaff_s2;
  puVar2 = (undefined1 *)(*pcVar8)(param_1,0x3a);
  if (puVar2 == (undefined1 *)0x0) {
    return 0;
  }
  pcVar8 = (code *)(long)DAT_ffffffffbfc438b0;
  *puVar2 = 0;
  lVar3 = (*pcVar8)(param_1,piVar9,10);
  iVar1 = DAT_ffffffffbfc43fc4;
  if ((char *)(long)*piVar9 != param_1) {
    if (*(char *)(long)*piVar9 != '\0') {
      return 0xffffffffffffffff;
    }
    if (lVar3 < 1) {
      return 0xffffffffffffffff;
    }
    if (lVar3 != 1) {
      return 0xffffffffffffffff;
    }
    lVar3 = (long)DAT_ffffffffbfc43fc4;
    if (*(int *)(lVar3 + 8) == 0xffff) {
      return 0xffffffffffffffff;
    }
    pcVar7 = (char *)(long)((int)puVar2 + 1);
    puVar2 = (undefined1 *)(*(code *)(long)DAT_ffffffffbfc43798)(pcVar7,0x2d);
    pcVar6 = (char *)0x0;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0;
      pcVar6 = (char *)(long)((int)puVar2 + 1);
    }
    lVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar7,piVar9,10);
    if ((char *)(long)*piVar9 != pcVar7) {
      if (*(char *)(long)*piVar9 != '\0') {
        return 0xffffffffffffffff;
      }
      if ((long)(ulong)*(ushort *)(lVar3 + 4) <= lVar4) {
        return 0xffffffffffffffff;
      }
      lVar5 = lVar4;
      if (pcVar6 == (char *)0x0) {
LAB_ffffffffbfc14644:
        *param_3 = (int)lVar4;
        *param_2 = iVar1;
        *param_4 = (int)lVar5;
        return 1;
      }
      lVar5 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar6,piVar9,10);
      if ((char *)(long)*piVar9 != pcVar6) {
        if (*(char *)(long)*piVar9 != '\0') {
          return 0xffffffffffffffff;
        }
        if (lVar5 < lVar4) {
          return 0xffffffffffffffff;
        }
        if (lVar5 < (long)(ulong)*(ushort *)(lVar3 + 4)) goto LAB_ffffffffbfc14644;
      }
    }
  }
  return 0xffffffffffffffff;
}

