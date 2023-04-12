/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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

import Zemu, { ButtonKind, DEFAULT_START_OPTIONS, zondaxMainmenuNavigation } from '@zondax/zemu'
import { newAcalaApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

const expected_address = '21SdAbm9cbKEm8ZFXgKBdeLjPtM1JQDKLaUi1i1pohCV5KjS'
const expected_pk = '19306b58f9e46fc24a406534ec9bb7aea62f88b7b4965536c5dd1d80db1f4c11'

jest.setTimeout(180000)

describe('Standard', function () {
  test.concurrent.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('main menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      const mainmenuNavigation = zondaxMainmenuNavigation(m.name, [1, 0, 0, 5, -6])
      await sim.start({ ...defaultOptions, model: m.name })
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, mainmenuNavigation.schedule)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('get app version', async function (m) {
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

  test.concurrent.each(models)('get address', async function (m) {
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

  test.concurrent.each(models)('show address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        approveKeyword: m.name === 'stax' ? 'QR' : '',
        approveAction: ButtonKind.ApproveTapButton,
      })
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

  test.concurrent.each(models)('show address - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        rejectKeyword: m.name === 'stax' ? 'QR' : '',
      })
      const app = newAcalaApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndReject('.', `${m.prefix.toLowerCase()}-show_address_reject`)

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })
})
