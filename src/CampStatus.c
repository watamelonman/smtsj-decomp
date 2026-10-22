/*
 * src/CampStatus.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


typedef float f32;

/* Reached through two pointers from CampStatusWork.unk_002c. */
typedef struct CampStatusLink {
    u8 pad_0000[0x14];
    u32 unk_0014;
} CampStatusLink;

/* Animation/scale block at CampStatusWork.unk_0094. */
typedef struct CampStatusAnim {
    u8 pad_0000[0x20];
    f32 scale;                  /* +0x20: reset to 1.0 */
    u8 pad_0024[0x4];
    s32 unk_0028;               /* +0x28: reset to -1 */
} CampStatusAnim;

/* Camp status work; the first argument here and also *data_02176be4. */
typedef struct CampStatusWork {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x8];
    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0xc];
    CampStatusLink **unk_002c;
    u8 pad_0030[0x64];
    CampStatusAnim *unk_0094;
    u8 pad_0098[0x5c];
    u32 unk_00f4;
    u32 unk_00f8;
    u8 pad_00fc[0x2];
    s16 unk_00fe;
    u8 pad_0100[0xc];
    s16 unk_010c;
    u8 pad_010e[0x2];
    u32 unk_0110;
    u8 pad_0114[0x94];
    u32 unk_01a8;
    u8 pad_01ac[0x94];
    u8 unk_0240;
    u8 unk_0241;
    u8 pad_0242[0xe];
    u32 unk_0250;               /* +0x250: written to 1 by func_020dcb44 */
    u8 pad_0254[0x4];
    u32 unk_0258;
    u8 pad_025c[0x4];
    u32 unk_0260;
    u8 pad_0264[0x7230];
    u32 unk_7494;
} CampStatusWork;

extern CampStatusWork *data_02176be4;

u32 CampStatus_GetUnkField1c(CampStatusWork *work);
u32 CampStatus_GetUnkField7494(CampStatusWork *work);

/* Read the unidentified work word at +0x1c; no caller evidence for a better name. */
u32 CampStatus_GetUnkField1c(CampStatusWork *work) { return work->unk_001c; }

/* Read the 49-byte table at data_0213c60c; an out-of-range index reads entry 0. */
extern u8 data_0213c60c[49];

int CampStatus_GetTableByte(u32 i)
{
    if (i >= 49) {
        i = 0;
    }
    return data_0213c60c[i];
}

/* Read the cached word at +0x7494 (shape only; purpose not evidenced). */
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
void Unk05b82c_Unk_05b82c();
void func_020ca5a4();
void func_020119a0();
void CampStatus_Unk_0d51cc(void)
{
    int i;
    for (i = 59; i <= 64; i++) {
        Unk05b82c_Unk_05b82c(i);
    }
    func_020ca5a4(0);
    func_020ca5a4(2);
}

void CampStatus_Copy12c(void *src)
{
    func_020119a0((u8 *)data_02176be4 + 300, src, 60);
}

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
int CampStatus_GetTableByte();
/* decompiler-derived */
u32 CampStatus_Unk_0db394(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  tmp1 = CampStatus_GetTableByte(arg1);
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

int CampStatus_IsUnkF4F8Set(void)
{
    CampStatusWork *w = data_02176be4;
    return w->unk_00f4 != 0 && w->unk_00f8 != 0;
}

/* Read the unidentified word at +0x1a8 in the shared work. */
u32 CampStatus_GetUnk1a8(void)
{
    return data_02176be4->unk_01a8;
}

/* Write the unidentified word at +0x1a8 in the shared work. */
void CampStatus_SetUnk1a8(u32 value)
{
    data_02176be4->unk_01a8 = value;
}

/* Read the unidentified word at +0x258 in the shared work. */
u32 CampStatus_GetUnk258(void)
{
    return data_02176be4->unk_0258;
}

/* Raise the mode flag at +0x260; see CampStatus_ResetAnim for the clear. */
void CampStatus_SetUnk260(void)
{
    data_02176be4->unk_0260 = 1;
}

void CampStatus_ResetAnim(void)
{
    data_02176be4->unk_0260 = 0;
    data_02176be4->unk_0094->unk_0028 = -1;
    data_02176be4->unk_0094->scale = 1.0f;
}

void CampStatus_SetUnk240(u8 a, u8 b)
{
    data_02176be4->unk_0240 = a;
    data_02176be4->unk_0241 = b;
}

void CampStatus_GetLinkUnk14(u32 *out)
{
    *out = (*data_02176be4->unk_002c)->unk_0014;
}

void CampStatus_Unk_0dcaac(void)
{
    FIELD(u32, data_02176be4, 244) = 0;
    FIELD(s16, data_02176be4, 270) = -80;
}

void CampStatus_Unk_0dd308(s32 *v, s32 add, int n, s32 *cnt, float *out)
{
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            v[i] += add;
        }
    }
    if (*cnt >= 10) {
        return;
    }
    (*cnt)++;
    *out = *cnt / 10.0f;
}

/* Set the unidentified flag at +0x250; neutral name kept from symbols.txt. */
void func_020dcb44(void)
{
    data_02176be4->unk_0250 = 1;
}
