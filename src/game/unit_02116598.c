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


int Unk116598_Unk_1171c8();
/* decompiler-derived */
u32 Unk116598_Unk_11727c(void)
{
  u32 value;
  value = Unk116598_Unk_1171c8();
  Unk02f078_Unk_02f20c();
  return value;
}


/* decompiler-derived */
void Unk116598_Unk_116700(u32 arg0)
{
  int value;
  value = Unk116598_Get_data_02176e5c();
  *(u32 *)(value + 4) = arg0;
  *(u32 *)(value + 0xc) = 1;
}

int func_021167e0();
/* decompiler-derived */
void Unk116598_Unk_11671c(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e5c();
  *v1 = 1;
  func_021167e0();
  Unk116598_Unk_1168b8();
}


/* decompiler-derived */
void Unk116598_Unk_116810(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e5c();
  *v1 = 2;
  func_021167e0();
  Unk116598_Unk_1168b8();
}

int func_02065e88();
int func_020773dc();
int func_020a23f4();
/* decompiler-derived */
void Unk116598_Unk_11689c(void)
{
  func_020a23f4(2);
  func_02065e88();
  func_020773dc(1);
}


/* decompiler-derived */
void Unk116598_Unk_117968(u32 arg0)
{
  int value;
  value = Unk116598_Get_data_02176e68();
  *(u32 *)(value + 4) = arg0;
  *(u32 *)(value + 0xc) = 1;
}


int func_02117a28();
/* decompiler-derived */
void Unk116598_Unk_117984(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e68();
  *v1 = 1;
  func_02117a28();
  Unk116598_Unk_117ae4();
}


/* decompiler-derived */
void Unk116598_Unk_117ac8(void)
{
  func_020a23f4(2);
  func_02065e88();
  func_020773dc(1);
}


/* decompiler-derived */
void Unk116598_Unk_116738(u32 arg0)
{
  int value;
  value = Unk116598_Get_data_02176e5c();
  *(u32 *)(value + 4) = 3;
  *(u32 *)(value + 8) = arg0;
  *(u32 *)(value + 0xc) = 1;
}

int func_0211683c();
int func_02117294();
int func_02117790();
/* decompiler-derived */
void Unk116598_Unk_116b48(void)
{
  u32 value;
  func_02117790();
  func_02117294();
  value = func_0211683c();
  *data_02176e5c = value;
}


/* decompiler-derived */
int Unk116598_Unk_1171a8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return *(char *)(value + 0x5fc2) == '\x01';
}


/* decompiler-derived */
int Unk116598_Unk_1171c8(int arg0,int arg1)
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
int Unk116598_Unk_1171e8(int arg0,int arg1)
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
void Unk116598_Unk_1172bc(void)
{
  if (*data_02176e60 != 0) {
    return;
  }
  func_02061424();
}


int func_02117a68();
/* decompiler-derived */
void Unk116598_Unk_117cd4(void)
{
  u32 value;
  func_02117790();
  func_02117294();
  value = func_02117a68();
  *data_02176e68 = value;
}


int func_0202e788();
int func_02116c20();
/* decompiler-derived */
u32 func_02117050(u32 arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_02116c20(*(u16 *)(tmp1 + 0x35c),arg0,arg1,1);
  if (tmp1 == 1) {
    tmp2 = 2;
  }
  return tmp2;
}

int func_02057524();
int func_02057534();
int func_021176c0();
/* decompiler-derived */
void func_02117620(int arg0)
{
  if (*(int *)(arg0 + 0x18) != 0) {
    return;
  }
  if (*(int *)(arg0 + 0xc) != 1 && *(int *)(arg0 + 0xc) != 2) {
    return;
  }
  if (*(int *)(arg0 + 4) == 0) {
    return;
  }
  func_02057524(*(u32 *)(arg0 + 0x14));
  func_021176c0(*(u32 *)(arg0 + 8),*(u8 *)(arg0 + 0x13),0x16);
  func_02057534();
  return;
}


/* decompiler-derived */
void func_02117670(int arg0)
{
  if (*(int *)(arg0 + 0x18) != 0) {
    return;
  }
  if (*(int *)(arg0 + 0xc) != 1 && *(int *)(arg0 + 0xc) != 3) {
    return;
  }
  if (*(int *)(arg0 + 4) == 0) {
    return;
  }
  func_02057524(*(u32 *)(arg0 + 0x14));
  func_021176c0(*(u32 *)(arg0 + 8),*(u8 *)(arg0 + 0x13),0x16);
  func_02057534();
  return;
}



/* decompiler-derived */
u32 func_02117114(void)
{
  int tmp1;
  int tmp2;
  tmp2 = 0;
  do {
    tmp1 = Unk0de678_Unk_0dee2c(tmp2);
    if (tmp1 != 0) {
      tmp1 = Unk02e000_Unk_02e774();
      if (*(char *)(tmp1 + tmp2 + 0x5fba) == '\0') {
        tmp1 = Unk02e000_Unk_02e774();
        *(u8 *)(tmp1 + tmp2 + 0x5fba) = 1;
        return 1;
      }
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 9);
  return 0;
}

int func_02035440();
int func_02044534();
int func_020956e8();
int func_021177b8();
/* decompiler-derived */
void func_02116968(int arg0)
{
  func_021167e0();
  func_020956e8();
  Unk116598_Unk_1168b8();
  if (*(int *)(arg0 + 0x10) != 0) {
    func_02044534(0x1e);
  }
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e5c = 0;
  if (*(int *)(arg0 + 4) == 3) {
    func_02035440(*(u32 *)(arg0 + 8));
  }
  Unk02cad4_Unk_02cbdc(*(u32 *)(arg0 + 4));
  return;
}


/* decompiler-derived */
void func_02117b94(int arg0)
{
  func_02117a28();
  func_020956e8();
  Unk116598_Unk_117ae4();
  if (*(int *)(arg0 + 0x10) != 0) {
    func_02044534(0x1e);
  }
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e68 = 0;
  if (*(int *)(arg0 + 4) == 3) {
    func_02035440(*(u32 *)(arg0 + 8));
  }
  Unk02cad4_Unk_02cbdc(*(u32 *)(arg0 + 4));
  return;
}


