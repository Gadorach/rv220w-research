/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc53470
 * Function: FUN_ffffffffbfc53470
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

undefined8 FUN_ffffffffbfc53470(long param_1,int param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int iVar9;
  long lVar7;
  long lVar8;
  undefined8 unaff_s0;
  long lVar10;
  undefined8 unaff_s1;
  char *pcVar11;
  undefined8 unaff_s2;
  char *pcVar12;
  undefined8 unaff_s3;
  int iVar13;
  undefined8 unaff_s4;
  code *pcVar14;
  long lVar15;
  undefined8 in_ra;
  
  lVar15 = (long)((int)&stack0x00000000 + -0x50);
  *(undefined1 **)(lVar15 + 0x38) = &_gp;
  *(undefined8 *)(lVar15 + 0x28) = unaff_s3;
  pcVar14 = (code *)(long)iRamffffffffbfc55d98;
  *(undefined8 *)(lVar15 + 0x30) = unaff_s4;
  *(undefined8 *)(lVar15 + 0x20) = unaff_s2;
  iVar13 = (int)param_1;
  *(undefined8 *)(lVar15 + 0x18) = unaff_s1;
  pcVar11 = (char *)(long)(iVar13 + 0x2a);
  *(undefined8 *)(lVar15 + 0x10) = unaff_s0;
  *(undefined8 *)(lVar15 + 0x40) = in_ra;
  (*pcVar14)((int)&stack0x00000000 + -0x4c,iVar13 + 6,6);
  pcVar14 = (code *)(long)iRamffffffffbfc55ce0;
  if (*(char *)(param_1 + 0x2a) != '\x01') goto LAB_ffffffffbfc537f0;
  if (*(short *)(pcVar11 + 10) == -0x8000) {
    *(undefined4 *)(long)iRamffffffffbfc55c50 = 1;
  }
  iVar9 = iRamffffffffbfc55c28;
  if (pcVar11[0xf2] == '\x01') {
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5ad8);
    pcVar14 = (code *)(long)iRamffffffffbfc55d98;
    *(undefined1 *)(param_1 + 0x2a) = 2;
    (*pcVar14)(iVar13 + 0x3a,iVar9 + 0x5bf8,4);
    piVar6 = (int *)(long)iRamffffffffbfc55c50;
    pcVar11[0xf2] = '\x02';
    if (*piVar6 == 0) {
      iVar9 = iVar9 + 0x5bf8;
    }
    else {
      iVar9 = iRamffffffffbfc55c28 + 0x5c00;
    }
    (*(code *)(long)iRamffffffffbfc55d98)(lVar15,iVar9,4);
    (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + 0x11d,uRamffffffffbfc55dd8,0x2f);
    pcVar14 = (code *)(long)iRamffffffffbfc55ce0;
    goto LAB_ffffffffbfc537f0;
  }
  if (pcVar11[0xf2] != '\x03') {
    return 0xffffffffffffffff;
  }
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5af8);
  cVar1 = pcVar11[0xc];
  *(undefined1 *)(param_1 + 0x2a) = 2;
  iVar9 = iRamffffffffbfc55c28;
  if ((((cVar1 == -0x40) || (cVar1 == '\0')) &&
      ((cVar2 = pcVar11[0xd], cVar2 == -0x58 || (cVar2 == '\0')))) && ((byte)pcVar11[0xe] < 2)) {
    pcVar12 = pcVar11;
    if ((cVar1 != -0x40) || (cVar2 != -0x58)) {
      param_2 = param_2 + -0x2a;
LAB_ffffffffbfc536c8:
      while (bVar4 = 6 < param_2, param_2 = param_2 + -1, bVar4) {
        if ((*pcVar12 == '2') && (pcVar12[1] == '\x04')) {
          (*(code *)(long)iRamffffffffbfc55d98)(iRamffffffffbfc55c28 + 0x6e80,(int)pcVar12 + 2,4);
          bVar4 = true;
          goto LAB_ffffffffbfc536d8;
        }
        pcVar12 = (char *)(long)((int)pcVar12 + 1);
      }
      bVar4 = false;
LAB_ffffffffbfc536d8:
      iVar9 = iRamffffffffbfc55c28;
      if ((((*(char *)((long)iRamffffffffbfc55c28 + 0x6e80) == -0x40) &&
           (lVar8 = (long)(iRamffffffffbfc55c28 + 0x6e80), *(char *)(lVar8 + 1) == -0x58)) &&
          (*(char *)(lVar8 + 2) == '\x01')) && (bVar4)) {
        (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + 0x36,lVar8,4);
        lVar10 = (long)(iVar13 + 0x3a);
        lVar7 = lVar8;
LAB_ffffffffbfc53730:
        (*(code *)(long)iRamffffffffbfc55d98)(lVar10,lVar8,4);
      }
      else {
        (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + 0x36,iRamffffffffbfc55c28 + 0x5bf8,4);
        (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + 0x3a,iVar9 + 0x5bf8,4);
        lVar7 = (long)(iVar9 + 0x5bf8);
      }
      iVar9 = iRamffffffffbfc55d98;
      pcVar11[0xf2] = '\x05';
      goto LAB_ffffffffbfc53788;
    }
    param_2 = param_2 + -0x2a;
    if (pcVar11[0xe] != 1) goto LAB_ffffffffbfc536c8;
    if ((byte)(pcVar11[0xf] - 2U) < 0xfc) {
      lVar10 = (long)(iVar13 + 0x3a);
      lVar8 = (long)(iVar13 + 0x36);
      lVar7 = lVar10;
      goto LAB_ffffffffbfc53730;
    }
  }
  else {
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5b18);
    (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + 0x36,iVar9 + 0x6e78,4);
    (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + 0x3a,iVar9 + 0x6e78,4);
    iVar9 = iRamffffffffbfc55d98;
    iVar5 = iRamffffffffbfc55c28;
    pcVar11[0xf2] = '\x06';
    lVar7 = (long)(iVar5 + 0x5c00);
LAB_ffffffffbfc53788:
    (*(code *)(long)iVar9)(lVar15,lVar7,4);
  }
  pcVar14 = (code *)(long)iRamffffffffbfc55d98;
  if (*(int *)(long)iRamffffffffbfc55c50 != 0) {
    (*pcVar14)(lVar15,iRamffffffffbfc55c28 + 0x5c00,4);
    pcVar14 = (code *)(long)iRamffffffffbfc55d98;
  }
  (*pcVar14)(iVar13 + 0x11d,uRamffffffffbfc55dd8,0x2f);
  lVar7 = (long)(iRamffffffffbfc55c28 + 0x5bf8);
  bVar3 = *(byte *)(lVar7 + 3);
  *(byte *)(lVar7 + 3) = bVar3 + 1;
  if (0xfa < bVar3) {
    *(undefined1 *)(lVar7 + 3) = 100;
  }
  pcVar14 = (code *)(long)iRamffffffffbfc55ce0;
LAB_ffffffffbfc537f0:
  (*pcVar14)(param_1,0x14c,lVar15);
  return 0;
}

