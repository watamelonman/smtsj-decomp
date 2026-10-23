# src/game/unit_02039bb4.c

- `Unk039bb4_Unk_03a9ec`: decompiler-derived
- `Unk039bb4_Unk_03aa10`: decompiler-derived
- `Unk039bb4_Unk_03aa34`: decompiler-derived
- `Unk039bb4_Unk_03aa58`: decompiler-derived
- `Unk039bb4_Unk_03aa7c`: decompiler-derived
- `Unk039bb4_Unk_03aaa0`: decompiler-derived
- `Unk039bb4_Unk_03aac4`: decompiler-derived
- `Unk039bb4_Unk_03a298`: decompiler-derived
- `Unk039bb4_Thunk_0203ab84`: tail-forwards to `func_0203ab84` through `ldr ip; bx ip`. Evidence: instructions at `0x02039d04` and target literal at `0x02039d0c`. No additional work or arguments are introduced.
- `Unk039bb4_Unk_03a1c8`: Increments the signed word at work +0x18 and returns 1. Evidence: ARM instructions at `0x02003a1c8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a2f8`: Increments the signed word at work +0x18 and returns 1. Evidence: ARM instructions at `0x02003a2f8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a7f8`: Calls `func_0203a334(work, 0)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a7f8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a81c`: Calls `func_0203a334(work, 1)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a81c`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a840`: Calls `func_0203a334(work, 2)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a840`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a864`: Calls `func_0203a334(work, 3)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a864`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a9c8`: Calls `func_0203a334(work, 4)`, then increments the signed word at work +0x18 and returns 1. The field is read after the call. Evidence: ARM instructions at `0x02003a9c8`; the wider meaning is unknown, so the name stays neutral.
- `Unk039bb4_Unk_03a30c`: decompiler-derived
- `Unk039bb4_Unk_039d10`: decompiler-derived
- `Unk039bb4_Unk_039d3c`: decompiler-derived
- `Unk039bb4_Unk_039d68`: decompiler-derived
- `Unk039bb4_Unk_039d94`: decompiler-derived
- `Unk039bb4_Unk_03a26c`: decompiler-derived
- `Unk039bb4_Unk_039f1c`: decompiler-derived
- `Unk039bb4_Unk_039ee8`: decompiler-derived
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
