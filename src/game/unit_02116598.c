/*
 * unit_02116598: empty callbacks and thin forwarders. Unk116598_Thunk_021177e0 and
 * Unk116598_Unk_1166f4 are called back-to-back from func_0203c320.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_021177e0(void);
void func_02117808(void);
void func_021172fc(void);

/* Empty callbacks (no direct callers; function-table slots). */
void Unk116598_Nop_116b44(void) { }
void Unk116598_Nop_116b68(void) { }
void Unk116598_Nop_116b6c(void) { }
void Unk116598_Nop_117cd0(void) { }

/* Forwarders: pass the caller's arguments straight through. */
void Unk116598_Thunk_021177e0(void) { func_021177e0(); }
void Unk116598_Unk_1166f4(void) { func_02117808(); }
void Unk116598_Unk_116804(void) { func_021172fc(); }
void Unk116598_Unk_117950(void) { func_021177e0(); }



/* forwards to `func_02117808` */
void Unk116598_Thunk_02117808(void) { func_02117808(); }


/* forwards to `func_021172fc` */
void Unk116598_Thunk_021172fc(void) { func_021172fc(); }

extern u32 data_02176e5c[];
/* decompiler-derived */
u32 Unk116598_Get_data_02176e5c(void)
{
  return *data_02176e5c;
}

extern u32 data_02176e68[];
/* decompiler-derived */
u32 Unk116598_Get_data_02176e68(void)
{
  return *data_02176e68;
}

int Unk065e88_Unk_065eac();
int Unk095560_Unk_096130();
int func_020a2414();
/* decompiler-derived */
void Unk116598_Unk_1168b8(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
  func_020a2414();
}

int func_021172dc();
int func_021177cc();
/* decompiler-derived */
void Unk116598_Unk_116954(void)
{
  func_021177cc(0);
  func_021172dc();
}


extern u32 data_02176e60[];
/* decompiler-derived */
void Unk116598_Clear_data_02176e60(void)
{
  *data_02176e60 = 0;
}

extern u32 data_02176e64[];
/* decompiler-derived */
void Unk116598_Clear_data_02176e64(void)
{
  *data_02176e64 = 0;
}


/* decompiler-derived */
void Unk116598_Unk_117ae4(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
  func_020a2414();
}


/* decompiler-derived */
void Unk116598_Unk_117b80(void)
{
  func_021177cc(0);
  func_021172dc();
}


int func_021171c8();
/* decompiler-derived */
u32 func_0211727c(void)
{
  u32 tmp1;
  tmp1 = func_021171c8();
  Unk02f078_Unk_02f20c();
  return tmp1;
}


/* decompiler-derived */
void func_02116700(u32 arg0)
{
  int tmp1;
  tmp1 = Unk116598_Get_data_02176e5c();
  *(u32 *)(tmp1 + 4) = arg0;
  *(u32 *)(tmp1 + 0xc) = 1;
  return;
}

int func_021167e0();
/* decompiler-derived */
void func_0211671c(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e5c();
  *v1 = 1;
  func_021167e0();
  Unk116598_Unk_1168b8();
  return;
}


/* decompiler-derived */
void func_02116810(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e5c();
  *v1 = 2;
  func_021167e0();
  Unk116598_Unk_1168b8();
  return;
}

int func_02065e88();
int func_020773dc();
int func_020a23f4();
/* decompiler-derived */
void func_0211689c(void)
{
  func_020a23f4(2);
  func_02065e88();
  func_020773dc(1);
  return;
}


/* decompiler-derived */
void func_02117968(u32 arg0)
{
  int tmp1;
  tmp1 = Unk116598_Get_data_02176e68();
  *(u32 *)(tmp1 + 4) = arg0;
  *(u32 *)(tmp1 + 0xc) = 1;
  return;
}


int func_02117a28();
/* decompiler-derived */
void func_02117984(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e68();
  *v1 = 1;
  func_02117a28();
  Unk116598_Unk_117ae4();
  return;
}


/* decompiler-derived */
void func_02117ac8(void)
{
  func_020a23f4(2);
  func_02065e88();
  func_020773dc(1);
  return;
}


/* decompiler-derived */
void func_02116738(u32 arg0)
{
  int tmp1;
  tmp1 = Unk116598_Get_data_02176e5c();
  *(u32 *)(tmp1 + 4) = 3;
  *(u32 *)(tmp1 + 8) = arg0;
  *(u32 *)(tmp1 + 0xc) = 1;
  return;
}

int func_0211683c();
int func_02117294();
int func_02117790();
/* decompiler-derived */
void func_02116b48(void)
{
  u32 tmp1;
  func_02117790();
  func_02117294();
  tmp1 = func_0211683c();
  *data_02176e5c = tmp1;
  return;
}


/* decompiler-derived */
int func_021171a8(void)
{
  int tmp1;
  tmp1 = Unk02e000_Unk_02e774();
  return *(char *)(tmp1 + 0x5fc2) == '\x01';
}


/* decompiler-derived */
int func_021171c8(int arg0,int arg1)
{
  if (arg0 == 0) {
    if (arg1 == 5) {
      arg1 = 8;
    }
    return arg1;
  }
  return arg1 + 5;
}


/* decompiler-derived */
int func_021171e8(int arg0,int arg1)
{
  if (arg0 == 0) {
    if (arg1 == 8) {
      arg1 = 5;
    }
    return arg1;
  }
  return arg1 + -5;
}

int func_02061424();
/* decompiler-derived */
void func_021172bc(void)
{
  if (*data_02176e60 != 0) {
    return;
  }
  func_02061424();
  return;
}


int func_02117a68();
/* decompiler-derived */
void func_02117cd4(void)
{
  u32 tmp1;
  func_02117790();
  func_02117294();
  tmp1 = func_02117a68();
  *data_02176e68 = tmp1;
  return;
}
