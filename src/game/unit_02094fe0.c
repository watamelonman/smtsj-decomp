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

void Unk094fe0_Nop_095000(void);
int Unk094fe0_Unk_095004(int arg0);
u32 Unk094fe0_GetUnkField9a0(void *obj);
Unk094fe0Work *Unk094fe0_Thunk_0202e8cc(void);
int Unk094fe0_Unk_094fec(int arg0);

/* empty callback */
void Unk094fe0_Nop_095000(void) { }

/* decompiler-derived */
int Unk094fe0_Unk_095004(int arg0)
{
  return arg0 + 0x990;
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

void Unk094fe0_SetUnkField9a0(u32 value)
{
    Unk094fe0_Thunk_0202e8cc()->unk_09a0 = value;
}

u32 Unk094fe0_GetWorkUnkField9a0(void)
{
    return Unk094fe0_GetUnkField9a0(Unk094fe0_Thunk_0202e8cc());
}
