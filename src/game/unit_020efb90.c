#include "types.h"

/* Local views contain only fields established by this unit's ARM accesses. */
typedef struct Unk0efb90Work {
    u8 pad_0000[8];
    s32 state;
    u32 unk_000c;
    s32 offset;
    u8 pad_0014[0x38];
    u32 selector;
    u8 list[1]; /* Borrowed subobject; its full extent is unknown. */
} Unk0efb90Work;

typedef struct Unk0efb90Flags {
    u8 pad_0000[0x40];
    u32 flags;
} Unk0efb90Flags;

void func_020f7248(void);
s32 Unk0f7188_Unk_0f7210(void);
void func_020f82e0(void *list);
void Unk0fedd4_SetState2(void);
u32 Unk0e8228_Unk_0e8374(u32 selector);
void Unk0f8448_Init(void *list, u32 value);
void Unk0fd9f0_Unk_0fda58(s32 value);
void Unk0feba0_Unk_0febe8(s32 value);
s32 Unk0f8448_GetUnkField10(void *list);
s32 Unk0f8448_GetUnkField0(void *list);
s32 Unk0f8448_GetEntry(void *list, s32 index);
void func_02057e18(s32 value);
void func_02057df8(void);
void Unk0e8228_Unk_0e8e50(void);
void Unk0e8228_Unk_0e8e6c(void);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Unk_0e8e7c(void);
void func_020f53d0(s32 layer, s32 index, s32 x, s32 y, s32 kind, s32 marked);
void Unk0f51dc_Unk_0f5738(s32 x, s32 y);
void Unk100208_Unk_100208(s32 value);
Unk0efb90Flags *Unk044904_Get_data_0215ee98(void);
s32 Unk0e651c_Unk_0e666c(s32 id);
s32 Unk0e8228_Unk_0e8bc4(void);
s32 Unk0e8228_Unk_0e8be8(void);

/* ARM body is only a return: this callback intentionally has no effect. */
void Unk0efb90_Nop_0efd18(void) { }

/* ARM call target establishes this forwarding callback's identity. */
void Unk0efb90_Thunk_020f7248(void) { func_020f7248(); }

/* Update the borrowed +0x50 list when enabled; state 10 triggers state 2. */
void Unk0efb90_Unk_0efb90(Unk0efb90Work *work)
{
    if (!Unk0f7188_Unk_0f7210()) return;
    func_020f82e0(work->list);
    if (work->state != 10) return;
    Unk0fedd4_SetState2();
}

/* Initialize the borrowed list using the work object's +0x4c selector. */
void Unk0efb90_Unk_0efce8(Unk0efb90Work *work)
{
    u32 value;
    Unk0feba0_Unk_0febe8(1);
    Unk0fd9f0_Unk_0fda58(0);
    value = Unk0e8228_Unk_0e8374(work->selector);
    Unk0f8448_Init(work->list, value);
}

/* Dispatch only event codes 0, 2..6 and 8 when the second argument is zero. */
void func_020efd1c(void *context, s32 blocked, u32 event)
{
    if (blocked != 0) return;
    switch (event) {
    case 0: case 2: case 3: case 4: case 5: case 6: case 8:
        Unk100208_Unk_100208(4);
        break;
    }
}

/* Modes 1 and 2 require their corresponding global flag and query checks. */
s32 func_020efd64(void *context, s32 mode)
{
    Unk0efb90Flags *global = Unk044904_Get_data_0215ee98();
    switch (mode) {
    case 1:
        if (!Unk0e651c_Unk_0e666c(0x707)) return 0;
        if ((global->flags << 28) >> 31) return 0;
        if (!Unk0e8228_Unk_0e8bc4()) return 0;
        break;
    case 2:
        if ((global->flags << 29) >> 31) return 0;
        if (!Unk0e8228_Unk_0e8be8()) return 0;
        break;
    }
    return 1;
}

/* Walk the borrowed list, submitting rows 15 units apart; entries 1/4 add a mark. */
void func_020efbc0(Unk0efb90Work *work)
{
    s32 count, x, y, negative, rowX, marked, i;
    Unk0f8448_GetUnkField10(work->list);
    count = Unk0f8448_GetUnkField0(work->list);
    if (work->state == 1) return;
    func_02057e18(31);
    func_02057df8();
    Unk0e8228_Unk_0e8e50();
    x = work->offset;
    y = 0;
    negative = x < 0;
    if (negative) x += 24;
    y += 25;
    for (i = 0; i < count; i++) {
        s32 kind, entry;
        Unk0e8228_Unk_0e8e6c();
        rowX = x;
        if (x > 0) rowX = 0;
        entry = Unk0f8448_GetEntry(work->list, i);
        marked = 0;
        switch (entry) {
        case 1: marked = 1;
        case 2: kind = 1; break;
        case 4: marked = 1;
        case 3: kind = 2; break;
        default: kind = 0; break;
        }
        func_020f53d0(0, i, rowX, y, kind, marked);
        if (marked) Unk0f51dc_Unk_0f5738(rowX, y);
        if (negative) x -= 8;
        y += 15;
    }
    Unk0e8228_Thunk_02057534();
    Unk0e8228_Unk_0e8e7c();
}
