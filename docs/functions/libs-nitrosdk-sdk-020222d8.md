# libs/NitroSDK/sdk_020222d8.c

The existing `func_` symbols are retained because the subsystem identity is not
established. Evidence below comes from the delinked ARM instructions, their
relocations, and the callers already reconstructed in `src/game/`. No module
boundary changes are introduced.

Public-source search: no reconstructed copy of this address range is present in
the workspace, and web search was unavailable (this attempt's query was
cancelled). The SDK classification on the card is therefore not treated as
provenance for names; the neutral `func_` symbols are kept.

The shared `data_02156d28` view models only the accessed words: a command at
offset 0, 62 parameter words from offset 4, and the flag word at byte 252.
`data_02156d74`, `data_02156de4` and `data_02156e28` are borrowed input/output
blocks, and `data_02156e58`/`data_02156e88` are borrowed 12-word matrix buffers.
The node, command and packet views expose only the offsets touched by the
delinked instructions.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_02022468` | `ldmia` copies three vector words into `data_02156e08` only when the input is non-null, then clears mask `0xa4` in the shared flag word. The input remains owned by the caller. | 100% |
| `func_02022498` | Tests shared flag bit 3; when clear, calls `func_0200101c` with the `data_02156d74` input and `data_02156e28` output, then sets the bit. Always returns the borrowed `data_02156e28` block. | 100% |
| `func_020224dc` | Calls `func_020013a8(data_02156de4, data_02156d74, data_02156e58)`, feeds parameters 58..60 and `data_02156e58` into `func_02000fe8`, then calls `func_0200101c(data_02156e58, data_02156e88)`. All blocks remain borrowed by the shared state. | 100% |
| `func_02022534` | Tests flag bit 7; when clear, calls `func_020224dc` to recompute both matrices and sets the bit. Returns the borrowed `data_02156e58` matrix in all cases. | 100% |
| `func_0202256c` | Same cache protocol and shared bit as `func_02022534`; returns the borrowed `data_02156e88` matrix. | 100% |
| `func_020225a4` | Walks the singly linked node chain (`next` at 0x10) and, for `index < count` (byte 0x19), reads the 16-bit entry at 0x1a. When `(entry & 0x300) == 0x100` and the callback at 0xc is non-null, calls it with `(context, node, entry & 0xff)`. Returns 1 if any callback ran, else 0; a null chain returns 0. All nodes are borrowed. | 100% |
| `func_02022610` | With nonzero `additive`, adds `value` to each of three destination words; otherwise adds `(value * src[i]) >> 12`. The caller owns both three-word arrays. | 100% |
| `func_02022af4` | Loops clearing flag bit 6 at offset 8, reading the opcode byte through the pointer at offset 0, and calling `data_0213d504[opcode & 0x1f](command, opcode & 0xe0)`; stops when flag bit 5 is set. The command and dispatch table are borrowed. | 100% |
| `func_02022cd8` | Walks the same node chain; for each `i < count` whose entry has bit 8 set, sets bit `(i & 31)` of `bits[i >> 5]`. A null chain is a no-op. The bitset belongs to the caller. | 100% |
| `func_02022e1c` | Calls the optional callback at record offset 0xc with the record itself, then increments the word at offset 0. The record is borrowed. | 100% |
| `func_02022e44` | Calls the optional callback at record offset 0x10 with the record itself, then sets bit 5 of the word at offset 8. The record is borrowed. | 100% |
| `func_02024a64` | If packet flags (offset 8) have neither bit 8 nor bit 9 set, copies the payload word at 0xe0 or 0xe4 three times into a local block and submits command `0x1b` with count 3; always increments the cursor word at offset 0. The packet is borrowed. | 100% |
| `func_020251c8` | Waits through `func_02025224` while submission status is nonzero. If the shared buffer is non-null and its first word is nonzero, fills `count * 4` bytes at `buffer + 1` with `0x4000400`, then clears the first word. The buffer remains owned by the submission state. | 100% |
| `func_02025224` | Spins while the word at `data_02159c90 + 4` is nonzero; the status is changed asynchronously outside this function. No return value. | 100% |
| `func_0202523c` | Unconditionally stores zero to the first word of a caller-owned buffer; there is no null check in the original. | 100% |
| `func_0202242c` | Would submit the command at offset 0 with the pointer at offset 4 and count 62, then clear flag bits 0 and 1. Left in the delink; see the hard list. | Left in delink |

## Hard list

- `func_0202242c` (60 bytes, best 99.67%): the target loads the address of
  `data_02156d28` into two separate literal-pool slots that both have addend
  zero, loads the command word through the first, adds `4` to the second, and
  only then calls `func_020252fc`. MWCC 2.0/sp1p5 folds the `+4` into a second
  relocation addend (`data_02156d28+0x4`), producing a 56-byte function with no
  `add`; when the source expresses the command and parameter pointer as
  `p[0]`/`p+1`, it strength-reduces them to `ldr r0,[r1],#4`. Declaring a
  separate alias name for the state generates the required duplicate slot and
  explicit `add`, but leaves the second relocation naming the alias instead of
  `data_02156d28`, so objdiff stops at 99.67%; the alias is also only a compile-
  time name and is not a second address when the unit links from C. A local
  `volatile` pointer is the only non-alias shape seen that emits the `add`, but
  it also homes the pointer on the stack, adding stack traffic and changing the
  frame.
  Attempt 2 re-derived the exact target and retried struct member access, array
  indexing, `&member`/`member + 1`/subscript forms, a hoisted command local,
  local pointer variables (plain, `const`, `register`, `volatile`), a union with
  a word view, a raw `extern u32[]` view with two compatible block-scope
  declarations, casts through `u8 *`/`void *`/`u32`, integer-address arithmetic,
  separate base expressions, an alias declaration, and the `opt_propagation`,
  `opt_common_subs`, `opt_strength_reduction`, `opt_lifetimes`,
  `opt_foldconstants`, `opt_movepostops`, and `peephole` pragmas; none produced
  the duplicate slot with the explicit add under the canonical symbol. A human
  can use `tools/decompme.py` (`nds_arm9`) to permute the source.
