# game/unit_020e7ac4 — M1-T455 / M1-T456

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

## M1-T456

All six functions below match at 100% objdiff. Names retain the original
neutral address labels because the instructions do not establish a game-level
purpose. The work pointer and singleton are borrowed and must be live.

| Function | Behavior and evidence | Contract |
| --- | --- | --- |
| `func_020e7ac4` | Advances state-dependent phase/ramp and restores four pending words; `020e7af4..020e7b74`. | Live work pointer; pause helper prevents updates. |
| `func_020e7b80` | Submits two entries with staggered, nonnegative phase; `020e7b88..020e7d34`. | Live work; requires nonzero +0x58 and +0x50. |
| `func_020e7d40` | Submits four entries with selection-dependent tint and staggered phase; `020e7d48..020e7f00`. | Live work; requires zero +0x58 and nonzero +0x50. |
| `func_020e7f44` | Compares four pending words, backs them up and clears selection on change; `020e7f60..020e7ff4`. | Live singleton; accepts four 32-bit words. |
| `func_020e807c` | Tracks the last hit among four 64-by-16 rectangles at y=176 and confirms a released selection; `020e8094..020e8188`. | Live singleton; returns index 0..3 on confirmation, otherwise -1. |
| `func_020e81c0` | Copies a 24-byte helper record and submits it with unit scales; `020e81d4..020e821c`. | Borrowed handle; index selects the source record; phase is signed. |

Loop increment order and local declaration order preserve the original compiler's
instruction scheduling and register allocation. No module boundaries changed.
No hard functions remain in M1-T456.
