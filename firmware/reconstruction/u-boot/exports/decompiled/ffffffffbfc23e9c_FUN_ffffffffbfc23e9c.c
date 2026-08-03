/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc23e9c
 * Function: FUN_ffffffffbfc23e9c
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

int FUN_ffffffffbfc23e9c(char *param_1,undefined4 param_2,ulong *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar4;
  char cVar8;
  char *pcVar9;
  long lVar10;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar11;
  undefined8 unaff_s2;
  int iVar13;
  ulong *puVar12;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  ulong uVar14;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  ulong uVar15;
  ulong uVar16;
  undefined8 unaff_s7;
  int *piVar17;
  undefined8 in_ra;
  
  piVar17 = (int *)(long)((int)&stack0x00000000 + -0x60);
  *(undefined1 **)(piVar17 + 0x14) = &_gp;
  *(undefined8 *)(piVar17 + 0x12) = unaff_s7;
  *(undefined8 *)(piVar17 + 0x10) = unaff_s6;
  *(undefined8 *)(piVar17 + 8) = unaff_s2;
  *(undefined8 *)(piVar17 + 6) = unaff_s1;
  *(undefined8 *)(piVar17 + 0x16) = in_ra;
  *(undefined8 *)(piVar17 + 0xe) = unaff_s5;
  uVar15 = 0;
  *(undefined8 *)(piVar17 + 0xc) = unaff_s4;
  *(undefined8 *)(piVar17 + 10) = unaff_s3;
  *(undefined8 *)(piVar17 + 4) = unaff_s0;
  *piVar17 = param_2;
  pcVar4 = param_1;
  while( true ) {
    cVar8 = *(char *)(long)*piVar17;
    iVar7 = (int)pcVar4;
    if (cVar8 == '\0') {
      *pcVar4 = '\0';
      return iVar7 - (int)param_1;
    }
    uVar14 = 0;
    if (cVar8 == '%') break;
LAB_ffffffffbfc24278:
    *pcVar4 = cVar8;
    pcVar4 = (char *)(long)((int)pcVar4 + 1);
LAB_ffffffffbfc2436c:
    *piVar17 = *piVar17 + 1;
  }
LAB_ffffffffbfc23ef4:
  do {
    lVar3 = (long)*piVar17;
    while( true ) {
      *piVar17 = (int)lVar3 + 1;
      cVar8 = *(char *)(lVar3 + 1);
      if (cVar8 == '+') break;
      if (cVar8 < ',') {
        if (cVar8 == ' ') {
          uVar14 = uVar14 | 8;
          goto LAB_ffffffffbfc23ef4;
        }
        if (cVar8 != '#') {
LAB_ffffffffbfc23f74:
          if ((byte)(cVar8 - 0x30U) < 10) {
            iVar5 = (*(code *)(long)(DAT_ffffffffbfc43700 + 0x3bc0))(piVar17);
          }
          else {
            iVar5 = -1;
            if (cVar8 == '*') {
              iVar5 = (int)*param_3;
              *piVar17 = (int)lVar3 + 2;
              param_3 = (ulong *)(long)((int)param_3 + 8);
              if (iVar5 < 0) {
                iVar5 = -iVar5;
                uVar14 = uVar14 | 0x10;
              }
            }
          }
          iVar13 = *piVar17;
          pcVar9 = (char *)(long)iVar13;
          iVar6 = -1;
          if (*pcVar9 == '.') {
            *piVar17 = iVar13 + 1;
            if ((byte)(pcVar9[1] - 0x30U) < 10) {
              iVar6 = (*(code *)(long)(DAT_ffffffffbfc43700 + 0x3bc0))(piVar17);
LAB_ffffffffbfc2402c:
              pcVar9 = (char *)(long)*piVar17;
              if (-1 < iVar6) goto LAB_ffffffffbfc2403c;
            }
            else if (pcVar9[1] == '*') {
              iVar6 = (int)*param_3;
              *piVar17 = iVar13 + 2;
              param_3 = (ulong *)(long)((int)param_3 + 8);
              goto LAB_ffffffffbfc2402c;
            }
            iVar6 = 0;
            pcVar9 = (char *)(long)*piVar17;
          }
LAB_ffffffffbfc2403c:
          lVar3 = (long)*pcVar9;
          if (((lVar3 == 0x68) || (lVar3 == 0x6c)) || (lVar3 == 0x71)) {
            *piVar17 = (int)pcVar9 + 1;
          }
          else {
            lVar3 = -1;
          }
          cVar8 = *(char *)(long)*piVar17;
          iVar13 = (int)param_3;
          if (cVar8 == 'n') {
            uVar14 = *param_3;
            param_3 = (ulong *)(long)(iVar13 + 8);
            *(int *)(long)(int)uVar14 = iVar7 - (int)param_1;
            goto LAB_ffffffffbfc2436c;
          }
          if (cVar8 < 'o') {
            if (cVar8 == 'c') {
              setCopReg(2,lVar3,*(undefined4 *)(uVar14 + 5));
              *pcVar4 = (char)(int)*param_3;
              while( true ) {
                iVar5 = iVar5 + -1;
                pcVar4 = (char *)(long)((int)pcVar4 + 1);
                if (iVar5 < 1) break;
                *pcVar4 = ' ';
              }
              param_3 = (ulong *)(long)(iVar13 + 8);
              goto LAB_ffffffffbfc2436c;
            }
            if ('c' < cVar8) {
              if (cVar8 == 'd') {
                uVar14 = uVar14 | 2;
              }
              else {
                if (cVar8 != 'i') goto LAB_ffffffffbfc24264;
                uVar14 = uVar14 | 2;
              }
LAB_ffffffffbfc24290:
              lVar10 = 10;
              goto LAB_ffffffffbfc24294;
            }
            if (cVar8 == '%') goto LAB_ffffffffbfc24278;
            if (cVar8 == 'X') {
              uVar14 = uVar14 | 0x40;
              lVar10 = 0x10;
              goto LAB_ffffffffbfc24294;
            }
LAB_ffffffffbfc24264:
            *pcVar4 = '%';
            cVar8 = *(char *)(long)*piVar17;
            pcVar4 = (char *)(long)(iVar7 + 1);
            if (cVar8 != '\0') goto LAB_ffffffffbfc24278;
            *piVar17 = *piVar17 + -1;
          }
          else if (cVar8 == 's') {
            pcVar9 = (char *)(long)(int)*param_3;
            if (pcVar9 == (char *)0x0) {
              pcVar9 = (char *)(long)(DAT_ffffffffbfc436f4 + 0x12d8);
            }
            iVar7 = (*(code *)(long)DAT_ffffffffbfc43ce4)(pcVar9,iVar6);
            uVar2 = getCopReg(2,4);
            *(undefined4 *)(uVar14 + 10) = uVar2;
            while (bVar1 = iVar7 < iVar5, iVar5 = iVar5 + -1, bVar1) {
              *pcVar4 = ' ';
              pcVar4 = (char *)(long)((int)pcVar4 + 1);
            }
            iVar6 = 0;
            while (bVar1 = iVar6 < iVar7, iVar6 = iVar6 + 1, bVar1) {
              cVar8 = *pcVar9;
              pcVar9 = (char *)(long)((int)pcVar9 + 1);
              *pcVar4 = cVar8;
              pcVar4 = (char *)(long)((int)pcVar4 + 1);
            }
            while (bVar1 = iVar7 < iVar5, iVar5 = iVar5 + -1, bVar1) {
              *pcVar4 = ' ';
              pcVar4 = (char *)(long)((int)pcVar4 + 1);
            }
            param_3 = (ulong *)(long)(iVar13 + 8);
          }
          else {
            if (cVar8 < 't') {
              if (cVar8 == 'o') {
                lVar10 = 8;
                goto LAB_ffffffffbfc24294;
              }
              if (cVar8 != 'p') goto LAB_ffffffffbfc24264;
              if (iVar5 == -1) {
                uVar14 = uVar14 | 1;
                iVar5 = 8;
              }
              uVar16 = (ulong)(uint)*param_3;
              puVar12 = (ulong *)(long)(iVar13 + 8);
              lVar10 = 0x10;
LAB_ffffffffbfc243a8:
              pcVar11 = (code *)(long)(DAT_ffffffffbfc43700 + 0x3c08);
              param_3 = puVar12;
            }
            else {
              if (cVar8 == 'u') goto LAB_ffffffffbfc24290;
              if (cVar8 != 'x') goto LAB_ffffffffbfc24264;
              lVar10 = 0x10;
LAB_ffffffffbfc24294:
              if (lVar3 != 0x71) {
                if (lVar3 == 0x6c) {
                  uVar16 = (ulong)(uint)*param_3;
                  puVar12 = (ulong *)(long)(iVar13 + 8);
                  uVar15 = uVar16;
                }
                else if (lVar3 == 0x68) {
                  uVar16 = (ulong)(ushort)*param_3;
                  puVar12 = (ulong *)(long)(iVar13 + 8);
                  uVar15 = uVar16;
                  if ((uVar14 & 2) != 0) {
                    special2(uVar16,uVar16,0,0x3a);
                  }
                }
                else {
                  puVar12 = (ulong *)(long)(iVar13 + 8);
                  if ((uVar14 & 2) == 0) {
                    uVar16 = (ulong)(uint)*param_3;
                    uVar15 = uVar16;
                  }
                  else {
                    uVar16 = (ulong)(int)*param_3;
                    uVar15 = uVar16;
                  }
                }
                goto LAB_ffffffffbfc243a8;
              }
              if (lVar10 == 0x10) {
                uVar15 = *param_3;
                uVar14 = uVar14 | 1;
                pcVar11 = (code *)(long)(DAT_ffffffffbfc43700 + 0x3c08);
                pcVar4 = (char *)(*pcVar11)(pcVar4,uVar15 >> 0x20,0x10,8,iVar6,uVar14);
                lVar10 = 0x10;
                iVar5 = 8;
                uVar16 = uVar15 & 0xffffffff;
                param_3 = (ulong *)(long)(iVar13 + 8);
              }
              else {
                pcVar11 = (code *)(long)(DAT_ffffffffbfc43700 + 0x3c08);
                uVar16 = uVar15;
              }
            }
            pcVar4 = (char *)(*pcVar11)(pcVar4,uVar16,lVar10,iVar5,iVar6,uVar14);
          }
          goto LAB_ffffffffbfc2436c;
        }
        uVar14 = uVar14 | 0x20;
        lVar3 = (long)*piVar17;
      }
      else {
        if (cVar8 == '-') {
          uVar14 = uVar14 | 0x10;
          goto LAB_ffffffffbfc23ef4;
        }
        if (cVar8 != '0') goto LAB_ffffffffbfc23f74;
        uVar14 = uVar14 | 1;
        lVar3 = (long)*piVar17;
      }
    }
    uVar14 = uVar14 | 4;
  } while( true );
}

