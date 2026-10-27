# CRI unit 0208325c

This partial translation unit implements the eight functions in M2-T428.
Original `func_` symbols are retained because public CRI API names are not
established. A public-source search for CRI/ADX Nintendo DS middleware found
format tooling (including https://github.com/Youjose/CriCodecs), but no matching
runtime source; implementation follows the original ARM instructions.
The remainder of the unit stays linked from the delinked original.

| Function | Instruction evidence and contract |
| --- | --- |
| `func_020832ac` | Literal at 020832b4 selects `func_0208a988`; tail-forwards its signed result with no arguments. That existing implementation dispatches the global mode and returns zero. |
| `func_020832b8` | Literal at 020832c0 selects argument-free entry helper `func_020821e0`, which invokes `func_0208211c(1)`. No defined result. |
| `func_020832c4` | Literal at 020832cc selects argument-free exit helper `func_020821f0`, which invokes `func_02082168(1)`. No defined result. |
| `func_02083490` | Literal at 02083498 selects `func_02082544`; r0/r1 pass through as callback/context. The provider stores them at 02173ff4/+4; 0208211c loads the pair and invokes callback(context). Context lifetime must cover subsequent provider calls. |
| `func_02083820` | Loads the word at `data_021746e4 + 0x0c`; neighboring 02083830/02083848 increment/decrement it. Exposed as an unsigned raw word without assigning an unsupported purpose. |
| `func_02083860` | Loads the independent word at `data_02174740 + 0x0c`. Provider owns the shared storage. |
| `func_02083870` | Writes one to `data_02174740 + 0x0c`, without reading other fields. |
| `func_02083884` | Writes zero to the same shared word, without reading other fields. |

The private state prefix exposes only the observed +0x0c word; preceding
words are opaque layout padding. It makes no claims about the full state size.
No allocation or ownership transfer occurs in these accessors.

## Validation

The match gate checks all eight definitions against their delinked targets.
The checksum gate verifies the image built with this partial TU still delinked,
as required by the card; it does not claim the whole TU is complete.
No new behavioral tests are required by the card: instruction matching is the
acceptance check for these forwarding and shared-word operations.

## Hard list

None of the eight requested functions is deferred.
