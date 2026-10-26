# CRI record helpers (M2-T022 / M2-T023)

All eleven functions below match the delinked ARM originals at 100% with the
configured mwccarm 2.0/sp1p5 compiler. Existing `func_` symbols are retained for
linkage; no original API names have been established.

The partial record is 0x3c bytes. Its layout follows the original instruction
offsets, including signed halfwords at +0x28 through +0x38. Pointers must be valid
unless explicitly stated otherwise. Output operations preserve instruction order,
including when caller buffers alias record storage.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_0208073c` | Clears all four 0x3c-byte pool records at `data_021734f4`. The compiler clear intrinsic reproduces the 240-byte bulk stores at 02080758..02080768 without an external library call. |
| `func_02080774` | Scans four slots for an inactive word; returns null if full. Clears the selected record, sets active=1 and its index at +4, zeros +8/+0x0c, and calls `func_0207ae34(500, 44100, record+0x30, record+0x32)`. Finally clears each of the eight pair bytes separately, preserving the original stores after the helper call. Pool storage is borrowed; callers release records through the existing clear helper. |
| `func_02080908` | Rejects nonzero state at +0x0c; otherwise writes request 2 at +0x14 and four caller words at +0x18..+0x24, returning 1. Instruction evidence: 02080908..02080938. |
| `func_0208081c` | Forwards scalar arguments in reversed order to `func_0207ae34`, with halfword outputs at record +0x30 and +0x32 (`add` instructions at 02080828/2c). No return value is consumed here. |
| `func_02080838` | Interleaves two signed halfword pairs into +0x28, +0x2a, +0x2c, +0x2e; alternating `ldrsh`/`strh` establishes element width and order. |
| `func_0208085c` | Extracts the interleaved signed halfwords into two two-element output buffers, in the same alternating order. |
| `func_02080880` | Stores three halfword inputs at +0x34/+0x36/+0x38, evidenced by three `strh` instructions. |
| `func_02080890` | Reads those three signed halfwords and writes each to a separate output pointer, evidenced by alternating `ldrsh`/`strh`. |
| `func_020808ac` | Accepts null as a no-op; otherwise clears the active word and invokes `func_020119c0(record, 0, 0x3c)`. The explicit first store is present in the original. |
| `func_020808cc` | Returns the word at +0x0c (`ldr r0, [r0, #12]`). |
| `func_020808d4` | Rejects a nonzero +0x0c state with return 0. Otherwise writes request value 1 at +0x14 and four caller words at +0x18..+0x24, returning 1. |

## Source search

Searched for public CRI ADX/STM middleware reconstructions before implementation.
Search results included current [CRI documentation](https://game.criware.jp/manual/native/adx2_en/latest/criatom_intro_sdk.html)
and ADX decoder projects, but no source was identified for these record helpers.
The implementation therefore follows the delinked instructions; current API names
were not used to infer the original identities.

## Validation and remaining scope

The cards explicitly require no new tests. Objdiff checks every implemented
function against the original instructions. All eleven functions in the TU now
match at 100%; no link-completion configuration is changed. The full build,
anticheat gate, Python test suite, and checksum gate pass.

For M2-T023, a further public-source search found
[vgmstream's ADX parser](https://github.com/vgmstream/vgmstream/blob/master/src/meta/adx.c)
and CRI-related decompilation projects, but no matching record-pool implementation.
The new functions therefore use instruction evidence and retain their neutral symbols.
The numbers 500 and 44100 are observed helper inputs; no unsupported API meaning
is assigned to them.

Hard list: none for either card.
