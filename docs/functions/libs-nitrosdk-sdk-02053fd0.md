# sdk_02053fd0

The existing neutral linker names are retained. The instruction stream establishes
upload state and region construction, but does not establish original API names.
No symbol configuration or delink completion flags were changed.

Known-source search: checked the public NitroSystem source used by pokeplatinum
([upstream](https://github.com/ntrtwl/NitroSystem), pokeplatinum's pinned revision
21c8fd078fdda34f3c2622ef0751d00adaacf890). No matching implementation was identified;
these bodies were reconstructed from the original ARM instructions.

The private types describe only instruction-observed layouts. The provider owns
the state, staging buffer and record array. Region descriptions and record
initialization destinations are caller-owned. All functions use existing SDK
providers and add no module dependency or ownership transfer.

| Function | Contract and evidence | Status |
| --- | --- | --- |
| `func_02053fd0` | Resets staging, stores the signed mode at state +4, and calls the setup provider except for sentinel 8. BL/STR/CMP sequence at 0x02053fd8–0x02053ff0. | 100% |
| `func_02053ffc` | For modes other than 8, flushes 512 bytes at 0x0212cc60 and selects the main/sub palette provider according to signed mode / 4. | Hard; original delink retained |
| `func_02054058` | Requires the dirty halfword and mode != 8; dispatches the palette helper, transfers 0x13c0 bytes from 0x0212ce60, then uploads staging. Guards and three BLs at 0x02054060–0x02054090. | 100% |
| `func_020540a0` | Clears 1536 bytes at data_02160820 and sets state halfword +0 to one. Fill arguments and STRH at 0x020540a4–0x020540bc. | 100% |
| `func_020540cc` | When dirty and mode != 8, uploads 1536 staging bytes and clears the halfword. Guard, BL and STRH at 0x020540d4–0x020540fc. | 100% |
| `func_0205410c` | Returns borrowed data_02160e20 + index * 40, with no bounds check. MLA at 0x02054114; caller must supply a valid index. | 100% |
| `func_02054120` | Clears a caller-owned 40-byte record and stores the supplied first word. Fill and STR at 0x02054134–0x02054138. | 100% |
| `func_02054140` | Builds up to two offset/size pairs in KiB. Selector zero uses bank masks 0x70 and 0x0f; other selectors use 0x184. Each bit adds the original 16/32/64/128 units. Destination needs a count and two pairs; branch-local indexed stores establish the layout. | 100% |

## Hard list

- `func_02053ffc` (92 bytes): the candidate had the correct size and control
  flow, but objdiff reported 92.35%. After the flush call, the original loads
  the source address into r0 before computing mode / 4 in r1; the candidate
  computes the quotient in r0 and loads the source later. Tried explicit
  temporaries, nested guards, switches, early returns and inline transfer
  wrappers with different argument orders. None matched the register allocation.
  The candidate body was removed, leaving a typed external declaration and the
  original delink implementation. A human can open a scratch with
  `tools/decompme.py` for further compiler investigation.

Validation uses compiler/objdiff comparisons against original instruction bytes;
this card requires no new runtime tests. The TU remains linked from the original
delink until a human marks it complete.
