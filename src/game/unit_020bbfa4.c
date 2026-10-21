/* src/game/unit_020bbfa4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void Unk0a0ce4_Unk_0a0d68(int value);
/* Forward the input plus six to Unk0a0ce4_Unk_0a0d68; callers at
 * 0x02047d5c and 0x02047d68 supply the input. Its domain is not yet known. */
void Unk0bbfa4_Unk_0bc0a4(int arg0)
{
  Unk0a0ce4_Unk_0a0d68(arg0 + 6);
}

u32 func_0203ac00(u32 index);
void Unk118b04_Unk_118e50(int index, int increment);
u32 Unk118b04_Unk_118e74(int index);
/* Add argument zero to state slot 12 and return command status 1.
 * Unk118b04_Unk_118e50 stores the sum at state + 0x14 + index * 4. */
u32 Unk0bbfa4_Unk_0bbfa4(void)
{
  u32 value;
  value = func_0203ac00(0);
  Unk118b04_Unk_118e50(0xc,value);
  return 1;
}


/* Add argument zero to state slot 13 and return command status 1.
 * Slot layout is evidenced by Unk118b04_Unk_118e50. */
u32 Unk0bbfa4_Unk_0bbfc4(void)
{
  u32 value;
  value = func_0203ac00(0);
  Unk118b04_Unk_118e50(0xd,value);
  return 1;
}


/* Add argument zero to state slot 14 and return command status 1.
 * Slot layout is evidenced by Unk118b04_Unk_118e50. */
u32 Unk0bbfa4_Unk_0bbfe4(void)
{
  u32 value;
  value = func_0203ac00(0);
  Unk118b04_Unk_118e50(0xe,value);
  return 1;
}


/* Add argument zero to state slot 15 and return command status 1.
 * Slot layout is evidenced by Unk118b04_Unk_118e50. */
u32 Unk0bbfa4_Unk_0bc004(void)
{
  u32 value;
  value = func_0203ac00(0);
  Unk118b04_Unk_118e50(0xf,value);
  return 1;
}

int Unk03aae8_Unk_03acf4(u32 value);
/* Publish state slot 12 as the command result, clamping signed negative
 * values to zero; return command status 1. The getter uses state + 0x14. */
u32 Unk0bbfa4_Unk_0bc024(void)
{
  int value;
  value = Unk118b04_Unk_118e74(0xc);
  if (value < 0) {
    value = 0;
  }
  Unk03aae8_Unk_03acf4(value);
  return 1;
}


/* Publish state slot 13 as the command result, clamping signed negative
 * values to zero; return command status 1. The getter uses state + 0x14. */
u32 Unk0bbfa4_Unk_0bc044(void)
{
  int value;
  value = Unk118b04_Unk_118e74(0xd);
  if (value < 0) {
    value = 0;
  }
  Unk03aae8_Unk_03acf4(value);
  return 1;
}


/* Publish state slot 14 as the command result, clamping signed negative
 * values to zero; return command status 1. The getter uses state + 0x14. */
u32 Unk0bbfa4_Unk_0bc064(void)
{
  int value;
  value = Unk118b04_Unk_118e74(0xe);
  if (value < 0) {
    value = 0;
  }
  Unk03aae8_Unk_03acf4(value);
  return 1;
}



/* decompiler-derived */
u32 Unk0bbfa4_Unk_0bc084(void)
{
  int value;
  value = Unk118b04_Unk_118e74(0xf);
  if (value < 0) {
    value = 0;
  }
  Unk03aae8_Unk_03acf4(value);
  return 1;
}

int Unk044904_Unk_045048();
int func_02053000();
/* decompiler-derived */
void Unk0bbfa4_Unk_0bc144(void)
{
  int value;
  value = Unk044904_Unk_045048();
  *(u32 *)(value + 0x58) = 0xf;
  func_02053000(*(u32 *)(value + 0x5c));
  *(u32 *)(value + 0x5c) = 0;
  func_02053000(*(u32 *)(value + 0x60));
  *(u32 *)(value + 0x60) = 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk044904_Unk_045048();
int func_02044ec4();
u8 *func_020a1428(u32 id);
u32 Unk0bbfa4_Unk_0bc17c(void)
{
    u8 *r = (u8 *)func_02044ec4(FIELD(u32, Unk044904_Unk_045048(), 64));
    u32 v = FIELD(u32, func_020a1428(FIELD(u16, r + 256, 216)), 36);
    return (v << 4) >> 25;
}
