/*
 * src/game/unit_020a163c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020445f4();
int func_0204fed8();
void func_020a208c(void);

void Unk0a163c_Thunk_020a208c(void);
int Unk0a163c_Unk_0a1718(u16 *arg0,u16 *arg1);
void Unk0a163c_Unk_0a1814(u32 arg0);
void Unk0a163c_Unk_0a1834(u32 arg0);

/* forwards to `func_020a208c` */
void Unk0a163c_Thunk_020a208c(void) { func_020a208c(); }

/* decompiler-derived */
int Unk0a163c_Unk_0a1718(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
void Unk0a163c_Unk_0a1814(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x12,1);
  func_0204fed8(value,arg0);
}

/* decompiler-derived */
void Unk0a163c_Unk_0a1834(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x12,0);
  func_0204fed8(value,arg0);
}


int func_02053000();
int func_020a1a24();
/* decompiler-derived */
u32 func_020a1ae0(u32 *arg0)
{
  func_020a1a24();
  func_02053000(arg0[1]);
  arg0[1] = 0;
  *arg0 = 0;
  return 1;
}

