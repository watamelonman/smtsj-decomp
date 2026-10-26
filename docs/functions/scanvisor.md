# ScanVisor

## M1-T983: small ARM helpers

Names retain the configured symbols. Evidence below comes from the delinked
`src/ScanVisor.o`; field descriptions do not imply established gameplay meaning.
The source and the eight implementations already existed when this card began.

- `ScanVisor_Nop_0a34a4` (0x020a34a4, 4 bytes): only `bx lr`.
  `ScanVisor_Draw` passes its visor pointer; this callback intentionally does nothing.
- `ScanVisor_Nop_0a34a8` (0x020a34a8, 4 bytes): only `bx lr`.
  The second empty callback also receives the pointer from `ScanVisor_Draw`.
- `ScanVisor_GetConst20` (0x020a2bb0, 8 bytes): `mov r0, #20; bx lr`.
  No parameters; the query returns 20 without accessing state.
- `ScanVisor_Unk_0a45f8` (0x020a45f8, 8 bytes): `ldr r0, [r0, #0x14]; bx lr`.
  Requires a valid object and returns its unsigned word at +0x14; semantic name unknown.
- `ScanVisor_GetConst6` (0x020a4e40, 8 bytes): `mov r0, #6; bx lr`.
  No parameters; the query returns 6 without accessing state.
- `ScanVisor_Thunk_020fc6b8` (0x020a28e8, 12 bytes): loads `ip` from a
  literal with an ABS32 relocation to `Unk0fc584_SetDir`, then `bx ip`.
  The C no-argument forwarding call preserves this tail-call implementation.
- `ScanVisor_GetSlot` (0x020a42b8, 12 bytes): adds `index << 2` to the
  object pointer and loads the word at +0x1c0. Caller supplies a valid table
  index and object; no check exists in the original. The declaration's 16-word
  extent is inherited and is not established by this accessor alone.
- `ScanVisor_SetRange` (0x020a43dc, 12 bytes): stores r1 at +0x1c and r2
  at +0x20, then returns. Requires a valid writable record. The existing range
  symbol is retained; units and ordering constraints are unknown.

Validation: all eight functions report 100% in `build/report.json`; the match
gate, anticheat gate, nine unittest tests, and original-image checksum gate pass.
No new tests were required by this card; objdiff checks the instruction behavior.

No hard functions for M1-T983.

## Existing work on other cards

- `ScanVisor_SetUnkFields24_28`: decompiler-derived
- `ScanVisor_Unk_0a4904`: decompiler-derived
- `ScanVisor_ClearUnkField198`: decompiler-derived
- `ScanVisor_Thunk_020a4600`: decompiler-derived
- `ScanVisor_Get_data_02176b04`: decompiler-derived
- `ScanVisor_Unk_0a3620`: decompiler-derived
- `ScanVisor_Unk_0a465c`: decompiler-derived
- `ScanVisor_Unk_0a4a30`: decompiler-derived
- `ScanVisor_Unk_0a4644`: decompiler-derived
- `ScanVisor_Unk_0a2a1c`: decompiler-derived
- `ScanVisor_Unk_0a2ab0`: decompiler-derived
- `ScanVisor_Unk_0a2acc`: decompiler-derived
- `ScanVisor_Unk_0a27e0`: decompiler-derived
- `ScanVisor_Unk_0a2800`: decompiler-derived

## Not done in M1-T985
- `ScanVisor_Unk_0a4a18`
- `ScanVisor_Unk_0a2980`
- `ScanVisor_Unk_0a2b18`: decompiler-derived
- `ScanVisor_Unk_0a2b38`: decompiler-derived
- `ScanVisor_Unk_0a29a0`: decompiler-derived
- `ScanVisor_Unk_0a29c4`: decompiler-derived
- `ScanVisor_Unk_0a2a8c`: decompiler-derived
- `ScanVisor_Unk_0a2a38`: decompiler-derived

## Not done in M1-T986
- `ScanVisor_Unk_0a3254`
- `ScanVisor_Unk_0a2b58`
- `ScanVisor_Unk_0a28f4`: decompiler-derived
- `ScanVisor_Unk_0a2a60`: decompiler-derived
- `ScanVisor_Unk_0a42c4`: decompiler-derived

## Not done in M1-T987
- `ScanVisor_SetField34`
- `ScanVisor_SetRangeA`
- `ScanVisor_SetField214`
- `ScanVisor_Unk_0a4a44`
- `ScanVisor_Unk_0a2920`
- `ScanVisor_Unk_0a2ae8`: decompiler-derived
- `ScanVisor_Unk_0a29e8`: decompiler-derived
- `ScanVisor_Unk_0a2b7c`: decompiler-derived
- `ScanVisor_Unk_0a4544`: decompiler-derived
- `ScanVisor_Unk_0a27a8`: decompiler-derived

## Not done in M1-T988
- `ScanVisor_Unk_0a2950`
- `ScanVisor_Unk_0a379c`
- `ScanVisor_FindEnt20`
- `ScanVisor_Unk_0a284c`: decompiler-derived
- `ScanVisor_Unk_0a28b0`: decompiler-derived
- `ScanVisor_Unk_0a2660`: decompiler-derived
- `ScanVisor_Unk_0a273c`: decompiler-derived

## Not done in M1-T989
- `ScanVisor_FindSlotByKey`
- `ScanVisor_Unk_0a4950`
- `ScanVisor_AllSlotsF28Is80`
- `ScanVisor_Unk_0a3760`

## Not done in M1-T990
- `ScanVisor_Unk_0a4910`
- `ScanVisor_SetById`
- `func_020a3ac0`
- `ScanVisor_AnySlotField14`
- `ScanVisor_ResetBits`
- `ScanVisor_Unk_0a4578`
- `ScanVisor_Unk_0a4864`
- `ScanVisor_Unk_0a48b4`

## Not done in M1-T991
- `func_020a4df0`
- `ScanVisor_LoadSearchParts`
- `ScanVisor_Unk_0a3274`
- `func_020a30b4`
- `func_020a466c`
- `func_020a2c90`
- `func_020a4370`
- `ScanVisor_Unk_0a42f0`
- `ScanVisor_Unk_0a2e5c`: decompiler-derived

## Not done in M1-T992
- `func_020a2c00`
- `func_020a269c`
- `func_020a3008`
- `func_020a2f3c`
- `func_020a3630`
- `ScanVisor_Draw`
- `func_020a2d0c`
- `ScanVisor_LoadSearchParts`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4a44`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4950`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4864`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4910`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Unk_0a48b4`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Unk_0a42f0`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Draw`: hand-matched
- `ScanVisor_SetById`: hand-matched
- `ScanVisor_Unk_0a4a18`: hand-matched
- `ScanVisor_SetField34`: hand-matched
- `ScanVisor_SetRangeA`: hand-matched
- `ScanVisor_SetField214`: hand-matched
- `ScanVisor_Unk_0a2920`: hand-matched
- `ScanVisor_Unk_0a2950`: hand-matched
- `ScanVisor_Unk_0a2980`: hand-matched
- `ScanVisor_Unk_0a2b58`: hand-matched
- `ScanVisor_ResetBits`: hand-matched
- `ScanVisor_Unk_0a3254`: hand-matched
- `ScanVisor_Unk_0a3760`: hand-matched
- `ScanVisor_Unk_0a379c`: hand-matched
- `ScanVisor_FindEnt20`: hand-matched
- `ScanVisor_Unk_0a4578`: hand-matched
- `ScanVisor_FindSlotByKey`: hand-matched
- `ScanVisor_AnySlotField14`: hand-matched
- `ScanVisor_AllSlotsF28Is80`: hand-matched
- `ScanVisor_Unk_0a3274`: hand-matched
