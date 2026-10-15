/*
 * src/game/unit_0206ae94.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk06ae94Work {
    u8 unk_0000[0x34];
    u32 UnkField0034;
    u8 unk_0038[0x4];
    u32 UnkField003c;
    u32 UnkField0040;
} Unk06ae94Work;


extern u32 data_021457e0[];
int func_02052d34();
int func_02052d58();

u32 Unk06ae94_GetUnkField4c(void *obj);
void Unk06ae94_Unk_06c8e0(Unk06ae94Work *work,u32 arg1,u32 arg2);
void Unk06ae94_Unk_06ae94(u32 arg0);
void Unk06ae94_Unk_06aeb4(u32 arg0);

/* get u32 at +0x4c */
u32 Unk06ae94_GetUnkField4c(void *obj) { return FIELD(u32, obj, 0x4c); }

/* decompiler-derived */
void Unk06ae94_Unk_06c8e0(Unk06ae94Work *work,u32 arg1,u32 arg2)
{
  work->UnkField0034 = work->UnkField0034 | 4;
  work->UnkField003c = arg2;
  work->UnkField0040 = arg1;
}

/* decompiler-derived */
void Unk06ae94_Unk_06ae94(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d34();
}

/* decompiler-derived */
void Unk06ae94_Unk_06aeb4(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d58();
}



int func_0206c0b0();
int func_0206d4e8();
int func_02071844();
int func_02071d6c();
/* decompiler-derived */
void func_0206c76c(u32 *arg0)
{
  int tmp1;
  if (arg0 == (u32 *)0x0) {
    return;
  }
  tmp1 = 0;
  if (0 < (int)arg0[3]) {
    do {
      func_0206c0b0(arg0[tmp1 + 0x14]);
      tmp1 = tmp1 + 1;
    } while (tmp1 < (int)arg0[3]);
  }
  tmp1 = 0;
  if (0 < (int)arg0[4]) {
    do {
      func_0206d4e8(arg0[tmp1 + 0x24]);
      tmp1 = tmp1 + 1;
    } while (tmp1 < (int)arg0[4]);
  }
  tmp1 = 0;
  if (0 < (int)arg0[6]) {
    do {
      func_02071d6c(arg0[tmp1 + 0x44]);
      tmp1 = tmp1 + 1;
    } while (tmp1 < (int)arg0[6]);
  }
  tmp1 = 0;
  if (0 < (int)arg0[5]) {
    do {
      func_02071844(arg0[tmp1 + 0x34]);
      tmp1 = tmp1 + 1;
    } while (tmp1 < (int)arg0[5]);
  }
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[6] = 0;
  arg0[5] = 0;
  arg0[7] = 0;
  arg0[1] = 0;
  if ((u32 *)*arg0 != (u32 *)0x0) {
    *(u32 *)*arg0 = 0;
  }
  return;
}

