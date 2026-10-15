/* src/game/unit_0212449c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02044534();
int func_0205bb68();
int func_0205c368();
int func_0205c3dc();
int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void Unk12449c_Unk_12449c(int *arg0)
{
  u32 value1;
  int value2;
  func_020629c4(arg0[6]);
  value2 = 0;
  do {
    if (arg0[value2 + 2] != 0) {
      func_0205c3dc();
      arg0[value2 + 2] = 0;
    }
    value2 = value2 + 1;
  } while (value2 < 4);
  if (arg0[1] != 0) {
    func_0205c368();
    arg0[1] = 0;
  }
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  value1 = 0;
  do {
    func_0205bb68();
    value1 = value1 + 1;
  } while (value1 < 4);
  if (arg0[9] == 0) {
    return;
  }
  func_02044534(0x1e);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_021245bc();
void Unk12449c_Unk_124590(u8 *p)
{
    if (FIELD(u32, p, 60) == 0) {
        return;
    }
    FIELD(u32, p, 40) = 0;
    func_021245bc(p);
    FIELD(u32, p, 40) = 1;
}
