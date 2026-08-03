/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc17524
 * Function: do_loop
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
 * 
 * 
 * Recovered from U-Boot command table: command='loop', maxargs=3, repeatable=1, usage=''.
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
   
   
   Recovered from U-Boot command table: command='loop', maxargs=3, repeatable=1, usage=''. */

undefined8 do_loop(long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int in_t9_lo;
  undefined8 unaff_gp;
  long lVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar5[3] = unaff_gp;
  *puVar5 = unaff_s0;
  puVar5[4] = in_ra;
  lVar4 = (long)(in_t9_lo + 0x2c1bc);
  puVar5[2] = unaff_s2;
  puVar5[1] = unaff_s1;
  if (param_3 < 3) {
    (*(code *)(long)*(int *)(lVar4 + 0x92c))
              (*(int *)(lVar4 + 0x14) + -0x5320,*(undefined4 *)(param_1 + 0x10));
  }
  else {
    lVar1 = (*(code *)(long)*(int *)(lVar4 + 0x408))(*param_4,4);
    if (-1 < lVar1) {
      (*(code *)(long)*(int *)(lVar4 + 0x1d0))(param_4[1],0,0x10);
      iVar2 = (*(code *)(long)*(int *)(lVar4 + 0x1d0))(param_4[2],0,0x10);
      if (iVar2 != 1) {
        iVar3 = iVar2;
        if (lVar1 == 4) {
          do {
            do {
              iVar3 = iVar3 + -1;
            } while (iVar3 != -1);
            iVar3 = iVar2;
          } while( true );
        }
        if (lVar1 != 2) {
          do {
            do {
              iVar3 = iVar3 + -1;
            } while (iVar3 != -1);
            iVar3 = iVar2;
          } while( true );
        }
        do {
          do {
            iVar3 = iVar3 + -1;
          } while (iVar3 != -1);
          iVar3 = iVar2;
        } while( true );
      }
      if (lVar1 == 4) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if (lVar1 != 2) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 1;
}

