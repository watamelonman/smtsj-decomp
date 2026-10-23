/*
 * src/game/unit_020bac80.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02ee5c_GetTierFromField70(void);
int Unk03aae8_Unk_03acf4();
void *Unk03aae8_Unk_03ad14(void);
void *Unk044904_Get_data_0215ee98(void);
void func_02044ec4(void);
void func_0204fdac(u32 handle, u32 value);

void Unk0bac80_Thunk_02044ec4(void);
u32 Unk0bac80_Unk_0badc0(void);
u32 Unk0bac80_Unk_0bae08(void);
int Unk0bac80_Unk_0bae18(void);
u32 Unk0bac80_Unk_0bae50(void);
u32 Unk0bac80_Unk_0bb298(void);
void Unk0bac80_Unk_0badd0(u32 arg0);
void Unk0bac80_Unk_0badec(u32 arg0);

/* Borrowed views: offsets come from the loads in 020badc0..020bae18.
 * Gaps describe only the accessed prefix; ownership stays with the providers. */
typedef struct Unk0bac80Context {
    u8 pad_0000[0xe8];
    u32 work_address;
} Unk0bac80Context;

typedef struct Unk0bac80Work {
    u8 pad_0000[0x40];
    u32 unk_0040;
    u8 pad_0044[0x10];
    u32 unk_0054;
    u8 pad_0058[8];
    u32 unk_0060;
    u8 pad_0064[4];
    u32 unk_0068;
} Unk0bac80Work;

/* The original LDR ip / BX ip thunk names 02044ec4 as its sole target. */
void Unk0bac80_Thunk_02044ec4(void) { func_02044ec4(); }

/* Return the borrowed work address stored at context +0xe8 (020badc0 LDR). */
u32 Unk0bac80_Unk_0badc0(void)
{
    Unk0bac80Context *context = Unk03aae8_Unk_03ad14();
    return context->work_address;
}

/* Read the opaque word at work +0x68; the provider must supply valid work. */
u32 Unk0bac80_Unk_0bae08(void)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    return work->unk_0068;
}

/* Return a borrowed subobject address, +0x8c from the global provider.
 * Its integer address ABI is retained for the existing handlers below. */
int Unk0bac80_Unk_0bae18(void)
{
    u8 *base = Unk044904_Get_data_0215ee98();
    return (int)(base + 0x8c);
}

/* Publish the tier query result and return handler completion (1).
 * Evidence: consecutive BLs at 020bae54/020bae58 pass r0 unchanged. */
u32 Unk0bac80_Unk_0bae50(void)
{
    u32 tier = Unk02ee5c_GetTierFromField70();
    Unk03aae8_Unk_03acf4(tier);
    return 1;
}

/* Publish work +0x40 through the shared result setter, then complete (1).
 * Evidence: 020bb2a0 loads +0x40 before calling 0203acf4. */
u32 Unk0bac80_Unk_0bb298(void)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    Unk03aae8_Unk_03acf4(work->unk_0040);
    return 1;
}

/* Forward the opaque work +0x54 handle and the caller's unchanged word.
 * Evidence: LDR +0x54 and MOV r1,r4 before BL 0204fdac. */
void Unk0bac80_Unk_0badd0(u32 arg0)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    func_0204fdac(work->unk_0054, arg0);
}

/* Forward the opaque work +0x60 handle and the caller's unchanged word.
 * Evidence: LDR +0x60 and MOV r1,r4 before BL 0204fdac. */
void Unk0bac80_Unk_0badec(u32 arg0)
{
    Unk0bac80Work *work = (Unk0bac80Work *)Unk0bac80_Unk_0badc0();
    func_0204fdac(work->unk_0060, arg0);
}


int func_02049d80();
/* decompiler-derived */
u32 Unk0bac80_Unk_0bae34(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,2);
  Unk03aae8_Unk_03acf4();
  return 1;
}

int func_02049f24();
/* decompiler-derived */
u32 Unk0bac80_Unk_0bae64(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049f24(value,0);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bae80(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,0);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0baf6c(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,1);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0baf88(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049f24(value,1);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb078(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,3);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb094(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,4);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb0b0(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,5);
  Unk03aae8_Unk_03acf4();
  return 1;
}



/* decompiler-derived */
u32 Unk0bac80_Unk_0bb0cc(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,6);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb0e8(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,7);
  Unk03aae8_Unk_03acf4();
  return 1;
}

int Unk02e000_GetWorkArea();
int func_020bac80();
/* decompiler-derived */
void Unk0bac80_Unk_0bacf8(u32 arg0)
{
  int value;
  value = Unk02e000_GetWorkArea();
  func_020bac80(arg0,*(u16 *)(value + 0x35c) + 1);
}


/* decompiler-derived */
void Unk0bac80_Unk_0bad1c(u32 arg0)
{
  int value;
  value = Unk02e000_GetWorkArea();
  func_020bac80(arg0,*(u16 *)(value + 0x35c) - 1);
}

int func_0203ac00();
/* decompiler-derived */
u32 Unk0bac80_Unk_0bb104(void)
{
  int value1;
  int value2;
  value1 = func_0203ac00(0);
  if (value1 < 0xf) {
    value2 = Unk02e000_GetWorkArea();
    Unk03aae8_Unk_03acf4(*(u16 *)(value2 + value1 * 2 + 0x386));
  }
  else {
    Unk03aae8_Unk_03acf4(0);
  }
  return 1;
}

int func_0203ac00();
int Unk02e000_GetWorkArea();
u32 Unk0bac80_Unk_0bb144(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a < 15) {
        u16 *t = (u16 *)((u8 *)Unk02e000_GetWorkArea() + 134 + 768);
        t[a] += b;
    }
    return 1;
}
