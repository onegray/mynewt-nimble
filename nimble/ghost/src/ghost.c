
#include "controller/ble_phy.h"
#include "controller/ble_ll.h"

#ifndef MYNEWT
#include "nimble/nimble_port.h"
#endif


void
ble_ll_start(void *arg) // initial part from ble_ll_task()
{
    //struct ble_npl_event *ev;

    /* Init ble phy */
    ble_phy_init();

    /* Set output power to 1mW (0 dBm) */
    ble_phy_txpwr_set(MYNEWT_VAL(BLE_LL_TX_PWR_DBM));

    /* Register callback for transport */
    //ble_hci_trans_cfg_ll(ble_ll_hci_cmd_rx, NULL, ble_ll_hci_acl_rx, NULL);

    /* Tell the host that we are ready to receive packets */
    //ble_ll_hci_send_noop();

    // while (1) {
    //     ev = ble_npl_eventq_get(&g_ble_ll_data.ll_evq, BLE_NPL_TIME_FOREVER);
    //     assert(ev);
    //     ble_npl_event_run(ev);
    // }
}


void ble_startup() // ble_hs_startup_go()
{
	// BLE_HCI_OCF_CB_RESET
	ble_ll_reset();

}


void
ble_hs_init(void)
{

#if NIMBLE_BLE_CONNECT
    
    //ble_gatts_start();

#endif
    
    //ble_hs_sync();
    //  ->  ble_hs_startup_go(void)
                ble_startup();



}
