/* src/game/unit_0209e418.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk09e418_Unk_09e468(void)
{
  int *v1;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  v1[0x1cf3] = 10;
  *(u32 *)(*v1 + 4) = 0;
  v1[0x1cfa] = 5;
}


/* decompiler-derived */
void Unk09e418_Unk_09e418(u16 arg0,u16 arg1,u16 arg2)
{
  int *v1;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  v1[0x1cf3] = 9;
  *(u32 *)(*v1 + 4) = 0;
  *(u16 *)(v1 + 0x1cfd) = arg0;
  *(u16 *)((int)v1 + 0x73f6) = arg1;
  *(u16 *)(v1 + 0x1cfe) = arg2;
  v1[0x1cfa] = 4;
}
