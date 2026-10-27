/* NitroSystem sound capture helpers. The implementations follow
 * ctrl-cheeb-del/pokeheartgold lib/NitroSystem/src/snd_capture.c, whose
 * function order (Init, Main, Stop, BeginSleep, EndSleep) and field offsets
 * match this delinked object. The symbol configuration is human-owned, so the
 * linker names stay neutral and the descriptive names live in comments. */
#include "libs/unknown/lib_0202aeb0.h"

#define SND_CAPTURE_TYPE_REVERB 0
#define SND_CAPTURE_TYPE_EFFECT 1
#define SND_CMD_FLAG_BLOCK      1
#define OS_MESSAGE_NOBLOCK      0

/** Advance a fader toward its target by one frame. */
extern void func_0202caa4(Unk02aeb0Fader *fader);
/** Return the current fader value, or the target once the fade is finished. */
extern s32 func_0202ca70(Unk02aeb0Fader *fader);
/** Return whether the fader has reached its target. */
extern int func_0202cabc(Unk02aeb0Fader *fader);
/** Stop the sound timers selected by the channel, capture and alarm masks. */
extern void func_02009350(u32 chBitFlag, u32 capBitFlag, u32 alarmBitFlag,
                          u32 flags);
/** Start the sound timers selected by the channel, capture and alarm masks. */
extern void func_02009328(u32 chBitFlag, u32 capBitFlag, u32 alarmBitFlag,
                          u32 flags);
/** Set the volume of the channels selected by the channel mask. */
extern void func_02009434(u32 chBitFlag, int volume, int pan);
/** Select the capture output source. */
extern void func_02009528(u32 a, u32 b, u32 c, u32 d);
/** Return the tag of the most recently queued sound command. */
extern u32 func_02009ae8(void);
/** Block until the command queue has been flushed. */
extern void func_020098c0(u32 flags);
/** Wait until the command identified by tag has been processed. */
extern void func_02009a7c(u32 tag);
/** Receive a message from a queue; returns zero when the queue is empty. */
extern int func_02006934(Unk02aeb0MessageQueue *queue, void *message,
                         u32 flags);
/** Release a previously locked capture mask. */
extern void func_02029f58(u32 capBitFlag);
/** Release a previously locked sound-channel mask. */
extern void func_02029f28(u32 chBitFlag);
/** Release an allocated alarm number. */
extern void func_02029fbc(int alarmNo);
/** Fill a byte range with a 32-bit value. */
extern void func_020086a0(u32 value, void *dest, u32 size);
/** Flush a byte range from the data cache. */
extern void func_02006c94(void *address, u32 size);

/** NNSi_SndCaptureInit: clear the work header and mark capture inactive. */
void func_0202aeb0(void)
{
    data_0215ca74.unk_00 = 0;
    data_0215ca74.state.isActive = 0;
}

/** NNSi_SndCaptureMain: fade the reverb volume and stop it when finished. */
void func_0202aec8(void)
{
    Unk02aeb0CaptureState *state = &data_0215cabc;
    int volume;

    if (!data_0215ca74.state.isActive) {
        return;
    }
    if (state->type != SND_CAPTURE_TYPE_REVERB) {
        return;
    }
    func_0202caa4(&state->fader);
    if (state->isStopping && func_0202cabc(&state->fader)) {
        func_0202af50();
        return;
    }
    volume = func_0202ca70(&state->fader) >> 8;
    if (volume == state->volume) {
        return;
    }
    func_02009434(state->chBitFlag, volume, 0);
    state->volume = volume;
}

/** NNSi_SndCaptureStop: stop timers, release the alarm, locks and output. */
void func_0202af50(void)
{
    Unk02aeb0CaptureState *state = &data_0215cabc;
    int hasAlarm;
    u32 alarmBitFlag;

    if (!data_0215ca74.state.isActive) {
        return;
    }
    hasAlarm = state->alarmNo >= 0;
    alarmBitFlag = hasAlarm ? (1u << state->alarmNo) : 0;
    func_02009350(state->chBitFlag, state->capBitFlag, alarmBitFlag, 0);
    if (hasAlarm) {
        u32 tag = func_02009ae8();
        func_020098c0(SND_CMD_FLAG_BLOCK);
        func_02009a7c(tag);
        while (func_02006934(&data_0215ca7c, 0, OS_MESSAGE_NOBLOCK)) {
        }
    }
    if (state->capBitFlag) {
        func_02029f58(state->capBitFlag);
    }
    if (state->lockedChBitFlag) {
        func_02029f28(state->lockedChBitFlag);
    }
    if (hasAlarm) {
        func_02029fbc(state->alarmNo);
    }
    if (state->type == SND_CAPTURE_TYPE_EFFECT) {
        func_02009528(0, 0, 0, 0);
    }
    state->isActive = 0;
}

/** NNSi_SndCaptureBeginSleep: stop the capture timer for sleep. */
void func_0202b040(void)
{
    Unk02aeb0CaptureState *state = &data_0215cabc;
    u32 tag;

    if (!data_0215ca74.state.isActive) {
        return;
    }
    func_02009350(state->chBitFlag, state->capBitFlag,
                  state->alarmNo >= 0 ? (1u << state->alarmNo) : 0, 0);
    tag = func_02009ae8();
    func_020098c0(SND_CMD_FLAG_BLOCK);
    func_02009a7c(tag);
}

/** NNSi_SndCaptureEndSleep: clear the buffers and restart the capture timer. */
void func_0202b0a0(void)
{
    Unk02aeb0CaptureState *state = &data_0215cabc;

    if (!data_0215ca74.state.isActive) {
        return;
    }
    state->pos = 0;
    func_020086a0(0, state->bufferL, state->bufSize);
    func_020086a0(0, state->bufferR, state->bufSize);
    func_02006c94(state->bufferL, state->bufSize);
    func_02006c94(state->bufferR, state->bufSize);
    func_02009328(state->chBitFlag, state->capBitFlag,
                  state->alarmNo >= 0 ? (1u << state->alarmNo) : 0, 0);
}
