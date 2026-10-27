# sdk_02056cac matching functions

These functions retain their neutral original symbols: the delink's NitroSDK
label does not establish an upstream API identity. Public-source searches of
pret/pokeplatinum and zeldaret SDK material did not identify these wrappers.
The implementation therefore follows the original ARM instructions. All eight
functions match at 100%; the remaining TU code stays supplied by the delink.

| Function | Bytes | Evidence and contract |
| --- | ---: | --- |
| `func_02056cac` | 20 | Selects work with `func_02056110`, passes its borrowed entry base at +8 to `func_0205bfd0`, which pops an entry when the count is nonzero. |
| `func_02056cc0` | 16 | Tail-calls `func_02056cd0` with count one. That provider shifts slot and count by nine, giving a 512-byte transfer. Source remains caller-owned. |
| `func_02056d88` | 136 | Selects an eight-byte entry; extracts bits 22..25, 0..10 and 11..21 for the callback at work +0x201c. Passes a seven-word stack packet to `func_0205bf18`, which synchronously copies it into its queue. Caller supplies valid indices and callback lifetimes. |
| `func_02056e10` | 52 | Visits indices zero and one, calling `func_0205c0ec` on the entry base only when the work's first word is nonzero. |
| `func_02056e44` | 36 | Clears mask 0xe000 in volatile display-control words at 0x04000000 and 0x04001000, preserving other bits. |
| `func_02056e68` | 100 | Writes fourteen observed defaults to `data_021683c8`: five scalar words and nine vector components. Component meanings remain unproven; the layout is private. |
| `func_020572c0` | 24 | Calls `func_02056e68`, `func_02056ecc`, `func_02056f58`, then `func_020572d8` in order. |
| `func_020572d8` | 32 | Writes zero at `data_0215f05c + 0x10`, then signed -1 sentinels at +0x11 and +0x12. |

The entry bitfields reproduce the original shift-only extraction. Keeping the
borrowed entry pointer in the packet and deriving the queue base from the work
pointer reproduces the original register lifetimes without assembly.

Validation: direct instruction/relocation comparison, objdiff match gate, full
build/checksum, anticheat, and the existing Python test suite. No new tests are
required by this card; instruction matching provides the behavioral oracle.

Hard list: none.
