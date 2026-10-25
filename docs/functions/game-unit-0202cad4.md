# src/game/unit_0202cad4.c

## M1-T418 — verified at 100% objdiff

The original ARM instructions and relocations in the delinked object supply the
contracts below. Neutral names retain uncertainty about the surrounding subsystem.

- `Unk02cad4_Thunk_Unk065e88_Unk_065eac` (0x0202cee0, 12 bytes): calls
  `Unk065e88_Unk_065eac` without arguments; no return value is consumed.
- `Unk02cad4_Thunk_0206148c` (0x0202d150, 12 bytes): calls `func_0206148c`
  without arguments. The relocation supplies the destination evidence.
- `Unk02cad4_Unk_02cbdc` (0x0202cbdc, 16 bytes): stores its unsigned argument
  at `data_0213d338 + 8`; no validation or ownership transfer.
- `Unk02cad4_GetUnk00` (0x0202cbec, 16 bytes): returns the word at
  `data_0213d338 + 0`, including any sentinel value.
- `Unk02cad4_Unk_02ce80` (0x0202ce80, 20 bytes): calls
  `Unk065e88_Unk_065e88`, then selects entry zero through address 0x020e13ac.
- `Unk02cad4_ResetGlobals` (0x0202cbc0, 28 bytes): writes unsigned -1
  to the first three words at `data_0213d338`. The global view describes only
  these accessed fields, not the full allocation.
- `Unk02cad4_Unk_02ce94` (0x0202ce94, 76 bytes): returns immediately when
  `Unk0e1648_Unk_0e1648` is zero. Otherwise reads borrowed records 0 and 1,
  publishes the unsigned maximum of their +0x38 words through
  `Unk02e000_Set_data_0215dd24`, and stores state 1 through the +8 setter.
- `func_0202cdf4` (0x0202cdf4, 140 bytes): short-circuits four index-zero
  `func_020537b8` calls with masks 0x200, 0x100, 4, 8. When all succeed,
  changes a zero byte at `data_0215dd1c` to 1 and returns 1; an already
  nonzero byte returns 0. A failed test clears exactly a byte value of 1
  and returns 0. Other byte values remain unchanged. Returning the zero
  assignment in the clear branch reproduces the original register reuse.

## M1-T419 — verified at 100% objdiff

- `func_0202cad4` (0x0202cad4, 236 bytes): dispatches the selected
  28-byte table entry through enter/update/leave callbacks. Phase zero optionally
  configures its display; phase one waits for the pending state to cease being
  unsigned -1; phase two optionally cleans up, saves the previous state, installs
  the pending state, and resets the phase. No parameters or ownership transfer.
  Evidence: original table stride, indirect calls, and global field accesses.
- `func_0202cbfc` (0x0202cbfc, 280 bytes): initializes services, configures
  three slots, seeds one slot from a three-word startup record (or 2048 on failure)
  and another from the XOR of eight words, then requests initial state zero and
  clears the input latch. Returns 1. Evidence: original calls and main's single
  invocation before its frame loop. Separate product/factor locals preserve the
  original multiplication evaluation and register allocation.
- `func_0202cd14` (0x0202cd14, 224 bytes): performs the per-frame service and
  dispatcher calls. Modes 2 and 3 also update the +0x18 global value, conditionally
  increment a counter, and process the four-mask input latch. An activated latch
  triggers the early return path; otherwise the function runs the final service
  and polls GXSTAT geometry-busy bit 27 until clear. Returns 1 on both paths.
  Evidence: main's frame-loop call and the original MMIO address 0x04000600.
- `Unk02cad4_SetupDisplayMode` (0x0202ceec, 612 bytes): retains the existing
  matching layout setup for modes 0 through 3. Arguments are mode, an unused word,
  and a word forwarded to the display initialization calls; no ownership transfer.
  Evidence for the descriptive name: named palette/plane resources and display
  setup callees in each branch. Other modes only call the common initial helper.

The global view now describes accessed words through +0x18; its first three
words alone are reset to unsigned -1. Callback entries and startup buffers are
borrowed. Existing symbol names remain unchanged for relocation compatibility.

## Hard list

None. All twelve functions in this translation unit match at 100%.
