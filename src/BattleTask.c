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

/* Configure eligible type-2 slots, propagate bit 9, and order six pointer slots. */
void func_02048520(void)
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

