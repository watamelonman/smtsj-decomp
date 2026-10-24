#include "types.h"

/* Borrowed work view; field offsets are evidenced by ARM loads/stores in
 * 020e7f0c, 020e8000..020e8078 and 020e8198. Meanings remain unknown. */
typedef struct Unk0e7ac4Work {
    u8 state;
    u8 pad_01[3];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 values[4];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    s32 phase;
    u32 ramp;
    u32 unk_3c;
    u32 selected[4];
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
} Unk0e7ac4Work;

extern Unk0e7ac4Work *data_02176cdc;
extern void func_0205bb68(void);
extern void func_0205ddb4(u32 value);
extern void func_020e7f44(u32 a, u32 b, u32 c, u32 d);

/* Empty callback, evidenced by the sole bx lr at 020e7b7c. */
void Unk0e7ac4_Nop_0e7b7c(void)
{
}

/* Releases the nonzero +0x54 value and clears the singleton; the caller
 * supplies live work. Evidence: calls and stores at 020e7f14..020e7f38. */
void Unk0e7ac4_Unk_0e7f0c(Unk0e7ac4Work *work)
{
    func_0205bb68();
    if (work->unk_54 != 0) {
        func_0205ddb4(work->unk_54);
        work->unk_54 = 0;
    }
    data_02176cdc = 0;
}

/* Forwards the saved four words of live singleton work to 020e7f44;
 * evidence: loads from +0x24..+0x30 at 020e81a4..020e81b0. */
void Unk0e7ac4_Unk_0e8198(void)
{
    Unk0e7ac4Work *work = data_02176cdc;
    func_020e7f44(work->unk_24, work->unk_28, work->unk_2c, work->unk_30);
}

/* Sets +4 only when +0x58 is nonzero; requires live singleton work.
 * Evidence: conditional store at 020e8024. */
void Unk0e7ac4_Unk_0e8014(u32 value)
{
    if (data_02176cdc->unk_58 != 0) {
        data_02176cdc->unk_04 = value;
    }
}

/* Sets +8 only when +0x58 is nonzero; requires live singleton work.
 * Evidence: conditional store at 020e8040. */
void Unk0e7ac4_Unk_0e8030(u32 value)
{
    if (data_02176cdc->unk_58 != 0) {
        data_02176cdc->unk_08 = value;
    }
}

/* Returns +0x58, or zero without work; evidence: conditional load at 020e8070. */
u32 Unk0e7ac4_Unk_0e8060(void)
{
    if (data_02176cdc == 0) {
        return 0;
    }
    return data_02176cdc->unk_58;
}

/* Stores +0x50 in live singleton work; evidence: str at 020e8008. */
void Unk0e7ac4_Unk_0e8000(u32 value)
{
    data_02176cdc->unk_50 = value;
}

/* Stores +0x58 in live singleton work; evidence: str at 020e8054. */
void Unk0e7ac4_Unk_0e804c(u32 value)
{
    data_02176cdc->unk_58 = value;
}

extern int func_02052728(void);
extern void func_020086a0(u32 value, void *dest, u32 size);
extern void func_020086bc(const void *src, void *dest, u32 size);
extern void func_02008904(const void *src, void *dest, u32 size);
extern const void *func_0205e318(u32 handle, u32 index);
extern void func_0205e048(u32 mode, u32 handle, const void *record, u32 x,
                         s32 phase, float sx, float sy, u32 zero, float scale,
                         u32 flags, u32 extra);

/* Copies the helper's 24-byte record before submission; ARM 020e81d4..020e821c
 * establishes the copy size and fixed scale. The handle remains borrowed. */
void func_020e81c0(u32 handle, u32 index, u32 x, s32 phase, u32 flags)
{
    u32 record[6];
    func_02008904(func_0205e318(handle, index), record, 24);
    func_0205e048(2, handle, record, x, phase, 1.0f, 1.0f, 0, 1.0f, flags, 0);
}

/* Advances the byte state and signed phase, then restores four saved words;
 * evidence: 020e7af4..020e7b74. Work must be live. */
void func_020e7ac4(Unk0e7ac4Work *work)
{
    if (func_02052728() != 0) return;
    switch (work->state) {
    case 1:
        if (work->phase > 0) work->phase -= 2;
        if (work->ramp < 0x1f000) work->ramp += 0x18cd;
        break;
    case 2:
        if (work->phase < 20) work->phase += 4;
        else {
            work->state = 1;
            work->phase = 26;
            work->ramp = 0;
            func_020086a0(0, &work->unk_04, 16);
            work->unk_04 = work->values[0];
            work->unk_08 = work->values[1];
            work->unk_0c = work->values[2];
            work->unk_10 = work->values[3];
        }
        break;
    case 3: break;
    }
}

/* Replaces four pending words only on change; 020e7f60..020e7ff4 shows
 * comparison, backup copy, and clearing. Singleton must be live. */
void func_020e7f44(u32 a, u32 b, u32 c, u32 d)
{
    if (data_02176cdc->values[0] == a && data_02176cdc->values[1] == b &&
        data_02176cdc->values[2] == c && data_02176cdc->values[3] == d) return;
    data_02176cdc->state = 2;
    func_020086bc(data_02176cdc->values, &data_02176cdc->unk_24, 16);
    func_020086a0(0, data_02176cdc->values, 16);
    func_020086a0(0, data_02176cdc->selected, 16);
    data_02176cdc->values[0] = a;
    data_02176cdc->values[1] = b;
    data_02176cdc->values[2] = c;
    data_02176cdc->values[3] = d;
}

extern int func_02053d38(u16 *a, u16 *b);
extern int func_02053e44(s32 x, s32 y, s32 width, s32 height, u32 mode, u32 extra);

/* Tracks the last of four hit rectangles and returns a confirmed index or -1;
 * evidence: 020e8094..020e8188. Singleton must be live. */
s32 func_020e807c(void)
{
    s32 selected = -1;
    s32 i;
    u16 a, b;
    for (i = 0; i < 4; i++) {
        if (data_02176cdc->selected[i]) selected = i;
    }
    if (selected >= 0) {
        if (func_02053d38(&a, &b) == 0) {
            func_020086a0(0, data_02176cdc->selected, 16);
            if (func_02053e44(selected * 64, 176, 64, 16, 2, 0)) return selected;
        }
    } else {
        s32 slot;
        s32 x;
        for (slot = 0, x = 0; slot < 4; slot++, x += 64) {
            if (func_02053e44(x, 176, 64, 16, 1, 0)) selected = slot;
        }
        if (selected >= 0) data_02176cdc->selected[selected] = 1;
    }
    return -1;
}

extern void func_02057524(u32 mode);
extern void func_02057e58(u32 a, u32 b, u32 c);
extern void func_02057df8(void);
extern void func_02057eb8(s32 value);
extern void func_02057fd8(void);
extern void func_02057e18(u32 value);
extern void func_02057ddc(u32 value);
extern void func_020572d8(void);
extern void func_0205dee8(u32 mode, u32 handle, u32 index, u32 x, s32 phase,
                         float sx, float sy, u32 zero, float scale, u32 flags);

/* Submits two entries while +0x58 and +0x50 are enabled; ARM
 * 020e7b88..020e7d34 supplies phase clamps and helper arguments. */
void func_020e7b80(Unk0e7ac4Work *work)
{
    s32 phase;
    if (work->unk_58 == 0 || work->unk_50 == 0) return;
    func_02057524(6);
    func_02057e58(2, 40, 3);
    switch (work->state) {
    case 1:
    case 2:
        func_02057df8();
        func_02057eb8(2);
        func_02057fd8();
        func_02057e18(31);
        phase = work->phase - 6;
        if (phase < 0) phase = 0;
        if (work->unk_04 == 0) func_020e81c0(work->unk_54, 2, 0, phase, 9);
        else {
            func_020e81c0(work->unk_54, 0, 0, phase, 15);
            func_02057ddc(0xafffe7ff);
            func_0205dee8(2, work->unk_54, work->unk_04 + 2, 0, phase,
                          1.0f, 1.0f, 0, 1.0f, 15);
        }
        func_02057df8();
        phase = work->phase - 4;
        if (phase < 0) phase = 0;
        if (work->unk_08 == 0) func_020e81c0(work->unk_54, 2, 64, phase, 9);
        else {
            func_020e81c0(work->unk_54, 0, 64, phase, 14);
            func_02057ddc(0xafffe7ff);
            func_0205dee8(2, work->unk_54, work->unk_08 + 2, 64, phase,
                          1.0f, 1.0f, 0, 1.0f, 15);
            func_02057df8();
        }
        func_02057e18(31);
        func_02057eb8(-1);
        func_02057df8();
        break;
    case 3: break;
    }
    func_020572d8();
}

/* Submits four entries while +0x58 is clear and +0x50 enabled; ARM
 * 020e7d48..020e7f00 supplies selection tint and staggered phase clamps. */
void func_020e7d40(Unk0e7ac4Work *work)
{
    s32 i, phase, x;
    if (work->unk_58 != 0) return;
    if (work->unk_50 == 0) return;
    func_02057524(4);
    func_02057e58(2, 40, 3);
    switch (work->state) {
    case 1:
    case 2:
        func_02057eb8(2);
        func_02057fd8();
        func_02057e18(31);
        for (i = 0, x = 0; i < 4; x += 64, i++) {
            func_02057df8();
            phase = work->phase - (3 - i) * 2;
            if (phase < 0) phase = 0;
            if ((&work->unk_04)[i] == 0) {
                func_020e81c0(work->unk_54, 2, x, phase, 9);
            } else if (work->selected[i]) {
                func_020e81c0(work->unk_54, 1, x, phase, 9);
                func_02057ddc(255);
                func_0205dee8(2, work->unk_54, (&work->unk_04)[i] + 2, x,
                              phase, 1.0f, 1.0f, 0, 1.0f, 10);
            } else {
                func_020e81c0(work->unk_54, 0, x, phase, 9);
                func_02057ddc(0xafffe7ff);
                func_0205dee8(2, work->unk_54, (&work->unk_04)[i] + 2, x,
                              phase, 1.0f, 1.0f, 0, 1.0f, 10);
            }
        }
        func_02057df8();
        func_02057e18(31);
        func_02057eb8(-1);
        break;
    case 3: break;
    }
    func_020572d8();
}
