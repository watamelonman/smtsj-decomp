# src/game/unit_020bc1a8.c

## M1-T545

These ARM functions retain the existing C bodies. Evidence is the corresponding
function in `build/delinks/src/game/unit_020bc1a8.o`; offsets below are bytes.
Pointers are borrowed and non-null unless null behavior is specified.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bc1a8_GetConst0` | 8 | At 020bc420, returns constant zero. |
| `Unk0bc1a8_Unk_0bc504` | 16 | At 020bc504, forwards the payload address and mode to 0bc514 with a zero request argument, via an indirect tail call. The address is represented as a 32-bit DS word. |
| `Unk0bc1a8_GetHeaderWord` | 20 | At 020bc598, reads the aligned header word at payload -8, or returns 0xffff for null. |
| `Unk0bc1a8_GetHeaderWord4` | 20 | At 020bc5ac, reads the aligned header word at payload -4, or returns 0xffff for null. |
| `Unk0bc1a8_SetPrevWord` | 20 | At 020bc5c0, writes the aligned header word at payload -4 and returns 1; null returns 0 without writing. |
| `Unk0bc1a8_Unk_0bc6d4` | 20 | At 020bc6d4, writes the word at context +4 through data_02176ba8. Requires initialized context. |
| `Unk0bc1a8_Unk_0bc6e8` | 20 | At 020bc6e8, reads that same context word. Requires initialized context. |
| `Unk0bc1a8_Unk_0bc4e0` | 36 | At 020bc4e0, calls 0bcc34 with the object base, then invokes the optional function pointer at +28 with payload base +52. Requires a live object; callback may be null. |

Neutral names remain because the instructions establish operations but do not
establish the application meaning of the context word or callback.

Validation: all eight functions report 100% in objdiff. The match build,
checksum (all artifacts byte-identical), anticheat, and nine tool tests pass.
No new tests are required by this card; objdiff checks the original instructions.

## M1-T546

Evidence is the original ARM instructions in
`build/delinks/src/game/unit_020bc1a8.o`; all offsets below are bytes.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bc1a8_SetFlag4Inv` | 40 | 020bc548: nonzero mode clears mask 4 in payload -12; zero sets it. Null is ignored; other payloads require an aligned writable header. |
| `Unk0bc1a8_SetFlag1Inv` | 40 | 020bc570: same operation with mask 1. |
| `Unk0bc1a8_Unk_0bc514` | 52 | 020bc514: calls 02061424 on payload -52; nonzero mode then passes header -4 and the request word to 0bcacc. Payload is a live DS address. |
| `Unk0bc1a8_IsSlotEmpty` | 56 | 020bc650: signed index >=41 returns 1, otherwise tests the slot object against null. Other indices must address the initialized table. |
| `func_020bc614` | 60 | 020bc614: scans 41 twelve-byte slots and copies object +40 to +36 when occupied. Context is reloaded each iteration; see DEC-010. |
| `Unk0bc1a8_Unk_0bc5d4` | 64 | 020bc5d4: if context is absent, allocates eight bytes, installs data_0215034c as the table and sets the second word to 1. |
| `Unk0bc1a8_Unk_0bc9b4` | 64 | 020bc9b4: builds a borrowed 72-byte stack request through 0bc8c8 with mode 1; on success forwards it and the slot to 0bc770. |
| `Unk0bc1a8_Unk_0bcc34` | 72 | 020bcc34: scans 41 slots, clears the first object address equal to the supplied DS address, returns 1 on finding it and 0 otherwise. Requires initialized context. |

Seven existing bodies already matched and retain their instruction sequences.
The new loop initially allowed the compiler to hoist the context load; preserving
that observed read with volatile gives identical instructions (DEC-010).
All eight requested functions report 100%. No M1-T546 hard functions remain.
No new tests: the card waives them and objdiff verifies the original instructions.

## M1-T547

Evidence is the original ARM instructions in
`build/delinks/src/game/unit_020bc1a8.o`. All eight functions match at 100%.
The existing source was extended rather than recreated, preserving earlier cards.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bc1a8_IsSlotEmptyOrFlag8` | 76 | 020bc688: signed index >=41, an empty slot, or mask 8 at object +36 returns 1. Other indices require initialized context and a valid slot. |
| `Unk0bc1a8_Unk_0bc490` | 80 | 020bc490: invokes callback +24 on payload +52 unless absent or mask 1 at +36 is set; brackets the call with mode-2 helpers and 0580ec toggles. Requires a live object. |
| `func_020bc1a8` | 88 | 020bc1a8: requires 03fa28 success, clear state bit 3 at +64, zero state +92 and zero 04a968 result for state +140. State returned by 044904 is borrowed. |
| `func_020bc8c8` | 96 | 020bc8c8: initializes a 72-byte request; signed slots below 41 succeed. Other slots fail, with an optional callback at data_02176ba8 +4 for slot 0xfffe and mode 3. Source is a DS address of a 68-byte payload or zero. |
| `func_020bc3bc` | 100 | 020bc3bc: invokes callback +16 when masks 4/16 at +36 are clear and context mode is nonzero; then invokes callback +12 when mask 2 is clear. Both callbacks are optional and borrow payload +52. |
| `func_020bc428` | 104 | 020bc428: invokes callback +20 unless absent or mask 1 is set; brackets it with mode-2 calls and toggles conditioned on 0bc420. Requires a live object. |
| `func_020bcbc4` | 112 | 020bcbc4: builds a mode-4 request; missing source sets first presence bit and word 0xffff, then dispatches through 0bc770. The 72-byte stack request is borrowed only during calls. |
| `func_020bc6fc` | 116 | 020bc6fc: stores mode, then copies a 68-byte source payload or clears two flag bytes and sixteen words. Destination requires word alignment and 72 writable bytes; padding at +6/+7 is left untouched for null source. |

Internal layout types express only observed fields. Word alignment of the stack
request and reading flags before storing a payload word preserve the original
access sequence. Application meanings remain unknown, so existing neutral names
are retained. No new tests are required by the card; objdiff checks instruction
identity. No M1-T547 hard functions remain.

## M1-T548

All seven functions report 100% in objdiff. The existing source was extended,
preserving previous cards. Evidence is the original ARM instructions in
`build/delinks/src/game/unit_020bc1a8.o`; offsets are bytes.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bc1a8_Unk_0bc928` | 140 | Builds mode 0, creates the slot object, sets header +36 mask 4, clears +40 low four bits, stores value at +48 and dispatches the request. Source is a borrowed payload DS address or zero; fourth argument is unused. |
| `func_020bc770` | 164 | Slot 0xfffe invokes the optional global callback; signed slots 0..40 dispatch object callback +32 with payload +52 and request. Returns 0 for invalid, empty or callback-free slots, otherwise 1. Request is borrowed. |
| `func_020bc814` | 180 | Validates signed slot 0..40, clears a 36-byte descriptor, invokes slot +4 to fill it, creates an object and stores its slot/value at +44/+48. Optional slot +8 receives payload +52. Requires successful allocation; returns payload or null for invalid/unconfigured slot. |
| `func_020bc2fc` | 192 | Selects wrappers according to descriptor callbacks +12/+16, +20 and +24; allocates descriptor size +52, copies 36 bytes and clears header +36..51. Descriptor is borrowed; null allocation returns null. |
| `func_020bc9f4` | 216 | Builds mode 2; optional first payload word updates object +48 except sentinel 0xfffb. Sentinel 0xfffc instead selects +40 mask 24, otherwise mask 12; then dispatches. Requires a live slot object. |
| `func_020bcacc` | 248 | Builds mode 3; ignores empty slots, clears +40 mask 24 for first-word sentinel 0xfffc, otherwise mask 15. Missing source supplies presence bit 0 and first word 0xffff, then dispatches. |
| `func_020bc200` | 252 | Resolves a record and category from metadata +36 bits 21..27. Requires a nonzero work halfword at +902 + category*2, excludes categories 12/13, nonzero 04a968/record flag, record +642 bits 1/2 and registered IDs. Requires record mode-2 value below state +140 mode-2 value. State/work/record views are borrowed. |

The descriptor and flag views encode only observed storage. Neutral names remain
because the application meaning of these operations is not established. Local
callee placement preserves original relocation matching (DEC-011). No boundary
changes or new dependencies. No new tests are required by the card; objdiff
checks every instruction against the original.

Hard list: none.
