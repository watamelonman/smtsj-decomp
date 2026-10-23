# game/unit_0203bba4

## M1-T180 — verified at 100% objdiff

Evidence comes from the ARM instructions and call relocations in
`build/delinks/src/game/unit_0203bba4.o`. All eight callbacks take no
parameters; command arguments come from `func_0203ac00(index)`. Work-area
pointers are borrowed. Return values are retained as command status codes;
their broader scheduling meaning is not inferred. Neutral names are retained
because these call sequences do not establish a more specific purpose.

| Function | Bytes | Observed contract |
| --- | ---: | --- |
| `Unk03bba4_Unk_03bcc0` | 24 | Loads the word at work-area +0x358 and passes it to 03acf4; returns 1. |
| `Unk03bba4_Unk_03bbd0` | 28 | Reads argument 0, masks to eight bits (`and #255`), calls 020b8660; returns 1. |
| `Unk03bba4_Unk_03bc88` | 28 | Uses `ldrsb` at work-area +0x364 and publishes the sign-extended value through 03acf4; returns 1. |
| `Unk03bba4_Unk_03bca4` | 28 | Uses `ldrsb` at work-area +0x365 and publishes the sign-extended value through 03acf4; returns 1. |
| `Unk03bba4_Unk_03bd18` | 36 | Sign-extends the low halfword of argument 0, calls ImageObj 07784c, then SetCode8; returns 3. |
| `Unk03bba4_Unk_03bd7c` | 36 | Sign-extends the low halfword of argument 0, calls ImageObj 077880, then SetCode8; returns 3. |
| `Unk03bba4_Unk_03bba4` | 44 | Follows context +0xe8 and stores 19 at subobject +0x18; calls 116810 only when 02095818 returns 3; returns 3. |
| `Unk03bba4_Unk_03bcd8` | 64 | Reads arguments 0 and 1 in order, sign-extends both low halfwords, calls ImageObj 07782c, SetCode8, and ScanVisor 0a2920(0); returns 3. |

The signed argument conversions intentionally occur in the callbacks, before
passing full-width values to the ImageObj helpers. The byte readers likewise
must preserve negative values when converting to the publisher's u32 argument.
Field access goes through partial struct views in
`include/game/unit_0203bba4.h`: `Unk02e000WorkArea` (`unk_0358`, `unk_0364`,
`unk_0365`), `Unk03aae8Ctx` (`unk_00e8`) and `Unk03bba4Sub` (`unk_0018`).
Their sizes are unknown; gaps are padding. 03bba4/03bc40 keep a small inline
setter because passing the constant before the pointer preserves the original
register order (a direct `ctx->unk_00e8->unk_0018 = 19` measured 98.18%).

## Other existing functions (outside M1-T180)

- `Unk03bba4_Unk_03bd3c`: forwards two signed command arguments to ImageObj 077860, sets code 8 and clears the ScanVisor switch; returns 3.
- `Unk03bba4_Unk_03bbec`: forwards three unsigned halfword arguments to 09e418, then passes context +0xe8 to 02deb0; returns 3.
- `Unk03bba4_Unk_03bc40`: forwards argument 0 to 065b10 after an optional 065c10 call, sets substate 6; returns 3.
- `Unk03bba4_Unk_03bda0`: polls readiness helpers, applies and clears a pending work slot, and waits for the background mode check.

## Hard list

None for M1-T180; all eight targets match exactly.
