# sdk_0204f7d4

The existing `func_` symbols are retained because the subsystem identity is not
established. Evidence below comes from the delinked ARM instructions and their
relocations. No module boundary changes are introduced.

Public-source search: inspected pret/pokeplatinum's library tree and searched
for the adjacent `<p>` / `<br>` strings and table key `0x8001`; no matching
implementation was located. Web searches for NitroSDK sources likewise did not
identify this unit. The SDK classification on the card is not proof of provenance.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_0204f7d4` | Initializes a 56-byte command through `func_0204f0a4`, sets command word 28, dispatches through `func_0204f098`. The second input supplies both initializer arguments 1 and 2. | 100% |
| `func_0204f804` | Same initializer; command 26, third/fourth inputs stored at byte offsets 20/24. | 100% |
| `func_0204f848` | Same layout and argument forwarding; command 27. | 100% |
| `func_0204f88c` | Unsigned halfword key comparison over 50 records at `data_02143494`, stride 16. Returns the borrowed first matching record or null. Input remains 32 bits, so out-of-range keys do not truncate. | 100% |
| `func_0204f8c0` | Calls the lookup and zero-extends record byte 2; absent key returns zero. | 100% |
| `func_0204f8d8` | Calls the lookup and zero-extends record byte 12; absent key returns zero. | 100% |
| `func_0204f8f0` | Zero selector returns one without lookup; otherwise returns record word 8 or zero when absent. | 100% |
| `func_0204f914` | Scans string prefixes from `data_02143488`, using length/compare helpers at `02015118`, `020152cc`, `020153e0`. Writes matched length and returns a 16-bit index plus `0x8001`; sentinel failure returns `0xffff` without writing length. | Left in delink |

## Hard list

- `func_0204f914`: reconstructed the control flow with an initial comparison
  against `data_021437b4`, followed by a do/while comparison against
  `data_021437b8`, and final sentinel comparison against `data_021437bc`.
  Reached 97.76%. Executable instructions matched except literal-load offsets:
  MWCC reused the table-address pool slot, while the original has two separate
  slots referring to `data_02143488`, producing an extra four bytes. Tried scalar,
  array, and nested-array declarations and equivalent address expressions; all
  merged the slots. Omitted this function's C definition as required by the card;
  its original delinked implementation remains linked. A human can use
  `tools/decompme.py` to investigate the original declaration/compiler behavior.
