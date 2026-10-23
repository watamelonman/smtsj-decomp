#include "GameState.h"
#include "types.h"

/* Only the id and signed cell coordinates accessed by this unit are known. */
typedef struct Unk1122bcWork {
    u8 pad_0000[0x35c];
    u16 unk_035c;
    u8 pad_035e[6];
    s8 unk_0364;
    s8 unk_0365;
} Unk1122bcWork;

/* Cell layout follows the byte state and halfword counter accesses below. */
typedef struct Unk1122bcCell {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} Unk1122bcCell;

/* Resource entry: this unit reads only byte +0x19. */
typedef struct Unk1122bcRecord {
    u8 pad_00[0x19];
    u8 unk_19;
} Unk1122bcRecord;

Unk1122bcWork *Unk02e000_GetWorkArea(void);
int Unk02f2a8_Unk_035b08(int group, int index);
int Unk0e651c_Unk_0e666c(u32 flag);
Unk1122bcRecord *Unk09a268_Unk_09c484(int index);
Unk1122bcCell *Unk02f2a8_GetCell38e8(int x, int y);
void func_0209a884(void *buffer, void *body);
void Unk09a268_Unk_09a80c(Unk1122bcCell *cell, int value);
void Unk09a268_Unk_09a830(Unk1122bcCell *cell, int value);
void Unk09a268_SetOnlyBit(Unk1122bcCell *cell, int bit);
int Unk09a268_Unk_09a844(Unk1122bcCell *cell);

/* Tests id against resource (8,4), requiring event flag 0x159 to equal 1. */
int Unk1122bc_Unk_1122bc(int id)
{
    if (id == Unk02f2a8_Unk_035b08(8, 4)) {
        if (Unk0e651c_Unk_0e666c(0x159) == 1) {
            return 1;
        }
    }
    return 0;
}

/* Initializes the current cell using resource entry 19's byte +0x19;
 * flag 0x159 selects its byte state, and the counter starts at zero. */
void func_021122f8(void)
{
    Unk1122bcRecord *record = Unk09a268_Unk_09c484(19);
    GameState *gs = GetGameState();
    Unk1122bcCell *cell = Unk02f2a8_GetCell38e8(
        Unk02e000_GetWorkArea()->unk_0364,
        Unk02e000_GetWorkArea()->unk_0365);
    int flag;

    func_0209a884(gs->unk_38e8, (u8 *)gs + 4);
    Unk09a268_Unk_09a80c(cell, 1);
    Unk09a268_Unk_09a830(cell, 0);
    Unk09a268_SetOnlyBit(cell, record->unk_19);
    flag = Unk0e651c_Unk_0e666c(0x159);
    cell->unk_01 = flag == 0 ? 3 : flag * 2 - 1;
    cell->unk_02 = 0;
}

/* Advances the current cell's counter; when the cell predicate equals 1,
 * updates its flags, cycles its byte state through 0..3, and returns 1. */
int func_02112394(void)
{
    Unk1122bcRecord *record = Unk09a268_Unk_09c484(19);
    int result = 0;
    Unk1122bcCell *cell = Unk02f2a8_GetCell38e8(
        Unk02e000_GetWorkArea()->unk_0364,
        Unk02e000_GetWorkArea()->unk_0365);

    cell->unk_02++;
    if (Unk09a268_Unk_09a844(cell) == 1) {
        Unk09a268_Unk_09a80c(cell, 1);
        Unk09a268_Unk_09a830(cell, 1);
        Unk09a268_SetOnlyBit(cell, record->unk_19);
        cell->unk_01++;
        if (cell->unk_01 >= 4) {
            cell->unk_01 = 0;
        }
        cell->unk_02 = 0;
        result = 1;
    }
    return result;
}

/* IsCurrent denotes equality with resource (8,4), as evidenced by the
 * comparison here and the active work-area id supplied by 0x02112460. */
int Unk1122bc_IsCurrent(int id)
{
    int result = 0;
    if (id == Unk02f2a8_Unk_035b08(8, 4)) {
        result = 1;
    }
    return result;
}

/* Returns zero only for the matching active id with predicate 0x021122BC false. */
u32 Unk1122bc_Unk_112460(void)
{
    u32 result = 1;
    if (Unk1122bc_IsCurrent(Unk02e000_GetWorkArea()->unk_035c) == 1) {
        if (Unk1122bc_Unk_1122bc(Unk02e000_GetWorkArea()->unk_035c) == 0) {
            result = 0;
        }
    }
    return result;
}

/* Returns zero when the active id satisfies predicate 0x021122BC, else one. */
int Unk1122bc_Unk_1124a0(void)
{
    int result = 1;
    if (Unk1122bc_Unk_1122bc(Unk02e000_GetWorkArea()->unk_035c) == 1) {
        result = 0;
    }
    return result;
}

/* Returns two when the active id satisfies predicate 0x021122BC, else zero. */
u32 Unk1122bc_Unk_1124c8(void)
{
    u32 result = 0;
    if (Unk1122bc_Unk_1122bc(Unk02e000_GetWorkArea()->unk_035c) == 1) {
        result = 2;
    }
    return result;
}
