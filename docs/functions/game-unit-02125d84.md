# game/unit_02125d84 — M1-T309

All eight requested functions match at 100%. Names remain neutral because the
assembly establishes storage operations but does not establish original API names.
Offsets below are from the delinked ARM instructions. Owner and record types are
partial views, not claims about the original type names.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_02125d84` | Returns a signed extent from `data_0213ce10`, indexed by shape bits 14–15 and 30–31. Caller `func_02125fa8` uses it as horizontal extent. The packed index must address a valid table entry. |
| `func_02125da8` | Uses the same packed index with `data_0213ce1c`; lookup caller uses the result as vertical extent. Returns the signed byte widened to int. |
| `func_02125dcc` | M1-T310. Initializer: stores count (stack arg 2), resource +4, format +8, r2 at +12; allocates `count*16` records via `func_02052fe0` and copies shape/x/y from 8-byte source records (stack arg 1). Sums `(scale*w*h)>>1` (scale 2 for format 4, else 1) into +24, allocates the buffer at +20, then gives each record its slice at +12 and stores `func_02056c54(resource, slice, format, w, h)` at +8. The zero stored to +24 must come from the loop counter for the store order to match. |
| `Unk125d84_Unk_125f0c` | Calls `func_02056cac` with owner +4 once per count, reloading count after calls; frees buffer at +20 and records at +16 and clears both pointers. Owner must be valid. The repeated identical resource argument is preserved. |
| `func_02125f60` | Fills buffer +20 for byte count +24 via `func_02008644`. Format +8 equal to 4 repeats the low byte; other formats repeat the low nibble across a halfword. |
| `func_02125fa8` | Returns the first 16-byte record containing unsigned x/y, or null. Record coordinates at +4/+6 are inclusive lower bounds; table-derived upper bounds are exclusive. Owner count and record storage must agree. |
| `func_02126038` | Replaces one nibble in an 8×8 tile of 32 bytes. Coordinates wrap modulo eight. Halfword index is `2*(y&7) + ((x&4)!=0)`; shift is `4*(x&3)`. Caller must supply a four-bit value and writable tile. |
| `func_0212608c` | Writes into a byte slot in an 8×8 tile of 64 bytes. Coordinates wrap modulo eight; halfword index is `4*(y&7)+((x&7)>>1)`. The original mask is **15**, shifted by `8*(x&1)`, not 255. Preserve this behavior; values are truncated after shifting to 16 bits. |
| `func_021260d8` | Looks up the containing record, returns on miss, subtracts its origin, and selects an 8×8 tile from pixels +12 using the horizontal extent. Format 4 uses 64-byte tiles and `func_0212608c`; other formats use 32-byte tiles and `func_02126038`. Preserves the unused vertical-extent call and rounds byte offset down to even. |

## Hard list

None. `func_02125dcc` was matched in M1-T310. This TU remains linked from the delink
pending human completion.
