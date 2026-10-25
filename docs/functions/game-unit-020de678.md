# src/game/unit_020de678.c

## M1-T686

These eight ARM functions retain their existing symbol names. Evidence is the
instructions and relocations in `build/delinks/src/game/unit_020de678.o`.
Helper selector meanings and the global word's meaning remain unknown.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `Unk0de678_Nop_0df05c` | 4 B | At 0x020df05c, only `bx lr`; no arguments or side effects. |
| `Unk0de678_Nop_0df060` | 4 B | At 0x020df060, only `bx lr`; no arguments or side effects. |
| `Unk0de678_Thunk_02124e04` | 12 B | At 0x020df578, tail branch through the literal relocated to `Unk124c5c_Unk_124e04`; no arguments. |
| `Unk0de678_Get_data_021508d4` | 16 B | At 0x020de950, loads the address relocated to `data_021508d4`, then returns its first unsigned 32-bit word. |
| `Unk0de678_Unk_0dea60` | 16 B | At 0x020dea60, passes selector 31 to `Unk044394_Unk_044534`; no arguments. |
| `Unk0de678_Unk_0df598` | 16 B | At 0x020df598, passes selector 32 to `Unk044394_Unk_044428`; no arguments. |
| `Unk0de678_Unk_0df5a8` | 16 B | At 0x020df5a8, passes selector 32 to `Unk044394_Unk_044534`; no arguments. |
| `Unk0de678_Unk_0dee2c` | 20 B | At 0x020dee2c, adds 0xf1 then 0x500 to the integer argument and tail-calls `Unk0e651c_Unk_0e666c`; callers must avoid signed overflow. |

No hard-list entries for M1-T686.

## M1-T687

All eight ARM functions match at 100% against the delinked object. Evidence is
instruction offsets and relocations in `build/delinks/src/game/unit_020de678.o`.
Unknown state and selector meanings retain their existing neutral symbols.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `Unk0de678_Unk_0df584` | 20 B | Stores one to global offset 0x2c; no arguments. |
| `func_020df330` | 24 B | Stores one at offset 4 and the unsigned argument at offset 8. |
| `Unk0de678_Unk_0debf8` | 32 B | Forwards an unsigned word to `func_020dec18`, returns its result, and clears offset 0xcc on a nonzero result. |
| `Unk0de678_Unk_0df4cc` | 36 B | Sets offset 16, stores the first argument's low byte at 24 and the second word at 20, and clears offset 28. |
| `Unk0de678_Unk_0df0a4` | 40 B | Calls seven helpers in relocation order, including selector 30 to `Unk044394_Unk_044534`; no arguments. |
| `Unk0de678_Unk_0df348` | 44 B | Sets offset 4, calls `func_020df330(3)`, then stores the argument at offset 12. |
| `Unk0de678_CountLeading` | 48 B | Counts the nonzero halfwords at offset 10 in up to four consecutive 26-byte records. Caller supplies four readable records. The load, stride, and bound support the existing descriptive name. |
| `func_020deedc` | 48 B | When offset 0xc8 is zero, calls `Unk0bc1a8_Unk_0bc9b4(24, 0)`; always calls `Unk044394_Unk_044534(9)`. |

No hard-list entries for M1-T687. Existing routines belonging to later cards
remain outside this card's implementation scope.

## M1-T688

All eight ARM functions match at 100% against the delinked object. Evidence is
instruction offsets and relocations in `build/delinks/src/game/unit_020de678.o`;
the three newly added bodies also pass direct instruction/relocation comparison.
The five existing bodies were retained, documented, and their helper prototypes
typed. No runtime tests were added: the card does not require them, and exact
instruction comparison verifies the original behavior.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `Unk0de678_Unk_0df4f0` | 48 B | Clears words at global offsets 32/36, calls `Unk095560_Unk_0958a8(0, 0)`, then clears offset 16. No arguments. |
| `Unk0de678_GetPair` | 52 B | At 0x020dedf8, copies low bytes from offsets 32/36 when offset 16 is nonzero, otherwise writes two zeros. Caller supplies two writable bytes. The pair of byte stores supports its existing name. |
| `Unk0de678_Unk_0de870` | 64 B | Returns immediately when global offset 0xc8 is nonzero; otherwise calls the eight observed helpers in order, including selector 30. No arguments. |
| `Unk0de678_Unk_0df064` | 64 B | Calls nine helpers in relocation order, passing selectors 194, 1, 0, 30, and 2 where observed. No arguments. |
| `Unk0de678_Unk_0dec94` | 68 B | Calls the preparation and value-query helpers, then `Unk02d15c_Unk_02d8a8(1, value, argument)`. On nonzero result clears offset 0xcc and returns 1; otherwise returns 0. |
| `func_020df520` | 88 B | Sets global offset 40, forwards the integer argument and selectors 1/0 with `data_02150904` to `func_0209db70`, then invokes selectors 8, (1,1,2,0,3), and 10 in order. |
| `func_020de720` | 100 B | Obtains resource 22/4, then its record pointer and unsigned count. Searches 28-byte records by leading unsigned halfword against the full word argument; returns the first borrowed record or null. |
| `func_020de784` | 100 B | Same resource and key comparison; returns the first zero-based index or -1. Does not retain or modify resource storage. |

The search argument uses a full word because the original compares the loaded
halfword directly with the incoming register without narrowing it. Existing
callers pass narrower keys, but that does not establish a narrower callee contract.
No hard-list entries for M1-T688.

## M1-T689

Seven functions match at 100% against the delinked object. Evidence is the
instructions and relocations in `build/delinks/src/game/unit_020de678.o`.
Existing names are retained; selector meanings remain unknown.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `func_020dec18` | 124 B | Scans the external iterator for selectors 1, 3, or the result of `Unk02d15c_Unk_02d9f8`; returns a boolean. Incoming word is unused. |
| `func_020de7e8` | 136 B | First flag clears 208 bytes of global state; then invokes ten observed providers, with the final selector-2 call controlled by the second flag. Compiler intrinsic clear emits the original inline stores. |
| `func_020ded70` | 136 B | Original forwards signed byte pairs from the resource selected by global byte 24, advances index 28, and loops or clears active state at the end. Left in the delink. |
| `func_020deb68` | 144 B | Scans selectors 1, 3, or the result of `Unk02d15c_Unk_02d9a8`; clears global offset 0xcc on success and returns a boolean. |
| `func_020decd8` | 152 B | Dispatches states 0/1 at offset 0xcc, forwards pending state changes, and invokes the pair updater when active. Returns one only while waiting for completion in state 1. |
| `func_020dee40` | 156 B | Allocates a 12-byte callback work area; null ends early. Clears two words, records current provider values, and forwards selectors 9 and 24. Provider owns the allocation. |
| `func_020de8b0` | 160 B | Unless bypassed, scans selector 40. Initializes state, conditionally starts the display sequence, and returns the search flag. |
| `Unk_LoadPalette_020de678` | 168 B | Six packed color-pair calls followed by six draw calls, with channel increments of 38 and offset increments of 32. Packed four-channel data supports the existing palette name. |

### Hard list

- `func_020ded70`: readable signed-byte array and two-byte record views both
  reproduced behavior, but best objdiff was 98.24%. Remaining differences are
  register allocation for the shared pair index and the increment after the
  forwarding call. Explicit pair pointers and local global-state pointers were
  also tried; neither matched. Body omitted, preserving original delink linkage.
  A human can prepare a scratch with `tools/decompme.py scratch func_020ded70`.

## Not done in M1-T690
- `func_020df374`
- `func_020df420`
- `func_020deaa0`
- `func_020df234`
- `func_020de960`
- `func_020def0c`
- `func_020df0cc`
