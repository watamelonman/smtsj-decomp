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

## DEC-008 — Preserve direction reads and dispatcher relocations in 020f6250

The original 020f6998 reads the global direction at +358 for its switch and
reloads it for 02034b7c. A volatile-qualified field preserves those two accesses;
this records observed access behavior without asserting hardware ownership.
Ordinary reads cache the direction and change both register allocation and size.
The 020f6ef8 dispatcher follows its C callees because placing it before them
produced a 99.75% objdiff relocation discrepancy despite the standalone byte
comparison passing. With this ordering all seven implemented functions match.
Revisit these constraints if compiler or original-type evidence supplies a
matching ordinary declaration or objdiff resolves forward local calls identically.
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

## DEC-009 — Preserve integer address calculation in 02058824

The teardown wrapper computes a 48-byte record offset, then reloads the global
base after its first call. Using typed array indexing for both calls lets mwcc
retain the whole record address and removes two original instructions. Compute
the first address as a 32-bit integer plus the byte offset, then use the typed
record view for the second call. This preserves the original instructions on
the DS's 32-bit address space without changing record layout or call semantics.
Revisit if original SDK declarations explain this distinction.
## DEC-009 — Keep the SDK build record in the startup text section

`BuildInfo` at 0x02000ba0 is data inside the original executable section, not a
function. Define this translation unit's `rodata` section as executable `.text`
with mwcc's `define_section` pragma so its typed constant record stays in the
original section. The ARM `arm section` pragma does not change mwcc's output.
This setting is local to the source file; the public header has no section
side effects. The first four pointers retain the original relocations; the
unrelocated static BSS end remains the literal linker boundary 0x02176ea0.
## DEC-009 — Preserve signed text byte access in 020a9a90

The two glyph loops test signed bytes and separately reload the byte passed to
020a9ac8. Use a signed cursor for termination and space tests, and an unsigned
byte read explicitly converted to s8 for the mapping argument. These equivalent
C byte views reproduce the original loads with mwcc without introducing volatile
semantics. The glyph mapper accepts a signed byte; the resource indices and
coordinates remain signed integers as evidenced by the original arithmetic.

## DEC-010 — Preserve the context reload in 020bc614

The original reloads data_02176ba8 on every slot iteration. An ordinary read
lets mwcc hoist that load, changing the instructions and register allocation.
Use a volatile view for this loop's context pointer read to preserve the observed
accesses. This matching constraint does not establish synchronization or hardware
ownership; the table and object words remain ordinary memory accesses.

## DEC-011 — Preserve local call direction in 020bc1a8

Place 020bc770 before 020bcbc4 and 020bc2fc before 020bc814. With this
compiler, forward and backward local call relocations have different encoded
branch addends; the report's fuzzy comparison distinguishes them even when the
interactive diff resolves both to the same symbol. Callee placement reproduces
the original call direction without changing behavior or tool configuration.


## DEC-012 — Preserve address-based optional-word copies in 020ff140

The original initializer stores constants in two stack words as well as copying
those words into the outgoing presence-tagged message. An inline helper taking
a typed pointer eliminates the separate stores with mwccarm 2.0/sp1p5. Pass the
borrowed source as a 32-bit DS address and dereference it as s32 inside the helper;
this retains the observed copies without volatile access or extra side effects.
The caller owns both source words until the inline copy finishes. The helper is
private to this TU; its index must be in 0..15.
## DEC-012 — Preserve the palette transfer singleton reload

The original 0206f508 reloads buffer state from data_02170ccc +4 after scanning
its dirty bits. An ordinary C read lets mwcc retain the state across the scan,
changing both register allocation and the transfer setup. Use a volatile word
view for this single reload to reproduce the observed access. This matching
constraint does not imply concurrent mutation or hardware ownership. Slot
contents and the scan itself remain ordinary memory accesses.


## DEC-013 — Preserve one-word request records in 020f7188

The four request builders store selected values both in source stack slots and
in outgoing request words. Model each outgoing word as a one-word record and
copy a local record into it. With mwccarm 2.0/sp1p5 this reproduces those stores
without volatile accesses, padding stores or compiler directives. Ordinary scalar
assignments remove the source copies. The two flag bytes and sixteen records
are cleared separately, leaving the two alignment bytes unspecified as in ARM.
These private views describe only the observed request layout, not gameplay meaning.


## DEC-014 — Preserve bounded scan entry checks in 020986ac

The three scans at 02098740, 02098860 and 020988bc compare the initial id
111 to 210 before entering the loop. mwccarm 2.0/sp1p5 normally propagates
that constant and removes the entry comparison and branch. Scope
`opt_propagation off` to these three functions to preserve the observed
control flow without changing their ordinary C behavior. Declaring the result
before the id also reproduces the original register allocation. All three
functions then match at 100%; the pragma is popped before any later code.


## DEC-015 — Preserve StaffRoll image lookup scheduling

In func_02117f94, retain a borrowed pointer to the selected ten-word table row
and add its selected value twice before adding the image record's resource
index. With mwccarm 2.0/sp1p5, spelling this as multiplication by two schedules
the two table lookups differently and changes register allocation. Repeated
addition reproduces the original shifted add and all preceding instructions
without volatile accesses or compiler directives. Table values must keep the
signed index arithmetic in range, and both table indices must be valid.


## DEC-016 — Preserve 02098b9c register allocation

The record/permission dispatcher at 02098b9c assigns its state and coordinate
arguments to r6/r5/r4, with kind and enabled in r7/r8. mwccarm 2.0/sp1p5 lifetime
optimization instead assigns kind/enabled to r4/r5 and shifts the arguments to
r8/r7/r6. Scope `opt_lifetimes off` to this function to retain the original
allocation without volatile accesses or changes to C behavior. Typed borrowed
bitfield views preserve the observed shift pairs for packed permission fields.
All 1104 bytes then match; the pragma is popped immediately after the function.


## DEC-017 — Preserve 0203a0a0 and 0203a1dc propagation boundaries

Scope `opt_propagation off` separately to these two functions and restore
compiler settings immediately afterward. For the saved-value duplicate,
explicit slot/value temporaries retain the original word-copy registers.
For callback dispatch, local typed pointers retain the numeric table-base
literal loads instead of folding the addresses into immediate additions.
Initialize the count view after early callback returns, matching its original
lifetime. Its eight-byte stride exposes the consumed-count word at record +4.
These settings preserve ordinary C behavior without volatile accesses,
assembly, or changes to the human-owned relocation configuration.

## DEC-018 — Type the 0209d42c singleton storage

Declare `data_02176278` as a private struct with 64 observed 32-byte name slots,
count, cursor, and phase words. Retain a byte view for the earlier matched
functions. Direct typed member updates in 0209d44c and 0209d500 preserve the
original load/store ordering and register allocation; casting the byte array
at each update produced different instructions. This changes no ownership or
storage allocation: the singleton remains externally defined. All earlier
functions and the eight M1-T708 additions remain at 100% objdiff.
## DEC-018 — Preserve 02039bb4 stack-handler code generation

For the record initializer, disable strength reduction and common-subexpression
elimination locally: the original indexes both stack arrays independently and
recomputes the selected record address after the name copy. Explicit do/while
loops retain the original first-iteration control flow. For the directory scan,
disable lifetime optimization and reuse the directory count as the record index;
declaration order retains the original registers across string comparisons.
For tagged negation, disable lifetime optimization and common-subexpression
elimination so the float store recomputes its stack address after subtraction.
For binary operations, disable propagation to retain separate global result
stores and reloads. Explicit branches assign boolean results; logical float
operands compare against double zero as established by the conversion calls.
Each setting is restored immediately after its function. These choices preserve
ordinary memory semantics without volatile accesses or assembly.

## DEC-019 — Preserve 0211d884 conditional assignment ordering

Disable conditional rebuilding only for `func_0211d884`, restoring it immediately
afterward. With the default setting, mwcc converts the group-0/group-1 selection
into a boolean and emits the two conditional moves in reverse order. Disabling
this transformation preserves the original `movne 0; moveq 1` sequence while
retaining readable C and ordinary memory semantics. The input handler follows
its local callees in source, as in the delink; this also preserves its 100% score
in the project report. No assembly or volatile accesses are required.

## DEC-020 — Preserve the 0211727c word argument to the byte setter

The call at 0x02117288 forwards the complete result of 0x021171c8 in r0 to
0x0202f20c, without a byte mask, and returns the complete saved result afterward.
Declare the provider argument as a word in this TU to describe that observed ABI.
The provider's byte store at work +0x361 consumes only the low byte (see
`src/game/unit_0202f078.c`); its implementation's byte parameter would cause mwcc
to insert an extra caller-side mask here. No value range for the mapping inputs
is assumed, and no full-result truncation is introduced.

## DEC-021 — Preserve descriptor indexing and local zero-store order

**Date:** 2026-10-26 · **Status:** Active
**Context.** `func_020cc3c0` and `func_020cc5d8` access the 68-byte descriptor
at work +0xdc. Caching an `Unk0cb32cParams *` local makes mwcc keep the
address in a register, changing the original `adds r1,r4,#0xdc` null check and
the `work + i` / `work + i*4` scaled loop stores. In `func_020cccc4`, a scalar
`index = 0` lets mwcc schedule the work-state load before the zero store, while
the original stores zero through a materialized `&index` first.
**Decision.** Access the work descriptor through the typed
`Unk0cb32cWorkParams` view, and declare the event index as a one-element
`u32 index[1] = {0}` in the case block. Both are local code-generation
constraints; the fields remain ordinary borrowed memory.
**Cost accepted.** The source spells two MWCC-specific matching shapes instead
of the cleanest scalar form.
**What would make us revisit.** Compiler or original-type evidence that
reproduces the same accesses with ordinary scalar locals.
## DEC-021 — Preserve the 020a65c4 radius-scan register split

Scope `opt_strength_reduction off` to `func_020a65c4` and restore the setting
immediately afterward. With the default setting, mwccarm 2.0/sp1p5 gives the
outer row counter r7 and the `y - row` absolute-value temporary r6; the original
uses the opposite split and conditional-move schedule. Disabling strength
reduction for this function preserves the original r6/r7 assignment and the
`movge`/`movlt` order while leaving the C semantics ordinary. No assembly,
volatile accesses or byte blobs are involved.

## DEC-022 — Preserve the 02044b84 rank table and 02045138 loop form

The delinked 02044b84 object embeds 0x0212cc24 as a plain literal-pool word
with no relocation; no symbol exists for that byte table in the human-owned
symbol map. Reference the table by its observed address and scope
`opt_propagation off` to the function so mwccarm 2.0/sp1p5 emits the literal
load instead of folding the address into immediate additions. The same scoped
setting on 02045138 keeps mwcc from constant-folding `sizeof(order)-1` and the
descending pointer into an immediate stack offset; explicit do/while loops
retain the original store-before-test shape and avoid loop rotation. Both
pragmas are restored immediately after their functions. No assembly, volatile
accesses, relocation changes or byte blobs are involved.

## DEC-022 — Keep the 020cbce4 index reset in the provider argument

The state-3 path clears work +0xd4 and submits a halfword-aligned 114-byte list
by value to 020deaa0. Express the clear as the final index argument assignment.
With a separate preceding statement, mwcc schedules the work store before the
outgoing stack-address calculation; the original calculates that address first.
The argument assignment preserves both the reset-before-call contract and the
original instruction order. The list copy reads +0x20..+0x91, disjoint from the
reset word, so argument evaluation order does not change the submitted data.

## DEC-023 — Keep one live range for the 020ecf20 selection index

The mode dispatcher derives a selection index before its switch, and the
original keeps that index in callee-saved `r4` as a single live range. Under
default lifetime splitting, mwccarm 2.0/sp1p5 instead places the post-call zero
initialization in caller-saved `ip`, shifting the parameters to `r5`/`r4` and
changing the instruction schedule. Scope `opt_lifetimes off` to this function
and restore the setting immediately afterward. The pragma changes no C
semantics: the index still defaults to zero, mode 0 overwrites it on both area
paths, and mode 1 only relies on the default when the area exceeds eight.


## DEC-024 — Preserve byte-copy pointer order in 02115498

The original copies two byte-aligned sixteen-byte ID blocks with paired-byte
loops. A byte-array aggregate assignment produces those loops, but default
mwccarm propagation computes the source pointer first and swaps its register
with the destination pointer. Explicit destination/source locals with
`opt_propagation off` reproduce the original destination-first allocation.
Scope this setting to `func_02115498` and restore it immediately afterward.
The C still performs ordinary aggregate copies without assembly or code blobs.


## DEC-026 — Preserve CaveArea render callback expression boundaries

Scope `opt_propagation off` and `opt_common_subs off` to `func_020ec704`,
restoring both immediately afterward. Propagation otherwise hoists the layer
constant across the layout branches; common-subexpression optimization folds
the three byte-state equalities into a range check. The original uses three
conditional compares and separate branch argument setup. Array views preserve
base-plus-index loads, and declaring the pair index before the area index
reproduces the original r4/r5 allocation. These settings leave the draw behavior
unchanged; the individual 1156-byte function verifies at 100% in objdiff.

## DEC-027 — Keep CaveArea background paths duplicated

`func_020ecc24` submits the same two background strips and three frames in
both arms of the `FIELD(u8,p,0xa8)` test, followed by `func_020ed800` or
`func_020ed8f4`. Hoisting the shared sequence above the test is the natural C
form, but the compiler then emits one common path and the branch layout no
longer matches the original; objdiff drops the function from 100% to about
55%. The two paths therefore stay written out in full so each arm reproduces
the original instruction sequence. The duplication is deliberate and must not
be collapsed without rechecking objdiff.

## DEC-025 — Preserve 02113294 branch, list-loop and sentinel behavior

`func_02113974` uses a switch for the word +32 assignment and scopes
`opt_propagation off` to retain the original branch-and-merged-store shape.
`func_021151fc` scopes the same setting to retain the original group/index
register allocation; explicit do loops avoid redundant initial bounds checks.
`func_02115500` scopes `opt_strength_reduction off` to retain the original
halfword-index sum rather than independently incremented byte pointers.
All settings are restored immediately after the relevant function.

The original 02115500 reserves 76 stack bytes (including the outgoing argument),
zeroes 72 bytes at stack +4, and writes sentinel 0x8001 at stack +36, +70 and
+104. The final write exceeds that buffer and the local stack reservation.
The matching implementation retains this original defect as `ids[50]` in a
36-halfword array; extending the array would change the stack frame and fail
instruction matching. This is a reconstruction of observed behavior, not a safe
buffer contract for new callers. The TU continues linking from the delinked
original until a human marks it complete.

## DEC-026 — Keep the 02113bc4 zero stores at their original biased addresses

The original of `func_02113bc4` zeroes `work+214+2*limit` and
`work+214+2*end`, which are the ID slots at index `limit-1` and `end-1`, not
`ids[limit]`/`ids[end]` in the plain `work+216` view. Casting `work-2` before
indexing emits the original `strh ..., [r1, #214]` addressing without a
separate subtraction. The inline comments at each store record that intent so a
future change to the `Unk113294Ids` layout cannot silently move the writes.
Scope `opt_propagation off` separately to `func_02113bc4` and
`func_021153a4` and restore it after each; the split scopes still match.

## DEC-027 — Preserve indexed provider selection in 0211527c

Scope `opt_strength_reduction off` to `func_0211527c` and restore it immediately
afterward. With the default setting, mwccarm keeps a separate provider byte offset
on the stack and increments it each group; the original instead computes
`work + group*4` and loads at +160. Explicit row pointer and base-index locals
preserve the eleven-entry row stride without changing the grid contents.
