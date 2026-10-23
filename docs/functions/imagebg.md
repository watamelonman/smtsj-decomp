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

## Existing adjacent implementations

`ImageBg_Unk_0e54d4` and `ImageBg_AllocBuf` are already present and also match
at 100%. The former initializes mode 1; the latter populates the second global
word using the original allocator arguments. `func_020e5580` and
`func_020e5664` remain supplied by the delink and are outside this card.
