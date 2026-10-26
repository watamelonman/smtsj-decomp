# game/unit_020fa7e8 — M1-T500 and M1-T501

All eight functions below match the delinked ARM object at 100% objdiff.
Names remain neutral because the instruction and relocation evidence does not
establish a game-level purpose. No inline assembly or code blobs are used.

| Function | Observed contract and evidence |
| --- | --- |
| `Unk0fa7e8_Unk_0fa7e8` | Requires writable storage through +0x2f. Clears words +0, +0xc, +8, +0x2c, halfword +0x28 and twelve individual bytes +0x10..+0x1b, in original store order. Calls `func_02065604(0)`, `func_02065bc0()`, then `func_020655b4(0)`. Other fields are preserved. |
| `func_020fa84c` | Initializes a callback descriptor: work size 0x30 at +0, zero at +4, and six callback addresses at +0xc..+0x20. Preserves +8. Original absolute relocations identify `func_020faa88`, the four empty callbacks, and `func_020fae7c` in that order. M1-T501 establishes the work and event callback argument types. |
| `Unk0fa7e8_Nop_0faa84` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Nop_0fae70` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Nop_0fae74` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Nop_0fae78` | Empty callback; original is a single return instruction. Its address occurs in the descriptor initializer. |
| `Unk0fa7e8_Unk_0fb0e0` | Requires a valid word at base +0x10 + index*4. Queries that word with `Unk095560_Unk_0957c0`; returns a nonzero result immediately, otherwise queries ID 0x259 and returns its result. Evidence: indexed load, conditional return and literal pool. |
| `Unk0fa7e8_Unk_0fb108` | Gets resource 0x25, entry zero through `func_020445f4`, then forwards that result and the supplied value to `func_0204fed8`. Returns the helper result preserved in r0. Evidence: original call operands and relocations. |

## Hard list

None. All seven M1-T501 functions and the eight preceding M1-T500 functions
are implemented. The translation unit continues linking from the delinked
object until human completion.

## Validation

The objdiff match gate verifies exact generated code against the original;
no new behavioral tests are required by this card. The full-image checksum
gate checks the existing delink-based link, rather than switching this unit
to complete (the split configuration is human-owned).

## M1-T501 message and state handlers

The original symbol names are retained: the available instructions establish
message and state behavior, but do not identify a game-level purpose.

| Function | Observed contract and evidence |
| --- | --- |
| `func_020fa8a8` | Sends slot 23 a 68-byte message containing the three arguments, selector 3 and constant 6. Presence bits are 0xe6. Evidence: stack stores and dispatcher relocation. |
| `func_020fa92c` | Sends selector 2 and the argument to slot 23, then returns shared response `data_02176e0c`. Dispatch must finish before the response is read. |
| `func_020fa9a0` | Sends selector 1 and the argument, returning whether the shared response is exactly one. Evidence: post-dispatch comparison. |
| `func_020faa20` | Sends selector zero and the argument to slot 23, marking both optional words present. |
| `func_020fadf4` | Sends slot 22 a message naming destination 23, the supplied ID, phase and result. Presence bits are 0xc5. |
| `func_020faa88` | Advances states 0..4 of a borrowed 0x30-byte work record. Readiness helpers gate transitions; IDs 10..12 deliberately fall through to populate multiple slots. Optional notifications use `func_020fadf4`; completion posts word 3 with the final result. Evidence: original switch targets and helper relocations. |
| `func_020fae7c` | Handles only event tag 4. Requires optional words 6 and 7; selectors 0..2 update notification or shared response, while selector 3 copies optional words into work and resolves its handle. The sender must provide a valid source with the requested count fitting the work values. Evidence: flag tests, indexed copy and original call operands. |

The event message starts at +4; its two flag bytes precede sixteen words.
Only flag bytes and words are initialized, preserving unused alignment bytes.
The callback descriptor now carries typed callback declarations; stored callback
addresses and the module boundary remain unchanged. The resource wrapper at
0x020fb108 returns the resource lookup result retained in r0 by the original.

Validation uses direct generated-instruction comparison, the objdiff gate,
unit tests, anticheat and the checksum gate. This card requires no new tests;
the original object supplies the exact instruction-level acceptance oracle.
