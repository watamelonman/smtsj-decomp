# sdk_0205e53c

Sixteen ARM wrappers reconstructed from the original instructions. Public source
was sought in NitroSDK and pret/pokediamond/pokeplatinum references; no matching
wrapper implementation was identified. Symbol names remain neutral because the
card's SDK classification does not establish these wrappers' original names.
The remaining functions in the translation unit stay supplied by the delink.

The private state view describes provider-owned storage at `data_0216b348`.
Offsets come from literal loads and field accesses, without adding ownership.
The float interpretation at +0xc8 follows the soft-float comparisons against
zero and 1.0 in `func_0208e1ac`.

| Function | Behavior and instruction evidence | Result |
| --- | --- | --- |
| `func_0205e560` | Selects `func_0208e084` or `func_0208e0e8` with slot zero and the original second argument; CMP and BL at 0205e564..0205e578. | 100% objdiff |
| `func_0205e580` | Tail-calls `func_0208e13c(0)`; MOV at 0205e584. | 100% objdiff |
| `func_0205e5b4` | Returns signed state +0xd0; LDR at 0205e5b8. | 100% objdiff |
| `func_0205e5c4` | Stores float at +0xc8 then forwards it to `func_0208e1ac`; STR at 0205e5cc. | 100% objdiff |
| `func_0205e5dc` | Returns stored float at +0xc8; LDR at 0205e5e0. | 100% objdiff |
| `func_0205e63c` | Calls `func_0202b914` with borrowed pointer +0x94 and saves its result at +0x98; BL/STR at 0205e648/0205e650. | 100% objdiff |
| `func_0205e65c` | Forwards pointer +0x94 and saved word +0x98 to `func_0202b960`; paired LDR at 0205e664/0205e668. | 100% objdiff |
| `func_0205e6a8` | Forwards request and state +0xd4 to `func_0205e6c0`; LDR at 0205e6b0. Returns provider slot or -1. | 100% objdiff |

| `func_0205e53c` | Selects the slot-zero provider with zero argument; CMP/BL at 0205e540..0205e558. | 100% objdiff |
| `func_0205e590` | Forwards argument to slot zero and stores status -1 at +0xd0; STR at 0205e5a8. | 100% objdiff |
| `func_0205e5ec` | Refuses while +0xd8 is nonzero; resets provider before submission and after success; BL sequence at 0205e610..0205e630. | 100% objdiff |
| `func_0205e678` | Scans eight pointer slots at +0xa8 for the first null, or returns -1; LDR/CMP loop at 0205e680..0205e698. | 100% objdiff |
| `func_0205e6c0` | Requires enable byte +0xa4 and an empty slot; submits with three -1 defaults and applies level byte +0xa5, returning slot or -1; 0205e6c0..0205e738. | 100% objdiff |
| `func_0205e740` | Reverses arguments to provider 0202a110 and returns whether result is positive; MOVGT/MOVLE at 0205e754..0205e75c. | 100% objdiff |
| `func_0205e764` | Rejects signed indices outside 0..7 and clamps unsigned value to 65535 before forwarding slot address; 0205e768..0205e798. | 100% objdiff |
| `func_0205e79c` | Clamps unsigned level to 127; index eight updates all eight handles, otherwise updates the supplied index without a bounds check; 0205e7a4..0205e7fc. | 100% objdiff |

The M2-T237 source search included [pret/pokediamond](https://github.com/pret/pokediamond)
and its NitroSystem sound-player API references. No matching game-specific
wrapper was identified; the code follows the instruction evidence above.
The state view now includes enable/level bytes at +0xa4/+0xa5, eight borrowed
slots at +0xa8, and the busy word at +0xd8. The separate `data_0216b3f0`
external preserves the original handle-array relocation. Explicit local state
pointers retain the singleton address across provider calls, matching the
original register lifetime without imposing volatility or changing ownership.

No new behavioral tests are required by this card; objdiff verifies generated
instructions and relocations against the original for each function.

Hard list: none.
