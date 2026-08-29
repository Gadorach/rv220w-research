include $(TOPDIR)/rules.mk

PKG_NAME:=octeon-pci-irq-diag
PKG_RELEASE:=1
PKG_LICENSE:=GPL-2.0-only

include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

define KernelPackage/octeon-pci-irq-diag
  SUBMENU:=Other modules
  TITLE:=Read-only Octeon legacy PCI INTx/CIU diagnostics
  DEPENDS:=@TARGET_octeon
  FILES:=$(PKG_BUILD_DIR)/octeon_pci_irq_diag.ko
  AUTOLOAD:=$(call AutoLoad,89,octeon_pci_irq_diag)
endef

define KernelPackage/octeon-pci-irq-diag/description
 Read-only CN50xx CIU interrupt provenance for the RV220W RAM-only WLAN
 qualification image. Exposes CIU_INTX_SUM0 and CIU_INTX_EN0 plus decoded
 PCI INT0-INT3 bits through sysfs. It does not bind PCI devices, acknowledge
 interrupts, modify CIU masks, remap IRQs, or write PCI/SSB/RF state.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	+$(KERNEL_MAKE) $(PKG_JOBS) M="$(PKG_BUILD_DIR)" modules
endef

$(eval $(call KernelPackage,octeon-pci-irq-diag))
