# Kusama  8.9130.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> | 
|Remark |    |   |   | `Vecu8` remark <br/> | 
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|Set code |    |   |   | `Vecu8` code <br/> | 
|Set code without checks |    |   |   | `Vecu8` code <br/> | 
|Set storage |    |   |   | `VecKeyValue` items <br/> | 
|Kill storage |    |   |   | `VecKey` keys <br/> | 
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> | 
|Remark with event |    |   |   | `Vecu8` remark <br/> | 

## Babe

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|Plan config change |    |   |   | `NextConfigDescriptor` config <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|Transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/> | 
|Free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|Force transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|Freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> | 
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> | 
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> | 

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> | 

## Staking

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/>`CompactBalance` amount <br/>`RewardDestination` payee <br/> | 
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> | 
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> | 
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> | 
|Validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> | 
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` targets <br/> | 
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  | 
|Set payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> | 
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/> | 
|Set validator count |    | :heavy_check_mark: |   | `Compactu32` new_ <br/> | 
|Increase validator count |    | :heavy_check_mark: |   | `Compactu32` additional <br/> | 
|Scale validator count |    |   |   | `Percent` factor <br/> | 
|Force no eras |    | :heavy_check_mark: |   |  | 
|Force new era |    | :heavy_check_mark: |   |  | 
|Set invulnerables |    |   |   | `VecAccountId` invulnerables <br/> | 
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|Force new era always |    | :heavy_check_mark: |   |  | 
|Cancel deferred slash |    |   |   | `EraIndex` era <br/>`Bytes` slash_indices <br/> | 
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> | 
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> | 
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> | 
|Set staking limits |    |   |   | `Balance` min_nominator_bond <br/>`Balance` min_validator_bond <br/>`Optionu32` max_nominator_count <br/>`Optionu32` max_validator_count <br/>`OptionPercent` threshold <br/> | 
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  | 

## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## ImOnline

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Heartbeat |    |   |   | `HeartbeatBlockNumber` heartbeat <br/>`AuthorityIdasRuntimeAppPublicSignature` signature <br/> | 

## Democracy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    |   |   | `Hash` proposal_hash <br/>`Compactu128` amount <br/> | 
|Second |    | :heavy_check_mark: |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> | 
|Vote |    |   |   | `Compactu32` ref_index <br/>`AccountVoteBalanceOfT` vote <br/> | 
|Emergency cancel |    | :heavy_check_mark: |   | `ReferendumIndex` ref_index <br/> | 
|External propose |    |   |   | `Hash` proposal_hash <br/> | 
|External propose majority |    |   |   | `Hash` proposal_hash <br/> | 
|External propose default |    |   |   | `Hash` proposal_hash <br/> | 
|Fast track |    |   |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> | 
|Veto external |    |   |   | `Hash` proposal_hash <br/> | 
|Cancel referendum |    | :heavy_check_mark: |   | `Compactu32` ref_index <br/> | 
|Cancel queued |    | :heavy_check_mark: |   | `ReferendumIndex` which <br/> | 
|Delegate |    |   |   | `AccountId` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> | 
|Undelegate |    | :heavy_check_mark: |   |  | 
|Clear public proposals |    | :heavy_check_mark: |   |  | 
|Note preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Note preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Note imminent preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Note imminent preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Reap preimage |    |   |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> | 
|Unlock |    |   |   | `AccountId` target <br/> | 
|Remove vote |    | :heavy_check_mark: |   | `ReferendumIndex` index <br/> | 
|Remove other vote |    |   |   | `AccountId` target <br/>`ReferendumIndex` index <br/> | 
|Enact proposal |    |   |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> | 
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> | 
|Cancel proposal |    | :heavy_check_mark: |   | `Compactu32` prop_index <br/> | 

## Council

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## PhragmenElection

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vote |    |   |   | `VecAccountId` votes <br/>`Compactu128` amount <br/> | 
|Remove voter |    | :heavy_check_mark: |   |  | 
|Submit candidacy |    | :heavy_check_mark: |   | `Compactu32` candidate_count <br/> | 
|Renounce candidacy |    |   |   | `Renouncing` renouncing <br/> | 
|Remove member |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`bool` has_replacement <br/> | 
|Clean defunct voters |    | :heavy_check_mark: |   | `u32` num_voters <br/>`u32` num_defunct <br/> | 

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> | 
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> | 
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|Clear prime |    | :heavy_check_mark: |   |  | 

## Treasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> | 
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> | 

## Claims

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/> | 
|Mint claim |    |   |   | `EthereumAddress` who <br/>`Balance` amount <br/>`OptionTupleBalanceOfTBalanceOfTBlockNumber` vesting_schedule <br/>`OptionStatementKind` statement <br/> | 
|Claim attest |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/>`Bytes` statement <br/> | 
|Attest |    | :heavy_check_mark: |   | `Bytes` statement <br/> | 
|Move claim |    | :heavy_check_mark: |   | `EthereumAddress` old <br/>`EthereumAddress` new_ <br/>`OptionAccountId` maybe_preclaim <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> | 

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> | 
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> | 
|Clear identity |    | :heavy_check_mark: |   |  | 
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> | 
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> | 
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountId` new_ <br/> | 
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> | 
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> | 
|Kill identity |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> | 
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> | 
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> | 
|Remove sub |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` sub <br/> | 
|Quit sub |    | :heavy_check_mark: |   |  | 

## Society

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bid |    | :heavy_check_mark: |   | `Balance` amount <br/> | 
|Unbid |    | :heavy_check_mark: |   | `u32` pos <br/> | 
|Vouch |    | :heavy_check_mark: |   | `AccountId` who <br/>`Balance` amount <br/>`Balance` tip <br/> | 
|Unvouch |    | :heavy_check_mark: |   | `u32` pos <br/> | 
|Vote |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` candidate <br/>`bool` approve <br/> | 
|Defender vote |    | :heavy_check_mark: |   | `bool` approve <br/> | 
|Payout |    | :heavy_check_mark: |   |  | 
|Found |    | :heavy_check_mark: |   | `AccountId` founder <br/>`u32` max_members <br/>`Bytes` rules <br/> | 
|Unfound |    | :heavy_check_mark: |   |  | 
|Judge suspended member |    | :heavy_check_mark: |   | `AccountId` who <br/>`bool` forgive <br/> | 
|Judge suspended candidate |    |   |   | `AccountId` who <br/>`Judgement` judgement <br/> | 
|Set max members |    | :heavy_check_mark: |   | `u32` max <br/> | 

## Recovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|As recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> | 
|Set recovered |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|Create recovery |    |   |   | `VecAccountId` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> | 
|Initiate recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Vouch recovery |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|Claim recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Close recovery |    | :heavy_check_mark: |   | `AccountId` rescuer <br/> | 
|Remove recovery |    | :heavy_check_mark: |   |  | 
|Cancel recovered |    | :heavy_check_mark: |   | `AccountId` account <br/> | 

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    | :heavy_check_mark: |   |  | 
|Vest other |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> | 
|Vested transfer |    |   |   | `LookupasStaticLookupSource` target <br/>`VestingInfoBalanceOfTBlockNumber` schedule <br/> | 
|Force vested transfer |    |   |   | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` target <br/>`VestingInfoBalanceOfTBlockNumber` schedule <br/> | 
|Merge schedules |    | :heavy_check_mark: |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> | 

## Scheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> | 
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 
|Cancel named |    |   |   | `Vecu8` id <br/> | 
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 
|Add proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxies |    | :heavy_check_mark: |   |  | 
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|Kill anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> | 
|Announce |    |   |   | `AccountId` real <br/>`CallHashOfT` call_hash <br/> | 
|Remove announcement |    |   |   | `AccountId` real <br/>`CallHashOfT` call_hash <br/> | 
|Reject announcement |    |   |   | `AccountId` delegate <br/>`CallHashOfT` call_hash <br/> | 
|Proxy announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    |   |   | `VecAccountId` other_signatories <br/>`Call` call <br/> | 
|As multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCallT` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> | 
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> | 

## Bounties

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose bounty |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`Bytes` description <br/> | 
|Approve bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Propose curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` curator <br/>`CompactBalance` fee <br/> | 
|Unassign curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Accept curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Award bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Claim bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Close bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Extend bounty expiry |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`Bytes` remark <br/> | 

## Tips

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report awesome |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/> | 
|Retract tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 
|Tip new |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/>`Compactu128` tip_value <br/> | 
|Tip |    | :heavy_check_mark: |   | `Hash` hash <br/>`Compactu128` tip_value <br/> | 
|Close tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 
|Slash tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> | 
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> | 
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> | 
|Submit |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`u32` num_signed_submissions <br/> | 

## Gilt

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Place bid |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`u32` duration <br/> | 
|Retract bid |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`u32` duration <br/> | 
|Set target |    |   |   | `Compactu64` target <br/> | 
|Thaw |    |   |   | `Compactu32` index <br/> | 

## BagsList

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Rebag |    | :heavy_check_mark: |   | `AccountId` dislocated <br/> | 

## Configuration

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation upgrade frequency |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set validation upgrade delay |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set code retention period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set max code size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max pov size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max head data size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set parathread cores |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set parathread retries |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set group rotation frequency |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set chain availability period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set thread availability period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set scheduling lookahead |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max validators per core |    | :heavy_check_mark: |   | `Optionu32` new_ <br/> | 
|Set max validators |    | :heavy_check_mark: |   | `Optionu32` new_ <br/> | 
|Set dispute period |    |   |   | `SessionIndex` new_ <br/> | 
|Set dispute post conclusion acceptance period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set dispute max spam slots |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set dispute conclusion by time out period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set no show slots |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set n delay tranches |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set zeroth delay tranche width |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set needed approvals |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set relay vrf modulo samples |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max upward queue count |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max upward queue size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max downward message size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set ump service total weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> | 
|Set max upward message size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max upward message num per candidate |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp open request ttl |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp sender deposit |    |   |   | `Balance` new_ <br/> | 
|Set hrmp recipient deposit |    | :heavy_check_mark: |   | `Balance` new_ <br/> | 
|Set hrmp channel max capacity |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp channel max total size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parachain inbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parathread inbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp channel max message size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parachain outbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parathread outbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max message num per candidate |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set ump max individual weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> | 

## ParasShared

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParaInclusion

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParaInherent

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Enter |    |   |   | `ParachainsInherentDataHeader` data <br/> | 

## Paras

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force set current code |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/> | 
|Force set current head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> | 
|Force schedule code upgrade |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/>`BlockNumber` relay_parent_number <br/> | 
|Force note new head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> | 
|Force queue action |    |   |   | `ParaId` para <br/> | 

## Initializer

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force approve |    | :heavy_check_mark: |   | `BlockNumber` up_to <br/> | 

## Dmp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Ump

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> | 

## Hrmp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Hrmp init open channel |    |   |   | `ParaId` recipient <br/>`u32` proposed_max_capacity <br/>`u32` proposed_max_message_size <br/> | 
|Hrmp accept open channel |    |   |   | `ParaId` sender <br/> | 
|Hrmp close channel |    |   |   | `HrmpChannelId` channel_id <br/> | 
|Force clean hrmp |    |   |   | `ParaId` para <br/> | 
|Force process hrmp open |    | :heavy_check_mark: |   |  | 
|Force process hrmp close |    | :heavy_check_mark: |   |  | 
|Hrmp cancel open request |    |   |   | `HrmpChannelId` channel_id <br/> | 

## ParasDisputes

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force unfreeze |    | :heavy_check_mark: |   |  | 

## Registrar

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register |    |   |   | `ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> | 
|Force register |    |   |   | `AccountId` who <br/>`Balance` deposit <br/>`ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> | 
|Deregister |    |   |   | `ParaId` id <br/> | 
|Swap |    |   |   | `ParaId` id <br/>`ParaId` other <br/> | 
|Force remove lock |    |   |   | `ParaId` para <br/> | 
|Reserve |    | :heavy_check_mark: |   |  | 

## Slots

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force lease |    |   |   | `ParaId` para <br/>`AccountId` leaser <br/>`Balance` amount <br/>`LeasePeriodOfT` period_begin <br/>`LeasePeriodOfT` period_count <br/> | 
|Clear all leases |    |   |   | `ParaId` para <br/> | 
|Trigger onboard |    |   |   | `ParaId` para <br/> | 

## Auctions

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|New auction |    | :heavy_check_mark: |   | `Compactu32` duration <br/>`Compactu32` lease_period_index <br/> | 
|Bid |    | :heavy_check_mark: |   | `Compactu32` para <br/>`Compactu32` auction_index <br/>`Compactu32` first_slot <br/>`Compactu32` last_slot <br/>`CompactBalance` amount <br/> | 
|Cancel auction |    | :heavy_check_mark: |   |  | 

## Crowdloan

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    |   |   | `Compactu32` index <br/>`Compactu128` cap <br/>`Compactu32` first_period <br/>`Compactu32` last_period <br/>`Compactu32` end <br/>`OptionMultiSigner` verifier <br/> | 
|Contribute |    |   |   | `Compactu32` index <br/>`Compactu128` amount <br/>`OptionMultiSignature` signature <br/> | 
|Withdraw |    |   |   | `AccountId` who <br/>`Compactu32` index <br/> | 
|Refund |    |   |   | `Compactu32` index <br/> | 
|Dissolve |    |   |   | `Compactu32` index <br/> | 
|Edit |    |   |   | `Compactu32` index <br/>`Compactu128` cap <br/>`Compactu32` first_period <br/>`Compactu32` last_period <br/>`Compactu32` end <br/>`OptionMultiSigner` verifier <br/> | 
|Add memo |    |   |   | `ParaId` index <br/>`Vecu8` memo <br/> | 
|Poke |    |   |   | `ParaId` index <br/> | 

## XcmPallet

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

