/* Script-style result handlers; offsets and signedness follow the original ARM code. */
#include "types.h"


/* Script argument/result channels; field meanings remain unidentified. */
s32 func_0203ac00(u32 argument);
void Unk03aae8_Unk_03acf4(s32 value);
s32 func_0204fde0(u32 handle);
s32 func_0204fe18(void);
s32 func_02050074(s32 lower, s32 upper);
void func_020bc0b4(void);
u32 Unk0bac80_Unk_0badec(u32 selector);
u8 *Unk0bac80_Unk_0badc0(void);
u8 *Unk0bac80_Unk_0bae08(void);

/* For argument 0 < 15, select source 0 and a 36-byte entry, store its address
 * at work +0x68, and publish its index. Otherwise publish zero. Returns 1.
 * Evidence: calls and MLA/STR at 0x020bb908..0x020bb974. */
u32 Unk0bb908_Unk_0bb908(void)
{
  int value1;
  u32 value2;
  int value3;
  u8 *value4;
  value1 = func_0203ac00(0);
  if (value1 < 0xf) {
    func_020bc0b4();
    value2 = Unk0bac80_Unk_0badec(0);
    value1 = func_0204fe18();
    value1 = func_02050074(0,value1 + -1);
    value3 = func_0204fde0(value2);
    value4 = Unk0bac80_Unk_0badc0();
    *(int *)(value4 + 0x68) = value1 * 0x24 + value3;
    Unk03aae8_Unk_03acf4(value1);
  }
  else {
    Unk03aae8_Unk_03acf4(0);
  }
  return 1;
}


/* As above, using source selector 1; evidence: immediate at 0x020bb990.
 * Stores the selected entry at work +0x68 and publishes its index; returns 1. */
u32 Unk0bb908_Unk_0bb978(void)
{
  int value1;
  u32 value2;
  int value3;
  u8 *value4;
  value1 = func_0203ac00(0);
  if (value1 < 0xf) {
    func_020bc0b4();
    value2 = Unk0bac80_Unk_0badec(1);
    value1 = func_0204fe18();
    value1 = func_02050074(0,value1 + -1);
    value3 = func_0204fde0(value2);
    value4 = Unk0bac80_Unk_0badc0();
    *(int *)(value4 + 0x68) = value1 * 0x24 + value3;
    Unk03aae8_Unk_03acf4(value1);
  }
  else {
    Unk03aae8_Unk_03acf4(0);
  }
  return 1;
}

/* Publishes the unsigned halfword at selected entry +4, or zero for null.
 * Evidence: LDRH at 0x020bb9f8. Returns 1. */
u32 Unk0bb908_Unk_0bb9e8(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p, 4));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the unsigned halfword at selected entry +0, or zero for null.
 * Evidence: LDRH at 0x020bba24. Returns 1. */
u32 Unk0bb908_Unk_0bba14(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p, 0));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the unsigned halfword at selected entry +2, or zero for null.
 * Evidence: LDRH at 0x020bba50. Returns 1. */
u32 Unk0bb908_Unk_0bba40(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p, 2));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the signed halfword at entry +6 + argument0 * 10. Indices >=3
 * use zero; negative indices are preserved. Null entries publish zero.
 * Evidence: signed CMP/MOVGE and LDRSH at 0x020bba80..0x020bba98. Returns 1. */
u32 Unk0bb908_Unk_0bba6c(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(s16, p + i * 10, 6));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the unsigned halfword at entry +8 + argument0 * 10. Indices >=3
 * use zero; negative indices are preserved. Null entries publish zero.
 * Evidence: signed CMP/MOVGE and LDRH at 0x020bbac8..0x020bbae0. Returns 1. */
u32 Unk0bb908_Unk_0bbab4(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 10, 8));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the unsigned halfword at entry +10 + argument0 * 10. Indices >=3
 * use zero; negative indices are preserved. Null entries publish zero.
 * Evidence: signed CMP/MOVGE and LDRH at 0x020bbb10..0x020bbb28. Returns 1. */
u32 Unk0bb908_Unk_0bbafc(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 10, 10));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
