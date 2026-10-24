# game/unit_020bcc7c

All six functions match the delinked ARM code at 100% objdiff. Names remain
unchanged because the exact owning subsystem is not established. The local
`SelectionState` view names fields from their arithmetic use, not an inferred
UI identity. Storage is borrowed and initialized by the caller; counts, spans,
and positions must permit the original signed arithmetic without overflow.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020bcc7c` | Decrement selected position, then start if necessary. At the lower boundary, wrap sets selected to count minus one and start to max(count minus span, 0); otherwise clear both and return zero. Returns one on the other paths. Evidence: loads/stores at +0x10/+8 and wrap test at +0x18. |
| `func_020bccec` | Increment selected position. At count, wrap clears selected/start; without wrap undo the increment and return zero. Advance start when selected reaches start plus span. Evidence: count comparison at +4 and final span addition from +0. |
| `Unk0bcc7c_Unk_0bcd58` | Return zero if start is nonpositive; otherwise subtract span minus one, clamp to zero, and adjust selected by start minus saved start. Evidence: +8, +0xc and +0x10 arithmetic. |
| `func_020bcda4` | Return zero when start is already at least count minus span. Otherwise advance by span minus one, clamp to count minus span and adjust selected by the change from saved start. Evidence: paired count/span loads and +0xc delta. |
| `Unk0bcc7c_Unk_0bcdf8` | Forward borrowed state to `func_020bce08` with page movement enabled; discard result. Evidence: r1 = 1 and tail interworking branch to the update function. |
| `func_020bce08` | Snapshot start/selected, then query channel zero masks 0x40 and 0x80 in order. If enabled, query page masks 0x20 and 0x10 afterward. Return minus one/one for successful backward/forward movement and zero otherwise. Evidence: four calls to `func_02053824` followed by the four local movement helpers. No stronger interpretation of the external query is assumed. |

## Validation

The typed seven-word layout preserves all original offsets and all six compiled
function bodies match at 100%. No new tests are required by this card; objdiff
checks the complete instruction sequences against the original implementation.

## Hard list

None.
