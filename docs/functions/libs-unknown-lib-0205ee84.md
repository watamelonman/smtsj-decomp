# lib_0205ee84

M2-T278 reconstructs eight ARM functions of the bit-stream translation unit at
0205ee84–0205f1d8. All eight report 100% in objdiff and the full image still
matches its checksum.

## Source and naming evidence

The required known-source search found no public NitroSDK, MSL or NitroSystem
implementation of this bit-stream API. The routines are plain C over three
providers that are already identified elsewhere in the tree: `func_02052fe0`
allocates, `func_02053000` releases (see `libs/NitroSDK/sdk_0205c1c8.c`), and
`func_02008848`/`func_02008904` are the MSL `memset`/`memcpy` pair whose argument
order is established by the same reconstructed TU. Existing neutral linker names
are retained because `config/arm9/symbols.txt` is human-owned.

The record layout below comes from the delinked object's loads and stores:
+0 is the byte buffer, +4 the byte capacity, +8 the current byte and +0xc the
current bit (0..7). The two single-bit neighbours `func_0205f070` and
`func_0205f0f8` (a separate card) update +8/+0xc and establish those offsets.
Game callers in `src/game/unit_02111400.c` use the stream to pack and unpack the
24-byte records of the exchange format, which fixes the meaning of the copy
directions and of the bit order.

## func_0205f038 (12 bytes)

Tail-dispatches to the provider deallocator with the stream pointer. The
allocation is the 16-byte header returned by `func_0205efc8`, so the whole block
is released at once. Called after encoding and after successful decoding in
`unit_02111400`.

## func_0205f05c (20 bytes)

Copies `+4` bytes from the buffer at `+0` into caller-owned storage via
`func_02008904(buffer, destination, capacity)`. `func_02111ac4` uses it to
publish the finished 24-byte encoded record.

## func_0205f044 (24 bytes)

The reverse direction: copies caller storage into the stream buffer via
`func_02008904(source, buffer, capacity)`. `func_02111c54` uses it to install the
received 24-byte record before reading bits.

## func_0205efa8 (32 bytes)

Returns the provider word at `data_0216b428 + 0xc` when `func_0205ecd8()` is
nonzero; otherwise returns the literal 3, which callers use as "not available".
The provider predicate itself loads word +0 of the same singleton.

## func_0205efc8 (60 bytes)

Allocates `bytes + 16` bytes, clears the whole block, then initializes the header
with `buffer = bytes ? block + 16 : 0` and `capacity = bytes`. A zero-byte request
still returns a usable header with a null buffer. The allocation is written off as
a single block by `func_0205f038`.

## func_0205f004 (52 bytes)

Allocates and clears a 16-byte header only, then stores the caller's buffer and
capacity. Unlike `func_0205efc8` the byte storage is borrowed, so the caller keeps
ownership of the payload while the header is still released with `func_0205f038`.

## func_0205f168 (56 bytes)

Writes the low `bits` bits of `value`, least significant bit first, by calling the
neighbouring single-bit writer `func_0205f070` once per bit and shifting `value`
right. A zero bit count returns immediately.

## func_0205f1a0 (56 bytes)

Reads `bits` bits least significant bit first through the neighbouring single-bit
reader `func_0205f0f8`, accumulating each bit at its position in the result. A
zero bit count returns zero.

## Hard list

None.
