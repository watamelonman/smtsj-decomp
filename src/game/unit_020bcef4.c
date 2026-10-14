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
int func_020bd584();
int func_020bd614();

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
  func_020bd584(arg0,*arg1);
}

/* decompiler-derived */
void Unk0bcef4_Unk_0bd470(u32 *arg0)
{
  func_020bd614(*arg0);
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
