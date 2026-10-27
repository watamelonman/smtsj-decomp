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

`include/libs/NitroSDK/sdk_02058370.h` exposes a borrowed graphics-resource work
view: the handle is at +0x2058 and associated state blocks begin at +0x205c and
+0x2084. The wrapper depends only on SDK bank, geometry and resource providers;
callers retain the work storage and provider calls govern resource lifetime.
`include/libs/NitroSDK/sdk_0205c1c8.h` defines borrowed resource-prefix,
12-byte entry and 40-byte record views for the resource wrapper helpers. The
wrapper's flag distinguishes a borrowed resource from one released at teardown;
the independent 320-byte buffer is caller-owned. These helpers depend only on
base types and existing copy, fill, allocation, and resource-release providers.

`include/libs/unknown/lib_0204915c.h` exposes borrowed singleton resource slots
+0x7990/+0x7994/+0x7998 and a callback input flag at +0x40. The lookup helpers
depend only on base types and existing resource/setup providers; they neither
allocate nor transfer ownership of the singleton, tables or returned entries.
The same resource wrapper header exposes caller-owned path output and owned
resource loading through the existing prefix, string, path-probe and loader
providers. Constructed loader paths must fit the original 64-byte stack buffer.

`include/libs/unknown/lib_02027eac.h` defines the borrowed NitroSystem G3D joint
result used by the basic and Maya scale/SRT cgtool routines. The cgtool code owns
no storage: results and scale arrays are caller-owned, identity bits belong to
the shared render state, and the 24-byte parent scale cache remains provider
owned. The unit depends only on existing geometry submission and cache data.
`include/libs/NitroSDK/sdk_020116a8.h` defines borrowed locale, message, work
and global-prefix views for the message pump and single-byte conversion
wrappers. The work slot at +0xc0 is volatile because the interrupt-disabled loop
re-reads it after each wait call; the 36-byte message is stack-owned only while
its handlers run. The global-prefix view spans the following BSS symbol only to
describe the byte at +0x26 cleared by the pump.
