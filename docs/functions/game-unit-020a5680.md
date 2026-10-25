# game/unit_020a5680 — M1-T549

All eight target functions match at 100% with mwccarm 2.0/sp1p5 and the
repository compiler flags. Evidence below is from the delinked ARM object;
No domain-specific meaning is inferred for unknown fields.

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

## M1-T550

All eight additional targets match at 100% with the repository compiler flags.
Names remain neutral because instruction evidence does not establish domain meaning.

| Function | Evidence and contract |
| --- | --- |
| `func_020a5680` | Scans the owner's 0x220-byte entries for the first unsigned ID at +0x0c; returns a borrowed pointer or NULL. Owner must exist. |
| `func_020a56cc` | Same scan against the signed word at +0x14. Count is read at +0xcc0 on each iteration, as in the original loads. |
| `Unk0a5680_Unk_0a572c` | Signed selector +0x12 equal to -1 copies 512 bytes from pointer +0x1c to embedded +0x20; otherwise calls 0206f24c with size 1 shifted by selector+13. Control is forwarded in r3 on both paths; buffers and shift range must be valid. |
| `Unk0a5680_Unk_0a5778` | Uses entry ID through 02044ec4/0204a244 to index signed-byte table 0213c3d4. Refreshes +0x12 and calls 0a572c with 4096 when changed or forced. Returns 0/1. |
| `func_020a59c4` | Stores the incoming word at entry[count]+0 and increments the global owner's count. Caller must ensure available capacity. The owner pointer is reloaded after the store. |
| `Unk0a5680_Unk_0a5c14` | Forwards incoming r0 to 020a1854, then its result and the saved second/third arguments to 020a59f4. Returns whether the resulting entry is non-NULL. |
| `func_020a609c` | Iterates the table, resolves entry+8 via 020616c0, and calls Unk065e88_SetUnkField20 for non-NULL results with float 1.0 or 0.0 according to the input flag. The initial count comes from the initial owner; subsequent count reads reload the global owner. |
| `Unk0a5680_Unk_0a611c` | Resolves the incoming ID; if present, passes resolved word +0 to 0205ca88 and writes its result minus one with 0205c41c, then clears byte +0x38. |

The owner view contains six entries because 6 * 0x220 == 0xcc0; callers remain
responsible for count validity. Volatile count preserves the original repeated
loads. These views are private to the TU; no module boundary changes.
Hard list for M1-T550: none.
