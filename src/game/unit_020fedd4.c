/*
 * src/game/unit_020fedd4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk05b82c_Unk_05b82c();
void func_0205bb68(void);
void func_020feef0(void);

void Unk0fedd4_Thunk_0205bb68(void);
void Unk0fedd4_Thunk_020feef0(void);
void Unk0fedd4_Unk_0fedd4(void);

/* forwards to `func_0205bb68` */
void Unk0fedd4_Thunk_0205bb68(void) { func_0205bb68(); }

/* forwards to `func_020feef0` */
void Unk0fedd4_Thunk_020feef0(void) { func_020feef0(); }

/* decompiler-derived */
void Unk0fedd4_Unk_0fedd4(void)
{
  Unk05b82c_Unk_05b82c(0xd1);
}


extern u32 data_02176e28[];
int func_02061424();
/* decompiler-derived */
void Unk0fedd4_Unk_0fee18(void)
{
  if (*data_02176e28 == 0) {
    return;
  }
  func_02061424();
}

int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void Unk0fedd4_Unk_0fef78(int *arg0)
{
  if (*arg0 != 0) {
    func_020629c4(arg0[1]);
    arg0[1] = 0;
  }
  if (arg0[2] != 0) {
    func_0205ddb4();
    arg0[2] = 0;
  }
  *data_02176e28 = 0;
}

extern u8 data_021510f4[];
int func_0205dcd4();
int func_020629ac();
/* decompiler-derived */
void Unk0fedd4_Unk_0fefc8(int *arg0,int arg1)
{
  int value;
  *arg0 = arg1;
  arg0[1] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = -1;
  arg0[7] = 0;
  arg0[8] = 0;
  if (*arg0 != 0) {
    value = func_020629ac(5,2,1,1);
    arg0[1] = value;
  }
  value = func_0205dcd4(((int)data_021510f4),1);
  arg0[2] = value;
}
