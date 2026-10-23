# game/unit_020f077c

All five functions match at 100% in objdiff. Evidence is the ARM instruction
stream at 0x020f077c–0x020f09b4; existing symbol names are retained because the
application-level purpose is not established.

- `func_020f077c`: fills a descriptor with work size 0xf4, kind 4 and five
  callbacks, clears callback +0x18, and preserves the caller's field at +8.
  The callback addresses are directly visible in the original literal pool.
- `Unk0f077c_Unk_0f07d4`: clears the caller-owned 0xf4-byte work block through
  `func_02008848`, stores its pointer in `data_02176dfc`, then invokes setup.
- `func_020f0800`: sets work +0x40 to 28 and +0x4c to 1, registers work
  callbacks with `func_020f711c` (including signed argument -128), initializes
  the embedded list at +0x50 and registers its +0xa0/+0x9c callbacks.
  The embedded storage extends through the end of the observed 0xf4-byte work
  allocation; no internal list layout is inferred here.
- `Unk0f077c_Nop_0f08dc`: empty callback, evidenced by the single `bx lr`.
  Accepts the same work pointer as the other descriptor callbacks and ignores it.
- `func_020f08e0`: calls common work handling, then dispatches on work +8.
  State 11 forwards work +0x40 and zero to `Unk0bc1a8_Unk_0bc9b4`.
  State 2 invokes the +0x40 helper, then chooses id 28, 29 or 27 using the
  two external predicates; ids 28 and 27 also issue value 4 to the external
  helper. State 9 resets the embedded list and writes state 10. All other
  states have no additional action.

## Validation

The build and objdiff gate verify all five definitions against the delinked
original. This unit remains linked from the original delink until a human marks
it complete, as required by the card.

## Hard list

None.
