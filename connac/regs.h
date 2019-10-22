/* SPDX-License-Identifier: ISC */
/* Copyright (C) 2019 MediaTek Inc. */

#ifndef __CONNAC_REGS_H
#define __CONNAC_REGS_H

enum connac_regs_base {
	MCU_BASE,
	PDMA_BASE,
	DMA_SHDL_BASE,
	CSR_BASE,
	WF_PHY_BASE,
	WF_CFG_BASE,
	WF_AGG_BASE,
	WF_TMAC_BASE,
	WF_RMAC_BASE,
	WF_DMA_BASE,
	WTBL_ON_BASE,
	WTBL_OFF_BASE,
	LPON_BASE,
	WF_MIB_BASE,
	WTBL_BASE,
	TOPCFG_BASE,
	TOPMISC_BASE,
	HIF2_BASE,
	UMAC_BASE,
	EFUSE_BASE,
	__MAX_BASE,
};

static const u32 connac_mmio_regs_base[] = {
	[MCU_BASE] =		0x2000,
	[PDMA_BASE] =		0x4000,
	[DMA_SHDL_BASE] =	0x6000,
	[CSR_BASE] =		0x7000,
	[WF_PHY_BASE] =		0x10000,
	[WF_CFG_BASE] =		0x20000,
	[WF_AGG_BASE] =		0x22000,
	[WF_TMAC_BASE] =	0x24000,
	[WF_RMAC_BASE] =	0x25000,
	[WF_DMA_BASE] =		0x27000,
	[WTBL_ON_BASE] =	0x29000,
	[WTBL_OFF_BASE] =	0x29800,
	[LPON_BASE] =		0x2b000,
	[WF_MIB_BASE] =		0x2d000,
	[WTBL_BASE] =		0x30000,
	[TOPCFG_BASE] =		0xb0000,
	[TOPMISC_BASE] =	0xc0000,
	[HIF2_BASE] =		0xf0000,
	[UMAC_BASE] =		0x7c000000,
	[EFUSE_BASE] =		0x81070000,
};

static const u32 connac_abs_regs_base[] = {
	[MCU_BASE] =		0x80000000,
	[PDMA_BASE] =		0x50000000,
	[DMA_SHDL_BASE] =	0x5000a000,
	[CSR_BASE] =		0x40000000,
	[WF_PHY_BASE] =		0x82070000,
	[WF_CFG_BASE] =		0x820F0000,
	[WF_AGG_BASE] =		0x820F2000,
	[WF_TMAC_BASE] =	0x820F4000,
	[WF_RMAC_BASE] =	0x820F5000,
	[WF_DMA_BASE] =		0x820F7000,
	[WTBL_ON_BASE] =	0x820f9000,
	[WTBL_OFF_BASE] =	0x820f9800,
	[LPON_BASE] =		0x820fb000,
	[WF_MIB_BASE] =		0x820fd000,
	[WTBL_BASE] =		0x820e0000,
	[TOPCFG_BASE] =		0x80020000,
	[TOPMISC_BASE] =	0x81020000,
	[HIF2_BASE] =		0x7c030000,
	[UMAC_BASE] =		0x7c000000,
	[EFUSE_BASE] =		0x81070000,
};

#define MT_UMAC(dev, _n)		((dev)->regs[UMAC_BASE] + (_n))
#define UDMA_TX_QSEL(dev)		MT_UMAC(dev, 0x8)
#define FW_DL_EN			BIT(3)

#define UDMA_WLCFG_1(dev)		MT_UMAC(dev, 0xc)
#define WL_RX_AGG_PKT_LMT		GENMASK(7, 0)
#define WL_TX_TMOUT_LMT			GENMASK(27, 8)

#define UDMA_WLCFG_0(dev)		MT_UMAC(dev, 0x18)
#define WL_RX_AGG_TO			GENMASK(7, 0)
#define WL_RX_AGG_LMT			GENMASK(15, 8)
#define WL_TX_TMOUT_FUNC_EN		BIT(16)
#define WL_TX_DPH_CHK_EN		BIT(17)
#define WL_RX_MPSZ_PAD0			BIT(18)
#define WL_RX_FLUSH			BIT(19)
#define TICK_1US_EN			BIT(20)
#define WL_RX_AGG_EN			BIT(21)
#define WL_RX_EN			BIT(22)
#define WL_TX_EN			BIT(23)
#define WL_RX_BUSY			BIT(30)
#define WL_TX_BUSY			BIT(31)

#define MT_TOP_MISC2(dev)		((dev)->regs[TOPCFG_BASE] + 0x134)
#define MT_TOP_MISC2_FW_STATE		GENMASK(3, 1)
#define MT_TOP_MISC2_FW_PWR_ON		BIT(1)
#define MT_TOP_MISC2_FW_N9_RDY		BIT(2)
#define MT_CONN_ON_MISC(dev)		((dev)->regs[TOPMISC_BASE] + 0x1140)

#define MT_MCU(dev, ofs)		((dev)->regs[MCU_BASE] + (ofs))
#define MT_HW_REV(dev)			(MT_MCU(dev, 0x0))
#define MT_HW_CHIPID(dev)		(MT_MCU(dev, 0x8))

#define MT_MCU_PCIE_REMAP_1(dev)	(MT_MCU(dev, 0x500))
#define MT_MCU_PCIE_REMAP_1_OFFSET	GENMASK(17, 0)
#define MT_MCU_PCIE_REMAP_1_BASE	GENMASK(31, 18)
#define MT_PCIE_REMAP_BASE_1		0x40000

#define MT_MCU_PCIE_REMAP_2		0x700c
#define MT_MCU_PCIE_REMAP_2_OFFSET	GENMASK(15, 0)
#define MT_MCU_PCIE_REMAP_2_BASE	GENMASK(31, 16)
#define MT_PCIE_REMAP_BASE_2		0x90000

#define MT_PCIE_IRQ_ENABLE(dev)		((dev)->regs[HIF2_BASE] + 0x0188)

#define MT_HIF(dev, ofs)		((dev)->regs[PDMA_BASE] + (ofs))

#define MT_CFG_LPCR_HOST(dev)		MT_HIF(dev, 0x1f0)
#define MT_CFG_LPCR_HOST_FW_OWN		BIT(0)
#define MT_CFG_LPCR_HOST_DRV_OWN	BIT(1)

#define MT_CONN_HIF_ON_LPCTL(dev)	((dev)->regs[CSR_BASE] + 0x0000)

#define MT_INT_SOURCE_CSR(dev)		MT_HIF(dev, 0x200)
#define MT_INT_MASK_CSR(dev)		MT_HIF(dev, 0x204)
#define MT_DELAY_INT_CFG(dev)		MT_HIF(dev, 0x210)

#define MT_INT_RX_DONE(_n)		BIT(_n)
#define MT_INT_RX_DONE_ALL		GENMASK(1, 0)
#define MT_INT_TX_DONE_ALL		GENMASK(19, 4)
#define MT_INT_TX_DONE(_n)		BIT((_n) + 4)

#define MT_WPDMA_GLO_CFG(dev)			MT_HIF(dev, 0x208)
#define MT_WPDMA_GLO_CFG_TX_DMA_EN		BIT(0)
#define MT_WPDMA_GLO_CFG_TX_DMA_BUSY		BIT(1)
#define MT_WPDMA_GLO_CFG_RX_DMA_EN		BIT(2)
#define MT_WPDMA_GLO_CFG_RX_DMA_BUSY		BIT(3)
#define MT_WPDMA_GLO_CFG_DMA_BURST_SIZE		GENMASK(5, 4)
#define MT_WPDMA_GLO_CFG_TX_WRITEBACK_DONE	BIT(6)
#define MT_WPDMA_GLO_CFG_BIG_ENDIAN		BIT(7)
#define MT_WPDMA_GLO_CFG_FW_RING_BP_TX_SCH	BIT(9)
#define MT_WPDMA_GLO_CFG_MULTI_DMA_EN		GENMASK(11, 10)
#define MT_WPDMA_GLO_CFG_FIFO_LITTLE_ENDIAN	BIT(12)
#define MT_WPDMA_GLO_CFG_TX_BT_SIZE_BIT21	GENMASK(23, 22)
#define MT_WPDMA_GLO_CFG_SW_RESET		BIT(24)
#define MT_WPDMA_GLO_CFG_FIRST_TOKEN_ONLY	BIT(26)
#define MT_WPDMA_GLO_CFG_OMIT_TX_INFO		BIT(28)

#define MT_WPDMA_RST_IDX(dev)		MT_HIF(dev, 0x20c)

#define MT_TX_RING_BASE(dev)		MT_HIF(dev, 0x300)
#define MT_RX_RING_BASE(dev)		MT_HIF(dev, 0x400)

#define MT_WPDMA_GLO_CFG1(dev)		MT_HIF(dev, 0x500)
#define MT_WPDMA_TX_PRE_CFG(dev)	MT_HIF(dev, 0x510)
#define MT_WPDMA_RX_PRE_CFG(dev)	MT_HIF(dev, 0x520)
#define MT_WPDMA_ABT_CFG(dev)		MT_HIF(dev, 0x530)
#define MT_WPDMA_ABT_CFG1(dev)		MT_HIF(dev, 0x534)

#define MT_WF_PHY(dev, ofs)		((dev)->regs[WF_PHY_BASE] + (ofs))

#define MT_WF_PHY_WF2_RFCTRL0(dev)	MT_WF_PHY(dev, 0x1900)
#define MT_WF_PHY_WF2_RFCTRL0_LPBCN_EN	BIT(9)

#define MT_WF_PHY_R0_B0_PHYMUX_5(dev)	MT_WF_PHY(dev, 0x0614)

#define MT_HIF_DMASHDL_PKT_MAX_SIZE(dev) ((dev)->regs[DMA_SHDL_BASE] + 0x1c)

#define PLE_PKT_MAX_SIZE_MASK		(0xfff << 0)
#define PLE_PKT_MAX_SIZE_NUM(p)		(((p) & 0xfff) << 0)
#define GET_PLE_PKT_MAX_SIZE_NUM(p)	(((p) & PLE_PKT_MAX_SIZE_MASK) >> 0)

#define PSE_PKT_MAX_SIZE_MASK		(0xfff << 16)
#define PSE_PKT_MAX_SIZE_NUM(p)		(((p) & 0xfff) << 16)
#define GET_PSE_PKT_MAX_SIZE_NUM(p)	(((p) & PSE_PKT_MAX_SIZE_MASK) >> 16)

#define _DMASHDL_BASE(dev, ofs)		((dev)->regs[DMA_SHDL_BASE] + (ofs))
#define MT_HIF_DMASHDL_OPTION_CTRL(dev)	(_DMASHDL_BASE(dev, 0x08))
#define MT_HIF_DMASHDL_REFILL_CTRL(dev)	(_DMASHDL_BASE(dev, 0x10))
#define MT_HIF_DMASHDL_GROUP0_CTRL(dev)	(_DMASHDL_BASE(dev, 0x20))
#define MT_HIF_DMASHDL_GROUP1_CTRL(dev)	(_DMASHDL_BASE(dev, 0x24))
#define MT_HIF_DMASHDL_GROUP2_CTRL(dev)	(_DMASHDL_BASE(dev, 0x28))
#define MT_HIF_DMASHDL_GROUP3_CTRL(dev)	(_DMASHDL_BASE(dev, 0x2c))
#define MT_HIF_DMASHDL_GROUP4_CTRL(dev)	(_DMASHDL_BASE(dev, 0x30))
#define MT_HIF_DMASHDL_GROUP5_CTRL(dev)	(_DMASHDL_BASE(dev, 0x34))
#define MT_HIF_DMASHDL_GROUP6_CTRL(dev)	(_DMASHDL_BASE(dev, 0x38))
#define MT_HIF_DMASHDL_GROUP7_CTRL(dev)	(_DMASHDL_BASE(dev, 0x3c))
#define MT_HIF_DMASHDL_GROUP8_CTRL(dev)	(_DMASHDL_BASE(dev, 0x40))
#define MT_HIF_DMASHDL_GROUP9_CTRL(dev)	(_DMASHDL_BASE(dev, 0x44))
#define MT_HIF_DMASHDL_GROUP10_CTRL(dev)	(_DMASHDL_BASE(dev, 0x48))
#define MT_HIF_DMASHDL_GROUP11_CTRL(dev)	(_DMASHDL_BASE(dev, 0x4c))
#define MT_HIF_DMASHDL_GROUP12_CTRL(dev)	(_DMASHDL_BASE(dev, 0x50))
#define MT_HIF_DMASHDL_GROUP13_CTRL(dev)	(_DMASHDL_BASE(dev, 0x54))
#define MT_HIF_DMASHDL_GROUP14_CTRL(dev)	(_DMASHDL_BASE(dev, 0x58))
#define MT_HIF_DMASHDL_GROUP15_CTRL(dev)	(_DMASHDL_BASE(dev, 0x5c))

#define MT_HIF_DMASHDL_SHDL_SET0(dev)	(_DMASHDL_BASE(dev, 0xb0))
#define MT_HIF_DMASHDL_SHDL_SET1(dev)	(_DMASHDL_BASE(dev, 0xb4))

#define MT_HIF_DMASHDL_Q_MAP0(dev)	(_DMASHDL_BASE(dev, 0xd0))
#define MT_HIF_DMASHDL_Q_MAP1(dev)	(_DMASHDL_BASE(dev, 0xd4))
#define MT_HIF_DMASHDL_Q_MAP2(dev)	(_DMASHDL_BASE(dev, 0xd8))
#define MT_HIF_DMASHDL_Q_MAP3(dev)	(_DMASHDL_BASE(dev, 0xdc))

#define DMASHDL_MAX_QUOTA_MASK         (0xfff << 16)
#define DMASHDL_MIN_QUOTA_MASK         (0xfff << 0)
#define DMASHDL_MAX_QUOTA_OFFSET       16
#define DMASHDL_MIN_QUOTA_OFFSET       0

#define DMASHDL_MIN_QUOTA_NUM(p) (((p) & 0xfff) << DMASHDL_MIN_QUOTA_OFFSET)
#define GET_DMASHDL_MIN_QUOTA_NUM(p) \
	(((p) & DMASHDL_MIN_QUOTA_MASK) >> DMASHDL_MIN_QUOTA_OFFSET)

#define DMASHDL_MAX_QUOTA_NUM(p) (((p) & 0xfff) << DMASHDL_MAX_QUOTA_OFFSET)
#define GET_DMASHDL_MAX_QUOTA_NUM(p) \
	(((p) & DMASHDL_MAX_QUOTA_MASK) >> DMASHDL_MAX_QUOTA_OFFSET)

#define MT_PDMA(dev, _n)		((dev)->regs[PDMA_BASE] + (_n))
#define PDMA_HIF_RST			MT_PDMA(dev, 0x100)
#define CONN_HIF_LOGIC_RST_N		BIT(4)

#define MT_DMASHDL(dev, _n)		((dev)->regs[DMA_SHDL_BASE] + (_n))

#define DMASHDL_OPTIONAL_CONTROL(dev)	MT_DMASHDL(dev, 0x8)
#define DMASHDL_PAGE_SETTING(dev)	MT_DMASHDL(dev, 0xc)
#define GROUP_SEQUENCE_ORDER_TYPE	BIT(16)

#define DMASHDL_REFILL_CONTROL(dev)	MT_DMASHDL(dev, 0x10)

#define DMASHDL_PKT_MAX_SIZE(dev)	MT_DMASHDL(dev, 0x1c)
#define PLE_PACKET_MAX_SIZE		GENMASK(11, 0)
#define PSE_PACKET_MAX_SIZE		GENMASK(27, 16)

#define DMASHDL_GROUP0_CONTROL(dev)	MT_DMASHDL(dev, 0x20)
#define DMASHDL_GROUP1_CONTROL(dev)	MT_DMASHDL(dev, 0x24)
#define DMASHDL_GROUP2_CONTROL(dev)	MT_DMASHDL(dev, 0x28)
#define DMASHDL_GROUP3_CONTROL(dev)	MT_DMASHDL(dev, 0x2c)
#define DMASHDL_GROUP4_CONTROL(dev)	MT_DMASHDL(dev, 0x30)
#define DMASHDL_GROUP15_CONTROL(dev)	MT_DMASHDL(dev, 0x5c)
#define MIN_QUOTA			GENMASK(11, 0)
#define MAX_QUOTA			GENMASK(27, 16)

#define DMASHDL_SCHED_SETTING0(dev)	MT_DMASHDL(dev, 0xb0)
#define DMASHDL_SCHED_SETTING1(dev)	MT_DMASHDL(dev, 0xb4)

#define DMASHDL_QUEUE_MAPPING0(dev)	MT_DMASHDL(dev, 0xd0)
#define DMASHDL_QUEUE_MAPPING1(dev)	MT_DMASHDL(dev, 0xd4)
#define DMASHDL_QUEUE_MAPPING2(dev)	MT_DMASHDL(dev, 0xd8)
#define DMASHDL_QUEUE_MAPPING3(dev)	MT_DMASHDL(dev, 0xdc)
#define QUEUE0_MAP			GENMASK(3, 0)
#define QUEUE1_MAP			GENMASK(7, 4)
#define QUEUE2_MAP			GENMASK(11, 8)
#define QUEUE3_MAP			GENMASK(15, 12)
#define QUEUE4_MAP			GENMASK(19, 16)
#define QUEUE5_MAP			GENMASK(23, 20)
#define QUEUE6_MAP			GENMASK(27, 24)
#define QUEUE7_MAP			GENMASK(31, 28)
#define QUEUE8_MAP			GENMASK(3, 0)
#define QUEUE9_MAP			GENMASK(7, 4)
#define QUEUE10_MAP			GENMASK(11, 8)
#define QUEUE11_MAP			GENMASK(15, 12)
#define QUEUE12_MAP			GENMASK(19, 16)
#define QUEUE13_MAP			GENMASK(23, 20)
#define QUEUE14_MAP			GENMASK(27, 24)
#define QUEUE15_MAP			GENMASK(31, 28)
#define QUEUE16_MAP			GENMASK(3, 0)
#define QUEUE17_MAP			GENMASK(7, 4)
#define QUEUE18_MAP			GENMASK(11, 8)
#define QUEUE19_MAP			GENMASK(15, 12)

#define MT_WF_CFG(dev, ofs)		((dev)->regs[WF_CFG_BASE] + (ofs))

#define MT_CFG_CCR(dev)			MT_WF_CFG(dev, 0x000)
#define MT_CFG_CCR_MAC_D1_1X_GC_EN	BIT(24)
#define MT_CFG_CCR_MAC_D0_1X_GC_EN	BIT(25)
#define MT_CFG_CCR_MAC_D1_2X_GC_EN	BIT(30)
#define MT_CFG_CCR_MAC_D0_2X_GC_EN	BIT(31)

#define MT_WF_AGG(dev, ofs)		((dev)->regs[WF_AGG_BASE] + (ofs))

#define MT_AGG_ARCR(dev)		MT_WF_AGG(dev, 0x010)
#define MT_AGG_ARCR_INIT_RATE1		BIT(0)
#define MT_AGG_ARCR_RTS_RATE_THR	GENMASK(12, 8)
#define MT_AGG_ARCR_RATE_DOWN_RATIO	GENMASK(17, 16)
#define MT_AGG_ARCR_RATE_DOWN_RATIO_EN	BIT(19)
#define MT_AGG_ARCR_RATE_UP_EXTRA_TH	GENMASK(22, 20)

#define MT_AGG_ARUCR(dev)		MT_WF_AGG(dev, 0x018)
#define MT_AGG_ARDCR(dev)		MT_WF_AGG(dev, 0x01c)
#define MT_AGG_ARXCR_LIMIT_SHIFT(_n)	(4 * (_n))
#define MT_AGG_ARXCR_LIMIT(_n)		GENMASK(2 + \
					MT_AGG_ARXCR_LIMIT_SHIFT(_n), \
					MT_AGG_ARXCR_LIMIT_SHIFT(_n))

#define MT_AGG_ACR0(dev)		MT_WF_AGG(dev, 0x070)
#define MT_AGG_ACR_NO_BA_RULE		BIT(0)
#define MT_AGG_ACR_NO_BA_AR_RULE	BIT(1)
#define MT_AGG_ACR_PKT_TIME_EN		BIT(2)
#define MT_AGG_ACR_CFEND_RATE		GENMASK(15, 4)
#define MT_AGG_ACR_BAR_RATE		GENMASK(31, 20)

#define MT_AGG_SCR(dev)			MT_WF_AGG(dev, 0x0fc)
#define MT_AGG_SCR_NLNAV_MID_PTEC_DIS	BIT(3)

#define MT_WF_TMAC(dev, ofs)		((dev)->regs[WF_TMAC_BASE] + (ofs))

#define MT_TMAC_TRCR0(dev)		MT_WF_TMAC(dev, 0x09c)
#define MT_TMAC_TRCR1(dev)		MT_WF_TMAC(dev, 0x070)
#define MT_TMAC_TRCR_CCA_SEL		GENMASK(31, 30)
#define MT_TMAC_TRCR_SEC_CCA_SEL	GENMASK(29, 28)

#define MT_TMAC_CTCR0(dev)		MT_WF_TMAC(dev, 0x0f4)
#define MT_TMAC_CTCR0_INS_DDLMT_REFTIME	GENMASK(5, 0)
#define MT_TMAC_CTCR0_INS_DDLMT_DENSITY	GENMASK(15, 12)
#define MT_TMAC_CTCR0_INS_DDLMT_EN	BIT(17)
#define MT_TMAC_CTCR0_INS_DDLMT_VHT_SMPDU_EN	BIT(18)

#define MT_WF_RMAC(dev, ofs)		((dev)->regs[WF_RMAC_BASE] + (ofs))

#define MT_WF_RFCR(dev)			MT_WF_RMAC(dev, 0x000)
#define MT_WF_RFCR_DROP_STBC_MULTI	BIT(0)
#define MT_WF_RFCR_DROP_FCSFAIL		BIT(1)
#define MT_WF_RFCR_DROP_VERSION		BIT(3)
#define MT_WF_RFCR_DROP_PROBEREQ	BIT(4)
#define MT_WF_RFCR_DROP_MCAST		BIT(5)
#define MT_WF_RFCR_DROP_BCAST		BIT(6)
#define MT_WF_RFCR_DROP_MCAST_FILTERED	BIT(7)
#define MT_WF_RFCR_DROP_A3_MAC		BIT(8)
#define MT_WF_RFCR_DROP_A3_BSSID	BIT(9)
#define MT_WF_RFCR_DROP_A2_BSSID	BIT(10)
#define MT_WF_RFCR_DROP_OTHER_BEACON	BIT(11)
#define MT_WF_RFCR_DROP_FRAME_REPORT	BIT(12)
#define MT_WF_RFCR_DROP_CTL_RSV		BIT(13)
#define MT_WF_RFCR_DROP_CTS		BIT(14)
#define MT_WF_RFCR_DROP_RTS		BIT(15)
#define MT_WF_RFCR_DROP_DUPLICATE	BIT(16)
#define MT_WF_RFCR_DROP_OTHER_BSS	BIT(17)
#define MT_WF_RFCR_DROP_OTHER_UC	BIT(18)
#define MT_WF_RFCR_DROP_OTHER_TIM	BIT(19)
#define MT_WF_RFCR_DROP_NDPA		BIT(20)
#define MT_WF_RFCR_DROP_UNWANTED_CTL	BIT(21)

#define MT_WF_RFCR1(dev)		MT_WF_RMAC(dev, 0x004)
#define MT_WF_RFCR1_DROP_ACK		BIT(4)
#define MT_WF_RFCR1_DROP_BF_POLL	BIT(5)
#define MT_WF_RFCR1_DROP_BA		BIT(6)
#define MT_WF_RFCR1_DROP_CFEND		BIT(7)
#define MT_WF_RFCR1_DROP_CFACK		BIT(8)

#define MT_WF_RMAC_MIB_TIME0(dev)	MT_WF_RMAC(dev, 0x03c4)
#define MT_WF_RMAC_MIB_RXTIME_CLR	BIT(31)
#define MT_WF_RMAC_MIB_RXTIME_EN	BIT(30)

#define MT_WF_RMAC_MIB_AIRTIME0(dev)	MT_WF_RMAC(dev, 0x0380)

#define MT_WF_RMAC_MIB_TIME5(dev)	MT_WF_RMAC(dev, 0x03d8)
#define MT_MIB_OBSSTIME_MASK		GENMASK(23, 0)

#define MT_WF_DMA(dev, ofs)		((dev)->regs[WF_DMA_BASE] + (ofs))

#define MT_DMA_DCR0(dev)		MT_WF_DMA(dev, 0x000)
#define MT_DMA_DCR0_MAX_RX_LEN		GENMASK(15, 2)
#define MT_DMA_DCR0_RX_VEC_DROP		BIT(17)

#define MT_WTBL_ENTRY_SIZE		256

#define MT_WTBL(dev, n)			((dev)->regs[WTBL_BASE] + (n))
#define MT_WTBL_OFF(dev, n)		((dev)->regs[WTBL_OFF_BASE] + (n))

#define MT_WTBL_W0_KEY_IDX		GENMASK(24, 23)
#define MT_WTBL_W0_RX_KEY_VALID		BIT(26)
#define MT_WTBL_W0_RX_IK_VALID		BIT(27)

#define MT_WTBL_W2_KEY_TYPE		GENMASK(7, 4)

#define MT_WTBL_UPDATE(dev)		MT_WTBL_OFF(dev, 0x030)
#define MT_WTBL_UPDATE_WLAN_IDX		GENMASK(7, 0)
#define MT_WTBL_UPDATE_RXINFO_UPDATE	BIT(11)
#define MT_WTBL_UPDATE_RATE_UPDATE	BIT(13)
#define MT_WTBL_UPDATE_TX_COUNT_CLEAR	BIT(14)
#define MT_WTBL_UPDATE_BUSY		BIT(31)

#define MT_WTBL_ON(dev, _n)		((dev)->regs[WTBL_ON_BASE] + (_n))

#define MT_WTBL_RICR0(dev)		MT_WTBL_ON(dev, 0x010)
#define MT_WTBL_RICR1(dev)		MT_WTBL_ON(dev, 0x014)

#define MT_WTBL_RIUCR0(dev)		MT_WTBL_ON(dev, 0x020)

#define MT_WTBL_RIUCR1(dev)		MT_WTBL_ON(dev, 0x024)
#define MT_WTBL_RIUCR1_RATE0		GENMASK(11, 0)
#define MT_WTBL_RIUCR1_RATE1		GENMASK(23, 12)
#define MT_WTBL_RIUCR1_RATE2_LO		GENMASK(31, 24)

#define MT_WTBL_RIUCR2(dev)		MT_WTBL_ON(dev, 0x028)
#define MT_WTBL_RIUCR2_RATE2_HI		GENMASK(3, 0)
#define MT_WTBL_RIUCR2_RATE3		GENMASK(15, 4)
#define MT_WTBL_RIUCR2_RATE4		GENMASK(27, 16)
#define MT_WTBL_RIUCR2_RATE5_LO		GENMASK(31, 28)

#define MT_WTBL_RIUCR3(dev)		MT_WTBL_ON(dev, 0x02c)
#define MT_WTBL_RIUCR3_RATE5_HI		GENMASK(7, 0)
#define MT_WTBL_RIUCR3_RATE6		GENMASK(19, 8)
#define MT_WTBL_RIUCR3_RATE7		GENMASK(31, 20)

#define MT_WTBL_W5_CHANGE_BW_RATE	GENMASK(7, 5)
#define MT_WTBL_W5_SHORT_GI_20		BIT(8)
#define MT_WTBL_W5_SHORT_GI_40		BIT(9)
#define MT_WTBL_W5_SHORT_GI_80		BIT(10)
#define MT_WTBL_W5_SHORT_GI_160		BIT(11)
#define MT_WTBL_W5_BW_CAP		GENMASK(13, 12)
#define MT_WTBL_W5_MPDU_FAIL_COUNT	GENMASK(25, 23)
#define MT_WTBL_W5_MPDU_OK_COUNT	GENMASK(28, 26)
#define MT_WTBL_W5_RATE_IDX		GENMASK(31, 29)

#define MT_WTBL_W27_CC_BW_SEL		GENMASK(6, 5)

#define MT_LPON(dev, _n)		((dev)->regs[LPON_BASE] + (_n))

#define MT_LPON_T0CR(dev)		MT_LPON(dev, 0x010)
#define MT_LPON_T0CR_MODE		GENMASK(1, 0)

#define MT_LPON_UTTR0(dev)		MT_LPON(dev, 0x018)
#define MT_LPON_UTTR1(dev)		MT_LPON(dev, 0x01c)

#define MT_WF_MIB(dev, ofs)		((dev)->regs[WF_MIB_BASE] + (ofs))

#define MT_MIB_M0_MISC_CR(dev)		MT_WF_MIB(dev, 0x00c)
#define MT_MIB_MB_SDR0(dev, n)		MT_WF_MIB(dev, 0x100 + ((n) << 4))
#define MT_MIB_RTS_RETRIES_COUNT_MASK	GENMASK(31, 16)
#define MT_MIB_RTS_COUNT_MASK		GENMASK(15, 0)

#define MT_MIB_SDR9(dev, n)		MT_WF_MIB(dev, 0x02c + ((n) << 9))
#define MT_MIB_SDR9_BUSY_MASK		GENMASK(23, 0)

#define MT_MIB_SDR16(dev, n)		MT_WF_MIB(dev, 0x48 + ((n) << 9))
#define MT_MIB_BUSY_MASK		GENMASK(23, 0)

#define MT_MIB_SDR36(dev, n)		MT_WF_MIB(dev, 0x098 + ((n) << 9))
#define MT_MIB_SDR36_TXTIME_MASK	GENMASK(23, 0)
#define MT_MIB_SDR37(dev, n)		MT_WF_MIB(dev, 0x09c + ((n) << 9))
#define MT_MIB_SDR37_RXTIME_MASK	GENMASK(23, 0)

#define MT_TX_AGG_CNT(n)		MT_WF_MIB(0xa8 + ((n) << 2))


#define MT_EFUSE_BASE_CTRL		0x000
#define MT_EFUSE_BASE_CTRL_EMPTY	BIT(30)

#define MT_EFUSE_CTRL			0x008
#define MT_EFUSE_CTRL_AOUT		GENMASK(5, 0)
#define MT_EFUSE_CTRL_MODE		GENMASK(7, 6)
#define MT_EFUSE_CTRL_LDO_OFF_TIME	GENMASK(13, 8)
#define MT_EFUSE_CTRL_LDO_ON_TIME	GENMASK(15, 14)
#define MT_EFUSE_CTRL_AIN		GENMASK(25, 16)
#define MT_EFUSE_CTRL_VALID		BIT(29)
#define MT_EFUSE_CTRL_KICK		BIT(30)
#define MT_EFUSE_CTRL_SEL		BIT(31)

#define MT_EFUSE_WDATA(_i)		(0x010 + ((_i) * 4))
#define MT_EFUSE_RDATA(_i)		(0x030 + ((_i) * 4))

#endif
