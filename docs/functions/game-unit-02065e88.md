# unit_02065e88

Setters on a shared game object (layout `GameObj`, field meanings unknown).

## M1-T1017 (verified at 100% objdiff)
- `Unk065e88_Nop_066c90`: empty body (bare `bx lr`, 4 bytes); address is stored in the
  callback table built by `Unk065e88_Unk_06646c`. No direct callers. Neutral name: nothing
  in the callers or data says what the callback does.
- `Unk065e88_SetPair04`: stores the two arguments in the adjacent u32 pair at +0x04/+0x08.
- `Unk065e88_SetUnkField20`: stores the u32 argument at +0x20.
- `Unk065e88_SetUnkField24`: stores the u32 argument at +0x24.
- `Unk065e88_SetUnkField28`: stores the u32 argument at +0x28.
- `Unk065e88_SetUnkField2C`: stores the u32 argument at +0x2C.
- `Unk065e88_SetUnkField30`: stores the u32 argument at +0x30.
- `Unk065e88_SetUnkField34`: stores the u32 argument at +0x34.

All eight are single `str r1,[r0,#off]` stores (or two for the pair) and were already present
and matching when the card started; this task added per-function contracts and re-verified
them with objdiff.

## M1-T1018 (verified at 100% objdiff)

The eight implementations were already present on entry. This card gives the
setters typed fields, makes the lookup-result forwarding explicit, and documents
the instruction evidence. All are ARM functions; names retain unknown semantics.

- `Unk065e88_SetUnkField3c` (020662cc, 8 bytes): stores a u32 at object
  offset +0x3c. The caller owns a writable object through that offset.
- `Unk065e88_SetUnkFieldsc_10` (02066284, 12 bytes): stores the second and
  third arguments at +0x0c and +0x10, respectively. These stores establish the
  field-based name, without assigning gameplay meanings.
- `Unk065e88_Unk_068554` (02068554, 16 bytes): calls the resource-19 id lookup
  `func_020a1428`, then passes its returned pointer in r0 to `func_020684c0`.
  Returns the latter's result; the record must be valid because 020684c0
  dereferences it. Resource lookup evidence is in `unit_020a1418.c`.
- `Unk065e88_Unk_065eac` (02065eac, 20 bytes): calls `func_0205bb68` three
  times. The calls set no argument registers; no broader purpose is inferred.
- `Unk065e88_Call_02065fc0` (02065fac, 20 bytes): forwards the first three
  words, supplies 3 as the fourth argument, and moves the incoming fourth word
  to the fifth argument's stack slot. The call instruction supports the name.
- `Unk065e88_SetFlag3a` (020662b8, 20 bytes): normalizes the input to 0 or 1
  and writes the byte at +0x3a; the cmp and conditional moves support the name.
- `Unk065e88_Unk_0663bc` (020663bc, 28 bytes): saves arg0 in r4, forwards
  arg1 to `Unk05ae50_Unk_05af2c`, then restores arg0 into r0 for `func_020617c8`.
  The first callee currently ignores the forwarded word; its register transfer
  is still represented explicitly to preserve the original wrapper.
- `Unk065e88_GetTable` (020663d8, 32 bytes): selector 0 returns 0214544c,
  selector 1 returns 02144e44. Other selectors leave r0 unchanged; C explicitly
  returns the selector cast to a pointer, which is not a valid table contract.
  The literal loads and GetTableEntry's word indexing support the table name.

Hard list for M1-T1018: none. All eight match including the explicit fallback
return and typed lookup-result forwarding. No runtime tests were added because
this matching card uses the original object as the byte-level oracle.

## M1-T1019 (verified at 100% objdiff)

All eight bodies were present on entry and already matched. This card makes
argument forwarding explicit, types the helper declarations used by these
functions, and records contracts from the original ARM instructions.

- `Unk065e88_Unk_06644c` (0206644c, 32 bytes): compares readable pairs
  of unsigned halfwords, second halfword first and first halfword on ties.
  The signed difference is returned without normalizing its magnitude.
- `Unk065e88_Unk_065e88` (02065e88, 36 bytes): calls 0202e0cc, then
  calls 0205b82c with ids 188, 189 and 190. No gameplay meaning is inferred.
- `Unk065e88_Unk_066258` (02066258, 36 bytes): reads a caller-owned
  handle slot, forwards a nonzero handle to 0205c3dc, then zeros the slot.
  The original ldr into r0 before the branch establishes the forwarded argument.
- `Unk065e88_GetTableCount` (020663f8, 36 bytes): returns 193 for
  selectors 0 and 1, otherwise zero. The constants and GetTableEntry's word
  indexing support the table name.
- `Unk065e88_Unk_067d30` (02067d30, 36 bytes): forwards r0/r1 to
  020445d0, passes the returned resource to 0204fe18, stores the low halfword
  of that result through the incoming r2, then passes the resource to 0204fde0.
  Explicit arguments replace the old implicit register forwarding.
- `Unk065e88_GetTableEntry` (0206641c, 48 bytes): subtracts one from
  the incoming index; offsets >= count - 1 become zero, while negative
  offsets survive. Returns GetTable(selector) plus that word offset. Callers
  must provide a valid table selector and index; this preserves the original
  signed comparison and its unusual exclusion of the last table word.
- `Unk065e88_SetMode` (020672b4, 72 bytes): stores the mode at +0,
  then returns if notification is disabled. Otherwise mode 1 calls 02072238,
  mode 2 stores 1 at +0x220, and mode 4 stores 1 at +0x2f0. The store and
  dispatch support the existing name; the caller owns the selected fields.
- `Unk065e88_Unk_068564` (02068564, 76 bytes): returns false if bit
  28 at +0x24 is set. Otherwise it requires either a zero halfword at +0x2a
  or a nonzero 020e666c result, followed by a nonzero 020684c0 result.
  The result is normalized to 0/1; the partial struct follows these loads.

Hard list for M1-T1019: none. All eight match the original object at 100%.
No runtime tests were added: the task explicitly waives them and objdiff is the
byte-level oracle. The existing source is extended rather than recreated to
preserve the earlier cards and the remaining implementations.

## M1-T1020 (verified at 100% objdiff)

Five bodies were already present and matching. Three missing bodies were added;
helper declarations now state their argument contracts. Names remain neutral
because the instruction evidence does not establish gameplay semantics.

- `Unk065e88_Unk_066078` (02066078, 84 bytes): byte +0x38 enables a
  handle update; byte +0x39 enables a position/count comparison. Reaching
  count minus one clears both bytes. The handle is the word at +0.
- `Unk065e88_Unk_06646c` (0206646c, 88 bytes): writes size 1104,
  mode 4, null at +0x0c and callbacks at +0x10 through +0x20. Leaves +8
  untouched. The caller provides a writable 36-byte descriptor.
- `Unk065e88_Unk_065ec0` (02065ec0, 112 bytes): writes size 120,
  invokes 02095818, then writes mode 4, halfword 100 at +8, and six
  callbacks at +0x0c through +0x20. The caller owns the descriptor.
- `Unk065e88_Unk_0672fc` (020672fc, 116 bytes): resets 02063920's
  shared state, looks up resource 12 with the incoming selector, converts
  each of n entries, then passes the last result as the fifth argument to
  02061f10 with the owner's +0x108 handle. Requires n > 0; the original
  does not initialize the result when the count is zero.
- `Unk065e88_Unk_065f30` (02065f30, 124 bytes): clears 120 bytes,
  stores two allocation results, and returns immediately if either fails.
  On success clears +8, +0x0c and +0x4c, calls 02063a6c and publishes
  the owner at 0216b9ac. A failed second allocation retains the first.
- `func_02067418` (02067418, 140 bytes): resolves incoming halfword
  ids via 020a1428; each record's byte +2 indexes resource 18. Converts
  each result, submitting the last through the owner's +0x11c handle.
  The byte count at +0xb2 must be positive and the id array must cover it.
- `func_020684c0` (020684c0, 148 bytes): returns 1 when bit 0 of
  halfword +0x28 is clear. Otherwise looks up the id at +0, then the
  upper 15 bits of +0x28 when nonzero, accepting either successful lookup
  whose byte +0x1f has nonzero upper six bits. Returns 0 otherwise.
  The temporary is 36 bytes: 0202e9c8 copies exactly 36 bytes, as its
  implementation in unit_0202e000.c confirms. Bitfields reproduce the
  original shifts. Keeping this definition last also avoids the documented
  objdiff same-file caller scoring artifact (tools/hand/README.md).
- `func_02066c94` (02066c94, 156 bytes): returns for +0x234 == 11
  or +0x390 == 8. Otherwise calls 02057e58 twice, calls 02057eb8(4),
  dispatches modes 1, 2/3, and 4 to 02072370, 0207498c, and 02092624
  respectively, then calls 02057eb8(-1). Other modes have no callback.

Hard list for M1-T1020: none. All eight match at 100%. No runtime tests
were added because the card waives them; objdiff supplies the byte-level oracle.
The translation unit remains linked from the original delink as required.

## M1-T1021 (verified at 100% objdiff)

All eight missing bodies are implemented with typed parameters and instruction-based
contracts. Names remain neutral: the data accesses establish mechanics, without
establishing gameplay meanings. Existing implementations are preserved. The wrapper
at 02065fac now types its final argument as a halfword, consistent with the callee's
`ldrh` of the fifth stack argument; both wrapper and callee match.

- `func_02067370` (168 bytes): resets conversion state, opens resource 18,
  and visits the signed selection indices at shared-work +0x348, with byte
  count at +0x357. Nonnegative indices select owner pointers at +0x120;
  each pointed record's halfword +0x36 resolves resource 19, whose byte +2
  indexes resource 18. Submits the last converted value through owner +0x118.
  Requires at least one nonnegative selection and valid referenced entries;
  the original leaves the result uninitialized otherwise.
- `func_02067c88` (168 bytes): calls 020dd910, builds a 16-byte local
  descriptor, and submits id 161 with owner handle +0. Resets dispatch state,
  reads shared-work byte +0x6e, resolves table 021457d4 with selector 2,
  and submits the returned pointer +0xf0 with format/table 021457dc.
- `func_020685b0` (168 bytes): clamps the incoming rank downward using
  owner +4 indexed by kind. Scans count (+0xb0) consecutive 100-byte resource-19
  records, requiring matching byte +2, byte +3 at or above rank, and a true
  02068564 predicate. Returns the index with the smallest distance below 255;
  ties retain the first result and no match returns zero. Kind must be <64.
- `func_02068658` (168 bytes): uses owner +0x44 to clamp rank upward,
  then selects the nearest eligible record at or below rank. Other selection,
  validity, tie and zero-result contracts are identical to 020685b0.
- `func_02065fc0` (176 bytes): allocates 64 bytes with 020611dc. The
  first callback is always 02066078; nonzero input c puts 020660cc in the
  second callback slot, zero puts it in the third. The fourth is 02066258.
  Creates a handle, forwards a/b to 0205c3fc, stores unit float values at
  +0x14/+0x18/+0x20, -1 at +0x28/+0x30/+0x34/+0x3c, and byte 1 at
  +0x38/+0x3a. Returns the owner; original assumes allocation succeeds.
- `func_02067b28` (176 bytes): submits four 0x7b7b7bff dispatch words.
  Zero value uses owner handle +0x3b0, id 25, x minus 8, y, unit scales
  and layer 10. Nonzero value submits table 021457cc through 020a9fd8.
- `func_02067bd8` (176 bytes): uses the same handle path for zero value,
  including the dispatch words. Nonzero value instead calls 02057df8 and
  submits table 021457d0. Owner +0x3b0 must be valid for the zero path.
- `func_020674a4` (192 bytes): resolves the incoming id via resource 19.
  A zero record id uses four 0x7b7b7bff words; category byte +5 equal to
  4 uses 0x39dccbff, category 5 uses 0xff7b63ff, otherwise calls 02057df8.
  Submits the caller descriptor, signed halfword fifth argument and incoming
  fourth argument through the owner's handle with layer 10.

Review corrections: the allocation now uses named `GameObj` fields, with float
slots and separate flag bytes. The +0x20 slot retains a union word view because
its pre-existing setter stores raw bits. Selection entries, shared work, and
+0x3b0 dispatch owners use partial structs with explicit padding. The 15-element
selection span is inferred from the gap to the count byte; capacity is unproven.
Bounds tables use neutral offset names because their gameplay meaning is unknown.

The 02067c88 lookup result now has a named +0xf0 field. Inspection of
020a9fd8 shows it saves the second/third arguments as words; 020a9f34 adjusts
those saved coordinates arithmetically, and 020a9bb4 receives their values.
Thus changing the second argument to a pointer would misrepresent the callee.
The explicit address-to-coordinate conversion remains intentional: the original
02067c88 uses `add r1, r0, #240`, without loading or dereferencing that address.

Hard list for M1-T1021: none. All eight functions and the earlier 32 definitions
match at 100%. No runtime tests were added because the card waives them; the
original object is the byte-level oracle. The TU remains linked from the delink.

## M1-T1022 (verified at 100% objdiff)

All eight missing bodies are implemented. Neutral names are retained because
instruction/data evidence establishes operations without gameplay meanings.
Partial owner and record structs describe only observed fields and loop extents.

- `func_02067564` (208 bytes): resolves resource 19 by the incoming halfword
  id. Zero record id and categories other than 4/5 select four 0x7b7b7bff
  words; category 4 selects 0x18525aff, category 5 selects 0x5a3129ff.
  Submits the caller descriptor, fourth argument and signed halfword fifth
  argument through owner handle +0, with layer 10. Resource and handle must
  be valid.
- `func_020662d4` (232 bytes): obtains shared storage at 02140ac8, calls
  0205ae50 with the index, then selects two tables and a count by mode.
  Modes 0/1/2 select 193 entries, mode 3 selects 71. Calls 02052b58(0),
  passing its result, the selected tables, two mode-indexed bytes from
  02144814/02144815 and the indexed 24-byte shared record to 02061828.
  Returns 1. Mode must be 0..3 and index must select valid shared storage;
  the original does not validate either argument.
- `func_02068bf8` (256 bytes): visits ids 0 through owner halfword +0xbc
  minus one via 020de720. That helper searches resource 22/4 for matching
  record ids and returns 28-byte records. For each, clears twelve local
  flags and marks nonzero halfwords at +2 through +0x18 that occur in the
  caller list; zero terminates the scan. Returns halfword +0x1a from the
  first record with all flags set, otherwise zero. Every visited record
  must exist. Count must be positive: the original leaves the cursor
  uninitialized when the caller list is empty. An empty record matches.
- `func_02067780` (264 bytes): resolves resource 19 and builds a 16-byte
  descriptor with 02060dd4(owner, 0, fifth halfword argument, 5). Category
  4 uses four 0x39dccbff words, category 5 uses 0xff7b63ff; others reset
  dispatch state with 02057df8. Kind byte +2 equal to zero overrides this
  with 0x7b7b7bff and increments the submitted value. Both paths submit
  owner handle +0, the incoming third argument and layer 10.
- `func_020666bc` (276 bytes): publishes the owner at 0216b9b4 and sets
  adjacent shared words to 1; clears observed owner state, initializes
  +0x400 via 0205e5b4, and obtains resources 22/4 and 23/1 with counts
  stored at +0xbc/+0xc4. Copies twelve area-record pointers to +0x120,
  clears 96 bytes at +0x15c, allocates 240 and 1956 bytes into +0x404/
  +0x408, calls 02067d54, stores the used-slot count at +0x158, and
  enables mode 1. Owner storage must cover +0x43c; allocations must succeed.
- `func_02067888` (280 bytes): descriptor and kind-zero behavior match
  02067780, while category 4 uses 0x18525aff, category 5 uses 0x5a3129ff,
  and other categories explicitly select 0x7b7b7bff. Both descriptor
  dispatch functions require valid resource records and owner handles.
- `func_02067634` (332 bytes): resolves the halfword id at entry +0x36
  and returns immediately if lookup fails. Zero record id selects
  0x7b7b7bff. Category 4 chooses 0x18525aff for entry +0x34 equal to
  1/7, otherwise 0x39dccbff. Category 5 similarly chooses 0x5a3129ff
  or 0xff7b63ff. Other categories select 0x7b7b7bff for state 1/7,
  otherwise reset dispatch state. Submits the incoming descriptor and
  signed halfword value through owner +0 with layer 10.
- `func_02066d30` (336 bytes): unconditionally calls 020629c4 for handles
  +0x108/+0x10c/+0x110/+0x118/+0x11c/+0x114/+0x150, clearing nonzero
  slots afterward. Conditionally releases +0x3b0 and +0x3b4 via distinct
  helpers. Releases and clears twelve slots at +0x40c and eight at +0x3b8;
  frees the two buffers at +0x404/+0x408 and clears the published owner.
  Unconditional release helpers must accept zero, as in the original.

The existing 02067d30 wrapper now returns 0204fde0's pointer explicitly:
020666bc stores that return value. Its original call/return instructions already
forwarded r0; the typed return fixes the prior declaration without changing bytes.
No module boundary changes were needed; layouts remain local to this TU.

Hard list for M1-T1022: none. All eight target functions are 100% in the
objdiff report, as are the existing definitions checked by the match gate.
Anticheat and all nine existing tests pass; checksum confirms all configured
artifacts byte-identical. No runtime tests were added because the card waives
them and the original object is the byte-level oracle. The TU remains linked
from the original delink, pending human completion marking.

## M1-T1023

Four implementations were added with typed parameters and contracts derived from
ARM loads, stores and calls. Neutral address names retain unknown gameplay
semantics. The original delink remains the link source; no assembly stubs are
needed in this repository's Nintendo DS workflow.

- `func_020660cc` (396 bytes): skips zero scale (+0x20) or disabled byte
  +0x3a, optionally selects the layer at +0x3c and state at +0x30, and
  overrides each handle collection member's word +8 from object +0x34.
  Dispatches modes 0/1 through 0205c748/0205c948 with summed position
  offsets and the five stored scale/state arguments. Restores dispatch state
  and the layer afterward. The object handle and collection members must exist.
- `func_02067134` (384 bytes): releases seven owner handles and the two
  auxiliary resources. For twelve slots at +0x40c and eight at +0x3b8,
  calls 0205c6f8 with the nested handle, disables byte +0x3a, releases
  the callback object and clears the slot. Calls 0205bb68 and 020dc908
  afterward. All twenty callback pointers must be valid.
- `func_020679a0` (392 bytes): builds a 16-byte descriptor from the fifth
  halfword argument. Resource category 4/5 and entry state 1/7 select
  the same color words as 02067634. Other states reset dispatch state.
  Resource kind zero overrides the words with 0x7b7b7bff and increments
  the submitted value. Requires valid entry/resource pointers and owner handle.
- `func_02068cf8` (544 bytes): initializes thirty owner status bytes at
  +0x372, then scans resource-22 records. Each nonzero component is checked
  against the supplied ids and then its record flag. Zero components are
  skipped; the scan still visits all twelve positions. Any available component
  admits an otherwise eligible result. Writes result ids and status at +0x334;
  complete component sets clear +0x372 and may initialize the entry returned
  by 020de784. A component supplied by a record flag clears +0x334 even
  for incomplete sets. Output/status capacity must cover all admitted records.
- `func_02067d54` (416 bytes), **hard**: clears the 240/1956-byte buffers,
  collects available ids 411..900, sorts four-byte id/rank pairs with
  0206644c, then fills up to 24 ten-byte slots starting from signed +0x156
  minus one. Tried indexed halfword buffers (432-byte output), then typed
  pair/slot layouts (404-byte output). The latter matches the collection loop
  but differs in the second loop's register allocation and folds the empty-id
  load/store into a predicated store. Candidate was removed rather than
  retaining a nonmatching implementation.
- `func_02068a58` (416 bytes), **hard**: selects rank-matching resource-19
  candidates excluding three indices and twelve selected entry ids, filters
  the upper three bits of +0x24 against the shared mode, then chooses a
  candidate through 02050074. Tried a typed 100-byte record with a three-bit
  field, separate count increments and alternate local declaration order.
  Output reaches 416 bytes but assigns count/mode/record/index to different
  registers and differs in candidate append scheduling. Candidate was removed.
- `func_020664c4` (504 bytes), **hard**: message types 1/3/4 notify, update
  mode-specific states, or reset and switch modes. Reconstructed the jump table,
  nullable payload checks and flag-guarded word extraction, using an aggregate
  local initializer to reproduce the stack address store. Output reaches 504
  bytes but uses r3/ip instead of r5/r3 for the valid flag/payload and schedules
  conditional state stores differently. Reusing the flag for the type-4 mode
  did not resolve allocation. Candidate was removed.
- `func_02066e80` (692 bytes), **hard**: initializes owner handles and twenty
  callback objects from literal tables 02145788/94/b0. Reconstructed all calls,
  allocations and callback-field stores. Both direct and inline-helper local
  descriptor initialization produce 628 bytes: the compiler eliminates the
  unused descriptor initialization, while the original retains its loops and
  72-byte stack frame. Candidate was removed; no volatile workaround or
  artificial use was added to force otherwise dead stores.

Hard list for M1-T1023: `func_02067d54`, `func_02068a58`, `func_020664c4`,
`func_02066e80`. These require further matching work or human decomp.me scratches
via `tools/decompme.py`. No runtime tests were added: the card waives them and
objdiff compares the generated code with the original object.

Validation: full `match_gate.py` build/report passes for all 51 C definitions in
this TU, including all four new definitions at 100%. `anticheat.py` passes,
all nine existing unit tests pass, and `checksum.py` reports all configured
artifacts byte-identical to the original. The four hard-list functions remain
supplied by the original delink and are not claimed as matched C.

## M1-T1024

- `func_020667d0` (1216 bytes), **matched**: advances signed initialization
  byte +0x3e6 through stages 0..8, then dispatches owner modes 1, 2 and 4.
  Stage 1 allocates +0x108; stage 2 reads the resource-19 count, scans
  100-byte records for per-kind maximum/minimum eligible ranks in the two
  64-byte arrays, and allocates/configures four more handles. Stage 3 creates
  two handles; stage 4 loads resource-22/23 tables and counts; stages 5/6
  load descriptors 02145750/6c and create eight plus twelve callback objects.
  Stage 7 configures the first two callbacks; stage 8 calls 0206a2ac.
  The owner must cover 1104 bytes and resource/callback allocation must succeed.
  Typed local layouts describe only the accessed fields. Initial standalone
  output differed in the two loop-variable initialization instructions;
  initializing the index before the position accumulator reproduces the original.
- `func_02068700` (856 bytes), **matched**: selects a chance byte from
  owner +0x84 using the fifth argument and 0203fa28 result. Flags 180/181
  override the choice; flag 1855 forces the original id and is cleared.
  A successful choice clamps the resource record's rank window to 0..99.
  Flag 182 first searches kind-42 records, excluding two indices and the
  twelve active selection ids, checking record eligibility and bits at +8/+0x24.
  Otherwise it samples a rank (twice with flag 180, retaining the minimum),
  searches down through positive ranks with 02068a58, then searches upward
  through the configured maximum. The returned value is an id or zero.
  Requires valid owner tables, resource ids and active selection pointers.
  Explicit bitfields and separate chance-array layout reproduce the original
  shift tests and indexed load; inactive selection slots are skipped.
- `func_02067ef4` (1484 bytes), **hard**: resolves two resource-19 ids,
  rejects equal records and 02068bf8 failures, then checks symmetric id-pair,
  special-id/kind, kind-pair and packed kind/id/mode tables. Packed modes
  select the next rank, second next rank or previous rank, rejecting either
  input id as a result. The final kind table uses mode conditions, flag-based
  kind substitutions (177..179), rank averaging with rounding, optional saved
  ranks (flag 184), and a three-rank bonus (flag 183) before 020685b0.
  Reconstructed the full routine with typed six/eight/four-byte table entries
  and 8/16/8-bit packed fields. A common averaging calculation produced 1420
  bytes; preserving the original separate averaging branches produced 1504.
  Factoring each mode's argument selection before its call and indexing packed
  entries directly reached 1480 bytes. The packed-rule loop still assigns its
  base/kind/mode to different registers and schedules conditional loads and
  argument setup differently. The nonmatching candidate is omitted.

Hard list for M1-T1024: `func_02067ef4`; a human can create a public scratch
with `tools/decompme.py`. The Nintendo DS delink continues to supply this
function; no assembly stubs or configuration edits were added. No runtime tests
were added because the card waives them; original-object comparison is the
acceptance oracle. No module boundaries changed.

Validation: `match_gate.py` builds successfully and reports all 53 C definitions
in this TU at 100%, including both new targets. `anticheat.py` passes, all nine
unit tests pass, and `checksum.py` confirms all configured artifacts are
byte-identical. The hard-list target is not claimed as matched C.
