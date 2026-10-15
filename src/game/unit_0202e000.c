/*
 * src/game/unit_0202e000.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02140ac8[];
extern u32 data_0215dd24[];
int func_0202e0cc();
void func_0202e788(void);
int func_0205a9d0();

void Unk02e000_Nop_02e3e0(void);
u32 Unk02e000_GetAddr_data_02140ac8(void);
void Unk02e000_Thunk_0202e788(void);
void Unk02e000_Set_data_0215dd24(u32 arg0);
u32 Unk02e000_Get_data_0215dd24(void);
u32 Unk02e000_Unk_02e170(void);
void Unk02e000_Unk_02e0ac(void);
int Unk02e000_Unk_02e774(void);
int Unk02e000_Unk_02e8b8(void);
int Unk02e000_Unk_02e8f0(void);

/* empty callback */
void Unk02e000_Nop_02e3e0(void) { }

/* decompiler-derived */
u32 Unk02e000_GetAddr_data_02140ac8(void)
{
  return ((int)data_02140ac8);
}

/* forwards to `func_0202e788` */
void Unk02e000_Thunk_0202e788(void) { func_0202e788(); }

/* decompiler-derived */
void Unk02e000_Set_data_0215dd24(u32 arg0)
{
  *data_0215dd24 = arg0;
}

/* decompiler-derived */
u32 Unk02e000_Get_data_0215dd24(void)
{
  return *data_0215dd24;
}

/* decompiler-derived */
u32 Unk02e000_Unk_02e170(void)
{
  return *(u32 *)(((int)data_0215dd24) + 4);
}

/* decompiler-derived */
void Unk02e000_Unk_02e0ac(void)
{
  func_0205a9d0(0xa0);
  func_0202e0cc();
}

/* decompiler-derived */
int Unk02e000_Unk_02e774(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x98;
}

/* decompiler-derived */
int Unk02e000_Unk_02e8b8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0xafc;
}

/* decompiler-derived */
int Unk02e000_Unk_02e8f0(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x90;
}


int func_0202e180();
int func_0202e23c();
int func_0202e5a8();
int func_0202e5c4();
/* decompiler-derived */
void Unk02e000_Unk_02e144(void)
{
  int value;
  func_0202e180();
  func_0202e23c();
  func_0202e5a8();
  value = 0;
  do {
    func_0202e5c4(value);
    value = value + 1;
  } while (value < 2);
}



/* decompiler-derived */
int func_0202e75c(int arg0)
{
  return arg0 * 0x48 + *(int *)(((int)data_0215dd24) + 4);
}


/* decompiler-derived */
int func_0202e884(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x65d0;
}


/* decompiler-derived */
int func_0202e89c(int arg0)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x5d26 + arg0 * 4;
}




