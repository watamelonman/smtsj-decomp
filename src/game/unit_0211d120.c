/* src/game/unit_0211d120.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11d120Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
} Unk11d120Work;

int func_02053000();
extern u32 data_02176e74[];
void func_02008848();
void func_0211d178(u32 x)
{
    *data_02176e74 = x;
    func_02008848(x, 0, 176);
}

/* decompiler-derived */
void Unk11d120_Unk_11d288(int arg0)
{
  func_02053000(((Unk11d120Work *)arg0)->unk_0004);
  ((Unk11d120Work *)arg0)->unk_0004 = 0;
  return;
}

int func_020493e0();
int func_0204faf0();
int func_020655b4();
int func_02065628();
int func_0206569c();
int func_02065b10();
int func_020a1428();
/* decompiler-derived */
void Unk11d120_Unk_11d198(u16 *arg0)
{
  int tmp1;
  func_02065628(1);
  func_020655b4(1);
  if (*(int *)(arg0 + 2) != 0) {
    tmp1 = func_020a1428(*arg0);
    func_0204faf0(6,*arg0);
    func_0204faf0(7,*(u8 *)(tmp1 + 2));
    func_020493e0(8);
    func_0206569c();
    return;
  }
  func_02065b10(1,*arg0);
  return;
}
