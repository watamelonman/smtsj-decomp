# sdk_0204ff30

All eight requested functions match at 100% with the configured mwccarm compiler.
The original `func_` symbols are retained for linkage. Behavioral descriptions below
come from the delinked ARM instructions, without assigning an unsupported SDK API name.

Public-source lookup: searched the pret/pokeheartgold checkout (lib and src) for
`MTBL`, `0x4c42544d`, and the generator constants; no matching C implementation was
found. The implementation therefore follows the original instructions directly.

| Function | Bytes | Contract and instruction evidence |
| --- | ---: | --- |
| `func_0204ff30` | 52 | Returns the first index at header offset 16; null or signature other than `MTBL` (`0x4c42544d`) returns zero. |
| `func_0204ff64` | 68 | Validates the same signature, then returns offset-16 first index plus offset-12 count minus one, with unsigned wraparound. Invalid/null returns zero. |
| `func_0205002c` | 24 | Stores the low 16 bits of the seed into `data_0215f008[stream]`; the caller must provide an in-bounds stream. |
| `func_02050044` | 48 | Updates that stream with `(109 * state + 1021) & 65535` and returns the new state. The multiply, two additions and shifts establish the LCG. |
| `func_02050074` | 20 | Tail-calls `func_02050088(stream, 0, maximum)`, preserving the inclusive upper bound. |
| `func_02050088` | 36 | Advances the selected stream and returns `minimum + ((range * sample) >> 16)`, where range is `maximum - minimum + 1`. Multiplication and additions wrap at 32 bits exactly as in ARM; callers must choose bounds accordingly. |
| `func_020500ac` | 16 | Returns `data_0215f008[stream]` without advancing; no bounds check exists in the original. |
| `func_02050138` | 40 | Repeated unsigned multiplication computes a power; signed exponents at or below zero return one. Products wrap at 32 bits. |

The private header view describes only the five observed words; storage is borrowed.
The signature predicate uses C99 `_Bool`, preserving the original materialized
boolean and subsequent comparison. No module boundary changes were needed.

Validation: objdiff checks all eight instruction sequences and relocations. No new
behavioral tests are required by this card; the project's existing suite, anticheat,
build and checksum gates are run alongside the match gate.

Hard list: none. The two functions in this TU outside this card (`func_0204ffa8`
and `func_020500bc`) remain supplied by the delinked original.
