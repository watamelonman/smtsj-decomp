/*
 * src/game/unit_020bcef4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0bcef4Work {
    u8 unk_0000[0x4];
    u32 UnkField0004;
} Unk0bcef4Work;


int func_020bd30c();
int func_020bd49c();
u32 Unk0bcef4_Unk_0bd584(int arg0,u32 arg1);
int Unk0bd5f0_Unk_0bd614();

void Unk0bcef4_Unk_0bd2fc(u32 arg0,u32 arg1);
void Unk0bcef4_Unk_0bd388(u32 arg0,u32 *arg1);
void Unk0bcef4_Unk_0bd470(u32 *arg0);
void Unk0bcef4_Unk_0bd5c4(u32 arg0);
void Unk0bcef4_Unk_0bd3e0(Unk0bcef4Work *work);
void Unk0bcef4_Unk_0bd480(int *arg0,int arg1);

/* decompiler-derived */
void Unk0bcef4_Unk_0bd2fc(u32 arg0,u32 arg1)
{
  func_020bd30c(arg0,arg1,0);
}

/* decompiler-derived */
void Unk0bcef4_Unk_0bd388(u32 arg0,u32 *arg1)
{
  Unk0bcef4_Unk_0bd584(arg0,*arg1);
}

/* decompiler-derived */
void Unk0bcef4_Unk_0bd470(u32 *arg0)
{
  Unk0bd5f0_Unk_0bd614(*arg0);
}

/* decompiler-derived */
void Unk0bcef4_Unk_0bd5c4(u32 arg0)
{
  func_020bd49c(arg0,2);
}

/* decompiler-derived */
void Unk0bcef4_Unk_0bd3e0(Unk0bcef4Work *work)
{
  int value;
  value = work->UnkField0004 + 1;
  work->UnkField0004 = value;
  if (1 < value) {
    work->UnkField0004 = 1;
  }
}

/* decompiler-derived */
void Unk0bcef4_Unk_0bd480(int *arg0,int arg1)
{
  *arg0 = arg1;
  if ((arg1 == 1 || arg1 == 4) || arg1 == 6) {
    arg0[1] = 1;
  }
}



/* decompiler-derived */
void Unk0bcef4_Unk_0bcef4(u32 *arg0,u32 arg1,u32 arg2,u32 arg3)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = arg3;
}

int func_020bd5f0();
/* decompiler-derived */
void Unk0bcef4_Unk_0bd368(int arg0,int arg1)
{
  func_020bd5f0((*(int *)(arg1 + 0x10) - *(int *)(arg1 + 8)) * 0xc + arg0);
}


int func_020bd070();
int func_020bd54c();
/* decompiler-derived */
u32 Unk0bcef4_Unk_0bd29c(int arg0,int *arg1)
{
  int value;
  value = 0;
  if (0 < *arg1) {
    do {
      func_020bd070(arg0,1,0);
      func_020bd54c(arg0,0);
      value = value + 1;
      arg0 = arg0 + 0xc;
    } while (value < *arg1);
  }
  return 1;
}

int func_020bd398();
/* decompiler-derived */
u32 Unk0bcef4_Unk_0bd584(int arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  u32 tmp3;
  tmp2 = 0xffffffff;
  tmp3 = 0;
  if (arg1 != 0) {
    do {
      tmp1 = func_020bd398(arg0);
      if (tmp1 != 0) {
        tmp2 = tmp3;
      }
      tmp3 = tmp3 + 1;
      arg0 = arg0 + 0xc;
    } while (tmp3 < arg1);
  }
  return tmp2;
}
