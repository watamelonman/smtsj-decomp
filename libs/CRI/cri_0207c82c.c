#include "types.h"

/* Partial CRI record layout established by loads/stores in this unit.
 * The cleanup helper clears the entire 0xb4-byte allocation. */
typedef struct Unk0207c82c {
    s8 unk_00;
    s8 unk_01;
    s8 unk_02;
    s8 unk_03;
    void *unk_04;
    s32 unk_08;
    void *unk_0c[8];
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u8 pad_50[8];
    s32 unk_58;
    s32 unk_5c;
    u8 pad_60[0x40];
    s32 unk_a0;
    u32 unk_a4;
    s32 unk_a8;
    s32 unk_ac;
    u32 unk_b0;
} Unk0207c82c;

void func_0207a278(void *handle);
void func_0207ae14(void);
void func_0207ae20(void);
void *func_020119c0(void *dest, int value, u32 size);
s32 func_02079ea0(void *handle, s32 value);
s32 func_02079ec4(void *handle, s32 value);
s32 func_02079f24(void *handle);
void func_0207a96c(void *handle);

extern Unk0207c82c data_02172dac[4];
s32 func_020815b0(void *source);
s32 func_02081628(void *source);
s32 func_020816a0(void *source);
void *func_0207a1ac(s32 count, s32 value, s32 half, s32 total);
void func_0207ccb0(Unk0207c82c *work, s32 *first, s32 *second, s32 *third);
void func_0207a6d8(void *handle,
                   void (*callback)(Unk0207c82c *, s32 *, s32 *, s32 *),
                   Unk0207c82c *work);

/* Resets the observed counters and limits; ARM stores establish the offsets
 * and the 0x7fffffff/-1 sentinels. Other record fields are preserved. */
void func_0207c82c(Unk0207c82c *work)
{
    work->unk_a0 = 0;
    work->unk_2c = 0;
    work->unk_30 = 0;
    work->unk_34 = 0;
    work->unk_38 = 0x7fffffff;
    work->unk_3c = -1;
    work->unk_40 = 0;
    work->unk_44 = 0;
    work->unk_03 = 0;
    work->unk_a8 = 0;
    work->unk_ac = 0;
}

/* Claims the first free record and creates its handle. The scan/stride at
 * 0207c884 and stores at 0207c914 establish this contract. sources must contain
 * count pointers (and at least one); count must fit the record's pointer area.
 * Returns null if all four records are occupied or handle creation fails. */
Unk0207c82c *func_0207c868(s32 value, s32 count, void **sources)
{
    s32 first;
    Unk0207c82c *work;
    s32 half;
    void *source = sources[0];
    s32 i;
    s32 total;

    for (i = 0; i < 4; i++) {
        if (data_02172dac[i].unk_00 == 0) break;
    }
    if (i == 4) return 0;
    work = &data_02172dac[i];
    first = func_020815b0(source);
    half = func_02081628(source) / 2;
    total = func_020816a0(source) / 2;
    work->unk_04 = func_0207a1ac(count, first, half, half + total);
    if (work->unk_04 == 0) return 0;
    func_0207a6d8(work->unk_04, func_0207ccb0, work);
    work->unk_08 = value;
    work->unk_02 = count;
    for (i = 0; i < count; i++) work->unk_0c[i] = sources[i];
    work->unk_01 = 0;
    func_0207c82c(work);
    work->unk_48 = 0;
    work->unk_4c = 0;
    work->unk_58 = 0;
    work->unk_5c = 0;
    work->unk_00 = 1;
    return work;
}

/* Accepts null; detaches the offset-4 handle before releasing it, then clears
 * all 0xb4 bytes between the paired calls seen in the original. */
void func_0207c978(Unk0207c82c *work)
{
    if (work == 0) return;
    if (work->unk_04 != 0) {
        void *handle = work->unk_04;
        work->unk_04 = 0;
        func_0207a278(handle);
    }
    func_0207ae14();
    func_020119c0(work, 0, 0xb4);
    func_0207ae20();
}

/* Returns the signed state byte, as established by the original LDRSB. */
s32 func_0207c9b8(const Unk0207c82c *work)
{
    return work->unk_01;
}

/* Stores offset 8 and forwards the value to the offset-4 handle; evidence:
 * STR at 0207c9c4 followed by the tail call to 02079ea0. */
s32 func_0207c9c0(Unk0207c82c *work, s32 value)
{
    work->unk_08 = value;
    return func_02079ea0(work->unk_04, value);
}

/* Updates the offset-38 limit and forwards it; the original stores before
 * tail-calling 02079ec4. The handle must be valid for that callee. */
s32 func_0207c9d4(Unk0207c82c *work, s32 value)
{
    work->unk_38 = value;
    return func_02079ec4(work->unk_04, value);
}

/* Forwards the offset-4 handle to 02079f24, preserving its result. */
s32 func_0207c9e8(Unk0207c82c *work)
{
    return func_02079f24(work->unk_04);
}

/* Resets counters/limits before setting state to one; BL/STRB order in the
 * original requires the state update to follow the reset. */
void func_0207c9f8(Unk0207c82c *work)
{
    func_0207c82c(work);
    work->unk_01 = 1;
}

/* Calls 0207a96c on the handle before clearing the state byte, as evidenced
 * by the original BL followed by STRB at offset 1. */
void func_0207ca10(Unk0207c82c *work)
{
    func_0207a96c(work->unk_04);
    work->unk_01 = 0;
}
