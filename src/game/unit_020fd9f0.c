/* Battle help/talk work helpers; field meanings are limited to observed accesses. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fd9f0Work {
    u8 pad_0000[0xc];
    u32 unk_000c;
    u8 pad_0010[0x4];
    u32 unk_0014;
    u8 pad_0018[0xc];
    s32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
    u32 unk_0038;
    u32 unk_003c;
    u32 unk_0040;
} Unk0fd9f0Work;

/* Store -1 at +0x14 of a valid borrowed work object (020fdc0c). */
void Unk0fd9f0_Unk_0fdc0c(Unk0fd9f0Work *work)
{
  work->unk_0014 = 0xffffffff;
  return;
}

extern u32 data_02176e20[];
/* Read the singleton address; the literal load at 020fdb04 names data_02176e20.
 * Zero means no work object has been installed. */
u32 Unk0fd9f0_Get_data_02176e20(void)
{
  return *data_02176e20;
}

void func_020572d8(void);
void func_02057eb8(s32 value);
/* Issue the -1 setting then finalize it, as observed at 020fe2b0. */
void Unk0fd9f0_Unk_0fe2b0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
  return;
}

void func_02061424(u32 address);
/* Forward the installed singleton to 02061424 only when nonzero (020fda14). */
void Unk0fd9f0_Unk_0fda14(void)
{
  int tmp1;
  tmp1 = Unk0fd9f0_Get_data_02176e20();
  if (tmp1 == 0) {
    return;
  }
  func_02061424((u32)tmp1);
  return;
}

u32 func_020fdb14(void);
/* Install the result of 020fdb14 only if the singleton is absent (020fd9f0). */
void Unk0fd9f0_Unk_0fd9f0(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk0fd9f0_Get_data_02176e20();
  if (tmp1 != 0) {
    return;
  }
  tmp2 = func_020fdb14();
  *data_02176e20 = tmp2;
  return;
}


#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

/* Store +1 for nonzero flags, -1 otherwise; 020fda28 writes singleton +0x14.
 * The existing SetDir symbol describes this signed direction setting. */
void Unk0fd9f0_SetDir(int flag)
{
    Unk0fd9f0Work *p = (Unk0fd9f0Work *)Unk0fd9f0_Get_data_02176e20();
    if (p == 0) {
        return;
    }
    if (flag != 0) {
        p->unk_0014 = 1;
    } else {
        p->unk_0014 = -1;
    }
}

/* Release the nonzero +0x24 handle through 02061424, then clear it (020fe33c).
 * The caller retains ownership of the borrowed work object. */
void Unk0fd9f0_Unk_0fe33c(Unk0fd9f0Work *work)
{
  if (work->unk_0024 == 0) {
    return;
  }
  func_02061424((u32)work->unk_0024);
  work->unk_0024 = 0;
  return;
}



/* Initialize borrowed work fields; offsets and defaults follow 020fdb80. */
void Unk0fd9f0_Unk_0fdb80(Unk0fd9f0Work *arg0)
{
  ((Unk0fd9f0Work *)arg0)->unk_000c = 0xffffffe5;
  ((Unk0fd9f0Work *)arg0)->unk_0014 = 1;
  ((Unk0fd9f0Work *)arg0)->unk_0028 = 1;
  ((Unk0fd9f0Work *)arg0)->unk_002c = 1;
  ((Unk0fd9f0Work *)arg0)->unk_0030 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0034 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0038 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_003c = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0024 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0040 = 0;
  return;
}

void func_02057524(s32 value);
void func_02057ddc(s32 value);
void func_02057e18(s32 value);
void func_02057e58(s32 a, s32 b, s32 c);
/* Configure the five subsystem settings in the order observed at 020fe278. */
void Unk0fd9f0_Unk_0fe278(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057e58(2,0x30,10);
  func_02057eb8(2);
  func_02057524(4);
  return;
}

extern u8 data_021510b8[];
extern u8 data_021510cc[];
extern u8 data_021510e0[];
void Unk05b82c_Unk_05b82c(s32 id);
u32 func_0205c2c4(const u8 *path);
u32 func_0205dcd4(const u8 *path, s32 mode);
/* Load borrowed work handles; data_021510b8/cc/e0 contain the Battle/battle_help
 * and battle_talk resource paths, supporting the existing symbol name. */
void Unk0fd9f0_LoadBattleHelpTalk(u32 *arg0)
{
  u32 tmp1;
  Unk05b82c_Unk_05b82c(0xd5);
  Unk05b82c_Unk_05b82c(0xd6);
  tmp1 = func_0205dcd4(data_021510b8,1);
  *arg0 = tmp1;
  tmp1 = func_0205dcd4(data_021510cc,1);
  arg0[7] = tmp1;
  tmp1 = func_0205c2c4(data_021510e0);
  arg0[8] = tmp1;
}

void func_0205bb68(void);
void func_0205c368(u32 handle);
void func_0205ddb4(u32 handle);
/* Release work handles at +0x24, +0x20, +0 and +0x1c, then clear the singleton.
 * The callback receives valid borrowed work, as observed at 020fdc18. */
void Unk0fd9f0_Unk_0fdc18(u32 *arg0)
{
  Unk0fd9f0_Unk_0fe33c((Unk0fd9f0Work *)arg0);
  if (arg0[8] != 0) {
    func_0205c368(arg0[8]);
    arg0[8] = 0;
  }
  if (*arg0 != 0) {
    func_0205ddb4(*arg0);
    *arg0 = 0;
  }
  if (arg0[7] != 0) {
    func_0205ddb4(arg0[7]);
    arg0[7] = 0;
  }
  func_0205bb68();
  func_0205bb68();
  *data_02176e20 = 0;
}

void func_020fde4c(u8 *work);
void func_020fe004(u8 *work);
void func_020fe1f8(u8 *work);
/* Dispatch valid borrowed work by the state at +0x2c (020fde0c). */
void Unk0fd9f0_Update(u8 *p)
{
    switch (FIELD(u32, p, 44)) {
    case 0:
        return;
    case 1:
        func_020fde4c(p);
        func_020fe004(p);
        return;
    case 2:
        func_020fe1f8(p);
        return;
    }
}

/* Return the packed color selected by modes 1 and 2, or the default.
 * Evidence: 020fe300 passes this result to Unk065e88_SetUnkField28. */
u32 Unk0fd9f0_GetColor(int x)
{
    switch (x) {
    case 1:
        return 0xff0000;
    case 2:
        return 0xff000000;
    }
    return 0x299ce700;
}

/* Set +0x28 in state 1; in state 2 reset direction and release +0x24.
 * An absent singleton is ignored, as observed at 020fda58. */
void Unk0fd9f0_Unk_0fda58(u32 x)
{
    u32 p = Unk0fd9f0_Get_data_02176e20();
    if (p == 0) {
        return;
    }
    switch (FIELD(u32, p, 44)) {
    case 1:
        FIELD(u32, p, 40) = x;
        return;
    case 2:
        FIELD(u32, p, 52) = 1;
        FIELD(u32, p, 56) = 1;
        Unk0fd9f0_Unk_0fdc0c((Unk0fd9f0Work *)p);
        Unk0fd9f0_Unk_0fe33c((Unk0fd9f0Work *)p);
        return;
    }
}

void func_020fdd90(u8 *work);
u32 func_020611dc(void (*first)(u8 *), void (*update)(u8 *), u32 unused,
                  void (*destroy)(u32 *), u32 size, u32 group, u32 flags, u32 active);
/* Allocate 0x44 bytes with the callbacks embedded in 020fdb14, then initialize
 * fields and resources. Return zero when allocation fails; ownership is external. */
u32 func_020fdb14(void)
{
    u32 p = func_020611dc(func_020fdd90, Unk0fd9f0_Update, 0,
                         Unk0fd9f0_Unk_0fdc18, 0x44, 3, 0, 1);
    if (p == 0) return 0;
    Unk0fd9f0_Unk_0fdb80((Unk0fd9f0Work *)p);
    Unk0fd9f0_LoadBattleHelpTalk((u32 *)p);
    return p;
}
