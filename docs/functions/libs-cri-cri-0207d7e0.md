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
instruction matching verifies the generated code. The remaining unit functions are covered by the later cards below. There are no hard-list
functions among these eight targets. The unit remains delinked until human
completion marking.


## M2-T320

A fresh public-source search for CRI ADX Nintendo DS code found no matching
implementation. The [CRI SDK portal](https://sdk.criware.com/adx2) and
[public API manual](https://game.criware.jp/manual/native/adx2_en/latest/criapi_refman.html)
did not supply a source counterpart. These neutral symbols follow the original
instructions. All eight additions match at 100%; no hard-list entries remain
for this card. No tests are required; objdiff checks the instruction sequences.

| Function | Bytes | Instruction evidence and contract |
| --- | ---: | --- |
| `func_0207d800` | 28 | Null returns zero; otherwise call `0207a750` with borrowed provider at +4. |
| `func_0207d83c` | 72 | Positive `0207a770` and byte +1 in {2,3} permit `0207a778`; otherwise zero. |
| `func_0207d884` | 80 | Same guard, forwarding signed index to `0207a780`; otherwise -128. |
| `func_0207d904` | 88 | Increment global +0xc; transition to one clears all 1000 aligned pool bytes; return one. |
| `func_0207d95c` | 80 | Decrement global +0xc; transition to zero clears the pool. References must be balanced. |
| `func_0207db2c` | 148 | Scan configured count/start at `02145ed8` +0/+4 with 100-byte stride for zero signed byte +0; initialize via `0207d9ac`, clear byte +3, return borrowed slot or null on exhaustion. Configuration must describe a valid pool range. |
| `func_0207dbc0` | 44 | Pair `0207e7d4`/`0207e7e0` around `0207dbec`, preserving its returned slot. |
| `func_0207dbec` | 48 | Signed selector below 0x100 calls `0207da90`; otherwise `0207db2c`; forward provider as fourth argument with three zero words. |

The pool remains provider-owned. The scoped strength-reduction setting preserves
the scan's original multiply and register allocation (See DEC-038). The aligned
word declaration allows the compiler clear intrinsic to reproduce its word-store
loop without any assembly or hand-coded instruction data.


## M2-T321

The public-source search found no matching CRI implementation; the
[cri-audio-toolkit source](https://github.com/darkruss48/cri-audio-toolkit)
concerns audio formats rather than this slot-management unit. Both functions
were reconstructed from their original ARM instructions, retaining neutral
symbols because the underlying provider and field semantics remain uncertain.

| Function | Bytes | Instruction evidence and contract |
| --- | ---: | --- |
| `func_0207d9ac` | 228 | Under `0207e7b0`/`0207e7bc`, initialize a caller-owned aligned 100-byte slot. Store arguments at +8/+12/+16, the sign word at +20, and signed ceiling of the third argument divided by 2048 at +24/+52. Set +48 to 64, +92 to zero and +96 to 0xfffff. For a non-null provider, call its vtable +36 with indices zero and one and store their sum at +68/+28/+32. Clear bytes +2/+72 and set +1/+0 to one; other fields retain their prior values. Provider must supply a valid vtable, and returned counts must have a representable signed sum. |
| `func_0207da90` | 156 | Scan count `02145ed8` +8 starting at `0217307c` +8, using 100-byte strides in `02173094`. Initialize the first slot whose signed byte +0 is zero, set byte +3 to one, and return its borrowed address; return null on exhaustion. Configuration must describe a valid pool range. |

Both targets match at 100% objdiff. No additional tests are required by this
card; instruction comparison validates the reconstruction. The allocator reuses
the scoped strength-reduction choice from DEC-038. No new module boundary or
ownership transfer is introduced, and neither target remains on the hard list.
All eighteen functions in this unit now have C implementations; the unit stays
delinked pending human completion marking.
