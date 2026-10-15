/* src/game/unit_0202cad4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk065e88_Unk_065eac();
/* decompiler-derived */
void Unk02cad4_Thunk_Unk065e88_Unk_065eac(void)
{
  Unk065e88_Unk_065eac();
}

void func_0206148c(void);
/* forwards to `func_0206148c` */
void Unk02cad4_Thunk_0206148c(void) { func_0206148c(); }

/* Three-word block at 0x0213d338; reset to -1 by func_0202cbc0. */
typedef struct Unk02cad4Globals {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk02cad4Globals;

extern Unk02cad4Globals data_0213d338;

void func_0202cbc0(void)
{
    Unk02cad4Globals *g = &data_0213d338;
    g->unk_00 = -1;
    g->unk_04 = -1;
    g->unk_08 = -1;
}

u32 func_0202cbec(void)
{
    return data_0213d338.unk_00;
}

void Unk02cad4_Unk_02cbdc(u32 arg0)
{
    data_0213d338.unk_08 = arg0;
}

int Unk065e88_Unk_065e88();
int func_020e13ac();
/* decompiler-derived */
void Unk02cad4_Unk_02ce80(void)
{
  Unk065e88_Unk_065e88();
  func_020e13ac(0);
}

int Unk02e000_Unk_02e75c();
/* decompiler-derived */
void Unk02cad4_Unk_02ce94(void)
{
  int value1;
  int value2;
  u32 value3;
  value1 = Unk0e1648_Unk_0e1648();
  if (value1 == 0) {
    return;
  }
  value3 = 0;
  value1 = 0;
  do {
    value2 = Unk02e000_Unk_02e75c(value1);
    value1 = value1 + 1;
    if (value3 < *(u32 *)(value2 + 0x38)) {
      value3 = *(u32 *)(value2 + 0x38);
    }
  } while (value1 < 2);
  Unk02e000_Set_data_0215dd24(value3);
  Unk02cad4_Unk_02cbdc(1);
}

