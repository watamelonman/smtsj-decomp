/* src/CaveArea.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CaveAreaWork {
    u8 pad_0000[0x7c];
    u32 unk_007c;
    u32 unk_0080;
    u8 pad_0084[0x24];
    u8 unk_00a8;
    u8 pad_00a9[0x13];
    s32 unk_00bc;
    u8 pad_00c0[0x8];
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


extern u8 data_02150d6c[];
u32 func_0205ba98();
void CaveArea_AllocBuf(u8 *p)
{
    FIELD(u32, p, 128) = func_0205ba98(0x4000, 0x200, data_02150d6c, 0x5a1);
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

extern u8 data_02150d78[];
extern u8 data_02150d94[];
extern u8 data_02150dac[];
int func_02013c3c();
int func_0205ae60();
int func_0205b398();
void CaveArea_AllocBuf();
/* Loads Cave/Area/cave_area0%d (or cave_privatearmy) layout (medium). */
void CaveArea_LoadAreaLayout(int arg0)
{
  int tmp1;
  u8 auStack_48 [64];
  tmp1 = ((CaveAreaWork *)arg0)->unk_00bc;
  if (((CaveAreaWork *)arg0)->unk_00a8 == '\0') {
    if (tmp1 == 5) {
      func_02013c3c(auStack_48,data_02150d78);
    }
    else {
      func_02013c3c(auStack_48,data_02150d94,tmp1 + 1);
    }
  }
  else {
    func_02013c3c(auStack_48,data_02150dac,tmp1 + 6);
  }
  CaveArea_AllocBuf(arg0);
  *(u8 **)(arg0 + 0x6c) = auStack_48;
  ((CaveAreaWork *)arg0)->unk_007c = 0;
  func_0205ae60(arg0 + 0x68);
  func_0205b398(((CaveAreaWork *)arg0)->unk_0080,arg0 + 0x68);
  ((CaveAreaWork *)arg0)->unk_0124 = 1;
}
