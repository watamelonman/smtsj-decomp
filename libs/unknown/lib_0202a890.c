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
    int format;
    s32 isActive : 1;
    s32 isPlaying : 1;
    s32 reserved : 30;
    u32 bufSize;
    int numBlocks;
    void (*callback)(int isAlarm, int numChannels, void **buffers, u32 blockSize, int format, void *argument);
    void *arg;
    int curBlock;
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


/** Borrowed hardware-channel buffer and relative volume, indexed by channel 0..15. */
typedef struct StreamChannel {
    u8 *buffer;
    int volume;
} StreamChannel;
/** Callback borrows channel buffers for this delivery only; blockSize is bytes. */
typedef void (*StreamBufferCallback)(int, int, void **, u32, int, void *);
extern int data_0215c9a4;
extern StreamChannel data_0215c9f4[];
extern void *data_0215c9b4[];
/** Initialize the borrowed stream list with the link offset in bytes. */
extern void func_0201fc2c(void *list, u16 offset);
/** Lock the selected hardware channels; return zero on failure. */
extern int func_02029ee0(u32 channels);
/** Allocate an alarm, returning a negative number on exhaustion. */
extern int func_02029f74(void);
/** Configure a looping PCM hardware channel; size and loop start are words. */
extern void func_0200947c(int channel, int format, const void *buffer, int loop, u32 loopStart, u32 length, int volume, int shift, int timer, int pan);
/** Schedule the borrowed alarm callback with tick-based start and period. */
extern void func_020093b4(int alarm, u32 start, u32 period, void (*callback)(SoundStream *), SoundStream *argument);
/** Append a borrowed stream to the active list. */
extern void func_0201fc70(void *list, void *object);
/** Disable interrupts and return their previous state. */
extern u32 func_02007a58(void);
/** Restore the previous interrupt state. */
extern void func_02007a6c(u32 state);
/** Convert decibel volume to packed hardware volume and shift. */
extern int func_02009ec0(int volume);
/** Set packed volume components for a hardware channel mask. */
extern void func_02009434(u32 channels, int volume, int shift);
/** Remove the borrowed callback from the pre-sleep list. */
extern void func_0200e7a4(StreamSleepCallback *callback);
/** Remove the borrowed callback from the post-sleep list. */
extern void func_0200e7bc(StreamSleepCallback *callback);
/** Stop active playback; stream ownership stays with the caller. */
extern void func_0202ab84(SoundStream *stream);
/** Release stream alarm/list membership without freeing stream storage. */
extern void func_0202ad04(SoundStream *stream);
/** Deliver alarm-driven stream blocks. */
extern void func_0202ad34(SoundStream *stream);
/** Suspend timers before sleep. */
extern void func_0202adf4(SoundStream *stream);
/** Refill pending blocks and resume after sleep. */
extern void func_0202ae40(SoundStream *stream);

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

/** NNS_SndStrmInit in the cited source: initialize stream flags and borrowed sleep callbacks. */
void func_0202a890(SoundStream *strm) {
    if (!data_0215c9a4) {
        func_0201fc2c(&data_0215c9a8, 0);
        data_0215c9a4 = 1;
    }
    strm->preSleep.callback = (void (*)(void *))func_0202adf4;
    strm->preSleep.argument = strm;
    strm->postSleep.callback = (void (*)(void *))func_0202ae40;
    strm->postSleep.argument = strm;
    strm->chBitFlag = 0;
    strm->numChannels = 0;
    strm->isActive = 0;
    strm->isPlaying = 0;
}

/** NNS_SndStrmAllocChannel in the cited source: lock the supplied hardware channels.
 * chNo has numChannels entries, each in 0..15; stream capacity is 16 channels. */
int func_0202a908(SoundStream *strm, int numChannels, const u8 *chNo) {
    u32 chBitFlag = 0;
    int i;
    for (i = 0; i < numChannels; i++) {
        strm->chNo[i] = chNo[i];
        chBitFlag |= 1 << chNo[i];
    }
    if (!func_02029ee0(chBitFlag)) {
        return 0;
    }
    strm->numChannels = numChannels;
    strm->chBitFlag = chBitFlag;
    return 1;
}

/** NNS_SndStrmSetup in the cited source: partition caller-owned PCM storage, configure
 * channels and alarm, and fill the first block. Channels and numBlocks must be positive.
 * Buffer blocks are rounded down to 32-byte multiples; timer is in units of 32 ticks. */
int func_0202a990(SoundStream *strm, int format, void *buffer, u32 bufSize, u32 timer, u32 numBlocks, StreamBufferCallback callback, void *arg) {
    u32 alarmPeriod, chBufSize;
    u32 blocks = numBlocks;
    int i;
    u32 intrMode;

    if (strm->isActive) {
        func_0202ab84(strm);
    }
    // per channel, a multiple of 32 bytes per block
    chBufSize = bufSize / (strm->numChannels * (blocks << 5));
    chBufSize *= blocks;
    chBufSize <<= 5;
    strm->bufSize = chBufSize;
    alarmPeriod = (timer * (format == 1 ? (chBufSize >> 1) : chBufSize)) / blocks;
    strm->alarmNo = func_02029f74();
    if (strm->alarmNo < 0) {
        return 0;
    }
    for (i = 0; i < strm->numChannels; i++) {
        int chNo = strm->chNo[i];
        data_0215c9f4[chNo].buffer = (u8 *)buffer + strm->bufSize * i;
        data_0215c9f4[chNo].volume = 0;
        func_0200947c(chNo, format, data_0215c9f4[chNo].buffer, 1, 0, strm->bufSize >> 2, 127, 0, timer << 5, 64);
    }
    func_020093b4(strm->alarmNo, alarmPeriod, alarmPeriod, func_0202ad34, strm);
    func_0201fc70(&data_0215c9a8, strm);
    strm->format = format;
    strm->numBlocks = numBlocks;
    strm->callback = callback;
    strm->arg = arg;
    strm->curBlock = 0;
    strm->volume = 0;
    strm->isActive = -1;
    intrMode = func_02007a58();
    strm->numBlocks = 1; // fill the whole buffer at once
    func_0202ad44(strm, 0);
    strm->numBlocks = numBlocks;
    func_02007a6c(intrMode);
    return 1;
}

/** NNS_SndStrmSetVolume in the cited source: add the stream decibel offset to
 * each channel offset and submit the converted hardware volume and shift. */
void func_0202aba0(SoundStream *strm, int volume) {
    int chNo, i;
    strm->volume = volume;
    for (i = 0; i < strm->numChannels; i++) {
        chNo = strm->chNo[i];
        int chVolume = func_02009ec0(strm->volume + data_0215c9f4[chNo].volume);
        func_02009434(1 << chNo, chVolume & 0xFF, chVolume >> 8);
    }
}

/** ForceStopStrm in the cited source: stop timers, remove sleep callbacks, wait
 * for queued commands, then release alarm/list membership. Storage remains borrowed. */
void func_0202ac90(SoundStream *strm) {
    u32 tag;
    if (strm->isPlaying) {
        func_02009350(strm->chBitFlag, 0, 1 << strm->alarmNo, 0);
        func_0200e7a4(&strm->preSleep);
        func_0200e7bc(&strm->postSleep);
        strm->isPlaying = 0;
        tag = func_02009ae8();
        func_020098c0(1);
        func_02009a7c(tag);
    }
    func_0202ad04(strm);
}

/** EndSleep__Strm in the cited source: refill blocks through the loop boundary
 * with interrupts disabled for each delivery, then restart playback timers. */
void func_0202ae40(SoundStream *strm) {
    if (!strm->isPlaying) {
        return;
    }
    while (strm->curBlock != 0) {
        u32 intrMode = func_02007a58();
        func_0202ad44(strm, 1);
        func_02007a6c(intrMode);
    }
    func_02009328(strm->chBitFlag, 0, 1 << strm->alarmNo, 0);
}
