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
void func_020f58bc(s32 a, s32 b, s32 c, s32 d, s32 e,
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
void Unk0f51dc_Unk_0f57d4(s32 a, s32 b, s32 c, s32 d, s32 e)
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
void func_020f5754(s32 a, s32 b, s32 c, s32 d, s32 e)
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
