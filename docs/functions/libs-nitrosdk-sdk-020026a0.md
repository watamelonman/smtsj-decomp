# libs/NitroSDK/sdk_020026a0.c

NitroSDK 4.2 GX display helpers. The original source is public: the bodies match
`GX.c` and `GX_state.c` in pret/pokediamond
(`arm9/lib/NitroSDK/src/`), adjusted only for the delinked symbol names in this
ROM. The project has no `gx.h` yet, so the register addresses and masks are
spelled as literals and the state view lives in
`include/libs/NitroSDK/sdk_020026a0.h`.

All ten targets are at 100% in objdiff and the full-image checksum still
matches. Evidence for each entry is the original ARM instruction stream plus the
corresponding pokediamond function.

- `func_020026a0` (`0x020026a0`, 4 B): empty entry (`bx lr`). No evidence ties it
  to a named SDK function, so the neutral name stays.
- `func_020026a4` (`0x020026a4`, 332 B): `GX_Init`. Sets POWCNT1's DSEL, the
  `E2DGB|E2DG|RE|GE` init mask and LCD bits, calls `GX_InitGXState`
  (`func_02002998`), acquires a VRAM lock through `OS_GetLockID`
  (`func_02005d6c`), terminating with `OS_Terminate` (`func_02007e94`) on the
  `-3` error code, clears DISPSTAT/DISPCNT, fills the 0x60-byte 2D block and
  the 0x70-byte sub-engine block with `MI_DmaFill32` (`func_02007ec0`) or, when
  GXi_DmaId is `-1`, `MIi_CpuClear32` (`func_020086a0`), then writes 0x100 to
  the four BG2/BG3 affine entries of both engines. The gGXState data layout,
  `GXi_VRamLockId` at `data_021521a0+2` and `GXi_DmaId` at
  `data_0213ce40+4` come from the delinked relocation targets.
- `func_020027f0` (`0x020027f0`, 52 B): `GX_VBlankIntr`. Sets or clears DISPSTAT
  bit 3 (V-blank IRQ enable) at `0x04000004` and returns the bit's value sampled
  before the update.
- `func_02002824` (`0x02002824`, 60 B): `GX_DispOff`. Reads DISPCNT, stores zero
  to `sIsDispOn` (`data_0213ce40`), saves the two-bit BG mode to `sDispMode`
  (`data_021521a0`), then clears DISPCNT bits 16-17.
- `func_02002860` (`0x02002860`, 72 B): `GX_DispOn`. Sets `sIsDispOn`, then
  restores the saved BG mode or, when the saved mode is zero, enables graphics
  mode 1 (DISPCNT bit 16).
- `func_020028a8` (`0x020028a8`, 104 B): `GX_SetGraphicsMode`. Saves the display
  mode, suppresses it while the display is off, rebuilds DISPCNT from the BG
  mode, the saved mode and the BG0 2D/3D bit (`control & 0xfff0fff0`), and turns
  `sIsDispOn` off again when the saved mode is zero.
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

All ten targets in the translation unit are at 100% in objdiff.

## Hard list

None; every function in this unit now has a matching C body.
