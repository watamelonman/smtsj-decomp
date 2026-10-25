# src/game/unit_020f7188.c

## M1-T621: verified matches

All eight functions below score 100% in objdiff with the configured ARM compiler.
Names and contracts come from original ARM loads, stores and branch targets;
no gameplay meaning is inferred. The local struct describes offsets 0x00–0x1c,
not the full allocation size. Registered storage remains owned by the caller.

- `Unk0f7188_Nop_0f7884` (4 B): no parameters or effects; original is `bx lr`.
- `Unk0f7188_Nop_0f7ae0` (4 B): no parameters or effects; original is `bx lr`.
- `Unk0f7188_Nop_0f7ae4` (4 B): no parameters or effects; original is `bx lr`.
- `Unk0f7188_Call_02065cfc` (24 B): narrows its integer argument to signed
  16 bits and tail-calls `func_02065cfc(1, id)`. Target literal and shifts
  establish the wrapper name and argument conversion.
- `Unk0f7188_Unk_0f7ca8` (24 B): writes the supplied 32-bit value to offset
  0x18 of the registered object, if present.
- `Unk0f7188_Unk_0f780c` (36 B): registers non-null writable storage at
  `data_02176e08`, then clears offsets 0, 8, 0x14 and 0x18.
- `func_020f7c64` (44 B): if storage is registered, stores argument three at
  0x10, argument two as a halfword at 0x0c, and argument one at 4, in that
  order. Global reloads after stores preserve the original aliasing behavior.
- `Unk0f7188_Unk_0f7210` (56 B): requires a readable object; returns true only
  if offset 8 equals 10, offset 0x14 equals zero, and signed field 0x10 is
  at least signed field 0x1c. Does not modify the object.

## Existing implementation

`Unk0f7188_Unk_0f7cc0` remains unchanged. Its switch dispatches values
0, 1, 7, 8 and 10 to the field-0x18 setter with 1, and all others with 0.
Placing the setter before this caller yields 100% objdiff for both; placing
it after the caller caused the documented same-file call scoring artifact
(99.52%), despite matching instruction sequences.

## Hard list

None for M1-T621.

## M1-T622: verified matches

All eight requested functions score 100% in objdiff. Existing symbol names are
retained because no gameplay semantics are established by the instruction evidence.

- `func_020f7830` (84 B): requires a writable 36-byte descriptor. Writes size
  28, clears offsets 4 and 0x14, and installs callbacks at 0x0c, 0x10,
  0x18, 0x1c and 0x20. ARM literal relocations identify the five callbacks;
  offset 8 remains untouched. Callback addresses are stored, never invoked here.
- `func_020f7c10` (84 B): when registered, stores the signed halfword ID and
  full signed limit, resolves group 12/index 27 through `func_020445f4`, passes
  the result and caller value to `func_0204fed8`, stores its result at offset
  4, then calls the existing field-0x18 selector. Global reloads follow ARM.
- `Unk0f7188_Unk_0f7cc0` (84 B): already present and reverified; values
  0, 1, 7, 8 and 10 select 1, all others select 0. No change was necessary.
- `func_020f7bac` (100 B): follows the same call and store sequence as
  0f7c10, but converts a nonzero third argument to limit 2, otherwise 0.
- `func_020f7de4` (100 B): clears two flag bytes and sixteen request records,
  copies the second argument into record 2, sets flag 4 and submits the
  borrowed request to `func_020bc9f4` with the first argument as kind.
- `func_020f7d14` (104 B): clears the request, copies value 65535 into record
  0, sets flag 1 and submits it to `func_020bcacc` with the caller's kind.
- `func_020f7d7c` (104 B): same request shape as 0f7d14, with caller value
  in record 0 and the second argument as kind.
- `func_020f7e48` (108 B): copies the second and third arguments into records
  6 and 7, sets flags 0xc0, and submits to `func_020bcbc4` with caller kind.

Request layouts and indices follow the byte/word stores in the original ARM;
record copies preserve the observed source stack stores (See DEC-013).
No new tests are required by this card: exact instruction/relocation comparison
and the project gates provide validation. No M1-T622 functions remain hard.

## M1-T623: verified matches

All five requested functions score 100% with the configured ARM compiler.
Existing neutral symbols are retained: instruction evidence establishes field
and service behavior, but does not establish gameplay names. Pointers are
borrowed and must reference the fields accessed below.

- `func_020f7188` (136 B): after `func_020fec00` permits advancement,
  adds signed field 0x14 to 0x10. Crossing either signed bound at 0x18/0x1c
  clamps the value, clears the increment, copies 0x0c to 8 and returns one.
  Otherwise returns zero. Bounds and strict comparisons follow ARM branches.
- `func_020f7ae8` (196 B): requires a readable event. Kind zero checks
  presence of request word 4 twice, passing its inverse to 02065604 and
  020655b4 around 02065bc0. Other kinds have no effects. The stored word
  value is unused; ARM tests the flag, not the value.
- `func_020f7888` (600 B): advances registered state phases 0 through 4
  when the observed service predicates permit. Phase zero configures ID
  slots 6/7 and the mode selected by field 0x10; later phases wait, record
  the result at offset 8 and submit a kind-1 request containing words 0/3.
  ARM calls establish service order, flags 0x101 and slot 25 polling.
- `func_020f7578` (660 B): dispatches bits 5..8 of input word 0x24 after
  submitting its halfword at 0x20. Selectors 0..8 choose the original
  service and request sequences, including slot 30 and the byte-0x23
  comparison with 7. The input must expose bytes through offset 0x27.
- `func_020f7248` (816 B): handles event kinds 1..4 using request words
  0, 2, 6 and 7. Updates signed progression fields, forwards selected
  requests, and invokes optional callbacks at offsets 0x34/0x38/0x3c.
  Word presence is separate from value; absent values default to zero.
  ARM accesses establish a writable 0x40-byte record and borrowed event.

The inlined output helper initializes both selector defaults before reading
records, preserving the original instruction sequence and separate temporary
word slots. Exact instruction/relocation comparison supplies validation;
this card requires no new tests. No M1-T623 functions remain hard.
