/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc05930
 * Function: FUN_ffffffffbfc05930
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

undefined8 FUN_ffffffffbfc05930(void)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar5[4] = &_gp;
  iVar3 = DAT_ffffffffbfc436f4;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43de4;
  puVar5[5] = in_ra;
  puVar5[1] = unaff_s1;
  *puVar5 = unaff_s0;
  puVar5[3] = unaff_s3;
  puVar5[2] = unaff_s2;
  (*pcVar4)(iVar3 + -0x7f30,0,0xfc00000000000000);
  (*(code *)(long)DAT_ffffffffbfc43850)(DAT_ffffffffbfc436f4 + -0x7f18,0,0x300000000);
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7f00,0x8001180008000400,0,0xffffffffffffffff);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0100);
  if ((((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0200), lVar1 == 0)) &&
      (lVar1 = (*pcVar4)(0x30d0600), lVar1 == 0)) && (lVar1 = (*pcVar4)(0x30d0700), lVar1 == 0)) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7ef0,0x8001180010000400,0,0xffffffffffffffff);
  }
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7ee0,0x80014f00000007f8,0,0xffffffffffffffff);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0100);
  if (((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0200), lVar1 == 0)) &&
     ((lVar1 = (*pcVar4)(0x30d0600), lVar1 == 0 && (lVar1 = (*pcVar4)(0x30d0700), lVar1 == 0)))) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7ed0,0x8001180020000018,0,0xffffffffffffffff);
  }
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7ec0,&DAT_8001180080000780,0,0x400000000);
  (*(code *)(long)DAT_ffffffffbfc43ffc)(DAT_ffffffffbfc436f4 + -0x7eb0,0x80011800800007f8,0,0x1f);
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7ea0,0x80011800800007f0,0,0xffffffffffffffff);
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7e90,0x80011800800007e8,0,0xffffffffffffffff);
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7e80,0x8001070000000730,0,0xffffffffffffffff);
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7e70,0x8001180050000080,0,0xffffffffffffffff);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0400);
  if (lVar1 == 0) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7e58,0x80011f00000003f8,0,0xffffffffffffffff);
  }
  lVar1 = (*pcVar4)(0x30d0400);
  if ((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0400), lVar1 == 0)) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7e48,0x80011800a0000000,0,0xffffffffffffffff);
  }
  uVar2 = (uint)_DAT_80016700000003f8;
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x7c80);
  if (lVar1 != 0) {
    iVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar1,0,0);
    uVar2 = uVar2 & iVar3 << 0x10;
  }
  if (uVar2 != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7e38,uVar2);
    *(int *)((long)DAT_ffffffffbfc436f4 + 0x4800) =
         *(int *)((long)DAT_ffffffffbfc436f4 + 0x4800) + 1;
  }
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7e10,0x8001180040000008,0,0xffffffffffffffff);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0100);
  if ((((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0200), lVar1 == 0)) &&
      (lVar1 = (*pcVar4)(0x30d0400), lVar1 == 0)) &&
     ((lVar1 = (*pcVar4)(0x30d0600), lVar1 == 0 && (lVar1 = (*pcVar4)(0x30d0700), lVar1 == 0)))) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7e00,0x80011800900007f8,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7df0,0x80011800980007f8,0,0xffffffffffffffff);
  }
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7de0,0x8001180058000080,0,0xffffffffffffffff);
  iVar3 = DAT_ffffffffbfc436ec + 0x4d40;
  lVar1 = (*(code *)(long)iVar3)(0x30d0200);
  if (lVar1 == 0) {
    lVar1 = (*(code *)(long)iVar3)(0x30d0600);
    if (lVar1 == 0) {
      (*(code *)(long)DAT_ffffffffbfc43ffc)
                (DAT_ffffffffbfc436f4 + -0x7dc8,0x80011800a8000010,0,0xffffffffffffffff);
    }
  }
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7db8,&DAT_80011800000000f8,0,0xffffffffffffffff);
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7da0,0x80011800f00007f8,0,0xffffffffffffffff);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0200);
  if (((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0400), lVar1 == 0)) &&
     ((lVar1 = (*pcVar4)(0x30d0600), lVar1 == 0 && (lVar1 = (*pcVar4)(0x30d0700), lVar1 == 0)))) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7d90,0x80011800300007f0,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7d80,0x80011800300007f8,0,0xffffffffffffffff);
  }
  (*(code *)(long)DAT_ffffffffbfc43ffc)
            (DAT_ffffffffbfc436f4 + -0x7d70,0x80011800280000e8,0,0xffffffffffffffff);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0200);
  if (((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0600), lVar1 == 0)) &&
     (lVar1 = (*pcVar4)(0x30d0700), lVar1 == 0)) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7d60,0x8001180038000080,0,0xffffffffffffffff);
  }
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4d40);
  lVar1 = (*pcVar4)(0x30d0001);
  if (((lVar1 == 0) && (lVar1 = (*pcVar4)(0x30d0300), lVar1 == 0)) &&
     (lVar1 = (*pcVar4)(0x30d0700), lVar1 == 0)) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7d48,0x80011800680007f8,0,0xffffffffffffffff);
  }
  iVar3 = DAT_ffffffffbfc436ec + 0x4d40;
  lVar1 = (*(code *)(long)iVar3)(0x30d0400);
  if ((lVar1 != 0) || (lVar1 = (*(code *)(long)iVar3)(0x30d0700), lVar1 != 0)) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7d30,0x80011800e0000400,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7da0,0x80011800f00007f8,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7d20,0x8001070000100078,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)(DAT_ffffffffbfc436f4 + -0x7d10,0x580,0,0xffffffffffffffff)
    ;
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7cf8,0x8001180070000080,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7e10,0x8001180040000008,0,0xffffffffffffffff);
  }
  lVar1 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4d40))(0x30d0400);
  if (lVar1 != 0) {
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7ce0,0x80011800b0000870,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7cc0,0x80011800b8000870,0,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43ffc)
              (DAT_ffffffffbfc436f4 + -0x7ca0,0x80011f0000008580,0,0xffffffffffffffff);
  }
  pcVar4 = (code *)(long)DAT_ffffffffbfc4400c;
  if (*(int *)((long)DAT_ffffffffbfc436f4 + 0x4800) == 0) {
    iVar3 = DAT_ffffffffbfc436f4 + -0x7c38;
  }
  else {
    (*pcVar4)(DAT_ffffffffbfc436f4 + -0x7c88);
    pcVar4 = (code *)(long)DAT_ffffffffbfc4400c;
    iVar3 = DAT_ffffffffbfc436f4 + -0x7c70;
  }
  (*pcVar4)(iVar3);
  return 0;
}

