#ifndef GAME_UNIT_0211D520_H
#define GAME_UNIT_0211D520_H

#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11d520Work {
    s32 state;
    s32 group;
    s32 list_count;
    s32 list_000c;
    s32 first;
    s32 list_0014;
    s32 unk_0018;
    s32 list_001c[2];
    s32 cursor[29];
    u8 pad_0098[0x10];
    u32 *unk_00a8;
    s32 count;
    s32 *flags;
    u8 pad_00b4[0x1b8];
    u32 unk_026c;
    u32 unk_0270;
    u32 unk_0274;
    u32 unk_0278[2];
    u32 unk_0280[2];
    u32 unk_0288;
    u32 unk_028c[18];
    u32 unk_02d4;
    u32 unk_02d8;
    u32 unk_02dc;
    u32 unk_02e0;
    s32 direction;
    s32 widths[11];
    s32 title_width;
    s32 delay;
} Unk11d520Work;

/* Alternate work-area view: 218 halfword IDs, count at 0x268, handles at 0x28c. */
typedef struct Unk11d520Ids {
    u8 pad[180];
    u16 ids[218];
    u32 n;
    u8 pad2[32];
    u32 h[18];
} Unk11d520Ids;

/* Slot requests contain two presence bytes and sixteen words; padding is untouched. */
typedef struct Unk11d520Request { u8 flags[2]; u32 words[16]; } Unk11d520Request;

/* Text-provider output uses four words; only the last pair is adjusted here. */
typedef struct Unk11d520Rect { s32 a, b, c, d; } Unk11d520Rect;

u32 func_0204fe68(u32 resource, u32 group);

u32 func_0204fed8(u32 group, u32 entry);

void func_0205c408(u32 handle, u32 value);

void func_0205c6e0(u32 handle);

extern u8 data_02151d18[];

void func_0205ddb4(u32 handle);

void func_0205bb68(void);

void func_020629c4(u32 handle);

void func_0205c3dc(u32 handle);

void func_0205c368(u32 handle);

s32 Unk118b04_GetEntryKey(s32 id);

u32 Unk02f2a8_GetRes36Unk19(s32 key);

void func_0204fcb0(s32 slot, u32 entry);

s32 Unk118b04_Unk_118b78(s32 id);

void func_02061f10(u32 handle, s32 index, s32 x, s32 y, u32 entry);

void func_0211d884(Unk11d520Work *p);

void func_0211db58(Unk11d520Work *p);

s32 func_02061a04(s32 font, u32 text, s32 mode);

void func_02053000(void *p);

s32 func_02119460(s32 group);

void func_0211955c(u32 *entries, s32 count, s32 group);

void Unk0bcef4_Unk_0bcef4(s32 *list, s32 visible, s32 count, s32 mode);

void Unk0bcef4_Unk_0bd29c(s32 *cursor, s32 *list);

void func_020bd1a8(s32 *cursor, s32 *list, s32 *flags, s32 mode);

s32 func_020537b8(s32 device, s32 mask);

s32 func_02053800(s32 device, s32 mask);

s32 func_02053824(s32 device, s32 mask);

s32 func_020bce08(s32 *list, s32 mode);

void Unk0a0ce4_Unk_0a0da4(s32 sound);

void Unk0bc1a8_SetFlag4Inv(Unk11d520Work *p, s32 enabled);

void func_0205257c(s32 mode);

void func_02063920(void);

u32 func_02063a44(u32 text, s32 slot);

u32 func_02063a30(u32 text);

s32 func_020619b8(s32 font, s32 value);

extern u32 data_02151d14[];

extern u8 data_02151dd8[], data_02151f58[], data_02151f64[];

extern u8 data_02151f70[], data_02151f7c[], data_02151f88[];

void func_0205ad2c(u32 value);

void Unk05b82c_CreateEntry(void *entry);

u32 func_0205dcd4(void *entry, s32 mode);

u32 func_0205c2c4(void *entry);

u32 func_020629ac(s32 a, s32 b, s32 c, s32 d);

void func_02061e98(u32 handle, s32 a, s32 b);

u32 func_0205c3c0(void);

void func_0205c3fc(u32 handle, u32 a, u32 b);

void Unk02e000_Unk_02e0cc(void);

void Unk05b82c_Unk_05b82c(s32 value);

s32 Unk0bc1a8_IsSlotEmpty(s32 slot);

u32 Unk0bc1a8_GetHeaderWord(Unk11d520Work *p);

void Unk0bc1a8_Unk_0bc928(s32 slot, u32 header, Unk11d520Request *r);

void func_020e7f44(s32 a, s32 b, s32 c, s32 d);

void Unk0e7ac4_Unk_0e8000(s32 value);

void func_020bcbc4(s32 slot, Unk11d520Request *r);

void func_020525cc(s32 mode);

void Unk0bc1a8_Unk_0bc514(Unk11d520Work *p, s32 value, Unk11d520Request *r);

void Unk0bcef4_Unk_0bd388(s32 *cursor, s32 *list);

s32 func_02052728(void);

extern const s16 data_0213cd1c[];

s32 func_0205c704(u32 handle);

s32 func_0205b36c(u32 handle);

void Unk0bc1a8_Unk_0bc9b4(u32 slot, Unk11d520Request *r);

void Unk118b04_ClearFlag2(u32 id);

void func_020580ec(s32 enabled);

void func_02057524(s32 value);

void Unk_LoadPalette_020de678(u32 palette);

void func_02057534(void);

void func_02057df8(void);

void func_02057e18(s32 value);

void func_02057ddc(u32 value);

void func_02057fd8(void);

void func_0205c748(s32 layer, u32 image, s32 x, s32 y, float sx, float sy,
                   s32 rotation, float alpha, s32 flags);

void func_0205de40(s32 layer, u32 image, s32 index, s32 x, s32 y, float sx,
                   float sy, s32 rotation, float alpha, s32 flags);

void func_0205dee8(s32 layer, u32 image, s32 index, s32 x, s32 y, float sx,
                   float sy, s32 rotation, float alpha, s32 flags);

void func_02060dd4(Unk11d520Rect *rect, u32 text, s32 a, s32 b, s32 c);

void func_02059f70(u32 text, u32 flags, s32 x, s32 y, Unk11d520Rect *rect, s32 a, s32 b);

#endif
