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
`include/libs/unknown/lib_0202aeb0.h` exposes borrowed sound-capture work,
state and message-queue views. The work area's state field begins at +0x48 and
the state's channel, capture, alarm, fader and volume fields follow the
instruction-established offsets; the aliases at `data_0215cabc` and
`data_0215ca7c` keep the original per-symbol relocations. The sound subsystem
retains ownership of the work area, buffers and fader, and the helpers depend
only on existing NitroSDK sound, cache, fill and message providers.

`include/libs/unknown/lib_02029b78.h` exposes the five borrowed 24-byte frame
texture regions and the three-word frame palette manager used by those state
blocks. The save/restore helpers copy only `head`/`tail` and `lo`/`hi`; the
regions and manager remain owned by the GFD VRAM manager.
`include/libs/NitroSDK/sdk_0205c1c8.h` defines borrowed resource-prefix,
12-byte entry and 40-byte record views for the resource wrapper helpers. The
wrapper's flag distinguishes a borrowed resource from one released at teardown;
the independent 320-byte buffer is caller-owned. These helpers depend only on
base types and existing copy, fill, allocation, and resource-release providers.

`include/libs/NitroSDK/sdk_02005a08.h` exposes the borrowed volatile `OSLockWord`
view (`lockFlag`, `ownerID`, `extension`) used by the NitroSDK spin-lock
helpers; callers retain the lock storage and the OS boot state owns it.

`include/libs/unknown/lib_0204915c.h` exposes borrowed singleton resource slots
+0x7990/+0x7994/+0x7998 and a callback input flag at +0x40. The lookup helpers
depend only on base types and existing resource/setup providers; they neither
allocate nor transfer ownership of the singleton, tables or returned entries.
The same resource wrapper header exposes caller-owned path output and owned
resource loading through the existing prefix, string, path-probe and loader
providers. Constructed loader paths must fit the original 64-byte stack buffer.

`include/libs/unknown/lib_02049398.h` exposes the borrowed singleton slots
+0x7994/+0x79a4/+0x79a8 used by the adjacent record-lookup unit, plus a
caller-owned 256-entry array of 56-byte records with trailing bookkeeping words.
The helpers depend only on base types and existing TBB1/TBL1/MTBL, fill and battle
record providers; the singleton, tables and returned entries remain provider owned.

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

`include/libs/unknown/lib_02028d00.h` exposes caller-owned 4x4 Q12 matrix
storage and a borrowed NitroSystem material-animation layout. The four 3ds Max
texture helpers write only entries 00, 01, 10, 11, 30 and 31 and depend on the
existing asynchronous SDK division providers. No ownership is transferred.
`include/libs/unknown/lib_02028578.h` declares the borrowed NitroSystem G3D joint
result used by the Maya joint-SRT sender and reuses the shared material/matrix
views of the neighbouring cgtool units. The texture-matrix constructor table at
0x0213d584 and the geometry submission routine belong to their existing
providers; the packet matrix, the joint result and the material result are all
caller- or provider-owned, and this unit allocates and retains nothing.

`include/libs/NitroSDK/sdk_02052b58.h` exposes the borrowed 16-byte state
prefix used by the SDK helpers: index/count/flag words and a pointer to
caller-owned two-byte records. The provider owns the state and callers retain
the record storage; the wrappers depend only on existing library providers.

`include/libs/unknown/lib_02028a2c.h` reuses the neighbouring 3ds Max unit's
borrowed material and caller-owned matrix layouts. The SI3D sender owns its
stack geometry packet only during submission; both routines depend solely on
existing SDK division and geometry providers and retain no storage.
`include/libs/unknown/lib_02048e90.h` exposes a borrowed singleton layout for
its setup, teardown and update wrappers: the latch words at +0x50/+0x54, ten
object pointers at +0x64, resource slot +0x7870, nine resource pointers at
+0x798c and initialization guard +0x7a3c. The wrappers depend only on base
types and existing providers; providers retain ownership of objects and state,
and resource release remains governed by the existing teardown provider.

`include/libs/unknown/lib_0202162c.h` exposes the caller-owned NitroSystem
animation/render layouts and the borrowed model count prefix for the G3D kernel.
The helpers depend only on the existing word-fill provider, format initializer
registry and default blend callbacks. Resource ownership stays with providers;
list attachment borrows animation chains and performs no allocation.

`include/libs/NitroSDK/sdk_020276f8.h` exposes borrowed NitroSystem texture
SRT resource/dictionary and model prefixes plus caller-owned animation objects
with trailing material mappings. It reuses the existing material result layout;
the evaluators depend only on dictionary-name lookup, halfword fill and the
animation kernel callback registry. No resource ownership is transferred.
`include/libs/NitroSDK/sdk_02053c08.h` exposes the borrowed five-entry
touch-sample table: each 14-byte record holds the current and previous touch
flag and calibrated x/y coordinates, plus one never-read alignment halfword.
The sample shift, three touch-state queries, the rectangle hit test and the
integer-distance check depend only on base types and the existing touch-panel,
integer-distance and GX providers. The table and calibration storage remain
provider-owned; this unit allocates and releases nothing.

`include/libs/NitroSDK/sdk_0205de1c.h` exposes borrowed object/provider and
range-table prefixes, caller-owned 24-byte records, and the 56-byte submission
packet. The wrappers depend only on existing drawing and provider-state helpers
and geometry stack registers. Providers retain all table and resource storage;
auxiliary state is temporarily rebound and restored around submission.
`libs/CRI/cri_0207a8d0.c` keeps its partial CRI work-area view private: the
state word at +4, the released child pointer at +8, the result words at
+0x90/+0x94 and the boolean flag at +0xac. The accessors, state setter, release
path and halfword row-shift helpers depend only on base types and the
neighbouring CRI release provider (0x0208095c). The caller owns the work area
and its child object; this unit allocates and retains nothing.

The CRI work-area view also exposes format bytes +0xd/+0xe/+0xf, borrowed
input/output pointers +0x48/+0x5c, row bookkeeping +0x64..+0x74 and callbacks
with contexts at +0x78/+0x7c, +0x80/+0x84 and +0xe8/+0xec. Child-state
providers control progression; callbacks borrow the work-area fields during
calls. The result and progress words extend through +0xe4; ownership remains
with the caller and existing providers.
