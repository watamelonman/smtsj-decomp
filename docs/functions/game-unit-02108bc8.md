# game/unit_02108bc8 — M1-T414

The seven implemented functions match at 100% in objdiff. Names already present
in the symbol map are preserved. Neutral names avoid inferring gameplay purpose.
The local work view describes only observed offsets; the trailing field is a
borrowed region start, not a statement about allocation length.

| Function | Contract and evidence from original ARM instructions |
| --- | --- |
| `Unk108bc8_Unk_108bc8` | Converts argument two through `Unk0a163c_Unk_0a1814` and `func_02063a30`, then forwards it as the fifth argument to `func_02061f10`, with argument one, -1, 0, 0. |
| `Unk108bc8_GetSize` | Returns 0x5bfc bytes, evidenced by its literal load at 02108c00. |
| `Unk108bc8_Alloc` | Null guard and `func_02052fe0(0x5ffc)` call establish allocation of singleton storage; repeated calls retain the existing allocation. |
| `Unk108bc8_Unk_108c3c` | Passes the singleton to `func_02053000`, then clears the global. No null guard is added. |
| `Unk108bc8_Unk_108c60` | Allocates on null and returns borrowed singleton storage. |
| `Unk108bc8_GetHead` | Conditional `ldrh` at offset zero returns the first unsigned halfword, or zero for a null singleton. |
| `func_02109050` | Requires valid source/destination work records. Copies byte +2, word +0x5fc4, word +0x348, and selected regions using the original helpers. Copies 491 records of 36 bytes at +0x16fc and clears bit zero in each record's bytes +11 and +31. Other offsets and copy lengths follow the original address arithmetic. |
| `func_02109174` | Original allocates 0x7718 bytes, brackets overlay-1 helper `func_ov001_0217838c` with module calls, selects partial restore when byte +154 is 3, otherwise copies 0x6538 bytes from +152, copies another 0x1148 bytes from +0x65d0, frees temporary and singleton storage, then calls `func_02108ca4`. Remains linked from the delinked original. |

## Hard list

- `func_02109174` (188 bytes): a readable candidate reproduced the copy order,
  branch, offsets, and overlay relocation, but objdiff reached only 92.15%.
  Original loads literal 1 into r5 and reuses it as the second module-call
  argument. Candidates with two typed integer arguments, a pointer identifier,
  and a 64-bit module value instead emitted immediate moves and a smaller
  180-byte function. No candidate is installed for this routine. A human can
  investigate the module API types/compiler behavior in a decomp.me scratch.

## Outside this card

`func_02108ca4` belongs to M1-T415 and remains in the original object.
