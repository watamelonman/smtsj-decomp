# game/unit_02038fbc

Seven functions are implemented in C and match the original object at 100%.
The TU remains linked from its delinked object until a human marks it complete.
Names are retained from the symbol map; the behavior below comes from the original
loads, stores, bounds checks and call sequences. Owner-taking functions share the
`Unk038fbcOwner` layout (header +0, aux +4, grid +8, 32 table pointers +12; 0x8c bytes)
and the partial `Unk038fbcHeader` (origin +8/+9, width/height +10/+11, per-kind counts +12).

| Function | Contract and evidence |
| --- | --- |
| `Unk038fbc_GetNodeUnk08` | Returns the word loaded at node offset +8; null returns zero. The partial node layout records only the observed words. |
| `Unk038fbc_Unk_039138` | Null-safe resource release via `func_020516d0`, followed by clearing 0x8c owner bytes via `func_02008848`. |
| `Unk038fbc_Unk_0391d8` | Returns zero for a missing owner/resource, otherwise multiplies header bytes +10 and +11 using signed-halfword multiplication. These are the dimensions also used by the grid accessor. |
| `Unk038fbc_Unk_038fbc` | Releases a nonnull backing resource, clears eight owner bytes and returns one; missing owner/resource returns zero. |
| `Unk038fbc_GetElement` | Reads the kind count at resource +12+kind, rejects an out-of-range unsigned index, and advances owner table +12+4*kind by index times the kind stride. A valid resource and kind are caller preconditions. |
| `Unk038fbc_Unk_039160` | Subtracts header origin bytes +8/+9 from absolute coordinates, checks dimensions +10/+11 and returns the eight-byte grid record through owner +8; null or out-of-bounds inputs return zero. |
| `Unk038fbc_Unk_039248` | Returns kind strides: 32 for 0; 8 for 2,5,8,9,10; 4 for the other kinds through 12; zero otherwise. |
| `func_02038ff8` | Not implemented in C; remains in the delinked original. Formats a 64-byte path with `data_02142074` or `data_02142090`, checks it via `func_020513d4`, and formats fallback `data_021420b8` if absent. Loads via `func_02051610`, then initializes the owner header, +64 auxiliary section, +132 grid and 32 element pointers. Populated tables skip a four-byte prefix and advance by count times stride. Null owner or failed load returns zero; success returns one. |

## Hard list

- `func_02038ff8` (0x140 bytes): reconstructed the path formatting/fallback,
  byte-array initialization, resource loading and all 32 table fixups. The candidate
  reproduces the control flow and register allocation, but mwccarm 2.0/sp1p5
  combines the auxiliary/grid pointer stores into `stmib`, producing 316 bytes
  instead of 320. Referencing the owner header for the grid assignment instead
  introduces an extra reload and produces 324 bytes. Tried typed owner/serialized
  section layouts, byte/word/integer address expressions and inline section setters;
  these did not resolve the store scheduling difference. Candidate omitted rather
  than accepting a partial match. A human can use `tools/decompme.py` to investigate
  the original separate `str +4; add #132; str +8` sequence.
