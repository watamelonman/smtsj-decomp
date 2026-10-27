# libs/unknown/lib_0202aeb0

All five functions match at 100% with the configured mwccarm 2.0/sp1p5.
They are the NitroSystem sound capture state helpers. Linker names remain
neutral because `config/arm9/symbols.txt` is human-owned; the descriptive
NitroSystem names are used in the source comments and below.

## Source evidence

The public NitroSystem reconstruction in
[ctrl-cheeb-del/pokeheartgold `lib/NitroSystem/src/snd_capture.c`](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/snd_capture.c)
contains the exact implementations, and
[`lib/include/nnsys/snd_internal.h`](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/include/nnsys/snd_internal.h)
defines the layouts:

- `SndCaptureWork` puts `state` at +0x48; `gSndCaptureWork` is `data_0215ca74`
  and its `msgQueue` alias is `data_0215ca7c`.
- `SndCaptureState` starts at `data_0215cabc` and has `lockedChBitFlag` at
  +0x20, `chBitFlag` at +0x24, `capBitFlag` at +0x28, `alarmNo` at +0x2c,
  `fader` at +0x3c, `isStopping` at +0x4c and `volume` at +0x50.
- The five functions appear in the same address order as the public source:
  `Init`, `Main`, `Stop`, `BeginSleep`, `EndSleep`.

The instruction streams agree instruction-for-instruction, including the
`alarmNo >= 0 ? 1 << alarmNo : 0` mask, the `>> 8` fader volume, the command
tag/flush/wait sequence, the message-queue drain loop in `Stop`, and the two
`MIi_CpuClear32` plus `DC_FlushRange` pairs before restarting the timer.

## Functions

| Linker name | Size | NitroSystem name and behavior |
| --- | --- | --- |
| `func_0202aeb0` | 24 | `NNSi_SndCaptureInit` — clears the work header and marks capture inactive. |
| `func_0202aec8` | 136 | `NNSi_SndCaptureMain` — advances the reverb fader, stops it when finished, otherwise updates the channel volume when it changes. |
| `func_0202af50` | 240 | `NNSi_SndCaptureStop` — stops the timers, drains the command queue/messages when an alarm is active, releases capture/channel locks and the alarm, restores the output selector for effects, and clears the active flag. |
| `func_0202b040` | 96 | `NNSi_SndCaptureBeginSleep` — stops the capture timer and waits for the command queue before sleep. |
| `func_0202b0a0` | 132 | `NNSi_SndCaptureEndSleep` — resets the position, clears both buffers, flushes their cache lines and restarts the capture timer. |

Statistics: 628 bytes of code, 5 functions, 5 at 100%. No inline assembly,
byte blobs or special cases are used.

## Validation

`tools/match_gate.py` reports 100% for all five functions,
`tools/checksum.py` reports the image byte-identical to the original, the
anticheat gate is clean, and the nine existing unit tests pass. The TU remains
linked from its delinked original until a human marks it `complete`.

## Hard list

None.
