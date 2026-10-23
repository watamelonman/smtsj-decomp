# game/unit_020bb908

All eight functions match the delinked ARM object at 100% with mwccarm
2.0/sp1p5 and the repository build flags. Each takes no C parameters and
returns 1. Values are published through `Unk03aae8_Unk_03acf4`; arguments
come from `func_0203ac00`. Names remain neutral because the field meanings
are not established. Evidence below refers to the original instruction addresses.

| Function | Observed behavior and evidence |
| --- | --- |
| `Unk0bb908_Unk_0bb908` | Signed argument 0 below 15 calls `func_020bc0b4`, selects source 0 through `Unk0bac80_Unk_0badec`, obtains an index through `func_02050074(0, func_0204fe18() - 1)`, and stores `func_0204fde0(source) + index * 36` at work +0x68. Publishes the index, or zero when the argument is >=15. CMP at 0x020bb914, MLA/STR at 0x020bb954/0x020bb958. |
| `Unk0bb908_Unk_0bb978` | Same selection/store/result sequence with source selector 1 (MOV at 0x020bb990); MLA/STR at 0x020bb9c4/0x020bb9c8. |
| `Unk0bb908_Unk_0bb9e8` | Publishes the selected entry's unsigned halfword at +4; null publishes zero. LDRH at 0x020bb9f8. |
| `Unk0bb908_Unk_0bba14` | Publishes the selected entry's unsigned halfword at +0; null publishes zero. LDRH at 0x020bba24. |
| `Unk0bb908_Unk_0bba40` | Publishes the selected entry's unsigned halfword at +2; null publishes zero. LDRH at 0x020bba50. |
| `Unk0bb908_Unk_0bba6c` | Publishes the signed halfword at entry +6 + index * 10. Signed indices >=3 become zero; negative indices remain unchanged. Null publishes zero. CMP/MOVGE at 0x020bba80/0x020bba84; LDRSH at 0x020bba98. |
| `Unk0bb908_Unk_0bbab4` | Same index/null rules, unsigned halfword at +8 + index * 10. CMP/MOVGE at 0x020bbac8/0x020bbacc; LDRH at 0x020bbae0. |
| `Unk0bb908_Unk_0bbafc` | Same index/null rules, unsigned halfword at +10 + index * 10. CMP/MOVGE at 0x020bbb10/0x020bbb14; LDRH at 0x020bbb28. |

Typed layouts (local to the TU, not yet shared): `Unk0bb908Entry` is the
36-byte entry (`u16 unk_0000/0002/0004` plus `Unk0bb908Slot unk_0006[3]`,
each slot 10 bytes: `s16 unk_00, u16 unk_02, u16 unk_04`, 4 bytes padding;
the array size 3 is inferred from the index clamp). `Unk0bac80Work` only
declares `unk_0068`, the selected entry pointer.

`Unk0bac80_Unk_0badc0` returns the work pointer; its `unk_0068` field is
returned by `Unk0bac80_Unk_0bae08` (see that unit's loads). The source
selector's result is kept as an opaque 32-bit handle because the original
caller explicitly saves r0 and passes it to `func_0204fde0`; no stronger
return contract or field semantics are inferred from the neighbouring C.
The entry pointer must cover the accessed offsets and caller-supplied index;
the original does not guard negative indices.

## Hard list

None.
