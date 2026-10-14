/*
 * src/game/unit_02094fe0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02175dac[];
void func_0202e8cc(void);

void Unk094fe0_Nop_095000(void);
int Unk094fe0_Unk_095004(int arg0);
u32 Unk094fe0_GetUnkField9a0(void *obj);
void Unk094fe0_Thunk_0202e8cc(void);
int Unk094fe0_Unk_094fec(int arg0);

/* empty callback */
void Unk094fe0_Nop_095000(void) { }

/* decompiler-derived */
int Unk094fe0_Unk_095004(int arg0)
{
  return arg0 + 0x990;
}

/* get u32 at +0x9a0 */
u32 Unk094fe0_GetUnkField9a0(void *obj) { return FIELD(u32, obj, 0x9a0); }

/* forwards to `func_0202e8cc` */
void Unk094fe0_Thunk_0202e8cc(void) { func_0202e8cc(); }

/* decompiler-derived */
int Unk094fe0_Unk_094fec(int arg0)
{
  return arg0 * 0x1c + ((int)data_02175dac);
}



