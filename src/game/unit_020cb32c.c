/*
 * src/game/unit_020cb32c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_0205e484(u32 arg0, u32 group);
u32 func_020cb3dc(void);
int Unk0cb32c_Unk_0cb4e4(u32 arg0, u32 arg1);
int Unk0cb32c_Unk_0cb564(u32 arg0, u32 unused);
void Unk122a78_Unk_122a78(void);
void Unk122a78_Unk_122aa0(void);
void Unk1241ec_Unk_1241ec(void);
void Unk1241ec_Unk_124214(void);
void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124258(void);

void Unk0cb32c_Nop_0cba74(void);
void Unk0cb32c_Nop_0cccc0(void);
void Unk0cb32c_Unk_0cb35c(u32 arg0);
void Unk0cb32c_Unk_0cb57c(u32 arg0);
u32 Unk0cb32c_Unk_0cb32c(void);
u32 Unk0cb32c_Unk_0cb344(void);
u32 Unk0cb32c_Unk_0cb54c(void);

/* Original 020cba74 is only BX LR: this callback has no side effects. */
void Unk0cb32c_Nop_0cba74(void) { }

/* Original 020cccc0 is only BX LR: this callback has no side effects. */
void Unk0cb32c_Nop_0cccc0(void) { }

/* Forward arg0 with group 30 to 0205e484; original 020cb35c sets r1 to 30. */
void Unk0cb32c_Unk_0cb35c(u32 arg0)
{
  func_0205e484(arg0,0x1e);
}

/* Forward arg0 to 020cb564; original 020cb57c also clears unused r1. */
void Unk0cb32c_Unk_0cb57c(u32 arg0)
{
  Unk0cb32c_Unk_0cb564(arg0, 0);
}

/* Call 122a78, 124338 and 1241ec in that order, then return 1; evidenced by the three BL instructions at 020cb330..020cb338. */
u32 Unk0cb32c_Unk_0cb32c(void)
{
  Unk122a78_Unk_122a78();
  Unk1241ec_Thunk_02124338();
  Unk1241ec_Unk_1241ec();
  return 1;
}

/* Call 124214, 124258 and 122aa0 in that order, then return 1; evidenced by the three BL instructions at 020cb348..020cb350. */
u32 Unk0cb32c_Unk_0cb344(void)
{
  Unk1241ec_Unk_124214();
  Unk1241ec_Unk_124258();
  Unk122a78_Unk_122aa0();
  return 1;
}

/* Pass only the low byte returned by 020cb3dc to 020cb4e4 with index 0; original 020cb554 masks r0 with 255. */
u32 Unk0cb32c_Unk_0cb54c(void)
{
  u8 value;
  value = func_020cb3dc();
  return Unk0cb32c_Unk_0cb4e4(value,0);
}


int Unk0cb32c_Unk_0cca80(u8 *work);
/* Store the new state after calling 0cca80 on the same borrowed work when
 * state is 2; evidenced by the conditional BL and STR at 020ccac0. */
void Unk0cb32c_Unk_0ccaa8(int *arg0,int arg1)
{
  if (arg1 == 2) {
    Unk0cb32c_Unk_0cca80((u8 *)arg0);
  }
  *arg0 = arg1;
}

void Unk095560_Unk_0956c8(void);
int Unk0de678_Get_data_021508d4(void);
int Unk0bc1a8_Unk_0bc9b4(u32 value, u32 flags);
void Unk0de678_Unk_0de870(void);
/* If the 1508d4 getter returns zero, call 0bc9b4(15, 0) then 0cb344;
 * always call 0de870 and 0956c8 afterward (BL order at 020cba7c..020cbaa0). */
void Unk0cb32c_Unk_0cba78(void)
{
  int value;
  value = Unk0de678_Get_data_021508d4();
  if (value == 0) {
    Unk0bc1a8_Unk_0bc9b4(0xf,0);
    Unk0cb32c_Unk_0cb344();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
}


void func_02122e1c(u32 handle);
void ImageBg_Unk_0e5530(void);
void Unk0fd268_Unk_0fd3ac(void);
/* Release the borrowed handle and clear its slot before the four cleanup calls;
 * evidence: LDR/BL/STR and BL order at 020cb754..020cb788. */
void Unk0cb32c_Unk_0cb754(u32 *arg0)
{
  Unk0bc1a8_Unk_0bc9b4(10,0);
  func_02122e1c(*arg0);
  *arg0 = 0;
  ImageBg_Unk_0e5530();
  Unk0fd268_Unk_0fd3ac();
  Unk0cb32c_Unk_0cb344();
  Unk0de678_Unk_0de870();
}


/* Map selectors 0..4 to 6,8,7,9,5; preserve other unsigned values.
 * Evidence: unsigned jump-table bound and MOV returns at 020cb440. */
u32 Unk0cb32c_Unk_0cb440(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 6;
  case 1:
    return 8;
  case 2:
    return 7;
  case 3:
    return 9;
  case 4:
    return 5;
  default:
    return arg0;
  }
}

void func_02059f70(u32 handle, u32 zero, s32 x, s32 y, void *descriptor, u32 flags, u32 value);
void func_02060dd4(void *descriptor, const u32 *handle, u32 zero, u32 index, u32 value);
/* Build a 16-byte descriptor and submit it with the borrowed handle and coordinates;
 * evidence: stack buffer and two BLs at 020cb488..020cb4e0. */
void Unk0cb32c_Unk_0cb488(u32 *arg0,s32 arg1,s32 arg2,u32 arg3,
                  u32 arg4,u32 arg5)
{
  u8 auStack_24 [16];
  func_02060dd4(auStack_24,arg0,0,arg3,arg4);
  func_02059f70(*arg0,0,arg1,arg2,auStack_24,0,arg5);
}

int func_020445f4(u32 group, u32 index);
int func_0204fed8(int handle, u32 index);
/* Resolve group 30 and arg0, then forward the result and arg1 to 04fed8;
 * constants and call order follow 020cb4e4..020cb500. */
int Unk0cb32c_Unk_0cb4e4(u32 arg0, u32 arg1)
{
    return func_0204fed8(func_020445f4(0x1e, arg0), arg1);
}

int Unk0a0ce4_Unk_0a0da4(u32 value);
void func_02063920(u32 handle);
int func_02063a30(int handle);
void func_02061f10(u32 handle, int index, u32 zero, u32 flags, int value);
int func_0205caa0(u32 value);
int func_0205ca88(u32 value);
int Unk0e651c_Unk_0e666c(u32 index);
int Unk122e1c_Unk_122f88(u32 handle, u32 index, int value);
/* Reset a handle, resolve (b,c), then submit its converted value with index -1;
 * evidence: four ordered BLs and stack fifth argument at 020cb504. */
void Unk0cb32c_Unk_0cb504(u32 a, u32 b, u32 c)
{
    func_02063920(a);
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk0cb32c_Unk_0cb4e4(b, c)));
}

/* Borrow writable work through +0x0c: call 0a0da4(5), set +8 to 4,
 * enter state 13, then store arg1 at +0x0c; original STR/BL order is retained. */
void Unk0cb32c_Unk_0ccac8(u8 *arg0,u32 arg1)
{
  Unk0a0ce4_Unk_0a0da4(5);
  *(u32 *)(arg0 + 8) = 4;
  Unk0cb32c_Unk_0ccaa8((int *)arg0, (int)0xd);
  *(u32 *)(arg0 + 0xc) = arg1;
}

/* Borrowed, word-aligned work prefix used by the two target state helpers.
 * Padding exposes only offsets established by their original LDR/STRs. */
typedef struct Unk0cb32cStateWork {
    s32 state;
    u32 reserved_004;
    u32 field_008;
    u8 reserved_00c[0x88];
    u32 handle_094;
    u8 reserved_098[0x10];
    u32 selector_0a8;
    u8 reserved_0ac[0x2c];
    u32 field_0d8;
} Unk0cb32cStateWork;

void Unk122e1c_Unk_123294(u32 handle);
/* Clear the +0x94 handle through its provider, store the new +0xd8 value,
 * set +8 to 1 and enter state 3; STR/BL evidence at 020ccaf8. */
void Unk0cb32c_Unk_0ccaf8(Unk0cb32cStateWork *arg0,u32 arg1)
{
  Unk122e1c_Unk_123294(arg0->handle_094);
  arg0->field_0d8 = arg1;
  arg0->field_008 = 1;
  Unk0cb32c_Unk_0ccaa8((int *)arg0, (int)3);
}

void func_0205c41c(void);
int func_0205c6ec(u32 value);
/* Call 05c41c then forward arg0 to 05c6ec; 020cb564 preserves arg0 in r4.
 * The wrapper at 020cb57c supplies an unused second register argument. */
int Unk0cb32c_Unk_0cb564(u32 arg0, u32 unused)
{
  func_0205c41c();
  return func_0205c6ec(arg0);
}

/* Return the signed >= comparison of 05caa0(x) and 05ca88(x);
 * original CMP uses MOVGE/MOVLT at 020cb5a8..020cb5b0. */
int Unk0cb32c_Unk_0cb58c(u32 x)
{
    return func_0205caa0(x) >= func_0205ca88(x);
}

/* Test whether provider entry 0x752 is zero (literal and CMP at 020cb7f4..020cb800). */
int Unk0cb32c_Unk_0cb7f0(void)
{
    return Unk0e651c_Unk_0e666c(0x752) == 0;
}

/* Borrow readable work through +0x94; pass that word, zero and provider
 * entry 0x5f1 to 122f88, following LDR/MOV/BL at 020cca88..020cca9c. */
int Unk0cb32c_Unk_0cca80(u8 *p)
{
    return Unk122e1c_Unk_122f88(FIELD(u32, p, 148), 0, Unk0e651c_Unk_0e666c(0x5f1));
}

/* Partial borrowed work view: original 020cccb4 reads only the word at +0x124. */
typedef struct Unk0cb32cWork {
    u8 reserved_000[0x124];
    u32 field_124;
} Unk0cb32cWork;

/* Inspect +0x124 without changing work; original LDR/CMP/BX has no branch or
 * store. Both paths return without changing the work. */
void func_020cccb4(const Unk0cb32cWork *work)
{
    if (work->field_124 != 0) {
        return;
    }
}

u32 Unk095560_Unk_095a2c(u32 value);
int func_020de8b0(int bypass);
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, u32 source);
void func_020bc9f4(u32 slot, u32 source);
/* Forward the current selector, then initialize slots only when de8b0(0)
 * returns zero; evidence: conditional return and BL order at 020cba20. */
void func_020cba20(void)
{
    Unk095560_Unk_095a2c(func_020cb3dc());
    if (func_020de8b0(0) != 0) return;
    Unk0cb32c_Unk_0cb32c();
    Unk0bc1a8_Unk_0bc928(15, 65535, 0);
    Unk0bc1a8_Unk_0bc928(16, 15, 0);
    func_020bc9f4(16, 0);
}

void Unk1241ec_Unk_124224(u32 value);
/* Select a provider mode from the low halfword at +0xa8; selector zero
 * also tests entry 0x5f1. Evidence: shifts, branches and BLs at 020ccc64. */
void func_020ccc64(const Unk0cb32cStateWork *work)
{
    u32 value;
    switch ((u16)work->selector_0a8) {
    case 0: value = Unk0e651c_Unk_0e666c(0x5f1) ? 0 : 3; break;
    case 1: value = 1; break;
    default: value = 2; break;
    }
    Unk1241ec_Unk_124224(value);
}

/* Borrowed descriptor prefix; callback signatures remain opaque because this
 * initializer only stores their addresses and never invokes them. */
typedef struct Unk0cb32cDescriptor {
    u32 size;
    u32 flags;
    u32 reserved_008;
    void (*callbacks[6])(void);
} Unk0cb32cDescriptor;
void func_020cbce4(void);
void func_020cc5d8(void);
void func_020cbc50(void);
void func_020cccc4(void);
/* Fill the descriptor size, flags and six callback addresses, leaving +8 intact;
 * evidence: STR offsets and relocated literals at 020cbaa4..020cbafc. */
void func_020cbaa4(Unk0cb32cDescriptor *descriptor)
{
    descriptor->size = 0x130;
    descriptor->flags = 0;
    descriptor->callbacks[0] = func_020cbce4;
    descriptor->callbacks[1] = func_020cc5d8;
    descriptor->callbacks[2] = (void (*)(void))func_020cccb4;
    descriptor->callbacks[3] = Unk0cb32c_Nop_0cccc0;
    descriptor->callbacks[4] = func_020cbc50;
    descriptor->callbacks[5] = func_020cccc4;
}
