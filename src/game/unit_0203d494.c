/* Script handlers; offsets and control flow follow the ARM original. */
#include "types.h"

/* Borrowed query record: three halfword ids at the observed +0x40 offset. */
typedef struct { u8 padding[0x40]; u16 values[3]; } QueryRecord;
/* Borrowed slot record: six halfword ids at the observed +0x28 offset. */
typedef struct { u8 padding[0x28]; u16 values[6]; } SlotRecord;

s32 func_0203ac00(s32 index);
void Unk03aae8_Unk_03acf4(u32 value);
u8 *Unk02e000_GetWorkArea(void);
u8 *Unk02e000_Unk_02e7c0(s32 index);
u8 *Unk09974c_Unk_099c60(void);
u8 *Unk03aae8_Unk_03ad14(void);
u16 Unk02f2a8_Unk_035b08(s32 first, s32 second);
void func_0209e33c(u32 id, s32 first, s32 second, s32 third);
u32 func_02098050(s32 selector);
float func_02097f68(s32 selector);

/* Count nonzero matching halfwords in eligible work records; ARM evidence:
 * work +0x40 has three entries, slot +0x28 has six, statuses 1/7/6 exclude. */
s32 func_0203d494(void)
{
    s16 id = func_0203ac00(0);
    s32 include = func_0203ac00(1) != 0;
    u8 *work = Unk02e000_GetWorkArea();
    s32 count = 0;
    s32 excluded;
    s32 i, j;
    if (include) {
        excluded = 0;
        if (FIELD(u16, work, 0x6c) == 1 ||
            FIELD(u16, work, 0x6c) == 7 ||
            FIELD(u16, work, 0x6c) == 6 ||
            FIELD(s16, work, 0x1c) <= 0)
            excluded = 1;
        if (!excluded && FIELD(u16, work, 2) != 0) {
            work = Unk09974c_Unk_099c60();
            for (j = 0; j < 3; j++) {
                if (((QueryRecord *)work)->values[j] != 0 &&
                    id == ((QueryRecord *)work)->values[j])
                    count++;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        work = Unk02e000_Unk_02e7c0(i);
        if (work != 0) {
            excluded = 0;
            if (FIELD(u16, work, 0x34) == 1 ||
                FIELD(u16, work, 0x34) == 7 ||
                FIELD(u16, work, 0x34) == 6 ||
                FIELD(s16, work, 0x1e) <= 0)
                excluded = 1;
            if (!excluded) {
                for (j = 0; j < 6; j++) {
                    if (((SlotRecord *)work)->values[j] != 0 &&
                        id == ((SlotRecord *)work)->values[j])
                        count++;
                }
            }
        }
    }
    Unk03aae8_Unk_03acf4(count);
    return 1;
}

/* Publish selector-2 query as an integer; ARM calls _ffix for mode 1. */
u32 Unk03d494_Unk_03d5c8(void)
{
    s32 mode = func_0203ac00(0);
    s32 value = 0;
    if (mode == 0)
        value = func_02098050(2);
    else if (mode == 1)
        value = (s32)func_02097f68(2);
    Unk03aae8_Unk_03acf4(value);
    return 1;
}

/* Forward signed 16-bit script arguments with work id +0x35c, then set
 * context +0xe8's state (+0x18) to 15, as stored by the ARM original. */
s32 Unk03d494_Unk_03d618(void)
{
    s16 a, b, c;
    u8 *o;
    func_0203ac00(0);
    a = func_0203ac00(1);
    b = func_0203ac00(2);
    c = func_0203ac00(3);
    func_0209e33c(FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 92), a, b, c);
    o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 15;
    return 3;
}

/* Select the work id when either signed index is negative; otherwise resolve
 * the pair. ARM then forwards three signed halfwords and sets state 15. */
s32 func_0203d688(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    s16 d = func_0203ac00(3);
    s16 e = func_0203ac00(4);
    u32 id;
    u8 *o;
    if (a < 0 || b < 0)
        id = FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 92);
    else
        id = Unk02f2a8_Unk_035b08(a, b);
    func_0209e33c(id, c, d, e);
    o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 15;
    return 3;
}
