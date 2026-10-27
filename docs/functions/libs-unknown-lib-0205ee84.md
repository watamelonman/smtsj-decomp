# lib_0205ee84

M2-T278 and M2-T279 reconstruct the twelve ARM functions of the bit-stream
translation unit at 0205ee84–0205f1d8. All twelve report 100% in objdiff and
the full image still matches its checksum.

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
current bit (0..7). The single-bit neighbours `func_0205f070` and `func_0205f0f8`
update +8/+0xc and establish those offsets.
Game callers in `src/game/unit_02111400.c` use the stream to pack and unpack the
24-byte records of the exchange format, which fixes the meaning of the copy
directions and of the bit order.

`func_0205ee84`/`func_0205ef20` drive the provider singleton `data_0216b428`
(+4 run flag, +8 start-up phase, +0xc per-slot status), the same state machine
as the adjacent `func_0205ede8` in `libs/NitroSDK/sdk_0205ea18`. Their first
argument is a slot index, not a pointer: `func_02050668` uses it as a byte
offset (`strb r0, [base, index]`) and `func_0205111c` multiplies it by the
20-byte record size (`mov r0,#20; mla r0,index,r0,base`). SaveLoadTask passes
that field from its slot table.

## func_0205ee84 (156 bytes)

Runs the provider start-up state machine one step for a slot. Phase 0 clears the
status word, announces readiness through `func_0205ecd8`/`func_02050df4`, then
sets the run flag and moves to phase 1. Phase 1 stores
`func_0205111c(index)` as the slot status and moves to phase 2 unless that call
already returned 2. Every other phase shuts the provider down through
`func_02050e80` and returns 1. Returns 0 while still starting. The delinked
`func_0205ede8` is the same routine for the neighbouring subsystem.

## func_0205ef20 (136 bytes)

Starts a provider slot when `enabled` is nonzero. It clears the status word,
checks `func_0205ecd8`, registers the slot with `func_02050668(index, 0)`, then
re-checks `func_02050df4`, sets the run flag, records `func_0205105c()`, clears
the run flag again and calls `func_02050e80`. Returns 1 on every path; the two
SaveLoadTask call sites (020e0754/020e0764) ignore the result.

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

## func_0205f070 (136 bytes)

Writes one bit at the cursor. A null buffer drops the bit but still advances the
cursor; a cursor at or past the capacity returns without advancing. Otherwise it
sets or clears bit `bitIndex` of byte `byteIndex`, then increments the bit
cursor and rolls it into the byte cursor at 8. `func_0205f168` writes fields
through this entry point.

## func_0205f0f8 (112 bytes)

Reads one bit at the cursor with the same cursor rules as `func_0205f070`: a
null buffer yields zero but advances, an out-of-range cursor yields zero without
advancing. `func_0205f1a0` assembles fields from these single bits.

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
