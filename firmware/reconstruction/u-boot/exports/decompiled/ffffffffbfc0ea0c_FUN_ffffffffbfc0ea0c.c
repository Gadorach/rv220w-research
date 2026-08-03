/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0ea0c
 * Function: FUN_ffffffffbfc0ea0c
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

void FUN_ffffffffbfc0ea0c(void)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  char cVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined8 unaff_s0;
  long lVar12;
  code *pcVar13;
  undefined8 *puVar14;
  undefined8 in_ra;
  
  puVar14 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar14[1] = &_gp;
  *puVar14 = unaff_s0;
  puVar14[2] = in_ra;
  iVar5 = DAT_ffffffffbfc436f4;
  lVar12 = (long)DAT_ffffffffbfc436f4;
  if (*(int *)(lVar12 + 0x4a78) == 0) {
    return;
  }
  pcVar13 = (code *)(long)DAT_ffffffffbfc43f0c;
  *(undefined4 *)(long)DAT_ffffffffbfc43d74 = 0;
  pcVar6 = (char *)(*pcVar13)(iVar5 + -23000);
  if (pcVar6 != (char *)0x0) {
    pcVar10 = (char *)(long)*(int *)(lVar12 + 0x4a78);
    pcVar11 = pcVar10;
    do {
      cVar3 = *pcVar11;
      pcVar8 = pcVar6;
      pcVar9 = pcVar11;
      do {
        cVar4 = *pcVar8;
        pcVar9 = (char *)(long)((int)pcVar9 + 1);
        pcVar8 = (char *)(long)((int)pcVar8 + 1);
        cVar7 = cVar3;
        if (cVar4 != cVar3) break;
        bVar2 = cVar3 != '\0';
        cVar3 = *pcVar9;
        cVar7 = cVar4;
      } while (bVar2);
      if (cVar7 == cVar4) {
        *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a78) = (int)pcVar11;
        return;
      }
      piVar1 = (int *)(pcVar11 + 0x30);
      pcVar11 = (char *)(long)*piVar1;
    } while (pcVar10 != pcVar11);
    *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a78) = *piVar1;
  }
  (*(code *)(long)DAT_ffffffffbfc43b14)
            (DAT_ffffffffbfc436f4 + -23000,*(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a78));
  return;
}

