# sdk_02051378

Status of the dependency helpers and the eight functions in M2-T417. The translation unit is still
linked from the delink (`complete: false`), so the remaining functions in
`0x02051378..0x020519e8` are supplied by the original object until a human
marks the unit complete.

## Evidence and interpretation

The repository has no vendored public NitroSDK FS source for these helpers, so
the existing neutral `func_` symbols are retained. Their contracts are
established by the delinked instructions and by existing callers:

- `func_0200ba88` clears the 0x48-byte file context; `func_0200bd68` parses a
  path string (`func_0200bab0` compares its bytes with `/` and `\`) and opens
  it; `func_0200bdb0` closes it; `func_0200bf14` seeks with an origin selector;
  `func_0200bf04` reads bytes.
- `libs/unknown/lib_0205f1d8.c` and `libs/NitroSDK/sdk_0205bbac.c` use the
  same open/read/close helpers and pass a 0x48-byte stack context, which fixes
  the context size used here.
- `func_02051844` is the only caller of `func_020517f8`; it reads through the
  buffer at +0x48 and compares its cursor against the +0x24/+0x28 span, fixing
  the work-object offsets. Descriptive names were not invented for these
  addresses.

The file-context and work-object layouts are private to this translation unit.

## Functions

| Symbol | Size | Observed behavior | Match |
| --- | ---: | --- | ---: |
| `func_020513d4` | 60 | Opens `path` in a stack context, closes it on success and returns the open flag (an existence probe). | 100% |
| `func_02051410` | 32 | Initializes a caller-owned context and opens `path` in it. | 100% |
| `func_02051430` | 12 | Tail-call wrapper that closes a context. | 100% |
| `func_0205143c` | 16 | Returns the work object's +0x28 end minus its +0x24 base (total byte span). | 100% |
| `func_0205144c` | 48 | Seeks to `offset` from the start, then reads `size` bytes into `buffer`. | 100% |
| `func_0205147c` | 16 | Tail-call wrapper that reads one 32-bit word (size 4). | 100% |
| `func_020516d0` | 12 | Tail-call wrapper that releases an allocation through `func_02053000`. | 100% |
| `func_020517f8` | 76 | Lazily allocates the +0x48 read buffer and returns its size, or 0 when it already exists. | 100% |

## M2-T417 functions

Public-source search checked the NitroSDK reconstruction project
(https://github.com/nitro-decomp/nitro/) and pret/pokeplatinum references.
No matching application-level file/decompression wrapper was found; these
implementations follow the delinked instructions. The SDK decoder initializers
at 0x02008dfc/0x02008e44/0x02008dd4 store the destination and header-derived
output length, supporting the decoder interpretation. Neutral symbols remain.

| Symbol | Size | Observed behavior | Match |
| --- | ---: | --- | ---: |
| `func_02051378` | 92 | Enables filesystem IRQs and IME, initializes FS, sizes and installs allocated FS work storage. | 100% |
| `func_0205148c` | 104 | Dispatches synchronous decompression by header format nibble. | 100% |
| `func_020514f4` | 84 | Recognizes header types 0x10, 0x20, 0x30 and 0x80. | 100% |
| `func_02051548` | 100 | Initializes the streaming decoder context for types 0x10, 0x20 and 0x30. | 100% |
| `func_020515ac` | 100 | Feeds an input chunk into the selected decoder and returns its result. | 100% |
| `func_02051610` | 192 | Loads a file and optionally decompresses it into separately allocated output. | Omitted; delink retained |
| `func_020516dc` | 284 | Opens the stream, records its basename and header, and allocates decoder/chunk storage for compressed input. | 100% |
| `func_02051844` | 420 | Advances asynchronous read or incremental decompression state, then closes and releases decoder storage at completion. | 100% |

The extended private work layout spans 120 bytes. The decoder allocation has
544 bytes of state followed by a chunk buffer sized in 1024-byte blocks.
The work retains its output pointer; completion frees only decoder storage.

## Validation

The eight dependency helpers and seven new functions match at 100% in objdiff.
`python3 tools/match_gate.py`, `python3 tools/anticheat.py`,
`python3 -m unittest discover -s tests -t . -q` and `python3 tools/checksum.py`
pass. The card requires no new runtime tests; these wrappers depend on existing
providers, and object comparison checks exact calls, offsets and control flow.

## Hard list

- `func_02051610`: reconstructed whole-file read, optional output allocation,
  decompression and temporary release reached 97.71%. The original forms the
  stack header address and loads through it before calling `func_020514f4`;
  compiled C folds this into a direct stack load (188 rather than 192 bytes).
  Tried scalar, byte-array, word-array and structure header storage, signed
  alias loads, a volatile load and an inline header accessor. None preserved
  the original address formation. The implementation is omitted, retaining
  the original delink; a human can open a decomp.me scratch for this function.
