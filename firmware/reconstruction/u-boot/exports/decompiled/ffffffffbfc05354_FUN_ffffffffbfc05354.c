/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc05354
 * Function: FUN_ffffffffbfc05354
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

void FUN_ffffffffbfc05354(void)

{
  long lVar1;
  ulong uVar2;
  undefined8 unaff_s0;
  code *pcVar3;
  int iVar4;
  undefined8 unaff_s1;
  ulong uVar5;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  ulong uVar6;
  undefined8 unaff_s4;
  ulong uVar7;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  ulong uVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar9[7] = &_gp;
  puVar9[1] = unaff_s1;
  iVar4 = DAT_ffffffffbfc436ec;
  *puVar9 = unaff_s0;
  puVar9[8] = in_ra;
  pcVar3 = (code *)(long)(iVar4 + 0x4d40);
  puVar9[6] = unaff_s6;
  puVar9[5] = unaff_s5;
  puVar9[4] = unaff_s4;
  puVar9[3] = unaff_s3;
  puVar9[2] = unaff_s2;
  lVar1 = (*pcVar3)(0x30d0200);
  uVar6 = 0x100;
  if (lVar1 == 0) {
    lVar1 = (*pcVar3)(0x30d0100);
    uVar6 = 0x200;
    if (lVar1 == 0) {
      lVar1 = (*pcVar3)(0x30d0001);
      uVar6 = 0x400;
      if (lVar1 == 0) {
        lVar1 = (*pcVar3)(0x30d0300);
        uVar6 = 0x800;
        if (lVar1 == 0) {
          lVar1 = (*pcVar3)(0x30d0400);
          uVar6 = 0x800;
          if (lVar1 == 0) {
            lVar1 = (*pcVar3)(0x30d0700);
            uVar6 = 0x200;
            if (lVar1 == 0) {
              lVar1 = (*pcVar3)(0x30d0600);
              if (lVar1 == 0) {
                uVar6 = 0;
                uVar7 = 0;
                (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7fd0);
                goto LAB_ffffffffbfc05454;
              }
              uVar6 = 0x80;
            }
          }
        }
      }
      uVar7 = 8;
      goto LAB_ffffffffbfc05454;
    }
  }
  uVar7 = 4;
LAB_ffffffffbfc05454:
  iVar4 = DAT_ffffffffbfc436ec + 0x4ee8;
  lVar1 = (*(code *)(long)iVar4)(0x109);
  if (lVar1 == 0) {
    lVar1 = (*(code *)(long)iVar4)(0x108);
    if (lVar1 != 0) {
      uVar7 = (long)((int)uVar7 >> 1);
    }
  }
  else {
    uVar7 = (long)((int)uVar7 >> 2);
  }
  uVar2 = (*(code *)(long)DAT_ffffffffbfc4385c)();
  uVar2 = (uVar2 & 0xf) << 6 | 4;
  for (uVar8 = 0; uVar8 != uVar6; uVar8 = uVar8 + 1) {
    for (uVar5 = 0; uVar5 != uVar7; uVar5 = uVar5 + 1) {
      uVar2 = uVar2 & 0xffffffffffffffc7 | (uVar5 & 7) << 3;
      SYNC(0);
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))(&DAT_8001180080000030,uVar2);
      prefetch((uVar8 & 0xffffffffffffff) << 7 | 0x8000000000000000,0x1e);
      SYNC(0);
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))(&DAT_8001180080000030,0);
    }
  }
  return;
}

