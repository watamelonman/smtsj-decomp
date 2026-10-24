#include "types.h"

/* Callback-owned 16-byte work block; byte fields are evidenced by fd268/fd2fc. */
typedef struct Unk0fcfe4Work {
    int kind;
    u32 color;
    u8 counter, interval, visible, remaining, state;
    u8 pad_000d[3];
} Unk0fcfe4Work;

extern Unk0fcfe4Work *data_02176e18;
extern int Unk0981dc_Unk_098324(int left, int right);
extern void func_020fd268(Unk0fcfe4Work *work);
extern void func_020fd2fc(Unk0fcfe4Work *work);
extern Unk0fcfe4Work *func_020611dc(void (*update)(Unk0fcfe4Work *),
    void (*draw)(Unk0fcfe4Work *), void *hook, void *cleanup,
    u32 size, u32 arg5, u32 arg6, u32 arg7);

/* Compare kind priorities through the shared comparator; zero has special precedence. */
int func_020fcfe4(int left, int right)
{
    int a, b;
    if (right == 0) return 0;
    if (left == 0) return 1;
    a = 0;
    b = 0;
    switch (left) {
    case 1: a = 3; break;
    case 2: a = 2; break;
    case 3: a = 9; break;
    }
    switch (right) {
    case 1: b = 3; break;
    case 2: b = 2; break;
    case 3: b = 9; break;
    }
    return Unk0981dc_Unk_098324(a, b);
}

/* Assign a kind's packed color to a borrowed work block; null is accepted. */
void func_020fd068(Unk0fcfe4Work *work, int kind)
{
    if (work == 0) return;
    if (kind == 0) work->color = 0xff0f00ff;
    else if (kind == 1) work->color = 0x9e2087ff;
    else if (kind == 2) work->color = 0x2acae7ff;
    else if (kind == 3) work->color = 0x2ed943ff;
    else work->color = 0xffffffff;
}

/* Create the singleton callback task, or replace its kind when priority permits. */
void func_020fd0c8(int kind)
{
    Unk0fcfe4Work *work;
    if (data_02176e18 != 0) {
        if (func_020fcfe4(kind, data_02176e18->kind) != 1) return;
        data_02176e18->kind = kind;
        func_020fd068(data_02176e18, kind);
        return;
    }
    work = func_020611dc(func_020fd268, func_020fd2fc, 0, 0, 16, 0, 0, 1);
    if (work == 0) return;
    work->kind = kind;
    work->interval = 0;
    work->state = 0;
    work->counter = 0;
    work->visible = 1;
    work->remaining = 1;
    data_02176e18 = work;
    func_020fd068(work, kind);
}

/* Pack byte channels in the word format consumed by the draw callback. */
static inline u32 PackColor(u8 r, u8 g, u8 b)
{
    return ((r << 24) & 0xff000000) + ((g << 16) & 0xff0000) + ((b << 8) & 0xff00) + 255;
}

/* Create a custom-color task only when absent; interval/count truncate to bytes. */
void func_020fd190(u32 color, u32 interval, u32 remaining)
{
    Unk0fcfe4Work *work;
    if (data_02176e18 != 0) return;
    work = func_020611dc(func_020fd268, func_020fd2fc, 0, 0, 16, 0, 0, 1);
    if (work == 0) return;
    work->kind = 0;
    work->interval = interval;
    work->state = 0;
    work->counter = 0;
    work->visible = 1;
    work->remaining = remaining;
    work->color = PackColor((color >> 24) & 255, (color >> 16) & 255, (color >> 8) & 255);
    data_02176e18 = work;
}
