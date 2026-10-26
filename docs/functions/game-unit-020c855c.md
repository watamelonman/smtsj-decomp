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

## Other existing functions

- `Unk0c855c_Unk_0c9890`: decompiler-derived
- `Unk0c855c_Unk_0c9c5c`: decompiler-derived
- `Unk0c855c_Unk_0c855c`: decompiler-derived

## Not done in M1-T931
- `Unk0c855c_InitCallbacks`
- `Unk0c855c_Unk_0ca648`
- `func_020c9bd8`
- `func_020c9234`
- `func_020ca5a4`

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
- `Unk0c855c_InitCallbacks`: hand-matched
- `Unk0c855c_Unk_0ca648`: hand-matched
