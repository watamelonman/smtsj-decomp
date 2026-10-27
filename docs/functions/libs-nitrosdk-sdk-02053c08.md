# sdk_02053c08

Eight matched functions at `0x02053c08-0x02053fd0`: a five-entry touch-sample
record table, the sample shift helper, three touch-state accessors, a rectangle
hit test and an integer-distance check. The delink has no descriptive symbol
names for this wrapper, so the `func_` symbols are retained for linkage; field
roles are documented below because the touch provider's public `TPData` layout
establishes them.

Public-source lookup: the touch-panel calls resolve to the public
[NitroSDK 4.2 `libraries/spi/src/tp.c`](https://github.com/ntrtwl/NitroSDK/blob/ccbbcc8b6db4c4dbba3d503d2026978d78977840/libraries/spi/src/tp.c)
and its
[`tp.h`](https://github.com/ntrtwl/NitroSDK/blob/ccbbcc8b6db4c4dbba3d503d2026978d78977840/include/nitro/spi/ARM9/tp.h):
`func_0200d380` = `TP_Init`, `func_0200d3f8` = `TP_GetUserInfo`,
`func_0200d48c` = `TP_SetCalibrateParam`, `func_0200d5b4` =
`TP_RequestSamplingAsync`, `func_0200d648` = `TP_WaitRawResult`,
`func_0200d884` = `TP_GetCalibratedPoint`. That public source does not contain
this wrapper or its five-record table; no C implementation was copied.

The shared header `include/libs/NitroSDK/sdk_02053c08.h` describes only the
borrowed 14-byte record: `touch`, `previousTouch`, `x`, `y`, `previousX`,
`previousY` and one never-read alignment halfword. The table is owned by the
SDK/game bootstrap; `func_02053c98` returns borrowed entries and no function in
this unit allocates or releases storage.

## func_02053c08

- Original: ARM, address `0x02053c08`, size 144 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: calls the touch initializer, obtains user calibration, returns 0
  when it is unavailable, clears all five 14-byte records and installs the
  calibration. Returns 1 on success.
- Evidence: ordered calls at `0x02053c14`/`0x02053c1c`/`0x02053c84` and the
  five-iteration loop at `0x02053c30..0x02053c7c` that stores fourteen zero
  bytes per iteration.
- Note: the record clear is written as fourteen explicit byte stores because
  mwccarm does not unroll the equivalent byte loop at this optimization level.

## func_02053c98

- Original: ARM, address `0x02053c98`, size 20 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns `&data_021607c4[index]`. The caller must keep the index in
  range; there is no bounds check.
- Evidence: `ldr`, `mov r1, #14`, `mla r0, r1, r0, r2`, so the record stride is
  fourteen bytes.

## func_02053cac

- Original: ARM, address `0x02053cac`, size 140 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: retries `TP_RequestSamplingAsync`/`TP_WaitRawResult` until a sample
  is returned, converts it with `TP_GetCalibratedPoint`, then shifts the first
  record: `previousTouch/previousX/previousY` receive the old `touch/x/y`. A raw
  validity halfword of 0 (the public `TP_VALIDITY_VALID`) publishes the new
  touch flag and calibrated x/y; any other validity clears the current fields.
- Evidence: the request/wait loop at `0x02053cbc..0x02053ccc`, the conversion
  call at `0x02053cd8`, the validity test at `0x02053cdc..0x02053ce8` and the
  halfword stores at `0x02053cf8..0x02053d2c`.

## func_02053d38

- Original: ARM, address `0x02053d38`, size 84 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns 1 while `touch` is nonzero and copies the calibrated `x/y`
  to the two optional outputs. A non-touched record writes zero to both
  nonnull outputs and returns 0.
- Evidence: `ldrh`/`cmp` on `data_021607c4` and the paired conditional stores at
  `0x02053d3c..0x02053d84`.

## func_02053d8c

- Original: ARM, address `0x02053d8c`, size 92 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: the touch-down edge query: same outputs as `func_02053d38`, but it
  succeeds only when `touch == 1` and `previousTouch == 0`.
- Evidence: the conditional `ldrheq`/`cmpeq` pair at `0x02053d90..0x02053d98`
  followed by the same output sequence as `func_02053d38`.

## func_02053de8

- Original: ARM, address `0x02053de8`, size 92 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: the touch-up edge query: succeeds only when `touch == 0` and
  `previousTouch == 1`, reporting the last touched coordinates
  `previousX/previousY`.
- Evidence: the compare pair at `0x02053dec..0x02053df4` and the `+8`/`+10`
  loads at `0x02053df8`/`0x02053e00`.

## func_02053e44

- Original: ARM, address `0x02053e44`, size 292 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: when `draw == 1` and the renderer is ready, submits the rectangle
  `x/y/width/height` through the ordered GX calls. It then selects a touch
  source with `kind` (0 = current touch, 1 = touch-down edge, 2 = touch-up
  edge) and returns 1 only when that point lies in the half-open rectangle;
  otherwise it returns 0. `kind` is contractually 0-2: for any other value the
  original branches to the hit test with caller-saved `r4` untouched and reads
  it as the hit flag, so the result is undefined rather than 0. The C local is
  intentionally left uninitialized to keep that behaviour and the match.
- Evidence: the `draw`/readiness guards at `0x02053e60..0x02053e70`, the GX call
  sequence at `0x02053e74..0x02053ec4`, the `kind` chain at
  `0x02053ec8..0x02053f18` and the bounds tests at `0x02053f24..0x02053f64`.
  Only the call order and argument values of the GX sequence are evidenced; the
  meanings of `0xff000000`, 16, 10, 21 and 31 are not established, so the code
  reproduces them verbatim with a comment listing each call.

## func_02053f68

- Original: ARM, address `0x02053f68`, size 104 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns 1 when a current touch point exists and its integer
  distance from `(x, y)` is at least `distance`; otherwise returns 0.
  `func_020500bc` writes `dx*dx + dy*dy` to the SQRT operand register and
  returns the integer square root, so `distance` is not squared.
- Evidence: the local coordinate pair stores at `0x02053f90..0x02053fac`, the
  `func_020500bc` call at `0x02053fb0` and the `cmp r0, r4` early return at
  `0x02053fb4..0x02053fc0`.

## Validation

All eight functions are defined in C with no inline assembly, byte blobs or
`INCLUDE_ASM`. The standalone helper comparison checks every instruction word
and relocation against the ROM; `tools/match_gate.py` reports 100% for all
eight functions and `tools/checksum.py` confirms the image is unchanged.

## Hard list

None: every function in this translation unit matches.
