/*
 * src/game/unit_020bc1a8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020bc514();

int Unk0bc1a8_GetConst0(void);
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1);

/* returns 0 */
int Unk0bc1a8_GetConst0(void) { return 0; }

/* decompiler-derived */
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1)
{
  func_020bc514(arg0,arg1,0);
}


int func_020bc770();
int func_020bc8c8();
/* decompiler-derived */
void func_020bc9b4(u32 arg0,u32 arg1)
{
  int tmp1;
  u8 auStack_50 [72];
  tmp1 = func_020bc8c8(auStack_50,arg0,arg1,1);
  if (tmp1 != 0) {
    func_020bc770(arg0,auStack_50);
    return;
  }
  return;
}

extern u32 data_02176ba8[];
/* decompiler-derived */
u32 func_020bcc34(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = *(int **)*data_02176ba8;
  do {
    if (*v2 == arg0) {
      *v2 = 0;
      return 1;
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 3;
  } while (tmp1 < 0x29);
  return 0;
}
