# src/game/unit_020c855c.c

## M1-T930

Names remain neutral because the instructions establish field operations, not
higher-level game semantics. Evidence addresses below refer to the original ARM
instructions in `build/delinks/src/game/unit_020c855c.o` (loaded at 0x020c855c).
All seven retained card functions report 100% objdiff.

- `Unk0c855c_Unk_0ca690`: returns the input byte pointer plus 0x6180.
  Evidence: 020ca690 adds 0x2180 then 0x4000. The caller owns the region.
- `Unk0c855c_Unk_0c92dc`: reads the unsigned halfword at offset 0x3a,
  then returns that index from the word table `data_0213c51c`.
  Evidence: 020c92dc–020c92e4. The index must be valid for the table.
- `Unk0c855c_Unk_0ca58c`: clears words at offsets 0, 0x14, 0x18 and
  0x1c; leaves intervening words intact. Evidence: 020ca58c–020ca59c.
  The input must cover at least eight writable words.
- `Unk0c855c_Unk_0c92c0`: dispatches `data_0213c54c[index]` to
  `Unk0ca69c_Unk_0ca6a4`, using the unsigned halfword at offset 0x3a.
  Evidence: 020c92c0–020c92d0, including the indirect tail call.
- `Unk0c855c_Unk_0c9b90`: selects a record using stride 0x60 and forwards
  the supplied value to `func_020c98ec` with a third argument of zero.
  Evidence: 020c9b90–020c9ba4. The integer first parameter represents the
  original 32-bit record-array address; callers must supply a valid index.
- `Unk0c855c_Unk_0c9d8c`: scans four records at stride 0x60; sets word
  0x1c to one where word 0x30 is nonzero. Evidence: 020c9d8c–020c9db0.
  The byte pointer must cover all four records; other fields are preserved.
- `Unk0c855c_Unk_0c9bac`: returns zero upon finding any zero word at
  offset 0x30 in four records, otherwise one. Evidence: 020c9bac–020c9bd4.
  The byte pointer must cover four records at stride 0x60.

### Hard list

- `func_020c9eb0` (48 bytes): left in the delinked original. It creates a
  handle through `CampStatus_Unk_0d353c`, stores it in record[index]+0x5c,
  and passes that field to `func_020616c0`. Scalar temporaries, a volatile
  temporary, single-word aggregate copies, typed 0x60-byte records, explicit
  byte offsets and register locals were tried. Best objdiff was 76.17%:
  aggregate copies reproduce the stack store, but mwcc retains the index
  across the call and emits an MLA afterward. The original multiplies into
  r4 before the call, saves the base in r5, then adds them afterward.
  No mismatching C body is retained. A human can use `tools/decompme.py`
  for a scratch focused on this allocation/order difference.

## M1-T931

All eight requested functions report 100% objdiff. Existing matching bodies
were retained and documented; three missing bodies were added. No new hard
functions remain for this card. Names stay neutral where instruction evidence
does not establish a higher-level purpose.

- `Unk0c855c_InitCallbacks` (020ca550–020ca588): initializes a nine-word
  descriptor with size 32 and callbacks `func_020ca2e4` and `func_020c9ee0`;
  preserves word 2. Evidence: stores and the two pointer relocations.
- `Unk0c855c_Unk_0ca648` (020ca648–020ca68c): calls `func_0205bb68`
  once for selectors 0/1, twelve times for 2, and never otherwise.
  Evidence: three-way branch and counted loop.
- `Unk0c855c_Unk_0c9890` (020c9890–020c98e8): obtains three values
  from `func_02057fd8` after the reset call, forwarding them and the input
  value to `func_020c92f0` for indices 0..3. The caller owns the work area.
- `Unk0c855c_Unk_0c9c5c` (020c9c5c–020c9cb8): scans four 0x60-byte
  records, dispatches value 2 for state 3 at offset 4, then value 3 for
  a nonnegative selected index. That index must be valid for the array.
- `Unk0c855c_Unk_0c855c` (020c855c–020c85c4): latches nonzero
  `func_020537b8` results for masks 0x40/0x80/0x20/0x10 into words
  0x1a8/0x1ac/0x1b0/0x1b4 of borrowed writable work.
- `func_020c9bd8` (020c9bd8–020c9c58): dispatches value 2 to state-2
  records and retains the last result. For a nonnegative selected index,
  a nonzero result becomes the mode passed directly to `func_020c98ec`;
  otherwise the wrapper dispatches value 1 with mode zero. Evidence:
  r2 is assigned the wrapper result and survives the loop exit. The wrapper
  now exposes its forwarded return value without changing its instructions.
- `func_020c9234` (020c9234–020c92bc): adds signed velocity at 0x19c
  to position at 0x198, clamps at the supplied bounds, and zeroes velocity
  upon reaching a bound. It updates four records and conditionally calls
  `func_020c8a24` when word 0x1a0 is nonzero. Work must cover these fields.
- `func_020ca5a4` (020ca5a4–020ca644): resets the provider then calls
  `Unk05b82c_Unk_05b82c` with ID 195 for selector 0, ID 196 for 1,
  or IDs 197..208 for 2. Other selectors only perform the reset.
  Evidence: immediate ID arguments and explicit branch arms.

## Not done in M1-T932
- `func_020c9cbc`
- `func_020c8a24`
- `func_020c9db4`
- `func_020c8f08`
- `func_020c8b18`
- `func_020c9030`
- `func_020c8ce0`
- `func_020ca2e4`
- `Unk0c855c_Unk_0c92c0`: decompiler-derived (struct cleanup)
- `Unk0c855c_Unk_0c92dc`: decompiler-derived (struct cleanup)
