/* Argument-forwarding helpers for the 0x020f51dc translation unit. */
#include "types.h"

/* Borrowed record from GetArr58; only fields used by this TU are exposed. */
typedef struct Unk0f51dcRecord {
    u8 pad_0000[0x22];
    u8 unk_0022;
    u8 pad_0023;
    u32 kind : 5;
    u32 unk_0024_5 : 7;
    u32 variant : 5;
    u32 unk_0024_17 : 15;
} Unk0f51dcRecord;

void func_020572d8(void);
void func_02057eb8(s32 value);
void func_02057524(s32 value);
void func_02057ddc(s32 value);
void func_02057e18(s32 value);
void func_020f6250(s32 mode, s32 x, s32 y, s32 value);
void func_020f58bc(s32 a, s32 b, s32 c, s32 d, float e,
                   s32 f, u32 g, u32 h);
Unk0f51dcRecord *Unk0ea208_GetArr58(s32 index);
u32 Unk0f7eb4_Unk_0f7eb4(u32 value);
u32 Unk0ea208_GetField0(void);
void func_0205de40(s32 mode, u32 handle, u32 id, s32 x, s32 y,
                   float scaleX, float scaleY, s32 value, float alpha, s32 order);
extern const u32 data_0213c954[];

/* Calls the two reset helpers in order, passing the all-bits-set sentinel. */
void Unk0f51dc_Unk_0f623c(void)
{
    func_02057eb8(-1);
    func_020572d8();
}

/* Forwards the caller's coordinates with fixed selector 6 and value 17. */
void Unk0f51dc_Unk_0f5738(s32 x, s32 y)
{
    func_020f6250(6, x, y, 17);
}

/* Forwards five arguments with the fixed trailing tuple (0, 8, 0). */
void Unk0f51dc_Unk_0f57d4(s32 a, s32 b, s32 c, s32 d, float e)
{
    func_020f58bc(a, b, c, d, e, 0, 8, 0);
}

/* Forwards coordinates with selector 10 and value 17. */
void Unk0f51dc_Unk_0f5dfc(s32 x, s32 y)
{
    func_020f6250(10, x, y, 17);
}

/* Forwards coordinates with selector and value both set to 17. */
void Unk0f51dc_Unk_0f5ab4(s32 x, s32 y)
{
    func_020f6250(17, x, y, 17);
}

/* Applies the observed setup sequence (31, -1, 4); helper semantics are unknown. */
void Unk0f51dc_Unk_0f621c(void)
{
    func_02057e18(31);
    func_02057ddc(-1);
    func_02057524(4);
}

/* The first argument indexes GetArr58. Forwards kind (or the converted variant
 * for kind 8) and byte +0x22; missing records produce no call. */
void func_020f5754(s32 a, s32 b, s32 c, s32 d, float e)
{
    Unk0f51dcRecord *record = Unk0ea208_GetArr58(a);
    if (record == 0) return;
    {
        u32 value = record->kind;
        if (value == 8) value = Unk0f7eb4_Unk_0f7eb4(record->variant);
        func_020f58bc(a, b, c, d, e, 0, value, record->unk_0022);
    }
}

/* Submits a table-selected entry when alpha and the shared handle are nonzero.
 * The caller supplies a valid table index; index 2 uses 0.84 alpha when flag is zero. */
void func_020f5ad4(s32 x, s32 y, s32 index, float alpha, s32 flag)
{
    u32 handle;
    const u32 *entries;
    if (alpha == 0.0f) return;
    handle = Unk0ea208_GetField0();
    if (handle == 0) return;
    entries = data_0213c954;
    if (flag == 0 && index == 2) alpha = 0.84f;
    func_0205de40(2, handle, entries[index], x, y,
                   1.0f, 1.0f, 0, alpha, 16);
}

extern const u32 data_0213c948[];
s32 func_02044ec4(s32 index);
s32 func_0204a244(s32 index);
s32 func_0204a67c(s32 index, s32 field);
void func_020f5ec4(s32 x, s32 y, s32 a, s32 b, s32 c, s32 flag,
                   s32 value, s32 extra);

/* Submits the indexed entry; selector 2 with flag zero scales alpha by 0.84.
 * Evidence: table data_0213c948 and the original floating multiply. */
void func_020f5800(s32 x, s32 y, s32 index, float alpha, s32 flag)
{
    u32 handle;
    if (alpha == 0.0f) return;
    handle = Unk0ea208_GetField0();
    if (handle == 0) return;
    if (index == 2 && flag == 0) {
        if (alpha == 1.0f) alpha = 0.84f;
        else alpha *= 0.84f;
    }
    func_0205de40(2, handle, data_0213c948[index], x, y,
                   1.0f, 1.0f, 0, alpha, 16);
}

/* Reads fields 12 through 15 of the resolved record and forwards them with
 * the supplied coordinates; field 15 is normalized to a boolean. */
void func_020f5e18(s32 index, s32 x, s32 y, s32 extra)
{
    s32 record, value, a, b, c, flag;
    if (Unk0ea208_GetField0() == 0) return;
    record = func_02044ec4(index);
    value = func_0204a244(record);
    a = func_0204a67c(record, 12);
    b = func_0204a67c(record, 13);
    c = func_0204a67c(record, 14);
    flag = func_0204a67c(record, 15) != 0;
    func_020f5ec4(x, y, a, b, c, flag, value, extra);
}

/* Submits entries 12 and 13 using integer ratios of the supplied maximum.
 * Evidence: the original divides by maximum before converting to float;
 * maximum must be nonzero. */
void func_020f5d0c(s32 x, s32 y, s32 a, s32 b, s32 maximum)
{
    u32 handle = Unk0ea208_GetField0();
    float scale;
    s32 position;
    if (handle == 0) return;
    func_0205de40(2, handle, 12, x, y, 1.0f, 1.0f, 0, 1.0f, 16);
    scale = (float)((b * 100) / maximum) / 100.0f;
    position = (a * 86) / maximum;
    position -= ((maximum - b) * 43) / maximum;
    func_0205de40(2, handle, 13, x, position, 1.0f, scale, 0, 1.0f, 18);
}

/* Borrowed Arr40 prefix; offsets follow LDRH +0x20 and LDRB +0x2c. */
typedef struct Unk0f51dcArr40 {
    u8 pad_0000[0x20];
    u16 unk_0020;
    u8 pad_0022[10];
    u8 unk_002c;
} Unk0f51dcArr40;
Unk0f51dcArr40 *Unk0ea208_GetArr40(s32 index);
const void *Unk0ea208_GetArr24(s32 index);
s32 func_0209993c(u32 value);
u32 Unk0ca69c_Unk_0ca69c(u32 value);
u32 Unk0c855c_Unk_0ca690(u32 value);
void func_020a9fd8(s32 mode, s32 x, s32 y, s32 a, s32 b, s32 order,
                   const void *data, ...);
void func_02058e9c(s32 mode, u32 id, s32 x, s32 y, float scale, s32 a, s32 order);
void func_02060b60(s32 mode, const void *data, s32 x, s32 y, s32 a, s32 order);
void func_02057df8(void);
extern const u8 data_02150e30[];
extern const u8 data_02150e2c[];

/* Submits Arr40 fields +0x20 and +0x2c with the indexed Arr24 data.
 * Alpha zero and absent resources return without submission. */
void func_020f5b68(s32 index, s32 x, s32 y, s32 mode, float alpha)
{
    u32 handle;
    Unk0f51dcArr40 *record;
    if (alpha == 0.0f) return;
    handle = Unk0ea208_GetField0();
    if (handle == 0) return;
    record = Unk0ea208_GetArr40(index);
    if (record == 0) return;
    func_0205de40(2, handle, 11, x, y, 1.0f, 1.0f, 0, alpha, 18);
    if (alpha == 1.0f) func_02057e18(31);
    else func_02057e18((u8)(((s32)(u32)(100.0f * alpha) * 31) / 100));
    func_020a9fd8(2, x + 104, y + 5, 2, 10, 19, data_02150e30,
                   func_0209993c(record->unk_0020));
    func_02058e9c(2, Unk0ca69c_Unk_0ca69c(record->unk_002c), x + 1, y + 1,
                   1.0f, 0, 19);
    if (mode == 2) func_02057ddc(0x5a5a5a00);
    func_02060b60(1, Unk0ea208_GetArr24(index), x + 20, y + 1, 0, 18);
    if (mode == 2) func_02057df8();
}

/* Submits entries 18 and 19/20, a converted icon, and the indexed Arr24 data.
 * Evidence: the flag selects entry 19 versus 20; alpha controls a 0..31 value. */
void func_020f58bc(s32 index, s32 x, s32 y, s32 mode, float alpha,
                   s32 flag, u32 icon, u32 value)
{
    u32 handle;
    if (alpha == 0.0f) return;
    handle = Unk0ea208_GetField0();
    if (handle == 0) return;
    func_0205de40(2, handle, 18, x, y, 1.0f, 1.0f, 0, alpha, 18);
    if (flag != 0)
        func_0205de40(2, handle, 19, x, y, 1.0f, 1.0f, 0, alpha, 19);
    else
        func_0205de40(2, handle, 20, x, y, 1.0f, 1.0f, 0, alpha, 19);
    func_02058e9c(2, Unk0c855c_Unk_0ca690(icon), x + 1, y + 1, 1.0f, 0, 19);
    if (alpha == 1.0f) func_02057e18(31);
    else func_02057e18((u8)(((s32)(u32)(100.0f * alpha) * 31) / 100));
    func_020a9fd8(2, x + 112, y + 5, 2, 10, 19, data_02150e2c, value);
    if (mode == 2) func_02057ddc(0x5a5a5a00);
    func_02060b60(1, Unk0ea208_GetArr24(index), x + 16, y + 1, 0, 19);
    if (mode == 2) func_02057df8();
}

/* Builds three submissions; modes 2..4 derive width and positions from percent.
 * Evidence: constants 120, 125, 136, divisor 100 and scale divisor 66. */
void func_020f51dc(s32 x, s32 y, s32 mode, s32 percent)
{
    u32 handle;
    float scale;
    s32 middle, end;
    if (mode == 0) return;
    handle = Unk0ea208_GetField0();
    if (handle == 0) return;
    Unk0f51dc_Unk_0f621c();
    middle = x;
    end = x;
    scale = 1.0f;
    switch (mode) {
    case 2: {
        s32 width = (percent * 120) / 100;
        x = 0; middle = x; end = x;
        scale = (float)(width + 66) / 66.0f;
        middle += width / 2;
        end += width;
        end -= 1;
        break;
    }
    case 3: {
        s32 width = (percent * 125) / 100;
        x = 0; middle = x; end = x;
        scale = (float)(width + 66) / 66.0f;
        middle += width / 2;
        end += width;
        end -= 1;
        break;
    }
    case 4: {
        s32 width = (percent * 136) / 100;
        x = 0; middle = x; end = x;
        scale = (float)(width + 66) / 66.0f;
        middle += width / 2;
        end += width;
        end -= 8;
        break;
    }
    }
    func_0205de40(2, handle, 0, end, y, 1.0f, 1.0f, 0, 1.0f, 16);
    func_0205de40(2, handle, 1, middle, y, scale, 1.0f, 0, 1.0f, 16);
    func_0205de40(2, handle, 2, x, y, 1.0f, 1.0f, 0, 1.0f, 18);
    Unk0f51dc_Unk_0f623c();
}

const void *Unk0ea208_GetArr10(s32 index);
extern const u32 data_0213c93c[];

/* Selects an Arr10 entry by group and selector, then submits a table entry.
 * Evidence: group 0 accepts selectors 0..2; group 1 remaps selectors 0..7.
 * The table index must be valid for data_0213c93c. */
void func_020f53d0(s32 group, s32 selector, s32 x, s32 y, s32 index, s32 flag)
{
    u32 handle = Unk0ea208_GetField0();
    float alpha;
    if (handle == 0) return;
    func_02057e18(31);
    alpha = 1.0f;
    if (index == 2) {
        func_02057ddc(0x5a5a5a00);
        if (flag == 0) alpha = 0.84f;
    }
    switch (group) {
    case 0:
        switch (selector) {
        case 0:
            func_02060b60(1, Unk0ea208_GetArr10(0), x + 1, y + 1, 0, 18);
            break;
        case 1:
            func_02060b60(1, Unk0ea208_GetArr10(1), x + 1, y + 1, 0, 18);
            break;
        case 2:
            func_02060b60(1, Unk0ea208_GetArr10(2), x + 1, y + 1, 0, 18);
            break;
        }
        func_02057df8();
        func_0205de40(2, handle, data_0213c93c[index], x, y,
                       1.0f, 1.0f, 0, alpha, 16);
        break;
    case 1:
        switch (selector) {
        case 0:
            func_02060b60(1, Unk0ea208_GetArr10(0), x + 1, y + 1, 0, 18);
            break;
        case 3:
            func_02060b60(1, Unk0ea208_GetArr10(1), x + 1, y + 1, 0, 18);
            break;
        case 4:
            func_02060b60(1, Unk0ea208_GetArr10(2), x + 1, y + 1, 0, 18);
            break;
        case 5:
            func_02060b60(1, Unk0ea208_GetArr10(3), x + 1, y + 1, 0, 18);
            break;
        case 7:
            func_02060b60(1, Unk0ea208_GetArr10(4), x + 1, y + 1, 0, 18);
            break;
        case 1:
            func_02060b60(1, Unk0ea208_GetArr10(0), x + 1, y + 1, 0, 18);
            break;
        case 2:
            func_02060b60(1, Unk0ea208_GetArr10(1), x + 1, y + 1, 0, 18);
            break;
        case 6:
            func_02060b60(1, Unk0ea208_GetArr10(2), x + 1, y + 1, 0, 18);
            break;
        }
        func_02057df8();
        func_0205de40(2, handle, data_0213c93c[index], x, y,
                       1.0f, 1.0f, 0, alpha, 16);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

u32 Unk0ea208_GetField4(void);
const void *Unk0ea208_GetField3c(void);
u32 Unk0ddeb0_Unk_0ddfd8(u16 value);
u32 Unk0ca69c_Unk_0ca6a4(u32 value);
void func_0205dee8(s32 mode, u32 handle, u32 id, s32 x, s32 y,
                   float scaleX, float scaleY, s32 value, float alpha, s32 order);
extern const u8 data_0213c960[];
extern const u8 data_02150e38[];
extern const u8 data_02150e3c[];
extern const u8 data_02150e40[];
extern const u8 data_02150e44[];
extern const u8 data_02150e48[];
extern const u8 data_02150e4c[];
extern const u8 data_02150e50[];

/* Submits a fading base entry, then icon and numeric text once percent >=100.
 * Evidence: GetField4 supplies the handle and data_0213c960 selects an overlay.
 * Value must index that byte table; its low halfword is passed to the icon helper. */
void func_020f5ec4(s32 x, s32 y, s32 a, s32 b, s32 c, s32 flag,
                   s32 value, s32 percent)
{
    u32 handle;
    s32 position;
    float alpha;
    if (percent <= 0) return;
    handle = Unk0ea208_GetField4();
    if (handle == 0) return;
    position = x - 20;
    alpha = 1.0f;
    if (percent < 100) alpha = (float)percent / 100.0f;
    func_0205dee8(2, handle, 0, position, y, 1.0f, 1.0f, 0, alpha, 17);
    if (percent < 100) return;
    if (percent == 100) func_02057e18(31);
    else func_02057e18((u8)((percent * 31) / 100));
    func_02058e9c(2, Unk0ca69c_Unk_0ca6a4(Unk0ddeb0_Unk_0ddfd8((u16)value)),
                   position + 1, y + 50, 1.0f, 0, 18);
    if (data_0213c960[value] != 0)
        func_0205de40(2, handle, data_0213c960[value], position, y,
                       1.0f, 1.0f, 0, alpha, 18);
    if (percent == 100) func_02057e18(31);
    else func_02057e18((u8)((percent * 31) / 100));
    func_02060b60(1, Unk0ea208_GetField3c(), position + 2, y + 3, 0, 18);
    if (a == 0)
        func_020a9fd8(1, position + 27, y + 3, 0, 0, 18, data_02150e38);
    else
        func_020a9fd8(1, position + 27, y + 3, 0, 0, 18, data_02150e3c, a);
    if (b == 0)
        func_020a9fd8(1, position + 27, y + 15, 0, 0, 18, data_02150e40);
    else
        func_020a9fd8(1, position + 27, y + 15, 0, 0, 18, data_02150e44, b);
    if (c == 0)
        func_020a9fd8(1, position + 27, y + 27, 0, 0, 18, data_02150e48);
    else
        func_020a9fd8(1, position + 27, y + 27, 0, 0, 18, data_02150e4c, c);
    if (flag != 0)
        func_0205de40(2, handle, 1, position, y, 1.0f, 1.0f, 0, 1.0f, 18);
    else
        func_020a9fd8(1, position + 27, y + 39, 0, 0, 18, data_02150e50);
}
