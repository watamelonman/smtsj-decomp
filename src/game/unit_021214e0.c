#include "types.h"

/* Partial views preserve the offsets used by this unit without assuming ownership. */
typedef struct { u8 pad_000[856]; int direction; u16 id; u8 pad_35e[6]; s8 x, y; } Work1214e0;
typedef struct { u8 kind; u8 pad_001[3]; u32 flags; } Cell1214e0;
typedef struct { u8 pad_000[4]; u8 body[572]; u8 table[1]; } State1214e0;
typedef struct { u8 pad_000[7]; u8 index; } Selection1214e0;
typedef struct {
    u8 pad_000[4]; u8 entries[992]; Selection1214e0 *selection;
    u8 pad_3e8[8384]; u8 target[1];
} Owner1214e0;
Work1214e0 *Unk02e000_GetWorkArea(void);
int Unk02f2a8_Unk_035b08(int group, int index);
u32 func_020361ec(int direction, int amount);
State1214e0 *GetGameState(void);
Cell1214e0 *Unk038fbc_Unk_039160(void *table, int x, int y);
void *Unk02f2a8_Unk_034970(void *body, int x, int y);
int Unk09a268_FindEntry(void *entries, int index, int slot);
void func_02058b14(void *target, int entry, int value);

/* Tests the opposite adjacent cell for packed type 1 and byte kind 32.
 * Evidence: direction adjustment and cell fields in the original instructions;
 * the meaning of mode 2 and these cell codes remains unknown. */
int func_021214e0(int mode)
{
    int result = 0;
    if (mode == 2) {
        Work1214e0 *work = Unk02e000_GetWorkArea();
        if (work->id == Unk02f2a8_Unk_035b08(8, 3)) {
            u32 direction = func_020361ec(work->direction, mode);
            int x = work->x;
            int y = work->y;
            void *table;
            Cell1214e0 *first, *second;
            switch (direction) {
            case 1: x++; break;
            case 2: y++; break;
            case 3: x--; break;
            case 0: y--; break;
            }
            table = GetGameState()->table;
            first = Unk038fbc_Unk_039160(table, x, y);
            second = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(GetGameState()->body, x, y), x, y);
            if (table && second) {
                if (((first->flags << 12) >> 28) == 1 && second->kind == 32)
                    result = 1;
            }
        }
    }
    return result;
}

/* Looks up all three slots for selection index +6 and forwards each found entry
 * with value zero through the owner's embedded target. Owner and selection must
 * be valid; negative lookup results are absent. */
void func_021215d4(Owner1214e0 *owner)
{
    u8 index = owner->selection->index + 6;
    int first = Unk09a268_FindEntry(owner->entries, index, 0);
    int second = Unk09a268_FindEntry(owner->entries, index, 1);
    int third = Unk09a268_FindEntry(owner->entries, index, 2);
    if (first > -1) func_02058b14(owner->target, first, 0);
    if (second > -1) func_02058b14(owner->target, second, 0);
    if (third > -1) func_02058b14(owner->target, third, 0);
}

