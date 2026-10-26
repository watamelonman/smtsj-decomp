# src/game/unit_020e8228.c

## M1-T897 verified wrappers

All eight functions match at 100% objdiff. Evidence below comes from the
original ARM instructions and relocations in the delinked object. Unknown
argument meanings retain neutral names; no domain semantics are inferred.

- `Unk0e8228_Nop_0e93d4` (4 B, 020e93d4): `bx lr` only; a no-op callback taking no parameters.
- `Unk0e8228_Thunk_02057534` (12 B, 020e8e60): literal-load and `bx ip` tail-call `func_02057534`, taking no parameters.
- `Unk0e8228_Thunk_02045c38` (12 B, 020e8f68): literal-load and `bx ip` tail-call `Unk044904_GetFlag18`; returns its integer flag result unchanged. The callee implementation in `src/game/unit_02044904.c` confirms the return contract.
- `Unk0e8228_Unk_0e8cd8` (16 B, 020e8cd8): `mvn r0, #0` and a relocation to `ScanVisor_Unk_0a29a0` pass `0xffffffff` as an unsigned sentinel, with no caller parameters.
- `Unk0e8228_Unk_0e8e50` (16 B, 020e8e50): `mov r0, #4` and a relocation to `func_02057524` pass the fixed integer 4, with no caller parameters.
- `Unk0e8228_Unk_0e8e6c` (16 B, 020e8e6c): `mov r0, #2` and a relocation to `func_02057eb8` pass the fixed integer 2, with no caller parameters.
- `Unk0e8228_Unk_0e8e7c` (16 B, 020e8e7c): `mvn r0, #0` and a relocation to `func_02057eb8` pass -1, with no caller parameters.
- `Unk0e8228_Unk_0e8eac` (16 B, 020e8eac): `add r0, r0, #8` and a relocation to `Unk0e8228_Unk_0e8e8c` forward the unsigned argument plus eight. Unsigned arithmetic preserves ARM wraparound for the full input range.

No M1-T897 functions remain on the hard list. The empty callback is intentional,
as demonstrated by its single original return instruction.

## M1-T898 verified functions

All eight functions match at 100% objdiff. Evidence comes from the delinked
ARM instructions and relocations plus the callers named below. Names stay
neutral where the callers only show a loop bound or an opaque forwarding.

- `Unk0e8228_Get_data_02176ce0` (16 B, 020e9038): loads the global pointer
  stored in `data_02176ce0` and returns it. The data symbol supplies the name;
  users treat the result as the shared work object (see
  `Unk0e8228_Unk_0e84e4`).
- `Unk0e8228_Unk_0e8398` (20 B, 020e8398): calls `Unk0e8228_Unk_0e8d90(7,
  0xffffffff)`, forwarding selector 7 and the unsigned -1 sentinel. Callers
  run it before scanning the entries counted by `Unk0e8228_Unk_0e8488()`, but
  the callee is opaque, so the name stays neutral.
- `Unk0e8228_Unk_0e8460` (20 B, 020e8460): returns the word stored at
  `data_02150c30 + 0x2c` plus one. Used as an exclusive loop bound in
  `src/game/unit_020eed24.c` and as a count guard in `src/game/unit_020ea208.c`;
  the meaning of the stored word itself is not established.
- `Unk0e8228_Unk_0e8474` (20 B, 020e8474): returns `*(s32 *)(data_02150c30 +
  0x34) + 1`; `unit_020eed24.c` iterates that many 64-byte records.
- `Unk0e8228_Unk_0e8488` (20 B, 020e8488): returns `*(s32 *)(data_02150c30 +
  0x3c) + 1`; callers use it as a loop bound and compare it with one to detect
  an empty table (`unit_020f0be0.c`, `unit_020f4c50.c`).
- `Unk0e8228_Unk_0e9c94` (20 B, 020e9c94): tail-calls `func_020e9c00(arg0, 2,
  arg1)`, inserting constant selector 2 between the two forwarded arguments.
- `Unk0e8228_Unk_0e84e4` (24 B, 020e84e4): returns the word at shared-work
  offset 0x178, or zero when `Get_data_02176ce0` returns null. Callers compare
  and iterate it as a record count (`src/game/unit_020ef248.c`).
- `Unk0e8228_Unk_0e84fc` (24 B, 020e84fc): calls
  `Unk0e8228_Unk_0e8374(8)`, forwards its result to
  `Unk0e8228_GetArr88Field20`, then forwards that result as the id to
  `Unk09974c_Unk_099d14`; the third call's result is returned, and
  `unit_020ef248.c` consumes it as a borrowed record pointer. The argument
  flow is visible in the delinked original (`mov r0,#8; bl ...; bl ...; bl ...`).

## Other TU functions

- `Unk0e8228_Unk_0e8514` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8b7c` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8b94` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8bac` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8c50` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8c68` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8db8` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8f20` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8f38` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e8f50` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e9020` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0e9048` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0ea028` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_Unk_0ea040` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e8228_IsSet_data_02176cdc` (28 B): decompiler-derived (Ghidra output, cleaned)

## Hard list
- `Unk0e8228_Call_02008848`: no candidate matched locally
- `Unk0e8228_Unk_0e82ac`: decompiler-derived
- `Unk0e8228_Unk_0e8684`: decompiler-derived
- `Unk0e8228_Unk_0e8cbc`: decompiler-derived
- `Unk0e8228_Unk_0e8c9c`: decompiler-derived
- `Unk0e8228_Unk_0e8d18`: decompiler-derived
- `Unk0e8228_Unk_0e940c`: decompiler-derived

## Not done in M1-T901
- `Unk0e8228_Unk_0e8c80`
- `Unk0e8228_Unk_0e8e8c`
- `Unk0e8228_Unk_0e9728`: decompiler-derived
- `Unk0e8228_Unk_0e9f18`: decompiler-derived
- `Unk0e8228_Unk_0e9f38`: decompiler-derived
- `Unk0e8228_Unk_0e8bc4`: decompiler-derived
- `Unk0e8228_Unk_0e8c2c`: decompiler-derived

## Not done in M1-T902
- `Unk0e8228_Unk_0e8374`
- `Unk0e8228_IsField4One`
- `Unk0e8228_IsFieldCOne`
- `Unk0e8228_Unk_0e8dd0`: decompiler-derived
- `Unk0e8228_Unk_0e8dfc`: decompiler-derived
- `Unk0e8228_Unk_0e9fa4`: decompiler-derived

## Not done in M1-T903
- `Unk0e8228_Unk_0e8d90`
- `Unk0e8228_IsState3`
- `Unk0e8228_Unk_0e8ce8`
- `Unk0e8228_GetCurEntry`
- `func_020e93d8`

## Not done in M1-T904
- `Unk0e8228_GetArr30`
- `Unk0e8228_GetArr58`
- `Unk0e8228_GetArr40`
- `Unk0e8228_Unk_0e8fe4`
- `func_020e942c`
- `Unk0e8228_ClearSel`
- `Unk0e8228_Unk_0e8be8`
- `func_020e9b10`
- `Unk0e8228_Unk_0e85c8`: decompiler-derived

## Not done in M1-T905
- `Unk0e8228_GetArr88Field20`
- `Unk0e8228_Unk_0e8260`
- `func_020e9f58`
- `func_020e8d38`
- `func_020e9fd0`
- `func_020e8628`
- `func_020e8ebc`

## Not done in M1-T906
- `func_020e946c`
- `func_020e9b54`
- `func_020e86a0`
- `func_020e8f74`
- `func_020e9814`
- `func_020e9aa0`
- `func_020e852c`
- `func_020ea0ec`

## Not done in M1-T907
- `func_020e9884`
- `func_020e9c00`
- `func_020ea058`
- `func_020e9778`
- `func_020ea160`
- `func_020e82c8`
- `func_020e8a30`
- `func_020e92a8`

## Not done in M1-T908
- `func_020e9de4`
- `func_020e9ca8`
- `func_020e9900`
- `func_020e9060`
- `func_020e94d8`
- `func_020e8710`
- `Unk0e8228_Call_02008848`: decompiler-derived (plain cleanup)
- `Unk0e8228_Unk_0e8e8c`: decompiler-derived (plain cleanup)
- `Unk0e8228_Unk_0e8d90`: decompiler-derived (plain cleanup)
- `Unk0e8228_Unk_0e8260`: hand-matched
- `Unk0e8228_Unk_0e8374`: hand-matched
- `Unk0e8228_GetArr30`: hand-matched
- `Unk0e8228_GetArr58`: hand-matched
- `Unk0e8228_GetArr40`: hand-matched
- `Unk0e8228_GetArr88Field20`: hand-matched
- `Unk0e8228_IsField4One`: hand-matched
- `Unk0e8228_IsFieldCOne`: hand-matched
- `Unk0e8228_Unk_0e8be8`: hand-matched
- `Unk0e8228_Unk_0e8c80`: hand-matched
- `Unk0e8228_Unk_0e8ce8`: hand-matched
- `Unk0e8228_IsState3`: hand-matched
- `Unk0e8228_Unk_0e8fe4`: hand-matched
- `Unk0e8228_GetCurEntry`: hand-matched
- `Unk0e8228_ClearSel`: hand-matched
