# src/game/unit_020aa118.c

- `Unk0aa118_Nop_0ae054` (4 B): empty callback used as a no-op function pointer.
- `Unk0aa118_Thunk_020af8d8` (12 B): forwards its three arguments to `Unk0aa118_Unk_0af8d8`.
- `Unk0aa118_Unk_0ab454` (20 B): clears the +0x18 word of the object returned by `Unk044904_Unk_04509c`.
- `Unk0aa118_Clear814` (24 B): zero-fills the 0x814-byte structure at `p`.
- `Unk0aa118_PeekItem` (24 B): returns the item at the list cursor, or 0 once the cursor is at or past the end.
- `Unk0aa118_Unk_0ab4b8` (28 B): returns non-zero when the +0x18 word of the `Unk044904_Unk_04509c` object is set.
- `func_020ab4d4` (32 B): looks up the record for id `a`, then applies bit `b` (masked to 8 bits) through `func_02049aec(record, mask, 1)` and returns its result.
- `Unk0aa118_Unk_0afb40` (36 B): returns the table base for record id `data_0214d380[i]`, or 0 when `i` is 0.

## M1-T1077 (all verified at 100% objdiff)

- `Unk0aa118_SortRemaining` (40 B): sorts four-byte list entries from cursor
  (+0x80) to count (+0x84) with `Unk0aa118_CompareItems`. The call at
  0x020aa224 and cursor-relative start support the descriptive name.
- `Unk0aa118_Unk_0ab34c` (40 B): calls `func_020aa4f4(2, 0, 0, 0)`,
  then `func_020ae1e8(data_02176b18)`; larger purpose remains unknown.
- `Unk0aa118_Unk_0af7cc` (44 B): resolves a table through `func_020491b4`,
  checks the unsigned index against `func_0205f2e4`, and selects index 0
  when out of range before calling `func_0205f41c`.
- `Unk0aa118_Unk_0af7f8` (44 B): resolves the first index with the preceding
  helper, bounds-checks the second through `func_0204fd18`, then calls
  `func_0204fdac`, substituting 0 for an out-of-range second index.
- `Unk0aa118_Unk_0afb64` (44 B): allocates 0x94 bytes, clears them through
  `func_02008848`, writes the argument to the first word, and returns storage.
- `Unk0aa118_Advance` (52 B): increments the +0x80 cursor at 0x020aa264,
  calls `func_020aa130`, clamps to +0x84 count and returns 0 at the end,
  otherwise 1. These accesses support the descriptive name.
- `Unk0aa118_Unk_0af8d8` (52 B): returns borrowed table storage for the id,
  offset by 412 when `a == 1`, with the selection inverted for nonzero `c`.
- `Unk0aa118_Unk_0ab8f8` (56 B): checks global +0x40 bit 11 and
  `func_020b081c(2)` before OR-ing bit 3 into the caller's +8 word.

These implementations were already present at task start. Rebuilding confirmed
all eight matches; this task adds their contracts and corrects stale status.

## M1-T1078 (all verified at 100% objdiff)

The eight C bodies were already present at task start. Rebuilding verified
all eight matches; this task documents their contracts and corrects stale status.
No algorithm or module boundary changed.

- `Unk0aa118_Unk_0af824` (56 B): finds a record for the id and uses its
  first two bytes to select borrowed table storage. Missing ids use table (0, 0).
- `Unk0aa118_GetTableD2f4` (60 B): reads `data_0214d2f4` at one-based index
  `i`, with offsets 3 and 6 for `k == 2` and `k == 3`; other k values use 0.
  The literal data-symbol access supports the name. The index must be in bounds.
- `Unk0aa118_CompareItems` (68 B): compares borrowed item pointers by descending
  unsigned word +0x14, breaking ties by ascending unsigned word +0. The callback
  passed to sorting at 0x020aa224 supports the name; equal keys return zero.
- `Unk0aa118_Unk_0afab0` (72 B): returns table (39, 0) storage, advanced by
  half its unsigned entry count times 22 when bits 16..23 of x equal 1.
- `Unk0aa118_Unk_0afaf8` (72 B): the same selection for table (0, 0).
- `Unk0aa118_Unk_0ab930` (76 B): returns byte +58, +59, or +60 of p for
  id classifications 4, 1, or 5 from `func_0204add4`; otherwise returns zero.
  The caller supplies storage containing these bytes.
- `Unk0aa118_Unk_0acb28` (76 B): visits ten global pointers at +0x64;
  non-null entries with nonzero bits 16..23 in their first word receive
  `func_0204a7b4(entry, 2)`. The broader purpose remains unknown.
- `Unk0aa118_FindRecord` (76 B): scans 326 records of 34 bytes in
  `data_0214d398`, comparing id against each record +2 via `func_020152cc`.
  The comparison in FindRecord at 0x020af780 supports the name. Returns the first matching
  borrowed record, or null if absent.

## Hard list

None for M1-T1077 or M1-T1078.

- `func_020aa298` (M1-T1079): all instruction matches except one. The original
  emits `mov r0,r6; popne` for the `y != 0` early return, while every C form
  tried compiles to `movne r0,r6; popne`. Trials covered direct `return x`,
  `if/else`, `switch`, `goto`, local result copies, pointer/small integer
  parameter types, all installed mwccarm 1.2/2.0 service packs, and several
  optimization/pragma variants. The rest of the function (record lookup,
  `Unk044904_Unk_044f4c`, `func_0204a9ec`, fallback through `func_020b1144`)
  was verified instruction-for-instruction with a `switch` on the
  `func_0204a9ec` result. Left out of C so the delink remains authoritative.

## M1-T1079 (verified at 100% objdiff unless noted)

- `Unk0aa118_Unk_0afb90` (76 B): allocates and clears a 0x90-byte node, links
  it at the owner's +0x18 head / +0x1c tail, increments the +4 node count and
  returns the node. The head/tail/link stores at 0x020afb90 support this.
- `func_020afbdc` (76 B): walks the +0x18 node list, frees each node, decrements
  the +4 count, stops after the +0x1c tail (or a null link), then frees the
  owner. Head/tail accesses at 0x020afbdc support this contract.
- `Unk0aa118_AddUniqueId` (80 B): adds an id to the global `Unk044904_Unk_04509c`
  object's id array when absent, capped at six entries. The +0x18 count and
  capacity check at 0x020ab468 support this.
- `Unk0aa118_Unk_0afa60` (80 B): looks up the id through `Unk09974c_Unk_099d14`,
  rejects entries that do not match `data_0214fef8` via `func_020152cc`, and
  otherwise forwards to `Unk0aa118_Unk_0af8d8`. The `data_0214fef8` literal at
  0x020afa60 supports the comparison.
- `func_020aa130` (88 B): clears bit 15 of word +8 on each entry of the three
  32-entry groups. Group k starts at +0x88 + k*0x284; the +0x308 count and
  +0x14 entry stride at 0x020aa130 support this layout.
- `func_020aa188` (88 B): inserts the borrowed entry pointer into the 32-entry
  list when absent, re-sorts the unconsumed range and returns 1; returns 0 when
  full. The +0x84 count, capacity check and `Unk0aa118_SortRemaining` call at
  0x020aa188 support this contract. The caller at 0x020efdf4 passes a record
  pointer, which fixes the pointer parameter type.
- `func_020aa298` (88 B): not done; see the hard list above.
- `Unk0aa118_Unk_0ab4f4` (88 B): returns 1 when the mode argument is 3;
  otherwise rejects mode-2 records that fail `func_0204a0e8(record, 400)` and
  forwards to `func_020b0310`. The mode check and calls at 0x020ab4f4 support
  this contract.

## M1-T1080 (seven verified at 100% objdiff)

Names remain the configured neutral symbols: the instruction sequences establish
these operations but do not establish their wider gameplay purpose.

- `func_020ae270` (104 B): resolves the category byte from the leading id
  word, submits the corresponding table, flushes requests, then chooses request
  16 or fallback `(0, 60, 17, 0)` using the two global queries. Evidence:
  the category shifts and callee sequence at 0x020ae270.
- `func_020af9f4` (108 B): tries `func_020cb1a0` then `func_020cb21c`,
  returning table storage for the first nonzero resolved id. Both failing selects
  `data_0214fef0`. Category and reversal pass through unchanged.
- `func_020ae16c` (124 B): category 1 forwards to `func_020ae0d8`, bypassing
  the counter check only when query 1 succeeds and global halfword +0x38 is
  zero. Other categories submit request 8. Evidence: the branches and halfword
  access at 0x020ae16c.
- `func_020af85c` (124 B): finds `data_0214fee4`, resolves its first two bytes
  to a table, then returns six-byte entries at index - 1, index + 2, or index + 5
  for groups 1, 2, or 3. Other groups return the base; a missing record returns
  null. Caller must provide valid group indices. Storage is borrowed.
- `func_020ab2c8` (132 B): dispatches record kind +8 equal to 5 or 6 through
  separate resolvers using id +12, then submits `(0, 32, result, 0)`; all other
  kinds do nothing. The original jump table preserves distinct return groups.
- `func_020ae1e8` (136 B): allocates temporary work, selects the
  `data_0214d318` table and clears flag 0x10, then appends kind-2 nodes from
  eight-byte records until their second word is UINT_MAX. It processes the
  work and frees the nodes and owner. Input is borrowed and sentinel terminated.
- `func_020ae0d8` (148 B): rejects global +0x40 bit 2 with request 6. When
  bypass is zero it checks global halfword +0x3a, increments that halfword even
  on failure, and rejects a failed query with request 5. Otherwise it calls
  `func_020ae058` and returns 1. The third argument is unused in the original.

### Hard list: M1-T1080

- `func_020ae058` (128 B): retained in the delinked object, without a C body.
  The assembly submits `(0, 32, 4, 0)`, loops over one eight-byte descriptor
  at `data_0213c424` (operation byte +1), submits `(70, 3, 0, 1)`, flushes,
  then submits `(0, id, 8)`. Compiled C trials with for/do loops at the default
  optimization level fold the one-iteration loop (70.09%). A local optimization
  level 2 trial retains the loop and reaches 93.22%, but generates separate
  shift/add/indexed-load instructions instead of add plus byte load, and assigns
  the cursor/counter registers differently. Typed byte and bitfield descriptors
  reached 84.19% and 89.50%; optimization levels 1 and 3 also failed to match.
  No trial body or compiler override is retained. A human can use
  `tools/decompme.py` to investigate the address generation and loop optimization.

## Not done in M1-T1081
- `func_020ae978`
- `func_020aca7c`
- `func_020aea20`
- `func_020aad08`
- `func_020aeacc`
- `func_020aa42c`
- `func_020af90c`
- `func_020ab374`

## Not done in M1-T1082
- `func_020ab54c`
- `func_020ae888`
- `func_020aa4f4`
- `func_020ac97c`
- `func_020aabf4`
- `Unk0aa118_Unk_0acb74`
- `func_020aa2f0`
- `func_020aeb90`
- `Unk0aa118_Unk_0acb74`: decompiler-derived (plain+fix cleanup)
- `Unk0aa118_PeekItem`: hand-matched
- `Unk0aa118_Clear814`: hand-matched
- `Unk0aa118_CompareItems`: hand-matched
- `Unk0aa118_AddUniqueId`: hand-matched
- `Unk0aa118_Unk_0ab930`: hand-matched
- `Unk0aa118_Unk_0acb28`: hand-matched
- `Unk0aa118_GetTableD2f4`: hand-matched
- `Unk0aa118_FindRecord`: hand-matched
- `Unk0aa118_Unk_0afa60`: hand-matched
- `Unk0aa118_Unk_0afab0`: hand-matched
- `Unk0aa118_Unk_0afaf8`: hand-matched
- `Unk0aa118_Unk_0afb40`: hand-matched
