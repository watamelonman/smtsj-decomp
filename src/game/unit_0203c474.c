/*
 * src/game/unit_0203c474.c: handlers reached from the 8-byte-entry table at
 * 0x0212b624 (relocs point the entry's second word at the handler). Handlers
 * take no C arguments; these entries return 1, except
 * Unk03c474_Unk_03c474, Unk03c474_Unk_03c4a0, Unk03c474_Unk_03c540 and
 * Unk03c474_Unk_03c638, which return 3. The meaning of
 * the return value is not established.
 */
#include "types.h"

void Unk02dcfc_Unk_02df00(int worker, u32 code);
void Unk02dcfc_SetOwnerCode26(void);
int func_0203ac00(int index);
u32 Unk03aae8_Unk_03ad14(void);
int Unk03aae8_Unk_03ad24();
int Unk03aae8_Unk_03ad98();
int func_0205e484();
/* Consumes the value left in r0 by func_0203ac00 in the original handler. */
void func_0205e590(int value);
int func_02065544();
int func_0206569c();
int func_02065bc0();
/* Applies `on` to the visor setters selected by the current visor mode (+0). */
void func_020a269c(u32 on);
void ScanVisor_Unk_0a273c(u32 on);
void ScanVisor_SetField34(s32 on);
/* Forwards `on` to Unk0fd268_SetDir after a null check on the visor data. */
void ScanVisor_Unk_0a27e0(u32 on);
/* 1 writes visor +0x1c = 2, 0 writes visor +0x1c = -2. */
void ScanVisor_SetRangeA(s32 on);
/* 1 writes visor +0x214 = -3, 0 writes visor +0x214 = 3. */
void ScanVisor_SetField214(s32 on);
void ScanVisor_Unk_0a28b0(s32 on);
/* Thunk to Unk0fc584_SetDir (takes no arguments); callers still load r0. */
void ScanVisor_Thunk_020fc6b8(u32 ignored);
void ScanVisor_Unk_0a2920(s32 on);

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

/* Passes 0 to the current-mode visor setters via func_020a269c; returns 1. */
u32 Unk03c474_Unk_03c5b8(void)
{
  func_020a269c(0);
  return 1;
}

/* Passes 1 to the five visor setters called by ScanVisor_Unk_0a273c; returns 1. */
u32 Unk03c474_Unk_03c5cc(void)
{
  ScanVisor_Unk_0a273c(1);
  return 1;
}

/* Passes 0 to the five visor setters called by ScanVisor_Unk_0a273c; returns 1. */
u32 Unk03c474_Unk_03c5e0(void)
{
  ScanVisor_Unk_0a273c(0);
  return 1;
}

/* Selects visor +0x210 = 50 and +0x214 = 0 via ScanVisor_Unk_0a28b0; returns 1. */
u32 Unk03c474_Unk_03c5f4(void)
{
  ScanVisor_Unk_0a28b0(0);
  return 1;
}

/* Calls the direction thunk with 1, then sets owner worker +0x18 to 26; returns 3. */
u32 Unk03c474_Unk_03c540(void)
{
  ScanVisor_Thunk_020fc6b8(1);
  Unk02dcfc_SetOwnerCode26();
  return 3;
}

/* Selects visor +0x34 = -3 and calls the +0x24c helper with 1; returns 1. */
u32 Unk03c474_Unk_03c56c(void)
{
  ScanVisor_SetField34(1);
  ScanVisor_Unk_0a2920(1);
  return 1;
}

/* Selects visor +0x34 = 3 and calls the +0x24c helper with 0; returns 1. */
u32 Unk03c474_Unk_03c588(void)
{
  ScanVisor_SetField34(0);
  ScanVisor_Unk_0a2920(0);
  return 1;
}

/* Only the owner field read by this handler is modeled; other fields are opaque. */
typedef struct Unk03c474Owner {
  u8 pad_0000[0xe8];
  int worker;
} Unk03c474Owner;

/* Forwards script argument index 0 to func_0205e590, then sets worker state 21/code 1; returns 3. */
u32 Unk03c474_Unk_03c4a0(void)
{
  Unk03c474Owner *owner;
  func_0205e590(func_0203ac00(0));
  owner = (Unk03c474Owner *)Unk03aae8_Unk_03ad14();
  Unk02dcfc_Unk_02df00(owner->worker, 1);
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
