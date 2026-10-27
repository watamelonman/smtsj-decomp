# CRI unit 0208325c

This partial translation unit implements the eight functions in M2-T428 and eight more in M2-T429.
Original `func_` symbols are retained because public CRI API names are not
established. A public-source search for CRI/ADX Nintendo DS middleware found
format tooling (including https://github.com/Youjose/CriCodecs), but no matching
runtime source; implementation follows the original ARM instructions.
The remainder of the unit stays linked from the delinked original.

| Function | Instruction evidence and contract |
| --- | --- |
| `func_0208325c` | Reads `02174740 +0x20`: modes zero/one call `02007ad4`; mode two dispatches `0208390c`, clears `02174700 +0x10`, passes `021748e4` to `020064e0`, then calls `02007ad4`. Other modes return. |
| `func_020832d0` | On zero nesting count (`021746e4 +8`), saves volatile hardware IE at `04000210` to `02174714` and calls IRQ-mask disable provider `020059d8(1)`. Increments the count on every entry. |
| `func_0208331c` | Decrements the same unsigned nesting count; only a zero result calls IRQ-mask enable provider `020059a8(1)`. Callers must balance entries and exits. |
| `func_02083708` | Calls the existing `02083820` accessor and returns one for any nonzero word, otherwise zero. |
| `func_02083830` | Increments `021746e4 +0x0c` modulo 2^32. |
| `func_02083848` | Decrements that word modulo 2^32. |
| `func_0208390c` | Loads optional callback at `02174700 +0`, invoking it with the borrowed context at +4 only when nonnull. |
| `func_02083930` | Independently dispatches the optional callback at `02174700 +8` with the borrowed context at +0x0c. |
| `func_020832ac` | Literal at 020832b4 selects `func_0208a988`; tail-forwards its signed result with no arguments. That existing implementation dispatches the global mode and returns zero. |
| `func_020832b8` | Literal at 020832c0 selects argument-free entry helper `func_020821e0`, which invokes `func_0208211c(1)`. No defined result. |
| `func_020832c4` | Literal at 020832cc selects argument-free exit helper `func_020821f0`, which invokes `func_02082168(1)`. No defined result. |
| `func_02083490` | Literal at 02083498 selects `func_02082544`; r0/r1 pass through as callback/context. The provider stores them at 02173ff4/+4; `func_02082220` and `func_0208228c` load the pair and invoke `callback(context, data_021742cc)`. Context lifetime must cover subsequent provider calls. |
| `func_02083820` | Loads the word at `data_021746e4 + 0x0c`; neighboring 02083830/02083848 increment/decrement it. Exposed as an unsigned raw word without assigning an unsupported purpose. |
| `func_02083860` | Loads the independent word at `data_02174740 + 0x0c`. Provider owns the shared storage. |
| `func_02083870` | Writes one to `data_02174740 + 0x0c`, without reading other fields. |
| `func_02083884` | Writes zero to the same shared word, without reading other fields. |

The private state prefix exposes the observed +8 and +0x0c counters and
+0x20 dispatch word; intervening words are opaque layout padding. The separate
callback prefix exposes two callback/context pairs and the +0x10 reset word.
Neither view makes claims about the full state size.
No allocation or ownership transfer occurs in these accessors.

## Validation

The match gate checks all sixteen definitions against their delinked targets.
The checksum gate verifies the image built with this partial TU still delinked,
as required by the card; it does not claim the whole TU is complete.
No new behavioral tests are required by the card: instruction matching is the
acceptance check for these forwarding and shared-word operations.

## Hard list

None of the sixteen implemented functions is deferred.

M2-T429 source search found [vgmstream ADX format parsing](https://github.com/vgmstream/vgmstream/blob/master/src/meta/adx.c), but no matching runtime implementation. Reconstruction therefore uses the original ARM loads, branches and provider calls.

M2-T429 local validation: all eight requested functions report 100% in objdiff;
anticheat passes, all nine repository unit tests pass, and checksum reports all
artifacts byte-identical to the original.
