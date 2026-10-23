#include "types.h"

/* Layout follows the pointer loads at +0/+4 and resource accesses at +8/+0xc/+0x10. */
typedef struct Unk109dccWork {
    u32 *current;
    u32 *maximum;
    void *unk08;
    void *unk0c;
    void *unk10;
} Unk109dccWork;

/* The copied 24-byte record has a signed extent at byte 12. */
typedef struct Unk109dccRecord {
    u8 unk00[12];
    s16 extent;
    u8 unk0e[10];
} Unk109dccRecord;

extern void func_0205c704(void *);
extern void func_02061424(Unk109dccWork *);
extern void func_0205c3dc(void *);
extern void func_020580ec(int);
extern void func_02057524(int);
extern void func_02057df8(void);
extern void func_02057534(void);
extern void func_0205de40(int, void *, int, int, int, float, float, int, float, int);
extern void *func_0205e318(void *, int);
extern void func_02008904(const void *, void *, u32);
extern void func_0205e048(int, void *, Unk109dccRecord *, int, int, float, float, int, float, int, int);
extern void func_0205c748(int, void *, int, int, float, float, int, float, int);
extern Unk109dccWork *func_020611dc(void (*)(Unk109dccWork *), void (*)(Unk109dccWork *), int, void (*)(Unk109dccWork *), int, int, int, int);
extern void *func_0205c3c0(void);
extern void func_0205c3fc(void *, void *, void *);
extern void func_0205c408(void *, int);
extern void func_0205c6e0(void *);

/* Update the +0x10 resource and finish work when the pointed-to maximum is zero. */
void Unk109dcc_Unk_109dcc(Unk109dccWork *work)
{
    func_0205c704(work->unk10);
    if (*work->maximum != 0) return;
    func_02061424(work);
}

/* Submit records 20/21; the latter's extent follows the current/maximum ratio. */
void func_02109df8(Unk109dccWork *work)
{
    Unk109dccRecord record;
    int extent;
    func_020580ec(0);
    func_02057524(7);
    func_02057df8();
    func_0205de40(2, work->unk08, 4, 0, 0, 1.0f, 1.0f, 0, 1.0f, 20);
    if (*work->maximum == 0 || *work->current >= *work->maximum) {
        func_0205de40(1, work->unk08, 3, 0, 0, 1.0f, 1.0f, 0, 1.0f, 21);
    } else {
        func_02008904(func_0205e318(work->unk08, 3), &record, 24);
        extent = record.extent;
        record.extent = (extent * *work->current) / *work->maximum;
        if (record.extent <= 0) record.extent = 1;
        if (record.extent > extent) record.extent = extent;
        func_0205e048(1, work->unk08, &record, 0, 0, 1.0f, 1.0f, 0, 1.0f, 21, 0);
    }
    func_0205c748(2, work->unk10, 0, 0, 1.0f, 1.0f, 0, 1.0f, 20);
    func_02057534();
    func_020580ec(1);
}

/* Release the optional resource at +0x10 and clear its ownership slot. */
void Unk109dcc_Unk_109f70(Unk109dccWork *work)
{
    if (work->unk10 == 0) return;
    func_0205c3dc(work->unk10);
    work->unk10 = 0;
}

/* Allocate 20 bytes with these callbacks and initialize the +0x10 resource. */
Unk109dccWork *func_02109f94(u32 *current, u32 *maximum, void *arg2, void *arg3)
{
    Unk109dccWork *work = func_020611dc(Unk109dcc_Unk_109dcc, func_02109df8, 0,
        Unk109dcc_Unk_109f70, 20, 4, 101, 1);
    work->current = current;
    work->maximum = maximum;
    work->unk08 = arg2;
    work->unk0c = arg3;
    work->unk10 = func_0205c3c0();
    func_0205c3fc(work->unk10, work->unk08, work->unk0c);
    func_0205c408(work->unk10, 0);
    func_0205c6e0(work->unk10);
    return work;
}
