/* src/game/unit_020f09b4.c: matched functions for the 0x020f09b4 translation unit. */
#include "types.h"

/* Work object behind this TU; only the fields this file touches are named. */
typedef struct Unk0f09b4Work {
    u8 pad_0000[8];
    s32 unk_0008;
    u8 pad_000c[4];
    s32 unk_0010;
    u8 pad_0014[0x38];
    u32 unk_004c; /* id passed to Unk0e8228_Unk_0e8374 when the list is reset */
    u32 unk_0050; /* head of the list object used through the 0f8448 helpers */
    u8 pad_0054[0x10];
} Unk0f09b4Work;

void func_020f7248(void);
s32 Unk0f7188_Unk_0f7210(void);
void func_020f82e0(u32 value);
void Unk0fedd4_SetState2(void);
void Unk0feba0_Unk_0febe8(s32 value);
void Unk0fd9f0_Unk_0fda58(s32 value);
u32 Unk0e8228_Unk_0e8374(u32 value);
void Unk0f8448_Init(void *obj, u32 value);

void func_02057e18(s32 value);
void func_02057df8(void);
void Unk0e8228_Unk_0e8e50(void);
void Unk0e8228_Unk_0e8e6c(void);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Unk_0e8e7c(void);
u32 Unk0f8448_GetUnkField10(void *obj);
u32 Unk0f8448_GetUnkField0(void *obj);
u32 Unk0f8448_GetEntry(void *obj, s32 index);
void func_020f53d0(s32 a, s32 b, s32 x, s32 y, s32 c, s32 d);
void Unk0f51dc_Unk_0f5738(s32 x, s32 y);
void Unk100208_Unk_100208(s32 value);

/* Maps a list index to 0, 3, 4 or 5 for indices 0..3, and to 7 for index 4 or any
   larger index. */
int func_020f0b1c(int index)
{
    switch (index) {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 4;
    case 3:
        return 5;
    case 4:
    default:
        return 7;
    }
}

/* Empty callback slot: this table entry has no state to update. */
void Unk0f09b4_Nop_0f0b94(void) { }

/* Forwards to func_020f7248 with the same arguments (a tail call in the original). */
void Unk0f09b4_Thunk_020f7248(void) { func_020f7248(); }

/* Calls func_020f82e0 on the work list and, when the object is in state 10, resets the
   state machine. Does nothing when the 0f7188 check reports zero. */
void Unk0f09b4_Unk_0f09b4(Unk0f09b4Work *work)
{
    if (Unk0f7188_Unk_0f7210() == 0) return;
    func_020f82e0((u32)&work->unk_0050);
    if (work->unk_0008 != 10) return;
    Unk0fedd4_SetState2();
}

/* Resets the 0feba0/0fd9f0 helpers and re-initialises the work list from the id at
   +0x4c. */
void Unk0f09b4_Unk_0f0b64(Unk0f09b4Work *work)
{
    u32 value;
    Unk0feba0_Unk_0febe8(1);
    Unk0fd9f0_Unk_0fda58(0);
    value = Unk0e8228_Unk_0e8374(work->unk_004c);
    Unk0f8448_Init(&work->unk_0050, value);
}

/* Walks the `count` entries of the work list at +0x50. Each entry's kind is read with
   Unk0f8448_GetEntry and mapped to two arguments for func_020f53d0; entries whose second
   argument is set also call Unk0f51dc_Unk_0f5738 with the computed position. The y
   coordinate starts at 25 and advances 15 per entry; the x base shrinks by 8 per entry
   when the initial base was negative. The meaning of the forwarded values is not known. */
void func_020f09e4(Unk0f09b4Work *work)
{
    s32 count;
    s32 base;
    s32 y;
    s32 i;
    s32 x;
    s32 mode;
    s32 line;
    s32 kind;
    u32 negative;

    /* The original evaluates the +0x10 getter first and discards its result. */
    (void)Unk0f8448_GetUnkField10(&work->unk_0050);
    count = Unk0f8448_GetUnkField0(&work->unk_0050);
    if (work->unk_0008 == 1) return;
    func_02057e18(31);
    func_02057df8();
    Unk0e8228_Unk_0e8e50();
    base = work->unk_0010;
    y = 0;
    negative = base < 0;
    if (negative) base += 40;
    y += 25;
    for (i = 0; i < count; i++) {
        Unk0e8228_Unk_0e8e6c();
        x = base;
        if (base > 0) x = 0;
        kind = Unk0f8448_GetEntry(&work->unk_0050, i);
        line = 0;
        switch (kind) {
        case 1:
            line = 1;
            /* fall through */
        case 2:
            mode = 1;
            break;
        case 4:
            line = 1;
            /* fall through */
        case 3:
            mode = 2;
            break;
        default:
            mode = 0;
            break;
        }
        func_020f53d0(1, func_020f0b1c(i), x, y, mode, line);
        if (line) Unk0f51dc_Unk_0f5738(x, y);
        if (negative) base -= 8;
        y += 15;
    }
    Unk0e8228_Thunk_02057534();
    Unk0e8228_Unk_0e8e7c();
}

/* When `blocked` is zero, calls Unk100208_Unk_100208(4) for modes 0 and 2..6 and 8;
   modes 1, 7 and anything above 8 do nothing. `unused` is not read. */
void func_020f0b98(s32 unused, s32 blocked, s32 mode)
{
    if (blocked != 0) return;
    switch (mode) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
        Unk100208_Unk_100208(4);
        break;
    }
}
