/* Work-area helpers; layouts and contracts follow the original ARM accesses. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ef248Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[4];
    s32 unk_0010;
    u8 pad_0014[0x2c];
    u32 unk_0040;
    u32 unk_0044;
    u8 pad_0048[0xac];
    float ramps[6];
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
int Unk0e8228_Unk_0e8374(u32 value);
void Unk0f8448_Init(void *work, int value);
void func_020ef8d0(void *work);
u32 Unk0e8228_Unk_0e84e4(void);
void Unk0feba0_Unk_0febe8(int value);
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

void func_020ef4b8(Unk0ef248Work *work);
void func_020ef578(Unk0ef248Work *work);
/* Borrowed descriptor layout evidenced by stores at 0, 4 and 0xc..0x20. */
typedef struct Unk0ef248Descriptor {
    u32 size, kind, unknown;
    void (*update)(Unk0ef248Work *);
    void (*ready)(Unk0ef248Work *);
    void (*draw)(Unk0ef248Work *);
    void (*unused)(void);
    void (*nop)(void);
    void (*finish)(void);
} Unk0ef248Descriptor;
/* Original 0x020ef248 installs the work size and callback table; +8 is retained. */
void func_020ef248(Unk0ef248Descriptor *p)
{
    p->size = 0x10c;
    p->kind = 4;
    p->update = func_020ef4b8;
    p->ready = Unk0ef248_Unk_0ef548;
    p->draw = func_020ef578;
    p->unused = 0;
    p->nop = Unk0ef248_Nop_0ef4b4;
    p->finish = Unk0ef248_Thunk_020f7248;
}

/* Original 0x020ef330 staggers six percentage ramps using words +0x10 and +0x18.
 * The nonzero +0x10 path requires a nonzero +0x18 divisor and representable signed arithmetic. */
void func_020ef330(Unk0ef248Work *p)
{
    int value, i;
    if (FIELD(int, p, 0x10) == 0) {
        for (i = 0; i < 6; i++) {
            ((float *)((u8 *)p + 0xf4))[i] = 1.0f;
        }
        return;
    }
    value = (FIELD(int, p, 0x18) - FIELD(int, p, 0x10)) * 300 / FIELD(int, p, 0x18);
    if (value > 250) Unk0ef248_Unk_0ef2ec(&FIELD(float, p, 0x108), value - 250);
    if (value > 180) Unk0ef248_Unk_0ef2ec(&FIELD(float, p, 0x104), value - 180);
    if (value > 120) Unk0ef248_Unk_0ef2ec(&FIELD(float, p, 0x100), value - 120);
    if (value > 70) Unk0ef248_Unk_0ef2ec(&FIELD(float, p, 0xfc), value - 70);
    if (value > 30) Unk0ef248_Unk_0ef2ec(&FIELD(float, p, 0xf8), value - 30);
    Unk0ef248_Unk_0ef2ec(&FIELD(float, p, 0xf4), value);
}

void func_020f7188(Unk0ef248Work *work);
void Unk0bc1a8_Unk_0bc9b4(u32 value, int flag);
void func_020f8264(void *work);
/* Original 0x020ef4b8 advances work, updates ramps outside state 1, and handles states 2/9/11. */
void func_020ef4b8(Unk0ef248Work *p)
{
    func_020f7188(p);
    if (p->unk_0008 != 1) func_020ef330(p);
    switch (p->unk_0008) {
    case 11: Unk0bc1a8_Unk_0bc9b4(p->unk_0040, 0); break;
    case 0: case 1: break;
    case 2: p->unk_0008 = 1; break;
    case 3: case 4: case 5: case 6: case 7: case 8: break;
    case 9: func_020f8264((u8 *)p + 0x50); p->unk_0008 = 10; break;
    case 10: break;
    }
}

int Unk0f8448_GetUnkField8(void *work);
int Unk0f8448_GetUnkField0(void *work);
void func_020ea208(int index, int value);
int Unk09974c_Unk_099bd4(int value);
void Unk0fedd4_Unk_0fee38(int value);
/* Original 0x020ef8d0 copies bounded indexed entries, then forwards a selected entry in states 9/10. */
void func_020ef8d0(void *work)
{
    int start, count, i;
    u32 limit;
    start = Unk0f8448_GetUnkField8(work);
    count = Unk0f8448_GetUnkField0(work);
    limit = Unk0e8228_Unk_0e84e4();
    if (limit < (u32)count) count = limit;
    for (i = 0; i < count; i++) {
        func_020ea208(i, Unk0e8228_GetArr88Field20(start + i));
    }
    switch (data_02176df0->unk_0008) {
    case 9: case 10:
        Unk0fedd4_Unk_0fee38(Unk09974c_Unk_099bd4(Unk0e8228_GetArr88Field20(Unk0f8448_GetUnkField10(work))));
        break;
    }
}

/* Borrowed record prefix: halfword +0x22 and flag bit 7 at +0x2a are observed. */
typedef struct Unk0ef248Record {
    u8 pad[0x22];
    u16 value;
    u8 pad24[6];
    u8 flagsLow : 7;
    u8 flag7 : 1;
} Unk0ef248Record;
Unk0ef248Record *Unk0e8228_Unk_0e84fc(void);
void func_020e8ebc(u32 value);
void Unk0e8228_Unk_0e8f50(int value);
void func_020e8710(u32 value, int mode, int flag);
int Unk09974c_IsKind1or14(Unk0ef248Record *record);
void Unk0e8228_Unk_0e8db8(void);
void func_020e8a30(u32 value, int mode);
int func_020cb1a0(u32 value);
void func_020f7578(Unk0ef248Work *work, int value);
/* Original 0x020ef78c branches on record +0x22 and flag bit 7, submitting work +0x40. */
void func_020ef78c(void)
{
    Unk0ef248Work *work = data_02176df0;
    Unk0ef248Record *record = Unk0e8228_Unk_0e84fc();
    func_020e8ebc(record->value);
    Unk0e8228_Unk_0e8f50(0);
    if (record->value == 0) {
        if (record->flag7) {
            Unk0e8228_Unk_0e8f50(2);
            func_020e8710(work->unk_0040, 4, 0);
            func_020f7e48(work->unk_0040, 0, 7);
            Unk0feba0_Unk_0febe8(0);
            return;
        }
        if (Unk09974c_IsKind1or14(record)) {
            Unk0e8228_Unk_0e8db8();
            func_020e8a30(work->unk_0040, 4);
            func_020f7e48(work->unk_0040, 0, 7);
        } else {
            func_020e8710(work->unk_0040, 4, 0);
            func_020f7e48(work->unk_0040, 0, 7);
        }
        Unk0feba0_Unk_0febe8(0);
    } else {
        func_020f7578(work, func_020cb1a0(record->value));
    }
}

void func_020f711c(Unk0ef248Work *work, u32 value, int a, int b,
                  int c, int d, int e, int f, void (*callback)(u8 *), int g, int h);
void func_020f81cc(void *work, int kind, u32 count, int zero, int a, int b,
                  int (*predicate)(u32, int), void (*select)(void),
                  void (*submit)(void), void (*entry)(void *));
void Unk0f81a4_SetUnkField9c(void *work, void (*callback)(void *));
/* Original 0x020ef3f0 initializes words +0x40..+0x4c and registers the embedded work callbacks. */
void func_020ef3f0(Unk0ef248Work *work)
{
    work->unk_0040 = 32;
    work->unk_0044 = 8;
    FIELD(int, work, 0x48) = 0;
    FIELD(int, work, 0x4c) = 0;
    func_020f711c(work, work->unk_0040, -10, 0, 10, -10, 0, 0, Unk0ef248_Unk_0ef6fc, 0, 0);
    func_020f81cc((u8 *)work + 0x50, 6, Unk0e8228_Unk_0e84e4(), 0, 1, 0,
                  Unk0ef248_Unk_0ef74c, func_020ef78c, Unk0ef248_Unk_0ef878, Unk0ef248_Unk_0ef8ac);
    Unk0f81a4_SetUnkField9c((u8 *)work + 0x50, func_020ef8d0);
}

void Unk0f8448_Unk_0f8468(void *work);
int Unk0f8448_GetUnkField4(void *work);
int Unk0f8448_GetEntry(void *work, int index);
void func_02057df8(void);
void func_02057e18(int value);
void Unk0e8228_Unk_0e8e50(void);
void Unk0e8228_Unk_0e8e6c(void);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Unk_0e8e7c(void);
void func_020f5ad4(int x, int y, int mode, float ramp, int flag);
void Unk0f51dc_Unk_0f5dfc(int x, int y);
void func_020f5b68(int index, int x, int y, int mode, float ramp);
void func_020f5d0c(int x, int y, int start, int count, int total);
/* Original 0x020ef578 submits bounded embedded entries with the six +0xf4
 * ramps and state-dependent modes. Borrowed work must span 0x10c bytes;
 * the embedded count must be at most six to index the ramps. */
void func_020ef578(Unk0ef248Work *work)
{
    int count, limit, y, i, mode, entry, flag, start, total;
    Unk0f8448_Unk_0f8468((u8 *)work + 0x50);
    count = Unk0f8448_GetUnkField0((u8 *)work + 0x50);
    limit = Unk0f8448_GetUnkField4((u8 *)work + 0x50);
    if (limit < count) count = limit;
    if (work->unk_0008 == 1) return;
    func_02057df8();
    Unk0e8228_Unk_0e8e50();
    y = 25;
    for (i = 0; i < count; i++) {
        Unk0e8228_Unk_0e8e6c();
        func_02057e18(31);
        mode = 0;
        entry = Unk0f8448_GetEntry((u8 *)work + 0x50, i);
        flag = work->unk_0010 == 0;
        if (flag) {
            switch (entry) {
            case 2: flag = 0; /* Fall through: kind 2 shares mode 1. */
            case 1: mode = 1; break;
            case 3: flag = 0; /* Fall through: kind 3 shares mode 2. */
            case 4: mode = 2; break;
            default: flag = 0; mode = 0; break;
            }
        }
        func_020f5ad4(74, y, mode, work->ramps[i], flag);
        if (flag) Unk0f51dc_Unk_0f5dfc(74, y);
        func_020f5b68(i, 74, y, mode, work->ramps[i]);
        y += 15;
    }
    Unk0e8228_Unk_0e8e6c();
    start = Unk0f8448_GetUnkField8((u8 *)work + 0x50);
    total = Unk0e8228_Unk_0e84e4();
    if (total > 6 && work->unk_0010 == 0) {
        func_020f5d0c(0, 0, start, count, total);
    }
    Unk0e8228_Thunk_02057534();
    Unk0e8228_Unk_0e8e7c();
}
