/* src/game/unit_020939f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0939f0Work {
    u8 pad_0000[0xc];
    u8 unk_000c;
    u8 unk_000d;
    u8 unk_000e;
    u8 pad_000f[0x1d];
    s32 unk_002c;
    s32 unk_0030;
    s32 unk_0034;
    u8 pad_0038[0x4];
    u32 unk_003c;
    u32 unk_0040;
    u32 unk_0044;
    u8 pad_0048[0x4];
    u32 unk_004c;
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0x4];
    u32 unk_005c;
    u32 unk_0060;
    u32 unk_0064;
    u8 pad_0068[0x4];
    u8 unk_006c;
} Unk0939f0Work;

void func_02057678(void);
/* forwards to `func_02057678` */
void Unk0939f0_Thunk_02057678(void) { func_02057678(); }

extern u32 data_02175d8c[];
/* decompiler-derived */
void Unk0939f0_Set_data_02175d8c(u32 arg0)
{
  *data_02175d8c = arg0;
}


/* decompiler-derived */
u32 Unk0939f0_Get_data_02175d8c(void)
{
  return *data_02175d8c;
}

extern u32 data_02175d90[];
void Unk0939f0_Unk_093f0c(int arg0);
void func_02093ae4(u8 *o)
{
    FIELD(u32, o, 0x08) = 0;
    FIELD(u8, o, 0x6c) = 0;
    FIELD(u32, o, 0x68) = 0;
    Unk0939f0_Unk_093f0c((int)o);
}

/* decompiler-derived */
void Unk0939f0_Clear_data_02175d90(void)
{
  *data_02175d90 = 0;
}

int func_02070440();
/* decompiler-derived */
void Unk0939f0_Unk_093dbc(int arg0)
{
  func_02070440(arg0 + 0xc,arg0 + 0x60,arg0 + 0x5c,arg0 + 100,arg0 + 0x2c,
                arg0 + 0x3c,arg0 + 0x4c);
}


int func_0200219c();
/* decompiler-derived */
void Unk0939f0_Unk_093ea8(int arg0)
{
  u32 tmp1;
  if (*data_02175d90 == 0) {
    return;
  }
  tmp1 = func_0200219c(0xff000 - ((Unk0939f0Work *)arg0)->unk_002c,0xd000);
  ((Unk0939f0Work *)arg0)->unk_003c = tmp1;
  tmp1 = func_0200219c(0xff000 - ((Unk0939f0Work *)arg0)->unk_0030,0xd000);
  ((Unk0939f0Work *)arg0)->unk_0040 = tmp1;
  tmp1 = func_0200219c(0xff000 - ((Unk0939f0Work *)arg0)->unk_0034,0xd000);
  ((Unk0939f0Work *)arg0)->unk_0044 = tmp1;
  ((Unk0939f0Work *)arg0)->unk_006c = 4;
  return;
}

int func_020086a0();
/* decompiler-derived */
void Unk0939f0_Unk_093f0c(int arg0)
{
  func_020086a0(0,arg0 + 0xc,0x20);
  ((Unk0939f0Work *)arg0)->unk_000c = 0xff;
  ((Unk0939f0Work *)arg0)->unk_000d = 0xff;
  ((Unk0939f0Work *)arg0)->unk_000e = 0xff;
  ((Unk0939f0Work *)arg0)->unk_002c = 0xff000;
  ((Unk0939f0Work *)arg0)->unk_0030 = 0xff000;
  ((Unk0939f0Work *)arg0)->unk_0034 = 0xff000;
  ((Unk0939f0Work *)arg0)->unk_003c = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0040 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0044 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_004c = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0050 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0054 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0060 = 0;
  ((Unk0939f0Work *)arg0)->unk_005c = 0;
  ((Unk0939f0Work *)arg0)->unk_0064 = 0;
  return;
}

int func_02061424();
/* decompiler-derived */
void Unk0939f0_Unk_093da4(void)
{
  func_02061424(*data_02175d90);
}
