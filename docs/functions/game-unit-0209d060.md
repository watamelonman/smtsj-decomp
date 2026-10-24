# game/unit_0209d060

M1-T306: all eight requested ARM functions match at 100% in objdiff.
Evidence below refers to original ARM9 instruction addresses in the delinked
object. The singleton at `data_02176274` points to a four-byte work block;
its sole word's wider meaning is unknown. Names remain unchanged.

| Function | Evidence and contract |
| --- | --- |
| `Unk09d060_Unk_09d060` | 0209d060–0209d068 loads, increments, and stores the work word. Requires a valid work pointer; unsigned arithmetic wraps. Installed as the update callback by 0209d084. |
| `Unk09d060_Clear_data_02176274` | 0209d070–0209d078 stores zero in the singleton slot. Installed as the destruction callback; does not itself free memory. |
| `func_0209d084` | 0209d084–0209d108 returns if already allocated; otherwise calls 020611dc with update callback, two zero arguments, destruction callback, size 4, alignment 4, 65535, and 1. For a nonnull parent it passes parent then new work to 020616ec, then calls 020d1cb4. The opaque parent uses the same pointer contract as 0209d170; no allocation failure handling appears in the original. |
| `Unk09d060_Unk_09d10c` | 0209d10c–0209d138 calls 02061424 with the existing singleton, clears its slot, then always calls Unk0d1c98_Release. The original therefore supplies the work pointer omitted by the earlier unprototyped declaration. |
| `Unk09d060_Unk_09d13c` | 0209d13c–0209d16c returns zero when ScanVisor_Unk_0a2980 returns zero; otherwise returns whether 02061750(singleton) is zero. It does not independently check singleton validity. |
| `Unk09d060_Unk_09d170` | 0209d170–0209d190 passes singleton and the opaque child pointer to 020616ec only when the singleton exists. The call order complements the parent link in 0209d084. |
| `Unk09d060_GetCtxUnk00` | 0209d194–0209d1ac loads the singleton's first word when present, otherwise returns zero. |
| `Unk09d060_Unk_09d1b0` | 0209d1b0–0209d1c8 conditionally stores zero in the singleton's first word. |

The callback and pointer prototypes preserve the original argument registers;
opaque link endpoints do not imply knowledge of other work-block layouts.
No module boundary changed. The TU remains linked from the delink until a human
marks it complete.

## Hard list / outside this card

No M1-T306 functions remain unmatched. `func_0209d1cc` belongs to M1-T307,
remains absent from this C file, and continues to link from the delinked object.
