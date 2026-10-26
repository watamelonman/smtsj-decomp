# src/game/unit_0205ae50.c

## M1-T425

All eight functions match the delinked ARM object at 100%. Evidence below is
from the original instruction sequences; field and subsystem meanings remain
unknown, so existing neutral symbols are retained. Work pointers are borrowed
and must be non-null unless explicitly described as optional.

- `Unk05ae50_Unk_05b228` (12 B): stores 1 in the byte at work +0x59
  (`MOV`, `STRB`); no ownership transfer.
- `Unk05ae50_Unk_05ae50` (16 B): calls `func_0205ad9c` and forwards its
  returned work pointer to `func_0205ae60`; the consecutive calls preserve R0.
- `Unk05ae50_Unk_05af2c` (16 B): obtains the singleton work and forwards it
  to `Unk05ae50_Unk_05af3c`, as established by the two original relocations.
- `Unk05ae50_Unk_05b388` (16 B): obtains the singleton work and forwards it
  to `func_0205b36c`, as established by the two original relocations.
- `Unk05ae50_Unk_05afd8` (20 B): clears the low two bits of an unsigned
  limit and stores it at `data_0216a184 + 0x5a8` (`BIC` and `STR`).
- `Unk05ae50_Unk_05b358` (20 B): returns exactly 0 or 1 according to the
  byte at work +0x59 (`LDRB`, compare, conditional moves).
- `func_0205b36c` (28 B): loads the optional linked work pointer at +0x14;
  returns 0 for null, otherwise calls `Unk05ae50_Unk_05b358` on that work.
  The original null guard and call support the typed link without assigning
  an unsupported semantic name.
- `Unk05ae50_Unk_05af3c` (40 B): passes the word at +0x10 to
  `func_02053000`, clears words +0x10, +8 and +0xc in that order, and returns
  1. The call relocation and ordered stores establish this contract.

## M1-T426

All eight requested functions match at 100% in objdiff; the eight M1-T425
functions remain at 100%.

Evidence is the original ARM instructions and call relocations. All work,
resource and request pointers are borrowed; work and descriptor pointers must
be valid for the helper calls. Unknown subsystem and field meanings retain
neutral names. No new runtime tests are required by this matching card.

- `Unk05ae50_Reset` (40 B): clears 0x5ac singleton bytes via
  `func_02008848`, then sets the four-byte-aligned limit to 0x18000 through
  `Unk05ae50_Unk_05afd8`.
- `Unk05ae50_Unk_05afec` (64 B): reads the volatile VCOUNT halfword at
  0x04000006 once, returns zero outside 191..213 inclusive, and otherwise
  returns the signed minimum of its argument and singleton +0x5a8 with the
  low two bits cleared. The comparisons and BIC establish the contract.
- `Unk05ae50_WaitVCountThen_05af64` (76 B): when `func_02052624` returns
  less than 31, polls VCOUNT until 191..213, then submits the six-word
  descriptor. At 31 or above it submits immediately. Both volatile reads
  in the original polling loop are preserved.
- `Unk05ae50_Unk_05af64` (116 B): saves state with `func_02007a58`,
  processes each nonzero source in the descriptor's two three-word groups
  through their original setup/copy/finalization calls, and restores state
  with `func_02007a6c`. Call relocations establish the groups; their broader
  subsystem purpose is not inferred.
- `func_0205b154` (172 B): saves/restores state and drains the singleton's
  forty-slot ring during VCOUNT 191..213. Each slot is 36 bytes; read/write
  indices are at +0x5a0/+0x5a4. A failed `func_0205b02c` stops processing;
  successful slots invoke an optional callback from +0x1c with +0x20 as
  argument. The read index wraps at 40; VCOUNT >=211 stops further slots.
- `func_0205b398` (172 B): returns for an already-bound request or null
  data at request +0x10. Otherwise initializes work with data +12, binds
  request +0x14, clears work +0x59, obtains two descriptor values from
  `func_0205aa78`, and queues the descriptor with the byte-setting callback.
  Work words +0xc/0/+0x10/+4 supply the other descriptor values.
- `func_0205b444` (128 B): clears work +0x59 and queues the descriptor
  using the two resource helper results, work words 0/+4, and the two
  `func_0205aa78` outputs. The callback relocation identifies
  `Unk05ae50_Unk_05b228` as the completion byte setter.
- `func_0205b4c4` (124 B): builds the same descriptor, submits it through
  `Unk05ae50_WaitVCountThen_05af64`, then sets work +0x59 directly. The
  original call order and STRB establish synchronous completion ordering.

The temporary descriptor uses the full nine-word queue-record allocation,
although only its first six words are initialized and consumed on submission.
This preserves the observed 48-byte local stack frame, including two outputs
and the fifth outgoing argument. The queue record's remaining fields are
populated by the queue helper, not fabricated by these callers.

## M1-T427

All three requested functions match at 100% in objdiff. Evidence is the
original ARM instructions and call/data relocations; unknown meanings retain
neutral names. Arguments are borrowed and non-null.

- `func_0205ae60` (204 B): builds a 64-byte path using `func_0205ad6c`,
  work +4, and `data_02143bcc`; a failed `func_020519f0` probe selects
  `data_02143bd4` instead. Loads through `func_02051610`, returning null on
  failure. On success, queries the header at resource +12 and stores payload
  start (resource +28), the next range start, and the resource at work +8,
  +12, and +16. Returns the loaded resource. The probe uses two local words;
  the separate header output follows them in the original stack frame.
- `func_0205b02c` (296 B): advances cumulative progress at descriptor +24,
  processing the second transfer group before the first. Each copy is bounded
  by `Unk05ae50_Unk_05afec`; nonpositive limits leave progress unchanged.
  Original unsigned comparisons establish completion at the sum of both
  lengths. Setup, cache-range, copy, and finalization calls preserve the
  observed order; returns exactly zero or one.
- `func_0205b234` (216 B): enters/exits the original helper pair with argument
  1, checks the forty-slot ring for fullness, and invokes `func_02007e94` on
  full. Otherwise copies all 36 descriptor bytes, zeros source/length pairs
  when either is absent, resets progress, records callback/work, and publishes
  the next write index, wrapping at forty. Callback and work remain borrowed
  until draining. Callers provide storage for the full nine-word descriptor.

No runtime tests were added: this card uses original-object matching as its
behavioral oracle. Existing M1-T425 and M1-T426 functions remain at 100%.

## Hard list

None for M1-T425, M1-T426, or M1-T427.
