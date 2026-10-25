# game/unit_02122a78

All three functions match at 100% objdiff. Names remain neutral because the
instructions establish operations but do not establish their game-level purpose.

## `Unk122a78_Unk_122a78` (0x02122a78, 40 bytes)

Calls `Unk05b82c_Unk_05b82c` with each of the first three IDs in
`data_0213cd70`, in table order. Takes no arguments and returns no value.
Evidence: indexed word loads and an unsigned loop bound of three.

## `Unk122a78_Unk_122aa0` (0x02122aa0, 28 bytes)

Calls `func_0205bb68` exactly three times, without passing arguments or using
results. No arguments or return value. The callee's broader purpose remains
unestablished here.

## `func_02122abc` (0x02122abc, 864 bytes)

Returns the 292-byte callback state allocated by `func_020611dc`. Registers
`func_021236b4`, `func_02123bc8`, a null callback, and `func_02122e1c`.
Loads two resource pairs from the four referenced data symbols, creates 17
objects plus one additional object, and initializes mode-dependent counts,
flags, counters and handle groups. The first handle group uses IDs starting at
100; the six-element second group uses IDs 110 through 115. Mode four with a
zero result from `func_02117170` uses three explicit group-four assignments.
Computes a floating-point reciprocal of the first selected object's last frame.

The private struct follows the original field offsets. The seven-slot first
handle/flag capacities are inferred from adjacent field boundaries; initialization
uses only the mode-selected count (three or five). Resource and handle values
remain opaque 32-bit values. Allocation success and a nonzero last-frame divisor
are preconditions inherited from the original, which checks neither. Callback
registration controls the state lifetime; this constructor does not release it.

## Validation

- Standalone instruction comparison of `func_02122abc`: identical.
- `python3 tools/match_gate.py`: all three functions at 100%.
- `python3 tools/anticheat.py`: passed.
- `python3 -m unittest discover -s tests -t . -q`: nine tests passed.
- `python3 tools/checksum.py`: all artifacts byte-identical.

## Hard list

None.
