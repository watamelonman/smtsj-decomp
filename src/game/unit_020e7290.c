#include "types.h"

/* Partial work layout from the word accesses in 020e747c and 020e7734..020e78b0. */
typedef struct Unk0e7290Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x78];
    void *unk_008c;
    u8 pad_0090[0x174];
    u32 unk_0204;
} Unk0e7290Work;

/* Each successive flag is 0x5c bytes after the first flag at work + 0xed. */
typedef struct Unk0e7290FlagView {
    u8 pad_0000[0xed];
    u8 unk_00ed;
} Unk0e7290FlagView;

/* Resource 0x22's signed stride is read at +0xc by 020e77a8. */
typedef struct Unk0e7290Resource {
    u8 pad_0000[0xc];
    s32 unk_000c;
} Unk0e7290Resource;

extern Unk0e7290Work *data_02176cd8;
extern const char data_02150bf0[];
void func_02061424(Unk0e7290Work *work);
void func_02053000(void *value);
Unk0e7290Resource *func_020445d0(u32 resource, u32 index);
s32 func_0204fde0(void);
void func_02013c3c(char *dest, const char *format, ...);
void func_020e7290(Unk0e7290Work *work, u32 value);
void func_020e736c(Unk0e7290Work *work, u32 value);

/* Clear the global pointer; the sole store at 020e764c supports the existing name. */
void Unk0e7290_Clear_data_02176cd8(void)
{
    data_02176cd8 = 0;
}

/* Forward the active work to 02061424 only in states 0 and 5; report acceptance. */
u32 Unk0e7290_Unk_0e7734(void)
{
    Unk0e7290Work *work = data_02176cd8;
    if (work == 0) {
        return 0;
    }
    if (work->unk_0010 == 5 || work->unk_0010 == 0) {
        func_02061424(work);
        return 1;
    }
    return 0;
}

/* Format into caller-owned storage, clamping the signed index to at least one.
 * The resource stride and base query are observed at 020e77bc..020e77e4. */
void Unk0e7290_Unk_0e77a8(char *dest, s32 index)
{
    Unk0e7290Resource *resource = func_020445d0(0x22, 0);
    s32 base = func_0204fde0();
    if (index < 1) {
        index = 1;
    }
    func_02013c3c(dest, data_02150bf0, resource->unk_000c * (index - 1) + base);
}

/* Require all four byte flags before releasing +0x8c and moving +0xc to +8.
 * The caller owns work; the four flags occur at +0xed with stride 0x5c. */
u32 Unk0e7290_Unk_0e747c(Unk0e7290Work *work)
{
    Unk0e7290FlagView *flags;
    int ready;
    int count;
    u8 *cursor;
    count = 0;
    ready = 1;
    cursor = (u8 *)work;
    do {
        flags = (Unk0e7290FlagView *)cursor;
        count++;
        cursor += 0x5c;
        if (flags->unk_00ed == 0) {
            ready = 0;
        }
    } while (count < 4);
    if (ready) {
        func_02053000(work->unk_008c);
        work->unk_008c = 0;
        work->unk_0008 = work->unk_000c;
        work->unk_000c = 0;
        return 1;
    }
    return 0;
}

/* Store the pair at +0 and +4 if active; these stores support the existing Set name. */
void Unk0e7290_Set_0e7770(u32 a, u32 b)
{
    if (data_02176cd8 != 0) {
        data_02176cd8->unk_0000 = a;
        data_02176cd8->unk_0004 = b;
    }
}

/* Store the caller's word at +0x204 only when the global work exists. */
void Unk0e7290_Unk_0e7790(u32 value)
{
    if (data_02176cd8 != 0) {
        data_02176cd8->unk_0204 = value;
    }
}

/* Accept a pending value only in states 0 and 5, clearing +8 and the state word. */
int Unk0e7290_Unk_0e77f0(u32 value)
{
    u32 state;
    if (data_02176cd8 == 0) {
        return 0;
    }
    state = data_02176cd8->unk_0010;
    if (state != 5 && state != 0) {
        return 0;
    }
    data_02176cd8->unk_0008 = 0;
    data_02176cd8->unk_000c = value;
    data_02176cd8->unk_0010 = 0;
    return 1;
}

/* Accept a value in states 0 and 5, run three work helpers, then force state 5.
 * Reload the global between calls because those helpers may change it. */
int func_020e7840(u32 value)
{
    u32 state;
    if (data_02176cd8 == 0) {
        return 0;
    }
    state = data_02176cd8->unk_0010;
    if (state != 5 && state != 0) {
        return 0;
    }
    data_02176cd8->unk_000c = value;
    func_020e7290(data_02176cd8, 0);
    func_020e736c(data_02176cd8, 0);
    Unk0e7290_Unk_0e747c(data_02176cd8);
    data_02176cd8->unk_0010 = 5;
    return 1;
}
