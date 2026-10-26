# libs/MSL/msl_02017850.c

Sixteen functions in this delink unit are reconstructed as readable C and match
the delinked original at 100% with mwccarm 2.0/sp1p5. Eight further routines in
this unit (the decimal carry helper, three conversion/intrinsic routines and
four comparison routines, all listed at the end) remain as delinked assembly;
they are hand-written runtime assembly that the pinned C compiler does not
reproduce.

The unit is part of the MSL double-precision math library. No public NitroSDK
MSL source matches this ROM build byte for byte, so the bodies and call sites in
`libs/CRI/cri_0208aba0.c` and `libs/NitroSDK/sdk_020116a8.s` were used as
evidence, together with the public MSL reconstructions in pret/pokeheartgold
(`lib/MSL_C/src/msl_fp_runtime.c`, `msl_fp_ansi_str2dec.c`) and pokebw2
(`lib/msl/src/fp/fp_fastI.s`). Those sources confirm which routines were C
(`__str2dec`, the decimal rounding helpers) and which were already hand-written
assembly in MSL (the comparison primitives and the double-to-u64 conversion).
The four wrappers only load a target address and branch with the argument
registers untouched, which is the MSL tail-call shape; every caller in CRI
passes the result of `_f2d`, so the argument and result are `double`.

The module adds no dependency and does not change an architectural boundary.
The unit stays linked from its delinked original until a human marks it complete.

## func_0201ba48 — 12 bytes

Forwards a double to `func_02017058`. The body is `ldr ip, [pc]; bx ip` with the
literal `func_02017058`; only the target address is loaded, so all argument
registers reach the callee unchanged. Matches 100%.

## func_0201ba54 — 12 bytes

Forwards a double to `func_02017850`, the first major routine in this unit.
Evidence is the same untouched-register tail call and the `_f2d` caller in
`cri_0208aba0.c`. Matches 100%.

## func_0201ba60 — 12 bytes

Forwards a double to `func_020186d4`. Callers pass a double constant (for
example `0.0` and `960.0`) built as a register pair, confirming the double
contract. Matches 100%.

## func_0201ba6c — 12 bytes

Forwards a double to `func_020188ac`. Same tail-call shape and double callers as
the other three wrappers. Matches 100%.

## func_0201bb30 — 4 bytes

No-op. The whole body is `bx lr`, so the routine returns without touching any
register that carries a result. The name stays neutral because no caller or
string identifies the routine's purpose. Matches 100%.

## func_0201cf28 — 20 bytes

Returns the sign bit of a double as an `s32` (`0x80000000` when negative, zero
otherwise). The original saves the four argument registers, loads the high word
at `[sp, #4]` and masks it with `0x80000000`. Expressing the parameter as a
`MslDoubleBits` union pointer reproduces the argument spill and the high-word
load exactly. Matches 100%.

## func_0201cfd8 — 24 bytes

Releases a heap block through `func_02007170` with arena 0 and heap index -1,
which selects the arena's default heap. The result is returned unchanged
(`ldr ip, [pc, #12]; mov r2, r0; mov r0, #0; sub r1, r0, #1; bx ip`).
`func_020117f0` calls it only for a non-null pointer and ignores the result,
which is the usual `free` contract. Matches 100%.

## func_0201e048 — 8 bytes

Returns the largest positive signed 32-bit value, `0x7fffffff`. The body is
`mvn r0, #0x80000000`, the immediate complement of the requested constant.
Matches 100%.

## func_0201b3ec — 32 bytes

Returns the absolute value bit pattern of a double: the high word is masked with
`0x7fffffff` while the low word is returned untouched. Taking the address of the
parameter reproduces the original's `push {r0-r3}` home area and the in-place
high-word store. The name stays neutral because no caller or string identifies
the public entry point. Matches 100%.

## func_0201b254 — 40 bytes

Copies the sign of the second double onto the first (`copysign` semantics): the
high word of the first argument is masked with `0x7fffffff` and ORed with the
high-word sign of the second argument. Writing the masks as one expression on the
parameter pairs reproduces the original load order and avoids a stack frame.
Matches 100%.

## func_0201cfac — 44 bytes

Adds the integer third argument to a double's binary exponent. `func_0201b5cc`
splits the double into mantissa plus exponent, the exponent is adjusted, and
`func_0201b688` rebuilds the double; both helpers are read from their bodies as
frexp/ldexp-style split and combine. Matches 100%.

## func_0201bb34 — 64 bytes

Sets the decimal digit count at offset +4 and propagates the rounding increment.
The body rejects non-positive counts and counts that do not shrink the current
length, stores the new count, asks `func_0201ba78` whether the digit list is
usable, and only then calls `func_0201bae4`. The store must happen before the
negative-result test, which is why the helper result is held in a local. Matches
100%.

## func_0201ba78 — 108 bytes

Round-up decision for the decimal mantissa. Returns 1 when the digit at `digits`
is greater than 5; returns -1 when it is less than 5; for an exact 5 it scans the
remaining digits to the mantissa length and rounds up if any is nonzero,
otherwise it rounds to even by testing the previous digit's low bit. This is the
`__must_round` contract used by `func_0201bb34` (which increments only for a
non-negative result) and by `__str2dec` in the public MSL source. Matches 100%.

## func_0201bdc4 — 156 bytes

Parses the integer digit run at `text` into the decimal value: stores the binary
exponent, clears the sign byte, copies at most 32 characters minus `'0'` into
`digits[+5]`, stores the count at +4, then applies the same round-half-to-even
decision to the first discarded character (skipping following zeros) and calls
`func_0201bae4` when it must increment. This is the MSL `__str2dec` routine; the
body and the public reconstructed source (`msl_fp_ansi_str2dec.c`) agree,
including the signed-byte loads, which require the source pointer to be
`const s8 *`. Matches 100%.

## func_0201ce94 — 148 bytes

Returns the population count of a 64-bit word (0..64) with the standard SWAR
sequence and the masks `0x55555555`, `0x33333333` and `0x0f0f0f0f`, finishing
with a low-byte mask. The dtoa caller `func_0201c648` subtracts the count from
53; applied to the mask below a normalised mantissa's lowest set bit, that gives
the significant-bit run used to choose the decimal exponent. Passing the value
as `u64` reproduces the r0/r1 argument pair and the exact instruction selection.
Matches 100%.

## func_0201cf3c — 112 bytes

Classifies a double from its IEEE-754 bits, returning 1 for NaN, 2 for
infinity, 3 for zero, 4 for a normal value and 5 for a denormal. The exponent
field is isolated with `0x7ff00000`; when it is zero or all ones the mantissa and
low word decide between zero/denormal or infinity/NaN. Callers such as
`func_0201c648` compare the result with 1 and 2, confirming the encoding. The
argument is inspected through its address, which reproduces the original
`push {r0-r3}` home-area save. Matches 100%.

## func_0201d40c (`_dfix`) — 76 bytes

Double to signed 32-bit conversion with saturation. **Not matched.** The body is
hand-scheduled runtime assembly: it masks the high word, loads the bias constant
after the mask, fuses `1054 - exponent` into `subs ...; ble`, builds the mantissa
in r3, and materialises overflow as `mvn r0, r1, asr #31; add r0, #0x80000000`.
A readable C version with the same bit algorithm is 80 bytes and only reaches
33% because the compiler hoists the constant and the sign shift and splits the
compare from the subtract. Left as delinked assembly.

## func_0201d4e4 (`_dflt`) — 64 bytes

Signed integer to double. **Not matched.** The body starts with `clz ip, r0` and
normalises the mantissa with `lsls`, then assembles the IEEE exponent and
mantissa directly. mwccarm 2.0/sp1p5 exposes no C intrinsic that emits `clz`
(`__builtin_clz`, `__cntlzw`, `_clz` and `#pragma intrinsic` all produce an
external call), and a C normalisation loop compiles to a byte-at-a-time loop.
Left as delinked assembly.

## func_0201d524 (`_dfltu`) — 60 bytes

Unsigned integer to double. **Not matched.** Same runtime shape as `_dflt`, with
an early `cmp r0, #0; bxeq lr`, a sign-bit branch that skips normalisation, and
the same `clz` instruction. For the same reason as `_dflt` there is no C
spelling in this compiler that emits the original `clz`. Left as delinked
assembly.

## func_0201bae4 — 76 bytes

Increments a fixed-length decimal mantissa stored at +5, carrying from the least
significant digit and setting a leading 1 plus `exponent++` on overflow.
**Not matched.** A C `for (;;)` loop produces the exact instruction sequence but
mwcc always appends an unreachable `bx lr` epilogue (80 bytes, 94.74%). The ROM
has no fourth return: the spare `bx lr` at `0x0201bb30` is the separately named
no-op `func_0201bb30`, and no relocation or branch targets it, so the symbol
split treats it as a different function. Left as delinked assembly.

## func_0201d458 (`_ll_ufrom_d` / `_d_dtoull`) — 140 bytes

Double to unsigned 64-bit conversion, truncating; finite negative values give 0,
a negative NaN gives all ones, and values at or above 2^64 give all ones.
**Not matched.** The routine is hand-written MSL runtime assembly (identical to
`_ll_ufrom_d` in pokebw2's `fp_fastI.s` and `d_dtoull` in pokeheartgold's
`msl_fp_runtime.c`). A readable C version is 168 bytes: it reproduces the
positive path and the shared zero/all-ones returns, but mwcc materialises the
negative-range constant `0xFFF00000` in a register and uses a branchless
select, whereas the ROM uses `cmn r1, #0x100000; cmpeq r0, #0; bhi` and a shared
tail block. No C spelling tried (`u64` and two-`u32` signatures, comparison with
`0xFFF0000000000000`, subtraction and carry tests) produced the `cmn` form.
Left as delinked assembly.

## _dgeq (`func_0201e050`) — 152 bytes

Double comparison `a >= b`, returning 1/0 and also leaving the result in the
CPSR carry flag for callers that branch immediately after the call.
**Not matched.** The routine is hand-written MSL runtime assembly (the same body
appears as `_dgeq` in pokebw2's `fp_fastI.s` and pokeheartgold's
`msl_fp_runtime.c`). It tests both operands for infinity/NaN with
`cmn r12, r1, lsl #1`, orders finite values by sign, and writes CPSR with
`mrs`/`msr`. C cannot both return the boolean and set the caller-visible CPSR
flag, and emitting the `mrs`/`msr` sequence would require inline assembly, which
the project forbids. Left as delinked assembly.

## _dgr (`func_0201e0e8`) — 152 bytes

Double comparison `a > b`, with the same return-plus-CPSR-carry contract as
`_dgeq`. **Not matched.** Same hand-written runtime body and same reason: the
condition-code side effect is not expressible in portable C without inline
assembly. Left as delinked assembly.

## _deq (`func_0201e2c0`) — 140 bytes

Double comparison `a == b`, returning 1/0 and leaving equality in the CPSR Z
flag. **Not matched.** Hand-written MSL runtime assembly (it explicitly
sets/clears `0x40000000` for the unordered case). The CPSR side effect is not
expressible in portable C without inline assembly, which the project forbids.
Left as delinked assembly. (The neighbouring `_dleq`, `_dls` and `_dneq` belong
to other cards and have the same shape.)

## Validation

`python3 tools/match_gate.py` reports 100% for all C definitions in this unit,
`python3 tools/checksum.py` reports all artifacts byte-identical to the original,
and `python3 tools/anticheat.py` passes. No unit tests are required by this card;
objdiff compares the generated instructions and relocations against the
delinked object.

## Hard list

- `func_0201d40c` (`_dfix`): hand-scheduled conversion; C scheduling differs.
- `func_0201d4e4` (`_dflt`): `clz` not reachable from C in this compiler.
- `func_0201d524` (`_dfltu`): `clz` not reachable from C in this compiler.
- `func_0201bae4`: C always emits a trailing `bx lr`; the ROM epilogue is
  symbolised separately as `func_0201bb30`.
- `func_0201d458` (`_ll_ufrom_d` / `_d_dtoull`): hand-written assembly; the
  `cmn`/`cmpeq` range test and shared return blocks do not come from C.
- `_dgeq`, `_dgr`, `_deq`: hand-written comparisons that return a boolean and
  leave the answer in CPSR for the caller; inline assembly would be required.

These eight are good candidates for a decomp.me scratch
(`FORGE_DECOMPME_OK=1 python3 tools/decompme.py`) or a human-written assembly
file if the project later allows per-function asm.
