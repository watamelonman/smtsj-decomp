/* Work-area helpers; layouts and contracts follow the original ARM accesses. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ef248Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[0x34];
    u32 unk_0040;
    u32 unk_0044;
} Unk0ef248Work;

/* Original 0x020ef4b4 is a bare return: an intentionally empty callback. */
void Unk0ef248_Nop_0ef4b4(void) { }

void func_020f7248(void);
/* Original 0x020ef6f0 branches directly to func_020f7248, forwarding no arguments. */
void Unk0ef248_Thunk_020f7248(void) { func_020f7248(); }

extern Unk0ef248Work *data_02176df0;
void func_02008848(void *dst, int value, u32 size);
void func_020ef3f0(Unk0ef248Work *work);
/* Original 0x020ef2a0 clears 0x10c caller-owned bytes, publishes the work, then initializes it. */
void Unk0ef248_Unk_0ef2a0(Unk0ef248Work *arg0)
{
  func_02008848(arg0,0,0x10c);
  data_02176df0 = arg0;
  func_020ef3f0(arg0);
}

int Unk0f7188_Unk_0f7210(void);
void func_020f82e0(void *work);
void Unk0fedd4_SetState2(void);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
/* Array view of caller-owned work, evidenced by stores at +0xf4 through +0x108. */
typedef struct Unk0ef248Obj {
    u8 pad[0xf4];
    u32 unk_f4[6];
} Unk0ef248Obj;
int Unk0e8228_Unk_0e8374();
void Unk0f8448_Init();
void func_020ef8d0();
u32 Unk0e8228_Unk_0e84e4();
void Unk0feba0_Unk_0febe8();
int Unk0e8228_Thunk_02045c38(u32 value);
int func_020e8f74(void);
int Unk0e8228_Unk_0e8fe4(int value);
int Unk0e8228_GetArr88Field20(int index);
/* Original 0x020ef2cc stores zero in six consecutive words at +0xf4. */
void Unk0ef248_ClearArrF4(Unk0ef248Obj *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->unk_f4[i] = 0;
    }
}

/* Existing matched helper: clamp the signed percentage to a float in [0, 1]. */
void Unk0ef248_Unk_0ef2ec(float *p, int v)
{
    if (v < 0) {
        *p = 0.0f;
        return;
    }
    if (v > 100) {
        *p = 1.0f;
        return;
    }
    *p = v / 100.0f;
}

/* Original 0x020ef548 updates the embedded +0x50 work when ready, then signals state 10. */
void Unk0ef248_Unk_0ef548(Unk0ef248Work *arg0)
{
  int value;
  value = Unk0f7188_Unk_0f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0((u8 *)arg0 + 0x50);
  if (arg0->unk_0008 != 10) {
    return;
  }
  Unk0fedd4_SetState2();
}

void func_02044ec4(void);
void Unk0e8228_Unk_0e8c80(void);
void func_020f7d14(u32 value);
void func_020f7e48(u32 value, int arg1, int arg2);
u32 Unk0f8448_GetUnkField10(void *work);
void Unk0e8228_Unk_0e8d90(u32 value, u32 field10);
/* Existing matched helper: initialize embedded work from +0x44, select mode, and clear six slots. */
void Unk0ef248_Unk_0ef6fc(u8 *p)
{
    Unk0f8448_Init(p + 80, Unk0e8228_Unk_0e8374(FIELD(u32, p, 68)));
    func_020ef8d0(p + 80);
    if (Unk0e8228_Unk_0e84e4() >= 6) {
        Unk0feba0_Unk_0febe8(3);
    } else {
        Unk0feba0_Unk_0febe8(2);
    }
    Unk0ef248_ClearArrF4((Unk0ef248Obj *)p);
}

/* Original 0x020ef74c rejects only when either predicate is true and the indexed query equals one. */
int Unk0ef248_Unk_0ef74c(u32 a, int b)
{
    if (Unk0e8228_Thunk_02045c38(a) != 0 || func_020e8f74() != 0) {
        if (Unk0e8228_Unk_0e8fe4(Unk0e8228_GetArr88Field20(b)) == 1) {
            return 0;
        }
    }
    return 1;
}

/* Original 0x020ef878 snapshots the published work before callbacks and submits fields +4 and +0x40. */
void Unk0ef248_Unk_0ef878(void)
{
  Unk0ef248Work *value;
  value = data_02176df0;
  Unk0e8228_Unk_0e8c80();
  func_02044ec4();
  func_020f7d14(value->unk_0004);
  func_020f7e48(value->unk_0040,0,1);
}

/* Original 0x020ef8ac forwards the input object's +0x10 field and published work's +0x44 field. */
void Unk0ef248_Unk_0ef8ac(void *work)
{
  u32 tmp1;
  tmp1 = Unk0f8448_GetUnkField10(work);
  Unk0e8228_Unk_0e8d90(data_02176df0->unk_0044,tmp1);
}
