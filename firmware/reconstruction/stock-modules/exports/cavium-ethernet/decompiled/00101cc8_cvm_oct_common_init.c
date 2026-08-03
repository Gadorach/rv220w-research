/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00101cc8
 * Function: cvm_oct_common_init
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Initializes common Octeon Ethernet resources, packet I/O, device state and MDIO integration shared by ports.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Initializes common Octeon Ethernet resources, packet I/O, device state and MDIO
   integration shared by ports.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_common_init(int param_1)

{
  byte bVar3;
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar4;
  byte abStack_40 [2];
  undefined1 auStack_3e [2];
  undefined1 auStack_3c [12];
  
  abStack_40[0] = 0x8b;
  brcm_miiphy_write(0,0,0xe,abStack_40);
  abStack_40[0] = 0x4b;
  brcm_miiphy_write(0,0,0x5d,abStack_40);
  brcm_miiphy_write(0,0x31,2,auStack_3e);
  brcm_miiphy_write(0,0x31,4,auStack_3e);
  brcm_miiphy_write(0,0x31,6,auStack_3e);
  brcm_miiphy_write(0,0x31,8,auStack_3e);
  brcm_miiphy_write(0,0x31,0x10,auStack_3e);
  brcm_miiphy_write(0,0x31,0,auStack_3e);
  brcm_miiphy_write(0,0x31,10,auStack_3e);
  abStack_40[0] = 0;
  brcm_miiphy_write(0,0,0,abStack_40);
  brcm_miiphy_write(0,0,1,abStack_40);
  brcm_miiphy_write(0,0,2,abStack_40);
  brcm_miiphy_write(0,0,3,abStack_40);
  brcm_miiphy_write(0,0,4,abStack_40);
  brcm_miiphy_write(0,0,5,abStack_40);
  brcm_miiphy_write(0,0,6,abStack_40);
  brcm_miiphy_write(0,0,7,abStack_40);
  bVar3 = brcm_miiphy_read(0,0,0xb);
  abStack_40[0] = bVar3 & 0xfc | 2;
  brcm_miiphy_write(0,0,0xb,abStack_40);
  if ((pow_send_group == -1) ||
     ((always_use_pow == 0 && (lVar2 = (*(code *)&strstr)(pow_send_list,param_1), lVar2 == 0)))) {
    if (*(int *)(param_1 + 0x564) != -1) {
      *(ulonglong *)(param_1 + 0x1d8) = ZEXT48(cvm_oct_xmit);
      *(ulonglong *)(param_1 + 0x58) = *(ulonglong *)(param_1 + 0x58) | 2;
      iRam00111260 = iRam00111260 + 1;
      uVar4 = *(ulonglong *)(param_1 + 0x58);
      goto code_r0x00102030;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x564) = 0xffffffff;
  }
  *(ulonglong *)(param_1 + 0x1d8) = ZEXT48(cvm_oct_xmit_pow);
  (*(code *)&memset)(auStack_3c,0,8);
  uVar4 = *(ulonglong *)(param_1 + 0x58);
code_r0x00102030:
  *(ulonglong *)(param_1 + 0x78) = ZEXT48(local_cavium_ethernet_text_002238);
  *(undefined4 *)(param_1 + 0x144) = 0x10;
  *(ulonglong *)(param_1 + 0x288) = ZEXT48(local_cavium_ethernet_text_0029a8);
  *(ulonglong *)(param_1 + 0x280) = ZEXT48(local_cavium_ethernet_text_002028);
  *(ulonglong *)(param_1 + 0x2b0) = ZEXT48(local_cavium_ethernet_text_002718);
  *(ulonglong *)(param_1 + 0x290) = ZEXT48(cvm_oct_ioctl);
  *(ulonglong *)(param_1 + 0x58) = uVar4 | 0x1000;
  *(ulonglong *)(param_1 + 0x90) = ZEXT48(cvm_oct_ethtool_ops);
  cvm_oct_mdio_setup_device(param_1);
  (*(code *)*(undefined8 *)(param_1 + 0x288))(param_1,auStack_3c);
  (*(code *)*(undefined8 *)(param_1 + 0x2b0))(param_1,*(undefined4 *)(param_1 + 0xa4));
  uVar1 = (*(code *)*(undefined8 *)(param_1 + 0x78))(param_1);
  (*(code *)&memset)(uVar1,0,0xb8);
  return 0;
}

