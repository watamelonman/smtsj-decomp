/* src/game/unit_02039774.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020399f4();
/* decompiler-derived */
void Unk039774_Unk_039b00(u32 arg0)
{
  func_020399f4(arg0,0);
}

int func_020397cc();
int func_02053000();
/* decompiler-derived */
void Unk039774_Unk_039b10(int arg0)
{
  if (*(int *)(arg0 + 0xd8) != 0) {
    func_02053000();
    *(u32 *)(arg0 + 0xd8) = 0;
  }
  if (*(int *)(arg0 + 0xdc) != 0) {
    func_02053000();
    *(u32 *)(arg0 + 0xdc) = 0;
  }
  if (*(int *)(arg0 + 0xd4) != 0) {
    func_02053000();
    *(u32 *)(arg0 + 0xd4) = 0;
  }
  func_020397cc(arg0);
  func_02053000(arg0);
}
