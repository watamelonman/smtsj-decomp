# libs/NitroSDK/sdk_0205bbac

All six ARM functions match at 100% using the configured compiler. The unit
remains linked from the delink pending human completion marking.

## Evidence and source search

No matching public NitroSDK source was identified for this range; the original
ARM instructions and relocations in the delink are the implementation evidence.
The names stay neutral because no string, caller or data reference establishes
the library identities. Cross-unit evidence comes from the existing callers:
`src/game/unit_0206ea70.c` declares `func_0205bccc(request, mode, source, count,
destination, transfer)` as void and passes a span of 512-byte slots;
`libs/NitroSDK/sdk_02056090.c` (still delinked) calls `func_0205bcf8` and
`func_0205be68` with a 0x2e20-byte object and format/width/height triples. The
format mapping is visible in `func_020563dc` (3 -> width*height/2, 4 ->
width*height, 7 -> width*height*2), and `func_0205618c` supplies the byte
alignment stored in the header.

Layouts are private borrowed views. The command object is one 0x2e20-byte
allocation: 1024 eight-byte entries followed by a header at +0x2000 (count,
byte offset, begin, end, copy callback, size callback, alignment). The blocking
context used by `func_0205bbac` occupies 0x48 bytes, proven by the 108-byte
stack frame shared with the 36-byte queue record. The queue record reuses the
existing nine-word layout submitted to `func_0205b234`.

## Functions

- `func_0205bbac` (288 bytes): builds 32- or 512-byte units from `blockSize`
  and dispatches either a blocking file-backed upload or a queued transfer.
  The blocking path opens the context, allocates and fills a temporary buffer,
  waits for VCOUNT 191..213, flushes the cache, starts the DMA helper, and
  releases the buffer. The queued path zeroes the nine-word record and stores
  source/destination/size at words 3..5 before calling `func_0205b234`. The
  request receives the destination pointer and unit count; returns 1, or 0 when
  the context cannot be opened.
- `func_0205bccc` (44 bytes): void wrapper that forwards the transfer flag and
  requests a 512-byte block transfer; the only caller uses it for a dirty span
  of 512-byte slots.
- `func_0205bcf8` (84 bytes): clears the whole 0x2e20-byte object, stores the
  copy/size callbacks and alignment, seeds the byte window with begin and
  begin+length, and resets the byte offset to begin.
- `func_0205bd4c` (88 bytes): asks the size callback for the byte count, then
  returns the next command index when fewer than 1024 entries exist and the
  transfer fits before the window end. Returns -1 otherwise; the full-object
  path reports through `func_02007e94` (expected not to return).
- `func_0205bda4` (196 bytes): packs width (bits 0..10), height (11..21) and
  format (22..25) into the entry's flags word. When appending at the current
  count it also records the byte offset, advances the offset with the optional
  alignment, and increments the count. Returns the entry pointer.
- `func_0205be68` (176 bytes): reserves an entry, clears its ready bit, flushes
  the source range with `func_02006c94`, copies it through the header callback
  and sets the ready bit. Returns the entry index, or 0 when no entry/window is
  available.

## Validation

Objdiff reports 100% for all six functions. The full build reproduces the
original image (`checksum` is byte-identical), the unit suite passes, and
`tools/anticheat.py` reports no inline asm or byte blobs. No new behavioral
tests are required by this card.

## Hard list

None.
