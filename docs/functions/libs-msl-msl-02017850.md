# libs/MSL/msl_02017850.c

Eight functions at the start of this delink unit are reconstructed as readable C
and match the delinked original at 100% with mwccarm 2.0/sp1p5. The rest of the
unit stays as delinked assembly for later cards.

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

## Validation

`python3 tools/match_gate.py` reports 100% for all eight C definitions added by
this card, `python3 tools/checksum.py` reports all artifacts byte-identical to
the original, and `python3 tools/anticheat.py` passes. No unit tests are
required by this card; objdiff compares the generated instructions and
relocations against the delinked object.

## Hard list

None. All eight functions in this card match.
