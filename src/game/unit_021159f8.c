#include "types.h"

/* Borrowed views contain only fields accessed by this unit. */
typedef struct Unk1159f8Cell {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} Unk1159f8Cell;

typedef struct Unk1159f8Record {
    u8 pad_00[0x19];
    u8 unk_19;
} Unk1159f8Record;

typedef struct Unk1159f8State {
    u8 pad_0000[4];
    u8 unk_0004[0x38e4];
    u8 unk_38e8[0x3b04];
    s32 unk_73ec;
} Unk1159f8State;

typedef struct Unk1159f8Work {
    u8 pad_000[0x35c];
    u16 unk_35c;
} Unk1159f8Work;

extern Unk1159f8Work *Unk02e000_GetWorkArea(void);
extern int Unk02f2a8_Unk_035b08(int group, int index);
extern int Unk0e651c_Unk_0e666c(int id);
extern Unk1159f8Record *Unk09a268_Unk_09c484(int id);
extern Unk1159f8State *GetGameState(void);
extern Unk1159f8Cell *Unk02f2a8_GetCell38e8(int x, int y);
extern void func_0209a884(void *destination, void *source);
extern void Unk09a268_Unk_09a80c(Unk1159f8Cell *cell, int value);
extern void Unk09a268_Unk_09a830(Unk1159f8Cell *cell, int value);
extern void Unk09a268_SetOnlyBit(Unk1159f8Cell *cell, int value);
extern int Unk09a268_Unk_09a844(Unk1159f8Cell *cell);

/* Query ids 346..348 for three coordinate pairs, only in the selected (8,3) area.
 * Evidence: the original compares these coordinates before calling 020e666c. */
int func_021159f8(int area, int x, int y)
{
    int result = 0;
    if (area == Unk02f2a8_Unk_035b08(8, 3)) {
        if (x == 23 && y == 18) {
            result = Unk0e651c_Unk_0e666c(346);
        } else if (x == 22 && y == 17) {
            result = Unk0e651c_Unk_0e666c(347);
        } else if (x == 24 && y == 17) {
            result = Unk0e651c_Unk_0e666c(348);
        }
    }
    return result;
}

/* Initialize the selected cell; selectors 6 and 7 override the default pair.
 * Borrows game state and record 19; no ownership is transferred. */
void func_02115a80(int selector)
{
    Unk1159f8Record *record = Unk09a268_Unk_09c484(19);
    Unk1159f8State *state = GetGameState();
    int x = 23;
    int y = 18;
    Unk1159f8Cell *cell;
    switch (selector) {
    case 5: break;
    case 6: x = 22; y = 17; break;
    case 7: x = 24; y = 17; break;
    }
    cell = Unk02f2a8_GetCell38e8(x, y);
    func_0209a884(state->unk_38e8, state->unk_0004);
    Unk09a268_Unk_09a80c(cell, 1);
    Unk09a268_Unk_09a830(cell, 0);
    Unk09a268_SetOnlyBit(cell, record->unk_19);
    cell->unk_01 = 1;
    cell->unk_02 = 0;
}

/* Advance the selected cell's 16-bit counter, wrapping naturally. A helper
 * result of exactly one changes its state to 2 and returns one; otherwise zero. */
int func_02115b1c(void)
{
    int result = 0;
    Unk1159f8Record *record = Unk09a268_Unk_09c484(19);
    int selector = GetGameState()->unk_73ec;
    int x = 23;
    int y = 18;
    Unk1159f8Cell *cell;
    switch (selector) {
    case 5: break;
    case 6: x = 22; y = 17; break;
    case 7: x = 24; y = 17; break;
    }
    cell = Unk02f2a8_GetCell38e8(x, y);
    cell->unk_02++;
    if (Unk09a268_Unk_09a844(cell) == 1) {
        Unk09a268_Unk_09a80c(cell, 1);
        Unk09a268_Unk_09a830(cell, 1);
        Unk09a268_SetOnlyBit(cell, record->unk_19);
        cell->unk_01 = 2;
        cell->unk_02 = 0;
        result = 1;
    }
    return result;
}

/* Compare an area id with selector (8,3), as evidenced by the selector call
 * and equality comparison in the original; returns a boolean integer. */
int Unk1159f8_IsCurrent(int area)
{
    int result = 0;
    if (area == Unk02f2a8_Unk_035b08(8, 3)) {
        result = 1;
    }
    return result;
}

/* At (23,17) in the selected area, require all three queries to be nonzero.
 * Other positions return one without querying ids 346..348. */
int func_02115bf4(int area, int x, int y)
{
    int result = 1;
    if (area == Unk02f2a8_Unk_035b08(8, 3) && x == 23 && y == 17) {
        if (!Unk0e651c_Unk_0e666c(346) ||
            !Unk0e651c_Unk_0e666c(347) ||
            !Unk0e651c_Unk_0e666c(348)) {
            result = 0;
        }
    }
    return result;
}

/* Use the borrowed work area's id for the coordinate query; map exactly one
 * to two, and every other result to zero. */
u32 Unk1159f8_Unk_115c68(int x, int y)
{
    u32 result = 0;
    Unk1159f8Work *work = Unk02e000_GetWorkArea();
    if (func_021159f8(work->unk_35c, x, y) == 1) {
        result = 2;
    }
    return result;
}
