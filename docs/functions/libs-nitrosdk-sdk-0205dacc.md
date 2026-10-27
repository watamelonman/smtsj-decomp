# sdk_0205dacc (M2-T276)

The eight functions below are reconstructed from ARM instructions and relocations.
Existing neutral linker names are retained because the subsystem's identity is not
established; the NitroSDK directory label and the presence of `.gtsh`/`.cmp` path
suffixes (`data_02143c18`, `data_02143c20`) do not prove which library produced the
format. Public-source lookups covered the NitroSDK-derived code reconstructed in
[pret/pokeplatinum](https://github.com/pret/pokeplatinum) and
[zeldaret/ph](https://github.com/zeldaret/ph); no matching implementation of this
resource wrapper was identified, and no external implementation was copied.

`func_0205dacc` and `func_0205dc28` belong to M2-T277; they are declared in the shared
header but are not part of this card. Partial layouts describe only the offsets
accessed here. Indices, pointers and counts are unchecked, as in the original.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_0205db5c` | Copies the first word of a record into a local and the following word into caller storage, then returns the first word through `func_02008904`. The record need not be word-aligned. |
| `func_0205dbf0` | Stores an entry pointer at `items[count]`, then increments the count. Evidence: loads from +4/+8 and the reload of +8 after the store. |
| `func_0205dc0c` | Binds the group to +0xc, the first record at group+0x14 to +0x10, and `group+0x14 + count*8` to +0x14. The count at group+0xc is read before the record base. |
| `func_0205db8c` | Scans the registry through `func_0205aa68`/`func_0205a99c`; `func_0205aa68()` is re-evaluated on every iteration. Skips entries whose byte at +0x58 is zero, compares the candidate name at +0x2c with the item name at +0x10, and on equality stores the candidate at item+0x30 and returns one. Returns zero when no entry matches. |
| `func_0205dcd4` | Builds a path through `func_0205dacc` with the `.gtsh` suffix, loads it through `func_02051610`, allocates/clears a 28-byte wrapper, records the resource and an ownership flag of zero, allocates `resource->count * 4` bytes for the entry table, parses the resource with `func_0205dc28(u32 mode)` and returns the wrapper. The path buffer is 64 bytes. |
| `func_0205dd58` | Allocates/clears the same 28-byte wrapper, records the borrowed resource, sets the ownership flag at +0x18 to one, allocates `resource->count * 4` bytes for the entry table, parses it with the supplied mode and returns the wrapper. |
| `func_0205ddb4` | Releases the resource only when +0x18 is zero, then always frees the entry table at +4 and the wrapper. |
| `func_0205dde4` | Resolves every entry in address order by calling `func_0205db8c` on `items[i]` while `i < count`. |

## Hard list

Nothing from this card remains on the hard list. All eight functions compare
instruction-for-instruction and by relocation against the delinked original and
report 100% in objdiff.

## Validation

`python3 tools/match_gate.py`, `python3 tools/checksum.py`,
`python3 tools/anticheat.py` and the repository unittest suite pass. The translation
unit is still linked from its delink in the human-owned configuration.
