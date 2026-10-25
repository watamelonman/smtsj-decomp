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

## M1-T719

Seven functions below match at 100% in the objdiff report. Provider names remain
external; the neutral `func_` symbols are retained because the instructions do
not establish gameplay names. The work area is 0xe4 bytes, with counted
26-byte records at +0x14 and item handles at +0x88.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020ce578` | No arguments. Query 02f0e8, store global mode at +4, conditionally call 02f0c4, then initialize providers. A zero de8b0 result enables the final three calls with bc928(20, 65535, 0). |
| `func_020ce628` | Fill a borrowed callback descriptor with size 0xe4, zero flags, and six function pointers at +0xc through +0x20. The reserved word at +8 is not written. |
| `func_020ce7cc` | Unless saved value +0xd8 equals 15, release counted non-null items, clear their slots, and release/reset the +0x10 handle and providers. Always call bc9b4(10, 0), dea60, and clear the global owner. |
| `func_020cecb8` | Pass the supplied word and phase address +8 to cb5b4. Results 1, 2, 3 respectively invoke cf2cc, cf360 followed by cec98, or SetState with +4. Deferred; see hard list below. |
| `func_020cf2cc` | Release counted non-null items, reset their slots and +0x10 handle, tear down providers in observed call order, then clear +0xdc and +0xe0. |
| `func_020cf360` | Recreate providers and items using 26-byte records. First record ID 604 adjusts both index and count by minus one. Configure the handle using the stored +0xd0 count, then set +0xdc and +0xe0 to one. |
| `func_020cf454` | Convert the low 16 bits of +0xa8 into provider mode 0..4; selection zero uses d3138 to choose 0 or 5. The switch and 124224 call establish the mapping. |
| `func_020cf4d0` | Requires a valid message. Kind 1 calls bc504(work, 0). Kind 3 requires state 5 and decodes payload word +0x10 only when flag bit 3 is set. Selection 100 deactivates counted items and enters state 2; other selections save +0xd4, pass record +0x20+26*index to dec94 and enter state 7. Other kinds do nothing. |

## Hard list (M1-T719)

- `func_020cecb8` (96 bytes): a typed switch implementation compiled to the
  same 24 instructions and relocation targets. `objdiff-cli diff` reported
  100%, but `objdiff-cli report generate` consistently reported 99.791664%,
  including single-threaded deduplicated reporting. Moving the definition
  before SetState did not change that result. The candidate was removed to
  respect the strict report gate; the original delink remains authoritative.
  A human can investigate with `tools/decompme.py` and the report/diff discrepancy.

## Not done in M1-T720
- `func_020ce684`
- `func_020cefac`
- `func_020ced18`
- `func_020ce868`
