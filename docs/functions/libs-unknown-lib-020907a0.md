# libs/unknown/lib_020907a0

All eight functions match at 100% with the configured mwccarm 2.0/sp1p5.
Existing `func_` linker names are retained because the symbol configuration is
human-owned. No public NitroSDK/MSL source was located for these routines; the
implementation was reconstructed from the original ARM instructions and the
delink relocations. The TU remains linked from its delinked original pending
human completion.

## Source and layout evidence

The routines operate on one zero-initialized state block, `data_02175d68`
(`kind:bss`), which holds two borrowed arenas and four cached resource pointers:

| Offset | Meaning |
| --- | --- |
| 0x00 | cached 0x300-byte slice (arena 1) |
| 0x04 | cached 0x2100-byte slice (arena 1) |
| 0x08 | cached 0x659c-byte slice (arena 2) |
| 0x0c | remaining capacity of arena 1 |
| 0x10 | next free address in arena 1 |
| 0x14 | remaining capacity of arena 2 |
| 0x18 | next free address in arena 2 |
| 0x20 | cached 0x180-byte slice (arena 1) |

The two arenas are reset by the two setters. Each cache getter follows the same
original flow: return the cached pointer if non-null; otherwise, if the arena
has enough capacity, record the next pointer, copy the resource, advance the
arena pointers and return the copy; else return the immutable resource itself.
Copies go through `func_02008768` (`kind:function(arm,size=0x58)` at
0x02008768), whose relocation is present at each call site in
`config/arm9/relocs.txt`.

The getter literals at 0x0213b9f8 and 0x0213b878 carry load relocations and are
declared as symbols. The literals at 0x02134d90 and 0x02132c90 have no recorded
relocation, but the matching objects still resolve them through the split's
address map; the C references them by neutral `data_` names because the
configuration is human-owned.

## func_020907ac — 8 bytes

Returns the constant 9600 (`0x2580`). No inputs or side effects are observed.
Matches 100%.

## func_020907a0 — 12 bytes

Returns the constant 26012 (`0x659c`). No inputs or side effects are observed.
Matches 100%.

## func_020907b4 — 32 bytes

Resets arena 2 from caller-owned storage: stores the buffer at 0x18, stores the
word-rounded-down size (`size & ~3`) at 0x14, and clears the 0x659c-byte cache at
0x08. The caller keeps the buffer alive. Matches 100%.

## func_020907d4 — 40 bytes

Resets arena 1 from caller-owned storage: stores the buffer at 0x10, stores the
word-rounded-down size (`size & ~3`) at 0x0c, and clears the caches at 0x00,
0x04 and 0x20. The caller keeps the buffer alive. Matches 100%.

## func_02090878 — 112 bytes

Returns the cached 0x2100-byte resource from arena 1, copying it into the arena
on first use when at least 8448 bytes remain; otherwise returns the immutable
original at 0x02132c90. Matches 100%.

## func_020908e8 — 112 bytes

Returns the cached 0x300-byte resource from arena 1, copying it into the arena
on first use when at least 768 bytes remain; otherwise returns the immutable
original at 0x0213b9f8. Matches 100%.

## func_02090958 — 112 bytes

Returns the cached 0x180-byte resource from arena 1, copying it into the arena
on first use when at least 384 bytes remain; otherwise returns the immutable
original at 0x0213b878. Matches 100%.

## func_020907fc — 124 bytes

Returns the cached 0x659c-byte resource from arena 2, copying it into the arena
on first use when at least 26012 bytes remain; otherwise returns the immutable
original at 0x02134d90. Matches 100%.

## Validation

`python3 tools/match_gate.py` reported all eight functions at 100%.
`python3 tools/checksum.py` reported all artifacts byte-identical to the
original image. `python3 tools/anticheat.py` passed, and the unittest suite
passed. No inline asm, asm includes or byte blobs were added.

## Hard list

None.
