/* src/game/unit_0203c6a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* returns 1 */
int Unk03c6a4_GetConst1(void) { return 1; }

int func_0203ac00();
int func_0203c748();
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


int func_0203ae10();
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
  value1 = func_0203ae10(value2,value1);
  value3 = func_02065544();
  if (value3 == 0) {
    func_02065bc0();
  }
  func_0206569c(value1);
  *(u32 *)(value2 + 0x18) = 0x1c;
  return 3;
}
