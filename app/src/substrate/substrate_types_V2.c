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
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccessListItem_V2(parser_context_t* c, pd_AccessListItem_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readEvmAddress_V2(c, &v->address))
    CHECK_ERROR(_readVecH256(c, &v->storageKeys))
    return parser_ok;
}

parser_error_t _readAccountId32_V2(parser_context_t* c, pd_AccountId32_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V2(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32_V2(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountIdLookupOfT_V2(parser_context_t* c, pd_AccountIdLookupOfT_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V2(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V2(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAccountId_V2(parser_context_t* c, pd_AccountId_V2_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex64_V2(parser_context_t* c, pd_AccountIndex64_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V2(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountKey20_V2(parser_context_t* c, pd_AccountKey20_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V2(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readAmount_V2(parser_context_t* c, pd_Amount_V2_t* v)
{
    return _readu128(c, &v->value);
}

parser_error_t _readBodyId_V2(parser_context_t* c, pd_BodyId_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unit
        break;
    case 1: // Named
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    case 2: // Index
        CHECK_ERROR(_readCompactu32(c, &v->index))
        break;
    case 3: // Executive
    case 4: // Technical
    case 5: // Legislative
    case 6: // Judicial
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBodyPart_V2(parser_context_t* c, pd_BodyPart_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Voice
        break;
    case 1: // Members
        CHECK_ERROR(_readCompactu32(c, &v->count))
        break;
    case 2: // Fraction
    case 3: // AtleastProportion
    case 4: // MoreThanProportion
        CHECK_ERROR(_readFraction_V2(c, &v->fraction))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoundedCallOfT_V2(parser_context_t* c, pd_BoundedCallOfT_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readH256(c, &v->legacy))
        break;
    case 1:
        CHECK_ERROR(_readBytes(c, &v->_inline))
        break;
    case 2:
        CHECK_ERROR(_readTupleH256u32_V2(c, &v->lookup))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoxVersionedMultiLocation_V2(parser_context_t* c, pd_BoxVersionedMultiLocation_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiLocationV0_V2(c, &v->multilocationV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiLocationV1_V2(c, &v->multilocationV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readCallHashOf_V2(parser_context_t* c, pd_CallHashOf_V2_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readClassIdOfTTokenIdOfT_V2(parser_context_t* c, pd_ClassIdOfTTokenIdOfT_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readClassIdOfT_V2(c, &v->value1))
    CHECK_ERROR(_readTokenIdOfT_V2(c, &v->value2))
    return parser_ok;
}

parser_error_t _readClassIdOfT_V2(parser_context_t* c, pd_ClassIdOfT_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V2(parser_context_t* c, pd_CompactAccountIndex_V2_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCurrencyId_V2(parser_context_t* c, pd_CurrencyId_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_readTokenSymbol_V2(c, &v->token))
        break;
    case 1: // DexShare
        CHECK_ERROR(_readDexShareFixed_V2(c, &v->dexShare))
        break;
    case 2: // EvmAddress
        CHECK_ERROR(_readEvmAddress_V2(c, &v->erc20))
        break;
    case 3: // StableAssetPoolId
        CHECK_ERROR(_readUInt32(c, &v->stableAssetPoolToken))
        break;
    case 4: // Lease
        CHECK_ERROR(_readUInt32(c, &v->liquidCrowdloan))
        break;
    case 5: // ForeignAssetId
        CHECK_ERROR(_readUInt16(c, &v->foreignAsset))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readDexShareFixed_V2(parser_context_t* c, pd_DexShareFixed_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readDexShare_V2(c, &v->dexShare1))
    CHECK_ERROR(_readDexShare_V2(c, &v->dexShare2))
    return parser_ok;
}

parser_error_t _readDexShare_V2(parser_context_t* c, pd_DexShare_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_readTokenSymbol_V2(c, &v->token))
        break;
    case 1: // EvmAddress
        CHECK_ERROR(_readEvmAddress_V2(c, &v->erc20))
        break;
    case 2: // Lease
        CHECK_ERROR(_readUInt32(c, &v->liquidCrowdloan))
        break;
    case 3: // ForeignAssetId
        CHECK_ERROR(_readUInt16(c, &v->foreignAsset))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readEcdsaSignature_V2(parser_context_t* c, pd_EcdsaSignature_V2_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readEd25519Signature_V2(parser_context_t* c, pd_Ed25519Signature_V2_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readEip712Signature_V2(parser_context_t* c, pd_Eip712Signature_V2_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readEraIndex_V2(parser_context_t* c, pd_EraIndex_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEvmAddress_V2(parser_context_t* c, pd_EvmAddress_V2_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readFraction_V2(parser_context_t* c, pd_Fraction_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->nom))
    CHECK_ERROR(_readCompactu32(c, &v->denom))
    return parser_ok;
}

parser_error_t _readJunctionV0X1_V2(parser_context_t* c, pd_JunctionV0X1_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV0X2_V2(parser_context_t* c, pd_JunctionV0X2_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV0X3_V2(parser_context_t* c, pd_JunctionV0X3_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV0X4_V2(parser_context_t* c, pd_JunctionV0X4_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV0X5_V2(parser_context_t* c, pd_JunctionV0X5_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV0X6_V2(parser_context_t* c, pd_JunctionV0X6_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV0X7_V2(parser_context_t* c, pd_JunctionV0X7_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction5))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV0X8_V2(parser_context_t* c, pd_JunctionV0X8_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction5))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction6))
    CHECK_ERROR(_readJunctionV0_V2(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionV0_V2(parser_context_t* c, pd_JunctionV0_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parent
        break;
    case 1: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_readAccountId32_V2(c, &v->accountId32))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64_V2(c, &v->accountIndex64))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_readAccountKey20_V2(c, &v->accountKey20))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 8: // OnlyChild
        break;
    case 9: // Plurality
        CHECK_ERROR(_readPlurality_V2(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionV1X1_V2(parser_context_t* c, pd_JunctionV1X1_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV1X2_V2(parser_context_t* c, pd_JunctionV1X2_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV1X3_V2(parser_context_t* c, pd_JunctionV1X3_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV1X4_V2(parser_context_t* c, pd_JunctionV1X4_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV1X5_V2(parser_context_t* c, pd_JunctionV1X5_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV1X6_V2(parser_context_t* c, pd_JunctionV1X6_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV1X7_V2(parser_context_t* c, pd_JunctionV1X7_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction5))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV1X8_V2(parser_context_t* c, pd_JunctionV1X8_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction5))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction6))
    CHECK_ERROR(_readJunctionV1_V2(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionV1_V2(parser_context_t* c, pd_JunctionV1_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_readAccountId32_V2(c, &v->accountId32))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64_V2(c, &v->accountIndex64))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_readAccountKey20_V2(c, &v->accountKey20))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 7: // OnlyChild
        break;
    case 8: // Plurality
        CHECK_ERROR(_readPlurality_V2(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionsV0_V2(parser_context_t* c, pd_JunctionsV0_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Null
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV0X1_V2(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV0X2_V2(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV0X3_V2(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionV0X4_V2(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV0X5_V2(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV0X6_V2(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV0X7_V2(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV0X8_V2(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionsV1_V2(parser_context_t* c, pd_JunctionsV1_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV1X1_V2(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV1X2_V2(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV1X3_V2(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionV1X4_V2(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV1X5_V2(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV1X6_V2(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV1X7_V2(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV1X8_V2(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readKeys_V2(parser_context_t* c, pd_Keys_V2_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLookupasStaticLookupSource_V2(parser_context_t* c, pd_LookupasStaticLookupSource_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V2(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V2(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMultiLocationV0_V2(parser_context_t* c, pd_MultiLocationV0_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionsV0_V2(c, &v->junctions))
    return parser_ok;
}

parser_error_t _readMultiLocationV1_V2(parser_context_t* c, pd_MultiLocationV1_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->parents))
    CHECK_ERROR(_readJunctionsV1_V2(c, &v->interior))
    return parser_ok;
}

parser_error_t _readMultiSignature_V2(parser_context_t* c, pd_MultiSignature_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_readEd25519Signature_V2(c, &v->ed25519))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_readSr25519Signature_V2(c, &v->sr25519))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_readEcdsaSignature_V2(c, &v->ecdsa))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readNetworkId_V2(parser_context_t* c, pd_NetworkId_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Any
    case 2: // Polkadot
    case 3: // Kusama
        break;
    case 1: // Index
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOverweightIndex_V2(parser_context_t* c, pd_OverweightIndex_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readPerbill_V2(parser_context_t* c, pd_Perbill_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPlurality_V2(parser_context_t* c, pd_Plurality_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyId_V2(c, &v->id))
    CHECK_ERROR(_readBodyPart_V2(c, &v->part))
    return parser_ok;
}

parser_error_t _readPoolId_V2(parser_context_t* c, pd_PoolId_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 1) {
        return parser_unexpected_value;
    }
    CHECK_ERROR(_readCurrencyId_V2(c, &v->currencyid))
    return parser_ok;
}

parser_error_t _readPoolTokenIndex_V2(parser_context_t* c, pd_PoolTokenIndex_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readProxyType_V2(parser_context_t* c, pd_ProxyType_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 8) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readReferendumIndex_V2(parser_context_t* c, pd_ReferendumIndex_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readSr25519Signature_V2(parser_context_t* c, pd_Sr25519Signature_V2_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readStableAssetPoolId_V2(parser_context_t* c, pd_StableAssetPoolId_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readSwapPath_V2(parser_context_t* c, pd_SwapPath_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Dex
        CHECK_ERROR(_readVecCurrencyId_V2(c, &v->currencies))
        break;
    case 1: // Taiga
        CHECK_ERROR(_readTaiga_V2(c, &v->taiga))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTaiga_V2(parser_context_t* c, pd_Taiga_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value1))
    CHECK_ERROR(_readUInt32(c, &v->value2))
    CHECK_ERROR(_readUInt32(c, &v->value3))
    return parser_ok;
}

parser_error_t _readTimepoint_V2(parser_context_t* c, pd_Timepoint_V2_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTokenIdOfT_V2(parser_context_t* c, pd_TokenIdOfT_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readTokenSymbol_V2(parser_context_t* c, pd_TokenSymbol_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTransactionAction_V2(parser_context_t* c, pd_TransactionAction_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readEvmAddress_V2(c, &v->h160))
        break;
    case 1:
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readTupleCurrencyIdCurrencyIdOptionVecSwapPath_V2(parser_context_t* c, pd_TupleCurrencyIdCurrencyIdOptionVecSwapPath_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCurrencyId_V2(c, &v->currencyid1))
    CHECK_ERROR(_readCurrencyId_V2(c, &v->currencyid2))
    CHECK_ERROR(_readOptionVecSwapPath_V2(c, &v->paths))
    return parser_ok;
}

parser_error_t _readTupleH256u32_V2(parser_context_t* c, pd_TupleH256u32_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readH256(c, &v->h256))
    CHECK_ERROR(_readUInt32(c, &v->u32))
    return parser_ok;
}

parser_error_t _readWeightLimit_V2(parser_context_t* c, pd_WeightLimit_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unlimited
        break;
    case 1: // Limited
        CHECK_ERROR(_readCompactu64(c, &v->limited))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readWeight_V2(parser_context_t* c, pd_Weight_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu64(c, &v->refTime))
    CHECK_ERROR(_readCompactu64(c, &v->proofSize))
    return parser_ok;
}

parser_error_t _readXcmWeight_V2(parser_context_t* c, pd_XcmWeight_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readu8_array_32_V2(parser_context_t* c, pd_u8_array_32_V2_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccessListItem_V2(parser_context_t* c, pd_VecAccessListItem_V2_t* v) {
    GEN_DEF_READVECTOR(AccessListItem_V2)
}

parser_error_t _readVecAccountId_V2(parser_context_t* c, pd_VecAccountId_V2_t* v) {
    GEN_DEF_READVECTOR(AccountId_V2)
}

parser_error_t _readVecCurrencyId_V2(parser_context_t* c, pd_VecCurrencyId_V2_t* v) {
    GEN_DEF_READVECTOR(CurrencyId_V2)
}

parser_error_t _readVecSwapPath_V2(parser_context_t* c, pd_VecSwapPath_V2_t* v) {
    GEN_DEF_READVECTOR(SwapPath_V2)
}

parser_error_t _readVecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V2(parser_context_t* c, pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V2_t* v) {
    GEN_DEF_READVECTOR(TupleCurrencyIdCurrencyIdOptionVecSwapPath_V2)
}

parser_error_t _readOptionProxyType_V2(parser_context_t* c, pd_OptionProxyType_V2_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V2(parser_context_t* c, pd_OptionTimepoint_V2_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecCurrencyId_V2(parser_context_t* c, pd_OptionVecCurrencyId_V2_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecCurrencyId_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecSwapPath_V2(parser_context_t* c, pd_OptionVecSwapPath_V2_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecSwapPath_V2(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccessListItem_V2(
    const pd_AccessListItem_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringEvmAddress_V2(&v->address, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecH256(&v->storageKeys, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringEvmAddress_V2(&v->address, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecH256(&v->storageKeys, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountId32_V2(
    const pd_AccountId32_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V2(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32_V2(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V2(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32_V2(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIdLookupOfT_V2(
    const pd_AccountIdLookupOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V2(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V2(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAccountId_V2(
    const pd_AccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex64_V2(
    const pd_AccountIndex64_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V2(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V2(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20_V2(
    const pd_AccountKey20_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V2(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V2(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAmount_V2(
    const pd_Amount_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBodyId_V2(
    const pd_BodyId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Unit
        snprintf(outValue, outValueLen, "Unit");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Index
        CHECK_ERROR(_toStringCompactu32(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Executive
        snprintf(outValue, outValueLen, "Executive");
        break;
    case 4: // Technical
        snprintf(outValue, outValueLen, "Technical");
        break;
    case 5: // Legislative
        snprintf(outValue, outValueLen, "Legislative");
        break;
    case 6: // Judicial
        snprintf(outValue, outValueLen, "Judicial");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBodyPart_V2(
    const pd_BodyPart_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Voice
        snprintf(outValue, outValueLen, "Voice");
        break;
    case 1: // Members
        CHECK_ERROR(_toStringCompactu32(&v->count, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Fraction
        CHECK_ERROR(_toStringFraction_V2(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AtLeastProportion
        CHECK_ERROR(_toStringFraction_V2(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // MoreThanProportion
        CHECK_ERROR(_toStringFraction_V2(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoundedCallOfT_V2(
    const pd_BoundedCallOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringH256(&v->legacy, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        CHECK_ERROR(_toStringBytes(&v->_inline, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        CHECK_ERROR(_toStringTupleH256u32_V2(&v->lookup, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiLocation_V2(
    const pd_BoxVersionedMultiLocation_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiLocationV0_V2(&v->multilocationV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiLocationV1_V2(&v->multilocationV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringCallHashOf_V2(
    const pd_CallHashOf_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringClassIdOfTTokenIdOfT_V2(
    const pd_ClassIdOfTTokenIdOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringClassIdOfT_V2(&v->value1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTokenIdOfT_V2(&v->value2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringClassIdOfT_V2(&v->value1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTokenIdOfT_V2(&v->value2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringClassIdOfT_V2(
    const pd_ClassIdOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringCompactAccountIndex_V2(
    const pd_CompactAccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurrencyId_V2(
    const pd_CurrencyId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_toStringTokenSymbol_V2(&v->token, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // DexShare
        CHECK_ERROR(_toStringDexShareFixed_V2(&v->dexShare, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // EvmAddress
        CHECK_ERROR(_toStringEvmAddress_V2(&v->erc20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // StableAssetPoolId
        CHECK_ERROR(_toStringu32(&v->stableAssetPoolToken, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // Lease
        CHECK_ERROR(_toStringu32(&v->liquidCrowdloan, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // ForeignAssetId
        CHECK_ERROR(_toStringu16(&v->foreignAsset, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringDexShareFixed_V2(
    const pd_DexShareFixed_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringDexShare_V2(&v->dexShare1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDexShare_V2(&v->dexShare2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringDexShare_V2(&v->dexShare1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDexShare_V2(&v->dexShare2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringDexShare_V2(
    const pd_DexShare_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_toStringTokenSymbol_V2(&v->token, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // EvmAddress
        CHECK_ERROR(_toStringEvmAddress_V2(&v->erc20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Lease
        CHECK_ERROR(_toStringu32(&v->liquidCrowdloan, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // ForeignAssetId
        CHECK_ERROR(_toStringu16(&v->foreignAsset, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringEcdsaSignature_V2(
    const pd_EcdsaSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringEd25519Signature_V2(
    const pd_Ed25519Signature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringEip712Signature_V2(
    const pd_Eip712Signature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(65);
}

parser_error_t _toStringEraIndex_V2(
    const pd_EraIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEvmAddress_V2(
    const pd_EvmAddress_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(20);
}

parser_error_t _toStringFraction_V2(
    const pd_Fraction_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X1_V2(
    const pd_JunctionV0X1_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X2_V2(
    const pd_JunctionV0X2_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X3_V2(
    const pd_JunctionV0X3_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X4_V2(
    const pd_JunctionV0X4_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X5_V2(
    const pd_JunctionV0X5_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X6_V2(
    const pd_JunctionV0X6_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X7_V2(
    const pd_JunctionV0X7_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X8_V2(
    const pd_JunctionV0X8_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV0_V2(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV0_V2(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0_V2(
    const pd_JunctionV0_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parent
        snprintf(outValue, outValueLen, "Parent");
        break;
    case 1: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_toStringAccountId32_V2(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64_V2(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20_V2(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 9: // Plurality
        CHECK_ERROR(_toStringPlurality_V2(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionV1X1_V2(
    const pd_JunctionV1X1_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X2_V2(
    const pd_JunctionV1X2_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X3_V2(
    const pd_JunctionV1X3_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X4_V2(
    const pd_JunctionV1X4_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X5_V2(
    const pd_JunctionV1X5_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X6_V2(
    const pd_JunctionV1X6_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X7_V2(
    const pd_JunctionV1X7_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X8_V2(
    const pd_JunctionV1X8_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV1_V2(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV1_V2(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1_V2(
    const pd_JunctionV1_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_toStringAccountId32_V2(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64_V2(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20_V2(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 8: // Plurality
        CHECK_ERROR(_toStringPlurality_V2(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionsV0_V2(
    const pd_JunctionsV0_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Null
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Null");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV0X1_V2(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV0X2_V2(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV0X3_V2(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV0X4_V2(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV0X5_V2(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV0X6_V2(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV0X7_V2(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV0X8_V2(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionsV1_V2(
    const pd_JunctionsV1_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Here
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Here");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV1X1_V2(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV1X2_V2(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV1X3_V2(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV1X4_V2(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV1X5_V2(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV1X6_V2(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV1X7_V2(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV1X8_V2(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringKeys_V2(
    const pd_Keys_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLookupasStaticLookupSource_V2(
    const pd_LookupasStaticLookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V2(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V2(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMultiLocationV0_V2(
    const pd_MultiLocationV0_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringJunctionsV0_V2(&v->junctions, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringMultiLocationV1_V2(
    const pd_MultiLocationV1_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionsV1_V2(&v->interior, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionsV1_V2(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMultiSignature_V2(
    const pd_MultiSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_toStringEd25519Signature_V2(&v->ed25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_toStringSr25519Signature_V2(&v->sr25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_toStringEcdsaSignature_V2(&v->ecdsa, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringNetworkId_V2(
    const pd_NetworkId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Any
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Polkadot
        snprintf(outValue, outValueLen, "Polkadot");
        break;
    case 3: // Kusama
        snprintf(outValue, outValueLen, "Kusama");
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOverweightIndex_V2(
    const pd_OverweightIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPerbill_V2(
    const pd_Perbill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPlurality_V2(
    const pd_Plurality_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyId_V2(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart_V2(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyId_V2(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart_V2(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPoolId_V2(
    const pd_PoolId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->value > 1) {
        return parser_unexpected_value;
    }
    CHECK_ERROR(_toStringCurrencyId_V2(&v->currencyid, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringPoolTokenIndex_V2(
    const pd_PoolTokenIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProxyType_V2(
    const pd_ProxyType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1:
        snprintf(outValue, outValueLen, "CancelProxy");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Governance");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Auction");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Swap");
        break;
    case 5:
        snprintf(outValue, outValueLen, "Loan");
        break;
    case 6:
        snprintf(outValue, outValueLen, "DexLiquidity");
        break;
    case 7:
        snprintf(outValue, outValueLen, "StableAssetSwap");
        break;
    case 8:
        snprintf(outValue, outValueLen, "StableAssetLiquidity");
        break;
    default:
        return parser_print_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringReferendumIndex_V2(
    const pd_ReferendumIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSr25519Signature_V2(
    const pd_Sr25519Signature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringStableAssetPoolId_V2(
    const pd_StableAssetPoolId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSwapPath_V2(
    const pd_SwapPath_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Dex
        CHECK_ERROR(_toStringVecCurrencyId_V2(&v->currencies, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Taiga
        CHECK_ERROR(_toStringTaiga_V2(&v->taiga, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTaiga_V2(
    const pd_Taiga_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringu32(&v->value1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->value2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->value3, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->value1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->value2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->value3, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTimepoint_V2(
    const pd_Timepoint_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTokenIdOfT_V2(
    const pd_TokenIdOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTokenSymbol_V2(
    const pd_TokenSymbol_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "ACA");
        break;
    case 1:
        snprintf(outValue, outValueLen, "AUSD");
        break;
    case 2:
        snprintf(outValue, outValueLen, "DOT");
        break;
    case 3:
        snprintf(outValue, outValueLen, "LDOT");
        break;
    case 20:
        snprintf(outValue, outValueLen, "RENBTC");
        break;
    case 21:
        snprintf(outValue, outValueLen, "CASH");
        break;
    case 128:
        snprintf(outValue, outValueLen, "KAR");
        break;
    case 129:
        snprintf(outValue, outValueLen, "KUSD");
        break;
    case 130:
        snprintf(outValue, outValueLen, "KSM");
        break;
    case 131:
        snprintf(outValue, outValueLen, "LKSM");
        break;
    case 132:
        snprintf(outValue, outValueLen, "TAI");
        break;
    case 168:
        snprintf(outValue, outValueLen, "BNC");
        break;
    case 169:
        snprintf(outValue, outValueLen, "VSKSM");
        break;
    case 170:
        snprintf(outValue, outValueLen, "PHA");
        break;
    case 171:
        snprintf(outValue, outValueLen, "KINT");
        break;
    case 172:
        snprintf(outValue, outValueLen, "KBTC");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringTransactionAction_V2(
    const pd_TransactionAction_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringEvmAddress_V2(&v->h160, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Create");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringTupleCurrencyIdCurrencyIdOptionVecSwapPath_V2(
    const pd_TupleCurrencyIdCurrencyIdOptionVecSwapPath_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringCurrencyId_V2(&v->currencyid1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCurrencyId_V2(&v->currencyid2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecSwapPath_V2(&v->paths, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCurrencyId_V2(&v->currencyid1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCurrencyId_V2(&v->currencyid2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecSwapPath_V2(&v->paths, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleH256u32_V2(
    const pd_TupleH256u32_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringH256(&v->h256, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->u32, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringH256(&v->h256, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->u32, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringWeightLimit_V2(
    const pd_WeightLimit_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Unlimited
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Unlimited");
        break;
    case 1: // Limited
        CHECK_ERROR(_toStringCompactu64(&v->limited, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringWeight_V2(
    const pd_Weight_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringXcmWeight_V2(
    const pd_XcmWeight_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringu8_array_32_V2(
    const pd_u8_array_32_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccessListItem_V2(
    const pd_VecAccessListItem_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccessListItem_V2);
}

parser_error_t _toStringVecAccountId_V2(
    const pd_VecAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V2);
}

parser_error_t _toStringVecCurrencyId_V2(
    const pd_VecCurrencyId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(CurrencyId_V2);
}

parser_error_t _toStringVecSwapPath_V2(
    const pd_VecSwapPath_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SwapPath_V2);
}

parser_error_t _toStringVecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V2(
    const pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleCurrencyIdCurrencyIdOptionVecSwapPath_V2);
}

parser_error_t _toStringOptionProxyType_V2(
    const pd_OptionProxyType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V2(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V2(
    const pd_OptionTimepoint_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V2(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecCurrencyId_V2(
    const pd_OptionVecCurrencyId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecCurrencyId_V2(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecSwapPath_V2(
    const pd_OptionVecSwapPath_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecSwapPath_V2(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
