/* src/game/unit_0203ce68.c: script command handlers (read args via func_0203ac00). */
#include "game/unit_0203ce68.h"

/* Work block returned by Unk02e000_Thunk_0202e788 (partial view). The four u16 slots at +0x0..+0x6 are
 * read by Unk03ce68_Unk_03ce68 and written by Unk03ce68_Unk_03ced0; ARM 0x0203cfe4 loads byte 0x70. */
typedef struct Unk03ce68Work {
    u16 unk_0000;
    u16 unk_0002;
    u16 unk_0004;
    u16 unk_0006;
    u8 pad_0008[0x68];
    u8 unk_0070;
} Unk03ce68Work;

void Unk0979d8_ResetAllEntries(void);
int Unk096754_Unk_096a14(int operand);
int func_0203ac00(int operandIndex);
int Unk03aae8_Unk_03acf4(u32 value);
Unk03ce68Work *Unk02e000_Thunk_0202e788(void);
u8 Unk09974c_GetEntryUnk08(u32 id);
s8 Unk09727c_GetAreaS8(int i);
s8 Unk0981dc_Unk_098258(u32 id, int selector);
/* The callees store a byte, but these call sites pass the value sign-extended from 16 bits
 * (lsl/asr #16 in the ROM), so the caller-side prototypes take s16. */
void Unk096754_Unk_097220(int i, s16 v);
void Unk0981dc_Unk_0981f4(u32 id, u32 selector, s16 value);

/* Script query: reads a slot index (0..3; arg 1 is read and ignored) and writes the work area's
 * u16 in that slot as the script result (0 for other indices). Returns 1. */
int Unk03ce68_Unk_03ce68(void)
{
    int slot = func_0203ac00(0);
    Unk03ce68Work *w;
    u16 v;
    func_0203ac00(1);
    w = Unk02e000_Thunk_0202e788();
    v = 0;
    switch (slot) {
    case 0:
        v = w->unk_0000;
        break;
    case 1:
        v = w->unk_0002;
        break;
    case 2:
        v = w->unk_0004;
        break;
    case 3:
        v = w->unk_0006;
        break;
    }
    Unk03aae8_Unk_03acf4(v);
    return 1;
}


/* Script command: reads an id (arg 1; arg 0 is read and ignored) and stores it in the work-area
 * slot chosen by Unk09974c_GetEntryUnk08(id): kinds 3..6 map to slots 0..3,
 * other kinds store nothing. Returns 1. */
int Unk03ce68_Unk_03ced0(void)
{
    u16 id;
    Unk03ce68Work *w;
    func_0203ac00(0);
    id = func_0203ac00(1);
    w = Unk02e000_Thunk_0202e788();
    switch (Unk09974c_GetEntryUnk08(id)) {
    case 3:
        w->unk_0000 = id;
        break;
    case 4:
        w->unk_0002 = id;
        break;
    case 5:
        w->unk_0004 = id;
        break;
    case 6:
        w->unk_0006 = id;
        break;
    }
    return 1;
}


/* ARM 0x0203cf48: report whether the operand lookup returns a value other
 * than -1; the handler always returns completion status 1. */
int Unk03ce68_Unk_03cf48(void)
{
    int v = Unk096754_Unk_096a14(func_0203ac00(0));
    int r = 1;
    if (v == -1) {
        r = 0;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

/* Invoke the entry reset and return completion status 1 (ARM 0x0203cfb4). */
u32 Unk03ce68_Unk_03cfb4(void)
{
  Unk0979d8_ResetAllEntries();
  return 1;
}

void Unk096754_ResetAreaPos(void);
/* Invoke the area-position reset and return completion status 1 (ARM 0x0203cfc4). */
u32 Unk03ce68_Unk_03cfc4(void)
{
  Unk096754_ResetAreaPos();
  return 1;
}

/* Consume operand zero, report 1, and return completion status 1 (ARM 0x0203cf78). */
u32 Unk03ce68_Unk_03cf78(void)
{
  func_0203ac00(0);
  Unk03aae8_Unk_03acf4(1);
  return 1;
}

int Unk02ee5c_GetTierFromField70(void);
/* ARM 0x0203cfd4: consume operand zero and report work byte 0x70; return 1. */
int Unk03ce68_Unk_03cfd4(void)
{
    func_0203ac00(0);
    Unk03aae8_Unk_03acf4(Unk02e000_Thunk_0202e788()->unk_0070);
    return 1;
}

/* Consume operand zero and report the byte-0x70 tier; return 1 (ARM 0x0203cff4). */
u32 Unk03ce68_Unk_03cff4(void)
{
  func_0203ac00(0);
  Unk03aae8_Unk_03acf4(Unk02ee5c_GetTierFromField70());
  return 1;
}

int Unk0981dc_Unk_0981dc(u8 operand);
/* Narrow operand zero to eight bits and report the callee result; return 1
 * (ARM 0x0203cf94). The neutral name preserves the unknown command meaning. */
u32 Unk03ce68_Unk_03cf94(void)
{
  u8 value;
  value = func_0203ac00(0);
  Unk03aae8_Unk_03acf4(Unk0981dc_Unk_0981dc(value));
  return 1;
}

void Unk02ee5c_AddClamped70(int delta);
/* Consume two operands and apply operand one as a signed 16-bit delta
 * to the byte-0x70 updater; return completion status 1 (ARM 0x0203d010). */
u32 Unk03ce68_Unk_03d010(void)
{
  short v1;
  func_0203ac00(0);
  v1 = func_0203ac00(1);
  Unk02ee5c_AddClamped70((int)v1);
  return 1;
}

/* Maps a script selector 0..4 to 0, 4, 1, 2, 3; anything else maps to 0. */
int Unk03ce68_Unk_03d038(int sel)
{
    switch (sel) {
    case 0:
        return 0;
    case 1:
        return 4;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    }
    return 0;
}


/* Script query: reads a target (arg 0) and a selector (arg 1, remapped by Unk03ce68_Unk_03d038).
 * Target 0 reads Unk09727c_GetAreaS8(selector), targets 1..3 read Unk0981dc_Unk_098258(target - 1,
 * selector); the value (0 for other targets) becomes the script result. Returns 1. */
int Unk03ce68_Unk_03d088(void)
{
    int target = func_0203ac00(0);
    int sel = Unk03ce68_Unk_03d038(func_0203ac00(1));
    int v = 0;
    if (target == 0) {
        v = Unk09727c_GetAreaS8(sel);
    } else if (target >= 1 && target <= 3) {
        v = Unk0981dc_Unk_098258((u8)(target - 1), sel);
    }
    Unk03aae8_Unk_03acf4(v);
    return 1;
}


/* Script command: the setter counterpart of Unk03ce68_Unk_03d088. Reads a target, a selector
 * (remapped by Unk03ce68_Unk_03d038) and a value; target 0 stores through Unk096754_Unk_097220,
 * targets 1..3 through Unk0981dc_Unk_0981f4(target - 1, ...). Returns 1. */
int Unk03ce68_Unk_03d0f0(void)
{
    int target = func_0203ac00(0);
    int arg1 = func_0203ac00(1);
    int value = func_0203ac00(2);
    int sel = Unk03ce68_Unk_03d038(arg1);
    if (target == 0) {
        Unk096754_Unk_097220(sel, (s16)value);
    } else if (target >= 1 && target <= 3) {
        Unk0981dc_Unk_0981f4((u8)(target - 1), sel, (s16)value);
    }
    return 1;
}
