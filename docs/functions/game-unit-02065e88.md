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

## Remaining functions
- `Unk065e88_Unk_06644c`: decompiler-derived
- `Unk065e88_Unk_065e88`: decompiler-derived
- `Unk065e88_Unk_066258`: decompiler-derived
- `Unk065e88_Unk_067d30`: decompiler-derived

## Not done in M1-T1019
- `Unk065e88_GetTableCount`
- `Unk065e88_GetTableEntry`
- `Unk065e88_SetMode`
- `Unk065e88_Unk_068564`
- `Unk065e88_Unk_065f30`: decompiler-derived

## Not done in M1-T1020
- `Unk065e88_Unk_066078`
- `Unk065e88_Unk_06646c`
- `Unk065e88_Unk_065ec0`
- `Unk065e88_Unk_0672fc`
- `func_02067418`
- `func_020684c0`
- `func_02066c94`

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
- `Unk065e88_GetTableCount`: hand-matched
- `Unk065e88_GetTableEntry`: hand-matched
- `Unk065e88_SetMode`: hand-matched
- `Unk065e88_Unk_068564`: hand-matched
- `Unk065e88_Unk_065ec0`: hand-matched
- `Unk065e88_Unk_066078`: hand-matched
- `Unk065e88_Unk_06646c`: hand-matched
- `Unk065e88_Unk_0672fc`: hand-matched
