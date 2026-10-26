# Architecture

Updated in the SAME change as any module boundary change.

## Layers (enforced by `forge.toml [layers]`)
Arrows mean "may include/call". Nothing points upward.

(Fill in from the preset; see preset README.)

The `game/unit_020f6250` scene handlers share partial borrowed layout views in
`include/game/unit_020f6250.h`; resource data remains external to the handlers.

## Boundaries that must not be crossed

The `libs/unknown/lib_020296b8.c` library unit exposes its material and matrix
views through `include/libs/unknown/lib_020296b8.h`. It depends only on base
types, the existing geometry submission function, and the original constructor
dispatch table; it has no game-layer dependency.
`include/game/unit_020bac80.h` defines borrowed prefix views for the state,
work area, and entry table used by `src/game/unit_020bac80.c`. Providers retain
ownership; the views expose only offsets observed in the original instructions.

## Glossary

`include/game/unit_020a163c.h` holds private layout views and provider declarations
for the resource/list TU. The views expose only instruction-established fields;
resource providers retain their existing ownership and lifetime contracts.

`include/game/unit_0203aae8.h` defines borrowed object-prefix and eight-byte
record views for the script provider dispatchers. Only instruction-observed
fields are exposed; active work and provider storage retain their ownership.

`include/game/unit_0211d520.h` defines borrowed work, recorded-ID, slot-request,
and text-rectangle views for the list display callbacks. Offsets and descriptor
strides follow the original loads and calls. External resource providers retain
ownership; the work area owns display handles between allocation and teardown.

`include/game/unit_020cb32c.h` exposes borrowed work/display prefix views and
provider declarations for the list teardown and paired drawing helpers.
Offsets follow original loads and stores; resource providers retain ownership.

`include/libs/NitroSDK/sdk_020222d8.h` adds borrowed NitroSystem material,
joint-result, model-resource and SBC scratch views. The SBC handlers depend
only on existing SDK providers and geometry hardware; model/animation storage
stays with its provider, while the draw operation owns scratch and cache flags.
`include/libs/MSL/msl_02017850.h` exposes a borrowed formatting-request prefix
for the MSL decimal formatter: only the signed precision at offset two is read.
The request and decimal output storage remain caller-owned; the helpers depend
only on existing MSL numeric routines and base types.
`include/libs/unknown/lib_02061798.h` exposes borrowed font-table and render
object views for the text library. The optional halfword table is at font
record +0x30; the render object's first pointer references a child whose
+0x84 flag is updated by device polling. These views add no ownership or
lifetime guarantees and depend only on base types and existing providers.

The text-library borrowed views also expose singleton mode bytes +0x54/+0x55,
its enable word +0x70 and reset byte +0x74, and a four-word metric buffer
whose +8 origin is caller supplied. Provider ownership remains unchanged.
