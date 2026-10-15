/* src/StaffRoll.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct StaffRollWork {
    u8 pad_0000[0x4];
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x9c];
    u32 unk_00ac;
    u8 pad_00b0[0x8];
    u32 unk_00b8;
    u8 pad_00bc[0x24];
    s32 unk_00e0;
} StaffRollWork;

void StaffRoll_Nop_117cf4(void) { }


/* empty callback */
void StaffRoll_Nop_117cf8(void) { }


/* decompiler-derived */
void StaffRoll_Unk_11825c(int arg0)
{
  ((StaffRollWork *)arg0)->unk_0004 = 0;
  ((StaffRollWork *)arg0)->unk_0008 = 0;
  ((StaffRollWork *)arg0)->unk_000c = 0;
  return;
}



/* decompiler-derived */
void StaffRoll_Unk_1182a4(int arg0)
{
  int tmp1;
  int tmp2;
  tmp2 = arg0 + 0xf8;
  tmp1 = 0;
  do {
    if ((*(int *)(tmp2 + 4) == 1) && (*(int *)(tmp2 + 8) + 0x10 < ((StaffRollWork *)arg0)->unk_00e0)) {
      StaffRoll_Unk_11825c(tmp2);
    }
    tmp1 = tmp1 + 1;
    tmp2 = tmp2 + 0x10;
  } while (tmp1 < 0x20);
  return;
}

int func_02117f94();
int func_021180e4();
int func_02118174();
/* decompiler-derived */
u32 StaffRoll_Unk_1181a0(int arg0)
{
  u32 tmp1;
  tmp1 = 0;
  switch(((StaffRollWork *)arg0)->unk_00ac) {
  case 0:
    if (((StaffRollWork *)arg0)->unk_00b8 <= ((StaffRollWork *)arg0)->unk_0008) {
      ((StaffRollWork *)arg0)->unk_00ac = 3;
    }
    break;
  case 1:
    func_02117f94();
    break;
  case 2:
    func_021180e4();
    break;
  case 3:
    func_02118174();
    break;
  case 4:
    tmp1 = 1;
  }
  return tmp1;
}

