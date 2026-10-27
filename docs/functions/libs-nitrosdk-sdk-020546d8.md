# sdk_020546d8 (M2-T489)

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
provider; these wrappers allocate nothing and retain no pointers. The opaque
state declaration is private to the TU and introduces no module boundary.

## Hard list

None of the eight requested functions is deferred.
