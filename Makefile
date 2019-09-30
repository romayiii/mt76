EXTRA_CFLAGS += -Werror -DCONFIG_MT76_LEDS

obj-m := mt76.o
obj-$(CONFIG_MT7603E) += mt7603/
obj-$(CONFIG_MT76x02_LIB) += mt76x02-lib.o
obj-$(CONFIG_MT76x02_USB) += mt76x02-usb.o
obj-$(CONFIG_MT76_USB) += mt76-usb.o
obj-$(CONFIG_MT76x2_COMMON) += mt76x2/
obj-$(CONFIG_MT76x0_COMMON) += mt76x0/
obj-$(CONFIG_MT7615E) += mt7615/
obj-$(CONFIG_CONNAC_COMMON) += connac/

mt76-y := \
	mmio.o util.o trace.o dma.o mac80211.o debugfs.o eeprom.o \
	tx.o agg-rx.o mcu.o airtime.o

mt76-$(CONFIG_PCI) += pci.o

mt76-usb-y := usb.o usb_trace.o

mt76x02-lib-y := mt76x02_util.o mt76x02_mac.o mt76x02_mcu.o \
		 mt76x02_eeprom.o mt76x02_phy.o mt76x02_mmio.o \
		 mt76x02_txrx.o mt76x02_trace.o mt76x02_debugfs.o \
		 mt76x02_dfs.o mt76x02_beacon.o

mt76x02-usb-y := mt76x02_usb_mcu.o mt76x02_usb_core.o
