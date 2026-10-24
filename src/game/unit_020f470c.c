/* src/game/unit_020f470c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"




/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f470cWork {
    u8 pad_0000[8];
    u32 state;
    u8 pad_000c[0x44];
    s32 unk_0050;
    u8 embedded_0054[0xa4];
} Unk0f470cWork;

/* The original callback immediately returns without reading any arguments. */
void Unk0f470c_Nop_0f4874(void) { }

void func_020f7248(void);
/* The original interworking thunk forwards directly to func_020f7248. */
void Unk0f470c_Thunk_020f7248(void) { func_020f7248(); }

int Unk0f7188_Unk_0f7210();
int func_020f82e0();
/* Predicate 0f7210 gates the update of the embedded object at +0x54. */
void Unk0f470c_Unk_0f4908(Unk0f470cWork *arg0)
{
  int value;
  value = Unk0f7188_Unk_0f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0->embedded_0054);
}

extern u32 data_02176e00[];
int func_02008848();
int func_020f4790();
/* Clear the observed 0xf8-byte work area, publish it, then initialize it. */
void Unk0f470c_Unk_0f4764(Unk0f470cWork *arg0)
{
  func_02008848(arg0,0,0xf8);
  *data_02176e00 = (u32)arg0;
  func_020f4790(arg0);
}

int Unk0d1c98_Unk_0d1d94();
int func_020ea630();
int Unk0f470c_Unk_0f4b80(Unk0f470cWork *arg0);
/* Predicate 0e8bac gates forwarding and submission of resource 8 with -1. */
void Unk0f470c_Unk_0f4c20(Unk0f470cWork *arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Unk_0e8bac();
  if (value1 == 0) {
    return;
  }
  Unk0f470c_Unk_0f4b80(arg0);
  value2 = func_020ea630(8);
  Unk0d1c98_Unk_0d1d94(value2,0xffffffff);
}



int Unk0e8228_GetArr40();
int Unk0ea208_Unk_0ea70c();
int func_020ea744();
int Unk0ea208_Unk_0ea828();
/* decompiler-derived */
void Unk0f470c_Unk_0f4958(int arg0)
{
  u32 value;
  value = Unk0f8448_GetUnkField10(arg0 + 0x54);
  Unk0ea208_Unk_0ea70c();
  if (((Unk0f470cWork *)arg0)->unk_0050 != 0) {
    Unk0ea208_Unk_0ea828();
    return;
  }
  Unk0e8228_GetArr40(value);
  func_020ea744();
}

int func_020f7d14();
int func_020f7de4();
int func_020f7e48();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020d1e94();
/* After 0ea70c, states 1 and 2 suppress the call to 020d1e94(1). */
void Unk0f470c_Unk_0f49f4(Unk0f470cWork *p)
{
    Unk0ea208_Unk_0ea70c();
    switch (p->state) {
    case 1:
    case 2:
        return;
    }
    func_020d1e94(1);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void Unk0e8228_Unk_0e8f50();
void Unk0f470c_Unk_0f4a1c(u8 *p, int a, int b)
{
    if (a != 2) {
        return;
    }
    switch (b) {
    case 1:
    case 5:
    case 6:
        FIELD(u32, p, 80) = 1;
        Unk0e8228_Unk_0e8f50(1);
        return;
    }
    FIELD(u32, p, 80) = 0;
    Unk0e8228_Unk_0e8f50(0);
}

/* decompiler-derived */
void Unk0f470c_Unk_0f4b44(void)
{
  int value;
  value = *data_02176e00;
  Unk0e8228_Unk_0e8b94();
  func_020f7e48(*(u32 *)(value + 4),0,5);
  func_020f7d14(*(u32 *)(value + 4));
  func_020f7de4(*(u32 *)(value + 0x40),0);
}

int func_02044ec4();
int func_020e82c8();
int Unk0e8228_Unk_0e8c80();
int func_020e8d38();
/* decompiler-derived */
void Unk0f470c_Unk_0f4ac0(void)
{
  u32 value1;
  int value2;
  int value3;
  int value4;
  value1 = Unk0f8448_GetUnkField10();
  value4 = *data_02176e00;
  Unk0e8228_Unk_0e8c80();
  value2 = func_02044ec4();
  value1 = Unk0e8228_GetArr40(value1);
  value3 = Unk0e8228_Unk_0e8bac();
  if (value3 != 0) {
    value2 = Unk044904_Unk_045048();
    *(u32 *)(value2 + 0x40) = value1;
    func_020e82c8();
    return;
  }
  value2 = func_020e8d38(value2,value2 + 0x1e8,value1,*(u32 *)(value4 + 0x28));
  if (value2 != 0) {
    Unk0e8228_Unk_0e8d18(0);
  }
  func_020f7e48(*(u32 *)(value4 + 0x40),0,8);
}

/* Forward the field-10 result to 0e8d90 with singleton field +0x44.
 * The original leaves the callee result in r0 for its caller. */
int Unk0f470c_Unk_0f4b80(Unk0f470cWork *arg0)
{
  u32 tmp1;
  tmp1 = Unk0f8448_GetUnkField10(arg0);
  return Unk0e8228_Unk_0e8d90(*(u32 *)(*data_02176e00 + 0x44),tmp1);
}

int Unk0f8448_GetUnkField10();
int Unk0f8448_GetUnkField0();
/* Both accessors receive the embedded object; the trailing state comparison
 * has no visible effect, as in the original instructions at 020f4944.
 * See DEC-008 for why the redundant comparison is retained. */
void func_020f4928(Unk0f470cWork *work)
{
    Unk0f8448_GetUnkField10(work->embedded_0054);
    Unk0f8448_GetUnkField0(work->embedded_0054);
    if (work->state == 1) {
        return;
    }
}
