# sdk_0205de1c

All seven functions are reconstructed in C. Original symbol names are retained;
no public-source identity was established. A public NitroSDK/NitroSystem sprite
source search found no implementation matching these object/range layouts.
The instruction stream and provider accessors are the evidence for the layouts.
No new behavioral tests are required by the card: exact object comparison is the
acceptance oracle, with the existing regression suite and image checksum gates.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `func_0205de1c` | 20 | Loads table +4, selects an object, tail-calls `func_0205db8c`; index must be valid. |
| `func_0205de30` | 16 | Replaces selected object +48 with a borrowed provider pointer. |
| `func_0205de40` | 168 | Table +16 holds count/byte-offset pairs; table +12 holds 24-byte records. Ascending traversal passes final flag 1. |
| `func_0205dee8` | 168 | Same ascending traversal, passing final flag 0 (no reset requested). |
| `func_0205df90` | 184 | Calls `func_02057fd8`, starts at count minus one and traverses backwards with final flag 0. |
| `func_0205e048` | 628 | Builds a 56-byte packet from signed halfwords +8..14 and packed flags +16, converts Q12 degrees to a 16-bit turn when input flag 0x800000 is clear, applies alpha, and submits. Zero opacity returns early. Reset is requested only when its final parameter is nonzero: nonopaque submissions reset directly; opaque submissions reset for provider modes 1 or 6. Geometry stack push/pop writes bracket submission. |
| `func_0205e2bc` | 92 | Saves provider +80/+76, binds object +52/+12, submits through `func_02058fd0`, restores saved values. |

`Unk05de1cObject::auxiliaryData` exposes only the first word at +52; its full
extent is unknown. Packet bytes +36..51 are untouched by the original helper.
The low two flag bits use a bitfield view to preserve the observed extraction
and reloads. Opacity uses the unsigned float conversion followed by a signed
right shift, as in the original. Inputs must be valid for the original provider;
this reconstruction adds no validation or ownership transfers.

Hard list: none.
