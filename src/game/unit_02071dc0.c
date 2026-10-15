/* src/game/unit_02071dc0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0205bb68();
/* decompiler-derived */
void Unk071dc0_Unk_071e08(void)
{
  u32 value;
  value = 0;
  do {
    func_0205bb68();
    value = value + 1;
  } while (value < 9);
}

int Unk05b82c_Unk_05b82c();
void Unk071dc0_Unk_071dc0(void);
/* decompiler-derived */
void Unk071dc0_Unk_071de4(void)
{
  u32 value;
  Unk071dc0_Unk_071dc0();
  value = 0;
  do {
    Unk05b82c_Unk_05b82c(value);
    value = value + 1;
  } while (value < 9);
}

extern u8 data_02171d14[];
void func_02071e24();
/* decompiler-derived */
void Unk071dc0_Unk_072200(void)
{
  int value1;
  int value2;
  value1 = ((int)data_02171d14);
  value2 = 0;
  if (0 < *(int *)(((int)data_02171d14) + 0x600)) {
    do {
      func_0205bb68();
      value2 = value2 + 1;
    } while (value2 < *(int *)(value1 + 0x600));
  }
  func_02071e24();
}

extern u8 data_021458d8[];
extern u8 data_021459b0[];
int func_0205ad2c();
int func_0205ad78();
/* decompiler-derived; refs "Data/Effect/tex/" */
void Unk071dc0_Unk_071dc0(void)
{
  func_0205ad2c(data_021459b0);
  func_0205ad78(data_021458d8,9);
}

extern u8 data_02170d14[];
int func_02008848();
void func_02071e24(void)
{
    func_02008848(data_02170d14, 0, 0x1608);
}

int func_02072030(void)
{
    switch (FIELD(s32, data_02171d14, 0x604)) {
    case 4:
        return 1;
    case 5:
        return -1;
    }
    return 0;
}
