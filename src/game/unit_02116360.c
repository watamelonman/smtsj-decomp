/* src/game/unit_02116360.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
/* 8-byte record filled by Unk116360_FillEntry. */
typedef struct Unk116360Entry {
    u16 id;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
} Unk116360Entry;
void Unk116360_FillEntry();
/* decompiler-derived */
void Unk116360_Unk_116404(int arg0,u32 arg1,u32 arg2)
{
  int value;
  if (arg0 == 0) {
    return;
  }
  value = Unk02e000_GetWorkArea();
  Unk116360_FillEntry(arg0,*(u16 *)(value + 0x35c),arg1,arg2);
}

int func_02116360();
/* decompiler-derived */
u32 Unk116360_Unk_116438(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = func_02116360(*(u16 *)(value1 + 0x35c),arg0,arg1);
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}

int Unk03e43c_Unk_03fa28(void);
int func_02035b08(int a, int b);

/* Fills `e` when the (8,6) lookup equals `id` and the position is (36,18). */
void Unk116360_FillEntry(Unk116360Entry *e, int id, int x, int y)
{
    if (e == 0) {
        return;
    }
    if (Unk03e43c_Unk_03fa28() != 0) {
        return;
    }
    if (id != func_02035b08(8, 6) || x != 36 || y != 18) {
        return;
    }
    e->id = id;
    e->unk_02 = 18;
    e->unk_03 = 30;
    e->unk_04 = 0;
}
