# sdk_0204ff30

Nine implemented functions match at 100% with the configured mwccarm compiler.
The original `func_` symbols are retained for linkage. Behavioral descriptions below
come from the delinked ARM instructions, without assigning an unsupported SDK API name.

Public-source lookup: searched the pret/pokeheartgold checkout (lib and src) for
`MTBL`, `0x4c42544d`, and the generator constants; no matching C implementation was
found. The implementation therefore follows the original instructions directly.

| Function | Bytes | Contract and instruction evidence |
| --- | ---: | --- |
| `func_0204ff30` | 52 | Returns the first index at header offset 16; null or signature other than `MTBL` (`0x4c42544d`) returns zero. |
| `func_0204ff64` | 68 | Validates the same signature, then returns offset-16 first index plus offset-12 count minus one, with unsigned wraparound. Invalid/null returns zero. |
| `func_0204ffa8` | 132 | Runs the observed initialization calls in order, sets `data_0213ce44` to one, clears bit 16 of the sub-engine display register at `0x04001000`, forwards both incoming words unchanged to `func_02052e68`, seeds streams zero and one with 1192, and returns one. Parameter semantics beyond forwarding remain unknown. |
| `func_0205002c` | 24 | Stores the low 16 bits of the seed into `data_0215f008[stream]`; the caller must provide an in-bounds stream. |
| `func_02050044` | 48 | Updates that stream with `(109 * state + 1021) & 65535` and returns the new state. The multiply, two additions and shifts establish the LCG. |
| `func_02050074` | 20 | Tail-calls `func_02050088(stream, 0, maximum)`, preserving the inclusive upper bound. |
| `func_02050088` | 36 | Advances the selected stream and returns `minimum + ((range * sample) >> 16)`, where range is `maximum - minimum + 1`. Multiplication and additions wrap at 32 bits exactly as in ARM; callers must choose bounds accordingly. |
| `func_020500ac` | 16 | Returns `data_0215f008[stream]` without advancing; no bounds check exists in the original. |
| `func_02050138` | 40 | Repeated unsigned multiplication computes a power; signed exponents at or below zero return one. Products wrap at 32 bits. |

The private header view describes only the five observed words; storage is borrowed.
The signature predicate uses C99 `_Bool`, preserving the original materialized
boolean and subsequent comparison. No module boundary changes were needed.

Validation: objdiff checks all nine implemented instruction sequences and relocations. No new
behavioral tests are required by this card; the project's existing suite, anticheat,
build and checksum gates are run alongside the match gate.

## M2-T121 source lookup and hard list

Public-source searches for NitroSDK MTBL and distance/square-root implementations
found no matching initialization wrapper or two-coordinate integer routine.
The documented [VEC_Distance](https://twlsdk.randommeaninglesscharacters.com/docs/nitro/NitroSDK/fx/vec/VEC_Distance.html)
uses three fixed-point coordinates, unlike the two-word integer routine here.
No public implementation was copied. Existing symbols are retained for linkage;
comments describe instruction-established behavior without guessing SDK API names.

| Function | Bytes | Contract and remaining mismatch |
| --- | ---: | --- |
| `func_020500bc` | 124 | Takes two borrowed pairs of 32-bit coordinates. Calls `func_02050138` to square each difference, writes their wrapping sum to the 32-bit SQRT operand at `0x040002b8` after selecting mode zero at `0x040002b0`, polls busy bit 15 twice, and returns `0x040002b4`. This integer distance helper requires exclusive access to the SQRT unit. |

Hard list: `func_020500bc`. The C reconstruction reached 99.35% in objdiff,
with identical instruction count and only the order of the two second-coordinate
loads differing: target loads `[r4, #4]` into r1 before `[r5, #4]` into r2;
mwccarm emits these in reverse order. Tried separate coordinate/difference
locals, combined and separate sums, signed/unsigned integer declarations,
register hints and inline subtraction helpers. None matched, so the candidate
was removed and the function remains supplied by the delinked original.
A human can use `tools/decompme.py` for further scratch work. No `INCLUDE_ASM`
was added because this project already links unmatched functions from the delink.

