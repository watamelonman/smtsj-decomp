# src/game/unit_020bac80.c

## M1-T403: verified matches

All eight functions below are 100% in objdiff. Evidence is the original ARM
instruction stream (addresses from `config/arm9/symbols.txt`), inspected with
`tools/hand/asm.py`. Names remain neutral because field purposes are unknown.
Provider-owned objects are borrowed; these helpers neither allocate nor free them.
The local struct views name only observed fields and preserve their byte offsets.

- `Unk0bac80_Thunk_02044ec4` (12 B): original LDR ip / BX ip veneer
  forwards to `func_02044ec4`; the C call produces the matching thunk.
- `Unk0bac80_Unk_0badc0` (16 B): calls `Unk03aae8_Unk_03ad14`,
  loads its word at +0xe8, and returns that borrowed work address.
- `Unk0bac80_Unk_0bae08` (16 B): calls the work-address getter and
  returns the opaque word at +0x68. Requires a valid provider-owned work object.
- `Unk0bac80_Unk_0bae18` (16 B): returns the global provider address plus
  0x8c, as shown by ADD r0,r0,#140. Keeps the existing integer-address ABI
  used by other handlers in this TU.
- `Unk0bac80_Unk_0bae50` (20 B): queries
  `Unk02ee5c_GetTierFromField70`, passes its r0 result to
  `Unk03aae8_Unk_03acf4`, and returns completion value 1. The argument is now
  explicit in C. The setter's body at 0203acf4 stores that word at +0xa8
  in its current context and clears a byte at +0x3b.
- `Unk0bac80_Unk_0bb298` (24 B): loads work +0x40, passes the word
  to the same setter, and returns completion value 1.
- `Unk0bac80_Unk_0badd0` (28 B): preserves the input word in r4,
  loads work +0x54 as the first argument, and forwards the input as the
  second argument to `func_0204fdac`. Handle semantics remain unknown.
- `Unk0bac80_Unk_0badec` (28 B): the same forwarding sequence with the
  handle at work +0x60. No range restriction on the forwarded word is inferred.

No M1-T403 hard functions remain. Other card implementations below are retained.

## Not done in M1-T406
- `func_020bafa4`
- `func_020bb00c`
- `func_020bac80`
- `func_020bad40`
- `func_020bb18c`

## M1-T404: verified query result wrappers

Each 28-byte ARM wrapper calls `Unk0bac80_Unk_0bae18` for the borrowed
subobject address, passes a fixed selector in r1 to the query below, forwards
its returned r0 word to `Unk03aae8_Unk_03acf4`, and returns completion value 1.
Evidence: original instruction streams inspected with `tools/hand/asm.py`.
The C now expresses the result forwarding explicitly. The provider must supply
a valid subobject; no ownership transfers. Selector meanings and result units
are unknown, so the wrapper names remain neutral.

- `Unk0bac80_Unk_0bae34` (28 B): query `func_02049d80`, selector 2; publishes the opaque result.
- `Unk0bac80_Unk_0bae64` (28 B): query `func_02049f24`, selector 0; publishes the opaque result.
- `Unk0bac80_Unk_0bae80` (28 B): query `func_02049d80`, selector 0; publishes the opaque result.
- `Unk0bac80_Unk_0baf6c` (28 B): query `func_02049d80`, selector 1; publishes the opaque result.
- `Unk0bac80_Unk_0baf88` (28 B): query `func_02049f24`, selector 1; publishes the opaque result.
- `Unk0bac80_Unk_0bb078` (28 B): query `func_02049d80`, selector 3; publishes the opaque result.
- `Unk0bac80_Unk_0bb094` (28 B): query `func_02049d80`, selector 4; publishes the opaque result.
- `Unk0bac80_Unk_0bb0b0` (28 B): query `func_02049d80`, selector 5; publishes the opaque result.

All eight wrappers are 100% in the generated objdiff report. The match gate
passes for all 30 C definitions checked in changed files. No M1-T404 hard
functions remain.

## M1-T405: verified matches

All eight functions below are 100% in objdiff. Evidence is the original ARM
instruction stream inspected with `tools/hand/asm.py`; field and command purposes
remain unknown, so existing neutral names are retained. Provider objects are
borrowed and must remain valid throughout each call.

- `Unk0bac80_Unk_0bb0cc` (28 B): queries `func_02049d80` selector 6 on
  the subobject from 020bae18, publishes its returned word, and returns 1.
- `Unk0bac80_Unk_0bb0e8` (28 B): the same sequence with selector 7.
- `Unk0bac80_Unk_0bacf8` (36 B): reads the unsigned halfword at work
  +0x35c and passes its value plus one to 020bac80 with the original first
  argument. The addition occurs after integer promotion, without halfword wrapping.
- `Unk0bac80_Unk_0bad1c` (36 B): the same forwarding with subtraction
  of one; a zero halfword produces signed -1.
- `Unk0bac80_Unk_0bb104` (64 B): obtains signed argument 0; when it is
  below 15, publishes the halfword indexed from work +0x386, otherwise zero.
  The original CMP/BGE does not reject negative indices; valid addressing is
  a caller precondition, rather than an added bounds check.
- `Unk0bac80_Unk_0bb144` (72 B): obtains arguments 0 and 1, and adds
  argument 1 to the halfword indexed by argument 0 from work +0x386 if the
  signed index is below 15. STRH truncates the sum modulo 65536. The same
  caller index precondition applies.
- `func_020bae9c` (104 B): obtains argument 0 and the subobject's first
  word, calls 0204f59c with `(0, word, argument)`, then 0204f24c with
  `(0, word, argument, 0, 0, 1)`. Sets bit 13 in work +0x44 and returns 3.
- `func_020baf04` (104 B): calls 0204f650 with
  `(0, word, argument, 21)`, then 0204f24c with
  `(0, word, argument, 1, 0, 1)`. Sets the same work bit and returns 3.

Validation: match gate passed, anticheat passed, all nine unit tests passed,
and checksum reported all artifacts byte-identical to the original. No new
runtime tests were required by this card; objdiff checks the compiled functions.
No M1-T405 hard functions remain.
