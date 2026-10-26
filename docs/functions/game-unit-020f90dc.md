# game/unit_020f90dc

M1-T751 implements the following ARM functions. Names remain neutral where the
observed field accesses do not establish a gameplay purpose. Local structures
model only the offsets used here; the entry descriptor stride is 24 bytes.

| Function | Observed behavior / evidence |
| --- | --- |
| `Unk0f90dc_Unk_0f90dc` | Compares a signed area halfword (30 for current area, 32 for an explicit area) against record byte 34. |
| `Unk0f90dc_Unk_0f9128` | Comparator subtracts byte 1 of two indirectly referenced entries. |
| `func_020f9140` | Registers six descriptors from `data_02150f38`, creates two shared handles and groups of five and ten handles. |
| `func_020f91fc` | Releases and clears both groups and shared handles, makes six cleanup calls, then releases fields 0x100 and 0x104. |
| `func_020f92bc` | Adds an ID to the halfword list at 0xf8 only if absent and below capacity at offset 8. Direct count accesses reproduce register allocation. |
| `func_020f9318` | Reads the selected entry's first byte, forwards it to two consumers and adds it to the unique list. Slot records have a 12-byte stride. |
| `Unk0f90dc_Nop_0f9ce4` | Empty callback, evidenced by the sole return instruction. |
| `Unk0f90dc_Unk_0fa4cc` | Calls group cleanup and frees/clears four owned allocations at 0x50, 0xf8, 0xec and 0xf4. |

## Hard list

M1-T751 has no hard functions.

## M1-T752

The following six ARM implementations match at 100% with mwccarm 2.0/sp1p5.
Existing implementations in the unit remain at 100%. Names retain their configured
neutral symbols because the instructions do not establish a gameplay name.

| Function | Observed behavior / evidence | Status |
| --- | --- | --- |
| `func_020f9374` | Refreshes visible entries using their byte-zero IDs, maps provider states 1/2 to handle modes 2/3, and sets text byte 0x40. The visible range must be nonempty: the original passes the final iteration's provider result onward. | 100% |
| `func_020f9434` | Frees/rebuilds pointer and flag lists from 68-byte records, filters low-seven-bit group values and ID predicates, sorts by byte one, and restores a saved ID. | 100% |
| `func_020f9644` | Initializes handles for callback kind zero, reads optional message words 7/8/4, restores a slot/ID, and handles kind-one closure with a cleared message. | 100% |
| `func_020f9900` | Advances six states, checks handle animations, drains accumulated IDs, and submits completion messages. | 100% |
| `func_020f9b4c` | Dispatches list movement and input masks 0x200/0x100/2/1; forwards the selected ID and initiates closure. | 100% |
| `func_020f9ce8` | Draws slot images 11/12 and 14–16 at 80-pixel intervals, with optional markers on inactive slots. | 100% |
| `func_020f9efc` | Draws transition/active-list states, status overlays at 13-pixel row intervals, a scrollbar based on sprite 44, and per-row text bounds. | Delinked; hard |

### M1-T752 hard list

- `func_020f9efc` (1488 bytes): a complete C reconstruction reached 99.46%.
  Instruction comparison showed remaining register allocation differences in the
  active-list path: first visible index, entry ID, scrollbar height/size, and
  later text iteration. Tried separate/shared loop indices, local scopes,
  signed/unsigned ID temporaries, and shared status/scrollbar temporaries.
  Moving the image default assignment after the status-provider call improved
  the initial 97.55% reconstruction to 99.41%; sharing the initial loop index
  with the later total count reached 99.46%. No unmatched definition is retained
  in production C. This function still links from the original delinked object;
  no assembly inclusion is needed in this DS pipeline. A human can open a
  scratch with `tools/decompme.py` for the remaining allocation work.
