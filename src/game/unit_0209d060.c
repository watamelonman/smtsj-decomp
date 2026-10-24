#include "types.h"

/* The allocation in func_0209d084 is four bytes; callbacks access its only word. */
typedef struct Unk09d060Ctx {
    u32 unk_00;
} Unk09d060Ctx;

extern Unk09d060Ctx *data_02176274;

void func_02061424(Unk09d060Ctx *work);
void Unk0d1c98_Release(void);
s32 ScanVisor_Unk_0a2980(void);
s32 func_02061750(Unk09d060Ctx *work);
void func_020616ec(void *parent, void *child);
void func_020d1cb4(void);
Unk09d060Ctx *func_020611dc(void (*update)(Unk09d060Ctx *),
    void (*arg1)(void), u32 arg2, void (*destroy)(void),
    u32 size, u32 alignment, u32 arg6, u32 arg7);

/* Increment the allocated work word; evidence: load/add/store at 0209d060. */
void Unk09d060_Unk_09d060(Unk09d060Ctx *work)
{
    work->unk_00++;
}

/* Clear the singleton slot; evidence: zero store through 02176274 at 0209d070. */
void Unk09d060_Clear_data_02176274(void)
{
    data_02176274 = 0;
}

/* Create the singleton once; 0209d084 requests four bytes and links an optional parent. */
void func_0209d084(void *parent)
{
    if (data_02176274 != 0) return;
    data_02176274 = func_020611dc(Unk09d060_Unk_09d060, 0, 0,
        Unk09d060_Clear_data_02176274, 4, 4, 0xffff, 1);
    if (parent != 0) {
        func_020616ec(parent, data_02176274);
    }
    func_020d1cb4();
}

/* Free the singleton if present, then release its companion (calls at 0209d10c). */
void Unk09d060_Unk_09d10c(void)
{
    if (data_02176274 != 0) {
        func_02061424(data_02176274);
        data_02176274 = 0;
    }
    Unk0d1c98_Release();
}

/* Test the work only when the visor query succeeds; evidence: branches at 0209d13c. */
s32 Unk09d060_Unk_09d13c(void)
{
    if (ScanVisor_Unk_0a2980() == 0) {
        return 0;
    }
    return func_02061750(data_02176274) == 0;
}

/* Link child to the singleton when present; 0209d170 passes it as the first argument. */
void Unk09d060_Unk_09d170(void *child)
{
    if (data_02176274 != 0) {
        func_020616ec(data_02176274, child);
    }
}

/* Return the work word or zero without a singleton; evidence: loads at 0209d194. */
u32 Unk09d060_GetCtxUnk00(void)
{
    Unk09d060Ctx *work = data_02176274;
    if (work != 0) {
        return work->unk_00;
    }
    return 0;
}

/* Reset the work word if allocated; evidence: conditional zero store at 0209d1b0. */
void Unk09d060_Unk_09d1b0(void)
{
    if (data_02176274 != 0) {
        data_02176274->unk_00 = 0;
    }
}
