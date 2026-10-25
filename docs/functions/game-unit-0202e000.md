# src/game/unit_0202e000.c

M1-T649: all eight functions verified at **100% objdiff**. Existing candidates
were retained and the global-word accessors cleaned up using typed array indexing.
Evidence below is from the delinked ARM instructions; returned views remain borrowed.

| Function | Address / bytes | Evidence and contract |
| --- | --- | --- |
| `Unk02e000_Nop_02e3e0` | 0x0202e3e0 / 4 | `bx lr` only; intentional empty callback. |
| `Unk02e000_GetAddr_data_02140ac8` | 0x0202e0c0 / 12 | Loads relocated symbol address and returns it as a 32-bit address; no ownership transfer. |
| `Unk02e000_Thunk_0202e788` | 0x0202e798 / 12 | Loads GetWorkArea into ip and tail-jumps; identical borrowed return contract. |
| `Unk02e000_Set_data_0215dd24` | 0x0202e0f4 / 16 | Stores r0 at global offset zero; accepts any 32-bit word. |
| `Unk02e000_Get_data_0215dd24` | 0x0202e104 / 16 | Loads global offset zero without interpretation. |
| `Unk02e000_Unk_02e170` | 0x0202e170 / 16 | Loads global offset four; EnsureAlloc7718 stores the allocation here. Neutral name retained. |
| `Unk02e000_GetWorkArea` | 0x0202e788 / 16 | Calls Unk_02e774 and adds four; GetAreaRecord and TestFlag use the returned work view. Requires allocation. |
| `Unk02e000_GetSubBlock3a4` | 0x0202e8e0 / 16 | Calls GetWorkArea and adds 0x3a4; requires allocation, sub-block purpose unknown. |

## M1-T650

All eight targets verified at **100% objdiff**. Existing candidates already
matched; retained their arithmetic and call order, typed the initialization
callee argument, and replaced raw global-word loads with array indexing.
Address-valued `int` returns retain the existing TU ABI (32-bit ARM addresses).
No allocation ownership transfers and no bounds checks occur in these helpers.

| Function | Address / bytes | Instruction evidence and contract |
| --- | --- | --- |
| `Unk02e000_Unk_02e0ac` | 0x0202e0ac / 20 | Calls `func_0205a9d0(0xa0)` then `Unk_02e0cc`; purpose unconfirmed. |
| `Unk02e000_Unk_02e228` | 0x0202e228 / 20 | Calls `Unk_02e774`, adds 0x3c8 then 0x5c00; borrowed address at +0x5fc8. |
| `Unk02e000_Unk_02e774` | 0x0202e774 / 20 | Loads `data_0215dd24[1]`, adds 0x98; requires the allocation established by EnsureAlloc7718. |
| `Unk02e000_Unk_02e8b8` | 0x0202e8b8 / 20 | Calls `Unk_02e774`, adds 0x2fc then 0x800; borrowed address at +0xafc. |
| `Unk02e000_GetUnk094fe0Work` | 0x0202e8cc / 20 | Calls `Unk_02e774`, adds 0xfc then 0xc00. `Unk094fe0_Thunk_0202e8cc` in unit_02094fe0 returns this as its work block, supporting the existing name. |
| `Unk02e000_Unk_02e8f0` | 0x0202e8f0 / 20 | Loads `data_0215dd24[1]`, adds 0x90; Unk_02e180 initializes eight bytes at this borrowed address. |
| `Unk02e000_Call_02e4dc` | 0x0202e578 / 24 | Adds 500 to base, multiply-adds index times 100, tail-calls func_0202e4dc. Caller supplies valid record storage/index. |
| `Unk02e000_Call_02e520` | 0x0202e590 / 24 | Same record computation, tail-calls func_0202e520; caller retains storage ownership. |

## Hard list

No M1-T650 or M1-T652 targets remain on the hard list.

## M1-T652

All eight existing C candidates verified at **100% objdiff**. Retained matching
logic, added instruction-based contracts and typed the allocation and resource
callee parameters. The TU already existed despite the card's creation wording.
No new tests are required by this card; objdiff checks generated instructions.

| Function | Address / bytes | Instruction evidence and contract |
| --- | --- | --- |
| `Unk02e000_SetMgrUnk38` | 0x0202e070 / 32 | Conditional stores of the two input words to manager +0x38/+0x3c; null is ignored. |
| `Unk02e000_HasField36` | 0x0202e904 / 32 | Null returns zero; otherwise loads an unsigned halfword at +0x36 and normalizes to boolean. Borrowed storage must support the halfword load. |
| `Unk02e000_Unk_02e0cc` | 0x0202e0cc / 40 | Calls func_0205ad2c(data_0213d89c[0]), then func_0205ad78(data_02140ac8, 0xde). Purpose unknown; neutral name retained. |
| `Unk02e000_GetTier` | 0x0202e440 / 40 | Sign tests after subtracting 3, 11 and 31 select tiers 0..3. GetSlotPtr uses these same tier boundaries; intended inputs are slot indices. |
| `Unk02e000_Unk_02e144` | 0x0202e144 / 44 | Calls Unk_02e180, func_0202e23c and Call_02008848 in order, then loops over Unk_02e5c4(0) and (1). Requires allocation; overall purpose unconfirmed. |
| `Unk02e000_EnsureAlloc7718` | 0x0202e114 / 48 | If global word +4 is zero, calls func_02052fe0(0x7718) and stores its result there. Module retains ownership; no allocation failure handling in original. |
| `Unk02e000_AddCounter5fc4` | 0x0202e1f8 / 48 | Adds input to work word +0x5fc4, then stores the smaller unsigned value of the wrapped sum and 35999999. Requires allocation. |
| `Unk02e000_SetSlot` | 0x0202e000 / 52 | Rejects null manager and signed indices outside 0..15; stores input word at manager +0x74 + index*4. Borrowed manager remains externally owned. |

## M1-T653

Seven targets verified at **100% objdiff**. Six existing matching candidates
were retained and documented; `func_0202e4dc` was added with its typed return
and argument, correcting its earlier void/pointer declaration. No tests were
added because this card uses original-instruction matching as its acceptance check.
The TU already existed despite the card's creation wording.

| Function | Address / bytes | Instruction evidence and contract |
| --- | --- | --- |
| `Unk02e000_Unk_02e7c0` | 0x0202e7c0 / 52 | Signed byte at work+0x354+i selects work+0x74+byte*60; negative returns null. Requires allocation and valid input index. |
| `Unk02e000_Unk_02e180` | 0x0202e180 / 56 | Clears eight bytes at Unk_02e8f0, writes 2,2,1,1, calls func_0202e1b8. Requires allocation; overall purpose unconfirmed. |
| `Unk02e000_GetSlot` | 0x0202e034 / 60 | Loads manager+0x74+i*4, supporting the existing name. Null manager or signed index outside 0..15 returns zero. |
| `Unk02e000_GetRecordUnk1c` | 0x0202eb0c / 60 | Loads halfword +0x1c of record id-1 in the 36-byte table. IDs above 491 return zero; callers must supply valid IDs 1..491. |
| `func_0202e1b8` | 0x0202e1b8 / 64 | Masks bytes 0 and 1 of Unk_02e8f0 to two bits, selects byte from ROM 0x0212b3f8 and word from ROM 0x0212b3fc, calls func_0205e800 and func_0205e5c4. Unmatched; see hard-list entry below. |
| `func_0202e4dc` | 0x0202e4dc / 68 | Looks up signed low halfword with FindIndex_02e3e4; nonnegative result selects GetSlotPtr. Missing index or null slot retries lookup with -1. Returns borrowed record; allocation required. |
| `Unk02e000_Unk_02e840` | 0x0202e840 / 68 | Searches the three nonnegative signed bytes at work+0x354 for FindEntryIndex(p); returns boolean. Requires allocation. |
| `Unk02e000_TestFlag` | 0x0202e924 / 68 | Tests bit i at work+0x374, supporting the name; indices outside 0..89 return false. Requires allocation for valid indices. |

### M1-T653 hard list

- `func_0202e1b8`: left linked from the delinked original. Direct fixed-address
  table indexing reached 43.44%; disabling propagation and using local table
  pointers reached 96.25% with identical size and operations, but index and table
  registers r0/r1 were exchanged in both lookups. Tried declaration order,
  scoped pointers, integer address expressions, explicit index/value temporaries,
  bitfield views and register hints; none matched all instructions. Candidate
  omitted as required by the card. A human can use `tools/decompme.py` for scratch work.

## Not done in M1-T654
- `Unk02e000_GetRecordUnk1e`
- `Unk02e000_GetRecordUnk1f`
- `Unk02e000_SetRecord`
- `Unk02e000_FindEntryIndex`
- `Unk02e000_IsRecordAvailable`
- `Unk02e000_GetRecordFlag0`
- `Unk02e000_GetRecordFlag1`
- `Unk02e000_SetSlot40`

## Not done in M1-T655
- `Unk02e000_SetRecordUnk1c`
- `func_0202e520`
- `Unk02e000_GetRecord`
- `Unk02e000_FindIndex_02e3e4`
- `Unk02e000_SetBit_02e968`
- `Unk02e000_SetRecordFlag1f`
- `Unk02e000_SetRecordFlag1f_1`
- `Unk02e000_SetRecordUnk1e`

## Not done in M1-T656
- `Unk02e000_SetRecordUnk1f_2`
- `Unk02e000_GetSlotPtr`
- `func_0202e5dc`
- `func_0202e23c`
- `Unk02e000_FindEntryIndex`: hand-matched
- `Unk02e000_SetRecord`: hand-matched
- `Unk02e000_SetSlot40`: hand-matched
- `Unk02e000_GetRecordUnk1e`: hand-matched
- `Unk02e000_IsRecordAvailable`: hand-matched
- `Unk02e000_GetRecordFlag0`: hand-matched
- `Unk02e000_GetRecordFlag1`: hand-matched
- `Unk02e000_GetRecordUnk1f`: hand-matched
- `Unk02e000_FindIndex_02e3e4`: hand-matched
- `Unk02e000_GetSlotPtr`: hand-matched
- `Unk02e000_SetBit_02e968`: hand-matched
- `Unk02e000_GetRecord`: hand-matched
- `Unk02e000_SetRecordUnk1c`: hand-matched
- `Unk02e000_SetRecordUnk1e`: hand-matched
- `Unk02e000_SetRecordFlag1f`: hand-matched
- `Unk02e000_SetRecordFlag1f_1`: hand-matched
- `Unk02e000_SetRecordUnk1f_2`: hand-matched

## M1-T651

All eight existing candidates verified at **100% objdiff**. Evidence is the
original ARM instruction sequence. Address returns retain the existing 32-bit
ABI; all views are borrowed and require prior allocation and valid indices.
Neutral names remain where instruction evidence does not establish purpose.

| Function | Address / bytes | Instruction evidence and contract |
| --- | --- | --- |
| `Unk02e000_Unk_02e5c4` | 0x0202e5c4 / 24 | Calls Unk_02e75c(index), then func_02008848(record, 0, 72). |
| `Unk02e000_Unk_02e75c` | 0x0202e75c / 24 | Loads allocation word +4 and multiply-adds index times 72. |
| `Unk02e000_Unk_02e884` | 0x0202e884 / 24 | Loads allocation word +4; adds 0x5d0 and 0x6000. |
| `Unk02e000_ClearMgrUnk38` | 0x0202e090 / 28 | Calls manager alias getter; conditionally stores zero at +0x38 and +0x3c, supporting the existing name. Null is allowed. |
| `Unk02e000_Call_02008848` | 0x0202e5a8 / 28 | Calls Unk_02e884 then func_02008848 with zero and length 0x1148; returns its result. |
| `Unk02e000_Unk_02e740` | 0x0202e740 / 28 | Calls Unk_02e75c, loads unsigned byte +0x28, returns whether nonzero. |
| `Unk02e000_GetAreaRecord` | 0x0202e7a4 / 28 | Calls GetWorkArea, adds 0x74, multiply-adds index times 60; record table arithmetic supports the existing name. |
| `Unk02e000_Unk_02e89c` | 0x0202e89c / 28 | Loads allocation word +4, adds 0x26 and 0x5d00, then index shifted left two. Address need not be word aligned. |

No M1-T651 targets remain on the hard list.
