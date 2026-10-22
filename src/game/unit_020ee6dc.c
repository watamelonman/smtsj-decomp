/* src/game/unit_020ee6dc.c: callbacks used by the work object set up in unit_020ee454.
 * Bodies marked "decompiler-derived" are cleaned Ghidra output; the rest were matched by hand. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. The 0x50 sub-object is
 * the block driven by unit_020f8448 (see Unk0f8448_GetEntry/GetUnkField*). */
typedef struct Unk0ee6dcWork {
    u8 pad_0000[0x8];
    s32 unk_0008;     /* state: 1 makes func_020ee70c bail out, 10 triggers SetState2 */
    u8 pad_000c[0x4];
    s32 unk_0010;     /* list x origin; negative means the list is mirrored */
    u8 pad_0014[0x30];
    u32 unk_0044;     /* handle passed to Unk0e8228_Unk_0e8374 */
} Unk0ee6dcWork;

/* Callees from the 020f7xxx/020f8xxx object layer and the 020e8xxx game helpers. Kept as plain
 * int/u32 parameters because only their calling convention is known here. */
u32 Unk0f8448_GetUnkField10(void *obj);
u32 Unk0f8448_GetUnkField0(void *obj);
u32 Unk0f8448_GetEntry(u8 *p, int i);
void Unk0f8448_Init(void *obj, u32 value);
int Unk0f7188_Unk_0f7210(void);
int func_020f82e0(void *obj);
int Unk0fedd4_SetState2(void);
int Unk0e8228_Unk_0e8374(u32 value);
int func_020f8264(void *obj);
int Unk0fd9f0_Unk_0fda58(int value);
int Unk0feba0_Unk_0febe8(int value);
void func_02057e18(int value);
void func_02057df8(void);
void Unk0e8228_Unk_0e8e50(void);
void Unk0e8228_Unk_0e8e6c(void);
void func_020f53d0(int a, int b, int x, int y, int c, int d);
void Unk0f51dc_Unk_0f5738(int x, int y);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Unk_0e8e7c(void);
int Unk100208_Unk_100208(int value);

/* Empty callback installed in the work object's function table (the +0x20 slot). */
void Unk0ee6dc_Nop_0ee8b8(void) { }

void func_020f7248(void);
/* Forwards to `func_020f7248` (tail call through the literal pool). */
void Unk0ee6dc_Thunk_020f7248(void) { func_020f7248(); }

/* Per-frame update: does nothing while Unk0f7188_Unk_0f7210 reports idle; otherwise updates the
 * 0x50 sub-object and, once the work state is 10, advances the 0fedd4 controller to state 2. */
void Unk0ee6dc_Unk_0ee6dc(Unk0ee6dcWork *work)
{
    int value;

    value = Unk0f7188_Unk_0f7210();
    if (value == 0) {
        return;
    }
    func_020f82e0((u8 *)work + 0x50);
    if (work->unk_0008 != 10) {
        return;
    }
    Unk0fedd4_SetState2();
}

/* (Re)initialises the 0x50 sub-object from the handle at +0x44, then notifies it. The 1/0 pair
 * selects the 0feba0/0fd9f0 UI modes before the re-init, matching the original call order. */
void Unk0ee6dc_Unk_0ee880(Unk0ee6dcWork *work)
{
    u32 value;

    Unk0feba0_Unk_0febe8(1);
    Unk0fd9f0_Unk_0fda58(0);
    value = Unk0e8228_Unk_0e8374(work->unk_0044);
    Unk0f8448_Init((u8 *)work + 0x50, value);
    func_020f8264((u8 *)work + 0x50);
}

/* Maps a list entry index (0..3) to the entry kind passed to func_020f53d0; indices outside
 * 0..3 use kind 7. */
int func_020ee844(int index)
{
    switch (index) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 6;
    case 3:
    default:
        return 7;
    }
}

/* Callback invoked when the work object's sub-block reports a selection change. Returns without
 * doing anything when `flag` is non-zero; otherwise kinds 0, 2..6 and 8 request item 4 from
 * unit_02100208, while kinds 1 and 7 are ignored. `self` is part of the callback signature. */
void func_020ee8bc(void *self, u32 flag, int kind)
{
    (void)self;
    if (flag != 0) {
        return;
    }
    switch (kind) {
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

/* Draws the work object's visible list. `unk_0010` is the list x origin; a negative origin means
 * the list is mirrored (start 32 pixels in, then step x by -8 per row). Every entry is drawn at
 * (drawX, y), y starting at 25 and advancing by 15 per row. The switch maps entry kinds 1..4 to
 * the (show marker, kind) pair passed to func_020f53d0; kind 0 and unknown kinds draw nothing.
 * Callback installed at +0x14 of the work function table by unit_020ee454. */
void func_020ee70c(Unk0ee6dcWork *work)
{
    u8 *sub = (u8 *)work + 0x50;
    int count;
    int x;
    int y;
    int i;
    int drawX;
    int kind;
    int show;
    int negative;
    u32 entry;

    Unk0f8448_GetUnkField10(sub);
    count = Unk0f8448_GetUnkField0(sub);
    if (work->unk_0008 == 1) {
        return;
    }
    func_02057e18(31);
    func_02057df8();
    Unk0e8228_Unk_0e8e50();
    x = work->unk_0010;
    y = 0;
    negative = x < 0;
    if (negative != 0) {
        x += 32;
    }
    y += 25;
    for (i = 0; i < count; i++) {
        Unk0e8228_Unk_0e8e6c();
        drawX = x;
        if (x > 0) {
            drawX = 0;
        }
        show = 0;
        entry = Unk0f8448_GetEntry(sub, i);
        switch (entry) {
        case 1:
            show = 1;
            /* fall through */
        case 2:
            kind = 1;
            break;
        case 4:
            show = 1;
            /* fall through */
        case 3:
            kind = 2;
            break;
        case 0:
        default:
            kind = 0;
            break;
        }
        func_020f53d0(1, func_020ee844(i), drawX, y, kind, show);
        if (show != 0) {
            Unk0f51dc_Unk_0f5738(drawX, y);
        }
        if (negative != 0) {
            x -= 8;
        }
        y += 15;
    }
    Unk0e8228_Thunk_02057534();
    Unk0e8228_Unk_0e8e7c();
}
