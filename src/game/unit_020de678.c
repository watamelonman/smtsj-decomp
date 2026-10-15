/*
 * src/game/unit_020de678.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_021508d4[];
int func_02044428();
int func_02044534();
int Unk0e651c_Unk_0e666c();
void func_02124e04(void);

void Unk0de678_Nop_0df05c(void);
void Unk0de678_Nop_0df060(void);
void Unk0de678_Thunk_02124e04(void);
u32 Unk0de678_Get_data_021508d4(void);
void Unk0de678_Unk_0dea60(void);
void Unk0de678_Unk_0df598(void);
void Unk0de678_Unk_0df5a8(void);
void Unk0de678_Unk_0dee2c(int arg0);

/* empty callback */
void Unk0de678_Nop_0df05c(void) { }

/* empty callback */
void Unk0de678_Nop_0df060(void) { }

/* forwards to `func_02124e04` */
void Unk0de678_Thunk_02124e04(void) { func_02124e04(); }

/* decompiler-derived */
u32 Unk0de678_Get_data_021508d4(void)
{
  return *data_021508d4;
}

/* decompiler-derived */
void Unk0de678_Unk_0dea60(void)
{
  func_02044534(0x1f);
}

/* decompiler-derived */
void Unk0de678_Unk_0df598(void)
{
  func_02044428(0x20);
}

/* decompiler-derived */
void Unk0de678_Unk_0df5a8(void)
{
  func_02044534(0x20);
}

/* decompiler-derived */
void Unk0de678_Unk_0dee2c(int arg0)
{
  Unk0e651c_Unk_0e666c(arg0 + 0x5f1);
}



/* decompiler-derived */
void Unk0de678_Unk_0df584(void)
{
  *(u32 *)(((int)data_021508d4) + 0x2c) = 1;
}

int func_0205bb68();
int Unk0a23f4_Unk_0a2414();
int Unk0fc584_Unk_0fc6a0();
/* decompiler-derived */
void Unk0de678_Unk_0df0a4(void)
{
  Unk0a23f4_Unk_0a2414();
  func_02044534(0x1e);
  Unk065e88_Unk_065eac();
  Unk0de678_Unk_0df5a8();
  Unk0fc584_Unk_0fc6a0();
  func_0205bb68();
  Unk095560_Unk_096130();
}


int Unk124c5c_Unk_124d54();
/* decompiler-derived */
void Unk0de678_Unk_0de870(void)
{
  if (*(int *)(((int)data_021508d4) + 200) != 0) {
    return;
  }
  Unk0a23f4_Unk_0a2414();
  func_02044534(0x1e);
  Unk124c5c_Unk_124d54();
  Unk065e88_Unk_065eac();
  Unk0de678_Unk_0df5a8();
  Unk0fc584_Unk_0fc6a0();
  func_0205bb68();
  Unk095560_Unk_096130();
}

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
int Unk065e88_Unk_065e88();
int Unk0964f8_Unk_096508();
int Unk0a23f4_Unk_0a23f4();
int Unk0fc584_Unk_0fc674();
int Unk0fc584_Unk_0fc84c();
int func_020dec18();
typedef struct Unk0de678Rec {
    u8 pad_00[0xa];
    u16 unk_0a;
    u8 pad_0c[0xe];
} Unk0de678Rec;
int func_020dea70(Unk0de678Rec *p)
{
    int n = 0;
    int i = 0;
    for (; i < 4; i++) {
        if (p[i].unk_0a == 0) {
            break;
        }
        n++;
    }
    return n;
}

int func_020debf8(u32 a)
{
    int r = func_020dec18(a);
    if (r != 0) {
        *(u32 *)(((int)data_021508d4) + 0xcc) = 0;
    }
    return r;
}

/* decompiler-derived */
void Unk0de678_Unk_0df064(void)
{
  Unk0964f8_Unk_096508();
  Unk0de678_Unk_0df598();
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xc2);
  Unk0fc584_Unk_0fc674(1);
  Unk0fc584_Unk_0fc84c(0);
  Unk065e88_Unk_065e88();
  func_02044428(0x1e);
  Unk0a23f4_Unk_0a23f4(2);
}

int func_0202d8a8();
int Unk02d15c_Unk_02da48();
int func_020cb3dc();
/* decompiler-derived */
u32 Unk0de678_Unk_0dec94(u32 arg0)
{
  u32 value1;
  int value2;
  func_020cb3dc();
  value1 = Unk02d15c_Unk_02da48();
  value2 = func_0202d8a8(1,value1,arg0);
  if (value2 != 0) {
    *(u32 *)(((int)data_021508d4) + 0xcc) = 0;
    return 1;
  }
  return 0;
}


