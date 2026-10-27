# MSL unit 0201703c

## func_0201703c — 16-bit string length

`unsigned int func_0201703c(const unsigned short *text)` counts code units
before the first zero halfword. The caller owns the readable, terminated input;
there is no allocation. Halfword postincrement loads, a counter starting at -1,
and the zero test establish `wcslen` semantics. Original symbol retained.
The 28-byte C implementation matches the original.

## func_02017058 — inverse cosine (not retained)

The observed ABI is `double func_02017058(double value)`, returning radians.
The constants, special cases and three range-reduction branches identify the
fdlibm/MSL `acos` implementation. Source search first checked pret/pokeplatinum
and pret/pokediamond; the attempted MSL source paths were unavailable.
The comparison used the public Sun fdlibm implementation preserved in
[OpenLibm e_acos.c](https://github.com/JuliaMath/openlibm/blob/master/src/e_acos.c).

Adaptations were little-endian double word access, the existing square-root
provider `func_0201d8c4`, and the target's float NaN at `data_0213cf94` instead
of generating NaN by division. This produced the target's 2040-byte instruction
layout and constants, but runtime call relocations differ: 32 compiled `_dadd`
calls target `func_0201cff0` in the original; seven compiled `_dsub` calls target
the symbol currently named `_dadd` (0201da78). Multiplication, division,
square-root and float-conversion calls agree. Explicitly calling the observed
providers was also tried: it produced 2032 bytes with different register
allocation, so that implementation was discarded.

The original remains in the delinked object. A human should investigate the
runtime symbol identities before attempting to link the ordinary C version;
no protected configuration was changed.

## Hard list

- `func_02017058`: investigate addition/subtraction runtime symbol mapping, then
  retry the fdlibm source or open a decomp.me scratch with `tools/decompme.py`.

## Validation

No new tests are required by this card. Instruction/relocation comparison and
the project match, checksum, anticheat and unittest gates validate the retained
function; `acos` remains deferred.
