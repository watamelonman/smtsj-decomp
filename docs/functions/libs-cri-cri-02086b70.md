# CRI unit 02086b70

The entry points in this card live in the translation unit that spans
0x02086b70..0x02087268. A search of the repository and of the public CRI/ADX
sources used by the earlier CRI cards (format decoders such as libadx and
CriCodecs) found no matching middleware implementation. The functions are
therefore reconstructed from their delinked ARM instructions. The unit stays
linked from the delink until a human marks it `complete` in
`config/arm9/delinks.txt`; the remaining functions of the unit belong to
follow-up cards. M2-T431 matched the first eight registry/accessor helpers;
M2-T432 adds the eight volume, pan, refcount and player-lifetime helpers.

The private views in `libs/CRI/cri_02086b70.c` expose only fields established by
these instructions: the two halfwords at +0x1c/+0x1e of the object passed to the
paired accessors, the global word at `data_02175a04`, the +0x4/+0xc/+0x10 slots
of the library record at `data_02175a08`, and the player record whose +0x20/+0x22
halfwords, +0x34 embedded stream, +0x1b0/+0x1b4 handles and 0xa2c-byte extent are
shown by the code. All storage remains owned by the caller or by the CRI library
globals.

## Evidence and interpretation

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_02086b70` | Null check then `ldrhne r0,[r0,#28]; lsrne r0,r0,#1` returns half of the unsigned halfword at +0x1c. Callers 020849dc and 02084ff4 pass the word from their own +0x20 slot. The `(u32)` cast is required because C promotes the `u16` field to signed `int` before shifting. | 100% |
| `func_02086b84` | Same shape as 02086b70 using the halfword at +0x1e; called from 020849f8. | 100% |
| `func_02086b98` | `strh r1,[r0,#0x22]` then `func_0202aba0(r0+0x34, r1)` and `func_0202ac0c(r0+0x34, 0, 0)`; returns r1 unchanged. The two callees are the Nitro stream master-volume and per-channel-volume helpers documented in `libs/unknown/lib_0202a890.c`, which establishes that +0x34 holds an embedded stream. | 100% |
| `func_02086bc8` | Maps a signed -15..15 pan to the halfword at +0x20 and to `func_0202ac60(r0+0x34, 0, pan)`. Zero maps to 64, -15 to 0 and 15 to 127; the interior is `(pan+15)*128/30`, visible as the signed `/30` magic (0x88888889, shift 4) with sign fixup. | 100% |
| `func_02086c28` | `ldr r1,=data_02175a04; str r0,[r1]` stores the incoming word in the shared library global. | 100% |
| `func_02086c38` | `ldr r2,=data_02175a04; mov r0,#30; ldr r2,[r2]; str r2,[r1]` copies the library word through the second argument and returns 30. The only caller, 02087550, sets r0 to zero before the tail call, so the first parameter is unused by this implementation. | 100% |
| `func_02086c50` | `ldr r1,=data_02175a08; ldr r2,[r1,#4]; add r2,#1; str r2,[r1,#4]` bumps the library counter and returns zero in r0. | 100% |
| `func_02086dc4` | When the library counter at +0x4 is zero it first calls 02086c50 (which initialises it), then dispatches `func_02086c6c(&data_02147614, 6, arg0, arg1, arg2)` with the third word passed on the stack, and returns zero. | 100% |
| `func_02086e18` | Single interworking tail call (`ldr ip,=func_02086c28; bx ip`) forwarding the incoming word to the setter above. | 100% |
| `func_02086e24` | `ldr r1,=data_02175a08; str r0,[r1,#12]` stores the incoming word in the library record's +0xc slot. The slot is read back by 02086f34. | 100% |
| `func_02086e34` | Single interworking tail call forwarding the incoming word to `func_0208995c`, which stores it in its own global. | 100% |
| `func_02086e40` | Single interworking tail call forwarding the incoming word to `func_0208996c`, which stores it in its own global. | 100% |
| `func_02086e4c` | Loads the +0x10 counter, calls 0208997c when it is zero and then increments it: a provider-initialise-then-take-reference sequence. | 100% |
| `func_02086e7c` | Pre-decrements the +0x10 counter and calls 02089a2c when it reaches zero (`subs`/`popne` in the original): the matching release. | 100% |
| `func_02086f60` | Saves the +0x1b4 handle in r0, clears the slot, calls 02089a8c with the saved handle, then clears the whole 0xa2c-byte player with `func_020119c0(player, 0, 0xa2c)`. | 100% |
| `func_02087054` | Calls 02086f98 (player reinitialise, still delinked) and stores the incoming word in the +0x1b0 slot. | 100% |

No string, caller or data-use evidence identifies the CRI API names, so the
linker-visible symbols keep their neutral names. The two accessors return a
derived rate/size value, but its unit is not established. The pan mapping's
extremes are pinned by the literal constants in the branch arms, and the
interior divisor 30 is read off the signed-division magic.

## Validation

The build and objdiff match gate report 100% for all sixteen functions above. The
checksum gate reports all artifacts byte-identical to the original. Anticheat
passes and the existing unit tests pass. No new behavioral tests are required by
this card: exact instruction matching verifies each implementation.

## Hard list

None.
