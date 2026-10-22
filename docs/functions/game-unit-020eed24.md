# src/game/unit_020eed24.c

All six functions match the original ARM code. Neutral names are retained because
call sequences and offsets alone do not establish the subsystem's purpose.
Layouts in the C file describe only fields observed in these functions.

- `Unk0eed24_Thunk_020f7248` (12 bytes): forwards to `func_020f7248`;
  evidence is the original branch relocation. No arguments are consumed here.
- `Unk0eed24_Unk_0eeebc` (24 bytes): passes 1 to `func_020d1e94`
  and `Unk0fd9f0_Unk_0fda58`, in that order.
- `Unk0eed24_Unk_0eee94` (40 bytes): passes 0 to
  `Unk0feba0_Unk_0febe8`, obtains index 10 through `func_020ea630`,
  forwards that result with -1, then selects value 3 in the final call.
- `func_020eeed4` (88 bytes): writes descriptor values 24 and 4,
  five callback addresses, and a zero field. Callback identities are evidenced by
  literal-pool relocations; slot 0x08 is untouched. The callback prototypes describe
  stored addresses only; this function does not invoke them.
- `func_020eed24` (92 bytes): requires both external checks to succeed,
  then forwards the handles at work offsets 0x40 and 0x04 to three operations
  and passes 6 to the final operation. The second check uses mask 0xc03.
- `func_020eed80` (264 bytes): returns immediately for work state 1.
  Otherwise brackets two array traversals with external calls. The fourth argument
  to each entry operation is 100, reduced by ten times a positive difference
  between work fields 0x1c and 0x10. The first traversal skips null entries and
  supplies x = field 0x10 + 39 + 64 * index, y = 102. The second supplies
  x = field 0x10 + a signed halfword from `func_02049c58`, y = 30.
  Array counts are queried again on each loop iteration, as in the original.

## Hard list

None.
