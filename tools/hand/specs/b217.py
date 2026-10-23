F4E28 = r'''/* Counts how many units of record `id` (at most 98) the shared budget at
 * +0x344 covers: each unit costs func_020e49cc(0, id) and, until
 * func_020e4ca4 reports the record or a flagged record leaves the
 * 0f4510 set, one count of each entry's material (stopping when an owned
 * amount would go negative). */
int func_020e4e28(Unk0e1648Work *work, u32 id)
{
    Unk0e1648Rec *record = (Unk0e1648Rec *)func_020f3de8(work->unk_0068, id);
    s32 budget = Unk02e000_GetWorkArea()->value;
    int owned[3] = {0, 0, 0};
    int i;
    int price;
    int count;
    int done;

    for (i = 0; i < 3; i++) {
        if (record->ents[i].a != 0) owned[i] = func_0209993c(record->ents[i].a);
    }
    price = func_020e49cc(0, record->id);
    count = 0;
    done = 0;
    do {
        budget -= price;
        if (budget < 0) break;
        if (func_020e4ca4(work, id) == 0 && done == 0) {
            for (i = 0; i < 3; i++) {
                if (record->ents[i].a != 0) {
                    owned[i] -= record->ents[i].b;
                    if (owned[i] < 0) return count;
                }
            }
            if (record->unk_03 != 0 && Unk0f3db4_Unk_0f4510(work->unk_0068, id) == 0) done = 1;
        }
        count++;
    } while (count != 99);
    return count;
}'''

PRE32 = r'''void Unk118b04_Unk_118e50(u32 kind, s32 value);
void Unk0f3db4_Unk_0f4398(Unk0e1648Rec *record, s32 count);
void Unk0f3db4_Unk_0f4538(u32 kind, u32 index);
void func_02099a28(u32 id, s32 count);
'''

F32E8 = r'''/* Pays for work->unk_0098 units of the selected record: charges
 * unk_0098 * unk_00c8 to the shared budget (reported through 118e50 kind
 * 18), registers the record through 0f4398 (one unit for a flagged record
 * not yet in the 0f4510 set, none for one already in it), adds the units
 * with func_02099a28, then marks the record in the 0f4510 set and clears
 * +0xee8 when it was not there. */
void func_020e32e8(Unk0e1648Work *work)
{
    s32 count = work->unk_0098;
    s32 value = work->unk_00c8 * count;
    int id;
    Unk0e1648Rec *record;
    int add;
    s32 units;

    Unk02e000_GetWorkArea()->value -= value;
    Unk0fc584_Unk_0fc86c();
    Unk118b04_Unk_118e50(18, value);
    id = Unk0e1648_Unk_0e2da0(work)->unk_0002;
    record = (Unk0e1648Rec *)func_020f3de8(work->unk_0068, id);
    add = 0;
    units = count;
    if (record->unk_03 != 0) {
        if (Unk0f3db4_Unk_0f4510(work->unk_0068, id) == 0) {
            add = 1;
            units = 1;
        }
    } else {
        add = 1;
    }
    if (add != 0) {
        Unk0f3db4_Unk_0f4398(record, units);
    }
    func_02099a28(record->id, count);
    if (Unk0f3db4_Unk_0f4510(work->unk_0068, id) != 0) {
        return;
    }
    Unk0f3db4_Unk_0f4538(work->unk_0068, id);
    work->unk_0ee8 = 0;
}'''

SPECS = [('src/game/unit_020e1648.c', [('func_020e32e8', F32E8), ('func_020e4e28', F4E28)], PRE32)]
