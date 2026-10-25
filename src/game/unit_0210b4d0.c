#include "types.h"

/* Only the accessed fields are known; gaps preserve the observed ARM offsets. */
typedef struct { u8 pad[0x35c]; u16 unk35c; u8 gap[6]; s8 x, y; } Work;
/* Borrowed cell prefix: byte state and wrapping 16-bit update count. */
typedef struct { u8 unk0, state; u16 ticks; } Cell;
/* Borrowed entry prefix; byte 25 supplies the bit selector. */
typedef struct { u8 pad[25]; u8 bit; } Entry;
/* Map rectangle uses unsigned byte coordinates and extents, not end points. */
typedef struct { u8 pad[8]; u8 x, y, width, height; } Bounds;
/* The original clears 140 bytes; only its borrowed bounds pointer is decoded. */
typedef struct { Bounds *bounds; u32 opaque[34]; } Map;
extern Work *Unk02e000_GetWorkArea(void);
extern int Unk02f2a8_Unk_035b08(int, int);
extern int Unk0e651c_Unk_0e666c(int);
extern Entry *Unk09a268_Unk_09c484(int);
extern u8 *GetGameState(void);
extern u8 *GameState_GetBody(void);
extern Cell *Unk02f2a8_GetCell38e8(int, int);
extern void func_0209a884(void *, void *);
extern void Unk09a268_Unk_09a80c(Cell *, int);
extern void Unk09a268_Unk_09a830(Cell *, int);
extern void Unk09a268_SetOnlyBit(Cell *, int);
extern int Unk09a268_Unk_09a844(Cell *);
extern int Unk04bb9c_GetCtxUnka20(void);
extern void func_0204b6f4(void);
extern int func_02038ff8(Map *, void *, int, int);
extern u8 *Unk038fbc_Unk_039160(void *, int, int);
extern void Unk038fbc_Unk_039138(Map *);
int func_0210b4d0(int id);
int func_0210b6c8(int id);
void func_0210b7e4(int id);

/* Tests the flag associated with one of three IDs produced by 035b08. */
int func_0210b4d0(int id)
{
    int result = 0;
    if (id == Unk02f2a8_Unk_035b08(4, 6)) {
        if (Unk0e651c_Unk_0e666c(184) == 1) result = 1;
    } else if (id == Unk02f2a8_Unk_035b08(4, 7)) {
        if (Unk0e651c_Unk_0e666c(185) == 1) result = 1;
    } else if (id == Unk02f2a8_Unk_035b08(4, 1)) {
        if (Unk0e651c_Unk_0e666c(186) == 1) result = 1;
    }
    return result;
}

/* Initializes the borrowed current cell; selection 1/2 chooses flag 185/186,
 * otherwise flag 184. Evidence: calls and stores at 0210b558..0210b61c. */
void func_0210b558(int selection)
{
    Work *work;
    Cell *cell;
    Entry *entry;
    u8 *game;
    int flag;
    int choice = selection;
    int state;
    entry = Unk09a268_Unk_09c484(19);
    game = GetGameState();
    flag = 184;
    switch (choice) {
    case 0: break;
    case 1: flag = 185; break;
    case 2: flag = 186; break;
    }
    work = Unk02e000_GetWorkArea();
    cell = Unk02f2a8_GetCell38e8(work->x, Unk02e000_GetWorkArea()->y);
    func_0209a884(game + 0x38e8, game + 4);
    Unk09a268_Unk_09a80c(cell, 1);
    Unk09a268_Unk_09a830(cell, 0);
    Unk09a268_SetOnlyBit(cell, entry->bit);
    state = Unk0e651c_Unk_0e666c(flag);
    cell->state = state == 0 ? 3 : state * 2 - 1;
    cell->ticks = 0;
    func_0210b7e4(Unk04bb9c_GetCtxUnka20());
}

/* Advances the current cell's timer; returns one when its state changes. */
int func_0210b620(void)
{
    int result = 0;
    Entry *entry = Unk09a268_Unk_09c484(19);
    Work *work = Unk02e000_GetWorkArea();
    Cell *cell = Unk02f2a8_GetCell38e8(work->x, Unk02e000_GetWorkArea()->y);
    cell->ticks++;
    if (Unk09a268_Unk_09a844(cell) == 1) {
        Unk09a268_Unk_09a80c(cell, 1);
        Unk09a268_Unk_09a830(cell, 1);
        Unk09a268_SetOnlyBit(cell, entry->bit);
        cell->state++;
        if (cell->state >= 4) cell->state = 0;
        cell->ticks = 0;
        func_0204b6f4();
        result = 1;
    }
    return result;
}

/* Recognizes the same three generated IDs without consulting their flags. */
int func_0210b6c8(int id)
{
    int result = 0;
    if (id == Unk02f2a8_Unk_035b08(4, 6) ||
        id == Unk02f2a8_Unk_035b08(4, 7) ||
        id == Unk02f2a8_Unk_035b08(4, 1)) result = 1;
    return result;
}

/* Maps codes 16..19 to a state according to the current work-area flag. */
u8 Unk10b4d0_Unk_10b71c(u32 code)
{
    u8 result = 0;
    int flag = func_0210b4d0(Unk02e000_GetWorkArea()->unk35c);
    switch (code) {
    case 16: if (flag != 0) result = 2; break;
    case 17: if (flag == 0) result = 2; break;
    case 18: if (flag == 0) result = 3; else result = 1; break;
    case 19: if (flag == 0) result = 1; else result = 3; break;
    }
    return result;
}

/* Returns two when the current work-area ID has its associated flag set. */
u32 Unk10b4d0_Unk_10b794(void)
{
    u32 result = 0;
    if (func_0210b4d0(Unk02e000_GetWorkArea()->unk35c) == 1) result = 2;
    return result;
}

/* Returns one when the current work-area ID has its associated flag set. */
int Unk10b4d0_Unk_10b7bc(void)
{
    int result = 0;
    if (func_0210b4d0(Unk02e000_GetWorkArea()->unk35c) == 1) result = 1;
    return result;
}

/* Copies codes 16..19 into the destination map, swapping pairs when flagged.
 * Other IDs return immediately; the temporary map is released after traversal. */
void func_0210b7e4(int id)
{
    u8 *body;
    int flag;
    int x0, xmax, y, ymax, x;
    if (func_0210b6c8(id) == 0) return;
    Unk09a268_Unk_09c484(12);
    body = GameState_GetBody();
    flag = func_0210b4d0(id);
    Map map = {0};
    if (func_02038ff8(&map, body + 532, 0, 0) != 1) return;
    x0 = map.bounds->x;
    y = map.bounds->y;
    xmax = x0 + map.bounds->width;
    ymax = y + map.bounds->height;
    for (; y < ymax; y++) {
        for (x = x0; x < xmax; x++) {
            u8 *source = Unk038fbc_Unk_039160(&map, x, y);
            if (source != 0) {
                int change = 0;
                int value = 0;
                switch (*source) {
                case 16: change = 1; if (flag == 0) value = 16; else value = 17; break;
                case 17: change = 1; if (flag == 0) value = 17; else value = 16; break;
                case 18: change = 1; if (flag == 0) value = 18; else value = 19; break;
                case 19: change = 1; if (flag == 0) value = 19; else value = 18; break;
                }
                if (change == 1) {
                    u8 *destination = Unk038fbc_Unk_039160(body + 852, x, y);
                    if (destination != 0) *destination = value;
                }
            }
        }
    }
    Unk038fbc_Unk_039138(&map);
}
