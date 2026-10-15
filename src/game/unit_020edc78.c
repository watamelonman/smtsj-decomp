/* src/game/unit_020edc78.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0edc78Work {
    u8 pad_0000[0x58];
    u16 unk_0058;
    u8 pad_005a[0x4a];
    u32 unk_00a4;
    u8 pad_00a8[0x73e4];
    u32 unk_748c;
    u32 unk_7490;
} Unk0edc78Work;

int func_020edc78();
/* decompiler-derived */
u32 Unk0edc78_Unk_0ee00c(void)
{
  func_020edc78();
  return 0;
}

int func_02034a68();
int func_02052d7c();
int func_0209a7bc();
int func_020a0da4();
/* decompiler-derived */
void Unk0edc78_Unk_0edf98(int arg0)
{
  int value1;
  int value2;
  value1 = Unk09a268_Unk_09c484(5);
  value2 = func_02034a68();
  Unk09a268_Unk_09a80c(value2,1);
  Unk09a268_Unk_09a830(value2,0);
  func_0209a7bc(value2,*(u8 *)(value1 + 0x19));
  *(u8 *)(value2 + 1) = 1;
  *(u16 *)(value2 + 2) = 0;
  func_020a0da4(((Unk0edc78Work *)arg0)->unk_0058);
  func_02052d7c(arg0 + 0xa8,((Unk0edc78Work *)arg0)->unk_00a4);
  ((Unk0edc78Work *)arg0)->unk_748c = 1;
  ((Unk0edc78Work *)arg0)->unk_7490 = 1;
}
