#include "GameState.h"
#include "types.h"

void func_0203428c(void);
void func_0206146c(void);
void func_02057660(int a, int b);

int Unk02e000_Unk_02e774();
void Unk02f2a8_ClearEntry5e12Bit0(int i)
{
    if (i >= 64) {
        return;
    }
    if (i < 0) {
        return;
    }
    {
        u8 *p = (u8 *)Unk02e000_Unk_02e774() + 0x5e12;
        p[i] &= ~1;
    }
}

void Unk02f2a8_SetField6138(int k, u32 v)
{
    u8 *w = (u8 *)Unk02e000_Unk_02e774();
    switch (k) {
    case 1:
        *(u32 *)(w + 0x6138) = v;
        break;
    case 2:
        *(u32 *)(w + 0x613c) = v;
        break;
    case 3:
        *(u32 *)(w + 0x6140) = v;
        break;
    }
}

void Unk02f2a8_Nop_0303c8(void) { }
void Unk02f2a8_Nop_0303cc(void) { }
void func_02035db8();
void func_02036318();
void func_0209e0b0();
int Unk095560_Thunk_020961a0();
void func_020305a8();
void func_020a269c();
void Unk0a4e48_Unk_0a4e9c();
int func_02035c90();
void Unk02f2a8_Unk_0306a8(int *arg0);

typedef struct Unk02f2a8Obj39160 {
    u32 unk_0000;
    u32 pad_0004_0 : 16;
    u32 unk_0004_16 : 4;
} Unk02f2a8Obj39160;
void func_02030548(u8 *p)
{
    u8 *a = (u8 *)Unk02e000_GetWorkArea();
    u8 *b = (u8 *)Unk02e000_GetWorkArea();
    func_02035db8(p + 0x70, FIELD(s8, a, 0x364), FIELD(s8, b, 0x365));
}

void func_02031408(GameState *gs)
{
    s8 x = FIELD(s8, gs, 0x744e);
    s8 y = FIELD(s8, gs, 0x744f);
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 t = FIELD(s32, gs, 0x7450);
    u32 v = FIELD(u32, w, 0x358);
    if (t != -1) {
        v = t;
    }
    func_02036318(x, y, v);
}

int func_02032a08(int *p)
{
    func_0209e0b0();
    if (Unk095560_Thunk_020961a0() != 0) {
        return;
    }
    Unk02f2a8_Unk_0306a8(p);
    func_020305a8(p, 1);
    func_020a269c(1);
}

void func_02032df4(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    Unk0a4e48_Unk_0a4e9c(2);
}

void func_020333b4(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7480) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    FIELD(u32, gs, 0x7488) = 0;
    if (FIELD(u32, gs, 0x73dc) != 0) {
        return;
    }
    func_020a269c(0);
    func_0205257c(3);
    Unk0a4e48_Unk_0a4e9c(2);
    func_020a0da4(5);
}

/* Main body at +4, or 0 when no GameState exists. */
u8 *GameState_GetBody(void)
{
    if (gGameState != 0) {
        return gGameState->unk_0004;
    }
    return 0;
}

u32 *func_02034a44(int a, int b)
{
    return (u32 *)gGameState->unk_38e8 + func_02035c90(a, b);
}

u32 *func_02034a68(void)
{
    return func_02034a44(FIELD(s8, gGameState, 0x7482), FIELD(s8, gGameState, 0x7483));
}

u32 func_02034ab0(void)
{
    u32 r = 0;
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)func_02039160();
    if (o != 0) {
        r = o->unk_0004_16;
    }
    return r;
}

void GameState_ClearRootUnk60(void)
{
    gGameState->root->unk_60 = 0;
}

u16 GameState_GetUnkField74f6(void)
{
    return gGameState->unk_74f6;
}

void Unk02f2a8_Nop_035430(void) { }

void Unk02f2a8_Thunk_0203428c(void) { func_0203428c(); }
void Unk02f2a8_Thunk_0206146c(void) { func_0206146c(); }

GameState *GetGameState(void) { return gGameState; }

void Unk02f2a8_Call_02057660(void) { func_02057660(2, 0); }

u16 GameState_GetUnkField74f4(void) { return gGameState->unk_74f4; }

int func_020360d8();
/* decompiler-derived */
void Unk02f2a8_Unk_035ec4(int arg0,u32 arg1)
{
  u16 tmp1;
  tmp1 = func_020360d8(arg1);
  *(u16 *)(arg0 + 0x18) = tmp1;
}

int Unk02e000_GetWorkArea();
/* decompiler-derived */
void Unk02f2a8_Unk_030578(int arg0)
{
  int tmp1;
  tmp1 = Unk02e000_GetWorkArea();
  Unk02f2a8_Unk_035ec4(arg0 + 0x7c,*(u32 *)(tmp1 + 0x358));
}

int func_02061424();
/* decompiler-derived */
void Unk02f2a8_Unk_030478(int arg0)
{
  if (arg0 == 0) {
    return;
  }
  *(u32 *)(arg0 + 0x14) = 5;
  func_02061424();
}

/* decompiler-derived */
void Unk02f2a8_Unk_033890(int arg0)
{
  *(u32 *)(arg0 + 0x7478) = 0;
  *(u8 *)(arg0 + 0x7480) = 0;
  *(u8 *)(arg0 + 0x7481) = 0;
  *(u32 *)(arg0 + 0x7484) = 0;
  *(u32 *)(arg0 + 0x7488) = 0;
}

/* decompiler-derived */
void Unk02f2a8_Unk_033ac8(int arg0)
{
  *(u32 *)(arg0 + 0x7478) = 0;
  *(u8 *)(arg0 + 0x7480) = 0;
  *(u8 *)(arg0 + 0x7481) = 0;
  *(u32 *)(arg0 + 0x7484) = 0;
  *(u32 *)(arg0 + 0x7488) = 0;
}

int func_02039160();
/* decompiler-derived */
u32 Unk02f2a8_Unk_034a8c(void)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_02039160();
  if (tmp1 != 0) {
    tmp2 = (*(u32 *)(tmp1 + 4) & 0xffff) >> 0xc;
  }
  return tmp2;
}

int func_02035a70();
int func_02044428();
int func_02044534();
int func_020f43d4();
/* decompiler-derived */
void Unk02f2a8_Unk_035440(int arg0)
{
  if (arg0 == 0) {
    arg0 = 1;
  }
  func_02044428(0x24);
  func_02035a70(arg0);
  func_02044534(0x24);
  func_020f43d4();
}

int func_02050088();
/* decompiler-derived */
void Unk02f2a8_Unk_036488(void)
{
  u16 tmp1;
  int tmp2;
  tmp2 = Unk02e000_GetWorkArea();
  *(u16 *)(tmp2 + 0xaf2) = 0;
  tmp1 = func_02050088(1,0x32,100);
  *(u16 *)(tmp2 + 0xaf4) = tmp1;
}

int func_0205bb68();
/* decompiler-derived */
void Unk02f2a8_Unk_0343b4(int arg0)
{
  int tmp1;
  tmp1 = 0;
  if (0 < *(int *)(arg0 + 8)) {
    do {
      func_0205bb68();
      tmp1 = tmp1 + 1;
    } while (tmp1 < *(int *)(arg0 + 8));
  }
  *(u32 *)(arg0 + 8) = 0;
}

int Unk02f2a8_Unk_030d20();
int func_020572c0();
int func_0205e590();
int Unk095560_Unk_0956a8();
/* decompiler-derived */
void Unk02f2a8_Unk_033c94(u32 *arg0)
{
  Unk02f2a8_Unk_030d20(arg0,1);
  Unk095560_Unk_0956a8();
  func_02044534(0x24);
  Unk02f2a8_Unk_030478(*arg0);
  func_02061424(arg0);
  func_020572c0();
  func_0205e590(0);
}

int func_020361ec();
int func_020a0da4();
/* decompiler-derived */
void Unk02f2a8_Unk_02fc10(int arg0)
{
  int tmp1;
  int tmp2;
  u32 tmp3;
  tmp1 = Unk02e000_GetWorkArea();
  tmp2 = Unk02e000_GetWorkArea();
  tmp3 = func_020361ec(*(u32 *)(tmp2 + 0x358),*(u32 *)(arg0 + 0x18));
  *(u32 *)(tmp1 + 0x358) = tmp3;
  *(u32 *)(arg0 + 0x1c) = 0;
  ScanVisor_Unk_0a2b38();
  Unk095560_Unk_09615c();
  func_020a0da4(0x2c);
}

int func_021214e0();
int func_021215d4();
/* decompiler-derived */
void Unk02f2a8_Unk_02f8ac(int arg0)
{
  int tmp1;
  *(u32 *)(arg0 + 0x1c) = 0;
  ScanVisor_Unk_0a2b38();
  Unk095560_Unk_09615c();
  tmp1 = func_021214e0(*(u32 *)(arg0 + 0x18));
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x9c) = 1;
    GetGameState();
    func_021215d4();
  }
  func_020a0da4(0x1b);
}

int func_0202f530();
int func_0202f8f0();
int func_0202fc50();
int func_02030204();
/* decompiler-derived */
void Unk02f2a8_Unk_0302f4(int arg0)
{
  switch(*(u32 *)(arg0 + 0x10)) {
  case 0:
    *(u32 *)(arg0 + 0x14) = 1;
    return;
  case 1:
    func_02030204();
    return;
  case 2:
    func_0202f530();
    return;
  case 3:
    func_0202f8f0();
    return;
  case 4:
    func_0202fc50();
    return;
  case 5:
    return;
  default:
    return;
  }
}

/* decompiler-derived */
void Unk02f2a8_Unk_03064c(int *arg0)
{
  int tmp1;
  arg0[0x1cf8] = 1;
  *(u32 *)(*arg0 + 4) = 0;
  *(u32 *)(*arg0 + 0x4c) = 0;
  arg0[0x1d5f] = 4;
  Unk11f2d0_Unk_11f320(arg0 + 0x1d66);
  ScanVisor_Unk_0a2b38();
  ScanVisor_Unk_0a2acc();
  tmp1 = 0;
  do {
    ScanVisor_Unk_0a2a8c(tmp1);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 7);
}

/* decompiler-derived */
void Unk02f2a8_Unk_0306a8(int *arg0)
{
  *(u32 *)(*arg0 + 0x4c) = 1;
  *(u32 *)(*arg0 + 0x54) = 1;
  *(u32 *)(*arg0 + 0x44) = 1;
  *(u32 *)(*arg0 + 0x50) = 1;
  *(u32 *)(*arg0 + 0x38) = 0;
  *(u32 *)(*arg0 + 0x34) = 0;
  arg0[0x1cf8] = 0;
  arg0[0x1cf9] = 0;
  Unk0caea8_Unk_0caf78();
  Unk0a0ce4_Unk_0a0d30(1);
  Unk0caea8_Unk_0caf88();
}

int func_02035edc();
int func_02036368();
/* decompiler-derived */
void Unk02f2a8_Unk_02f378(int arg0)
{
  if (*(int *)(arg0 + 0x60) == 1) {
    if (*(u32 *)(arg0 + 0x6c) < *(u32 *)(arg0 + 0x68)) {
      *(u32 *)(arg0 + 0x6c) = *(u32 *)(arg0 + 0x6c) + 1;
    }
  }
  else if (0 < *(int *)(arg0 + 0x6c)) {
    *(int *)(arg0 + 0x6c) = *(int *)(arg0 + 0x6c) + -1;
  }
  func_02036368(arg0 + 0x7c,*(u32 *)(arg0 + 100),*(u32 *)(arg0 + 0x68),
                *(u32 *)(arg0 + 0x6c));
  func_02035edc(arg0 + 0x7c,arg0 + 0x70);
}

int func_02034ad4();
int func_0205257c();
/* decompiler-derived */
void Unk02f2a8_Unk_032f3c(int *arg0)
{
  func_0205257c(4);
  Unk0a4e48_Unk_0a4e9c(3);
  func_0205e590(9);
  ScanVisor_Unk_0a2660();
  func_02034ad4(0x800,0xf);
  arg0[0x1d1e] = 0;
  arg0[0x1d1f] = 0;
  *(u8 *)(arg0 + 0x1d20) = 0;
  *(u8 *)((int)arg0 + 0x7481) = 0;
  arg0[0x1d21] = 0;
  arg0[0x1d22] = 0;
  *(u32 *)(*arg0 + 0x14) = 1;
  *(u32 *)(*arg0 + 0x18) = 2;
  *(u32 *)(*arg0 + 0x1c) = 0;
  func_020a0da4(8);
}

int func_0203fa58();
int func_020952ac();
/* decompiler-derived */
void Unk02f2a8_Unk_03538c(void)
{
  int tmp1;
  u32 tmp2;
  int tmp3;
  tmp1 = (int)GetGameState();
  tmp2 = Unk03e43c_Unk_03fa28();
  *(u32 *)(tmp1 + 0x74f0) = tmp2;
  func_0203fa58();
  tmp1 = (int)GetGameState();
  tmp3 = Unk03e43c_Unk_03fa28();
  if (*(int *)(tmp1 + 0x74f0) == tmp3) {
    return;
  }
  func_020952ac();
}

int func_0203480c();
int func_02041d70();
/* decompiler-derived */
int Unk02f2a8_Unk_030d20(int arg0,int arg1)
{
  ScanVisor_Unk_0a2b38();
  if (arg1 == 1) {
    func_02041d70(1);
  }
  else {
    func_02041d70(2);
  }
  func_0203480c(arg0 + 4,1);
  Unk09974c_Unk_09974c(arg0 + 0x7550);
  Unk11f2d0_Unk_11f2d0(arg0 + 0x7598);
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
  Unk0964f8_Unk_0964f8();
  Unk0a23f4_Unk_0a2414();
}

u32 Unk038fbc_Unk_038fbc(int *obj);
u32 Unk0387bc_Unk_038e40(int *obj);
u32 Unk0387bc_Unk_038cbc(int *obj);
void Unk02cad4_Unk_02cbdc(u32 a);

/* Tears down the GameState sub-objects and clears gGameState. */
void GameState_Shutdown(GameState *gs)
{
    Unk038fbc_Unk_038fbc((int *)gs->unk_314c);
    Unk0387bc_Unk_038e40((int *)gs->unk_3140);
    Unk0387bc_Unk_038cbc((int *)gs->unk_3134);
    Unk02cad4_Unk_02cbdc(gs->unk_73d0);
    gGameState = 0;
}

/* Returns whether the global game state exists. */
int GameState_Exists(void)
{
    return gGameState != 0;
}
