# sdk_02051378

Status of the eight functions in this card. The translation unit is still
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

## Validation

All eight functions match the delinked originals at 100% in objdiff.
`python3 tools/match_gate.py`, `python3 tools/anticheat.py`,
`python3 -m unittest discover -s tests -t . -q` and `python3 tools/checksum.py`
pass. The card requires no new runtime tests; these wrappers depend on existing
providers, and object comparison checks exact calls, offsets and control flow.

## Hard list

None.
