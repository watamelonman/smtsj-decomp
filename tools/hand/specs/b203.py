PRE = r'''/* Unit record from func_02044ec4; only the icon id at +0x1d8 is read here. */
typedef struct Unk0b28e4Unit {
    u8 pad_000[0x1d8];
    u16 unk_1d8;                /* 0x1d8: id passed to func_020a1740/func_020a1428 */
} Unk0b28e4Unit;
extern const Unk0b28e4IconIds data_0213c488;
'''

F5634 = r'''/* Draws one roster row for roster entry `id` in row `slot`: background, icon,
 * state icon (states 1..11), the two labels, the bar, the category grid and
 * the eight command buttons. Same layout as func_020b5338. */
void func_020b5634(Unk0b28e4Obj *work, int id, int slot)
{
    u32 res0 = func_020445f4(18, 0);
    u32 res1 = func_020445f4(18, 1);
    Unk0b28e4Unit *unit = func_02044ec4(
        ((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[id])->unk_36c);
    Unk0b28e4IconRecord *record = func_020a1740(unit->unk_1d8);
    Unk0b28e4Kind *kind = func_020a1428(unit->unk_1d8);
    int tier;
    int ly;
    u16 *list;
    int row;
    int index;
    int gy;
    int col;
    int x;
    int i;

    func_0203f2d4(work->unk_0008, 0, slot * 56 + 16, work->unk_0004, 0, 16, 256, 56);
    func_020b5f08(record->unk_6a, (u8)(slot * 2 + 7), work->unk_0c3c[slot], unit, 0, 0, work->unk_0c54[slot]);
    work->unk_0c7c[slot] = func_0204a244(unit);
    if (work->unk_0c7c[slot] >= 1 && work->unk_0c7c[slot] <= 11) {
        Unk0b28e4IconIds ids = data_0213c488;
        func_020b61f0(ids.ids[work->unk_0c7c[slot]], (u8)(slot + 13), work->unk_0c48[slot], work->unk_0c60[slot]);
    }
    tier = 1;
    if (kind->unk_05 == 4) tier = 3;
    if (kind->unk_05 == 5) tier = 5;
    if (func_0204a244(unit) == 1) tier++;
    ly = slot * 56 + 19;
    Unk0b28e4_Unk_0b5e10(work->unk_0c34, func_0204fed8(res0, kind->unk_02), 34, ly, 8, tier);
    Unk0b28e4_Unk_0b5e10(work->unk_0c34, func_0204fed8(res1, unit->unk_1d8), 74, ly, 16, tier);
    func_020b3dc4(unit->unk_1d8, work->unk_0004, work->unk_0008, 75, (u8)(slot * 56 + 39));
    list = func_0204a0d8(unit);
    for (row = 0, index = 0, gy = slot * 56 + 44; row < 2; row++, index += 3, gy += 12) {
        for (col = 0; col < 3; col++) {
            if (list[index + col] != 0) {
                Unk0b28e4_Unk_0b5e10(work->unk_0c30, Unk0caea8_Unk_0cb044(list[index + col]), col * 83 + 6, gy, 16, 7);
            }
        }
    }
    for (i = 0, x = 143; i <= 7; x += 14, i++) {
        Unk0b28e4_Unk_0b5e10(work->unk_0c34, func_02049398(Unk0b28e4_GetEntry34((u8 *)unit, i + 8) + 5),
                             x, slot * 56 + 32, 2, 1);
    }
}'''

FIX = [('    u32 unk_0c7c[3];            /* 0x0c7c: per-slot record state last drawn */',
        '    s32 unk_0c7c[3];            /* 0x0c7c: per-slot record state last drawn (signed range test 1..11) */')]

SPECS = [('src/game/unit_020b28e4.c', [('func_020b5634', F5634)], PRE, FIX)]
