#include "types.h"

s32 func_0203ac00(s32 index);
void Unk03aae8_Unk_03acf4(s32 value);
s32 Unk096754_Unk_097110(void);
s32 Unk0979d8_Unk_0981a4(u8 index);
void Unk096754_ClampField1e(s16 value);
void Unk0979d8_Unk_0981bc(u8 index, s16 value);
void Unk0979d8_Unk_097f34(s16 value);
void Unk0979d8_ClampAllField20(s16 value);
s32 func_0209993c(s32 value);
s32 Unk03cc58_Unk_03cd50(s32 entry, s32 amount, s32 mode);

/* Selector 0 reads the singleton; selectors 1..3 read indexed entries.
 * Evidence: the two getter calls and byte-sized selector adjustment below. */
s32 Unk03cc58_Unk_03cc58(void)
{
    s32 k = func_0203ac00(0);
    s32 r = 0;
    if (k == 0) {
        r = Unk096754_Unk_097110();
    } else if (k >= 1 && k <= 3) {
        r = Unk0979d8_Unk_0981a4((u8)(k - 1));
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

/* Dispatches a signed 16-bit value by selector; the original jump table
 * assigns selectors 1..3 to individual entries and 4..5 to aggregate calls. */
s32 func_0203ccac(void)
{
    s32 selector = func_0203ac00(0);
    s32 value = func_0203ac00(1);
    switch (selector) {
    case 0: Unk096754_ClampField1e((s16)value); break;
    case 1:
    case 2:
    case 3: Unk0979d8_Unk_0981bc((u8)(selector - 1), (s16)value); break;
    case 4: Unk0979d8_Unk_097f34((s16)value); break;
    case 5: Unk0979d8_ClampAllField20((s16)value); break;
    }
    return 1;
}

/* Forwards argument 0 through 0209993c into the result setter (BL chain). */
s32 Unk03cc58_Unk_03cd34(void)
{
    Unk03aae8_Unk_03acf4(func_0209993c(func_0203ac00(0)));
    return 1;
}

/* Script context from Unk03aae8_Unk_03ad14; only the +0xe8 subobject is used. */
typedef struct Unk03cc58Sub {
    u8 pad_00[0x18];
    s32 unk_18;                 /* 0x18: set to 5 after a positive change */
} Unk03cc58Sub;
typedef struct Unk03cc58Context {
    u8 pad_00[0xe8];
    Unk03cc58Sub *unk_e8;
} Unk03cc58Context;
s32 func_02095818(void);
void func_02065c10(void);
void func_02065aa4(s32 entry, s32 amount);
void func_020659a4(s32 entry, s32 amount);
void func_02099a28(s32 entry, s32 amount);
Unk03cc58Context *Unk03aae8_Unk_03ad14(void);
/* Keeps the value-then-subobject operand order of the original store. */
static inline void Unk03cc58_SetSubState(s32 value, Unk03cc58Sub *sub)
{
    sub->unk_18 = value;
}
u8 *Unk02e000_Thunk_0202e788(void);
s32 Unk09974c_GetEntryUnk08(s32 entry);
void func_02099b10(s32 entry, s32 amount);

/* Changes entry `entry` by `amount`. A positive amount goes through
 * func_02065aa4 (mode 0) or func_020659a4, then func_02099a28, sets the
 * context subobject's +0x18 to 5 and returns 3. Otherwise entries of kinds
 * 3..6 are left alone and the rest are reduced through func_02099b10;
 * returns 1. */
s32 Unk03cc58_Unk_03cd50(s32 entry, s32 amount, s32 mode)
{
    if (amount > 0) {
        /* The original calls func_02065c10 separately for result 1 and for
         * any other result (two calls in the ROM). */
        switch (func_02095818()) {
        case 1:
            func_02065c10();
            break;
        default:
            func_02065c10();
            break;
        }
        if (mode == 0) {
            func_02065aa4(entry, amount);
        } else {
            func_020659a4(entry, amount);
        }
        func_02099a28(entry, amount);
        Unk03cc58_SetSubState(5, Unk03aae8_Unk_03ad14()->unk_e8);
        return 3;
    }
    Unk02e000_Thunk_0202e788();
    switch (Unk09974c_GetEntryUnk08(entry)) {
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    }
    func_02099b10(entry, -amount);
    return 1;
}

/* Forwards two script arguments to the shared helper with mode 0. */
s32 Unk03cc58_Unk_03ce10(void)
{
    s32 entry = func_0203ac00(0);
    s32 amount = func_0203ac00(1);
    return Unk03cc58_Unk_03cd50(entry, amount, 0);
}

/* Forwards two script arguments to the shared helper with mode 1. */
s32 Unk03cc58_Unk_03ce3c(void)
{
    s32 entry = func_0203ac00(0);
    s32 amount = func_0203ac00(1);
    return Unk03cc58_Unk_03cd50(entry, amount, 1);
}
