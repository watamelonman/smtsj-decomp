# game/unit_0203d494

All four functions match the delinked ARM original at 100% objdiff.
Names remain unchanged: instruction and offset evidence establishes behavior,
but does not establish domain-specific names. All handlers take no C arguments;
they obtain arguments through `func_0203ac00`.

## func_0203d494 (308 bytes)

Counts nonzero halfwords equal to signed script argument 0. If argument 1 is
nonzero, the work record contributes its three entries at +0x40, provided its
+2 field is nonzero, +0x1c signed field is positive, and +0x6c status is not
1, 7, or 6. Each of three nonnull slot records contributes six entries at +0x28
when its +0x1e signed field is positive and +0x34 status is not 1, 7, or 6.
Publishes the count through `Unk03aae8_Unk_03acf4`, returns 1.
Evidence: original loads, loop bounds, comparisons and calls at 0x0203d494.
Typed array members preserve the original indexed halfword loads; byte-offset
arithmetic trials introduced extra induction variables and did not match.
All pointers returned by the accessors are borrowed; slot pointers may be null.

## Unk03d494_Unk_03d5c8 (80 bytes)

Argument 0 selects the selector-2 integer query (mode 0), selector-2 float query
converted to a signed integer (mode 1), or zero (other modes). Publishes the
result and returns 1. Evidence: calls to `func_02098050`, `func_02097f68`, and
`_ffix` in the original. The float-return prototype and explicit cast reproduce
the soft-float conversion; the conversion helper is not called with missing
arguments.

## Unk03d494_Unk_03d618 (112 bytes)

Evaluates and discards argument 0, truncates arguments 1–3 to signed halfwords,
and forwards them with the unsigned work id at +0x35c to `func_0209e33c`.
Writes 15 to +0x18 of the borrowed object referenced by context +0xe8; returns 3.
Evidence: original argument calls, sign extension, loads and final store.
Accessor results must be valid, as in the original.

## func_0203d688 (164 bytes)

Truncates arguments 0–4 to signed halfwords. If either of the first pair is
negative, uses the work id at +0x35c; otherwise resolves the pair through
`Unk02f2a8_Unk_035b08`. Forwards the selected id and remaining three arguments
to `func_0209e33c`, sets the same context object's +0x18 state to 15, returns 3.
Evidence: original signed comparisons, resolver call, and state store.
Accessor results must be valid, as in the original.

## Hard list

None.
