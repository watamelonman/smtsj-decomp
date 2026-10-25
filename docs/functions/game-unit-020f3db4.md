# src/game/unit_020f3db4.c

## M1-T503: eight matched helpers

Evidence: ARM disassembly of `build/delinks/src/game/unit_020f3db4.o`,
with symbol addresses from `config/arm9/symbols.txt`. All eight match at 100%.
Names remain neutral because the packed states and subsystem meanings are unknown.

- `Unk0f3db4_Unk_0f44a8` (8 B): returns `arg0 & 3`; the AND immediate establishes the two-bit mask.
- `Unk0f3db4_Unk_0f3dc8` (16 B): tail-forwards index 8 to `Unk044394_Unk_044428`, ignoring its result.
- `Unk0f3db4_Unk_0f3dd8` (16 B): tail-forwards index 8 to `Unk044394_Unk_044534`, ignoring its result.
- `Unk0f3db4_Unk_0f4528` (16 B): tests bit 2 and returns exactly zero or one, as shown by TST and conditional MOVs.
- `Unk0f3db4_Unk_0f4550` (16 B): reads a byte, sets bit 2, and writes it back; requires writable storage.
- `Unk0f3db4_Unk_0f3db4` (20 B): calls `Unk02e000_Unk_02e774` and adds 0x52 then 0x5e00, returning a borrowed work address in the existing integer-address convention.
- `Unk0f3db4_Unk_0f44d0` (20 B): retains only the old byte's bit 2, ORs the unmasked byte argument, and stores the result. Requires writable storage; callers normally supply a two-bit state.
- `Unk0f3db4_Unk_0f4490` (24 B): passes the table selector to `Unk0f3db4_Unk_0f3ec8`, loads the byte at the supplied offset, and calls the low-bit extractor. The caller must supply a valid selector and offset. The selector is now explicit instead of relying on an unprototyped call leaving r0 intact.

Hard list for M1-T503: none. Existing functions belonging to other cards are retained.

## M1-T504: eight matched functions

Evidence: ARM disassembly and relocations in
`build/delinks/src/game/unit_020f3db4.o`; addresses from the symbol map.
All eight functions match at 100% in objdiff. Borrowed records expose only
observed fields; the table selector and offset remain caller-bounded.

- `Unk0f3db4_Unk_0f4510` (24 B): loads the selected table byte and returns
  the bit-2 predicate from `Unk0f3db4_Unk_0f4528`. The return is explicit.
- `Unk0f3db4_Unk_0f4538` (24 B): adds the supplied offset to the selected
  table and calls the bit-2 setter; storage must be writable.
- `Unk0f3db4_IsName` (32 B): calls `func_020152cc` with the input string and
  `data_02150e24`, returning whether the comparison is zero. The existing
  symbol supplies the name; the relocation establishes the fixed operand.
- `Unk0f3db4_Unk_0f44b0` (32 B): forwards the selected table plus offset and
  byte value to the packed-byte writer, preserving the writer's bit-2 rule.
- `Unk0f3db4_Unk_0f44e4` (44 B): promotes low state 2 to 3 through the
  existing accessor and writer, leaving other states alone.
- `Unk0f3db4_Unk_0f4398` (60 B): scans three four-byte entries at +10;
  nonzero halfword IDs go to `func_02099b10` with the halfword at +12 times
  the supplied multiplier. No subsystem meaning is inferred.
- `Unk0f3db4_Unk_0f4448` (72 B): queries `func_0209993c`; a positive result
  is decremented if the ID equals any of four halfwords in the borrowed
  storage from `Unk02e000_Thunk_0202e788`. Nonpositive results pass through.
- `func_020f4070` (88 B): scans the same three entries, stopping on a zero
  ID. A query result below the entry count returns 0 at index zero or 1 at
  a later index; otherwise the result is 2, including an early zero ID.

Hard list for M1-T504: none. No new behavioral tests are required by the card;
the original object is the instruction-level acceptance oracle.

## M1-T505: eight matched functions

Evidence: ARM disassembly and relocations from the delinked original object;
objdiff reports 100% for all eight. Existing neutral symbols are retained.

- `Unk0f3db4_Unk_0f3e6c` (92 B): returns lengths 50, 50, 50, 50,
  100, 60 for selectors 0..5 and zero otherwise.
- `func_020f4560` (96 B): rejects selectors outside 0..5, then returns
  whether any packed state equals 2. The offset counter is a halfword.
- `Unk0f3db4_Unk_0f3ec8` (100 B): returns the borrowed work address
  plus 0, 50, 100, 150, 200, or 300, or null for an invalid selector.
- `func_020f43d4` (116 B): scans all six tables with halfword offsets,
  promoting state 2 to 3 while preserving the writer's bit-2 rule.
- `func_020f3de8` (132 B): selects resource 8, mapping selectors 0/1
  to table 0 and 2..5 to tables 1..4. Selector 1 adds 50 to the halfword
  index with wraparound. Calls 0204fe18, then obtains the base through
  0204fde0 and returns the indexed 46-byte record. Ownership stays external.
- `func_020f40c8` (152 B): resolves existing eight-byte entries using
  their ID at +4 and index at +2. Compares strings at record +22 and
  appends the incoming ID/index only when no equal string exists.
  The caller provides writable capacity; no bound is present in the original.
- `Unk0f3db4_Unk_0f4674` (152 B): copies only low two state bits for
  byte ranges [0,100), [100,150), [150,200), and [300,360).
  The gap [200,300) is intentionally untouched, following the original.
- `func_020f3f2c` (160 B): maps signed ID ranges 211..260, 261..310,
  311..360, 361..410, 111..210, and 51..110 to selectors 0..5.
  Other IDs return zero.

Hard list for M1-T505: none. The original object supplies the instruction-level
acceptance oracle; this card requires no new behavioral tests.

## Remaining functions outside M1-T505

- `func_020f3fcc`
- `func_020f45c0`
- `func_020f4180`
