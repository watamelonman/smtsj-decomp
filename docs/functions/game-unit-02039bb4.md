# src/game/unit_02039bb4.c

- `Unk039bb4_Unk_03a9ec`: Calls `func_0203a334(work, 5)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203a9ec`; no wider semantic name is established.
- `Unk039bb4_Unk_03aa10`: Calls `func_0203a334(work, 6)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203aa10`; no wider semantic name is established.
- `Unk039bb4_Unk_03aa34`: Calls `func_0203a334(work, 7)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203aa34`; no wider semantic name is established.
- `Unk039bb4_Unk_03aa58`: Calls `func_0203a334(work, 8)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203aa58`; no wider semantic name is established.
- `Unk039bb4_Unk_03aa7c`: Calls `func_0203a334(work, 9)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203aa7c`; no wider semantic name is established.
- `Unk039bb4_Unk_03aaa0`: Calls `func_0203a334(work, 10)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203aaa0`; no wider semantic name is established.
- `Unk039bb4_Unk_03aac4`: Calls `func_0203a334(work, 11)`, reloads and increments the signed word at +0x18, then returns 1. Work is borrowed. Evidence: ARM instructions at `0x0203aac4`; no wider semantic name is established.
- `Unk039bb4_Unk_03a298`: Reads the unsigned halfword at `work[+0xbc] + work[+0x18] * 4 + 2`, selects a 0x20-byte record from the table at +0xb4, copies its +0x18 word to work +0x18, and returns 1. Both tables are borrowed and indices must be valid. Evidence: ARM instructions at `0x0203a298`; the table purpose remains unknown.
- `Unk039bb4_Thunk_0203ab84`: tail-forwards to `func_0203ab84` through `ldr ip; bx ip`. Evidence: instructions at `0x02039d04` and target literal at `0x02039d0c`. No additional work or arguments are introduced.
- `Unk039bb4_Unk_03a1c8`: Increments the signed word at work +0x18 and returns 1. Evidence: ARM instructions at `0x02003a1c8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a2f8`: Increments the signed word at work +0x18 and returns 1. Evidence: ARM instructions at `0x02003a2f8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a7f8`: Calls `func_0203a334(work, 0)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a7f8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a81c`: Calls `func_0203a334(work, 1)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a81c`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a840`: Calls `func_0203a334(work, 2)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a840`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a864`: Calls `func_0203a334(work, 3)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a864`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a9c8`: Calls `func_0203a334(work, 4)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a9c8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a30c`: Copies the +0x18 word of a 0x20-byte record from the table at work +0xb8 into work +0x18. The unsigned halfword at current entry +2 selects the record. Returns 1; borrowed tables and indices must be valid. Evidence: ARM instructions at `0x02003a30c`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039d10`: Writes tag 0 to work +0x20 indexed by the signed word at +0x1c, writes the supplied word to work +0x3c indexed by the reloaded +0x1c, then increments +0x1c. The work address retains its existing 32-bit ABI; callers must provide valid append space. Evidence: ARM instructions at `0x020039d10`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039d3c`: Writes tag 1 to work +0x20 indexed by the signed word at +0x1c, writes the supplied word to work +0x3c indexed by the reloaded +0x1c, then increments +0x1c. The work address retains its existing 32-bit ABI; callers must provide valid append space. Evidence: ARM instructions at `0x020039d3c`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039d68`: Writes tag 5 to work +0x20 indexed by the signed word at +0x1c, writes the supplied word to work +0x3c indexed by the reloaded +0x1c, then increments +0x1c. The work address retains its existing 32-bit ABI; callers must provide valid append space. Evidence: ARM instructions at `0x020039d68`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039d94`: Writes tag 4 to work +0x20 indexed by the signed word at +0x1c, writes the supplied word to work +0x3c indexed by the reloaded +0x1c, then increments +0x1c. The work address retains its existing 32-bit ABI; callers must provide valid append space. Evidence: ARM instructions at `0x020039d94`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_03a26c`: Returns 0 without changes when work +0x1c is zero. Otherwise calls func_02039dc0 with the work address, writes its result plus one to +0x18, and returns 1. Evidence: ARM instructions at `0x02003a26c`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039f1c`: Appends the current four-byte entry’s unsigned halfword at +2 using the tag-zero helper, reloads and increments work +0x18, and returns 1. Evidence: ARM instructions at `0x020039f1c`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039ee8`: Increments work +0x18 before reading a full word from that entry in the +0xbc table; appends it using the tag-zero helper, reloads and increments +0x18 again, and returns 1. Evidence: ARM instructions at `0x020039ee8`. The wider purpose remains unknown, so the neutral name is retained.
- `Unk039bb4_Unk_039f4c`: decompiler-derived
- `Unk039bb4_Unk_039ff8`: decompiler-derived
- `Unk039bb4_Unk_03a030`: decompiler-derived
- `Unk039bb4_Unk_03a068`: decompiler-derived
- `Unk039bb4_Unk_03a158`: decompiler-derived
- `Unk039bb4_Unk_03a190`: decompiler-derived
- `Unk039bb4_Unk_03a2c0`: decompiler-derived

## Not done in M1-T677
- `Unk039bb4_Unk_039f80`

## Not done in M1-T678
- `Unk039bb4_Unk_039fbc`
- `Unk039bb4_Unk_03a0e0`
- `Unk039bb4_Unk_03a11c`
- `func_0203a0a0`
- `func_0203a944`
- `func_02039dc0`
- `func_0203a1dc`
- `func_02039e50`

## Not done in M1-T679
- `func_02039c60`
- `func_02039bb4`
- `func_0203a888`
- `func_0203a334`
- `Unk039bb4_Unk_039f80`: decompiler-derived (struct cleanup)
- `Unk039bb4_Unk_039fbc`: decompiler-derived (struct cleanup)
- `Unk039bb4_Unk_03a0e0`: decompiler-derived (struct cleanup)
- `Unk039bb4_Unk_03a11c`: decompiler-derived (struct cleanup)

## M1-T674 verification

The eight bodies were already present in the starting tree. This card adds explicit
work-pointer parameters, a two-argument helper declaration, and behavior contracts.
The helper retains its existing 32-bit address ABI for other callers in this unit.
No new module boundary or inferred semantic name is introduced.

Hard list for M1-T674: none.

## M1-T675 verification

The eight bodies already existed in the starting tree. This card makes their
work-pointer contracts explicit and cleans the indexed record lookup without
changing the shared layout or helper ABI. Neutral names retain the evidence
limits. No module boundary changes.

Validation: all eight targets report 100% objdiff; the match gate also passes
for every checked C function. The build, anticheat, nine existing unit tests,
and byte-identical artifact checksum gate pass. No new tests are required by
this card; instruction matching validates the original behavior.

Hard list for M1-T675: none.

## M1-T676 verification

The eight bodies already existed in the starting tree. This card replaces their
raw decompiler expressions with explicit work views, named values, and borrowed
storage contracts. The four append helpers retain their integer-address ABI for
existing callers. No module boundary changes or new semantic names are introduced.
Instruction matching is the behavioral test; this card requires no new tests.

Validation: all eight targets report 100% objdiff; the match gate passes all
76 checked C functions. The full build, anticheat, nine existing unit tests,
and byte-identical artifact checksum gate pass.

Hard list for M1-T676: none.
