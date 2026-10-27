# CRI unit 02086b70

The eight small entry points in this card live in the translation unit that spans
0x02086b70..0x02087268. A search of the repository and of the public CRI/ADX
sources used by the earlier CRI cards (format decoders such as libadx and
CriCodecs) found no matching middleware implementation. The functions are
therefore reconstructed from their delinked ARM instructions. The unit stays
linked from the delink until a human marks it `complete` in
`config/arm9/delinks.txt`; the remaining functions of the unit belong to
follow-up cards.

The private views in `libs/CRI/cri_02086b70.c` expose only fields established by
these instructions: the two halfwords at +0x1c/+0x1e of the object passed to the
paired accessors, the global word at `data_02175a04`, and the +0xc slot of the
library record at `data_02175a08`. All storage remains owned by the caller or by
the CRI library globals.

## Evidence and interpretation

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_02086b70` | Null check then `ldrhne r0,[r0,#28]; lsrne r0,r0,#1` returns half of the unsigned halfword at +0x1c. Callers 020849dc and 02084ff4 pass the word from their own +0x20 slot. The `(u32)` cast is required because C promotes the `u16` field to signed `int` before shifting. | 100% |
| `func_02086b84` | Same shape as 02086b70 using the halfword at +0x1e; called from 020849f8. | 100% |
| `func_02086c28` | `ldr r1,=data_02175a04; str r0,[r1]` stores the incoming word in the shared library global. | 100% |
| `func_02086c38` | `ldr r2,=data_02175a04; mov r0,#30; ldr r2,[r2]; str r2,[r1]` copies the library word through the second argument and returns 30. The only caller, 02087550, sets r0 to zero before the tail call, so the first parameter is unused by this implementation. | 100% |
| `func_02086e18` | Single interworking tail call (`ldr ip,=func_02086c28; bx ip`) forwarding the incoming word to the setter above. | 100% |
| `func_02086e24` | `ldr r1,=data_02175a08; str r0,[r1,#12]` stores the incoming word in the library record's +0xc slot. The slot is read back by 02086f34. | 100% |
| `func_02086e34` | Single interworking tail call forwarding the incoming word to `func_0208995c`, which stores it in its own global. | 100% |
| `func_02086e40` | Single interworking tail call forwarding the incoming word to `func_0208996c`, which stores it in its own global. | 100% |

No string, caller or data-use evidence identifies the CRI API names, so the
linker-visible symbols keep their neutral names. The two accessors return a
derived rate/size value, but its unit is not established.

## Validation

The build and objdiff match gate report 100% for all eight functions above. The
checksum gate reports all artifacts byte-identical to the original. Anticheat
passes and the existing unit tests pass. No new behavioral tests are required by
this card: exact instruction matching verifies each implementation.

## Hard list

None.
