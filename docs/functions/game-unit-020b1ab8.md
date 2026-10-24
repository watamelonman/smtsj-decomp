# game/unit_020b1ab8 — M1-T348 / M1-T349

All twelve functions below match at 100% in objdiff. Names remain the original
neutral `func_` symbols because their game-level purpose is not established and
symbol configuration is human-owned. Evidence is the original ARM loads, stores,
and call targets, rather than an inferred gameplay interpretation.

The by-value coordinate aggregate contains two signed 16-bit components. The
work view is 28 bytes: byte kind at +0, state at +1, variant at +2,
direction at +3, counters at +4/+8, value at +12, another word at +16,
mode at +20, and signed coordinate pair at +24. The creator at 020b1ab8 establishes these
offsets. Its callers assume successful creation and do not check for null.
The coordinate tables at 0213c42c and 0213c42e lie in the read-only section;
each addresses one component of an interleaved five-pair table.

| Function | Evidence and contract |
| --- | --- |
| `func_020b1ab8` | Allocates 28 bytes through 020611dc with update 020b17f4, draw 020b1884, category 4, and unsigned 16-bit priority 10 minus direction. Returns null on failure; otherwise registers through 0209d170 and initializes kind 4, supplied mode/position/direction, and zero state, counters, value, variant and +16 word. |
| `func_020b1d44` | Offsets its copied pair through 020b1bc4 and forwards to 020b1b68 with variant 2 and the low direction byte. |
| `func_020b1e08` | Offsets the pair, subtracts 12 from its signed y component with halfword truncation, and creates kind 6/value 0 with flag-selected mode 6/7. Requires successful creation. |
| `func_020b1ed4` | Offsets the pair and subtracts 12 from y only when the fourth argument is zero; creates kind 8/value 1 with flag-selected mode 6/7. Requires successful creation. |
| `func_020b1b68` | Calls 020b1ab8 with the supplied position, mode 7 for nonzero flag or 6 otherwise, and the low byte of direction. Stores kind 4, the supplied word value, and the low byte of variant. |
| `func_020b1bc4` | Reduces unsigned direction modulo 5, then adds signed halfwords from the interleaved tables to the pointed-to coordinate pair. Stores truncate each sum to 16 bits. The pointer must be valid. |
| `func_020b1c18` | Calls 020b1bc4 on its by-value position, then 020b1b68 with variant 3, forwarding the value, flag, and low direction byte. |
| `func_020b1c7c` | Same call pattern with variant 4. The caller's original coordinate pair is unchanged. |
| `func_020b1ce0` | Same call pattern with variant 1. The caller's original coordinate pair is unchanged. |
| `func_020b1da8` | Offsets its by-value position through 020b1bc4, creates work with flag-selected mode 6/7 and low direction byte, then writes kind 5 and value 3. |
| `func_020b1e74` | Same offset and creation pattern, then writes kind 7 and value 2. |
| `func_020b1f48` | Same offset and creation pattern, then writes kind 9 without changing the creator's value field. |

No module boundary changes or new dependencies. The unit continues to link from the delinked original until a human marks it
complete; no configuration was changed.

## Hard list

None for M1-T348 or M1-T349. All four M1-T349 implementations preserve the
original ARM instruction sequences, including aggregate passing and narrowing.
