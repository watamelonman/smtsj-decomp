# sdk_02058370

All seven implemented functions match the original ARM instructions. Names remain
neutral because the exact middleware wrapper identities are not established.
No tests were added: this card uses instruction matching and ROM checksum gates.

Public-source search checked NitroSDK and the SDK initialization example in
[TwlIPL main.c](https://git.randommeaninglesscharacters.com/rvtr/TwlIPL/blame/commit/14cffdac9ab1ee6266ab26838c87263cf0da2cf9/build/gcdfirm/gcdfirm-disp/ARM9/main.c).
The latter corroborates the LCDC VRAM clear, OAM fill with 192, and palette clear
sequence, but is not an exact source for this wrapper TU. Neighboring reconstructed
GX bank getters establish the texture and texture-palette mask roles.

| Function | Result and evidence |
| --- | --- |
| `func_02058370` | Matched, 60 bytes. Calls all thirteen neighboring SDK bank release helpers. |
| `func_020583ac` | Matched, 116 bytes. Selects all LCDC banks, clears 0xa4000 VRAM bytes, releases LCDC, fills main/sub OAM with 192 and clears their palettes. |
| `func_02058420` | Matched, 56 bytes. Sums capacities for selected masks across nine eight-byte records at 0x0212e350. |
| `func_02058458` | Matched, 124 bytes. Counts assigned texture banks A-D using a 16-bit counter, adds texture-palette E/F/G capacities of 64/16/16 KiB and calls 020584d4. |
| `func_020584d4` | Matched, 84 bytes. Calls 020222d8, sets GXSTAT bits 30-31 to 2, sets singleton byte +20, and calls 0202990c(count) and 02029c00(paletteBytes, 1). |
| `func_02058528` | Matched, 32 bytes. Stores 02051610's returned handle at caller-owned work +0x2058 and returns one. |
| `func_02058548` | Matched, 96 bytes. Returns zero for an absent handle; otherwise finalizes work +0x205c/+0x2084, calls two resource helpers, clears the handle and returns one. |

The header exposes only borrowed work storage and observed member offsets. The
resource provider determines handle ownership; this unit pairs acquisition with
its observed release calls. State-block extents beyond accessed starting addresses
are intentionally unspecified.

## Compiler details

See DEC-032. Locally disabling propagation preserves the absolute descriptor
address and explicit geometry initialization temporaries. The descending
nine-record do/while loop reproduces the original initial count subtraction
without an extra entry test. The table address has no relocation or configured
symbol, so it remains a typed absolute data pointer.

## Hard list

None. All seven functions have C definitions with identical instructions.
