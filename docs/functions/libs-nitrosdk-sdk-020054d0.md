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
All thirteen C definitions added in M2-T366 and M2-T367 match at 100%. The build,
anticheat, repository unit tests and checksum gates pass. The partial TU remains
linked from the delink pending human completion.

## M2-T368 additions

Existing linker names are retained. Public-source comparisons:
[OS_interrupt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/OS_interrupt.c)
provides `OS_SetIrqFunction`, `OSi_EnterDmaCallback` and
`OSi_EnterTimerCallback`; [OS_irqTable.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/OS_irqTable.c)
provides the dispatcher. [GX_load3d.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load3d.c)
provides the texture/palette load lifecycle: `GX_LoadTexPltt`,
`GX_EndLoadTex` and `GX_EndLoadTexPltt`. The shared state at
`data_021521dc` is the `TexLoadState` already identified in
`libs/NitroSDK/sdk_02005238.c` from the same public source: +4 is
`sTexLCDCBlk1`, +8 `sTexPlttLCDCBlk`, +12 `sTexPltt`, +20 `sTex`,
+24 `sTexLCDCBlk2` and +28 `sSzTexBlk1`. `data_0213ce44` is `GXi_DmaId`;
it is waited on, not released.

| Function | Size | Contract and evidence | Result |
| --- | ---: | --- | --- |
| `func_020054d0` | 76 | `GX_EndLoadTex`: no arguments. If `GXi_DmaId` (`data_0213ce44`) is not -1, wait on it; pass the saved texture bank mask at state +20 to the bank-restore provider (`func_0200303c`, which manipulates the LCDC bank-enable register), then clear state +28, +24, +4 and +20 in that order. | 100% |
| `func_02005550` | 108 | `GX_LoadTexPltt`: caller-owned source, unsigned byte offset and size. Copy into the borrowed palette LCDC block at state +8 plus offset; a configured `GXi_DmaId` selects the six-argument DMA provider with zero callback/argument, otherwise the three-argument synchronous copy provider. | 100% |
| `func_020055bc` | 68 | `GX_EndLoadTexPltt`: no arguments. Wait on `GXi_DmaId` unless -1, pass the saved palette bank at state +12 to the bank-restore provider (`func_02003214`), then clear state +12 and +8. | 100% |
| `func_02005640` | 116 | Boolean clear request and unsigned IRQ mask. Save CPU IRQ mode, optionally clear matching check bits, restore mode and sleep on the IRQ queue until a requested check bit is set. | Deferred |
| `func_020056b8` | 136 | Unsigned callback slot 0..7. Clear callback before calling it with its borrowed argument, set the indexed check flag and disable its IRQ when the saved enable flag is zero. Public `OSi_IrqCallback` confirms the behavior. | Deferred |
| `func_020057d8` | 136 | Unsigned IRQ mask and argument-free handler. Scan 22 bits; DMA bits 8..11 use callback records 0..3 and timer bits 3..6 use 4..7. Other bits write the DTCM IRQ table. Matching public `OS_SetIrqFunction`. | 100% |
| `func_020058ec` | 72 | DMA channel 0..3, callback and borrowed argument. Store callback/argument, enable bit channel+8 and preserve its previous enabled state in the record. Matching public `OSi_EnterDmaCallback`. | 100% |
| `func_02005934` | 72 | Timer 0..3, callback and borrowed argument. Store callback/argument, enable bit timer+3 and set record enable to one. Matching public `OSi_EnterTimerCallback`. | 100% |

### Additional hard list

- `func_02005640`: tried direct fixed addresses, a DTCM layout view, linker-base
  address arithmetic, inline flag accessors, volatile reads, explicit early
  return and do/while forms. Best objdiff was 85.48%. The compiler hoisted the
  loop check-word address construction ahead of the initial test and used
  different registers. No C definition is retained.
- `func_020056b8`: public dispatcher source plus explicit flag/enable temporaries
  reached 98.82%. Remaining differences swap r1/r2 around the check-word update
  and enable test. Tried declaration order, callback aliases, plain records,
  inline accessors, volatile access and size optimization. No C definition is
  retained; existing wrappers still call the delinked provider.

Both can be opened as human-managed scratches with `tools/decompme.py`.
No inline assembly or code blobs were added. The six additions and all thirteen
existing definitions pass objdiff at 100% (19 definitions total).
