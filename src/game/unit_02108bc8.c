#include "types.h"

/* Only fields accessed here are described; gaps retain their original byte sizes. */
typedef struct Unk108bc8Record {
    u8 pad_00[11];
    u8 flags_0b;
    u8 pad_0c[19];
    u8 flags_1f;
    u8 pad_20[4];
} Unk108bc8Record;

typedef struct Unk108bc8Work {
    u16 head;
    u8 unk_02;
    u8 pad_03[0x4c - 3];
    u8 unk_4c[18];
    u8 unk_5e[18];
    u8 pad_70[0x348 - 0x70];
    u32 unk_348;
    u8 pad_34c[0x38a - 0x34c];
    u8 unk_38a[30];
    u8 unk_3a8[0xcfc - 0x3a8];
    u8 unk_cfc[0x16fc - 0xcfc];
    Unk108bc8Record records[491];
    u8 pad_5c08[0x5e12 - 0x5c08];
    u8 unk_5e12[64];
    u8 unk_5e52[0x5fc4 - 0x5e52];
    u32 unk_5fc4;
    u8 unk_5fc8[1];
} Unk108bc8Work;

extern Unk108bc8Work *data_02176e34;
void *func_02052fe0(u32 size);
void func_02053000(void *allocation);
u32 Unk0a163c_Unk_0a1814(u32 value);
u32 func_02063a30(u32 value);
void func_02061f10(u32 value, s32 index, u32 a, u32 b, u32 resource);
void Unk118b04_Unk_119434(void *dst, const void *src);
void func_02008904(const void *src, void *dst, u32 size);
void func_02095468(void *dst, const void *src);
void Unk0f3db4_Unk_0f4674(void *dst, const void *src);
void func_0209a268(void *dst, const void *src);
/* The original forwards the converted second argument as the fifth call argument. */
void Unk108bc8_Unk_108bc8(u32 a, u32 b)
{
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk0a163c_Unk_0a1814(b)));
}

/* Returns the fixed byte count observed at 02108c00. */
u32 Unk108bc8_GetSize(void)
{
    return 0x5bfc;
}

/* Allocation call and singleton null guard at 02108c0c establish ownership. */
void Unk108bc8_Alloc(void)
{
    if (data_02176e34 != 0) return;
    data_02176e34 = func_02052fe0(0x5ffc);
}

/* Releases the singleton allocation, then clears the owning pointer. */
void Unk108bc8_Unk_108c3c(void)
{
    func_02053000(data_02176e34);
    data_02176e34 = 0;
}

/* Returns borrowed singleton storage, allocating it on first access. */
Unk108bc8Work *Unk108bc8_Unk_108c60(void)
{
    if (data_02176e34 == 0) Unk108bc8_Alloc();
    return data_02176e34;
}

/* The original halfword load at offset zero supports the existing GetHead name. */
u32 Unk108bc8_GetHead(void)
{
    if (data_02176e34 != 0) return data_02176e34->head;
    return 0;
}

/* Growth block is returned by value; HP/MP formula evidence also appears in CampStatus. */
typedef struct Unk108bc8Base {
    u8 hpRate, mpRate;
    u16 unk_02, unk_04, unk_06, hpBase, mpBase;
} Unk108bc8Base;

/* Borrowed 36-byte saved record; flag bit one retains existing resource fields. */
typedef struct Unk108bc8Saved {
    u8 level, stats[5], current[5];
    u8 flag0:1, flag1:1, otherFlags:6;
    u16 hp, mp, ids[6];
    u8 tail[8];
} Unk108bc8Saved;

/* Borrowed 40-byte slot: id selects growth data and HP/MP occupy +16/+18. */
typedef struct Unk108bc8Slot {
    u16 id;
    u8 pad_02[2];
    u8 level, stats[5];
    u8 pad_0a[6];
    u16 hp, mp;
    u8 pad_14[20];
} Unk108bc8Slot;

/* Twelve signed indices at +0x348; negative entries do not name an area. */
typedef struct Unk108bc8AreaWork {
    u8 pad[0x348];
    s8 indices[12];
} Unk108bc8AreaWork;

void func_02096c8c(void);
u8 *Unk02e000_GetWorkArea(void);
u8 *Unk02e000_GetAreaRecord(int index);
void func_0209786c(void *area);
u8 *Unk02e000_Thunk_0202e788(void);
void Unk02ee5c_Unk_02efa4(void);
u8 *Unk02e000_Unk_02e774(void);
u8 *func_020a1428(u16 id);
Unk108bc8Base func_020b8804(u16 id);

/* Caps the level and vitality growth formula at the original 999 HP limit. */
static inline u16 Unk108bc8_CalcHp(u8 level, u8 vi, Unk108bc8Base base)
{
    u16 result;
    s32 value = base.hpBase + (level * 6 + base.hpRate * (vi * 3) / 100);
    if (value > 999) result = 999;
    else result = value;
    return result;
}

/* Caps the level and magic growth formula at the original 999 MP limit. */
static inline u16 Unk108bc8_CalcMp(u8 level, u8 ma, Unk108bc8Base base)
{
    u16 result;
    s32 value = base.mpBase + (level * 3 + base.mpRate * (ma * 2) / 100);
    if (value > 999) result = 999;
    else result = value;
    return result;
}

/* Refreshes area and saved-record derived values. Offsets, loop bounds and flag
 * bit one are evidenced by ARM loads at 02108cbc, 02108d38 and 02108f1c. */
void func_02108ca4(void)
{
    u8 *work;
    int i, j;
    u8 index;
    Unk108bc8Saved *record;
    Unk108bc8Slot *slot;
    Unk108bc8Base base, slotBase;
    func_02096c8c();
    work = Unk02e000_GetWorkArea();
    for (i = 0; i < 12; i++) {
        if (((Unk108bc8AreaWork *)(work + i))->indices[0] >= 0)
            func_0209786c(Unk02e000_GetAreaRecord(((Unk108bc8AreaWork *)(work + i))->indices[0]));
    }
    if (work[0x357] < 8) work[0x357] = 8;
    for (index = 0; index < 12; index++)
        Unk02e000_GetAreaRecord(index)[0x3a] = index;
    work = Unk02e000_Thunk_0202e788();
    *(u16 *)(work + 0x58) = 0;
    *(u16 *)(work + 0x6a) = 0;
    Unk02ee5c_Unk_02efa4();
    record = (Unk108bc8Saved *)(Unk02e000_Unk_02e774() + 0x16fc);
    for (i = 0; i < 491; i++, record++) {
        u8 *resource = func_020a1428((u16)(i + 1));
        if (resource) {
            if (!record->flag1) {
                record->level = resource[3];
                record->stats[0] = resource[26];
                record->stats[1] = resource[30];
                record->stats[2] = resource[27];
                record->stats[3] = resource[28];
                record->stats[4] = resource[29];
                record->current[0] = resource[26];
                record->current[1] = resource[30];
                record->current[2] = resource[27];
                record->current[3] = resource[28];
                record->current[4] = resource[29];
                for (j = 0; j < 6; j++) record->ids[j] = ((u16 *)(resource + 46))[j];
            }
            { Unk108bc8Base *p = &base; *p = func_020b8804((u16)(i + 1)); }
            record->hp = Unk108bc8_CalcHp(record->level, record->stats[2], base);
            record->mp = Unk108bc8_CalcMp(record->level, record->stats[1], base);
        }
    }
    slot = (Unk108bc8Slot *)(Unk02e000_Unk_02e774() + 0x5c08);
    for (i = 0; i < 3; i++, slot++) {
        if (func_020a1428(slot->id)) {
            { Unk108bc8Base *p = &slotBase; *p = func_020b8804(slot->id); }
            slot->hp = Unk108bc8_CalcHp(slot->level, slot->stats[2], slotBase);
            slot->mp = Unk108bc8_CalcMp(slot->level, slot->stats[1], slotBase);
        }
    }
}

/* Copies selected record regions; 02109050 clears bit zero in both flag bytes. */
void func_02109050(Unk108bc8Work *dst, const Unk108bc8Work *src)
{
    int i;
    u8 *flags0;
    u8 *flags1;
    dst->unk_02 = src->unk_02;
    Unk118b04_Unk_119434(dst->unk_5fc8, src->unk_5fc8);
    dst->unk_5fc4 = src->unk_5fc4;
    dst->unk_348 = src->unk_348;
    func_02008904(src->unk_4c, dst->unk_4c, 18);
    func_02008904(src->unk_5e, dst->unk_5e, 18);
    func_02008904(src->unk_38a, dst->unk_38a, 30);
    func_02008904(src->records, dst->records, 0x450c);
    flags0 = &dst->records[0].flags_0b;
    flags1 = &dst->records[0].flags_1f;
    for (i = 0; i < 491; i++) {
        *flags0 &= ~1;
        flags0 += sizeof(Unk108bc8Record);
        *flags1 &= ~1;
        flags1 += sizeof(Unk108bc8Record);
    }
    func_02008904(src->unk_5e12, dst->unk_5e12, 64);
    func_02095468(dst->unk_cfc, src->unk_cfc);
    Unk0f3db4_Unk_0f4674(dst->unk_5e52, src->unk_5e52);
    func_0209a268(dst->unk_3a8, src->unk_3a8);
}

