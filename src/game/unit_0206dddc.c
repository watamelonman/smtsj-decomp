/* Accessors for the table at data_0216bac8; record meanings remain unknown. */
#include "types.h"

/* 24-byte slot; six of them fill the 0x90 bytes copied at record +0x2c (0x0206dee8). */
typedef struct Unk06dddcSlot {
    u32 unk00;
    u32 unk04; /* maximised over all six slots by 0x0206e0dc */
    u8 pad_08[0x10];
} Unk06dddcSlot;

/* 20-byte subentry of the array at record +0x13c (stride from 0x0206dfc8). */
typedef struct Unk06dddcSub {
    u32 unk00; /* index into the record's 552-byte entry array (0x0206e0dc) */
    s16 unk04;
    s16 unk06;
    u8 unk08[12];
} Unk06dddcSub;

/* 552-byte entry of the array at record +0x24 (size from 0x0206de10). */
typedef struct Unk06dddcEntry {
    u8 pad_0000[0xfc];
    u32 unk00fc;
    u8 pad_0100[0x6c];
    u32 unk016c;
    u8 pad_0170[0xb4];
    u32 unk0224; /* 0..3, selects unk00fc or unk016c in 0x0206e0dc */
} Unk06dddcEntry;

/* 328-byte record; 64 of them (0x5200 bytes cleared by 0x0206df10). */
typedef struct Unk06dddcRecord {
    u8 unk000[0x20]; /* bytes from +1 are compared by 0x0206e06c */
    s32 unk020; /* entry count, at most 16 (0x0206de10) */
    Unk06dddcEntry *unk024;
    s32 unk028; /* subentry count, at most 64 (0x0206de7c) */
    Unk06dddcSlot unk02c[6];
    u8 pad_00bc[0x80];
    Unk06dddcSub *unk13c;
    u8 pad_0140[8];
} Unk06dddcRecord;

/* The ROM addresses some record fields through their own symbols
 * (data_0216bae8 = +0x20, baec = +0x24, baf0 = +0x28, bc04 = +0x13c), so those
 * stay separate byte arrays indexed with the 328-byte record stride. */
extern s32 data_0216bac4[];
extern Unk06dddcRecord data_0216bac8[64];
extern u8 data_0216bae8[];
extern u8 data_0216baec[];
extern u8 data_0216baf0[];
extern u8 data_0216bc04[];

void func_020086a0(u32 value, void *dst, u32 size);
void func_020086bc(const void *src, void *dst, u32 size);
void *func_02052fe0(u32 size);
void func_02053000(void *p);
int func_020152cc(const void *bytes, int key);
u32 func_020943dc(int a, int i);

/* Return record i's entry array, or null when i is past the record count. */
Unk06dddcEntry *Unk06dddc_GetEntryUnk24(int i)
{
    if (data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return *(Unk06dddcEntry **)(data_0216baec + i * 328);
}

/* Copy n (at most 16) 552-byte entries from src into a new allocation owned by
 * record i and store n as its entry count; n <= 0 only stores the count. */
void func_0206de10(int i, const void *src, int n)
{
    u32 size;

    if (n > 16) {
        return;
    }
    if (n > 0) {
        size = n * 552;
        *(void **)(data_0216baec + i * 328) = func_02052fe0(size);
        func_020086bc(src, *(void **)(data_0216baec + i * 328), size);
    }
    *(s32 *)(data_0216bae8 + i * 328) = n;
}

/* Same as func_0206de10 for the 20-byte subentry array (at most 64) of record i. */
void func_0206de7c(int i, const void *src, int n)
{
    u32 size;

    if (n > 64) {
        return;
    }
    if (n > 0) {
        size = n * 20;
        *(void **)(data_0216bc04 + i * 328) = func_02052fe0(size);
        func_020086bc(src, *(void **)(data_0216bc04 + i * 328), size);
    }
    *(s32 *)(data_0216baf0 + i * 328) = n;
}

/* Copy the six 24-byte slots (0x90 bytes) from src into record i. */
void Unk06dddc_Unk_06dee8(int i, const void *src)
{
    func_020086bc(src, data_0216bac8[i].unk02c, sizeof(data_0216bac8[i].unk02c));
}

/* Free every record's two arrays, then clear all 64 records and the count. */
void func_0206df10(void)
{
    int i;

    for (i = 0; i < data_0216bac4[0]; i++) {
        if (data_0216bac8[i].unk13c != 0) {
            func_02053000(data_0216bac8[i].unk13c);
            data_0216bac8[i].unk13c = 0;
            data_0216bac8[i].unk028 = 0;
        }
        if (data_0216bac8[i].unk024 != 0) {
            func_02053000(data_0216bac8[i].unk024);
            data_0216bac8[i].unk024 = 0;
            data_0216bac8[i].unk020 = 0;
        }
    }
    func_020086a0(0, data_0216bac8, sizeof(data_0216bac8));
    data_0216bac4[0] = 0;
}

/* Return the table count word (load at 0x0206dfa0); no ownership transfer. */
u32 Unk06dddc_Get_data_0216bac4(void)
{
  return *data_0216bac4;
}

/* Return a borrowed 328-byte record; the caller supplies a valid index.
 * Evidence: 0x0206e058 adds index * 0x148 to data_0216bac8. */
u8 *Unk06dddc_Unk_06e058(int arg0)
{
  return (u8 *)&data_0216bac8[arg0];
}

/* Read the word at record offset +0x28; valid index required.
 * Evidence: 0x0206dfb0 indexes data_0216baf0 with stride 0x148. */
u32 Unk06dddc_Unk_06dfb0(int arg0)
{
  return *(u32 *)(data_0216baf0 + arg0 * 0x148);
}

/* Read the signed halfword at subrecord offset +4; both indices must be valid.
 * Evidence: 0x0206dfc8 loads the pointer at record +0x13c and uses stride 0x14. */
int Unk06dddc_Unk_06dfc8(int arg0,int arg1)
{
  return (int)*(short *)(arg1 * 0x14 + *(u8 **)(data_0216bc04 + arg0 * 0x148) + 4);
}

/* Read the word at subrecord offset +0; both indices must be valid.
 * Evidence: 0x0206dfec loads the pointer at record +0x13c and uses stride 0x14. */
u32 Unk06dddc_Unk_06dfec(int arg0,int arg1)
{
  return *(u32 *)(*(u8 **)(data_0216bc04 + arg0 * 0x148) + arg1 * 0x14);
}

/* Return the borrowed bytes at subrecord offset +8; both indices must be valid.
 * Evidence: 0x0206e010 loads the pointer at record +0x13c and uses stride 0x14. */
u8 *Unk06dddc_Unk_06e010(int arg0,int arg1)
{
  return arg1 * 0x14 + *(u8 **)(data_0216bc04 + arg0 * 0x148) + 8;
}

/* Read the signed halfword at subrecord offset +6; both indices must be valid.
 * Evidence: 0x0206e034 loads the pointer at record +0x13c and uses stride 0x14. */
int Unk06dddc_Unk_06e034(int arg0,int arg1)
{
  return (int)*(short *)(arg1 * 0x14 + *(u8 **)(data_0216bc04 + arg0 * 0x148) + 6);
}

/* Return the index of the first record whose bytes from +1 make
 * func_020152cc(bytes, k) return 0, or 255 when none does. */
u8 Unk06dddc_Unk_06e06c(int k)
{
    int i;
    for (i = 0; i < data_0216bac4[0]; i++) {
        if (func_020152cc(Unk06dddc_Unk_06e058((u8)i) + 1, k) == 0) {
            return i;
        }
    }
    return 255;
}

/* Return borrowed record bytes starting at +1, preserving the null check.
 * Evidence: 0x0206e0c4 calls the record accessor, then conditionally adds one.
 * The caller supplies a valid record index. */
u8 *Unk06dddc_Unk_06e0c4(u32 a)
{
    u8 *p = Unk06dddc_Unk_06e058(a);
    if (p != 0) {
        return p + 1;
    }
    return 0;
}

/* Return the largest of: the six slot words, base + mul * value for every
 * subentry of record i (value picked from its entry by unk0224), and
 * func_020943dc(0..3, i). Returns 0 when i is past the record count. */
int func_0206e0dc(int i)
{
    Unk06dddcEntry tmp;
    int max;
    Unk06dddcEntry *entries;
    int j;
    int off;
    s16 base;
    s16 mul;
    s16 val;

    if (data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    max = 0;
    entries = Unk06dddc_GetEntryUnk24(i);
    off = i * sizeof(Unk06dddcRecord);
    for (j = 0; j < 6; j++) {
        if ((u32)max < (&data_0216bac8[i])->unk02c[j].unk04) {
            max = (&data_0216bac8[i])->unk02c[j].unk04;
        }
    }
    j = 0;
    if (*(s32 *)(data_0216baf0 + off) > 0) {
        do {
            func_020086bc(&entries[((Unk06dddcRecord *)((u8 *)data_0216bac8 + off))->unk13c[j].unk00], &tmp, sizeof(tmp));
            val = 0;
            base = ((Unk06dddcRecord *)((u8 *)data_0216bac8 + off))->unk13c[j].unk04;
            mul = ((Unk06dddcRecord *)((u8 *)data_0216bac8 + off))->unk13c[j].unk06;
            if (mul < 1) {
                mul = 1;
            }
            switch (tmp.unk0224) {
            case 0:
                val = tmp.unk00fc;
                break;
            case 1:
            case 2:
            case 3:
                val = tmp.unk016c;
                break;
            }
            if (max < base + mul * val) {
                max = base + mul * val;
            }
            j++;
        } while (j < ((Unk06dddcRecord *)((u8 *)data_0216bac8 + off))->unk028);
    }
    if ((u32)max < func_020943dc(0, i)) {
        max = func_020943dc(0, i);
    }
    if ((u32)max < func_020943dc(1, i)) {
        max = func_020943dc(1, i);
    }
    if ((u32)max < func_020943dc(2, i)) {
        max = func_020943dc(2, i);
    }
    if ((u32)max < func_020943dc(3, i)) {
        max = func_020943dc(3, i);
    }
    return max;
}
