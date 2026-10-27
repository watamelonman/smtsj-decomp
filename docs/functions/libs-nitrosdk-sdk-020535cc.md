# sdk_020535cc — M2-T409

This partial TU implements the eight functions assigned to M2-T409. All eight
match the delinked ARM instructions at 100%. Other functions remain supplied by
the delink; the split configuration remains human-owned.

A public-source search for NitroSDK PAD code in pret/pokeplatinum found no
matching implementation for this record/state wrapper. Reconstruction therefore
uses the original instructions and retains the original neutral symbols rather
than assigning speculative SDK names.

## Evidence and contracts

The initializer at 0x020535cc clears five records, advancing by 0x56 bytes.
The updater at 0x02053640 writes held input at +0, its complement at +2, and
`current & ~previous` at +4. Query callers must supply a device index in 0..4;
mask bits are tested for any overlap. Storage remains provider-owned.

| Function | Behavior and instruction evidence | Match |
| --- | --- | --- |
| `func_020537b8` | Tests the +0 held halfword against the supplied word mask. | 100% |
| `func_020537dc` | Tests the +2 complemented halfword against the supplied word mask. | 100% |
| `func_02053800` | Tests the +4 newly pressed halfword against the supplied word mask. | 100% |
| `func_020539cc` | Stores the reload word at `data_02160794 + 0x10`; the updater copies it into the countdown at +0xc. | 100% |
| `func_02053bc8` | Reads the state word at +0; the updater assigns states 0..3. | 100% |
| `func_02053bd8` | Stores the flag at +0x14, tested for equality to one before the provider sequence at 0x02053a78. | 100% |
| `func_02053be8` | Stores the flag at +0x18, tested for equality to one before the provider call at 0x02053ac0. | 100% |
| `func_02053bf8` | Stores the flag at +0x1c, tested for equality to one before callback dispatch at 0x02053adc. | 100% |

The flag setters preserve the full supplied word; they do not normalize values.
Private prefix views introduce no new public data types or ownership boundary.
The address calculation for the +2/+4 queries preserves the base-symbol
relocation and the original multiply-accumulate instruction. An explicit local
bit intersection also reproduces the original TST operand order.

## Validation

`python3 tools/match_gate.py` passes, including all eight functions above.
`python3 tools/checksum.py` reports all artifacts byte-identical to the original.
The anticheat gate passes and all nine unittest cases pass. No new behavioral
tests were required by this card; instruction identity is the acceptance check.

## Hard list

None for M2-T409.
