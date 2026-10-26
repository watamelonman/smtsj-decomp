# sdk_0205c1c8

Public-source lookup: searched public NitroSDK and pret/pokeplatinum-related
G2D resource helpers; no implementation with these layouts and allocation
providers was identified. The split's NitroSDK directory alone does not prove
SDK provenance. Existing `func_` symbols are retained because symbol configuration
is human-owned. All contracts below come from the original ARM instructions.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_0205c1c8` | Copies the prefix returned by `func_0205ad6c`, appends the name and `.cmp` (`data_02143c08`), then probes the path through `func_020519f0`. On zero it rebuilds the path with the caller suffix and returns zero; otherwise returns one. Caller owns sufficient output storage. | 100% |
| `func_0205c2c4` | Allocates/clears a 16-byte wrapper, builds a path in 64 stack bytes with fallback `.gtan` (`data_02143c10`), loads the resource, sets ownership flag to zero and binds it. Returns the owned wrapper. | 100% |
| `func_0205c258` | Copies four bytes from source into a local result, then four bytes from source +4 into caller output; returns the first word. Source need not be word-aligned. | 100% |
| `func_0205c288` | Binds resource at +0, table at resource +20 at +4, and table end at +8 using resource +12 count and 12-byte stride. | Hard; omitted |
| `func_0205c328` | Allocates/clears a 16-byte wrapper, sets +12 to one, then binds the supplied borrowed resource. | 100% |
| `func_0205c368` | Calls resource release only when wrapper +12 is zero, then always frees the wrapper. | 100% |
| `func_0205c390` | Uses unchecked 12-byte entry index; entry +4 is resource-relative offset, entry +8 is count; reads +4 of the last 40-byte record. Count must be nonzero. | 100% |
| `func_0205c3c0` | Allocates 320 bytes and invokes the clear helper before returning ownership. | 100% |
| `func_0205c3dc` | Tail-forwards the buffer to the existing deallocator. | 100% |
| `func_0205c3e8` | Tail-forwards a zero fill of 320 writable bytes. | 100% |

## Hard list

- `func_0205c288`: tested typed header/entry pointer arithmetic, byte and integer
  address arithmetic, signed count multiplication, intermediate table assignment,
  and changing definition order. The closest candidate has the correct 60-byte
  size and behavior, but loads the resource pointer into r0 instead of r1 and
  schedules the stride constant after the count load. The straightforward version
  also schedules the initial table address before the resource store. Objdiff
  reported 73% for that version. No candidate was retained; the original delinked
  implementation remains in use. A human can create a decomp.me scratch with
  `tools/decompme.py` for the register allocation/scheduling problem.

For M2-T128, public-source searches in pret/pokeplatinum and NitroSDK resource
helpers found no matching implementation. The `.gtan` and `.cmp` strings and
custom prefix/resource providers support the behavior above, but do not establish
SDK provenance or a more specific format name. Existing configuration symbols
remain unchanged. Both new functions passed direct instruction/relocation
comparison and objdiff at 100%; checksum and all repository tests passed.

No assembly stub is added: this repository links incomplete TUs from their
original delinks. The table binder above remains the only omitted function.
