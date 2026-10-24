# game/unit_020cce38

M1-T407: all eight requested ARM functions match at 100% objdiff with
mwccarm 2.0/sp1p5. Evidence below is from the original delinked object's
instructions and relocations. Names remain unchanged; unknown fields and
callback slots use offset-based names rather than inferred game semantics.
All work and descriptor pointers borrow caller-owned, writable storage.

| Function | Contract and original evidence |
| --- | --- |
| `Unk0cce38_Enter` | Calls `func_020cb3dc` and `Unk095560_Unk_095a2c`; a nonzero `func_020de8b0(0)` result returns early. Otherwise calls `Unk0cb32c_Unk_0cb32c` and `Unk0bc1a8_Unk_0bc928(17, 65535, 0)`. The call relocations and conditional return at 020cce50 establish this sequence. |
| `Unk0cce38_Nop_0cce70` | Takes no consumed arguments and has no effects: its sole instruction is `bx lr`. |
| `Unk0cce38_Unk_0cce74` | When `Unk0de678_Get_data_021508d4()` is zero, calls `Unk0bc1a8_Unk_0bc9b4(17, 0)` and `Unk0cb32c_Unk_0cb344`. Both paths then call `Unk0de678_Unk_0de870` and `Unk095560_Unk_0956c8`; branch at 020cce80 skips only the conditional pair. |
| `func_020ccea0` | Fills a descriptor of at least 0x24 bytes: stores work size 0xc4 at +0, zero at +4, and six function pointers at +0xc through +0x20. Preserves +8. ABS32 relocations identify, in order, `func_020ccfe0`, `func_020cd200`, `Unk0cd470_Unk_0cd470`, `func_020cd490`, `Unk0cce38_Unk_0ccfac`, and `func_020cd49c`. Callback signatures reflect the work argument and the event callback's additional word-array argument; no callbacks are invoked here. |
| `Unk0cce38_Unk_0ccfac` | Passes the word at work +0x7c to `func_02122e1c`, clears that word, calls `ImageBg_Unk_0e5530` and `Unk0de678_Unk_0dea60`, then clears the singleton at `data_02176bc8`. LDR/STR offsets and call relocations at 020ccfac establish the handle teardown sequence. |
| `Unk0cce38_Unk_0cd430` | Passes the work +0x7c word to `Unk122e1c_Unk_122ff0`, stores the unrestricted second word argument at +0xb8, then writes byte values 1 at +2 and 3 at +0. The three stores distinguish word and byte fields; no game-state meanings are assumed. |
| `Unk0cce38_Unk_0cd45c` | Tail-forwards the address of work +0x7c to `Unk0cb32c_Unk_0cb754`. The original adds 0x7c without dereferencing it and uses an ABS32 relocation for the tail call. |
| `Unk0cce38_Nop_0cd46c` | Takes no consumed arguments and has no effects: its sole instruction is `bx lr`. |

## Other functions in this translation unit

The existing `Unk0cce38_Unk_0ccefc` work initializer is retained and also
matches at 100%. `func_020ccfe0` and `func_020cd200` belong to M1-T408 and
remain supplied by the delink. The unit remains incomplete in the human-owned
delink configuration.

## Hard list

None for M1-T407.
