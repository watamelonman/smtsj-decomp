# game/unit_020e675c

## M1-T225 — all eight functions match at 100%

Evidence is the delinked ARM instructions at each function's address. Neutral
symbols are retained because table contents do not establish domain names.
The shared selector `func_020445d0` returns a borrowed resource handle;
`func_0204fde0(handle)` supplies its base and `func_0204fe18(handle)` its count.
`func_02011810` takes key, base, count, stride, and comparator (the same search
interface used in `game/unit_020a1418`).

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0e675c_Unk_0e675c` | Compare leading unsigned bytes, returning left minus right. Two `ldrb` instructions followed by `sub`; used by `func_020e679c`. Both pointers must be readable. |
| `Unk0e675c_Unk_0e676c` | Compare leading unsigned halfwords. Two `ldrh` instructions followed by `sub`; used by `func_020e67f4`. Both pointers must be halfword aligned and readable. |
| `Unk0e675c_Unk_0e677c` | Same halfword ordering, used for six-byte records by `func_020e6874`. Requires readable, aligned keys. |
| `Unk0e675c_Unk_0e678c` | Same halfword ordering, used for twelve-byte records by `func_020e68f0`. Requires readable, aligned keys. |
| `func_020e679c` | Search group 0x21/table 0 with a 16-byte key buffer and stride 0x10. `strb` truncates the supplied id to eight bits; only that byte is initialized or compared. Returns a borrowed matching record or NULL. |
| `func_020e67f4` | Search group 0x21/table 1 with a 52-byte aligned key buffer and stride 0x34. `strh` truncates the id to sixteen bits; remaining key bytes are not examined by the comparator. Returns a borrowed matching record or NULL. |
| `Unk0e675c_Unk_0e684c` | Select group 0x21/table 2 and return its base plus four times the unsigned index, clamped to five (`cmp`, `movhi`, shifted `add`). Result is borrowed. |
| `Unk0e675c_Unk_0e68cc` | Select group 0x17/table 2, invoke its base accessor, then return its count. The original leaves the result of `func_0204fe18` in r0. |

Validation: all eight entries in the generated objdiff report are 100%; the
full checksum gate verifies the original image while this TU remains delinked.
No new tests are required by this card; the binary match is the behavior oracle.

## M1-T226 — remaining three functions match at 100%

Group 0x17 uses the same selector/base/count/search interface as above.
`func_020a1428` is the entry lookup also called from `BattleShowingTask.c` and
`CampStatus.c`; only the six halfwords at +0x2e that this TU reads are typed.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020e6874` | Search group 0x17/table 2 with a 6-byte key (`strh` of the id) and stride 6, comparator `Unk0e675c_Unk_0e677c`. Returns a borrowed record or NULL. |
| `func_020e68f0` | Search group 0x17/table 1 with a 12-byte key and stride 12, comparator `Unk0e675c_Unk_0e678c`. Returns a borrowed record or NULL. |
| `func_020e6948` | Look up `func_020a1428(owner)`, then repeat the `func_020e6874` search inline (no call in the original; a call did not inline under mwcc). Return 1 if the record id equals any of the entry's six ids at +0x2e (`ldrh [r1, #46]` loop to 6), or if bit pair 0-1, 2-3 or 6-7 of the record byte at +4 is nonzero (`lsl`/`lsrs #30` tests); else 0. The search result is not NULL-checked. |

Validation: `tools/match_gate.py` reports all 11 C functions in this TU at
100%, and `tools/checksum.py` reports all artifacts byte-identical.
