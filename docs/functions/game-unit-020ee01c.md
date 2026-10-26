# game/unit_020ee01c

Original neutral symbols are retained because the full subsystem purpose is not
established. The unit remains delink-backed until a human marks it complete.

## func_020ee01c — 360 bytes, 100% objdiff

Takes a borrowed work object with a signed substate at +0x7481. Substates 4..6
run the graphics reset sequence; other substates return immediately. Copies the
vectors at data_0213c870 and data_0213c87c, configures projection constants,
installs a zero translation and identity matrix, clears global flags 0xa4,
and submits the work's embedded object at +0x41c. The writes to hardware
registers 0x04000444 and 0x04000448 and graphics-context calls establish the
reset behavior; they do not establish a more specific game-level name.
The linker resolves the interworking call to Thumb func_02000edc.

## func_020ee184 — 80 bytes, 100% objdiff

Takes two borrowed pointers to opaque record pointers. For each non-null record,
func_02049c28 writes a two-halfword pair; the comparator subtracts the signed
first components. Null records use 256. Evidence for the comparison contract:
func_020ee1d4 passes this callback to func_02013c68 with element size four and
count six, sorting the registry pointer slots beginning at +0x74.

## func_020ee1d4 — 640 bytes, retained original

The caller func_020ee454 allocates a 52-byte task with this callback. The observed
layout is a state word and six eight-byte handle/value slots. States 0 and 4 wait
for func_02052728; state 1 initializes source records; state 2 handles type-2
registry records, packs eligible sources into the six slots, and sorts six
registry pointers. State 3 sends message kind 13, then state 5 waits for
Unk09d060_Unk_09d13c before releasing the task.

### Hard list

- **func_020ee1d4**: typed C switch with fallthrough and bounded record loops was
  attempted. Reordering registry/source declarations reproduced the loop register
  allocation. The ordinary two-byte-flags/sixteen-word message candidate compiled
  to 636 bytes rather than 640. The original reserves an additional stack word
  and stores 2 there before sending the message; its flags initialization also
  assigns the counter and cursor registers differently. Tried an inline message
  setter with an address-taken local value, and a containing message envelope;
  neither reproduced the message block. Extra call-argument experiments were
  discarded because the callee only consumes two arguments. No partial body is
  shipped. Use a decomp.me scratch to resolve the original message construction
  and stack layout before adding this function.
