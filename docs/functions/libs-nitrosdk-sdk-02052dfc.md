# sdk_02052dfc

## func_02052dfc — hard list

- Original: ARM, address `0x02052dfc`, size 108 bytes.
- Status: omitted from C; the existing delink remains authoritative. Best candidate
  scored **99.26%**, so this is not a completed match.
- Contract inferred from instructions: destination is a writable four-element
  row-major signed 20.12 matrix; angle is an int in 0..65535 representing a turn;
  both scale arguments are nonzero signed 20.12 values. It constructs a rotation
  and then scales its rows by `0x1000000 / scale_x` and
  `0x1000000 / scale_y`, with signed integer division.
- Evidence: signed halfword loads from `0x0212629c` at twice `angle >> 4`
  and the following element, calls to `func_02000d78`, two `_s32_div_f`
  calls, then `func_02000d84` with identical source/destination pointers.
- Public-source search: [NitroSDK fx_trig.h](https://github.com/ntrtwl/NitroSDK/blob/main/include/nitro/fx/fx_trig.h)
  confirms the sine/cosine indexing. [NitroSDK fx_mtx22.c](https://github.com/ntrtwl/NitroSDK/blob/main/libraries/fx/src/fx_mtx22.c)
  supplies the corresponding rotation and row-scaling helpers. The related
  [NitroSystem SRT builder](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g2d/src/g2d_SRTControl.c)
  takes a control structure and uses direct scales, so it is not this wrapper.
- Remaining difference: original loads at offsets `0x20` and `0x24` are
  `ldrsh r1, [ip, lr]` and `ldrsh r2, [ip, r4]`; candidate uses
  `[lr, ip]` and `[r4, ip]`. All other instructions agree after relocation.
- Tried pointer and array views, inline sine/cosine accessors, reversed
  indexing, integer address expressions, volatile element reads, and optimizer
  controls. None produced an exact match. No experimental pragmas are retained.
- Infrastructure observation: the sine/cosine table has no configured symbol.
  A human can investigate a proper table symbol/relocation before opening a
  scratch with `tools/decompme.py`; protected configuration was not changed.

### Reproducible candidate for a human scratch

This is analysis material, not a matched production implementation. Compiled
with the configured mwccarm 2.0/sp1p5 flags, it produces the 99.26% result above.

```c
typedef signed int fx32;
typedef signed short fx16;

/** Four signed 20.12 elements, stored row by row for the SDK matrix helpers. */
typedef struct Unk02052dfcMatrix {
    fx32 m00, m01, m10, m11;
} Unk02052dfcMatrix;

#pragma thumb on
extern void func_02000d78(Unk02052dfcMatrix *dst, fx32 sine, fx32 cosine);
#pragma thumb off
extern void func_02000d84(const Unk02052dfcMatrix *src,
                         Unk02052dfcMatrix *dst, fx32 x, fx32 y);

/** Build rotation then reciprocal scale; evidenced by the table loads and
 * calls to rotation (02000d78) and row scaling (02000d84). Angle is a nonnegative
 * 16-bit turn index in an int; scales are nonzero signed 20.12 values.
 * The sine/cosine table is ROM data at 0212629c, without a configured symbol. */
void func_02052dfc(Unk02052dfcMatrix *dst, int angle, fx32 scale_x, fx32 scale_y)
{
    const fx16 *table = (const fx16 *)0x0212629c;
    fx32 inverse_x;
    fx32 inverse_y;
    func_02000d78(dst, table[(angle >> 4) * 2], table[(angle >> 4) * 2 + 1]);
    inverse_x = 0x1000000 / scale_x;
    inverse_y = 0x1000000 / scale_y;
    func_02000d84(dst, dst, inverse_x, inverse_y);
}
```
