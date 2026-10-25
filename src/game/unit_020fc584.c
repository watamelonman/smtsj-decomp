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
    u32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    u32 unk_0010;
    s32 unk_0014;
    u32 unk_0018;
    s32 unk_001c;
    s32 unk_0020;
    s32 unk_0024;
    s32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
    u32 unk_0038;
    u32 unk_003c;
} Unk0fc584State;

typedef struct Unk0fc584Context {
    u8 pad_0000[4];
    u32 unk_0004;
    u8 pad_0008[0x28b0 - 8];
    struct Unk0fc584Panel *unk_28b0;
    u32 unk_28b4;
    u32 unk_28b8;
    u32 unk_28bc;
} Unk0fc584Context;

extern u32 data_02176e14[];
extern u8 *data_02176e10;
void func_020a4e48(u32 value);
void func_020a4eb0(u32 kind, u32 arg1, u32 arg2);
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


/* Clear +0x28 and copy +0x24 to +0x20 when below 64 (020fc824 stores). */
void Unk0fc584_Unk_0fc824(void)
{
  Unk0fc584State *work;
  if (Unk0fc584_IsBelow64() == 0) {
    return;
  }
  work = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
  work->unk_0028 = 0;
  work->unk_0020 = work->unk_0024;
}

u32 func_020fc8bc(u32 arg0);
/* Create and publish a singleton only when absent (020fc674 call and store). */
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


void func_0205bb68(void);
void func_0205ddb4(u32 handle);
/* Select +0x1c or its negation for +0x14; 020fc6b8 proves the sign selection. */
void Unk0fc584_SetDir(int flag)
{
    Unk0fc584State *p = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return;
    }
    if (flag != 0) {
        p->unk_0014 = p->unk_001c;
    } else {
        p->unk_0014 = -p->unk_001c;
    }
}

/* Test signed +0x0c against 64; absent singleton returns false (020fc6e4). */
int Unk0fc584_IsBelow64(void)
{
    Unk0fc584State *p = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return 0;
    }
    return p->unk_000c < 64;
}

/* Test +0x0c for zero; absent singleton returns false (020fc70c). */
int Unk0fc584_IsFieldCZero(void)
{
    Unk0fc584State *p = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return 0;
    }
    return p->unk_000c == 0;
}

/* Release the +8 handle and resource group, then unpublish; 020fc9fc calls/stores. */
void Unk0fc584_Unk_0fc9fc(int *arg0)
{
  if (*arg0 == 0) {
    if (arg0[2] != 0) {
      func_0205ddb4(arg0[2]);
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  else {
    if (arg0[2] != 0) {
      func_0205ddb4(arg0[2]);
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  *data_02176e14 = 0;
}

extern u8 data_02151058[];
extern u8 data_0215106c[];
u32 func_0205dcd4(const u8 *layout, u32 flag);
void Unk05b82c_Unk_05b82c(u32 resource);
/* Select resource 0xda/0x59 and layout; names cite cave_moneywindow/battle_money strings. */
void Unk0fc584_LoadMoneyWindow(Unk0fc584Work *arg0, int arg1)
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

void func_020fc734(s32 value);
void Unk0fc584_Unk_0fc86c(void);
/* Dispatch input via +0x2c/+0x30 for kind one, otherwise directly (020fc7b8). */
void Unk0fc584_Unk_0fc7b8(u32 arg0)
{
  int tmp1;
  Unk0fc584State *v2;
  tmp1 = Unk0fc584_IsBelow64();
  if (tmp1 == 0) {
    return;
  }
  v2 = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
  if (v2->unk_0000 == 1) {
    Unk0fc584_Unk_0fc84c((u32)arg0);
    Unk0fc584_Unk_0fc86c();
    return;
  }
  func_020fc734(arg0);
}

/* Compare +0x20 and +0x24 only when below 64 (020fc7f4 loads and compare). */
int Unk0fc584_Unk_0fc7f4(void)
{
    Unk0fc584State *p;
    if (Unk0fc584_IsBelow64() == 0) {
        return 0;
    }
    p = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    return p->unk_0020 != p->unk_0024;
}

/* Forward +0x2c only when singleton, +0x30 and +0x2c are nonzero (020fc86c). */
void Unk0fc584_Unk_0fc86c(void)
{
    Unk0fc584State *p = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    if (p != 0 && p->unk_0030 != 0 && p->unk_002c != 0) {
        func_020fc734(p->unk_002c);
    }
}

/* Borrowed panel prefix: 020fc5d4 writes word +0x2c and byte +0x37. */
typedef struct Unk0fc584Panel {
    u8 pad_0000[0x2c];
    u32 unk_002c;
    u8 pad_0030[7];
    u8 unk_0037;
} Unk0fc584Panel;
void func_0205fd10(Unk0fc584Panel *panel, u32 value);

/* Select context +4 from unsigned kind and forward all words; 020fc584 comparisons/calls. */
void func_020fc584(u32 kind, u32 arg1, u32 arg2)
{
    Unk0fc584Context *p = (Unk0fc584Context *)data_02176e10;
    if (p == 0) return;
    if (kind <= 1) p->unk_0004 = 0;
    else p->unk_0004 = 2;
    func_020a4e48(0);
    func_020a4eb0(kind, arg1, arg2);
}

/* Set context/panel flags before forwarding the value; offsets proven by 020fc5d4. */
void func_020fc5d4(u32 value)
{
    if (data_02176e10 == 0) return;
    ((Unk0fc584Context *)data_02176e10)->unk_28b8 = 1;
    ((Unk0fc584Context *)data_02176e10)->unk_28b0->unk_002c = 189;
    ((Unk0fc584Context *)data_02176e10)->unk_28b0->unk_0037 = 5;
    func_0205fd10(((Unk0fc584Context *)data_02176e10)->unk_28b0, value);
}

void Unk0a0ce4_Unk_0a0da4(u32 value);
/* Accumulate a signed change with a minimum nonzero step; 020fc734 divides by 60. */
void func_020fc734(s32 value)
{
    Unk0fc584State *p;
    if (!Unk0fc584_IsBelow64()) return;
    p = (Unk0fc584State *)Unk0fc584_Get_data_02176e14();
    if (p->unk_0024 != p->unk_0020) p->unk_0024 = p->unk_0020;
    p->unk_0028 = value / 60;
    if (p->unk_0028 == 0) {
        if (value > 0) p->unk_0028 = 1;
        if (value < 0) p->unk_0028 = -1;
    }
    Unk0a0ce4_Unk_0a0da4(12);
    p->unk_0024 += value;
    p->unk_003c = 3;
}

/* Initialize the 64-byte state; 020fc944 selects 64/-6 or 97/-16 by kind. */
void func_020fc944(Unk0fc584State *p, u32 kind)
{
    p->unk_0004 = 0;
    p->unk_0000 = kind;
    p->unk_0008 = 0;
    p->unk_0010 = 0;
    p->unk_0014 = 0;
    p->unk_0020 = 0;
    p->unk_0024 = 0;
    p->unk_002c = 0;
    p->unk_0030 = 0;
    p->unk_0038 = 1;
    p->unk_003c = 0;
    if (kind == 0) {
        p->unk_000c = 64;
        p->unk_0018 = 64;
        p->unk_001c = -6;
    } else {
        p->unk_000c = 97;
        p->unk_0018 = 97;
        p->unk_001c = -16;
    }
}

void func_020fcc10(Unk0fc584State *p);
void func_020fcd18(Unk0fc584State *p);
void func_020fca5c(Unk0fc584State *p);
u32 func_020611dc(void (*update)(Unk0fc584State *), void (*callback)(Unk0fc584State *),
    u32 arg2, void (*destroy)(int *), u32 size, u32 group, u32 arg6, u32 arg7);
/* Allocate 64 bytes with kind-selected callbacks, initialize and load layout (020fc8bc). */
u32 func_020fc8bc(u32 kind)
{
    void (*callback)(Unk0fc584State *);
    Unk0fc584State *p;
    switch (kind) {
    case 0: callback = func_020fcc10; break;
    default: callback = func_020fcd18; break;
    }
    p = (Unk0fc584State *)func_020611dc(func_020fca5c, callback, 0,
        Unk0fc584_Unk_0fc9fc, 64, 3, 0, 1);
    if (p == 0) return 0;
    func_020fc944(p, kind);
    Unk0fc584_LoadMoneyWindow((Unk0fc584Work *)p, kind);
    return (u32)p;
}

extern u8 data_021510a0[];
void func_020a9fd8(u32 kind, u32 arg1, u32 arg2, u32 mode,
    u32 arg4, u32 arg5, const u8 *format, s32 value);
/* Clamp signed +0x20 to 0..99999999 for formatted output; 020fcf5c literal/call. */
void func_020fcf5c(Unk0fc584State *p, u32 arg1, u32 arg2, u32 arg3)
{
    s32 value = p->unk_0020;
    if (value < 0) value = 0;
    if (value > 99999999) value = 99999999;
    func_020a9fd8(1, arg1, arg2, 2, arg3, 17, data_021510a0, value);
}
