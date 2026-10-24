# game/unit_0203812c

- `func_0203812c` (816 bytes, ARM): initializes sub-blocks at work +0x205c
  and +0x2084, saves/restores the state returned by `func_02007a58`, and
  processes the source at +0x2058. When `func_02052624()` is below 31, it
  first polls volatile VCOUNT until it is within 191–213 inclusive.
  It obtains a resource through `func_02025b14`, copies fixed 16-byte names
  selected by signed indices at input-record +0x20, and binds destination
  records 1 through count−1 using `func_020257ec`. It then binds dictionary
  entries 0–7 to records count through count+7. Each binding stores a pointer
  at record +0x54 and calls `func_0202172c`. Missing resources or dictionary
  entries produce null bindings. Indexed dictionary entries use a stored
  stride and contain offsets relative to the resource base.

The original symbol is retained: instruction evidence establishes the lookup
and binding behavior, but no gameplay meaning. Parameters are borrowed typed
views; input pointers and selected names must be valid, dictionary data must
be well formed, and count must be at most 82 for the 90-record work prefix.
Opaque sub-block extents are partial layout views, not inferred full types.
See DEC-008 for the aligned temporary and unrolled tail.

Validation: standalone instruction/relocation comparison is identical;
objdiff reports 100% for the function. Anticheat, all nine tool tests, match,
and full-image checksum pass. No hard functions remain. No module boundary
changed; the TU remains linked from the delink until a human marks it complete.
