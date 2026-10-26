# game/unit_0210947c

All eight functions match the delinked ARM original at 100%. Names follow the
existing symbol table; no UI purpose is inferred from unknown resource IDs.
Private layouts describe only fields supported by loads, stores and the 0x48-byte
snapshot copy. Work allocation is 0xb4 bytes. Resource handles remain opaque.

| Function | Contract and evidence |
| --- | --- |
| `func_0210947c` | Advances states 0 and 1 using frame counters at +0x54/+0x58; interpolates +0x68 from +0x50 to zero, then updates the resource at +0x8c and three at +0x90. Unsigned duration comparisons preserve the original ARM conditions. |
| `func_02109538` | Draws the work's resources using coordinates +0x68/+0x6c. Snapshot bytes select layers, color and icons. State 1 fades layer 13 using signed elapsed frames divided by unsigned duration. The first background resource index is 10, as established by the live r2 value at its call. |
| `func_02109978` | Releases the optional +0x8c and +0x90 resources, releases +0xa8, then releases and clears the three +0x9c handles. Null checks follow the original exactly. |
| `func_021099fc` | Copies a 0x48-byte snapshot into +0x04, splits unsigned +0x38 into hours/minutes/seconds using base 60, refreshes text widths and reloads up to three resources from halfword lookup IDs. Local buffers are 40 and 64 bytes, matching the original stack layout. |
| `func_02109c04` | Creates a 0xb4-byte callback work area, installs four supplied resource handles, allocates owned resources and refreshes the snapshot. Mode zero starts at (-244, 0) over eight frames; other modes start at (-360, 76) over twelve. |
| `Unk10947c_SetUnkField5c` | Stores the supplied 32-bit value at +0x5c; name is supported by the single original STR. |
| `Unk10947c_Thunk_021099fc` | Forwards the work pointer unchanged; original branches through a literal containing `func_021099fc`. |
| `Unk10947c_IsUnk4cAtLeast2` | Returns whether the signed state at +0x4c is at least two; supported by CMP #2 and MOVGE/MOVLT. |

## Validation

Direct objdiff comparison reports 100% for each function. The translation unit
remains linked from the delink pending the human completion flag, per task policy.
No new tests are required by this card; instruction matching checks these bodies.

## Hard list

None.
