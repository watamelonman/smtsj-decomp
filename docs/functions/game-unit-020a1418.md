# src/game/unit_020a1418.c

Resource 19 is a table of 100-byte records (obtained with `func_020445d0(19, 0)` /
`func_0204fde0` / `func_0204fe18`). `Unit020a1418Entry` documents the fields these
functions use: id at +0, group kind at +2, a flag bit at +8 and the packed
`active`/`value` halfword at +0x28.

- `Unk0a1418_Unk_0a1418` (16 B): ordering callback passed to `func_02011810`; compares
  the two records' u16 ids. The name stays neutral because only the call site (the
  binary search below) identifies its role.
- `func_020a1428` (88 B): binary-searches the resource for a record by u16 id and
  returns it, or the search's NULL result. Callers (e.g. 0x0202e2bc, 0x02046250) pass
  a zero-extended u16 and dereference the returned record.
- `func_020a1480` (96 B): linear scan of the resource for the record whose packed
  +0x28 `value` (bits 1..15) equals the argument; returns the record or NULL.
- `func_020a14e0` (116 B): validity predicate for a record. Ids 0x158 and 0x1d9 are
  always accepted; otherwise the record's kind must match one of the three
  `data_0213c24c` pairs and `func_0209993c` must accept the paired value.
- `func_020a1554` (232 B): collects up to `capacity` record ids of the requested kind
  into `out`, skipping disabled records, ids rejected by `Unk065e88_Unk_068554`, and
  the two special ids; writes a 0 terminator when room remains. Returns 1 when the
  kind appears in `data_0213c24c`, else 0.

`data_0213c24c` and `data_0213c24e` are two u16 views of the same three {kind, value}
records: the first names the record start, the second an address two bytes later.
`func_020a14e0` uses both names, `func_020a1554` uses only `data_0213c24c`.

## Hard list

None: all five functions match at 100% in objdiff.
