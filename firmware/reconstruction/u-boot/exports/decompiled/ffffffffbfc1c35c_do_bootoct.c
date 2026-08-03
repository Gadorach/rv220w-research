/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1c35c
 * Function: do_bootoct
 * Subsystem: u-boot-command
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
 * 
 * Recovered from U-Boot command table: command='bootoct', maxargs=128, repeatable=0, usage=''.
 */

/* WARNING: Removing unreachable block (ram,0xffffffffbfc1cdc0) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1ce0c) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1ce1c) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1cde0) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1cdfc) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1ce00) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1ce04) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc1ce08) */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: u-boot-command
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='bootoct', maxargs=128, repeatable=0, usage=''. */

undefined4 do_bootoct(undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  bool bVar5;
  int iVar8;
  char cVar13;
  undefined4 uVar9;
  ulong uVar6;
  int iVar10;
  uint uVar11;
  long lVar7;
  int iVar12;
  int iVar14;
  int iVar16;
  int iVar17;
  char cVar18;
  char *pcVar15;
  int iVar20;
  char *pcVar19;
  undefined8 unaff_s0;
  ulong uVar21;
  undefined8 unaff_s1;
  long lVar22;
  long lVar23;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  uint uVar24;
  undefined8 unaff_s4;
  undefined8 uVar25;
  ulong uVar26;
  undefined8 unaff_s5;
  uint uVar27;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  int *piVar28;
  code *pcVar29;
  long lVar30;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  iVar17 = (int)&stack0x00000000;
  lVar30 = (long)(iVar17 + -0x510);
  *(undefined1 **)(lVar30 + 0x4f0) = &_gp;
  *(undefined8 *)(lVar30 + 0x500) = in_ra;
  *(undefined8 *)(lVar30 + 0x4f8) = unaff_s8;
  *(undefined8 *)(lVar30 + 0x4e8) = unaff_s7;
  *(undefined8 *)(lVar30 + 0x4e0) = unaff_s6;
  *(undefined8 *)(lVar30 + 0x4d8) = unaff_s5;
  *(undefined8 *)(lVar30 + 0x4d0) = unaff_s4;
  *(undefined8 *)(lVar30 + 0x4c8) = unaff_s3;
  *(undefined8 *)(lVar30 + 0x4c0) = unaff_s2;
  *(undefined8 *)(lVar30 + 0x4b8) = unaff_s1;
  *(undefined8 *)(lVar30 + 0x4b0) = unaff_s0;
  *(int *)(lVar30 + 0x49c) = (int)param_3;
  *(undefined4 *)(lVar30 + 0x4a0) = param_4;
  if ((param_3 < 2) ||
     (piVar28 = (int *)(*(code *)(long)DAT_ffffffffbfc438b0)
                                 (*(undefined4 *)((long)*(int *)(lVar30 + 0x4a0) + 4),0,0x10),
     piVar28 == (int *)0x0)) {
    piVar28 = (int *)(long)*(int *)(long)DAT_ffffffffbfc43d48;
  }
  lVar22 = (long)(*(int *)(lVar30 + 0x4a0) + *(int *)(lVar30 + 0x49c) * 4);
  iVar12 = *(int *)(lVar22 + -4);
  iVar8 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar12);
  if (*(char *)((long)(iVar12 + iVar8) + -1) == '\n') {
    iVar12 = *(int *)(lVar22 + -4);
    iVar8 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar12);
    *(undefined1 *)((long)(iVar12 + iVar8) + -1) = 0;
  }
  iVar12 = *(int *)(lVar30 + 0x4a0);
  uVar21 = 1;
  *(undefined4 *)(lVar30 + 0x498) = 0x100000;
  iVar8 = 2;
  *(undefined4 *)(lVar30 + 0x494) = 0x300000;
  lVar22 = 0;
  uVar25 = 0;
LAB_ffffffffbfc1c828:
  lVar23 = (long)iVar12;
  if (*(int *)(lVar30 + 0x49c) <= iVar8) goto code_r0xffffffffbfc1c838;
  iVar14 = 6;
  iVar16 = *(int *)(lVar23 + 8);
  pcVar15 = (char *)(long)iVar16;
  iVar10 = DAT_ffffffffbfc436f4 + -0xd10;
  pcVar19 = pcVar15;
  while( true ) {
    cVar1 = *pcVar19;
    cVar2 = *(char *)(long)iVar10;
    cVar13 = cVar2;
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    pcVar19 = (char *)(long)((int)pcVar19 + 1);
    cVar13 = cVar1;
    if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
  }
  if (cVar13 == cVar2) {
    uVar9 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar16 + 6,0,0);
    *(undefined4 *)(lVar30 + 0x498) = uVar9;
  }
  else {
    iVar20 = 5;
    iVar14 = 5;
    iVar10 = DAT_ffffffffbfc436f4 + -0xd08;
    pcVar19 = pcVar15;
    while( true ) {
      cVar1 = *pcVar19;
      cVar2 = *(char *)(long)iVar10;
      cVar13 = cVar2;
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      pcVar19 = (char *)(long)((int)pcVar19 + 1);
      cVar13 = cVar1;
      if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
    }
    if (cVar13 == cVar2) {
      uVar9 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar16 + 5,0,0);
      *(undefined4 *)(lVar30 + 0x494) = uVar9;
    }
    else {
      iVar14 = 5;
      iVar10 = DAT_ffffffffbfc436f4 + -0xd00;
      pcVar19 = pcVar15;
      while( true ) {
        cVar1 = *pcVar19;
        cVar2 = *(char *)(long)iVar10;
        cVar13 = cVar2;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar19 = (char *)(long)((int)pcVar19 + 1);
        cVar13 = cVar1;
        if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar13 == cVar2) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0xcf8);
        iVar16 = *(int *)(lVar23 + 8);
        *(uint *)(long)DAT_ffffffffbfc43860 = *(uint *)(long)DAT_ffffffffbfc43860 | 2;
        if (*(char *)((long)iVar16 + 5) == '=') {
          lVar23 = (long)*(char *)((long)iVar16 + 6);
          special2(lVar23,lVar23,0x10,0x2f);
          (*(code *)(long)DAT_ffffffffbfc43954)(lVar23);
        }
      }
      else {
        iVar10 = DAT_ffffffffbfc436f4 + -0xce0;
        pcVar19 = pcVar15;
        while( true ) {
          cVar1 = *pcVar19;
          cVar2 = *(char *)(long)iVar10;
          cVar13 = cVar2;
          if (iVar20 == 0) break;
          iVar20 = iVar20 + -1;
          pcVar19 = (char *)(long)((int)pcVar19 + 1);
          cVar13 = cVar1;
          if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
        }
        if (cVar13 == cVar2) {
          *(uint *)(long)DAT_ffffffffbfc43860 = *(uint *)(long)DAT_ffffffffbfc43860 | 0x20;
        }
        else {
          iVar14 = 0xb;
          iVar10 = DAT_ffffffffbfc436f4 + -0xcd8;
          pcVar19 = pcVar15;
          while( true ) {
            cVar1 = *pcVar19;
            cVar2 = *(char *)(long)iVar10;
            cVar13 = cVar2;
            if (iVar14 == 0) break;
            iVar14 = iVar14 + -1;
            pcVar19 = (char *)(long)((int)pcVar19 + 1);
            cVar13 = cVar1;
            if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
          }
          if (cVar13 == cVar2) {
            iVar16 = iVar16 + 9;
          }
          else {
            iVar20 = 9;
            iVar14 = 9;
            iVar10 = DAT_ffffffffbfc436f4 + -0xcc8;
            pcVar19 = pcVar15;
            while( true ) {
              cVar1 = *pcVar19;
              cVar2 = *(char *)(long)iVar10;
              cVar13 = cVar2;
              if (iVar14 == 0) break;
              iVar14 = iVar14 + -1;
              pcVar19 = (char *)(long)((int)pcVar19 + 1);
              cVar13 = cVar1;
              if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
            }
            if (cVar13 != cVar2) {
              iVar14 = 9;
              iVar10 = DAT_ffffffffbfc436f4 + -0xcb8;
              pcVar19 = pcVar15;
              while( true ) {
                cVar1 = *pcVar19;
                cVar2 = *(char *)(long)iVar10;
                cVar13 = cVar2;
                if (iVar14 == 0) break;
                iVar14 = iVar14 + -1;
                pcVar19 = (char *)(long)((int)pcVar19 + 1);
                cVar13 = cVar1;
                if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0')) break;
              }
              if (cVar13 == cVar2) {
                *(undefined4 *)(long)DAT_ffffffffbfc43bc8 = 1;
              }
              else {
                iVar10 = DAT_ffffffffbfc436f4 + -0xca8;
                pcVar19 = pcVar15;
                while( true ) {
                  cVar1 = *pcVar19;
                  cVar2 = *(char *)(long)iVar10;
                  cVar13 = cVar2;
                  if (iVar20 == 0) break;
                  iVar20 = iVar20 + -1;
                  pcVar19 = (char *)(long)((int)pcVar19 + 1);
                  cVar13 = cVar1;
                  if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0'))
                  break;
                }
                if (cVar13 == cVar2) {
                  lVar22 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar16 + 9,0,0);
                }
                else {
                  iVar14 = 10;
                  iVar10 = DAT_ffffffffbfc436f4 + -0xc98;
                  pcVar19 = pcVar15;
                  while( true ) {
                    cVar1 = *pcVar19;
                    cVar2 = *(char *)(long)iVar10;
                    cVar13 = cVar2;
                    if (iVar14 == 0) break;
                    iVar14 = iVar14 + -1;
                    pcVar19 = (char *)(long)((int)pcVar19 + 1);
                    cVar13 = cVar1;
                    if ((cVar2 != cVar1) || (iVar10 = iVar10 + 1, cVar13 = cVar2, cVar1 == '\0'))
                    break;
                  }
                  if (cVar13 != cVar2) {
                    iVar10 = 0xc;
                    iVar16 = DAT_ffffffffbfc436f4 + -0xc88;
                    while( true ) {
                      cVar1 = *pcVar15;
                      cVar2 = *(char *)(long)iVar16;
                      cVar13 = cVar2;
                      if (iVar10 == 0) break;
                      iVar10 = iVar10 + -1;
                      pcVar15 = (char *)(long)((int)pcVar15 + 1);
                      cVar13 = cVar1;
                      if ((cVar2 != cVar1) || (iVar16 = iVar16 + 1, cVar13 = cVar2, cVar1 == '\0'))
                      break;
                    }
                    if (cVar13 != cVar2) goto LAB_ffffffffbfc1c824;
                    *(int *)(lVar30 + 0x490) = iVar8 + 1;
                    goto LAB_ffffffffbfc1c83c;
                  }
                  uVar25 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar16 + 10,0,0);
                }
              }
              goto LAB_ffffffffbfc1c824;
            }
            pcVar29 = (code *)(long)DAT_ffffffffbfc43a54;
            iVar16 = iVar17 + -0x4fc;
            uVar3 = *(undefined2 *)((long)DAT_ffffffffbfc436f0 + 0x64b0);
            *(undefined1 *)(lVar30 + 0x16) =
                 *(undefined1 *)((long)(DAT_ffffffffbfc436f0 + 0x64b0) + 2);
            *(undefined2 *)(lVar30 + 0x14) = uVar3;
            (*pcVar29)(iVar17 + -0x4f9,0,0x11);
            (*(code *)(long)DAT_ffffffffbfc43a9c)(iVar16,*(int *)(lVar23 + 8) + 9,10);
          }
          uVar21 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar16,0,0);
        }
      }
    }
  }
LAB_ffffffffbfc1c824:
  iVar8 = iVar8 + 1;
  iVar12 = iVar12 + 4;
  goto LAB_ffffffffbfc1c828;
code_r0xffffffffbfc1c838:
  *(undefined4 *)(lVar30 + 0x490) = 0;
LAB_ffffffffbfc1c83c:
  if (lVar22 != 0) {
    uVar21 = (*(code *)(long)DAT_ffffffffbfc43ee0)((int)lVar22 + (int)uVar25);
    uVar6 = (*(code *)(long)DAT_ffffffffbfc43ee0)(uVar25);
    uVar21 = uVar21 & ~uVar6;
  }
  uVar21 = (*(code *)(long)DAT_ffffffffbfc43d28)(uVar21);
  if (uVar21 == 0) {
    iVar17 = DAT_ffffffffbfc436f4 + -0xc78;
    iVar12 = DAT_ffffffffbfc4400c;
LAB_ffffffffbfc1d4d4:
    (*(code *)(long)iVar12)(iVar17);
    return 0;
  }
  if ((long)uVar21 < 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0xc38);
    return 1;
  }
  lVar22 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0xcb8);
  if (lVar22 != 0) {
    *(uint *)(long)DAT_ffffffffbfc43bc8 = *(uint *)(long)DAT_ffffffffbfc43bc8 | 1;
  }
  pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
  if ((uVar21 & (long)*(int *)(long)DAT_ffffffffbfc43828) != 0) {
    iVar17 = DAT_ffffffffbfc436f4 + -0xc20;
    goto LAB_ffffffffbfc1d524;
  }
  (*pcVar29)(DAT_ffffffffbfc436f4 + -0xbc0,piVar28,uVar21,*(undefined4 *)(lVar30 + 0x498),
             *(undefined4 *)(lVar30 + 0x494));
  if (*(uint *)(lVar30 + 0x494) < 400) {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0xb48,*(uint *)(lVar30 + 0x494),400);
  }
  else {
    if (*piVar28 == 0x7f454c46) {
      cVar1 = *(char *)(piVar28 + 1);
      if ((byte)(cVar1 - 1U) < 2) {
        if (*(char *)((long)piVar28 + 5) == '\x02') {
          if (*(short *)(piVar28 + 4) == 2) {
            if ((ushort)(*(short *)((long)piVar28 + 0x12) - 8U) < 2) {
              if (cVar1 == '\x01') {
                (*(code *)(long)DAT_ffffffffbfc43e84)(iVar17 + -0x4a0,piVar28,0x34);
                uVar4 = *(ushort *)(lVar30 + 0xa0);
              }
              else {
                (*(code *)(long)DAT_ffffffffbfc43950)(iVar17 + -0x4a0,piVar28);
                uVar4 = *(ushort *)(lVar30 + 0xa0);
              }
              iVar12 = 0;
              while( true ) {
                iVar8 = ((uint)uVar4 - iVar12) + -1;
                if (iVar8 < 0) break;
                iVar16 = (int)piVar28;
                if (cVar1 == '\x01') {
                  (*(code *)(long)DAT_ffffffffbfc43e84)
                            (iVar17 + -0x4c8,
                             (uint)*(ushort *)(lVar30 + 0x9e) * iVar8 +
                             iVar16 + *(int *)(lVar30 + 0x90));
                  iVar8 = *(int *)(lVar30 + 0x4c);
                }
                else {
                  (*(code *)(long)DAT_ffffffffbfc4396c)
                            (iVar17 + -0x4c8,
                             (uint)*(ushort *)(lVar30 + 0x9e) * iVar8 +
                             iVar16 + *(int *)(lVar30 + 0x90),0x28);
                  iVar8 = *(int *)(lVar30 + 0x4c);
                }
                if (iVar8 == 3) {
                  iVar8 = *(int *)(lVar30 + 0x58);
                  iVar20 = 200;
                  uVar24 = *(uint *)(lVar30 + 0x5c);
                  iVar14 = DAT_ffffffffbfc436f4 + -0xa28;
                  iVar10 = iVar16 + iVar8 + *(int *)(lVar30 + 0x48);
                  while( true ) {
                    cVar2 = *(char *)(long)iVar14;
                    cVar13 = *(char *)(long)iVar10;
                    cVar18 = cVar13;
                    if (iVar20 == 0) break;
                    iVar20 = iVar20 + -1;
                    iVar14 = iVar14 + 1;
                    cVar18 = cVar2;
                    if ((cVar13 != cVar2) || (iVar10 = iVar10 + 1, cVar18 = cVar13, cVar2 == '\0'))
                    break;
                  }
                  if (cVar18 == cVar13) {
                    iVar12 = 0;
                    uVar27 = 0;
                    goto LAB_ffffffffbfc1cbd8;
                  }
                }
                iVar12 = iVar12 + 1;
              }
              pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
              iVar17 = DAT_ffffffffbfc436f4 + -2000;
            }
            else {
              pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
              iVar17 = DAT_ffffffffbfc436f4 + -0xa60;
            }
          }
          else {
            pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
            iVar17 = DAT_ffffffffbfc436f4 + -0xa80;
          }
        }
        else {
          pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
          iVar17 = DAT_ffffffffbfc436f4 + -0xaa0;
        }
      }
      else {
        pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
        iVar17 = DAT_ffffffffbfc436f4 + -0xac8;
      }
    }
    else {
      pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
      iVar17 = DAT_ffffffffbfc436f4 + -0xae8;
    }
LAB_ffffffffbfc1d510:
    (*pcVar29)(iVar17);
  }
  goto LAB_ffffffffbfc1d51c;
LAB_ffffffffbfc1cbd8:
  if ((int)(uint)*(ushort *)(lVar30 + 0xa0) <= iVar12) goto code_r0xffffffffbfc1cbfc;
  if (cVar1 == '\x01') {
    (*(code *)(long)DAT_ffffffffbfc43e84)
              (iVar17 + -0x4c8,
               (uint)*(ushort *)(lVar30 + 0x9e) * iVar12 + iVar16 + *(int *)(lVar30 + 0x90));
    uVar11 = *(uint *)(lVar30 + 0x48);
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4396c)
              (iVar17 + -0x4c8,
               (uint)*(ushort *)(lVar30 + 0x9e) * iVar12 + iVar16 + *(int *)(lVar30 + 0x90),0x28);
    uVar11 = *(uint *)(lVar30 + 0x48);
  }
  pcVar19 = (char *)(long)(int)(iVar16 + iVar8 + uVar11);
  if (uVar11 < uVar24) {
    iVar10 = DAT_ffffffffbfc436f4 + -0xa18;
    cVar2 = *pcVar19;
    pcVar15 = pcVar19;
    do {
      cVar13 = *(char *)(long)iVar10;
      pcVar15 = (char *)(long)((int)pcVar15 + 1);
      iVar10 = iVar10 + 1;
      cVar18 = cVar2;
      if (cVar13 != cVar2) break;
      bVar5 = cVar2 != '\0';
      cVar2 = *pcVar15;
      cVar18 = cVar13;
    } while (bVar5);
    iVar10 = 0xc;
    if (cVar18 == cVar13) {
      pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
      iVar17 = DAT_ffffffffbfc436f4 + -0xa08;
      goto LAB_ffffffffbfc1d510;
    }
    iVar14 = DAT_ffffffffbfc436f4 + -0x9d8;
    while( true ) {
      cVar2 = *pcVar19;
      cVar13 = *(char *)(long)iVar14;
      cVar18 = cVar13;
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      pcVar19 = (char *)(long)((int)pcVar19 + 1);
      cVar18 = cVar2;
      if ((cVar13 != cVar2) || (iVar14 = iVar14 + 1, cVar18 = cVar13, cVar2 == '\0')) break;
    }
    if ((cVar18 == cVar13) && (uVar27 == 0)) {
      uVar27 = *(uint *)(lVar30 + 0x54);
    }
  }
  iVar12 = iVar12 + 1;
  goto LAB_ffffffffbfc1cbd8;
code_r0xffffffffbfc1cbfc:
  (*(code *)(long)DAT_ffffffffbfc43a54)(iVar17 + -0x46c,0,0x1e0);
  (*(code *)(long)DAT_ffffffffbfc43a54)(iVar17 + -0x28c,0,0x1e0);
  iVar10 = 0;
  *(undefined4 *)(lVar30 + 0x484) = 0;
  iVar8 = 0;
  *(undefined4 *)(lVar30 + 0x480) = 0;
  *(undefined4 *)(lVar30 + 0x47c) = 0;
  *(undefined4 *)(lVar30 + 0x478) = 0;
  for (iVar12 = 0; iVar12 < (int)(uint)*(ushort *)(lVar30 + 0x9c); iVar12 = iVar12 + 1) {
    if (cVar1 == '\x01') {
      (*(code *)(long)DAT_ffffffffbfc43e84)
                (iVar17 + -0x4e8,
                 (uint)*(ushort *)(lVar30 + 0x9a) * iVar12 + iVar16 + *(int *)(lVar30 + 0x8c),0x20);
      iVar14 = *(int *)(lVar30 + 0x28);
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc44080)
                (iVar17 + -0x4e8,
                 (uint)*(ushort *)(lVar30 + 0x9a) * iVar12 + iVar16 + *(int *)(lVar30 + 0x8c));
      iVar14 = *(int *)(lVar30 + 0x28);
    }
    iVar20 = *(int *)(lVar30 + 0x3c);
    if ((iVar14 == 1) && (uVar24 = *(uint *)(lVar30 + 0x30), iVar20 != 0)) {
      iVar14 = *(int *)(lVar30 + 0x40);
      if ((uVar27 < uVar24) || (iVar14 = *(int *)(lVar30 + 0x40), uVar24 + iVar20 < uVar27)) {
        uVar9 = getCopReg(2,1);
        *(undefined4 *)((long)iVar14 + 10) = uVar9;
        lVar22 = (long)(iVar8 + iVar17 + -0x500);
        iVar10 = iVar10 + 1;
        *(undefined4 *)(lVar22 + 0x9c) = *(undefined4 *)(lVar30 + 0x2c);
        iVar8 = iVar8 + 0x18;
        uVar9 = *(undefined4 *)(lVar30 + 0x38);
        *(int *)(lVar22 + 0x98) = iVar20;
        *(undefined4 *)(lVar22 + 0xa0) = uVar9;
        *(uint *)(lVar22 + 0x94) = uVar24;
      }
      else {
        *(int *)(lVar30 + 0x484) = iVar20;
        *(undefined4 *)(lVar30 + 0x478) = *(undefined4 *)(lVar30 + 0x2c);
        *(undefined4 *)(lVar30 + 0x47c) = *(undefined4 *)(lVar30 + 0x38);
        *(uint *)(lVar30 + 0x480) = uVar24;
      }
    }
  }
  uVar24 = *(uint *)(lVar30 + 0xa4);
  if (iVar10 == 0) {
    uVar6 = 0;
    uVar24 = 0;
  }
  else {
    iVar12 = 1;
    lVar22 = (long)(iVar17 + -0x454);
    uVar6 = (ulong)(uVar24 + *(int *)(lVar30 + 0xa8));
    while( true ) {
      bVar5 = iVar10 <= iVar12;
      lVar22 = (long)((int)lVar22 + 0x18);
      iVar12 = iVar12 + 1;
      if (bVar5) break;
      uVar27 = *(uint *)(lVar22 + -0x18);
      uVar26 = (ulong)(uVar27 + *(int *)(lVar22 + -0x14));
      if (uVar27 < uVar24) {
        uVar24 = uVar27;
      }
      if (uVar6 < uVar26) {
        uVar6 = uVar26;
      }
    }
    uVar6 = uVar6 - 1;
  }
  *(undefined8 *)(lVar30 + 0x488) = 0;
  *(undefined8 *)(lVar30 + 0x470) = 0;
  if ((uVar24 < 0x10000000) || (0x1fffffff < uVar6)) {
    lVar22 = 0x10;
  }
  else {
    lVar22 = 0;
  }
  iVar12 = 0;
  lVar23 = (*(code *)(long)DAT_ffffffffbfc44074)(uVar21);
  while (-1 < lVar23) {
    lVar7 = (*(code *)(long)DAT_ffffffffbfc43f14)();
    iVar8 = 0;
    if (lVar7 == lVar23) {
      iVar12 = (*(code *)(long)DAT_ffffffffbfc43f14)();
      iVar12 = (*(code *)(long)DAT_ffffffffbfc43fdc)
                         (iVar12 * 0x530 + DAT_ffffffffbfc43b88,uVar24,uVar6,0x1c,0,
                          DAT_ffffffffbfc43e50);
      if (iVar12 < 0) {
        pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
        iVar17 = DAT_ffffffffbfc436f4 + -0x9c8;
        goto LAB_ffffffffbfc1d510;
      }
    }
    else {
      for (; iVar8 <= iVar12; iVar8 = iVar8 + 1) {
        iVar10 = (*(code *)(long)DAT_ffffffffbfc43f14)();
        (*(code *)(long)DAT_ffffffffbfc43964)
                  ((int)lVar23 * 0x530 + DAT_ffffffffbfc43b88,
                   iVar10 * 0x530 + iVar8 * 0x28 + DAT_ffffffffbfc43b88);
      }
    }
    lVar23 = (*(code *)(long)DAT_ffffffffbfc43c20)();
  }
  lVar23 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x4a40))(0x70d0300);
  if (lVar23 == 0) {
    special2(0xffffffffffffffff,0,0x1e,0x33);
  }
  if ((*(uint *)(lVar30 + 0x480) < 0x10000000) ||
     (iVar8 = *(int *)(lVar30 + 0x484),
     0x1fffffff < (*(uint *)(lVar30 + 0x480) + *(int *)(lVar30 + 0x484)) - 1)) {
    lVar22 = 0x10;
    iVar8 = *(int *)(lVar30 + 0x484);
  }
  if (iVar8 != 0) {
    lVar23 = (*(code *)(long)DAT_ffffffffbfc44074)(uVar21);
    iVar8 = iVar12;
    while (-1 < lVar23) {
      lVar7 = (*(code *)(long)DAT_ffffffffbfc43f14)();
      iVar10 = iVar12;
      if (lVar7 == lVar23) {
        iVar8 = (*(code *)(long)DAT_ffffffffbfc43f14)();
        iVar8 = (*(code *)(long)DAT_ffffffffbfc43fdc)
                          (iVar8 * 0x530 + DAT_ffffffffbfc43b88,*(undefined4 *)(lVar30 + 0x480),
                           *(int *)(lVar30 + 0x480) + *(int *)(lVar30 + 0x484) + -1,0x1c,0,
                           DAT_ffffffffbfc43e50);
        if (iVar8 < 0) {
          pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
          iVar17 = DAT_ffffffffbfc436f4 + -0x9a0;
          goto LAB_ffffffffbfc1d510;
        }
      }
      else {
        while( true ) {
          iVar10 = iVar10 + 1;
          if (iVar8 < iVar10) break;
          iVar14 = (*(code *)(long)DAT_ffffffffbfc43f14)();
          (*(code *)(long)DAT_ffffffffbfc43964)
                    ((int)lVar23 * 0x530 + DAT_ffffffffbfc43b88,
                     iVar14 * 0x530 + iVar10 * 0x28 + DAT_ffffffffbfc43b88);
        }
      }
      lVar23 = (*(code *)(long)DAT_ffffffffbfc43c20)();
    }
  }
  lVar23 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x4a40))(0xd0000);
  if ((lVar23 == 0) &&
     (lVar23 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x970), lVar23 == 0)) {
    uVar25 = 0x3800000000000000;
  }
  else {
    uVar25 = 0;
  }
  if ((*(ulong *)(lVar30 + 0x488) < 0x10000000) || (0x1fffffff < *(ulong *)(lVar30 + 0x470))) {
    lVar22 = 0x10;
  }
  lVar23 = (*(code *)(long)DAT_ffffffffbfc44074)(uVar21);
  while( true ) {
    if (lVar23 < 0) break;
    lVar23 = (*(code *)(long)DAT_ffffffffbfc43fdc)
                       ((int)lVar23 * 0x530 + DAT_ffffffffbfc43b88,*(undefined8 *)(lVar30 + 0x488),
                        *(undefined8 *)(lVar30 + 0x470),0x1c,uVar25,DAT_ffffffffbfc43e50);
    if (lVar23 < 0) {
      pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
      iVar17 = DAT_ffffffffbfc436f4 + -0x958;
      goto LAB_ffffffffbfc1d510;
    }
    lVar23 = (*(code *)(long)DAT_ffffffffbfc43c20)();
  }
  uVar6 = (long)(*(int *)(lVar30 + 0x484) + *(int *)(lVar30 + 0x480) + 0x1ffffff) &
          0xfffffffffe000000;
  if ((uVar6 < 0x10000000) ||
     (0x1fffffff < (uint)((int)uVar6 + *(int *)(lVar30 + 0x498) + *(int *)(lVar30 + 0x494)))) {
    lVar22 = 0x10;
  }
  lVar23 = (*(code *)(long)DAT_ffffffffbfc44074)(uVar21);
  iVar12 = *(int *)(lVar30 + 0x498);
  while( true ) {
    if (lVar23 < 0) break;
    iVar12 = (*(code *)(long)DAT_ffffffffbfc43b28)
                       (uVar6 & 0xffffffff,(int)uVar6 + iVar12 + *(int *)(lVar30 + 0x494),1,
                        iVar17 + -0x500);
    if (iVar12 == 0) {
LAB_ffffffffbfc1d4f4:
      pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
      iVar17 = DAT_ffffffffbfc436f4 + -0x930;
      goto LAB_ffffffffbfc1d510;
    }
    uVar6 = uVar6 & (long)(int)(-1L << (long)(*(int *)(lVar30 + 0x10) + 1));
    lVar23 = (*(code *)(long)DAT_ffffffffbfc43fdc)
                       ((int)lVar23 * 0x530 + DAT_ffffffffbfc43b88,uVar6 & 0xffffffff,
                        (int)uVar6 + *(int *)(lVar30 + 0x498) + *(int *)(lVar30 + 0x494) + -1,0x1c,
                        uVar25,DAT_ffffffffbfc43e50);
    if (lVar23 < 0) goto LAB_ffffffffbfc1d4f4;
    lVar23 = (*(code *)(long)DAT_ffffffffbfc43c20)();
    iVar12 = *(int *)(lVar30 + 0x498);
  }
  piVar28 = (int *)(long)(iVar17 + -0x460);
  (*(code *)(long)DAT_ffffffffbfc44074)(uVar21);
  do {
    iVar8 = DAT_ffffffffbfc43b88;
    iVar12 = *piVar28;
    if (iVar12 != 0) {
      iVar14 = (*(code *)(long)DAT_ffffffffbfc43f14)();
      iVar10 = piVar28[-3];
      (*(code *)(long)DAT_ffffffffbfc43a18)
                (iVar14 * 0x530 + iVar8,iVar10,iVar16 + piVar28[-1],iVar12);
      iVar14 = (*(code *)(long)DAT_ffffffffbfc43f14)();
      (*(code *)(long)DAT_ffffffffbfc44054)
                (iVar14 * 0x530 + iVar8,iVar10 + iVar12,0,piVar28[-2] - iVar12);
    }
    iVar12 = DAT_ffffffffbfc43b88;
    piVar28 = (int *)(long)((int)piVar28 + 0x18);
  } while (piVar28 != (int *)(long)(iVar17 + -0x280));
  if (*(int *)(lVar30 + 0x484) != 0) {
    iVar8 = (*(code *)(long)DAT_ffffffffbfc43f14)();
    (*(code *)(long)DAT_ffffffffbfc43a18)
              (iVar8 * 0x530 + iVar12,*(undefined4 *)(lVar30 + 0x480),
               *(int *)(lVar30 + 0x478) + iVar16,*(undefined4 *)(lVar30 + 0x47c));
    iVar8 = (*(code *)(long)DAT_ffffffffbfc43f14)();
    (*(code *)(long)DAT_ffffffffbfc44054)
              (iVar8 * 0x530 + iVar12,*(int *)(lVar30 + 0x480) + *(int *)(lVar30 + 0x47c),0,
               *(int *)(lVar30 + 0x484) - *(int *)(lVar30 + 0x47c));
  }
  uVar26 = uVar21;
  lVar23 = (*(code *)(long)DAT_ffffffffbfc44074)(uVar21);
  while (-1 < lVar23) {
    piVar28 = (int *)(long)(iVar17 + -0x280);
    do {
      iVar12 = *piVar28;
      uVar26 = (ulong)((int)lVar23 * 0x530 + DAT_ffffffffbfc43b88);
      if (iVar12 != 0) {
        iVar8 = piVar28[-3];
        (*(code *)(long)DAT_ffffffffbfc43a18)(uVar26,iVar8,iVar16 + piVar28[-1],iVar12);
        (*(code *)(long)DAT_ffffffffbfc44054)(uVar26,iVar8 + iVar12,0,piVar28[-2] - iVar12);
      }
      piVar28 = (int *)(long)((int)piVar28 + 0x18);
    } while (piVar28 != (int *)(long)(iVar17 + -0xa0));
    lVar23 = (*(code *)(long)DAT_ffffffffbfc43c20)();
  }
  setCopReg(2,uVar26,*(undefined4 *)(lVar22 + 6));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x900,*(undefined4 *)(lVar30 + 0x490));
  uVar9 = *(undefined4 *)(long)DAT_ffffffffbfc43860;
  pcVar29 = (code *)(long)DAT_ffffffffbfc43ef4;
  *(int *)(lVar30 + 0xc) = (int)lVar22;
  *(undefined4 *)(lVar30 + 4) = 0;
  lVar22 = (*pcVar29)(uVar21,*(int *)(lVar30 + 0x49c) - *(int *)(lVar30 + 0x490),
                      *(int *)(lVar30 + 0x4a0) + *(int *)(lVar30 + 0x490) * 4,
                      *(undefined4 *)(lVar30 + 0x88),*(undefined4 *)(lVar30 + 0x498),
                      *(undefined4 *)(lVar30 + 0x494),uVar9,uVar6 & 0xffffffff);
  if (lVar22 == 0) {
    lVar22 = (*(code *)(long)DAT_ffffffffbfc43ad0)(DAT_ffffffffbfc439c8,uVar21);
    pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
    if (lVar22 == 0) {
      iVar17 = DAT_ffffffffbfc436f4 + -0x830;
      *(uint *)(long)DAT_ffffffffbfc43828 = *(uint *)(long)DAT_ffffffffbfc43828 | (uint)uVar21;
      (*pcVar29)(iVar17,uVar21);
      uVar9 = getCopReg(2,0);
      *(undefined4 *)(uVar21 + 6) = uVar9;
      if (*(int *)(long)DAT_ffffffffbfc43bc8 == 0) {
        return 0;
      }
      (*(code *)(long)DAT_ffffffffbfc438c8)();
      (*(code *)(long)DAT_ffffffffbfc43ff4)();
      iVar17 = *(int *)(long)DAT_ffffffffbfc43828;
      iVar12 = DAT_ffffffffbfc43a00;
      goto LAB_ffffffffbfc1d4d4;
    }
    iVar17 = DAT_ffffffffbfc436f4 + -0x860;
  }
  else {
    pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
    iVar17 = DAT_ffffffffbfc436f4 + -0x8a0;
  }
  (*pcVar29)(iVar17,uVar21);
LAB_ffffffffbfc1d51c:
  pcVar29 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar17 = DAT_ffffffffbfc436f4 + -0x800;
LAB_ffffffffbfc1d524:
  (*pcVar29)(iVar17);
  return 0xffffffff;
}

