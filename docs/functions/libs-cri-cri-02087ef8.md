# CRI unit 02087ef8

The seven functions retain their original neutral symbols. Public CRI/ADX
source searches found format decoders (including FFmpeg and vgmstream), but no
matching middleware callback/state implementation. Reconstruction therefore
uses the original ARM instructions. Private borrowed layout views describe only
observed fields; no module boundary or ownership changes are introduced.

| Function | Evidence and contract |
| --- | --- |
| `func_02087ef8` | Conditional stores at 02087f04/02087f14 copy the two words beginning at `data_021477f8`; either output may be null. |
| `func_02087f20` | Checks context/storage and a signed 0x1800-byte minimum, calls the provider with the embedded +0x18 block, and registers six callbacks at 02087fd8..02087fec. Storage and context are caller supplied. The provider's failure path reports the error and returns without invoking the trailing helper, exactly as the original does. |
| `func_02088040` | Loads `data_021734ac` and invokes it only when non-null, forwarding the borrowed context. |
| `func_02088060` | Follows context +4, then parent +4; stops/releases the handle at state +0xb8 and clears that slot. A null context reports the original diagnostic. |
| `func_020880bc` | Tail-forwards an opaque handle to `func_0208a0d8`; provider result is returned unchanged. |
| `func_020880c8` | Tail-forwards an opaque handle to `func_0208a0e0`; provider result is returned unchanged. |
| `func_020880d4` | Provider status zero resets +0x90/+0x88. State 1 configures the handle using +0xac and advances to 2. State 2 performs the signed +0xc0 iteration count, updates delta/cumulative words and +0x94, and resets state on provider status 3. |

The status meanings and provider return-value semantics remain unknown; names do
not infer them. Callback handle parameters/results use pointer and word types
consistent with the forwarding instructions; no narrower ABI is assumed.

## Hard list

None.
