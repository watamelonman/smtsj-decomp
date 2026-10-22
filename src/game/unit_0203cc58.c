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
s32 func_0203cd50(s32 entry, s32 amount, s32 mode);

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

/* Forwards two script arguments to the shared helper with mode 0. */
s32 Unk03cc58_Unk_03ce10(void)
{
    s32 entry = func_0203ac00(0);
    s32 amount = func_0203ac00(1);
    return func_0203cd50(entry, amount, 0);
}

/* Forwards two script arguments to the shared helper with mode 1. */
s32 Unk03cc58_Unk_03ce3c(void)
{
    s32 entry = func_0203ac00(0);
    s32 amount = func_0203ac00(1);
    return func_0203cd50(entry, amount, 1);
}
