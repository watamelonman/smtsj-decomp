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

## Not done in M1-T382
- `Unk094fe0_TestBit`
- `Unk094fe0_GetSlot`
- `Unk094fe0_TestBit990`
- `Unk094fe0_TestFlag18`
- `func_020950e4`
- `func_0209512c`
- `Unk094fe0_Unk_095258`
- `Unk094fe0_Unk_0952ac`
- `Unk094fe0_Call_02095320`: hand-matched
- `Unk094fe0_Call_0209502c`: hand-matched
- `Unk094fe0_TestBit`: hand-matched
- `Unk094fe0_TestFlag18`: hand-matched
- `Unk094fe0_SetSlot`: hand-matched
- `Unk094fe0_GetSlot`: hand-matched
- `Unk094fe0_Unk_095204`: hand-matched
- `Unk094fe0_TestBit200`: hand-matched
- `Unk094fe0_TestBit990`: hand-matched
- `Unk094fe0_Call_02095370`: hand-matched
- `Unk094fe0_Unk_095370`: hand-matched
- `Unk094fe0_Unk_09502c`: hand-matched
- `Unk094fe0_Unk_095258`: hand-matched
- `Unk094fe0_Unk_0952ac`: hand-matched
- `Unk094fe0_Unk_0953f0`: hand-matched
