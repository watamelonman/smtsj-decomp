# lib_02048e90

M2-T240 reconstructs all five ARM functions with typed borrowed state views.
All five report 100% in objdiff. No functions remain on the hard list.

## Source and naming evidence

The required known-source search found no matching public SDK implementation.
The instruction sequences operate on the same `data_0215eea0` singleton as the
adjacent resource wrappers, invoke game-specific providers, and contain no SDK
signature or strings that establish a more specific purpose. Existing neutral
symbols are retained. Field contracts below come from the delinked object's
loads, stores, call arguments and relocations, not inferred subsystem names.

## func_02048e90 (72 bytes)

Returns immediately when the word at +0x7a3c is nonzero. Otherwise sets it to
one, clears +0x50 and invokes five providers in order; the third receives the
borrowed interior address +0x79b0. The caller must supply the full state layout.

## func_02048ed8 (24 bytes)

Loads the singleton pointer and tail-dispatches to `func_02048e90`. The singleton
must already reference valid state storage.

## func_02048ef0 (260 bytes)

Runs the original ordered teardown/provider sequence. Releases and clears nine
resource pointers at +0x798c, passes +0x7870 to its provider, and finally clears
the singleton pointer. Repeated provider calls and numeric arguments preserve
the original order; provider implementations determine resource lifetime.

## func_02048ff4 (80 bytes)

Looks up entry zero in resource slot zero, obtains its data and count, and
submits the borrowed data with the count truncated to 16 bits and the original
`data_0214316c` descriptor relocation. The descriptor's internal format is opaque.

## func_02049044 (280 bytes)

After three provider calls, scans ten object pointers beginning at +0x64.
Nonnull objects whose identifier bits 16..23 equal two are queried for kind.
Kinds 1, 2 and 7 use the query/12-check/transition path; other kinds use the
opposite query condition and a different transition provider. A separate input
condition latches +0x54 and issues notification providers only once. Finally,
a state-processing provider controls whether a second provider runs.

## Validation

Standalone instruction and relocation comparison matched all five bodies.
The project match gate and existing unit suite pass; no behavioral tests were
added because this card requires exact binary equivalence and exempts new tests.
