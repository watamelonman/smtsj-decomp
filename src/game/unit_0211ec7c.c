/* State callbacks with work-area offsets preserved from the original code. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11ec7cWork {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    s32 unk_001c;
    u32 unk_0020;
    u16 unk_0024;
    u8 pad_0026[0x82];
    u32 unk_00a8;
    u8 pad_00ac[0x4];
    u32 unk_00b0;
    u8 pad_00b4[0x1b8];
    u32 unk_026c;
    u8 pad_0270[0x4];
    s32 unk_0274;
} Unk11ec7cWork;

/* Empty entry callback: the original at 0x0211ef08 only returns. */
void Unk11ec7c_Nop_11ef08(void) { }

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
/* Calls 0x0202e0cc then 0x0205b82c with 0xd2; always returns 1. */
u32 Unk11ec7c_Unk_11efec(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xd2);
  return 1;
}

int func_0205dde4();
int func_0211eda0();
/* Requires a valid borrowed work area; forwards the words at +4 and +8 to helpers. */
void Unk11ec7c_Unk_11ee8c(Unk11ec7cWork *arg0)
{
  func_0205dde4(arg0->unk_0004);
  func_0211eda0(arg0->unk_0008);
  return;
}


/* Increments +0x18 with unsigned wrap; queues state 3 when it exceeds +0x14. */
void Unk11ec7c_Unk_11ef0c(Unk11ec7cWork *arg0)
{
  u32 tmp1;
  tmp1 = arg0->unk_0018 + 1;
  arg0->unk_0018 = tmp1;
  if (arg0->unk_0014 < tmp1) {
    arg0->unk_0010 = 3;
  }
  return;
}

void func_0211ee10(Unk11ec7cWork *work, int value);
/* Decrements +0x1c, calls 0x0211ee10 with zero, then clears state fields if expired. */
void Unk11ec7c_Unk_11ef2c(Unk11ec7cWork *arg0)
{
  arg0->unk_001c = arg0->unk_001c + -1;
  func_0211ee10(arg0,0);
  if (0 < arg0->unk_001c) {
    return;
  }
  arg0->unk_0010 = 0;
  arg0->unk_0014 = 0;
  arg0->unk_0018 = 0;
  arg0->unk_001c = 0;
  arg0->unk_0024 = 0;
  arg0->unk_0020 = 0;
  return;
}


int Unk044394_Unk_044534();
int func_02053000();
/* decompiler-derived */
void Unk11ec7c_Unk_11ec7c(int arg0)
{
  func_02053000(((Unk11ec7cWork *)arg0)->unk_026c);
  ((Unk11ec7cWork *)arg0)->unk_026c = 0;
  func_02053000(((Unk11ec7cWork *)arg0)->unk_00a8);
  ((Unk11ec7cWork *)arg0)->unk_00a8 = 0;
  func_02053000(((Unk11ec7cWork *)arg0)->unk_00b0);
  ((Unk11ec7cWork *)arg0)->unk_00b0 = 0;
  if (((Unk11ec7cWork *)arg0)->unk_0274 == 0) {
    return;
  }
  Unk044394_Unk_044534(0x24);
  return;
}

extern u8 data_02151fb4[];
int func_02008848();
int func_0205dcd4();
int func_020629ac();
void Unk11ec7c_Unk_11ee8c(Unk11ec7cWork *arg0);
void Unk11ec7c_Nop_11ef08(void);
void Unk11ec7c_Unk_11ef0c(Unk11ec7cWork *arg0);
void Unk11ec7c_Unk_11ef2c(Unk11ec7cWork *arg0);
void func_0211eea8(Unk11ec7cWork *work);
void Unk11ec7c_ApplyNext(Unk11ec7cWork *p);
void Unk11ec7c_Dispatch(Unk11ec7cWork *p);
/* Applies the queued state. Evidence: copies +0x10 to +0xc, resets +0x10
 * to -1 and invokes the entry callback. Requires a valid borrowed work area. */
void Unk11ec7c_ApplyNext(Unk11ec7cWork *p)
{
    p->unk_000c = p->unk_0010;
    p->unk_0010 = -1;
    switch (p->unk_000c) {
    case 1:
        Unk11ec7c_Unk_11ee8c(p);
        return;
    case 2:
        Unk11ec7c_Nop_11ef08();
        return;
    }
}

/* Dispatches the current state. Evidence: the +0xc switch calls one of
 * three callbacks. Requires a valid borrowed work area; other states do nothing. */
void Unk11ec7c_Dispatch(Unk11ec7cWork *p)
{
    switch ((u32)p->unk_000c) {
    case 0:
        break;
    case 1:
        func_0211eea8(p);
        break;
    case 2:
        Unk11ec7c_Unk_11ef0c(p);
        break;
    case 3:
        Unk11ec7c_Unk_11ef2c(p);
        break;
    }
}

/* decompiler-derived */
void Unk11ec7c_Unk_11f004(int *arg0)
{
  int tmp1;
  if (*arg0 == 1) {
    return;
  }
  func_02008848(arg0,0,0x28);
  *arg0 = 1;
  arg0[3] = 0;
  arg0[4] = 0;
  Unk02e000_Unk_02e0cc();
  tmp1 = func_0205dcd4(((int)data_02151fb4),1);
  arg0[1] = tmp1;
  tmp1 = func_020629ac(5,1,1,1);
  arg0[2] = tmp1;
  return;
}

/* Updates an active work area. Evidence: +0 gates ApplyNext and Dispatch.
 * The queued-state sentinel is -1; the caller retains ownership of p. */
void Unk11ec7c_Update(Unk11ec7cWork *p)
{
    if (p->unk_0000 == 0) {
        return;
    }
    if (p->unk_0010 != -1) {
        Unk11ec7c_ApplyNext(p);
    }
    Unk11ec7c_Dispatch(p);
}
