/* src/CaveArea.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CaveAreaWork {
    u8 pad_0000[0xc8];
    u8 unk_00c8;
    u8 pad_00c9[0x5b];
    s32 unk_0124;
    u8 pad_0128[0x38];
    u32 unk_0160;
} CaveAreaWork;

int func_0205bb68();
/* decompiler-derived */
void CaveArea_Unk_0ed354(void)
{
  func_0205bb68();
  func_0205bb68();
  return;
}


/* decompiler-derived */
void CaveArea_Unk_0ec278(int arg0)
{
  ((CaveAreaWork *)arg0)->unk_00c8 = 2;
  ((CaveAreaWork *)arg0)->unk_0160 = 1;
  return;
}


/* decompiler-derived */
void CaveArea_Unk_0ed3b4(u32 *arg0)
{
  *arg0 = 0;
  arg0[2] = 0;
  arg0[3] = 0x10;
  return;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void CaveArea_Unk_0eda18(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_020445f4(0x25,0);
  func_0204fed8(tmp1,arg0);
  return;
}


/* decompiler-derived */
void CaveArea_Unk_0ed26c(int arg0)
{
  if (((CaveAreaWork *)arg0)->unk_0124 == 0) {
    return;
  }
  func_0205bb68();
  ((CaveAreaWork *)arg0)->unk_0124 = 0;
  return;
}



