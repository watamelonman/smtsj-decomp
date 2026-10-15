#include "GameState.h"
#include "types.h"

void func_0203428c(void);
void func_0206146c(void);
void func_02057660(int a, int b);

void Unk02f2a8_Nop_0303c8(void) { }
void Unk02f2a8_Nop_0303cc(void) { }
void Unk02f2a8_Nop_035430(void) { }

void Unk02f2a8_Thunk_0203428c(void) { func_0203428c(); }
void Unk02f2a8_Thunk_0206146c(void) { func_0206146c(); }

GameState *GetGameState(void) { return gGameState; }

void Unk02f2a8_Call_02057660(void) { func_02057660(2, 0); }

u16 GameState_GetUnkField74f4(void) { return gGameState->unk_74f4; }

int func_020360d8();
/* decompiler-derived */
void func_02035ec4(int arg0,u32 arg1)
{
  u16 tmp1;
  tmp1 = func_020360d8(arg1);
  *(u16 *)(arg0 + 0x18) = tmp1;
}

int func_0202e788();
/* decompiler-derived */
void func_02030578(int arg0)
{
  int tmp1;
  tmp1 = func_0202e788();
  func_02035ec4(arg0 + 0x7c,*(u32 *)(tmp1 + 0x358));
}

int func_02061424();
/* decompiler-derived */
void func_02030478(int arg0)
{
  if (arg0 == 0) {
    return;
  }
  *(u32 *)(arg0 + 0x14) = 5;
  func_02061424();
}

/* decompiler-derived */
void func_02033890(int arg0)
{
  *(u32 *)(arg0 + 0x7478) = 0;
  *(u8 *)(arg0 + 0x7480) = 0;
  *(u8 *)(arg0 + 0x7481) = 0;
  *(u32 *)(arg0 + 0x7484) = 0;
  *(u32 *)(arg0 + 0x7488) = 0;
}

/* decompiler-derived */
void func_02033ac8(int arg0)
{
  *(u32 *)(arg0 + 0x7478) = 0;
  *(u8 *)(arg0 + 0x7480) = 0;
  *(u8 *)(arg0 + 0x7481) = 0;
  *(u32 *)(arg0 + 0x7484) = 0;
  *(u32 *)(arg0 + 0x7488) = 0;
}

int func_02039160();
/* decompiler-derived */
u32 func_02034a8c(void)
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
void func_02035440(int arg0)
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
void func_02036488(void)
{
  u16 tmp1;
  int tmp2;
  tmp2 = func_0202e788();
  *(u16 *)(tmp2 + 0xaf2) = 0;
  tmp1 = func_02050088(1,0x32,100);
  *(u16 *)(tmp2 + 0xaf4) = tmp1;
}

int func_0205bb68();
/* decompiler-derived */
void func_020343b4(int arg0)
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

int func_02030d20();
int func_020572c0();
int func_0205e590();
int func_020956a8();
/* decompiler-derived */
void func_02033c94(u32 *arg0)
{
  func_02030d20(arg0,1);
  func_020956a8();
  func_02044534(0x24);
  func_02030478(*arg0);
  func_02061424(arg0);
  func_020572c0();
  func_0205e590(0);
}

int func_020361ec();
int func_020a0da4();
/* decompiler-derived */
void func_0202fc10(int arg0)
{
  int tmp1;
  int tmp2;
  u32 tmp3;
  tmp1 = func_0202e788();
  tmp2 = func_0202e788();
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
void func_0202f8ac(int arg0)
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
void func_020302f4(int arg0)
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
void func_0203064c(int *arg0)
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
void func_020306a8(int *arg0)
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
void func_0202f378(int arg0)
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
void func_02032f3c(int *arg0)
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
