#include "types.h"

/* CRI/ADX unit 0208d8e8. The surrounding units establish the provider: the
 * "RIFF" scanner and the ADX string helpers live in cri_0208d5ac.c, and this
 * unit's 0x0208daa0/0x0208daac thunks forward to the NitroSDK heap entry
 * points func_02052ff0/func_02053000 (declared as alloc/free by
 * libs/NitroSDK/sdk_0205e318.c and src/game/unit_020946e0.c). */

/* Process-wide CRI memory descriptor. Its initialised contents at
 * data_02149548 are {0x3000, 0x100, data_02149658, data_02149558}: the two
 * pointer words are the address of each region and the two scalars are their
 * sizes. Only the word loads below are observed, so the field names stay
 * neutral. */
typedef struct Cri0208d8e8Memory {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
} Cri0208d8e8Memory;

/* CRI mixer object read by func_0208d95c. Offsets come straight from the
 * original: unknown_34 is added to the running write index, unknown_38 is the
 * s16 destination base, unknown_40 is the destination length and unknown_44 is
 * the current write position; both indices wrap at unknown_40. */
typedef struct Cri0208d8e8Mixer {
    u8 pad_00[0x34];
    u16 unk_34;
    s16 *unk_38;
    u8 pad_3c[0x04];
    s32 unk_40;
    u16 unk_44;
} Cri0208d8e8Mixer;

/* One of the two 0x58-byte voice records allocated by func_0208dad8 and
 * initialised by func_0208dea4 (which reaches a record with
 * `mla index, 0x58, data_02175ccc.unk_08`). Only the fields func_0208dad8
 * clears are named; the rest is padding. */
typedef struct Cri0208d8e8Record {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0c;
    u8 unk_0d;
    u8 unk_0e;
    u8 pad_0f;
    u8 pad_10[0x40];
    u32 unk_50;
    u32 unk_54;
} Cri0208d8e8Record;

/* CRI system singleton at data_02175ccc: initialisation flag, selected mode,
 * the two-record array, its count, the allocator/free hooks and a float
 * initialised to 1.0f. func_0208dab8 tests unk_04 to decide whether a pending
 * notification needs func_020795d8. */
typedef struct Cri0208d8e8System {
    u32 unk_00;
    u32 unk_04;
    Cri0208d8e8Record *unk_08;
    s32 unk_0c;
    void *(*unk_10)(u32);
    void (*unk_14)(void *);
    float unk_18;
} Cri0208d8e8System;

extern Cri0208d8e8Memory data_02149548;
extern u8 data_021750f4[];
extern Cri0208d8e8System data_02175ccc;
extern u8 data_02175cdc[];

extern void *func_02052ff0(u32 size);
extern void func_02053000(void *block);
extern void func_020795d8(void);
extern u32 func_020059d8(u32 mask);
extern void func_020059a8(u32 state);
extern void func_02079360(void *work, u32 length, u8 *buffer, s32 unused);
extern void func_02079374(void *work, u32 length, u8 *buffer, s32 unused);

/** Stores the two configured CRI work-area words through optional outputs.
 * The first output receives the pointer word at offset 8 of
 * data_02149548 and the second the size word at offset 0. Either output may be
 * null; the original guards each store with a separate CMP/LDRNE/STRNE. */
void func_0208d8e8(u32 *address, u32 *size)
{
    if (address != 0)
        *address = data_02149548.unk_08;
    if (size != 0)
        *size = data_02149548.unk_00;
}

/** Stores the second configured CRI work-area pair through optional outputs.
 * This is the offset-12/offset-4 sibling of func_0208d8e8; the initialised
 * data at data_02149548 holds a second pointer/size pair there. */
void func_0208d910(u32 *address, u32 *size)
{
    if (address != 0)
        *address = data_02149548.unk_0c;
    if (size != 0)
        *size = data_02149548.unk_04;
}

/** Clears the word at data_021750f4 + 0x124. That word is the same field
 * func_0208d94c returns and the buffer base func_0208d9bc reads as a u16
 * destination, so this drops the mixer's current output-buffer base. */
void func_0208d938(void)
{
    *(u32 *)(data_021750f4 + 0x124) = 0;
}

/** Returns the word at data_021750f4 + 0x124, the buffer base also cleared by
 * func_0208d938 and consumed as a u16 destination by func_0208d9bc. */
u32 func_0208d94c(void)
{
    return *(u32 *)(data_021750f4 + 0x124);
}

/** Copies `count` signed 16-bit samples into the mixer's circular destination
 * buffer starting at the write position. The start position is the sum of the
 * u16 at offset 0x44 and the u16 at offset 0x34, wrapped once by the signed
 * length at offset 0x40. Each store advances the position, and reaching the
 * length wraps it back to zero (CMP/MOVEQ pair in the original loop). A
 * non-positive count returns without touching the object.
 * The `i = 0` before the count guard and the do/while shape are load-bearing:
 * they make mwccarm emit the original MOV r3, r5 zero-copy and loop rotation
 * instead of MOV r3, #0 plus an extra top test. */
void func_0208d95c(Cri0208d8e8Mixer *mixer, const s16 *source, s32 count)
{
    s32 i;
    s32 position = mixer->unk_44 + mixer->unk_34;

    if (position >= mixer->unk_40)
        position -= mixer->unk_40;
    i = 0;
    if (count <= 0)
        return;
    do {
        mixer->unk_38[position] = source[i];
        position++;
        if (position == mixer->unk_40)
            position = 0;
        i++;
    } while (i < count);
}

/* See DEC-037 for the scoped optimizer setting. */
/** Decodes `count` source samples into the two stereo halves of the current
 * CRI output buffer and reports both halves to the caller. The first half is
 * the word at data_021750f4 + 0x124 (the base returned by func_0208d94c) and
 * the second starts `2 * mixer->unk_40` bytes later; both are written through
 * `output`, which the caller (02084384) passes on as a two-word pair to
 * func_0208636c.
 *
 * Each source sample is mixed with the mixer history sample at the current
 * circular position using weights 3:2, once added and once subtracted, then
 * shifted right by two and clamped to the s16 range. The history position is
 * the u16 at offset 0x44, advanced per sample and wrapped at the length in
 * offset 0x40; it is written back at the end. A non-positive count skips the
 * decode loop but still reports the two halves.
 *
 * The declaration order and the scoped `opt_common_subs off` are load-bearing:
 * mwccarm otherwise rotates the four loop-carried values through a different
 * register set (lr/r4/r5/r6 instead of r4/r5/r6/lr). */
#pragma push
#pragma opt_common_subs off
void func_0208d9bc(Cri0208d8e8Mixer *mixer, const s16 *source, s32 count, u32 *output)
{
    s32 i;
    s16 *dest0;
    s16 *dest1;
    u16 position;
    s32 sample;

    dest0 = (s16 *)*(u32 *)(data_021750f4 + 0x124);
    output[0] = (u32)dest0;
    dest1 = (s16 *)(*(u32 *)(data_021750f4 + 0x124) + (mixer->unk_40 << 1));
    output[1] = (u32)dest1;
    position = mixer->unk_44;
    i = 0;
    if (count <= 0)
        goto end;
    do {
        sample = (source[i] * 3 + mixer->unk_38[position] * 2) >> 2;
        if (sample > 32767)
            sample = 32767;
        else if (sample < -32768)
            sample = -32768;
        dest0[i] = sample;
        sample = (source[i] * 3 - mixer->unk_38[position] * 2) >> 2;
        if (sample > 32767)
            sample = 32767;
        else if (sample < -32768)
            sample = -32768;
        dest1[i] = sample;
        position = (u16)(position + 1);
        if (position == mixer->unk_40)
            position = 0;
        i++;
    } while (i < count);
end:
    mixer->unk_44 = position;
}
#pragma pop

/** Allocates `size` bytes from the CRI heap. The original is a bare
 * LDR IP/BX IP thunk into func_02052ff0; func_0208dad8 calls it with the byte
 * count for its 0x58-byte record array. */
void *func_0208daa0(u32 size)
{
    return func_02052ff0(size);
}

/** Releases a block obtained from func_0208daa0. The original is a bare
 * LDR IP/BX IP thunk into func_02053000. */
void func_0208daac(void *block)
{
    func_02053000(block);
}

/** Drains the CRI work notification when one is pending. data_02175ccc.unk_04
 * holds the pending flag/mode (func_0208dad8 initialises it to zero or one)
 * and func_020795d8 flushes the sound system; the original returns without
 * calling it when the word is zero. */
void func_0208dab8(void)
{
    if (data_02175ccc.unk_04 != 0)
        func_020795d8();
}

/** Initialises the CRI system singleton and its two voice records.
 *
 * The first call returns immediately when data_02175ccc.unk_00 is already set,
 * so the singleton is initialised at most once. Otherwise interrupts are
 * disabled through func_020059d8(1) for the whole initialisation. A
 * variable-length stack buffer of `length` bytes is filled with
 * `(u8)(base + i)` and handed, together with data_02175cdc, to
 * func_02079374 when `flag` is non-zero or to func_02079360 when it is zero;
 * the choice is recorded in unk_04 for func_0208dab8. The original also passes
 * 0 in r3 on the common path to both calls, so the fourth argument is part of
 * the observed outgoing ABI even though both wrappers ignore it.
 *
 * The allocator and free hooks are published in unk_10/unk_14, two
 * 0x58-byte records are allocated through func_0208daa0 and their fields
 * cleared, then unk_00 is set and unk_18 receives 1.0f. The interrupt state is
 * restored with func_020059a8. */
void func_0208dad8(u32 base, u32 length, s32 flag)
{
    u32 state;
    s32 i;
    s32 j;

    if (data_02175ccc.unk_00 != 0)
        return;
    state = func_020059d8(1);
    u8 buffer[length];

    for (i = 0; i < length; i++)
        buffer[i] = (u8)(base + i);
    data_02175ccc.unk_10 = func_0208daa0;
    data_02175ccc.unk_14 = func_0208daac;
    if (flag != 0) {
        func_02079374(data_02175cdc, length, buffer, 0);
        data_02175ccc.unk_04 = 1;
    } else {
        func_02079360(data_02175cdc, length, buffer, 0);
        data_02175ccc.unk_04 = 0;
    }
    data_02175ccc.unk_0c = 2;
    data_02175ccc.unk_08 = func_0208daa0(data_02175ccc.unk_0c * 0x58);
    for (j = 0; j < data_02175ccc.unk_0c; j++) {
        data_02175ccc.unk_08[j].unk_04 = 0;
        data_02175ccc.unk_08[j].unk_08 = 0;
        data_02175ccc.unk_08[j].unk_0c = 0;
        data_02175ccc.unk_08[j].unk_0d = 0;
        data_02175ccc.unk_08[j].unk_0e = 0;
        data_02175ccc.unk_08[j].unk_50 = 0;
        data_02175ccc.unk_08[j].unk_54 = 0;
    }
    data_02175ccc.unk_00 = 1;
    data_02175ccc.unk_18 = 1.0f;
    func_020059a8(state);
}
