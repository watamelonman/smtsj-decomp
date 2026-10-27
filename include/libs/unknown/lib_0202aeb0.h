#ifndef LIB_0202AEB0_H
#define LIB_0202AEB0_H
#include "types.h"

/* NitroSystem sound capture state. The public reconstruction in
 * ctrl-cheeb-del/pokeheartgold lib/NitroSystem/src/snd_capture.c and
 * lib/include/nnsys/snd_internal.h establishes the field order below; every
 * offset is confirmed by the original ARM loads and stores. */

/** Linear volume fader shared by the capture and fader units. */
typedef struct Unk02aeb0Fader {
    s32 origin;
    s32 target;
    s32 counter;
    s32 frames;
} Unk02aeb0Fader;

/** Capture state embedded at the end of the capture work area. isActive is
 * FALSE while the capture path is torn down, and alarmNo is -1 when no alarm
 * has been allocated. The original block is much larger than the fields the
 * capture helpers touch, so the tail is left as opaque reserved space. */
typedef struct Unk02aeb0CaptureState {
    int isActive;
    int type;
    u32 unk_08;
    void *bufferL;
    void *bufferR;
    u32 bufSize;
    u32 unk_18;
    u32 pos;
    u32 lockedChBitFlag;
    u32 chBitFlag;
    u32 capBitFlag;
    int alarmNo;
    u8 unk_30[0x0c];
    Unk02aeb0Fader fader;
    int isStopping;
    int volume;
    u8 unk_54[0x5b4 - 0x54];
} Unk02aeb0CaptureState;

/** Capture work area; msgQueue and msgs occupy the 0x40 bytes before state. */
typedef struct Unk02aeb0CaptureWork {
    u32 unk_00;
    u32 unk_04;
    u8 msgQueue[0x40];
    Unk02aeb0CaptureState state;
} Unk02aeb0CaptureWork;

/** Borrowed message queue at the start of gSndCaptureWork. */
typedef struct Unk02aeb0MessageQueue {
    u32 words[8];
} Unk02aeb0MessageQueue;

/** Capture work singleton; only state.isActive is read here. */
extern Unk02aeb0CaptureWork data_0215ca74;
/** Capture state alias at gSndCaptureWork + 0x48. */
extern Unk02aeb0CaptureState data_0215cabc;
/** Message queue alias at gSndCaptureWork + 8 (0x0215ca7c). */
extern Unk02aeb0MessageQueue data_0215ca7c;

/** NNSi_SndCaptureInit: clear the work header and mark capture inactive. */
void func_0202aeb0(void);
/** NNSi_SndCaptureMain: fade the reverb volume and stop it when finished. */
void func_0202aec8(void);
/** NNSi_SndCaptureStop: stop timers, release the alarm, locks and output. */
void func_0202af50(void);
/** NNSi_SndCaptureBeginSleep: stop the capture timer for sleep. */
void func_0202b040(void);
/** NNSi_SndCaptureEndSleep: clear the buffers and restart the capture timer. */
void func_0202b0a0(void);

#endif
