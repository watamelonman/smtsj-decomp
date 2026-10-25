# ImageBgDual3D

## M1-T535

- `ImageBgDual3D_Nop_1252f4` (`0x021252f4`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_1252f8` (`0x021252f8`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_1252fc` (`0x021252fc`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_125c3c` (`0x02125c3c`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_125c60` (`0x02125c60`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Nop_125c64` (`0x02125c64`, 4 bytes): immediate `BX LR`; reads no arguments and changes no state. The empty C body preserves this intentional no-op.
- `ImageBgDual3D_Thunk_021255b4` (`0x021257e8`, 12 bytes): `LDR IP` / `BX IP` through an absolute relocation to `func_021255b4`. The caller at `0x02125934` forwards borrowed work in R0; no return value is consumed.
- `ImageBgDual3D_Thunk_021177e0` (`0x021259ac`, 12 bytes): the same forwarding sequence, relocated to `Unk116598_Set` (`0x021177e0`); preserves its two opaque 32-bit arguments and void return contract.

The existing symbol names describe only behavior directly established by these instructions.
Matching is checked against the delinked object; this TU remains linked from the delink pending human completion.

## M1-T536

All eight functions match at 100% against the original ARM object.

- `ImageBgDual3D_Thunk_02117808` (`0x021259b8`, 12 bytes): absolute `LDR IP / BX IP` forwarding to `Unk116598_Reset`; no arguments or result.
- `ImageBgDual3D_Get_data_02176e94` (`0x021259f8`, 16 bytes): returns the global word unchanged. The caller at `0x021259e0` uses it as a non-null borrowed work address.
- `ImageBgDual3D_Unk_125a80` (`0x02125a80`, 16 bytes): calls `Unk095560_Unk_096130` then `Unk065e88_Unk_065eac`, both without arguments or consumed results. Their purpose remains unspecified.
- `ImageBgDual3D_Clear_data_02176e8c` (`0x02125300`, 20 bytes): stores zero in the named global word; its meaning is not inferred.
- `ImageBgDual3D_Call_02117360` (`0x02125984`, 20 bytes): forwards four words and an unsigned byte to `func_02117360`; the stack argument is explicitly loaded with `LDRB` and stored as a word for the call.
- `ImageBgDual3D_Call_02117400` (`0x02125998`, 20 bytes): the same argument contract, forwarding to `func_02117400`.
- `ImageBgDual3D_Unk_125afc` (`0x02125afc`, 20 bytes): calls `Unk116598_Unk_1177cc(0)` then `Unk116598_Unk_1172dc()`. The work argument supplied by `0x02125a90` is unused.
- `ImageBgDual3D_Unk_1259e0` (`0x021259e0`, 24 bytes): calls the global getter, writes one to the first work word, then calls `ImageBgDual3D_Unk_125a80`. No null check occurs in the original.

No hard functions remain in this card. Existing descriptive names reflect only observed loads, stores, or call destinations; neutral names retain unknown semantics.

## M1-T537

All eight functions match at 100% against the original ARM object. Neutral
names retain unknown semantics; the contracts below follow the original loads,
stores, comparisons and call relocations. No hard functions remain in this card.

- `ImageBgDual3D_Unk_125a68` (`0x02125a68`, 24 bytes): calls `ImageBgDual3D_AllocBuf`, `Unk065e88_Unk_065e88`, then `func_020773dc(1)`; no results consumed.
- `ImageBgDual3D_Unk_125ca4` (`0x02125ca4`, 24 bytes): returns the exact zero comparison of `ImageBgDual3D_Unk_12594c`, normalized to zero or one.
- `ImageBgDual3D_Unk_125cbc` (`0x02125cbc`, 24 bytes): returns the exact one comparison of the same helper, normalized to zero or one.
- `ImageBgDual3D_Unk_125d30` (`0x02125d30`, 24 bytes): calls `ImageBgDual3D_Unk_1258e8` only if `ImageBgDual3D_Unk_125cbc` is nonzero.
- `ImageBgDual3D_Unk_1259c4` (`0x021259c4`, 28 bytes): obtains the borrowed, non-null global work address; stores the argument at offset 4 and one at offset 0xc.
- `ImageBgDual3D_Unk_125c40` (`0x02125c40`, 32 bytes): calls `Unk116598_Unk_117790`, then `Unk116598_Unk_117294`, and stores the return word of `func_02125a08` in `data_02176e94`. No ownership inference is made.
- `ImageBgDual3D_Unk_125d10` (`0x02125d10`, 32 bytes): forwards its opaque word to `ImageBgDual3D_Unk_1258a0` only if `ImageBgDual3D_Unk_125cbc` is nonzero.
- `ImageBgDual3D_Unk_125650` (`0x02125650`, 40 bytes): passes the borrowed work's offset-0x8c word to `func_0205c408` with zero and then `func_0205c6e0`, and clears offset 0x208. Work must be non-null.

## M1-T538

All eight functions match at 100% against the original ARM object. The source
already contained matching implementations; this card verifies them and adds typed
contracts, readable record traversal, and explicit arguments previously carried in R0.
Neutral names preserve unknown semantics. No hard functions remain in this card.

- `ImageBgDual3D_Unk_1258e8` (`0x021258e8`, 40 bytes): checks the global handle with `func_02061698`, resolves it with `func_020616c0`, and forwards the borrowed result in R0 to `func_02061424`. Invalid handles cause an immediate return.
- `ImageBgDual3D_Unk_125618` (`0x02125618`, 56 bytes): reads a signed count at work offset 0x204 and checks bytes starting at offset 0xed with stride 0x5c. Returns zero at the first zero byte, otherwise one; nonpositive counts return one without reading records. Work must cover the indicated records.
- `ImageBgDual3D_Unk_12594c` (`0x0212594c`, 56 bytes): returns one when the global handle passes `func_02061698` and its resolved work has first word 5; returns zero otherwise.
- `ImageBgDual3D_Unk_125910` (`0x02125910`, 60 bytes): checks and resolves the global handle, forwards the work in R0 to `ImageBgDual3D_Thunk_021255b4`, then stores the opaque argument at offset 0x80 and zero at offset 0.
- `ImageBgDual3D_AllocBuf` (`0x02125c68`, 60 bytes): if `data_02176e98` is zero, calls `func_0205ba98` with size 0x28000, alignment 0x800, diagnostic string `data_02152180`, and line 22, then stores its result in the global. The existing allocator name is supported by this call and the paired release in 0x02125d48.
- `ImageBgDual3D_Unk_125cd4` (`0x02125cd4`, 60 bytes): forwards the opaque argument to `ImageBgDual3D_Unk_125910` when `ImageBgDual3D_Unk_125cbc` is nonzero; otherwise calls `func_021257f4` with the shared buffer, argument, and one.
- `ImageBgDual3D_Unk_125d48` (`0x02125d48`, 60 bytes): conditionally calls `ImageBgDual3D_Unk_1258e8` using the same predicate; then passes a nonzero shared buffer to `func_0205bb68` and clears the global. The original leaves the loaded buffer in R0 for the release call.
- `ImageBgDual3D_Unk_1252b4` (`0x021252b4`, 64 bytes): requires nonzero borrowed work word 2, unsigned work word 0 at most one, and a nonzero `Unk0bc1a8_IsSlotEmpty(0x24)` result before calling `Unk0bc1a8_Unk_0bc504(work, 0)`.

## M1-T539

All eight functions match at 100% against the original ARM object. Existing
implementations of 0x021258a0, 0x02125b10 and 0x02125a90 were verified and
their contracts documented; the other five implementations were added.
Neutral names retain unknown semantics. No hard functions remain in this card.

- `ImageBgDual3D_Unk_1258a0` (`0x021258a0`, 72 bytes): checks and resolves the global handle, passes its work word 0x8c and the argument to 0x0205c408, calls 0x0205c6e0 with that word, and sets work word 0x208 to one. Invalid handles return immediately.
- `ImageBgDual3D_Unk_125b10` (`0x02125b10`, 80 bytes): calls six teardown helpers, clears data_02176e94, forwards work word 8 to 0x02035440 only when signed work word 4 is three, then forwards word 4 to 0x0202cbdc. Work is borrowed and non-null.
- `func_02125738` (`0x02125738`, 88 bytes): only in work state 5, brackets 0x0205c748 with 0x02057524(0) and 0x02057534. The middle call receives mode 2, work word 0x8c, coordinates (0, 0), and trailing values (1.0, 1.0, 0, 1.0, 0).
- `func_02125790` (`0x02125790`, 88 bytes): the same state check and helper sequence, with coordinates (0, -256). Floating argument types describe the observed 0x3f800000 constants; no broader rendering semantics are assigned.
- `func_02125a08` (`0x02125a08`, 96 bytes): requests a 16-byte task from 0x020611dc with callbacks 0x02125b60, 0x02125c3c, null, and 0x02125b10, and trailing flags (0, 0, 1). Returns zero on failure; otherwise calls 0x02125a90 and returns the created address.
- `func_021255b4` (`0x021255b4`, 100 bytes): conditionally releases nonzero work words 0x8c, 0x84, and 0x88 through 0x0205c3dc, 0x0205ddb4, and 0x0205c368 respectively, clearing each. Unconditionally passes word 0x7c to 0x02053000 and clears it.
- `ImageBgDual3D_Unk_125a90` (`0x02125a90`, 108 bytes): calls 0x02077314 and 0x02125a68; if 0x02095b28(3) succeeds, calls setup helpers with (8, 3) and (8, 42, 0, -1), then 0x02095f94. Initializes work words 0, 4, 8, 12 to (0, 13, 1, 0) and calls 0x02125afc.
- `func_021257f4` (`0x021257f4`, 172 bytes): requests 0x20c bytes with callbacks 0x02125678, 0x02125738, 0x02125790, and 0x021257e8 and flags (0, 0, 1). Stores buffer/value at 0x90/0x80, publishes the handle through 0x020615ec, then returns for nonzero mode. Zero mode calls 0x02125314(work, 0), 0x021253c4(work, 0), and 0x02125650(work), then sets state 5. The caller consumes no result; using a void return reproduces the original conditional epilogue.

## M1-T540

All four functions match the original ARM instructions and relocations. Their
existing neutral symbols are retained because resource and state semantics are
only partly established. The earlier source is extended rather than recreated.

- `func_02125314` (`0x02125314`, 176 bytes): copies the 64-byte directory template at `data_0213cdd0` (`Data/Tex/Event/ED/`), normalizes it through 0x02015118, appends the indexed name from `data_02152148` and `.bin` at `data_02152170`, then calls 0x020513d4. Nonzero mode starts a request in work offset 4; zero mode stores the synchronous resource at offset 0x7c. Work is borrowed and its index must address the name table.
- `func_02125678` (`0x02125678`, 192 bytes): states 0 and 1 start loading and become state 2; state 2 polls the request and becomes 3 on zero; state 3 initializes records and becomes 4; state 4 waits for all record completion bytes, sets state 5 and calls 0x02125650. State 5 polls an active handle and clears offset 0x208 when complete. Out-of-range states do nothing.
- `func_02125b60` (`0x02125b60`, 220 bytes): state 0 polls 0x020961a0 and 0x02117834, advancing to 2 when work word 0xc is nonzero. State 1 requires three predicates before display setup, shared-buffer setup, state reset and 0x02117400(1, 1, 0, 0, 31). State 2 forwards the borrowed task to 0x02061424. Only its sixteen-byte prefix is used.
- `func_021253c4` (`0x021253c4`, 496 bytes): resolves an absent resource from the request, reads the entry count and consumes entries 0 and 1 as headers. Later entries populate records at offset 0x94 with stride 0x5c, copying a sixteen-byte descriptor, deriving dimensions and chaining coordinates from the shared buffer for the first four records. Formats paths with `%s_%02d` from `data_02152178`, then calls the mode-selected record helper. Finally registers all records and creates/attaches the final handle. The provider must supply storage covering every resource record; the observed work reserves four records. Descriptor aggregate assignment reproduces the original LDM/STM copy.

### Hard list

None for M1-T540.
