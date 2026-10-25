# src/game/unit_020ce578.c

The work area is borrowed. Field offsets and helper-call order below come from
`build/delinks/src/game/unit_020ce578.o`; no gameplay meaning is inferred.
M1-T718 has six functions at 100% objdiff and two deferred functions.

| Function | Contract and evidence |
| --- | --- |
| `Unk0ce578_Nop_0ce5e4` | Empty callback; original is `bx lr`. |
| `Unk0ce578_Unk_0ce5e8` | If the global query is zero, call bc9b4(20, 0), 124258 and 122aa0; then always call de870 and 0956c8 and clear the global word at data_02176bd0+4. No arguments. |
| `Unk0ce578_Unk_0cec98` | Pass the global d3138 query result, zero and the work area's +0x10 handle to 122f88. Requires valid work. |
| `Unk0ce578_SetState` | Write the supplied state to +0; when state is 2, invoke cec98 first. This store and the callers' constant state arguments support the existing descriptive name. |
| `Unk0ce578_Unk_0cf258` | Value 2 returns early when d3138 reports zero. Otherwise call a0da4(5), write 4 to +4, enter state 9, and store the supplied value at +0xc. |
| `Unk0ce578_Unk_0cf29c` | Call 123294 with the +0x10 handle, save the supplied word at +0xd8, write 1 to +4, and enter state 3. |
| `func_020cf4b8` | Original loads +0xdc, compares it to zero, and returns the loaded word. Deferred; see hard list. |
| `func_020cf4c4` | Original loads +0xe0, compares it to zero, and returns the loaded word. Deferred; see hard list. |

## Hard list (M1-T718)

- `func_020cf4b8` (12 bytes): original is `ldr r0,[r0,#0xdc]; cmp r0,#0; bx lr`.
- `func_020cf4c4` (12 bytes): same sequence with offset 0xe0.

Both remain linked from the original delink; no C definitions were retained.
With the configured mwccarm 2.0/sp1p5 and project flags, conditional-return
candidates reached 66.67% objdiff: they retain the compare but also emit
`moveq r0,#0` (16 bytes). Separate probes of ternary, explicit branches,
unsigned words and a volatile load also retain that extra move. A Boolean
return emits two normalization moves (20 bytes), while returning the loaded
value on both branches removes the compare (8 bytes). These agree with the
prior investigation in `docs/hard_functions.md`. A human can use
`tools/decompme.py` for further compiler investigation.

## Not done in M1-T719
- `func_020ce628`
- `func_020cecb8`
- `func_020cf454`
- `func_020ce578`
- `func_020cf2cc`
- `func_020ce7cc`
- `func_020cf360`
- `func_020cf4d0`

## Not done in M1-T720
- `func_020ce684`
- `func_020cefac`
- `func_020ced18`
- `func_020ce868`
