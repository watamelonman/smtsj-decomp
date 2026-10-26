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

## M1-T984: setters, thunks and work-object getter

Names retain the configured symbols. Field stores and call shapes come from the
delinked `src/ScanVisor.o`; they do not establish further gameplay meaning.

- `ScanVisor_SetUnkFields24_28` (0x020a43e8, 12 bytes): `str r1,[r0,#36];
  str r2,[r0,#40]; bx lr`. Stores the caller's pair in a slot record at
  +0x24/+0x28. `ScanVisor_Unk_0a4864` passes (8, 0) and `ScanVisor_Unk_0a42f0`
  passes (0, 0); the value units remain unknown.
- `ScanVisor_Unk_0a4904` (0x020a4904, 12 bytes): `mov r1,#1;
  str r1,[r0,#444]; bx lr`. Sets the word at +0x1bc to 1 on the list object;
  `ScanVisor_Unk_0a2920` passes base+0x24c.
- `ScanVisor_ClearUnkField198` (0x020a4988, 12 bytes): `mov r1,#0;
  str r1,[r0,#408]; bx lr`. Clears +0x198 on the list object passed at
  base+0x24c by `ScanVisor_Unk_0a2acc` and `ScanVisor_Unk_0a2b7c`.
- `ScanVisor_Thunk_020a4600` (0x020a49cc, 12 bytes): `ldr ip,[pc]; bx ip`
  with an ABS32 relocation to `ScanVisor_AnySlotField14` (0x020a4600). The
  typed `u8 *` parameter explicitly forwards the borrowed list pointer and
  the thunk returns the callee's integer 0/1 result. The caller at 0x020a35bc
  passes base+0x24c, calls at 0x020a35c0, and compares r0 with zero at
  0x020a35c4, establishing that the return value must be preserved.
- `ScanVisor_Get_data_02176b04` (0x020a2cfc, 16 bytes): `ldr r0, literal;
  ldr r0,[r0]; bx lr`, returning the bss word at 0x02176b04. Callers
  null-check it before using the result as the work-object base.
- `ScanVisor_Unk_0a3620` (0x020a3620, 16 bytes): `ldr ip,[pc,#4];
  add r0,r0,#588; bx ip` to `ScanVisor_Unk_0a4a44`. Forwards the list object
  at base+0x24c; `ScanVisor_Draw` supplies the visor pointer.
- `ScanVisor_Unk_0a465c` (0x020a465c, 16 bytes): `mov r1,#0;
  str r1,[r0,#16]; str r1,[r0,#20]; bx lr`. Clears the two words at
  +0x10/+0x14 on the idle slot returned by `ScanVisor_FindSlotByKey`.
- `ScanVisor_Unk_0a4a30` (0x020a4a30, 20 bytes): `ldr ip,[pc,#8];
  mov r1,#1; mov r2,r1; bx ip` to `ScanVisor_Unk_0a4950`. Forwards the list
  object at base+0x24c with arguments (1, 1); the callee owns all stores.

Validation: all eight functions report 100% in `build/report.json` after
re-typing their parameters; the match gate, anticheat gate and original-image
checksum gate pass. No new tests were required by this card.

No hard functions for M1-T984.

## Existing work on other cards

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
