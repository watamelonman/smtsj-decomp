# libs/unknown/lib_020ba678

## Evidence and source search

The card classifies this translation unit as SDK/middleware. A public-source
search of NitroSDK, pret/pokeplatinum and zeldaret reconstructions did not
identify a matching implementation. Local evidence instead identifies game
script request wrappers and command builders:

- `func_020b8b38` stores its four arguments into request words `+0x20` through
  `+0x2c` of the shared record returned by `Unk044904_Unk_045064`, then forwards
  the record to `func_0204e9d8`. It returns the submission Boolean.
- `Unk03aae8_Unk_03acf4` publishes the result in the implicit current script
  context.
- `func_0203ac00` reads a zero-based script operand.
- `func_020b8ac8` returns the shared record `+4`; `func_020b8aec` and
  `func_020b8b18` (its neighbouring providers) establish that the sub-record
  holds three words followed by a flag halfword at `+0x0c` and a word operand
  at `+0x10`.
- `func_0204acdc` returns the entry `+0x294` state view. The `+0x44` word is
  tested for bit 0, `+0x48` is a signed command-slot index and `+0x4a` is a
  halfword command operand.

The neutral `func_` symbols are retained to agree with the protected symbol map.
No SDK identity, request-specific meaning or field name beyond the observed
operations is asserted.

## Functions

| Symbol | Size | Contract |
| --- | ---: | --- |
| `func_020ba678` | 36 | Submit request 120 with three zero arguments, publish the result, return 1. |
| `func_020ba69c` | 36 | Submit request 121 with three zero arguments, publish the result, return 1. |
| `func_020ba6c0` | 36 | Submit request 122 with three zero arguments, publish the result, return 1. |
| `func_020ba6e4` | 44 | Submit request 123 with script operand 0 as first argument and two zero arguments, publish the result, return 1. |
| `func_020ba710` | 44 | Submit request 124 with script operand 0 as first argument and two zero arguments, publish the result, return 1. |
| `func_020ba73c` | 80 | Resolve the caller's word ID, publish it as the shared-record ID, reset the state's slot index to 0, set operand `+0x4a` to 100, initialize the state's command source (`func_0204afe0`), advance it (`func_0204b044`) and build the first command with `func_020ba78c(0)`. |
| `func_020ba78c` | 172 | Append one command to the entry's two 24-byte slots at `+0x1e8`; optionally set sub-record flag bit 7; fill slot words 0, 1, 3 and 5; publish slot 1 through the command list when the previous index was nonzero; advance the index and wrap 2 back to 1. |
| `func_020ba838` | 212 | Build one command from the sub-record kind (1..5) and return `0x50000000 | func_020b0874(entry ID, arg)`. Kinds 1 and 2 submit through `func_0204ebb4` with the sub-record flags and word; kinds 3 and 4 copy the entry ID; kind 5 only sets the command kind. Kinds 0 and 6 leave the command untouched. |

Evidence for each entry is the original ARM instruction stream beginning at the
address encoded in its symbol; the constants above are the original call
operands.

## Hard list

None of the eight C functions in this file is left out. Other functions in this
translation unit remain linked from the original delink as required by the card.
