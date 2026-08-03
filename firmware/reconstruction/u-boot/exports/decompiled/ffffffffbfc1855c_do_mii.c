/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1855c
 * Function: do_mii
 * Subsystem: mdio
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Recovered from U-Boot command table: command='mii', maxargs=5, repeatable=1, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='mii', maxargs=5, repeatable=1, usage=''. */

undefined8 do_mii(long param_1,long param_2,long param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined8 in_zero;
  undefined4 *puVar8;
  char cVar11;
  long lVar9;
  char cVar12;
  byte bVar13;
  int *piVar10;
  int iVar14;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  byte bVar16;
  int iVar15;
  undefined8 unaff_s2;
  int iVar17;
  undefined8 unaff_s3;
  undefined8 uVar18;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  char cVar19;
  undefined8 unaff_s6;
  code *pcVar20;
  byte *pbVar21;
  undefined8 in_ra;
  int iVar22;
  
  iVar22 = (int)&stack0x00000000;
  pbVar21 = (byte *)(long)(iVar22 + -0x70);
  *(undefined1 **)(pbVar21 + 0x58) = &_gp;
  *(undefined8 *)(pbVar21 + 0x20) = unaff_s0;
  puVar8 = (undefined4 *)(long)DAT_ffffffffbfc43818;
  *(undefined8 *)(pbVar21 + 0x28) = unaff_s1;
  uVar2 = *puVar8;
  puVar8 = (undefined4 *)(long)DAT_ffffffffbfc43c7c;
  *(undefined8 *)(pbVar21 + 0x30) = unaff_s2;
  uVar3 = *puVar8;
  puVar8 = (undefined4 *)(long)DAT_ffffffffbfc43bbc;
  *(undefined8 *)(pbVar21 + 0x60) = in_ra;
  uVar4 = *puVar8;
  puVar8 = (undefined4 *)(long)DAT_ffffffffbfc43fd8;
  *(undefined8 *)(pbVar21 + 0x50) = unaff_s6;
  uVar5 = *puVar8;
  puVar8 = (undefined4 *)(long)DAT_ffffffffbfc43cb8;
  *(undefined8 *)(pbVar21 + 0x48) = unaff_s5;
  uVar6 = *puVar8;
  *(undefined8 *)(pbVar21 + 0x40) = unaff_s4;
  *(short *)(pbVar21 + 6) = (short)uVar6;
  puVar8 = (undefined4 *)(long)DAT_ffffffffbfc439e8;
  *(undefined8 *)(pbVar21 + 0x38) = unaff_s3;
  *pbVar21 = (char)uVar2;
  pbVar21[1] = (byte)uVar3;
  pbVar21[2] = (byte)uVar4;
  pbVar21[3] = (byte)uVar5;
  setCopReg(2,in_zero,*(undefined4 *)(param_2 + 3));
  cVar11 = (char)*puVar8;
  if (cVar11 == 'i') {
    cVar19 = '\x01';
    cVar12 = '\0';
    if (param_3 < 3) {
      cVar19 = ' ';
    }
    while( true ) {
      if (cVar12 == cVar19) break;
      lVar9 = (*(code *)(long)DAT_ffffffffbfc4401c)
                        (cVar12,iVar22 + -0x68,iVar22 + -0x6c,iVar22 + -0x6b);
      if (lVar9 == 0) {
        uVar2 = *(undefined4 *)(pbVar21 + 8);
        bVar16 = pbVar21[4];
        bVar13 = pbVar21[5];
        uVar18 = (*(code *)(long)DAT_ffffffffbfc44044)(cVar12);
        lVar9 = (*(code *)(long)DAT_ffffffffbfc43cfc)(cVar12);
        if (lVar9 == 0x2c) {
          iVar14 = DAT_ffffffffbfc436f4 + -0x2b90;
        }
        else {
          iVar14 = DAT_ffffffffbfc436f4 + -0x2b88;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x2b80,cVar12,uVar2,bVar16,bVar13,uVar18,iVar14);
      }
      cVar12 = cVar12 + '\x01';
    }
    uVar18 = 0;
    piVar10 = (int *)(long)DAT_ffffffffbfc439e8;
  }
  else if (cVar11 == 'r') {
    uVar18 = 0;
    for (bVar16 = *pbVar21; bVar13 = pbVar21[2], bVar16 <= pbVar21[1]; bVar16 = bVar16 + 1) {
      while( true ) {
        pcVar20 = (code *)(long)DAT_ffffffffbfc43df0;
        if (pbVar21[3] < bVar13) break;
        pbVar21[6] = 0xff;
        pbVar21[7] = 0xff;
        lVar9 = (*pcVar20)(bVar16,bVar13,iVar22 + -0x6a);
        if (lVar9 == 0) {
          if ((*pbVar21 != pbVar21[1]) || (pbVar21[2] != pbVar21[3])) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2b08,bVar16,bVar13);
          }
          (*(code *)(long)DAT_ffffffffbfc4400c)
                    (DAT_ffffffffbfc436f4 + -0x2bb8,*(undefined2 *)(pbVar21 + 6));
        }
        else {
          uVar18 = 1;
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2b38,bVar16);
        }
        bVar13 = bVar13 + 1;
      }
      if ((*pbVar21 != pbVar21[1]) && (pbVar21[2] != pbVar21[3])) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
      }
    }
    piVar10 = (int *)(long)DAT_ffffffffbfc439e8;
  }
  else if (cVar11 == 'w') {
    uVar18 = 0;
    for (bVar16 = *pbVar21; bVar13 = pbVar21[2], bVar16 <= pbVar21[1]; bVar16 = bVar16 + 1) {
      for (; bVar13 <= pbVar21[3]; bVar13 = bVar13 + 1) {
        lVar9 = (*(code *)(long)DAT_ffffffffbfc43b2c)(bVar16,bVar13,*(undefined2 *)(pbVar21 + 6));
        if (lVar9 != 0) {
          uVar18 = 1;
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2ae8,bVar16,bVar13);
        }
      }
    }
    piVar10 = (int *)(long)DAT_ffffffffbfc439e8;
  }
  else {
    if (cVar11 != 'd') {
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
      return 1;
    }
    if ((5 < pbVar21[2]) || (bVar16 = *pbVar21, 5 < pbVar21[3])) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2ab8);
      return 1;
    }
    uVar18 = 0;
    bVar7 = true;
    for (; bVar16 <= pbVar21[1]; bVar16 = bVar16 + 1) {
      iVar17 = iVar22 + -100;
      iVar14 = 0;
      do {
        lVar9 = (*(code *)(long)DAT_ffffffffbfc43df0)(bVar16,iVar14,iVar17);
        iVar17 = iVar17 + 2;
        iVar15 = iVar14 + 1;
        if (lVar9 != 0) {
          uVar18 = 1;
          bVar7 = false;
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2b38,bVar16,iVar14);
        }
        iVar14 = iVar15;
      } while (iVar15 != 6);
      if (bVar7) {
        (*(code *)(long)DAT_ffffffffbfc43c18)(iVar22 + -100,pbVar21[2],pbVar21[3]);
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
    }
    piVar10 = (int *)(long)DAT_ffffffffbfc439e8;
  }
  bVar16 = *pbVar21;
  *piVar10 = (int)cVar11;
  bVar13 = pbVar21[1];
  *(uint *)(long)DAT_ffffffffbfc43818 = (uint)bVar16;
  bVar16 = pbVar21[2];
  *(uint *)(long)DAT_ffffffffbfc43c7c = (uint)bVar13;
  bVar13 = pbVar21[3];
  *(uint *)(long)DAT_ffffffffbfc43bbc = (uint)bVar16;
  uVar1 = *(ushort *)(pbVar21 + 6);
  *(uint *)(long)DAT_ffffffffbfc43fd8 = (uint)bVar13;
  *(uint *)(long)DAT_ffffffffbfc43cb8 = (uint)uVar1;
  return uVar18;
}

