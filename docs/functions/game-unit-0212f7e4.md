# src/game/unit_0212f7e4.c

No functions matched; the TU stays linked from the delink.

- `func_0212f7e4` (4 B): tail-call thunk to `func_021301f0`, a single `b func_021301f0`
  (`0xea000281`). Shape-certain name: `Unk212f7e4_Thunk_021301f0`.

## Hard list
- `func_0212f7e4`: not matchable with the project cflags. `void func_0212f7e4(void) { func_021301f0(); }`
  compiles to `ldr ip, =func_021301f0; bx ip` (12 B) because config/toolchain.toml builds with
  `-interworking`, and the callee is in another TU (unit_0212fa68). The toolchain comment counts
  71 `ldr ip/bx ip` tail calls in game code and 1 plain `b`; this is that one. The original was
  probably built without interworking for this call, or with the callee in the same file. The split
  is also odd: 0x0212f7e8..0x0212fa68 (0x280 B) after the thunk is data (halfwords like `0xffff8067`),
  not code. Possible fixes (human-only): a per-TU cflags override without `-interworking`, or
  re-splitting so the thunk shares a TU with `func_021301f0`. A decomp.me scratch won't help unless
  the flags change.
