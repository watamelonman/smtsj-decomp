# sdk_0208dc78 (M2-T378)

This card reconstructs eight of the fourteen functions in the delinked
`libs/NitroSDK/sdk_0208dc78.c` range (`0x0208dc78..0x0208e1f0`). A search of
this repository found no existing implementation of these routines; the
surrounding CRI units identify the data they operate on, so the bodies are
written from the delinked ARM instructions and relocations. The remaining six
functions in the range belong to M2-T379 and stay on the delink. The
translation unit is still linked from `config/arm9/delinks.txt` until a human
marks it `complete`.

The shared state is the CRI sound singleton at `data_02175ccc` already
described by `libs/CRI/cri_0208d8e8.c`: `+0x00` is the initialised flag,
`+0x04` the pending-notification word, `+0x08` the two-record table, `+0x0c`
the record count and `+0x18` the master volume. Each record is `0x58` bytes;
only the fields touched by these functions are named in
`include/libs/NitroSDK/sdk_0208dc78.h`.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_0208dc78` | Calls `func_0208dad8(0, 4, 1)`, prepares record zero with `func_0208dea4(0, 1, 1)`, then copies the value returned by `func_0205e5dc` into the singleton's master-volume word at `+0x18`. Evidence: the three literal argument words before each call and the `str r0,[r1,#0x18]` at `0208dc78..0208dcb0`. |
| `func_0208dd44` | Calls the sound-system register update `func_020795b8`, then calls `func_02029e6c` only when the pending-notification word at `+0x04` is zero. Evidence: the `ldr [r0,#4]`/`cmp`/`popne` and the conditional second call at `0208dd44..0208dd68`. |
| `func_0208df0c` | Releases record `index` through `func_0207990c(record->unk_00)` and clears its assigned byte `+0x0c` and playing byte `+0x0d`. A record whose `+0x0c` byte is zero is left untouched. Evidence: the `mla r4,r0,#0x58,table`, the `+0x0c` guard and the two `strb` clears at `0208df0c..0208df48`. |
| `func_0208e0e8` | Starts a record update: stores the caller's step at `+0x50`, clears the position at `+0x54`, sets the reverse-update byte `+0x0f`, calls `func_02079b4c(record->unk_00, 0)`, then clears the playing byte `+0x0d`. Records that are not assigned or not playing are skipped. Evidence: the conditional `ldrbne`/`cmpne`, the store pair, the `mov r0,#1` before `strb +0x0f`, and the zero kept in `r1` for both `+0x54` and the callee's second argument at `0208e0e8..0208e13c`. |
| `func_0208e13c` | Returns one when record `index` has a nonzero playing byte `+0x0d`, otherwise zero. Evidence: the `mla` stride and the `ldrb`/`cmp`/`movne`/`moveq` sequence at `0208e13c..0208e164`. |
| `func_0208e164` | Queries record `index` through `func_020799d4(record->unk_00)` and reports one for status one (active) or two (paused), zero otherwise. Evidence: the `mla`-style `mul` stride, the single call and the `cmp #1`/`beq`/`cmp #2`/`bne` chain with duplicated return-one blocks at `0208e164..0208e1ac`. The goto/switch source shape is required to keep those blocks; see DEC-040. |
| `func_0208e1ac` | Clamps the supplied volume to `[0.0f, 1.0f]` and stores it in the singleton's `+0x18` word. Evidence: the compares against zero and `0x3f800000`, the `movlo`/`movhi` clamps and the final `str r4,[r0,#0x18]` at `0208e1ac..0208e1e0`. |
| `func_0208e1e0` | Returns the stored master volume from the singleton's `+0x18` word. Evidence: the word load and `bx lr` at `0208e1e0..0208e1f0`; `func_0208dc78` and `func_0208e1ac` are its writers. |

`func_02079b4c` is declared with a second `s32` argument because the original
call in `func_0208e0e8` keeps zero in `r1` across the call; the neighbouring
`func_0208e084` path passes one in the same register. See DEC-040.

## Validation

All eight functions report 100% in objdiff against
`build/delinks/libs/NitroSDK/sdk_0208dc78.o`. The full checksum gate still
reports every artifact byte-identical to the original, all repository unit
tests pass, and no assembly, pragma-based instruction selection, volatile
escape or byte blob was used.

## Hard list

None. All eight functions assigned to this card match at 100%; the six other
functions in the range are intentionally left to M2-T379.
