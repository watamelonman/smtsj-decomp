# libs/MSL/msl_02017850.c

Twelve functions in this delink unit are reconstructed as readable C and match
the delinked original at 100% with mwccarm 2.0/sp1p5. Four further routines in
this card (one decimal helper and the three `_d*` conversion/intrinsic routines)
remain as delinked assembly and are listed at the end; they are hand-written
runtime assembly that the pinned C compiler does not reproduce.

The unit is part of the MSL double-precision math library. No public NitroSDK
MSL source matches this ROM build, so the bodies and call sites in
`libs/CRI/cri_0208aba0.c` and `libs/NitroSDK/sdk_020116a8.s` were used as
evidence. The four wrappers only load a target address and branch with the
argument registers untouched, which is the MSL tail-call shape; every caller in
CRI passes the result of `_f2d`, so the argument and result are `double`.

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

These four are good candidates for a decomp.me scratch
(`FORGE_DECOMPME_OK=1 python3 tools/decompme.py`) or a human-written assembly
file if the project later allows per-function asm.
