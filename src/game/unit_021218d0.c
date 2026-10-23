#include "types.h"

/* Borrowed layout views; padding denotes fields unused by these routines. */
typedef struct Unk1218d0Object {
    u32 unk_000;
    u8 pad_004[36];
    u8 *unk_028;
    u32 unk_02c;
    u8 pad_030[8];
    u32 unk_038;
    u8 pad_03c[308];
    u32 unk_170;
    u8 pad_174[24];
    u16 unk_18c[6];
    u8 unk_198[32];
    u16 unk_1b8[6];
    u8 pad_1c4[25];
    u8 unk_1dd;
    u8 pad_1de[164];
    u8 unk_282;
} Unk1218d0Object;

/* Manager prefix owns three borrowed slot pointers and an embedded object. */
typedef struct Unk1218d0Manager {
    u8 pad_000[60];
    u16 unk_03c;
    u8 pad_03e[42];
    Unk1218d0Object *unk_068[3];
    u8 pad_074[24];
    Unk1218d0Object unk_08c;
    u8 pad_310[16];
    u8 unk_320;
} Unk1218d0Manager;

/* Persistent work view; saved IDs are halfwords and empty area indices are -1. */
typedef struct Unk1218d0Work {
    u8 pad_000[28];
    u16 unk_01c;
    u16 unk_01e;
    u8 pad_020[40];
    u8 unk_048;
    u8 pad_049[35];
    u16 unk_06c;
    u8 pad_06e[742];
    s8 unk_354[3];
} Unk1218d0Work;

/* Borrowed area record: only the three saved halfword fields are exposed. */
typedef struct Unk1218d0Record {
    u8 pad_00[30];
    u16 unk_1e;
    u16 unk_20;
    u8 pad_22[18];
    u16 unk_34;
} Unk1218d0Record;

/* Lookup result packs category, counter index and flags into two halfwords. */
typedef struct Unk1218d0Entry {
    u8 pad_00[38];
    union {
        u16 raw;
        struct { u16 low : 2; u16 unused : 4; u16 category : 5; u16 index : 5; } bits;
    } unk_26;
    u16 unk_28 : 4;
    u16 unused_28 : 12;
} Unk1218d0Entry;

/* Only bit zero of the lookup result byte controls whether an ID is saved. */
typedef struct Unk1218d0Flags {
    u8 pad_00[3];
    u8 unk_03 : 1;
    u8 unused_03 : 7;
} Unk1218d0Flags;

Unk1218d0Entry *func_020cb21c(u32 id);
Unk1218d0Manager *Unk044904_Get_data_0215ee98(void);
Unk1218d0Object *Unk044904_FindInactiveSlot(void);
Unk1218d0Work *Unk02e000_Thunk_0202e788(void);
Unk1218d0Work *Unk02e000_GetWorkArea(void);
Unk1218d0Record *Unk02e000_GetAreaRecord(int index);
Unk1218d0Flags *func_020982c0(s8 id);
void func_0204ae84(void *work);
void func_0204a884(Unk1218d0Object *object);
int Unk02ee5c_GetTierFromField70(void);
void func_021219d0(u32 *field, Unk1218d0Work *work);
void func_02096c8c(void);
void func_0209786c(Unk1218d0Record *record);
void func_02122494(Unk1218d0Object *object, u32 id, u32 value, int mode);

/* Accumulate category counters from six IDs; evidence: packed fields at +38/+40. */
void func_021218d0(Unk1218d0Object *object)
{
    int i;
    for (i = 0; i < 6; i++) {
        Unk1218d0Entry *entry;
        if (object->unk_18c[i] == 0) continue;
        entry = func_020cb21c(object->unk_18c[i]);
        if (entry == 0) continue;
        if (entry->unk_26.bits.category == 5) {
            switch (entry->unk_28) {
            case 0: break;
            case 5:
                object->unk_198[entry->unk_26.bits.index]++;
                break;
            case 6:
                object->unk_198[entry->unk_26.bits.index] += 2;
                break;
            }
        }
    }
}

/* Latch bit zero when any of six referenced entries has nonzero low flag bits. */
void func_02121970(Unk1218d0Object *object)
{
    u16 *ids = object->unk_1b8;
    int i;
    for (i = 0; i < 6; i++) {
        Unk1218d0Entry *entry;
        if (ids[i] == 0) continue;
        entry = func_020cb21c(ids[i]);
        if (entry == 0) continue;
        if (entry->unk_26.bits.low != 0) {
            object->unk_282 = (object->unk_282 & ~1) | 1;
            return;
        }
    }
}

/* Initialize the manager's embedded object from the persistent work area. */
int func_02121d2c(void)
{
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    func_0204ae84(&manager->unk_320);
    func_0204a884(&manager->unk_08c);
    manager->unk_08c.unk_000 = 0x10000;
    manager->unk_08c.unk_028 = &Unk02e000_Thunk_0202e788()->unk_048;
    manager->unk_08c.unk_1dd = Unk02ee5c_GetTierFromField70();
    func_021219d0(&manager->unk_08c.unk_02c, Unk02e000_Thunk_0202e788());
    func_02121970(&manager->unk_08c);
    return 1;
}

/* Copy the embedded object's selected values back; validate the signed byte ID first. */
int func_02121d84(void)
{
    Unk1218d0Manager *manager;
    Unk1218d0Work *work = Unk02e000_Thunk_0202e788();
    manager = Unk044904_Get_data_0215ee98();
    int id;
    Unk1218d0Flags *flags;
    work->unk_06c = 0;
    id = manager->unk_08c.unk_170;
    flags = func_020982c0((s8)id);
    if (flags != 0 && flags->unk_03) work->unk_06c = id;
    work->unk_01c = manager->unk_08c.unk_02c;
    work->unk_01e = manager->unk_08c.unk_038;
    func_02096c8c();
    return 1;
}

/* Save a non-null object's values into its one-based area record; return success. */
int func_02122188(Unk1218d0Object *object)
{
    Unk1218d0Record *record;
    int id;
    Unk1218d0Flags *flags;
    if (object == 0) return 0;
    record = Unk02e000_GetAreaRecord((u16)object->unk_000 - 1);
    record->unk_34 = 0;
    id = object->unk_170;
    flags = func_020982c0((s8)id);
    if (flags != 0 && flags->unk_03) record->unk_34 = id;
    record->unk_1e = object->unk_02c;
    record->unk_20 = object->unk_038;
    func_0209786c(record);
    return 1;
}

/* Store three zero-based area indices, using -1 for an unoccupied manager slot. */
void func_02122200(void)
{
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    Unk1218d0Work *work = Unk02e000_GetWorkArea();
    int i;
    for (i = 0; i < 3; i++) {
        if (manager->unk_068[i] == 0) work->unk_354[i] = -1;
        else work->unk_354[i] = (u16)manager->unk_068[i]->unk_000 - 1;
    }
}

/* Allocate an inactive slot and assign the next counter ID with bit 17 set. */
u32 Unk1218d0_Unk_122544(u32 value, int mode)
{
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    Unk1218d0Object *object = Unk044904_FindInactiveSlot();
    u32 id = manager->unk_03c | 0x20000;
    manager->unk_03c++;
    func_02122494(object, id, value, mode);
    func_02121970(object);
    return id;
}

/* Reinitialize an existing slot with its current ID and mode -1, then refresh flags. */
u32 Unk1218d0_Unk_122590(u32 value, Unk1218d0Object *object)
{
    func_02122494(object, object->unk_000, value, -1);
    func_02121970(object);
    return object->unk_000;
}
