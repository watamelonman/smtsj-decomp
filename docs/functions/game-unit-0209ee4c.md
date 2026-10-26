# src/game/unit_0209ee4c.c

## M1-T766

All eight functions match at 100% objdiff. Evidence below is the target ARM
instruction sequence at the address encoded in each symbol (accessor: 0x0209eff8;
thunk: 0x0209f028; call wrappers: 0x0209f0c0 and 0x0209f534).
Existing symbol names are retained; unknown state transitions are not assigned
speculative gameplay meanings.

| Function | Contract and evidence |
| --- | --- |
| `Unk09ee4c_Thunk_02118c6c` | Tail-calls `func_02118c6c`; target loads its address into ip and branches through ip. No arguments. |
| `Unk09ee4c_Unk_0a03b8` | Returns `data_0213c190 + index * 24` as a target-width integer address; target literal and MLA establish base and stride. Index validity belongs to the caller. |
| `Unk09ee4c_Call_0204f1f8` | Adds unsigned byte d[1] to base, clamps a negative sum to zero, and forwards all four arguments. Target LDRB, ADDS and MOVMI establish this behavior. d requires two readable bytes. |
| `Unk09ee4c_Call_0204f68c` | Calls the helper with the address of object word +0x64 only if that word is nonzero. Object must be valid; helper can mutate the word. Target LDR, conditional return and ADD establish the contract. |
| `Unk09ee4c_Unk_09ef50` | If state exists, calls `ScanVisor_Unk_0a2ae8(arg0, 2)` then sets state +0x73e8 to 0x14. Target BL and STR provide the evidence. |
| `Unk09ee4c_GetField3c0Bits` | Returns bits 10..19 of state word +0x73c0, or zero without state. Target shifts left 12 then right 22 and narrows to u16. The typed local view records only this observed word. |
| `Unk09ee4c_Unk_09ee4c` | If state exists, clears +0x7400, sets root word +0x5c to 1, then sets state +0x73e8 to 0x12. Target stores establish the ordering; live state requires a valid root. |
| `Unk09ee4c_Unk_09ef80` | If state exists, calls `Unk11f2d0_Unk_11f308` on embedded object +0x7598 with arg0, then sets +0x73e8 to 0x15. Target address additions, BL and STR establish the behavior. |

### Hard list

None for M1-T766.

## M1-T767

All eight functions match at 100% in objdiff. Names remain neutral because the
instruction evidence establishes data flow without proving gameplay meaning.
Offsets below refer to borrowed storage; providers retain ownership.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk09ee4c_Unk_09efb4` | With live state, looks up the ID descriptor, invokes its first callback when present, then writes mode 22 and ID at +0x73e8/+0x73ec. Callback receives the ID. |
| `func_0209f298` | Adds signed record +0x192 to base, clamps negative results to zero, then calls `func_0204f364`. Either descriptor +16 bit 0 or bit 1 selects flag 1; otherwise flag 0. Target shifts establish the bitfield view. |
| `Unk09ee4c_Unk_09f5d8` | Rejects IDs whose bits 16..23 are not 2 with -1. Resolves ID, reads unsigned halfword +0x1d8, resolves that resource, and forwards its byte +3 with flag 0 to f550. |
| `Unk09ee4c_Unk_09fd14` | Clears ID slots then calls f034 four times with base 0, both IDs equal, flag 1 and consecutive 22-byte records. Caller supplies four valid records. |
| `func_0209f550` | Resolves entry or returns -1; submits four 22-byte records, calls f520 with base plus signed +0x192, calls a780 on the ID resource with 12, then returns signed +0x190. |
| `func_0209f034` | Rejects initial signed bytes 0/48 and a zero pattern-call result. Kinds 3/4/5 at unsigned +18 select the second ID; other kinds select the first. Adds signed +16 to base, clamps at zero, submits through f188 and returns the adjusted value. Record requires at least 20 readable bytes. |
| `func_0209f480` | Record +132 bits 14/15 enable submissions from words +112/+116. First uses kinds 21/1 and slot 0; second uses kinds 22/3, with base +4 and slot 1 if the first was enabled. All f24c calls pass final flag 1. |
| `func_0209ee80` | With live state, resolves index table entry and reads signed work coordinates +0x364/+0x365. Entry +16 equal to 1 enables direction adjustment: 0 decrements y, 1 increments x, 2 increments y, 3 decrements x. Stores index/coordinates at state +0x747c/+0x7482/+0x7483, calls visor helper with 2, then selects mode 19. |

The source bitfields preserve the target's shift-based extraction. Switch cases
preserve the observed comparison chain and direction jump table. Definition
ordering preserves local-call relocations for existing callers.

### Hard list

None for M1-T767. Validation: match gate, anticheat, nine tool tests and checksum.

## M1-T768

Three of the five card functions are now compiled from C and match at 100% objdiff.
Names stay neutral except where the argument/field flow is fully established by the
target instructions. Offsets refer to borrowed storage owned by the caller.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_0209f0d8` | Walks descriptor +8 entries (8-byte stride, value at +12, flag word at +16). Flags bit 5 selects kind 7 and bits 4..5 select kind 8; descriptor +132 low byte is the default kind, with bit 22 changing kind 5 to 6. Kinds 6/7/8 submit through f650 and f24c with kinds 21/22/8 and slot = entry index; base advances 20 per entry. After the loop, +100 is submitted through f6d8 and, when equal to 1, f158 is called with 60/12 and `func_0204aa18(func_02044ec4(id))`. |
| `func_0209f2e0` | Increments the resource byte at +478 and dispatches the indexed 8-byte entry from descriptor +12. Entry bit 2 submits kind 4; otherwise descriptor +132 kind 3/8/9 selects the f59c/f5e0/f618 path and entry bits 0/1 submit kinds 5/7. Returns 1 except for the bit-2 early return. |
| `func_020a02c0` | Checks `func_020f8098(work, 3, id)` and the force flag first. When unblocked, global +64 bit 19 selects f5d8; otherwise global +64 bit 12 plus an ID whose bits 16..23 are 2 selects f550. The final f3a4 call uses the submitted result, and the blocked path calls func_020449c4. |

Evidence for the matched functions is the target instruction sequence at each
symbol: f0d8 begins at 0x0209f0d8, f2e0 at 0x0209f2e0, a02c0 at 0x020a02c0.

### Hard list

- `func_0209fd64` (0x0209fd64, 1372 bytes): reconstructing the record-block, node-list,
  and pair-table paths in C reaches 87.73% objdiff. The remaining mismatches are
  compiler register allocation (records/id/node-id/base against r4..r9) and the
  address form of the +0x160 entry byte loop; the control flow and called helpers
  agree. A human should open a decomp.me scratch with the target.
- `func_0209f624` (0x0209f624, 1776 bytes): the Ghidra decompilation of this function
  stops at the jump-table switch around 0x0209f8c0, so the switch bodies could not be
  reconstructed reliably. No C definition was added; the target stays linked from the
  delink object.

Both hard functions still link from the delink object, so the full build and checksum
are unaffected.
