# game/unit_020e6a0c — M1-T480

The eight functions retain their existing neutral `func_` symbols because the
resource and selector semantics are not established. Layouts are local borrowed
views, inferred solely from the original loads/stores; padding is not a claim
about the complete record. No module boundary changes are introduced.

| Function | Bytes | Contract and assembly evidence |
| --- | ---: | --- |
| `func_020e6a0c` | 28 | Resolves resource `(33, 3)` through `020445d0` and `0204fde0`, returning its first word. Resolver output must be nonnull. |
| `func_020e6a28` | 556 | Negative index selects the default record; otherwise resolves an indexed record. Null indexed records or states 1/7 return 1. Selectors 81–85 increment signed bytes up to 99, touching one default field or both corresponding indexed fields. Returns 1 when any selected field is already capped, otherwise 0; invokes the respective refresh helper after recognized selectors. Other selectors return 1 without refreshing. Offsets and cap are evidenced by `ldrsb`, `cmp #99`, and `strblt`. |
| `func_020e6c54` | 400 | Negative index selects the default record; a missing indexed record returns 1. With mode zero, selectors 61/62 roll `02050074(0,99)` and act below 25. Selector 61 checks the signed low state byte and six IDs, rejecting lookup flag bit six, then writes state 3; selector 62 halves a signed halfword toward zero. The common exit returns 0 for mode zero, including failed rolls, and 1 otherwise. |
| `func_020e6de4` | 60 | Nonnull entry: returns halfword +0x24 when nonzero; otherwise returns signed `base * byte(+0x28) / 100`, or zero for a zero percentage. Caller must keep the multiplication within signed range. |
| `func_020e6e20` | 60 | Same contract using halfword +0x26 and percentage byte +0x29. The original signed multiply-high division establishes truncation toward zero. |
| `func_020e6e5c` | 96 | Filters a nonzero value against seven low bits of +0x2a. Zero selector/value returns -1. Selector 12 accepts values other than 1; 13 accepts 2/8; 14 accepts any nonzero value; remaining selectors require equality. Nonnull entry required. |
| `func_020e7194` | 164 | Resolves the entry, returning 1 if absent. Tests record -1 and all nonnegative signed IDs among twelve bytes at work-area +0x348. Any zero test result returns 0 and calls `02099b10(index,1)` unless +0x2f bit zero is set. No successful test returns 1. |
| `func_020e7238` | 88 | Resolves an entry and returns 1 if absent; otherwise returns `020e6ebc(record,entry)`. A zero result marks the entry via `02099b10` unless +0x2f bit zero is set. |

All eight pass standalone instruction/relocation comparison. Packed bitfields
reproduce the original shift-based extraction. Separate state-test branches and
an early switch break reproduce the 400-byte function's control flow and register
reuse without compiler overrides.

## Hard list

None.
