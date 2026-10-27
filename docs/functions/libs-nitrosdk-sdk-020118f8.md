# sdk_020118f8

This partial library TU contains MSL-style locale and memory helpers despite
its NitroSDK path. Existing symbol names are retained for callers. All nine
implemented functions match the original ARM instructions (100% objdiff).

Public-source lookup first searched NitroSDK memory helpers and pret's
pokeplatinum/pokediamond MSL sources. No usable matching C for those eight helpers was recovered;
their implementations were reconstructed from the original instructions.
The locale prefix remains private and adds no module boundary. Its second
callback has the wctomb signature established by its callers; the neighbouring
TU's generic table view does not express that signature.

| Function | Evidence and contract |
| --- | --- |
| `func_020118f8` | Single-byte wctomb implementation: stores the low byte of the wide input and returns one; null destination returns zero. Paired with the neighbouring single-byte mbtowc and selected through the locale table. |
| `func_0201190c` | Calls the second conversion callback at `data_0213cff4` +8. Passes the borrowed output and wide character through unchanged. |
| `func_02011928` | Wide-string conversion: halfword source reads, calls to the preceding conversion thunk, and byte-copy calls establish the role. Null source/output returns zero. Copies only whole converted characters within the byte limit and returns bytes copied. The original do/while allows a terminator store at the limit, so output must have room for that byte. Four-byte conversion scratch is stack-owned. |
| `func_020119a0` | memcpy-shaped forward byte copy, returning the original destination. `libs/MSL/msl_02012aa4.c` uses it for buffer writes. Explicit signed bytes preserve the original load instruction; stored bit patterns are unchanged. |
| `func_020119c0` | memset-shaped wrapper around `func_02011a40`, preserving the original destination as the return value. Existing CRI callers clear their work storage through it. |
| `func_020119d4` | memchr-shaped unsigned byte search: masks the target to eight bits, advances through at most the requested byte count, returns the first matching borrowed pointer or null. |
| `func_02011a00` | memcmp-shaped unsigned comparison with normalized -1/+1 results. The signature scanner in `libs/CRI/cri_0208d5ac.c` compares four-byte identifiers through this entry. Zero-length inputs are not dereferenced. |
| `func_02011a40` | Fill provider: low-byte replication, alignment prefix, eight-word blocks, trailing words and bytes. Counts are bytes; buffers remain caller-owned. The preceding memset wrapper establishes its contract. |

| `func_02011af0` | Parses one printf conversion into a caller-owned 16-byte descriptor and advances a caller-owned integer argument cursor for `*` width/precision. Flags, decimal digit accumulation, `hh`/`ll` and C99 length modifiers, integer/floating defaults, pointer normalization and invalid conversion marker `0xff` establish its purpose. Returns the byte after the conversion. Signed input bytes and the SDK classification table preserve the original ASCII range checks. |

## Parser source and linking prerequisite

The parser was adapted from the public [MSL `parse_format` implementation in
doldecomp/melee](https://github.com/doldecomp/melee/blob/master/src/MSL/printf.c).
The target additionally supports `j`, `t`, `z`, `F`, `a` and `A`; its length codes
and hexadecimal floating precision (13) follow the original instructions.
Direct instruction comparison matches all 354 instruction words and the width
limit literal; objdiff reports 100% including the classification-table reference.

The original literal points to the SDK ASCII classification table at `0x0212b01c`.
The original object has no relocation for it and the protected symbol config does
not export it. The C declaration uses `data_0212b01c`; a human must export that
data symbol before marking the TU complete. The delinked original remains linked
as required by this card. No protected configuration was changed.

## Validation

Direct compiler/ROM comparisons match every requested function. No new tests
are required by this card; objdiff checks the original instruction sequences.
The TU remains linked from the original object until a human marks it complete.
`python3 tools/match_gate.py` passes at 100% for all nine functions;
`python3 tools/checksum.py` reports every artifact byte-identical.
Anticheat passes, and unittest discovery passes all nine tool tests.

## Hard list

None of the nine implemented functions is deferred. The parser matches at 100%;
the data-symbol export above is a human configuration prerequisite, not a hard
function requiring a decomp.me scratch.
