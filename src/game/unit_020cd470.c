#include "types.h"

/* Borrowed callback object; only the observed flag is exposed. */
typedef struct Unk0cd470Work {
    u8 reserved[0xc0];
    s32 flag;
} Unk0cd470Work;

/* Descriptor callbacks are stored without invoking them in this unit. */
typedef void (*Unk0cd470Callback)(void *);
typedef struct Unk0cd470Descriptor {
    u32 size;
    u32 flags;
    u32 reserved;
    Unk0cd470Callback callbacks[6];
} Unk0cd470Descriptor;

/* Byte layout follows the accesses in 020cd594; the records have stride 0x1a. */
typedef struct Unk0cd470State {
    u8 state, substate, mode, reserved03;
    s32 field04, field08;
    void *items[4];
    void *handle;
    u8 records[0x74];
    u8 controls[3][0x1c];
    s32 count, selection, fieldf0, fieldf4;
} Unk0cd470State;

extern void func_02057524(s32 value);
extern void func_020572d8(void);
extern void Unk0bc1a8_Unk_0bc504(void *object, s32 value);
extern void func_020cb3dc(void);
extern void Unk095560_Unk_095a2c(void);
extern s32 func_020de8b0(s32 value);
extern void Unk0cb32c_Unk_0cb32c(void);
extern void Unk0bc1a8_Unk_0bc928(s32 id, s32 value, s32 flags);
extern s32 Unk0de678_Get_data_021508d4(void);
extern void Unk0bc1a8_Unk_0bc9b4(s32 id, s32 value);
extern void Unk0cb32c_Unk_0cb344(void);
extern void Unk0de678_Unk_0de870(void);
extern void Unk095560_Unk_0956c8(void);
extern void func_020cd778(void *);
extern void func_020cde1c(void *);
extern void func_020ce3e0(void *);
extern void Unk0cd6ec_Nop_0ce3ec(void *);
extern void func_020cd6ec(void *);
extern void func_020ce3f0(void *);
extern void func_020de960(void *records, s32 mode);
extern void *func_02122abc(void);
extern void ImageBg_Unk_0e54d4(u32 value);
extern void Unk0fd268_Unk_0fd380(s32 value);
extern s32 Unk0de678_CountLeading(void *records);
extern void *func_020ffd48(u32 id, s32 index, s32 count);
extern void func_0212351c(void *handle, s32 count, s32 mode);
extern void Unk0bcef4_Unk_0bcef4(void *control, s32 a, s32 b, s32 c);
extern void Unk1241ec_Unk_124224(u16 value);
extern void Unk0cb32c_Unk_0cb35c(u32 value);
extern void func_02052634(s32 a, s32 b, s32 c);
extern Unk0cd470State *data_02176bcc;

/* 020cd470: run the two helpers only when the borrowed object's +0xc0 flag is set. */
void Unk0cd470_Unk_0cd470(Unk0cd470Work *work)
{
    if (work->flag == 0) return;
    func_02057524(4);
    func_020572d8();
}

/* 020cd490: test the borrowed flag; both paths finish without further work. */
void func_020cd490(Unk0cd470Work *work)
{
    if (work->flag == 0) return;
}

/* 020cd49c: event code 1 forwards the object with a cleared second argument. */
void func_020cd49c(void *object, const u32 *event)
{
    switch (*event) {
    case 0: break;
    case 1: Unk0bc1a8_Unk_0bc504(object, 0); break;
    case 2: break;
    case 3: break;
    case 4: break;
    }
}

/* Existing Enter symbol: initialize shared state and request id 18 when permitted. */
void Unk0cd470_Enter(void)
{
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(0) != 0) return;
    Unk0cb32c_Unk_0cb32c();
    Unk0bc1a8_Unk_0bc928(18, 0xffff, 0);
}

/* 020cd508 is an intentionally empty callback (original consists of bx lr). */
void Unk0cd470_Nop_0cd508(void) { }

/* 020cd50c: conditionally release id 18 before the two unconditional helpers. */
void Unk0cd470_Unk_0cd50c(void)
{
    if (Unk0de678_Get_data_021508d4() == 0) {
        Unk0bc1a8_Unk_0bc9b4(18, 0);
        Unk0cb32c_Unk_0cb344();
    }
    Unk0de678_Unk_0de870();
    Unk095560_Unk_0956c8();
}

/* 020cd538: fill the descriptor's size and six callback slots, leaving +8 intact. */
void func_020cd538(Unk0cd470Descriptor *descriptor)
{
    descriptor->size = 0xf8;
    descriptor->flags = 0;
    descriptor->callbacks[0] = func_020cd778;
    descriptor->callbacks[1] = func_020cde1c;
    descriptor->callbacks[2] = func_020ce3e0;
    descriptor->callbacks[3] = Unk0cd6ec_Nop_0ce3ec;
    descriptor->callbacks[4] = func_020cd6ec;
    descriptor->callbacks[5] = func_020ce3f0;
}

/* 020cd594: initialize a writable 0xf8-byte state. The record producer must
 * supply at most four entries for the item slots; record ids are aligned u16s. */
void func_020cd594(Unk0cd470State *work)
{
    s32 i;
    u8 *record;
    func_020de960(work->records, 2);
    work->handle = func_02122abc();
    ImageBg_Unk_0e54d4(work->records[8]);
    Unk0fd268_Unk_0fd380(2);
    work->count = Unk0de678_CountLeading(work->records);
    i = 0;
    if (work->count > 0) {
        record = (u8 *)work;
        do {
            if (*(u16 *)(work->records + 10) == 0x25c)
                work->items[i] = func_020ffd48(*(u16 *)(record + 0x2a), i - 1, work->count - 1);
            else
                work->items[i] = func_020ffd48(*(u16 *)(record + 0x2a), i, work->count);
            i++;
            record += 0x1a;
        } while (i < work->count);
    }
    work->selection = 0;
    func_0212351c(work->handle, work->count, 1);
    Unk0bc1a8_Unk_0bc928(10, 18, 0);
    Unk0bcef4_Unk_0bcef4(work->controls[0], 3, 3, 1);
    Unk0bcef4_Unk_0bcef4(work->controls[1], 3, 3, 1);
    Unk0bcef4_Unk_0bcef4(work->controls[2], 4, 4, 1);
    data_02176bcc = work;
    work->fieldf0 = 8;
    work->substate = 0;
    work->state = 0;
    work->mode = 2;
    work->fieldf4 = 1;
    work->field04 = 0;
    work->field08 = 0;
    Unk1241ec_Unk_124224((u16)*(u32 *)(work->controls[0] + 0x10));
    Unk0cb32c_Unk_0cb35c(work->records[9]);
    func_02052634(1, 0, 31);
}
