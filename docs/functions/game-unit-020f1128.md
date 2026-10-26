# game/unit_020f1128 — M1-T876 / M1-T877

All eight requested functions match at 100% with the configured mwccarm compiler.
Names are retained from the symbol configuration; behavior below is grounded in
original ARM instructions rather than inferred game semantics. The TU remains
linked from its delinked object until a human marks it complete.

| Function | Size | Instruction evidence and contract |
| --- | ---: | --- |
| `Unk0f1128_Nop_0f21ac` | 4 | Bare return; intentionally empty callback. |
| `Unk0f1128_Unk_0f2d60` | 32 | Copies its word argument to a local and passes its address to `Unk0bd5f0_Unk_0c7f70(7, 0, ..., 1)`. Callee must consume the local synchronously. Taking the parameter address instead creates a different stack frame. |
| `Unk0f1128_Unk_0f2d30` | 48 | Adds 200 to argument 1 and passes a pointer to that local to `CampStatus_Unk_0dde3c` with command pair 12/23 and count 1. Arguments 2 and 3 are unused. |
| `func_020f1490` | 92 | Writes descriptor size 0x500, zero flags and six callback addresses at +0x0c through +0x20; preserves +0x08. Callback slots retain the original symbol addresses. |
| `func_020f2e1c` | 92 | Reads count at +0x28 and halfword ids from twelve-byte records starting +0x2c. Looks up each id, conditionally forwards the returned entry after the predicate call, then stores the final helper result at byte +0x24. |
| `func_020f2bfc` | 148 | Conditionally releases +0/+4, unconditionally releases two handles at +0x4dc/+0x4e0, and clears those slots. Calls the release helper on +8/+0x0c even for null handles, then conditionally clears them. |
| `func_020f2d80` | 156 | If +0x4f0 is nonzero, calls three helpers and writes state 12 at +0x4e4. Otherwise clears two bytes and sixteen words of a local control structure, submits it for indices 1 then 0, and forwards `(work, 1)`. The two alignment bytes are not initialized or interpreted here. |
| `func_020f2c90` | 160 | Calls setup, obtains context `(6, 0)`, and processes rows from signed +0x20 while the unsigned count bound and signed start-plus-18 bound allow. Submits only the final result, when nonnull, using handle +8 and arguments -1/0/0. Count/start are reread after calls as in the original. |

The work view names only fields used here. The fixed hundred-row extent follows
from the interval +0x2c..+0x4dc and twelve-byte stride; callers must supply valid
row bounds and a full work allocation. The callback descriptor and control views
are local to this TU; no module boundary changes were required.

## Hard list

None for M1-T876.

## M1-T877

Two additional functions match at 100%. The prior eight remain at 100%.
No behavior tests were added: the card disables the test-first requirement for
this binary-matching work; objdiff is the instruction-level acceptance check.

| Function | Size | Result and contract |
| --- | ---: | --- |
| `func_020f14ec` | 532 | **100%.** Borrows work and an event envelope whose first word selects events 0..4. Event 0 reads flag bit 3 and payload word 3 to set +0x4f0/+0x4f4. Event 3 reads flag bit 0/word 0, handles value 7, and optionally reads bit 3/word 3 to select state 11 or cancel pending state. Cancellation releases the selected provider entry and adjusts byte +0x24; both display handles receive flag 1. Other events return. |
| `func_020f1700` | 532 | **100%.** Borrows full work with handle prefixes pointing to provider objects. State 4 reduces +0x10 by 25 while positive, advances +0x14 up to ten and computes floating progress /10, then activates handles and copies +0x4e8 to state. State 11 waits for slot 7, submits command 32 or a halfword-truncated provider result +24, then enters state 9. States 9/10 increment and clamp byte +0x4ec to 16. State 12 waits before submitting controls 0/2/1/3/10. Every path decrements nonzero byte +0x4fc and signals flag inversion when it expires. |
| `func_020f1128` | 872 | **Best attempt 98.73%**, not linked. Reconstructed initializer: two display handles and two resource handles; provider IDs 111..210 are scanned into twelve-byte rows at +0x2c, sorted with `Unk0f0eac_Unk_0f1000`, and an initial control request is submitted. The candidate is `docs/functions/game-unit-020f1128-candidates.c`. Remaining blocker: the final request call is 6-argument in the original (two outgoing stack words at sp+0/sp+4 plus a control block at sp+8), and the original emits separate `str` stores while mwcc emits `stmia sp,{r0,r3}`; the two zeroing loops also use the opposite r0/r1 roles unless a separate loop variable is introduced. Candidate size 880 vs 872. |
| `func_020f1914` | 2200 | **Best attempt 81.02%**, not linked. Reconstructed state-13 input callback: masks 0x200/0x100 toggle display flags; 0x40/0x80 move by two columns with signed remainder-by-two wrap handling; 0x20/0x10 move one column; 0x1 activates the selected provider (matching bits 8..13 of provider halfword +6, releasing duplicates and adjusting +0x24); 0x400/0x200/0x100 handle pending state and the three sort modes. Candidate in the snapshot file. Remaining blockers: target keeps `old`/`mode` in stack slots sp+8/sp+4 and uses r10 for work (candidate uses r4/r5/r7), the navigation branch layout differs, and the 512/256 sort-mode switches compile as a compare/beq chain instead of the original compare/bne fall-through. Candidate size 1988 vs 2200. |
| `func_020f21b0` | 2636 | **Best attempt 92.32%**, not linked; candidate size 2700 vs 2636. Reconstructed draw callback: nine-by-two row loop with 13/122 spacing, fade/progress draws, provider predicate checks, scrollbar fixed-point divisions, state-13 selection overlay, and the state-9/10 timer bar. Remaining blockers: the row predicate is materialized as a boolean (`disabled`) where the original uses direct branches, so the branch tree and r6/r7/r8/r9 allocation differ; the same applies to the selection-overlay `enabled` predicate. A direct-branch rewrite removed the boolean but duplicated the draw sequences and grew the function. |

### Hard list (M1-T877)

- `func_020f1128`: finish the final control-request stack layout; best 98.73%,
  blocker is `stmia` vs separate outgoing-argument stores (see above).
- `func_020f1914`: register/stack-slot allocation and branch layout; best 81.02%.
- `func_020f21b0`: row/overlay predicate branch layout and register allocation;
  best 92.32%, size already matches.

The complete best-attempt C for all three is kept in
`docs/functions/game-unit-020f1128-candidates.c` (standalone, never linked).
A human can also prepare a scratch with
`tools/decompme.py scratch FUNC --check --dry-run --write /tmp/FUNC`.
These functions remain supplied by the delinked object; this DS project does not
use PS2 `INCLUDE_ASM` stubs.

