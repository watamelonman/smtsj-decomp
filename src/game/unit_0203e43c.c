/*
 * src/game/unit_0203e43c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_0215e85e[];
int func_0202e788();
int func_0203fa08();
void func_0203fa84(void);
int func_0205410c();

void Unk03e43c_Thunk_0203fa84(void);
int Unk03e43c_Unk_03f2ac(int arg0);
void Unk03e43c_Unk_03fa28(void);
void Unk03e43c_Unk_03f2bc(void);
void Unk03e43c_Unk_03fa3c(char arg0);

/* forwards to `func_0203fa84` */
void Unk03e43c_Thunk_0203fa84(void) { func_0203fa84(); }

/* decompiler-derived */
int Unk03e43c_Unk_03f2ac(int arg0)
{
  return ((int)data_0215e85e) + arg0;
}

/* decompiler-derived */
void Unk03e43c_Unk_03fa28(void)
{
  int value;
  value = func_0202e788();
  func_0203fa08(*(u8 *)(value + 0x360));
}

/* decompiler-derived */
void Unk03e43c_Unk_03f2bc(void)
{
  int value;
  value = func_0205410c();
  *(u8 *)(value + 0x10) = *(u8 *)(value + 0x10) | 2;
}

/* decompiler-derived */
void Unk03e43c_Unk_03fa3c(char arg0)
{
  int value;
  value = func_0202e788();
  *(char *)(value + 0x360) = arg0 * '\n';
}


int func_02020974();
int func_02051610();
int func_020516d0();
/* decompiler-derived */
int Unk03e43c_Unk_03e5a4(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020974(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_020207d0();
/* decompiler-derived */
int Unk03e43c_Unk_03e5dc(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_020207d0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020ac0();
/* decompiler-derived */
int Unk03e43c_Unk_03e614(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020ac0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020a74();
/* decompiler-derived */
int Unk03e43c_Unk_03e64c(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020a74(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

extern u8 data_0215e85c[];
/* decompiler-derived */
void Unk03e43c_Unk_03e794(int arg0,int arg1)
{
  int value1;
  int value2;
  int value3;
  value2 = 0;
  value3 = ((int)data_0215e85c) + arg1 * 0x20;
  do {
    value1 = arg0 + value2;
    value2 = value2 + 2;
    *(u8 *)(value3 + 2) = *(u8 *)(value1 + 0x28);
    *(u8 *)(value3 + 3) = *(u8 *)(value1 + 0x29);
    value3 = value3 + 2;
  } while (value2 < 0x20);
}




int func_02034398();
/* decompiler-derived */
void Unk03e43c_Unk_0434b0(short *arg0,short *arg1)
{
  int value;
  if (0xb0 < *arg0) {
    *arg0 = 0xb0;
  }
  if (0x70 < *arg1) {
    *arg1 = 0x70;
  }
  value = func_02034398();
  if ((int)*arg0 < (int)((*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8)) {
    value = func_02034398();
    *arg0 = (*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8;
  }
  value = func_02034398();
  if ((int)*arg1 < (int)((*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8)) {
    value = func_02034398();
    *arg1 = (*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8;
    return;
  }
}

int func_02056cc0();
/* decompiler-derived */
void func_0203e878(void)
{
  func_02056cc0(1,0,data_0215e85e);
}
