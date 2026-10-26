# NitroSDK VRAM allocation helpers (M2-T095, M2-T096)

## Evidence and contracts

Reference lookup started with [pret/pokediamond GX_vramcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_vramcnt.c).
Its bank setters and the neighboring original setters identify the allocation
roles. The original instructions independently establish each offset below:
load the state address `0x021521a4`, load an unsigned halfword at the specified
offset, and return. The C uses a private borrowed prefix view of that state.
No module boundary changes or new public types are introduced.

Every function takes `void` and returns a zero-extended bank mask in `u32`;
bits 0-8 denote banks A-I. They neither allocate nor modify state, and report
SDK bookkeeping rather than reading hardware registers. Existing linker names
are retained because the split and symbols are human-owned.

## Functions

| Function | SDK allocation role | State offset | Original size |
| --- | --- | --- | --- |
| `func_0200387c` | `GX_GetBankForBG` shape | `+0x02` | 16 bytes |
| `func_0200388c` | `GX_GetBankForOBJ` shape | `+0x04` | 16 bytes |
| `func_0200389c` | `GX_GetBankForBGExtPltt` shape | `+0x0e` | 16 bytes |
| `func_020038ac` | `GX_GetBankForOBJExtPltt` shape | `+0x10` | 16 bytes |
| `func_020038bc` | `GX_GetBankForTex` shape | `+0x08` | 16 bytes |
| `func_020038cc` | `GX_GetBankForTexPltt` shape | `+0x0a` | 16 bytes |
| `func_020038dc` | `GX_GetBankForSubBG` shape | `+0x12` | 16 bytes |
| `func_020038ec` | `GX_GetBankForSubOBJ` shape | `+0x14` | 16 bytes |

## Validation

The objdiff match gate checks the eight C definitions directly against the
delinked originals. The checksum gate checks the linked original image; this
unit remains linked from its delink until a human marks it complete.
No new runtime tests are required by the card: exact object comparison is the
behavioral oracle for these single-load getters.

Local results: all eight requested functions report 100% objdiff; anticheat
passes; all nine unit tests pass; checksum reports every artifact byte-identical
to the original. An initial overlapping build failed during ROM configuration;
the subsequent sequential checksum run passed.

## Hard list

None of the eight requested functions is left out. Other functions in the
translation unit remain outside this card's scope.

## M2-T096: disable wrappers and remaining palette getters

Reference: [pret/pokediamond GX_vramcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_vramcnt.c),
`disableBankForX_`, the six corresponding `GX_DisableBankFor*` wrappers,
and `GX_GetBankForSubBGExtPltt` / `GX_GetBankForSubOBJExtPltt`.
Original ARM instructions independently establish the slot addresses and getter
offsets below. Existing linker names are retained.

All eight functions take `void` and return a `u32` bank mask (bits 0-8 are
banks A-I). Disable wrappers tail-call `func_02003650` with a borrowed SDK
allocation slot: that helper clears the slot, disables the selected VRAM bank
registers, releases their SDK VRAM lock, and returns the previous mask.
The two getters read bookkeeping only and do not modify allocation or hardware.
The private state view is extended through offset 0x18; no public boundary changes.
Individual external slots preserve the original wrapper address relocations.

| Function | SDK role | Slot address / state offset | Size |
| --- | --- | --- | --- |
| `func_020037a0` | `GX_DisableBankForTex` | `0x021521ac` | 20 bytes |
| `func_020037b4` | `GX_DisableBankForTexPltt` | `0x021521ae` | 20 bytes |
| `func_020037c8` | `GX_DisableBankForClearImage` | `0x021521b0` | 20 bytes |
| `func_020037dc` | `GX_DisableBankForARM7` | `0x021521aa` | 20 bytes |
| `func_020037f0` | `GX_DisableBankForLCDC` | `0x021521a4` | 20 bytes |
| `func_02003804` | `GX_DisableBankForSubBG` | `0x021521b6` | 20 bytes |
| `func_020038fc` | `GX_GetBankForSubBGExtPltt` | `+0x16` | 16 bytes |
| `func_0200390c` | `GX_GetBankForSubOBJExtPltt` | `+0x18` | 16 bytes |

The card requires no new tests: exact objdiff comparison verifies these thin
wrappers and getters against the original instructions. The unit continues to
link from the delinked original pending human completion of the split config.

Local validation for M2-T096: all eight requested functions report 100% objdiff;
the build, anticheat, all nine unit tests, and byte-identical artifact checksum
checks pass.

Hard list for M2-T096: none.

## M2-T097: remaining disable wrappers and BG screen addresses

Known source was checked before implementation:
[pret/pokediamond GX_vramcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_vramcnt.c)
provides the four corresponding disable wrappers, and
[pret/pokediamond GX_bgcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_bgcnt.c)
provides the three screen-pointer getters. Original instructions independently
confirm register addresses, masks, allocation slots, and operation order.
Existing linker names are retained; no module boundary changes are introduced.

All seven functions take `void`. Disable wrappers return a `u32` previous bank
mask (bits 0-8 for A-I), clear the relevant extended palette enable bit when
applicable, and call `func_02003650` to clear bookkeeping, disable banks, and
release their SDK lock. The getters return borrowed `void *` addresses without
allocating or transferring ownership. They read volatile hardware registers;
BG screen blocks are 2 KiB and the main display has an additional shared screen
base in 64 KiB units. They do not validate whether the selected banks are mapped.

| Function | Known SDK role | Original evidence | Size |
| --- | --- | --- | --- |
| `func_0200377c` | `GX_DisableBankForOBJExtPltt` | Main DISPCNT bit 31; slot `0x021521b4` | 36 bytes |
| `func_02003818` | `GX_DisableBankForSubOBJ` | Slot `0x021521b8` | 20 bytes |
| `func_0200382c` | `GX_DisableBankForSubBGExtPltt` | Sub DISPCNT bit 30; slot `0x021521ba` | 40 bytes |
| `func_02003854` | `GX_DisableBankForSubOBJExtPltt` | Sub DISPCNT bit 31; slot `0x021521bc` | 40 bytes |
| `func_0200391c` | `G2_GetBG0ScrPtr` | BG0CNT `0x04000008`, mask `0x1f00`; DISPCNT mask `0x38000000` | 52 bytes |
| `func_02003950` | `G2S_GetBG0ScrPtr` | Sub BG0CNT `0x04001008`, mask `0x1f00`; base `0x06200000` | 32 bytes |
| `func_02003970` | `G2_GetBG1ScrPtr` | BG1CNT `0x0400000a`, mask `0x1f00`; DISPCNT mask `0x38000000` | 52 bytes |

No runtime tests are required by this card: object comparison verifies the
register operations and instruction order against the delinked originals.
The unit remains linked from its delink pending human completion.

Hard list for M2-T097: none.

Local validation for M2-T097: all seven requested functions and all sixteen
previous definitions report 100% objdiff. The build, anticheat, all nine unit
tests, and byte-identical artifact checksum checks pass. `git diff --check`
also passes.
