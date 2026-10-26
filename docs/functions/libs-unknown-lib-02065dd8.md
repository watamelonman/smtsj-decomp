# libs/unknown/lib_02065dd8

All three functions match the original ARM instructions, including relocations.
Existing neutral symbols are retained because application-level meanings are not established.
The TU remains delink-backed until a human marks it complete.

## Source investigation

Searched public web indexes for the address and NitroSDK source reconstructions,
including pret/pokeplatinum. No corresponding implementation was identified.
The singleton access through `func_02063a50` (global `data_0216b9a8` +4), and calls
into game units at 0x020bab80 and 0x020a0da4, suggest game-specific code despite
the library path. No SDK identity is claimed.

## func_02065dd8 — 68 bytes

Returns without effect if the singleton is absent. Otherwise sets its signed
fields +8 and +12 to 5 and 10, then calls `Unk0a0ce4_Unk_0a0da4` with 2 when
`func_020bab80` is nonzero, or 1 otherwise. Evidence: stores at 0x02065dec and
0x02065df4, followed by the conditional call paths. No arguments or return value.

## func_02065e1c — 12 bytes

No-argument tail wrapper returning the signed result of `func_020babdc`.
Evidence: literal at 0x02065e24 identifies the interworking target; that target
loads its result from its own singleton +8. No extra interpretation is assigned.

## func_02065e28 — 96 bytes

Returns 1 only if the singleton exists, its +0x18 field is nonzero, its +0x24
field is zero, and its child pointer at +0 points to a structure whose signed
+0x10 field is 2 or 3. Returns 0 otherwise. The child must be valid when the
preceding guards pass. Evidence: loads and branches at 0x02065e30–0x02065e84.
A switch preserves the original paired equality comparisons; an OR expression
instead compiled to a range check. The structures expose only observed fields.

## Hard list

None.
