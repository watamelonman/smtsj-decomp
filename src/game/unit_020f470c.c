/* Borrowed work views and callbacks reconstructed from ARM data accesses. */
#include "types.h"

int Unk0f8448_GetUnkField10(void *object);
int Unk0e8228_Unk_0e8bac(void);
void Unk0e8228_Unk_0e8b94(void);
int Unk044904_Unk_045048(void);
void Unk0e8228_Unk_0e8d18(int value);
int Unk0e8228_Unk_0e8d90(u32 value, u32 field);


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
void func_020f4790(Unk0f470cWork *work);
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
/* Field-10 selects an array entry unless the work flag requests 0ea828. */
void Unk0f470c_Unk_0f4958(Unk0f470cWork *arg0)
{
  u32 value;
  value = Unk0f8448_GetUnkField10(arg0->embedded_0054);
  Unk0ea208_Unk_0ea70c();
  if (arg0->unk_0050 != 0) {
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

void Unk0e8228_Unk_0e8f50();
/* Event 2 sets the work flag for values 1, 5 and 6 and publishes that flag. */
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

/* Singleton fields +4 and +0x40 select objects for the three update calls. */
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
/* The borrowed embedded object selects an array entry; 0e8bac selects its destination. */
void Unk0f470c_Unk_0f4ac0(void *object)
{
  u32 value1;
  int value2;
  int value3;
  int value4;
  value1 = Unk0f8448_GetUnkField10(object);
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

void func_020f4878(Unk0f470cWork *work);
/* Descriptor words and callback addresses are evidenced by stores at 020f470c.
 * The caller owns the descriptor; word +8 is deliberately untouched. */
void func_020f470c(u32 *descriptor)
{
    descriptor[0] = 0xf8;
    descriptor[1] = 3;
    descriptor[3] = (u32)func_020f4878;
    descriptor[4] = (u32)Unk0f470c_Unk_0f4908;
    descriptor[5] = (u32)func_020f4928;
    descriptor[6] = 0;
    descriptor[7] = (u32)Unk0f470c_Nop_0f4874;
    descriptor[8] = (u32)Unk0f470c_Thunk_020f7248;
}

int Unk0e8228_Unk_0e82ac(void);
int Unk0e8228_Unk_0e8374(u32 value);
void Unk0f8448_Init(void *object, int value);
/* Initialize the embedded object from work +0x44 when enabled, reset the flag,
 * then submit the resource selected by work +0x28 with sentinel -1. */
void func_020f4994(Unk0f470cWork *work)
{
    if (Unk0e8228_Unk_0e82ac()) {
        Unk0f8448_Init(work->embedded_0054,
                      Unk0e8228_Unk_0e8374(FIELD(u32, work, 0x44)));
    } else {
        Unk0f8448_Init(work->embedded_0054, 0);
    }
    work->unk_0050 = 0;
    Unk0e8228_Unk_0e8f50(0);
    FIELD(u32, work, 0xc) = 9;
    Unk0d1c98_Unk_0d1d94(func_020ea630(FIELD(u32, work, 0x28)), -1);
}

int func_0204a244(int object);
/* With 0e8bac enabled, reject states 1, 2, 7 and 11 from 0204a244.
 * The first callback argument is unused in the original. */
int func_020f4a60(void *unused, int index)
{
    int state;
    if (!Unk0e8228_Unk_0e8bac()) return 1;
    Unk0e8228_GetArr40(index);
    state = func_0204a244(func_02044ec4());
    switch (state) {
    case 1: case 2: case 7: case 11: return 0;
    }
    return 1;
}

int func_02053824(int channel, int mask);
void Unk0f8448_Thunk_020bcc7c(void *object);
void Unk0f8448_Thunk_020bccec(void *object);
/* When the singleton flag is clear, input masks 32 and 16 invoke opposite
 * object callbacks and refresh the singleton. Mask 16 takes return precedence. */
int func_020f4ba4(void *object)
{
    int result;
    Unk0f470cWork *work;
    work = (Unk0f470cWork *)*data_02176e00;
    result = 0;
    if (work->unk_0050 == 0) {
        if (func_02053824(0, 32)) {
            Unk0f8448_Thunk_020bcc7c(object);
            Unk0f470c_Unk_0f4958(work);
            result = -1;
        }
        if (func_02053824(0, 16)) {
            Unk0f8448_Thunk_020bccec(object);
            Unk0f470c_Unk_0f4958(work);
            result = 1;
        }
    }
    return result;
}

void func_020f711c(Unk0f470cWork *work, u32 handle, s32 x, s32 y,
                    s32 a, s32 b, u32 c, u32 d, u32 first, u32 second, u32 third);
int Unk0e8228_Unk_0e8460(void);
void func_020f81cc(void *object, int a, int b, int c, int d, int e,
                    u32 first, u32 second, u32 third, u32 fourth);
void Unk0f81a4_SetUnkField98(void *object, u32 callback);
void Unk0f81a4_SetUnkField9c(void *object, u32 callback);

/* Stores at 020f479c establish defaults and callback arguments; initialize the
 * borrowed work and its embedded object without assigning game semantics. */
void func_020f4790(Unk0f470cWork *work)
{
    int value;
    FIELD(u32, work, 0x40) = 30;
    FIELD(u32, work, 0x44) = 5;
    FIELD(u32, work, 0x48) = 0;
    FIELD(u32, work, 0x4c) = 0;
    func_020f711c(work, FIELD(u32, work, 0x40), -128, 0, 128, -128, 0, 0,
                 (u32)func_020f4994, (u32)Unk0f470c_Unk_0f49f4,
                 (u32)Unk0f470c_Unk_0f4a1c);
    value = Unk0e8228_Unk_0e8460();
    func_020f81cc(work->embedded_0054, value, value, 0, 1, 0,
                 (u32)func_020f4a60, (u32)Unk0f470c_Unk_0f4ac0,
                 (u32)Unk0f470c_Unk_0f4b44, (u32)Unk0f470c_Unk_0f4b80);
    Unk0f81a4_SetUnkField98(work->embedded_0054, (u32)func_020f4ba4);
    Unk0f81a4_SetUnkField9c(work->embedded_0054, (u32)Unk0f470c_Unk_0f4c20);
}

void func_020f7188(Unk0f470cWork *work);
void Unk0bc1a8_Unk_0bc9b4(u32 handle, int value);
void func_020f8264(void *object);
/* The jump table at 020f4894 handles states 11, 9 and 2; the caller owns
 * work, whose state changes from 9 to 10 and from 2 to 1. */
void func_020f4878(Unk0f470cWork *work)
{
    func_020f7188(work);
    switch (work->state) {
    case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8: case 10:
        break;
    case 11:
        Unk0bc1a8_Unk_0bc9b4(FIELD(u32, work, 0x40), 0);
        break;
    case 9:
        Unk0f470c_Unk_0f4958(work);
        func_020f8264(work->embedded_0054);
        work->state = 10;
        break;
    case 2:
        func_020f7de4(FIELD(u32, work, 0x40), 2);
        work->state = 1;
        break;
    }
}
