/* src/game/unit_0203aae8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk03aae8_Nop_03ae0c(void) { }

extern u8 data_0215de34[];
/* decompiler-derived */
u32 Unk03aae8_Unk_03ad14(void)
{
  return *(u32 *)(((int)data_0215de34) + 4);
}

int func_0203ac00();
int Unk094fe0_Call_0209502c();
/* decompiler-derived */
u32 Unk03aae8_Unk_03aef0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,0);
  return 1;
}

int Unk03aae8_Unk_03acf4();
int func_02050074();
int Unk094fe0_Call_020950b4();
int Unk03aae8_Unk_03af14(void)
{
    if (Unk094fe0_Call_020950b4((s16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* decompiler-derived */
u32 Unk03aae8_Unk_03b878(void)
{
  int value;
  value = func_0203ac00(0);
  func_02050074(0,value + -1);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk03aae8_Unk_03af50(void)
{
  short v1;
  int value1;
  u32 value2;
  value1 = Unk03aae8_Unk_03ad14();
  value2 = *(u32 *)(value1 + 0xe8);
  v1 = func_0203ac00(0);
  Unk02dcfc_Unk_02df00(value2,(int)v1);
  return 3;
}



/* decompiler-derived */
u32 Unk03aae8_Unk_03ac9c(int arg0)
{
  int value1;
  int value2;
  value2 = *(int *)(((int)data_0215de34) + 4);
  value1 = *(int *)(value2 + 0x1c) - (arg0 + 1);
  switch(*(u8 *)(value2 + value1 + 0x20)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    return *(u32 *)(value2 + value1 * 4 + 0x3c);
  }
  return 0;
}


int func_020b8660();
/* decompiler-derived */
u32 Unk03aae8_Unk_03ae68(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,1);
  switch((int)v1) {
  case 0x733:
    func_020b8660(0);
    break;
  case 0x734:
    func_020b8660(1);
    break;
  case 0x735:
    func_020b8660(2);
    break;
  case 0x736:
    func_020b8660(3);
    break;
  case 0x737:
    func_020b8660(4);
  }
  return 1;
}

/* decompiler-derived */
int Unk03aae8_Unk_03acf4(u32 arg0)
{
  int tmp1;
  tmp1 = (int)(data_0215de34);
  *(u8 *)(*(int *)(data_0215de34 + 4) + 0x3b) = 0;
  *(u32 *)(*(int *)(tmp1 + 4) + 0xa8) = arg0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef int (*Unk03aae8StepFn)(u8 *);
extern u8 data_02142170[];
void func_02095b48();
void func_0204b344();
void *func_0204b3cc();
void *func_0204fe68();
void *func_0204fed8();
void *Unk095560_Unk_095778();
int func_0201f1dc();

void Unk03aae8_Unk_03ad24(u8 *p)
{
    switch (FIELD(s32, p, 8)) {
    case 0: {
        u8 buf[64] = {0};
        func_02095b48(buf, FIELD(u32, p, 64));
        func_0204b344(p, buf);
        break;
    }
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *Unk03aae8_Unk_03ad98(u8 *p, int key)
{
    void *r = 0;
    switch (FIELD(s32, p, 8)) {
    case 0:
        r = func_0204b3cc(p, key);
        break;
    case 1:
        break;
    case 2:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 92), r), key);
        break;
    case 3:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 116), r), key);
        break;
    }
    return r;
}

void *Unk03aae8_Unk_03ae10(u8 *p, int key)
{
    void *r = 0;
    switch (FIELD(s32, p, 8)) {
    case 0:
        r = Unk095560_Unk_095778(key);
        break;
    case 1:
        break;
    case 2:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 80), r), key);
        break;
    case 3:
        break;
    }
    return r;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk094fe0_Unk_094fec();
void Unk094fe0_SetSlot();
int Unk094fe0_GetSlot();
void func_0209512c();
u32 Unk03aae8_Unk_03ad14(void);

int Unk03aae8_Unk_03b634(void)
{
    int r;
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    r = 0;
    switch (FIELD(s32, o, 8)) {
    case 0:
        r = Unk094fe0_Unk_094fec(FIELD(u32, o, 64));
        break;
    case 2:
        break;
    }
    Unk094fe0_SetSlot(r, a, b);
    return 1;
}

int Unk03aae8_Unk_03b694(void)
{
    int r;
    s16 a = func_0203ac00(0);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    r = 0;
    switch (FIELD(s32, o, 8)) {
    case 0:
        r = (s16)Unk094fe0_GetSlot(Unk094fe0_Unk_094fec(FIELD(u32, o, 64)), a);
        break;
    case 2:
        break;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

int Unk03aae8_Unk_03b6ec(void)
{
    s16 a = func_0203ac00(0);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    switch (FIELD(s32, o, 8)) {
    case 0:
        func_0209512c(Unk094fe0_Unk_094fec(FIELD(u32, o, 64)), a, 1);
        break;
    case 1:
        FIELD(u32, o, 64) |= 1 << a;
        break;
    case 2:
        break;
    case 3:
        FIELD(u32, o, 64) |= 1 << a;
        break;
    }
    return 1;
}

int Unk03aae8_Unk_03b89c(void)
{
    u32 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a > (u32)func_02050074(0, b - 1)) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

int Unk03aae8_Unk_03b93c(void)
{
    int v = func_0203ac00(0);
    int lo = func_0203ac00(1);
    int hi = func_0203ac00(2);
    if (lo <= v && v <= hi) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
