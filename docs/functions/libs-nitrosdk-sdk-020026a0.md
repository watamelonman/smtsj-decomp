# libs/NitroSDK/sdk_020026a0.c

NitroSDK 4.2 GX display helpers. The original source is public: the bodies match
`GX.c` and `GX_state.c` in pret/pokediamond
(`arm9/lib/NitroSDK/src/`), adjusted only for the delinked symbol names in this
ROM. The project has no `gx.h` yet, so the register addresses and masks are
spelled as literals and the state view lives in
`include/libs/NitroSDK/sdk_020026a0.h`.

All eight targets are at 100% in objdiff and the full-image checksum still
matches. Evidence for each entry is the original ARM instruction stream plus the
corresponding pokediamond function.

- `func_020026a0` (`0x020026a0`, 4 B): empty entry (`bx lr`). No evidence ties it
  to a named SDK function, so the neutral name stays.
- `func_020027f0` (`0x020027f0`, 52 B): `GX_VBlankIntr`. Sets or clears DISPSTAT
  bit 3 (V-blank IRQ enable) at `0x04000004` and returns the bit's value sampled
  before the update.
- `func_02002824` (`0x02002824`, 60 B): `GX_DispOff`. Reads DISPCNT, stores zero
  to `sIsDispOn` (`data_0213ce40`), saves the two-bit BG mode to `sDispMode`
  (`data_021521a0`), then clears DISPCNT bits 16-17.
- `func_02002860` (`0x02002860`, 72 B): `GX_DispOn`. Sets `sIsDispOn`, then
  restores the saved BG mode or, when the saved mode is zero, enables graphics
  mode 1 (DISPCNT bit 16).
- `func_02002910` (`0x02002910`, 28 B): `GXS_SetGraphicsMode`. Replaces the low
  three BG-mode bits of DISPCNT_SUB at `0x04001000`.
- `func_0200292c` (`0x0200292c`, 40 B): `GXx_SetMasterBrightness_`. Encodes a
  brightness: zero clears the word, positive values use `(1 << 14) | value`,
  negative values use `(2 << 14) | -value`.
- `func_02002954` (`0x02002954`, 68 B): inverse of the brightness encoding.
  Bits 14-15 select off/positive/negative and the low five bits hold the
  magnitude; the encoding with only bit 15 set is negated, 0xC000 reads as 0.
  No pokediamond source names this getter, so the neutral name stays.
- `func_02002998` (`0x02002998`, 96 B): `GX_InitGXState`. Clears the thirteen
  halfword fields of `gGXState` (`data_021521a4`) and the VRAM bank control
  registers at `0x04000240` (VRAMCNT A-D, E, F, G and VRAM_HI_CNT at +8).

## Hard list

The translation unit also contains two functions outside this card. They stay
linked from the delinked object, so no partial C bodies are present:

- `func_020026a4` (`0x020026a4`, 332 B): `GX_Init`. It sets POWCNT1, calls
  `GX_InitGXState`, acquires a VRAM lock ID through `OS_GetLockID`, clears
  DISPSTAT/DISPCNT, fills the 2D register block (0x60 bytes) and the sub-engine
  block (0x70 bytes) either by DMA or by CPU, then sets the BG2/BG3 affine
  entries to identity.
- `func_020028a8` (`0x020028a8`, 104 B): `GX_SetGraphicsMode`. It saves the
  display mode, handles the display-off case, and rebuilds DISPCNT from the BG
  mode, 2D/3D selection and the saved mode bits.
