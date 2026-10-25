# src/game/unit_020f470c.c

## M1-T370 — all eight functions match at 100%

The contracts below come from the ARM instructions at each function's address.
Work pointers are borrowed. The observed work area is 0xf8 bytes, with a state
word at +8, a flag at +0x50, and an embedded object beginning at +0x54.
Neutral names remain because these instructions do not establish game semantics.

- `Unk0f470c_Nop_0f4874` (4 bytes): immediately returns; no arguments or effects.
- `Unk0f470c_Thunk_020f7248` (12 bytes): interworking tail thunk to
  `func_020f7248`; the target literal and `bx ip` establish forwarding.
- `Unk0f470c_Unk_0f4908` (32 bytes): calls `0f7210` and, only for a
  nonzero result, passes work +0x54 to `func_020f82e0`.
- `func_020f4928` (36 bytes): calls the field-10 and field-0 accessors on
  work +0x54, then compares the state at +8 against 1. The original has
  an unconditional return after the comparison; the C early return preserves
  this otherwise redundant comparison under the project compiler.
- `Unk0f470c_Unk_0f4b80` (36 bytes): passes the incoming pointer to the
  field-10 accessor, then passes singleton +0x44 and that result to `0e8d90`.
  Returns the final callee's register result without assigning game semantics.
- `Unk0f470c_Unk_0f49f4` (40 bytes): calls `0ea70c`; states 1 and 2 return,
  while all other states call `func_020d1e94(1)`.
- `Unk0f470c_Unk_0f4764` (44 bytes): passes the work area, zero, and 0xf8
  to `func_02008848`, stores its address in `data_02176e00`, then calls
  `func_020f4790` on it. The zero-fill interpretation is supported by the
  explicit fill arguments and subsequent initialization.
- `Unk0f470c_Unk_0f4c20` (48 bytes): a nonzero `0e8bac` result gates
  `0f4b80(work)` followed by `0d1d94(func_020ea630(8), -1)`.

Validation: project build and objdiff match gate. Binary instruction equivalence
is the acceptance test; the card does not require additional host tests.

Hard list for M1-T370: none.

## M1-T371 — all eight functions match at 100%

Contracts below follow the ARM instructions at the named addresses; pointers are
borrowed and neutral names avoid inferring game semantics from callbacks alone.

- `Unk0f470c_Unk_0f4958` (60 bytes): reads embedded field 10, calls
  `0ea70c`, then uses the flag at +0x50 to choose `0ea828` or the array-entry
  lookup followed by `func_020ea744`.
- `Unk0f470c_Unk_0f4b44` (60 bytes): reads the singleton; calls `0e8b94`,
  then updates singleton +4 with arguments 0 and 5, calls `0f7d14` on it,
  and passes singleton +0x40 and zero to `0f7de4`.
- `Unk0f470c_Unk_0f4a1c` (68 bytes): ignores events other than 2. Values
  1, 5 and 6 set the work flag; other values clear it. Publishes that flag
  through `0e8f50`.
- `func_020f470c` (88 bytes): fills descriptor size 0xf8, kind 3, five
  callback addresses and a zero word. The word at +8 is untouched.
- `func_020f4994` (96 bytes): initializes the embedded object using either
  zero or `0e8374(work[+0x44])`, selected by `0e82ac`. Clears and publishes
  the flag, stores 9 at +0xc and submits the resource from +0x28 with -1.
- `func_020f4a60` (96 bytes): returns 1 when `0e8bac` is false; otherwise
  looks up the supplied index and rejects states 1, 2, 7 and 11 returned by
  `0204a244(02044ec4())`. Its first callback argument is unused.
- `func_020f4ba4` (124 bytes): a clear singleton flag enables input checks
  for masks 32 and 16. Each invokes its corresponding object thunk and
  refreshes the singleton through `0f4958`. Returns -1 for mask 32, 1 for
  mask 16 (which takes precedence), or zero when neither is processed.
- `Unk0f470c_Unk_0f4ac0` (132 bytes): obtains field 10 from its incoming
  object and selects an array entry. If `0e8bac` is true, stores the entry
  into `045048()` +0x40 and calls `020e82c8`. Otherwise calls `020e8d38`
  with the object from `02044ec4`, its +0x1e8 region, the entry, and singleton
  +0x28; a nonzero result triggers `0e8d18(0)`, then updates singleton +0x40.

Validation uses binary equivalence rather than host tests (tests_required=false).
All eight functions match the original instructions and relocations exactly.
No module boundary changes. Hard list for M1-T371: none.

## M1-T372 — remaining two functions

- `func_020f4790` (228 bytes): initializes borrowed work words +0x40,
  +0x44, +0x48 and +0x4c to 30, 5, 0 and 0. Calls `020f711c` with
  the observed numeric parameters and three callbacks. Uses `0e8460()` for
  both embedded-object selectors, installs four callbacks through `020f81cc`,
  then sets callbacks at embedded offsets +0x98 and +0x9c. Evidence is the
  stores, calls and nine callback literals at 020f4790–020f4870.
- `func_020f4878` (144 bytes): first calls `020f7188(work)`, then dispatches
  the state word at +8. State 11 calls `0bc9b4(work[+0x40], 0)`; state 9
  refreshes through `0f4958`, calls `020f8264` on embedded +0x54 and becomes
  10; state 2 calls `0f7de4(work[+0x40], 2)` and becomes 1. Other states
  return. Evidence is the jump table at 020f4894 and its three targets.

Both functions preserve neutral names because the instructions establish these
contracts without identifying game semantics. No module boundary changes.
Binary equivalence is the acceptance test (tests_required=false); standalone
instruction and relocation comparisons match both functions exactly. Full build
and objdiff confirm 100% for both; anticheat and all nine unit tests pass, and
checksum reports all artifacts byte-identical to the original.
Hard list for M1-T372: none.
