# NitroSystem texture and palette helpers

Source identification: [ntrtwl/NitroSystem kernel.c](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/kernel.c),
with checked material/dictionary accessors from
[res_struct_accessor_inline.h](https://github.com/ntrtwl/NitroSystem/blob/main/include/nnsys/g3d/binres/res_struct_accessor_inline.h).
Existing linker names are retained because symbol configuration is human-owned.

| Original symbol | Known source equivalent | Evidence | Match |
| --- | --- | --- | --- |
| func_02021a10 | NNS_G3dTexSetTexKey | Conditional key stores at +8/+24 | 100% |
| func_02021adc | NNS_G3dTexReleaseTexKey | Optional outputs, loaded-bit clearing, key reset | 100% |
| func_02021b28 | NNS_G3dPlttGetRequiredSize | Null guard and palette size at +48 times eight | 100% |
| func_02021b3c | NNS_G3dPlttSetPlttKey | Palette key store at +44 | 100% |
| func_02021b44 | NNS_G3dPlttLoad | GX palette begin/load/end, relative payload and loaded flag | 100% |
| func_02021b94 | NNS_G3dPlttReleasePlttKey | Loaded flag clear and key extraction/reset | 100% |
| func_02021e9c | NNS_G3dReleaseMdlTex | Texture dictionary traversal and binding-release calls | 100% |
| func_02022110 | NNS_G3dReleaseMdlPltt | Palette dictionary traversal and flag clearing | 100% |

The dictionary count preserves the repeated original reads (see DEC-042).
The resource and nested dictionaries must be valid for release routines; the
SDK inline null checks do not make subsequent dictionary dereferences safe.
Palette addresses use the key's low 16 bits in eight-byte units.

Hard list: none for this card. Other functions in the TU remain in the original
delinked object, as required by the task's partial-TU scope. No tests added:
this card sets tests_required=false; objdiff is the exact instruction oracle.
