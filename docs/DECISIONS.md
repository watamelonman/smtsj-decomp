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

## DEC-004 — Model the +0x30 draw resources as 96-byte entries
**Date:** 2026-10-22 · **Status:** Active
**Context.** `src/game/unit_020b28e4.c` accesses the block from +0x30 to +0xc2f
through the offsets +0x30, +0xf0, +0x150, +0x1b0, +0x210, +0x270, +0x2d0,
+0x330, +0x390, +0x7b0 and +0xbd0, and the dispatch routine indexes digit
entries with `(page + 22) * 96`. Every offset is 0x30 modulo 0x60 and the span
is exactly 32 entries, so the block is one array of 96-byte draw resources.
**Decision.** Replace the separate byte arrays with
`Unk0b28e4Entry96 unk_0030[32]` and index it by the observed entry number.
Offsets and generated code are unchanged for the already-matched functions;
only the field names changed. Cited from the layout comment in
`src/game/unit_020b28e4.c`.
**Cost accepted.** Most of the entry's internal layout stays opaque. The
initialization loop reveals three fields at entry +0x5a..+0x5d, which are
modelled in `Unk0b28e4Entry96`. That loop addresses them as
`work + i*96 + 0x8a` (a 0x30-byte header precedes the entry array), and the
cleaner `&work->unk_0030[i] + 0x5a` form changes mwcc's register allocation;
the `Unk0b28e4EntryFlags` overlay therefore documents that anchor explicitly as
a matching constraint.
**What would make us revisit.** A string, caller or data table that identifies
an individual field inside an entry, or a codegen change that lets the loop use
the entry pointer directly.

## DEC-005 — Define same-unit callees before their callers
**Date:** 2026-10-22 · **Status:** Active
**Context.** objdiff's report (`fuzzy_match_percent`, used by `match_gate`)
scores a caller below 100% when it is laid out before a same-unit callee that
this change newly defines, even though `objdiff-cli diff` and a word-by-word
comparison show identical instructions. `func_020b32bc` was 99.94% while it
preceded `func_020b4674` and `func_020b5070` in the object, and 100% after it
was moved after them.
**Decision.** Order definitions so that every same-unit callee precedes its
callers, even when the callee's ROM address is higher. The check uses the
report, not the per-symbol diff.
**Cost accepted.** Source order no longer follows ROM address order at the tail
of this TU; the section order is not part of any gate.
**What would make us revisit.** An objdiff release whose report resolves the
relocations without the ordering constraint.


## DEC-006 — Preserve the visible-count reload order in 020e40a4
**Date:** 2026-10-22 · **Status:** Active
**Context.** The original reloads work +0x6c after the handle callbacks and
before advancing the local slot cursor. Ordinary C reads compile with the
cursor increment scheduled before the reload, leaving two instructions different.
**Decision.** Use a volatile-qualified read of this single typed field at that
point. The loop still uses the callback-updated count; no whole-object volatile
qualification or guessed hardware ownership is implied.
**Cost accepted.** A local code-generation constraint is explicit in the source.
**What would make us revisit.** Compiler or original-type evidence that reproduces
this ordering with an ordinary field read.

## DEC-007 — Preserve the two submission views of work +0xb4

`func_020e2930` passes the word at work `+0xb4` unchanged to both
`func_0205de40` (an integer argument) and `func_0205e048` (a float argument).
Model that field as a union of `u32 bits` and `float scale` so both calls
preserve the original bits without numeric conversion. The initializer clears
its integer view. The instruction evidence establishes the representation;
it does not establish the field's game-level meaning.

## DEC-008 — Preserve work-relative entry flag views in 020fbed4

The initializer and wrapping draw callback address entry flags as
`work + index * 96 + 0x6d`, while entry submissions use a base at work +0x10.
Keep a shifted private work view for the flag accesses and the separately based
entry addresses for submissions. These are views into the same allocated work
block, not separately allocated work objects. Collapsing both expressions into
ordinary entry-array indexing changes multiplication and register allocation;
the separate views reproduce the original instructions at 100% objdiff.
## DEC-008 — Variadic argument cursors in game/unit_020a9a90

The original formatting wrappers align the address of the last named argument
to four bytes and advance one word to obtain the variadic cursor. Express that
32-bit ARM ABI operation directly in C, passing the borrowed cursor to
`func_02013b94`. The compiler distribution has no standard headers in this
project; `__builtin_next_arg` compiled as an external call rather than an
intrinsic. The explicit cursor expression matches all four wrappers exactly.
This is target-specific and should be revisited if standard library headers
become available or the target ABI changes.
## DEC-008 — Preserve the final comparison in 020f4928

The original callback calls two accessors, loads work +8, compares it to 1,
and returns unconditionally. Express the comparison as an early return in C:
MWCC retains the original comparison even though both paths return. Removing
it loses instruction equivalence. No game meaning is inferred from this test.
## DEC-008 — Preserve the selection scan's shared indexed exit

The three functions in `game/unit_020b0e08` branch from a successful inclusive
weight comparison to the same indexed load used after an exhausted scan sets
the index to `count - 1`. Use a local `selected` label to share that return.
A separate return inside the loop duplicates the epilogue; a post-loop bounds
check emits an extra comparison. Preserve the original inclusive comparison
and last-candidate fallback. Revisit if compiler/type evidence reproduces the
same control flow without a label.
## DEC-008 — Preserve VER record-count observations

`func_0206f778` reloads the file header's record count at loop tests and again
when preparing the subsequent copies or installation calls. Ordinary C lets
mwcc retain the final loop-test value and removes two original loads. Qualify
only the typed count field as volatile to preserve these observations and their
instruction order. This is a matching constraint, not evidence of hardware or
concurrent ownership. Revisit if original type or compiler evidence reproduces
the reloads without the qualifier.
## DEC-008 — Model 0206dafc interior symbols as one record array

`func_0206dafc` clears 328 bytes at `data_0216bac8 + index * 328` and
initializes bytes within that same record. The delinker labels those bytes
with individual data symbols. Represent them as fields in one typed record
rather than independent strided arrays: the latter imply unrelated objects
and produce different register allocation. The unified layout matches all
instructions, and objdiff resolves its interior relocations at 100%. Padding
records only observed offsets; the table capacity and field meanings remain
unknown. Revisit if further data-layout evidence changes the record boundary.
## DEC-008 — Preserve the aligned name buffer in 0203812c

The original clears its 16-byte temporary name with four word stores before
copying sixteen signed bytes. A union of four words and sixteen bytes expresses
that alignment and byte access in C; a plain byte array compiles to a byte-clear
loop. Keep dictionary entries 5–7 as separate assignments followed by record
initialization, matching the original unrolled tail and field-read expression.
## DEC-008 — Preserve stack count reloads and size-table ordering in 0205b540

The original push reloads the count between the two size-table writes and on
each diagnostic scan iteration. The pop reads the second size only after
restoring the first cursor. Qualify the count and size-table accesses as
volatile to preserve those observed accesses and ordering. This is a matching
constraint, not evidence of hardware ownership or synchronization. Ordinary
accesses let mwcc cache the count and hoist the second size load; revisit if
original declaration evidence permits reproducing the accesses otherwise.
