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
void Unk071dc0_Clear();
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
  Unk071dc0_Clear();
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
void Unk071dc0_Clear(void)
{
    func_02008848(data_02170d14, 0, 0x1608);
}

typedef struct Unk071dc0Rec {
    u8 pad_00[24];
} Unk071dc0Rec;
int func_0205b36c();

int Unk071dc0_Unk_071fcc(void)
{
    int i;
    FIELD(s32, data_02171d14, 0x604) = 0;
    for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++) {
        if (func_0205b36c(&((Unk071dc0Rec *)data_02170d14)[i]) == 0) {
            return 1;
        }
    }
    FIELD(s32, data_02171d14, 0x604) = 4;
    return 0;
}

int Unk071dc0_GetMode604Sign(void)
{
    switch (FIELD(s32, data_02171d14, 0x604)) {
    case 4:
        return 1;
    case 5:
        return -1;
    }
    return 0;
}
