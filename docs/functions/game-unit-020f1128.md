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

| Function | Size | Instruction evidence and contract |
| --- | ---: | --- |
| `func_020f14ec` | 532 | Borrows work and an event envelope whose first word selects events 0..4. Event 0 reads flag bit 3 and payload word 3 to set +0x4f0/+0x4f4. Event 3 reads flag bit 0/word 0, handles value 7, and optionally reads bit 3/word 3 to select state 11 or cancel pending state. Cancellation releases the selected provider entry and adjusts byte +0x24; both display handles receive flag 1. Other events return. The typed local payload view preserves unconditional word loads before flag testing. |
| `func_020f1700` | 532 | Borrows full work with handle prefixes pointing to provider objects. State 4 reduces +0x10 by 25 while positive, advances +0x14 up to ten and computes floating progress /10, then activates handles and copies +0x4e8 to state. State 11 waits for slot 7, submits command 32 or a halfword-truncated provider result +24, then enters state 9. States 9/10 increment and clamp byte +0x4ec to 16. State 12 waits before submitting controls 0/2/1/3/10. Every path decrements nonzero byte +0x4fc and signals flag inversion when it expires. |
| `func_020f1128` | 872 | Initializer creates two display handles and two resource handles; scans provider IDs 111..210 into twelve-byte rows at +0x2c, sorts with `Unk0f0eac_Unk_0f1000`, and submits initial control data. Candidate reconstructed the full routine and reached 98.09174%. Halfword provider bitfields were necessary to reproduce shift extraction rather than AND masking; separate loop locals restored the observed register allocation. Remaining differences: stack frame 0x44 versus 0x4c, omitted temporary stores at sp+0/sp+4 and ordering of the final control stores. Candidate omitted from production. |
| `func_020f1914` | 2200 | Instruction analysis: returns unless state is 13; handles input masks 0x200/0x100, two-column navigation with signed remainder-by-two and unsigned row-count comparisons, selected-entry provider updates, matching bits 8..13 of provider halfword +6, and three sort modes. The two mode-change paths use distinct comparator symbols (`func_020f1020` versus `func_020f10a4`); they must not be collapsed without proof. No compiled candidate or match claimed. Remains delinked. |
| `func_020f21b0` | 2636 | Instruction analysis: drawing calls use work fade/progress, a nine-by-two row loop with spacing 13/122, repeated provider predicates, and unsigned fixed-point scrollbar divisions. State 13 draws selection overlays; later state branches use the byte timer. Repeated predicate calls and stack argument lifetimes must be preserved when reconstructing the draw ABI. No compiled candidate or match claimed. Remains delinked. |

### Hard list (M1-T877)

- `func_020f1128`: finish temporary control payload lifetime/stack layout matching;
  best candidate was 98.09174%, deliberately not retained as C.
- `func_020f1914`: reconstruct navigation, provider mutations, and sorting as one
  scratch; no complete candidate yet.
- `func_020f21b0`: reconstruct drawing ABI and state branches as one scratch;
  no complete candidate yet.

A human can prepare each scratch with `tools/decompme.py scratch FUNC --check
--dry-run --write /tmp/FUNC`. These functions remain supplied by the delinked
object; this DS project does not use PS2 `INCLUDE_ASM` stubs.
