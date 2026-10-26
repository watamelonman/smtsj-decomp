# sdk_0205e800

All four functions are reconstructed from ARM instructions and retain their existing
neutral symbols: the available evidence does not establish original API names.
Public NitroSDK source was searched first (including the nitro-decomp/nitro project);
no corresponding routine was identified. The TU path alone is not evidence of an SDK API.

| Function | Contract and instruction evidence | Match |
| --- | --- | --- |
| `func_0205e800` | Caps an unsigned argument at 127 and stores its low byte in `data_0216b348.unk_00a5`; unsigned `movhi` and `strb` establish the behavior. | 100% |
| `func_0205e818` | Passes each of eight consecutive words at `data_0216b3f0` and the unchanged signed argument to `func_0202a0d4`. The eight-word extent is inferred from the loop, not a complete global layout. | 100% |
| `func_0205e84c` | Forwards a writable integer pointer, inclusive bounds, wrap flag, and direction to `func_0205e870`, supplying step 1 as its sixth argument. | 100% |
| `func_0205e870` | Selects decrement/increment masks by direction: 0 uses 64/128, 1 uses 32/16, 2 uses 128/64, 3 uses 16/32. The first queried mask has priority when both are active. Other directions produce no adjustment. Applies signed step, then clamps or repeatedly wraps across the inclusive bounds. A zero range falls back to the relevant bound. Returns 0 for no input, 1 after changing the stored value, or -1 if input produces no stored change. | 100% |

The adjustment helper requires valid writable storage, ordered bounds when wrapping,
and signed arithmetic within range. Mask meanings and global record semantics remain
unknown. Prototypes describe the observed 32-bit calling convention; signedness of
opaque helper arguments is not independently established.

Validation uses byte comparison against the original functions and the objdiff match
gate, plus the repository unit tests, anticheat gate, and full image checksum gate.
The TU remains linked from its original delink pending human completion marking.

## Hard list

None.
