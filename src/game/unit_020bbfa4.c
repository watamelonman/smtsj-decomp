/* src/game/unit_020bbfa4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020a0d68();
/* decompiler-derived */
void func_020bc0a4(int arg0)
{
  func_020a0d68(arg0 + 6);
  return;
}

int func_0203ac00();
int func_02118e50();
/* decompiler-derived */
u32 func_020bbfa4(void)
{
  u32 tmp1;
  tmp1 = func_0203ac00(0);
  func_02118e50(0xc,tmp1);
  return 1;
}


/* decompiler-derived */
u32 func_020bbfc4(void)
{
  u32 tmp1;
  tmp1 = func_0203ac00(0);
  func_02118e50(0xd,tmp1);
  return 1;
}


/* decompiler-derived */
u32 func_020bbfe4(void)
{
  u32 tmp1;
  tmp1 = func_0203ac00(0);
  func_02118e50(0xe,tmp1);
  return 1;
}


/* decompiler-derived */
u32 func_020bc004(void)
{
  u32 tmp1;
  tmp1 = func_0203ac00(0);
  func_02118e50(0xf,tmp1);
  return 1;
}

int func_0203acf4();
/* decompiler-derived */
u32 func_020bc024(void)
{
  int tmp1;
  tmp1 = Unk118b04_Unk_118e74(0xc);
  if (tmp1 < 0) {
    tmp1 = 0;
  }
  func_0203acf4(tmp1);
  return 1;
}


/* decompiler-derived */
u32 func_020bc044(void)
{
  int tmp1;
  tmp1 = Unk118b04_Unk_118e74(0xd);
  if (tmp1 < 0) {
    tmp1 = 0;
  }
  func_0203acf4(tmp1);
  return 1;
}


/* decompiler-derived */
u32 func_020bc064(void)
{
  int tmp1;
  tmp1 = Unk118b04_Unk_118e74(0xe);
  if (tmp1 < 0) {
    tmp1 = 0;
  }
  func_0203acf4(tmp1);
  return 1;
}



/* decompiler-derived */
u32 func_020bc084(void)
{
  int tmp1;
  tmp1 = Unk118b04_Unk_118e74(0xf);
  if (tmp1 < 0) {
    tmp1 = 0;
  }
  func_0203acf4(tmp1);
  return 1;
}

int func_02045048();
int func_02053000();
/* decompiler-derived */
void func_020bc144(void)
{
  int tmp1;
  tmp1 = func_02045048();
  *(u32 *)(tmp1 + 0x58) = 0xf;
  func_02053000(*(u32 *)(tmp1 + 0x5c));
  *(u32 *)(tmp1 + 0x5c) = 0;
  func_02053000(*(u32 *)(tmp1 + 0x60));
  *(u32 *)(tmp1 + 0x60) = 0;
  return;
}
