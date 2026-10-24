# src/game/unit_020946e0.c

## M1-T492 — verified matches

All eight functions below match the delinked ARM object at 100% with the configured
MWCC toolchain. Instruction addresses refer to the original ARM9 code. Neutral
names are retained where field or subsystem meanings are not established.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `Unk0946e0_Unk_0948fc` | 8 B | Returns the input address plus four; ADD at 0x020948fc. Does not dereference it. |
| `Unk0946e0_Thunk_02053000` | 12 B | Calls `func_02053000` without arguments; BL at 0x02094908. |
| `Unk0946e0_GetAddr_data_02175d94` | 12 B | Returns the module-owned shared record address; literal at 0x02094954. Uses a 32-bit DS address representation. |
| `Unk0946e0_Unk_094ae0` | 24 B | Writes the signed halfword at shared offset 0x10 to a non-null word output; LDRSH at 0x02094aec. |
| `Unk0946e0_Clear12` | 28 B | Null is a no-op; otherwise clears exactly 12 writable bytes through `func_02008848`. Guard and size appear at 0x02094738–0x02094744. |
| `Unk0946e0_Unk_0946e0` | 36 B | Allocates 12 bytes, unconditionally clears them, and returns the allocation address. Calls at 0x020946e8/0x020946f8 establish the allocation/clear sequence; no additional failure policy is introduced. |
| `Unk0946e0_Unk_094c50` | 36 B | Writes two sign-extended shared halfwords to a non-null two-word output; LDRSH at 0x02094c5c/0x02094c68. Preserves the two accessor calls. |
| `Unk0946e0_Unk_094a64` | 44 B | Forwards shared words at +4/+8 and the supplied index to `func_02057678`, then passes the same index and two zeroes to `func_02057628`; BL at 0x02094a78/0x02094a88. |

No M1-T492 functions remain on the hard list. Existing implementations for the
other cards in this translation unit are preserved.

## Hard list
- `Unk0946e0_Unk_094704`: decompiler-derived

## Not done in M1-T493
- `Unk0946e0_ResetRect`
- `Unk0946e0_Unk_094b98`
- `Unk0946e0_Unk_094d64`
- `Unk0946e0_Unk_094eb8`
- `Unk0946e0_Unk_094e30`
- `Unk0946e0_Unk_094e70`
- `Unk0946e0_ApplyRect`
- `Unk0946e0_Unk_094958`: decompiler-derived

## Not done in M1-T494
- `Unk0946e0_Unk_094bd4`
- `Unk0946e0_SetViewBox`
- `func_02094da0`
- `func_02094af8`
- `func_02094ef4`
- `func_02094c74`
- `func_02094750`
- `Unk0946e0_Unk_094b98`: decompiler-derived (proto cleanup)
- `Unk0946e0_Unk_094d64`: decompiler-derived (proto cleanup)
- `Unk0946e0_Clear12`: hand-matched
- `Unk0946e0_ResetRect`: hand-matched
- `Unk0946e0_Unk_094e30`: hand-matched
- `Unk0946e0_Unk_094e70`: hand-matched
- `Unk0946e0_Unk_094eb8`: hand-matched
- `Unk0946e0_SetViewBox`: hand-matched
- `Unk0946e0_ApplyRect`: hand-matched
- `Unk0946e0_Unk_094bd4`: hand-matched
