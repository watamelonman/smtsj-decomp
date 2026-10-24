# game/unit_0204459c

All eight functions retain their neutral original symbols. Behavior below is
supported by the original ARM instructions, rather than inferred game semantics.
The TU remains delink-backed until a human changes its completion status.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_0204459c` | Returns the borrowed offset-4 handle in the 16-byte `data_0214283c` record. Signed indices outside 0–48 return null. Evidence: comparisons against 0 and 49, shifted index and offset-4 load. |
| `func_020445d0` | Resolves the first argument through the handle table, returning null if absent; otherwise forwards handle and item to `func_0204fdac`. |
| `func_020445f4` | Same null-checked forwarding contract, using `func_0204fe68`. |
| `func_02044618` | Gets item zero of handle three, obtains its data/count and compares leading strings at 24-byte intervals with `func_020152cc`. Returns the borrowed first matching record, or null. Input name must be valid for the comparator. |
| `func_0204467c` | Searches eight-byte rows by signed leading ID. IDs greater than 1000 have 1000 subtracted with signed 16-bit narrowing. Returns the first index narrowed to signed 16 bits, or -1. Row storage must cover the unsigned count. |
| `func_020446c4` | Choices 2–4 select the current row's signed transition fields; all other choices select the following row. Negative -1 stops; -2 scans the 16 saved continuations backward, clears a consumed slot and repeats for nested -2 entries. IDs greater than 1000 save a continuation into the first empty slot. Resolves the ID through `func_0204467c`, rejects invalid indices and stores the selected index. The data must provide valid row references and a resolvable continuation when requesting a pop; an empty stack with -2 repeats indefinitely in the original as well. |
| `func_02044804` | Clears exactly 56 bytes, stores the borrowed row/callback tables and unsigned 16-bit count, fills all 16 continuation slots with -1 and loads the first row ID. Requires at least one row. |
| `func_02044868` | Calls the current ID's callback with the offset-38 state block when present. Results 1 or 2 clear state offset 44 and request a transition using the signed offset-38 choice. A failed transition or absent next callback returns zero. Successful transitions clear the choice; result 2 immediately recurses, other results return one. Tables must cover all referenced IDs. |

## Layout evidence

The work block is 56 bytes: signed ID/index at 0/2, sixteen signed continuation
slots at 4, unsigned count at 36, five state halfwords at 38, row pointer at 48
and callback pointer at 52. Each row has four signed halfwords. Callback table
entries have an eight-byte stride with the function pointer first; the second
word's meaning is unknown. Handle entries have a 16-byte stride, with the
borrowed pointer at offset four. No shared module boundary is changed.

## Validation

Standalone compiler comparison matches all eight instruction streams and
relocations. The task's objdiff, checksum, anticheat and unittest gates are run
against the complete worktree.

## Hard list

None.
