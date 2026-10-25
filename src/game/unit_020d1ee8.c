#include "types.h"

/* Borrowed owner view; offsets follow the accesses in this unit. */
typedef struct {
    u8 pad_0000[0x34];
    s8 slots[0x20c];
    u8 map[0x7200];
    int ready;
    u8 pad_7444[0x3c];
    s8 mode;
    s8 phase;
    s8 x;
    s8 y;
    int timer;
    int choice;
} Unk0d1ee8Work;

typedef struct {
    u8 kind;
    u8 index;
    u8 pad_02[2];
    u32 low : 16;
    u32 slot : 4;
    u32 high : 12;
} Unk0d1ee8Cell;

typedef struct { u32 value : 8; u32 rest : 24; } Unk0d1ee8Element;
typedef struct {
    u8 pad_000[0x358];
    int value;
    u16 area;
    u8 pad_35e[6];
    s8 x;
    s8 y;
} Unk0d1ee8Root;

extern Unk0d1ee8Root *Unk02e000_GetWorkArea(void);
extern Unk0d1ee8Cell *Unk038fbc_Unk_039160(void *map, int x, int y);
extern Unk0d1ee8Element *Unk038fbc_GetElement(void *map, int type, int index);
extern int Unk0e651c_Get2Bits(int area, int index);
extern void Unk0e651c_Set2Bits(int area, int index, int value);
extern int func_020654cc(void);
extern int func_02065cd0(void);
extern void func_02065c30(void);
extern void func_0206597c(int value);
extern void func_02065bc0(void);
extern int func_020987ac(int slot, int value);
extern void ScanVisor_Unk_0a2ab0(void);
extern int Unk04bb9c_GetCtxUnka20(void);
extern void func_0204c4cc(s16 x, s16 y);
extern int func_020d1ff4(Unk0d1ee8Work *work);
extern int Unk0e651c_Unk_0e666c(int bit);
extern void Unk0e651c_SetBitChecked(int bit, int value);
extern int Unk095560_Unk_095778(int message);
extern void func_0206569c(int message);
extern int func_02098740(int slot);
extern int Unk0e5fb8_Unk_0e63c8(int slot);
extern void Unk0e5fb8_Unk_0e641c(int slot, u8 value);
extern void func_020658dc(int message, int a, int b, int flags);
extern int func_0206559c(void);
extern int func_02065e1c(void);
extern void func_02034dd0(void);
typedef struct { u8 flags; u8 active; u16 timer; } Unk0d1ee8Current;
typedef struct { u8 pad_00[0x19]; u8 value; } Unk0d1ee8Resource;
extern Unk0d1ee8Resource *Unk09a268_Unk_09c484(int resource);
extern Unk0d1ee8Current *Unk02f2a8_GetCurrentCell38e8(void);
extern void Unk09a268_Unk_09a80c(Unk0d1ee8Current *cell, int value);
extern void Unk09a268_Unk_09a830(Unk0d1ee8Current *cell, int value);
extern void Unk09a268_Unk_09a870(Unk0d1ee8Current *cell, int value);
extern void Unk09a268_SetOnlyBit(Unk0d1ee8Current *cell, int value);
extern int ScanVisor_GetConst20(void);
extern int func_020a03cc(void);
extern int Unk0a23f4_Unk_0a2448(void);
extern int func_02052728(void);
extern void func_02034b7c(int area, int x, int y, int value, int a, int b, int c, int d);
extern void func_0204c780(int x, int y);
extern void func_02065c58(void);
extern void func_0205264c(int a, int b, int c, int d, int e);
extern void ScanVisor_Unk_0a2b7c(void);
extern void ScanVisor_Unk_0a2920(int value);
extern void GameState_ClearRootUnk60(void);

/* Advance the mode-zero interaction and raise the element's two-bit state to one. */
int func_020d1ee8(Unk0d1ee8Work *work)
{
    Unk0d1ee8Cell *cell;
    Unk0d1ee8Element *element;
    int done;
    cell = Unk038fbc_Unk_039160(work->map, work->x, work->y);
    element = Unk038fbc_GetElement(work->map, 12, cell->index);
    done = 0;
    switch (work->phase) {
    case 0:
        if (func_020654cc() == 1) {
            if (Unk0e651c_Get2Bits(Unk02e000_GetWorkArea()->area, element->value) < 1)
                Unk0e651c_Set2Bits(Unk02e000_GetWorkArea()->area, element->value, 1);
            func_0206597c(20);
            work->phase++;
        }
        break;
    case 1:
        if (func_02065cd0() == 1) {
            func_02065c30();
            work->phase++;
        }
        break;
    case 2:
        if (func_020654cc() == 1)
            done = 1;
        break;
    default:
        done = 1;
        break;
    }
    return done;
}

/* Run the alternate cell interaction: prompt, apply a slot choice, animate and finalize.
 * Phase and cell-field evidence is the dispatch and accesses at 020d1ff4..020d27a4.
 */
int func_020d1ff4(Unk0d1ee8Work *work)
{
    int done = 0;
    Unk0d1ee8Cell *cell = 0;
    if (work->phase != 9) {
        cell = Unk038fbc_Unk_039160(work->map, work->x, work->y);
        Unk038fbc_GetElement(work->map, 12, cell->index);
    }
    switch (work->phase) {
    case 0:
        if (func_020654cc() == 1) {
            if (Unk0e651c_Unk_0e666c(0x72b) == 1 && Unk0e651c_Unk_0e666c(0x73d) == 0) {
                Unk0e651c_SetBitChecked(0x73d, 1);
                func_0206569c(Unk095560_Unk_095778(0x3c));
                work->phase++;
            } else {
                work->phase += 2;
            }
        }
        break;
    case 1:
        if (func_02065cd0() == 1)
            work->phase++;
        break;
    case 2:
        if (Unk0e651c_Unk_0e666c(0x72c) == 1 && Unk0e651c_Unk_0e666c(0x73e) == 0) {
            Unk0e651c_SetBitChecked(0x73e, 1);
            func_0206569c(Unk095560_Unk_095778(0x3d));
            work->phase++;
        } else {
            work->phase += 2;
        }
        break;
    case 3:
        if (func_02065cd0() == 1)
            work->phase++;
        break;
    case 4: {
        int mode, value = 0, slot, message;
        mode = func_02098740(4);
        slot = work->slots[cell->slot - 1];
        if (slot >= 0)
            value = Unk0e5fb8_Unk_0e63c8(slot);
        if (mode == 1) {
            if (value == 0) message = 0x15;
            else message = 0x16;
        } else {
            if (value == 0) message = 0x17;
            else if (value == 1) message = 0x18;
            else message = 0x19;
        }
        func_020658dc(Unk095560_Unk_095778(message), 0, 0, 0x101);
        work->phase++;
        break;
    }
    case 5:
        if (func_0206559c() == 1) {
            int changed = 0;
            int answer, mode, choice;
            int slot = work->slots[cell->slot - 1];
            if (slot >= 0) {
                int value, message;
                answer = (u8)func_02065e1c();
                mode = func_02098740(4);
                value = Unk0e5fb8_Unk_0e63c8(slot);
                if (mode == 1) {
                    if (value == 0) message = 0x15;
                    else message = 0x16;
                } else {
                    if (value == 0) message = 0x17;
                    else if (value == 1) message = 0x18;
                    else message = 0x19;
                }
                choice = 0;
                switch (message) {
                case 0x15:
                    if (answer == 0) choice = 1;
                    else choice = -1;
                    break;
                case 0x16:
                    if (answer != 0) choice = -1;
                    break;
                case 0x17:
                    if (answer == 0) choice = 1;
                    else if (answer == 1) choice = 2;
                    else choice = -1;
                    break;
                case 0x18:
                    if (answer == 0) break;
                    if (answer == 1) choice = 2;
                    else choice = -1;
                    break;
                case 0x19:
                    if (answer == 0) break;
                    if (answer == 1) choice = 1;
                    else choice = -1;
                    break;
                }
                if (choice != -1 && choice != Unk0e5fb8_Unk_0e63c8(slot)) {
                    work->choice = choice;
                    changed = 1;
                }
            }
            func_02065c30();
            if (changed == 1) work->phase++;
            else work->phase = -1;
        }
        break;
    case 6:
        if (func_020654cc() == 1) {
            Unk0d1ee8Resource *resource;
            Unk0d1ee8Current *current;
            func_02034dd0();
            resource = Unk09a268_Unk_09c484(0x18);
            current = Unk02f2a8_GetCurrentCell38e8();
            Unk09a268_Unk_09a80c(current, 1);
            Unk09a268_Unk_09a830(current, 0);
            Unk09a268_SetOnlyBit(current, resource->value);
            current->active = 1;
            current->timer = 0;
            Unk0e5fb8_Unk_0e641c(work->slots[cell->slot - 1], (u8)work->choice);
            work->phase++;
        }
        break;
    case 7:
        work->timer++;
        if (ScanVisor_GetConst20() < work->timer && func_020a03cc() == 1) {
            work->timer = 0;
            work->phase = 100;
        } else {
            Unk02f2a8_GetCurrentCell38e8()->timer++;
            if (Unk0a23f4_Unk_0a2448() == 0) {
                work->timer = 0;
                work->phase++;
            }
        }
        break;
    case 8:
        Unk02f2a8_GetCurrentCell38e8()->timer++;
        if (func_02052728() == 0) {
            work->timer++;
            if (work->timer > 5) {
                Unk0d1ee8Root *root = Unk02e000_GetWorkArea();
                func_02034b7c(root->area, work->x, work->y, root->value, 4, 1, 1, 0);
                work->timer = 0;
                work->phase++;
            }
        }
        break;
    case 9: {
        Unk0d1ee8Current *current = Unk02f2a8_GetCurrentCell38e8();
        current->timer++;
        if (work->ready != 0) {
            Unk0d1ee8Element *element;
            int area;
            cell = Unk038fbc_Unk_039160(work->map, work->x, work->y);
            element = Unk038fbc_GetElement(work->map, 12, cell->index);
            Unk0e651c_Set2Bits(Unk02e000_GetWorkArea()->area, element->value, 3);
            area = Unk04bb9c_GetCtxUnka20();
            if (area == Unk02e000_GetWorkArea()->area)
                func_0204c780(work->x, work->y);
            Unk09a268_Unk_09c484(0x18);
            Unk09a268_Unk_09a80c(current, 0);
            Unk09a268_Unk_09a830(current, 0);
            Unk09a268_Unk_09a870(current, 0);
            Unk09a268_SetOnlyBit(current, 0);
            current->active = 0;
            current->timer = 0;
            func_02065bc0();
            work->phase++;
        }
        break;
    }
    case 10:
        if (func_020654cc() == 1) {
            int slot = work->slots[cell->slot - 1];
            int value = 0;
            if (slot >= 0)
                value = Unk0e5fb8_Unk_0e63c8(slot);
            if (value > 0) func_0206597c(7);
            else func_0206597c(0x2a);
            work->timer = 0;
            work->phase++;
        }
        break;
    case 11:
        if (func_02065cd0() == 1) {
            func_02065c58();
            work->timer = 0;
            work->phase++;
        }
        break;
    case 12:
        if (func_020654cc() == 1) done = 1;
        break;
    case -1:
        if (func_020654cc() == 1) done = 1;
        break;
    case 100: {
        Unk0d1ee8Resource *resource;
        Unk0d1ee8Current *current;
        func_0205264c(2, 4, 0x1f, 1, 2);
        ScanVisor_Unk_0a2b7c();
        ScanVisor_Unk_0a2920(1);
        GameState_ClearRootUnk60();
        resource = Unk09a268_Unk_09c484(0x18);
        current = Unk02f2a8_GetCurrentCell38e8();
        Unk09a268_Unk_09a80c(current, 1);
        Unk09a268_Unk_09a830(current, 0);
        Unk09a268_SetOnlyBit(current, resource->value);
        current->active = 1;
        current->timer = 0xaa;
        work->phase = 8;
        break;
    }
    default:
        done = 1;
        break;
    }
    return done;
}

/* Mark a kind-0x24 current cell as state two when slot four enables the interaction. */
int func_020d27bc(Unk0d1ee8Work *work)
{
    int done = 0;
    int x, y;
    Unk0d1ee8Cell *cell;
    Unk0d1ee8Element *element;
    x = Unk02e000_GetWorkArea()->x;
    y = Unk02e000_GetWorkArea()->y;
    cell = Unk038fbc_Unk_039160(work->map, x, y);
    if (cell != 0 && cell->kind == 0x24) {
        if (func_020987ac(4, 1) == 1 || func_020987ac(4, 2) == 1) {
            element = Unk038fbc_GetElement(work->map, 12, cell->index);
            if ((u32)Unk0e651c_Get2Bits(Unk02e000_GetWorkArea()->area, element->value) < 2) {
                int area;
                Unk0e651c_Set2Bits(Unk02e000_GetWorkArea()->area, element->value, 2);
                ScanVisor_Unk_0a2ab0();
                area = Unk04bb9c_GetCtxUnka20();
                if (area == Unk02e000_GetWorkArea()->area)
                    func_0204c4cc((s16)x, (s16)y);
            }
            done = 1;
        }
    }
    return done;
}

/* Select the interaction mode from slot four for the owner's kind-0x24 cell. */
int func_020d28c4(Unk0d1ee8Work *work)
{
    Unk0d1ee8Cell *cell;
    cell = Unk038fbc_Unk_039160(work->map, work->x, work->y);
    Unk038fbc_GetElement(work->map, 12, cell->index);
    if (cell->kind != 0x24)
        return 0;
    if (func_020987ac(4, 1) == 1 || func_020987ac(4, 2) == 1) {
        work->mode = 1;
        func_02065bc0();
    } else {
        work->mode = 0;
        func_02065bc0();
    }
    return 1;
}

/* Dispatch the interaction callback using the signed mode byte at owner +0x7480. */
int func_020d2958(Unk0d1ee8Work *work)
{
    if (work->mode == 0)
        return func_020d1ee8(work);
    else
        return func_020d1ff4(work);
}
