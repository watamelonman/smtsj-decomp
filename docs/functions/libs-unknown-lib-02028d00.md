# lib_02028d00: 3ds Max texture matrices

Source: [NitroSystem cgtool/3dsmax.c](https://github.com/ntrtwl/NitroSystem/blob/d636fb5d2b212e8736f09859fff447be2bd0ac85/libraries/g3d/src/cgtool/3dsmax.c).
The four helper bodies, fixed-point operations, material field offsets and
asynchronous divide calls match the original ARM instructions. The existing
linker names remain unchanged. No new algorithmic decisions were required.

All helpers borrow a material animation result and write caller-owned matrix
entries 00, 01, 10, 11, 30 and 31 only; the caller initializes other entries.
Scales, translations and division results use Q12, rotation uses signed Q12
halfwords, and original dimensions are unsigned pixel counts. Helpers issuing
division require nonzero dimensions and exclusive use of the SDK divider until
both results have been collected, as in the original source.

| Function | Known source helper | Behavior | Objdiff |
| --- | --- | --- | --- |
| `func_02028d00` | `texmtxCalc_flagS_` | Unit-scale rotation and translation, including aspect correction. | 100% (232 bytes) |
| `func_02028de8` | `texmtxCalc_flagR_` | Zero-rotation scale and translation around the texture center. | 100% (128 bytes) |
| `func_02028e68` | `texmtxCalc_flagRS_` | Unit-scale, zero-rotation translation in texture coordinates. | 100% (72 bytes) |
| `func_02028eb0` | `texmtxCalc_flagT_` | Zero-translation scale and rotation around the texture center. | 100% (248 bytes) |

## Validation

The original delinked object is the instruction-level oracle; the card does not
require new tests. `python3 tools/match_gate.py` verifies all four compiled
functions at 100%. The normal build retains the original delinked TU until a
human marks it complete, per the card.

## Hard list

None.
