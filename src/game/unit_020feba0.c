/* src/game/unit_020feba0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk0feba0_Unk_0fed7c(u32 *arg0,u32 arg1)
{
  switch(arg1) {
  case 0:
    *arg0 = 0xffffffbe;
    arg0[2] = 0;
    goto switchD_020fed80_default;
  case 1:
    arg0[2] = 0x14;
    goto switchD_020fed80_default;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    goto switchD_020fed80_default;
  }
  *arg0 = 0;
  arg0[5] = 100;
switchD_020fed80_default:
  arg0[3] = arg1;
}


extern u32 data_02176e24[];
/* decompiler-derived */
u32 Unk0feba0_Get_data_02176e24(void)
{
  return *data_02176e24;
}


/* decompiler-derived */
void Unk0feba0_Clear_data_02176e24(void)
{
  *data_02176e24 = 0;
}

int func_02061424();
/* decompiler-derived */
void Unk0feba0_Unk_0febc8(void)
{
  if (*data_02176e24 == 0) {
    return;
  }
  func_02061424();
}

int func_020fec84();
/* decompiler-derived */
void Unk0feba0_Unk_0feba0(void)
{
  int value;
  if (*data_02176e24 != 0) {
    return;
  }
  value = func_020fec84();
  *data_02176e24 = value;
}

/* decompiler-derived */
void Unk0feba0_Unk_0febe8(u32 arg0)
{
  u32 tmp1;
  tmp1 = Unk0feba0_Get_data_02176e24();
  Unk0feba0_Unk_0fed7c((u32 *)tmp1, (u32)arg0);
}

void Unk0feba0_Unk_0fed7c();
void func_020f51dc();
void func_020fec64(u32 *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    Unk0feba0_Unk_0fed7c(p);
}

void func_020fed54(int *p)
{
    if (p[3] == 0) {
        return;
    }
    func_020f51dc(p[0], p[1], p[3], 100 - p[5]);
}
