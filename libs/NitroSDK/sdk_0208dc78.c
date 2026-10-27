#include "libs/NitroSDK/sdk_0208dc78.h"

extern void func_0208dad8(u32 base, u32 length, s32 flag);
extern void func_0208dea4(s32 index, s32 argument, s32 mode);
extern float func_0205e5dc(void);
extern void func_020795b8(void);
extern void func_02029e6c(void);
extern void func_0207990c(u32 handle);
extern void func_02079b4c(u32 handle, s32 argument);
extern s32 func_020799d4(u32 handle);

/** Initialises the four-byte CRI work area with a nonzero notification flag,
 *  prepares voice zero, then copies the current master volume into the
 *  singleton. Evidence: the three literal arguments and the store through
 *  data_02175ccc + 0x18 at 0208dc78..0208dcb0. */
void func_0208dc78(void)
{
    func_0208dad8(0, 4, 1);
    func_0208dea4(0, 1, 1);
    data_02175ccc.unk_18 = func_0205e5dc();
}

/** Flushes the sound system after the register update only when the singleton
 *  has no pending notification. Evidence: the +4 load, CMP and conditional
 *  call to func_02029e6c at 0208dd44..0208dd68. */
void func_0208dd44(void)
{
    func_020795b8();
    if (data_02175ccc.unk_04 == 0)
        func_02029e6c();
}

/** Releases the indexed voice through func_0207990c and clears its assigned
 *  and playing bytes. Evidence: the 0x58 stride, the +0xc guard, the +0x00
 *  handle load and the pair of byte clears at 0208df0c..0208df48. */
void func_0208df0c(s32 index)
{
    Sdk0208dc78Voice *voice = &data_02175ccc.unk_08[index];

    if (voice->unk_0c == 0)
        return;
    func_0207990c(voice->unk_00);
    voice->unk_0c = 0;
    voice->unk_0d = 0;
}

/** Starts a voice update with the caller's step value: stores the step and a
 *  zero position, marks the reverse-update byte, then notifies the voice
 *  handle with a zero argument and clears the playing byte. Evidence: the
 *  +0x50/+0x54 stores, the +0xf set, the func_02079b4c call with r1=0 and the
 *  +0xd clear at 0208e0e8..0208e13c. See DEC-040 for the zero argument. */
void func_0208e0e8(s32 index, s32 step)
{
    Sdk0208dc78Voice *voice = &data_02175ccc.unk_08[index];

    if (voice->unk_0c == 0 || voice->unk_0d == 0)
        return;
    voice->unk_50 = step;
    voice->unk_54 = 0;
    voice->unk_0f = 1;
    func_02079b4c(voice->unk_00, 0);
    voice->unk_0d = 0;
}

/** Returns the indexed voice's playing byte as a boolean. Evidence: the 0x58
 *  stride, the +0xd byte load and the MOVNE/MOVEQ result at 0208e13c..0208e164. */
s32 func_0208e13c(s32 index)
{
    return data_02175ccc.unk_08[index].unk_0d != 0;
}

/** Reports whether the indexed voice's status query returns one (active) or
 *  two (paused). Evidence: the 0x58 stride, the handle load and the
 *  CMP/BEQ/CMP/BNE chain around func_020799d4 at 0208e164..0208e1ac.
 *
 *  The goto/switch shape is load-bearing: a plain if-chain lets mwccarm fold
 *  the two one returns into conditional moves, while this form keeps the
 *  original beq/bne blocks and their duplicate return-one bodies.
 *  See DEC-040. */
s32 func_0208e164(s32 index)
{
    s32 status = func_020799d4(data_02175ccc.unk_08[index].unk_00);

    if (status == 1)
        goto active;
    switch (status) {
    case 2:
        return 1;
    default:
        goto inactive;
    }
active:
    return 1;
inactive:
    return 0;
}

/** Clamps the master volume to [0.0, 1.0] and stores it in the singleton.
 *  Evidence: the float compares against zero and 0x3f800000, the MOVLO/MOVHI
 *  clamps and the store through data_02175ccc + 0x18 at 0208e1ac..0208e1e0. */
void func_0208e1ac(float volume)
{
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 1.0f)
        volume = 1.0f;
    data_02175ccc.unk_18 = volume;
}

/** Returns the stored master volume. Evidence: the +0x18 word load and BX LR
 *  at 0208e1e0..0208e1f0; func_0208dc78 and func_0208e1ac write that word. */
float func_0208e1e0(void)
{
    return data_02175ccc.unk_18;
}
