# NitroSDK BG uploads (`sdk_02004bac`)

Source evidence: [pret/pokediamond GX_load2d.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load2d.c).
The six wrappers follow that source's getter/copy sequence. Original getter
instructions independently establish the engine and BG index: screen getters
read BG3 control at register offset 0x0e, character getters read BG0/BG1 control
at 0x08/0x0a. Main-engine getters account for DISPCNT VRAM offsets; sub-engine
getters use 0x06200000. Original linker symbols are retained.

All arguments are caller-owned source bytes, destination byte offset, and byte
count. Screen copies require two-byte alignment; character copies require
four-byte alignment. Callers must supply valid configured VRAM destinations
and make DMA source data coherent before uploading. DMA channel 0xffffffff
selects CPU copying. These routines do not allocate or transfer ownership.

| Function | SDK identity and behavior | DMA threshold |
| --- | --- | --- |
| `func_02004bac` | `GX_LoadBG3Scr`: upload main BG3 screen data via `func_02003abc`. | size > 28 bytes |
| `func_02004c0c` | `GXS_LoadBG3Scr`: upload sub BG3 screen data via `func_02003b40`. | size > 28 bytes |
| `func_02004c6c` | `GX_LoadBG0Char`: upload main BG0 character data via `func_02003bb4`. | size > 48 bytes |
| `func_02004ccc` | `GXS_LoadBG0Char`: upload sub BG0 character data via `func_02003be8`. | size > 48 bytes |
| `func_02004d2c` | `GX_LoadBG1Char`: upload main BG1 character data via `func_02003c08`. | size > 48 bytes |
| `func_02004d8c` | `GXS_LoadBG1Char`: upload sub BG1 character data via `func_02003c3c`. | size > 48 bytes |

The public SDK source supplies the wrapper structure; the exact small-transfer
thresholds and copy providers come from the original instructions. Each wrapper
is 96 bytes. Objdiff comparison against the original is the behavioral and
instruction-level acceptance check; the card requires no new unit tests.

Validation: all six functions report 100% in objdiff. The match gate, checksum
gate (all artifacts byte-identical), anticheat gate, and all nine repository
unit tests pass. The TU remains linked from the delink pending human completion.

Hard list: none.
