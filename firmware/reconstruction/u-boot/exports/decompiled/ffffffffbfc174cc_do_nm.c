/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc174cc
 * Function: do_nm
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
 * Recovered from U-Boot command table: command='nm', maxargs=2, repeatable=1, usage=''.
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
   
   
   Recovered from U-Boot command table: command='nm', maxargs=2, repeatable=1, usage=''. */

void do_nm(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int in_t9_lo;
  
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc174f0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)(*(int *)((long)(in_t9_lo + 0x2c214) + 0x1c) + 0x72d8))
            (param_1,0,param_2,param_3,param_4);
  return;
}

