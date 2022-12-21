/** ******************************************************************************
 *  (c) 2018 - 2022 Zondax GmbH
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

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(180000)

async function activateCrowdloanMode(sim: any) {
  // Crowdloan can be activate only when expert mode is enabled
  await sim.clickRight()
  await sim.clickRight()
  await sim.clickBoth('', false)
  await sim.clickBoth('', false)
  await sim.clickLeft()
  await sim.clickLeft()

  // Activale Expert mode
  await sim.clickRight()
  await sim.clickBoth()

  //Activate Crowdloan
  await sim.clickRight()
  await sim.clickBoth()

  // Review warning message
  const reviewSteps = sim.startOptions.model === 'nanos' ? 6 : 5
  for (let i = 0; i < reviewSteps; i += 1) {
    await sim.clickRight()
  }

  // Accept
  await sim.clickBoth()

  // Just go forward
  await sim.clickRight()
  await sim.clickRight()
}

describe('Crowdloan', function () {
  test.each(models)('crowdloan menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newAcalaApp(sim.getTransport())

      const acala_expected_address = '21SdAbm9cbKEm8ZFXgKBdeLjPtM1JQDKLaUi1i1pohCV5KjS'
      const acala_expected_pk = '19306b58f9e46fc24a406534ec9bb7aea62f88b7b4965536c5dd1d80db1f4c11'
      const polkadot_expected_address = '25yY5dKSiDzv9heG4zPDQJLkPNSY7JL4NK5RQ9CWoNKrqsUY'
      const polkadot_expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

      let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)
      expect(resp.address).toEqual(acala_expected_address)
      expect(resp.pubKey).toEqual(acala_expected_pk)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      await activateCrowdloanMode(sim)

      resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)
      expect(resp.address).toEqual(polkadot_expected_address)
      expect(resp.pubKey).toEqual(polkadot_expected_pk)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
    } finally {
      await sim.close()
    }
  })
})
