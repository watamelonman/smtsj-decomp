# game/unit_020fa7e8 — M1-T500

All eight functions below match the delinked ARM object at 100% objdiff.
Names remain neutral because the instruction and relocation evidence does not
establish a game-level purpose. No inline assembly or code blobs are used.

| Function | Observed contract and evidence |
| --- | --- |
| `Unk0fa7e8_Unk_0fa7e8` | Requires writable storage through +0x2f. Clears words +0, +0xc, +8, +0x2c, halfword +0x28 and twelve individual bytes +0x10..+0x1b, in original store order. Calls `func_02065604(0)`, `func_02065bc0()`, then `func_020655b4(0)`. Other fields are preserved. |
| `func_020fa84c` | Initializes a callback descriptor: work size 0x30 at +0, zero at +4, and six callback addresses at +0xc..+0x20. Preserves +8. Original absolute relocations identify `func_020faa88`, the four empty callbacks, and `func_020fae7c` in that order. The callback declarations describe address storage only; their invocation signatures are not established here. |
| `Unk0fa7e8_Nop_0faa84` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Nop_0fae70` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Nop_0fae74` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Nop_0fae78` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Unk_0fb0e0` | Requires a valid word at base +0x10 + index*4. Queries that word with `Unk095560_Unk_0957c0`; returns a nonzero result immediately, otherwise queries ID 0x259 and returns its result. Evidence: indexed load, conditional return and literal pool. |
| `Unk0fa7e8_Unk_0fb108` | Gets resource 0x25, entry zero through `func_020445f4`, then forwards that result and the supplied value to `func_0204fed8`. Discards the helper result. Evidence: original call operands and relocations. |

## Hard list

None for M1-T500. Other functions in this translation unit remain outside this
card and continue linking from the delinked object until human completion.

## Validation

The objdiff match gate verifies exact generated code against the original;
no new behavioral tests are required by this card. The full-image checksum
gate checks the existing delink-based link, rather than switching this unit
to complete (the split configuration is human-owned).
