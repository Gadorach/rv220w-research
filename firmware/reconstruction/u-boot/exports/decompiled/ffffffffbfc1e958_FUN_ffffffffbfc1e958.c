/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1e958
 * Function: FUN_ffffffffbfc1e958
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

undefined8 FUN_ffffffffbfc1e958(char *param_1,char *param_2,int param_3,int param_4)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar7;
  char cVar11;
  long lVar4;
  char *pcVar5;
  long lVar6;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  int *piVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined1 *puVar19;
  char cVar21;
  int iVar20;
  undefined8 unaff_s0;
  undefined1 *puVar22;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined4 *puVar23;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar24;
  int *piVar25;
  undefined8 unaff_s8;
  undefined8 in_ra;
  int iVar26;
  
  iVar18 = (int)&stack0x00000000;
  iVar26 = iVar18 + -0x1d0;
  piVar25 = (int *)(long)iVar26;
  piVar25[0x59] = param_3;
  *(undefined1 **)(piVar25 + 0x6c) = &_gp;
  iVar10 = *(int *)(long)piVar25[0x59];
  piVar25[0x5a] = param_4;
  piVar25[0x58] = iVar10;
  iVar7 = DAT_ffffffffbfc436f4;
  *(undefined8 *)(piVar25 + 0x6e) = unaff_s8;
  iVar7 = iVar7 + -0x5240;
  *(undefined8 *)(piVar25 + 0x68) = unaff_s6;
  *(undefined8 *)(piVar25 + 0x66) = unaff_s5;
  *(undefined8 *)(piVar25 + 0x70) = in_ra;
  *(undefined8 *)(piVar25 + 0x6a) = unaff_s7;
  *(undefined8 *)(piVar25 + 100) = unaff_s4;
  *(undefined8 *)(piVar25 + 0x62) = unaff_s3;
  *(undefined8 *)(piVar25 + 0x60) = unaff_s2;
  *(undefined8 *)(piVar25 + 0x5e) = unaff_s1;
  *(undefined8 *)(piVar25 + 0x5c) = unaff_s0;
  iVar10 = *(int *)(long)piVar25[0x5a];
  cVar21 = *param_1;
  pcVar14 = param_1;
  do {
    cVar2 = *(char *)(long)iVar7;
    pcVar14 = (char *)(long)((int)pcVar14 + 1);
    iVar7 = iVar7 + 1;
    cVar11 = cVar21;
    if (cVar2 != cVar21) break;
    bVar1 = cVar21 != '\0';
    cVar21 = *pcVar14;
    cVar11 = cVar2;
  } while (bVar1);
  if (cVar11 != cVar2) {
    return 0;
  }
  lVar4 = (*(code *)(long)DAT_ffffffffbfc437c8)(param_2);
  if (lVar4 < 1) {
    cVar21 = '\0';
  }
  else {
    cVar21 = *(char *)((long)((int)param_2 + (int)lVar4) + -1);
  }
  pcVar5 = (char *)(long)(DAT_ffffffffbfc436f4 + 0x4e30);
  pcVar14 = param_2;
  pcVar15 = pcVar5;
  do {
    cVar2 = *pcVar14;
    pcVar14 = (char *)(long)((int)pcVar14 + 1);
    *pcVar15 = cVar2;
    pcVar15 = (char *)(long)((int)pcVar15 + 1);
  } while (cVar2 != '\0');
  iVar7 = 0;
  piVar16 = (int *)(long)(iVar18 + -0x180);
  do {
    cVar2 = *pcVar5;
    if ((cVar2 != ' ') && (cVar2 != '\t')) {
      if (cVar2 == '\0') {
LAB_ffffffffbfc1ead8:
        *(undefined4 *)((long)(iVar26 + iVar7 * 4) + 0x50) = 0;
        *piVar25 = 0;
        if (iVar7 != 0) goto LAB_ffffffffbfc1eb2c;
        iVar8 = 0;
        puVar23 = (undefined4 *)(long)DAT_ffffffffbfc43b1c;
        piVar16 = piVar25;
        iVar12 = DAT_ffffffffbfc4404c;
        break;
      }
      iVar12 = (int)pcVar5;
      *piVar16 = iVar12;
      iVar7 = iVar7 + 1;
      piVar16 = (int *)(long)((int)piVar16 + 4);
      do {
        iVar12 = iVar12 + 1;
        cVar2 = *(char *)(long)iVar12;
        if (cVar2 == '\0') goto LAB_ffffffffbfc1ead8;
      } while ((cVar2 != ' ') && (cVar2 != '\t'));
      pcVar5 = (char *)(long)iVar12;
      *pcVar5 = '\0';
      if (0x3f < iVar7) goto code_r0xffffffffbfc1eab0;
    }
    pcVar5 = (char *)(long)((int)pcVar5 + 1);
  } while( true );
LAB_ffffffffbfc1eb1c:
  puVar17 = (undefined4 *)(long)iVar12;
  if (puVar17 == puVar23) goto LAB_ffffffffbfc1ec44;
  piVar16 = (int *)(long)((int)piVar16 + 4);
  if (iVar8 == 0x12) {
    iVar8 = 0x13;
    piVar25[0x12] = DAT_ffffffffbfc436f4 + 0xb60;
    goto LAB_ffffffffbfc1ec44;
  }
  iVar8 = iVar8 + 1;
  iVar12 = iVar12 + 0x20;
  *(undefined4 *)((long)piVar16 + -4) = *puVar17;
  goto LAB_ffffffffbfc1eb1c;
code_r0xffffffffbfc1eab0:
  *(undefined4 *)((long)(iVar26 + iVar7 * 4) + 0x50) = 0;
  *piVar25 = 0;
LAB_ffffffffbfc1eb2c:
  if ((((iVar7 < 2) && (cVar21 != '\0')) && (cVar21 != ' ')) &&
     (iVar12 = piVar25[0x14], cVar21 != '\t')) {
    lVar6 = (*(code *)(long)DAT_ffffffffbfc43798)(iVar12,0x2e);
    if (lVar6 == 0) {
      iVar20 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar12);
    }
    else {
      iVar20 = (int)lVar6 - iVar12;
    }
    iVar8 = 0;
    iVar13 = DAT_ffffffffbfc4404c;
    while( true ) {
      puVar23 = (undefined4 *)(long)iVar13;
      if (puVar23 == (undefined4 *)(long)DAT_ffffffffbfc43b1c) break;
      iVar9 = (*(code *)(long)DAT_ffffffffbfc437c8)(*puVar23);
      if (iVar20 <= iVar9) {
        lVar6 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar12,*puVar23,iVar20);
        bVar1 = 0x11 < iVar8;
        if (lVar6 == 0) {
          iVar9 = iVar8 * 4;
          iVar8 = iVar8 + 1;
          if (bVar1) {
            *(int *)(long)(iVar9 + iVar26) = DAT_ffffffffbfc436f4 + 0xb60;
            break;
          }
          *(undefined4 *)(long)(iVar9 + iVar26) = *puVar23;
        }
      }
      iVar13 = iVar13 + 0x20;
    }
LAB_ffffffffbfc1ec44:
    *(undefined4 *)(long)(iVar8 * 4 + iVar26) = 0;
LAB_ffffffffbfc1ec48:
    if (iVar8 != 0) {
      if (iVar8 == 1) {
        iVar7 = (*(code *)(long)DAT_ffffffffbfc437c8)
                          (*(undefined4 *)((long)(iVar7 * 4 + iVar26) + 0x4c));
        puVar22 = (undefined1 *)(long)(iVar7 + *piVar25);
        iVar8 = (*(code *)(long)DAT_ffffffffbfc437c8)(puVar22);
        iVar18 = 1;
        iVar26 = DAT_ffffffffbfc436f4 + -0x3e70;
LAB_ffffffffbfc1ed44:
        iVar7 = piVar25[0x58];
        if (puVar22 != (undefined1 *)0x0) {
          iVar20 = iVar8 + iVar18;
          iVar12 = (int)param_2 + (int)lVar4;
          if (iVar7 + iVar20 < 0xfe) {
            iVar13 = 0;
            while( true ) {
              puVar19 = (undefined1 *)(long)iVar12;
              bVar1 = iVar8 <= iVar13;
              iVar13 = iVar13 + 1;
              if (bVar1) break;
              uVar3 = *puVar22;
              puVar22 = (undefined1 *)(long)((int)puVar22 + 1);
              *puVar19 = uVar3;
              iVar12 = iVar12 + 1;
            }
            iVar8 = 0;
            if (iVar26 == 0) {
              pcVar24 = (code *)(long)DAT_ffffffffbfc43e38;
              *puVar19 = 0;
              (*pcVar24)(iVar12 - iVar20);
              iVar18 = 7;
              iVar12 = DAT_ffffffffbfc439f0;
            }
            else {
              bVar1 = iVar18 != 0;
              while( true ) {
                iVar12 = DAT_ffffffffbfc43e38;
                iVar13 = iVar26 + iVar8;
                if (!bVar1) break;
                iVar8 = iVar8 + 1;
                *puVar19 = *(undefined1 *)(long)iVar13;
                puVar19 = (undefined1 *)(long)((int)puVar19 + 1);
                bVar1 = iVar8 < iVar18;
              }
              iVar18 = (int)puVar19 - iVar20;
              *puVar19 = 0;
            }
            (*(code *)(long)iVar12)(iVar18);
            iVar18 = piVar25[0x5a];
            *(int *)(long)piVar25[0x59] = iVar7 + iVar20;
            *(int *)(long)iVar18 = iVar10 + iVar20;
            return 1;
          }
          pcVar24 = (code *)(long)DAT_ffffffffbfc439f0;
          param_2 = (char *)0x7;
          goto LAB_ffffffffbfc1eec0;
        }
      }
      else {
        iVar12 = *piVar25;
        pcVar14 = (char *)(long)iVar12;
        if ((1 < iVar8) && (pcVar14 != (char *)0x0)) {
          iVar8 = (*(code *)(long)DAT_ffffffffbfc437c8)(pcVar14);
          iVar18 = iVar18 + -0x1cc;
          while( true ) {
            pcVar15 = (char *)(long)*(int *)(long)iVar18;
            iVar18 = iVar18 + 4;
            if (pcVar15 == (char *)0x0) break;
            iVar20 = 0;
            pcVar5 = pcVar14;
            while( true ) {
              bVar1 = iVar8 <= iVar20;
              iVar20 = iVar20 + 1;
              if ((bVar1) ||
                 (cVar21 = *pcVar15, pcVar15 = (char *)(long)((int)pcVar15 + 1), cVar21 != *pcVar5))
              break;
              pcVar5 = (char *)(long)((int)pcVar5 + 1);
            }
            iVar8 = (int)pcVar5 - iVar12;
          }
          if (iVar8 != 0) {
            iVar7 = (*(code *)(long)DAT_ffffffffbfc437c8)
                              (*(undefined4 *)((long)(iVar7 * 4 + iVar26) + 0x4c));
            iVar8 = iVar8 - iVar7;
            if (0 < iVar8) {
              iVar26 = 0;
              iVar18 = 0;
              puVar22 = (undefined1 *)(long)(iVar7 + *piVar25);
              goto LAB_ffffffffbfc1ed44;
            }
          }
        }
      }
      iVar18 = 0x4e;
      iVar10 = (*(code *)(long)DAT_ffffffffbfc437c8)(DAT_ffffffffbfc436f4 + 0xb68);
      iVar7 = (*(code *)(long)DAT_ffffffffbfc437c8)(DAT_ffffffffbfc436f4 + -0x3e70);
      for (; *piVar25 != 0; piVar25 = (int *)(long)((int)piVar25 + 4)) {
        iVar26 = (*(code *)(long)DAT_ffffffffbfc437c8)();
        pcVar24 = (code *)(long)DAT_ffffffffbfc43e38;
        if (iVar18 + iVar26 + iVar7 < 0x4e) {
          iVar12 = DAT_ffffffffbfc436f4 + -0x3e70;
        }
        else {
          iVar18 = iVar10 - iVar7;
          (*pcVar24)(DAT_ffffffffbfc436f4 + 0x1150);
          pcVar24 = (code *)(long)DAT_ffffffffbfc43e38;
          iVar12 = DAT_ffffffffbfc436f4 + 0xb68;
        }
        iVar18 = iVar18 + iVar26 + iVar7;
        (*pcVar24)(iVar12);
        (*(code *)(long)DAT_ffffffffbfc43e38)(*piVar25);
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
      (*(code *)(long)DAT_ffffffffbfc43e38)(param_1);
      pcVar24 = (code *)(long)DAT_ffffffffbfc43e38;
      goto LAB_ffffffffbfc1eec0;
    }
  }
  else {
    lVar6 = (*(code *)(long)DAT_ffffffffbfc43be8)(piVar25[0x14]);
    if ((lVar6 != 0) && ((code *)(long)*(int *)(lVar6 + 0x18) != (code *)0x0)) {
      iVar8 = (*(code *)(long)*(int *)(lVar6 + 0x18))(iVar7,iVar18 + -0x180,cVar21,0x14,piVar25);
      goto LAB_ffffffffbfc1ec48;
    }
    *piVar25 = 0;
  }
  pcVar24 = (code *)(long)DAT_ffffffffbfc439f0;
  if (1 < iVar7) {
    return 0;
  }
  param_2 = (char *)0x7;
LAB_ffffffffbfc1eec0:
  (*pcVar24)(param_2);
  return 1;
}

