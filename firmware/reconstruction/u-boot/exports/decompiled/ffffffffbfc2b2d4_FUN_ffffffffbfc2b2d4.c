/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2b2d4
 * Function: FUN_ffffffffbfc2b2d4
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

undefined8 FUN_ffffffffbfc2b2d4(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iVar5;
  ulong *puVar3;
  undefined8 uVar4;
  int iVar6;
  undefined8 in_t6;
  undefined8 unaff_s0;
  ulong uVar7;
  code *unaff_s1;
  undefined8 unaff_s2;
  ulong uVar8;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  ulong uVar9;
  undefined8 unaff_s5;
  undefined1 *puVar10;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  ulong uVar12;
  code *pcVar13;
  undefined4 *puVar14;
  long unaff_s8;
  undefined8 in_ra;
  int iVar11;
  
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  puVar14 = (undefined4 *)(long)((int)&stack0x00000000 + -0x90);
  *(undefined1 **)(puVar14 + 0x1c) = &_gp;
  puVar14[8] = uVar1;
  *(undefined8 *)(puVar14 + 0x1a) = unaff_s7;
  *(undefined8 *)(puVar14 + 0x10) = unaff_s2;
  iVar6 = *(int *)((long)(int)puVar14[8] + 0xc);
  *(undefined8 *)(puVar14 + 0x20) = in_ra;
  *(long *)(puVar14 + 0x1e) = unaff_s8;
  *(undefined8 *)(puVar14 + 0x18) = unaff_s6;
  *(undefined8 *)(puVar14 + 0x16) = unaff_s5;
  *(undefined8 *)(puVar14 + 0x14) = unaff_s4;
  *(undefined8 *)(puVar14 + 0x12) = unaff_s3;
  *(code **)(puVar14 + 0xe) = unaff_s1;
  *(undefined8 *)(puVar14 + 0xc) = unaff_s0;
  uVar12 = (ulong)*(int *)((long)(int)puVar14[8] + 4);
  if (iVar6 == 0) {
    if (*(int *)(long)DAT_ffffffffbfc43ee4 == 0) {
      lVar2 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + 0x1ac8);
      if (lVar2 != 0) {
        (*(code *)(long)DAT_ffffffffbfc43b04)(puVar14);
        iVar6 = DAT_ffffffffbfc436f4;
        pcVar13 = (code *)(long)DAT_ffffffffbfc4400c;
        *puVar14 = 0;
        puVar14[1] = 0;
        puVar14[2] = 0;
        puVar14[3] = 0;
        puVar14[4] = 0;
        puVar14[5] = 0;
        (*pcVar13)(iVar6 + 0x1ad8);
        (*(code *)(long)DAT_ffffffffbfc43b70)(puVar14);
      }
      setCopReg(2,in_t6,*(undefined4 *)(_DAT_8001180028000050 + 6));
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1b18);
      unaff_s1 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x6504);
      (*unaff_s1)(&DAT_8001180028000050,0x4000);
      pcVar13 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x4e3c);
      (*pcVar13)(1,0x80,1000);
      (*pcVar13)(2,0x400,0x80);
      (*pcVar13)(0,0x800,1000);
      (*(code *)(long)DAT_ffffffffbfc43960)();
      (*(code *)(long)DAT_ffffffffbfc43b60)();
      (*unaff_s1)(0x8001670000000210,0x3ff);
    }
    special2(uVar12,unaff_s8,0x1b,0x32);
    iVar11 = (int)param_1 + 0x10;
    puVar10 = (undefined1 *)(long)iVar11;
    uVar7 = 0;
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6504))(unaff_s8 + -0x7ffee7fff7fffb38,0xf0f);
    iVar6 = 0;
    do {
      iVar5 = iVar11 + iVar6;
      iVar6 = iVar6 + 1;
      uVar7 = uVar7 << 8 | (ulong)*(byte *)(long)iVar5;
    } while (iVar6 != 6);
    uVar8 = uVar12 & 3;
    puVar3 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6588))(uVar8,uVar12);
    uVar9 = *puVar3;
    special2(uVar8,unaff_s1,0xb,0x32);
    pcVar13 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x6504);
    (*pcVar13)(puVar3,uVar9 & 0xfffffffffffffffe);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffdd0,uVar7);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffe80,*puVar10);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffe78,puVar10[1]);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffe70,puVar10[2]);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffe68,puVar10[3]);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffe60,puVar10[4]);
    (*pcVar13)(unaff_s1 + unaff_s8 + -0x7ffee7fff7fffe58,puVar10[5]);
    uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6530))(uVar8,uVar12);
    (*pcVar13)(uVar4,0xb);
    uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x655c))(uVar8,uVar12);
    (*pcVar13)(uVar4,1);
    (*pcVar13)(puVar3,uVar9);
    iVar6 = puVar14[8];
    if (*(int *)(long)DAT_ffffffffbfc43ee4 == 0) {
      (*(code *)(long)DAT_ffffffffbfc43898)();
      *(undefined4 *)(long)DAT_ffffffffbfc43ee4 = 1;
      iVar6 = puVar14[8];
    }
    *(undefined4 *)((long)iVar6 + 0xc) = 1;
  }
  return 1;
}

