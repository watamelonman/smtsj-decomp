/*
 * src/game/unit_020bc1a8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void Unk0bc1a8_Unk_0bc514(int arg0,int arg1,u32 arg2);

int Unk0bc1a8_GetConst0(void);
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1);

/* returns 0 */
int Unk0bc1a8_GetConst0(void) { return 0; }

/* decompiler-derived */
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1)
{
  Unk0bc1a8_Unk_0bc514(arg0,arg1,0);
}


int func_020bc770();
int func_020bc8c8();
/* decompiler-derived */
void Unk0bc1a8_Unk_0bc9b4(u32 arg0,u32 arg1)
{
  int value;
  u8 auStack_50 [72];
  value = func_020bc8c8(auStack_50,arg0,arg1,1);
  if (value != 0) {
    func_020bc770(arg0,auStack_50);
    return;
  }
}

extern u32 data_02176ba8[];
/* decompiler-derived */
u32 Unk0bc1a8_Unk_0bcc34(int arg0)
{
  int value;
  int *v2;
  value = 0;
  v2 = *(int **)*data_02176ba8;
  do {
    if (*v2 == arg0) {
      *v2 = 0;
      return 1;
    }
    value = value + 1;
    v2 = v2 + 3;
  } while (value < 0x29);
  return 0;
}



int func_020bc814();
/* decompiler-derived */
void Unk0bc1a8_Unk_0bc928(int arg0,u32 arg1,u32 arg2,u32 arg3)
{
  int value1;
  int value2;
  u8 auStack_58 [72];
  u32 uStack_10;
  uStack_10 = arg3;
  value1 = func_020bc8c8(auStack_58,arg0,arg2,0);
  if (value1 != 0) {
    func_020bc814(arg0,arg1);
    value1 = arg0 * 0xc;
    value2 = *(int *)*data_02176ba8;
    *(u32 *)(*(int *)(value2 + value1) + 0x24) = *(u32 *)(*(int *)(value2 + value1) + 0x24) | 4;
    *(u32 *)(*(int *)(value2 + value1) + 0x28) =
         *(u32 *)(*(int *)(value2 + value1) + 0x28) & 0xfffffff0;
    *(u32 *)(*(int *)(value2 + value1) + 0x30) = arg1;
    func_020bc770(arg0,auStack_58);
    return;
  }
}

int func_02061424();
int func_020bc5ac();
int func_020bcacc();
/* decompiler-derived */
void Unk0bc1a8_Unk_0bc514(int arg0,int arg1,u32 arg2)
{
  u32 tmp1;
  func_02061424(arg0 + -0x34);
  if (arg1 == 0) {
    return;
  }
  tmp1 = func_020bc5ac(arg0);
  func_020bcacc(tmp1,arg2);
}

/* decompiler-derived */
void Unk0bc1a8_Unk_0bc6d4(u32 arg0)
{
  *(u32 *)(*data_02176ba8 + 4) = arg0;
}

/* decompiler-derived */
u32 Unk0bc1a8_Unk_0bc6e8(void)
{
  return *(u32 *)(*data_02176ba8 + 4);
}
