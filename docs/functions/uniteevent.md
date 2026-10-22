# src/UniteEvent.c

Fusion ("Unite") event translation unit, `0x0210B98C`-`0x0210FE28`. All functions
below were hand-matched to the delinked ARM code; `UniteEvent` is the object reached
through `data_02176e48`, and `EventMsg` is its message format (flags byte + optional
32-bit values).

- `func_0210b98c` — initialises one descriptor: writes `852` at +0x00, `3` at +0x04,
  and six handler pointers at +0x0C..+0x20 (including `UniteEvent_HandleMessage`).
  The load relocation at `0x021503E0` points to this initialiser. Neutral name: no
  string or caller identifies its role beyond the table shape.
- `UniteEvent_HandleMessage` — message handler for the event. Message 0 sets state 1
  and reads mode (argument 3, mode 3 sets `skipRequested` and resets mode) and icon
  (argument 4). Message 3 moves state 18 to 19 when argument 0 is 7. Messages 1, 2 and
  4 do nothing.
- `UniteEvent_SetState` — stores the new state and clears the +0x25C progress field.
- `UniteEvent_CopyIds` — copies `n` 16-bit ids into +0x266 through `func_0200866c`
  and records the count at +0x27E; does nothing when `data_02176e48` is null.
- `UniteEvent_SetId` — marks the id valid at +0x330 and stores the 16-bit id at
  +0x280; does nothing when `data_02176e48` is null.
- `UniteEvent_SetCtxUnk32c` — sets the +0x32C flag when `data_02176e48` is non-null.
- `UniteEvent_LoadEffects` — formats `"Data/Effect/%s"` twice (`data_02151418` for the
  medium, `data_02151428` for the effect), converts each result with `func_0206f6e4`
  and stores the bytes at destination +4.
- `func_0210fa60` — called by the state machine in `func_0210bc2c` with the slots at
  `UniteEvent+0x1E0`/`+0x21C`; zeroes +0x14..+0x1C, loads a resource with constant
  `0x3F800000`/`5` arguments, looks up an entry with `func_02044618` and applies up
  to two id pairs with `Unk06ae94_SetPair`. Always returns 1. Neutral name: no string
  identifies it.

## Hard list

None. All eight functions in M1-T1051 match at 100% in objdiff.
