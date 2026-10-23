/* Script-style result handlers; offsets and signedness follow the original ARM code. */
#include "types.h"

/* 36-byte table entry selected by the handlers below. Layout comes from the
 * LDRH/LDRSH offsets used here and the 0x24 stride (MLA in 0x020bb908). */
typedef struct Unk0bb908Slot {
    s16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u8 pad_06[4];
} Unk0bb908Slot;

typedef struct Unk0bb908Entry {
    u16 unk_0000;
    u16 unk_0002;
    u16 unk_0004;
    Unk0bb908Slot unk_0006[3]; /* size 3 from the CMP #3 index clamp */
} Unk0bb908Entry;

/* Work area returned by Unk0bac80_Unk_0badc0; only +0x68 is used here. */
typedef struct Unk0bac80Work {
    u8 pad_0000[0x68];
    Unk0bb908Entry *unk_0068;
} Unk0bac80Work;

/* Script argument/result channels; field meanings remain unidentified. */
s32 func_0203ac00(u32 argument);
void Unk03aae8_Unk_03acf4(s32 value);
Unk0bb908Entry *func_0204fde0(u32 handle);
s32 func_0204fe18(void);
s32 func_02050074(s32 lower, s32 upper);
void func_020bc0b4(void);
u32 Unk0bac80_Unk_0badec(u32 selector);
Unk0bac80Work *Unk0bac80_Unk_0badc0(void);
Unk0bb908Entry *Unk0bac80_Unk_0bae08(void);

/* For argument 0 < 15, select source 0 and an entry index in [0, count - 1],
 * store the entry's address in work->unk_0068, and publish the index.
 * Otherwise publish zero. Returns 1.
 * Evidence: calls and MLA/STR at 0x020bb908..0x020bb974. */
u32 Unk0bb908_Unk_0bb908(void)
{
    s32 arg;
    u32 handle;
    s32 count;
    s32 index;
    Unk0bb908Entry *base;
    Unk0bac80Work *work;

    arg = func_0203ac00(0);
    if (arg < 15) {
        func_020bc0b4();
        handle = Unk0bac80_Unk_0badec(0);
        count = func_0204fe18();
        index = func_02050074(0, count - 1);
        base = func_0204fde0(handle);
        work = Unk0bac80_Unk_0badc0();
        work->unk_0068 = &base[index];
        Unk03aae8_Unk_03acf4(index);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* As above, using source selector 1; evidence: immediate at 0x020bb990. */
u32 Unk0bb908_Unk_0bb978(void)
{
    s32 arg;
    u32 handle;
    s32 count;
    s32 index;
    Unk0bb908Entry *base;
    Unk0bac80Work *work;

    arg = func_0203ac00(0);
    if (arg < 15) {
        func_020bc0b4();
        handle = Unk0bac80_Unk_0badec(1);
        count = func_0204fe18();
        index = func_02050074(0, count - 1);
        base = func_0204fde0(handle);
        work = Unk0bac80_Unk_0badc0();
        work->unk_0068 = &base[index];
        Unk03aae8_Unk_03acf4(index);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes selected entry->unk_0004, or zero for null.
 * Evidence: LDRH at 0x020bb9f8. Returns 1. */
u32 Unk0bb908_Unk_0bb9e8(void)
{
    Unk0bb908Entry *e = Unk0bac80_Unk_0bae08();
    if (e != 0) {
        Unk03aae8_Unk_03acf4(e->unk_0004);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes selected entry->unk_0000, or zero for null.
 * Evidence: LDRH at 0x020bba24. Returns 1. */
u32 Unk0bb908_Unk_0bba14(void)
{
    Unk0bb908Entry *e = Unk0bac80_Unk_0bae08();
    if (e != 0) {
        Unk03aae8_Unk_03acf4(e->unk_0000);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes selected entry->unk_0002, or zero for null.
 * Evidence: LDRH at 0x020bba50. Returns 1. */
u32 Unk0bb908_Unk_0bba40(void)
{
    Unk0bb908Entry *e = Unk0bac80_Unk_0bae08();
    if (e != 0) {
        Unk03aae8_Unk_03acf4(e->unk_0002);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the signed unk_00 of slot argument0. Indices >= 3 use slot 0;
 * negative indices are not clamped. Null entries publish zero.
 * Evidence: signed CMP/MOVGE and LDRSH at 0x020bba80..0x020bba98. Returns 1. */
u32 Unk0bb908_Unk_0bba6c(void)
{
    Unk0bb908Entry *e = Unk0bac80_Unk_0bae08();
    s32 i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (e != 0) {
        Unk03aae8_Unk_03acf4(e->unk_0006[i].unk_00);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes unk_02 of slot argument0 (same clamp as above), or zero for null.
 * Evidence: signed CMP/MOVGE and LDRH at 0x020bbac8..0x020bbae0. Returns 1. */
u32 Unk0bb908_Unk_0bbab4(void)
{
    Unk0bb908Entry *e = Unk0bac80_Unk_0bae08();
    s32 i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (e != 0) {
        Unk03aae8_Unk_03acf4(e->unk_0006[i].unk_02);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes unk_04 of slot argument0 (same clamp as above), or zero for null.
 * Evidence: signed CMP/MOVGE and LDRH at 0x020bbb10..0x020bbb28. Returns 1. */
u32 Unk0bb908_Unk_0bbafc(void)
{
    Unk0bb908Entry *e = Unk0bac80_Unk_0bae08();
    s32 i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (e != 0) {
        Unk03aae8_Unk_03acf4(e->unk_0006[i].unk_04);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
