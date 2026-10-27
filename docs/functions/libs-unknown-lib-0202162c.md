# NitroSystem G3D animation and render object kernel

Source evidence: [ntrtwl/NitroSystem kernel.c](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/kernel.c)
and [kernel.h](https://github.com/ntrtwl/NitroSystem/blob/main/include/nnsys/g3d/kernel.h).
The six implementations follow the release source, with original linker names
retained because symbol configuration is human-owned. No new dependencies.

| Original symbol | Source identity and contract | Result |
| --- | --- | --- |
| `func_0202162c` | `NNS_G3dAnmObjCalcSizeRequired`: null resource/model returns zero; M uses material count, J/V use node count; required size rounds down after adding the 28-byte base and two bytes per mapping. | 100% |
| `func_0202168c` | `NNS_G3dAnmObjInit`: initialize frame, Q12 ratio, resources, priority and chain state, then invoke the first matching category pair's non-null initializer. Caller supplies sufficient storage. | 100% |
| `func_0202172c` | `NNS_G3dRenderObjInit`: clear 84 bytes, install three default blend callbacks and retain the borrowed model. | 100% |
| `func_02021780` | `addLink_`: splice an animation chain by priority, preserving the source's distinct single-item and longer-list insertion rules. Input chains must be disjoint and acyclic. | 100% |
| `func_02021838` | `updateHintVec_`: OR mapping-existence bits (0x100) into the supplied hint vector for every animation in the chain. Does not clear previous bits. | 100% |
| `func_020218a0` | `NNS_G3dRenderObjAddAnmObj`: update the appropriate material, joint or visibility hints and list; null animation/resource or unsupported category does nothing. | 100% |

The header reproduces only the model prefix needed for counts (+23/+24), the
animation layout (chain +16, priority +24, mapping count +25, mapping +26), and
the render state layout. Texture resources remain opaque. Animation, model and
render storage remain caller/provider-owned; no allocation or ownership transfer
occurs here. Hint vectors contain two words per category, as established by the
original render offsets +60/+68/+76 and 84-byte clear.

The format registry signatures at `data_0213d38c` and callbacks at
`data_0213d390` are overlapping eight-byte-stride borrowed views. Separate views
preserve both original relocations rather than referencing callbacks as an offset
from the signature symbol. Standalone instruction/relocation comparison confirms
all six functions exactly; objdiff also reports 100% for each.

## Hard list

None.
