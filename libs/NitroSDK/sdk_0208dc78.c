#include "libs/NitroSDK/sdk_0208dc78.h"

extern void func_0208dad8(u32 base, u32 length, s32 flag);
extern u32 func_0207963c(void *callbacks, s32 mode, s32 argument);
extern u8 data_02175cdc[];
extern s32 func_020513d4(const char *path);
extern void func_02079c7c(u32 handle, u32 start, u32 end);
extern void func_02079af0(u32 handle);
extern void func_02079bb0(u32 handle, float volume);
extern void func_02079a68(u32 handle, const char *path);
extern void func_020151fc(void *dest, const void *source, u32 length);
extern void func_0207960c(void);
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

/** Advances pending fades once per notification and submits the sound update.
 * Evidence: +0x50 duration, +0x54 counter and volume-provider calls at 0208dd68.
 * Record storage is borrowed; durations and counters are signed frame counts.
 * See DEC-041 for the explicit byte-offset induction variable. */
void func_0208dd68(void)
{
    s32 i;
    Sdk0208dc78Voice *voice;
    s32 offset;
    float volume;
    float scaled;
    s32 duration;
    if (data_02175ccc.unk_04 == 0) return;
    i = 0;
    if (data_02175ccc.unk_0c > 0) {
        offset = 0;
        do {
            voice = (Sdk0208dc78Voice *)((u8 *)data_02175ccc.unk_08 + offset);
            if (voice->unk_50 != 0) {
                voice->unk_54++;
                if (voice->unk_54 == voice->unk_50) {
                    if (voice->unk_0f == 0) {
                        func_02079b4c(voice->unk_00, 1);
                        voice->unk_0d = 1;
                    } else {
                        func_02079bb0(voice->unk_00, func_0208e1e0());
                    }
                    voice->unk_50 = 0;
                    voice->unk_54 = 0;
                } else {
                    volume = func_0208e1e0();
                    if (voice->unk_0f != 0) {
                        scaled = volume * (float)voice->unk_54;
                        volume = scaled / (float)voice->unk_50;
                    } else {
                        duration = voice->unk_50;
                        volume = volume * (float)(duration - voice->unk_54);
                        volume = volume / (float)duration;
                    }
                    func_02079bb0(voice->unk_00, volume);
                }
            }
            i++;
            offset += 88;
        } while (i < data_02175ccc.unk_0c);
    }
    func_0207960c();
}

/** Assigns an unused voice with provider mode one or two and default timing.
 * Evidence: allocator call, assignment byte and 16-unit end at 0208dea4. */
void func_0208dea4(s32 index, s32 argument, s32 mode)
{
    Sdk0208dc78Voice *voice = &data_02175ccc.unk_08[index];
    if (voice->unk_0c != 0) return;
    voice->unk_00 = func_0207963c(data_02175cdc, argument ? 2 : 1, mode);
    voice->unk_04 = 0;
    voice->unk_08 = 16;
    voice->unk_0c = 1;
    voice->unk_0d = 0;
    voice->unk_50 = 0;
    voice->unk_54 = 0;
}

/** Loads a valid path into an assigned voice, preserving the 64-byte path copy.
 * Evidence: path probe, timing conversion and +0x10 copy at 0208df48.
 * The caller must supply the original 64-byte readable path storage. */
void func_0208df48(s32 index, s32 flag, u32 time, const char *path)
{
    Sdk0208dc78Voice *voice = &data_02175ccc.unk_08[index];
    if (voice->unk_0c == 0) return;
    if (func_020513d4(path) == 0) return;
    voice->unk_04 = (time * 1000) / 60;
    voice->unk_50 = 0;
    voice->unk_54 = 0;
    func_02079c7c(voice->unk_00, voice->unk_04, voice->unk_08);
    func_02079bb0(voice->unk_00, data_02175ccc.unk_18);
    func_02079a68(voice->unk_00, path);
    voice->unk_0e = flag;
    func_020151fc(voice->pad_10, path, 64);
    if (voice->unk_0d != 0) func_0208e0e8(index, 0);
}

/** Sets the assigned voice's end timing in thousandths divided by 60.
 * Evidence: unsigned reciprocal division and timing calls at 0208e008. */
void func_0208e008(s32 index, u32 time)
{
    Sdk0208dc78Voice *voice = &data_02175ccc.unk_08[index];
    if (voice->unk_0c == 0) return;
    voice->unk_08 = (time * 1000) / 60;
    voice->unk_50 = 0;
    voice->unk_54 = 0;
    func_02079c7c(voice->unk_00, voice->unk_04, voice->unk_08);
    func_02079af0(voice->unk_00);
    if (voice->unk_0d != 0) func_0208e0e8(index, 0);
}

/** Starts a stopped assigned voice immediately for zero steps, otherwise fades.
 * Evidence: +0xf clear and conditional start with argument one at 0208e084. */
void func_0208e084(s32 index, s32 step)
{
    Sdk0208dc78Voice *voice = &data_02175ccc.unk_08[index];
    if (voice->unk_0c == 0) return;
    if (voice->unk_0d != 0) return;
    voice->unk_50 = step;
    voice->unk_54 = 0;
    voice->unk_0f = 0;
    if (voice->unk_50 != 0) return;
    func_02079b4c(voice->unk_00, 1);
    voice->unk_0d = 1;
}
