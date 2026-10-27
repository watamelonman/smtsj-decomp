# lib_020b78d8

Partial reconstruction of the ARM effect-task unit. All eight card functions
match at 100% with the configured compiler. Original neutral symbols are kept;
field effects alone do not establish original API names.

## Source search

Searched public NitroSDK/pret sources for task-based sprite effects before
reconstruction. No matching source was identified. The task creation calls,
signed displacement records, and object field setters suggest application
middleware rather than a standard SDK primitive. The inspected pret example
<https://github.com/pret/pokeplatinum/blob/main/src/applications/town_map/graphics.c>
uses a different task/sprite interface and was not used as implementation source.
The delinked instructions and relocations are the implementation evidence.

## Functions

| Function | Bytes | Contract and evidence |
| --- | ---: | --- |
| `func_020b78d8` | 4 | Empty original callback (`bx lr`); no observed arguments. |
| `func_020b78dc` | 68 | Resolve associated object through 020616c0; if present, add the indexed signed-byte displacement pair to task origins +0x10/+0x14 and call SetPair04. Index must address a valid two-byte record. |
| `func_020b7920` | 76 | Increment signed index +4; at count +8, restore the pair and finish the task through 02061424; otherwise apply the next displacement. |
| `func_020b796c` | 36 | Resolve object and restore origin pair when present. |
| `func_020b7a34` | 68 | Set field +0x2c to one when the float is less than 1.0, otherwise zero, then pass the unchanged float to field +0x20. `_fls` and setter relocations establish the behavior; no clamping is implied. |
| `func_020b7b90` | 24 | Resolve object and pass that object, rather than the task, to 02061424 when present. |
| `func_020b7e14` | 68 | Increment +4; at step 15 resolve object, set value 1.0 if present, then finish task; earlier steps call existing interpolation helper 020b7db4. |
| `func_020b7e58` | 28 | Resolve object and restore value 1.0 when present, via 020b7a34. |

## Layout and ownership

The C unit keeps its borrowed task prefix and opaque associated object private.
The task contains an unknown word at +0, signed index +4, signed count +8,
borrowed record pointer +0xc, and signed origins +0x10/+0x14. Providers retain
all storage. Each displacement component is a signed byte. The C record pointer
and explicit selected-record local preserve the original address calculation
and register allocation without changing ownership or module boundaries.

## Hard list

None of the eight requested functions remains unmatched. Other entry points in
this partial translation unit remain supplied by the delinked object and were
outside this card. The TU must remain incomplete until those are reconstructed.

## Validation

The initial objdiff comparison found seven exact functions and a register-only
difference in 020b78dc. Selecting the two-byte record explicitly and retaining
origin-first additions produced an exact match for the eighth function.
No behavioral test was added: this card disables test requirements and the
acceptance oracle is instruction/relocation equality against the original.
