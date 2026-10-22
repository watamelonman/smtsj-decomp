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

## Not done in M1-T1021
- `func_02067370`
- `func_02067c88`
- `func_020685b0`
- `func_02068658`
- `func_02065fc0`
- `func_02067b28`
- `func_02067bd8`
- `func_020674a4`

## Not done in M1-T1022
- `func_02067564`
- `func_020662d4`
- `func_02068bf8`
- `func_02067780`
- `func_020666bc`
- `func_02067888`
- `func_02067634`
- `func_02066d30`
