# CRI unit 0208539c

M2-T460 implements eight ARM functions. Original neutral `func_` symbols are
retained because the public CRI API names are not established. A public-source
search for CRI/ADX Nintendo DS middleware found format tooling such as
https://github.com/vgmstream/vgmstream/blob/master/src/meta/adx.c but no matching
runtime source. The implementation therefore follows the original instructions.
Other functions in this partial unit remain linked from the delinked original.

| Function | Evidence and contract |
| --- | --- |
| `func_0208544c` | Literal 02085454 selects argument-free entry provider 020821e0; tail-forwards it. |
| `func_02085458` | Literal 02085460 selects argument-free exit provider 020821f0; tail-forwards it. |
| `func_02085464` | Loads and discards the word at absolute address 0212ed08, then returns the borrowed string at data_02147418. The literal address has no relocation in the original; volatile preserves the observed read without inventing a second return value. |
| `func_020854a4` | Literal 020854ac selects numeric conversion provider 02016fa4; caller 02085570 passes text, end-pointer storage and radix 16. Returns its word result. |
| `func_02085580` | A single bx lr; caller 0208559c supplies a borrowed record pointer. No effects or defined return value. |
| `func_020855bc` | Stores callback at data_02175348 +4 and context at +0. Dispatcher 0208547c passes context, its second input, and its first input to the callback. Context must remain alive until registration is replaced or cleared. |
| `func_020855d0` | Calls 0208550c with text and a stack word output; returns that output and discards the provider's direct result. |
| `func_02085624` | Tail-forwards to 020119c0 with destination, zero and 56. That provider preserves and returns the destination; caller owns at least 56 writable bytes. |

No module boundary changes: callback storage and its layout remain private to this
library implementation. No allocation or ownership transfer is introduced.

## Hard list

None of the eight requested functions is deferred.
