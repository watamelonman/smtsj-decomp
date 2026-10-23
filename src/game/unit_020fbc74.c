#include "types.h"

/* Private view of the 96-byte work block; unknown members retain offset names. */
typedef struct Work0fbc74 {
    s32 state;
    u8 unk_04[36];
    s32 current;
    s32 pending;
    void *unk_30;
    void *unk_34;
    u16 offset;
    u8 pad_3a[2];
    s32 limit;
    void *handles[4];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
} Work0fbc74;

void func_0205c3dc(void *handle);
void Unk0d297c_Unk_0d33ac(void *block);
void func_020629c4(void *handle);
u32 Unk0d297c_Unk_0d2f18(s32 id);
void func_02061f10(void *handle, s32 a, s32 b, s32 c, u32 value);
void Unk0a0ce4_Unk_0a0da4(s32 value);
void func_02061424(Work0fbc74 *work);
void func_020fb634(Work0fbc74 *work);
void func_020fb858(Work0fbc74 *work);
Work0fbc74 *func_020611dc(void (*a)(Work0fbc74 *), void (*b)(Work0fbc74 *),
    s32 zero, void (*cleanup)(Work0fbc74 *), s32 size, s32 one, s32 zero2, s32 one2);
void *func_0205c3c0(void);
void func_0205c3fc(void *handle, s32 a, s32 b);
void func_0205c408(void *handle, s32 value);
void func_0205c6e0(void *handle);
void *func_020629ac(s32 a, s32 b, s32 c, s32 d);
void func_02061e98(void *handle, s32 a, s32 b);

/* Release the work block's four optional handles and its two auxiliary handles. */
void func_020fbc74(Work0fbc74 *work)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        if (work->handles[i] != 0) {
            func_0205c3dc(work->handles[i]);
            work->handles[i] = 0;
        }
    }
    if (work->current > 0) {
        Unk0d297c_Unk_0d33ac(work->unk_04);
    }
    func_020629c4(work->unk_30);
    func_020629c4(work->unk_34);
}

/* Queue a changed id; state 4 also records it as current and advances to state 5. */
void Unk0fbc74_Unk_0fbcd4(Work0fbc74 *work, s32 id)
{
    u32 value;
    if (work->current == id) return;
    value = Unk0d297c_Unk_0d2f18(id);
    func_02061f10(work->unk_34, -1, 0, 0, value);
    if (work->state == 4) {
        work->current = id;
        work->pending = id;
        work->state = 5;
        return;
    }
    work->pending = id;
}

/* In state 4, reset a nonzero offset and request state 7; report an already-zero offset. */
int Unk0fbc74_Unk_0fbd30(Work0fbc74 *work)
{
    if (work->state != 4) return 0;
    if (work->offset == 0) return 1;
    work->offset = 0;
    work->state = 7;
    Unk0a0ce4_Unk_0a0da4(2);
    return 0;
}

/* Advance the state-4 offset by ten, wrapping at the signed limit; report a change. */
int Unk0fbc74_Unk_0fbd74(Work0fbc74 *work)
{
    u16 old;
    if (work->state != 4) return 0;
    old = work->offset;
    work->offset = old + 10;
    if (work->offset >= work->limit) work->offset = 0;
    if (work->offset != old) {
        work->state = 7;
        return 1;
    }
    return 0;
}

/* Request the external transition only in state 4, returning whether it was requested. */
u32 Unk0fbc74_Unk_0fbdc4(Work0fbc74 *work)
{
    if (work->state == 4) {
        func_02061424(work);
        return 1;
    }
    return 0;
}

/* Allocate a 96-byte callback work block and initialize its four owned handles. */
Work0fbc74 *func_020fbde4(s32 a, s32 b)
{
    Work0fbc74 *work;
    s32 i;
    work = func_020611dc(func_020fb634, func_020fb858, 0, func_020fbc74, 96, 1, 0, 1);
    work->unk_54 = a;
    work->unk_58 = b;
    for (i = 0; i < 4; i++) {
        work->handles[i] = func_0205c3c0();
        func_0205c3fc(work->handles[i], work->unk_54, work->unk_58);
    }
    func_0205c408(work->handles[3], 12);
    func_0205c6e0(work->handles[3]);
    work->unk_50 = 0;
    work->current = -1;
    work->pending = -1;
    work->unk_30 = func_020629ac(5, 5, 0, 1);
    work->unk_34 = func_020629ac(5, 1, 0, 1);
    func_02061e98(work->unk_34, 16, 1);
    work->unk_5c = 0;
    return work;
}
