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

