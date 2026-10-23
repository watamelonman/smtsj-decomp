#include "types.h"

/* Partial object layout, evidenced by accesses in 020f81cc and 020f8264.
 * Callback results occupy the six words before the state word at +0x7c. */
typedef struct Unk0f81a4Work Unk0f81a4Work;
typedef u32 (*Unk0f81a4EntryCallback)(Unk0f81a4Work *work, s32 index);
typedef void (*Unk0f81a4Callback)(Unk0f81a4Work *work);
typedef int (*Unk0f81a4TestCallback)(Unk0f81a4Work *work);
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
    Unk0f81a4Callback unk_008c;
    Unk0f81a4Callback unk_0090;
    Unk0f81a4Callback unk_0094;
    Unk0f81a4TestCallback unk_0098;
    Unk0f81a4Callback unk_009c;
    Unk0f81a4Callback unk_00a0;
};

void func_0204afe0(Unk0f81a4Work *work, s32 value);
void Unk0bcef4_Unk_0bcef4(Unk0f81a4Work *work, u32 b, u32 c, u32 mode);
void Unk0bcef4_Unk_0bd29c(void *sub, Unk0f81a4Work *work);
void func_020bd1a8(void *sub, Unk0f81a4Work *work, u32 *entries, u32 mode);
void func_020f8264(Unk0f81a4Work *work);
void Unk0f81a4_Init(Unk0f81a4Work *work, u32 b, u32 c);
void Unk0bcef4_Unk_0bd388(void *sub, Unk0f81a4Work *work);
int Unk0bcef4_Unk_0bd2fc(void *sub, Unk0f81a4Work *work);
int Unk0bcef4_Unk_0bd368(void *sub, Unk0f81a4Work *work);
u32 Unk0e8228_Unk_0e85c8(void);
int func_02053800(u32 port, u32 mask);
int func_02053824(u32 port, u32 mask);
int func_020bce08(Unk0f81a4Work *work, u32 value);
void Unk100208_Unk_100208(u32 value);

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
void func_020f81cc(Unk0f81a4Work *work, u32 b, u32 c, u32 unused, u32 field80, s32 field84, Unk0f81a4EntryCallback callback, Unk0f81a4Callback field8c, Unk0f81a4Callback field90, Unk0f81a4Callback field94)
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

/* Store the optional test callback at +0x98 (STR in 020f824c); 020f82e0 uses it
 * in place of 020bce08 and tests its result. */
void Unk0f81a4_SetUnkField98(Unk0f81a4Work *work, Unk0f81a4TestCallback value)
{
    work->unk_0098 = value;
}

/* Store the optional completion callback at +0x9c (STR in 020f8254). */
void Unk0f81a4_SetUnkField9c(Unk0f81a4Work *work, Unk0f81a4Callback value)
{
    work->unk_009c = value;
}

/* Store the optional callback at +0xa0 (STR in 020f825c; called in 020f82e0). */
void Unk0f81a4_SetUnkFielda0(Unk0f81a4Work *work, Unk0f81a4Callback value)
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

/* Per-frame update: refresh the +0x1c block, call +0x94, then run the +0x7c
 * state. State 0 polls the 02053800/02053824 masks (0x800, 1, 2) and calls the
 * +0xa0 or +0x90 callbacks, refreshes the entries when +0x98 (or 020bce08 by
 * default) reports a change, passing 5/3/0/1/2 to 0x02100208; on success
 * of 0bd2fc it enters state 1, which waits for 0bd368 then calls +0x8c and
 * returns to state 0. The branch structure is from the ROM at 020f82e0. */
void func_020f82e0(Unk0f81a4Work *work)
{
    int changed;
    Unk0bcef4_Unk_0bd388((u8 *)work + 0x1c, work);
    work->unk_0094(work);
    switch (work->unk_007c) {
    case 0:
        if (work->unk_0084 != 0 && Unk0e8228_Unk_0e85c8() != 0)
            return;
        if (work->unk_00a0 != 0 && func_02053800(0, 0x800) != 0) {
            work->unk_00a0(work);
            Unk100208_Unk_100208(5);
            return;
        }
        if (work->unk_0098 != 0)
            changed = work->unk_0098(work);
        else
            changed = func_020bce08(work, work->unk_0080);
        if (changed != 0) {
            func_020f8264(work);
            Unk100208_Unk_100208(3);
        }
        if (func_02053824(0, 1) != 0) {
            if (Unk0bcef4_Unk_0bd2fc((u8 *)work + 0x1c, work) != 0) {
                work->unk_007c = 1;
                Unk100208_Unk_100208(0);
                return;
            }
            Unk100208_Unk_100208(1);
            return;
        }
        if (func_02053824(0, 2) == 0)
            return;
        Unk100208_Unk_100208(2);
        work->unk_0090(work);
        break;
    case 1:
        if (Unk0bcef4_Unk_0bd368((u8 *)work + 0x1c, work) == 0)
            return;
        work->unk_008c(work);
        work->unk_007c = 0;
        break;
    case 2:
        break;
    }
}
