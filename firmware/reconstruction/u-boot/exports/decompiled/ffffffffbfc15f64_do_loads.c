/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc15f64
 * Function: do_loads
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
 * Recovered from U-Boot command table: command='loads', maxargs=2, repeatable=0, usage=''.
 */

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
   
   Recovered from U-Boot command table: command='loads', maxargs=2, repeatable=0, usage=''. */

bool do_loads(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  char *pcVar1;
  char cVar3;
  long lVar2;
  undefined8 unaff_s0;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 unaff_s1;
  int iVar7;
  undefined8 unaff_s2;
  uint uVar8;
  undefined8 unaff_s3;
  int iVar9;
  undefined8 unaff_s4;
  uint uVar10;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  code *pcVar11;
  long in_k0;
  int *piVar12;
  undefined8 in_ra;
  
  iVar6 = (int)&stack0x00000000;
  piVar12 = (int *)(long)(iVar6 + -0x380);
  *(undefined1 **)(piVar12 + 0xda) = &_gp;
  *(undefined8 *)(piVar12 + 0xce) = unaff_s1;
  iVar5 = DAT_ffffffffbfc436f4;
  pcVar11 = (code *)(long)DAT_ffffffffbfc43f0c;
  *(undefined8 *)(piVar12 + 0xcc) = unaff_s0;
  *(undefined8 *)(piVar12 + 0xdc) = in_ra;
  *(undefined8 *)(piVar12 + 0xd8) = unaff_s6;
  *(undefined8 *)(piVar12 + 0xd6) = unaff_s5;
  *(undefined8 *)(piVar12 + 0xd4) = unaff_s4;
  *(undefined8 *)(piVar12 + 0xd2) = unaff_s3;
  *(undefined8 *)(piVar12 + 0xd0) = unaff_s2;
  pcVar1 = (char *)(*pcVar11)(iVar5 + -0x4248);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 != '1')) {
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x28e0) = 0;
  }
  else {
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x28e0) = 1;
  }
  if (param_3 == 2) {
    iVar5 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10);
  }
  else {
    iVar5 = 0;
  }
  uVar8 = 0xffffffff;
  uVar10 = 0;
  iVar9 = 0;
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4238);
  do {
    pcVar1 = (char *)(long)(iVar6 + -0x259);
LAB_ffffffffbfc1627c:
    do {
      do {
        if (pcVar1 < (char *)(long)(iVar6 + -0x55)) {
          cVar3 = (*(code *)(long)DAT_ffffffffbfc43e94)();
          if (*(int *)((long)DAT_ffffffffbfc436f4 + 0x28e0) != 0) {
            (*(code *)(long)DAT_ffffffffbfc439f0)(cVar3);
          }
          if (cVar3 != '\x03') {
            if (cVar3 < '\x04') {
              if (cVar3 == '\0') goto LAB_ffffffffbfc1629c;
              *pcVar1 = cVar3;
            }
            else {
              if ((cVar3 == '\n') || (cVar3 == '\r')) goto LAB_ffffffffbfc16290;
              *pcVar1 = cVar3;
            }
            if ((*(int *)((long)*(int *)(in_k0 + 0x80) + 4) == DAT_ffffffffbfc43e94) ||
               (lVar2 = (*(code *)(long)DAT_ffffffffbfc43b08)(), lVar2 == 0)) {
              pcVar1 = (char *)(long)((int)pcVar1 + 1);
              goto LAB_ffffffffbfc1627c;
            }
          }
LAB_ffffffffbfc1629c:
          iVar5 = -1;
LAB_ffffffffbfc162a4:
          iVar6 = 0;
          do {
            iVar6 = iVar6 + 1;
            lVar2 = (*(code *)(long)DAT_ffffffffbfc43c5c)();
            if (lVar2 != 0) {
              (*(code *)(long)DAT_ffffffffbfc43e94)();
            }
            (*(code *)(long)DAT_ffffffffbfc43b18)(1000);
          } while (iVar6 != 100);
          if (iVar5 != -1) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4290,iVar5);
            *(int *)(long)DAT_ffffffffbfc43d48 = iVar5;
          }
          else {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x41a0);
          }
          return iVar5 == -1;
        }
LAB_ffffffffbfc16290:
        *pcVar1 = '\0';
        if ((int)pcVar1 - (iVar6 + -0x259) < 0) goto LAB_ffffffffbfc1629c;
        iVar7 = iVar6 + -0x358;
        lVar2 = (*(code *)(long)DAT_ffffffffbfc43854)(iVar6 + -0x259,piVar12,iVar6 + -0x37c,iVar7);
        if (lVar2 < 0) goto LAB_ffffffffbfc1629c;
        uVar4 = uVar10;
        if (lVar2 < 1) {
LAB_ffffffffbfc1619c:
          iVar7 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x28e0);
          uVar10 = uVar4;
        }
        else {
          if (3 < lVar2) {
            if ((int)lVar2 - 7U < 3) {
              iVar6 = iVar6 + -0x378;
              (*(code *)(long)DAT_ffffffffbfc43b18)(10000);
              iVar5 = (uVar10 - uVar8) + 1;
              (*(code *)(long)DAT_ffffffffbfc4400c)
                        (DAT_ffffffffbfc436f4 + -0x4210,uVar8,uVar10,iVar5,iVar5);
              (*(code *)(long)DAT_ffffffffbfc43e48)(uVar8,iVar5);
              (*(code *)(long)DAT_ffffffffbfc439a4)(iVar6,DAT_ffffffffbfc436f4 + -0x5ca0,iVar5);
              (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7b80,iVar6);
              (*(code *)(long)DAT_ffffffffbfc439a4)(iVar6,DAT_ffffffffbfc436f4 + -0x41a8,uVar8);
              (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7b70,iVar6);
              iVar5 = piVar12[1];
              goto LAB_ffffffffbfc162a4;
            }
            goto LAB_ffffffffbfc1619c;
          }
          uVar4 = iVar5 + piVar12[1];
          lVar2 = (*(code *)(long)DAT_ffffffffbfc438a8)(uVar4);
          if (lVar2 == 0) {
            (*(code *)(long)DAT_ffffffffbfc43e84)(uVar4,iVar7,*piVar12);
          }
          else {
            lVar2 = (*(code *)(long)DAT_ffffffffbfc4407c)(iVar7,uVar4);
            if (lVar2 != 0) {
              iVar5 = -1;
              (*(code *)(long)DAT_ffffffffbfc43864)(lVar2);
              goto LAB_ffffffffbfc162a4;
            }
          }
          if (uVar4 < uVar8) {
            uVar8 = uVar4;
          }
          uVar4 = (uVar4 + *piVar12) - 1;
          if (uVar10 < uVar4) goto LAB_ffffffffbfc1619c;
          iVar7 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x28e0);
        }
        pcVar1 = (char *)(long)(iVar6 + -0x259);
      } while (iVar7 != 0);
      iVar9 = iVar9 + 1;
    } while (iVar9 != (iVar9 / 100) * 100);
    (*(code *)(long)DAT_ffffffffbfc439f0)(0x2e);
  } while( true );
}

