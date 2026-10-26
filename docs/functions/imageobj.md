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

## M1-T924 — verified ARM functions (8/8)

All eight entries match at 100% in objdiff. Instruction evidence is from the
delinked object `build/delinks/src/ImageObj.o`; original neutral symbols are
retained where the field meanings are not established.

- `ImageObj_Unk_079000` (40 B, 02079000): when the singleton exists, clears
  table slot `4 + *arg0 * 4`. LDR of the singleton at 02079004 and indexed
  store at 0207901c establish the slot layout; a valid index is required.
- `func_02077a9c` (44 B, 02077a9c): null-safe predicate returning one when a
  node's word at +4 equals 9 or 10. LDR/CMP/CMPNE at 02077aa8..02077ab0 and
  the separate return block at 02077ac0 establish the two accepted states.
- `ImageObj_Unk_077d68` (48 B, 02077d68): null-safe predicate returning one
  when the object's first word is 2 and its word at +0x50 is below 600.
  LDR/CMP at 02077d78 and 02077d84..02077d88 establish both conditions.
- `ImageObj_Release` (48 B, 02077ddc): when the loaded flag at +0x10 is set,
  releases the sub-object at +0x34, calls the shared cleanup, then clears the
  loaded flag and +0. LDR/CMP at 02077de4..02077de8 and the teardown BL at
  02077df0 establish the guard and field offsets.
- `func_02077e74` (48 B, 02077e74): null-safe teardown. A nonzero +0x6c word
  releases the field-68 handle and clears +0x6c; otherwise it forwards to
  `ImageObj_Unk_077ea4`. LDR/CMP/branch at 02077e80..02077e88 and the store
  at 02077e94 establish the split.
- `ImageObj_Unk_0775ec` (52 B, 020775ec): when the singleton exists, visits
  slots zero through two in order via `ImageObj_Unk_077554`. Accessor BL at
  020775f0 and loop bound CMP at 02077614 establish the iteration.
- `ImageObj_Unk_0776d4` (52 B, 020776d4): visits slots zero through two,
  forwards each slot handle to `func_02077a9c`, and returns one on the first
  state 9 or 10. BLs at 020776e0 and 020776e4 and bound CMP at 020776f8
  establish the loop and forwarding.
- `ImageObj_ReleaseField68` (52 B, 02077efc): releases a nonzero node handle
  at +0x68 through `func_02061424`, clears +0x68, then refreshes the
  singleton sub-object at +0x34. LDR at 02077f0c, BLs at 02077f18 and
  02077f28, and the store at 02077f24 establish the order.

Hard list for M1-T924: none.

## M1-T925 — verified ARM functions (8/8)

All eight entries match at 100% in objdiff. Evidence is from the delinked
object `build/delinks/src/ImageObj.o`; neutral names are retained where the
symbols do not establish a better description.

- `ImageObj_Unk_0775a0` (56 B, 020775a0): with no singleton it does nothing;
  otherwise it releases the work object when `0776d4` finds no slot in state
  9 or 10, and only sets flag `+0xc8` when one is found. Singleton LDR at
  020775a8, BL at 020775b4, flag store at 020775c0, Release BL at 020775cc.
- `ImageObj_GetOrCreate` (60 B, 02077478): returns the cached handle in slot
  `index`; when the slot is empty it creates the handle through
  `func_02077900` and caches it. Indexed LDR at 02077488, BL at 020774a4 and
  indexed STR at 020774ac. Requires a live slot table and an index in 0..47.
- `ImageObj_Unk_077228` (68 B, 02077228): scans slots zero through two; a
  live slot whose node reports state 9 or 10 makes it return zero, otherwise
  each live slot is torn down via `077554` and it returns one. BLs at
  02077234, 02077240 and 02077254; loop bound CMP at 0207725c.
- `ImageObj_Unk_077d98` (68 B, 02077d98): maps the system state to a display
  parameter (8 for states 0 and 2, zero otherwise) and forwards it with the
  node's `+0x68` handle to `Unk065e88_SetPair04`. BL at 02077da0, case MOVs at
  02077db8 and 02077dc0, final BL at 02077dd4.
- `ImageObj_Unk_077640` (72 B, 02077640): with no singleton, or when
  `079028` reports that the state word `+0x14` is not four, it returns;
  otherwise it releases and clears the `+0x18` handle, calls the two shared
  flush helpers, then clears `+0x14`. BL at 02077650, loads/stores at
  0207765c..02077680.
- `ImageObj_Unk_077708` (72 B, 02077708): returns one when the singleton is
  absent, or when every slot handle is zero or has a zero word at `+4`; the
  first live handle stops the scan with zero. Loop BL at 02077724 and
  conditional LDR at 02077728..02077730.
- `ImageObj_Unk_077554` (76 B, 02077554): tears down one slot when both the
  singleton and its handle exist. A node in state 9 or 10 only marks flag
  `+0xc4`; otherwise the node is torn down through `02077e74` and the slot is
  cleared through `079184`. BLs at 02077574, 02077590 and 02077598; flag
  store at 02077584.
- `ImageObj_Unk_077688` (76 B, 02077688): returns one when the singleton is
  absent, when every slot handle is zero, and when the work word at `+0x10`
  is zero; any live slot or a nonzero `+0x10` yields zero. Loop BL at
  020776a4 and LDR/CMP at 020776c0.

Hard list for M1-T925: none. `ImageObj_Unk_0779a0` is outside this card's
function list and remains covered by its own entry.

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
