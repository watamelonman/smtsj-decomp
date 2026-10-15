/* src/game/unit_02113294.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk113294Work {
    u8 pad_0000[0x8];
    u8 unk_0008;
    u8 pad_0009[0x7];
    u32 unk_0010;
    u8 pad_0014[0x8];
    u32 unk_001c;
    u32 unk_0020;
    u8 pad_0024[0x4];
    u32 unk_0028;
    u8 pad_002c[0xa4];
    u32 unk_00d0;
} Unk113294Work;

int func_020a0da4();
/* decompiler-derived */
void Unk113294_Unk_1156c4(u8 *arg0)
{
  func_020a0da4(0xb);
  ((Unk113294Work *)arg0)->unk_00d0 = 0xffffffff;
  ((Unk113294Work *)arg0)->unk_001c = 3;
  *arg0 = 3;
}


/* decompiler-derived */
void Unk113294_Unk_115698(u8 *arg0)
{
  func_020a0da4(0xb);
  ((Unk113294Work *)arg0)->unk_00d0 = 0xffffffff;
  ((Unk113294Work *)arg0)->unk_001c = 2;
  *arg0 = 3;
}



/* get u32 at +0x20 */
u32 Unk113294_GetUnkField20(void *obj) { return ((Unk113294Work *)obj)->unk_0020; }

int func_021150e8();
/* decompiler-derived */
void Unk113294_Unk_115110(void)
{
  func_021150e8(1,0x35);
  return;
}

int func_020655b4();
int func_02065604();
int func_02065bc0();
/* decompiler-derived */
void Unk113294_Unk_1156ec(void)
{
  func_02065bc0();
  func_02065604(1);
  func_020655b4(1);
  return;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void Unk113294_Unk_1150c8(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_020445f4(0x2a,arg0);
  func_0204fed8(tmp1,arg1);
  return;
}


/* decompiler-derived */
void Unk113294_Unk_115124(int arg0)
{
  func_021150e8(((Unk113294Work *)arg0)->unk_0008 + 1,((Unk113294Work *)arg0)->unk_0010 & 0xffff);
  return;
}


int func_021144e4();
int func_02114588();
int func_02114604();
int func_021146a4();
int func_021148ec();
int func_02114a1c();
/* decompiler-derived */
void Unk113294_Unk_114488(char *arg0)
{
  if (*arg0 == '\0') {
    return;
  }
  if (*(int *)(arg0 + -4) != 6) {
    Unk_LoadPalette_020de678(((Unk113294Work *)arg0)->unk_0028);
  }
  func_021144e4(arg0);
  func_02114588(arg0);
  func_02114604(arg0);
  func_021146a4(arg0);
  func_021148ec(arg0);
  func_02114a1c(arg0);
  return;
}


int func_02061e98();
int func_02061f10();
int func_02063920();
int func_02063a30();
/* decompiler-derived */
void Unk113294_Unk_11518c(u32 arg0)
{
  u32 tmp1;
  int tmp2;
  func_02061e98(arg0,0x10,1);
  func_02063920();
  tmp2 = 0;
  do {
    Unk113294_Unk_1150c8(0,tmp2 + 0x66U & 0xffff);
    tmp1 = func_02063a30();
    func_02061f10(arg0,0xffffffff,0,0,tmp1);
    tmp2 = tmp2 + 1;
  } while (tmp2 < 2);
  return;
}


