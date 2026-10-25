# game/unit_020469d8

Names remain neutral because the ARM9 instructions establish mechanics but not
higher-level gameplay intent. All pointers are borrowed for the duration of a call.
The unit remains linked from its original delinked object pending human completion.

## `Unk0469d8_Unk_0469d8` — 40 bytes, 100%

Fetch the current context, call `func_02049594`, and, when
`Unk044904_Unk_0459ec` is nonzero, fetch it again for `func_02049620`.
Return runner result 2. Evidence: calls and branch at 020469dc..020469f8.
The context getter's return value is an argument to each setup call.

## `Unk0469d8_Unk_046a00` — 44 bytes, 100%

Run `func_020496d0` on the current context, call `Unk09d060_Unk_09d1b0`,
and write 2 through the borrowed state pointer when `Unk09d42c_Unk_09d4bc`
returns zero. Always return 2. Evidence: 02046a08..02046a24, including STRH.

## `func_02046a2c` — 136 bytes, 100%

Poll a four-phase process selected by the signed halfword at state +6.
Phase 0 calls the initial probe and advances, then falls through to phase 1's
update/readiness pair. Readiness initializes the next subsystem and advances.
Phase 2 calls its setup and advances, then falls through to phase 3's
update/readiness pair; nonzero readiness returns 1. Otherwise return 0.
Evidence: jump table and signed halfword accesses at 02046a34..02046aac.
Out-of-range phases do nothing and return zero.

## `func_020472e0` — 88 bytes, 100%

Fetch queue entries from the current context. Empty means success (1).
An entry whose unsigned +4 threshold exceeds `Unk09d060_GetCtxUnk00`
returns 0 without dispatching or removing it. Otherwise dispatch with the
borrowed runner state, remove the entry, and continue while dispatch returns
nonzero. A zero dispatch result ends the loop and returns 1.
Evidence: unsigned comparison at 02047300..0204730c and pop at 02047324.

## `func_02046ab4` — 2092 bytes, deferred

Evidence: 02046ab4..020472dc resolves identifiers at record +8/+12, checks
source visibility, applies kind-specific null guards, then dispatches kinds
0..28. Kind 3 contains an effect switch over the low four bits at +20,
with a mode nibble and sound flag in that same word. Several effects pass a
pair of halfwords by value. Kind 6 builds a 68-byte message with two flag
bytes and sixteen word slots. Kind 11 writes runner state 2; kinds 8/9
can write runner +2 and return zero. Most paths return 1.

### Hard list

- `func_02046ab4`: reconstructed both switches and all call sites in a scratch
  C candidate; objdiff reached **96.96%**, with 2060 emitted bytes versus 2092.
  Tried raw-word versus typed bitfield views, signed/unsigned pair members,
  local declaration scopes, explicit versus aggregate pair initialization,
  and an inline message-slot setter. Bitfields fixed the original shift
  sequences and repeated loads. Outstanding differences include the effect
  boolean's r2/r3 allocation, pair-copy scratch register, and two extra stack
  temporaries at sp+4/sp+8 in the original message construction. Original frame
  is 84 bytes versus the candidate's 76. The queue consumer also scores
  99.77% when this nonmatching local body changes its branch displacement.
  No nonmatching definition is retained. Use `tools/decompme.py` with platform
  `nds_arm9` for further compiler/inline-helper investigation; keep this function
  linked from the delinked original.
