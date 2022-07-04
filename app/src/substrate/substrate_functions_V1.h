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
parser_error_t _readAccountId32_V1(parser_context_t* c, pd_AccountId32_V1_t* v);
parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v);
parser_error_t _readAccountIndex64_V1(parser_context_t* c, pd_AccountIndex64_V1_t* v);
parser_error_t _readAccountKey20_V1(parser_context_t* c, pd_AccountKey20_V1_t* v);
parser_error_t _readAmount_V1(parser_context_t* c, pd_Amount_V1_t* v);
parser_error_t _readBodyId_V1(parser_context_t* c, pd_BodyId_V1_t* v);
parser_error_t _readBodyPart_V1(parser_context_t* c, pd_BodyPart_V1_t* v);
parser_error_t _readBoxVersionedMultiLocation_V1(parser_context_t* c, pd_BoxVersionedMultiLocation_V1_t* v);
parser_error_t _readCallHashOf_V1(parser_context_t* c, pd_CallHashOf_V1_t* v);
parser_error_t _readClassIdOfTTokenIdOfT_V1(parser_context_t* c, pd_ClassIdOfTTokenIdOfT_V1_t* v);
parser_error_t _readClassIdOfT_V1(parser_context_t* c, pd_ClassIdOfT_V1_t* v);
parser_error_t _readCompactAccountIndex_V1(parser_context_t* c, pd_CompactAccountIndex_V1_t* v);
parser_error_t _readCurrencyId_V1(parser_context_t* c, pd_CurrencyId_V1_t* v);
parser_error_t _readDexShareFixed_V1(parser_context_t* c, pd_DexShareFixed_V1_t* v);
parser_error_t _readDexShare_V1(parser_context_t* c, pd_DexShare_V1_t* v);
parser_error_t _readEcdsaSignature_V1(parser_context_t* c, pd_EcdsaSignature_V1_t* v);
parser_error_t _readEd25519Signature_V1(parser_context_t* c, pd_Ed25519Signature_V1_t* v);
parser_error_t _readEip712Signature_V1(parser_context_t* c, pd_Eip712Signature_V1_t* v);
parser_error_t _readEraIndex_V1(parser_context_t* c, pd_EraIndex_V1_t* v);
parser_error_t _readEvmAddress_V1(parser_context_t* c, pd_EvmAddress_V1_t* v);
parser_error_t _readFraction_V1(parser_context_t* c, pd_Fraction_V1_t* v);
parser_error_t _readJunctionV0X1_V1(parser_context_t* c, pd_JunctionV0X1_V1_t* v);
parser_error_t _readJunctionV0X2_V1(parser_context_t* c, pd_JunctionV0X2_V1_t* v);
parser_error_t _readJunctionV0X3_V1(parser_context_t* c, pd_JunctionV0X3_V1_t* v);
parser_error_t _readJunctionV0X4_V1(parser_context_t* c, pd_JunctionV0X4_V1_t* v);
parser_error_t _readJunctionV0X5_V1(parser_context_t* c, pd_JunctionV0X5_V1_t* v);
parser_error_t _readJunctionV0X6_V1(parser_context_t* c, pd_JunctionV0X6_V1_t* v);
parser_error_t _readJunctionV0X7_V1(parser_context_t* c, pd_JunctionV0X7_V1_t* v);
parser_error_t _readJunctionV0X8_V1(parser_context_t* c, pd_JunctionV0X8_V1_t* v);
parser_error_t _readJunctionV0_V1(parser_context_t* c, pd_JunctionV0_V1_t* v);
parser_error_t _readJunctionV1X1_V1(parser_context_t* c, pd_JunctionV1X1_V1_t* v);
parser_error_t _readJunctionV1X2_V1(parser_context_t* c, pd_JunctionV1X2_V1_t* v);
parser_error_t _readJunctionV1X3_V1(parser_context_t* c, pd_JunctionV1X3_V1_t* v);
parser_error_t _readJunctionV1X4_V1(parser_context_t* c, pd_JunctionV1X4_V1_t* v);
parser_error_t _readJunctionV1X5_V1(parser_context_t* c, pd_JunctionV1X5_V1_t* v);
parser_error_t _readJunctionV1X6_V1(parser_context_t* c, pd_JunctionV1X6_V1_t* v);
parser_error_t _readJunctionV1X7_V1(parser_context_t* c, pd_JunctionV1X7_V1_t* v);
parser_error_t _readJunctionV1X8_V1(parser_context_t* c, pd_JunctionV1X8_V1_t* v);
parser_error_t _readJunctionV1_V1(parser_context_t* c, pd_JunctionV1_V1_t* v);
parser_error_t _readJunctionsV0_V1(parser_context_t* c, pd_JunctionsV0_V1_t* v);
parser_error_t _readJunctionsV1_V1(parser_context_t* c, pd_JunctionsV1_V1_t* v);
parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v);
parser_error_t _readLookupasStaticLookupSource_V1(parser_context_t* c, pd_LookupasStaticLookupSource_V1_t* v);
parser_error_t _readMultiLocationV0_V1(parser_context_t* c, pd_MultiLocationV0_V1_t* v);
parser_error_t _readMultiLocationV1_V1(parser_context_t* c, pd_MultiLocationV1_V1_t* v);
parser_error_t _readMultiSignature_V1(parser_context_t* c, pd_MultiSignature_V1_t* v);
parser_error_t _readNetworkId_V1(parser_context_t* c, pd_NetworkId_V1_t* v);
parser_error_t _readOpaqueCall_V1(parser_context_t* c, pd_OpaqueCall_V1_t* v);
parser_error_t _readOptionProxyType_V1(parser_context_t* c, pd_OptionProxyType_V1_t* v);
parser_error_t _readOptionTimepoint_V1(parser_context_t* c, pd_OptionTimepoint_V1_t* v);
parser_error_t _readOptionVecCurrencyId_V1(parser_context_t* c, pd_OptionVecCurrencyId_V1_t* v);
parser_error_t _readOptionVecSwapPath_V1(parser_context_t* c, pd_OptionVecSwapPath_V1_t* v);
parser_error_t _readOverweightIndex_V1(parser_context_t* c, pd_OverweightIndex_V1_t* v);
parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v);
parser_error_t _readPlurality_V1(parser_context_t* c, pd_Plurality_V1_t* v);
parser_error_t _readPoolId_V1(parser_context_t* c, pd_PoolId_V1_t* v);
parser_error_t _readPoolTokenIndex_V1(parser_context_t* c, pd_PoolTokenIndex_V1_t* v);
parser_error_t _readProxyType_V1(parser_context_t* c, pd_ProxyType_V1_t* v);
parser_error_t _readReferendumIndex_V1(parser_context_t* c, pd_ReferendumIndex_V1_t* v);
parser_error_t _readSr25519Signature_V1(parser_context_t* c, pd_Sr25519Signature_V1_t* v);
parser_error_t _readStableAssetPoolId_V1(parser_context_t* c, pd_StableAssetPoolId_V1_t* v);
parser_error_t _readSwapPath_V1(parser_context_t* c, pd_SwapPath_V1_t* v);
parser_error_t _readTaiga_V1(parser_context_t* c, pd_Taiga_V1_t* v);
parser_error_t _readTimepoint_V1(parser_context_t* c, pd_Timepoint_V1_t* v);
parser_error_t _readTokenIdOfT_V1(parser_context_t* c, pd_TokenIdOfT_V1_t* v);
parser_error_t _readTokenSymbol_V1(parser_context_t* c, pd_TokenSymbol_V1_t* v);
parser_error_t _readTransactionAction_V1(parser_context_t* c, pd_TransactionAction_V1_t* v);
parser_error_t _readTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1(parser_context_t* c, pd_TupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t* v);
parser_error_t _readVecAccessListItem_V1(parser_context_t* c, pd_VecAccessListItem_V1_t* v);
parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v);
parser_error_t _readVecCurrencyId_V1(parser_context_t* c, pd_VecCurrencyId_V1_t* v);
parser_error_t _readVecSwapPath_V1(parser_context_t* c, pd_VecSwapPath_V1_t* v);
parser_error_t _readVecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1(parser_context_t* c, pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t* v);
parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v);
parser_error_t _readu8_array_32_V1(parser_context_t* c, pd_u8_array_32_V1_t* v);

// toString functions
parser_error_t _toStringAccessListItem_V1(
    const pd_AccessListItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V1(
    const pd_AccountId32_V1_t* v,
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

parser_error_t _toStringAccountIndex64_V1(
    const pd_AccountIndex64_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V1(
    const pd_AccountKey20_V1_t* v,
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

parser_error_t _toStringBodyId_V1(
    const pd_BodyId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V1(
    const pd_BodyPart_V1_t* v,
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

parser_error_t _toStringCallHashOf_V1(
    const pd_CallHashOf_V1_t* v,
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

parser_error_t _toStringEcdsaSignature_V1(
    const pd_EcdsaSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V1(
    const pd_Ed25519Signature_V1_t* v,
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

parser_error_t _toStringFraction_V1(
    const pd_Fraction_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1_V1(
    const pd_JunctionV0X1_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2_V1(
    const pd_JunctionV0X2_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3_V1(
    const pd_JunctionV0X3_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4_V1(
    const pd_JunctionV0X4_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5_V1(
    const pd_JunctionV0X5_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6_V1(
    const pd_JunctionV0X6_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7_V1(
    const pd_JunctionV0X7_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8_V1(
    const pd_JunctionV0X8_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0_V1(
    const pd_JunctionV0_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1_V1(
    const pd_JunctionV1X1_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2_V1(
    const pd_JunctionV1X2_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3_V1(
    const pd_JunctionV1X3_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4_V1(
    const pd_JunctionV1X4_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5_V1(
    const pd_JunctionV1X5_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6_V1(
    const pd_JunctionV1X6_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7_V1(
    const pd_JunctionV1X7_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8_V1(
    const pd_JunctionV1X8_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1_V1(
    const pd_JunctionV1_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0_V1(
    const pd_JunctionsV0_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1_V1(
    const pd_JunctionsV1_V1_t* v,
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

parser_error_t _toStringMultiLocationV0_V1(
    const pd_MultiLocationV0_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V1(
    const pd_MultiLocationV1_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V1(
    const pd_MultiSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V1(
    const pd_NetworkId_V1_t* v,
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

parser_error_t _toStringOptionProxyType_V1(
    const pd_OptionProxyType_V1_t* v,
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

parser_error_t _toStringOptionVecSwapPath_V1(
    const pd_OptionVecSwapPath_V1_t* v,
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

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V1(
    const pd_Plurality_V1_t* v,
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

parser_error_t _toStringProxyType_V1(
    const pd_ProxyType_V1_t* v,
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

parser_error_t _toStringSr25519Signature_V1(
    const pd_Sr25519Signature_V1_t* v,
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

parser_error_t _toStringSwapPath_V1(
    const pd_SwapPath_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTaiga_V1(
    const pd_Taiga_V1_t* v,
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

parser_error_t _toStringTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1(
    const pd_TupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t* v,
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

parser_error_t _toStringVecCurrencyId_V1(
    const pd_VecCurrencyId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSwapPath_V1(
    const pd_VecSwapPath_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1(
    const pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t* v,
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

parser_error_t _toStringu8_array_32_V1(
    const pd_u8_array_32_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
