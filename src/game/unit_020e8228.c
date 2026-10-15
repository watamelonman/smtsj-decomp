/*
 * src/game/unit_020e8228.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02150c30[];
extern u32 data_02176cdc[];
extern u32 data_02176ce0[];
void func_02045c38(void);
int func_02057524();
void func_02057534(void);
int func_02057eb8();
int func_02061424();
int func_02099d14();
int ScanVisor_Unk_0a29a0();
int func_020e8374();
int func_020e849c();
void Unk0e8228_Unk_0e8d90(u32 arg0,u32 arg1);
void Unk0e8228_Unk_0e8e8c(u32 arg0);
int func_020e9c00();
int func_020ea5e4();
int Unk0ea208_Get_data_02176ddc();

void Unk0e8228_Nop_0e93d4(void);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Thunk_02045c38(void);
void Unk0e8228_Unk_0e8cd8(void);
void Unk0e8228_Unk_0e8e50(void);
void Unk0e8228_Unk_0e8e6c(void);
void Unk0e8228_Unk_0e8e7c(void);
void Unk0e8228_Unk_0e8eac(int arg0);
u32 Unk0e8228_Get_data_02176ce0(void);
void Unk0e8228_Unk_0e8398(void);
int Unk0e8228_Unk_0e8460(void);
int Unk0e8228_Unk_0e8474(void);
int Unk0e8228_Unk_0e8488(void);
void Unk0e8228_Unk_0e9c94(u32 arg0,u32 arg1);
u32 Unk0e8228_Unk_0e84e4(void);
void Unk0e8228_Unk_0e84fc(void);
u16 Unk0e8228_Unk_0e8514(void);
void Unk0e8228_Unk_0e8b7c(void);
void Unk0e8228_Unk_0e8b94(void);
u32 Unk0e8228_Unk_0e8bac(void);
void Unk0e8228_Unk_0e8c50(u32 arg0);
u32 Unk0e8228_Unk_0e8c68(void);
void Unk0e8228_Unk_0e8db8(void);
u32 Unk0e8228_Unk_0e8f20(void);
u32 Unk0e8228_Unk_0e8f38(void);
void Unk0e8228_Unk_0e8f50(u32 arg0);
void Unk0e8228_Unk_0e9020(u32 arg0);
int Unk0e8228_Unk_0e9048(int *arg0,int *arg1);
void Unk0e8228_Unk_0ea028(void);
u32 Unk0e8228_Unk_0ea040(void);
int Unk0e8228_IsSet_data_02176cdc(void);

/* empty callback */
void Unk0e8228_Nop_0e93d4(void) { }

/* forwards to `func_02057534` */
void Unk0e8228_Thunk_02057534(void) { func_02057534(); }

/* forwards to `func_02045c38` */
void Unk0e8228_Thunk_02045c38(void) { func_02045c38(); }

/* decompiler-derived */
void Unk0e8228_Unk_0e8cd8(void)
{
  ScanVisor_Unk_0a29a0(0xffffffff);
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8e50(void)
{
  func_02057524(4);
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8e6c(void)
{
  func_02057eb8(2);
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8e7c(void)
{
  func_02057eb8(0xffffffff);
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8eac(int arg0)
{
  Unk0e8228_Unk_0e8e8c(arg0 + 8);
}

/* decompiler-derived */
u32 Unk0e8228_Get_data_02176ce0(void)
{
  return *data_02176ce0;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8398(void)
{
  Unk0e8228_Unk_0e8d90(7,0xffffffff);
}

/* decompiler-derived */
int Unk0e8228_Unk_0e8460(void)
{
  return *(int *)(((int)data_02150c30) + 0x2c) + 1;
}

/* decompiler-derived */
int Unk0e8228_Unk_0e8474(void)
{
  return *(int *)(((int)data_02150c30) + 0x34) + 1;
}

/* decompiler-derived */
int Unk0e8228_Unk_0e8488(void)
{
  return *(int *)(((int)data_02150c30) + 0x3c) + 1;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e9c94(u32 arg0,u32 arg1)
{
  func_020e9c00(arg0,2,arg1);
}

/* decompiler-derived */
u32 Unk0e8228_Unk_0e84e4(void)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x178);
  }
  return value2;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e84fc(void)
{
  func_020e8374(8);
  func_020e849c();
  func_02099d14();
}

/* decompiler-derived */
u16 Unk0e8228_Unk_0e8514(void)
{
  u16 value1;
  int value2;
  value2 = func_020ea5e4();
  if (value2 == 0) {
    value1 = 0;
  }
  else {
    value1 = *(u16 *)(value2 + 0x20);
  }
  return value1;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8b7c(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value != 0) {
    *(u32 *)(value + 0x18) = 1;
  }
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8b94(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value != 0) {
    *(u32 *)(value + 0x18) = 0;
  }
}

/* decompiler-derived */
u32 Unk0e8228_Unk_0e8bac(void)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x18);
  }
  return value2;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8c50(u32 arg0)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value != 0) {
    *(u32 *)(value + 0x24) = arg0;
  }
}

/* decompiler-derived */
u32 Unk0e8228_Unk_0e8c68(void)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x24);
  }
  return value2;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8db8(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value != 0) {
    *(u32 *)(value + 0x184) = 1;
  }
}

/* decompiler-derived */
u32 Unk0e8228_Unk_0e8f20(void)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 == 0) {
    value2 = 0x1b;
  }
  else {
    value2 = *(u32 *)(value1 + 0x180);
  }
  return value2;
}

/* decompiler-derived */
u32 Unk0e8228_Unk_0e8f38(void)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x17c);
  }
  return value2;
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8f50(u32 arg0)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value != 0) {
    *(u32 *)(value + 0x28) = arg0;
  }
}

/* decompiler-derived */
void Unk0e8228_Unk_0e9020(u32 arg0)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value != 0) {
    *(u32 *)(value + 0x10) = arg0;
  }
}

/* decompiler-derived */
int Unk0e8228_Unk_0e9048(int *arg0,int *arg1)
{
  return (u32)*(u8 *)(*arg0 + 0x2e) - (u32)*(u8 *)(*arg1 + 0x2e);
}

/* decompiler-derived */
void Unk0e8228_Unk_0ea028(void)
{
  int value;
  value = Unk0ea208_Get_data_02176ddc();
  if (value == 0) {
    return;
  }
  func_02061424();
}

/* decompiler-derived */
u32 Unk0e8228_Unk_0ea040(void)
{
  int value1;
  u32 value2;
  value1 = Unk0ea208_Get_data_02176ddc();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x1cc);
  }
  return value2;
}

/* decompiler-derived */
int Unk0e8228_IsSet_data_02176cdc(void)
{
  return *data_02176cdc != 0;
}



/* decompiler-derived */
int Unk0e8228_Unk_0e82ac(void)
{
  int value;
  value = Unk02e000_Unk_02e8f0();
  return *(char *)(value + 3) == '\0';
}

int func_020e942c();
/* decompiler-derived */
void Unk0e8228_Unk_0e8684(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return;
  }
  func_020e942c(value,*(u32 *)(value + 0x10));
}


/* decompiler-derived */
void Unk0e8228_Unk_0e8cbc(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return;
  }
  ScanVisor_Unk_0a29a0(*(u32 *)(value + 8));
}

int func_02044ec4();
int func_0204a244();
int func_020e8c80();
/* decompiler-derived */
int Unk0e8228_Unk_0e8c9c(void)
{
  int value;
  func_020e8c80();
  func_02044ec4();
  value = func_0204a244();
  return value == 6;
}

int func_020e9778();
/* decompiler-derived */
void Unk0e8228_Unk_0e8d18(u32 arg0)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return;
  }
  func_020e9778(value,arg0);
}

int Unk0feba0_Unk_0febc8();
/* decompiler-derived */
void Unk0e8228_Unk_0e940c(void)
{
  Unk0e8228_Unk_0ea028();
  Unk0feba0_Unk_0febc8();
  *data_02176ce0 = 0;
}


int func_020e8628();
int func_020ea0ec();
int func_020ea160();
/* decompiler-derived */
void Unk0e8228_Unk_0e9728(void)
{
  int value;
  value = func_020e8628();
  if (value == 1) {
    func_020ea0ec();
    return;
  }
  func_020ea160();
}


/* decompiler-derived */
void Unk0e8228_Unk_0e9f18(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
}


/* decompiler-derived */
void Unk0e8228_Unk_0e9f38(u32 *arg0,u32 arg1)
{
  *arg0 = arg1;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
}

int func_020e83ac();
int func_020e8ce8();
/* decompiler-derived */
int Unk0e8228_Unk_0e8bc4(void)
{
  int value;
  func_020e83ac(0);
  func_02044ec4();
  value = func_020e8ce8();
  return value != 0;
}


/* decompiler-derived */
void Unk0e8228_Unk_0e8c2c(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return;
  }
  *(u32 *)(value + 0x1c) = 1;
  *(u32 *)(value + 0x20) = 0xb4;
}


int func_020e9900();
/* decompiler-derived */
u32 Unk0e8228_Unk_0e8dd0(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 != 0) {
    value2 = func_020e9900(arg0,value1,arg1);
    return value2;
  }
  return 0;
}

int func_020e9aa0();
/* decompiler-derived */
u32 Unk0e8228_Unk_0e8dfc(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 != 0) {
    value2 = func_020e9aa0(arg0,value1,arg1);
    return value2;
  }
  return 0;
}

int func_02008848();
int func_020e9060();
/* decompiler-derived */
void Unk0e8228_Unk_0e9fa4(u32 arg0)
{
  func_02008848(arg0,0,0x1cc);
  *data_02176ce0 = arg0;
  func_020e9060(arg0);
}



int func_020459fc();
int func_02053800();
int func_020e82c8();
int func_020e85a0();
int func_020fda58();
int Unk100208_Unk_100208();
/* decompiler-derived */
u32 Unk0e8228_Unk_0e85c8(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return 0;
  }
  value = func_020e85a0(value);
  if ((value != 0) && (value = func_02053800(0,0x400), value != 0)) {
    func_020459fc();
    Unk0e8228_Unk_0e8cd8();
    func_020e82c8();
    func_020fda58(2);
    Unk100208_Unk_100208(7);
    return 1;
  }
  return 0;
}

extern u8 data_02176ce4[];
/* decompiler-derived */
void Unk0e8228_Call_02008848(void)
{
  func_02008848(data_02176ce4,0,0xf8);
}

/* decompiler-derived */
void Unk0e8228_Unk_0e8e8c(u32 arg0)
{
  int tmp1;
  tmp1 = Unk0e8228_Get_data_02176ce0();
  if (tmp1 != 0) {
    *(u32 *)(tmp1 + 0x17c) = 0;
    *(u32 *)(tmp1 + 0x180) = arg0;
  }
}

int func_020e9de4();
/* decompiler-derived */
void Unk0e8228_Unk_0e8d90(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = Unk0e8228_Get_data_02176ce0();
  if (tmp1 == 0) {
    return;
  }
  func_020e9de4(tmp1,arg0,arg1);
}
