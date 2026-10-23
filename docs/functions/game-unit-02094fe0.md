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

## Not done in M1-T381
- `Unk094fe0_Call_02095320`
- `Unk094fe0_Call_0209502c`
- `Unk094fe0_Call_02095370`
- `Unk094fe0_SetSlot`
- `Unk094fe0_TestBit200`
- `Unk094fe0_Unk_095370`
- `Unk094fe0_Unk_095204`
- `func_020953c4`

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
