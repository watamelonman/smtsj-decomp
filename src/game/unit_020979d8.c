/* src/game/unit_020979d8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0979d8Work {
    u8 pad_0000[0x34];
    u16 unk_0034;
} Unk0979d8Work;



int Unk096754_GetAreaRecordIf();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk0979d8_ResetFields(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    FIELD(s16, p, 30) = FIELD(s16, p, 10);
    FIELD(s16, p, 32) = FIELD(s16, p, 12);
    return 1;
}

/* decompiler-derived */
u8 Unk0979d8_Unk_098124(void)
{
  u8 value1;
  int value2;
  value2 = Unk096754_GetAreaRecordIf();
  if (value2 == 0) {
    value1 = 0;
  }
  else {
    value1 = *(u8 *)(value2 + 0x38);
  }
  return value1;
}


/* decompiler-derived */
int Unk0979d8_Unk_09813c(void)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 0x1e);
  }
  return value;
}


/* decompiler-derived */
int Unk0979d8_Unk_098154(void)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 10);
  }
  return value;
}


/* decompiler-derived */
int Unk0979d8_Unk_09818c(void)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 0x20);
  }
  return value;
}


/* decompiler-derived */
int Unk0979d8_Unk_0981a4(void)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 0xc);
  }
  return value;
}

int Unk0979d8_ClampField1e();
/* decompiler-derived */
void Unk0979d8_Unk_09816c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value == 0) {
    return;
  }
  Unk0979d8_ClampField1e(value,arg1);
}

int Unk0979d8_ClampField20();
/* decompiler-derived */
void Unk0979d8_Unk_0981bc(u32 arg0,u32 arg1)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value == 0) {
    return;
  }
  Unk0979d8_ClampField20(value,arg1);
}


int Unk0979d8_ResetFields();
/* decompiler-derived */
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0){
  if (arg0 != 0) {
    arg0->unk_0034 = 0;
    Unk0979d8_ResetFields();
    return 1;
  }
  return 0;
}

int Unk096754_ClampField1c();
int Unk0979d8_ClampField1e(u8 *p, int v)
{
    s32 m;
    if (p == 0) {
        return 0;
    }
    m = FIELD(s16, p, 10);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 30) = m;
    return FIELD(s16, p, 30);
}

int Unk0979d8_ClampField20(u8 *p, int v)
{
    s32 m;
    if (p == 0) {
        return 0;
    }
    m = FIELD(s16, p, 12);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 32) = m;
    return FIELD(s16, p, 32);
}

int Unk0979d8_HasId(u8 *p, int id)
{
    int j;
    if (p == 0) {
        return 0;
    }
    for (j = 0; j < 6; j++) {
        if (id == ((u16 *)(p + 40))[j]) {
            return 1;
        }
    }
    return 0;
}

void Unk0979d8_CopyIds(u8 *p, u16 *out)
{
    int j;
    if (p == 0) {
        return;
    }
    for (j = 0; j < 6; j++) {
        out[j] = ((u16 *)(p + 40))[j];
    }
}

/* decompiler-derived */
void Unk0979d8_Unk_097f00(u32 arg0)
{
  Unk096754_ClampField1c();
  Unk0979d8_Unk_09816c(0,arg0);
  Unk0979d8_Unk_09816c(1,arg0);
  Unk0979d8_Unk_09816c(2,arg0);
}

int Unk096754_ClampField1e();
/* decompiler-derived */
void Unk0979d8_Unk_097f34(u32 arg0)
{
  Unk096754_ClampField1e();
  Unk0979d8_Unk_0981bc(0,arg0);
  Unk0979d8_Unk_0981bc(1,arg0);
  Unk0979d8_Unk_0981bc(2,arg0);
}


