/*
 * src/game/unit_020fedd4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Borrowed singleton layout: offsets +0x14 and +0x1c are evidenced by
 * the stores at 0x020feea4 and 0x020fee90 respectively. */
typedef struct Unk0fedd4Obj {
    u32 unk_00;
    u32 handle;                 /* +0x04 */
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 state;                  /* +0x14: 0, 1 or 2 */
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
} Unk0fedd4Obj;

extern Unk0fedd4Obj *data_02176e28;

void Unk05b82c_Unk_05b82c(int id);
void func_0205bb68(void);
Unk0fedd4Obj *Unk0fedd4_GetObj(void);

void Unk0fedd4_Thunk_0205bb68(void);
Unk0fedd4Obj *Unk0fedd4_Thunk_020feef0(void);
void Unk0fedd4_Unk_0fedd4(void);

/* Returns the borrowed singleton, possibly null; the original at 0x020feef0
 * loads data_02176e28 without allocating or changing ownership. */
Unk0fedd4Obj *Unk0fedd4_GetObj(void)
{
    return data_02176e28;
}

/* Tail-forwards to func_0205bb68, as evidenced by the relocation at
 * 0x020fedec; the target supplies all side effects. */
void Unk0fedd4_Thunk_0205bb68(void) { func_0205bb68(); }

/* Returns the same borrowed, possibly null singleton as GetObj; the tail
 * target is evidenced by the relocation at 0x020fef08. */
Unk0fedd4Obj *Unk0fedd4_Thunk_020feef0(void) { return Unk0fedd4_GetObj(); }

void func_02061f10(u32 handle, int a, int b, int c, u32 d);

void Unk0fedd4_Unk_0fee38(u32 arg)
{
    func_02061f10(Unk0fedd4_Thunk_020feef0()->handle, -1, 0, 0, arg);
}

void Unk0fedd4_SetUnk0c10(u32 a, u32 b)
{
    Unk0fedd4Obj *o = Unk0fedd4_Thunk_020feef0();
    o->unk_0c = a;
    o->unk_10 = b;
}

/* Requires an allocated singleton; stores the supplied word at +0x1c
 * (str at 0x020fee90). Its higher-level meaning is unknown. */
void Unk0fedd4_SetUnk1c(u32 a)
{
    Unk0fedd4_Thunk_020feef0()->unk_1c = a;
}

/* Requires an allocated singleton; writes 1 to the state word at +0x14
 * (str at 0x020feea4). The state's higher-level meaning is unknown. */
void Unk0fedd4_SetState1(void)
{
    Unk0fedd4_Thunk_020feef0()->state = 1;
}

/* Requires an allocated singleton; writes 1 to the state word at +0x14
 * (str at 0x020feeb8). The state's higher-level meaning is unknown. */
void Unk0fedd4_SetState1b(void)
{
    Unk0fedd4_Thunk_020feef0()->state = 1;
}

/* Requires an allocated singleton; writes 0 to the state word at +0x14
 * (str at 0x020feecc). The state's higher-level meaning is unknown. */
void Unk0fedd4_SetState0(void)
{
    Unk0fedd4_Thunk_020feef0()->state = 0;
}

void Unk0fedd4_SetState2(void)
{
    Unk0fedd4Obj *o = Unk0fedd4_Thunk_020feef0();
    o->state = 2;
    o->unk_20 = 1;
}

/* Passes fixed id 0xd1 to the 05b82c helper; evidenced by mov r0 at
 * 0x020fedd8 and the target relocation at 0x020fede0. Meaning is unknown. */
void Unk0fedd4_Unk_0fedd4(void)
{
  Unk05b82c_Unk_05b82c(0xd1);
}


int func_02061424();
u32 func_020fef0c();
void Unk0fedd4_Alloc(u32 a)
{
    if (data_02176e28 != 0) {
        return;
    }
    data_02176e28 = (Unk0fedd4Obj *)func_020fef0c(a);
}

/* decompiler-derived */
void Unk0fedd4_Unk_0fee18(void)
{
  if (data_02176e28 == 0) {
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
  data_02176e28 = 0;
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
