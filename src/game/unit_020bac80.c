/*
 * src/game/unit_020bac80.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#include "game/unit_020bac80.h"
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
int Unk02ee5c_GetTierFromField70(void);
int Unk03aae8_Unk_03acf4(u32 value);
void *Unk03aae8_Unk_03ad14(void);
void *Unk044904_Get_data_0215ee98(void);
void func_02044ec4(void);
void func_0204fdac(u32 handle, u32 value);
void Unk0bac80_Thunk_02044ec4(void);
u32 Unk0bac80_Unk_0badc0(void);
u32 Unk0bac80_Unk_0bae08(void);
int Unk0bac80_Unk_0bae18(void);
u32 Unk0bac80_Unk_0bae50(void);
u32 Unk0bac80_Unk_0bb298(void);
void Unk0bac80_Unk_0badd0(u32 arg0);
void Unk0bac80_Unk_0badec(u32 arg0);
/* Borrowed views: offsets come from the loads in 020badc0..020bae18.
 * Gaps describe only the accessed prefix; ownership stays with the providers. */
typedef struct Unk0bac80Context {
    u8 pad_0000[0xe8];
    u32 work_address;
} Unk0bac80Context;
typedef struct Unk0bac80Work {
    u8 pad_0000[0x40];
    u32 unk_0040;
    u8 pad_0044[0x10];
    u32 unk_0054;
    u8 pad_0058[8];
    u32 unk_0060;
    u8 pad_0064[4];
    u32 unk_0068;
} Unk0bac80Work;
/* The original LDR ip / BX ip thunk names 02044ec4 as its sole target. */
void Unk0bac80_Thunk_02044ec4(void) { func_02044ec4(); }

/* Return the borrowed work address stored at context +0xe8 (020badc0 LDR). */
u32 Unk0bac80_Unk_0badc0(void)
{
    Unk0bac80Context *context = Unk03aae8_Unk_03ad14();
    return context->work_address;
}

/* Read the opaque word at work +0x68; the provider must supply valid work. */
u32 Unk0bac80_Unk_0bae08(void)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    return work->unk_0068;
}

/* Return a borrowed subobject address, +0x8c from the global provider.
 * Its integer address ABI is retained for the existing handlers below. */
int Unk0bac80_Unk_0bae18(void)
{
    u8 *base = Unk044904_Get_data_0215ee98();
    return (int)(base + 0x8c);
}

/* Publish the tier query result and return handler completion (1).
 * Evidence: consecutive BLs at 020bae54/020bae58 pass r0 unchanged. */
u32 Unk0bac80_Unk_0bae50(void)
{
    u32 tier = Unk02ee5c_GetTierFromField70();
    Unk03aae8_Unk_03acf4(tier);
    return 1;
}

/* Publish work +0x40 through the shared result setter, then complete (1).
 * Evidence: 020bb2a0 loads +0x40 before calling 0203acf4. */
u32 Unk0bac80_Unk_0bb298(void)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    Unk03aae8_Unk_03acf4(work->unk_0040);
    return 1;
}

/* Forward the opaque work +0x54 handle and the caller's unchanged word.
 * Evidence: LDR +0x54 and MOV r1,r4 before BL 0204fdac. */
void Unk0bac80_Unk_0badd0(u32 arg0)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    func_0204fdac(work->unk_0054, arg0);
}

/* Forward the opaque work +0x60 handle and the caller's unchanged word.
 * Evidence: LDR +0x60 and MOV r1,r4 before BL 0204fdac. */
void Unk0bac80_Unk_0badec(u32 arg0)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    func_0204fdac(work->unk_0060, arg0);
}

/* Query the borrowed subobject by selector; returned word is opaque. */
u32 func_02049d80(u32 address, u32 selector);
/* Publish query 02049d80 selector 2 and return completion (1).
 * Evidence: 020bae34 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0bae34(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049d80(address, 2);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Alternate query on the same borrowed subobject and selector ABI. */
u32 func_02049f24(u32 address, u32 selector);
/* Publish query 02049f24 selector 0 and return completion (1).
 * Evidence: 020bae64 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0bae64(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049f24(address, 0);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish query 02049d80 selector 0 and return completion (1).
 * Evidence: 020bae80 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0bae80(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049d80(address, 0);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish query 02049d80 selector 1 and return completion (1).
 * Evidence: 020baf6c BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0baf6c(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049d80(address, 1);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish query 02049f24 selector 1 and return completion (1).
 * Evidence: 020baf88 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0baf88(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049f24(address, 1);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish query 02049d80 selector 3 and return completion (1).
 * Evidence: 020bb078 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0bb078(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049d80(address, 3);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish query 02049d80 selector 4 and return completion (1).
 * Evidence: 020bb094 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0bb094(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049d80(address, 4);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish query 02049d80 selector 5 and return completion (1).
 * Evidence: 020bb0b0 BL sequence forwards the query's r0 to 0203acf4.
 * The subobject is borrowed from 020bae18 and must remain valid. */
u32 Unk0bac80_Unk_0bb0b0(void)
{
    u32 address = Unk0bac80_Unk_0bae18();
    u32 result = func_02049d80(address, 5);
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

/* Publish selector 6 from query 02049d80; evidence: BL sequence at 020bb0cc. */
u32 Unk0bac80_Unk_0bb0cc(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  Unk03aae8_Unk_03acf4(func_02049d80(value,6));
  return 1;
}

/* Publish selector 7 from query 02049d80; evidence: BL sequence at 020bb0e8. */
u32 Unk0bac80_Unk_0bb0e8(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  Unk03aae8_Unk_03acf4(func_02049d80(value,7));
  return 1;
}

int Unk02e000_GetWorkArea(void);
int func_020bac80(u32 arg0, int value);
/* Forward work halfword +0x35c plus one; evidence: LDRH/ADD at 020bacf8. */
void Unk0bac80_Unk_0bacf8(u32 arg0)
{
  int value;
  value = Unk02e000_GetWorkArea();
  func_020bac80(arg0,*(u16 *)(value + 0x35c) + 1);
}

/* Forward work halfword +0x35c minus one; evidence: LDRH/SUB at 020bad1c. */
void Unk0bac80_Unk_0bad1c(u32 arg0)
{
  int value;
  value = Unk02e000_GetWorkArea();
  func_020bac80(arg0,*(u16 *)(value + 0x35c) - 1);
}

int func_0203ac00(u32 index);
/* Publish halfword at +0x386 indexed by signed argument 0 when below 15,
 * otherwise publish zero. Evidence: CMP/BGE and LDRH at 020bb104.
 * Negative indices are not rejected by the original; callers supply valid indices. */
u32 Unk0bac80_Unk_0bb104(void)
{
  int value1;
  int value2;
  value1 = func_0203ac00(0);
  if (value1 < 0xf) {
    value2 = Unk02e000_GetWorkArea();
    Unk03aae8_Unk_03acf4(*(u16 *)(value2 + value1 * 2 + 0x386));
  }
  else {
    Unk03aae8_Unk_03acf4(0);
  }
  return 1;
}

int func_0203ac00(u32 index);
int Unk02e000_GetWorkArea(void);
/* Add argument 1 modulo 65536 to the selected halfword at +0x386 when
 * argument 0 is below 15. Evidence: LDRH/ADD/STRH at 020bb144.
 * The caller must supply a valid index; the signed comparison permits negatives. */
u32 Unk0bac80_Unk_0bb144(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a < 15) {
        u16 *t = (u16 *)((u8 *)Unk02e000_GetWorkArea() + 134 + 768);
        t[a] += b;
    }
    return 1;
}

/* Opaque helper ABIs follow the argument registers at the original call sites. */
void func_0204f59c(u32 mode, u32 handle, int value);
void func_0204f650(u32 mode, u32 handle, int value, u32 selector);
void func_0204f24c(u32 mode, u32 handle, int value, u32 option,
                   u32 zero, u32 enabled);

/* Forward argument 0 through two helpers using the borrowed subobject's first
 * word, set work +0x44 bit 13, and return 3. Evidence: calls and ORR at 020bae9c.
 * The handle and command meanings are unknown; ownership remains with providers. */
u32 func_020bae9c(void)
{
    int value = func_0203ac00(0);
    u32 handle = *(u32 *)Unk0bac80_Unk_0bae18();
    u32 *work;
    func_0204f59c(0, handle, value);
    func_0204f24c(0, handle, value, 0, 0, 1);
    work = (u32 *)Unk0bac80_Unk_0badc0();
    work[0x44 / 4] |= 0x2000;
    return 3;
}

/* Forward argument 0 with selector 21, then call 0204f24c with option 1,
 * set work +0x44 bit 13, and return 3. Evidence: MOV/BL/ORR at 020baf04.
 * The subobject's first word is a borrowed opaque handle. */
u32 func_020baf04(void)
{
    int value = func_0203ac00(0);
    u32 handle = *(u32 *)Unk0bac80_Unk_0bae18();
    u32 *work;
    func_0204f650(0, handle, value, 21);
    func_0204f24c(0, handle, value, 1, 0, 1);
    work = (u32 *)Unk0bac80_Unk_0badc0();
    work[0x44 / 4] |= 0x2000;
    return 3;
}

void func_0204f5e0(u32 mode, u32 handle, int value);
/* Issue option 2 for argument 0, mark work bit 13, and return 3.
 * Evidence: calls and ORR at 020bafa4; the handle is borrowed. */
u32 func_020bafa4(void)
{
    int value = func_0203ac00(0);
    u32 handle = *(u32 *)Unk0bac80_Unk_0bae18();
    u32 *work;
    func_0204f5e0(0, handle, value);
    func_0204f24c(0, handle, value, 2, 0, 1);
    work = (u32 *)Unk0bac80_Unk_0badc0();
    work[0x44 / 4] |= 0x2000;
    return 3;
}

/* Issue selector 22 and option 3 for argument 0, mark work bit 13.
 * Evidence: immediate operands and BLs at 020bb00c; returns 3. */
u32 func_020bb00c(void)
{
    int value = func_0203ac00(0);
    u32 handle = *(u32 *)Unk0bac80_Unk_0bae18();
    u32 *work;
    func_0204f650(0, handle, value, 22);
    func_0204f24c(0, handle, value, 3, 0, 1);
    work = (u32 *)Unk0bac80_Unk_0badc0();
    work[0x44 / 4] |= 0x2000;
    return 3;
}

void Unk02f2a8_SetField7470(int value, int a, int b);
void func_02034b7c(int value, int a, int b, u32 word,
                   int option, int enabled, int zero, int one);
void Unk0a0ce4_Unk_0a0da4(int value);
/* Ignore negative values; forward signed bytes +7482/+7483 and work +358
 * through the original helpers, then signal 52. Evidence: 020bac80 BLs.
 * Both objects are borrowed. The return register has no result contract. */
int func_020bac80(u32 arg0, int value)
{
    Unk0bac80State *state = (Unk0bac80State *)arg0;
    Unk0bac80Area *work;
    if (value < 0) return;
    work = (Unk0bac80Area *)Unk02e000_GetWorkArea();
    Unk02f2a8_SetField7470(value, state->unk_7482, state->unk_7483);
    func_02034b7c(value, state->unk_7482, state->unk_7483,
                  work->unk_0358, 3, 1, 0, 1);
    Unk0a0ce4_Unk_0a0da4(52);
}
int func_02052728(void);
void func_0204b74c(int a, int b, u32 value);
/* Poll state byte +7481: start the helper when idle, advance the byte,
 * then report whether word +7440 equals 1. Evidence: 020bad40 switch/BLs.
 * Unknown states return zero; caller retains the object. */
u32 func_020bad40(Unk0bac80State *state)
{
    u32 result = 0;
    switch (state->unk_7481) {
    case 0:
        if (func_02052728() == 0) {
            Unk0bac80Area *work = (Unk0bac80Area *)Unk02e000_GetWorkArea();
            func_0204b74c(state->unk_7482, state->unk_7483, work->unk_035c);
            state->unk_7481++;
        }
        break;
    case 1:
        if (state->unk_7440 == 1) result = 1;
        break;
    }
    return result;
}

int func_0204a9ec(Unk0bac80Entry *entry);
int Unk0b0b5c_Unk_0b0c30(Unk0bac80Entry *entry, int limit);
int Unk0b0b5c_Unk_0b0cac(Unk0bac80Entry *entry, int limit);
/* For ten borrowed entries of kind 1 that pass 0204a9ec, issue paired
 * selector 21/22 commands with limit 999, then mark work bit 13.
 * Evidence: loop, handle mask and BL operands at 020bb18c. Returns 3. */
u32 func_020bb18c(void)
{
    int slot = 0;
    Unk0bac80Table *table = Unk044904_Get_data_0215ee98();
    int limit = 999;
    int i;
    int zero = 0;
    for (i = 0; i < 10; i++) {
        Unk0bac80Entry *entry = table->entries[i];
        if (entry != 0 && ((entry->handle >> 16) & 255) == 1 &&
            func_0204a9ec(entry) == 0) {
            int a = Unk0b0b5c_Unk_0b0c30(entry, limit);
            int b = Unk0b0b5c_Unk_0b0cac(entry, limit);
            func_0204f650(slot, entry->handle, a, 21);
            func_0204f24c(slot, entry->handle, a, 1, zero, 1);
            func_0204f650(slot + 6, entry->handle, b, 22);
            func_0204f24c(slot + 6, entry->handle, b, 3, 1, 1);
            slot += 12;
        }
    }
    {
        u32 *work = (u32 *)Unk0bac80_Unk_0badc0();
        work[0x44 / 4] |= 0x2000;
    }
    return 3;
}
