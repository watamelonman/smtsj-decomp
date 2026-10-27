# lib_0205f1d8

M2-T364 and M2-T365 reconstruct all fifteen ARM functions in the FBIN resource
translation unit (`0x0205f1d8`–`0x0205f70c`). All fifteen report 100% in objdiff
and the full image still matches its checksum.

## Source and naming evidence

No public NitroSDK, MSL or pret/zeldaret source implements this FBIN container
API; the routines are game-side code layered over the NitroSDK file helpers.
The helpers they call are already reconstructed in this tree
(`libs/NitroSDK/sdk_0205bbac.c`): `func_02051410` opens a file into a 0x48-byte
context, `func_0205144c` seeks and reads, and `func_02051430` closes it. The
`func_0200bc70` call in `func_0205f508` resolves the archive/file identity of a
source path; `func_02095a60` then feeds the resulting 12-byte locator to the
sibling functions.

The container layout is proven by the shipped data file
`extract/files/Data/Effect/Skill2EffectData.bin`: the word at +0 is
`0x4e494246` ("FBIN" in memory order), +4 is the entry count (42), +8 is the
payload offset (0xc0), and +0xc begins the entry size table. The sizes sum to
the remaining file length and each entry starts with a `TBB1` block at the
running sum. The magic checks in `func_0205f2e4`/`func_0205f318`/
`func_0205f340` load that same literal.

Function names stay neutral (`func_0205fXXX`) because `config/arm9/symbols.txt`
is human-owned and no string or caller names these routines. The struct names
are descriptive where the callers establish the meaning:

- `src/ImageBgDual3D.c`, `src/game/unit_0206ea70.c` and
  `src/game/unit_020a163c.c` use `func_0205f2e4` as a loop bound and
  `func_0205f41c` to visit each payload.
- `src/game/unit_020aa118.c` bounds an index with `func_0205f2e4` before
  returning `func_0205f41c`'s pointer.
- `src/game/unit_02044394.c` caches the header block using
  `func_0205f460`'s length and `func_0205f4b0`'s read.
- `src/game/unit_02095560.c` (the delinked caller `func_02095a60`) uses the
  locator with `func_0205f534`/`func_0205f590`/`func_0205f5f0`/
  `func_0205f668`. No direct caller of `func_0205f1d8`/`func_0205f25c` survives
  in the ARM9 image or the overlays (no branch or literal reference), and their
  one-byte cursor reservation is only visible in their own disassembly, so those
  two names and the `Unk05f1d8Stream` field names stay neutral.

## func_0205f1d8 (132 bytes)

Appends `size` bytes from `source` into a caller-owned stream. The stream layout
is proven by this function and by `func_0205f25c`: +0 is the storage pointer,
+4 its byte capacity, +8 the cursor and +0xc a status word. When +0xc is set,
the function clears it and advances the cursor by one reserved byte before the
copy. A null source returns 0. A null storage pointer skips the copy but still
advances the cursor by `size` and returns 1; a block past the capacity returns 0
without copying.

## func_0205f25c (136 bytes)

Reads `size` bytes from the same stream into `destination`, with the same
status-word, cursor and capacity rules as `func_0205f1d8`. A null destination
returns 0, a null storage pointer skips the copy and still advances the cursor,
and a block past the capacity returns 0.

## func_0205f3b0 (108 bytes)

Returns the byte offset of entry `index` inside the payload of a fully loaded
resource: the header's data offset plus the sizes of all preceding entries.
Returns 0 for an invalid resource or an out-of-range index. `func_0205f41c`
adds the result to the resource base, while `func_0205f5f0` and
`func_0205f668` use it to seek on disk.

## func_0205f2e4 (52 bytes)

Returns the entry count of an FBIN resource, or 0 when the pointer is null or
its magic word is not `FBIN`. Callers use the result as the upper bound for
indexed payload lookups.

## func_0205f318 (40 bytes)

Returns the payload offset at header +8, or 0 for a null/non-FBIN resource.
`func_0205f460` reads only the 12-byte header from disk and reports this field,
which `unit_02044394` then uses as the header-block length to cache.

## func_0205f340 (52 bytes)

Returns the address of the per-entry size table at header +0xc, or null for a
null/non-FBIN resource. `func_0205f3b0` walks this table to compute an entry
offset.

## func_0205f374 (60 bytes)

Returns `sizes[index]` for an in-range index, or 0 when the resource is invalid
or the unsigned index is not below the entry count. `func_0205f668` uses the
size to allocate and read one payload.

## func_0205f41c (68 bytes)

Returns a pointer to entry `index`'s payload in a fully loaded resource:
`resource + payloadOffset + sum(sizes[0..index-1])`. It validates only the
resource, not the index, matching the original; callers such as
`ImageBgDual3D` iterate below the count from `func_0205f2e4`.

## func_0205f460 (80 bytes)

Opens `name`, reads 12 bytes from offset 0 into a stack header, closes the file,
and returns the header's payload offset (0 when the open fails). The caller in
`unit_02044394` uses the result as the size of the cached header block, so only
the header and size table have to be read at this stage.

## func_0205f4b0 (88 bytes)

Opens `name`, reads `size` bytes from offset 0 into `buffer`, closes the file,
and returns 1; a failed open returns 0. The caller in `unit_02044394` passes the
length obtained from `func_0205f460`.

## func_0205f508 (44 bytes)

Initializes a 12-byte file locator from `source`: clears the offset at +8 and
calls `func_0200bc70` to resolve the archive/file identity in words +0/+4,
returning that call's success flag (0 for a null locator or source). Evidence:
`func_02095a60` passes the locator to `func_0205f534`/`func_0205f590`/
`func_0205f668`, which use +0/+4 to open the context and +8 as the read offset.

## func_0205f534 (92 bytes)

Opens the file named by `locator`, reads only the 12-byte FBIN header from the
locator's offset and returns its data offset (the header plus size-table
length), or 0 when the file cannot be opened. `func_02095a60` passes the result
to `func_0205f590` as the size of the block to load.

## func_0205f590 (96 bytes)

Reads `size` bytes from the locator's offset into `buffer` and returns 1; a
failed open returns 0. `func_02095a60` loads the header block that
`func_0205f534` sized.

## func_0205f5f0 (120 bytes)

Reads the first four bytes of entry `index` at the locator's offset plus
`func_0205f3b0`'s entry offset and returns the word shifted right by 8, or 0
when the file cannot be opened. The caller in `unit_02095a60` discards the
result, so the shifted field has no independently proven meaning and the
function keeps a neutral name.

## func_0205f668 (164 bytes)

Loads entry `index` into a buffer allocated with `func_0205f374`'s entry size,
passes it to `func_0205148c` together with `argument` (the caller's output
allocation, which `func_0205148c` dispatches on the block's format byte), frees
the temporary buffer and returns 1; a failed open returns 0. `func_02095a60`
uses it to materialise the selected entry.

## Validation

`python3 tools/match_gate.py` reports 100% for all fifteen functions,
`python3 tools/checksum.py` reports every module byte-identical to the original,
the unit suite passes, and `tools/anticheat.py` reports no inline asm or byte
blobs. No behavioural tests are required by this card.

## Hard list

None.
