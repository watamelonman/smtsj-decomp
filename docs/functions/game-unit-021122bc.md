# game/unit_021122bc

All seven functions match the delinked ARM object at 100% with the configured
mwccarm 2.0/sp1p5 compiler. Evidence is the original object's instructions and
relocations; gameplay purpose remains unknown. No hard functions remain.

The local work-area layout exposes the active halfword id at +0x35C and signed
coordinates at +0x364/+0x365. The cell has a byte state at +1 and a halfword
counter at +2; resource entry 19 supplies a bit index from byte +0x19. These
layouts describe only observed accesses and do not claim complete object sizes.

- `Unk1122bc_Unk_1122bc(int id)` (0x021122BC, 60 bytes): returns 1 when
  `id` equals resource lookup `(8,4)` and flag `0x159` equals 1, else 0.
- `func_021122f8(void)` (0x021122F8, 156 bytes): obtains entry 19, the game
  state, and the cell at the current signed coordinates. Calls `func_0209a884`
  with game-state +0x38E8 and +4, updates the cell through the three relocated
  helpers, sets byte +1 to 3 for flag zero or twice the flag minus one otherwise,
  and clears counter +2. Requires valid game-state, resource, and cell pointers.
  The two work-area calls and their left-to-right evaluation match the original.
- `func_02112394(void)` (0x02112394, 164 bytes): increments the current cell's
  halfword counter. If `Unk09a268_Unk_09a844` returns exactly 1, calls the cell
  setters with 1 and entry 19's bit index, increments the byte state with byte
  truncation before comparison, resets states >=4 to zero, clears the counter,
  and returns 1. Otherwise returns 0, retaining the incremented counter.
- `Unk1122bc_IsCurrent(int id)` (0x02112438, 40 bytes): tests equality with
  resource lookup `(8,4)`. The existing name is supported by this comparison
  and the caller at 0x02112460 supplying the active work-area id.
- `Unk1122bc_Unk_112460(void)` (0x02112460, 64 bytes): returns 0 only when
  the active id is current and predicate 0x021122BC returns 0; otherwise 1.
  Fetches the work area again before the second test, as in the original.
- `Unk1122bc_Unk_1124a0(void)` (0x021124A0, 40 bytes): returns 0 when
  predicate 0x021122BC on the active id equals 1, else 1.
- `Unk1122bc_Unk_1124c8(void)` (0x021124C8, 40 bytes): returns 2 when
  predicate 0x021122BC on the active id equals 1, else 0.

Validation uses instruction matching rather than host behavior tests: the card
requires no new tests, and matching verifies the exact calls, accesses, signed
coordinate loads, conditional instructions, and register allocation.
