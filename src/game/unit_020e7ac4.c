/* src/game/unit_020e7ac4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0e7ac4Work {
    u8 pad_0000[0x54];
    s32 unk_0054;
} Unk0e7ac4Work;

void Unk0e7ac4_Nop_0e7b7c(void) { }

extern u32 data_02176cdc[];
int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void Unk0e7ac4_Unk_0e7f0c(int arg0)
{
  func_0205bb68();
  if (((Unk0e7ac4Work *)arg0)->unk_0054 != 0) {
    func_0205ddb4();
    ((Unk0e7ac4Work *)arg0)->unk_0054 = 0;
  }
  *data_02176cdc = 0;
  return;
}

int func_020e7f44();
/* decompiler-derived */
void Unk0e7ac4_Unk_0e8198(void)
{
  int tmp1;
  tmp1 = *data_02176cdc;
  func_020e7f44(*(u32 *)(tmp1 + 0x24),*(u32 *)(tmp1 + 0x28),
                  *(u32 *)(tmp1 + 0x2c),*(u32 *)(tmp1 + 0x30));
}

/* decompiler-derived */
void Unk0e7ac4_Unk_0e8014(u32 arg0)
{
  if (*(int *)(*data_02176cdc + 0x58) != 0) {
    *(u32 *)(*data_02176cdc + 4) = arg0;
  }
}

/* decompiler-derived */
void Unk0e7ac4_Unk_0e8030(u32 arg0)
{
  if (*(int *)(*data_02176cdc + 0x58) != 0) {
    *(u32 *)(*data_02176cdc + 8) = arg0;
  }
}

/* decompiler-derived */
u32 Unk0e7ac4_Unk_0e8060(void)
{
  u32 tmp1;
  if (*data_02176cdc == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = *(u32 *)(*data_02176cdc + 0x58);
  }
  return tmp1;
}

/* decompiler-derived */
void Unk0e7ac4_Unk_0e8000(u32 arg0)
{
  *(u32 *)(*data_02176cdc + 0x50) = arg0;
}

/* decompiler-derived */
void Unk0e7ac4_Unk_0e804c(u32 arg0)
{
  *(u32 *)(*data_02176cdc + 0x58) = arg0;
}
