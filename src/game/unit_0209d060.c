#include "types.h"

/* The allocation in func_0209d084 is four bytes; callbacks access its only word. */
typedef struct Unk09d060Ctx {
    u32 unk_00;
} Unk09d060Ctx;

extern Unk09d060Ctx *data_02176274;

void func_02061424(Unk09d060Ctx *work);
void Unk0d1c98_Release(void);
s32 ScanVisor_Unk_0a2980(void);
s32 func_02061750(Unk09d060Ctx *work);
void func_020616ec(void *parent, void *child);
void func_020d1cb4(void);
Unk09d060Ctx *func_020611dc(void (*update)(Unk09d060Ctx *),
    void (*arg1)(void), u32 arg2, void (*destroy)(void),
    u32 size, u32 alignment, u32 arg6, u32 arg7);

/* Position filled by func_02049ca4/func_02049cd4 or set directly per kind. */
typedef struct Unk09d060Vec {
    s32 x;
    s32 y;
    s32 z;
} Unk09d060Vec;

/* Record from func_02044ec4; the byte at bits 16-23 of +0x00 selects a sub-entry. */
typedef struct Unk09d060Record {
    u32 unk_00;
    u8 pad_04[8];
    u8 unk_0c[4];       /* +0x0c address stored into Unk09d060Obj.unk_38; size guessed */
} Unk09d060Record;

/* Object returned by Unk06ae94_Call_06c130. */
typedef struct Unk09d060Obj {
    u8 pad_00[0x34];
    u32 unk_34;         /* +0x34 flags: 0x20 always, 0x02 in mode 5 */
    void *unk_38;       /* +0x38 */
} Unk09d060Obj;

/* Entry returned by func_02044618; two optional pairs start at +0x10. */
typedef struct Unk10fa60Entry {
    u8 pad_00[0x10];
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
} Unk10fa60Entry;

extern char data_0214c9b8[]; /* "ef_e" */
extern char data_0214c9c0[]; /* "_y" */
extern char data_0214c9c4[]; /* "ef_w" */

u32 Unk06dddc_Unk_06e06c(const char *name);
Unk09d060Record *func_02044ec4(u32 id);
void func_02049ca4(Unk09d060Record *entry, Unk09d060Vec *out);
void func_02049cd4(Unk09d060Record *entry, Unk09d060Vec *out);
int func_020153e0(const char *a, const char *b, u32 n);
int func_02015118(const char *s);
Unk09d060Obj *Unk06ae94_Call_06c130(u32 a, u32 b, u32 c, u32 d, u32 e, void *f, u32 g, u32 h);
int Unk06e4d8_Unk_06ea0c(int i);
void func_0206e8b0(u32 slot);
int Unk06ae94_Unk_06c8f8(u32 slot);
s32 Unk0a5680_GetEntryUnk14(u32 key);
u8 *Unk0a5680_GetEntrySub20(u32 key);
void Unk06ae94_Unk_06c8e0(Unk09d060Obj *obj, s32 a, u8 *b);
Unk10fa60Entry *func_02044618(const char *name);
void Unk06ae94_SetPair(void *pairs, u32 a, u32 b, int i);

/* Increment the allocated work word; evidence: load/add/store at 0209d060. */
void Unk09d060_Unk_09d060(Unk09d060Ctx *work)
{
    work->unk_00++;
}

/* Clear the singleton slot; evidence: zero store through 02176274 at 0209d070. */
void Unk09d060_Clear_data_02176274(void)
{
    data_02176274 = 0;
}

/* Create the singleton once; 0209d084 requests four bytes and links an optional parent. */
void func_0209d084(void *parent)
{
    if (data_02176274 != 0) return;
    data_02176274 = func_020611dc(Unk09d060_Unk_09d060, 0, 0,
        Unk09d060_Clear_data_02176274, 4, 4, 0xffff, 1);
    if (parent != 0) {
        func_020616ec(parent, data_02176274);
    }
    func_020d1cb4();
}

/* Free the singleton if present, then release its companion (calls at 0209d10c). */
void Unk09d060_Unk_09d10c(void)
{
    if (data_02176274 != 0) {
        func_02061424(data_02176274);
        data_02176274 = 0;
    }
    Unk0d1c98_Release();
}

/* Test the work only when the visor query succeeds; evidence: branches at 0209d13c. */
s32 Unk09d060_Unk_09d13c(void)
{
    if (ScanVisor_Unk_0a2980() == 0) {
        return 0;
    }
    return func_02061750(data_02176274) == 0;
}

/* Link child to the singleton when present; 0209d170 passes it as the first argument. */
void Unk09d060_Unk_09d170(void *child)
{
    if (data_02176274 != 0) {
        func_020616ec(data_02176274, child);
    }
}

/* Return the work word or zero without a singleton; evidence: loads at 0209d194. */
u32 Unk09d060_GetCtxUnk00(void)
{
    Unk09d060Ctx *work = data_02176274;
    if (work != 0) {
        return work->unk_00;
    }
    return 0;
}

/* Reset the work word if allocated; evidence: conditional zero store at 0209d1b0. */
void Unk09d060_Unk_09d1b0(void)
{
    if (data_02176274 != 0) {
        data_02176274->unk_00 = 0;
    }
}

/*
 * Spawn the effect `name` in its slot (Unk06dddc_Unk_06e06c returns 0xff for none),
 * placing it by `kind` from record `id` or a fixed offset, then link it to the
 * singleton and apply the optional pairs from func_02044618. Names starting "ef_e"
 * and ending "_y" use mode 1; "ef_w" in mode 5 stores the record's +0x0c address.
 */
void func_0209d1cc(const char *name, u32 id, u32 kind)
{
    u32 slot;
    Unk09d060Record *entry;
    u32 mode;
    Unk09d060Obj *obj;
    Unk10fa60Entry *pairs;
    Unk09d060Vec pos;

    slot = Unk06dddc_Unk_06e06c(name);
    if (slot == 0xff) {
        return;
    }
    entry = func_02044ec4(id);
    mode = 3;
    switch (kind) {
    case 0:
    case 3:
        if (entry != 0) {
            func_02049ca4(entry, &pos);
        }
        break;
    case 1:
    case 4:
        if (entry != 0) {
            func_02049cd4(entry, &pos);
        }
        break;
    case 6:
        pos.z = 0;
        pos.y = 0;
        pos.x = 0;
        break;
    case 9:
        mode = 1;
    case 8:
        pos.x = 0;
        pos.y = -5888;
        pos.z = 0;
        break;
    case 2:
    case 5:
        if (entry != 0) {
            func_02049ca4(entry, &pos);
        }
        mode = 5;
        break;
    case 7:
        pos.x = 0;
        pos.y = -10368;
        pos.z = 0;
        mode = 5;
        break;
    }
    if (func_020153e0(data_0214c9b8, name, 4) == 0) {
        if (func_020153e0(data_0214c9c0, name + (func_02015118(name) - 2), 2) == 0) {
            mode = 1;
        }
    }
    obj = Unk06ae94_Call_06c130(slot, pos.x, pos.y, pos.z, 0x3f800000, 0, 0, mode);
    Unk09d060_Unk_09d170(obj);
    obj->unk_34 |= 0x20;
    if (mode == 5) {
        obj->unk_34 |= 2;
        if (func_020153e0(data_0214c9c4, name, 4) == 0) {
            obj->unk_38 = &entry->unk_0c;
        }
    }
    if (Unk06e4d8_Unk_06ea0c(slot) != 0) {
        func_0206e8b0(slot);
    }
    if (Unk06ae94_Unk_06c8f8(slot) != 0 && ((entry->unk_00 >> 16) & 0xff) == 2) {
        s32 a = Unk0a5680_GetEntryUnk14(entry->unk_00);
        Unk06ae94_Unk_06c8e0(obj, a, Unk0a5680_GetEntrySub20(entry->unk_00));
    }
    pairs = func_02044618(name);
    if (pairs == 0) {
        return;
    }
    if (pairs->unk_10 != 0) {
        Unk06ae94_SetPair(obj, pairs->unk_10, pairs->unk_12, 0);
    }
    if (pairs->unk_14 != 0) {
        Unk06ae94_SetPair(obj, pairs->unk_14, pairs->unk_16, 1);
    }
}
