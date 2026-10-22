# Decision log

One numbered entry per non-obvious choice. Cite from code as `See DEC-00N`.

## DEC-000 — Title
**Date:** · **Status:** Active
**Context.** **Decision.** **Why.** (include the rejected alternative) **Cost accepted.**
**What would make us revisit.**

## DEC-001 — Preserve the record setter's observed word argument
**Date:** 2026-10-21 · **Status:** Active
**Context.** `Unk0bb2b0_Unk_0bb450` passes an untruncated 32-bit sum in r1 to
`Unk02e000_SetRecordUnk1c`. The setter's separate source declares a u16 value,
and its implementation stores that value with a halfword store.
**Decision.** Declare the caller boundary with a u32 value, matching the original
register argument. A u16 caller declaration would add truncation instructions
absent from the original. See `docs/functions/game-unit-020bb2b0.md`.
**Cost accepted.** The local declaration describes the observed machine ABI,
rather than sharing the callee translation unit's narrower C parameter type.
**What would make us revisit.** Evidence of a shared original prototype or a
project-wide convention for reconciling these historical call boundaries.

## DEC-002 — Preserve argument-free lookup calls
**Date:** 2026-10-22 · **Status:** Active
**Context.** `Unk09a268_Unk_09c498` calls `Unk09a268_Unk_09c484` without
initializing its index register and discards the returned address. Its preceding
`func_0209bb68` call likewise supplies no encoded-cell argument and discards
the kind result.
**Decision.** Keep both lookups' full parameter prototypes, and explicitly cast
their function pointers to no-argument signatures at these exceptional call sites.
Supplying an invented index would change the original instructions.
**Cost accepted.** This compiler-specific call boundary describes the observed ARM
ABI rather than a portable C call; objdiff verifies its instructions at 100%.
**What would make us revisit.** Evidence of an original shared declaration that
explains the incompatible call signatures.

## DEC-003 — Mark the work-area kind field volatile
**Date:** 2026-10-22 · **Status:** Active
**Context.** `func_0209c854` switches on the shared work area's +0x358 kind word
and then passes the same field to `func_02034b7c`. The original reloads the field
for the call; a plain typed read is coalesced by mwccarm and produces one less
instruction.
**Decision.** Declare the +0x358 field `volatile` in the partial work-area layout
so both reads are emitted, matching the original instruction stream.
**Cost accepted.** The qualifier describes the observed reload requirement; the
field is engine-shared, so callers must not assume it is stable across calls.
**What would make us revisit.** Evidence that the original field is not shared, or
a non-volatile formulation that reproduces the same two loads.
