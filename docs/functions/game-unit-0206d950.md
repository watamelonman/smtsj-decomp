# game/unit_0206d950

All five functions are 100% in the objdiff report. Original `func_` symbols are
retained as neutral names because the owning subsystem is not established.
Layouts are local to this translation unit; no module boundary changes.

## func_0206d950 (0x0206d950, 44 bytes)

Adds a signed step to a borrowed signed halfword and clamps the intermediate
signed word toward a limit: upper clamp for nonnegative steps, lower clamp for
negative steps. Stores the resulting halfword. Evidence: signed halfword load,
step-sign branch, signed comparisons, and halfword store. Caller must avoid
signed word overflow; the final halfword narrowing follows the original.

## func_0206d97c (0x0206d97c, 92 bytes)

Clears 0x102 bytes at `data_0216b9c0`, stores the first slot and inclusive last
slot at offsets 0x100/0x101, and calls `func_02057e30` for each slot in the
half-open input range. First slot is a byte and count is signed. Nonempty ranges
must fit in 0..63 without wrapping; no extra validation was added.
Evidence: clear-call size, byte stores, and byte-truncated loop increment.

## func_0206d9d8 (0x0206d9d8, 208 bytes)

Searches the configured inclusive range for a zero flag in one of four 64-byte
banks. Banks 0 and 3 scan upward; banks 1 and 2 scan downward. Claims a free slot
by storing 1, notifies `func_02057e30`, and returns the slot. Unsupported banks or
exhausted searches notify and return 63. Bounds must be valid for the banks;
byte iteration, including the original descending wrap behavior, is preserved.
Evidence: four-entry jump table, bank address shift by six, byte flag accesses,
and the shared fallback call.

## func_0206daa8 (0x0206daa8, 84 bytes)

Clears the configured inclusive range in each of the four banks without changing
the stored bounds or issuing notifications. Evidence: four-iteration byte outer
loop, bank shift by six, and zero-byte inner stores. Bounds must remain in 0..63.

## func_0206dafc (0x0206dafc, 736 bytes)

Clears the next 0x148-byte record in `data_0216bac8`, formats the supplied string
into its 31-byte name field at offset 1, then terminates it at the first dot if
present. Sets the three bytes at offsets +0..+2 of each eight-byte group starting
at 0xbc through 0x134 to 255. Increments `data_0216bac4` and returns the previous
index narrowed to a byte. Caller supplies a valid string and available table
capacity; capacity and byte-field meanings are unknown.

Evidence: the 328-byte multiply and clear size; `%s` at `data_021457e4`;
31-byte formatting call; character search argument 46; and the observed field
stores. The chained assignment preserves the original evaluation sequence.
A typed record layout reproduces the literal references to interior fields;
objdiff resolves these against the original individual data symbols. Independent
strided field arrays produced different scheduling and register allocation and
were replaced with the unified record layout.

## Hard list

None. All five requested functions matched; no scratch upload is needed.
