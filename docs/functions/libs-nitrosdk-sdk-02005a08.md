# NitroSDK OS spin locks and IRQ mask helper (0x02005a08)

Six functions match the original ARM instructions, literal pools and call
relocations at **100%** in objdiff using mwccarm 2.0/sp1p5. Two functions are
left on the hard list; they continue to link from the delinked object. The
original `func_` symbols are retained for objdiff and linking. This TU remains
linked from the delink until a human marks it `complete`.

## Public source evidence

The implementations correspond to
[pret/pokediamond's OS_spinLock.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/OS_spinLock.c)
and
[OS_interrupt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/OS_interrupt.c).
The interrupt handler covers `OS_ResetRequestIrqMask`; the lock functions cover
`OSi_DoLockByWord`, `OS_TryLockByWord`, `OSi_DoUnlockByWord`,
`OS_UnlockByWord` and `OSi_DoTryLockByWord`. The delinked call targets match the
same helpers in this ROM: `func_02007a84`/`func_02007a58` disable IRQ+FIQ or IRQ
only, `func_02007a98`/`func_02007a6c` restore those states, `func_02008a94` is
the single-word swap, and `WaitByLoop` is the BIOS wait entry. No assembly from
the reference is used.

`OSLockWord` is declared as a borrowed volatile view with the original
`lockFlag`, `ownerID` and `extension` fields. The lock words themselves live at
their original main-RAM locations and are owned by the OS boot state.

## Function entries

| Original symbol | SDK equivalent | Contract and behavior | Match |
| --- | --- | --- | --- |
| `func_02005a08` | `OS_ResetRequestIrqMask` | Saves and disables REG_OS_IME, returns REG_OS_IF, writes the new request mask to REG_OS_IF while IME is off, then restores IME. `mask` is a 32-bit IRQ request mask. | 100% (44 bytes) |
| `func_02005a34` | `OS_SetIrqStackChecker` | Writes `0xfddb597d` below the SVC stack top and `0x7bf9dd5b` at the top of the carved IRQ stack. | hard list |
| `func_02005a68` | `OS_InitLock` | One-time initialization: clears the boot lock word, tries lock id `0x7e`, waits until the extension halfword clears, resets the lock-ID words, zeroes the shared lock buffer, gives the card/cartridge buses to ARM7, then unlocks and tries lock id `0x7f`. | hard list |
| `func_02005b34` | `OSi_DoLockByWord` | Repeats `func_02005c14` while it returns a positive value, yielding with `WaitByLoop(0x400)` between attempts; returns the final zero or negative status. | 100% (76 bytes) |
| `func_02005b80` | `OS_TryLockByWord` | Forwards to `OSi_DoLockByWord` with `disableFiq = 0`; never waits for an owner. | 100% (16 bytes) |
| `func_02005b90` | `OSi_DoUnlockByWord` | Returns `-2` when `lockId` is not the stored owner. Otherwise saves the requested interrupt state, clears `ownerID`, runs the optional bus callback, clears `lockFlag`, restores interrupts and returns 0. | 100% (116 bytes) |
| `func_02005c04` | `OS_UnlockByWord` | Forwards to `OSi_DoUnlockByWord` with `disableFiq = 0`, leaving FIQ enabled. | 100% (16 bytes) |
| `func_02005c14` | `OSi_DoTryLockByWord` | Saves the requested interrupt state, swaps `lockId` into `lockFlag`, and if the old flag was zero runs the optional bus callback and records `lockId` as owner. Restores interrupts and returns the previous flag. | 100% (108 bytes) |

Callers supply a valid `OSLockWord *`; the SDK routines perform no null checks.
`lockId` values are 16-bit owner tags. The two `disableFiq` variants differ only
in whether FIQ is masked for the duration of the lock operation.

## Validation

The original object provides the executable reference in place of new unit
tests (the card sets `tests_required = false`). The match gate verifies every
compiled function body, including the interrupt-mask accesses, the thunk tail
calls, the compare-and-swap path and the literal pools. The checksum gate
verifies the original linked image, and the anticheat and unit-test gates also
pass.

## Hard list

- `func_02005a34` (`OS_SetIrqStackChecker`): the target loads the DTCM base via
  the `data_027e0000` relocation, but its `0x400` IRQ-stack size comes from a
  linker-defined value that the delinked object stores as an unrelocated
  `.word 0x400`. Writing the size as a plain constant folds
  `base + 0x3f80 - 0x400` into one `str [base, #0xb80]`, while keeping an
  external `SDK_IRQ_STACKSIZE` reproduces the exact eight instructions but the
  literal renders as a symbol relocation (99.92%). Numeric casts, enums,
  `sizeof`, pointer/function-pointer constants, `static const` and the
  propagation/folding pragmas were tried; all either fold the subtraction or
  add a `.rodata` load. No faithful source form produced an unrelocated
  `0x400` literal. The delink object still supplies this function.
- `func_02005a68` (`OS_InitLock`): the original has a function-scope static
  `isInitialized` word at `data_0215225c`; matching the reference source
  reproduces the instruction schedule exactly, but the compiler emits an
  `R_ARM_ABS32 .bss` relocation for that local static instead of the delink's
  `R_ARM_ABS32 data_0215225c` relocation (99.90%). File-scope static/global,
  weak, export and volatile declarations all change the register allocation
  away from the target, and direct address literals remove the relocation the
  delinked object expects. The delink object still supplies this function.

To finish these two, a human can extend the delink metadata so the `0x400`
literal keeps a symbol relocation and the static-init word keeps its
`data_0215225c` symbol, or open a scratch with `tools/decompme.py`.
