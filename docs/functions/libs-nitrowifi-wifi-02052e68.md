# libs/NitroWiFi/wifi_02052e68

Reconstruction of the NitroWiFi (SDK 4.2) buffer-group and connection-state
helpers in the partial TU at `0x02052e68`. All retained C definitions match
the delinked ARM instructions at 100%; deferred functions are listed separately. The TU is still linked from the delink;
the split configuration stays human-owned.

A public-source search (pret/pokeplatinum `lib/` and `src/`, which rebuild
NitroSDK/NitroSystem code for the DS) found no NitroWiFi unit, and no other
matching public NitroWiFi source was located. A follow-up web search for
NitroSDK/NitroWiFi and `WH_SYSSTATE_IDLE`/`WH_SYSSTATE_BUSY` also found no
matching source for these wrappers. The reconstruction therefore follows the
original instruction stream and keeps the neutral `func_XXXXXXXX` symbols.

## Data layout (evidence from instruction offsets)

`data_0215f4d8` is the buffer group:

| Offset | Type | Meaning |
| --- | --- | --- |
| +0x00 | u16 | current heap index used by `func_02052f7c` |
| +0x02 | u16 | saved heap index restored by `func_02052f68` |
| +0x04 | u32 | live-buffer counter changed by `02052f7c`/`02053000` |
| +0x08 | u32 * | heap descriptor array, `count + 1` entries |
| +0x0c | u32 | bytes arena 2 contributes to the group |

`data_0215f500` is the provider-owned connection block. Its private borrowed
view exposes `+0x0a` (halfword cleared by `func_020531fc`), `+0x14` (state,
written by `func_0205304c`), `+0x30` (pending value) and `+0x40` (callback).
The four-byte event prefix is borrowed only during callbacks; +2 supplies the
unsigned halfword result. No new public layout or ownership boundary is added. `data_021439e0`, `data_02143a08` and `data_02143a10` are the callback
argument tables read by `func_0205304c`.

The heap primitives were identified from their bodies: `func_02006ed8` /
`func_02006ec4` read an arena's base/end words, and `func_02020438` aligns a
span to 4 bytes, rejects spans under `0x4c` bytes and initialises a heap
descriptor through `func_0201fff0`; `func_02020470` then allocates from it.

## Functions

| Function | Behavior and instruction evidence | Match |
| --- | --- | --- |
| `func_02052e68` | Builds the buffer group for `count` transfer chunks. Sums the arena-0 and arena-2 spans (the arena-2 span is stored at +0xc), reserves an aligned `(count + 1)`-word heap array at the arena-0 base, then creates one heap per requested size rounded up to 32 bytes and gives the final slot the remaining span. Records `count` at +0 and +2; returns 1. `sizes == 0` skips the loop, so only the trailing heap is created. | 100% |
| `func_02052f58` | Stores the low halfword of its argument in the group's current-index field. `func_020caea8` calls it with 0 before a record load. | 100% |
| `func_02052f68` | Copies the saved index (+2) back to the current index (+0); the matching restore in `func_020caea8`. | 100% |
| `func_02052fe0` | Returns allocated storage from the current heap (used by `sdk_02051378.c`) with flag 1, which `func_02052f7c` maps to allocation mode 32 (head of the free span). | 100% |
| `func_02052ff0` | Returns allocated storage (forwarded by `func_0208daa0` in `cri_0208d8e8.c`) with flag 0, which `func_02052f7c` maps to mode -32 (tail). | 100% |
| `func_02053048` | Empty hook: a lone `bx lr`. Its two call sites (`0x020481f4`, `0x020a0e38`) ignore the return value, so no side effect is observable. | 100% |
| `func_020530b0` | Stores a pending value at connection +0x30 unless the state is exactly 9 or 10. Evidence: the ROM computes `state - 9` and stores only when the unsigned result is greater than 1. | 100% |
| `func_020531d8` | Event handler: a nonzero halfword at event +2 is forwarded to `func_020530b0`; zero requests state 1 through `func_0205304c`. Only caller is `func_020531b0`. | 100% |
| `func_02053130` | Requests state 3, submits callback `func_02053160` to `func_02010b7c`, returns 1 for result 2, otherwise records the result through `func_020530b0` and returns 0. Ordered BLs, callback literal and CMP #2 at 0x02053134..0x0205315c. | 100% |
| `func_020531b0` | Submits `func_020531d8` to `func_02010a54`; result 2 returns 1, otherwise records the result and returns 0. Callback literal and CMP #2 at 0x020531b4..0x020531bc. | 100% |
| `func_020531fc` | Returns 0 unless connection state +0x14 equals 2; then clears halfword +0xa, requests state 3 and returns 1. LDR/CMP/STRH evidence at 0x02053204..0x0205321c. | 100% |
| `func_02053288` | Requests state 3 and submits `func_020532b8` to `func_02010b7c`; result 2 returns 1, otherwise records the result and returns 0. Ordered BLs and callback literal at 0x0205328c..0x020532b4. | 100% |
| `func_020532b8` | Nonzero event +2 records the result then calls `func_0205342c`. Zero calls `func_020532ec`; a zero follow-up result requests state 9. LDRH and ordered BL paths at 0x020532bc..0x020532e4. | 100% |
| `func_02053324` | Nonzero event +2 records the result; zero requests state 1. LDRH/CMP and BL paths at 0x02053328..0x02053340. | 100% |
| `func_02053348` | Requests state 3 and submits `func_02053378` to `func_020109dc`; result 2 returns 1, otherwise records the result and returns 0. Ordered BLs and literal at 0x0205334c..0x02053374. | 100% |
| `func_020533ac` | Nonzero event +2 requests state 10; zero requests state 0. LDRH and two state-provider BL paths at 0x020533b0..0x020533cc. | 100% |
| `func_020533d4` | Returns the connection state word at +0x14; `func_0205304c` is its writer. | 100% |

The ROM passes 32-byte-aligned spans and 32-byte-rounded sizes, but the C keeps
the constants explicit so the arithmetic stays visible. Values stored through
the halfword fields truncate as the original stores do.

## M2-T453 functions

| Function | Behavior and instruction evidence | Match |
| --- | --- | --- |
| `func_02052f7c` | Masks interrupts, allocates from the current heap with alignment +32 for nonzero flag or -32 for zero, increments +4 only on success, restores the mask and returns storage. BLs to 02007a58/02020470/02007a6c identify the sequence. | 100% |
| `func_02053000` | Masks interrupts, finds the containing heap with 0201ff28, frees a non-null buffer with 020204a0, decrements +4 and restores the mask. Null leaves bookkeeping unchanged. | 100% |
| `func_02053160` | Records event +2 errors then invokes 020533e4; success calls 020531b0. A rejected follow-up invokes the optional +0x40 callback with borrowed table 02143a34 before cleanup. LDRH, BL and BLX paths establish the contract. | 100% |
| `func_020532ec` | Requests state 3 and submits 02053324 with argument zero to 02010a94. Result 2 returns success; other results are recorded before 020533e4 and return zero. | 100% |
| `func_02053378` | Nonzero event +2 requests state 9 then reloads and records the result; zero requests state 1. The reload preserves callback changes to the borrowed event. | 100% |
| `func_020533e4` | In state 5, calls 02010bec with borrowed work 0215fdc0 and records nonzero results. Always attempts 02053348; rejection selects state 10. CMP #5 and common BL at 0205340c establish the paths. | 100% |
| `func_02053570` | Skips only 02007e94 when state is 1; always requests state 3 and submits 020533ac to 02010a14. Result 2 clears halfword +6 and returns one; rejection requests state 9 and returns zero. | 100% |
| `func_02053230` | State 6 alone requests state 3, calls 02010c34 with work 0215f5a0, records errors and otherwise returns normalized acceptance from 02053288. Kept in delink; see hard list. | Deferred |

The borrowed connection view additionally exposes halfword +6 and types the
+0x40 callback as accepting a borrowed table pointer. No storage is retained.
A fresh public-source web search for NitroSDK wireless connection-manager source
found provider API documentation but no matching implementation of these wrappers.

## Hard list

- `func_02053230` (M2-T453): the reconstructed C matched every instruction
  except the order of the final conditional moves: the original emits
  `moveq r0, #0; movne r0, #1`, while mwcc emits the reverse order.
  Tried conditional expressions, explicit return branches, normalized boolean
  temporaries, switch, and nested state/error branches. Other variants changed
  function size or branch layout. The closest objdiff result was 99.45%.
  The candidate was removed and the original delink remains authoritative;
  a human can open a decomp.me scratch for this 88-byte function.

## M2-T454 functions

| Function | Behavior and instruction evidence | Match |
| --- | --- | --- |
| `func_02052e68` | Existing buffer-group initializer reverified against the delink; no implementation change needed. | 100% |
| `func_0205304c` | Calls the optional printf-style callback with `%s -> ` and the old state's table entry, stores the new state at +0x14, then reports `%s\n` with its table entry. Strings at 02143a08/02143a10 and table indexing at 02053070/02053094 establish the argument contract. State indices must fit the provider table. | 100% |
| `func_020530cc` | Submits borrowed work 0215f5a0 to 02010c34, records nonzero errors and returns zero; otherwise attempts 02053130. A rejected follow-up notifies with table 02143a14 before cleanup and returns zero; success returns one. Ordered BL/BLX paths at 020530d4..02053120. | 100% |
| `func_0205342c` | State 1 reports the already-idle string and returns. Other states report `WH_Finalize, state = %d` with the current state, then reload it. State 2 attempts 020531fc; states outside 4/5/6 request state 3 and cleanup. Otherwise requests state 3 and dispatches mode +0x38: 3 attempts 02053230; 5 cleans work before falling through to mode 1's 02053288; 2 attempts 020530cc; 4 cleans work before falling through to mode 0's 02053130. Failed requests invoke 020533e4; unknown modes return. Evidence: format string 02143a6c and six-way jump table 020534c8. | 100% |

The callback is variadic because the original strings require zero or one
format argument. Its tables and the mode word +0x38 remain provider-owned.
A fresh public-source search for NitroSDK WH state-manager code found no
matching implementation; the ROM strings and instructions supply the evidence.
