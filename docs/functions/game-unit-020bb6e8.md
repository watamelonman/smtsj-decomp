# src/game/unit_020bb6e8.c

All eight functions in this translation unit (`0x020bb6e8`-`0x020bb908`) are matched
at 100% in objdiff. The names in `config/arm9/symbols.txt` are retained: the calls and
data accesses establish each operation, but do not establish domain-level meanings.
Arguments are signed words unless the code narrows them explicitly, and every handler
returns status 1 through `r0`.

- `Unk0bb6e8_GetFlag282b1` (60 bytes): reads script argument 0, resolves the record
  through `Unk0bac80_Thunk_02044ec4`, and tests bit 1 of the byte at `+0x282`
  (`ldrb [r0,#642]; lsl #30; lsr #31`). Reports 1 or 0 through
  `Unk03aae8_Unk_03acf4`.
- `Unk0bb6e8_SetFlag282b1` (76 bytes): reads arguments 0 and 1, resolves the record,
  and stores argument 1 != 0 into bit 1 of `+0x282` (`bic #2` then `orr` with the
  shifted flag).
- `Unk0bb6e8_Unk_0bb770` (60 bytes): truncates argument 0 to 16 bits (`lsl #16;
  lsr #16`), queries `Unk02e000_GetRecordFlag0`, and reports its non-zero result.
- `Unk0bb6e8_Unk_0bb7ac` (56 bytes): converts argument 1 to 0/1, truncates argument 0
  to 16 bits, and forwards both to `Unk02e000_SetRecordFlag1f`.
- `func_020bb7e4` (156 bytes): loads the shared work object through
  `Unk0bac80_Unk_0badc0`, clears the five low flag bits at `+0x44` (bits 0, 1, 2 and
  the 2-bit field at bits 3..4), then reads script arguments 0, 1 and 2. Argument
  0 == 1 stores value 1 into the 2-bit field; argument 1 == 2 sets bit 1; argument
  1 == 3 sets bit 2; argument 2 == 5 sets bit 0.
- `Unk0bb6e8_Unk_0bb880` (32 bytes): loads the work object and reports the 8-bit field
  at bits 5..12 of the `+0x44` word (`lsl #19; lsr #24`).
- `Unk0bb6e8_Unk_0bb8a0` (32 bytes): reads argument 0; when it is below 15, calls
  `Unk0e5fb8_Unk_0e628c` with that argument.
- `Unk0bb6e8_Unk_0bb8c0` (72 bytes): reads argument 0; when it is below 15, calls
  `Unk0e5fb8_Unk_0e6254` with that argument and reports its non-zero result, otherwise
  reports 0.

## Hard list

None.
