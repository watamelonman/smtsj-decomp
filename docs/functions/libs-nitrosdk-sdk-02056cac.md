# sdk_02056cac matching functions

These functions retain their neutral original symbols: the delink's NitroSDK
label does not establish an upstream API identity. Public-source searches of
pret/pokeplatinum, pret/pokediamond and zeldaret SDK material did not identify
these wrappers. The implementation therefore follows the original ARM
instructions.

Ten of the eleven functions in the translation unit now match at 100%.
`func_02056f58` remains supplied by the delinked object and is on the hard
list below.

| Function | Bytes | Evidence and contract |
| --- | ---: | --- |
| `func_02056cac` | 20 | Selects work with `func_02056110`, passes its borrowed entry base at +8 to `func_0205bfd0`, which pops an entry when the count is nonzero. |
| `func_02056cc0` | 16 | Tail-calls `func_02056cd0` with count one. That provider shifts slot and count by nine, giving a 512-byte transfer. Source remains caller-owned. |
| `func_02056cd0` | 184 | Copies `count` 512-byte blocks to/from the GBA cartridge window selected by `engine`: zero uses the `0x05000000` backup path (`func_020050c4`/`func_0200510c`/`func_02005178`, direct PIO `func_02004760`), nonzero the `0x0A000000` ROM path (`func_02005278`/`func_02005290`/`func_020052f4`, direct PIO `func_020047b8`). The halfword status from `func_020038ac`/`func_0200390c` selects the queued or direct variant, and `func_02006c94` flushes the caller buffer. `slot` is a 512-byte sector index. |
| `func_02056d88` | 136 | Selects an eight-byte entry; extracts bits 22..25, 0..10 and 11..21 for the callback at work +0x201c. Passes a seven-word stack packet to `func_0205bf18`, which synchronously copies it into its queue. Caller supplies valid indices and callback lifetimes. |
| `func_02056e10` | 52 | Visits indices zero and one, calling `func_0205c0ec` on the entry base only when the work's first word is nonzero. |
| `func_02056e44` | 36 | Clears mask 0xe000 in volatile display-control words at 0x04000000 and 0x04001000, preserving other bits. |
| `func_02056e68` | 100 | Writes fourteen observed defaults to `data_021683c8`: five scalar words and nine vector components. Component meanings remain unproven; the layout is private. |
| `func_02056ecc` | 140 | Resets the first 184-byte geometry record at `data_0216846c`: signed extent pair at +0x08/+0x14, 0x1000 step at +0x1c, and the scale/bounds block at +0x84..+0xb6. `func_020572f8` indexes records with a 0xb8 stride, so the size is evidenced there rather than guessed. |
| `func_020572c0` | 24 | Calls `func_02056e68`, `func_02056ecc`, `func_02056f58`, then `func_020572d8` in order. |
| `func_020572d8` | 32 | Writes zero at `data_0215f05c + 0x10`, then signed -1 sentinels at +0x11 and +0x12. |

The entry bitfields reproduce the original shift-only extraction. Keeping the
borrowed entry pointer in the packet and deriving the queue base from the work
pointer reproduces the original register lifetimes without assembly.

Validation: direct instruction/relocation comparison, objdiff match gate, full
build/checksum, anticheat, and the existing Python test suite. No new tests are
required by this card; instruction matching provides the behavioral oracle.

## Hard list

### `func_02056f58` (872 bytes, still delinked)

Initializes the remaining eight 184-byte geometry records
(`data_021685dc`, `data_0216874c`, `data_021688bc`, `data_02168524`,
`data_02168694`, `data_02168804`, `data_02168a2c`, `data_02168974`) with two
families of ranges (`0x3000`/`-0x3000`/`-0x4000`/`0x4000`/`0x400000`/1/5/-5
versus `0xc0000`/`0x100000`/`0x800000`/10). The store order itself was
reproduced exactly from the target (including the one duplicate +0xb6 store),
but mwccarm 2.0/sp1p5 then materialises the repeated constants next to each
store and allocates the destination bases to `r2`/`sl`/`r9`, whereas the
original keeps the constants live from function entry in
`r8`/`r7`/`lr`/`r0`/`ip`/`r6`/`r5`/`r4`/`r3`/`fp` and uses `sl`/`r9`/`r2`/`r7`
for the eight destinations. The resulting body is 884 bytes and only one word
is identical.

Tried: assignments in target store order; natural field order; an `inline`
helper called eight times with the per-record values; explicit local constants
declared at entry; and `opt_propagation`, `opt_lifetimes`, `opt_common_subs`,
`opt_pulloutconstants`, `opt_repositioncode`, `opt_serializeassignments`,
`opt_scalarizeliveranges` and `opt_dead_assignments` toggles. None reproduce
the original constant hoisting/register allocation. A loop over the eight
destinations keeps the arrays on the stack and is smaller (756 bytes), so the
original is not a simple loop either. This needs a decomp.me scratch
(`tools/decompme.py`, platform `nds_arm9`) or a human with the original SDK
source. The definition is intentionally absent so the delink supplies the
function and the image stays correct.
