# game/unit_020ddeb0

M1-T346 and M1-T347: all eleven functions match at 100% with the configured
ARM compiler. Evidence below refers to the original delinked ARM instructions.
Opaque names are retained because the instruction sequences establish behavior,
but do not establish domain-specific meanings.

| Function | Contract and evidence |
| --- | --- |
| `Unk0ddeb0_Unk_0ddeb0` | Borrows an object pointer, builds a 16-byte stack descriptor through `func_02060dd4`, and passes it synchronously to `func_02059f70` with the object's first word and forwarded arguments. Original uses sp+12 for the descriptor and reserves 28 stack bytes. |
| `Unk0ddeb0_Unk_0ddf0c` | Passes an address of a zero halfword to `func_02061f10`, together with index -1 and two zero arguments. Evidence: `strh`, subtraction producing -1, and five call arguments. |
| `func_020ddf38` | Takes a signed phase, computes remainder modulo 60, and returns a byte: remainder/2+1 below 30, otherwise 30-remainder/2. Division truncates toward zero, including for negative input. Evidence: reciprocal multiply, signed quotient correction, comparison against 30, and byte mask. |
| `func_020ddf7c` | Takes a signed phase modulo 80; computes `(40-r)*3072` for r<=40 or `(r-40)*3072` otherwise, arithmetic-shifts by 12, converts to byte, then clamps to 1..30. The byte conversion precedes clamping, including for negative inputs. Evidence: reciprocal multiply, comparison against 40, shift by 10 after multiplying by three, shift by 12, byte mask, unsigned upper clamp. Caller evidence: `CampStatus.c` passes its phase field before `func_02057e18`. |
| `Unk0ddeb0_Unk_0ddfd8` | Reads an unsigned byte at an unchecked signed index into `data_0213c640`; callers must supply a valid index. Evidence: relocation to that table and register-indexed `ldrb`. |
| `Unk0ddeb0_Unk_0ddfe8` | Clamps a signed index to 0..14, resolves resource 15 entry 0, and returns the indexed word. Evidence: signed lower/upper comparisons, call immediates, and scaled word load. |
| `Unk0ddeb0_GetRes15Word0` | Returns word 0 of resource 15 entry 1. Name supported by call immediates 15 and 1 and final load at offset 0. |
| `Unk0ddeb0_GetRes15Word1` | Returns word 1 of resource 15 entry 1. Name supported by call immediates 15 and 1 and final load at offset 4. |

The temporary descriptor and halfword pointers are valid for the duration of their
calls. Resource accessors assume the external resolver returns valid word storage.
No module boundary changes are introduced.

## M1-T347 calculations

Names remain neutral because the arithmetic and callers do not establish a domain
meaning for the returned value. Arithmetic below uses unsigned 32-bit products
with wrapping before division. Every result is capped at 99,999,999.

| Function | Contract and evidence |
| --- | --- |
| `func_020de04c` | Takes a record ID; returns zero if `Unk02e000_SetRecord` fails. Otherwise sums record bytes 1..5, reads metadata coefficient at 44, and scans six record halfwords at 16 against six metadata halfwords at 46. The largest byte at offset 3 of `func_020e6874(entry)` among nonzero entries absent from metadata selects resource 15 entry 0. Computes `scale * (multiplier * (base + (extra + coefficient * sum * sum * sum / 1000))) / 200`. Evidence: original byte/halfword offsets, exclusion branches, resolver calls, and reciprocal multiplication constants. |
| `func_020de194` | Takes a record ID; returns zero on failed record resolution. Uses the sum of metadata bytes 26..30 and coefficient at 44, without the six-entry adjustment: `scale * (multiplier * (base + coefficient * sum * sum * sum / 1000)) / 200`. Evidence: five byte loads, coefficient halfword load, and reciprocal division sequences. |
| `func_020de258` | Takes a record ID and a borrowed, valid 36-byte record pointer. Uses the same formula and exclusion scan as `func_020de04c`, obtaining metadata through the ID and reading record fields directly from the second argument. Evidence: original preserves r1 as the record pointer and scans the same offsets. |

For all three functions, `scale` and `base` are resource 15 entry 1 words 0 and 1.
The multiplier is 1 when the low seven bits of record byte 30 are at least 100,
and 2 otherwise. The bitfield view preserves the original shift extraction.
Metadata and entry resolvers must return valid borrowed storage. Local views
express only observed offsets; no new module boundary is introduced.

## Hard list

None. All three M1-T347 functions match at 100%.
