# NitroSDK interrupt callback wrappers (sdk_020054d0)

Public-source comparison: [pret/pokediamond OS_interrupt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/OS_interrupt.c)
uses four DMA callback slots followed by four timer callback slots. Its
`OSi_EnterDmaCallback` and `OSi_EnterTimerCallback` establish this arrangement.
The original dispatcher at `func_020056b8` uses 12-byte callback records,
clears the callback before invoking it with its stored argument, sets an IRQ
check flag, and conditionally disables the interrupt. The source is useful
context; instruction evidence establishes each wrapper's exact index below.
Existing linker symbol names are retained; no speculative names are introduced.

All eight entry points take no arguments and return no value. They retain no
storage and rely on the existing dispatcher for callback ownership and IRQ state.

| Function | Original size | Contract and instruction evidence |
| --- | ---: | --- |
| `func_020056b4` | 4 | Empty handler: the entire original is `bx lr`; intentionally performs no work. |
| `func_02005740` | 16 | Tail-calls `func_020056b8(0)`: loads the dispatcher address into `ip`, moves 0 into `r0`, then executes `bx ip`. |
| `func_02005750` | 16 | Tail-calls `func_020056b8(1)`: loads the dispatcher address into `ip`, moves 1 into `r0`, then executes `bx ip`. |
| `func_02005760` | 16 | Tail-calls `func_020056b8(2)`: loads the dispatcher address into `ip`, moves 2 into `r0`, then executes `bx ip`. |
| `func_02005770` | 16 | Tail-calls `func_020056b8(3)`: loads the dispatcher address into `ip`, moves 3 into `r0`, then executes `bx ip`. |
| `func_02005780` | 16 | Tail-calls `func_020056b8(4)`: loads the dispatcher address into `ip`, moves 4 into `r0`, then executes `bx ip`. |
| `func_02005790` | 16 | Tail-calls `func_020056b8(5)`: loads the dispatcher address into `ip`, moves 5 into `r0`, then executes `bx ip`. |
| `func_020057a0` | 16 | Tail-calls `func_020056b8(6)`: loads the dispatcher address into `ip`, moves 6 into `r0`, then executes `bx ip`. |

## M2-T367 additions

The public [pret/pokediamond OS_interrupt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/OS_interrupt.c)
provides the matching C for the IRQ mask helpers, including the otherwise-unused
volatile IME read before restoration. Existing linker names are retained.
The queue storage is borrowed; hardware registers remain volatile.

| Function | Size | Contract and evidence | Result |
| --- | ---: | --- | --- |
| `func_020057b0` | 16 | No arguments; dispatch callback slot 7, evidenced by `mov r0, #7` and the dispatcher tail call. | 100% |
| `func_020057c0` | 24 | No arguments; clear queue words +4 then +0 at `data_027e0060`, matching `OS_InitIrqTable` and its inlined queue initialization. | 100% |
| `func_0200597c` | 44 | Take an unsigned IE mask, return old IE; replace IE at 0x04000210 while halfword IME at 0x04000208 is zero, then restore IME. Matches public `OS_SetIrqMask`. | 100% |
| `func_020059a8` | 48 | Take an unsigned mask, return old IE; OR requested bits into IE while preserving IME. Matches public `OS_EnableIrqMask`. | 100% |
| `func_020059d8` | 48 | Take an unsigned mask, return old IE; clear requested bits from IE while preserving IME. Matches public `OS_DisableIrqMask`. | 100% |
| `func_0200551c` | 52 | No arguments; store signed provider result at state +12 and table-selected page at +8. Index is result arithmetic-shifted by four; halfword table at 0x0212a3a0 is shifted left by 12. | Deferred |
| `func_02005600` | 36 | Read 48 bytes from the first pointer in four 12-byte blocks; write each block to the same second pointer. Original uses postincrement source LDM and fixed-destination STM. | Deferred |
| `func_02005624` | 28 | Read 64 bytes from the first pointer in two 32-byte blocks; write each block to the same second pointer. Original saves r4..r8 and transfers through r2..r8 and ip. | Deferred |

## Hard list

- `func_0200551c`: local page lookup followed by two state stores reached
  82.69%; compiler loaded the table address before the state address and used
  different registers. Moving the bank store before the lookup, using an
  explicit index, a struct state view, and embedding the assignment in the
  index did not reproduce the original scheduling (66.54% for store-first).
- `func_02005600`: four volatile three-word struct assignments reached 28.33%.
  Compiler used r0..r2 for transfers and explicit source additions rather than
  the original r2/r3/ip and postincrement LDM sequence.
- `func_02005624`: two volatile eight-word struct assignments reached 0%.
  Compiler split each block into four-register transfers and saved a different
  register set. Public [MI_memory.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/MI_memory.c)
  uses assembly for its related fixed-size copy routines; those advance the
  destination, unlike these fixed-destination transfers.

These three remain in the original delink with no C definition. A human can
create scratches with `tools/decompme.py`; no assembly or code blobs were added.

## Validation

Objdiff is the acceptance test; runtime tests are not required by this card.
All thirteen retained C definitions in this TU match at 100%. The build,
anticheat, repository unit tests and checksum gates pass. The partial TU remains
linked from the delink pending human completion.
