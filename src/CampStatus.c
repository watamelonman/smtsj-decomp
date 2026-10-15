/*
 * src/CampStatus.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct CampStatusWork {
    u8 unk_0000[0x7494];
    u32 UnkField7494;
} CampStatusWork;




u32 CampStatus_GetUnkField1c(void *obj);
u32 CampStatus_GetUnkField7494(CampStatusWork *work);

/* get u32 at +0x1c */
u32 CampStatus_GetUnkField1c(void *obj) { return FIELD(u32, obj, 0x1c); }

/* decompiler-derived */
u32 CampStatus_GetUnkField7494(CampStatusWork *work)
{
  return work->UnkField7494;
}



/* decompiler-derived */
int CampStatus_Unk_0d34e4(int *arg0,int arg1)
{
  if (arg1 < arg0[7]) {
    return *arg0 + *(int *)(arg0[6] + arg1 * 4) * 2;
  }
  return 0;
}

int func_02061424();
/* decompiler-derived */
void CampStatus_Unk_0d3510(int *arg0)
{
  int value;
  value = *arg0;
  *arg0 = value + 1;
  if (value + 1 < arg0[1]) {
    return;
  }
  arg0[2] = 0;
  func_02061424();
}


extern u8 data_021507f4[];
int func_02013c3c();
int func_02051610();
int func_0205b444();
/* decompiler-derived */
u32 func_020db338(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  func_02013c3c(auStack_48,((int)data_021507f4),arg1);
  tmp1 = func_02051610(auStack_48);
  *(u32 *)(arg0 + 0xc) = tmp1;
  func_0205b444(*(u32 *)(arg0 + 8),*(u32 *)(arg0 + 0xc));
  return 1;
}

extern u8 data_02150824[];
int func_020db37c();
/* decompiler-derived */
u32 func_020db394(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  tmp1 = func_020db37c(arg1);
  func_02013c3c(auStack_48,((int)data_02150824),tmp1);
  tmp1 = func_02051610(auStack_48);
  *(u32 *)(arg0 + 0xc) = tmp1;
  func_0205b444(*(u32 *)(arg0 + 8),*(u32 *)(arg0 + 0xc));
  return 1;
}




/* decompiler-derived */
int func_020dd88c(int arg0,int arg1)
{
  int tmp1;
  tmp1 = arg0;
  if ((arg1 == 2) && (arg0 == 0 || arg0 == 2)) {
    tmp1 = 2;
  }
  if ((arg1 == 5) && ((arg0 == 0 || arg0 == 2) || arg0 == 5)) {
    tmp1 = 5;
  }
  if ((arg1 == 1) && (((arg0 == 0 || arg0 == 2) || arg0 == 5) || arg0 == 1)) {
    tmp1 = 1;
  }
  if ((arg1 == 3) &&
     ((((arg0 == 0 || arg0 == 2) || arg0 == 5) || arg0 == 1) || arg0 == 3)) {
    tmp1 = 3;
  }
  if ((arg1 == 4) && (arg0 != 4)) {
    tmp1 = 4;
  }
  return tmp1;
}


int func_02057fd8();
int func_0205dee8();
/* decompiler-derived */
void func_020ddd2c(u32 arg0,u32 arg1,u32 arg2)
{
  func_0205dee8(2,arg0,0x10,arg1,0,0x3f800000,0x3f800000,0,arg2,2);
  func_02057fd8();
  func_0205dee8(2,arg0,0x11,arg1,0,0x3f800000,0x3f800000,0,arg2,3);
  func_02057fd8();
  func_0205dee8(2,arg0,0x12,arg1,0,0x3f800000,0x3f800000,0,arg2,4);
  return;
}
