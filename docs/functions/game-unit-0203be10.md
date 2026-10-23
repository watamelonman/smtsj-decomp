# src/game/unit_0203be10.c

All seven functions match at 100% in objdiff. Evidence below is from the
ARM9 instructions at each function's address and their symbolized calls.
Names remain neutral because the exact gameplay purpose is not established.
All seven functions take no arguments.

- `Unk03be10_Unk_03be10` (0x0203be10, 24 bytes): calls
  `ImageBg_IsMode1or2` and returns 1 exactly when its result is not 1.
  Used as the first manager callback by `func_0203be54` in modes 2–4.
- `Unk03be10_Unk_03be28` (0x0203be28, 24 bytes): calls
  `ImageBgDual3D_Unk_125ca4` with the same boolean return contract.
  Used as the first manager callback in mode 5.
- `Unk03be10_Unk_03be40` (0x0203be40, 20 bytes): passes 2 to
  `func_020773dc`, then returns 1. Installed as the second mode-0 callback
  by `func_0203be54`.
- `func_0203be54` (0x0203be54, 224 bytes): obtains script value 0 via
  `func_0203ac00`, explicitly narrows it to signed 16 bits, and clears the
  manager callbacks. Mode 0 initializes helpers, installs callbacks and
  stores the value in slot 0 and 1 in slot 1. Modes 2–4 and 5 pass the value
  to their respective background helpers, clear slot 1, and install a poll
  callback with a null second callback. Supported modes call
  `Unk02dcfc_SetCode7`; every path returns 3.
- `Unk03be10_Unk_03bf34` (0x0203bf34, 116 bytes): returns 0 while
  `func_0206552c` is nonzero or `ImageObj_Unk_077688` is zero. When slot 0
  equals 1, slot 1 equal to 0 triggers `Unk09e72c_Unk_09e8f0` once and is
  set to 1. Slot 1 equal to 1 polls `Unk09d42c_Unk_09e274` and returns 0
  until nonzero. Other ready paths return 1.
- `Unk03be10_Unk_03bfa8` (0x0203bfa8, 20 bytes): passes 1 to
  `func_020773dc`, then returns 1. Installed as the second mode-0 callback
  by `func_0203bfbc`.
- `func_0203bfbc` (0x0203bfbc, 160 bytes): clears manager callbacks and
  dispatches on `func_02095818`. Mode 0 returns 1 immediately when
  `ImageBg_IsSet_data_02176ca4` is zero; otherwise initializes helpers,
  installs the paired callbacks, calls `ImageBg_Unk_0e5530`, and sets
  slots 0 and 1 to 1 and 0. Modes 2–4 call `ImageBg_Unk_0e550c`; mode 5
  calls `ImageBgDual3D_Unk_125d30`. Supported non-immediate paths set code 7.
  All paths other than the immediate mode-0 completion return 3.

## Validation

`FORGE_BASE=HEAD python3 tools/match_gate.py` reports all seven definitions
at 100%. Anticheat and all nine repository unit tests pass. The checksum
gate reports all artifacts byte-identical to the original. The unit remains
linked from the delink until a human marks it complete.

## Hard list

None.
