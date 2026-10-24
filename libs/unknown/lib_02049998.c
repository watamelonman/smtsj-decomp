#include "libs/unknown/lib_02049998.h"

/* SDK copy helper reads source first and writes destination second. */
void func_02008904(const void *source, void *destination, u32 size);

/* Evidence: halfword masks at +4 identify independently updated packed counters. */
int func_02049998(Unk049998Status *status)
{
    if (status->unk_04_2) status->unk_04_2 = 0;
    if (status->unk_04_4) status->unk_04_4 = 0;
    /* Unsigned halfword wrapping decrement, before bitfield truncation. */
    if (status->unk_04_6) status->unk_04_6 = (u16)(status->unk_04_6 + 0xffff);
    if (status->unk_04_8) status->unk_04_8 = (u16)(status->unk_04_8 + 0xffff);
    if (status->unk_04_10) status->unk_04_10 = (u16)(status->unk_04_10 + 0xffff);
    return 0;
}

/* Evidence: signed load at +8 and null check of the leading pointer. */
int func_02049a58(Unk049998Counter *counter)
{
    if (counter->unk_08 < 0) return 0;
    if (!counter->unk_00) return 0;
    counter->unk_08++;
    return 0;
}

/* Evidence: the original compares only the word at offset zero with r1. */
int func_02049a84(const Unk049998Counter *counter, const void *handle)
{
    return counter->unk_00 == handle;
}

/* Evidence: copy call uses offsets 0x248, 0x264 and length 28, then clears bit zero. */
void func_02049a98(Unk049998Work *work)
{
    func_02008904(&work->unk_248, &work->unk_264, 28);
    work->unk_248.unk_18_0 = 0;
}

/* Evidence: sets bit zero at +0x260 before copying 24 bytes to +0x248. */
void func_02049ac0(Unk049998Work *work, const void *source)
{
    work->unk_248.unk_18_0 = 1;
    func_02008904(source, &work->unk_248, 24);
}

/* Evidence: masks 0x3fc and 2 at +0x260 encode a byte and boolean respectively. */
void func_02049aec(Unk049998Work *work, int value, int enabled)
{
    work->unk_248.unk_18_2 = value;
    work->unk_248.unk_18_1 = enabled != 0;
}

/* Evidence: +0x27c flags gate the tag 0xfffe and nonzero byte at +0x268. */
int func_02049b24(const Unk049998Work *work)
{
    if (!work->unk_264.unk_18_0) return 0;
    if (work->unk_264.unk_18_1 == 1) {
        if (((u16)work->unk_264.unk_04 == 0xfffe ?
            (u8)(work->unk_264.unk_04 >> 16) : 0) != 0) return 1;
    }
    return 0;
}

/* Evidence: +0x27c bit zero gates the indexed test of packed bits 2..9. */
int func_02049b7c(const Unk049998Work *work, int bit)
{
    u8 value;
    if (!work->unk_264.unk_18_0) return 0;
    value = work->unk_264.unk_18_2;
    if (value & (1 << bit)) return 1;
    return 0;
}
