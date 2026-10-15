/*
 * src/CampStatus.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CampStatusWork {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x8];
    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0xde];
    s16 unk_00fe;
    u8 pad_0100[0xc];
    s16 unk_010c;
    u8 pad_010e[0x2];
    u32 unk_0110;
    u8 pad_0114[0x7380];
    u32 unk_7494;
} CampStatusWork;

u32 CampStatus_GetUnkField1c(void *obj);
u32 CampStatus_GetUnkField7494(CampStatusWork *work);

/* get u32 at +0x1c */
u32 CampStatus_GetUnkField1c(void *obj) { return ((CampStatusWork *)obj)->unk_001c; }

/* decompiler-derived */
u32 CampStatus_GetUnkField7494(CampStatusWork *work)
{
  return work->unk_7494;
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
u32 CampStatus_Unk_0db338(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  func_02013c3c(auStack_48,((int)data_021507f4),arg1);
  tmp1 = func_02051610(auStack_48);
  ((CampStatusWork *)arg0)->unk_000c = tmp1;
  func_0205b444(((CampStatusWork *)arg0)->unk_0008,((CampStatusWork *)arg0)->unk_000c);
  return 1;
}

extern u8 data_02150824[];
int func_020db37c();
/* decompiler-derived */
u32 CampStatus_Unk_0db394(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  tmp1 = func_020db37c(arg1);
  func_02013c3c(auStack_48,((int)data_02150824),tmp1);
  tmp1 = func_02051610(auStack_48);
  ((CampStatusWork *)arg0)->unk_000c = tmp1;
  func_0205b444(((CampStatusWork *)arg0)->unk_0008,((CampStatusWork *)arg0)->unk_000c);
  return 1;
}




/* decompiler-derived */
int CampStatus_Unk_0dd88c(int arg0,int arg1)
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
void CampStatus_Unk_0ddd2c(u32 arg0,u32 arg1,u32 arg2)
{
  func_0205dee8(2,arg0,0x10,arg1,0,0x3f800000,0x3f800000,0,arg2,2);
  func_02057fd8();
  func_0205dee8(2,arg0,0x11,arg1,0,0x3f800000,0x3f800000,0,arg2,3);
  func_02057fd8();
  func_0205dee8(2,arg0,0x12,arg1,0,0x3f800000,0x3f800000,0,arg2,4);
  return;
}

int func_02057df8();
int func_02057e18();
/* decompiler-derived */
void CampStatus_Unk_0d71bc(int arg0)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2b,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2c,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2d,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);
  func_02057e18(0x1f);
  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2e,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2f,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,0x3f800000,3);
}

/* decompiler-derived */
void CampStatus_Unk_0d7680(int arg0)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,5,(int)((CampStatusWork *)arg0)->unk_00fe,0,0x3f800000,
                0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x41,(int)((CampStatusWork *)arg0)->unk_00fe,0,0x3f800000,
                0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,3);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x22,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x23,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x24,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x25,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x26,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x27,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x21,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);
  func_02057e18(0x1f);
}
