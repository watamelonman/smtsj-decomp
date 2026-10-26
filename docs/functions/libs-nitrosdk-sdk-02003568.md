# libs/NitroSDK/sdk_02003568 — M2-T060 / M2-T061

Known source checked before implementation: [pret/pokediamond GX_vramcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_vramcnt.c).
The reset/disable wrappers have the same operations and order as that reconstruction.
Original symbol names are retained to resolve the delinked calls without modifying
human-owned symbol configuration. All eleven wrappers take no parameters and return
a `u32` containing the previous VRAM bank mask. The shared helpers take a `u16 *`
to the allocation slot and clear that slot.

| Function | Known-source counterpart | Original evidence / contract |
| --- | --- | --- |
| `func_02003568` | `GX_ResetBankForBGExtPltt` | Clear DISPCNT bit 30, then reset slot `data_021521b2` to LCDC. |
| `func_0200358c` | `GX_ResetBankForOBJExtPltt` | Clear DISPCNT bit 31, then reset slot `data_021521b4` to LCDC. |
| `func_020035b0` | `GX_ResetBankForTex` | Reset slot `data_021521ac` to LCDC. |
| `func_020035c4` | `GX_ResetBankForTexPltt` | Reset slot `data_021521ae` to LCDC. |
| `func_020035d8` | `GX_ResetBankForSubBG` | Reset slot `data_021521b6` to LCDC. |
| `func_020035ec` | `GX_ResetBankForSubOBJ` | Reset slot `data_021521b8` to LCDC. |
| `func_02003730` | `GX_DisableBankForBG` | Disable banks in slot `data_021521a6`. |
| `func_02003600` | `GX_ResetBankForSubBGExtPltt` | Clear sub DISPCNT bit 30, then reset slot `data_021521ba` to LCDC. |
| `func_02003628` | `GX_ResetBankForSubOBJExtPltt` | Clear sub DISPCNT bit 31, then reset slot `data_021521bc` to LCDC. |
| `func_02003650` | `disableBankForX_` | Takes a borrowed `u16 *` allocation slot; clears it, disables selected banks A-I, releases their lock via `func_02007d3c(mask, data_021521a2)`, and returns the previous mask as `u32`. |
| `func_02003758` | `GX_DisableBankForBGExtPltt` | Clear main DISPCNT bit 30, then disable slot `data_021521b2`. |
| `func_02003744` | `GX_DisableBankForOBJ` | Disable banks in slot `data_021521a8`. |

Reset wrappers tail-call `func_02003534`, which clears the allocation slot,
adds its banks to the LCDC mask, applies that mapping, and returns the old mask.
Disable wrappers tail-call `func_02003650`, which clears the allocation slot,
turns off the selected VRAM bank control registers, releases the bank lock,
and returns the old mask. Slots are external symbols rather than a reconstructed
global structure, preserving the original relocation targets.

## Validation

- `python3 tools/match_gate.py`: all twelve functions are 100% in objdiff; build passed.
- `python3 tools/checksum.py`: all artifacts byte-identical to the original.
- `python3 tools/anticheat.py`: passed.
- `python3 -m unittest discover -s tests -t . -q`: nine tests passed.

No new tests were required by this card; the original instruction streams and
objdiff provide the acceptance oracle. The TU remains linked from the delink,
as required until a human marks it complete.

## Hard list

None. All twelve functions in this TU are implemented and match.
