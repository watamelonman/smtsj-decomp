# sdk_0204f9d8

M2-T258 reconstructs eight ARM functions. Public NitroSDK source was sought
before implementation; no matching source was identified. The game-area
accessors and token-stream caller indicate game-specific helpers despite the
SDK directory assignment. Existing neutral symbols are retained. Contracts
below follow the original comparisons, loads, stores and calls.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `func_0204f9d8` | 36 | Returns one exactly for unsigned tokens greater than `0x8000` and less than `0x83e9`. Used by the token-copy loop at `020d33cc`. |
| `func_0204f9fc` | 16 | Tests for token zero, the stream terminator checked by `020d33cc`. |
| `func_0204fa0c` | 64 | Selectors 1, 2, 3 call `Unk09727c_GetAreaSub24`, `Unk09727c_GetAreaSub5a`, `Unk09727c_GetAreaSub48`, respectively; other selectors return zero. |
| `func_0204fa94` | 64 | Clears all twelve words at `data_0215eeac` and only the first halfword of each of six 50-byte buffers at `data_0215eedc`. Buffer tails are preserved. |
| `func_0204fad4` | 28 | Accepts unsigned slot indices 1 through 11; rejects zero and all other values. |
| `func_0204faf0` | 36 | Calls the index guard and writes the supplied word to the indexed slot only on success. |
| `func_0204fb14` | 36 | Calls the same guard and returns the indexed word, or zero for invalid indices. A conditional expression preserves the original zero-result instruction ordering. |
| `func_0204fcb0` | 56 | Accepts one-based indices 1 through 6; passes the source and selected buffer to `func_0204fa4c` with capacity 25 halfwords. Invalid indices do not access the source. Valid sources must satisfy the existing bounded copier's readable-storage contract. |

All storage is borrowed from existing providers. The private buffer view models
the observed 50-byte stride and transfers no ownership. There is no new module
boundary. Instruction comparison and objdiff verify all eight functions at 100%.
The two other functions in this translation unit remain delinked for M2-T259.

## Hard list

None for M2-T258.
