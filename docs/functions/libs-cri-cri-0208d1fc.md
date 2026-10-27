# CRI unit 0208d1fc

This unit reconstructs the fourteen ACSVHL entry points between 0x0208d1fc and
0x0208d5ac. A repository search for `ACSVHL` and a search of the known public
CRI/ADX Nintendo DS reconstructions found no matching source, so the functions
are written from their delinked ARM instruction evidence. The unit stays linked
from the delink until a human marks it `complete` in `config/arm9/delinks.txt`.

The record layout is established by `func_0208d500`, which clears offsets 0 and
4, zeroes a 68-byte buffer at offset 8, then writes offsets 0x4c, 0x50, 0x54,
0x58 and 0x5c (values 0, 0, 30, 60 and 120). `func_0208d1fc` rejects work sizes
below 0x60, so the visible record is 0x60 bytes. The literals used by the unit
read `E2003091209 ACSVHL_Create : Work pointor is NULL.`,
`E2003091210 ACSVHL_Create : Work size is too small.`,
`E2003091600 ACSVHL_Init : Already initialized.` and
`E2003091601 ACSVHL_Init : Failed to initialize ACSFDR.` at data_0214946c,
data_021494a0, data_021494d4 and data_02149504; the record is exposed as
`AcsvhlWork` in `include/libs/CRI/cri_0208d1fc.h`.

## Evidence and interpretation

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_0208d1fc` | Create. `movs r4,r0; bne` rejects a null work pointer with the "Work pointor is NULL." literal; `cmp r1,#96; bcs` rejects a size below sizeof(AcsvhlWork) with "Work size is too small." and returns 0 on both paths. Otherwise it calls `func_0208d500` and returns the work pointer (`mov r0,r4`). | 100% |
| `func_0208d244` | Resets a record through `func_0208d500`. `cmp r0,#0; popeq {r3,pc}` skips the call for a null record; the record pointer is caller-owned. Evidence: `func_0208d500` is the routine Create calls after validating the work area, and the destroy path at 0x0208af40 calls this entry immediately after `func_0208d2d8` releases the offset-4 handle. | 100% |
| `func_0208d258` | Init. A non-zero offset-4 handle logs "Already initialized." and returns 0. Otherwise `func_0208c7cc(work + 8, 68)` creates the ACSFDR worker over the 68-byte buffer, the handle is stored at offset 4, and a null result logs "Failed to initialize ACSFDR." and returns 0. Success calls `func_0208c850(handle, 0, 0, 0, 0)` (r1..r3 and the stack word are zero) and returns 1. | 100% |
| `func_0208d2d8` | Loads the offset-4 worker handle, returns when it is null, otherwise calls `func_0208c814(handle)` and stores zero back at offset 4 (`mov r0,#0; str r0,[r4,#4]`). This is the release path paired with handle creation. | 100% |
| `func_0208d2fc` | `mov r1,#0; str r1,[r0,#76]`: clears the 32-bit word at offset 0x4c and returns nothing. | 100% |
| `func_0208d308` | `ldr r0,[r0,#76]`: returns the 32-bit word at offset 0x4c, the value cleared by `func_0208d2fc`. | 100% |
| `func_0208d310` | `ldrsb r0,[r0,#80]`: returns the signed state byte at offset 0x50. `func_0208d330` compares this byte against 0..3 and `func_0208d548` writes it, confirming a signed state field. | 100% |
| `func_0208d318` | `ldr ip,[pc,#4]; ldr r0,[r0,#4]; bx ip` with the `func_0208c830` literal: tail-forwards the offset-4 handle. `func_0208c830` returns the word at handle + 0x1c, so this entry returns a `u32`. | 100% |
| `func_0208d328` | `str r1,[r0]`: stores the caller's pointer in offset 0. `func_0208d330` reads that field as the base of a four-entry pointer array (`ldr r0,[r4]; ldr r8,[r0,r6,lsl #2]`). | 100% |
| `func_0208d330` | Update. The loop scans the four pointers at offset 0 (counter r6, bound 4); a channel must be non-null, pass `func_0208b8ec`, report 2 from `func_0208bac0`, and `func_0208ba58` selects its kind. The original kind dispatch is a five-entry jump table (`cmp r0,#4; addls pc,pc,r0,lsl #2`) whose entries for kinds 0, 3 and 4 return to the loop and whose kind 1/2 entries call `func_0208ba20` and raise the `any` flag (r7) when it returns 0. The signed byte at 0x50 then drives a four-entry jump table (`cmp r0,#3; addls`): state 0 starts a fade-in with `-0x5c` and 0x54 and moves to 1; state 1 either starts `func_0208d550` or, when `func_0208c828` reports completion, moves to 2; state 2 starts a fade from 0 with 0x58 and moves to 3; state 3 either starts `func_0208d57c` or moves back to 0 on completion. Every `func_0208c850` call passes two trailing zeros (r3 and the stack word), and `func_0208c8ec(handle)` runs last on every path. The empty kind cases are written out because that is what makes mwcc emit the same five-entry table; the compare-chain form compiles to a different shape. | 100% |
| `func_0208d500` | `str r1,[r4]` and `str r1,[r4,#4]` clear offsets 0 and 4, `add r0,r4,#8; mov r2,#68; bl func_020119c0` zeroes the 68-byte buffer at offset 8, and `str r0,[r4,#76]`, `strb r0,[r4,#80]`, `mov r0,#30/#60/#120; str` write 0 to 0x4c/0x50 and 30/60/120 to 0x54/0x58/0x5c. Offset 4 is stored after the memset arguments are set up, so the two clear stores are not adjacent in the original. | 100% |
| `func_0208d548` | `strb r1,[r0,#80]`: writes the signed state byte at offset 0x50; the setter paired with `func_0208d310` and used by the `func_0208d330` state machine. | 100% |
| `func_0208d550` | Loads the 0x54 interval, asks `func_0208c830` for the worker progress, multiplies the two (`mul r0,r4,r0`), negates the 0x5c range (`ldr r1,[r5,#92]; rsb r1,r1,#0`), divides with `_s32_div_f` and returns interval minus quotient (`sub r0,r4,r0`). The negative divisor is dictated by the original `rsb`, not by the reconstruction. | 100% |
| `func_0208d57c` | Same shape for the 0x58 step: progress from `func_0208c830` times the 0x58 value (`mul r0,r2,r0`), the negated 0x5c range, `_s32_div_f`, and the quotient subtracted from the 0x54 hold value (`ldr r1,[r4,#84]; sub r0,r1,r0`). | 100% |

No function name was made descriptive: the only strong evidence is the ACSVHL
strings, which name the module/record (`AcsvhlWork`) rather than the individual
entry points. The linker-visible names stay neutral.

No module boundary changed. The record type and the prototypes of the delinked
neighbours (`func_0208b494`, `func_0208b8ec`, `func_0208ba20`, `func_0208ba58`,
`func_0208bac0`, `func_020119c0`, `func_0208c7cc`, `func_0208c814`,
`func_0208c828`, `func_0208c830`, `func_0208c850`, `func_0208c8ec`,
`_s32_div_f`) are declared in the unit's own C file.

## Validation

The build and objdiff match gate passed: all fourteen reconstructed functions
report 100%. The checksum gate reports all artifacts byte-identical to the
original. Anticheat passed, and all nine existing unit tests passed. No new
behavioral tests are required by this card: exact instruction matching verifies
each implementation.

## Hard list

None. All functions of the translation unit are now reconstructed in C.
