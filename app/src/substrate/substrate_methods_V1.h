/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_UTILITY_V1 3
#define PD_CALL_MULTISIG_V1 4
#define PD_CALL_PROXY_V1 5
#define PD_CALL_BALANCES_V1 10
#define PD_CALL_CURRENCIES_V1 12
#define PD_CALL_VESTING_V1 13
#define PD_CALL_TRANSACTIONPAYMENT_V1 14
#define PD_CALL_BOUNTIES_V1 21
#define PD_CALL_COLLATORSELECTION_V1 41
#define PD_CALL_SESSION_V1 42
#define PD_CALL_XCMPQUEUE_V1 50
#define PD_CALL_XTOKENS_V1 54
#define PD_CALL_DEMOCRACY_V1 69
#define PD_CALL_DEX_V1 91
#define PD_CALL_AGGREGATEDDEX_V1 93
#define PD_CALL_HONZON_V1 102
#define PD_CALL_HOMA_V1 116
#define PD_CALL_INCENTIVES_V1 120
#define PD_CALL_NFT_V1 121
#define PD_CALL_EVM_V1 130
#define PD_CALL_EVMACCOUNTS_V1 132
#define PD_CALL_STABLEASSET_V1 200

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V1 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V1_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_PROXY_REMOVE_PROXIES_V1 3
typedef struct {
} pd_proxy_remove_proxies_V1_t;

#define PD_CALL_PROXY_ANONYMOUS_V1 4
typedef struct {
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V1_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V1 5
typedef struct {
    pd_AccountId_V1_t spawner;
    pd_ProxyType_V1_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V1_t;

#define PD_CALL_PROXY_ANNOUNCE_V1 6
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_announce_V1_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V1 7
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_remove_announcement_V1_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V1 8
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_reject_announcement_V1_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V1 9
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_CURRENCIES_UPDATE_BALANCE_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_CurrencyId_V1_t currency_id;
    pd_Amount_V1_t amount;
} pd_currencies_update_balance_V1_t;

#define PD_CALL_CURRENCIES_SWEEP_DUST_V1 3
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_VecAccountId_V1_t accounts;
} pd_currencies_sweep_dust_V1_t;

#define PD_CALL_VESTING_CLAIM_V1 0
typedef struct {
} pd_vesting_claim_V1_t;

#define PD_CALL_TRANSACTIONPAYMENT_SET_ALTERNATIVE_FEE_SWAP_PATH_V1 0
typedef struct {
    pd_OptionVecCurrencyId_V1_t fee_swap_path;
} pd_transactionpayment_set_alternative_fee_swap_path_V1_t;

#define PD_CALL_TRANSACTIONPAYMENT_DISABLE_CHARGE_FEE_POOL_V1 2
typedef struct {
    pd_CurrencyId_V1_t currency_id;
} pd_transactionpayment_disable_charge_fee_pool_V1_t;

#define PD_CALL_TRANSACTIONPAYMENT_WITH_FEE_PATH_V1 3
typedef struct {
    pd_VecCurrencyId_V1_t fee_swap_path;
    pd_Call_t call;
} pd_transactionpayment_with_fee_path_V1_t;

#define PD_CALL_TRANSACTIONPAYMENT_WITH_FEE_CURRENCY_V1 4
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Call_t call;
} pd_transactionpayment_with_fee_currency_V1_t;

#define PD_CALL_TRANSACTIONPAYMENT_WITH_FEE_PAID_BY_V1 5
typedef struct {
    pd_Call_t call;
    pd_AccountId_V1_t payer_addr;
    pd_MultiSignature_V1_t payer_sig;
} pd_transactionpayment_with_fee_paid_by_V1_t;

#define PD_CALL_TRANSACTIONPAYMENT_WITH_FEE_AGGREGATED_PATH_V1 6
typedef struct {
    pd_VecSwapPath_V1_t fee_aggregated_path;
    pd_Call_t call;
} pd_transactionpayment_with_fee_aggregated_path_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V1_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V1 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V1 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V1_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V1_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V1 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V1_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V1 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V1_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V1 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V1_t beneficiary;
} pd_bounties_award_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V1 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V1 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V1_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V1 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V1_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_;
} pd_collatorselection_set_invulnerables_V1_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V1 1
typedef struct {
    pd_Compactu32_t max;
} pd_collatorselection_set_desired_candidates_V1_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V1 2
typedef struct {
    pd_Compactu128_t bond;
} pd_collatorselection_set_candidacy_bond_V1_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V1 3
typedef struct {
} pd_collatorselection_register_as_candidate_V1_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_CANDIDATE_V1 4
typedef struct {
    pd_AccountId_V1_t new_candidate;
} pd_collatorselection_register_candidate_V1_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V1 5
typedef struct {
} pd_collatorselection_leave_intent_V1_t;

#define PD_CALL_COLLATORSELECTION_WITHDRAW_BOND_V1 6
typedef struct {
} pd_collatorselection_withdraw_bond_V1_t;

#define PD_CALL_XCMPQUEUE_SERVICE_OVERWEIGHT_V1 0
typedef struct {
    pd_OverweightIndex_V1_t index;
    pd_Weight_V1_t weight_limit;
} pd_xcmpqueue_service_overweight_V1_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V1 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V1_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V1 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V1_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V1 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V1_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V1 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V1_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V1 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V1_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V1 6
typedef struct {
    pd_Weight_V1_t new_;
} pd_xcmpqueue_update_threshold_weight_V1_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V1 7
typedef struct {
    pd_Weight_V1_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V1_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V1 8
typedef struct {
    pd_Weight_V1_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V1_t;

#define PD_CALL_XTOKENS_TRANSFER_V1 0
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Balance_t amount;
    pd_BoxVersionedMultiLocation_V1_t dest;
    pd_Weight_V1_t dest_weight;
} pd_xtokens_transfer_V1_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V1 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V1_t;

#define PD_CALL_DEMOCRACY_SECOND_V1 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V1_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V1 3
typedef struct {
    pd_ReferendumIndex_V1_t ref_index;
} pd_democracy_emergency_cancel_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V1 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V1_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V1 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V1_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V1 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V1 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V1_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V1 12
typedef struct {
} pd_democracy_undelegate_V1_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V1 13
typedef struct {
} pd_democracy_clear_public_proposals_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V1 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V1 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V1 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V1 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V1 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V1_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V1 19
typedef struct {
    pd_AccountId_V1_t target;
} pd_democracy_unlock_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V1 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V1_t;

#define PD_CALL_DEX_SWAP_WITH_EXACT_TARGET_V1 1
typedef struct {
    pd_VecCurrencyId_V1_t path;
    pd_Compactu128_t target_amount;
    pd_Compactu128_t max_supply_amount;
} pd_dex_swap_with_exact_target_V1_t;

#define PD_CALL_DEX_ADD_PROVISION_V1 3
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
    pd_Compactu128_t amount_a;
    pd_Compactu128_t amount_b;
} pd_dex_add_provision_V1_t;

#define PD_CALL_DEX_CLAIM_DEX_SHARE_V1 4
typedef struct {
    pd_AccountId_V1_t owner;
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
} pd_dex_claim_dex_share_V1_t;

#define PD_CALL_DEX_LIST_PROVISIONING_V1 6
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
    pd_Compactu128_t min_contribution_a;
    pd_Compactu128_t min_contribution_b;
    pd_Compactu128_t target_provision_a;
    pd_Compactu128_t target_provision_b;
    pd_Compactu32_t not_before;
} pd_dex_list_provisioning_V1_t;

#define PD_CALL_DEX_UPDATE_PROVISIONING_PARAMETERS_V1 7
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
    pd_Compactu128_t min_contribution_a;
    pd_Compactu128_t min_contribution_b;
    pd_Compactu128_t target_provision_a;
    pd_Compactu128_t target_provision_b;
    pd_Compactu32_t not_before;
} pd_dex_update_provisioning_parameters_V1_t;

#define PD_CALL_DEX_END_PROVISIONING_V1 8
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
} pd_dex_end_provisioning_V1_t;

#define PD_CALL_DEX_ENABLE_TRADING_PAIR_V1 9
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
} pd_dex_enable_trading_pair_V1_t;

#define PD_CALL_DEX_DISABLE_TRADING_PAIR_V1 10
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
} pd_dex_disable_trading_pair_V1_t;

#define PD_CALL_DEX_REFUND_PROVISION_V1 11
typedef struct {
    pd_AccountId_V1_t owner;
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
} pd_dex_refund_provision_V1_t;

#define PD_CALL_DEX_ABORT_PROVISIONING_V1 12
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
} pd_dex_abort_provisioning_V1_t;

#define PD_CALL_HONZON_CLOSE_LOAN_HAS_DEBIT_BY_DEX_V1 1
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Compactu128_t max_collateral_amount;
} pd_honzon_close_loan_has_debit_by_dex_V1_t;

#define PD_CALL_HONZON_TRANSFER_LOAN_FROM_V1 2
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_LookupasStaticLookupSource_V1_t from;
} pd_honzon_transfer_loan_from_V1_t;

#define PD_CALL_HONZON_AUTHORIZE_V1 3
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_LookupasStaticLookupSource_V1_t to;
} pd_honzon_authorize_V1_t;

#define PD_CALL_HONZON_UNAUTHORIZE_V1 4
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_LookupasStaticLookupSource_V1_t to;
} pd_honzon_unauthorize_V1_t;

#define PD_CALL_HONZON_UNAUTHORIZE_ALL_V1 5
typedef struct {
} pd_honzon_unauthorize_all_V1_t;

#define PD_CALL_HONZON_EXPAND_POSITION_COLLATERAL_V1 6
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Balance_t increase_debit_value;
    pd_Balance_t min_increase_collateral;
} pd_honzon_expand_position_collateral_V1_t;

#define PD_CALL_HONZON_SHRINK_POSITION_DEBIT_V1 7
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Balance_t decrease_collateral;
    pd_Balance_t min_decrease_debit_value;
} pd_honzon_shrink_position_debit_V1_t;

#define PD_CALL_HONZON_ADJUST_LOAN_BY_DEBIT_VALUE_V1 8
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Amount_V1_t collateral_adjustment;
    pd_Amount_V1_t debit_value_adjustment;
} pd_honzon_adjust_loan_by_debit_value_V1_t;

#define PD_CALL_HONZON_TRANSFER_DEBIT_V1 9
typedef struct {
    pd_CurrencyId_V1_t from_currency;
    pd_CurrencyId_V1_t to_currency;
    pd_Balance_t debit_transfer;
} pd_honzon_transfer_debit_V1_t;

#define PD_CALL_HOMA_CLAIM_REDEMPTION_V1 3
typedef struct {
    pd_AccountId_V1_t redeemer;
} pd_homa_claim_redemption_V1_t;

#define PD_CALL_HOMA_RESET_CURRENT_ERA_V1 7
typedef struct {
    pd_EraIndex_V1_t era_index;
} pd_homa_reset_current_era_V1_t;

#define PD_CALL_HOMA_FORCE_BUMP_CURRENT_ERA_V1 8
typedef struct {
    pd_EraIndex_V1_t bump_amount;
} pd_homa_force_bump_current_era_V1_t;

#define PD_CALL_INCENTIVES_DEPOSIT_DEX_SHARE_V1 0
typedef struct {
    pd_CurrencyId_V1_t lp_currency_id;
    pd_Compactu128_t amount;
} pd_incentives_deposit_dex_share_V1_t;

#define PD_CALL_INCENTIVES_CLAIM_REWARDS_V1 2
typedef struct {
    pd_PoolId_V1_t pool_id;
} pd_incentives_claim_rewards_V1_t;

#define PD_CALL_NFT_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t to;
    pd_ClassIdOfTTokenIdOfT_V1_t token;
} pd_nft_transfer_V1_t;

#define PD_CALL_EVM_ETH_CALL_V1 0
typedef struct {
    pd_TransactionAction_V1_t action;
    pd_Vecu8_t input;
    pd_Compactu128_t amount;
    pd_Compactu64_t gas_limit;
    pd_Compactu32_t storage_limit;
    pd_VecAccessListItem_V1_t access_list;
    pd_Compactu32_t valid_until;
} pd_evm_eth_call_V1_t;

#define PD_CALL_EVM_CALL_V1 1
typedef struct {
    pd_EvmAddress_V1_t target;
    pd_Vecu8_t input;
    pd_Compactu128_t amount;
    pd_Compactu64_t gas_limit;
    pd_Compactu32_t storage_limit;
    pd_VecAccessListItem_V1_t access_list;
} pd_evm_call_V1_t;

#define PD_CALL_EVM_CREATE_V1 3
typedef struct {
    pd_Vecu8_t input;
    pd_Compactu128_t amount;
    pd_Compactu64_t gas_limit;
    pd_Compactu32_t storage_limit;
    pd_VecAccessListItem_V1_t access_list;
} pd_evm_create_V1_t;

#define PD_CALL_EVM_CREATE2_V1 4
typedef struct {
    pd_Vecu8_t input;
    pd_H256_t salt;
    pd_Compactu128_t amount;
    pd_Compactu64_t gas_limit;
    pd_Compactu32_t storage_limit;
    pd_VecAccessListItem_V1_t access_list;
} pd_evm_create2_V1_t;

#define PD_CALL_EVM_TRANSFER_MAINTAINER_V1 7
typedef struct {
    pd_EvmAddress_V1_t contract;
    pd_EvmAddress_V1_t new_maintainer;
} pd_evm_transfer_maintainer_V1_t;

#define PD_CALL_EVM_PUBLISH_CONTRACT_V1 8
typedef struct {
    pd_EvmAddress_V1_t contract;
} pd_evm_publish_contract_V1_t;

#define PD_CALL_EVM_PUBLISH_FREE_V1 9
typedef struct {
    pd_EvmAddress_V1_t contract;
} pd_evm_publish_free_V1_t;

#define PD_CALL_EVM_ENABLE_CONTRACT_DEVELOPMENT_V1 10
typedef struct {
} pd_evm_enable_contract_development_V1_t;

#define PD_CALL_EVM_DISABLE_CONTRACT_DEVELOPMENT_V1 11
typedef struct {
} pd_evm_disable_contract_development_V1_t;

#define PD_CALL_EVM_SET_CODE_V1 12
typedef struct {
    pd_EvmAddress_V1_t contract;
    pd_Vecu8_t code;
} pd_evm_set_code_V1_t;

#define PD_CALL_EVM_SELFDESTRUCT_V1 13
typedef struct {
    pd_EvmAddress_V1_t contract;
} pd_evm_selfdestruct_V1_t;

#define PD_CALL_EVMACCOUNTS_CLAIM_ACCOUNT_V1 0
typedef struct {
    pd_EvmAddress_V1_t eth_address;
    pd_Eip712Signature_V1_t eth_signature;
} pd_evmaccounts_claim_account_V1_t;

#define PD_CALL_EVMACCOUNTS_CLAIM_DEFAULT_ACCOUNT_V1 1
typedef struct {
} pd_evmaccounts_claim_default_account_V1_t;

#define PD_CALL_STABLEASSET_MINT_V1 1
typedef struct {
    pd_StableAssetPoolId_V1_t pool_id;
    pd_VecBalance_t amounts;
    pd_Balance_t min_mint_amount;
} pd_stableasset_mint_V1_t;

#define PD_CALL_STABLEASSET_SWAP_V1 2
typedef struct {
    pd_StableAssetPoolId_V1_t pool_id;
    pd_PoolTokenIndex_V1_t i;
    pd_PoolTokenIndex_V1_t j;
    pd_Balance_t dx;
    pd_Balance_t min_dy;
    pd_u32_t asset_length;
} pd_stableasset_swap_V1_t;

#define PD_CALL_STABLEASSET_REDEEM_PROPORTION_V1 3
typedef struct {
    pd_StableAssetPoolId_V1_t pool_id;
    pd_Balance_t amount;
    pd_VecBalance_t min_redeem_amounts;
} pd_stableasset_redeem_proportion_V1_t;

#define PD_CALL_STABLEASSET_REDEEM_SINGLE_V1 4
typedef struct {
    pd_StableAssetPoolId_V1_t pool_id;
    pd_Balance_t amount;
    pd_PoolTokenIndex_V1_t i;
    pd_Balance_t min_redeem_amount;
    pd_u32_t asset_length;
} pd_stableasset_redeem_single_V1_t;

#define PD_CALL_STABLEASSET_REDEEM_MULTI_V1 5
typedef struct {
    pd_StableAssetPoolId_V1_t pool_id;
    pd_VecBalance_t amounts;
    pd_Balance_t max_redeem_amount;
} pd_stableasset_redeem_multi_V1_t;

#endif

typedef union {
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
    pd_utility_force_batch_V1_t utility_force_batch_V1;
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_proxy_remove_proxies_V1_t proxy_remove_proxies_V1;
    pd_proxy_anonymous_V1_t proxy_anonymous_V1;
    pd_proxy_kill_anonymous_V1_t proxy_kill_anonymous_V1;
    pd_proxy_announce_V1_t proxy_announce_V1;
    pd_proxy_remove_announcement_V1_t proxy_remove_announcement_V1;
    pd_proxy_reject_announcement_V1_t proxy_reject_announcement_V1;
    pd_proxy_proxy_announced_V1_t proxy_proxy_announced_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_currencies_update_balance_V1_t currencies_update_balance_V1;
    pd_currencies_sweep_dust_V1_t currencies_sweep_dust_V1;
    pd_vesting_claim_V1_t vesting_claim_V1;
    pd_transactionpayment_set_alternative_fee_swap_path_V1_t transactionpayment_set_alternative_fee_swap_path_V1;
    pd_transactionpayment_disable_charge_fee_pool_V1_t transactionpayment_disable_charge_fee_pool_V1;
    pd_transactionpayment_with_fee_path_V1_t transactionpayment_with_fee_path_V1;
    pd_transactionpayment_with_fee_currency_V1_t transactionpayment_with_fee_currency_V1;
    pd_transactionpayment_with_fee_paid_by_V1_t transactionpayment_with_fee_paid_by_V1;
    pd_transactionpayment_with_fee_aggregated_path_V1_t transactionpayment_with_fee_aggregated_path_V1;
    pd_bounties_propose_bounty_V1_t bounties_propose_bounty_V1;
    pd_bounties_approve_bounty_V1_t bounties_approve_bounty_V1;
    pd_bounties_propose_curator_V1_t bounties_propose_curator_V1;
    pd_bounties_unassign_curator_V1_t bounties_unassign_curator_V1;
    pd_bounties_accept_curator_V1_t bounties_accept_curator_V1;
    pd_bounties_award_bounty_V1_t bounties_award_bounty_V1;
    pd_bounties_claim_bounty_V1_t bounties_claim_bounty_V1;
    pd_bounties_close_bounty_V1_t bounties_close_bounty_V1;
    pd_bounties_extend_bounty_expiry_V1_t bounties_extend_bounty_expiry_V1;
    pd_collatorselection_set_invulnerables_V1_t collatorselection_set_invulnerables_V1;
    pd_collatorselection_set_desired_candidates_V1_t collatorselection_set_desired_candidates_V1;
    pd_collatorselection_set_candidacy_bond_V1_t collatorselection_set_candidacy_bond_V1;
    pd_collatorselection_register_as_candidate_V1_t collatorselection_register_as_candidate_V1;
    pd_collatorselection_register_candidate_V1_t collatorselection_register_candidate_V1;
    pd_collatorselection_leave_intent_V1_t collatorselection_leave_intent_V1;
    pd_collatorselection_withdraw_bond_V1_t collatorselection_withdraw_bond_V1;
    pd_xcmpqueue_service_overweight_V1_t xcmpqueue_service_overweight_V1;
    pd_xcmpqueue_suspend_xcm_execution_V1_t xcmpqueue_suspend_xcm_execution_V1;
    pd_xcmpqueue_resume_xcm_execution_V1_t xcmpqueue_resume_xcm_execution_V1;
    pd_xcmpqueue_update_suspend_threshold_V1_t xcmpqueue_update_suspend_threshold_V1;
    pd_xcmpqueue_update_drop_threshold_V1_t xcmpqueue_update_drop_threshold_V1;
    pd_xcmpqueue_update_resume_threshold_V1_t xcmpqueue_update_resume_threshold_V1;
    pd_xcmpqueue_update_threshold_weight_V1_t xcmpqueue_update_threshold_weight_V1;
    pd_xcmpqueue_update_weight_restrict_decay_V1_t xcmpqueue_update_weight_restrict_decay_V1;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V1_t xcmpqueue_update_xcmp_max_individual_weight_V1;
    pd_xtokens_transfer_V1_t xtokens_transfer_V1;
    pd_democracy_propose_V1_t democracy_propose_V1;
    pd_democracy_second_V1_t democracy_second_V1;
    pd_democracy_emergency_cancel_V1_t democracy_emergency_cancel_V1;
    pd_democracy_external_propose_V1_t democracy_external_propose_V1;
    pd_democracy_external_propose_majority_V1_t democracy_external_propose_majority_V1;
    pd_democracy_external_propose_default_V1_t democracy_external_propose_default_V1;
    pd_democracy_fast_track_V1_t democracy_fast_track_V1;
    pd_democracy_veto_external_V1_t democracy_veto_external_V1;
    pd_democracy_cancel_referendum_V1_t democracy_cancel_referendum_V1;
    pd_democracy_undelegate_V1_t democracy_undelegate_V1;
    pd_democracy_clear_public_proposals_V1_t democracy_clear_public_proposals_V1;
    pd_democracy_note_preimage_V1_t democracy_note_preimage_V1;
    pd_democracy_note_preimage_operational_V1_t democracy_note_preimage_operational_V1;
    pd_democracy_note_imminent_preimage_V1_t democracy_note_imminent_preimage_V1;
    pd_democracy_note_imminent_preimage_operational_V1_t democracy_note_imminent_preimage_operational_V1;
    pd_democracy_reap_preimage_V1_t democracy_reap_preimage_V1;
    pd_democracy_unlock_V1_t democracy_unlock_V1;
    pd_democracy_cancel_proposal_V1_t democracy_cancel_proposal_V1;
    pd_dex_swap_with_exact_target_V1_t dex_swap_with_exact_target_V1;
    pd_dex_add_provision_V1_t dex_add_provision_V1;
    pd_dex_claim_dex_share_V1_t dex_claim_dex_share_V1;
    pd_dex_list_provisioning_V1_t dex_list_provisioning_V1;
    pd_dex_update_provisioning_parameters_V1_t dex_update_provisioning_parameters_V1;
    pd_dex_end_provisioning_V1_t dex_end_provisioning_V1;
    pd_dex_enable_trading_pair_V1_t dex_enable_trading_pair_V1;
    pd_dex_disable_trading_pair_V1_t dex_disable_trading_pair_V1;
    pd_dex_refund_provision_V1_t dex_refund_provision_V1;
    pd_dex_abort_provisioning_V1_t dex_abort_provisioning_V1;
    pd_honzon_close_loan_has_debit_by_dex_V1_t honzon_close_loan_has_debit_by_dex_V1;
    pd_honzon_transfer_loan_from_V1_t honzon_transfer_loan_from_V1;
    pd_honzon_authorize_V1_t honzon_authorize_V1;
    pd_honzon_unauthorize_V1_t honzon_unauthorize_V1;
    pd_honzon_unauthorize_all_V1_t honzon_unauthorize_all_V1;
    pd_honzon_expand_position_collateral_V1_t honzon_expand_position_collateral_V1;
    pd_honzon_shrink_position_debit_V1_t honzon_shrink_position_debit_V1;
    pd_honzon_adjust_loan_by_debit_value_V1_t honzon_adjust_loan_by_debit_value_V1;
    pd_honzon_transfer_debit_V1_t honzon_transfer_debit_V1;
    pd_homa_claim_redemption_V1_t homa_claim_redemption_V1;
    pd_homa_reset_current_era_V1_t homa_reset_current_era_V1;
    pd_homa_force_bump_current_era_V1_t homa_force_bump_current_era_V1;
    pd_incentives_deposit_dex_share_V1_t incentives_deposit_dex_share_V1;
    pd_incentives_claim_rewards_V1_t incentives_claim_rewards_V1;
    pd_nft_transfer_V1_t nft_transfer_V1;
    pd_evm_eth_call_V1_t evm_eth_call_V1;
    pd_evm_call_V1_t evm_call_V1;
    pd_evm_create_V1_t evm_create_V1;
    pd_evm_create2_V1_t evm_create2_V1;
    pd_evm_transfer_maintainer_V1_t evm_transfer_maintainer_V1;
    pd_evm_publish_contract_V1_t evm_publish_contract_V1;
    pd_evm_publish_free_V1_t evm_publish_free_V1;
    pd_evm_enable_contract_development_V1_t evm_enable_contract_development_V1;
    pd_evm_disable_contract_development_V1_t evm_disable_contract_development_V1;
    pd_evm_set_code_V1_t evm_set_code_V1;
    pd_evm_selfdestruct_V1_t evm_selfdestruct_V1;
    pd_evmaccounts_claim_account_V1_t evmaccounts_claim_account_V1;
    pd_evmaccounts_claim_default_account_V1_t evmaccounts_claim_default_account_V1;
    pd_stableasset_mint_V1_t stableasset_mint_V1;
    pd_stableasset_swap_V1_t stableasset_swap_V1;
    pd_stableasset_redeem_proportion_V1_t stableasset_redeem_proportion_V1;
    pd_stableasset_redeem_single_V1_t stableasset_redeem_single_V1;
    pd_stableasset_redeem_multi_V1_t stableasset_redeem_multi_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_PROXY_PROXY_V1 0
typedef struct {
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V1_t;

#define PD_CALL_PROXY_ADD_PROXY_V1 1
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V1 2
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#define PD_CALL_CURRENCIES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CurrencyId_V1_t currency_id;
    pd_Compactu128_t amount;
} pd_currencies_transfer_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_CURRENCIES_TRANSFER_NATIVE_CURRENCY_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_Compactu128_t amount;
} pd_currencies_transfer_native_currency_V1_t;

#define PD_CALL_DEX_SWAP_WITH_EXACT_SUPPLY_V1 0
typedef struct {
    pd_VecCurrencyId_V1_t path;
    pd_Compactu128_t supply_amount;
    pd_Compactu128_t min_target_amount;
} pd_dex_swap_with_exact_supply_V1_t;

#define PD_CALL_DEX_ADD_LIQUIDITY_V1 2
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
    pd_Compactu128_t max_amount_a;
    pd_Compactu128_t max_amount_b;
    pd_Compactu128_t min_share_increment;
    pd_bool_t stake_increment_share;
} pd_dex_add_liquidity_V1_t;

#define PD_CALL_DEX_REMOVE_LIQUIDITY_V1 5
typedef struct {
    pd_CurrencyId_V1_t currency_id_a;
    pd_CurrencyId_V1_t currency_id_b;
    pd_Compactu128_t remove_share;
    pd_Compactu128_t min_withdrawn_a;
    pd_Compactu128_t min_withdrawn_b;
    pd_bool_t by_unstake;
} pd_dex_remove_liquidity_V1_t;

#define PD_CALL_AGGREGATEDDEX_SWAP_WITH_EXACT_SUPPLY_V1 0
typedef struct {
    pd_VecSwapPath_V1_t paths;
    pd_CompactBalance_t supply_amount;
    pd_CompactBalance_t min_target_amount;
} pd_aggregateddex_swap_with_exact_supply_V1_t;

#define PD_CALL_AGGREGATEDDEX_SWAP_WITH_EXACT_TARGET_V1 1
typedef struct {
    pd_VecSwapPath_V1_t paths;
    pd_CompactBalance_t target_amount;
    pd_CompactBalance_t max_supply_amount;
} pd_aggregateddex_swap_with_exact_target_V1_t;

#define PD_CALL_AGGREGATEDDEX_UPDATE_AGGREGATED_SWAP_PATHS_V1 2
typedef struct {
    pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t updates;
} pd_aggregateddex_update_aggregated_swap_paths_V1_t;

#define PD_CALL_HONZON_ADJUST_LOAN_V1 0
typedef struct {
    pd_CurrencyId_V1_t currency_id;
    pd_Amount_V1_t collateral_adjustment;
    pd_Amount_V1_t debit_adjustment;
} pd_honzon_adjust_loan_V1_t;

#define PD_CALL_HOMA_MINT_V1 0
typedef struct {
    pd_Compactu128_t amount;
} pd_homa_mint_V1_t;

#define PD_CALL_HOMA_REQUEST_REDEEM_V1 1
typedef struct {
    pd_Compactu128_t amount;
    pd_bool_t allow_fast_match;
} pd_homa_request_redeem_V1_t;

#define PD_CALL_HOMA_FAST_MATCH_REDEEMS_V1 2
typedef struct {
    pd_VecAccountId_V1_t redeemer_list;
} pd_homa_fast_match_redeems_V1_t;

#define PD_CALL_HOMA_FAST_MATCH_REDEEMS_COMPLETELY_V1 9
typedef struct {
    pd_VecAccountId_V1_t redeemer_list;
} pd_homa_fast_match_redeems_completely_V1_t;

#define PD_CALL_INCENTIVES_WITHDRAW_DEX_SHARE_V1 1
typedef struct {
    pd_CurrencyId_V1_t lp_currency_id;
    pd_Compactu128_t amount;
} pd_incentives_withdraw_dex_share_V1_t;

#endif

typedef union {
    pd_proxy_proxy_V1_t proxy_proxy_V1;
    pd_proxy_add_proxy_V1_t proxy_add_proxy_V1;
    pd_proxy_remove_proxy_V1_t proxy_remove_proxy_V1;
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
    pd_currencies_transfer_V1_t currencies_transfer_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_currencies_transfer_native_currency_V1_t currencies_transfer_native_currency_V1;
    pd_dex_swap_with_exact_supply_V1_t dex_swap_with_exact_supply_V1;
    pd_dex_add_liquidity_V1_t dex_add_liquidity_V1;
    pd_dex_remove_liquidity_V1_t dex_remove_liquidity_V1;
    pd_aggregateddex_swap_with_exact_supply_V1_t aggregateddex_swap_with_exact_supply_V1;
    pd_aggregateddex_swap_with_exact_target_V1_t aggregateddex_swap_with_exact_target_V1;
    pd_aggregateddex_update_aggregated_swap_paths_V1_t aggregateddex_update_aggregated_swap_paths_V1;
    pd_honzon_adjust_loan_V1_t honzon_adjust_loan_V1;
    pd_homa_mint_V1_t homa_mint_V1;
    pd_homa_request_redeem_V1_t homa_request_redeem_V1;
    pd_homa_fast_match_redeems_V1_t homa_fast_match_redeems_V1;
    pd_homa_fast_match_redeems_completely_V1_t homa_fast_match_redeems_completely_V1;
    pd_incentives_withdraw_dex_share_V1_t incentives_withdraw_dex_share_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
