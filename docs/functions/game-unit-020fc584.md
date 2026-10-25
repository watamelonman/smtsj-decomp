# src/game/unit_020fc584.c

## M1-T525 — verified matches

All eight functions below report 100% in objdiff. Evidence is the original ARM
instruction flow at each entry address; field names describe observed offsets,
without assigning an unproven subsystem meaning. Singleton addresses and field
views are borrowed, with no ownership transfer.

| Function | Evidence and contract |
| --- | --- |
| `Unk0fc584_Get_data_02176e14` | 020fc584 loads the word at `data_02176e14`; returns the singleton address, possibly zero. The existing integer-address ABI is retained for other functions in this TU. |
| `Unk0fc584_Unk_0fcfd0` | 020fcfd0 calls 02057eb8 with -1, then 020572d8 with no arguments. |
| `Unk0fc584_Unk_0fc6a0` | 020fc6a0 obtains the singleton and calls 02061424 only when nonzero. The pointer remains in r0 at the call, so it is an explicit typed argument in C. |
| `Unk0fc584_Unk_0fc894` | 020fc894 returns the singleton's first word, or zero if absent. |
| `Unk0fc584_SetField28bc` | 020fc638 conditionally adds 0x2000 and stores at +0x8bc: writes the context word at +0x28bc, doing nothing if absent. This access supports the existing field-based name. |
| `Unk0fc584_GetField28bc` | 020fc654 uses the same +0x2000/+0x8bc access: returns the context word at +0x28bc, or zero if absent. |
| `Unk0fc584_Unk_0fc84c` | 020fc84c stores the input word at singleton +0x2c and one at +0x30, if present. No range restriction is evident. |
| `Unk0fc584_Unk_0fcfb0` | 020fcfb0 calls 02057e18(31), 02057ddc(0xffffffff), then 02057524(4), in that order. |

No new tests are required by this card; the original object comparison validates
instruction selection and relocations. The full image is still linked from the
delinked unit until a human marks it complete.

### Hard list for M1-T525

None. All eight requested functions match.

### Outside M1-T525

- `Unk0fc584_Unk_0fc824`: existing decompiler-derived body.
- `Unk0fc584_Unk_0fc674`: existing decompiler-derived body.

## Not done in M1-T526
- `Unk0fc584_IsBelow64`
- `Unk0fc584_IsFieldCZero`
- `Unk0fc584_Unk_0fc86c`
- `Unk0fc584_SetDir`
- `Unk0fc584_Unk_0fc7f4`
- `Unk0fc584_Unk_0fc7b8`
- `Unk0fc584_Unk_0fc9fc`: decompiler-derived

## Not done in M1-T527
- `func_020fc584`
- `Unk0fc584_LoadMoneyWindow`
- `func_020fcf5c`
- `func_020fc5d4`
- `func_020fc944`
- `func_020fc734`
- `func_020fc8bc`

## Not done in M1-T528
- `func_020fcc10`
- `func_020fca5c`
- `func_020fcd18`
- `Unk0fc584_LoadMoneyWindow`: decompiler-derived (plain cleanup)
- `Unk0fc584_Unk_0fc7b8`: decompiler-derived (plain+fix cleanup)
- `Unk0fc584_SetDir`: hand-matched
- `Unk0fc584_IsBelow64`: hand-matched
- `Unk0fc584_IsFieldCZero`: hand-matched
- `Unk0fc584_Unk_0fc7f4`: hand-matched
- `Unk0fc584_Unk_0fc86c`: hand-matched
