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

int func_020950b4(Unk094fe0Work *w, u32 a);
void func_02095320(Unk094fe0Work *w, u32 a);
int Unk094fe0_Call_020950b4(u32 a)
{
    return func_020950b4(Unk094fe0_Thunk_0202e8cc(), a);
}

void Unk094fe0_Call_02095320(u32 a)
{
    func_02095320(Unk094fe0_Thunk_0202e8cc(), a);
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
void func_0209500c(int a, int b)
{
    func_0209502c(Unk094fe0_Thunk_0202e8cc(), a, b);
}

int func_020950b4(Unk094fe0Work *w, u32 bit)
{
    u32 sh = bit & 7;
    u32 idx = bit >> 3;
    u8 *bits = Unk094fe0_Nop_095000(w);
    if (idx >= 512) {
        return 0;
    }
    return (bits[idx] & (1 << sh)) != 0;
}

void Unk094fe0_SetUnkField9a0(u32 value)
{
    Unk094fe0_Thunk_0202e8cc()->unk_09a0 = value;
}

u32 Unk094fe0_GetWorkUnkField9a0(void)
{
    return Unk094fe0_GetUnkField9a0(Unk094fe0_Thunk_0202e8cc());
}
