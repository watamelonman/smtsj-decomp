/* Special entry and cell handling for the (8, 6) lookup. */
#include "types.h"


u8 *Unk02e000_GetWorkArea(void);
int Unk03e43c_Unk_03fa28(void);
/* 8-byte record filled by Unk116360_FillEntry. */
typedef struct Unk116360Entry {
    u16 id;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
} Unk116360Entry;
void Unk116360_FillEntry(Unk116360Entry *e, int id, int x, int y);
int Unk02f2a8_Unk_035b08(int a, int b);
/* Tests the lookup ID and position while the external state is zero. */
int Unk116360_Unk_116360(int a, int b, int c)
{
    int r = 0;
    if (Unk03e43c_Unk_03fa28() == 0) {
        if (a == Unk02f2a8_Unk_035b08(8, 6) && b == 36 && c == 18) {
            r = 1;
        }
    }
    return r;
}

/* Fills a non-null entry using the current work-area ID at offset 0x35c. */
void Unk116360_Unk_116404(Unk116360Entry *entry, int x, int y)
{
    u8 *work;
    if (entry == 0) {
        return;
    }
    work = Unk02e000_GetWorkArea();
    Unk116360_FillEntry(entry, *(u16 *)(work + 0x35c), x, y);
}

/* Returns 2 for the special position in the current work area, otherwise 0. */
u32 Unk116360_Unk_116438(u32 x, u32 y)
{
    u8 *work;
    int special;
    u32 result = 0;
    work = Unk02e000_GetWorkArea();
    special = Unk116360_Unk_116360(*(u16 *)(work + 0x35c), x, y);
    if (special == 1) {
        result = 2;
    }
    return result;
}

/* Fills `e` when the (8,6) lookup equals `id` and the position is (36,18).
 * The name is supported by the original stores to all four entry fields. */
void Unk116360_FillEntry(Unk116360Entry *e, int id, int x, int y)
{
    if (e == 0) {
        return;
    }
    if (Unk03e43c_Unk_03fa28() != 0) {
        return;
    }
    if (id != Unk02f2a8_Unk_035b08(8, 6) || x != 36 || y != 18) {
        return;
    }
    e->id = id;
    e->unk_02 = 18;
    e->unk_03 = 30;
    e->unk_04 = 0;
}

/* Cell byte/halfword fields are evidenced by loads and stores in func_02116470. */
typedef struct Unk116360Cell {
    u8 unk_00;
    u8 state;
    u16 unk_02;
} Unk116360Cell;

u8 *GetGameState(void);
u8 *Unk09a268_Unk_09c484(int index);
Unk116360Cell *Unk02f2a8_GetCell38e8(int x, int y);
void Unk09a268_Unk_09a80c(Unk116360Cell *cell, int value);
void Unk09a268_Unk_09a830(Unk116360Cell *cell, int value);
void Unk09a268_Unk_09a870(Unk116360Cell *cell, int value);
void Unk09a268_SetOnlyBit(Unk116360Cell *cell, int bit);

/* Updates the (36,18) cell for the (8,6) ID using game-state offset 0x74f0
 * and the external state; the two transitions reset the halfword at offset 2. */
void func_02116470(void)
{
    u8 *game = GetGameState();
    u8 *entry;
    Unk116360Cell *cell;
    int id;
    int state;
    if (game == 0) {
        return;
    }
    entry = Unk09a268_Unk_09c484(11);
    cell = 0;
    id = *(u16 *)(Unk02e000_GetWorkArea() + 0x35c);
    state = Unk03e43c_Unk_03fa28();
    if (id == Unk02f2a8_Unk_035b08(8, 6)) {
        cell = Unk02f2a8_GetCell38e8(36, 18);
    }
    if (cell == 0) {
        return;
    }
    if (*(int *)(game + 0x74f0) != 0 && state == 0) {
        if (cell->state == 0) {
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_Unk_09a870(cell, 0);
            Unk09a268_SetOnlyBit(cell, entry[25]);
            cell->state = 1;
            cell->unk_02 = 0;
        }
    } else if (*(int *)(game + 0x74f0) == 0 && state != 0) {
        if (cell->state == 2) {
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_Unk_09a870(cell, 0);
            Unk09a268_SetOnlyBit(cell, entry[25]);
            cell->state = 3;
            cell->unk_02 = 0;
        }
    }
}
