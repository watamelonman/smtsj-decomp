/*
 * src/game/unit_020de678.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_021508d4[];
int Unk044394_Unk_044428(u32 value);
int Unk044394_Unk_044534(u32 value);
int Unk0e651c_Unk_0e666c(int value);
void Unk124c5c_Unk_124e04(void);

void Unk0de678_Nop_0df05c(void);
void Unk0de678_Nop_0df060(void);
void Unk0de678_Thunk_02124e04(void);
u32 Unk0de678_Get_data_021508d4(void);
void Unk0de678_Unk_0dea60(void);
void Unk0de678_Unk_0df598(void);
void Unk0de678_Unk_0df5a8(void);
void Unk0de678_Unk_0dee2c(int arg0);

/* Target 0x020df05c is only bx lr; this callback has no side effects. */
void Unk0de678_Nop_0df05c(void) { }

/* Target 0x020df060 is only bx lr; this callback has no side effects. */
void Unk0de678_Nop_0df060(void) { }

/* The literal relocation at 0x020df580 identifies the tail-call target. */
void Unk0de678_Thunk_02124e04(void) { Unk124c5c_Unk_124e04(); }

/* Target 0x020de950 loads the first word at data_021508d4; its meaning is unknown. */
u32 Unk0de678_Get_data_021508d4(void)
{
  return *data_021508d4;
}

/* Target 0x020dea60 tail-calls Unk044394_Unk_044534 with selector 31. */
void Unk0de678_Unk_0dea60(void)
{
  Unk044394_Unk_044534(0x1f);
}

/* Target 0x020df598 tail-calls Unk044394_Unk_044428 with selector 32. */
void Unk0de678_Unk_0df598(void)
{
  Unk044394_Unk_044428(0x20);
}

/* Target 0x020df5a8 tail-calls Unk044394_Unk_044534 with selector 32. */
void Unk0de678_Unk_0df5a8(void)
{
  Unk044394_Unk_044534(0x20);
}

/* Target 0x020dee2c adds 0x5f1 before forwarding to Unk0e651c_Unk_0e666c. */
void Unk0de678_Unk_0dee2c(int arg0)
{
  Unk0e651c_Unk_0e666c(arg0 + 0x5f1);
}



/* At 0x020df584, sets the global word at offset 0x2c to one. */
void Unk0de678_Unk_0df584(void)
{
  *(u32 *)(((int)data_021508d4) + 0x2c) = 1;
}

int func_0205bb68();
int Unk0a23f4_Unk_0a2414();
int Unk0fc584_Unk_0fc6a0();
/* At 0x020df0a4, invokes the observed helper sequence with selector 30. */
void Unk0de678_Unk_0df0a4(void)
{
  Unk0a23f4_Unk_0a2414();
  Unk044394_Unk_044534(0x1e);
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
  Unk044394_Unk_044534(0x1e);
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
int func_020dec18(u32 value);
/* Borrowed 26-byte records; only the halfword at offset 10 is observed. */
typedef struct Unk0de678Rec {
    u8 pad_00[0xa];
    u16 unk_0a;
    u8 pad_0c[0xe];
} Unk0de678Rec;
/* At 0x020dea70, counts up to four leading records with nonzero offset-10 values.
 * The caller supplies four readable records. */
int Unk0de678_CountLeading(Unk0de678Rec *p)
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

/* At 0x020debf8, clears global offset 0xcc when the forwarded query succeeds. */
int Unk0de678_Unk_0debf8(u32 a)
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
  Unk044394_Unk_044428(0x1e);
  Unk0a23f4_Unk_0a23f4(2);
}

int Unk02d15c_Unk_02d8a8();
int Unk02d15c_Unk_02da48();
int func_020cb3dc();
/* decompiler-derived */
u32 Unk0de678_Unk_0dec94(u32 arg0)
{
  u32 value1;
  int value2;
  func_020cb3dc();
  value1 = Unk02d15c_Unk_02da48();
  value2 = Unk02d15c_Unk_02d8a8(1,value1,arg0);
  if (value2 != 0) {
    *(u32 *)(((int)data_021508d4) + 0xcc) = 0;
    return 1;
  }
  return 0;
}

void Unk0bc1a8_Unk_0bc9b4(u32 selector, u32 value);
void func_020df330(u32 value);
void Unk095560_Unk_0958a8();
void Unk0de678_GetPair(u8 *out)
{
    if (FIELD(u32, data_021508d4, 16) != 0) {
        out[0] = FIELD(u32, data_021508d4, 32);
        out[1] = FIELD(u32, data_021508d4, 36);
        return;
    }
    out[0] = 0;
    out[1] = 0;
}

/* At 0x020df348, activates state 3 and stores the supplied word at offset 12. */
void Unk0de678_Unk_0df348(u32 a)
{
    FIELD(u32, data_021508d4, 4) = 1;
    func_020df330(3);
    FIELD(u32, data_021508d4, 12) = a;
}

/* At 0x020df4cc, records a low-byte value and a word, sets offset 16,
 * and resets offset 28. No ownership of external storage is transferred. */
void Unk0de678_Unk_0df4cc(u32 a, u32 b)
{
    FIELD(u32, data_021508d4, 16) = 1;
    FIELD(u8, data_021508d4, 24) = a;
    FIELD(u32, data_021508d4, 20) = b;
    FIELD(u32, data_021508d4, 28) = 0;
}

void Unk0de678_Unk_0df4f0(void)
{
    FIELD(u32, data_021508d4, 32) = 0;
    FIELD(u32, data_021508d4, 36) = 0;
    Unk095560_Unk_0958a8(0, 0);
    FIELD(u32, data_021508d4, 16) = 0;
}

/* At 0x020df330, sets global offset 4 and records the supplied state word. */
void func_020df330(u32 value)
{
    FIELD(u32, data_021508d4, 4) = 1;
    FIELD(u32, data_021508d4, 8) = value;
}

/* At 0x020deedc, calls selector 24 only when global offset 0xc8 is zero,
 * then always forwards selector 9 to the second helper. */
void func_020deedc(void)
{
    if (FIELD(u32, data_021508d4, 0xc8) == 0) {
        Unk0bc1a8_Unk_0bc9b4(24, 0);
    }
    Unk044394_Unk_044534(9);
}
