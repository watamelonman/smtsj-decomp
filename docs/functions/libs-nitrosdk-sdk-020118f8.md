# sdk_020118f8

This partial library TU contains MSL-style locale and memory helpers despite
its NitroSDK path. Existing symbol names are retained for callers. All eight
card functions match the original ARM instructions (100% objdiff).

Public-source lookup first searched NitroSDK memory helpers and pret's
pokeplatinum/pokediamond MSL sources. No usable matching C was recovered;
implementations below were reconstructed from the original instructions.
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

## Validation

Direct compiler/ROM comparisons match every requested function. No new tests
are required by this card; objdiff checks the original instruction sequences.
The remainder of this delink TU remains supplied by the original object.

## Hard list

None of the eight requested functions is deferred.
