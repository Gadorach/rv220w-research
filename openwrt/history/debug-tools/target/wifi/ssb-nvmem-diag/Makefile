include $(TOPDIR)/rules.mk

PKG_NAME:=ssb-nvmem-diag
PKG_RELEASE:=3
PKG_LICENSE:=GPL-2.0-only

include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

define KernelPackage/ssb-nvmem-diag
  SUBMENU:=Other modules
  TITLE:=Broadcom SSB PCI NVM diagnostics with paired SPROM reads
  DEPENDS:=@PCI_SUPPORT +kmod-ssb
  FILES:=$(PKG_BUILD_DIR)/ssb_nvmem_diag.ko
  AUTOLOAD:=$(call AutoLoad,90,ssb_nvmem_diag)
endef

define KernelPackage/ssb-nvmem-diag/description
 Passive diagnostics for compatible Broadcom SSB PCI/PCIe devices remain
 non-binding. The module adds read-only paired 16-bit SPROM evidence matching
 stock Broadcom wl's two-reads-per-word sequence. The existing exact, gated
 BCM4322 OTP init-shadow control is unchanged and remains unavailable when
 chipstatus selects external SPROM. It does not bind the PCI function or alter RF.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	+$(KERNEL_MAKE) $(PKG_JOBS) \
		M="$(PKG_BUILD_DIR)" \
		modules
endef

$(eval $(call KernelPackage,ssb-nvmem-diag))
