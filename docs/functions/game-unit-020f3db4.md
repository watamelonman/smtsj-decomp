# src/game/unit_020f3db4.c

## M1-T503: eight matched helpers

Evidence: ARM disassembly of `build/delinks/src/game/unit_020f3db4.o`,
with symbol addresses from `config/arm9/symbols.txt`. All eight match at 100%.
Names remain neutral because the packed states and subsystem meanings are unknown.

- `Unk0f3db4_Unk_0f44a8` (8 B): returns `arg0 & 3`; the AND immediate establishes the two-bit mask.
- `Unk0f3db4_Unk_0f3dc8` (16 B): tail-forwards index 8 to `Unk044394_Unk_044428`, ignoring its result.
- `Unk0f3db4_Unk_0f3dd8` (16 B): tail-forwards index 8 to `Unk044394_Unk_044534`, ignoring its result.
- `Unk0f3db4_Unk_0f4528` (16 B): tests bit 2 and returns exactly zero or one, as shown by TST and conditional MOVs.
- `Unk0f3db4_Unk_0f4550` (16 B): reads a byte, sets bit 2, and writes it back; requires writable storage.
- `Unk0f3db4_Unk_0f3db4` (20 B): calls `Unk02e000_Unk_02e774` and adds 0x52 then 0x5e00, returning a borrowed work address in the existing integer-address convention.
- `Unk0f3db4_Unk_0f44d0` (20 B): retains only the old byte's bit 2, ORs the unmasked byte argument, and stores the result. Requires writable storage; callers normally supply a two-bit state.
- `Unk0f3db4_Unk_0f4490` (24 B): passes the table selector to `Unk0f3db4_Unk_0f3ec8`, loads the byte at the supplied offset, and calls the low-bit extractor. The caller must supply a valid selector and offset. The selector is now explicit instead of relying on an unprototyped call leaving r0 intact.

Hard list for M1-T503: none. Existing functions belonging to other cards are retained.

- `Unk0f3db4_Unk_0f4510`: decompiler-derived

## Not done in M1-T504
- `Unk0f3db4_Unk_0f4538`
- `Unk0f3db4_IsName`
- `Unk0f3db4_Unk_0f44b0`
- `Unk0f3db4_Unk_0f44e4`
- `Unk0f3db4_Unk_0f4398`
- `Unk0f3db4_Unk_0f4448`
- `func_020f4070`

## Not done in M1-T506
- `func_020f3fcc`
- `func_020f45c0`
- `func_020f4180`
- `Unk0f3db4_Unk_0f3e6c`: decompiler-derived
- `Unk0f3db4_Unk_0f3ec8`: decompiler-derived
- `Unk0f3db4_Unk_0f4674`: decompiler-derived

## Not done in M1-T505
- `func_020f4560`
- `func_020f43d4`
- `func_020f3de8`
- `func_020f40c8`
- `func_020f3f2c`
- `Unk0f3db4_Unk_0f4538`: decompiler-derived (plain+fix cleanup)
- `Unk0f3db4_Unk_0f44b0`: hand-matched
- `Unk0f3db4_Unk_0f44e4`: hand-matched
- `Unk0f3db4_IsName`: hand-matched
- `Unk0f3db4_Unk_0f4398`: hand-matched
- `Unk0f3db4_Unk_0f4448`: hand-matched
