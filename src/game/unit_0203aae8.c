/* src/game/unit_0203aae8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Intentionally empty callback: the original consists solely of a return. */
void Unk03aae8_Nop_03ae0c(void) { }

extern u8 data_0215de34[];
/* Return the borrowed active-work address stored at singleton offset +4. */
u32 Unk03aae8_Unk_03ad14(void)
{
  return *(u32 *)(((int)data_0215de34) + 4);
}

int func_0203ac00(int argumentIndex);
int Unk094fe0_Call_0209502c(int value, int mode);
/* Forward argument zero as a signed 16-bit value with mode zero; return status 1. */
u32 Unk03aae8_Unk_03aef0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,0);
  return 1;
}

void Unk03aae8_Unk_03acf4(u32 value);
int func_02050074(int selector, int index);
int Unk094fe0_Call_020950b4(int value);
/* Store whether the signed 16-bit argument query is nonzero; return status 1. */
int Unk03aae8_Unk_03af14(void)
{
    if (Unk094fe0_Call_020950b4((s16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Query selector zero using the one-based argument minus one and store its result. */
u32 Unk03aae8_Unk_03b878(void)
{
  int value;
  value = func_0203ac00(0);
  Unk03aae8_Unk_03acf4(func_02050074(0, value - 1));
  return 1;
}


void Unk02dcfc_Unk_02df00(u32 work, int value);

/* Forward work field +0xe8 and signed 16-bit argument zero; return status 3. */
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



/* Read a borrowed stack word only for tag 5; arg0 counts backward from the top. */
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

/* Clear active-work byte +0x3b, then store the full result word at +0xa8.
 * Reload the singleton pointer between writes, as in the original. */
void Unk03aae8_Unk_03acf4(u32 arg0)
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
void func_02095b48(u8 *buffer, u32 value);
void func_0204b344(u8 *object, const u8 *buffer);
void *func_0204b3cc(u8 *object, int key);
void *func_0204fe68(u32 handle, void *context);
void *func_0204fed8(void *object, int key);
void *Unk095560_Unk_095778(int key);
int _s32_div_f();

/* For kind 0, populate a zeroed 64-byte temporary from field +0x40 and apply it.
 * The borrowed object must expose its kind at +8. */
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

/* Resolve key through the kind-specific borrowed handle at +0x5c or +0x74.
 * Kind 0 delegates directly; unsupported kinds return null. */
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

/* Resolve key globally for kind 0 or through borrowed field +0x50 for kind 2.
 * Other kinds return null; evidence is the original kind jump table. */
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
int Unk094fe0_Unk_094fec(u32 value);
void Unk094fe0_SetSlot(int owner, int slot, int value);
int Unk094fe0_GetSlot(int owner, int slot);
void func_0209512c();
u32 Unk03aae8_Unk_03ad14(void);

/* Write a slot using signed 16-bit arguments; kind 0 resolves field +0x40,
 * while other kinds pass owner zero. Return script status 1. */
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

/* Read a signed 16-bit slot for kind 0, otherwise store zero; return status 1. */
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

/* Store the unsigned comparison of argument zero against the indexed query.
 * Argument one is a one-based index; both result branches return status 1. */
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

/* Store whether argument 0 lies within the inclusive signed bounds in arguments
 * 1 and 2; the original comparisons establish signed ordering. */
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

int func_02050088(int stream, u32 lower, u32 upper);
/* Query stream zero with bounds scaled by 1024, divide its unsigned result by
 * 100, multiply by argument 0 with word wrapping, then arithmetic-shift by 10.
 * The original umull reciprocal sequence establishes unsigned division. */
int func_0203b8e4(void)
{
    int scale = func_0203ac00(0);
    u32 lower = func_0203ac00(1);
    u32 upper = func_0203ac00(2);
    u32 value = (u32)func_02050088(0, lower << 10, upper << 10) / 100;
    Unk03aae8_Unk_03acf4((s32)((u32)scale * value) >> 10);
    return 1;
}
