/*
 * Copyright (C) 2016 Felix Fietkau <nbd@nbd.name>
 * Copyright (C) 2018 Lorenzo Bianconi <lorenzo.bianconi83@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "mt76x2.h"
#include "mt76x02_mac.h"

void mt76x2_remove_interface(struct ieee80211_hw *hw,
			     struct ieee80211_vif *vif)
{
	struct mt76x2_dev *dev = hw->priv;

	mt76_txq_remove(&dev->mt76, vif->txq);
}
EXPORT_SYMBOL_GPL(mt76x2_remove_interface);

int mt76x2_conf_tx(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
		   u16 queue, const struct ieee80211_tx_queue_params *params)
{
	struct mt76x2_dev *dev = hw->priv;
	u8 cw_min = 5, cw_max = 10, qid;
	u32 val;

	qid = mt76_ac_to_hwq(queue);

	if (params->cw_min)
		cw_min = fls(params->cw_min);
	if (params->cw_max)
		cw_max = fls(params->cw_max);

	val = FIELD_PREP(MT_EDCA_CFG_TXOP, params->txop) |
	      FIELD_PREP(MT_EDCA_CFG_AIFSN, params->aifs) |
	      FIELD_PREP(MT_EDCA_CFG_CWMIN, cw_min) |
	      FIELD_PREP(MT_EDCA_CFG_CWMAX, cw_max);
	mt76_wr(dev, MT_EDCA_CFG_AC(qid), val);

	val = mt76_rr(dev, MT_WMM_TXOP(qid));
	val &= ~(MT_WMM_TXOP_MASK << MT_WMM_TXOP_SHIFT(qid));
	val |= params->txop << MT_WMM_TXOP_SHIFT(qid);
	mt76_wr(dev, MT_WMM_TXOP(qid), val);

	val = mt76_rr(dev, MT_WMM_AIFSN);
	val &= ~(MT_WMM_AIFSN_MASK << MT_WMM_AIFSN_SHIFT(qid));
	val |= params->aifs << MT_WMM_AIFSN_SHIFT(qid);
	mt76_wr(dev, MT_WMM_AIFSN, val);

	val = mt76_rr(dev, MT_WMM_CWMIN);
	val &= ~(MT_WMM_CWMIN_MASK << MT_WMM_CWMIN_SHIFT(qid));
	val |= cw_min << MT_WMM_CWMIN_SHIFT(qid);
	mt76_wr(dev, MT_WMM_CWMIN, val);

	val = mt76_rr(dev, MT_WMM_CWMAX);
	val &= ~(MT_WMM_CWMAX_MASK << MT_WMM_CWMAX_SHIFT(qid));
	val |= cw_max << MT_WMM_CWMAX_SHIFT(qid);
	mt76_wr(dev, MT_WMM_CWMAX, val);

	return 0;
}
EXPORT_SYMBOL_GPL(mt76x2_conf_tx);

void mt76x2_sta_rate_tbl_update(struct ieee80211_hw *hw,
				struct ieee80211_vif *vif,
				struct ieee80211_sta *sta)
{
	struct mt76x2_dev *dev = hw->priv;
	struct mt76x02_sta *msta = (struct mt76x02_sta *) sta->drv_priv;
	struct ieee80211_sta_rates *rates = rcu_dereference(sta->rates);
	struct ieee80211_tx_rate rate = {};

	if (!rates)
		return;

	rate.idx = rates->rate[0].idx;
	rate.flags = rates->rate[0].flags;
	mt76x2_mac_wcid_set_rate(dev, &msta->wcid, &rate);
	msta->wcid.max_txpwr_adj = mt76x2_tx_get_max_txpwr_adj(dev, &rate);
}
EXPORT_SYMBOL_GPL(mt76x2_sta_rate_tbl_update);

void mt76x2_queue_rx_skb(struct mt76_dev *mdev, enum mt76_rxq_id q,
			 struct sk_buff *skb)
{
	struct mt76x2_dev *dev = container_of(mdev, struct mt76x2_dev, mt76);
	void *rxwi = skb->data;

	if (q == MT_RXQ_MCU) {
		skb_queue_tail(&dev->mcu.res_q, skb);
		wake_up(&dev->mcu.wait);
		return;
	}

	skb_pull(skb, sizeof(struct mt76x2_rxwi));
	if (mt76x2_mac_process_rx(dev, skb, rxwi)) {
		dev_kfree_skb(skb);
		return;
	}

	mt76_rx(&dev->mt76, q, skb);
}
EXPORT_SYMBOL_GPL(mt76x2_queue_rx_skb);
