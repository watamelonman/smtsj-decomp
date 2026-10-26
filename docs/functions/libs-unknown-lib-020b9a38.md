# libs/unknown/lib_020b9a38 — M2-T032, M2-T033

## Evidence and source search

A public-source search for NitroSDK / pret script-command implementations found
no matching source. Despite the library split label, these routines call the
same script operand/result helpers used by the game handlers in
`src/game/unit_0203c05c.c` and `src/game/unit_0203e23c.c`.
No SDK identity or request-specific meaning is established, so the original
neutral linker symbols are retained.

The original ARM instructions read operands 0 and 1 via `func_0203ac00`,
pass them unmodified to `func_020b8b38` with a constant code and zero fourth
argument, publish its result through `Unk03aae8_Unk_03acf4`, and return 1.
`func_020b9b18` is the one wider handler in the TU: it reads operands 0, 1 and 2
and forwards all three as the request payload.
Disassembly of 020b8b38 establishes four word stores at work offsets
0x20–0x2c and a boolean result; 0203acf4 clears context byte 0x3b and writes
that result at context offset 0xa8. Parameters and results use full 32-bit words.
Handlers take no explicit arguments and operate on the current runtime context.

## Functions

- `func_020b9a38(void)`: submit request code 71 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9a38` (56 bytes).
- `func_020b9a70(void)`: submit request code 72 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9a70` (56 bytes).
- `func_020b9aa8(void)`: submit request code 73 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9aa8` (56 bytes).
- `func_020b9ae0(void)`: submit request code 74 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9ae0` (56 bytes).
- `func_020b9b18(void)`: submit request code 75 with operands 0/1/2; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9b18` (68 bytes), which loads all three operands through `func_0203ac00` and passes them as the three payload words to `func_020b8b38`.
- `func_020b9b5c(void)`: submit request code 76 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9b5c` (56 bytes).
- `func_020b9b94(void)`: submit request code 77 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9b94` (56 bytes).
- `func_020b9bcc(void)`: submit request code 78 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9bcc` (56 bytes).
- `func_020b9c04(void)`: submit request code 79 with operands 0/1 and zero; publish its boolean result, then return completion status 1. Evidence: original ARM at `0x020b9c04` (56 bytes).

## Verification

The original object is the executable oracle; no new behavior tests are required
by this card. All nine definitions in the TU reached 100% in the objdiff match gate.
The full build, all nine unit tests, anticheat and checksum gates passed locally;
checksum reported all artifacts byte-identical to the original. The TU remains
linked from its delinked object pending the human completion flag.

## Hard list

None for this card. All nine functions in the TU now have matching C definitions.
