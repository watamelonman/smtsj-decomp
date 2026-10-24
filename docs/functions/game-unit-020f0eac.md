# game/unit_020f0eac

All eight M1-T191 functions match at 100% objdiff. Evidence below is from
ARM instructions in `extract/arm9/arm9.bin` at the listed entry addresses.
The context and records are borrowed; these functions do not allocate or free them.
Names are retained because the higher-level domain meaning is not established.

| Function | Observed contract and evidence |
| --- | --- |
| `Unk0f0eac_Unk_0f0eac` | At 0x020f0eac, captures `data_02176dfc`, runs the setup calls, initializes the embedded +0x50 object when the query returns zero, conditionally runs two more calls, and issues `(field40, 0, 2)`. |
| `Unk0f0eac_Unk_0f0f08` | At 0x020f0f08, queries the supplied object with `Unk0f8448_GetUnkField10` and forwards that result alongside the context's pointer at +0x4c. The object must satisfy that query's contract. |
| `Unk0f0eac_Unk_0f0f2c` | At 0x020f0f2c, issues `(field40, 0, 7)` followed by `(field40, 34)`; both calls use the captured context. |
| `func_020f0f5c` | At 0x020f0f5c, dispatches field-10 values 0..4 to operation values 4, 5, 6, 7, 8. Case 3 instead uses 13 when the query for 0x703 returns zero. Other values produce no operation. |
| `Unk0f0eac_Compare` | At 0x020f0fe0, unsigned byte loads at +4 are subtracted; on equality unsigned halfwords at +0 are subtracted. Returns a signed comparator result. |
| `Unk0f0eac_Unk_0f1000` | At 0x020f1000, subtracts unsigned halfwords at +2, breaking ties with unsigned halfwords at +0. Returns a signed comparator result. |
| `func_020f1020` | At 0x020f1020, resolves both +0 ids, queries both resolved objects, and orders nonzero query results before zero results. Ties compare unsigned +4 bytes then +0 halfwords. |
| `func_020f10a4` | At 0x020f10a4, uses the same id-query priority, then compares unsigned +2 halfwords and finally +0 halfwords. |

Comparator inputs must point to readable records containing the stated fields;
id-based comparators additionally require ids accepted by the resolver/query chain.
The local context view exposes only observed offsets and does not claim the full
size of the embedded +0x50 object.

Validation: match gate reports 100% for each entry; anticheat and all nine tool
unit tests pass; checksum reports all artifacts byte-identical to the original.
No new tests are required by this matching card. Hard list: none.
