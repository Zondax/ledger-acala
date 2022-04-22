# Acala  1.2000.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> | 
|Remark | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> | 
|Set heap pages |    |   |   | `u64` pages <br/> | 
|Set code |    |   |   | `Vecu8` code <br/> | 
|Set code without checks |    |   |   | `Vecu8` code <br/> | 
|Set changes trie config |    |   |   | `OptionChangesTrieConfiguration` changes_trie_config <br/> | 
|Set storage |    |   |   | `VecKeyValue` items <br/> | 
|Kill storage |    |   |   | `VecKey` keys <br/> | 
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> | 
|Remark with event | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    |   |   | `Compactu64` now <br/> | 

## Scheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> | 
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 
|Cancel named |    |   |   | `Vecu8` id <br/> | 
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    |   |   | `VecAccountId` other_signatories <br/>`Call` call <br/> | 
|As multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|Approve as multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> | 
|Cancel as multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    |   |   | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 
|Add proxy |    |   |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxy |    |   |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxies |    |   |   |  | 
|Anonymous |    |   |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|Kill anonymous |    |   |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> | 
|Announce |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|Remove announcement |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|Reject announcement |    |   |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> | 
|Proxy announced |    |   |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 

## TransactionPause

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Pause transaction |    |   |   | `Vecu8` pallet_name <br/>`Vecu8` function_name <br/> | 
|Unpause transaction |    |   |   | `Vecu8` pallet_name <br/>`Vecu8` function_name <br/> | 

## IdleScheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule task |    |   |   | `Task` task <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` Amount <br/> | 
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> | 
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` Amount <br/> | 
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` Amount <br/> | 
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> | 
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` Amount <br/> | 

## Currencies

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer |    |   |   | `LookupasStaticLookupSource` dest <br/>`CurrencyId` currency_id <br/>`Compactu128` Amount <br/> | 
|Transfer native currency |    |   |   | `LookupasStaticLookupSource` dest <br/>`Compactu128` Amount <br/> | 
|Update balance |    |   |   | `LookupasStaticLookupSource` who <br/>`CurrencyId` currency_id <br/>`AmountOf` amount <br/> | 
|Sweep dust |    |   |   | `CurrencyId` currency_id <br/>`VecAccountId` accounts <br/> | 

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    |   |   |  | 
|Vested transfer |    |   |   | `LookupasStaticLookupSource` dest <br/>`VestingScheduleOfT` schedule <br/> | 
|Update vesting schedules |    |   |   | `LookupasStaticLookupSource` who <br/>`VecVestingScheduleOfT` vesting_schedules <br/> | 
|Claim for |    |   |   | `LookupasStaticLookupSource` dest <br/> | 

## TransactionPayment

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set alternative fee swap path |    |   |   | `OptionVecCurrencyId` fee_swap_path <br/> | 

## Treasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    |   |   | `CompactBalance` Amount <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Reject proposal |    |   |   | `Compactu32` proposal_id <br/> | 
|Approve proposal |    |   |   | `Compactu32` proposal_id <br/> | 

## Bounties

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose bounty |    |   |   | `CompactBalance` Amount <br/>`Bytes` description <br/> | 
|Approve bounty |    |   |   | `Compactu32` bounty_id <br/> | 
|Propose curator |    |   |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` curator <br/>`CompactBalance` fee <br/> | 
|Unassign curator |    |   |   | `Compactu32` bounty_id <br/> | 
|Accept curator |    |   |   | `Compactu32` bounty_id <br/> | 
|Award bounty |    |   |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Claim bounty |    |   |   | `Compactu32` bounty_id <br/> | 
|Close bounty |    |   |   | `Compactu32` bounty_id <br/> | 
|Extend bounty expiry |    |   |   | `Compactu32` bounty_id <br/>`Bytes` remark <br/> | 

## Tips

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report awesome |    |   |   | `Bytes` reason <br/>`AccountId` who <br/> | 
|Retract tip |    |   |   | `Hash` hash <br/> | 
|Tip new |    |   |   | `Bytes` reason <br/>`AccountId` who <br/>`Compactu128` tip_value <br/> | 
|Tip |    |   |   | `Hash` hash <br/>`Compactu128` tip_value <br/> | 
|Close tip |    |   |   | `Hash` hash <br/> | 
|Slash tip |    |   |   | `Hash` hash <br/> | 

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation data |    |   |   | `ParachainInherentData` data <br/> | 
|Sudo send upward message |    |   |   | `UpwardMessage` message <br/> | 
|Authorize upgrade |    |   |   | `Hash` code_hash <br/> | 
|Enact authorized upgrade |    |   |   | `Vecu8` code <br/> | 

## CollatorSelection

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set invulnerables |    |   |   | `VecAccountId` new_ <br/> | 
|Set desired candidates |    |   |   | `Compactu32` max <br/> | 
|Set candidacy bond |    |   |   | `Compactu128` bond <br/> | 
|Register as candidate |    |   |   |  | 
|Register candidate |    |   |   | `AccountId` new_candidate <br/> | 
|Leave intent |    |   |   |  | 
|Withdraw bond |    |   |   |  | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys |    |   |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|Purge keys |    |   |   |  | 

## SessionManager

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule session duration |    |   |   | `Compactu32` start_session <br/>`Compactu32` duration <br/> | 

## PolkadotXcm

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> | 
|Teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> | 
|Reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> | 
|Execute |    |   |   | `BoxVersionedXcmTasSysConfigCall` message <br/>`Weight` max_weight <br/> | 
|Force xcm version |    |   |   | `BoxMultiLocation` location <br/>`XcmVersion` xcm_version <br/> | 
|Force default xcm version |    |   |   | `OptionXcmVersion` maybe_xcm_version <br/> | 
|Force subscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> | 
|Force unsubscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> | 
|Limited reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> | 
|Limited teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> | 

## DmpQueue

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> | 

## XTokens

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer |    |   |   | `CurrencyId` currency_id <br/>`Balance` Amount <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> | 
|Transfer multiasset |    |   |   | `BoxVersionedMultiAsset` asset <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> | 

## OrmlXcm

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send as sovereign |    |   |   | `BoxMultiLocation` dest <br/>`BoxXcmTuple` message <br/> | 

## Authority

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Dispatch as |    |   |   | `AsOriginId` as_origin <br/>`BoxCallOfT` call <br/> | 
|Schedule dispatch |    |   |   | `DispatchTimeBlockNumber` when <br/>`Priority` priority <br/>`bool` with_delayed_origin <br/>`BoxCallOfT` call <br/> | 
|Fast track scheduled dispatch |    |   |   | `BoxPalletsOrigin` initial_origin <br/>`ScheduleTaskIndex` task_id <br/>`DispatchTimeBlockNumber` when <br/> | 
|Delay scheduled dispatch |    |   |   | `BoxPalletsOrigin` initial_origin <br/>`ScheduleTaskIndex` task_id <br/>`BlockNumber` additional_delay <br/> | 
|Cancel scheduled dispatch |    |   |   | `BoxPalletsOrigin` initial_origin <br/>`ScheduleTaskIndex` task_id <br/> | 
|Authorize call |    |   |   | `BoxCallOfT` call <br/>`OptionAccountId` caller <br/> | 
|Remove authorized call |    |   |   | `Hash` hash <br/> | 
|Trigger call |    |   |   | `Hash` hash <br/>`Compactu64` call_weight_bound <br/> | 

## GeneralCouncil

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> | 

## GeneralCouncilMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    |   |   | `AccountId` who <br/> | 
|Remove member |    |   |   | `AccountId` who <br/> | 
|Swap member |    |   |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    |   |   | `VecAccountId` members <br/> | 
|Change key |    |   |   | `AccountId` new_ <br/> | 
|Set prime |    |   |   | `AccountId` who <br/> | 
|Clear prime |    |   |   |  | 

## FinancialCouncil

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> | 

## FinancialCouncilMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    |   |   | `AccountId` who <br/> | 
|Remove member |    |   |   | `AccountId` who <br/> | 
|Swap member |    |   |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    |   |   | `VecAccountId` members <br/> | 
|Change key |    |   |   | `AccountId` new_ <br/> | 
|Set prime |    |   |   | `AccountId` who <br/> | 
|Clear prime |    |   |   |  | 

## HomaCouncil

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> | 

## HomaCouncilMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    |   |   | `AccountId` who <br/> | 
|Remove member |    |   |   | `AccountId` who <br/> | 
|Swap member |    |   |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    |   |   | `VecAccountId` members <br/> | 
|Change key |    |   |   | `AccountId` new_ <br/> | 
|Set prime |    |   |   | `AccountId` who <br/> | 
|Clear prime |    |   |   |  | 

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> | 

## TechnicalCommitteeMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    |   |   | `AccountId` who <br/> | 
|Remove member |    |   |   | `AccountId` who <br/> | 
|Swap member |    |   |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    |   |   | `VecAccountId` members <br/> | 
|Change key |    |   |   | `AccountId` new_ <br/> | 
|Set prime |    |   |   | `AccountId` who <br/> | 
|Clear prime |    |   |   |  | 

## Democracy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    |   |   | `Hash` proposal_hash <br/>`Compactu128` Amount <br/> | 
|Second |    |   |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> | 
|Vote |    |   |   | `Compactu32` ref_index <br/>`AccountVoteBalanceOf` vote <br/> | 
|Emergency cancel |    |   |   | `ReferendumIndex` ref_index <br/> | 
|External propose |    |   |   | `Hash` proposal_hash <br/> | 
|External propose majority |    |   |   | `Hash` proposal_hash <br/> | 
|External propose default |    |   |   | `Hash` proposal_hash <br/> | 
|Fast track |    |   |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> | 
|Veto external |    |   |   | `Hash` proposal_hash <br/> | 
|Cancel referendum |    |   |   | `Compactu32` ref_index <br/> | 
|Cancel queued |    |   |   | `ReferendumIndex` which <br/> | 
|Delegate |    |   |   | `AccountId` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> | 
|Undelegate |    |   |   |  | 
|Clear public proposals |    |   |   |  | 
|Note preimage |    |   |   | `Bytes` encoded_proposal <br/> | 
|Note preimage operational |    |   |   | `Bytes` encoded_proposal <br/> | 
|Note imminent preimage |    |   |   | `Bytes` encoded_proposal <br/> | 
|Note imminent preimage operational |    |   |   | `Bytes` encoded_proposal <br/> | 
|Reap preimage |    |   |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> | 
|Unlock |    |   |   | `AccountId` target <br/> | 
|Remove vote |    |   |   | `ReferendumIndex` index <br/> | 
|Remove other vote |    |   |   | `AccountId` target <br/>`ReferendumIndex` index <br/> | 
|Enact proposal |    |   |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> | 
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> | 
|Cancel proposal |    |   |   | `Compactu32` prop_index <br/> | 

## AcalaOracle

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Feed values |    |   |   | `VecTupleOracleKeyOracleValue` values <br/> | 

## OperatorMembershipAcala

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    |   |   | `AccountId` who <br/> | 
|Remove member |    |   |   | `AccountId` who <br/> | 
|Swap member |    |   |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    |   |   | `VecAccountId` members <br/> | 
|Change key |    |   |   | `AccountId` new_ <br/> | 
|Set prime |    |   |   | `AccountId` who <br/> | 
|Clear prime |    |   |   |  | 

## Auction

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bid |    |   |   | `AuctionId` id <br/>`Compactu128` Amount <br/> | 

## Rewards

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Prices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Lock price |    |   |   | `CurrencyId` currency_id <br/> | 
|Unlock price |    |   |   | `CurrencyId` currency_id <br/> | 

## Dex

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Swap with exact supply |    |   |   | `VecCurrencyId` path <br/>`Compactu128` supply_amount <br/>`Compactu128` min_target_amount <br/> | 
|Swap with exact target |    |   |   | `VecCurrencyId` path <br/>`Compactu128` target_amount <br/>`Compactu128` max_supply_amount <br/> | 
|Add liquidity |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/>`Compactu128` max_amount_a <br/>`Compactu128` max_amount_b <br/>`Compactu128` min_share_increment <br/>`bool` stake_increment_share <br/> | 
|Add provision |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/>`Compactu128` amount_a <br/>`Compactu128` amount_b <br/> | 
|Claim dex share |    |   |   | `AccountId` owner <br/>`CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/> | 
|Remove liquidity |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/>`Compactu128` remove_share <br/>`Compactu128` min_withdrawn_a <br/>`Compactu128` min_withdrawn_b <br/>`bool` by_unstake <br/> | 
|List provisioning |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/>`Compactu128` min_contribution_a <br/>`Compactu128` min_contribution_b <br/>`Compactu128` target_provision_a <br/>`Compactu128` target_provision_b <br/>`Compactu32` not_before <br/> | 
|Update provisioning parameters |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/>`Compactu128` min_contribution_a <br/>`Compactu128` min_contribution_b <br/>`Compactu128` target_provision_a <br/>`Compactu128` target_provision_b <br/>`Compactu32` not_before <br/> | 
|End provisioning |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/> | 
|Enable trading pair |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/> | 
|Disable trading pair |    |   |   | `CurrencyId` currency_id_a <br/>`CurrencyId` currency_id_b <br/> | 

## AuctionManager

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Cancel |    |   |   | `AuctionId` id <br/> | 

## Loans

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Honzon

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Adjust loan |    |   |   | `CurrencyId` currency_id <br/>`Amount` collateral_adjustment <br/>`Amount` debit_adjustment <br/> | 
|Close loan has debit by dex |    |   |   | `CurrencyId` currency_id <br/>`Compactu128` max_collateral_amount <br/>`OptionVecCurrencyId` maybe_path <br/> | 
|Transfer loan from |    |   |   | `CurrencyId` currency_id <br/>`LookupasStaticLookupSource` from <br/> | 
|Authorize |    |   |   | `CurrencyId` currency_id <br/>`LookupasStaticLookupSource` to <br/> | 
|Unauthorize |    |   |   | `CurrencyId` currency_id <br/>`LookupasStaticLookupSource` to <br/> | 
|Unauthorize all |    |   |   |  | 

## CdpTreasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Extract surplus to treasury |    |   |   | `Compactu128` Amount <br/> | 
|Auction collateral |    |   |   | `CurrencyId` currency_id <br/>`Compactu128` Amount <br/>`Compactu128` target <br/>`bool` splited <br/> | 
|Set expected collateral auction size |    |   |   | `CurrencyId` currency_id <br/>`Compactu128` size <br/> | 

## CdpEngine

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Liquidate |    |   |   | `CurrencyId` currency_id <br/>`LookupasStaticLookupSource` who <br/> | 
|Settle |    |   |   | `CurrencyId` currency_id <br/>`LookupasStaticLookupSource` who <br/> | 
|Set global params |    |   |   | `Rate` global_interest_rate_per_sec <br/> | 
|Set collateral params |    |   |   | `CurrencyId` currency_id <br/>`ChangeOptionRate` interest_rate_per_sec <br/>`ChangeOptionRatio` liquidation_ratio <br/>`ChangeOptionRate` liquidation_penalty <br/>`ChangeOptionRatio` required_collateral_ratio <br/>`ChangeBalance` maximum_total_debit_value <br/> | 

## EmergencyShutdown

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Emergency shutdown |    |   |   |  | 
|Open collateral refund |    |   |   |  | 
|Refund collaterals |    |   |   | `Compactu128` Amount <br/> | 

## HomaLite

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Mint |    |   |   | `Compactu128` Amount <br/> | 
|Set total staking currency |    |   |   | `Balance` staking_total <br/> | 
|Adjust total staking currency |    |   |   | `AmountOf` by_amount <br/> | 
|Set minting cap |    |   |   | `Compactu128` new_cap <br/> | 
|Set xcm dest weight |    |   |   | `Compactu64` xcm_dest_weight <br/> | 
|Mint for requests |    |   |   | `Compactu128` Amount <br/>`VecAccountId` requests <br/> | 
|Request redeem |    |   |   | `Compactu128` liquid_amount <br/>`Permill` additional_fee <br/> | 
|Schedule unbond |    |   |   | `Compactu128` staking_amount <br/>`RelayChainBlockNumberOfT` unbond_block <br/> | 
|Replace schedule unbond |    |   |   | `VecTupleBalanceRelayChainBlockNumberOfT` new_unbonds <br/> | 
|Adjust available staking balance |    |   |   | `AmountOf` by_amount <br/>`u32` max_num_matches <br/> | 

## Incentives

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Deposit dex share |    |   |   | `CurrencyId` lp_currency_id <br/>`Compactu128` Amount <br/> | 
|Withdraw dex share |    |   |   | `CurrencyId` lp_currency_id <br/>`Compactu128` Amount <br/> | 
|Claim rewards |    |   |   | `PoolId` pool_id <br/> | 
|Update incentive rewards |    |   |   | `VecTuplePoolIdVecTupleCurrencyIdBalance` updates <br/> | 
|Update dex saving rewards |    |   |   | `VecTuplePoolIdRate` updates <br/> | 
|Update claim reward deduction rates |    |   |   | `VecTuplePoolIdRate` updates <br/> | 

## NFT

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create class |    |   |   | `CID` metadata <br/>`Properties` properties <br/>`Attributes` attributes <br/> | 
|Mint |    |   |   | `LookupasStaticLookupSource` to <br/>`ClassIdOfT` class_id <br/>`CID` metadata <br/>`Attributes` attributes <br/>`Compactu32` quantity <br/> | 
|Transfer |    |   |   | `LookupasStaticLookupSource` to <br/>`ClassIdOfTTokenIdOfT` token <br/> | 
|Burn |    |   |   | `ClassIdOfTTokenIdOfT` token <br/> | 
|Burn with remark |    |   |   | `ClassIdOfTTokenIdOfT` token <br/>`Vecu8` remark <br/> | 
|Destroy class |    |   |   | `ClassIdOfT` class_id <br/>`LookupasStaticLookupSource` dest <br/> | 
|Update class properties |    |   |   | `ClassIdOfT` class_id <br/>`Properties` properties <br/> | 

## EVM

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Eth call |    |   |   | `TransactionAction` action <br/>`Vecu8` input <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/>`Compactu32` valid_until <br/> | 
|Call |    |   |   | `EvmAddress` target <br/>`Vecu8` input <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/> | 
|Scheduled call |    |   |   | `EvmAddress` from <br/>`EvmAddress` target <br/>`Vecu8` input <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/> | 
|Create |    |   |   | `Vecu8` init <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/> | 
|Create2 |    |   |   | `Vecu8` init <br/>`H256` salt <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/> | 
|Create network contract |    |   |   | `Vecu8` init <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/> | 
|Create predeploy contract |    |   |   | `EvmAddress` target <br/>`Vecu8` init <br/>`Compactu128` Amount <br/>`Compactu64` gas_limit <br/>`Compactu32` storage_limit <br/> | 
|Transfer maintainer |    |   |   | `EvmAddress` contract <br/>`EvmAddress` new_maintainer <br/> | 
|Deploy |    |   |   | `EvmAddress` contract <br/> | 
|Deploy free |    |   |   | `EvmAddress` contract <br/> | 
|Enable contract development |    |   |   |  | 
|Disable contract development |    |   |   |  | 
|Set code |    |   |   | `EvmAddress` contract <br/>`Vecu8` code <br/> | 
|Selfdestruct |    |   |   | `EvmAddress` contract <br/> | 

## EvmAccounts

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim account |    |   |   | `EvmAddress` eth_address <br/>`EcdsaSignature` eth_signature <br/> | 
|Claim default account |    |   |   |  | 

## Sudo

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Sudo |    |   |   | `Call` call <br/> | 
|Sudo unchecked weight |    |   |   | `Call` call <br/>`Weight` weight <br/> | 
|Set key |    |   |   | `LookupasStaticLookupSource` new_ <br/> | 
|Sudo as |    |   |   | `LookupasStaticLookupSource` who <br/>`Call` call <br/> | 

