/* src/game/unit_0203ce68.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Partial view of the work block: ARM 0x0203cfe4 loads byte 0x70. */
typedef struct Unk03ce68Work {
    u8 pad_0000[0x70];
    u8 unk_0070;
} Unk03ce68Work;


void Unk0979d8_ResetAllEntries(void);
int Unk096754_Unk_096a14(int operand);
int func_0203ac00(int operandIndex);
int Unk03aae8_Unk_03acf4(u32 value);
u8 *Unk02e000_Thunk_0202e788(void);
int Unk09727c_GetAreaS8();
int Unk0981dc_Unk_098258();
u32 Unk03ce68_Unk_03d038(u32 arg0);

int Unk03ce68_Unk_03ce68(void)
{
    int k = func_0203ac00(0);
    u16 *w;
    int r;
    func_0203ac00(1);
    w = (u16 *)Unk02e000_Thunk_0202e788();
    r = 0;
    switch (k) {
    case 0: r = w[0]; break;
    case 1: r = w[1]; break;
    case 2: r = w[2]; break;
    case 3: r = w[3]; break;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

int func_0203ac00(int operandIndex);
int Unk03aae8_Unk_03acf4(u32 value);
u8 *Unk02e000_Thunk_0202e788(void);
int Unk09974c_GetEntryUnk08();
void Unk096754_Unk_097220();
void Unk0981dc_Unk_0981f4();
u32 Unk03ce68_Unk_03d038(u32 arg0);

int Unk03ce68_Unk_03ced0(void)
{
    u16 v;
    u16 *w;
    func_0203ac00(0);
    v = func_0203ac00(1);
    w = (u16 *)Unk02e000_Thunk_0202e788();
    switch (Unk09974c_GetEntryUnk08(v)) {
    case 0:
    case 1:
    case 2:
        break;
    case 3: w[0] = v; break;
    case 4: w[1] = v; break;
    case 5: w[2] = v; break;
    case 6: w[3] = v; break;
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

int func_0203ac00(int operandIndex);
int Unk03aae8_Unk_03acf4(u32 value);
/* Consume operand zero, report 1, and return completion status 1 (ARM 0x0203cf78). */
u32 Unk03ce68_Unk_03cf78(void)
{
  func_0203ac00(0);
  Unk03aae8_Unk_03acf4(1);
  return 1;
}

int Unk02ee5c_GetTierFromField70(void);
u8 *Unk02e000_Thunk_0202e788(void);
/* ARM 0x0203cfd4: consume operand zero and report work byte 0x70; return 1. */
int Unk03ce68_Unk_03cfd4(void)
{
    func_0203ac00(0);
    Unk03aae8_Unk_03acf4(((Unk03ce68Work *)Unk02e000_Thunk_0202e788())->unk_0070);
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



/* decompiler-derived */
u32 Unk03ce68_Unk_03d038(u32 arg0)
{
  switch(arg0) {
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
  default:
    return 0;
  }
}

int Unk03ce68_Unk_03d088(void)
{
    int k = func_0203ac00(0);
    u32 y = Unk03ce68_Unk_03d038(func_0203ac00(1));
    int r = 0;
    if (k == 0) {
        r = Unk09727c_GetAreaS8(y);
    } else if (k >= 1 && k <= 3) {
        r = Unk0981dc_Unk_098258((u8)(k - 1), y);
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

int Unk03ce68_Unk_03d0f0(void)
{
    int k = func_0203ac00(0);
    int x = func_0203ac00(1);
    int y = func_0203ac00(2);
    u32 e = Unk03ce68_Unk_03d038(x);
    if (k == 0) {
        Unk096754_Unk_097220(e, (s16)y);
    } else if (k >= 1 && k <= 3) {
        Unk0981dc_Unk_0981f4((u8)(k - 1), e, (s16)y);
    }
    return 1;
}
