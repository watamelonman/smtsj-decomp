# sdk_02020744

All three functions match the delinked ARM originals at 100% with the configured
MWCC 2.0/sp1p5 compiler. Existing `func_` link symbols are retained because the
symbol configuration is human-owned. Despite the TU's NitroSDK path, public
prior art identifies these routines with NNS frame-heap and G2D APIs.

Public-source comparison used pret/pokediamond revision
`b623abef1b4dfe204ca50aab42447ac00c134290`:

- [NNS_FND_frameheap.s](https://github.com/pret/pokediamond/blob/b623abef1b4dfe204ca50aab42447ac00c134290/arm9/asm/NNS_FND_frameheap.s)
- [NNS_G2D_g2d_nan_load.s](https://github.com/pret/pokediamond/blob/b623abef1b4dfe204ca50aab42447ac00c134290/arm9/asm/NNS_G2D_g2d_nan_load.s)

## func_02020744 — 80 bytes

Restores frame-heap allocation bounds from a saved state and removes that state
and newer states from the chain. A zero tag selects the current head; otherwise
the chain is searched for the first matching tag. Returns zero without modifying
the heap if no record exists, and one after restoring the bounds. Requires a
valid heap and a valid, acyclic record chain. The heap must outlive the call.

Evidence: target loads the chain at heap+0x2c and copies record+4/+8/+12 to
heap+0x24/+0x28/+0x2c. Neighbor 020206f4 builds the same four-word records.
Public `NNS_FndFreeByStateToFrmHeap` has the same behavior with a different
instruction schedule. An initial while loop matched only 78.60%; guarding a
do/while loop and breaking on a matching tag reproduces the original schedule.

## func_02020794 — 60 bytes

Finds the `ABNK` binary block (signature 0x41424e4b), unpacks its animation-bank
payload in place through 020207dc, and returns one with an output pointer eight
bytes past the block header. Missing blocks clear the output and return zero.
The file must be writable, the output slot valid, and the file storage must
remain alive while the returned bank is used. Bank internals remain opaque here.

Evidence: public `GetUnpackedAnimBankImpl_` uses the same block signature,
header offset, unpack call, and failure behavior. Both original call targets
are preserved with typed declarations. Match: 100%.

## func_020207d0 — 12 bytes

Tail-calls 02020794 with unchanged arguments and result; inherits its writable
file and output lifetime contract. Public `NNS_G2dGetUnpackedAnimBank` has the
same tail-call wrapper structure. Match: 100%.

## Hard list

None. No functions omitted. The TU remains linked from its delinked object until
a human marks it complete, as required by the task card.
