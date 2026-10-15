/* src/game/unit_02100810.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk100810Work {
    u8 pad_0000[0x1f38];
    u32 unk_1f38;
    u32 unk_1f3c;
    u8 pad_1f40[0x17c];
    u32 unk_20bc;
    u32 unk_20c0;
    u32 unk_20c4;
    u32 unk_20c8;
    u32 unk_20cc;
} Unk100810Work;



int func_020662b8();
/* decompiler-derived */
void Unk100810_Unk_107154(Unk100810Work *arg0, int arg1){
  if (arg1 != 0) {
    arg0->unk_20cc = 1;
    func_020662b8(arg0->unk_1f38);
    func_020662b8(arg0->unk_1f3c,1);
    return;
  }
  arg0->unk_20cc = 0;
  func_020662b8(arg0->unk_1f38);
  func_020662b8(arg0->unk_1f3c,0);
  return;
}

int func_020445f4();
int func_0204fed8();
int func_02061f10();
int func_02063920();
int func_02063a30();
/* decompiler-derived */
void Unk100810_Unk_104f18(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = func_020445f4(0xc);
  func_02063920();
  func_0204fed8(tmp1,arg2);
  func_02063a30();
  func_0204fed8(tmp1,0xcc);
  func_02063a30();
  func_0204fed8(tmp1,0xcd);
  tmp1 = func_02063a30();
  func_02061f10(arg0,0xffffffff,0,0,tmp1);
  return;
}

int func_020537b8();
/* decompiler-derived */
void Unk100810_Unk_1070d8(Unk100810Work *arg0){
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_20bc = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_20c0 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_20c4 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_20c8 = 1;
  }
  return;
}


