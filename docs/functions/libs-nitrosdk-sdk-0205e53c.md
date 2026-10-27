# sdk_0205e53c

Eight ARM wrappers reconstructed from the original instructions. Public source
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

No new behavioral tests are required by this card; objdiff verifies generated
instructions and relocations against the original for each function.

Hard list: none.
