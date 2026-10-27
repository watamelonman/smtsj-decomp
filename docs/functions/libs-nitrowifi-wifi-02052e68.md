# libs/NitroWiFi/wifi_02052e68

Reconstruction of the NitroWiFi (SDK 4.2) buffer-group and connection-state
helpers at `0x02052e68..0x020531fc` and `0x020533d4`. All functions below match
the delinked ARM instructions at 100%. The TU is still linked from the delink;
the split configuration stays human-owned.

A public-source search (pret/pokeplatinum `lib/` and `src/`, which rebuild
NitroSDK/NitroSystem code for the DS) found no NitroWiFi unit, and no other
public NitroWiFi source is available. The reconstruction therefore follows the
original instruction stream and keeps the neutral `func_XXXXXXXX` symbols.

## Data layout (evidence from instruction offsets)

`data_0215f4d8` is the buffer group:

| Offset | Type | Meaning |
| --- | --- | --- |
| +0x00 | u16 | current heap index used by `func_02052f7c` |
| +0x02 | u16 | saved heap index restored by `func_02052f68` |
| +0x04 | u32 | live-buffer counter changed by `02052f7c`/`02053000` |
| +0x08 | u32 * | heap descriptor array, `count + 1` entries |
| +0x0c | u32 | bytes arena 2 contributes to the group |

`data_0215f500` is the connection block; only `+0x14` (state, written by
`func_0205304c`), `+0x30` (pending value) and `+0x40` (callback) are touched by
this unit. `data_021439e0`, `data_02143a08` and `data_02143a10` are the callback
argument tables read by `func_0205304c`.

The heap primitives were identified from their bodies: `func_02006ed8` /
`func_02006ec4` read an arena's base/end words, and `func_02020438` aligns a
span to 4 bytes, rejects spans under `0x4c` bytes and initialises a heap
descriptor through `func_0201fff0`; `func_02020470` then allocates from it.

## Functions

| Function | Behavior and instruction evidence | Match |
| --- | --- | --- |
| `func_02052e68` | Builds the buffer group for `count` transfer chunks. Sums the arena-0 and arena-2 spans (the arena-2 span is stored at +0xc), reserves an aligned `(count + 1)`-word heap array at the arena-0 base via `func_02020438(..., 2)`, then creates one heap per requested size rounded up to 32 bytes and gives the final slot the remaining span. Records `count` at +0 and +2; returns 1. `sizes == 0` skips the loop, so only the trailing heap is created. | 100% |
| `func_02052f58` | Stores the low halfword of its argument in the group's current-index field. `func_020caea8` calls it with 0 before a record load. | 100% |
| `func_02052f68` | Copies the saved index (+2) back to the current index (+0); the matching restore in `func_020caea8`. | 100% |
| `func_02052fe0` | Returns allocated storage from the current heap (used by `sdk_02051378.c`) with flag 1, which `func_02052f7c` maps to allocation mode 32 (head of the free span). | 100% |
| `func_02052ff0` | Returns allocated storage (forwarded by `func_0208daa0` in `cri_0208d8e8.c`) with flag 0, which `func_02052f7c` maps to mode -32 (tail). | 100% |
| `func_02053048` | Empty hook: a lone `bx lr`. Its two call sites (`0x020481f4`, `0x020a0e38`) ignore the return value, so no side effect is observable. | 100% |
| `func_020530b0` | Stores a pending value at connection +0x30 unless the state is exactly 9 or 10. Evidence: the ROM computes `state - 9` and stores only when the unsigned result is greater than 1. | 100% |
| `func_020531d8` | Event handler: a nonzero halfword at event +2 is forwarded to `func_020530b0`; zero requests state 1 through `func_0205304c`. Only caller is `func_020531b0`. | 100% |
| `func_020533d4` | Returns the connection state word at +0x14; `func_0205304c` is its writer. | 100% |

The ROM passes 32-byte-aligned spans and 32-byte-rounded sizes, but the C keeps
the constants explicit so the arithmetic stays visible. Values stored through
the halfword fields truncate as the original stores do.

## Hard list

None. All nine functions (the eight card entries plus the enclosing
`func_02052e68`) match without inline assembly or retained non-matching code.
