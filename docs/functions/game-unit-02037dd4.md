# game/unit_02037dd4

## `func_02037dd4` — 0x02037dd4, 240 bytes

Starts and polls a single asynchronous request using state at `data_0215dd30`
and request storage at `data_0215dd34`. State zero constructs a 64-byte path
from `data_02141f98[1]`, the caller's suffix, and `data_02141fdc`, then
immediately falls through to polling. A zero poll result transfers the returned
pointer into context offset `0x2470`, clears the 124-byte state/request block,
and returns one. Pending or unknown states return zero.

Parameters are a writable context and a NUL-terminated suffix. Their lifetime
must span the sequence; the assembled path must fit the original 64-byte buffer.
The resource's purpose is not established, so the existing neutral symbol remains.
Evidence: calls to `func_02015134`, `func_0201524c`, and the request trio
`func_020516dc`/`func_02051844`/`func_020519e8`; the final store is at `0x2470`.

## `func_02037ec4` — 0x02037ec4, 616 bytes

Advances a seven-state sequence using `data_0215ddac` and request storage at
`data_0215ddb0`. State zero calls `func_02058854` on context offset `0x24a4`.
States one, three, and five construct paths with the same prefix and caller
suffix, followed respectively by `data_02141fe4`, `data_02141fec`, and
`data_02141ff4`. Each starts a request and immediately polls it. Completed
requests store pointers at `0x30a4`, `0x30a8`, and `0x30ac`. The final completion
clears the 124-byte state/request block and returns one; other calls return zero.

Parameters have the same lifetime and path-capacity contract as above, with a
context writable through offset `0x30af`. Evidence is the switch table, three
request/poll/result call sequences, and their destination stores. Exact resource
semantics remain unknown; the existing neutral symbol remains.

## Validation and hard list

Both functions match the target instructions and relocations with the standalone
comparison helper. No functions are deferred to the hard list.
