/** ******************************************************************************
 *  (c) 2021 Zondax GmbH
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
 ******************************************************************************* */

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newAcalaApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'
import { txBalances_transfer } from './zemu_blobs'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

const expected_address = '21SdAbm9cbKEm8ZFXgKBdeLjPtM1JQDKLaUi1i1pohCV5KjS'
const expected_pk = '19306b58f9e46fc24a406534ec9bb7aea62f88b7b4965536c5dd1d80db1f4c11'

jest.setTimeout(60000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

describe('Standard', function () {
  test.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.each(models)('main menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, [1, 0, 0, 4, -5])
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get app version', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())
      const resp = await app.getVersion()

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
      expect(resp).toHaveProperty('test_mode')
      expect(resp).toHaveProperty('major')
      expect(resp).toHaveProperty('minor')
      expect(resp).toHaveProperty('patch')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      console.log(resp.address)
      console.log(resp.pubKey)

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address`)

      const resp = await respRequest

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.navigateAndCompareUntilText('.', `${m.prefix.toLowerCase()}-show_address_reject`, 'REJECT')

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic normal', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txBalances_transfer, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_normal`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic expert', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlob = Buffer.from(txBalances_transfer, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_expert`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  // test.each(models)('sign large nomination', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({...defaultOptions, model: m.name})
  //     const app = newAcalaApp(sim.getTransport())
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txNomination, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

  //     await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_large_nomination`, m.name === 'nanos' ? 8 : 6)

  //     const signatureResponse = await signatureRequest
  //     console.log(signatureResponse)

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('set keys', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({...defaultOptions, model: m.name})
  //     const app = newAcalaApp(sim.getTransport())
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(setKeys, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

  //     await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-set-keys`, m.name === 'nanos' ? 21 : 14)

  //     const signatureResponse = await signatureRequest
  //     console.log(signatureResponse)

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })
})
