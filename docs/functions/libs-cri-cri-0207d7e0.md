# CRI unit 0207d7e0

M2-T319 implements the eight selected ARM functions. A public-source search
for CRI ADX Nintendo DS SDK source did not establish a matching implementation;
the [CRI public manuals](https://game.criware.jp/en/learn/manual/) are not a
source counterpart. The implementation follows the delinked instructions and
retains neutral symbols because field meanings are not established.

The six wrappers require a non-null borrowed state with a provider pointer at
offset +4; they forward that pointer without validation or ownership transfer.
The local prefix type exposes only those observed bytes and adds no module
boundary. The two remaining accessors require caller-provided storage of the
size indicated below. No allocation or lifetime extension occurs.

| Function | Bytes | Instruction evidence and contract |
| --- | ---: | --- |
| `func_0207d7e0` | 16 | Load +4 and tail-call `func_0207a740`; return its signed word (provider reads signed halfword +0x24). |
| `func_0207d7f0` | 16 | Load +4 and tail-call `func_0207a748`; return its word (provider reads +0x28). |
| `func_0207d81c` | 16 | Load +4 and tail-call `func_0207a760`; return its word (provider reads +0x30). |
| `func_0207d82c` | 16 | Load +4 and tail-call `func_0207a768`; return its word (provider reads +0x34). |
| `func_0207d8d4` | 8 | Add 0x60 to the borrowed base and return that address; storage must span the offset. |
| `func_0207d8dc` | 16 | Load +4 and tail-call `func_0207a78c`, whose calls update provider fields from its nested record. |
| `func_0207d8ec` | 16 | Load +4 and tail-call `func_0207a7bc`, whose calls submit provider fields to its nested record. |
| `func_0207d8fc` | 8 | Return the word at +0xb0; require aligned storage of at least 0xb4 bytes. |

All eight targets match at 100% objdiff. No new tests are required by the card;
instruction matching verifies the generated code. The remaining eleven unit
functions are outside this card and stay delinked. There are no hard-list
functions among these eight targets. The unit remains delinked until human
completion marking.
