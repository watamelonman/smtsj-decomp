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

## DEC-002 — Preserve the index-free record lookup call
**Date:** 2026-10-22 · **Status:** Active
**Context.** `Unk09a268_Unk_09c498` calls `Unk09a268_Unk_09c484` without
initializing its index register and discards the returned address.
**Decision.** Keep the lookup's full `int` parameter prototype, and explicitly cast
its function pointer to a no-argument signature at this exceptional call site.
Supplying an invented index would change the original instructions.
**Cost accepted.** This compiler-specific call boundary describes the observed ARM
ABI rather than a portable C call; objdiff verifies its instructions at 100%.
**What would make us revisit.** Evidence of an original shared declaration that
explains the incompatible call signatures.
