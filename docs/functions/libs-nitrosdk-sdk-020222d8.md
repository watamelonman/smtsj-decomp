# libs/NitroSDK/sdk_020222d8.c

The existing `func_` symbols are retained because the subsystem identity is not
established. Evidence below comes from the delinked ARM instructions, their
relocations, and the callers already reconstructed in `src/game/`. No module
boundary changes are introduced.

Public-source search: no reconstructed copy of this address range was present
in the workspace, and web search was unavailable during this attempt. The SDK
classification on the card is therefore not treated as provenance for names.

The shared `data_02156d28` view models only the accessed words: a command at
offset 0, 62 parameter words from offset 4, and the flag word at byte 252.
`data_02156e58` and `data_02156e88` are borrowed 12-word matrix buffers.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_02022468` | `ldmia` copies three vector words into `data_02156e08` only when the input is non-null, then clears mask `0xa4` in the shared flag word. The input remains owned by the caller. | 100% |
| `func_02022534` | Tests flag bit 7; when clear, calls `func_020224dc` to recompute both matrices and sets the bit. Returns the borrowed `data_02156e58` matrix in all cases. | 100% |
| `func_0202256c` | Same cache protocol and shared bit as `func_02022534`; returns the borrowed `data_02156e88` matrix. | 100% |
| `func_02022e1c` | Calls the optional callback at record offset 0xc with the record itself, then increments the word at offset 0. The record is borrowed. | 100% |
| `func_02022e44` | Calls the optional callback at record offset 0x10 with the record itself, then sets bit 5 of the word at offset 8. The record is borrowed. | 100% |
| `func_02025224` | Spins while the word at `data_02159c90 + 4` is nonzero; the status is changed asynchronously outside this function. No return value. | 100% |
| `func_0202523c` | Unconditionally stores zero to the first word of a caller-owned buffer; there is no null check in the original. | 100% |
| `func_0202242c` | Would submit the command at offset 0 with the pointer at offset 4 and count 62, then clear flag bits 0 and 1. Left in the delink; see the hard list. | Left in delink |

## Hard list

- `func_0202242c` (60 bytes, best 99.67%): the target loads the address of
  `data_02156d28` into two separate literal-pool slots that both have addend
  zero, loads the command word through the first, adds `4` to the second, and
  only then calls `func_020252fc`. MWCC 2.0/sp1p5 either folds the `+4` into a
  second relocation addend (`data_02156d28+0x4`), producing a 56-byte function
  with no `add`, or, when the source expresses the command and parameter pointer
  as `p[0]`/`p+1`, strength-reduces them to `ldr r0,[r1],#4`. Declaring a
  separate alias name for the state generates the required duplicate slot and
  explicit `add`, but leaves the second relocation naming the alias instead of
  `data_02156d28`, so objdiff stops at 99.67%; the alias is also only a compile-
  time name and would not resolve when the unit links from C. Tried struct
  member access, array indexing, a hoisted command local, local parameter
  pointers, volatile and integer-cast forms, a union with a word view, separate
  base expressions, an alias declaration, and the `opt_propagation`,
  `opt_common_subs`, `opt_strength_reduction`, `opt_lifetimes`,
  `opt_foldconstants`, `opt_movepostops`, and `peephole` pragmas; none produced
  the duplicate slot with the explicit add under the canonical symbol. A human
  can use `tools/decompme.py` (`nds_arm9`) to permute the source.
