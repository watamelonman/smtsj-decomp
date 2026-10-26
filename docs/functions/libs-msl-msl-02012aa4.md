# libs/MSL/msl_02012aa4.c

Fifteen functions in this delink unit are reconstructed as readable C and match
the delinked original at 100% with the configured mwccarm 2.0/sp1p5. The
remaining byte range is an unreachable qsort epilogue and is documented in the
hard list.

The public-source check used the standard MSL/ANSI C string and formatted-I/O
contracts: the formatting wrappers all target `func_02013b94`, the scanning
wrapper targets `func_0201509c`, and the string helpers have the byte-at-a-time
semantics of strncpy, strncat, strchr, strrchr, strstr, strlen, strcat and
strncmp. Linker symbol names remain unchanged because the symbol configuration
is human-owned and relocations refer to the `func_` names.

The module adds no new dependency and does not change an architectural boundary.
The unit stays linked from its delinked original until a human marks it complete.

## func_02013b50 — 68 bytes

Bounded output callback: appends `length` bytes to the state buffer, clipping to
the remaining capacity, advances the state position and returns 1. The state is
`{buffer, size, position}`; the subsequent `position` reload shows the original
updates the field in place after the copy (the copy could alias the state).
Matches 100%.

## func_02013b94 — 104 bytes

vsnprintf core: builds the `{buffer, size, position}` state on the stack, calls
`func_0201332c` with `func_02013b50` as the write callback, then terminates the
buffer. A result smaller than `size` writes at `result`; an exactly full buffer
writes at `size - 1`; a null buffer is left alone. Returns the formatter's
result, which may exceed the buffer size. Matches 100%.

## func_02013bfc — 24 bytes

vsprintf: forwards the buffer, format and argument list to `func_02013b94` with
size -1. The tail call copies only the size argument, which identifies the
unbounded variant of the formatter. Matches 100%.

## func_02013c14 — 40 bytes

snprintf: passes the caller's size to `func_02013b94` and builds the variadic
argument pointer from the rounded address of `format` plus one word. The
`push {r0-r3}` / register-save prologue is the standard AAPCS/MSL varargs
sequence. Matches 100%.

## func_02013c3c — 44 bytes

sprintf: the same varargs prologue, but the size is forced to -1, so no bound is
applied. Matches 100%.

## func_0201509c — 84 bytes

vsscanf core: rejects a null or empty input with -1, initialises the
`{input, atEnd}` reader state, and calls `func_020142c4` with `func_02015018` as
the character callback. The trailing constant argument selects the scanner
variant used for strings; the engine reads it from the caller's stack. Matches
100%.

## func_020150f0 — 40 bytes

sscanf: builds the same variadic argument pointer and forwards it with the input
and format strings to `func_0201509c`, which rejects null or empty input before
scanning. Matches 100%.

## func_02015118 — 28 bytes

strlen: walks the signed bytes of the string until the NUL terminator and returns
the count excluding it. The loop starts at -1 and increments before each test, so
an empty string returns zero. Matches 100%.

## func_020151fc — 80 bytes

strncpy: copies bytes until the source terminator or the count runs out; if the
terminator was copied, the remaining destination bytes are zero-filled. Returns
the destination pointer. The byte-reload in the loop is the assignment result
being retested. Matches 100%.

## func_0201524c — 48 bytes

strcat: scans to the destination terminator with a post-incrementing cursor,
steps back onto the NUL, then copies the source including its terminator. Returns
the original destination pointer. Signed-byte loads reproduce the original
instruction selection. Matches 100%.

## func_0201527c — 80 bytes

strncat: locates the destination terminator, then copies while the source is
non-empty and the count remains, always writing one final NUL. Returns the
destination pointer. The count is tested before the loop so a zero count leaves
the destination untouched apart from the terminator. Matches 100%.

## func_020153e0 — 52 bytes

strncmp: compares unsigned bytes up to `count`, returning the signed difference
of the first differing pair; equal prefixes stop early at NUL, and a zero count
returns zero. The byte-assignment order preserves the original register
allocation. Matches 100%.

## func_02015414 — 60 bytes

strchr: scans signed bytes with a post-incrementing pointer, returns the byte's
address when it equals the character, and returns the terminator address when the
character is zero. Otherwise a missing character returns null. Matches 100%.

## func_02015450 — 72 bytes

strrchr: keeps the current byte in a register, records the address of each match,
and advances a lookahead pointer by one. At the terminator it returns the last
record (or the terminator address when the character is zero), otherwise null.
Matches 100%.

## func_02015498 — 108 bytes

strstr: an empty substring returns the input; otherwise it tries each haystack
position whose first byte matches, comparing the remainder in lockstep and
reporting a match when the substring cursor reaches its terminator. The unsigned
byte loads distinguish it from the signed byte helpers above. Matches 100%.

## func_02013dc4 — 8 bytes (hard)

The delinked symbol is the shared return block of the preceding qsort
(`func_02013c68`): `add sp, sp, #16; pop {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}`.
No instruction in the ARM9 image branches to it, and it has no prologue or body;
the preceding qsort already contains its own complete return paths. A standalone
C function cannot emit a frame restore without a matching frame setup, so this
fragment is left in the delinked asm instead of faking a definition. A human may
want to treat the symbol boundary as a splitter artifact.

## Validation

`python3 tools/match_gate.py` reports 100% for all fifteen C definitions in this
unit, `python3 tools/checksum.py` reports all artifacts byte-identical to the
original, and `python3 tools/anticheat.py` passes. No new unit tests are required
by this card; objdiff compares the generated instructions and relocations against
the delinked object.

## Hard list

- `func_02013dc4` — unreachable out-of-line qsort epilogue; not expressible as
  standalone C. Open a decomp.me scratch only if the symbol split itself is
  revisited.
