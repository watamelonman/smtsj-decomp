# ImageBg

## M1-T202

All eight targets below match the delinked ARM object at 100% in objdiff.
Addresses and field evidence come from `build/delinks/src/ImageBg.o`
(disassembled with `arm-none-eabi-objdump -dr`) and the symbols in
`config/arm9/symbols.txt`. Existing symbol names are retained; unknown lifecycle
operations keep their neutral names.

| Function | Address / bytes | Observed contract and evidence |
| --- | --- | --- |
| `ImageBg_Get_data_02176ca4` | 0x020e5570 / 16 | Returns the first global word, a borrowed work address or zero; a literal load followed by one dereference. Integer address return preserves the existing interface. |
| `ImageBg_IsSet_data_02176ca4` | 0x020e54b8 / 28 | Compares that same word to zero and returns exactly 0 or 1. |
| `ImageBg_Unk_0e56f4` | 0x020e56f4 / 28 | Calls Release, then clears the first global word. Registered as the teardown callback by `func_020e5580` via the callback literal at 0x020e55f8. |
| `ImageBg_Unk_0e5530` | 0x020e5530 / 32 | Calls Release if work is absent; otherwise forwards the work address in r0 to `func_02061424`. Its lifecycle purpose remains unidentified. |
| `ImageBg_Unk_0e5550` | 0x020e5550 / 32 | Stores two opaque words at work offsets +12 and +16 if present. The mode-3 callback path at 0x020e56e4 reads this pair and forwards it to `Unk0e7290_Set_0e7770`; no units are established. |
| `ImageBg_Unk_0e550c` | 0x020e550c / 36 | If work exists, clears mode at +4 and calls `Unk0e7290_Unk_0e7790(0)`. Otherwise does nothing. |
| `ImageBg_Release` | 0x020e5638 / 44 | Checks the second global word; when nonzero, clears it before calling `func_0205bb68` and `Unk0e7290_Unk_0e7734`. Does not clear the first word. Release naming is supported by this paired cleanup and the teardown callback. |
| `ImageBg_IsMode1or2` | 0x020e5484 / 52 | Returns false for absent work; otherwise compares the +4 word with 1 and 2. The callback at 0x020e5664 dispatches on this same mode word. |

The local `ImageBgWork` view describes only the observed 20-byte callback
payload. The unidentified words retain offset names. It introduces no allocation
or ownership transfer. There are no hard-list targets for M1-T202.

## M1-T203

All four targets match the delinked object at 100% in objdiff (`tools/match_gate.py`).

| Function | Address / bytes | Observed contract and evidence |
| --- | --- | --- |
| `ImageBg_Unk_0e54d4` | 0x020e54d4 / 56 | Calls `Unk0e7290_Unk_0e7790(-1)`; unless mode 1 or 2 is active, allocates the buffer, creates the work task, then stores the opaque argument at +0 and mode 1 at +4. Already present from earlier work; verified at 100%. |
| `ImageBg_AllocBuf` | 0x020e55fc / 60 | If the second global word is zero, fills it from `func_0205ba98(0x1e000, 0x800, data_02150bd4, 216)`. The name is supported by the allocator call and the matching free in `ImageBg_Release`. Verified at 100%. |
| `func_020e5580` | 0x020e5580 / 124 | If no work exists, creates it with `func_020611dc(func_020e5664, 0, 0, ImageBg_Unk_0e56f4, 20, 1, 0, 1)` (literal pool at 0x020e55f0..f8); on success stores it in the first global word and calls `func_020e7658(second word, 0)`. Size 20 matches the `ImageBgWork` view. |
| `func_020e5664` | 0x020e5664 / 144 | Task update callback (registered above). Jump table on mode at +4: 0 idle; 1 calls `func_020e7840` (when `Unk02dcfc_GetField70() == 2`) or `Unk0e7290_Unk_0e77f0` with the +0 word, then sets mode 2 on nonzero, else 0; 2 waits for `Unk0e78b8_IsState5`, sets mode 3 and calls `Unk0e7290_Set_0e7770(0, 0)`; 3 calls `Unk0e7290_Set_0e7770(+12, +16)`. Matching needed an explicit `case 0: break;` (inline pop in the table) and separate `return`s per mode-1 outcome (strne/streq). |

The two `func_` names are kept: the purpose of the mode states is not established
beyond the call shapes above. There are no hard-list targets for M1-T203.

## Existing adjacent implementations

`ImageBg_Unk_0e54d4` and `ImageBg_AllocBuf` are already present and also match
at 100%. The former initializes mode 1; the latter populates the second global
word using the original allocator arguments. `func_020e5580` and
`func_020e5664` were matched in M1-T203 (above).
