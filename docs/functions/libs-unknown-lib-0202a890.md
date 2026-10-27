# NitroSystem sound stream helpers

Source evidence: [pokeheartgold snd_stream.c](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/snd_stream.c).
The source's function order, callback offsets and channel/alarm operations agree
with the target. Original configured linker symbols remain unchanged. The stream
view is private to this TU and borrowed; no module boundary or ownership changes.
Signed one-bit flags reproduce the original signed bitfield extraction; setting
isPlaying to -1 represents the sole nonzero value of that signed field.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| func_0202a968 | NNS_SndStrmFreeChannel: unlock the channel mask, clear mask/count; stream remains caller-owned. | 100% |
| func_0202ab30 | NNS_SndStrmStart: start channel/alarm timers, install sleep callbacks once, mark playing. | 100% |
| func_0202ab84 | NNS_SndStrmStop: forward active streams to ForceStopStrm. | 100% |
| func_0202ac0c | Channel-relative volume setter: stores the offset in the eight-byte hardware-channel record, adds stream volume, converts and submits packed volume/shift. | Deferred below |
| func_0202ac60 | Channel pan setter: channel-number lookup and mask passed to SND_SetChannelPan. Index must be nonnegative; indices above count-1 return. | 100% |
| func_0202ad04 | ShutdownStrm: free alarm, unlink stream, clear active flag. | 100% |
| func_0202ad34 | AlarmCallback: forward stream to buffer callback with alarm flag true. | 100% |
| func_0202adf4 | BeginSleep__Strm: stop playing timers, flush and wait for command completion. | 100% |

## Hard list

- `func_0202ac0c` (84 bytes): left in the original delink, with no C definition.
  The reconstructed setter reaches the correct size and operations but schedules
  the channel-mask shift before the volume-byte AND; the target schedules AND
  first. Tried reusing the channel parameter, local channel numbers, signed and
  unsigned result types, byte conversions, provider parameter types and explicit
  level/shift/mask locals in all assignment orders. None matched exactly with
  mwccarm 2.0/sp1p5, -O4,p. A human can create a decomp.me scratch using
  tools/decompme.py; no scratch was uploaded.

## M2-T400

| Function | Evidence and contract | Result |
| --- | --- | --- |
| func_0202a890 | NNS_SndStrmInit: initialize the shared list once and install borrowed sleep callbacks, clearing channel ownership and activity. | 100% |
| func_0202a908 | NNS_SndStrmAllocChannel: copy channel numbers, lock their combined mask, publish count/mask only on success. Caller supplies at most 16 channel numbers in 0..15. | 100% |
| func_0202a990 | NNS_SndStrmSetup: divide caller-owned PCM storage into channel buffers with 32-byte block alignment, configure channels/alarm, link the stream and deliver initial data under interrupt protection. Channel and block counts must be positive. | 100% |
| func_0202aba0 | NNS_SndStrmSetVolume: combine stream and per-channel decibel offsets, convert to packed hardware volume, and submit each channel. | 100% |
| func_0202ac90 | ForceStopStrm: stop playing timers, unregister sleep callbacks, wait for commands, then release alarm and list membership. | 100% |
| func_0202ad44 | StrmCallback: calculate the current block of each channel, deliver borrowed buffers and advance/wrap the block index. | Deferred below |
| func_0202ae40 | EndSleep__Strm: finish pending blocks under per-delivery interrupt protection, then restart timers for a playing stream. | 100% |

### Additional hard list

- `func_0202ad44` (176 bytes): retained in the original delink without a C
  definition. The public-source implementation reaches 99.09% with the correct
  size, operations and relocations. The compiler assigns the block offset to LR
  and loop index to IP; the target assigns offset to IP and index to LR.
  Tried signed/unsigned offset and index types, register qualifiers, all local
  declaration orders, separate initialization, pointer offsets and a while loop.
  None matched under mwccarm 2.0/sp1p5, -O4,p. A human can create a scratch with
  tools/decompme.py; no scratch was uploaded.
