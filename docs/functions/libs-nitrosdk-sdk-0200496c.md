# sdk_0200496c

Known-source reference: [pret/pokediamond GX_load2d.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load2d.c).
The original accessor calls and copy dispatch agree with the six SDK screen
loaders below. Configured symbols are retained because symbol configuration is
human-owned. No module boundaries change.

| Function | SDK equivalent | Screen-base accessor | objdiff |
| --- | --- | --- | --- |
| `func_0200496c` | `GX_LoadBG0Scr` | `func_0200391c` | 100% |
| `func_020049cc` | `GXS_LoadBG0Scr` | `func_02003950` | 100% |
| `func_02004a2c` | `GX_LoadBG1Scr` | `func_02003970` | 100% |
| `func_02004a8c` | `GXS_LoadBG1Scr` | `func_020039a4` | 100% |
| `func_02004aec` | `GX_LoadBG2Scr` | `func_020039c4` | 100% |
| `func_02004b4c` | `GXS_LoadBG2Scr` | `func_02003a48` | 100% |

Each function copies caller-owned source data to the current screen base plus
its byte offset. Offset and size are bytes; the source and destination must be
valid, two-byte-aligned ranges and size must be even. Callers must configure a
valid screen mapping. The functions neither validate the mapping nor own memory.
With DMA channel `data_0213ce44` other than -1 and size greater than 28 bytes,
they call the 16-bit DMA copy provider `func_02007fb0`; otherwise they call the
16-bit CPU copy provider `func_0200866c`. The inline helper preserves the SDK
copy policy and destination evaluation while keeping the six wrappers readable.

Validation: all six 96-byte functions match at 100% in objdiff. The TU remains
linked from the delink until a human marks it complete.

Hard list: none.
