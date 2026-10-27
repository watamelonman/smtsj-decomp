# sdk_020546d8 (M2-T489 / M2-T490)

This partial TU uses the original symbol names. Public-source discovery searched
NitroSDK/pret graphics code; no matching implementation of these wrappers was
located. Reconstruction follows the original ARM instructions, rather than an
assumed SDK API identity. Other functions remain supplied by the delink.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_02054818` | Updates sub BG3 control (0x0400100e): preserves mask 0x43, sets 0x80, merges size <<14, screen base <<8 and wrap <<13. |
| `func_02054840` | Same field update at sub BG2 control (0x0400100c). |
| `func_02054868` | Same field update at main BG3 control (0x040000e). |
| `func_02054890` | Same field update at main BG2 control (0x040000c). |
| `func_020548b8` | Updates sub BG3 control with fixed bits 0x84 instead of 0x80. |
| `func_02054a80` | Obtains state slot zero through 0205410c and resets it to mode one through 02054120. |
| `func_02054ad8` | Calls 02054af0 with the supplied index and defaults 0, 0, 8. |
| `func_02054af0` | Forwards index and the second word, clears the next two words, and passes the byte flag and halfword value to 02054a98. That provider stores them at slot +17 and +18. |

Graphics field inputs must already fit their hardware fields; the original does
not mask arguments before shifting. State storage belongs to the existing
provider; these wrappers allocate nothing and retain no pointers. The partial 40-byte state layout is private to the TU and introduces no module boundary.

## M2-T490

Public-source lookup found the graphics expressions in
[NitroSDK gx_bgcnt.h](https://github.com/ntrtwl/NitroSDK/blob/master/include/nitro/gx/gx_bgcnt.h).
The state helpers remain neutrally named: their contracts follow original loads,
stores and calls, without claiming a public SDK identity.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020546d8` | Main BG2 extended affine character control, equivalent to G2_SetBG2Control256x16Affine: preserves 0x43, merges size <<14, character base <<2, screen base <<8, wrap <<13. |
| `func_020548e0` | Sub BG2 direct-color bitmap control (0x0400100c): preserves 0x43, sets 0x84, merges size <<14, screen base <<8, wrap <<13. |
| `func_02054908` | Same direct-color bitmap update for main BG3 (0x0400000e). |
| `func_02054930` | Same direct-color bitmap update for main BG2 (0x0400000c). |
| `func_02054a98` | Gets the borrowed 40-byte indexed slot, resets mode to 2, stores arguments a/c/b at +4/+8/+12, byte flag at +17, halfword value at +18. |
| `func_02054ba4` | Comparator takes pointers to valid slot indices; returns 1 for left mode <=1, -1 for right mode <=1, then 1 for left flag, -1 for right flag, otherwise right value minus left value. Both excluded gives 1, following the original order. |
| `func_02054c0c` | Comparator takes pointers to valid slot indices; same mode exclusions, otherwise calls 020557cc on right then left and subtracts left result from right result (32-bit wrap). |
| `func_02054a08` | Deferred size helper: nonzero second argument selects 0xc000; otherwise mode 8 uses byte dimensions +8/+9 product plus 64, mode 5 indexes words at 0x0212e230, mode 2 indexes words at 0x0212e240, other modes use zero. Format word +12 equal to zero halves the result. |

The bitmap fixed bits and field meanings are supported by the public header;
all register arguments are unshifted SDK encodings and must fit their fields.
The private state view exposes only instruction-established fields and retains
provider ownership. No allocation or new module boundary is introduced.

## Hard list

- `func_02054a08`: switch ordering, multiplication, format test and size arithmetic
  reconstructed exactly. Using external array declarations produces matching
  instructions, but neither table has a symbol in the protected symbol map;
  those declarations would leave unresolved references when C is linked.
  Fixed-address indexing instead emits address additions and produces 128 bytes
  versus 120. Tried signed indices, volatile table loads, pointer/array forms,
  and disabling propagation, strength reduction and common subexpressions;
  none restored literal loads. Left supplied by the delink. A human can use
  `tools/decompme.py` to investigate the address materialization or define the
  table symbols in the protected configuration.
