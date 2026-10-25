# game/unit_0211f894 — M1-T293

The four C definitions match at 100% in objdiff. Original `func_` symbols
are retained because the application-level purpose is not established.
The unit remains linked from its delinked object until a human marks it complete.

## func_0211f894 — 224 bytes, 100%

Takes a valid caller-owned work pointer. Loads at offsets 0/4/16/20 establish
the partial state/step/resource/alternate layout. States 6 and 7 call the
intensity helper; every state calls `func_0211fa24(resource, 1)`.
State 2 submits bounds with signed height `(8 - step) * 172 / 8`, using
ID 0x5c00 and coordinates 42/90. States 3 and 4 submit the alternate resource
through `func_0205de40` at unit scale. Other states need no additional submission.

## func_0211f974 — 48 bytes, 100%

Takes the same valid work pointer. The comparisons against 6/7 condition only
the call to `func_0211f9a4`; the following resource load and call to
`func_0211fa24(resource, 0)` are unconditional.

## func_0211f9a4 — 128 bytes, 100%

Takes valid work. The multiply, signed division reciprocal 0x2e8ba2e9 and
byte mask establish intensity `((11 - step) * 31) / 11`, narrowed to a byte.
Zero becomes one. Calls `func_02057524(4)`, sets intensity, submits the
256 by 192 region with parameter 22, restores intensity 31, and closes with
`func_02057534`. No unsupported bounds on step are imposed.

## func_0211fa24 — 296 bytes, retained in delink

Typed interface: `void func_0211fa24(u32 resource, s32 direction)`.
Copies two six-word tables from 0x0213cd58 (0 through 5) and 0x0213cd40
(5 through 0). Direction selects the table and corner order. Each strip
computes adjacent grayscale values `25 + 38 * index`, packs the three color
channels with alpha 255, and calls `func_0205dee8` at successive offsets
0, 32, 64, 96, 128 and 160 with unit scale.

### Hard list

- `func_0211fa24`: best candidate scored 99.53% in objdiff. Arithmetic,
  branches, calls, stack size and loop matched; the first 24-byte table copy
  allocated its source/destination to lr/ip rather than ip/lr. Tried local
  array initializers, typed structure copies, explicit source/destination
  pointers, inline copy helpers, and local declaration/initialization orders.
  Color-expression ordering was resolved before stopping. Omitted the C
  definition rather than shipping a partial match. A human can use
  `tools/decompme.py` for a scratch; this DS repository retains the original
  via the delink, without introducing an `INCLUDE_ASM` stub.

## func_0211fb4c — 212 bytes, 100%

Takes submission ID, coordinates, signed bounds, and three forwarded integer
parameters. Rejects nonpositive bottom-minus-top or right-minus-left. The
stack offsets establish a 56-byte packet with four bounds at offsets
36/40/44/48; the remaining words belong to the opaque preparation routine.
Calls `func_02058bf8` with flags 0x20001, then `func_020574d4`. Writes 2/0 to
0x04000440/444, submits the packet using the pointer returned by
`Unk02e000_GetAddr_data_02140ac8`, and writes 1 to 0x04000448. The packet is
borrowed by these calls for the duration of the submission.

## Validation

`ninja`, `python3 tools/match_gate.py`, `python3 tools/anticheat.py`,
`python3 -m unittest discover -s tests -t . -q` (9 tests), and
`python3 tools/checksum.py` pass. No new tests: the card explicitly sets
`tests_required = false`; instruction matching checks the recovered bodies.
