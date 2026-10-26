# src/ImageObj.c

## M1-T922 — verified ARM functions

All eight entries match at 100% in the objdiff report. Evidence comes from
`extract/arm9/arm9.bin`, with addresses and sizes from `config/arm9/symbols.txt`.
Existing symbol names are retained; unknown field meanings are not inferred.

- `ImageObj_Get_data_0217231c` (16 B, 02077218): loads and returns the word at
  `data_0217231c`; the literal load followed by a word load supports the accessor name.
- `ImageObj_Unk_0775d8` (20 B, 020775d8): calls `077620`, `0775a0`, then
  `077640` in order. No parameters are consumed.
- `ImageObj_Unk_07784c` (20 B, 0207784c): forwards the supplied word as the
  second argument to `func_02079238`, with first argument zero.
- `ImageObj_Unk_077880` (20 B, 02077880): forwards the supplied integer plus
  one to `func_02079238`, with first argument one.
- `ImageObj_Unk_0778d4` (20 B, 020778d4): forwards the supplied integer plus
  three to `func_02079238`, with first argument two.
- `ImageObj_Unk_0778e8` (24 B, 020778e8): calls the singleton accessor, then
  reads the word at offset `4 + index * 4`. Requires a live singleton and valid index;
  the original has no null or bounds check.
- `ImageObj_Unk_07916c` (24 B, 0207916c): for a valid work pointer whose word
  at offset 4 equals one, stores `256 - word[0x2c]` at offset 0x1c. Conditional
  LDR/RSB/STR instructions establish the field offsets, but not their meanings.
- `ImageObj_Unk_0772f8` (28 B, 020772f8): passes its incoming work pointer to
  `ImageObj_Release`, then clears `data_0217231c`. The incoming r0 is preserved up
  to the BL, so the C signature explicitly accepts and forwards that pointer.

Hard list for M1-T922: none.

## M1-T923 — verified ARM functions

All eight entries match at 100% in objdiff. Instruction evidence is from
`extract/arm9/arm9.bin`; original neutral symbols are retained.

- `ImageObj_Unk_079028` (28 B, 02079028): calls the singleton accessor and
  compares its word at +0x14 with four, returning a boolean. Requires a live
  singleton. LDR/CMP at 02079030..02079034 establish the comparison.
- `ImageObj_Unk_0773bc` (32 B, 020773bc): if the singleton is nonzero,
  stores one at +0xc0 and +0xc4. Conditional stores at 020773cc..020773d0
  establish the offsets; the flags' meanings remain unknown.
- `ImageObj_Unk_077620` (32 B, 02077620): calls `ImageObj_Unk_077554`
  for indices zero, one, and two. ADD/CMP/BLT at 02077630..02077638
  establish the iteration range. No arguments or singleton check.
- `ImageObj_Unk_07782c` (32 B, 0207782c): forwards its two words as
  arguments two and three to `ImageObj_Unk_0791a8`, with slot zero and
  final flag zero (register moves at 02077830..02077840).
- `ImageObj_Unk_077860` (32 B, 02077860): forwards its first word and
  second integer plus one to slot one, with final flag zero. ADD/MOV
  at 0207786c..02077874 establish the constants.
- `ImageObj_Unk_077894` (32 B, 02077894): forwards its first word and
  second integer plus three to slot two, with final flag zero. ADD/MOV
  at 020778a0..020778a8 establish the constants.
- `ImageObj_Unk_0778b4` (32 B, 020778b4): same slot and increment as
  077894, with final flag one (020778c0..020778c8).
- `ImageObj_Unk_079184` (36 B, 02079184): reads singleton word at
  `4 + index * 4` and passes it to `func_02061424` if nonzero. Requires
  a live singleton and valid index. LDR into r0 at 02079194 and BL at
  020791a0 prove the forwarded handle; the provider now has a typed
  argument rather than relying on an unprototyped call preserving r0.

Hard list for M1-T923: none.

## Other existing implementations
- `ImageObj_Unk_0775ec`: decompiler-derived
- `ImageObj_Unk_0776d4`: decompiler-derived

## Not done in M1-T924
- `ImageObj_Unk_079000`
- `func_02077a9c`
- `ImageObj_Unk_077d68`
- `ImageObj_Release`
- `func_02077e74`
- `ImageObj_ReleaseField68`
- `ImageObj_Unk_077228`: decompiler-derived
- `ImageObj_Unk_077688`: decompiler-derived

## Not done in M1-T925
- `ImageObj_Unk_0775a0`
- `ImageObj_GetOrCreate`
- `ImageObj_Unk_077d98`
- `ImageObj_Unk_077640`
- `ImageObj_Unk_077708`
- `ImageObj_Unk_077554`
- `ImageObj_Unk_0779a0`: decompiler-derived

## Not done in M1-T926
- `ImageObj_Unk_0777e0`
- `ImageObj_Unk_077a4c`
- `ImageObj_Unk_0779f4`
- `ImageObj_Unk_077ea4`
- `func_02077f30`
- `func_02077e0c`
- `ImageObj_Unk_077c30`

## Not done in M1-T927
- `func_0207726c`
- `func_02077750`
- `ImageObj_Unk_0791a8`
- `func_020773dc`
- `func_020774b4`
- `func_02077900`
- `func_02077314`
- `func_02077ca0`

## Not done in M1-T929
- `func_02078940`
- `func_02078364`

## Not done in M1-T928
- `func_02078f34`
- `func_02078ce0`
- `func_02079044`
- `func_02077ac8`
- `func_02077f8c`
- `func_02078db4`
- `func_02078730`
- `func_020780f4`
- `ImageObj_Unk_0775a0`: decompiler-derived (plain cleanup)
- `ImageObj_Unk_077640`: decompiler-derived (plain cleanup)
- `ImageObj_Unk_0791a8`: decompiler-derived (proto cleanup)
- `ImageObj_Unk_079000`: decompiler-derived (plain cleanup)
- `ImageObj_Release`: hand-matched
- `ImageObj_GetOrCreate`: hand-matched
- `ImageObj_Unk_077554`: hand-matched
- `ImageObj_Unk_077708`: hand-matched
- `ImageObj_Unk_0777e0`: hand-matched
- `ImageObj_Unk_077a4c`: hand-matched
- `ImageObj_Unk_077d68`: hand-matched
- `ImageObj_Unk_077d98`: hand-matched
- `ImageObj_ReleaseField68`: hand-matched
- `ImageObj_Unk_0779f4`: hand-matched
- `ImageObj_Unk_077c30`: hand-matched
- `ImageObj_Unk_077ea4`: hand-matched
