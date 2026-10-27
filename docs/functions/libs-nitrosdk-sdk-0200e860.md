# NitroSDK RTC helpers (0200e860)

Reference: [NitroSDK RTC external.c](https://github.com/ntrtwl/NitroSDK/blob/main/libraries/rtc/src/external.c)
and [internal.c](https://github.com/ntrtwl/NitroSDK/blob/main/libraries/rtc/src/internal.c).
The public implementations identify these routines through the initialization
sequence, RTC FIFO tag 5, command values, work-field offsets and BCD arithmetic.
Original linker names are retained because symbol configuration is human-owned.

The private `RTCState` view combines the initialization halfword with the
following SDK work storage: lock +12, callback +16, buffers +20/+24,
callback argument +28, sequence +32, index +36, interrupt callback +40,
and synchronous result +44. This storage remains SDK-owned. Date output is
caller-owned and holds four 32-bit year/month/day/weekday fields.

| Original symbol | Known source identity and contract | Result |
| --- | --- | --- |
| `func_0200e860` | `RTC_Init`: initialize once, clear request/callback state, wait for ARM7 readiness and register the FIFO callback. | 100% |
| `func_0200e940` | `RTC_GetDate`: borrow caller date output, start an asynchronous date request with the result callback, wait on success and return completion status. | 100% |
| `func_0200eec8` | `RtcBCD2HEX`: validate all eight packed decimal nibbles, then accumulate a decimal integer; any nibble above nine returns zero. | 100% |
| `func_0200ef38` | `RtcGetResultCallback`: store the completion result at work +44; callback context is unused. | 100% |
| `func_0200ef48` | `RtcWaitBusy`: poll the volatile SDK lock at `data_02154304` while it equals one. | Deferred; original delink retained |
| `func_0200ef60` | `RTCi_ReadRawDateAsync`: forward command 0x12 to the shared sender; return send success. | 100% |
| `func_0200ef70` | `RTCi_WriteRawStatus2Async`: forward command 0x27 to the shared sender; return send success. | 100% |
| `func_0200ef80` | `RtcSendPxiCommand`: mask the shifted command to bits 8–14, send on FIFO tag 5 with error flag zero, and return whether sending succeeded. | 100% |

## Hard list

- `func_0200ef48` (24 bytes): the known SDK implementation is explicitly
  handwritten ARM assembly. A plain C `while (data_02154304 == 1) { }`
  with a volatile word produces the correct loop and size, but mwcc chooses
  r0 for the address and r1 for the load, whereas the original uses r12
  and r0. Objdiff reports 96.67%. No assembly or forced instruction bytes
  are used; the C definition is omitted for a human decomp.me investigation.
  `func_0200e940` retains an external reference to the original implementation.
  This repo uses delink objects rather than `INCLUDE_ASM` stubs.
