# game/unit_020e7ac4 — M1-T455

All eight functions below match the delinked ARM original at 100% objdiff.
Names remain neutral because field accesses establish behavior but do not
establish the work area's game-level purpose. The local struct is a borrowed
view through offset 0x58, not a claim about the full allocation size.

| Function | Behavior and evidence | Contract |
| --- | --- | --- |
| `Unk0e7ac4_Nop_0e7b7c` | Empty callback; original is a single `bx lr`. | No arguments or effects. |
| `Unk0e7ac4_Unk_0e8000` | Stores the argument at +0x50 (`020e8008`). | Singleton must be live. |
| `Unk0e7ac4_Unk_0e804c` | Stores the argument at +0x58 (`020e8054`). | Singleton must be live. |
| `Unk0e7ac4_Unk_0e8014` | Stores at +4 only if +0x58 is nonzero (`020e801c..020e8024`). | Singleton must be live; accepts a 32-bit word. |
| `Unk0e7ac4_Unk_0e8030` | Stores at +8 only if +0x58 is nonzero (`020e8038..020e8040`). | Singleton must be live; accepts a 32-bit word. |
| `Unk0e7ac4_Unk_0e8060` | Returns zero for a null singleton, otherwise its +0x58 word (`020e8068..020e8070`). | Null singleton is supported. |
| `Unk0e7ac4_Unk_0e8198` | Tail-calls `func_020e7f44` with saved words +0x24, +0x28, +0x2c, +0x30 (`020e81a4..020e81b4`). | Singleton must be live. |
| `Unk0e7ac4_Unk_0e7f0c` | Calls `func_0205bb68`, passes nonzero +0x54 to `func_0205ddb4`, clears that field, then clears the singleton (`020e7f14..020e7f38`). | Argument must point to live work; helper ownership details are unknown. |

The helper declarations reflect observed register arguments. No descriptive
renames or module boundary changes were needed. No hard functions remain in
M1-T455.

## Outside this card (M1-T456)

`func_020e81c0`, `func_020e7ac4`, `func_020e7f44`, `func_020e807c`,
`func_020e7b80`, and `func_020e7d40` remain supplied by the delinked original.
