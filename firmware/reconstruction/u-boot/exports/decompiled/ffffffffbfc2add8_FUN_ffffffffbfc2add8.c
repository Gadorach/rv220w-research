/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2add8
 * Function: FUN_ffffffffbfc2add8
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

undefined8 FUN_ffffffffbfc2add8(long param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  int iVar5;
  long lVar2;
  ulong uVar3;
  int iVar6;
  ulong *puVar4;
  ulong uVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong uVar8;
  int iVar9;
  undefined8 unaff_s2;
  uint uVar10;
  undefined8 unaff_s3;
  ulong unaff_s4;
  undefined8 unaff_s5;
  ulong uVar11;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar12;
  int *piVar13;
  undefined8 unaff_s8;
  int iVar14;
  undefined8 in_ra;
  
  piVar13 = (int *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(piVar13 + 0x14) = &_gp;
  *(undefined8 *)(piVar13 + 10) = unaff_s3;
  pcVar12 = (code *)(long)DAT_ffffffffbfc43b9c;
  *(undefined8 *)(piVar13 + 8) = unaff_s2;
  *(undefined8 *)(piVar13 + 6) = unaff_s1;
  *(undefined8 *)(piVar13 + 0x18) = in_ra;
  *(undefined8 *)(piVar13 + 0x16) = unaff_s8;
  *(undefined8 *)(piVar13 + 0x12) = unaff_s7;
  *(undefined8 *)(piVar13 + 0x10) = unaff_s6;
  *(undefined8 *)(piVar13 + 0xe) = unaff_s5;
  *(ulong *)(piVar13 + 0xc) = unaff_s4;
  *(undefined8 *)(piVar13 + 4) = unaff_s0;
  (*pcVar12)();
  iVar5 = *(int *)(long)DAT_ffffffffbfc43efc + 1;
  *(int *)(long)DAT_ffffffffbfc43efc = iVar5;
  if (iVar5 == 1) {
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x544c))(param_1);
  }
  iVar5 = DAT_ffffffffbfc436f0 + -0x57c8;
  lVar2 = (*(code *)(long)iVar5)(0);
  if (lVar2 == 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1a18);
  }
  (*(code *)(long)DAT_ffffffffbfc43e84)(lVar2,param_2,param_3);
  special2(0xffffffffffffffff,unaff_s4,0x13,0x33);
  iVar14 = DAT_ffffffffbfc436f0 + -0x5750;
  iVar6 = *(int *)(param_1 + 0x34);
  uVar3 = (*(code *)(long)iVar14)(lVar2);
  uVar1 = ((undefined4 *)(long)iVar6)[2];
  uVar3 = unaff_s4 & 0xffffff0000000000 | uVar3 & 0xffffffffff;
  *piVar13 = *(undefined4 *)(long)iVar6;
  uVar11 = param_3 & 0xffff | 0x800000010000;
  if ((uVar1 & 0xffff) < 0x100) {
    iVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x64b4))();
    lVar2 = (long)(iVar6 * 0x10 + 0x2800 + *(int *)(long)DAT_ffffffffbfc43774);
    if (lVar2 != 0) {
      uVar7 = *(ulong *)(lVar2 + 8);
      uVar10 = (uint)uVar7 & 0x1fff;
      uVar8 = uVar7 >> 0xd & 0x1fff;
      if ((ulong)(long)(int)(uVar10 + 2) < uVar8) {
        iVar5 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x581c))((uVar7 >> 0x20 & 0x1fffffff) << 7)
        ;
        uVar10 = (uint)*(ulong *)(lVar2 + 8) & 0x1fff;
        puVar4 = (ulong *)(long)(int)(iVar5 + uVar10 * 8);
        *(ulong *)(lVar2 + 8) =
             *(ulong *)(lVar2 + 8) & 0xffffffffffffe000 | (long)(int)(uVar10 + 2) & 0x1fffU;
        puVar4[1] = uVar3;
        *puVar4 = uVar11;
      }
      else {
        puVar4 = (ulong *)(*(code *)(long)iVar5)(uVar7 >> 0x3d);
        if (puVar4 == (ulong *)0x0) goto LAB_ffffffffbfc2b058;
        iVar5 = (int)uVar8 - uVar10;
        iVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x581c))
                          ((*(ulong *)(lVar2 + 8) >> 0x20 & 0x1fffffff) << 7);
        iVar6 = iVar6 + ((uint)*(undefined8 *)(lVar2 + 8) & 0x1fff) * 8;
        *(ulong *)(long)iVar6 = uVar11;
        iVar9 = iVar6 + 8;
        if (iVar5 != 1) {
          ((ulong *)(long)iVar6)[1] = uVar3;
          iVar9 = iVar6 + 0x10;
        }
        uVar11 = (*(code *)(long)iVar14)(puVar4);
        *(ulong *)(long)iVar9 = uVar11;
        special2(uVar11,uVar11,7,0x3a);
        special2(uVar11,uVar11,0,0x33);
        uVar11 = (*(ulong *)(lVar2 + 8) & 0xe0000000ffffffff | uVar11) & 0xffffffffffffe000;
        *(ulong *)(lVar2 + 8) = uVar11;
        if (iVar5 == 1) {
          *(ulong *)(lVar2 + 8) = uVar11 | 1;
          *puVar4 = uVar3;
        }
      }
      SYNC(4);
      SYNC(4);
      *(undefined8 *)
       (((long)*piVar13 & 0x3fU) << 0xc | 0x8001520000000000 | ((long)(int)uVar1 & 0x1ffU) << 3) = 2
      ;
      return 0;
    }
  }
LAB_ffffffffbfc2b058:
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1a40);
  return 0;
}

