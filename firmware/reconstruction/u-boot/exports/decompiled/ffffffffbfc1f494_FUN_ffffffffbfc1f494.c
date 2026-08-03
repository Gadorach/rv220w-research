/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1f494
 * Function: FUN_ffffffffbfc1f494
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

undefined8 FUN_ffffffffbfc1f494(long param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint *puVar4;
  undefined8 uVar5;
  int iVar6;
  char cVar7;
  char *pcVar8;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar9;
  undefined8 unaff_s3;
  undefined4 *puVar10;
  undefined8 unaff_s4;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar12[5] = &_gp;
  puVar12[1] = unaff_s1;
  *puVar12 = unaff_s0;
  puVar12[6] = in_ra;
  puVar12[4] = unaff_s4;
  puVar12[3] = unaff_s3;
  puVar12[2] = unaff_s2;
  if (param_1 == 0) {
    uVar11 = 1;
  }
  else {
    if (param_1 < 0) {
      return 0xffffffffffffffff;
    }
    if (2 < param_1) {
      return 0xffffffffffffffff;
    }
    uVar11 = 2;
  }
  iVar9 = 1;
  do {
    puVar10 = (undefined4 *)(long)DAT_ffffffffbfc43a24;
    iVar6 = (*(code *)(long)DAT_ffffffffbfc43a38)(*puVar10);
    if (iVar6 < iVar9) {
      return 0xffffffffffffffff;
    }
    puVar4 = (uint *)(*(code *)(long)DAT_ffffffffbfc4394c)(*puVar10,iVar9);
    iVar6 = (int)puVar4 + 8;
    cVar2 = *param_2;
    pcVar8 = param_2;
    do {
      cVar3 = *(char *)(long)iVar6;
      pcVar8 = (char *)(long)((int)pcVar8 + 1);
      iVar6 = iVar6 + 1;
      cVar7 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar8;
      cVar7 = cVar3;
    } while (bVar1);
    iVar9 = iVar9 + 1;
    if (cVar7 == cVar3) {
      if ((uVar11 & *puVar4) == 0) {
        return 0xffffffffffffffff;
      }
      uVar5 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0xdc0))(param_1);
      return uVar5;
    }
  } while( true );
}

