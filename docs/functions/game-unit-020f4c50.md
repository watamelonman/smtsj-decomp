# game/unit_020f4c50

All eight M1-T384 functions match at 100% with mwccarm 2.0/sp1p5,
using the project compiler flags. Evidence below refers to the delinked ARM
instructions at the named addresses; no higher-level gameplay meaning is assumed.

| Function | Observed behavior and contract |
| --- | --- |
| `func_020f4c50` | Writes a descriptor: work size 20, word 04 = 4, callback addresses at 0c/10/14/1c/20, and zero at 18. Word 08 remains untouched. Caller supplies writable descriptor storage. |
| `Unk0f4c50_Unk_0f4ca8` | Clears 20 bytes through `func_02008848`, stores the work pointer in `data_02176e04`, then calls the initializer. Caller retains ownership of the work area. |
| `Unk0f4c50_Unk_0f4cd4` | Sets work words 00/04/08/0c to 35/0/9/1. Word 10 is untouched. |
| `Unk0f4c50_Nop_0f4cf8` | Empty descriptor callback; original consists solely of a return. |
| `func_020f4cfc` | Switches on unsigned work word 0c. Case 6 calls `func_020f7de4`, case 7 calls `Unk0bc1a8_Unk_0bc9b4`; both receive word 00 and zero. Cases 0–5, 8–10 and out-of-range values return without action. |
| `Unk0f4c50_Nop_0f4d5c` | Empty descriptor callback; original consists solely of a return. |
| `Unk0f4c50_Nop_0f4d60` | Empty descriptor callback; original consists solely of a return. |
| `Unk0f4c50_Unk_0f51b0` | Nonzero mode converts work word 10 through `func_020ea630` and forwards the result with -1 to `Unk0d1c98_Unk_0d1d94`. Zero mode calls `func_020d1e94(1)`. |
| `func_020f4d64` | (M1-T385) Descriptor slot-20 message handler. Always calls `Unk0e8228_Unk_0e8c80` and `func_02044ec4`, then switches on the message type word: 1 calls `Unk0bc1a8_Unk_0bc504(work, 0)`; 2 sets state word 0c to 1 (payload +0c = 0) or to 2 with word 04 = payload +10 and `Unk0f4c50_Unk_0f51b0(work, 1)` (payload +0c = 1); 3 dispatches sub-kind payload +04: 14 and 13 match payload ids against `Unk0e8228_GetArr58` entries, then call `func_020f7e48`/`func_020f7d14` depending on `Unk0e8228_Unk_0e8dd0`/`0e8dfc`; 4 stores payload +20 in word 10 (payload +1c = 1) or, for +1c = 0, advances state word 0c to 6 (values 2/6/8) or 7 / calls `Unk0bc1a8_Unk_0bc9b4` (value 3). Payload words are read only when their flag bit (byte 0) is set. |

The local structures describe observed word offsets, not recovered game types.
Callback signatures describe the inputs consumed here; empty callbacks consume none.
The slot at 20 references `func_020f4d64`, matched in M1-T385. No module boundary changed.

## M1-T385 matching notes

- The ROM reads payload words through two inline levels for +0c/+14/+1c/+20 (null check
  twice, copy through a stack slot). Only an `int` local passed as `u32 *` kept that slot;
  a `u32` local or a one-element array was kept in a register (about 64 bytes shorter).
- Case bodies are laid out in source order 3, 2, 1, 4. Sub-kinds 13/14 are a `switch` with
  case 14 first, which gives the ROM's `cmp #13; beq; cmp #14; bne` chain.
- The type-4 path passes the switch value straight to `func_020f7e48` as its third argument
  (r2 is never reloaded), so that call takes `value`.

## Hard list

None for M1-T384 or M1-T385.
