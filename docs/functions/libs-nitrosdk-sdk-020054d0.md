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

## Validation

The original-object objdiff comparison is the acceptance test for these small
wrappers; the card does not require added runtime tests. All eight definitions
match at 100%. The build, anticheat check, nine repository unit tests and full
checksum gate passed; all checked artifacts are byte-identical to the original
while the TU remains linked from the delink.

## Hard list

None of the eight requested functions is deferred. Other functions in this
partial TU remain in the delink and were outside this card's scope.
