# game/unit_02115ca0

Both functions match the delinked ARM originals at 100%. Existing symbol names
are retained because the screen's identity is not established by this TU.
The work layout is derived from accesses at offsets 0, 4, 0x10, 0x14, and 0x18.

## func_02115ca0

Takes a work pointer and advances its frame counter and seven-state sequence.
States wait 32, 30, 30, 180, and 50 frames, then wait for handle completion
and two completion queries before handing the work to `func_02061424`.
The three handles are updated as their states become active. No ownership
transfer is inferred except the final call's use of the work pointer.

Validation: all 384 bytes match, including calls and state dispatch.

## func_02115e20

Takes the same work pointer. State 6 returns immediately. Other states bracket
state-dependent drawing calls with common setup and teardown. State 0 uses a
256 by 192 rectangle and a decreasing value; state 2 passes frame / 30 as a
floating-point alpha argument. Later states add the handles at 0x14 and 0x18.
The drawing interpretation follows the dimensions and repeated handle calls;
no particular screen or resource identity is assumed.

Validation: all 412 bytes match, including floating-point operations and literals.

## Hard list

None.
