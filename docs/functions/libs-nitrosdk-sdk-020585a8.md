# libs/NitroSDK/sdk_020585a8

The task's SDK path is retained. Public-source searches for NitroSDK/NitroSystem
resource-binding and G3X projection helpers did not identify an exact
implementation. The implementation is reconstructed from the delinked ARM
instructions and relocations; the existing neutral linker symbols are kept
because a specific SDK identity is not proven.

The original object is the test oracle (all three functions were initially
absent from C). No new behavioral tests are required by this card. Matching
checks cover instruction selection, field offsets, call targets, branches,
constants and relocation targets.

| Function | Instruction evidence and caller contract |
| --- | --- |
| `func_020585a8` | Initializes the two work state blocks at +0x205c/+0x2084, saves the interrupt state with `func_02007a58`, waits on VCOUNT (0x04000006) for the 191..213 window when `func_02052624()` is below 31, releases the prior source through `func_0202546c`, restores interrupts and reacquires with `func_02025b14`. It then walks the resource dictionary: for each index below the byte count at resource +9 it resolves the entry from the dictionary at +8 (entry offset at +14, stride and record offsets relative to the dictionary) and stores the bound pointer in the 92-byte record at +84 before calling `func_0202172c`. Index 90 raises the SDK check. The work area belongs to the caller and must hold 90 records plus the two state blocks. |
| `func_020586d0` | Saves five integer projection parameters at `data_02168c24`, forwards the first four and the fifth with the fixed 0x1000 scale and the shared state word to `func_02001e48`, then clears flag bits 4 and 6 at `data_02156d28 + 0xfc`. The five integer arguments come from the 02037864 and 020b7738 call sites. |
| `func_02058724` | Copies the two caller-supplied 12-byte axes into the basis workspace at `data_02168c38`, fills the middle axis with the fixed vector at 0x0212e398 (`{0, 0x1000, 0}`), caches the three axes at `data_02156f68/74/80`, builds the 48-byte matrix through `func_0200167c`, clears flag bits 3 and 5..7 at `data_02156d28 + 0xfc`, and copies the matrix to workspace +36. Callers pass two vectors (02037848, 020b773c). |

`data_02168c24` and `data_02168c38` are separate configured BSS symbols; their
layouts are exposed only through the typed views used here. `data_0212e398`
has no configured symbol, so it remains a typed absolute constant pointer.
`data_02156d28` reuses the shared `Unk0222d8State` view, whose flag word is at
byte 252.

## Compiler details

See DEC-033. Walking the three adjacent cached-axis destinations keeps the
original `ldmia`/`stmia` store order; spelling them as three independent
assignments makes mwccarm hoist two literal-pool loads. The linker resolves
both forms to the same bytes.

## Hard list

None. All three functions have C definitions with identical instructions.
