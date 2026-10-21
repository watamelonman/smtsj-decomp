# src/game/unit_0205b82c.c

All three functions match at 100% (objdiff). Names are neutral/hedged (see docs/naming.md).

- `Unk05b82c_Unk_05b82c(int id)`: fetches the descriptor for `id` via func_0205ad9c and passes it to
  `Unk05b82c_CreateEntry`. Called with ids from CampStatus and unit_02065e88 (0xbc..0xbe).
- `Unk05b82c_CreateEntry(Unk05b82cDesc *desc)`: calls `Unk05b82c_CreateNamedEntry` with no explicit
  name, then func_0205b900 and `Unk05ae50_Unk_05af3c(desc)`; returns the new entry.
- `Unk05b82c_CreateNamedEntry(Unk05b82cDesc *desc, int, const char *name)`: allocates an entry
  (func_0205adb4, fatal via func_02007e94 on NULL), stores it in `desc->entry` and copies a 32-byte
  name into it: the base name of `desc->path` (after the last '/'), else `name`, else "no_name".

## Hard list
None.
