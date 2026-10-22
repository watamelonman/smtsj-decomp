# src/game/unit_020392f8.c

Status: all five functions match the delinked original at 100% in objdiff.

The unit owns the YDM dungeon resource loader and the accessors for the sections it
returns. Path formats were read from the retail ARM9 image at `data_021420d8`,
`data_021420fc`, `data_02142120` and `data_02142148`:

| Address | String |
|---|---|
| `0x021420d8` | `Data/Dungeon/Ydm/%s_%02d_ydm.cmp` |
| `0x021420fc` | `Data/Dungeon/Ydm/%s_dk%02d_ydm.cmp` |
| `0x02142120` | `Data/Dungeon/Ydm/Map_dk_dummy_ydm.cmp` |
| `0x02142148` | `Data/Dungeon/Ydm/%s_dm%02d_%02d_ydm.cmp` |

## Functions

- `func_020392f8(YdmFile *ydm, const char *name, int floor, int extra, int dark, int kind)`
  — builds the YDM path selected by `kind`, maps the file, and fills `ydm`'s header and
  four section pointers. `kind == 0` uses the `_ydm` format, `kind == 1` uses `_dk` when
  `dark == 1` and the dummy map otherwise, and `kind == 2` uses the two-index `_dm` format
  with `floor` and `extra`. Returns 1 on success, 0 for a null output or a failed
  existence check/map. Section bases are chained from the header counts at +6/+7/+8 with
  a 4-byte terminator after each section.
- `Unk0392f8_GetEntry36(YdmFile *ydm, u32 i)` — returns the `i`-th 36-byte record in
  section 1 (`ydm->sec1`, header count at +7), or NULL when `i` is out of range.
- `Unk0392f8_GetEntry(YdmFile *ydm, u32 i)` — returns the `i`-th 8-byte record in
  section 2 (`ydm->sec2`, header count at +8), or NULL when `i` is out of range.
- `Unk0392f8_Unk_0394b8(YdmFile *ydm, int x, int y)` — converts grid coordinates to the
  16-bit cell in section 3. The header's +9/+10 bytes are the grid origin and +11/+12
  its width/height; returns NULL for a null object/file or coordinates outside the grid.
- `Unk0392f8_Unk_039454(u32 *arg0)` — releases the mapped file at `*arg0` and clears the
  20-byte `YdmFile` object; a null object is a no-op.

## Hard functions

None. All five functions above match at 100%.
