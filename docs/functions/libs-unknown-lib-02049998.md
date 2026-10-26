# libs/unknown/lib_02049998

All eight functions retain the symbol names in the human-owned symbol configuration.
Behavior below is supported by their ARM loads, stores, masks and calls, rather than
an inferred SDK API name. Parameters use partial local layouts; opaque prefixes are
not claims about the rest of the caller's object.

## Source search

Searched public NitroSDK/NitroSystem-related results and inspected
[ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem), including its packed
fields and 0xfffe uses. No corresponding implementation was identified. The packed
status and paired records here do not supply sufficient evidence for SDK names.
The C is reconstructed from the original instructions. `func_02008904` was also
inspected: it reads its first pointer and writes its second pointer.

## func_02049998 — 192 bytes

Takes `Unk049998Status *`, clears nonzero two-bit fields at bits 2 and 4,
and decrements nonzero fields at bits 6, 8 and 10 of the halfword at +4.
Returns zero. Other bits and the preceding bytes are preserved. Addition of
0xffff followed by halfword conversion expresses the original unsigned 16-bit
wrapping decrement before truncation to each field. Objdiff: 100%.

## func_02049a58 — 44 bytes

Takes `Unk049998Counter *`. If its signed halfword at +8 is nonnegative
and its leading handle exists, increments the halfword. Always returns zero;
conversion back to the halfword preserves the original machine wrap. Objdiff: 100%.

## func_02049a84 — 20 bytes

Takes a borrowed counter and handle. Returns one when the counter's leading
pointer equals the supplied handle, otherwise zero. Objdiff: 100%.

## func_02049a98 — 40 bytes

Takes `Unk049998Work *`. Copies 28 bytes from +0x248 to +0x264 via
`func_02008904`, then clears bit zero in the **source** record at +0x260.
The destination retains the copied flag. Objdiff: 100%.

## func_02049ac0 — 44 bytes

Takes a work pointer and readable source of at least 24 bytes. Sets bit zero
at +0x260 before copying the supplied 24 bytes to +0x248. The flag word is
outside the copied range. Objdiff: 100%.

## func_02049aec — 56 bytes

Takes a work pointer, integer value and boolean-like integer. Stores the low
eight value bits into bits 2..9 at +0x260 and sets bit one according to whether
the last argument is nonzero. Preserves unrelated bits. Objdiff: 100%.

## func_02049b24 — 88 bytes

Takes a borrowed work pointer. Returns one only when bits zero and one at
+0x27c are set, the low halfword at +0x268 is 0xfffe, and bits 16..23 of
that word are nonzero. Returns zero otherwise. Objdiff: 100%.

## func_02049b7c — 48 bytes

Takes a borrowed work pointer and bit index (0..7 for the stored byte).
Returns one when bit zero at +0x27c is set and the indexed bit of its packed
bits 2..9 is set. Returns zero otherwise. Objdiff: 100%.

## Hard list

None.
