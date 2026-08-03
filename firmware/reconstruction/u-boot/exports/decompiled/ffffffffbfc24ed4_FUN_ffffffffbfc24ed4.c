/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc24ed4
 * Function: FUN_ffffffffbfc24ed4
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

undefined8 FUN_ffffffffbfc24ed4(long param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  long lVar6;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar7;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined4 uVar8;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[5] = &_gp;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  puVar10[6] = in_ra;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  *puVar10 = unaff_s0;
  if (param_1 == 0) {
LAB_ffffffffbfc24f60:
    uVar4 = 0xfffffffffffffffe;
  }
  else {
    lVar3 = (*(code *)(long)*(int *)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x18);
    *(int *)(param_1 + 0x1c) = (int)lVar3;
    if (lVar3 != 0) {
      *(undefined4 *)(lVar3 + 0x14) = 0;
      *(undefined4 *)(lVar3 + 0xc) = 0;
      if ((int)param_2 < 0) {
        param_2 = -param_2;
        *(undefined4 *)(lVar3 + 0xc) = 1;
      }
      if (7 < param_2 - 8) {
        (*(code *)(long)DAT_ffffffffbfc43784)(param_1);
        goto LAB_ffffffffbfc24f60;
      }
      lVar3 = (long)*(int *)(param_1 + 0x1c);
      iVar1 = *(int *)(param_1 + 0x20);
      uVar2 = *(undefined4 *)(param_1 + 0x28);
      uVar8 = 0;
      if (*(int *)(lVar3 + 0xc) == 0) {
        uVar8 = DAT_ffffffffbfc43c44;
      }
      *(uint *)(lVar3 + 0x10) = param_2;
      puVar5 = (undefined4 *)(*(code *)(long)iVar1)(uVar2,1,0x40);
      if (puVar5 != (undefined4 *)0x0) {
        iVar7 = 1 << (param_2 & 0x1f);
        lVar6 = (*(code *)(long)*(int *)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,iVar7);
        puVar5[10] = (int)lVar6;
        iVar1 = DAT_ffffffffbfc43700;
        if (lVar6 != 0) {
          puVar5[0xb] = (int)lVar6 + iVar7;
          puVar5[0xe] = uVar8;
          *puVar5 = 0;
          (*(code *)(long)(iVar1 + 0x4b28))(puVar5,param_1,(int)puVar5 + 0x3c);
          pcVar9 = (code *)(long)DAT_ffffffffbfc43ab8;
          *(int *)(lVar3 + 0x14) = (int)puVar5;
          (*pcVar9)(param_1);
          return 0;
        }
        (*(code *)(long)*(int *)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar5,0x40);
      }
      pcVar9 = (code *)(long)DAT_ffffffffbfc43784;
      *(undefined4 *)(lVar3 + 0x14) = 0;
      (*pcVar9)(param_1);
    }
    uVar4 = 0xfffffffffffffffc;
  }
  return uVar4;
}

