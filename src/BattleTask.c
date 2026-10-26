#include "types.h"

/* Layout views retain unknown fields; offsets come from the original loads. */
typedef struct BattleEntry {
    u32 unk_000;
    u8 pad_004[0x1d8 - 4];
    u16 unk_1d8;
} BattleEntry;
/* Current work view; ten slot pointers begin at +0x64. */
typedef struct BattleWork {
    u8 pad_000[0x40];
    u32 unk_040_low : 9;
    u32 unk_040_flag : 1;
    u32 unk_040_high : 22;
    u8 pad_044[0x64 - 0x44];
    BattleEntry *unk_064[10];
} BattleWork;
/* Two signed coordinates passed together as a single word. */
typedef struct BattlePair { s16 x, y; } BattlePair;
/* Three signed fixed-point coordinates passed by value. */
typedef struct BattleVector { s32 x, y, z; } BattleVector;
/* Resource object view with position and control fields at original offsets. */
typedef struct BattleObject {
    void *unk_000;
    s32 unk_004, unk_008;
    u8 pad_00c[0x24 - 0xc];
    s32 unk_024;
    u8 pad_028[8];
    s32 unk_030;
    u8 pad_034[8];
    s32 unk_03c;
} BattleObject;
/* Signed halfword resource bounds; unknown fields preserve the original spacing. */
typedef struct BattleBounds { s16 unk_000[2]; s16 unk_004; s16 unk_006; s16 unk_008; s16 unk_00a; s16 unk_00c; } BattleBounds;
/* Resource descriptor owns the bounds pointer at +0x18c. */
typedef struct BattleResource { u8 pad_000[0x18c]; BattleBounds *unk_18c; } BattleResource;
/* Partial resource context; the tail marks an address, not its allocation size. */
typedef struct BattleResourceWork { u8 pad_000[0x7000]; u8 unk_7000[1]; } BattleResourceWork;
/* Global context view locates the resource context at +0x9b0. */
typedef struct BattleGlobal { u8 pad_000[0x9b0]; BattleResourceWork unk_9b0; } BattleGlobal;

BattleWork *Unk044904_Get_data_0215ee98(void);
void Unk06e4d8_Unk_06e538(void);
void func_0206eab4(void);
void Unk071dc0_Unk_071de4(void);
void func_02093a1c(void);
void func_0206df10(void);
void Unk06e4d8_Unk_06e680(void);
void Unk06ea70_Unk_06eb54(void);
void Unk071dc0_Unk_071e08(void);
void Unk071dc0_Unk_072200(void);
void Unk0939f0_Unk_093da4(void);
extern u32 data_02143334[];
extern BattleGlobal *data_0215eea0;
void func_02053048(void);
void func_02049c28(BattleEntry *entry, BattlePair *out);
void func_020a59c4(s32 value);
s32 func_020a1854(u16 value);
void Unk0a5680_Unk_0a5fb0(void);
s32 func_0204a9ec(BattleEntry *entry);
void func_020a609c(s32 value);
void func_02013c68(void *base, u32 count, u32 size, int (*compare)(BattleEntry **, BattleEntry **));
BattleEntry *func_02044ec4(u32 id);
BattleObject *func_020a22e0(void *base, u16 id, s32 mode);
BattleResource *func_020a2250(void *base, u16 id);
void func_020a5dac(BattleObject *object, u32 a, s32 b, s32 c);
void func_0205c408(void *object, s32 value);
s32 func_02050074(s32 a, s32 b);
void func_0205c41c(void *object, s32 value);
void func_0205c6e0(void *object);
void func_02049c0c(BattleEntry *entry, BattlePair pair);
void func_02049c3c(BattleEntry *entry, BattlePair pair);
void func_02049c88(BattleEntry *entry, BattleVector vector);
void func_02049cb8(BattleEntry *entry, BattleVector vector);

/* Track whether work exists; release the latched state once work disappears. */
int BattleTask_Unk_0481d4(void)
{
    if (Unk044904_Get_data_0215ee98() == 0) {
        if (*data_02143334 == 1) {
            func_02053048();
            *data_02143334 = 0;
        }
    } else {
        *data_02143334 = 1;
    }
    return Unk044904_Get_data_0215ee98() != 0;
}

/* Invoke the four subsystem callbacks in the order required by the original. */
void BattleTask_Unk_04822c(void)
{
    Unk06e4d8_Unk_06e538();
    Unk071dc0_Unk_071de4();
    func_0206eab4();
    func_02093a1c();
}

/* Invoke the six companion callbacks in their original order. */
void BattleTask_Unk_048244(void)
{
    func_0206df10();
    Unk071dc0_Unk_072200();
    Unk06ea70_Unk_06eb54();
    Unk071dc0_Unk_071e08();
    Unk06e4d8_Unk_06e680();
    Unk0939f0_Unk_093da4();
}

/* Submit up to six signed character IDs, or the ten work slots when absent. */
void func_02048264(u32 unused, const s8 *ids)
{
    BattleWork *work = Unk044904_Get_data_0215ee98();
    int i;
    if (ids) {
        for (i = 0; i < 6; i++) {
            if (ids[i] == 0) break;
            func_020a59c4(ids[i] - 65);
        }
    } else {
        for (i = 0; i < 10; i++) {
            BattleEntry *entry = work->unk_064[i];
            if (entry && ((entry->unk_000 >> 16) & 255) == 2)
                func_020a59c4(func_020a1854(entry->unk_1d8));
        }
    }
    Unk0a5680_Unk_0a5fb0();
}

/* Configure an entry's resource object and paired positions; coordinates use 12 fractional bits. */
BattleObject *func_020482f0(u32 id, s32 a, s32 b)
{
    BattleEntry *entry = func_02044ec4(id);
    BattleObject *object = func_020a22e0(data_0215eea0->unk_9b0.unk_7000, entry->unk_1d8, 1);
    BattleBounds *bounds;
    BattlePair pair;
    BattleVector vector;
    func_020a5dac(object, id, a, b);
    func_0205c408(object->unk_000, 0);
    func_0205c41c(object->unk_000, func_02050074(0, 4) << 2);
    func_0205c6e0(object->unk_000);
    object->unk_024 = 1;
    object->unk_030 = 2;
    object->unk_03c = 0;
    bounds = func_020a2250(data_0215eea0->unk_9b0.unk_7000, entry->unk_1d8)->unk_18c;
    pair.x = object->unk_004;
    pair.y = object->unk_008;
    func_02049c0c(entry, pair);
    pair.y = object->unk_008 + bounds->unk_00c - bounds->unk_004;
    func_02049c3c(entry, pair);
    vector.x = ((object->unk_004 - 128) << 12) / 32;
    vector.y = (- (object->unk_008 + bounds->unk_008 - 96) << 12) / 32;
    vector.z = 0;
    func_02049c88(entry, vector);
    vector.x = ((object->unk_004 - 128) << 12) / 32;
    vector.y = (- (object->unk_008 + bounds->unk_00a - 96) << 12) / 32;
    vector.z = 0;
    func_02049cb8(entry, vector);
    return object;
}

/* Compare the signed first coordinate, treating missing entries as 256. */
int BattleTask_Unk_0484d0(BattleEntry **a, BattleEntry **b)
{
    s16 x = 256, y = 256;
    BattlePair tx, ty;
    if (*a) { func_02049c28(*a, &tx); x = tx.x; }
    if (*b) { func_02049c28(*b, &ty); y = ty.x; }
    return x - y;
}

/* Configure eligible type-2 slots, propagate bit 9, and order six pointer slots.
 * The caller supplies an unused global context in r0. */
void func_02048520(BattleGlobal *unused)
{
    BattleWork *work = Unk044904_Get_data_0215ee98();
    int i;
    for (i = 0; i < 10; i++) {
        BattleEntry *entry = work->unk_064[i];
        if (entry && ((entry->unk_000 >> 16) & 255) == 2 && !func_0204a9ec(entry))
            func_020482f0(entry->unk_000, 0, 0);
    }
    if (work->unk_040_flag) func_020a609c(1);
    else func_020a609c(0);
    func_02013c68(&work->unk_064[4], 6, 4, BattleTask_Unk_0484d0);
}


/* Borrowed initialization views; offsets follow func_0204870c's ARM accesses. */
typedef struct BattleInitFlags {
    u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 b3 : 1;
    u32 b4 : 1; u32 b5 : 1; u32 b6 : 1; u32 b7 : 1;
    u32 b8 : 1; u32 b9 : 1; u32 b10 : 1; u32 b11 : 1;
    u32 b12 : 1; u32 b13 : 1; u32 b14 : 1; u32 b15 : 1;
    u32 b16 : 1; u32 b17 : 1; u32 b18 : 1; u32 b19 : 1;
    u32 b20 : 1; u32 b21 : 1; u32 b22 : 1; u32 b23 : 1;
    u32 b24 : 1; u32 b25 : 1; u32 b26 : 1; u32 b27 : 1;
    u32 b28 : 1; u32 b29 : 1; u32 b30 : 1; u32 b31 : 1;
} BattleInitFlags;
/* Request fields are borrowed for initialization; the final four IDs are halfwords. */
typedef struct BattleInitRequest {
    u32 ids[6]; s16 value; u16 pad_01a; BattleInitFlags flags;
    u8 mode; u8 pad_021[7]; u32 value_028, value_02c, value_030;
    s8 text_034[8]; s8 text_03c[16]; u16 entries[4];
} BattleInitRequest;
/* Caller-owned output contains a control word at +0x3c and totals 0x44 bytes. */
typedef struct BattleInitOutput { u8 pad[0x3c]; BattleInitFlags flags; u32 tail; } BattleInitOutput;
/* Full work size is established by allocation; embedded entries have stride 0x2e0. */
typedef struct BattleInitEntry { u32 id; u8 pad[0x2dc]; } BattleInitEntry;
/* Work owns embedded slot storage; the context tail denotes an address only. */
typedef struct BattleInitWork {
    u8 pad_000[0x38]; u16 value_038; u8 pad_03a[4]; s16 value_03e;
    BattleInitFlags flags; u32 value_044, value_048, value_04c;
    u8 pad_050[12]; u32 value_05c; BattleInitOutput *output;
    BattleInitEntry *slots[10]; BattleInitEntry first;
    BattleInitEntry entries[12]; BattleInitEntry extra_entries[6]; u8 pad_372c[0x77bc-0x372c];
    u32 records[6][3]; u8 pad_7804[0x7870-0x7804];
    void *value_7870; u8 pad_7874[0x798c-0x7874];
    void *resources[9]; u8 context[1];
} BattleInitWork;
void func_020580ec(s32 value);
void *func_020611dc(void (*a)(void), void (*b)(void), s32 zero, void (*c)(void), u32 size, s32 d, s32 e, s32 f);
void func_02049044(void); void func_0204915c(void); void func_02048ef0(void);
void func_02008848(void *dst, s32 value, u32 size);
void Unk0e8228_Call_02008848(void);
void Unk044904_Unk_044e90(void *work);
void Unk0a0ce4_Unk_0a0d30(s32 value);
void func_0209d084(void *work);
void Unk0946e0_ResetRect(void);
void *Unk0946e0_Unk_0946e0(void);
void Unk0939f0_Set_data_02175d8c(void *value);
void Unk044394_Unk_044428(s32 value);
void Unk044394_Unk_044534(s32 value);
void *func_02051610(const void *name);
void func_02048ff4(void *work);
void *Unk044904_Unk_045048(void);
s32 func_02015118(const void *text);
void *Unk044904_Unk_045080(void);
void func_020f7f68(void *dst, const void *src);
void Unk0f7eb4_Unk_0f8078(void *dst);
s8 *Unk02e000_GetWorkArea(void);
void Unk1218d0_Unk_122590(u16 id, BattleInitEntry *entry);
void func_02121d2c(void);
void func_02122074(s32 id);
void Unk1218d0_Unk_122544(u16 id, s32 value);
void func_020a587c(void *work, void *context);
void Unk0b28e4_Unk_0b62e8(void); void func_020b63b4(void);
void func_020b6514(s32 value); void Unk02e000_Unk_02e0cc(void);
void Unk05b82c_Unk_05b82c(s32 value); void Unk065e88_Unk_065e88(void);
void func_02065498(void); void func_020ca5a4(s32 value);
void *func_0205ba98(u32 a, u32 b, const void *name, u32 line);
void func_020e7658(void *object, u32 mode);
void Unk0a23f4_Unk_0a23f4(s32 value); void func_020a594c(void);
void func_020485c4(void *request);
extern const u8 data_02143338[];
extern const u8 data_02143354[];
extern const u8 data_02143378[];
extern const u8 data_02143394[];
extern const u8 data_021433b0[];
extern const u8 data_021433d0[];
extern const u8 data_021433f4[];
extern const u8 data_02143410[];
extern const u8 data_0214342c[];

/* Encode the observed type-1 entry identifier with a 16-bit slot number. */
static inline u32 BattleInitId(u16 id)
{
    return ((u32)id & 0xffff) | 0x10000;
}

/* Initialize allocated work from a borrowed request and output; original accesses
 * establish the layout and call ordering, but not a gameplay-specific name. */
void func_0204870c(BattleInitRequest *request, BattleInitOutput *output)
{
    BattleInitWork *work;
    int i;
    func_020580ec(0);
    if (Unk044904_Get_data_0215ee98()) return;
    work = func_020611dc(func_02049044, func_0204915c, 0, func_02048ef0, 0x7a40, 0, 0, 0);
    data_0215eea0 = (BattleGlobal *)work;
    if (!work) return;
    func_02008848(work, 0, 0x7a40);
    Unk0e8228_Call_02008848();
    Unk044904_Unk_044e90(work);
    func_02008848(work->records, 0, 0x48);
    for (i = 0; i < 6; i++) work->records[i][0] = 0;
    func_02008848(output, 0, 0x44);
    output->flags.b0 = 1;
    output->flags.b1 = 1;
    work->flags.b0 = request->flags.b0;
    work->flags.b1 = request->flags.b1;
    work->flags.b2 = request->flags.b2;
    work->flags.b3 = request->flags.b3;
    work->flags.b4 = request->flags.b4;
    work->flags.b5 = request->flags.b5;
    work->flags.b6 = request->flags.b6;
    work->flags.b7 = request->flags.b7;
    work->flags.b8 = request->flags.b8;
    work->flags.b9 = request->flags.b9;
    work->flags.b11 = request->flags.b10;
    work->flags.b12 = request->flags.b11;
    work->flags.b10 = request->flags.b12;
    work->flags.b13 = request->flags.b13;
    work->flags.b17 = request->flags.b14;
    work->flags.b18 = request->flags.b15;
    work->flags.b19 = request->flags.b16;
    work->value_04c = request->value_028;
    work->output = output;
    work->value_038 = 0;
    work->flags.b16 = 1;
    work->value_05c = 0;
    work->value_03e = request->value;
    work->flags.b20 = 0;
    work->value_044 = request->value_02c;
    work->value_048 = request->value_030;
    Unk0a0ce4_Unk_0a0d30(2);
    func_0209d084(work);
    Unk0946e0_ResetRect();
    work->value_7870 = Unk0946e0_Unk_0946e0();
    Unk0939f0_Set_data_02175d8c(work->value_7870);
    Unk044394_Unk_044428(1);
    Unk044394_Unk_044428(3);
    Unk044394_Unk_044428(2);
    Unk044394_Unk_044428(10);
    Unk044394_Unk_044428(11);
    Unk044394_Unk_044428(14);
    Unk044394_Unk_044428(7);
    work->resources[0] = func_02051610(data_02143338);
    func_02048ff4(work);
    work->resources[1] = func_02051610(data_02143354);
    work->resources[3] = func_02051610(data_02143378);
    work->resources[2] = func_02051610(data_02143394);
    work->resources[4] = func_02051610(data_021433b0);
    ((void **)Unk044904_Unk_045048())[20] = work->resources[4];
    work->resources[5] = func_02051610(data_021433d0);
    ((void **)Unk044904_Unk_045048())[21] = work->resources[5];
    work->resources[6] = func_02051610(data_021433f4);
    work->resources[7] = func_02051610(data_02143410);
    if (func_02015118(request->text_03c))
        func_020f7f68(Unk044904_Unk_045080(), request->text_03c);
    else Unk0f7eb4_Unk_0f8078(Unk044904_Unk_045080());
    work->resources[8] = 0;
    Unk044394_Unk_044428(23);
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i] =
                &((BattleInitWork *)Unk044904_Get_data_0215ee98())->first;
        else if (i < 4) {
            int slot = Unk02e000_GetWorkArea()[0x353 + i];
            if (slot >= 0)
                ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i] =
                &((BattleInitWork *)Unk044904_Get_data_0215ee98())->entries[slot];
        } else
            ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i] =
                &((BattleInitWork *)Unk044904_Get_data_0215ee98())->extra_entries[i - 4];
    }
    if (((BattleInitWork *)Unk044904_Get_data_0215ee98())->flags.b10) {
        for (int i = 0; i < 4; i++) {
            ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i] = 0;
            if (i < 4 && request->entries[i]) {
                BattleInitEntry *entry = &((BattleInitWork *)Unk044904_Get_data_0215ee98())->entries[i];
                ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i] = entry;
                entry->id = BattleInitId((u16)(i + 100));
                Unk1218d0_Unk_122590(request->entries[i], entry);
            }
        }
    } else {
        s8 *area;
        func_02121d2c();
        area = Unk02e000_GetWorkArea();
        for (int i = 0; i < 12; i++) if (area[0x348+i] >= 0) func_02122074(area[0x348+i]);
        for (int i = 0; i < 3; i++) {
            if (area[0x354+i] >= 0)
                ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i+1] =
                    &((BattleInitWork *)Unk044904_Get_data_0215ee98())->entries[area[0x354+i]];
            else ((BattleInitWork *)Unk044904_Get_data_0215ee98())->slots[i+1] = 0;
        }
    }
    for (i = 0; i < 6; i++) if (request->ids[i]) Unk1218d0_Unk_122544((u16)request->ids[i], -1);
    Unk044394_Unk_044534(23);
    func_020a587c(work, work->context);
    func_02048264((u32)work, func_02015118(request->text_034) ? request->text_034 : 0);
    Unk0b28e4_Unk_0b62e8();
    func_020b63b4();
    if (((BattleInitWork *)Unk044904_Get_data_0215ee98())->flags.b10) func_020b6514(1);
    else func_020b6514(0);
    Unk02e000_Unk_02e0cc();
    Unk05b82c_Unk_05b82c(215);
    Unk05b82c_Unk_05b82c(216);
    Unk05b82c_Unk_05b82c(191);
    Unk05b82c_Unk_05b82c(219);
    Unk05b82c_Unk_05b82c(220);
    Unk05b82c_Unk_05b82c(221);
    Unk065e88_Unk_065e88();
    func_02065498();
    func_020ca5a4(0);
    func_020ca5a4(1);
    func_020e7658(func_0205ba98(0x1e000, 0x800, data_0214342c, 0x225), request->mode);
    Unk0a23f4_Unk_0a23f4(work->flags.b10 ? 3 : 1);
    BattleTask_Unk_04822c();
    func_020a594c();
    func_020485c4(0);
    func_02048520(data_0215eea0);
}
