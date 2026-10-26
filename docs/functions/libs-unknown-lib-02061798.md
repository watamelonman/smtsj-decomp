# libs/unknown/lib_02061798

Fifty-five functions of this TU are reconstructed from the original ARM
instructions and match at 100%: seven from M2-T1057, eight from M2-T1058,
eight from M2-T1059, the eight covered by M2-T1060, the eight covered by
M2-T1061, the eight covered by M2-T1062 and the eight covered by M2-T1063.
`func_02062264` is the exception: it is a four-byte copy of the preceding
function's unreachable epilogue and cannot be expressed as a standalone C
function (see Hard list).

All names remain neutral linker symbols: the surrounding records and the
public SDK sources found below do not establish an application-level API name.
Addresses below are call-site addresses from `config/arm9/relocs.txt` and are
labelled as such; they are not function start addresses.

## Source investigation

Searched the public NitroSystem reconstruction
([ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem)) for the font and
text-canvas code around `g2d_Font.c`, `g2d_TextCanvas.c` and
`g2d_CharCanvas.c`. No implementation with this 56-byte four-entry font
registry, its `+0x28` / `+0x30` / `+0x34` / `+0x48` / `+0x81` render-object
fields, or the `data_0216b5a0` / `data_0216b9a8` text globals was found. The
same source area covers the eight M2-T1060 helpers (singleton state
predicates, allocation wrappers and bit-word updates), the eight M2-T1061
helpers (state predicates, a glyph-advance multiply and singleton/state
setters), and the eight M2-T1062 helpers (a font-table index, a render-object
countdown, message/singleton state setters and release/state helpers); no
public implementation was identified for them either. The code is therefore
reconstructed from the instructions and keeps the neutral symbols.

The C declares only the fields observed in the instructions. Unrelated bytes
in the caller's objects stay in `pad_*` arrays; no SDK struct layout is
claimed. `func_02063a44` and `func_02063a60` return two different globals, so
the header uses two distinct opaque types, `Unk061798ResultA` and
`Unk061798ResultB`. The pointer at font-record `+0x28` is typed as an opaque
`Unk061798FontData *` because callers dereference it (call site `0x020601f4`).
`func_02063584` takes `s8` because `func_0206358c` forwards the signed byte at
`+0x81` and the original emits `ldrsb`. M2-T1059 added the object words at
`+0x4`, `+0x8`, `+0xc`, `+0x10`, the signed byte at `+0x68`, and the word at
`+0x1c` of `Unk061798ResultB`; the padding around them keeps every earlier
offset unchanged. M2-T1061 added the signed byte at `+0x35` and the words at
`+0x38` and `+0x44` of `Unk061798Object`, appended the `+0x58`/`+0x60`/`+0x64`
words to `Unk061798ResultB`, and typed its `+0` word as the render-object
pointer that `func_0206557c` forwards to `func_02062a3c`. M2-T1062 typed the
`+4` word of `Unk061798ResultB` as a second render-object pointer and added
its `+0x50` word, gave `Unk061798Font` the `+0x2c` table pointer and the signed
`+0x34` count, and added byte `+0x90` to `Unk061798Object`. M2-T1063 added the
`+0x14`, `+0x24`, `+0x2c` and `+0x3c` words of `Unk061798Object`, the `+0x28` and
`+0x4c` words of `Unk061798ResultB`, the four-entry `data_0216b4c0` font
registry, and the `data_0216b5a0`/`data_0216b5a8` text-buffer descriptor. The
descriptor is typed as an 8-byte pointer/length pair because `data_0216b5a8`
follows it in bss and the initialiser points the first word at that buffer.

## func_02061798 — 48 bytes

Initialises the four-entry font registry at `data_0216b4c0` by storing -1 in
the id word at `+0x20` of every 56-byte entry, marking all slots free for
`func_020618cc`. The target keeps an indexed `mla` loop (`mla r1, ip, r0, r2`
with 56 in r0) rather than a strength-reduced pointer walk, so
`opt_strength_reduction` and `opt_rotateloops` are scoped off around this
function. Its only direct caller is `0x0202cc0c`. Objdiff: 100%.

## func_0206190c — 16 bytes

Calls `func_020618cc(id)` and returns the pointer at `+0x28` of the selected
font record. Callers dereference the result (call sites `0x0205f810`,
`0x0205fd24`, `0x02060124`, `0x020601f0`; the last reads field `+0x10` of the
result). Objdiff: 100%.

## func_0206191c — 12 bytes

Tail wrapper for `func_020618cc`. Takes the font id passed by callers in r0
(call sites `0x02060210`, `0x020608a0`, `0x02062118`) and returns the selected
56-byte font record; its glyph table starts at +0 and callers read it with
`ldrh` at +0 and at `+2*index`. Objdiff: 100%.

## func_02061928 — 40 bytes

Calls `func_020618cc(id)` and returns a pointer to entry `index-1` of the
4-byte table at `+0x2c` of the selected font record. The signed count at
`+0x34` clamps an index at or above it to entry 0; the original emits
`sub r4, r4, #1; cmp r4, r1; movge r4, #0` and keeps the index in r4 across
the call, which the pre-declared local reproduces. The only caller
`0x02061b3c` reads bytes `+2`/`+3` of the returned entry. Objdiff: 100%.

## func_02061950 — 16 bytes

Calls `func_020618cc(id)` and returns a pointer to the first header byte at
`+0x24` of the selected record. The only direct callers are `func_02061960`
and `func_02061970` (relocations at `0x02061964` and `0x02061974`). Objdiff:
100%.

## func_02061960 — 16 bytes

Returns the first header byte (`+0x24`) of the font record selected by the id
in r0; it forwards through `func_02061950` before the `ldrb`. Call sites
include `0x02060c54` and `0x02060e50`. Objdiff: 100%.

## func_02061970 — 16 bytes

Returns the second header byte (`+0x25`) of the font record selected by the id
in r0; it forwards through `func_02061950` before the `ldrb` at offset 1.
Callers use the byte as part of a glyph advance (call site `0x02061b9c`).
Objdiff: 100%.

## func_020619f8 — 12 bytes

Tail wrapper for `func_02061970`, with the font id passed in r0 (call site
`0x02061b9c`). Objdiff: 100%.

## func_02061e98 — 28 bytes

Sets or clears bits of `mask` in the object's `+0x4` word. The original
compares the third argument with 1 (`cmp r2, #1`), ORs on equality and
otherwise ANDs the loaded word with the complement of `mask`. Call sites
`0x020605c0`/`0x020605cc` pass 0 and 1 in r2; `0x0206699c`, `0x020d5594` and
`0x0211d5d0` are further callers. Objdiff: 100%.

## func_02061eb4 — 20 bytes

Tests whether any bit of the mask in r1 is set in the object's `+0x4` word and
returns 0/1; call sites `0x020605a8`, `0x020625a8` and `0x020632e4` branch on
the result. The original emits `tst; movne #1; moveq #0`. Objdiff: 100%.

## func_0206232c — 36 bytes

Reads the font id at `+0x28`, calls `func_02061960` for that record's first
header byte, adds the signed byte at `+0x35` (`ldrsb`), and multiplies the sum
by the 32-bit second argument. The original saves the multiplier in r4 across
the `func_02061960` call. Call sites `0x020603b8` and `0x02065240`. Objdiff:
100%.

## func_020629ac — 24 bytes

Wrapper around `func_02060a48`. Callers set all four argument registers before
calling it (call sites `0x02065f54`, `0x0206683c`, `0x02066940`, `0x0209938c`,
`0x0211d5c0`), and the original moves r3 into r2 before the call, so the
wrapper forwards its first, second and fourth arguments and drops the third.
It returns the allocated record, or 0 when `func_02060a48` returned 0; the
explicit null test reproduces the original `cmp; moveq r0, #0` rather than a
tail call. Objdiff: 100%.

## func_02062a00 — 44 bytes

Releases the object's `+0x14` slot through `Unk0d297c_FreeSlot`, but only when
the slot pointer is non-null and the state word at `+0xc` is 1 or 3. The
original loads `+0x14` first, then tests `+0xc` with `cmp #1; cmpne #3` and a
`popne`; the address it passes is `object + 0x14`. Call sites include
`0x02061f4c`, `0x020629f0`, `0x020633fc`, the two `func_02065b74` calls at
`0x02065b88`/`0x02065b90` and `0x020d1b44`. Objdiff: 100%.

## func_02062a2c — 16 bytes

Reads the font id at `+0x28` of a render object and tail-calls
`func_0206190c` with it, returning the selected record's `+0x28` pointer. Call
sites `0x02060614`, `0x02060a38` and `0x020620a8` dereference the result.
Objdiff: 100%.

## func_02062a3c — 32 bytes

Returns 0 when the object's `+0x10` word is 0 or 1, and 1 otherwise. The
original tests both values with `cmp #0; cmpne #1` and branches to separate
0/1 return blocks, so the C uses a switch with the two accepted values.
Call sites `0x02063c48`, `0x02063d10`, `0x020651bc` and `0x02065594` (the last
is `func_0206557c`). Objdiff: 100%.

## func_02062a5c — 24 bytes

Loads the object's `+0x10` word and returns 1 when it is 2 or 3, else 0. Call
site `0x02064224` returns early when the result is zero. Writing the test as
`value != 2 && value != 3` keeps the original `cmp #2; cmpne #3` pair with the
predicated `movne r0, #0; moveq r0, #1`; the positive `==` form swapped the
two moves. Objdiff: 100%.

## func_02062a74 — 20 bytes

Returns 1 when the object's `+0x10` word is zero, else 0 (`ldr; cmp #0;
moveq #1; movne #0`). Call site `0x02060b94` returns from its caller when the
result is non-zero; the other call sites are `0x02063c10` and `0x02064128`.
Objdiff: 100%.

## func_02063490 — 16 bytes

Clears the two halfwords at `+0x4e` and `+0x4c` of a render object, in that
store order. Call site `0x02063418` does this while resetting the object's
text state. Objdiff: 100%.

## func_0206357c — 8 bytes

Takes a render-object pointer and a 32-bit value; stores the value at +0x30.
Callers pass a glyph/record value before advancing text (call sites
`0x02060318`, `0x02060550`, `0x02060654`). Objdiff: 100%.

## func_02063584 — 8 bytes

Takes a render-object pointer and a signed byte; stores the byte at +0x34.
Callers use it for a mode 0/1/2 and for the active count (call sites
`0x02062634`, `0x02063640`, `0x020636e4`). Objdiff: 100%.

## func_0206358c — 16 bytes

Loads the signed byte at `+0x81` of a render object and tail-calls
`func_02063584` to store it at `+0x34` (call sites `0x0206255c`,
`0x0206258c`, `0x020636b8`). Objdiff: 100%.

## func_0206359c — 8 bytes

Takes a render-object pointer and a 32-bit value; stores the value at +0x48.
Call site `0x02063e88` uses it to clear the field on the object's first pointer
(also `0x02063ec4`). Objdiff: 100%.

## func_02063920 — 52 bytes

Clears the shared 1024-byte text buffer at `data_0216b5a8` with
`func_02008644(0, data_0216b5a8, 0x400)`, then resets the descriptor at
`data_0216b5a0` so its `+0` word points at that buffer and its `+4` length
word is zero. The two bss objects are adjacent and the literal reload after
the fill proves the pointer store. Call sites include `0x02067310`,
`0x0206737c`, `0x0206a2cc`, `0x02090d4c` and many other text resets.
Objdiff: 100%.

## func_02063a30 — 20 bytes

Tail wrapper for `func_02063954`: forwards the text pointer in r0 and the
constant append code `0x8001` in r1, returning the result object. Call site
`0x0206733c` keeps that pointer across a loop. The pool holds
`func_02063954` followed by `0x00008001`, matching the original literal order.
Objdiff: 100%.

## func_02063a44 — 12 bytes

Tail wrapper for `func_02063954`. Forwards the text pointer in r0 and the
character code in r1 and returns the result object (call sites `0x0211c464`,
`0x0211d8f8`, `0x0211d93c`). Objdiff: 100%.

## func_02063a50 — 16 bytes

Returns word `+4` of the bss object `data_0216b9a8`, the shared result
singleton. Callers test it for null before reading fields (call sites
`0x020654d0`, `0x02065530`, `0x02065548`). Objdiff: 100%.

## func_02063a60 — 12 bytes

No-argument tail wrapper for `func_02063a50`, which returns the singleton from
`data_0216b9a8` +4. Callers test the result for null and read fields through it
(call sites `0x020641c8`, `0x0206545c`). Objdiff: 100%.

## func_02063f54 — 48 bytes

Queries device 0 with mask 1 through `func_02053800`, returning the query
result. When the result is non-zero it stores 1 at the object's `+0x24` word
and 0 at `+0x2c`; when it is zero the object is untouched and the query's zero
result is returned. The target keeps the result in r0 across the stores (so
the constants use r1) and has no `mov r0` on either return path, which
establishes the status return type. Call sites are `0x02064150`,
`0x0206418c` and `0x02064198`. Objdiff: 100%.

## func_020641c4 — 44 bytes

Increments the `+0x28` word of the `func_02063a60` singleton and stores the
new value, wrapping it back to zero once it reaches 0xffff. The literal at
`0x020641ec` is `0x0000ffff`, and the original stores the incremented value
before the conditional `movge`/`strge` reset. Its only caller is
`0x02063b88`, immediately before `func_020641f0`. Objdiff: 100%.

## func_020641f0 — 40 bytes

Returns immediately when `func_0206557c` returns zero; otherwise loads the
signed byte at `+0x68` of the object with `ldrsb` and decrements it only when
it is positive (`subgt`/`strbgt`). Its only caller `0x02063b90` invokes it after
`func_020641c4`. Objdiff: 100%.

## func_020642a8 — 20 bytes

Loads the signed byte at `+0x68` of the object with `ldrsb` and returns 1 when
it is positive, else 0. Call site `0x02064294` selects between a reset and a
field update, and `0x020642e8` is the other caller. Objdiff: 100%.

## func_0206431c — 32 bytes

Returns 0 when the object's `+0x38` word is 1 or 3, and 1 otherwise. The
original tests both values with `cmp #1; cmpne #3` and branches to separate
0/1 return blocks (call site `0x02065518`); the switch keeps that shape.
Objdiff: 100%.

## func_0206433c — 32 bytes

Returns 0 when the object's `+0x44` word is 1 or 3, and 1 otherwise; same
compare and separate-return shape as `func_0206431c`, on the `+0x44` word.
Call sites `0x020653c8` and `0x02065504`. Objdiff: 100%.

## func_0206435c — 20 bytes

Stores 2 at `+0x8` and 5 at `+0xc` of the object, in that order. Call site
`0x02065488` does this before writing bytes at `+0x54`/`+0x55`; further call
sites are `0x02065c04`, `0x02065db0` and `0x02065dc8`. Objdiff: 100%.

## func_0206541c — 28 bytes

Loads the object's `+0x6c` word, returns when it is neither 0 nor 2, and
otherwise calls `func_02065374(object)`. The original keeps the word in r1
across `cmp #0; cmpne #2; popne`, so the early return is written with the
negated conjunction. The function address is loaded at `0x02065f20` for use as
a callback. Objdiff: 100%.

## func_02065438 — 28 bytes

Calls `func_02065374(object)` when the object's `+0x6c` word is 1 or 2, and
returns otherwise. The original keeps the word in r1 across `cmp #1; cmpne
#2; popne`, so the early return is written with the negated conjunction. The
function address is loaded at `0x02065f24` for use as a callback. Objdiff:
100%.

## func_0206552c — 24 bytes

Returns 1 when `func_02063a50` (the shared result singleton from
`data_0216b9a8` +4) is non-null, else 0. Call sites include `0x0203bda4` and
`0x020964b4`; the original emits `cmp; movne #1; moveq #0`. Objdiff: 100%.

## func_0206557c — 32 bytes

Returns 0 when the `func_02063a50` singleton is absent; otherwise loads the
render-object pointer at `+0` of the singleton (`ldr r0, [r0]`) and returns
`func_02062a3c`'s answer for it. The original emits `cmp; moveq r0, #0; popeq`
before the call. Call sites `0x0204b190`, `0x020641f8`, `0x020642d4`,
`0x020f7994`, `0x020f79c4`, `0x020fac78`, `0x020facc4`, `0x02113050` and
`0x02113080`. Objdiff: 100%.

## func_0206559c — 24 bytes

Returns the signed word at `+0x5c` of the `func_02063a50` singleton, or 0 when
the singleton is absent (`cmp; moveq r0, #0; ldrne r0, [r0, #92]`). Call site
`0x0204b1a4` compares the result with 1. Objdiff: 100%.

## func_02065604 — 16 bytes

Stores the value in r0 at `+0` of the bss object `data_0216b9a8`, the object
behind the shared singleton. Call sites `0x020f7b4c`/`0x020f7b58` pass 0/1;
`0x020fa838` and `0x021156f8` also call it. Objdiff: 100%.

## func_02065614 — 20 bytes

Stores the value in r0 at `+0x1c` of the singleton returned by
`func_02063a60`. It keeps the argument in r4 across the call, matching the
original `push {r4, lr}`; call sites `0x020dfe1c`/`0x020dfe28` pass 1/0.
Objdiff: 100%.

## func_02065628 — 20 bytes

Stores the argument at `+0x20` of the `func_02063a60` singleton. The original
keeps the argument in r4 across the call (`push {r4, lr}`), which the local
store reproduces; callers at `0x020dfdfc` and `0x0211c4ac` pass 1. Objdiff:
100%.

## func_0206567c — 32 bytes

Clears the `+0x60` and `+0x64` words of the `func_02063a60` singleton and then
calls `func_0206563c(0)`. The original materialises the zero once in r1, reuses
it for both stores and emits `mov r0, r1` before the call, which the shared
local reproduces. Call sites `0x020f3324` and `0x020f339c`. Objdiff: 100%.

## func_0206569c — 16 bytes

Tail wrapper for `func_020656ac`: passes the object in r0 through and sets the
second argument to `-1` (`mvn r1, #0`). Call sites include `0x0203c690`,
`0x020d20dc` and `0x020dfe5c`; the result is ignored. Objdiff: 100%.

## func_020658a0 — 20 bytes

Tail wrapper for `func_020658b4`: loads its address, sets r1 and r2 both to 1
(`mov r1, #1; mov r2, r1`) and branches. Call site `0x021107fc` passes the
object held in r4. Objdiff: 100%.

## func_020658b4 — 40 bytes

Forwards the object (`r0`) and mode (`r1`) to `func_02065864`, then returns
when mode is -1; otherwise forwards the third argument (`r2`) to
`func_020bac00`. The original loads -1 into r0 with `mvn r0, #0` for the
compare, keeping the mode in r5 across the first call. Call site
`0x020658e4` forwards its own first three arguments, and `func_020658a0`
loads this address at `0x020658b0` for its 1/1 tail call. Objdiff: 100%.

## func_0206597c — 40 bytes

Calls `func_02063a60` with its result unused, then looks up the message object
for `message` with `Unk095560_Unk_095778`. When the lookup returns null
it returns; otherwise it passes the object to `func_020656ac` with mode -1.
Call sites pass small message ids: `0x02065a7c`/`0x02065a88`/`0x02065a94`
pass 13/12/90 and `0x020a07dc` passes 4. Objdiff: 100%.

## func_02065b74 — 40 bytes

Returns when `func_02063a50` (the shared singleton) is null; otherwise calls
`func_02062a00` on both render-object pointers at `+0` and `+4` of the
singleton, releasing the slots they reference. Call sites `0x0204809c` and
`0x0204813c` also call it, and the two state setters below tail-call it.
Objdiff: 100%.

## func_02065b98 — 40 bytes

Gets the `func_02063a60` singleton, stores 2 at `+0x50` and 0 at `+0x5c`, then
loads byte `+0x90` of its render object (`ldrb`) and forwards it to
`func_020babec`. Its only caller `0x02065884` is inside `func_02065864`, after
`func_020656ac` has run. Objdiff: 100%.

## func_02065c10 — 32 bytes

Calls `func_02065bc0` and then sets the `+0x8`, `+0xc` and `+0x58` words of the
`func_02063a50` singleton to 1. The original does not null-check the singleton.
Call sites include `0x0203bc60`, `0x0203cd74`/`0x0203cd7c`,
`0x0203d9cc`/`0x0203da54`, `0x020dfdf4`, `0x020e2e3c`, `0x020fac08` and
`0x0210a26c`/`0x0210a308`. Objdiff: 100%.

## func_02065c30 — 40 bytes

Returns when `func_02063a50` is null; otherwise stores 3 at `+0x8` and 5 at
`+0xc` of the singleton, then calls `func_02065b74` to release its render
objects. Call site `0x020a3ec4` runs it when `func_02065cd0` reports state 1;
other call sites include `0x0203c72c`, `0x020d1fbc` and `0x0211c74c`. Objdiff:
100%.

## func_02065c58 — 40 bytes

Same null-check and release tail as `func_02065c30`, but stores 4 at `+0x8`
and 5 at `+0xc`. Call site `0x020a0804` follows a `func_0206597c(4)` message
reset. Objdiff: 100%.

## func_02065c80 — 40 bytes

Returns when the `func_02063a50` singleton is null; otherwise stores 3 at
`+0x8` and 0 at `+0xc`, then calls `func_02065b74` to release its render
objects. Call sites are `0x0204b148`, `0x0204b180`, `0x0210b324` and
`0x0211c864`. Objdiff: 100%.

## func_02065ca8 — 40 bytes

Returns when the `func_02063a50` singleton is null; otherwise stores 0 at
`+0x8` and at `+0x4c`, then calls `Unk0bc1a8_Unk_0bc9b4` with id 25. The
original keeps 25 in r0 after the two stores. Call sites include
`0x0203be94`, `0x0203bffc`, `0x02048f28`, `0x02063de4` and many text resets.
Objdiff: 100%.

## func_02065cd0 — 44 bytes

Returns 1 when the `func_02063a50` singleton is absent; otherwise loads its
`+0` render-object pointer and returns whether that object's `+0x3c` word
equals 1. The original materialises the boolean with `moveq #1; movne #0`.
Call sites include `0x0204b128`, `0x0204b13c`, `0x0204b16c`, `0x020a07f8`
and `0x020a3e7c`/`0x020a3eb8`. Objdiff: 100%.


## M2-T1064 source search

Searched public NitroSDK/font rendering sources before reconstruction. The
[NNS G2D API list](https://twlsdk.randommeaninglesscharacters.com/docs/twl/TwlSystem/g2d/g2d.html)
did not identify an equivalent four-slot registry or these command wrappers.
No public implementation was reused; field and call contracts below follow
the original instructions, retaining neutral symbol names.

## func_02063b4c — 52 bytes

Five-case dispatch on the second argument's word: only state 1 calls
`Unk0bc1a8_Unk_0bc504(object, 0)`. The jump table at 0x02063b58 establishes
the range, including no-op cases. Objdiff: 100%.

## func_02063f84 — 52 bytes

Queries device 0 for mask 0x400 through `func_02053824`. When nonzero, sets
+0x24 and +0x2c on the supplied object and +0x84 on its first pointer to one.
The stores at 0x02063fa4..0x02063fb0 establish the borrowed child view.
Objdiff: 100%.

## func_02065498 — 52 bytes

Checks `data_0216b9a8` +4 directly. When null, forwards (25, 0xffff, 0) to
`Unk0bc1a8_Unk_0bc928`; returns one in either case. Objdiff: 100%.

## func_02061980 — 56 bytes

Selects the font by id and returns null if its +0x30 halfword table is null.
Otherwise decrements the signed index and clamps it to zero when at or above
the +0x34 count; negative indices are preserved. The returned pointer is
borrowed. See DEC-030 for the observed pointer reload. Objdiff: 100%.

## func_02065544 — 56 bytes

Returns zero if the shared singleton is absent or its +0x4c word is zero;
otherwise tests its +8 word for nonzero. Objdiff: 100%.

## func_020629c4 — 60 bytes

Nullable teardown: calls `func_02060160`, optionally `func_0205bb68` on the
first pointer, then `func_02060248`, `func_02062a00`, and `func_02061424` on
the supplied object. Order follows 0x020629d0..0x020629f8. Objdiff: 100%.

## func_02065864 — 60 bytes

Calls `func_020656ac(object, mode)` and obtains the shared singleton even
when mode is -1. Other modes call `func_02065b98`, forward mode to
`func_020ba964`, and forward the singleton child's +0x90 byte to
`func_020babec`. Objdiff: 100%.

## func_020618cc — 64 bytes

Searches the four 56-byte font records for the first matching unsigned id at
+0x20, returning a borrowed record or null. The registry reset at
`func_02061798` and the accessors `func_0206190c` / `func_0206191c` establish
the layout and use. Byte-stride address calculation for the comparison and
array indexing for the return reproduce the original register allocation;
loop strength reduction and rotation are disabled locally. See DEC-031.
Objdiff: 100%.

## Hard list

- `func_02062264` (4 bytes): the original instruction is only
  `pop {r3, r4, r5, r6, r7, pc}` (0xe8bd80f8). It is the unreachable trailing
  epilogue of `func_02062208`; `func_02062208` ends at 0x02062258 with a
  conditional return of the same form, then branches back to its loop, and no
  branch, call or literal anywhere in the ARM9 image targets 0x02062264.
  A standalone C function cannot emit a register pop without a matching push
  (an empty function compiles to `bx lr`), and expressing it would require
  inline asm, which the card forbids. Leave the symbol to the delink object;
  a human should correct the split so the epilogue stays part of
  `func_02062208` before this symbol is considered matchable.

## Validation

`tools/hand/cmp.py` reports OK for `func_020618cc`; all eight M2-T1064
functions now match. The match gate reports all 82 compiled functions in the
changed unit at 100%. `ninja`, `tools/match_gate.py`, `tools/checksum.py`,
`tools/anticheat.py` and the repository unit tests are run before handing the
change back.
