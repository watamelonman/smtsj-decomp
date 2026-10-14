/*
 * src/game/unit_020aa118.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk044904_Unk_04509c();
void func_020af8d8(void);

void Unk0aa118_Nop_0ae054(void);
void Unk0aa118_Thunk_020af8d8(void);
void Unk0aa118_Unk_0ab454(void);
int Unk0aa118_Unk_0ab4b8(void);

/* empty callback */
void Unk0aa118_Nop_0ae054(void) { }

/* forwards to `func_020af8d8` */
void Unk0aa118_Thunk_020af8d8(void) { func_020af8d8(); }

/* decompiler-derived */
void Unk0aa118_Unk_0ab454(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  *(u32 *)(value + 0x18) = 0;
}

/* decompiler-derived */
int Unk0aa118_Unk_0ab4b8(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  return *(int *)(value + 0x18) != 0;
}


int func_02008848();
int func_02052fe0();
/* decompiler-derived */
u32 * func_020afb64(u32 arg0)
{
  u32 *v1;
  v1 = (u32 *)func_02052fe0(0x94);
  func_02008848(v1,0,0x94);
  *v1 = arg0;
  return v1;
}


int func_0204fde0();
int func_020af780();
int func_020af7f8();
/* decompiler-derived */
void func_020af824(void)
{
  u8 *v1;
  v1 = (u8 *)func_020af780();
  if (v1 != (u8 *)0x0) {
    func_020af7f8(*v1,v1[1]);
    func_0204fde0();
    return;
  }
  func_020af7f8(0,0);
  func_0204fde0();
  return;
}
