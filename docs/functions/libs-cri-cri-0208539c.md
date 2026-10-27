# CRI unit 0208539c

M2-T460 and M2-T461 each implement eight ARM functions. Original neutral `func_` symbols are
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

## M2-T461 additions

The public-source search found no matching CRI Nintendo DS runtime implementation;
these functions follow the delinked ARM instructions. All eight additions match
100% in objdiff. The private record view has a signed tag at +0, signed state
at +1 and words at +4, +0x10 and +0x14; its 56-byte stride follows 020855b0.
Callers retain records and the shared table; no module boundary changes occur.

| Function | Evidence and contract |
| --- | --- |
| `func_0208547c` | Loads callback from data_02175348 +4; when present passes context at +0, second input, first input. Registration must keep the borrowed context alive. |
| `func_02085584` | Walks ten records at data_02175350 with stride 56; calls 02085580 for each nonzero signed tag at +0. |
| `func_02085710` | Null is ignored. Calls 02085974, then clears tag +0 and all 56 bytes via 02085624 only if the tag equals one. |
| `func_020857d0` | Returns word +0x10; null dispatches zero and diagnostic data_02147514, then returns zero. |
| `func_02085974` | Null dispatches zero and data_02147590. Otherwise calls entry provider 0208544c, clears byte +1, then calls exit provider 02085458. |
| `func_020859a8` | Returns sign-extended byte +1; null dispatches zero and data_021475a8, then returns zero. |
| `func_020859d0` | Returns word +4; null dispatches zero and data_021475c0, then returns zero. |
| `func_02085a60` | Returns word +0x14; null dispatches zero and data_021475f0, then returns zero. |

## Hard list

None of the requested functions is deferred.
