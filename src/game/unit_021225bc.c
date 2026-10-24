#include "types.h"

/* Local views expose only fields observed in this unit; storage belongs to callers. */
typedef struct UnitWork {
    u8 pad_000[0x35c];
    u16 unk_35c;
    u8 pad_35e[6];
    s8 unk_364;
    s8 unk_365;
} UnitWork;
typedef struct UnitState {
    u8 pad_000[4];
    u8 unk_004[0x23c];
    u8 unk_240[0x36a8];
    u8 unk_38e8[1];
} UnitState;
typedef struct UnitCell {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} UnitCell;
typedef struct UnitEntry {
    u8 pad_00[0x19];
    u8 unk_19;
} UnitEntry;
typedef struct UnitTile {
    u32 unk_00;
    u32 unk_04_low : 16;
    u32 unk_04_nibble : 4;
    u32 unk_04_high : 12;
} UnitTile;

int Unk02f2a8_Unk_035b08(int group, int index);
int Unk0e651c_Unk_0e666c(int flag);
UnitEntry *Unk09a268_Unk_09c484(int index);
UnitState *GetGameState(void);
UnitWork *Unk02e000_GetWorkArea(void);
UnitTile *Unk038fbc_Unk_039160(void *grid, int x, int y);
int Unk02f2a8_Unk_035c14(int id, int selector);
UnitCell *Unk02f2a8_GetCell38e8(int x, int y);
void func_0209a884(void *destination, void *source);
void Unk09a268_Unk_09a80c(UnitCell *cell, int value);
void Unk09a268_Unk_09a830(UnitCell *cell, int value);
void Unk09a268_SetOnlyBit(UnitCell *cell, int bit);
int Unk09a268_Unk_09a844(UnitCell *cell);

/* Tests the observed (7,5) id, selector 2 and cell (10,27), requiring flag 0x10f clear. */
int func_021225bc(int id, int selector, int x, int y)
{
    int result = 0;
    if (id == Unk02f2a8_Unk_035b08(7, 5) && selector == 2 && x == 10 && y == 27) {
        if (Unk0e651c_Unk_0e666c(0x10f) == 0)
            result = 1;
    }
    return result;
}

/* Initializes cell (10,27) only when the current id, tile nibble and selector match. */
void func_02122610(void)
{
    UnitEntry *entry = Unk09a268_Unk_09c484(5);
    UnitState *state = GetGameState();
    UnitCell *cell;
    if (Unk02f2a8_Unk_035b08(7, 5) != Unk02e000_GetWorkArea()->unk_35c)
        return;
    if (Unk038fbc_Unk_039160(state->unk_240, Unk02e000_GetWorkArea()->unk_364,
                              Unk02e000_GetWorkArea()->unk_365)->unk_04_nibble != 2)
        return;
    if (Unk02f2a8_Unk_035c14(Unk02f2a8_Unk_035b08(7, 5), 2) != 2)
        return;
    cell = Unk02f2a8_GetCell38e8(10, 27);
    func_0209a884(state->unk_38e8, state->unk_004);
    Unk09a268_Unk_09a80c(cell, 1);
    Unk09a268_Unk_09a830(cell, 0);
    Unk09a268_SetOnlyBit(cell, entry->unk_19);
    cell->unk_01 = 3;
    cell->unk_02 = 0;
}

/* Advances the cell counter; returns one when inapplicable or when its completion test succeeds. */
int func_021226f8(void)
{
    UnitEntry *entry = Unk09a268_Unk_09c484(5);
    UnitState *state = GetGameState();
    int result = 0;
    UnitCell *cell;
    if (Unk02f2a8_Unk_035b08(7, 5) != Unk02e000_GetWorkArea()->unk_35c)
        return 1;
    if (Unk038fbc_Unk_039160(state->unk_240, Unk02e000_GetWorkArea()->unk_364,
                              Unk02e000_GetWorkArea()->unk_365)->unk_04_nibble != 2)
        return 1;
    if (Unk02f2a8_Unk_035c14(Unk02f2a8_Unk_035b08(7, 5), 2) != 2)
        return 1;
    cell = Unk02f2a8_GetCell38e8(10, 27);
    cell->unk_02++;
    if (Unk09a268_Unk_09a844(cell) == 1) {
        Unk09a268_Unk_09a80c(cell, 1);
        Unk09a268_Unk_09a830(cell, 1);
        Unk09a268_SetOnlyBit(cell, entry->unk_19);
        cell->unk_01 = 0;
        cell->unk_02 = 0;
        result = 1;
    }
    return result;
}

/* Returns selector value 2 for coordinates accepted by the current-id predicate, otherwise zero. */
int func_021227fc(int x, int y)
{
    int result = 0;
    int selector = Unk02f2a8_Unk_035c14(Unk02e000_GetWorkArea()->unk_35c, 2);
    if (func_021225bc(Unk02e000_GetWorkArea()->unk_35c, selector, x, y) == 1)
        result = 2;
    return result;
}
