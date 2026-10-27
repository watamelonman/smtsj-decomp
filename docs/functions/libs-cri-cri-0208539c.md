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

## M2-T462 additions

All eight requested functions match 100% against the delinked ARM object.
A further public-source search found CRI's public C# bindings
(https://github.com/cri-middleware), but no matching DS runtime C source.
These implementations follow the original instruction and relocation evidence.
The existing private record view now exposes word +0x18 and text at +0x1c;
its size remains 56 bytes. All table, key, text and record storage is borrowed.
No module boundary or ownership changes occur.

| Function | Evidence and contract |
| --- | --- |
| `func_0208539c` | Rejects a zero signed first key byte; reads count from data_02175340 and entries from data_02175344. Compares twelve bytes through 020153e0, advances sixteen bytes per entry, and returns the first matching borrowed entry or null. Keys must expose twelve readable bytes. |
| `func_02085410` | Returns -1 for an absent table, -3 for an unmatched key; otherwise writes entry word +12 through the caller's output and returns zero. |
| `func_020854b0` | Signed-byte digit tests at 020854b4 accept 0–9, a–f and A–F; multiply-accumulates with the supplied radix and writes the first unaccepted byte pointer through end. Arithmetic wraps in a 32-bit unsigned word; digits are not checked against radix. |
| `func_0208550c` | Length provider 02015118 triggers diagnostic (0,0) for length >=18 but parsing continues. Parses first word with 020854b0 at radix sixteen, skips one nonzero delimiter, and optionally parses second word through 020854a4. Input is null-terminated; output storage is caller-owned. |
| `func_020855e4` | Scans ten signed tags at data_02175350, stride 56; returns the first tag-zero record or null. Does not reserve or initialize the slot. |
| `func_02085638` | Sets unit +4 to 2048, parses text +0x1c's second word into +8, rounds up the signed unit count into +12, clears +16/+24/+20 and byte +1, then tags byte +0 as one. Caller supplies a writable 56-byte record with terminated text. |
| `func_02085688` | Null text, nonzero third argument, and exhausted pool report data_02147480/021474a4/021474c8 respectively and return null. The second argument is unused in the original. Copies text through 0208d68c with size eighteen into record +0x1c, initializes the slot, and returns it. |
| `func_020859f8` | Null reports data_021475d8. Saves old +16 times unit +4, writes the new unit, rounds up size +8 into count +12, converts the saved position into new units at +16, and multiplies +24 by the new unit into +20. Unit must be nonzero and signed arithmetic must fit. |

## Hard list

None of the requested functions is deferred.
