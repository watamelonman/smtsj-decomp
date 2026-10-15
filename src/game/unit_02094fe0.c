/*
 * src/game/unit_02094fe0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk094fe0Work {
    u8 pad_0000[0x9a0];
    u32 unk_09a0;
} Unk094fe0Work;

extern u8 data_02175dac[];
Unk094fe0Work *Unk02e000_GetUnk094fe0Work(void);

u8 *Unk094fe0_Nop_095000(Unk094fe0Work *w);
int Unk094fe0_Unk_095004(int arg0);
u32 Unk094fe0_GetUnkField9a0(void *obj);
Unk094fe0Work *Unk094fe0_Thunk_0202e8cc(void);
int Unk094fe0_Unk_094fec(int arg0);

/* returns its argument (the ROM body is just `bx lr`) */
u8 *Unk094fe0_Nop_095000(Unk094fe0Work *w) { return (u8 *)w; }

/* decompiler-derived */
int Unk094fe0_Unk_095004(int arg0)
{
  return arg0 + 0x990;
}

int Unk094fe0_TestBit(Unk094fe0Work *w, u32 a);
int Unk094fe0_TestBit990(Unk094fe0Work *w, u32 a);
int Unk094fe0_Call_020950b4(u32 a)
{
    return Unk094fe0_TestBit(Unk094fe0_Thunk_0202e8cc(), a);
}

void Unk094fe0_Call_02095320(u32 a)
{
    Unk094fe0_TestBit990(Unk094fe0_Thunk_0202e8cc(), a);
}

/* get u32 at +0x9a0 */
u32 Unk094fe0_GetUnkField9a0(void *obj) { return ((Unk094fe0Work *)obj)->unk_09a0; }

/* forwards to `Unk02e000_GetUnk094fe0Work` */
Unk094fe0Work *Unk094fe0_Thunk_0202e8cc(void) { return Unk02e000_GetUnk094fe0Work(); }

/* decompiler-derived */
int Unk094fe0_Unk_094fec(int arg0)
{
  return arg0 * 0x1c + ((int)data_02175dac);
}

void func_0209502c();
void Unk094fe0_Call_0209502c(int a, int b)
{
    func_0209502c(Unk094fe0_Thunk_0202e8cc(), a, b);
}

void func_020950e4();
void func_020e6708();
void *Unk02e000_GetWorkArea();

void func_0209502c(Unk094fe0Work *w, int a, int b)
{
    u8 v;
    func_020950e4(Unk094fe0_Nop_095000(w), a, b);
    func_020e6708(a, b);
    v = ((u8 *)Unk02e000_GetWorkArea())[855];
    switch (a) {
    case 0x70c:
        if (v < 10) {
            v = 10;
        }
        break;
    case 0x70d:
        if (v < 12) {
            v = 12;
        }
        break;
    }
    ((u8 *)Unk02e000_GetWorkArea())[855] = v;
}

int Unk094fe0_TestBit(Unk094fe0Work *w, u32 bit)
{
    u32 sh = bit & 7;
    u32 idx = bit >> 3;
    u8 *bits = Unk094fe0_Nop_095000(w);
    if (idx >= 512) {
        return 0;
    }
    return (bits[idx] & (1 << sh)) != 0;
}

void func_020950e4();
void Unk094fe0_Unk_095370(Unk094fe0Work *w, u32 a, int b);
int Unk094fe0_TestFlag18(u8 *p, int bit)
{
    if (p == 0) {
        return 0;
    }
    if (bit < 0 || bit > 31) {
        return 0;
    }
    return (FIELD(u32, p, 0x18) & (1 << bit)) != 0;
}

void Unk094fe0_SetSlot(u8 *p, int i, u32 v)
{
    if (p == 0) {
        return;
    }
    if (i < 0 || i >= 5) {
        return;
    }
    ((u32 *)(p + 4))[i] = v;
}

u32 Unk094fe0_GetSlot(u8 *p, int i)
{
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 5) {
        return 0;
    }
    return ((u32 *)(p + 4))[i];
}

void Unk094fe0_Unk_095204(u32 a, int b)
{
    if (a >= 15360) {
        return;
    }
    func_020950e4((u8 *)Unk094fe0_Thunk_0202e8cc() + 512, a, b);
}

int Unk094fe0_TestBit200(Unk094fe0Work *w, u32 a)
{
    if (a >= 15360) {
        return 0;
    }
    return (FIELD(u8, (u8 *)w + (a >> 3), 512) & (1 << (a & 7))) != 0;
}

int Unk094fe0_TestBit990(Unk094fe0Work *w, u32 a)
{
    u32 i = a - 1;
    u8 *bits;
    if (i >= 128) {
        return 0;
    }
    bits = (u8 *)Unk094fe0_Unk_095004((int)w);
    return (bits[i >> 3] & (1 << (i & 7))) != 0;
}

void Unk094fe0_Call_02095370(u32 a, int b)
{
    Unk094fe0_Unk_095370(Unk094fe0_Thunk_0202e8cc(), a, b);
}

void Unk094fe0_Unk_095370(Unk094fe0Work *w, u32 a, int b)
{
    u32 i = a - 1;
    if (i >= 128) {
        return;
    }
    func_020950e4((u8 *)Unk094fe0_Unk_095004((int)w), i, b);
}

void Unk094fe0_SetUnkField9a0(u32 value)
{
    Unk094fe0_Thunk_0202e8cc()->unk_09a0 = value;
}

u32 Unk094fe0_GetWorkUnkField9a0(void)
{
    return Unk094fe0_GetUnkField9a0(Unk094fe0_Thunk_0202e8cc());
}
