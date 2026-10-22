/*
 * src/game/unit_020bbb44.c: script-handler style functions that publish a value to the
 * script VM through Unk03aae8_Unk_03acf4 (the same result channel used by the neighbouring
 * unit_020bb908.c / unit_020bbd6c.c handlers). Every function returns 1 to the caller.
 * Field offsets are taken from the delinked original; their meanings are not yet known.
 */
#include "types.h"

int func_0203ac00();
int Unk03aae8_Unk_03acf4();
u32 Unk0bac80_Unk_0bae08();
u32 Unk0bac80_Unk_0badd0();
int func_0204fde0();
u32 func_0204fe18();
int Unk0e5fb8_Unk_0e61c8();
int Unk0e5fb8_Unk_0e620c();

/* Publishes the u16 at +0xC of record `slot` (stride 10) from the table returned by
 * Unk0bac80_Unk_0bae08; slot 0 is used when the script index is out of range (>= 3) and the
 * value 0 is published when the table pointer is null. */
u32 func_020bbb44(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);

    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 10, 12));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Same as func_020bbb44 but publishes the u16 at +0xE of the selected record. */
u32 func_020bbb8c(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);

    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 10, 14));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Selects table 0 through Unk0bac80_Unk_0badd0, publishes the u16 at script index i of that
 * table (i is clamped to 0 when it is not below the table's element count). */
u32 func_020bbbd4(void)
{
    u32 h = Unk0bac80_Unk_0badd0(0);
    u32 n = func_0204fe18();
    u8 *p = (u8 *)func_0204fde0(h);
    int i = func_0203ac00(0);

    if (i >= n) {
        i = 0;
    }
    Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 2, 0));
    return 1;
}

/* Looks up script entry (index 0, value 1 & 0xFF) through Unk0e5fb8_Unk_0e61c8. Publishes 1
 * when the lookup succeeds, otherwise 0; indices >= 15 publish 0 without a lookup. */
u32 func_020bbc1c(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);

    if (a < 15) {
        if (Unk0e5fb8_Unk_0e61c8(a, b & 255) != 0) {
            Unk03aae8_Unk_03acf4(1);
        } else {
            Unk03aae8_Unk_03acf4(0);
        }
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Assigns the value of script entry (index 0, value 1 & 0xFF) through Unk0e5fb8_Unk_0e620c;
 * indices >= 15 leave the table untouched. Always returns 1. */
u32 func_020bbc7c(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);

    if (a < 15) {
        Unk0e5fb8_Unk_0e620c(a, b & 255);
    }
    return 1;
}

/* Selects table 1 through Unk0bac80_Unk_0badd0 and publishes the u16 at command argument 0
 * (row, 20-byte stride) and argument 1 (column). A column >= 10 is replaced by column 0 and
 * rows >= 15 publish 0. */
u32 func_020bbcb4(void)
{
    u32 h = Unk0bac80_Unk_0badd0(1);
    u8 *p;
    int row;
    int col;

    func_0204fe18();
    p = (u8 *)func_0204fde0(h);
    row = func_0203ac00(0);
    col = func_0203ac00(1);
    if (row < 15) {
        if (col >= 10) {
            col = 0;
        }
        Unk03aae8_Unk_03acf4(FIELD(u16, p + row * 20 + col * 2, 0));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Selects table 2 through Unk0bac80_Unk_0badd0 and publishes the u16 at (script index 0 - 1),
 * or entry 0 when that index is not below the table's element count. */
u32 func_020bbd20(void)
{
    u32 h = Unk0bac80_Unk_0badd0(2);
    u32 n = func_0204fe18();
    u8 *p = (u8 *)func_0204fde0(h);
    u32 i = func_0203ac00(0) - 1;

    if (i >= n) {
        i = 0;
    }
    Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 2, 0));
    return 1;
}
