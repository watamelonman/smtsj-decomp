# ImageBgDual3D

## M1-T535

- `ImageBgDual3D_Nop_1252f4` (`0x021252f4`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_1252f8` (`0x021252f8`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_1252fc` (`0x021252fc`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_125c3c` (`0x02125c3c`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_125c60` (`0x02125c60`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_125c64` (`0x02125c64`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Thunk_021255b4` (`0x021257e8`, 12 bytes): `LDR IP` / `BX IP` through an absolute relocation to `func_021255b4`. No arguments or return value are used by its caller at `0x02125934`.
- `ImageBgDual3D_Thunk_021177e0` (`0x021259ac`, 12 bytes): the same forwarding sequence, relocated to `Unk116598_Set` (`0x021177e0`); preserves its two opaque 32-bit arguments and void return contract.

The existing symbol names describe only behavior directly established by these instructions.
Matching is checked against the delinked object; this TU remains linked from the delink pending human completion.

## M1-T536

All eight functions match at 100% against the original ARM object.

- `ImageBgDual3D_Thunk_02117808` (`0x021259b8`, 12 bytes): absolute `LDR IP / BX IP` forwarding to `Unk116598_Reset`; no arguments or result.
- `ImageBgDual3D_Get_data_02176e94` (`0x021259f8`, 16 bytes): returns the global word unchanged. The caller at `0x021259e0` uses it as a non-null borrowed work address.
- `ImageBgDual3D_Unk_125a80` (`0x02125a80`, 16 bytes): calls `Unk095560_Unk_096130` then `Unk065e88_Unk_065eac`, both without arguments or consumed results. Their purpose remains unspecified.
- `ImageBgDual3D_Clear_data_02176e8c` (`0x02125300`, 20 bytes): stores zero in the named global word; its meaning is not inferred.
- `ImageBgDual3D_Call_02117360` (`0x02125984`, 20 bytes): forwards four words and an unsigned byte to `func_02117360`; the stack argument is explicitly loaded with `LDRB` and stored as a word for the call.
- `ImageBgDual3D_Call_02117400` (`0x02125998`, 20 bytes): the same argument contract, forwarding to `func_02117400`.
- `ImageBgDual3D_Unk_125afc` (`0x02125afc`, 20 bytes): calls `Unk116598_Unk_1177cc(0)` then `Unk116598_Unk_1172dc()`. The work argument supplied by `0x02125a90` is unused.
- `ImageBgDual3D_Unk_1259e0` (`0x021259e0`, 24 bytes): calls the global getter, writes one to the first work word, then calls `ImageBgDual3D_Unk_125a80`. No null check occurs in the original.

No hard functions remain in this card. Existing descriptive names reflect only observed loads, stores, or call destinations; neutral names retain unknown semantics.

## Other tasks

- `ImageBgDual3D_Unk_125a68`: decompiler-derived
- `ImageBgDual3D_Unk_125ca4`: decompiler-derived
- `ImageBgDual3D_Unk_125cbc`: decompiler-derived
- `ImageBgDual3D_Unk_125d30`: decompiler-derived
- `ImageBgDual3D_Unk_1259c4`: decompiler-derived
- `ImageBgDual3D_Unk_125c40`: decompiler-derived
- `ImageBgDual3D_Unk_125d10`: decompiler-derived
- `ImageBgDual3D_Unk_125650`: decompiler-derived
- `ImageBgDual3D_Unk_125618`: decompiler-derived
- `ImageBgDual3D_Unk_125cd4`: decompiler-derived
- `ImageBgDual3D_Unk_125d48`: decompiler-derived
- `ImageBgDual3D_Unk_1252b4`: decompiler-derived

## Not done in M1-T538
- `ImageBgDual3D_Unk_1258e8`
- `ImageBgDual3D_Unk_12594c`
- `ImageBgDual3D_Unk_125910`
- `ImageBgDual3D_AllocBuf`
- `ImageBgDual3D_Unk_125b10`: decompiler-derived

## Not done in M1-T539
- `ImageBgDual3D_Unk_1258a0`
- `func_02125738`
- `func_02125790`
- `func_02125a08`
- `func_021255b4`
- `ImageBgDual3D_Unk_125a90`
- `func_021257f4`

## Not done in M1-T540
- `func_02125314`
- `func_02125678`
- `func_02125b60`
- `func_021253c4`
- `ImageBgDual3D_Unk_1258a0`: decompiler-derived (plain cleanup)
- `ImageBgDual3D_Unk_12594c`: decompiler-derived (plain cleanup)
- `ImageBgDual3D_Unk_1258e8`: decompiler-derived (plain cleanup)
- `ImageBgDual3D_Unk_125a90`: hand-matched
- `ImageBgDual3D_Unk_125910`: hand-matched
- `ImageBgDual3D_AllocBuf`: hand-matched
