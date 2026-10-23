PRE = r'''s32 *Unk038fbc_GetElement(u32 handle, u32 kind, u32 index);
u32 Unk02f2a8_Unk_0349c4(void *map, int x, int y);
int Unk0e651c_Get2Bits(u32 value, u32 index);
'''

FCE30 = r'''/* Tests the map entry at the transition coordinates: when the two-bit field
 * selected by element 8 of the entry is 3, the current cell gets bit 3, loses
 * bit 4, takes record 5's state bit and becomes kind 1 (type-1 record at
 * work +996) or kind 3, then func_0209c548 runs; otherwise the transition
 * kind becomes -1. */
void func_0209ce30(u8 *work)
{
    Unk09a268Transition *w = (Unk09a268Transition *)work;
    u8 *entry;
    u8 *element;
    Unk09a268Rec *record;
    Unk09a268Cell *cell;

    entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(work + 4, w->x, w->y), w->x, w->y);
    element = (u8 *)Unk038fbc_GetElement(Unk02f2a8_Unk_034970(work + 4, w->x, w->y), 8, entry[1]);
    if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(work + 4, w->x, w->y), *element) == 3) {
        record = Unk09a268_Unk_09c484(5);
        cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
        if (Unk09a268_IsType1(Unk0392f8_Unk_0394b8(work + 996, w->x, w->y)) == 1) {
            Unk09a268_Unk_09a80c((u32)cell, 1);
            Unk09a268_Unk_09a830((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, record->unk_19);
            cell->kind = 1;
            cell->counter = 0;
        } else {
            Unk09a268_Unk_09a80c((u32)cell, 1);
            Unk09a268_Unk_09a830((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, record->unk_19);
            cell->kind = 3;
            cell->counter = 0;
        }
        func_0209c548((Unk09a268MapWork *)work);
    } else {
        w->kind = -1;
    }
}'''

FCBF8 = r'''/* Tests the map entry at the transition coordinates: when the two-bit field
 * selected by bits 8..15 of element 7 of the entry is 3, the current cell gets bit 3, loses
 * bit 4, takes record 5's state bit and becomes kind 1 (type-1 record at
 * work +996) or kind 3, then func_0209c548 runs; otherwise the transition
 * kind becomes -1. */
void func_0209cbf8(u8 *work)
{
    Unk09a268Transition *w = (Unk09a268Transition *)work;
    u8 *entry;
    s32 *element;
    Unk09a268Rec *record;
    Unk09a268Cell *cell;

    entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(work + 4, w->x, w->y), w->x, w->y);
    element = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(work + 4, w->x, w->y), 7, entry[1]);
    if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(work + 4, w->x, w->y),
                          (u32)(*element << 16) >> 24) == 3) {
        record = Unk09a268_Unk_09c484(5);
        cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
        if (Unk09a268_IsType1(Unk0392f8_Unk_0394b8(work + 996, w->x, w->y)) == 1) {
            Unk09a268_Unk_09a80c((u32)cell, 1);
            Unk09a268_Unk_09a830((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, record->unk_19);
            cell->kind = 1;
            cell->counter = 0;
        } else {
            Unk09a268_Unk_09a80c((u32)cell, 1);
            Unk09a268_Unk_09a830((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, record->unk_19);
            cell->kind = 3;
            cell->counter = 0;
        }
        func_0209c548((Unk09a268MapWork *)work);
    } else {
        w->kind = -1;
    }
}'''

SPECS = [('src/game/unit_0209a268.c', [('func_0209cbf8', FCBF8), ('func_0209ce30', FCE30)], PRE)]
