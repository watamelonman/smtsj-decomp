/* Special entry and cell handling for the (8, 6) lookup. */
#include "types.h"
#include "GameState.h"

/* Local view of the work area: only the current lookup ID halfword at
 * +0x35c is used by this TU. */
typedef struct Unk116360Work {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} Unk116360Work;

/* Local view of GameState: GameState.h still covers +0x74f0 with pad_7481,
 * so this TU reads the word through a tail view (same approach as
 * Unk02f2a8GameStateTail in unit_0202f2a8.c). */
typedef struct Unk116360GameStateTail {
    u8 pad_0000[0x74f0];
    u32 unk_74f0;
} Unk116360GameStateTail;

/* Record returned by Unk09a268_Unk_09c484; only the bit index byte at +0x19
 * is used here (unit_0209a268.c reads the same byte as record->unk_19). */
typedef struct Unk116360Record {
    u8 pad_00[0x19];
    u8 unk_19;
} Unk116360Record;

Unk116360Work *Unk02e000_GetWorkArea(void);
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
    Unk116360Work *work;
    if (entry == 0) {
        return;
    }
    work = Unk02e000_GetWorkArea();
    Unk116360_FillEntry(entry, work->unk_035c, x, y);
}

/* Returns 2 for the special position in the current work area, otherwise 0. */
u32 Unk116360_Unk_116438(u32 x, u32 y)
{
    Unk116360Work *work;
    int special;
    u32 result = 0;
    work = Unk02e000_GetWorkArea();
    special = Unk116360_Unk_116360(work->unk_035c, x, y);
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

/* No shared prototypes exist for these callees; the cell parameter type is
 * inferred from this TU (other TUs pass the cell as u32). */
Unk116360Record *Unk09a268_Unk_09c484(int index);
Unk116360Cell *Unk02f2a8_GetCell38e8(int x, int y);
void Unk09a268_Unk_09a80c(Unk116360Cell *cell, int value);
void Unk09a268_Unk_09a830(Unk116360Cell *cell, int value);
void Unk09a268_Unk_09a870(Unk116360Cell *cell, int value);
void Unk09a268_SetOnlyBit(Unk116360Cell *cell, int bit);

/* Updates the (36,18) cell for the (8,6) ID using game-state offset 0x74f0
 * and the external state; the two transitions reset the halfword at offset 2. */
void func_02116470(void)
{
    GameState *game = GetGameState();
    Unk116360Record *entry;
    Unk116360Cell *cell;
    int id;
    int state;
    if (game == 0) {
        return;
    }
    entry = Unk09a268_Unk_09c484(11);
    cell = 0;
    id = Unk02e000_GetWorkArea()->unk_035c;
    state = Unk03e43c_Unk_03fa28();
    if (id == Unk02f2a8_Unk_035b08(8, 6)) {
        cell = Unk02f2a8_GetCell38e8(36, 18);
    }
    if (cell == 0) {
        return;
    }
    /* The two branches repeat the same calls and stores to match the original. */
    if (((Unk116360GameStateTail *)game)->unk_74f0 != 0 && state == 0) {
        if (cell->state == 0) {
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_Unk_09a870(cell, 0);
            Unk09a268_SetOnlyBit(cell, entry->unk_19);
            cell->state = 1;
            cell->unk_02 = 0;
        }
    } else if (((Unk116360GameStateTail *)game)->unk_74f0 == 0 && state != 0) {
        if (cell->state == 2) {
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_Unk_09a870(cell, 0);
            Unk09a268_SetOnlyBit(cell, entry->unk_19);
            cell->state = 3;
            cell->unk_02 = 0;
        }
    }
}
