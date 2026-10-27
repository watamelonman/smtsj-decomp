# lib_020b78d8

Partial reconstruction of the ARM effect-task unit. All twenty reconstructed functions
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

| `func_020b7a78` | 108 | Resolve the borrowed object and apply a float descending from 1 to 0 over fifteen steps. Step zero is 1; signed steps at least 15 are 0; other steps use `(-1 * (float)step) / 15 + 1`. Operations follow the soft-float calls and 15.0 literal. |
| `func_020b7ae4` | 96 | Interpolate 255 to 0 through 0205eae0 with duration 15; clamp below 76 and pack three intensity bytes plus low byte 255 into object field +0x28. |
| `func_020b7b44` | 76 | Increment step; at 15 restore object value 0 and finish the task, otherwise update both descending float and packed intensity. |
| `func_020b7ba8` | 116 | Create provider-owned eight-byte state with update 020b7b44 and finish 020b7b90, associate the borrowed object, initialize step zero and apply both effects. Return null on allocation failure. |
| `func_020b7db4` | 96 | Apply rising float: zero at step zero, one at signed steps at least 15, otherwise `(1 * (float)step) / 15`. Lookup and setter evidence mirrors the descending helper. |
| `func_020b7e74` | 108 | Create eight-byte state with update 020b7e14 and finish 020b7e58, associate the object and apply rising step zero. Return null on allocation failure. |
| `func_020b801c` | 92 | Scan ten singleton object pointers at +0x64; pass mode 6 to 020b7ee0 for IDs whose bits 16..23 equal 2, excluding the supplied ID. |
| `func_020b8078` | 80 | Scan the same ten slots and submit mode 7 for every type-two ID; null slots are ignored. |

## Layout and ownership

The C unit keeps its borrowed task prefix and opaque associated object private.
The task contains an unknown word at +0, signed index +4, signed count +8,
borrowed record pointer +0xc, and signed origins +0x10/+0x14. Providers retain
all storage. Each displacement component is a signed byte. The C record pointer
and explicit selected-record local preserve the original address calculation
and register allocation without changing ownership or module boundaries.

## Hard list

None. All twenty functions in this translation unit now match. The TU remains
linked from the delinked object until a human marks it complete.

## Validation

The initial objdiff comparison found seven exact functions and a register-only
difference in 020b78dc. Selecting the two-byte record explicitly and retaining
origin-first additions produced an exact match for the eighth function.
No behavioral test was added: this card disables test requirements and the
acceptance oracle is instruction/relocation equality against the original.

### M2-T465 source search and matching

A further public-source search inspected pret/pokeplatinum task/sprite effects
(`src/battle_anim/script_funcs_1.c` on GitHub); its SysTask and sprite interfaces
do not match these providers. No matching known source was found, so this card
uses the delinked ARM instructions and relocations as evidence.

The two constructors request only eight bytes: they use the shared task view's
first two words, never its displacement-only suffix. Category 4 and zero priority
and flags are forwarded unchanged to the existing provider. The ten-slot
singleton view is private and borrowed; no new module boundary is introduced.

Seven functions matched on the first standalone compile. The descending float
needed an explicit negative-one intermediate and separate addition to preserve
the original soft-float evaluation/register order. All eight then matched.

### M2-T466 constructors and dispatch

A public-source search for the function address and Nintendo DS sprite task
effects found no matching SDK implementation. Existing provider interfaces and
the original ARM instructions/relocations remain the evidence; neutral names
are retained.

| Function | Bytes | Contract and evidence |
| --- | ---: | --- |
| `func_020b7990` | 164 | Create a 24-byte displacement task, associate the borrowed object, select count/table through 0206aeec/0206aed4, store the signed halfword origin and apply step zero. Return null on allocation failure. Kind must select a valid provider table. |
| `func_020b7c1c` | 172 | Resolve the object and increment the four-step intensity task; interpolate signed endpoints at +8/+12 before step four, then use the endpoint and finish the task. Pack intensity into the upper three bytes with low byte 255; null objects receive no color write. |
| `func_020b7cc8` | 236 | Create a 16-byte intensity task from 255 to 76 for nonzero mode, or 76 to 255 for zero. Return null if the object's color already equals the requested endpoint or allocation fails. Apply the initial packed color immediately. Object must be valid. |
| `func_020b7ee0` | 316 | Resolve an ID and its halfword origin, select rising/displacement/falling/intensity task for modes 0..7, and submit a nonnull task through 0209d170. Missing objects or unsupported modes submit nothing. |

The private object prefix exposes only color +0x28. A separate 16-byte intensity
view gives integer names to +8/+12 instead of treating those words as a table
pointer. The coordinate pair uses two signed halfwords and the original
four-byte by-value ABI. Providers own task allocation; all object/resource
references remain borrowed. No module boundary changes.

The first compile matched the constructor, updater and dispatcher. Reordering
the intensity constructor's equivalent mode branches preserved the original
conditional instruction order. All four then matched, including after replacing
the temporary pointer-based endpoint representation with the typed intensity
view. No behavioral tests were added because tests_required is false; objdiff
instruction and relocation equality is the acceptance oracle.
