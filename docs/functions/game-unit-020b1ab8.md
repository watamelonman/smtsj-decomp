# game/unit_020b1ab8 — M1-T348

All eight functions below match at 100% in objdiff. Names remain the original
neutral `func_` symbols because their game-level purpose is not established and
symbol configuration is human-owned. Evidence is the original ARM loads, stores,
and call targets, rather than an inferred gameplay interpretation.

The by-value coordinate aggregate contains two signed 16-bit components. The
partial work view exposes only the fields needed here: byte kind at +0, byte
variant at +2, and word value at +12. The creator at 020b1ab8 establishes these
offsets. Its callers assume successful creation and do not check for null.
The coordinate tables at 0213c42c and 0213c42e lie in the read-only section;
each addresses one component of an interleaved five-pair table.

| Function | Evidence and contract |
| --- | --- |
| `func_020b1b68` | Calls 020b1ab8 with the supplied position, mode 7 for nonzero flag or 6 otherwise, and the low byte of direction. Stores kind 4, the supplied word value, and the low byte of variant. |
| `func_020b1bc4` | Reduces unsigned direction modulo 5, then adds signed halfwords from the interleaved tables to the pointed-to coordinate pair. Stores truncate each sum to 16 bits. The pointer must be valid. |
| `func_020b1c18` | Calls 020b1bc4 on its by-value position, then 020b1b68 with variant 3, forwarding the value, flag, and low direction byte. |
| `func_020b1c7c` | Same call pattern with variant 4. The caller's original coordinate pair is unchanged. |
| `func_020b1ce0` | Same call pattern with variant 1. The caller's original coordinate pair is unchanged. |
| `func_020b1da8` | Offsets its by-value position through 020b1bc4, creates work with flag-selected mode 6/7 and low direction byte, then writes kind 5 and value 3. |
| `func_020b1e74` | Same offset and creation pattern, then writes kind 7 and value 2. |
| `func_020b1f48` | Same offset and creation pattern, then writes kind 9 without changing the creator's value field. |

No module boundary changes or new dependencies. Unimplemented functions in this
translation unit continue to come from the delinked original, as configured.

## Hard list

None for M1-T348.
