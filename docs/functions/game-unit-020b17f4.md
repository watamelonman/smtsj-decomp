# game/unit_020b17f4

Both ARM functions match the delinked original at 100% with mwccarm
2.0/sp1p5 and the project flags. The TU remains linked from the delinked object
until a human marks it complete. Names remain neutral because the callback
object's game role has not been established.

## func_020b17f4 — 0x020b17f4, 144 bytes

Takes a writable local work object. Increments the signed counters at +4 and
+8 on every call. Signed state byte +1 selects the update: state 0 advances
at eight frames, state 1 at 24, resetting +4 on either transition. States 2
and 3 call `func_02061424(work)` at eight frames and thereafter if the object
remains active. Other states only increment the counters. Evidence: loads,
comparisons and stores at 0x020b17f8–0x020b187c. Caller must supply valid storage
through +8 and counters that do not overflow signed 32-bit arithmetic.

## func_020b1884 — 0x020b1884, 564 bytes

Takes the same object, readable through +0x1b. State 0 interpolates a byte
value from 0 to 31 over eight frames, state 1 uses 31, state 2 interpolates
back to zero; other states do not draw. Nonzero values configure the draw
helpers. Signed halfwords +0x18/+0x1a supply coordinates; +8 controls the
1-to-minus-16 vertical interpolation over 40 frames.

Byte +2 indexes two interleaved word tables at 0x0213c440/0x0213c444 (eight-byte
stride); caller must provide an in-range table index. Byte +0 selects the
rendering path: 4 formats +0x0c using format 0x0214fefc and mode +0x10; 5–8
measure resource +0x0c+0x6c00, clamp its center against horizontal bounds 0/256,
and draw it; 9 draws resource 215. Other values perform only common setup and
cleanup. Byte +3 supplies the draw argument plus five, and +0x14 is passed to
the setup helper. Evidence: dispatch at 0x020b1980 and calls at
0x020b19ec/0x020b1a50/0x020b1a88. Draw/opacity terminology describes the helper
usage and float-scale arguments; it does not identify the in-game message.

## Hard list

None.
