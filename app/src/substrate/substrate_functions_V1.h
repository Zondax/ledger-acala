/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V1.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccessListItem_V1(parser_context_t* c, pd_AccessListItem_V1_t* v);
parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v);
parser_error_t _readAccountVoteSplit_V1(parser_context_t* c, pd_AccountVoteSplit_V1_t* v);
parser_error_t _readAccountVoteStandard_V1(parser_context_t* c, pd_AccountVoteStandard_V1_t* v);
parser_error_t _readAccountVote_V1(parser_context_t* c, pd_AccountVote_V1_t* v);
parser_error_t _readAmount_V1(parser_context_t* c, pd_Amount_V1_t* v);
parser_error_t _readAsOriginId_V1(parser_context_t* c, pd_AsOriginId_V1_t* v);
parser_error_t _readAssetId_V1(parser_context_t* c, pd_AssetId_V1_t* v);
parser_error_t _readAtLeast64BitUnsigned_V1(parser_context_t* c, pd_AtLeast64BitUnsigned_V1_t* v);
parser_error_t _readAttributes_V1(parser_context_t* c, pd_Attributes_V1_t* v);
parser_error_t _readAuctionId_V1(parser_context_t* c, pd_AuctionId_V1_t* v);
parser_error_t _readBoxAssetMetadataBalanceOfT_V1(parser_context_t* c, pd_BoxAssetMetadataBalanceOfT_V1_t* v);
parser_error_t _readBoxCallOrHashOfT_V1(parser_context_t* c, pd_BoxCallOrHashOfT_V1_t* v);
parser_error_t _readBoxMultiLocation_V1(parser_context_t* c, pd_BoxMultiLocation_V1_t* v);
parser_error_t _readBoxPalletsOrigin_V1(parser_context_t* c, pd_BoxPalletsOrigin_V1_t* v);
parser_error_t _readBoxVersionedMultiAsset_V1(parser_context_t* c, pd_BoxVersionedMultiAsset_V1_t* v);
parser_error_t _readBoxVersionedMultiAssets_V1(parser_context_t* c, pd_BoxVersionedMultiAssets_V1_t* v);
parser_error_t _readBoxVersionedMultiLocation_V1(parser_context_t* c, pd_BoxVersionedMultiLocation_V1_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V1(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V1_t* v);
parser_error_t _readBoxVersionedXcmTuple_V1(parser_context_t* c, pd_BoxVersionedXcmTuple_V1_t* v);
parser_error_t _readCID_V1(parser_context_t* c, pd_CID_V1_t* v);
parser_error_t _readCallHashOf_V1(parser_context_t* c, pd_CallHashOf_V1_t* v);
parser_error_t _readChangeBalance_V1(parser_context_t* c, pd_ChangeBalance_V1_t* v);
parser_error_t _readChangeOptionRate_V1(parser_context_t* c, pd_ChangeOptionRate_V1_t* v);
parser_error_t _readChangeOptionRatio_V1(parser_context_t* c, pd_ChangeOptionRatio_V1_t* v);
parser_error_t _readClassIdOfTTokenIdOfT_V1(parser_context_t* c, pd_ClassIdOfTTokenIdOfT_V1_t* v);
parser_error_t _readClassIdOfT_V1(parser_context_t* c, pd_ClassIdOfT_V1_t* v);
parser_error_t _readCompactAccountIndex_V1(parser_context_t* c, pd_CompactAccountIndex_V1_t* v);
parser_error_t _readConviction_V1(parser_context_t* c, pd_Conviction_V1_t* v);
parser_error_t _readCurrencyId_V1(parser_context_t* c, pd_CurrencyId_V1_t* v);
parser_error_t _readDexShareFixed_V1(parser_context_t* c, pd_DexShareFixed_V1_t* v);
parser_error_t _readDexShare_V1(parser_context_t* c, pd_DexShare_V1_t* v);
parser_error_t _readDispatchTimeBlockNumber_V1(parser_context_t* c, pd_DispatchTimeBlockNumber_V1_t* v);
parser_error_t _readEip712Signature_V1(parser_context_t* c, pd_Eip712Signature_V1_t* v);
parser_error_t _readEraIndex_V1(parser_context_t* c, pd_EraIndex_V1_t* v);
parser_error_t _readEvmAddress_V1(parser_context_t* c, pd_EvmAddress_V1_t* v);
parser_error_t _readForeignAssetId_V1(parser_context_t* c, pd_ForeignAssetId_V1_t* v);
parser_error_t _readKeyValue_V1(parser_context_t* c, pd_KeyValue_V1_t* v);
parser_error_t _readKey_V1(parser_context_t* c, pd_Key_V1_t* v);
parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v);
parser_error_t _readLookupasStaticLookupSource_V1(parser_context_t* c, pd_LookupasStaticLookupSource_V1_t* v);
parser_error_t _readMemberCount_V1(parser_context_t* c, pd_MemberCount_V1_t* v);
parser_error_t _readMoment_V1(parser_context_t* c, pd_Moment_V1_t* v);
parser_error_t _readOpaqueCall_V1(parser_context_t* c, pd_OpaqueCall_V1_t* v);
parser_error_t _readOptionAccountId_V1(parser_context_t* c, pd_OptionAccountId_V1_t* v);
parser_error_t _readOptionProxyType_V1(parser_context_t* c, pd_OptionProxyType_V1_t* v);
parser_error_t _readOptionRate_V1(parser_context_t* c, pd_OptionRate_V1_t* v);
parser_error_t _readOptionReferendumIndex_V1(parser_context_t* c, pd_OptionReferendumIndex_V1_t* v);
parser_error_t _readOptionTimepoint_V1(parser_context_t* c, pd_OptionTimepoint_V1_t* v);
parser_error_t _readOptionVecCurrencyId_V1(parser_context_t* c, pd_OptionVecCurrencyId_V1_t* v);
parser_error_t _readOptionXcmVersion_V1(parser_context_t* c, pd_OptionXcmVersion_V1_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V1(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V1_t* v);
parser_error_t _readOverweightIndex_V1(parser_context_t* c, pd_OverweightIndex_V1_t* v);
parser_error_t _readParachainInherentData_V1(parser_context_t* c, pd_ParachainInherentData_V1_t* v);
parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v);
parser_error_t _readPoolId_V1(parser_context_t* c, pd_PoolId_V1_t* v);
parser_error_t _readPoolTokenIndex_V1(parser_context_t* c, pd_PoolTokenIndex_V1_t* v);
parser_error_t _readPriority_V1(parser_context_t* c, pd_Priority_V1_t* v);
parser_error_t _readProperties_V1(parser_context_t* c, pd_Properties_V1_t* v);
parser_error_t _readProxyType_V1(parser_context_t* c, pd_ProxyType_V1_t* v);
parser_error_t _readRate_V1(parser_context_t* c, pd_Rate_V1_t* v);
parser_error_t _readReferendumIndex_V1(parser_context_t* c, pd_ReferendumIndex_V1_t* v);
parser_error_t _readScheduleTaskIndex_V1(parser_context_t* c, pd_ScheduleTaskIndex_V1_t* v);
parser_error_t _readStableAssetPoolId_V1(parser_context_t* c, pd_StableAssetPoolId_V1_t* v);
parser_error_t _readStreamDependency_V1(parser_context_t* c, pd_StreamDependency_V1_t* v);
parser_error_t _readSwapLimitBalance_V1(parser_context_t* c, pd_SwapLimitBalance_V1_t* v);
parser_error_t _readTask_V1(parser_context_t* c, pd_Task_V1_t* v);
parser_error_t _readTimepoint_V1(parser_context_t* c, pd_Timepoint_V1_t* v);
parser_error_t _readTokenIdOfT_V1(parser_context_t* c, pd_TokenIdOfT_V1_t* v);
parser_error_t _readTokenSymbol_V1(parser_context_t* c, pd_TokenSymbol_V1_t* v);
parser_error_t _readTransactionAction_V1(parser_context_t* c, pd_TransactionAction_V1_t* v);
parser_error_t _readTupleCurrencyIdBalance_V1(parser_context_t* c, pd_TupleCurrencyIdBalance_V1_t* v);
parser_error_t _readTupleOracleKeyOracleValue_V1(parser_context_t* c, pd_TupleOracleKeyOracleValue_V1_t* v);
parser_error_t _readTuplePoolIdRate_V1(parser_context_t* c, pd_TuplePoolIdRate_V1_t* v);
parser_error_t _readTuplePoolIdVecTupleCurrencyIdBalance_V1(parser_context_t* c, pd_TuplePoolIdVecTupleCurrencyIdBalance_V1_t* v);
parser_error_t _readTupleXcmInterfaceOperationOptionWeightOptionBalance_V1(parser_context_t* c, pd_TupleXcmInterfaceOperationOptionWeightOptionBalance_V1_t* v);
parser_error_t _readTupleu16OptionBalanceOptionVecUnlockChunk_V1(parser_context_t* c, pd_Tupleu16OptionBalanceOptionVecUnlockChunk_V1_t* v);
parser_error_t _readUpwardMessage_V1(parser_context_t* c, pd_UpwardMessage_V1_t* v);
parser_error_t _readVecAccessListItem_V1(parser_context_t* c, pd_VecAccessListItem_V1_t* v);
parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v);
parser_error_t _readVecAssetId_V1(parser_context_t* c, pd_VecAssetId_V1_t* v);
parser_error_t _readVecAtLeast64BitUnsigned_V1(parser_context_t* c, pd_VecAtLeast64BitUnsigned_V1_t* v);
parser_error_t _readVecCurrencyId_V1(parser_context_t* c, pd_VecCurrencyId_V1_t* v);
parser_error_t _readVecKeyValue_V1(parser_context_t* c, pd_VecKeyValue_V1_t* v);
parser_error_t _readVecKey_V1(parser_context_t* c, pd_VecKey_V1_t* v);
parser_error_t _readVecTupleCurrencyIdBalance_V1(parser_context_t* c, pd_VecTupleCurrencyIdBalance_V1_t* v);
parser_error_t _readVecTupleOracleKeyOracleValue_V1(parser_context_t* c, pd_VecTupleOracleKeyOracleValue_V1_t* v);
parser_error_t _readVecTuplePoolIdRate_V1(parser_context_t* c, pd_VecTuplePoolIdRate_V1_t* v);
parser_error_t _readVecTuplePoolIdVecTupleCurrencyIdBalance_V1(parser_context_t* c, pd_VecTuplePoolIdVecTupleCurrencyIdBalance_V1_t* v);
parser_error_t _readVecTupleXcmInterfaceOperationOptionWeightOptionBalance_V1(parser_context_t* c, pd_VecTupleXcmInterfaceOperationOptionWeightOptionBalance_V1_t* v);
parser_error_t _readVecTupleu16OptionBalanceOptionVecUnlockChunk_V1(parser_context_t* c, pd_VecTupleu16OptionBalanceOptionVecUnlockChunk_V1_t* v);
parser_error_t _readVecVestingScheduleOf_V1(parser_context_t* c, pd_VecVestingScheduleOf_V1_t* v);
parser_error_t _readVestingScheduleOf_V1(parser_context_t* c, pd_VestingScheduleOf_V1_t* v);
parser_error_t _readVote_V1(parser_context_t* c, pd_Vote_V1_t* v);
parser_error_t _readWeightLimit_V1(parser_context_t* c, pd_WeightLimit_V1_t* v);
parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v);
parser_error_t _readXcmVersion_V1(parser_context_t* c, pd_XcmVersion_V1_t* v);
parser_error_t _readschedulePeriodBlockNumber_V1(parser_context_t* c, pd_schedulePeriodBlockNumber_V1_t* v);
parser_error_t _readschedulePriority_V1(parser_context_t* c, pd_schedulePriority_V1_t* v);

// toString functions
parser_error_t _toStringAccessListItem_V1(
    const pd_AccessListItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V1(
    const pd_AccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V1(
    const pd_AccountVoteSplit_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V1(
    const pd_AccountVoteStandard_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V1(
    const pd_AccountVote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAmount_V1(
    const pd_Amount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAsOriginId_V1(
    const pd_AsOriginId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetId_V1(
    const pd_AssetId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAtLeast64BitUnsigned_V1(
    const pd_AtLeast64BitUnsigned_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAttributes_V1(
    const pd_Attributes_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuctionId_V1(
    const pd_AuctionId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxAssetMetadataBalanceOfT_V1(
    const pd_BoxAssetMetadataBalanceOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V1(
    const pd_BoxCallOrHashOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V1(
    const pd_BoxMultiLocation_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V1(
    const pd_BoxPalletsOrigin_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAsset_V1(
    const pd_BoxVersionedMultiAsset_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V1(
    const pd_BoxVersionedMultiAssets_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V1(
    const pd_BoxVersionedMultiLocation_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V1(
    const pd_BoxVersionedXcmTasSysConfigCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V1(
    const pd_BoxVersionedXcmTuple_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCID_V1(
    const pd_CID_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V1(
    const pd_CallHashOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangeBalance_V1(
    const pd_ChangeBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangeOptionRate_V1(
    const pd_ChangeOptionRate_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangeOptionRatio_V1(
    const pd_ChangeOptionRatio_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassIdOfTTokenIdOfT_V1(
    const pd_ClassIdOfTTokenIdOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassIdOfT_V1(
    const pd_ClassIdOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V1(
    const pd_CompactAccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V1(
    const pd_Conviction_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V1(
    const pd_CurrencyId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDexShareFixed_V1(
    const pd_DexShareFixed_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDexShare_V1(
    const pd_DexShare_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchTimeBlockNumber_V1(
    const pd_DispatchTimeBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEip712Signature_V1(
    const pd_Eip712Signature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V1(
    const pd_EraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEvmAddress_V1(
    const pd_EvmAddress_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringForeignAssetId_V1(
    const pd_ForeignAssetId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V1(
    const pd_KeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V1(
    const pd_Key_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V1(
    const pd_Keys_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V1(
    const pd_LookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V1(
    const pd_MemberCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V1(
    const pd_Moment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V1(
    const pd_OpaqueCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V1(
    const pd_OptionAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V1(
    const pd_OptionProxyType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRate_V1(
    const pd_OptionRate_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V1(
    const pd_OptionReferendumIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V1(
    const pd_OptionTimepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecCurrencyId_V1(
    const pd_OptionVecCurrencyId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V1(
    const pd_OptionXcmVersion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V1(
    const pd_OptionschedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V1(
    const pd_OverweightIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V1(
    const pd_ParachainInherentData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId_V1(
    const pd_PoolId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolTokenIndex_V1(
    const pd_PoolTokenIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V1(
    const pd_Priority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProperties_V1(
    const pd_Properties_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V1(
    const pd_ProxyType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRate_V1(
    const pd_Rate_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V1(
    const pd_ReferendumIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleTaskIndex_V1(
    const pd_ScheduleTaskIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStableAssetPoolId_V1(
    const pd_StableAssetPoolId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V1(
    const pd_StreamDependency_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSwapLimitBalance_V1(
    const pd_SwapLimitBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTask_V1(
    const pd_Task_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V1(
    const pd_Timepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTokenIdOfT_V1(
    const pd_TokenIdOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTokenSymbol_V1(
    const pd_TokenSymbol_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransactionAction_V1(
    const pd_TransactionAction_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCurrencyIdBalance_V1(
    const pd_TupleCurrencyIdBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleOracleKeyOracleValue_V1(
    const pd_TupleOracleKeyOracleValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePoolIdRate_V1(
    const pd_TuplePoolIdRate_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePoolIdVecTupleCurrencyIdBalance_V1(
    const pd_TuplePoolIdVecTupleCurrencyIdBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleXcmInterfaceOperationOptionWeightOptionBalance_V1(
    const pd_TupleXcmInterfaceOperationOptionWeightOptionBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleu16OptionBalanceOptionVecUnlockChunk_V1(
    const pd_Tupleu16OptionBalanceOptionVecUnlockChunk_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUpwardMessage_V1(
    const pd_UpwardMessage_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccessListItem_V1(
    const pd_VecAccessListItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V1(
    const pd_VecAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetId_V1(
    const pd_VecAssetId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAtLeast64BitUnsigned_V1(
    const pd_VecAtLeast64BitUnsigned_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCurrencyId_V1(
    const pd_VecCurrencyId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V1(
    const pd_VecKeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V1(
    const pd_VecKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleCurrencyIdBalance_V1(
    const pd_VecTupleCurrencyIdBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleOracleKeyOracleValue_V1(
    const pd_VecTupleOracleKeyOracleValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePoolIdRate_V1(
    const pd_VecTuplePoolIdRate_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePoolIdVecTupleCurrencyIdBalance_V1(
    const pd_VecTuplePoolIdVecTupleCurrencyIdBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleXcmInterfaceOperationOptionWeightOptionBalance_V1(
    const pd_VecTupleXcmInterfaceOperationOptionWeightOptionBalance_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleu16OptionBalanceOptionVecUnlockChunk_V1(
    const pd_VecTupleu16OptionBalanceOptionVecUnlockChunk_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V1(
    const pd_VecVestingScheduleOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V1(
    const pd_VestingScheduleOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V1(
    const pd_Vote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V1(
    const pd_WeightLimit_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V1(
    const pd_Weight_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V1(
    const pd_XcmVersion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V1(
    const pd_schedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V1(
    const pd_schedulePriority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
