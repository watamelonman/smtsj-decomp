/*
 * src/game/unit_0203c474.c: handlers reached from the 8-byte-entry table at
 * 0x0212b624 (relocs point the entry's second word at the handler). Handlers
 * take no C arguments because the table call is indirect; they return 1, except
 * Unk03c474_Unk_03c474 and Unk03c474_Unk_03c4a0, which return 3. The meaning of
 * the return value is not established.
 */
#include "types.h"

int Unk02dcfc_Unk_02df00();
int Unk02dcfc_SetOwnerCode26();
int func_0203ac00();
int Unk03aae8_Unk_03ad14();
int Unk03aae8_Unk_03ad24();
int Unk03aae8_Unk_03ad98();
int func_0205e484();
int func_0205e590();
int func_02065544();
int func_0206569c();
int func_02065bc0();
/* Applies `on` to the visor setters selected by the current visor mode (+0). */
void func_020a269c(u32 on);
int ScanVisor_Unk_0a273c();
int ScanVisor_SetField34();
/* Forwards `on` to Unk0fd268_SetDir after a null check on the visor data. */
void ScanVisor_Unk_0a27e0(u32 on);
/* 1 writes visor +0x1c = 2, 0 writes visor +0x1c = -2. */
void ScanVisor_SetRangeA(s32 on);
/* 1 writes visor +0x214 = -3, 0 writes visor +0x214 = 3. */
void ScanVisor_SetField214(s32 on);
int ScanVisor_Unk_0a28b0();
/* Thunk to Unk0fc584_SetDir (takes no arguments); callers still load r0. */
void ScanVisor_Thunk_020fc6b8(u32 ignored);
int ScanVisor_Unk_0a2920();

u32 Unk03c474_Unk_03c5b8(void);
u32 Unk03c474_Unk_03c5cc(void);
u32 Unk03c474_Unk_03c5e0(void);
u32 Unk03c474_Unk_03c5f4(void);
u32 Unk03c474_Unk_03c540(void);
u32 Unk03c474_Unk_03c56c(void);
u32 Unk03c474_Unk_03c588(void);
u32 Unk03c474_Unk_03c4a0(void);
u32 Unk03c474_Unk_03c474(void);
u32 Unk03c474_Unk_03c638(void);

/* Selects the visor +0x214 = -3 value via ScanVisor_SetField214; returns 1. */
u32 Unk03c474_Unk_03c4c8(void)
{
  ScanVisor_SetField214(1);
  return 1;
}

/* Selects the visor +0x214 = 3 value via ScanVisor_SetField214; returns 1. */
u32 Unk03c474_Unk_03c4dc(void)
{
  ScanVisor_SetField214(0);
  return 1;
}

/* Selects the visor +0x1c = 2 value via ScanVisor_SetRangeA; returns 1. */
u32 Unk03c474_Unk_03c4f0(void)
{
  ScanVisor_SetRangeA(1);
  return 1;
}

/* Selects the visor +0x1c = -2 value via ScanVisor_SetRangeA; returns 1. */
u32 Unk03c474_Unk_03c504(void)
{
  ScanVisor_SetRangeA(0);
  return 1;
}

/* Forwards 1 to the visor direction setter (ScanVisor_Unk_0a27e0 -> Unk0fd268_SetDir); returns 1. */
u32 Unk03c474_Unk_03c518(void)
{
  ScanVisor_Unk_0a27e0(1);
  return 1;
}

/* Forwards 0 to the visor direction setter (ScanVisor_Unk_0a27e0 -> Unk0fd268_SetDir); returns 1. */
u32 Unk03c474_Unk_03c52c(void)
{
  ScanVisor_Unk_0a27e0(0);
  return 1;
}

/*
 * Calls the Unk0fc584_SetDir thunk with 0. The thunk takes no arguments, but the
 * original still loads r0 = 0 before the branch, so the value is kept here.
 */
u32 Unk03c474_Unk_03c558(void)
{
  ScanVisor_Thunk_020fc6b8(0);
  return 1;
}

/* Passes 1 to func_020a269c, which applies it to the setters for the current visor mode; returns 1. */
u32 Unk03c474_Unk_03c5a4(void)
{
  func_020a269c(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5b8(void)
{
  func_020a269c(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5cc(void)
{
  ScanVisor_Unk_0a273c(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5e0(void)
{
  ScanVisor_Unk_0a273c(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5f4(void)
{
  ScanVisor_Unk_0a28b0(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c540(void)
{
  ScanVisor_Thunk_020fc6b8(1);
  Unk02dcfc_SetOwnerCode26();
  return 3;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c56c(void)
{
  ScanVisor_SetField34(1);
  ScanVisor_Unk_0a2920(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c588(void)
{
  ScanVisor_SetField34(0);
  ScanVisor_Unk_0a2920(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c4a0(void)
{
  int value;
  func_0203ac00(0);
  func_0205e590();
  value = Unk03aae8_Unk_03ad14();
  Unk02dcfc_Unk_02df00(*(u32 *)(value + 0xe8),1);
  return 3;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c474(void)
{
  u32 value1;
  int value2;
  value1 = func_0203ac00(0);
  func_0205e484(value1,0);
  value2 = Unk03aae8_Unk_03ad14();
  Unk02dcfc_Unk_02df00(*(u32 *)(value2 + 0xe8),1);
  return 3;
}

static inline void Unk03c474_SetSubUnkC(u16 v, u8 *sub)
{
    FIELD(u16, sub, 0x0c) = v;
}
int Unk03c474_Unk_03c608(void)
{
    int v = func_0203ac00(0);
    if (v > 0) {
        Unk03c474_SetSubUnkC(v - 1, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    }
    return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c638(void)
{
  u32 value1;
  int value2;
  int value3;
  value1 = func_0203ac00(0);
  value2 = Unk03aae8_Unk_03ad14();
  value2 = *(int *)(value2 + 0xe8);
  if (*(int *)(value2 + 0x28) == 0) {
    Unk03aae8_Unk_03ad24(value2);
    *(u32 *)(value2 + 0x28) = 1;
  }
  value1 = Unk03aae8_Unk_03ad98(value2,value1);
  value3 = func_02065544();
  if (value3 == 0) {
    func_02065bc0();
  }
  func_0206569c(value1);
  *(u32 *)(value2 + 0x18) = 0x1c;
  return 3;
}
