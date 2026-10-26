# libs/NitroSDK/sdk_020222d8.c

The existing `func_` linker symbols are retained. Public NitroSystem source
identifies the animation blending and G3D SBC renderer by matching command
numbers, callback stages, resource layouts, and matrix operations. Evidence
below also comes from the delinked ARM instructions and relocations.

Public-source reference: [ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem),
[`libraries/g3d/src/anm.c`](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/anm.c)
and [`libraries/g3d/src/sbc.c`](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/sbc.c).
The four M2-T1029 implementations adapt those routines to existing linker names,
borrowed layout views, and geometry-provider declarations. No public API renaming
or new game-layer dependency is introduced.

The shared `data_02156d28` view models only the accessed words: a command at
offset 0, 62 parameter words from offset 4, and the flag word at byte 252. A
flexible tail array covers the words at `0x100 + 0x140 .. 0x260` (absolute
0x240..0x260), which only `func_020222d8` writes.
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
| `func_02022a6c` | Clears the caller's `bits` word, then walks the node chain beginning at the given node (the target has no null check, so the chain must be non-empty). For each `index < count` (byte 0x19) whose 16-bit entry at 0x1a has `(entry & 0x300) == 0x100` and whose callback at 0xc is non-null, it calls `callback(&scratch, node, entry & 0xff)` and ORs the callback-written scratch word into `*bits`. Returns 1 if any callback ran, else 0. The chain and bitset are borrowed. | 100% |
| `func_02022af4` | Loops clearing flag bit 6 at offset 8, reading the opcode byte through the pointer at offset 0, and calling `data_0213d504[opcode & 0x1f](command, opcode & 0xe0)`; stops when flag bit 5 is set. The command and dispatch table are borrowed. | 100% |
| `func_02022cd8` | Walks the same node chain; for each `i < count` whose entry has bit 8 set, sets bit `(i & 31)` of `bits[i >> 5]`. A null chain is a no-op. The bitset belongs to the caller. | 100% |
| `func_02022d40` | Tests object flag bit 4; when set, clears the three 8-byte hint bitsets at 0x3c/0x44/0x4c with `func_020086a0(0, bitset, 8)`, rebuilds each from its non-null node chain at 0x08/0x10/0x18 through `func_02022cd8`, then clears bit 4. Drawing goes through `func_02022b3c`: it reuses the shared render-state pointer at `data_02156f8c` when non-null; otherwise it installs a 392-byte stack scratch block as the shared state for that call and clears the pointer afterwards. The object is borrowed and must outlive the call. | 100% |
| `func_02022e1c` | Calls the optional callback at record offset 0xc with the record itself, then increments the word at offset 0. The record is borrowed. | 100% |
| `func_02022e44` | Calls the optional callback at record offset 0x10 with the record itself, then sets bit 5 of the word at offset 8. The record is borrowed. | 100% |
| `func_02022fe8` | Callback-driven SBC command handler. It only advances the 2-byte command cursor when flag bit 9 is set or flag bit 0 is clear. Otherwise it reads state byte 0x8f only when the callback at 0x18 is non-null. For state 1 it clears flag bit 6, runs the callback, and re-reads both state and flags. Unless the callback set bit 6 or flag bit 8 is set, it emits command `0x14` with the single word formed from the byte after the cursor. If the resulting state is 3 it clears bit 6 and runs the callback again. Always advances the cursor by 2. | 100% |
| `func_0202353c` | Material SBC handler. It reads the material index from byte 1 of the command cursor and dispatches only when flag bit 9 is clear and either flag bit 0 is set, flag bit 3 is clear, or the index differs from the cached material id (byte 0xad). The record is resolved from the dictionary at 0xd8 (`numEntry` at +5, entry offset at +10, entry stride from the entry header), and the handler tail-calls `data_0213d414[record->itemTag](object, option, record, index)`. Always advances the cursor by 2. A valid record is assumed, as in the target. | 100% |
| `func_020235ec` | Shape-send SBC handler. It reads state byte 0x91 only when the callback at 0x20 is non-null. State 1 clears flag bit 6, runs the callback and re-reads state/flags; unless the callback set bit 6 or flag bit 8 is set, it forwards `source->size` bytes at `(u8 *)source + source->offset` to `func_02025248`. State 2 and state 3 each clear bit 6 and run the callback, with the state re-read after state 2. The command block is borrowed; there is no cursor advance. | 100% |
| `func_020236c0` | Shape SBC handler. It dispatches only when flag bit 9 is clear, flag bit 0 is set and flag bit 1 is clear. It reads the shape index from byte 1 of the command cursor, resolves the record from the dictionary at 0xdc (`numEntry` at +1, entry offset at +6), keys the dispatch on the record's `itemTag`, and tail-calls `data_0213d424[tag](object, option, record, index)`. Always advances the cursor by 2. A valid record is assumed. | 100% |
| `func_02024a64` | If packet flags (offset 8) have neither bit 8 nor bit 9 set, copies the payload word at 0xe0 or 0xe4 three times into a local block and submits command `0x1b` with count 3; always increments the cursor word at offset 0. The packet is borrowed. | 100% |
| `func_020251c8` | Waits through `func_02025224` while submission status is nonzero. If the shared buffer is non-null and its first word is nonzero, copies `count * 4` bytes from `buffer + 1` to the GX FIFO at `0x04000400` via `func_020086e4`, then clears the first word. `func_020086e4` is a word copy with its source in r0 and destination in r1. The buffer remains owned by the submission state. | 100% |
| `func_02025224` | Spins while the word at `data_02159c90 + 4` is nonzero; the status is changed asynchronously outside this function. No return value. | 100% |
| `func_0202523c` | Unconditionally stores zero to the first word of a caller-owned buffer; there is no null check in the original. | 100% |
| `func_02025248` | Sends a display list. Blocks smaller than 256 bytes, or when the shared DMA-channel word is -1, go through `func_020252fc(first word, source + 4, size / 4 - 1)`. Larger blocks first flush through `func_020251c8`, set the submission-busy word, and start an asynchronous DMA transfer on the shared channel using `func_02008560` when the shared fast-DMA word is set, otherwise `func_0200835c`; both receive `func_0202523c` and the shared completion word as callback/argument. Source and size are caller-owned. | 100% |
| `func_020253e0` | Flushes the staged command buffer through `func_020251c8`, then writes zero to the matrix-mode registers at 0x04000440, +4 and +0x14. When `position` is non-null it polls `func_02004210` into a 16-word stack scratch until it returns 0, then copies the result out with `func_020017b0`; when `normal` is non-null it polls `func_02004240` directly into that output. Finally it writes 1 to 0x04000448 and 2 to 0x04000440. The caller owns both output matrices. | 100% |
| `func_020252fc` | Sends a GX command plus parameter words. When the shared submission buffer belongs to the caller and has room it appends the command word at `buffer[index+1]`, copies the parameters after it, and bumps the word count; otherwise it flushes the buffer (or waits on the busy word) and writes the command straight to the GX FIFO at 0x04000400. The parameter block is borrowed for the call. | 100% |
| `func_020222d8` | Initialises the shared G3X state block. Writes the command word, parameter defaults, projection/viewport constants and matrix-table fields at the delinked offsets, calls `func_02000f8c(data_02156d74)` and `func_02001784(data_02156d30)`, then fills the remaining register-image words and calls `func_02000ddc(data_02156de4)`. The final words set the three `0x1000` staging sizes in `parameters[58..60]`, the `0x1000` tail word, the zeroed tail words and the `-0x1000` sentinel. | 100% |
| `func_02022b3c` | Clears a caller-owned 392-byte scratch block and fills it from the command block: base/command pointers, dictionary-derived material and shape tables, material id/tag fields, optional binding slot at the command's index, and the four flag bits. It calls the optional command callback with the scratch block, runs `func_02022af4` on it, and clears command flag bit 0. | 100% |
| `func_02022e6c` | Texture SBC handler. Reads the texture index from the command cursor, runs the state-1/2/3 callback protocol at callback slot 0x14 and state byte 0x8e, consults the render object's bitset callback when the index bit is set, and stores the command's low bit into the shared word at +0x184 unless that callback accepted the index. Always advances the cursor by 3. | 100% |
| `func_02024988` | Display-list SBC handler. Runs the state-1/3 callback protocol using callback slot 0x34 and state byte 0x96, decodes a little-endian 32-bit offset and length from cursor bytes 1..8, forwards `command + offset` through `func_02025248`, and advances the cursor by 9. | 100% |
| `func_02024ad4` | Matrix SBC handler. Updates the fog/matrix-stack word at `buf+0x10`, emits the fixed command 16 value 3, runs the state-1/2/3 callback protocol (slot 0x3c, state byte 0x98), sends the texture-scale commands 27/34 from `buf+0x2c/0x2e`, resolves a material record and sends its selected 16-word block, then emits the current normal matrix (9 words) with the shared flag-selected material block. The cursor advances by 3. | 100% |
| `func_02023bc0` | Material SBC handler. Increments the cursor count for options 0x20/0x40/0x60, emits command 20 with the option-selected cursor byte when flag bit 8 is clear, runs the state-1/3 callback protocol (slot 0x28, state byte 0x93), builds the 16-word matrix through `func_02004210`/`func_02000fb4`/`func_020017e4`, records three matrix columns and three `func_02002380` results, and sends the flag-selected material block (or the fallback `data_0213d474` block). Option 0x20/0x60 may emit command 19, then the cursor advances by the option-dependent count. | 100% |
| `func_02023ec8` | Shape SBC handler. Same option/count and callback protocol as 02023bc0 but with callback slot 0x2c, state byte 0x94, shape tables `data_0213d4ec`/`data_0213d4f8`, and an extra normal-matrix sign fix on `data_0213d4c8` selected by `matC[5]/matC[6]`. It emits the same projection/normal matrix commands and flag-selected shape blocks, then advances by the option-dependent count. | 100% |
| `func_0202242c` | Would submit the command at offset 0 with the pointer at offset 4 and count 62, then clear flag bits 0 and 1. Left in the delink; see the hard list. | Left in delink |
| `func_02022680` | `NNSi_G3dAnmBlendJnt` in `anm.c`. Blends a borrowed animation chain into an 88-byte caller-owned joint result. Null or unusable chains return false; a single applicable provider is called directly. Multiple providers use normalised positive 20.12 weights, intersect result flags, accumulate scale/translation/rotation, and rebuild the rotation basis with cross products and normalisation. Original first-provider axes are retained when the blended axes vanish. | 100% |
| `func_020230b4` | `NNSi_G3dFuncSbc_MAT_InternalDefault` in `sbc.c`. Runs material callback stages A/B/C; selects recorded, cached, or temporary 56-byte results; merges resource colors with shared register defaults; decodes optional texture SRT; blends material animation; and submits GX material/texture commands unless disabled or transparent. The caller supplies a valid material index/resource, and callbacks may replace the borrowed result pointer. The eight static color masks mirror the public source and original read-only table at 0x0212b390. | 100% |
| `func_02023760` | `NNSi_G3dFuncSbc_NODEDESC` in `sbc.c`. Resolves recorded or animated joint SRT, decodes compact pivot rotations or full rotation records, calls the selected scaling/matrix providers, and optionally restores/stores matrix-stack slots. Callbacks can skip each stage; the joint-result pointer is cleared after submission. The cursor advances by four bytes plus option-selected stack operands. The static 9-by-4 pivot table mirrors the public source and original at 0x0212b3b0. | 100% |
| `func_0202422c` | `NNSi_G3dFuncSbc_NODEMIX` with envelope caching enabled in `sbc.c`. Reads stack-slot/joint/byte-weight triples, caches clip and normal matrices in 100-byte entries, accumulates weighted matrix components with 64-bit fixed-point products, restores projection state and stores the mixed matrix. Requires a valid model envelope resource and at least two stream entries, as in the SDK source. Advances the cursor by `3 + 3 * count`. | 100% |
| `func_02024e18` | `NNSi_G3dFuncSbc_PRJMAP` in `sbc.c`. Projection texture mapping with callback stages, material effect matrix, GX matrix readback and texture-coordinate packing. Left in the delink; see the hard list. | Left in delink |

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

- `func_02024e18` (944 bytes, best range-preserving candidate 99.78814%):
  adapted the public `NNSi_G3dFuncSbc_PRJMAP`, including callback slots 0x40/0x99,
  matrix-stack slot 30, the shared texture-generation command and projection
  matrix, effect-matrix resource lookup, shared transform selection, hardware
  readback and final coordinate packing. All remaining instruction differences
  in the report were register assignments around texture-coordinate conversion.
  The target preserves the shifted S input in r2 while it reuses r1 for the
  shifted T input; the candidate reuses r1 for S and r0 for T, then uses r2
  for the narrowed S component. Tried direct expressions, signed/unsigned
  intermediate widths, conversion helpers, reordered operands and locals, and
  inline submission wrappers with MWCC 2.0/sp1p5. Narrowing both input locals
  to s16 gave 99.98305%, but changed the shifts from 8/16 to 16/24 and lost
  input range, so that candidate was rejected. No unmatched body is retained
  in C. A human can open an `nds_arm9` scratch with `tools/decompme.py` using
  the public PRJMAP source and the original function; the coordinate packing
  is the remaining permutation target.
