# src/game/unit_02094fe0.c

## M1-T380: verified matching functions

All eight functions below report 100% in objdiff with the configured ARM compiler.
Addresses and instructions refer to the original ARM9 image. Work pointers and
returned views are borrowed; these helpers do not allocate or transfer ownership.
Unknown field and table meanings retain neutral names.

| Function | Size | Contract and evidence |
| --- | --- | --- |
| `Unk094fe0_Nop_095000` | 4 B | Returns the work pointer as a byte view. The sole `bx lr` at 0x02095000 leaves r0 unchanged; callers use the result as the bit-array base. |
| `Unk094fe0_Unk_095004` | 8 B | Returns the byte view at work +0x990. The `add r0, r0, #0x990` at 0x02095004 proves the offset; `Unk094fe0_TestBit990` indexes the returned bytes. Requires valid work. |
| `Unk094fe0_GetUnkField9a0` | 8 B | Reads a word from valid work +0x9a0, exactly the `ldr` at 0x020953bc. No field semantics are inferred. |
| `Unk094fe0_Thunk_0202e8cc` | 12 B | Returns the shared work pointer. The `ldr ip`/`bx ip` at 0x02094fe0 uses the literal address of `Unk02e000_GetUnk094fe0Work`. |
| `Unk094fe0_GetWorkUnkField9a0` | 16 B | Retrieves shared work and calls the field getter. The original has calls at 0x020953b0 and 0x020953b4 rather than an inlined load. |
| `Unk094fe0_Unk_094fec` | 20 B | Returns the unchecked address of record index in `data_02175dac`, with 28-byte stride. The literal at 0x02094ffc and `mla` at 0x02094ff4 establish base and stride. Extent and record purpose remain unknown; callers must provide a valid index. |
| `Unk094fe0_SetUnkField9a0` | 20 B | Retrieves shared work and stores the supplied word at +0x9a0. The store at 0x020953a4 establishes the offset and width. |
| `Unk094fe0_Call_020950b4` | 24 B | Retrieves shared work, passes the original unsigned bit index to `Unk094fe0_TestBit`, and returns its result. Calls at 0x020950a4/0x020950ac establish the forwarding contract. The callee handles out-of-range indices. |

The existing C bodies already matched at task start. Address helpers now use
pointer parameters/results instead of integer addresses; the getter takes a typed
const work pointer. Matching remained 100% after these type corrections.
No new tests are required by this card; objdiff verifies the compiled behavior.

## M1-T380 hard list

None.

## M1-T381: verified matching functions

All eight report 100% in objdiff. The shared work pointer comes from `Unk094fe0_Thunk_0202e8cc`.
The bit setter `func_020950e4(bits, bit, set)` sets the bit when `set == 1` and clears it otherwise.

| Function | Size | Contract and evidence |
| --- | --- | --- |
| `Unk094fe0_Call_02095320` | 24 B | Returns `Unk094fe0_TestBit990(work, a)`: 1 if bit a-1 of the +0x990 array is set. r0 from the callee is passed back, so the return type is now `int` (it was `void`). |
| `Unk094fe0_Call_0209502c` | 32 B | Forwards (a, b) with the shared work pointer to `Unk094fe0_Unk_09502c`. Called by unit_0203aae8 with b = 0/1. |
| `Unk094fe0_Call_02095370` | 32 B | Forwards (a, b) with the shared work pointer to `Unk094fe0_Unk_095370`. |
| `Unk094fe0_SetSlot` | 36 B | Stores v in `slots[i]` of an `Unk094fe0Record`. A null record or i outside 0..4 is ignored (`cmp #5; bxge`). The 28-byte record type comes from the 0x1c stride of `Unk094fe0_Unk_094fec`: the word at +0, `slots[5]` at +4, and the word at +0x18 that `TestFlag18` reads. |
| `Unk094fe0_TestBit200` | 40 B | Returns 1 if bit a of `w->unk_0200` (work +0x200) is set. Returns 0 if the bit is clear or a >= 15360 (unsigned `cmp #15360; movcs`). The bound gives an array of 0x780 bytes. |
| `Unk094fe0_Unk_095370` | 40 B | Sets or clears bit a-1 of the +0x990 array (`Unk094fe0_Unk_095004`). Ignores a outside 1..128 (`sub #1; cmp #128; popcs`). |
| `Unk094fe0_Unk_095204` | 44 B | Sets or clears bit a of the shared work's `unk_0200` array. Ignores a >= 15360. |
| `func_020953c4` | 44 B | Writes (cnt, flag, id) into the shared work's `unk_09a4` record (strb +0x9a6, strb +0x9a7, strh +0x9a4). `Unk094fe0_Unk_0953f0` later reads and clears that record. To match, the code must go through an `Unk094fe0Timer *` (`add r1, r0, #0x1a4` base). Direct `w->unk_09a4.x` stores compile to 40 bytes. |

Struct changes: `Unk094fe0Work` now names the +0x200 bit array (`unk_0200[0x780]`), split out of the old leading pad. `Unk094fe0Record` is new. The stale `void func_020950e4();` declarations were replaced with the real prototype. The other functions in the file still match.

## M1-T381 hard list

None.

## Not done in M1-T383
- `Unk094fe0_Unk_09502c`
- `Unk094fe0_Unk_0953f0`
- `func_02095468`

## M1-T382: verified matching functions

These six report 100% in objdiff. Their bodies were already in the file and matched. This card
added the per-function comments and replaced the raw-offset record access with `Unk094fe0Record`
fields. Matching stayed at 100% after that change.

| Function | Size | Contract and evidence |
| --- | --- | --- |
| `Unk094fe0_TestBit` | 48 B | Returns 1 if bit `bit` of the work's leading byte array (the `Nop_095000` view) is set. Returns 0 if the bit is clear or `bit >> 3 >= 512` (the `cmp #512` bound). |
| `Unk094fe0_GetSlot` | 48 B | Returns `slots[i]` of an `Unk094fe0Record`, or 0 for a null record or i outside 0..4. It is the read counterpart of `Unk094fe0_SetSlot`. unit_0203aae8 casts the result to s16. |
| `Unk094fe0_TestBit990` | 48 B | Returns 1 if bit a-1 of the work's +0x990 array is set. Returns 0 if the bit is clear or a is outside 1..128 (`sub #1; cmp #128`). |
| `Unk094fe0_TestFlag18` | 56 B | Returns 1 if bit `bit` (0..31) of the record's +0x18 word is set. Returns 0 for a null record, an out-of-range bit or a clear bit. The parameter is now `const Unk094fe0Record *` (it was `u8 *` + `FIELD`). |
| `Unk094fe0_Unk_095258` | 84 B | Arms countdown slot i of `timers[4]` in the shared work with (id, cnt). Returns 1 on success, or 0 if i >= 4, id >= 4096 or cnt == 0. |
| `Unk094fe0_Unk_0952ac` | 92 B | Decrements every non-zero `timers[i].cnt`. When a slot reaches 0, it calls `Unk0e651c_SetBitChecked(id, 1)`. |

## M1-T382 hard list

Both functions are still linked from the delink, so `Unk094fe0_Unk_09502c`, `Unk094fe0_Unk_095204` and
`Unk094fe0_Unk_095370` call the original code.

- `func_020950e4` (72 B): `int f(u8 *bits, u32 bit, int set)`. It returns 0 for null bits. Otherwise it sets bit `bit` if `set == 1` and clears it if not, then returns 1.
  The closest source (`u32 sh` assigned after the null check, then
  `bits[bit >> 3] = bits[bit >> 3] & (u8)~(u8)(1 << sh)`) matches every word except the last `and`, which is
  `and r2, r3, r2` where the ROM has `and r2, r2, r3`. The `&=` form also puts `mvn` into r2 instead of r3.
  Tried without success: swapping operand order, u8/u32/int casts, mask and value locals, index and pointer locals,
  `/ 8` and `% 8`, a ternary, a switch, an early return and a static inline helper.
- `func_0209512c` (76 B): `int f(Unk094fe0Record *p, int bit, int set)`. It sets bit `bit` (0..31) of `p->unk_0018`
  if `set == 1` and clears it if not. It returns 0 for a null record or an out-of-range bit. This is the setter that
  matches `TestFlag18`; unit_0203aae8 calls it with set = 1. Only the else branch differs: the ROM has
  `mvnne r2, r2, lsl r1; ldrne r1; andne r1, r1, r2`, while every variant compiles to
  `mvnne r1, ...; ldrne r2; andne r1, r2, r1`. Tried: the same families as above, plus a `u32 *`/FIELD/s32 field,
  `1u`, u32/u8 `set`, and `-1 ^ m`.
