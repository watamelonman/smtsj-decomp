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

## DEC-002 — Address the work-area flag array as u32 arithmetic
**Date:** 2026-10-22 · **Status:** Active
**Context.** `func_020c1968` adds an index to the work-area pointer and reads the signed
byte at `+0x348 + index`. Expressing this as `work[idx + 0x348]` makes mwcc use a
register-offset `ldrsb`, while the original adds the index to the base first and then
reads at a small constant offset.
**Decision.** Add the raw addresses (`(u32)GetWorkArea() + (u32)idx + 0x300`) and read
`flags[0x48]`, which reproduces the original `add r0, r4, r0; add #0x300; ldrsb #0x48`.
**Cost accepted.** The expression is less idiomatic than array indexing and needs the
accompanying comment.
**What would make us revisit.** A compiler flag or typed work-area struct that produces
the same addressing without the explicit casts.
