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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    pd_Compactu32_t nom;
    pd_Compactu32_t denom;
} pd_Fraction_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Vecu8_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V1_t fraction;
    };
} pd_BodyPart_V1_t;

typedef struct {
    uint8_t value;
    pd_Vecu8_t named;
} pd_NetworkId_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V1_t;

typedef struct {
    pd_NetworkId_V1_t networkId;
    pd_u8_array_32_V1_t key;
} pd_AccountId32_V1_t;

typedef struct {
    pd_NetworkId_V1_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V1_t;

typedef struct {
    pd_NetworkId_V1_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V1_t;

typedef struct {
    pd_BodyId_V1_t id;
    pd_BodyPart_V1_t part;
} pd_Plurality_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V1_t accountId32;
        pd_AccountIndex64_V1_t accountIndex64;
        pd_AccountKey20_V1_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Vecu8_t generalKey;
        pd_Plurality_V1_t plurality;
    };
} pd_JunctionV0_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction;
} pd_JunctionV0X1_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
} pd_JunctionV0X2_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
} pd_JunctionV0X3_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
} pd_JunctionV0X4_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
} pd_JunctionV0X5_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
    pd_JunctionV0_V1_t junction5;
} pd_JunctionV0X6_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
    pd_JunctionV0_V1_t junction5;
    pd_JunctionV0_V1_t junction6;
} pd_JunctionV0X7_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
    pd_JunctionV0_V1_t junction5;
    pd_JunctionV0_V1_t junction6;
    pd_JunctionV0_V1_t junction7;
} pd_JunctionV0X8_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction;
} pd_JunctionV1X1_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
} pd_JunctionV1X2_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
} pd_JunctionV1X3_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
} pd_JunctionV1X4_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
} pd_JunctionV1X5_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
    pd_JunctionV0_V1_t junction5;
} pd_JunctionV1X6_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
    pd_JunctionV0_V1_t junction5;
    pd_JunctionV0_V1_t junction6;
} pd_JunctionV1X7_V1_t;

typedef struct {
    pd_JunctionV0_V1_t junction0;
    pd_JunctionV0_V1_t junction1;
    pd_JunctionV0_V1_t junction2;
    pd_JunctionV0_V1_t junction3;
    pd_JunctionV0_V1_t junction4;
    pd_JunctionV0_V1_t junction5;
    pd_JunctionV0_V1_t junction6;
    pd_JunctionV0_V1_t junction7;
} pd_JunctionV1X8_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV0X1_V1_t x1;
        pd_JunctionV0X2_V1_t x2;
        pd_JunctionV0X3_V1_t x3;
        pd_JunctionV0X4_V1_t x4;
        pd_JunctionV0X5_V1_t x5;
        pd_JunctionV0X6_V1_t x6;
        pd_JunctionV0X7_V1_t x7;
        pd_JunctionV0X8_V1_t x8;
    };
} pd_JunctionsV0_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV1X1_V1_t x1;
        pd_JunctionV1X2_V1_t x2;
        pd_JunctionV1X3_V1_t x3;
        pd_JunctionV1X4_V1_t x4;
        pd_JunctionV1X5_V1_t x5;
        pd_JunctionV1X6_V1_t x6;
        pd_JunctionV1X7_V1_t x7;
        pd_JunctionV1X8_V1_t x8;
    };
} pd_JunctionsV1_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EvmAddress_V1_t;

typedef struct {
    pd_JunctionsV0_V1_t junctions;
} pd_MultiLocationV0_V1_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV1_V1_t interior;
} pd_MultiLocationV1_V1_t;

typedef struct {
    uint8_t value;
} pd_TokenSymbol_V1_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_u128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstance_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V1_t multilocationV0;
        pd_MultiLocationV1_V1_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_TokenSymbol_V1_t token;
        pd_EvmAddress_V1_t erc20;
        uint32_t liquidCrowdloan;
        uint16_t foreignAsset;
    };
} pd_DexShare_V1_t;

typedef struct {
    pd_Vecu8_t id;
    pd_Compactu128_t amount;
} pd_AbstractFungible_V1_t;

typedef struct {
    pd_Vecu8_t _class;
    pd_AssetInstance_V1_t instance;
} pd_AbstractNonFungible_V1_t;

typedef struct {
    pd_MultiLocationV0_V1_t id;
    pd_Compactu128_t amount;
} pd_ConcreteFungible_V1_t;

typedef struct {
    pd_MultiLocationV0_V1_t _class;
    pd_AssetInstance_V1_t instance;
} pd_ConcreteNonFungible_V1_t;

typedef struct {
    pd_DexShare_V1_t dexShare1;
    pd_DexShare_V1_t dexShare2;
} pd_DexShareFixed_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t fungible;
        pd_AssetInstance_V1_t nonFungible;
    };
} pd_Fungibility_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_BoxVersionedMultiLocation_V1_t concrete;
        pd_Vecu8_t abstract;
    };
} pd_MultiAssetId_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_TokenSymbol_V1_t token;
        pd_DexShareFixed_V1_t dexShare;
        pd_EvmAddress_V1_t erc20;
        uint32_t stableAssetPoolToken;
        uint32_t liquidCrowdloan;
        uint16_t foreignAsset;
    };
} pd_CurrencyId_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Vecu8_t abstract;
        pd_MultiLocationV0_V1_t concrete;
        pd_AbstractFungible_V1_t abstractFungible;
        pd_AbstractNonFungible_V1_t abstractNonFungible;
        pd_ConcreteFungible_V1_t concreteFungible;
        pd_ConcreteNonFungible_V1_t concreteNonFungible;
    };
} pd_MultiAssetV0_V1_t;

typedef struct {
    pd_MultiAssetId_V1_t assetId;
    pd_Fungibility_V1_t fungibility;
} pd_MultiAssetV1_V1_t;

typedef struct {
    uint8_t value;
} pd_Vote_V1_t;

typedef struct {
    pd_EvmAddress_V1_t address;
    pd_VecH256_t storageKeys;
} pd_AccessListItem_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V1_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V1_t;

typedef struct {
    pd_Vote_V1_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V1_t;

typedef struct {
    uint32_t value;
} pd_AssetId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AtLeast64BitUnsigned_V1_t;

typedef struct {
    uint32_t value;
} pd_ClassIdOfT_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V1_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Rate_V1_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_V1_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SwapPath_V1_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V1_t;

typedef struct {
    uint64_t value;
} pd_TokenIdOfT_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleCurrencyIdBalance_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleOracleKeyOracleValue_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TuplePoolIdRate_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TuplePoolIdVecTupleCurrencyIdBalance_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleXcmInterfaceOperationOptionWeightOptionBalance_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Tupleu16OptionBalanceOptionVecUnlockChunk_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCurrencyId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV0_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV1_V1_t;

typedef struct {
    pd_BlockNumber_t start;
    pd_BlockNumber_t period;
    uint32_t period_count;
    pd_Balance_t balance;
} pd_VestingScheduleOf_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V1_t voteStandard;
        pd_AccountVoteSplit_V1_t voteSplit;
    };
} pd_AccountVote_V1_t;

typedef struct {
    pd_u128_t value;
} pd_Amount_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiAssetV0_V1_t multiassetV0;
        pd_MultiAssetV1_V1_t multiassetV1;
    };
} pd_BoxVersionedMultiAsset_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_V1_t vecMultiassetV0;
        pd_VecMultiAssetV1_V1_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_V1_t;

typedef struct {
    pd_ClassIdOfT_V1_t value1;
    pd_TokenIdOfT_V1_t value2;
} pd_ClassIdOfTTokenIdOfT_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V1_t id;
        pd_CompactAccountIndex_V1_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_V1_t ed25519;
        pd_Sr25519Signature_V1_t sr25519;
        pd_EcdsaSignature_V1_t ecdsa;
    };
} pd_MultiSignature_V1_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V1_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V1_t contained;
} pd_OptionTimepoint_V1_t;

typedef struct {
    uint8_t value;
    pd_CurrencyId_V1_t currencyid;
} pd_PoolId_V1_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V1_t dependency;
} pd_Priority_V1_t;

typedef struct {
    uint8_t value;
    pd_Balance_t balance1;
    pd_Balance_t balance2;
} pd_SwapLimitBalance_V1_t;

typedef struct {
    uint8_t value;
    pd_EvmAddress_V1_t h160;
} pd_TransactionAction_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccessListItem_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AsOriginId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Attributes_V1_t;

typedef struct {
    uint32_t value;
} pd_AuctionId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxAssetMetadataBalanceOfT_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallOrHashOfT_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CID_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChangeBalance_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChangeOptionRate_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChangeOptionRatio_V1_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DispatchTimeBlockNumber_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Eip712Signature_V1_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ForeignAssetId_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V1_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V1_t;

typedef struct {
    uint64_t value;
} pd_Moment_V1_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V1_t contained;
} pd_OptionAccountId_V1_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V1_t contained;
} pd_OptionProxyType_V1_t;

typedef struct {
    uint8_t some;
    pd_Rate_V1_t contained;
} pd_OptionRate_V1_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V1_t contained;
} pd_OptionReferendumIndex_V1_t;

typedef struct {
    uint8_t some;
    pd_VecCurrencyId_V1_t contained;
} pd_OptionVecCurrencyId_V1_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V1_t contained;
} pd_OptionXcmVersion_V1_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V1_t contained;
} pd_OptionschedulePeriodBlockNumber_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainInherentData_V1_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V1_t;

typedef struct {
    uint32_t value;
} pd_PoolTokenIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Properties_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScheduleTaskIndex_V1_t;

typedef struct {
    uint32_t value;
} pd_StableAssetPoolId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Task_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UpwardMessage_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAtLeast64BitUnsigned_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSwapPath_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleCurrencyIdBalance_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleOracleKeyOracleValue_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePoolIdRate_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePoolIdVecTupleCurrencyIdBalance_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleXcmInterfaceOperationOptionWeightOptionBalance_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleu16OptionBalanceOptionVecUnlockChunk_V1_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V1_t;

typedef struct {
    uint64_t value;
} pd_Weight_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V1_t;

#ifdef __cplusplus
}
#endif
