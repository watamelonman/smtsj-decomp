# src/game/unit_020e8228.c

## M1-T897 verified wrappers

All eight functions match at 100% objdiff. Evidence below comes from the
original ARM instructions and relocations in the delinked object. Unknown
argument meanings retain neutral names; no domain semantics are inferred.

- `Unk0e8228_Nop_0e93d4` (4 B, 020e93d4): `bx lr` only; a no-op callback taking no parameters.
- `Unk0e8228_Thunk_02057534` (12 B, 020e8e60): literal-load and `bx ip` tail-call `func_02057534`, taking no parameters.
- `Unk0e8228_Thunk_02045c38` (12 B, 020e8f68): literal-load and `bx ip` tail-call `Unk044904_GetFlag18`; returns its integer flag result unchanged. The callee implementation in `src/game/unit_02044904.c` confirms the return contract.
- `Unk0e8228_Unk_0e8cd8` (16 B, 020e8cd8): `mvn r0, #0` and a relocation to `ScanVisor_Unk_0a29a0` pass `0xffffffff` as an unsigned sentinel, with no caller parameters.
- `Unk0e8228_Unk_0e8e50` (16 B, 020e8e50): `mov r0, #4` and a relocation to `func_02057524` pass the fixed integer 4, with no caller parameters.
- `Unk0e8228_Unk_0e8e6c` (16 B, 020e8e6c): `mov r0, #2` and a relocation to `func_02057eb8` pass the fixed integer 2, with no caller parameters.
- `Unk0e8228_Unk_0e8e7c` (16 B, 020e8e7c): `mvn r0, #0` and a relocation to `func_02057eb8` pass -1, with no caller parameters.
- `Unk0e8228_Unk_0e8eac` (16 B, 020e8eac): `add r0, r0, #8` and a relocation to `Unk0e8228_Unk_0e8e8c` forward the unsigned argument plus eight. Unsigned arithmetic preserves ARM wraparound for the full input range.

No M1-T897 functions remain on the hard list. The empty callback is intentional,
as demonstrated by its single original return instruction.

## M1-T898 verified functions

All eight functions match at 100% objdiff. Evidence comes from the delinked
ARM instructions and relocations plus the callers named below. Names stay
neutral where the callers only show a loop bound or an opaque forwarding.

- `Unk0e8228_Get_data_02176ce0` (16 B, 020e9038): loads the global pointer
  stored in `data_02176ce0` and returns it. The data symbol supplies the name;
  users treat the result as the shared work object (see
  `Unk0e8228_Unk_0e84e4`).
- `Unk0e8228_Unk_0e8398` (20 B, 020e8398): calls `Unk0e8228_Unk_0e8d90(7,
  0xffffffff)`, forwarding selector 7 and the unsigned -1 sentinel. Callers
  run it before scanning the entries counted by `Unk0e8228_Unk_0e8488()`, but
  the callee is opaque, so the name stays neutral.
- `Unk0e8228_Unk_0e8460` (20 B, 020e8460): returns the word stored at
  `data_02150c30 + 0x2c` plus one. Used as an exclusive loop bound in
  `src/game/unit_020eed24.c` and as a count guard in `src/game/unit_020ea208.c`;
  the meaning of the stored word itself is not established.
- `Unk0e8228_Unk_0e8474` (20 B, 020e8474): returns `*(s32 *)(data_02150c30 +
  0x34) + 1`; `unit_020eed24.c` iterates that many 64-byte records.
- `Unk0e8228_Unk_0e8488` (20 B, 020e8488): returns `*(s32 *)(data_02150c30 +
  0x3c) + 1`; callers use it as a loop bound and compare it with one to detect
  an empty table (`unit_020f0be0.c`, `unit_020f4c50.c`).
- `Unk0e8228_Unk_0e9c94` (20 B, 020e9c94): tail-calls `func_020e9c00(arg0, 2,
  arg1)`, inserting constant selector 2 between the two forwarded arguments.
- `Unk0e8228_Unk_0e84e4` (24 B, 020e84e4): returns the word at shared-work
  offset 0x178, or zero when `Get_data_02176ce0` returns null. Callers compare
  and iterate it as a record count (`src/game/unit_020ef248.c`).
- `Unk0e8228_Unk_0e84fc` (24 B, 020e84fc): calls
  `Unk0e8228_Unk_0e8374(8)`, forwards its result to
  `Unk0e8228_GetArr88Field20`, then forwards that result as the id to
  `Unk09974c_Unk_099d14`; the third call's result is returned, and
  `unit_020ef248.c` consumes it as a borrowed record pointer. The argument
  flow is visible in the delinked original (`mov r0,#8; bl ...; bl ...; bl ...`).

## M1-T899 verified field accessors

All eight functions are 24 bytes and match at 100% objdiff. The original ARM
loads, stores and conditional instructions establish the following contracts.
The two private layout views borrow provider storage and expose only observed
fields; their padding represents offsets, not inferred content. The work
provider keeps its existing integer-address ABI for other functions in this TU.
Field meanings remain unknown, so function names stay neutral.

| Function | Instruction evidence and contract |
| --- | --- |
| `Unk0e8228_Unk_0e8514` | Calls `Unk0ea208_GetArr58`; `ldrhne [r0,#0x20]` returns an unsigned halfword, with `moveq r0,#0` for an absent record. |
| `Unk0e8228_Unk_0e8b7c` | Calls the shared work getter; `movne r1,#1; strne [r0,#0x18]` sets the word only when work exists. |
| `Unk0e8228_Unk_0e8b94` | The same null check and `strne [r0,#0x18]` clear that word to zero. |
| `Unk0e8228_Unk_0e8bac` | `moveq r0,#0; ldrne [r0,#0x18]` returns the word or zero without work. |
| `Unk0e8228_Unk_0e8c50` | Preserves the full unsigned argument in r4 across the getter call and conditionally stores it at work offset 0x24. |
| `Unk0e8228_Unk_0e8c68` | `moveq r0,#0; ldrne [r0,#0x24]` returns the word or zero without work. |
| `Unk0e8228_Unk_0e8db8` | `movne r1,#1; strne [r0,#0x184]` sets the word only when work exists. |
| `Unk0e8228_Unk_0e8f20` | `moveq r0,#27; ldrne [r0,#0x180]` returns the word, defaulting to 27 without work. |

No M1-T899 functions remain on the hard list. No new behavioral tests were
required by this card; objdiff checks the emitted instructions against retail.

## M1-T900 verified functions

All eight functions match at 100% objdiff. Evidence is the original ARM
instructions and relocations in the delinked object. Layouts borrow provider
storage; unknown field meanings retain neutral names. No new behavioral tests
are required by this card; objdiff verifies the emitted instructions directly.

| Function | Instruction evidence and contract |
| --- | --- |
| `Unk0e8228_Unk_0e8f38` (24 B, 020e8f38) | Calls the work getter; `moveq r0,#0; ldrne r0,[r0,#0x17c]` returns the word or zero without work. |
| `Unk0e8228_Unk_0e8f50` (24 B, 020e8f50) | Preserves the unsigned argument in r4 across the getter; `strne r4,[r0,#0x28]` writes only when work exists. |
| `Unk0e8228_Unk_0e9020` (24 B, 020e9020) | Same argument preservation and null check, with `strne r4,[r0,#0x10]`. |
| `Unk0e8228_Unk_0e9048` (24 B, 020e9048) | Dereferences both record pointers, loads unsigned bytes at 0x2e, then subtracts the second from the first. Valid nonnull pointers are required; result ranges from -255 to 255. |
| `Unk0e8228_Unk_0ea028` (24 B, 020ea028) | Calls `Unk0ea208_Get_data_02176ddc`, returns immediately on null, otherwise calls `func_02061424` with the provider handle. The getter result in r0 is not clobbered by `cmp r0,#0; popeq`, so it is still r0 at the call: the provider pointer is func_02061424's handle argument. `src/game/unit_020ea208.c:122` declares `void func_02061424(u32 handle)`, and `docs/functions/game-unit-020fedd4.md` identifies it as the task release call. |
| `Unk0e8228_Unk_0ea040` (24 B, 020ea040) | Calls the same provider; returns its word at 0x1cc or zero if absent. |
| `Unk0e8228_IsSet_data_02176cdc` (28 B, 020e8228) | Relocation names the global; loads its word and uses conditional moves to return exactly zero or one for its nonzero test. |
| `Unk0e8228_Call_02008848` (28 B, 020e8244) | At 020e8244, relocations identify the tail-call target and `data_02176ce4`; immediate arguments are zero and 0xf8. These establish the existing Call name without inferring the callee's purpose. |

No M1-T900 functions remain on the hard list.

## Hard list
- (none)

## M1-T901 verified functions

All eight functions match at 100% objdiff. Evidence is the original ARM
instructions and relocations in the delinked object. Unknown argument meanings
retain neutral names; no domain semantics are inferred.

| Function | Instruction evidence and contract |
| --- | --- |
| `Unk0e8228_Unk_0e82ac` (28 B, 020e82ac) | Calls `Unk02e000_Unk_02e8f0` (the allocation word + 0x90, see `src/game/unit_0202e000.c`), then `ldrb r0,[r0,#3]`; `moveq r0,#1` / `movne r0,#0` returns exactly 1 when that byte is zero. `src/game/unit_020ee904.c` consumes the result as a state flag, so the name stays neutral. |
| `Unk0e8228_Unk_0e8684` (28 B, 020e8684) | Calls the work getter; `popeq` returns without work, otherwise forwards the work pointer and its word at +0x10 to `func_020e942c`, which stores the second argument at work + 0x0c. |
| `Unk0e8228_Unk_0e8c80` (28 B, 020e8c80) | Calls the work getter; returns 0 when absent, otherwise forwards the work pointer to `Unk0e8228_GetCurEntry`. Callers pass the result to `func_02044ec4` as an entry key (`unit_020ea208.c`, `unit_020efdf4.c`). |
| `Unk0e8228_Unk_0e8cbc` (28 B, 020e8cbc) | Calls the work getter; `popeq` returns without work, otherwise forwards the word at +8 to `ScanVisor_Unk_0a29a0`. |
| `Unk0e8228_Unk_0e8c9c` (32 B, 020e8c9c) | Calls `0e8c80`, passes its result to `func_02044ec4`, then passes that record to `func_0204a244`; `cmp r0,#6` returns exactly 1 when the state is 6. |
| `Unk0e8228_Unk_0e8d18` (32 B, 020e8d18) | Preserves the selector in r4 across the work getter; `popeq` returns without work, otherwise forwards the work pointer and selector to `func_020e9778`. Callers pass 0 or 1 (`unit_020ee904.c`, `unit_020efdf4.c`). |
| `Unk0e8228_Unk_0e8e8c` (32 B, 020e8e8c) | Calls the work getter; when work exists, `strne r1,[r0,#0x17c]` with `movne r1,#0` clears that word and `strne r4,[r0,#0x180]` stores the caller's selector. The pair is read back by 0e8f20/0e8f38; callers only pass 0 or 1. |
| `Unk0e8228_Unk_0e940c` (32 B, 020e940c) | Calls `Unk0e8228_Unk_0ea028` (provider release), then `Unk0feba0_Unk_0febc8`, then stores zero to the global word `data_02176ce0`. |

Typing `func_02044ec4` as `u32 func_02044ec4(u32 key)` made the existing
implicit-argument call in `Unk0e8228_Unk_0e8bc4` explicit
(`func_02044ec4(Unk0e8228_GetArr30(0))`); that function still matches at 100%.

No M1-T901 functions remain on the hard list.

## M1-T902 verified helpers

All eight functions match at 100% objdiff. Evidence is the original ARM
instructions at the addresses below; callers retain ownership of all storage.

| Function | Instruction contract |
| --- | --- |
| `Unk0e8228_Unk_0e9728` (32 B, 020e9728) | Calls `func_020e8628`, compares against exactly one, and calls `func_020ea0ec` on equality or `func_020ea160` otherwise. Takes no arguments. |
| `Unk0e8228_Unk_0e9f18` (32 B, 020e9f18) | Six word stores clear offsets 0 through 20. Requires a writable 24-byte row; 020e8260 supplies global table storage. |
| `Unk0e8228_Unk_0e9f38` (32 B, 020e9f38) | Stores the second argument at offset zero, then clears offsets 4 through 20. Requires a writable 24-byte row, as supplied by 020e8260. |
| `Unk0e8228_Unk_0e8374` (36 B, 020e8374) | Preserves the selector in r4 across the work getter; returns zero without work, otherwise calls `func_020e9ca8(work, selector)`. |
| `Unk0e8228_Unk_0e8bc4` (36 B, 020e8bc4) | Calls `GetArr30(0)`, passes its result to `func_02044ec4`, forwards that result in r0 to `Unk_0e8ce8`, then normalizes to zero or one. The C now makes both forwarded arguments explicit. |
| `Unk0e8228_Unk_0e8c2c` (36 B, 020e8c2c) | Returns without work; otherwise stores one at +0x1c and 180 at +0x20. No units are inferred. |
| `Unk0e8228_IsField4One` (40 B, 020e85a0) | Returns zero without work; otherwise loads +4 and returns exactly whether it equals one. Offset and comparison support the existing name. |
| `Unk0e8228_IsFieldCOne` (40 B, 020e8b54) | Returns zero without work; otherwise loads +0x0c and returns exactly whether it equals one. Offset and comparison support the existing name. |

No M1-T902 functions remain on the hard list. Existing bodies already matched;
this card verifies them and adds typed contracts and instruction evidence.
The no-argument `IsField4One` call no longer supplies an unused work argument.

## M1-T903 verified functions

All eight functions match at 100% objdiff. Contracts below follow the original
ARM instructions and relocations; opaque parameters remain unsigned DS words
or addresses. Borrowed storage remains owned by the caller/provider.

| Function | Instruction evidence and contract |
| --- | --- |
| `Unk0e8228_Unk_0e8d90` (40 B) | 020e8d9c obtains work; null returns immediately, otherwise 020e8db0 forwards work and both opaque words to 020e9de4. |
| `Unk0e8228_IsState3` (40 B) | 020e8e3c loads work +0 and compares with 3, yielding a boolean; null work yields zero. This comparison supports the existing name. |
| `Unk0e8228_Unk_0e8dd0` (44 B) | 020e8de0 guards nullable work, then calls 020e9900 with first word, work, second word; returns its result or zero without work. |
| `Unk0e8228_Unk_0e8dfc` (44 B) | 020e8e0c guards nullable work, then calls 020e9aa0 with first word, work, second word; returns its result or zero without work. |
| `Unk0e8228_Unk_0e9fa4` (44 B) | 020e9fb4 clears 0x1cc writable bytes; publishes the address in data_02176ce0 and calls 020e9060. Caller must supply valid storage. |
| `Unk0e8228_Unk_0e8ce8` (48 B) | Null entry returns zero. Calls 0204a244, sign-extends its low byte for 020982c0, then returns one for a missing record or its signed byte at +2. |
| `Unk0e8228_GetCurEntry` (48 B) | 020e9750 loads selection +8 and clamps negative indices to zero. IsField4One selects entry bank +0x30 or +0x40. The entry-key use in 0e8c80 and its callers supports the name; caller supplies valid work and index. |
| `func_020e93d8` (52 B) | 020e93dc reads the state word; a five-slot switch calls 020bc504 with the borrowed object address and zero only for state 1. All other states return. |

No M1-T903 functions remain on the hard list. No new behavioral tests were
added: the acceptance oracle is exact instruction/relocation matching against
the original object, followed by the existing tests and full-image checksum.

## M1-T904 verified functions

All eight functions match at 100% objdiff. Six bodies already matched from
earlier waves; this card added the two missing definitions (`func_020e942c`,
`func_020e9b10`) and documented every contract from the original instructions.
No domain meaning is inferred where the evidence only shows an offset, bound
or fixed selector, so those names stay neutral.

| Function | Instruction evidence and contract |
| --- | --- |
| `Unk0e8228_GetArr30` (60 B, 020e83ac) | Calls the work getter; null work returns zero. Indices outside 0..3 return zero, otherwise `ldr [work + i*4 + 0x30]` returns the four-word table entry. |
| `Unk0e8228_GetArr58` (60 B, 020e83e8) | Same null guard; valid indices 0..11 return the twelve-word table entry at work +0x58. |
| `Unk0e8228_GetArr40` (60 B, 020e8424) | Same null guard; valid indices 0..5 return the six-word table entry at work +0x40. |
| `Unk0e8228_Unk_0e8fe4` (60 B, 020e8fe4) | Null argument returns zero. Looks up the argument through `Unk09974c_Unk_099d14`, reads the unsigned halfword at +0x22; zero returns zero, otherwise `func_020cb1a0(halfword)` supplies a record whose byte at +0x23 is compared with 7. |
| `func_020e942c` (64 B, 020e942c) | `str r1,[r0,#0x0c]` stores the selector at work +0x0c. A two-way switch calls `func_020ea058` for selector 0; selector 1 calls `func_020e8628` and invokes `func_020ea0ec` only when it returns exactly one, otherwise `func_020ea160`. Other selectors return without a call. |
| `Unk0e8228_ClearSel` (64 B, 020e9bc0) | `adds r1,r0,#392; bxeq lr` returns when the embedded selection address is null. Otherwise it clears the two flag bytes at +392 and the sixteen words at +396. The caller owns the host storage; the layout records only these observed offsets. |
| `Unk0e8228_Unk_0e8be8` (68 B, 020e8be8) | Resolves slot zero through `GetArr30`, `func_02044ec4` and `func_0204a244`; states 1, 7 and 11 return zero. Otherwise it returns `func_020e9b54(work)`, or zero when the shared work object is absent. |
| `func_020e9b10` (68 B, 020e9b10) | Scans the first nine words of `data_02150c0c` through `Unk0bc1a8_IsSlotEmptyOrFlag8`; a zero result returns zero immediately. After all nine, it returns whether `ScanVisor_Unk_0a2980` is nonzero. |

No M1-T904 functions remain on the hard list.

## M1-T905 verified functions

All eight functions match at 100% objdiff. The existing table accessors,
row selector and guarded call sequence already matched; five missing bodies
were added. Contracts follow original ARM instructions and relocations.
Opaque selectors retain neutral names and provider storage remains borrowed.

| Function | Instruction evidence and contract |
| --- | --- |
| `Unk0e8228_GetArr88Field20` (72 B, 020e849c) | Guards nullable work and indices outside 0..59, loads the pointer at work +0x88 + index*4, then returns its unsigned halfword +0x20 or zero for null. The observed offsets support the existing accessor name. |
| `Unk0e8228_Unk_0e8260` (76 B, 020e8260) | Selector zero clears the global 24-byte row at data_02176ce4 +8 through 020e9f18. Unsigned selectors 1..3 call 020e9f38 with row +32 +(selector-1)*24 and value zero; other selectors do nothing. |
| `func_020e9f58` (76 B, 020e9f58) | Initializes descriptor +0 to 0x1cc, clears +4/+0x10/+0x18, and stores relocated callback addresses 020e92a8, 020e93d4, 020e940c and 020e93d8 at +0x0c/+0x14/+0x1c/+0x20. Leaves +8 unchanged; requires 36 writable bytes. |
| `func_020e8d38` (88 B, 020e8d38) | Returns zero without work; otherwise computes 020e946c(work, arg0, arg2), then returns 020e94d8(work, arg0, arg1, result, arg3). The fifth argument is passed on the stack. |
| `func_020e9fd0` (88 B, 020e9fd0) | Calls 020611dc with relocated callbacks 020eb488/020eb6cc/020eb6e4, a zero third argument, size 0x1d8 and stack flags 1/0/1. Stores the returned handle in data_02176ddc, then passes it to 020eb308. |
| `func_020e8628` (92 B, 020e8628) | Returns 3 without work, 2 when work +4 differs from one; otherwise switches on signed work +8, returning 0 for -1, 1 for zero, and 2 for ten or other values. The original retains a comparison against ten. |
| `Unk0e8228_Unk_0e85c8` (96 B, 020e85c8) | Requires work, IsField4One and nonzero 02053800(0, 0x400). Calls 020459fc, 020e8cd8, 020e82c8, 020fda58(2), 02100208(7), then returns one; any failed guard returns zero. |
| `func_020e8ebc` (100 B, 020e8ebc) | Null work returns. Stores selector at +0x17c; selector zero sets +0x180 to 27. Otherwise looks up 020cb1a0(selector): record byte +0x23 of 4 or 8 sets 27, while other kinds set bits 12..16 of record word +0x24 plus eight. |

No M1-T905 functions remain on the hard list. No new tests are required by
this card: exact instruction and relocation matching supplies the acceptance
oracle, alongside the existing test suite and full-image checksum.

## Not done in M1-T906
- `func_020e946c`
- `func_020e9b54`
- `func_020e86a0`
- `func_020e8f74`
- `func_020e9814`
- `func_020e9aa0`
- `func_020e852c`
- `func_020ea0ec`

## Not done in M1-T907
- `func_020e9884`
- `func_020e9c00`
- `func_020ea058`
- `func_020e9778`
- `func_020ea160`
- `func_020e82c8`
- `func_020e8a30`
- `func_020e92a8`

## Not done in M1-T908
- `func_020e9de4`
- `func_020e9ca8`
- `func_020e9900`
- `func_020e9060`
- `func_020e94d8`
- `func_020e8710`
- `Unk0e8228_Unk_0e8e8c`: decompiler-derived (plain cleanup)
- `Unk0e8228_Unk_0e8260`: hand-matched
- `Unk0e8228_GetArr30`: hand-matched
- `Unk0e8228_GetArr58`: hand-matched
- `Unk0e8228_GetArr40`: hand-matched
- `Unk0e8228_GetArr88Field20`: hand-matched
- `Unk0e8228_Unk_0e8be8`: hand-matched
- `Unk0e8228_Unk_0e8c80`: hand-matched
- `Unk0e8228_Unk_0e8ce8`: hand-matched
- `Unk0e8228_IsState3`: hand-matched
- `Unk0e8228_Unk_0e8fe4`: hand-matched
- `Unk0e8228_GetCurEntry`: hand-matched
- `Unk0e8228_ClearSel`: hand-matched
