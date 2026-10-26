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

## M1-T526 — verified matches

All eight requested functions report 100% in objdiff. Parameters carry words or
boolean flags; singleton field views remain borrowed. Evidence below comes from
the original ARM instructions at the listed entry addresses.

| Function | Evidence and contract |
| --- | --- |
| `Unk0fc584_IsBelow64` | 020fc6e4 returns false without a singleton, otherwise compares signed +0x0c against 64. The load and signed comparison support the existing descriptive name. |
| `Unk0fc584_IsFieldCZero` | 020fc70c returns false without a singleton, otherwise tests +0x0c for zero, supporting the field-based name. |
| `Unk0fc584_Unk_0fc824` | 020fc824 requires IsBelow64, clears +0x28, then copies +0x24 into +0x20. |
| `Unk0fc584_Unk_0fc86c` | 020fc86c requires a singleton and nonzero +0x30 and +0x2c; forwards +0x2c to 020fc734. It does not clear either field. |
| `Unk0fc584_Unk_0fc674` | 020fc674 creates through 020fc8bc with the supplied word only when the singleton is absent, then publishes its returned address. |
| `Unk0fc584_SetDir` | 020fc6b8 copies +0x1c into +0x14 for a nonzero flag and negates it for zero; absent singleton does nothing. This sign selection supports the existing direction name without assigning further meaning to the fields. |
| `Unk0fc584_Unk_0fc7f4` | 020fc7f4 returns false unless IsBelow64; otherwise returns whether +0x20 and +0x24 differ. |
| `Unk0fc584_Unk_0fc7b8` | 020fc7b8 requires IsBelow64. Kind +0x00 equal to one dispatches through 020fc84c and 020fc86c; other kinds pass the supplied word directly to 020fc734. |

The original-object comparison is the acceptance test; this card requires no new
unit tests. The unit continues linking from the delinked object pending human
completion marking.

### Hard list for M1-T526

None. All eight requested functions match.

## M1-T527 — verified matches

All eight requested functions report 100% in objdiff. Evidence is the original
ARM instruction flow at the entry addresses. State and panel pointers are borrowed;
020fc8bc returns the allocator-owned address using the existing word-address ABI.

| Function | Evidence and contract |
| --- | --- |
| `func_020fc584` | Sets context +4 to zero for unsigned kind <=1, otherwise two; calls 020a4e48(0), then forwards all three input words to 020a4eb0. Absent context does nothing. |
| `Unk0fc584_LoadMoneyWindow` | 020fc9ac selects resource 0xda and cave_moneywindow for zero kind, or resource 0x59 and battle_money otherwise. The layout strings support the existing name. Stores the returned handle at +8. |
| `func_020fcf5c` | Clamps signed state +0x20 to 0..99999999 and forwards it with format data_021510a0 and the three supplied output words to 020a9fd8. |
| `Unk0fc584_Unk_0fc9fc` | For either kind, releases a nonzero +8 handle through 0205ddb4, clears it, calls 0205bb68, and clears the singleton. The explicit handle argument preserves the original r0 flow. |
| `func_020fc5d4` | With a context, sets +0x28b8 to one, writes 189 and byte five at panel +0x2c/+0x37, then forwards the panel and supplied word to 0205fd10. Repeated context loads follow the original instructions. |
| `func_020fc944` | Initializes the 64-byte state. Kind zero selects +0x0c/+0x18=64 and +0x1c=-6; other kinds select 97 and -16. Leaves +0x28/+0x34 untouched as in the original. |
| `func_020fc734` | Requires IsBelow64; synchronizes +0x24 with +0x20, stores signed input/60 at +0x28 with minimum magnitude one for nonzero input, calls 020a0da4(12), adds the input to +0x24 and sets +0x3c=3. |
| `func_020fc8bc` | Allocates 64 bytes through 020611dc with callbacks 020fca5c, kind-selected 020fcc10/020fcd18, and 020fc9fc. Returns zero on allocation failure; otherwise initializes state and loads the money-window layout. |

The original-object comparison supplies the acceptance test; the card requires no
new unit tests. This unit continues linking from the delinked original pending a
human completion marking. No module boundary changes are introduced.

### Hard list for M1-T527

None. All eight requested functions match.

## M1-T528 — verified matches

All three requested functions match the original ARM instructions and relocations.
The state is borrowed and remains 64 bytes. The +0x34 word is a float; +4 and
+0x18 use signed comparisons as evidenced by 020fca5c.

| Function | Evidence and contract |
| --- | --- |
| `func_020fca5c` | Wraps the frame count at 65535, advances signed +0x0c toward zero or +0x18, and computes floating opacity at +0x34. Synchronizes settled +0x20/+0x24 from work-area +0x344; otherwise advances by +0x28, emits helper 12 every six frames, clamps through 020fc824, and handles the countdown/input completion. |
| `func_020fcc10` | Requires IsBelow64, draws cells 0 and 2 with state opacity, and draws cell 1 and the formatted value only at opacity 1.0. Drawing setup/cleanup follows the original call sequence. |
| `func_020fcd18` | Requires IsBelow64, configures drawing and draws cell 0. At opacity 1.0, clamps the displayed value to 0..99999999, draws resource 0x611b twice, and selects formats 02151088/94/98/9c using +0x30 and signed +0x2c. Local scopes preserve the original register lifetimes. |

The formatted-output helper is variadic: the 02151088 format call passes no
numeric argument in the original. No ownership or module boundary changes occur.
The unit continues linking from the delink until a human marks it complete.
The card requires no new tests; original-object comparison is the acceptance test.

### Hard list for M1-T528

None. All three requested functions match.
