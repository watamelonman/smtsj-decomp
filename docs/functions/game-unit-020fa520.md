# game/unit_020fa520

M1-T239 implements all three ARM functions in readable C. Original symbol names
are retained because the precise subsystem role is not established. The local
work and record types describe only the fields accessed here; opaque subobjects
and unknown fields are not assigned guessed meanings. No module boundary changes.

## `func_020fa520` — 0x020fa520, 92 bytes

Initializes a descriptor with work size 344, kind 1, and six callback addresses.
Leaves offset +8 untouched. The original literal pool identifies callbacks
`func_020f9900`, `func_020f9b4c`, `Unk0f90dc_Nop_0f9ce4`, `func_020f9efc`,
`Unk0f90dc_Unk_0fa4cc`, and `func_020f9644`, in that order. The caller supplies
writable descriptor storage. Status: **100% objdiff**.

## `func_020fa57c` — 0x020fa57c, 348 bytes

Walks the borrowed 68-byte records at work +4 using the unsigned count at +8.
The byte at record +0 is passed to the predicates at 0x020d2b58 and 0x020d2b64.
When the first predicate succeeds, the low seven bits of record +3 select a
category (required range 1..3). Counts that category and sets its flag if the
second predicate succeeds. Allocates 12 bytes per populated category, stores
ascending count/category/flag triples at work +0x50, and writes their count at
+0x54. Allocation and lifetime follow the original: this function does not free
any previous output. The shifts by 25/23 and stride increments by 68/12 provide
direct evidence for these layouts. A distinct final category loop variable
preserves the original register allocation. Status: **100% objdiff**.

## `func_020fa6d8` — 0x020fa6d8, 272 bytes

Initializes caller-provided work storage: invokes `Unk0d297c_LoadMissionLog`,
creates/configures the handles at +0x100/+0x104, obtains records and their count
from resource 28, allocates two bytes per record at +0xf8, and gets resource 29
at +0x0c. Clears +0xfc/+0xec/+0xf4, builds categories through `func_020fa57c`,
then initializes the subobjects at +0x10/+0x2c with the resulting group count.
Finally clears +0x14c. Resource identifiers and call order are observed directly
in the original instructions; the remaining field meanings stay neutral.
Status: **100% objdiff**.

## Validation

Instruction/relocation comparison against the extracted original and the full
objdiff match gate cover all three functions. No additional behavioral tests are
required by this matching card. The checksum gate checks the complete build;
this TU remains linked from the delink until a human marks it complete.

## Hard list

None.
