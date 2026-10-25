/* Matching C for the 020fc584 unit; unknown fields retain offset-based names. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fc584Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
} Unk0fc584Work;

/* Borrowed field views; gaps describe only offsets observed in this unit. */
typedef struct Unk0fc584State {
    u32 unk_0000;
    u8 pad_0004[0x28];
    u32 unk_002c;
    u32 unk_0030;
} Unk0fc584State;

typedef struct Unk0fc584Context {
    u8 pad_0000[0x28bc];
    u32 unk_28bc;
} Unk0fc584Context;

extern u32 data_02176e14[];
extern u8 *data_02176e10;
void func_020a4e48();
void func_020a4eb0();
int Unk0fc584_IsBelow64(void);
/* Store the +0x28bc word when the context exists (020fc638 str +0x8bc after +0x2000). */
void Unk0fc584_SetField28bc(u32 x)
{
    if (data_02176e10 != 0) {
        ((Unk0fc584Context *)data_02176e10)->unk_28bc = x;
    }
}

/* Read the +0x28bc word, or zero without a context; evidenced by 020fc654 loads. */
u32 Unk0fc584_GetField28bc(void)
{
    if (data_02176e10 == 0) {
        return 0;
    }
    return ((Unk0fc584Context *)data_02176e10)->unk_28bc;
}

/* Return the borrowed singleton address stored at data_02176e14 (020fc584 literal/load). */
u32 Unk0fc584_Get_data_02176e14(void)
{
  return *data_02176e14;
}

void func_020572d8(void);
void func_02057eb8(s32 value);
/* Forward -1 to 02057eb8, then call 020572d8; order follows 020fcfd0. */
void Unk0fc584_Unk_0fcfd0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
}

void func_02061424(Unk0fc584State *work);
/* Pass the borrowed singleton to 02061424 only when present (020fc6a0 r0 flow). */
void Unk0fc584_Unk_0fc6a0(void)
{
  Unk0fc584State *work = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
  if (work == 0) {
    return;
  }
  func_02061424(work);
}


/* Read the singleton's first word, returning zero when absent (020fc894 ldr [r0]). */
u32 Unk0fc584_Unk_0fc894(void)
{
    Unk0fc584State *work = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    return work == 0 ? 0 : work->unk_0000;
}

/* Store the supplied word at +0x2c and mark +0x30 as one, if present (020fc84c stores). */
void Unk0fc584_Unk_0fc84c(u32 arg0)
{
    Unk0fc584State *work = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    if (work != 0) {
        work->unk_002c = arg0;
        work->unk_0030 = 1;
    }
}

void func_02057524(u32 value);
void func_02057ddc(u32 value);
void func_02057e18(u32 value);
/* Forward 31, -1 and 4 to the three helpers in the order observed at 020fcfb0. */
void Unk0fc584_Unk_0fcfb0(void)
{
    func_02057e18(31);
    func_02057ddc(0xffffffff);
    func_02057524(4);
}


int Unk0fc584_IsBelow64();
/* decompiler-derived */
void Unk0fc584_Unk_0fc824(void)
{
  int value;
  value = Unk0fc584_IsBelow64();
  if (value == 0) {
    return;
  }
  value = Unk0fc584_Get_data_02176e14();
  *(u32 *)(value + 0x28) = 0;
  *(u32 *)(value + 0x20) = *(u32 *)(value + 0x24);
}

int func_020fc8bc();
/* decompiler-derived */
void Unk0fc584_Unk_0fc674(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0fc584_Get_data_02176e14();
  if (value1 != 0) {
    return;
  }
  value2 = func_020fc8bc(arg0);
  *data_02176e14 = value2;
}


int func_0205bb68();
int func_0205ddb4();
void Unk0fc584_SetDir(int flag)
{
    u32 p = Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return;
    }
    if (flag != 0) {
        FIELD(int, p, 20) = FIELD(int, p, 28);
    } else {
        FIELD(int, p, 20) = -FIELD(int, p, 28);
    }
}

int Unk0fc584_IsBelow64(void)
{
    u32 p = Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return 0;
    }
    return FIELD(int, p, 12) < 64;
}

int Unk0fc584_IsFieldCZero(void)
{
    u32 p = Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return 0;
    }
    return FIELD(int, p, 12) == 0;
}

/* decompiler-derived */
void Unk0fc584_Unk_0fc9fc(int *arg0)
{
  if (*arg0 == 0) {
    if (arg0[2] != 0) {
      func_0205ddb4();
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  else {
    if (arg0[2] != 0) {
      func_0205ddb4();
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  *data_02176e14 = 0;
}

extern u8 data_02151058[];
extern u8 data_0215106c[];
int func_0205dcd4();
/* Loads battle_money (arg1 != 0) or cave_moneywindow layout (medium). */
void Unk0fc584_LoadMoneyWindow(int arg0,int arg1)
{
  u32 tmp1;
  if (arg1 == 0) {
    Unk05b82c_Unk_05b82c(0xda);
    tmp1 = func_0205dcd4(data_02151058,1);
    ((Unk0fc584Work *)arg0)->unk_0008 = tmp1;
    return;
  }
  Unk05b82c_Unk_05b82c(0x59);
  tmp1 = func_0205dcd4(data_0215106c,1);
  ((Unk0fc584Work *)arg0)->unk_0008 = tmp1;
}

int func_020fc734();
void Unk0fc584_Unk_0fc86c();
/* decompiler-derived */
void Unk0fc584_Unk_0fc7b8(u32 arg0)
{
  int tmp1;
  int *v2;
  tmp1 = Unk0fc584_IsBelow64();
  if (tmp1 == 0) {
    return;
  }
  v2 = (int *)Unk0fc584_Get_data_02176e14();
  if (*v2 == 1) {
    Unk0fc584_Unk_0fc84c((u32)arg0);
    Unk0fc584_Unk_0fc86c();
    return;
  }
  func_020fc734(arg0);
}

int Unk0fc584_Unk_0fc7f4(void)
{
    u32 p;
    if (Unk0fc584_IsBelow64() == 0) {
        return 0;
    }
    p = Unk0fc584_Get_data_02176e14();
    return FIELD(int, p, 32) != FIELD(int, p, 36);
}

void Unk0fc584_Unk_0fc86c(void)
{
    u32 p = Unk0fc584_Get_data_02176e14();
    if (p != 0 && FIELD(u32, p, 48) != 0 && FIELD(u32, p, 44) != 0) {
        func_020fc734(FIELD(u32, p, 44));
    }
}
