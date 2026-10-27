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
    u32 unk_38;
    u8 pad_3c[0x04];
    s32 unk_40;
    u16 unk_44;
} Cri0208d8e8Mixer;

extern Cri0208d8e8Memory data_02149548;
extern u8 data_021750f4[];
extern u8 data_02175ccc[];

extern void *func_02052ff0(u32 size);
extern void func_02053000(void *block);
extern void func_020795d8(void);

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
        ((s16 *)mixer->unk_38)[position] = source[i];
        position++;
        if (position == mixer->unk_40)
            position = 0;
        i++;
    } while (i < count);
}

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

/** Drains the CRI work notification when one is pending. Offset 4 of
 * data_02175ccc holds the pending flag/handle (func_0208dad8 initialises it to
 * zero) and func_020795d8 flushes the sound system; the original returns
 * without calling it when the word is zero. */
void func_0208dab8(void)
{
    if (*(u32 *)(data_02175ccc + 4) != 0)
        func_020795d8();
}
