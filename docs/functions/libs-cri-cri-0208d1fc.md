# CRI unit 0208d1fc

This unit reconstructs the eight ACSVHL accessor and teardown helpers between
0x0208d244 and 0x0208d548. A repository search for `ACSVHL` and a search of the
known public CRI/ADX Nintendo DS reconstructions found no matching source, so
the functions are written from their delinked ARM instruction evidence. The unit
stays linked from the delink until a human marks it `complete` in
`config/arm9/delinks.txt`.

The record layout is established by the still-delinked constructor
`func_0208d500`, which clears offsets 0 and 4, zeroes a 68-byte buffer at offset
8, then writes offsets 0x4c, 0x50, 0x54, 0x58 and 0x5c (values 0, 0, 30, 60 and
120). `func_0208d1fc` rejects work sizes below 0x60, so the visible record is
0x60 bytes. The literals used by that Create function read
`E2003091209 ACSVHL_Create : Work pointor is NULL.` and
`E2003091210 ACSVHL_Create : Work size is too small.`; the record is exposed as
`AcsvhlWork` in `include/libs/CRI/cri_0208d1fc.h`.

## Evidence and interpretation

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_0208d244` | Resets a record through `func_0208d500`. `cmp r0,#0; popeq {r3,pc}` skips the call for a null record; the record pointer is caller-owned. Evidence: `func_0208d500` is the routine Create calls after validating the work area, and the destroy path at 0x0208af40 calls this entry immediately after `func_0208d2d8` releases the offset-4 handle. | 100% |
| `func_0208d2d8` | Loads the offset-4 worker handle, returns when it is null, otherwise calls `func_0208c814(handle)` and stores zero back at offset 4 (`mov r0,#0; str r0,[r4,#4]`). This is the release path paired with handle creation. | 100% |
| `func_0208d2fc` | `mov r1,#0; str r1,[r0,#76]`: clears the 32-bit word at offset 0x4c and returns nothing. | 100% |
| `func_0208d308` | `ldr r0,[r0,#76]`: returns the 32-bit word at offset 0x4c, the value cleared by `func_0208d2fc`. | 100% |
| `func_0208d310` | `ldrsb r0,[r0,#80]`: returns the signed state byte at offset 0x50. `func_0208d330` compares this byte against 0..3 and `func_0208d548` writes it, confirming a signed state field. | 100% |
| `func_0208d318` | `ldr ip,[pc,#4]; ldr r0,[r0,#4]; bx ip` with the `func_0208c830` literal: tail-forwards the offset-4 handle. `func_0208c830` returns the word at handle + 0x1c, so this entry returns a `u32`. | 100% |
| `func_0208d328` | `str r1,[r0]`: stores the caller's pointer in offset 0. `func_0208d330` reads that field as the base of a four-entry pointer array (`ldr r0,[r4]; ldr r8,[r0,r6,lsl #2]`). | 100% |
| `func_0208d548` | `strb r1,[r0,#80]`: writes the signed state byte at offset 0x50; the setter paired with `func_0208d310` and used by the `func_0208d330` state machine. | 100% |

No function name was made descriptive: the only strong evidence is the
`ACSVHL_Create` string, which names the module/record (`AcsvhlWork`) rather than
the individual accessors. The linker-visible names stay neutral.

No module boundary changed. Only the record type and prototypes for the
delinked neighbors (`func_0208d500`, `func_0208c814`, `func_0208c830`) are
declared, in the unit's own C file.

## Validation

The build and objdiff match gate passed: all eight reconstructed functions
report 100%. The checksum gate reports all artifacts byte-identical to the
original. Anticheat passed, and all nine existing unit tests passed. No new
behavioral tests are required by this card: exact instruction matching verifies
each implementation.

## Hard list

None for the eight reconstructed functions. The remaining functions of the TU
(`func_0208d1fc`, `func_0208d258`, `func_0208d330`, `func_0208d500`,
`func_0208d550`, `func_0208d57c`) remain provided by the delinked original, as
required by the card.
