/* NitroSystem sound streams. Evidence: ctrl-cheeb-del/pokeheartgold,
 * lib/NitroSystem/src/snd_stream.c (matching function order and operations).
 * Original linker symbols are retained because symbol configuration is human-owned. */
#include "types.h"

/** Borrowed sleep callback record; the power manager retains no ownership. */
typedef struct StreamSleepCallback {
    void (*callback)(void *);
    void *argument;
    struct StreamSleepCallback *next;
} StreamSleepCallback;

/** Borrowed stream prefix; offsets and flag widths follow the original accesses.
 * Signed status fields preserve arithmetic extraction. See DEC-041. */
typedef struct SoundStream {
    u8 link[8];
    StreamSleepCallback preSleep;
    StreamSleepCallback postSleep;
    u32 unknown20;
    s32 isActive : 1;
    s32 isPlaying : 1;
    s32 reserved : 30;
    u8 unknown28[20];
    int volume;
    int alarmNo;
    u32 chBitFlag;
    int numChannels;
    u8 chNo[16]; /* Hardware channel numbers, each in 0..15. */
} SoundStream;

extern u8 data_0215c9a8[];
/** Release the caller's locked hardware channel mask. */
extern void func_02029f28(u32 channels);
/** Start selected channel/capture/alarm timers with the supplied command flags. */
extern void func_02009328(u32 channels, u32 captures, u32 alarms, u32 flags);
/** Stop selected channel/capture/alarm timers with the supplied command flags. */
extern void func_02009350(u32 channels, u32 captures, u32 alarms, u32 flags);
/** Borrow a callback record for execution before sleep. */
extern void func_0200e774(StreamSleepCallback *callback);
/** Borrow a callback record for execution after sleep. */
extern void func_0200e78c(StreamSleepCallback *callback);
/** Stop and shut down an active stream; storage remains caller-owned. */
extern void func_0202ac90(SoundStream *stream);
/** Set hardware pan for a channel mask. */
extern void func_0200945c(u32 channels, int pan);
/** Release an allocated alarm number. */
extern void func_02029fbc(int alarmNo);
/** Unlink a borrowed object from its provider-owned list. */
extern void func_0201fd78(void *list, void *object);
/** Deliver stream buffers to the callback; isAlarm distinguishes alarm delivery. */
extern void func_0202ad44(SoundStream *stream, int isAlarm);
/** Return the most recently queued sound command tag. */
extern u32 func_02009ae8(void);
/** Flush sound commands; flag one waits for queue space. */
extern void func_020098c0(u32 flags);
/** Wait until the sound processor completes the specified command tag. */
extern void func_02009a7c(u32 tag);

/** NNS_SndStrmFreeChannel in the cited source: release channels once, then clear ownership. */
void func_0202a968(SoundStream *stream)
{
    u32 channels = stream->chBitFlag;
    if (channels == 0) return;
    func_02029f28(channels);
    stream->chBitFlag = 0;
    stream->numChannels = 0;
}

/** NNS_SndStrmStart in the cited source: start timers and register sleep callbacks once. */
void func_0202ab30(SoundStream *stream)
{
    func_02009328(stream->chBitFlag, 0, 1 << stream->alarmNo, 0);
    if (stream->isPlaying) return;
    func_0200e774(&stream->preSleep);
    func_0200e78c(&stream->postSleep);
    stream->isPlaying = -1;
}

/** NNS_SndStrmStop in the cited source: shut down only an active stream. */
void func_0202ab84(SoundStream *stream)
{
    if (stream->isActive) func_0202ac90(stream);
}

/** Set channel pan; the channel-mask call to SND_SetChannelPan establishes its
 * purpose. `channel` must be >= 0, since a negative index reads chNo[-1]; an
 * index above numChannels - 1 is ignored. */
void func_0202ac60(SoundStream *stream, int channel, int pan)
{
    if (channel > stream->numChannels - 1) return;
    func_0200945c(1 << stream->chNo[channel], pan);
}

/** ShutdownStrm in the cited source: release the alarm and unlink the active stream. */
void func_0202ad04(SoundStream *stream)
{
    func_02029fbc(stream->alarmNo);
    func_0201fd78(data_0215c9a8, stream);
    stream->isActive = 0;
}

/** AlarmCallback in the cited source: deliver the next buffers as an alarm callback. */
void func_0202ad34(SoundStream *stream)
{
    func_0202ad44(stream, 1);
}

/** BeginSleep__Strm in the cited source: stop playing timers and wait for sound commands. */
void func_0202adf4(SoundStream *stream)
{
    u32 tag;
    if (!stream->isPlaying) return;
    func_02009350(stream->chBitFlag, 0, 1 << stream->alarmNo, 0);
    tag = func_02009ae8();
    func_020098c0(1);
    func_02009a7c(tag);
}
