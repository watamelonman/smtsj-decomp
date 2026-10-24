# game/unit_020fcfe4

The four task-card functions match at 100% in objdiff. Original symbol names
are retained because the higher-level meaning of the kind values is unproven.
The local 16-byte work layout comes from word stores at +0/+4 and byte stores
at +8 through +12. The callbacks at 020fd268 and 020fd2fc establish the counter,
interval, visibility, remaining-count and state roles; the latter submits +4
to the packed-color drawing helper. Callback allocation owns the work block;
`data_02176e18` holds the singleton pointer.

- `func_020fcfe4` (132 bytes): compare two kind priorities. A zero right kind
  returns zero, otherwise a zero left kind returns one. Kinds 1/2/3 map to
  comparator values 3/2/9; other kinds map to zero. Passes both values to
  `Unk0981dc_Unk_098324`; the caller requires an exact result of one.
- `func_020fd068` (96 bytes): null-safe color assignment. Kinds 0/1/2/3 select
  `ff0f00ff`/`9e2087ff`/`2acae7ff`/`2ed943ff`; other kinds select all ones.
  Evidence is the four literal words and stores to work +4.
- `func_020fd0c8` (200 bytes): replace the existing singleton kind/color only
  when the comparator returns one, or allocate a 16-byte callback task. On
  successful allocation, initializes the kind, zero counter/interval/state,
  visible=1 and remaining=1, publishes it and assigns its kind color. Allocation
  failure leaves the singleton absent.
- `func_020fd190` (216 bytes): allocate only when the singleton is absent.
  Initializes kind/counter/state to zero and visible to one, truncates interval
  and remaining arguments to bytes, and packs the input word's upper three
  bytes with a low byte of 255. The byte-parameter packing helper preserves
  the original channel-extension instructions. Allocation failure does nothing.

## Validation

Direct compiled instruction comparisons pass for all four functions; the match
and checksum gates validate object matching and the original linked image.
The card explicitly requires no new tests; matching against the original code
is the acceptance test. No module boundaries changed.

## Hard list

None.
