#ifndef SDK_0208DC78_H
#define SDK_0208DC78_H

#include "types.h"

/** One of the two voice records in the CRI sound singleton. Only the fields
 *  touched by this unit are represented; the stride below is 0x58 bytes. */
typedef struct Sdk0208dc78Voice {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0c;
    u8 unk_0d;
    u8 unk_0e;
    u8 unk_0f;
    u8 pad_10[0x40];
    u32 unk_50;
    u32 unk_54;
} Sdk0208dc78Voice;

/** CRI sound singleton at data_02175ccc. The record table and count are
 *  published by func_0208dad8 in cri_0208d8e8.c; unk_18 is the master volume. */
typedef struct Sdk0208dc78System {
    u32 unk_00;
    u32 unk_04;
    Sdk0208dc78Voice *unk_08;
    s32 unk_0c;
    void *(*unk_10)(u32);
    void (*unk_14)(void *);
    float unk_18;
} Sdk0208dc78System;

extern Sdk0208dc78System data_02175ccc;

/** Initialises the CRI voice subsystem and snapshots the master volume. */
void func_0208dc78(void);
/** Flushes the sound system when no notification is pending. */
void func_0208dd44(void);
/** Releases the voice assigned to a record index, if any. */
void func_0208df0c(s32 index);
/** Starts a voice update with the given step value. */
void func_0208e0e8(s32 index, s32 step);
/** Reports whether the indexed voice is currently playing. */
s32 func_0208e13c(s32 index);
/** Reports whether the indexed voice is active or paused. */
s32 func_0208e164(s32 index);
/** Clamps and stores the master volume in the range [0.0, 1.0]. */
void func_0208e1ac(float volume);
/** Returns the stored master volume. */
float func_0208e1e0(void);

#endif
