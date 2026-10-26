# sdk_02052dfc

## func_02052dfc

- Original: ARM, address `0x02052dfc`, size 108 bytes.
- Status: **100% objdiff match**, with readable C and typed parameters.
- Contract: destination is a writable four-element row-major signed 20.12
  matrix; angle is an int in 0..65535 representing a turn; both scale
  arguments are nonzero signed 20.12 values. Constructs a rotation, then
  scales its rows by `0x1000000 / scale_x` and `0x1000000 / scale_y`,
  using signed integer division.
- Evidence: signed halfword loads from the interleaved table at `0x0212629c`
  using twice `angle >> 4` and the following element; a call to
  `func_02000d78`, two `_s32_div_f` calls, and `func_02000d84` with identical
  source/destination pointers.
- Public-source lookup: [NitroSDK fx_trig.h](https://github.com/ntrtwl/NitroSDK/blob/main/include/nitro/fx/fx_trig.h)
  declares `FX_SinCosTable_` and supplies identical sine/cosine indexing.
  [NitroSDK fx_mtx22.c](https://github.com/ntrtwl/NitroSDK/blob/main/libraries/fx/src/fx_mtx22.c)
  supplies the corresponding rotation and row-scaling helpers. No exact
  public source for this wrapper was identified; its linker name is retained.
- Matching detail: the previous absolute-address pointer caused the compiler
  to reverse the base/index operands of two halfword loads (99.26%). Using
  the SDK's external array declaration emits the original operand order.
- Integration requirement: protected `config/arm9/symbols.txt` does not name
  the table. A human must bind `FX_SinCosTable_` to `0x0212629c` before marking
  this TU complete. The declaration references existing ROM data and does
  not define a replacement table. The current delink remains linked, as
  required by the task card; objdiff normalizes the table relocation.

## Hard list

None; the function's instructions match. The table symbol integration above
remains human-owned.
