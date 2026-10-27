# sdk_0205b900

All eight ARM functions match at 100% using the configured compiler. The unit
remains linked from the delink pending human completion marking.

## Evidence and source search

Searched public NitroSDK references in pret/pokeplatinum and zeldaret before
reconstruction. No matching public source was identified. Despite the card's
SDK path, the calls use the adjacent resource stack and transfer queue, plus
three separate `=%s(%d)` format strings at 0x02143bf0/0x02143bf8/0x02143c00.
Names remain the existing neutral symbols rather than asserting SDK identities.
The original delink instructions and relocations are the implementation evidence;
adjacent `src/game/unit_0205b540.c` and `src/game/unit_0205ae50.c` corroborate
stack count, entry fields, transfer words and queue callback layout.

Layouts are private borrowed views. Work is supplied by the existing allocator;
these wrappers retain its ownership rules. Six transfer words occupy a nine-word
queue record; callback metadata is supplied by the queue provider. Bounds storage
starts at +0x18, the 32-byte label at +0x2c, and flag bytes at +0x58/+0x59.

## Functions

- `func_0205b900` (124 bytes): obtains two bounds sizes, pushes the work to the
  resource stack, transfers source/destination/size triples immediately through
  the VCOUNT helper, then marks byte +0x59 ready. Work must be valid.
- `func_0205b97c` (36 bytes): gets singleton work, creates work using its +0x10
  pointer advanced by 12 bytes, runs the immediate transfer and returns it.
  The provider must supply a valid singleton and payload.
- `func_0205b9a0` (136 bytes): reserves the bounds sizes and submits the same two
  transfer triples to the queue. Clears +0x59; callback `Unk05ae50_Unk_05b228`
  sets it when processing completes. Work must outlive queued processing.
- `func_0205ba28` (112 bytes): creates work from borrowed input, formats its
  label with `data_02143bf0`, derives bounds and reserves both stack sizes.
  Name must be a valid terminated string; label output is bounded to 32 bytes.
- `func_0205ba98` (108 bytes): returns null when the existing allocator returns
  null; otherwise formats `data_02143bf8`, reserves caller-supplied sizes and
  sets +0x58. Sizes retain the adjacent stack provider's byte units.
- `func_0205bb04` (100 bytes): creates work from resource +12, fills source words
  using `func_0205accc`/`func_0205acd4`, formats `data_02143c00`, transfers
  immediately and returns the work. Resource and name must be readable.
- `func_0205bb68` (24 bytes): pops the stack and passes a non-null result to
  `func_0205aa54`; an empty stack requires no release.
- `func_0205bb80` (44 bytes): snapshots stack count at +0x400 and invokes the
  pop/release wrapper that many times, with an unsigned loop counter.

## Validation

Objdiff provides instruction and relocation comparison for each function; no new
behavioral tests are required by this card. Run the repository unit suite,
anticheat, match and checksum gates as the integration checks.

## Hard list

None.
