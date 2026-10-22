# src/game/unit_0203e23c.c

Script command handlers. Each one reads its arguments with `func_0203ac00(i)`, returns 1, and
query handlers store their answer with `Unk03aae8_Unk_03acf4` (script result word). All nine are
hand-matched (100%). Linker symbols retain their original names. The typed public declarations and descriptive
`ScriptCmd_*` aliases are in `include/game/unit_0203e23c.h`; aliases describe the observed
callee/data behaviour without assigning unknown opcode numbers or field meanings.

- `Unk03e23c_Unk_03e23c` (`ScriptCmd_GetRecordUnk1f`): result = `Unk02e000_GetRecordUnk1f(arg0)`.
- `Unk03e23c_Unk_03e260` (`ScriptCmd_SetRecordUnk1f`): `Unk02e000_SetRecordUnk1f_2(arg0, arg1)`.
- `Unk03e23c_Unk_03e290` (`ScriptCmd_HasEntryCapacity`): result = `Unk096754_Unk_0969f0()` as 0/1 (entry count below the work-area limit).
- `Unk03e23c_Unk_03e2bc` (`ScriptCmd_HasEntryId`): result = 1 if `Unk096754_HasEntryId(arg0)`, else 0.
- `func_0203e2f8`: obtains the first free entry slot from `Unk096754_Unk_096a14`; if one exists,
  calls `Unk097514_Unk_0977f0(slot, arg0, 0)`. While `BattleTask_Unk_0481d4()` is nonzero it
  records the entry's unk_1e before the call and passes the delta to `func_020494d0(arg0, delta)`
  afterwards. Returns 1 in all cases. Neutral name: the callees do not establish a script opcode.
- `Unk03e23c_Unk_03e36c` (`ScriptCmd_ClearEntryById`): looks up the slot of entry id arg0 (`func_02096af4`) and, if found, passes it to `func_02096958`.
- `Unk03e23c_Unk_03e398` (`ScriptCmd_IsEntryFlagSet`): result = 1 if flag bit `arg0 - 0x6f` is set (`Unk0986ac_Thunk_02098714`), else 0.
- `Unk03e23c_Unk_03e3d0` (`ScriptCmd_GetField3c0Bits`): result = `Unk09ee4c_GetField3c0Bits()`.
- `Unk03e23c_Unk_03e3e4` (`ScriptCmd_AddRecordUnk1e`): adds arg1 to record unk_1e of id arg0; while `BattleTask_Unk_0481d4()` is
  nonzero it also calls `func_020494d0(id, arg1)`. `Unk02e000_SetRecordUnk1e` is declared with an
  `int` id here: the `u32` form reorders the callee-saved registers.

All functions in this TU are now defined in C.

## Hard list
None.
