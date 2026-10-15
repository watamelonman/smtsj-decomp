/* src/game/unit_0203c6a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* returns 1 */
int Unk03c6a4_GetConst1(void) { return 1; }

int func_0203ac00();
int func_0203c748();
int Unk03aae8_Unk_03ad14();
void func_02065c30();
static inline void Unk03c6a4_SetSubState(u32 v, u8 *sub)
{
    FIELD(u32, sub, 0x18) = v;
}
int Unk03c6a4_Unk_03c718(void)
{
    if (func_02065544() == 0) {
        return 3;
    }
    func_02065c30();
    Unk03c6a4_SetSubState(4, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

/* decompiler-derived */
void Unk03c6a4_Unk_03c84c(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0203c748(0,(int)v1,0,0,0);
}


/* decompiler-derived */
void Unk03c6a4_Unk_03c878(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0203c748(1,(int)v1,0,0,0);
}


/* decompiler-derived */
void Unk03c6a4_Unk_03c8a4(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0203c748(2,(int)v1,0,0,0);
}


/* decompiler-derived */
void Unk03c6a4_Unk_03c8d0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0203c748(0,(int)v1,1,0,0);
}


/* decompiler-derived */
void Unk03c6a4_Unk_03c8fc(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0203c748(1,(int)v1,1,0,0);
}


/* decompiler-derived */
void Unk03c6a4_Unk_03c928(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0203c748(2,(int)v1,1,0,0);
}


int Unk03aae8_Unk_03ae10();
int func_02065544();
int func_0206569c();
int func_02065bc0();
/* decompiler-derived */
u32 Unk03c6a4_Unk_03c6a4(void)
{
  u32 value1;
  int value2;
  int value3;
  value1 = func_0203ac00(0);
  value2 = Unk03aae8_Unk_03ad14();
  value2 = *(int *)(value2 + 0xe8);
  if (*(int *)(value2 + 0x2c) == 0) {
    Unk03aae8_Nop_03ae0c(value2);
    *(u32 *)(value2 + 0x2c) = 1;
  }
  value1 = Unk03aae8_Unk_03ae10(value2,value1);
  value3 = func_02065544();
  if (value3 == 0) {
    func_02065bc0();
  }
  func_0206569c(value1);
  *(u32 *)(value2 + 0x18) = 0x1c;
  return 3;
}

int func_0203ac00();
int func_0203c748();

int func_0203c954(void)
{
    s16 a = func_0203ac00(0);
    int k = func_0203ac00(1);
    int m;
    m = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        m = 1;
        break;
    case 2:
        m = 2;
        break;
    }
    return func_0203c748(m, a, 0, 0, 0x101);
}

int func_0203c9c0(void)
{
    s16 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    int k = func_0203ac00(2);
    int m;
    func_0203ac00(3);
    m = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        m = 1;
        break;
    case 2:
        m = 2;
        break;
    }
    return func_0203c748(m, a, b, 0, 0);
}
