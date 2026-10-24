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

## M1-T493 — verified matches

The inherited bodies already reproduced the original instructions. This card makes
both task-update arguments explicit, types the helper declarations used here, and
records their contracts. All eight functions match at 100% with configured MWCC.
Addresses below refer to the original ARM9 instructions.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `Unk0946e0_Unk_094704` | 48 B | Null is a no-op. Writes input halfwords at +0/+2/+8, negates the signed delay into +10, and clears +4/+6. STRH sequence at 0x02094710–0x0209472c. Caller supplies 12 writable bytes. |
| `Unk0946e0_ResetRect` | 60 B | Resets shared origin, copies signed origin halfwords into position words, sets dimensions to 256 by 192, and clears +0x14. Stores at 0x0209491c–0x02094944 support the existing rectangle name. |
| `Unk0946e0_Unk_094b98` | 60 B | Non-null DS task address. A negative +8 counter becomes zero and captures the shared +0x10 halfword; subsequent calls update the same task through `func_02094af8` and release it through `func_02061424` when the update returns nonzero. Branches/calls at 0x02094ba8–0x02094bcc. |
| `Unk0946e0_Unk_094d64` | 60 B | Non-null DS task address. A negative +0x10 counter becomes zero and captures two shared signed halfwords; otherwise updates that task through `func_02094c74` and releases it on nonzero completion. Branches/calls at 0x02094d74–0x02094d98. |
| `Unk0946e0_Unk_094eb8` | 60 B | Resolves the supplied key through `func_02044ec4`/`func_02049c28`, subtracts 128 from the first signed halfword, then forwards it with zero y and the two remaining parameters. STRH/LDRSH at 0x02094ee0/0x02094ee4 preserve halfword wrapping. |
| `Unk0946e0_Unk_094e30` | 64 B | Clamps x inclusively to [-64, 64], reads shared signed y at +2, and forwards x/y and both remaining parameters to `func_02094da0`. Comparisons and LDRSH at 0x02094e38–0x02094e58. |
| `Unk0946e0_Unk_094e70` | 72 B | Resolves the supplied key to a signed halfword pair, subtracts (128, 96), and forwards the wrapped pair with both remaining parameters. Stack STRH/LDRSH at 0x02094e9c–0x02094eb0. |
| `Unk0946e0_ApplyRect` | 80 B | Sends shared position words to `func_02057678`, then sends half the signed dimension differences from (256, 192), truncated toward zero and shifted by 12, to `func_02057628`. Calls at 0x02094aa8/0x02094ad8 support the existing rectangle name. |

No M1-T493 functions remain on the hard list. Neutral names remain where the
instructions establish operations but do not establish subsystem intent.

## Remaining work outside M1-T493

The inherited bodies for `Unk0946e0_Unk_094958`,
`Unk0946e0_Unk_0949e0`, and `Unk0946e0_Unk_094bd4` remain unchanged.
Functions still provided only by the delink include `func_02094750`,
`func_02094af8`, `func_02094c74`, `func_02094da0`, and `func_02094ef4`.
