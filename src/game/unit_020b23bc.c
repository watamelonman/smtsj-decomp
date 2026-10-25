#include "types.h"

/* Borrowed work view; coordinates at +0x7482/+0x7483 select a map cell. */
typedef struct Unk0b23bcWork {
    u8 pad_0000[0x5508];
    u8 cells[0x1f78];
    s8 active;
    s8 state;
    s8 x;
    s8 y;
} Unk0b23bcWork;

/* Only the cell tag is inspected by this unit's entry predicate. */
typedef struct Unk0b23bcCell {
    s8 tag;
    u8 index;
} Unk0b23bcCell;

Unk0b23bcCell *Unk0a6174_Unk_0a6a88(void *cells, int x, int y);
void func_02034dd0(void);
void Unk118b04_Unk_118e50(int id, int enabled);

/* For a tag-2 cell at the signed work coordinates, clear the active byte and
 * invoke the two entry callbacks. Other tags leave work unchanged and return 0.
 * Evidence: loads at +0x7482/+0x7483, tag comparison, and store at +0x7480. */
int func_020b23bc(Unk0b23bcWork *work)
{
    if (Unk0a6174_Unk_0a6a88(work->cells, work->x, work->y)->tag != 2)
        return 0;
    work->active = 0;
    func_02034dd0();
    Unk118b04_Unk_118e50(7, 1);
    return 1;
}
