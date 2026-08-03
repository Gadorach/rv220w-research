/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00102c58
 * Function: init_module
 * Subsystem: module-lifecycle
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: Kernel module lifecycle
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Registers the switch-control character device, module parameters and initial BCM switch policy.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: bcm5398
   Subsystem: Kernel module lifecycle
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Registers the switch-control character device, module parameters and initial BCM
   switch policy.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 init_module(void)

{
  longlong lVar1;
  undefined8 uVar2;
  uint auStack_30 [4];
  
  (*(code *)&printk)(&DAT_00103030,uRam00103368);
  lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103048);
  if (lVar1 == 0) {
    if (_DAT_00103780 == 0) {
      _DAT_00103780 = 8;
    }
  }
  else {
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
    if ((lVar1 == 0) && (_DAT_00103780 == 0)) {
      _DAT_00103780 = 5;
    }
  }
  (*(code *)&printk)(&UNK_00103058,_DAT_00103360,_DAT_00103780);
  lVar1 = (*(code *)&alloc_chrdev_region)(auStack_30,0,1,uRam00103368);
  if (lVar1 < 0) {
    (*(code *)&printk)(&UNK_00103080,lVar1);
    uVar2 = 0xffffffffffffffff;
  }
  else {
    uRam00103784 = auStack_30[0] >> 0x14;
    auStack_30[0] = uRam00103784 << 0x14;
    (*(code *)&cdev_init)(0x103788,0x103370);
    uRam001037e8 = ZEXT48(__this_module);
    uRam001037f0 = 0x103370;
    lVar1 = (*(code *)&cdev_add)(0x103788,auStack_30[0],1);
    if (lVar1 < 0) {
      (*(code *)&printk)(&UNK_001030a8,lVar1);
      return 0xffffffffffffffff;
    }
    uVar2 = 0;
  }
  return uVar2;
}

