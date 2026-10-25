# src/StaffRoll.c

## M1-T640 — verified 100% objdiff

Names follow the existing symbol map. Neutral names remain where the purpose of
fields or constants is unknown. Evidence below is the original ARM code at each
listed address; record pointers are borrowed and must point to writable storage
for setters, or readable aligned storage for queries.

| Function | Original evidence and contract |
| --- | --- |
| `StaffRoll_Nop_117cf4` | 0x02117CF4: immediate return, no arguments or effects. The Nop name is supported by that instruction. |
| `StaffRoll_Nop_117cf8` | 0x02117CF8: immediate return, no arguments or effects; same evidence for Nop. |
| `StaffRoll_Unk_117cfc` | 0x02117CFC: reads the first halfword and returns it only if it is 0x8082; otherwise zero. Requires a non-null aligned halfword pointer. |
| `StaffRoll_Unk_117d18` | 0x02117D18: passes work +0x304 to `func_0204fed8`, returns zero for null, otherwise calls the preceding marker query. |
| `StaffRoll_Unk_117d38` | 0x02117D38: calls the marker query and maps 0x8082 to 0x739CD6FF, returning -1 otherwise. The meaning of the packed constant is unconfirmed. |
| `StaffRoll_Tick` | 0x02118174: increments unsigned +0xB4, compares against unsigned +0xC4, and on reaching the limit sets +0xAC to 1 and resets +0xB4. This counter advance supports the existing Tick name. |
| `StaffRoll_Unk_11825c` | 0x0211825C: clears record words +4, +8 and +12, preserving +0. Requires at least 16 writable bytes. |
| `func_02118270` | 0x02118270: scans 32 records of stride 16 starting at work +0xF8. Returns the first record whose +4 word is zero, or null when none qualify. Requires readable records through work +0x2F7. |

The search bound and stride come directly from the original loop. The typed slot
view describes only these observed words; its first word has no inferred purpose.
The existing dispatcher now explicitly forwards its work pointer to the typed
`StaffRoll_Tick` parameter, preserving its original call instructions.

Hard list for M1-T640: none. All eight functions match; no scratch is needed.



## Other functions (outside M1-T640)
- `StaffRoll_Unk_1182a4`: decompiler-derived
- `StaffRoll_Unk_1181a0`: decompiler-derived

## Not done in M1-T641
- `StaffRoll_Update`
- `StaffRoll_Unk_118490`
- `func_02118208`
- `func_02118424`
- `func_02118518`
- `func_02117d5c`

## Not done in M1-T643
- `func_021182f0`
- `func_0211882c`
- `func_02117f94`
- `func_02118974`
- `func_0211882c`: hand-written. Parses staff-roll command list and lays out text lines.
- `StaffRoll_Unk_118620`: decompiler-derived (plain cleanup)
- `StaffRoll_Unk_1186cc`: decompiler-derived (plain cleanup)
- `StaffRoll_Unk_118490`: hand-matched
- `StaffRoll_Update`: hand-matched
