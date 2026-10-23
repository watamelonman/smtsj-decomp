# game/unit_020f81a4

M1-T217: all eight targets match at 100% in objdiff. Evidence below is
from the ARM instructions in the original image, not inferred domain names.
The local work layout describes only observed fields; callers own its storage.

| Function | Observed behavior and contract |
| --- | --- |
| `Unk0f81a4_Unk_0f81a4` | At 020f81a4, loads +0x84 into argument 2 and tail-calls `func_0204afe0`, retaining the object as argument 1. |
| `Unk0f81a4_Unk_0f81b4` | At 020f81b4, returns whether the signed word at +0x84 differs from -1. |
| `func_020f81cc` | At 020f81cc, stores arguments 7–10 at +0x88 through +0x94, clears +0x98/+0x9c/+0xa0, stores arguments 5–6 at +0x80/+0x84, leaves argument 4 unused, calls Init with arguments 1–3, then clears +0x7c. |
| `Unk0f81a4_Init` | At 020f8224, calls the base initializer with mode 1, initializes the embedded +0x1c block with the object, then calls `func_020f8264`. |
| `Unk0f81a4_SetUnkField98` | At 020f824c, stores the supplied word at +0x98. Purpose remains unknown. |
| `Unk0f81a4_SetUnkField9c` | At 020f8254, stores the supplied callback at +0x9c. Its optional invocation with the object is evidenced at 020f82c8–020f82d8. |
| `Unk0f81a4_SetUnkFielda0` | At 020f825c, stores the supplied word at +0xa0. Purpose remains unknown. |
| `func_020f8264` | Returns immediately if +0x88 is null. Otherwise saves the +8 index base, calls +0x88 with object and base+i for each signed i below the live +0 count, stores results at +0x64+4*i, refreshes the +0x1c block through `func_020bd1a8` with mode 1, then calls non-null +0x9c. The six result words precede +0x7c; callers must supply a count fitting that storage. |

Parameters and callbacks have explicit types. Unknown fields retain neutral names;
the pre-existing `func_` symbol names remain unchanged because symbols are human-owned.
No module boundary changed. Matching the original instructions is the regression
check for this card (`tests_required = false`); no behavioral test harness is added.

## Hard list

None for M1-T217.

## Outside this card

`func_020f82e0` belongs to M1-T218 and remains linked from the delinked object.
