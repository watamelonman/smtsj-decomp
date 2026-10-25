# game/unit_020a5680 — M1-T549

All eight target functions match at 100% with mwccarm 2.0/sp1p5 and the
repository compiler flags. Evidence below is from the delinked ARM object;
o domain-specific meaning is inferred for unknown fields.

| Function | Evidence and contract |
| --- | --- |
| `Unk0a5680_Clear_data_02176b14` | At 0x020a5718, writes zero to the global owner slot. Does not free the old owner. |
| `Unk0a5680_Unk_0a5e78` | At 0x020a5e78, doubles the index and performs a signed halfword load from `data_0213c3e0`. Caller must supply a valid table index; bounds are not checked. |
| `Unk0a5680_GetEntryUnk14` | At 0x020a5e48, calls `func_020a5680(id)` and reads the signed word at +0x14, returning -1 for an absent entry. |
| `Unk0a5680_GetEntrySub20` | At 0x020a5e60, returns the borrowed address at entry +0x20, or NULL for an absent entry. Ownership remains with the entry. |
| `Unk0a5680_Unk_0a5fb0` | At 0x020a5fb0, tail-calls `func_020a5e8c` with the global owner. Requires that helper's owner preconditions; does not check NULL. |
| `Unk0a5680_Unk_0a5e28` | At 0x020a5e28, looks up the ID, then passes entry +8 to `func_020616c0`. Returns that helper's borrowed pointer, or NULL when the entry is missing. |
| `Unk0a5680_Unk_0a60fc` | At 0x020a60fc, resolves the ID and tests unsigned byte +0x38. Returns exactly 0 or 1, with 0 for an absent object. |
| `Unk0a5680_Unk_0a6150` | At 0x020a6150, resolves the ID and writes bytes +0x38 and +0x39 to 1 and 0. An absent object is left alone. |

`func_020a5680` compares its sole ID argument against entry +0x0c, scanning
0x220-byte entries. This supports the single-argument declarations of its
wrappers. The existing `Unk0a5680_Unk_0a611c` caller now also forwards its ID
explicitly to preserve the observed incoming-r0 contract with the typed helper.
No module boundary changed. Other existing bodies in this TU are outside this
card and retained.

## Hard list

None for M1-T549. The remaining original functions continue to link from the
delinked TU until a human marks the unit complete.
