/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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
#include "substrate_dispatch_V3.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readTokenSymbol_V3(parser_context_t* c, pd_TokenSymbol_V3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // ACA
    case 1: // AUSD
    case 2: // DOT
    case 3: // LDOT
    case 4: // TAP
    case 128: // KAR
    case 129: // KUSD
    case 130: // KSM
    case 131: // LKSM
    case 132: // TAI
    case 168: // BNC
    case 169: // VSKSM
    case 170: // PHA
    case 171: // KINT
    case 172: // KBTC
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readCurrencyId_V3(parser_context_t* c, pd_CurrencyId_V3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_readTokenSymbol_V3(c, &v->token))
        break;
    case 1: // DexShare
        CHECK_ERROR(_readDexShareFixed(c, &v->dexShare))
        break;
    case 2: // EvmAddress
        CHECK_ERROR(_readEvmAddress(c, &v->erc20))
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

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringTokenSymbol_V3(
    const pd_TokenSymbol_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
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
    case 4:
        snprintf(outValue, outValueLen, "TAP");
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

parser_error_t _toStringCurrencyId_V3(
    const pd_CurrencyId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_toStringTokenSymbol_V3(&v->token, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // DexShare
        CHECK_ERROR(_toStringDexShareFixed(&v->dexShare, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // EvmAddress
        CHECK_ERROR(_toStringEvmAddress(&v->erc20, outValue, outValueLen, pageIdx, pageCount))
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
