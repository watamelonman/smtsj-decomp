/*
 * src/game/unit_0202d15c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0213d898[];
int Unk095560_GetManagerSub3a8();

u32 Unk02d15c_Unk_02d934(void);
u32 Unk02d15c_Unk_02d944(void);
void Unk02d15c_Unk_02d81c(void);
void Unk02d15c_Unk_02d91c(u32 arg0,u32 arg1);

/* decompiler-derived */
u32 Unk02d15c_Unk_02d934(void)
{
  int value;
  value = Unk095560_GetManagerSub3a8();
  return *(u32 *)(value + 4);
}

/* decompiler-derived */
u32 Unk02d15c_Unk_02d944(void)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  return *v1;
}

/* decompiler-derived */
void Unk02d15c_Unk_02d81c(void)
{
  *data_0213d898 = 0xffffffff;
}

/* decompiler-derived */
void Unk02d15c_Unk_02d91c(u32 arg0,u32 arg1)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  *v1 = arg1;
  v1[1] = arg0;
}



/* decompiler-derived */
u32 func_0202d9a8(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1a;
  case 1:
    return 0x1d;
  case 2:
    return 0x14;
  case 3:
    return 0x17;
  case 4:
    return 0x20;
  default:
    return 0x1a;
  }
}


/* decompiler-derived */
u32 func_0202d9f8(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1b;
  case 1:
    return 0x1e;
  case 2:
    return 0x15;
  case 3:
    return 0x18;
  case 4:
    return 0x21;
  default:
    return 0x1b;
  }
}



/* decompiler-derived */
u32 func_0202da48(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1c;
  case 1:
    return 0x1f;
  case 2:
    return 0x16;
  case 3:
    return 0x19;
  case 4:
    return 0;
  default:
    return 0x1c;
  }
}
