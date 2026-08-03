/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13170
 * Function: FUN_ffffffffbfc13170
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

void FUN_ffffffffbfc13170(void)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  int iVar7;
  long lVar4;
  int iVar8;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar9;
  uint uVar11;
  undefined8 uVar10;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar12;
  undefined8 *puVar13;
  undefined8 in_ra;
  
  puVar13 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar13[4] = &_gp;
  puVar13[5] = in_ra;
  puVar13[1] = unaff_s1;
  pcVar12 = (code *)(long)DAT_ffffffffbfc439d0;
  puVar13[3] = unaff_s3;
  puVar13[2] = unaff_s2;
  *puVar13 = unaff_s0;
  (*pcVar12)();
  iVar8 = DAT_ffffffffbfc436f4;
  (*(code *)(long)DAT_ffffffffbfc43e7c)();
  lVar3 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x5258);
  if (lVar3 == 0) {
    lVar3 = (*(code *)(long)DAT_ffffffffbfc43f0c)(iVar8 + -0x5260);
    iVar7 = 0;
LAB_ffffffffbfc131f0:
    if (lVar3 != 0) {
      iVar8 = 1;
      if (0 < iVar7) {
        iVar8 = iVar7;
      }
      bVar2 = false;
      while (0 < iVar8) {
        iVar7 = 0;
        if (bVar2) {
          (*(code *)(long)DAT_ffffffffbfc439f0)(10);
          piVar6 = (int *)(long)DAT_ffffffffbfc43e88;
          goto LAB_ffffffffbfc132ac;
        }
        do {
          iVar7 = iVar7 + 1;
          lVar4 = (*(code *)(long)DAT_ffffffffbfc43b08)();
          if (lVar4 != 0) {
            iVar8 = 0;
            bVar2 = true;
            (*(code *)(long)DAT_ffffffffbfc43e94)(10000);
            goto LAB_ffffffffbfc13254;
          }
          (*(code *)(long)DAT_ffffffffbfc43b18)();
        } while (iVar7 != 100);
        iVar8 = iVar8 + -1;
LAB_ffffffffbfc13254:
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5248,iVar8);
      }
      (*(code *)(long)DAT_ffffffffbfc439f0)(10);
      piVar6 = (int *)(long)DAT_ffffffffbfc43e88;
      if (bVar2) goto LAB_ffffffffbfc132ac;
      (*(code *)(long)DAT_ffffffffbfc4374c)();
      (*(code *)(long)DAT_ffffffffbfc43fcc)(lVar3,0);
    }
  }
  else {
    iVar7 = (*(code *)(long)DAT_ffffffffbfc43f3c)(lVar3,0,10);
    lVar3 = (*(code *)(long)DAT_ffffffffbfc43f0c)(iVar8 + -0x5260);
    if (-1 < iVar7) goto LAB_ffffffffbfc131f0;
  }
  piVar6 = (int *)(long)DAT_ffffffffbfc43e88;
LAB_ffffffffbfc132ac:
  *(undefined4 *)(long)*piVar6 = 2;
  SYNC(0);
  lVar3 = 1;
  do {
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43e4c)(DAT_ffffffffbfc436f4 + -0x5240);
    (*(code *)(long)DAT_ffffffffbfc437f8)();
    piVar6 = (int *)(long)DAT_ffffffffbfc43e88;
    if (lVar4 == -3) {
      iVar8 = *piVar6;
      if (*(int *)(long)iVar8 == 1) {
        uVar9 = ((int *)(long)iVar8)[1];
        uVar11 = 0xf7;
        if (uVar9 < 0xf8) {
          uVar11 = uVar9;
        }
        if (uVar11 != 0) {
          iVar8 = iVar8 + 8;
          iVar7 = DAT_ffffffffbfc436f4 + 0x4ab0;
          uVar9 = uVar11;
          do {
            cVar1 = *(char *)(long)iVar8;
            uVar9 = uVar9 - 1;
            *(char *)(long)iVar7 = cVar1;
            iVar7 = iVar7 + 1;
            if (cVar1 == '\0') break;
            iVar8 = iVar8 + 1;
          } while (uVar9 != 0);
        }
        puVar5 = (undefined4 *)(long)*piVar6;
        *(undefined1 *)(long)(int)(uVar11 + DAT_ffffffffbfc436f4 + 0x4ab0) = 0;
        *puVar5 = 2;
        puVar5[1] = 0;
        SYNC(0);
LAB_ffffffffbfc13390:
        uVar10 = 1;
        if (lVar4 == 0) goto LAB_ffffffffbfc133bc;
      }
      else {
        lVar4 = -1;
      }
      uVar10 = 0;
      if (lVar4 != -1) goto LAB_ffffffffbfc133bc;
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5230);
    }
    else {
      if (lVar4 < 1) goto LAB_ffffffffbfc13390;
      iVar7 = DAT_ffffffffbfc436f4 + 0x4ab0;
      iVar8 = DAT_ffffffffbfc44084;
      do {
        cVar1 = *(char *)(long)iVar8;
        iVar8 = iVar8 + 1;
        *(char *)(long)iVar7 = cVar1;
        iVar7 = iVar7 + 1;
      } while (cVar1 != '\0');
      uVar10 = 0;
LAB_ffffffffbfc133bc:
      lVar3 = (*(code *)(long)DAT_ffffffffbfc43fcc)(DAT_ffffffffbfc436f4 + 0x4ab0,uVar10);
    }
    if (lVar3 < 1) {
      *(undefined1 *)((long)DAT_ffffffffbfc436f4 + 0x4ab0) = 0;
    }
  } while( true );
}

