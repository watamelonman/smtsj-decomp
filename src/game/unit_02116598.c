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

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
/* Object passed as first arg; +0x13 is byte3 of unk_0010 (LE). */
typedef struct Unk116598Work {
    u32 unk_0000;
    s32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    u32 unk_0014;
    s32 unk_0018;
} Unk116598Work;
void func_021177e0(void);
void func_02117808(void);
void func_021172fc(void);

void func_02117360(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_02117400(u32 a, u32 b, u32 c, u32 d, u8 e);

void func_021166c0(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117360(a, b, c, d, e);
}

void func_021166d4(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117400(a, b, c, d, e);
}

/* Empty callbacks (no direct callers; function-table slots). */
void Unk116598_Nop_116b44(void) { }
void Unk116598_Nop_116b68(void) { }
void Unk116598_Nop_116b6c(void) { }
void func_02117928(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117360(a, b, c, d, e);
}

void func_0211793c(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117400(a, b, c, d, e);
}

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
int Unk0a23f4_Unk_0a2414();
/* decompiler-derived */
void Unk116598_Unk_1168b8(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
  Unk0a23f4_Unk_0a2414();
}

void Unk116598_Unk_1172dc(void);
void Unk116598_Unk_1177cc(u32 arg0);
/* decompiler-derived */
void Unk116598_Unk_116954(Unk116598Work *work)
{
  Unk116598_Unk_1177cc(0);
  Unk116598_Unk_1172dc();
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
  Unk0a23f4_Unk_0a2414();
}


/* decompiler-derived */
void Unk116598_Unk_117b80(Unk116598Work *work)
{
  Unk116598_Unk_1177cc(0);
  Unk116598_Unk_1172dc();
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

void Unk116598_Unk_1167e0(void);
/* decompiler-derived */
void Unk116598_Unk_11671c(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e5c();
  *v1 = 1;
  Unk116598_Unk_1167e0();
  Unk116598_Unk_1168b8();
}


/* decompiler-derived */
void Unk116598_Unk_116810(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e5c();
  *v1 = 2;
  Unk116598_Unk_1167e0();
  Unk116598_Unk_1168b8();
}

int Unk065e88_Unk_065e88();
int func_020773dc();
int Unk0a23f4_Unk_0a23f4();
/* decompiler-derived */
void Unk116598_Unk_11689c(void)
{
  Unk0a23f4_Unk_0a23f4(2);
  Unk065e88_Unk_065e88();
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


void Unk116598_Unk_117a28(void);
/* decompiler-derived */
void Unk116598_Unk_117984(void)
{
  u32 *v1;
  v1 = (u32 *)Unk116598_Get_data_02176e68();
  *v1 = 1;
  Unk116598_Unk_117a28();
  Unk116598_Unk_117ae4();
}


/* decompiler-derived */
void Unk116598_Unk_117ac8(void)
{
  Unk0a23f4_Unk_0a23f4(2);
  Unk065e88_Unk_065e88();
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
void Unk116598_Unk_117294(void);
void Unk116598_Unk_117790(void);
/* decompiler-derived */
void Unk116598_Unk_116b48(void)
{
  u32 value;
  Unk116598_Unk_117790();
  Unk116598_Unk_117294();
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
  Unk116598_Unk_117790();
  Unk116598_Unk_117294();
  value = func_02117a68();
  *data_02176e68 = value;
}


int Unk02e000_GetWorkArea();
int func_02116c20();
/* decompiler-derived */
u32 Unk116598_Unk_117050(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = func_02116c20(*(u16 *)(value1 + 0x35c),arg0,arg1,1);
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}

int func_02057524();
int func_02057534();
int func_021176c0();
/* decompiler-derived */
void Unk116598_Unk_117620(Unk116598Work *work)
{
  if (work->unk_0018 != 0) {
    return;
  }
  if (work->unk_000c != 1 && work->unk_000c != 2) {
    return;
  }
  if (work->unk_0004 == 0) {
    return;
  }
  func_02057524(work->unk_0014);
  func_021176c0(work->unk_0008,((u8 *)&work->unk_0010)[3],0x16);
  func_02057534();
}


/* decompiler-derived */
void Unk116598_Unk_117670(Unk116598Work *work)
{
  if (work->unk_0018 != 0) {
    return;
  }
  if (work->unk_000c != 1 && work->unk_000c != 3) {
    return;
  }
  if (work->unk_0004 == 0) {
    return;
  }
  func_02057524(work->unk_0014);
  func_021176c0(work->unk_0008,((u8 *)&work->unk_0010)[3],0x16);
  func_02057534();
}



/* decompiler-derived */
u32 Unk116598_Unk_117114(void)
{
  int value1;
  int value2;
  value2 = 0;
  do {
    value1 = Unk0de678_Unk_0dee2c(value2);
    if (value1 != 0) {
      value1 = Unk02e000_Unk_02e774();
      if (*(char *)(value1 + value2 + 0x5fba) == '\0') {
        value1 = Unk02e000_Unk_02e774();
        *(u8 *)(value1 + value2 + 0x5fba) = 1;
        return 1;
      }
    }
    value2 = value2 + 1;
  } while (value2 < 9);
  return 0;
}

int Unk02f2a8_Unk_035440();
int func_02044534();
int Unk095560_Unk_0956e8();
int func_021177b8();
/* decompiler-derived */
void Unk116598_Unk_116968(int arg0)
{
  Unk116598_Unk_1167e0();
  Unk095560_Unk_0956e8();
  Unk116598_Unk_1168b8();
  if (((Unk116598Work *)arg0)->unk_0010 != 0) {
    func_02044534(0x1e);
  }
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e5c = 0;
  if (((Unk116598Work *)arg0)->unk_0004 == 3) {
    Unk02f2a8_Unk_035440(((Unk116598Work *)arg0)->unk_0008);
  }
  Unk02cad4_Unk_02cbdc(((Unk116598Work *)arg0)->unk_0004);
}


/* decompiler-derived */
void Unk116598_Unk_117b94(int arg0)
{
  Unk116598_Unk_117a28();
  Unk095560_Unk_0956e8();
  Unk116598_Unk_117ae4();
  if (((Unk116598Work *)arg0)->unk_0010 != 0) {
    func_02044534(0x1e);
  }
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e68 = 0;
  if (((Unk116598Work *)arg0)->unk_0004 == 3) {
    Unk02f2a8_Unk_035440(((Unk116598Work *)arg0)->unk_0008);
  }
  Unk02cad4_Unk_02cbdc(((Unk116598Work *)arg0)->unk_0004);
}

/* decompiler-derived */
void Unk116598_Unk_1177cc(u32 arg0)
{
  *(u32 *)*data_02176e64 = arg0;
}

int func_02117550();
/* decompiler-derived */
void Unk116598_Unk_1172dc(void)
{
  if (*data_02176e60 == 0) {
    return;
  }
  func_02117550();
}

int func_020bc650();
/* decompiler-derived */
void Unk116598_Unk_1167e0(void)
{
  int tmp1;
  tmp1 = func_020bc650(0x18);
  if (tmp1 != 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc9b4(0x18,0);
}

/* decompiler-derived */
void Unk116598_Unk_117a28(void)
{
  int tmp1;
  tmp1 = func_020bc650(0x18);
  if (tmp1 != 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc9b4(0x18,0);
}

int func_021174d0();
/* decompiler-derived */
void Unk116598_Unk_117294(void)
{
  int tmp1;
  if (*data_02176e60 != 0) {
    return;
  }
  tmp1 = func_021174d0();
  *data_02176e60 = tmp1;
}

int func_021178c0();
/* decompiler-derived */
void Unk116598_Unk_117790(void)
{
  int tmp1;
  if (*data_02176e64 != 0) {
    return;
  }
  tmp1 = func_021178c0();
  *data_02176e64 = tmp1;
}

/* decompiler-derived */
void Unk116598_Unk_1174a0(void)
{
  *(u32 *)(*data_02176e60 + 0x18) = 1;
}

/* decompiler-derived */
void Unk116598_Unk_1174b8(void)
{
  *(u32 *)(*data_02176e60 + 0x18) = 0;
}

void func_02077314(void);
int func_020443e4(int id);
s32 func_02044428(int id);
int func_02095b28(int id);
void Unk02d15c_Unk_02d91c(int a, int b);
void func_0202d86c(int a, int b, int c, int d);
void func_02095f94(void);

void Unk116598_Unk_1168cc(Unk116598Work *work)
{
    func_02077314();
    Unk116598_Unk_11689c();
    if (func_020443e4(30) == 0) {
        work->unk_0010 = func_02044428(30);
    }
    if (func_02095b28(1) == 0) {
        return;
    }
    Unk02d15c_Unk_02d91c(8, 1);
    func_0202d86c(8, 41, 0, -1);
    func_02095f94();
    work->unk_0000 = 0;
    work->unk_0004 = 3;
    work->unk_0008 = 1;
    work->unk_000c = 0;
    Unk116598_Unk_116954(work);
}

void Unk116598_Unk_117af8(Unk116598Work *work)
{
    func_02077314();
    Unk116598_Unk_117ac8();
    if (func_020443e4(30) == 0) {
        work->unk_0010 = func_02044428(30);
    }
    if (func_02095b28(2) == 0) {
        return;
    }
    Unk02d15c_Unk_02d91c(8, 2);
    func_0202d86c(8, 42, 0, -1);
    func_02095f94();
    work->unk_0000 = 0;
    work->unk_0004 = 13;
    work->unk_0008 = 1;
    work->unk_000c = 0;
    Unk116598_Unk_117b80(work);
}
