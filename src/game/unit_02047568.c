/* src/game/unit_02047568.c: matched functions.
 * Bodies marked "decompiler-derived" were lifted from Ghidra output and cleaned; the
 * remaining functions were reconstructed from the delinked object's disassembly. */
#include "types.h"

/* One-word slot at data_0215ee9c; the two scene-entry helpers below store a value here. */
typedef struct Unk047568Saved {
    u32 value;
} Unk047568Saved;

extern u8 data_0215ee9c[];

int func_0205257c(int mode);
int func_020525cc(int mode);
int func_02052728(void);
int func_0205e590(int mode);
int func_0205e4f8(int id);
int func_020614b0(u8 *data);
int func_02061698(u8 *data);
int func_020a269c(int mode);
int func_020b07c4(int mode);
int func_020ee454(void);
int func_0211b6a8(void);
int Unk09d060_Unk_09d13c(void);
u32 Unk044904_Get_data_0215ee98(void);
void Unk044904_Unk_045480(void);
void func_02048ed8(void);

/* Selects mode 2 via func_0205257c, then stores the value returned by func_020ee454 into
 * data_0215ee9c and reports success. */
int func_02047568(void)
{
    Unk047568Saved saved;
    func_0205257c(2);
    saved.value = func_020ee454();
    *(Unk047568Saved *)data_0215ee9c = saved;
    return 1;
}

/* Returns 0 when func_02052728 reports a pending mode or data_0215ee9c is already
 * registered; otherwise registers it with func_020614b0 and returns 1. */
int Unk047568_Unk_047590(void)
{
    int tmp1;
    tmp1 = func_02052728();
    if (tmp1 != 0) {
        return 0;
    }
    tmp1 = func_02061698(data_0215ee9c);
    if (tmp1 == 0) {
        func_020614b0(data_0215ee9c);
        return 1;
    }
    return 0;
}

/* Per-frame handler for the mode-2 sub-state in `st`: clamps the u16 at +0x38 to 999 and
 * writes it into bits 10..19 of the word at +0x60/+0x3c, then advances st[1] through
 * modes 1..4 and hands back to mode 2. Returns 0 when no mode is active, else 1. */
int func_020475cc(u16 *st)
{
    u32 base;
    u32 obj;
    u32 h;
    u32 v;

    if (Unk09d060_Unk_09d13c() == 0) {
        return 0;
    }

    base = Unk044904_Get_data_0215ee98();
    h = FIELD(u16, base, 56);
    if ((s32)h > 0x3e7) {
        h = 0x3e7;
    }
    obj = FIELD(u32, Unk044904_Get_data_0215ee98(), 0x60);
    v = FIELD(u32, obj, 0x3c);
    v = (v & 0xfff003ff) | ((h << 22) >> 12);
    FIELD(u32, obj, 0x3c) = v;

    if ((s16)st[1] == 1) {
        st[0] = 3;
        obj = FIELD(u32, Unk044904_Get_data_0215ee98(), 0x60);
        v = FIELD(u32, obj, 0x3c);
        v = (v & ~0x3fc) | 8;
        FIELD(u32, obj, 0x3c) = v;
    } else if (func_020b07c4(1) != 0) {
        st[0] = 4;
        obj = FIELD(u32, Unk044904_Get_data_0215ee98(), 0x60);
        v = FIELD(u32, obj, 0x3c);
        v = (v & ~0x3fc) | 12;
        FIELD(u32, obj, 0x3c) = v;
        func_0205e590(10);
    } else if ((s16)st[1] == 2 || func_020b07c4(2) != 0) {
        if ((s16)st[1] == 2) {
            obj = FIELD(u32, Unk044904_Get_data_0215ee98(), 0x60);
            v = FIELD(u32, obj, 0x3c);
            FIELD(u32, obj, 0x3c) = (v & ~0x3fc) | 4;
        } else {
            obj = FIELD(u32, Unk044904_Get_data_0215ee98(), 0x60);
            v = FIELD(u32, obj, 0x3c);
            FIELD(u32, obj, 0x3c) = v & ~0x3fc;
        }
        if (((FIELD(u32, Unk044904_Get_data_0215ee98(), 0x40) << 24) >> 31) == 0) {
            st[0] = 2;
            func_0205257c(2);
            func_0205e590(10);
            func_020a269c(0);
        }
    }
    return 1;
}

/* Resumes the session selected by func_0205e4f8(-1), then runs the shared restore helper;
 * returns 0 when a mode is already pending or the session check fails. */
int Unk047568_Unk_047718(void)
{
    if (func_02052728() != 0) {
        return 0;
    }
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    Unk044904_Unk_045480();
    func_02048ed8();
    return 1;
}

/* Selects mode 2 via func_020525cc, sets bit 0x8000 in the word at +0x40, then stores the
 * value returned by func_0211b6a8 into data_0215ee9c and reports success. */
int func_02047750(void)
{
    Unk047568Saved saved;
    func_020525cc(2);
    FIELD(u32, Unk044904_Get_data_0215ee98(), 0x40) |= 0x8000;
    saved.value = func_0211b6a8();
    *(Unk047568Saved *)data_0215ee9c = saved;
    return 1;
}
