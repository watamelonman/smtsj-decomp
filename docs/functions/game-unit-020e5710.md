# game/unit_020e5710

The names remain neutral: table fields suggest selection behavior, but their game-level
meaning is not established. All object/table views are borrowed; no allocation ownership
is transferred. This unit remains delink-backed until a human marks it complete.

| Function | Status | Behavior and evidence |
| --- | --- | --- |
| `func_020e5710` | 100% | Scans six halfword IDs through `func_020e6874`; tests bits 4..5 of byte +4 and returns whether any qualify. Zero IDs are looked up too. |
| `func_020e5750` | 100% | Uses `func_020e679c` and mode/flag 131 to choose five weights at +1, +6, or +11. Accumulates byte weights against random bounds (1,99), then adjusts the input byte by -2, -1, 0, +1, or +2; subtraction is guarded and addition wraps. |
| `func_020e582c` | 100% | Requires a positive attempt count and bit 0x706. Reads work ID +0x36 and six IDs +0x28. For eligible inputs, tests signed record value /25 plus low seven bits of record word +0x24. Flag 133 forces success; flag 188 scales the unsigned chance by 150/100. |
| `func_020e5924` | 100% | Builds a six-byte signed slot list from nonzero IDs whose record byte +4 has bits 4..5 set. Returns -1 for no slots, the sole slot directly, or a random slot using bounds (1,count-1). |
| `func_020e59c8` | Original retained; hard | Scans six-byte entries for an adjusted byte +3 and nonzero bits 6..7 at +4. Builds variable-length halfword candidate arrays. Flag 134 prefers candidates sharing byte +2 with the selected input and absent from the six IDs. Otherwise searches cyclically from a random candidate for an absent ID. |

## Hard list

- `func_020e59c8` (752 bytes): implemented both table passes, variable-length arrays,
  same-group filtering, and cyclic fallback. The C candidate compiled to 744 bytes;
  register allocation spills the adjusted rank rather than the candidate-fill counter,
  producing different loads/stores and array setup. Tried declaration orders, explicit
  byte bitfields, delayed initialization, wider rank/group locals, and VLA initialization
  placement. No candidate matched, so its definition is omitted and the original delinked
  function remains in use. A human can use `tools/decompme.py` for a scratch.

Validation: standalone instruction comparisons and the real objdiff match gate report
100% for the four implemented functions. No new behavioral tests are required by this card;
matching the original instruction stream is the acceptance oracle.
