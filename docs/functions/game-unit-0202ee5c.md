# game/unit_0202ee5c

Evidence below is the delinked ARM instruction stream. Six functions match at
100% with the configured compiler; the TU remains linked from the delink.
Names describe only observed offsets and operations, without assigning gameplay meaning.

- `Unk02ee5c_SetRecordFlag0b` (`0x0202ee5c`, 100%): accepts an unsigned
  record id and integer value. Work accessor result + `0x16fc` contains
  36-byte records indexed by `id - 1`; byte `0x0b` bit 0 receives the normalized
  boolean while other bits are preserved. Returns 1 on update, 0 for ids above
  491. Callers must supply ids 1..491; zero is not rejected by the original.
- `Unk02ee5c_GetRecordFlagB` (`0x0202eec0`, 100%): reads that same record bit
  as 0 or 1, returning 0 for ids above 491. The same caller id contract applies.
- `Unk02ee5c_GetTierFromField70` (`0x0202ef0c`, 100%): reads work byte `0x70`;
  returns 5 for 160..255, 4 for 0..95, and 1 otherwise. The comparisons and
  returned constants support the existing tier name, without identifying its purpose.
- `Unk02ee5c_AddClamped70` (`0x0202ef34`, 100%): accepts an integer delta;
  returns without updating if any predicate for `0x404`, `0x405`, or `0x406`
  is nonzero. Otherwise adds to work byte `0x70`, narrows the sum to signed
  16 bits, clamps to 0..255, and stores the byte. Narrowing precedes clamping.
- `Unk02ee5c_Unk_02efa4` (`0x0202efa4`, original object): assembles an 18-halfword
  output at work + `0x24` from lists at `0x5a` and `0x48`. Each source is
  copied until zero or eight entries; separator 1 overwrites the first
  terminator, and remaining output slots through index 17 are zeroed.
  No supported gameplay interpretation was found; retain the neutral symbol.
- `Unk02ee5c_Unk_02f044` (`0x0202f044`, 100%): returns a borrowed pointer to
  the six-byte work region at accessor result + `0x368`. Ownership stays with
  the work area; no supported gameplay interpretation is assigned.
- `Unk02ee5c_Unk_02f054` (`0x0202f054`, 100%): calls that accessor, passes its
  result with arguments 0 and 6 to `func_02008848`, then sets byte 1 to 100.
  The zero-fill initialization description is supported by this call pattern;
  the region's gameplay role remains unknown.

## Hard list

- `Unk02ee5c_Unk_02efa4`: attempted counted loops, do/while loops, separate source
  counters, struct array fields, raw halfword indexing, and explicit temporaries.
  Best result was 94.75%: the same 160-byte instruction sequence, but the
  output index and temporary registers differed (C used r1/r2/r3/ip where
  the target used ip/r1/r2/r3). No nonmatching definition is retained. It
  continues linking from the delinked object; no INCLUDE_ASM is used by this
  DS pipeline. A human can create a scratch with `tools/decompme.py`.
- `Unk02ee5c_Unk_02efa4`: hand-matched
