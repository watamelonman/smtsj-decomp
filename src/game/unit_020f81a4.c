#include "types.h"

/* Partial object layout, evidenced by accesses in 020f81cc and 020f8264.
 * Callback results occupy the six words before the state word at +0x7c. */
typedef struct Unk0f81a4Work Unk0f81a4Work;
typedef u32 (*Unk0f81a4EntryCallback)(Unk0f81a4Work *work, s32 index);
typedef void (*Unk0f81a4Callback)(Unk0f81a4Work *work);
struct Unk0f81a4Work {
    s32 unk_0000;
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[0x58];
    u32 unk_0064[6];
    u32 unk_007c;
    u32 unk_0080;
    s32 unk_0084;
    Unk0f81a4EntryCallback unk_0088;
    u32 unk_008c;
    u32 unk_0090;
    u32 unk_0094;
    u32 unk_0098;
    Unk0f81a4Callback unk_009c;
    u32 unk_00a0;
};

void func_0204afe0(Unk0f81a4Work *work, s32 value);
void Unk0bcef4_Unk_0bcef4(Unk0f81a4Work *work, u32 b, u32 c, u32 mode);
void Unk0bcef4_Unk_0bd29c(void *sub, Unk0f81a4Work *work);
void func_020bd1a8(void *sub, Unk0f81a4Work *work, u32 *entries, u32 mode);
void func_020f8264(Unk0f81a4Work *work);
void Unk0f81a4_Init(Unk0f81a4Work *work, u32 b, u32 c);

/* Forward the object's +0x84 value to 0204afe0, as shown by the tail call. */
void Unk0f81a4_Unk_0f81a4(Unk0f81a4Work *work)
{
    func_0204afe0(work, work->unk_0084);
}

/* Test the observed -1 sentinel at +0x84; no other values are excluded. */
int Unk0f81a4_Unk_0f81b4(Unk0f81a4Work *work)
{
    return work->unk_0084 != -1;
}

/* Store caller-supplied fields and callbacks before initialization, then clear
 * +0x7c. The original stack loads establish the parameter order. */
void func_020f81cc(Unk0f81a4Work *work, u32 b, u32 c, u32 unused, u32 field80, s32 field84, Unk0f81a4EntryCallback callback, u32 field8c, u32 field90, u32 field94)
{
    work->unk_0088 = callback;
    work->unk_008c = field8c;
    work->unk_0090 = field90;
    work->unk_0094 = field94;
    work->unk_0098 = 0;
    work->unk_009c = 0;
    work->unk_00a0 = 0;
    work->unk_0080 = field80;
    work->unk_0084 = field84;
    Unk0f81a4_Init(work, b, c);
    work->unk_007c = 0;
}

/* Initialize the base and embedded +0x1c block, then populate callback results;
 * the three calls at 020f8224 establish this ordering and constant mode. */
void Unk0f81a4_Init(Unk0f81a4Work *work, u32 b, u32 c)
{
    Unk0bcef4_Unk_0bcef4(work, b, c, 1);
    Unk0bcef4_Unk_0bd29c((u8 *)work + 0x1c, work);
    func_020f8264(work);
}

/* Store the unknown word at +0x98 (STR in 020f824c). */
void Unk0f81a4_SetUnkField98(Unk0f81a4Work *work, u32 value)
{
    work->unk_0098 = value;
}

/* Store the optional completion callback at +0x9c (STR in 020f8254). */
void Unk0f81a4_SetUnkField9c(Unk0f81a4Work *work, Unk0f81a4Callback value)
{
    work->unk_009c = value;
}

/* Store the unknown word at +0xa0 (STR in 020f825c). */
void Unk0f81a4_SetUnkFielda0(Unk0f81a4Work *work, u32 value)
{
    work->unk_00a0 = value;
}

/* With a +0x88 callback, populate +0x64 entries using the saved +8 base,
 * refresh the embedded block, then invoke the optional +0x9c callback.
 * Callers must keep the count within the six-word result storage. */
void func_020f8264(Unk0f81a4Work *work)
{
    s32 base;
    s32 i;
    if (work->unk_0088 == 0)
        return;
    base = work->unk_0008;
    for (i = 0; i < work->unk_0000; i++)
        work->unk_0064[i] = work->unk_0088(work, i + base);
    func_020bd1a8((u8 *)work + 0x1c, work, work->unk_0064, 1);
    if (work->unk_009c != 0)
        work->unk_009c(work);
}
