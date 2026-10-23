# game/unit_020d1c98

All six functions match the delinked ARM original at 100% in objdiff.
The partial resource and work layouts describe only offsets accessed here;
no screen or resource identity is established, so neutral names are retained.

- `Unk0d1c98_Unk_0d1c98(work)` (28 bytes): calls `func_020629c4`
  on the resource at work +4 and clears that ownership slot.
- `func_020d1cb4()` (152 bytes): initializes the singleton only when absent,
  allocating 20 bytes with the three callbacks, requesting resource `(5, 1, 0, 1)`,
  and clearing its state word. Allocation and field accesses establish the layout.
- `Unk0d1c98_Release()` (72 bytes): releases the singleton's resource,
  clears its slot, calls `func_02061424` on the work, and clears the global.
  The release name is supported by these paired cleanup calls and cleared pointers.
- `Unk0d1c98_Unk_0d1d94(arg0, arg1)` (16 bytes): forwards both words
  to `func_020d1da4` with the third argument zero.
- `func_020d1da4(arg0, arg1, arg2)` (240 bytes): optionally forwards arg2,
  submits arg0 to the resource operation, calls the work helper, and records the
  excess above 50 of a derived value capped at 190. State 0 becomes 3 with +16
  cleared; state 4 becomes 3. Records arg1 at +12. Meaning follows the original
  calls and offsets; no higher-level purpose is inferred.
- `func_020d1e94(arg0)` (84 bytes): when initialized and in state 2 or 3,
  nonzero arg0 selects state 4 and sets +16; zero arg0 sets +12 instead.
  A local work pointer and switch cases preserve the original pointer reuse and
  separate equality comparisons.

## Hard functions

None.
