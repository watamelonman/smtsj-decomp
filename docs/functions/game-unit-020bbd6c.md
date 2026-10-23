# game/unit_020bbd6c — M1-T135

All eight targets match at 100% with the configured ARM compiler. Evidence below
comes from the delinked original's calls, field offsets, and instruction widths;
semantic names for unknown fields and functions remain neutral. These handlers
have no explicit parameters; their inputs come from the command argument getter
and shared work accessor. Return values are the original handler status codes.

- `func_020bbd6c` (100 bytes): selects table 3 through
  `Unk0bac80_Unk_0badd0`, obtains its count and halfword data, adds command
  argument 0 to `func_02050074(0, count - 1)`, clamps the signed index to
  `[0, count - 1]`, and publishes the selected halfword. Returns 1. The
  original requires a positive table count; no extra fallback is introduced.
- `Unk0bbd6c_Unk_0bbdd0` (32 bytes): obtains shared work and stores argument 0
  as a 32-bit value at +0x48. Returns 3.
- `Unk0bbd6c_Unk_0bbdf0` (32 bytes): obtains shared work and stores the low
  16 bits of argument 0 at +0x64. Returns 3.
- `Unk0bbd6c_Unk_0bbe10` (32 bytes): forwards argument 0 to
  `func_020fdaa8` with selector 1. Returns 1.
- `Unk0bbd6c_Unk_0bbe30` (32 bytes): forwards argument 0 to
  `func_020fdaa8` with selector 2. Returns 1.
- `func_020bbe50` (112 bytes): resolves the work +0x40 key with
  `func_02044ec4`, initializes a pair of halfwords to zero, and lets
  `func_02049c28` fill the pair. Passes the pair by value to `func_020b1f48`
  with second argument zero and third argument indicating whether key bits
  16..23 equal 1. Returns 1. The pair layout preserves the original halfword
  loads/stores and aggregate argument copy.
- `Unk0bbd6c_Unk_0bbec0` (20 bytes): publishes zero through
  `Unk03aae8_Unk_03acf4` and returns 1.
- `func_020bbed4` (112 bytes, M1-T136): takes argument 0 modulo 65536 and
  searches the same twelve 0x2e0-byte records as `func_020bbf44`. For the
  first kind-1 record whose +0x1d8 halfword matches, calls `func_0204a9ec` on
  it and publishes 1 if that returns nonzero, else 0; a miss publishes 0
  through `Unk03aae8_Unk_03acf4`. Returns 1.
- `func_020bbf44` (96 bytes): takes argument 0 modulo 65536, then searches
  twelve records at global accessor result +0x36c, stride 0x2e0. For the
  first record whose key bits 16..23 equal 1 and whose +0x1d8 halfword
  matches the argument, copies its key to shared work +0x4c. If none match,
  leaves that field untouched. Returns 1.

## Hard list

None. `func_020bbed4` (M1-T136) also matches at 100%, so all nine functions
in this TU are written in C.
