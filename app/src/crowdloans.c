/*******************************************************************************
*   (c) 2018 - 2022 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "os.h"
#include "cx.h"
#include "coin.h"
#include "app_main.h"
#include "tx.h"
#include "view.h"
#include "app_mode.h"
#include "zxformat.h"

void account_accept() {
#ifdef APP_ACCOUNT_MODE_ENABLED
    app_mode_set_account(!app_mode_account());
    view_idle_show(0, NULL);
#endif
}

static const char* RELAY_CHAIN_POLKADOT = "Polkadot";
static const char* RELAY_CHAIN_KUSAMA = "Kusama";
static const char* PARACHAIN = COIN_NAME;

static const char* ACCOUNT_CROWDLOAN = "Crowdloan account.";
static const char* ACCOUNT_LEGACY = "Legacy account.";

static const char *crowdloan_message_00 = "You are about to switch to";
static const char *crowdloan_message_01 = "If you are not sure why you are here, reject or unplug your device immediately.";
static const char *crowdloan_message_02 = "Activating this mode will allow you to sign transactions using";

zxerr_t account_getNumItems(uint8_t *num_items) {
    zemu_log_stack("crowdloan_getNumItems");
    *num_items = 1;
    return zxerr_ok;
}

zxerr_t account_getItem(int8_t displayIdx,
                       char *outKey, uint16_t outKeyLen,
                       char *outVal, uint16_t outValLen,
                       uint8_t pageIdx, uint8_t *pageCount) {
    if (displayIdx != 0) {
        return zxerr_no_data;
    }

    snprintf(outKey, outKeyLen, "Warning!");

    char* account_str = (char*)PIC(ACCOUNT_CROWDLOAN);
    char* chain_str = (char*)PIC(RELAY_CHAIN_POLKADOT);
    const uint32_t derivation_path = HDPATH_1_RECOVERY & 0xFFF;
    if (derivation_path == 0x1b2) {
        chain_str = (char*)PIC(RELAY_CHAIN_KUSAMA);
    }
    if(app_mode_account()) {
        account_str = (char*)PIC(ACCOUNT_LEGACY);
        chain_str = (char*)PIC(PARACHAIN);
    }

    char tmpBuf[250];
    snprintf(tmpBuf, sizeof(tmpBuf), "%s %s %s %s, %s keys.",
                            (char*)PIC(crowdloan_message_00),
                            account_str,
                            (char*)PIC(crowdloan_message_01),
                            (char*)PIC(crowdloan_message_02),
                            chain_str);
    pageString(outVal, outValLen, tmpBuf, pageIdx, pageCount);
    return zxerr_ok;
}

zxerr_t account_enabled() {
#ifdef APP_ACCOUNT_MODE_ENABLED
    view_review_init(account_getItem, account_getNumItems, account_accept);
    view_review_show(0x00);
#endif
    return zxerr_ok;
}